// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: filesystem/filesystemasync.cpp
// Functions: 115
// ============================================================

#include "filesystem\filesystemasync.h"

//------------------------------------------------------------------------------
// Address: 0x10002370
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
// Address: 0x100025F0
// Name: public: virtual enum AsyncFileOperation_t CAsyncSearchRequest::GetAsyncOperationType(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAsyncSearchRequest::GetAsyncOperationType(ConCommandBase *this)
{
  return this->m_pszHelpString;
}

//------------------------------------------------------------------------------
// Address: 0x10004710
// Name: public: void CUtlVector<class CBaseFileSystem::COpenedFile,class CUtlMemory<class CBaseFileSystem::COpenedFile,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int>>::Remove(
        CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int> > *this,
        int elem)
{
  int v3; // eax

  free(pMem: this->m_Memory.m_pMemory[elem].m_pName);
  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 8 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100047F0
// Name: public: void CUtlVector<class CBaseFileSystem::COpenedFile,class CUtlMemory<class CBaseFileSystem::COpenedFile,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int>>::Purge(
        CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int> > *this)
{
  int i; // edi
  CBaseFileSystem::COpenedFile *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
    free(pMem: this->m_Memory.m_pMemory[i].m_pName);
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
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004EA0
// Name: public: int CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::InsertMultipleBefore(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CBaseFileSystem::CSearchPath *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CBaseFileSystem::CSearchPath *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CBaseFileSystem::CSearchPath::CSearchPath(this: v12);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10006BE0
// Name: public: void CUtlVector<class CBaseFileSystem::CPathIDInfo __near *,class CUtlMemory<class CBaseFileSystem::CPathIDInfo __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CPathIDInfo *,CUtlMemory<CBaseFileSystem::CPathIDInfo *,int>>::PurgeAndDeleteElements(
        CUtlVector<CBaseFileSystem::CPathIDInfo *,CUtlMemory<CBaseFileSystem::CPathIDInfo *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CBaseFileSystem::CPathIDInfo **m_pMemory; // ecx

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
// Address: 0x10006C50
// Name: public: void CUtlVector<class CZipPackFile::CPackFileEntry,class CUtlMemory<class CZipPackFile::CPackFileEntry,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::EnsureCapacity(
        CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int> > *this,
        int num)
{
  CZipPackFile::CPackFileEntry *m_pMemory; // edx
  unsigned int v4; // eax
  CZipPackFile::CPackFileEntry *v5; // eax

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
    v4 = 20 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CZipPackFile::CPackFileEntry *)_g_pMemAlloc->Realloc_2(
                                                                   this: _g_pMemAlloc,
                                                                   a2: m_pMemory,
                                                                   a3: v4);
      goto LABEL_5;
    }
    v5 = (CZipPackFile::CPackFileEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006D50
// Name: public: int CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::InsertBefore(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBaseFileSystem::CSearchPath *m_pMemory; // ecx
  int v6; // eax
  CBaseFileSystem::CSearchPath *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CBaseFileSystem::CSearchPath::CSearchPath(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10006DC0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::Purge(CUtlVector<char,CUtlMemory<char,int> > *this)
{
  bool v2; // sf
  char *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
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
// Address: 0x10006E10
// Name: public: bool CUtlVector<class CPackFile __near *,class CUtlMemory<class CPackFile __near *,int>>::FindAndRemove(class CPackFile __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CPackFile *,CUtlMemory<CPackFile *,int>>::FindAndRemove(
        CUtlVector<CPackFile *,CUtlMemory<CPackFile *,int> > *this,
        CPackFile **src)
{
  int m_Size; // edx
  int v4; // eax
  CPackFile **m_pMemory; // ebx
  CPackFile **i; // ecx
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
// Address: 0x10006E80
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertBefore(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10006EF0
// Name: public: int CUtlVector<class CBaseFileSystem::COpenedFile,class CUtlMemory<class CBaseFileSystem::COpenedFile,int>>::InsertBefore(int,class CBaseFileSystem::COpenedFile const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int>>::InsertBefore(
        CUtlVector<CBaseFileSystem::COpenedFile,CUtlMemory<CBaseFileSystem::COpenedFile,int> > *this,
        int elem,
        const CBaseFileSystem::COpenedFile *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBaseFileSystem::COpenedFile *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<__int64,int>::Grow((CUtlMemory<__int64,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  CopyConstruct<CBaseFileSystem::COpenedFile>(pMemory: &this->m_Memory.m_pMemory[elem], src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10006F60
// Name: public: int CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>>::InsertBefore(int,class CStoreIDEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>>::InsertBefore(
        CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *this,
        int elem,
        const CStoreIDEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CStoreIDEntry *m_pMemory; // ecx
  int v7; // eax
  CStoreIDEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<__int64,int>::Grow((CUtlMemory<__int64,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10007690
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbol,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10007700
// Name: public: int CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10007770
// Name: public: void CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::RemoveAll(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CPackFile *m_pPackFile; // esi
  CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *v4; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      m_pPackFile = this->m_Memory.m_pMemory[v2].m_pPackFile;
      if ( m_pPackFile != nullptr && _InterlockedDecrement(&m_pPackFile->m_iRefs) == 0 )
      {
        if ( m_pPackFile->OnFinalRelease(this: m_pPackFile) )
          ((void (__thiscall *)(CPackFile *, int))m_pPackFile->dtr_CRefCountServiceBase<1,CRefMT>)(
            a1: m_pPackFile,
            a2: 1);
        this = v4;
      }
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008890
// Name: public: void CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::FastRemove(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        int elem)
{
  int v3; // esi
  CPackFile *m_pPackFile; // ebx
  int m_Size; // eax
  CBaseFileSystem::CSearchPath *m_pMemory; // ecx
  __int64 v7; // xmm0_8
  CBaseFileSystem::CSearchPath *v8; // eax

  v3 = elem;
  m_pPackFile = this->m_Memory.m_pMemory[elem].m_pPackFile;
  if ( m_pPackFile != nullptr
    && _InterlockedDecrement(&m_pPackFile->m_iRefs) == 0
    && m_pPackFile->OnFinalRelease(this: m_pPackFile) )
  {
    ((void (__thiscall *)(CPackFile *, int))m_pPackFile->dtr_CRefCountServiceBase<1,CRefMT>)(a1: m_pPackFile, a2: 1);
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v7 = *(_QWORD *)&this->m_Memory.m_pMemory[m_Size - 1].m_storeId;
      v8 = &this->m_Memory.m_pMemory[m_Size - 1];
      *(_QWORD *)&m_pMemory[elem].m_storeId = v7;
      *(_QWORD *)&m_pMemory[v3].m_bIsDvdDevPath = *(_QWORD *)&v8->m_bIsDvdDevPath;
      *(_QWORD *)&m_pMemory[v3].m_pPackFile = *(_QWORD *)&v8->m_pPackFile;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008920
// Name: public: void CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::Remove(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        int elem)
{
  CPackFile *m_pPackFile; // ebx

  m_pPackFile = this->m_Memory.m_pMemory[elem].m_pPackFile;
  if ( m_pPackFile != nullptr
    && _InterlockedDecrement(&m_pPackFile->m_iRefs) == 0
    && m_pPackFile->OnFinalRelease(this: m_pPackFile) )
  {
    ((void (__thiscall *)(CPackFile *, int))m_pPackFile->dtr_CRefCountServiceBase<1,CRefMT>)(a1: m_pPackFile, a2: 1);
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 24 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1000A700
// Name: public: CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::~CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::~CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this)
{
  bool v2; // sf
  CBaseFileSystem::CSearchPath *m_pMemory; // eax

  CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::RemoveAll(this);
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
// Address: 0x1000A830
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
// Address: 0x1000AB80
// Name: public: class CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>> __near & CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>>::operator=(class CUtlVector<class CBaseFileSystem::CSearchPath,class CUtlMemory<class CBaseFileSystem::CSearchPath,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *__thiscall CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::operator=(
        CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *this,
        const CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int> > *other)
{
  int m_Size; // ebx
  int v4; // esi
  int i; // edx
  CBaseFileSystem::CSearchPath *v6; // eax
  CBaseFileSystem::CSearchPath *v7; // ecx

  m_Size = other->m_Size;
  CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::RemoveAll(this);
  CUtlVector<CBaseFileSystem::CSearchPath,CUtlMemory<CBaseFileSystem::CSearchPath,int>>::InsertMultipleBefore(
    this,
    elem: this->m_Size,
    num: m_Size);
  if ( m_Size > 0 )
  {
    v4 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v6 = &other->m_Memory.m_pMemory[v4];
      v7 = &this->m_Memory.m_pMemory[v4];
      v7->m_storeId = v6->m_storeId;
      v7->m_pPathIDInfo = v6->m_pPathIDInfo;
      v7->m_bIsDvdDevPath = v6->m_bIsDvdDevPath;
      v7->m_Path.m_Id = v6->m_Path.m_Id;
      v7->m_pDebugPath = v6->m_pDebugPath;
      v7->m_pPackFile = v6->m_pPackFile;
      ++v4;
      v7->m_bIsLocalizedPath = v6->m_bIsLocalizedPath;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000B450
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
// Address: 0x10015E60
// Name: public: void CAsyncRequestBase::DeleteOuter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::DeleteOuter(CAsyncRequestBase *this)
{
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation > ASYNC_OP_UNDEFINED )
    {
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        return;
      }
      if ( m_Operation == ASYNC_OP_SCANDIR )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
        return;
      }
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015EB0
// Name: public: virtual void CAsyncFileRequest::SetUserBuffer(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::SetUserBuffer(CAsyncFileRequest *this, void *pDataBuffer, unsigned int nBufferSize)
{
  this->m_pUserProvidedDataBuffer = pDataBuffer;
  this->m_nUserProvidedBufferSize = nBufferSize;
  this->m_bDeleteBufferMemory = false;
}

//------------------------------------------------------------------------------
// Address: 0x10015ED0
// Name: public: virtual void CAsyncFileRequest::ProvideDataBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::ProvideDataBuffer(CAsyncFileRequest *this)
{
  this->m_pUserProvidedDataBuffer = nullptr;
  this->m_nUserProvidedBufferSize = 0;
  this->m_bDeleteBufferMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x10015EE0
// Name: public: virtual void CAsyncFileRequest::ReadFileDataAt(__int64,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::ReadFileDataAt(CAsyncFileRequest *this, __int64 nOffset, unsigned int nReadSize)
{
  this->m_nFileSeekOffset = nOffset;
  this->m_nMaxIOSizeInBytes = nReadSize;
}

//------------------------------------------------------------------------------
// Address: 0x10015F00
// Name: public: virtual void CAsyncFileRequest::WriteFileDataAt(__int64,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::WriteFileDataAt(CAsyncFileRequest *this, __int64 nOffset, unsigned int nWriteSize)
{
  LODWORD(this->m_nFileSeekOffset) = nOffset;
  LODWORD(this->m_nMaxIOSizeInBytes) = nWriteSize;
  HIDWORD(this->m_nFileSeekOffset) = HIDWORD(nOffset);
  HIDWORD(this->m_nMaxIOSizeInBytes) = 0;
  this->m_bDeleteBufferMemory = false;
}

//------------------------------------------------------------------------------
// Address: 0x10015F30
// Name: public: enum AsyncRequestStatus_t CAsyncFileRequest::ValidateSubmittedRequest(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncFileRequest::ValidateSubmittedRequest(CAsyncFileRequest *this, bool bPerformSync)
{
  AsyncFileOperation_t m_Operation; // eax

  if ( this->GetFileName(this) == nullptr )
    return -97;
  if ( this->GetUserBuffer(this) != nullptr && this->GetUserBufferSize(this) == 0 )
    return -96;
  m_Operation = this->m_Base.m_Operation;
  if ( (m_Operation == ASYNC_OP_WRITEFILE || m_Operation == ASYNC_OP_APPENDFILE) && this->GetUserBuffer(this) == nullptr )
    return -95;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015FA0
// Name: public: virtual void CAsyncSearchRequest::SetSearchFilespec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetSearchFilespec(CAsyncSearchRequest *this, const char *pFullSearchSpec)
{
  _V_strcpy(dest: this->m_SearchSpec, src: pFullSearchSpec);
  this->m_Base.m_Operation = ASYNC_OP_SCANDIR;
}

//------------------------------------------------------------------------------
// Address: 0x10015FD0
// Name: public: virtual void CAsyncSearchRequest::SetSearchPathAndFileSpec(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetSearchPathAndFileSpec(
        CAsyncSearchRequest *this,
        const char *pPathId,
        const char *pRelativeSearchSpec)
{
  char *m_FileSpec; // ebx
  const char *v5; // eax
  char pFixedupPath[260]; // [esp+Ch] [ebp-208h] BYREF
  char pTempPath[260]; // [esp+110h] [ebp-104h] BYREF

  m_FileSpec = this->m_FileSpec;
  v5 = V_UnqualifiedFileName(in: pRelativeSearchSpec);
  _V_strcpy(dest: m_FileSpec, src: v5);
  V_ExtractFilePath(path: pRelativeSearchSpec, dest: this->m_SearchPath, destSize: 260);
  V_StripTrailingSlash(ppath: this->m_SearchPath);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: this->m_SearchPath,
    a3: pPathId,
    a4: pTempPath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  V_FixupPathName(pOut: pFixedupPath, nOutLen: 0x104u, pPath: pTempPath);
  V_ComposeFileName(path: pFixedupPath, filename: m_FileSpec, dest: this->m_SearchSpec, destSize: 260);
  this->m_Base.m_Operation = ASYNC_OP_SCANDIR;
}

//------------------------------------------------------------------------------
// Address: 0x10016080
// Name: public: virtual void CAsyncSearchRequest::SetSearchPathAndFileSpec(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetSearchPathAndFileSpec(
        CAsyncSearchRequest *this,
        const char *pPathId,
        const char *pRelativeSearchPath,
        const char *pSearchSpec)
{
  char *m_FileSpec; // ebx
  char pFixedupPath[260]; // [esp+Ch] [ebp-208h] BYREF
  char pTempPath[260]; // [esp+110h] [ebp-104h] BYREF

  m_FileSpec = this->m_FileSpec;
  _V_strcpy(dest: this->m_FileSpec, src: pSearchSpec);
  _V_strcpy(dest: this->m_SearchPath, src: pRelativeSearchPath);
  V_StripTrailingSlash(ppath: this->m_SearchPath);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: this->m_SearchPath,
    a3: pPathId,
    a4: pTempPath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  V_FixupPathName(pOut: pFixedupPath, nOutLen: 0x104u, pPath: pTempPath);
  V_ComposeFileName(path: pFixedupPath, filename: m_FileSpec, dest: this->m_SearchSpec, destSize: 260);
  this->m_Base.m_Operation = ASYNC_OP_SCANDIR;
}

//------------------------------------------------------------------------------
// Address: 0x10016120
// Name: public: virtual void CAsyncSearchRequest::SetSubdirectoryScan(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetSubdirectoryScan(CAsyncSearchRequest *this, bool bInclude)
{
  this->m_bRecurseSubdirs = bInclude;
}

//------------------------------------------------------------------------------
// Address: 0x10016130
// Name: public: virtual void __near * CAsyncFileSystem::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAsyncFileSystem *__thiscall CAsyncFileSystem::QueryInterface(CAsyncFileSystem *this, const char *pInterfaceName)
{
  int v3; // eax

  v3 = _V_strlen(str: "VNewAsyncFileSystem001");
  return V_strncmp(s1: pInterfaceName, s2: "VNewAsyncFileSystem001", count: v3 + 1) == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016160
// Name: private: static void __near * CAsyncFileSystem::OldAsyncAllocatorCallback(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CAsyncFileSystem::OldAsyncAllocatorCallback(const char *pszFilename, unsigned int nBytes)
{
  return g_pAsyncFileSystem->AllocateBuffer(this: g_pAsyncFileSystem, a2: nBytes, a3: 16);
}

//------------------------------------------------------------------------------
// Address: 0x10016180
// Name: public: virtual void __near * CAsyncFileSystem::AllocateBuffer(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CAsyncFileSystem::AllocateBuffer(
        CAsyncFileSystem *this,
        unsigned int nBufferSize,
        unsigned int nAlignment)
{
  unsigned int v3; // eax
  void *result; // eax
  unsigned int v5; // esi

  v3 = nAlignment;
  if ( ((nAlignment - 1) & nAlignment) != 0 )
    return nullptr;
  if ( nAlignment <= 4 )
    v3 = 4;
  v5 = v3 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v3 - 1 + nBufferSize + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v5 & ((unsigned int)result + v5 + 4)) - 4) = result;
    return (void *)(~v5 & ((unsigned int)result + v5 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100161E0
// Name: public: virtual void CAsyncFileSystem::ReleaseBuffer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::ReleaseBuffer(CAsyncFileSystem *this, unsigned int pBuffer)
{
  if ( pBuffer != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((pBuffer & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x10016210
// Name: public: void CAsyncRequestBase::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::Release(CAsyncRequestBase *this)
{
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // eax

  if ( this->m_RequestState != ASYNC_REQUEST_STATE_COMPLETED )
  {
    _Error(a1: "Async Request has not finished, unable to release");
    return;
  }
  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation > ASYNC_OP_UNDEFINED )
    {
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        return;
      }
      if ( m_Operation == ASYNC_OP_SCANDIR )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
        return;
      }
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016260
// Name: public: void CAsyncRequestBase::AbortAfterServicing(struct CAsyncResultInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::AbortAfterServicing(CAsyncRequestBase *this, CAsyncResultInfo_t *results)
{
  int (__thiscall ***m_pOuter)(void *); // esi
  AsyncFileOperation_t m_Operation; // ecx

  m_pOuter = (int (__thiscall ***)(void *))this->m_pOuter;
  if ( this->m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation <= ASYNC_OP_UNDEFINED )
    {
LABEL_5:
      _Error(a1: "Bad Outer in CAsyncRequestBase::AbortAfterServicing");
      return;
    }
    if ( m_Operation > ASYNC_OP_APPENDFILE )
    {
      if ( m_Operation == ASYNC_OP_SCANDIR )
        return;
      goto LABEL_5;
    }
    if ( (**m_pOuter)(a1: m_pOuter) == 1 && m_pOuter[16] == nullptr && results->m_pAllocatedBuffer != nullptr )
      free(pMem: results->m_pAllocatedBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100162C0
// Name: public: enum AsyncRequestStatus_t CAsyncRequestBase::ValidateSubmittedRequest(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncRequestBase::ValidateSubmittedRequest(CAsyncRequestBase *this, bool bPerformSync)
{
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation > ASYNC_OP_UNDEFINED )
    {
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
        return CAsyncFileRequest::ValidateSubmittedRequest(this: (CAsyncFileRequest *)m_pOuter, bPerformSync);
      if ( m_Operation == ASYNC_OP_SCANDIR )
        return _V_strlen(str: (const char *)m_pOuter + 88) >= 1 ? 0 : 0xFFFFFFA8;
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::ValidateSubmittedRequest");
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016320
// Name: public: virtual void CAsyncFileRequest::LoadFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::LoadFile(CAsyncFileRequest *this, const char *pFileName)
{
  if ( this->m_pFileName != nullptr )
    free(pMem: (void *)this->m_pFileName);
  if ( pFileName != nullptr )
    this->m_pFileName = MemAlloc_StrDup(pString: pFileName);
  else
    this->m_pFileName = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_READFILE;
}

//------------------------------------------------------------------------------
// Address: 0x10016370
// Name: public: virtual void CAsyncFileRequest::SaveFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::SaveFile(CAsyncFileRequest *this, const char *pFileName)
{
  if ( this->m_pFileName != nullptr )
    free(pMem: (void *)this->m_pFileName);
  if ( pFileName != nullptr )
    this->m_pFileName = MemAlloc_StrDup(pString: pFileName);
  else
    this->m_pFileName = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_WRITEFILE;
}

//------------------------------------------------------------------------------
// Address: 0x100163C0
// Name: public: virtual void CAsyncFileRequest::AppendFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::AppendFile(CAsyncFileRequest *this, const char *pFileName)
{
  if ( this->m_pFileName != nullptr )
    free(pMem: (void *)this->m_pFileName);
  if ( pFileName != nullptr )
    this->m_pFileName = MemAlloc_StrDup(pString: pFileName);
  else
    this->m_pFileName = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_APPENDFILE;
}

//------------------------------------------------------------------------------
// Address: 0x10016410
// Name: public: virtual void CAsyncFileRequest::SetFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::SetFileName(CAsyncFileRequest *this, const char *pFileName)
{
  if ( this->m_pFileName != nullptr )
    free(pMem: (void *)this->m_pFileName);
  if ( pFileName != nullptr )
    this->m_pFileName = MemAlloc_StrDup(pString: pFileName);
  else
    this->m_pFileName = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016450
// Name: public: bool CAsyncRequestQueue::IsInQueue(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncRequestQueue::IsInQueue(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pHead; // eax
  bool v5; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pItem != nullptr && (m_pHead = this->m_pHead) != nullptr )
  {
    do
    {
      if ( m_pHead == pItem )
      {
        v5 = this->m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)this, 0);
        return 1;
      }
      m_pHead = m_pHead->m_pNext;
    }
    while ( m_pHead != nullptr );
    v5 = this->m_Mutex.m_depth-- == 1;
    if ( !v5 )
      return 0;
    _InterlockedExchange((volatile __int32 *)this, 0);
    return 0;
  }
  else
  {
    v5 = this->m_Mutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100164E0
// Name: public: bool CAsyncRequestQueue::IsInQueueIp(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncRequestQueue::IsInQueueIp(CAsyncRequestQueue *this, const IAsyncRequestBase *pInterfaceBase)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pHead; // eax
  bool v5; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pInterfaceBase != nullptr && (m_pHead = this->m_pHead) != nullptr )
  {
    do
    {
      if ( (const IAsyncRequestBase *)m_pHead->m_pOuter == pInterfaceBase )
      {
        v5 = this->m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)this, 0);
        return 1;
      }
      m_pHead = m_pHead->m_pNext;
    }
    while ( m_pHead != nullptr );
    v5 = this->m_Mutex.m_depth-- == 1;
    if ( !v5 )
      return 0;
    _InterlockedExchange((volatile __int32 *)this, 0);
    return 0;
  }
  else
  {
    v5 = this->m_Mutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016570
// Name: public: void CAsyncRequestQueue::AddToHead(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::AddToHead(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( this->m_pHead != nullptr )
  {
    pItem->m_pPrev = nullptr;
    pItem->m_pNext = this->m_pHead;
    this->m_pHead = pItem;
    pItem->m_pNext->m_pPrev = pItem;
    ++this->m_nQueueSize;
  }
  else
  {
    this->m_pTail = pItem;
    this->m_pHead = pItem;
    pItem->m_pPrev = nullptr;
    pItem->m_pNext = nullptr;
    this->m_nQueueSize = 1;
  }
  if ( this->m_Mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016600
// Name: public: void CAsyncRequestQueue::AddToTail(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::AddToTail(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pTail; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  m_pTail = this->m_pTail;
  if ( m_pTail != nullptr )
  {
    pItem->m_pPrev = m_pTail;
    pItem->m_pNext = nullptr;
    this->m_pTail = pItem;
    pItem->m_pPrev->m_pNext = pItem;
    ++this->m_nQueueSize;
  }
  else
  {
    this->m_pTail = pItem;
    this->m_pHead = pItem;
    pItem->m_pPrev = nullptr;
    pItem->m_pNext = nullptr;
    this->m_nQueueSize = 1;
  }
  if ( this->m_Mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016680
// Name: public: void CAsyncRequestQueue::InsertBefore(class CAsyncRequestBase __near *,class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::InsertBefore(
        CAsyncRequestQueue *this,
        CAsyncRequestBase *pItem,
        CAsyncRequestBase *pInsertAt)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pPrev; // eax
  bool v6; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pInsertAt == nullptr
    || this->m_nQueueSize == 0
    || pItem == nullptr
    || CAsyncRequestQueue::IsInQueue(this, pItem: pInsertAt) == 0 )
  {
    v6 = this->m_Mutex.m_depth-- == 1;
    if ( !v6 )
      return;
    goto LABEL_15;
  }
  if ( pInsertAt == this->m_pHead )
  {
    CAsyncRequestQueue::AddToHead(this, pItem);
  }
  else
  {
    m_pPrev = pInsertAt->m_pPrev;
    m_pPrev->m_pNext = pItem;
    pInsertAt->m_pPrev = pItem;
    pItem->m_pPrev = m_pPrev;
    pItem->m_pNext = pInsertAt;
    ++this->m_nQueueSize;
  }
  v6 = this->m_Mutex.m_depth-- == 1;
  if ( v6 )
LABEL_15:
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016720
// Name: public: void CAsyncRequestQueue::PriorityInsert(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::PriorityInsert(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx
  bool v4; // zf
  CAsyncRequestBase *m_pHead; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pItem != nullptr )
  {
    m_pHead = this->m_pHead;
    if ( m_pHead != nullptr )
    {
      while ( m_pHead->m_priority >= pItem->m_priority )
      {
        m_pHead = m_pHead->m_pNext;
        if ( m_pHead == nullptr )
          goto LABEL_11;
      }
      CAsyncRequestQueue::InsertBefore(this, pItem, pInsertAt: m_pHead);
    }
    else
    {
LABEL_11:
      CAsyncRequestQueue::AddToTail(this, pItem);
    }
    v4 = this->m_Mutex.m_depth-- == 1;
    if ( v4 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
  else
  {
    v4 = this->m_Mutex.m_depth-- == 1;
    if ( v4 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100167B0
// Name: public: void CAsyncRequestQueue::Remove(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::Remove(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pPrev; // eax
  CAsyncRequestBase *m_pNext; // eax
  bool v6; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pItem == nullptr || this->m_nQueueSize == 0 || CAsyncRequestQueue::IsInQueue(this, pItem) == 0 )
  {
    v6 = this->m_Mutex.m_depth-- == 1;
    if ( !v6 )
      return;
    goto LABEL_19;
  }
  if ( this->m_nQueueSize == 1 )
  {
    this->m_pTail = nullptr;
    this->m_pHead = nullptr;
  }
  else
  {
    m_pPrev = pItem->m_pPrev;
    if ( m_pPrev != nullptr )
      m_pPrev->m_pNext = pItem->m_pNext;
    else
      this->m_pHead = pItem->m_pNext;
    m_pNext = pItem->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = pItem->m_pPrev;
    else
      this->m_pTail = pItem->m_pPrev;
  }
  --this->m_nQueueSize;
  pItem->m_pNext = nullptr;
  pItem->m_pPrev = nullptr;
  v6 = this->m_Mutex.m_depth-- == 1;
  if ( v6 )
LABEL_19:
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016870
// Name: public: class CAsyncRequestBase __near * CAsyncRequestQueue::RemoveHead(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncRequestBase *__thiscall CAsyncRequestQueue::RemoveHead(CAsyncRequestQueue *this)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pHead; // edi
  bool v4; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( this->m_nQueueSize != 0 && (m_pHead = this->m_pHead) != nullptr )
  {
    CAsyncRequestQueue::Remove(this, pItem: this->m_pHead);
    v4 = this->m_Mutex.m_depth-- == 1;
    if ( v4 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    return m_pHead;
  }
  else
  {
    v4 = this->m_Mutex.m_depth-- == 1;
    if ( v4 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100168F0
// Name: public: bool CAsyncFileSystem::ResolveAsyncRequest(class IAsyncRequestBase const __near *,class CAsyncRequestBase __near * __near &,enum AsyncRequestState_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncFileSystem::ResolveAsyncRequest(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest,
        CAsyncRequestBase **pRequestBase,
        AsyncRequestState_t *CurrentStage)
{
  if ( CAsyncRequestQueue::IsInQueueIp(this: &this->m_Composing, pInterfaceBase: pRequest) != 0 )
  {
    *pRequestBase = pRequest->GetBase(this: pRequest);
    *CurrentStage = ASYNC_REQUEST_STATE_COMPOSING;
    return 1;
  }
  else if ( CAsyncRequestQueue::IsInQueueIp(this: &this->m_Submitted, pInterfaceBase: pRequest) != 0 )
  {
    *pRequestBase = pRequest->GetBase(this: pRequest);
    *CurrentStage = ASYNC_REQUEST_STATE_SUBMITTED;
    return 1;
  }
  else if ( CAsyncRequestQueue::IsInQueueIp(this: &this->m_InFlight, pInterfaceBase: pRequest) != 0 )
  {
    *pRequestBase = pRequest->GetBase(this: pRequest);
    *CurrentStage = ASYNC_REQUEST_STATE_SERVICING;
    return 1;
  }
  else if ( CAsyncRequestQueue::IsInQueueIp(this: &this->m_Completed, pInterfaceBase: pRequest) != 0 )
  {
    *pRequestBase = pRequest->GetBase(this: pRequest);
    *CurrentStage = pRequest->GetRequestState(this: pRequest);
    return 1;
  }
  else
  {
    *pRequestBase = nullptr;
    *CurrentStage = ASYNC_REQUEST_STATE_UNDEFINED;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100169D0
// Name: public: void CAsyncFileSystem::RemoveRequest(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::RemoveRequest(CAsyncFileSystem *this, CAsyncRequestBase *pRequest)
{
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  switch ( pRequest->m_RequestState )
  {
    case ASYNC_REQUEST_STATE_COMPOSING:
      CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: pRequest);
      break;
    case ASYNC_REQUEST_STATE_SUBMITTED:
      CAsyncRequestQueue::Remove(this: &this->m_Submitted, pItem: pRequest);
      break;
    case ASYNC_REQUEST_STATE_SERVICING:
      CAsyncRequestQueue::Remove(this: &this->m_InFlight, pItem: pRequest);
      break;
    case ASYNC_REQUEST_STATE_AWATING_FINISH:
    case ASYNC_REQUEST_STATE_COMPLETED:
      CAsyncRequestQueue::Remove(this: &this->m_Completed, pItem: pRequest);
      break;
    default:
      _Error(a1: " Couldn't Find Async Request to Remove");
      break;
  }
  if ( p_m_AsyncStateUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10016A80
// Name: public: bool CAsyncFileSystem::ValidateRequestPtr(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncFileSystem::ValidateRequestPtr(CAsyncFileSystem *this, CAsyncRequestBase *pRequest)
{
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v5; // zf
  bool result; // al

  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  switch ( pRequest->m_RequestState )
  {
    case ASYNC_REQUEST_STATE_COMPOSING:
      if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Composing, pItem: pRequest) == 0 )
        goto $LN8;
      goto LABEL_7;
    case ASYNC_REQUEST_STATE_SUBMITTED:
$LN8:
      if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Submitted, pItem: pRequest) == 0 )
        goto $LN6;
      v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( v5 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      return true;
    case ASYNC_REQUEST_STATE_SERVICING:
$LN6:
      if ( CAsyncRequestQueue::IsInQueue(this: &this->m_InFlight, pItem: pRequest) == 0 )
        goto $LN4_2;
      v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( v5 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      return true;
    case ASYNC_REQUEST_STATE_AWATING_FINISH:
    case ASYNC_REQUEST_STATE_COMPLETED:
$LN4_2:
      if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Completed, pItem: pRequest) == 0 )
        goto LABEL_19;
LABEL_7:
      v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( v5 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      result = true;
      break;
    default:
LABEL_19:
      v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( v5 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016C10
// Name: public: void CAsyncRequestBase::ProcessCallback(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::ProcessCallback(CAsyncRequestBase *this, bool bRelease)
{
  CFunctor *m_pCallback; // ecx

  if ( this->m_RequestState == ASYNC_REQUEST_STATE_AWATING_FINISH )
  {
    m_pCallback = this->m_pCallback;
    if ( m_pCallback != nullptr )
    {
      this->m_bProcessingCallback = true;
      m_pCallback->operator()(this: m_pCallback);
      this->m_pCallback->Release(this: this->m_pCallback);
      this->m_pCallback = nullptr;
      this->m_bProcessingCallback = false;
    }
    this->m_RequestState = ASYNC_REQUEST_STATE_COMPLETED;
    if ( bRelease && !this->m_bDontAutoRelease )
      CAsyncRequestBase::Release(this);
  }
  else
  {
    _Error(a1: "Callback called at wrong time");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016C80
// Name: public: void CAsyncRequestBase::UpdateAfterServicing(struct CAsyncResultInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::UpdateAfterServicing(CAsyncRequestBase *this, CAsyncResultInfo_t *results)
{
  _DWORD *m_pOuter; // eax
  AsyncFileOperation_t m_Operation; // ecx
  bool v4; // zf
  int m_nBytesTransferred; // ecx

  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation <= ASYNC_OP_UNDEFINED )
    {
LABEL_10:
      _Error(a1: "Bad Outer in CAsyncRequestBase::UpdateAfterServicing");
      return;
    }
    if ( m_Operation > ASYNC_OP_APPENDFILE )
    {
      if ( m_Operation == ASYNC_OP_SCANDIR )
      {
        m_pOuter[15] = m_pOuter[20];
        return;
      }
      goto LABEL_10;
    }
    v4 = m_pOuter[16] == 0;
    m_pOuter[22] = results->m_pAllocatedBuffer;
    if ( v4 )
      m_nBytesTransferred = results->m_nBytesTransferred;
    else
      m_nBytesTransferred = m_pOuter[17];
    m_pOuter[23] = m_nBytesTransferred;
    m_pOuter[24] = results->m_nBytesTransferred;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016CF0
// Name: public: virtual class IAsyncRequestBase __near * CAsyncGroupRequest::GetAsyncRequest(int)
// Source: json
//------------------------------------------------------------------------------
IAsyncRequestBase *__thiscall CAsyncGroupRequest::GetAsyncRequest(CAsyncGroupRequest *this, int nRNum)
{
  if ( nRNum < 0 || nRNum >= this->m_RequestList.m_Size )
    return nullptr;
  else
    return this->m_RequestList.m_Memory.m_pMemory[nRNum];
}

//------------------------------------------------------------------------------
// Address: 0x10016D10
// Name: public: virtual class IAsyncFileRequest __near * CAsyncGroupRequest::GetAsyncFileRequest(int)
// Source: json
//------------------------------------------------------------------------------
IAsyncFileRequest *__thiscall CAsyncGroupRequest::GetAsyncFileRequest(CAsyncGroupRequest *this, int nRNum)
{
  IAsyncRequestBase *v2; // esi
  int v3; // eax

  if ( nRNum < 0 || nRNum >= this->m_RequestList.m_Size )
    return nullptr;
  v2 = this->m_RequestList.m_Memory.m_pMemory[nRNum];
  v3 = v2->GetAsyncOperationType(this: v2);
  if ( v3 == 1 || v3 == 2 || v3 == 3 )
    return (IAsyncFileRequest *)v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016D60
// Name: public: virtual class IAsyncSearchRequest __near * CAsyncGroupRequest::GetAsyncSearchRequest(int)
// Source: json
//------------------------------------------------------------------------------
IAsyncSearchRequest *__thiscall CAsyncGroupRequest::GetAsyncSearchRequest(CAsyncGroupRequest *this, int nRNum)
{
  IAsyncRequestBase *v2; // esi

  if ( nRNum < 0 || nRNum >= this->m_RequestList.m_Size )
    return nullptr;
  v2 = this->m_RequestList.m_Memory.m_pMemory[nRNum];
  return v2->GetAsyncOperationType(this: v2) == 4 ? (IAsyncSearchRequest *)v2 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016DA0
// Name: public: CAsyncFileRequest::CAsyncFileRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncFileRequest *__thiscall CAsyncFileRequest::CAsyncFileRequest(CAsyncFileRequest *this)
{
  this->__vftable = (CAsyncFileRequest_vtbl *)&CAsyncFileRequest::`vftable';
  this->m_Base.m_pCallback = nullptr;
  this->m_Base.m_pResultQueue = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_UNDEFINED;
  this->m_Base.m_priority = 0;
  this->m_Base.m_pNext = nullptr;
  this->m_Base.m_pPrev = nullptr;
  this->m_Base.m_RequestState = ASYNC_REQUEST_STATE_COMPOSING;
  this->m_Base.m_RequestStatus = ASYNC_REQUEST_OK;
  *(_WORD *)&this->m_Base.m_bAbortRequest = 0;
  this->m_Base.m_bDontAutoRelease = false;
  this->m_Base.m_pSyncThreadEvent = nullptr;
  this->m_Base.m_pOldAsyncControl = nullptr;
  this->m_Base.m_pOldAsyncStatus = FSASYNC_OK;
  this->m_Base.m_pGroup = nullptr;
  this->m_Base.m_pOuter = this;
  this->m_pFileName = nullptr;
  this->m_pUserProvidedDataBuffer = nullptr;
  this->m_nUserProvidedBufferSize = 0;
  this->m_nFileSeekOffset = 0;
  this->m_nMaxIOSizeInBytes = 0;
  this->m_pResultsBuffer = nullptr;
  this->m_nResultsBufferSize = 0;
  this->m_nIOActualSize = 0;
  this->m_bDeleteBufferMemory = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016E00
// Name: public: virtual void CAsyncGroupRequest::DontKeepRequestPostCallback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::DontKeepRequestPostCallback(CAsyncSearchRequest *this)
{
  this->m_Base.m_bDontAutoRelease = false;
}

//------------------------------------------------------------------------------
// Address: 0x10016E10
// Name: public: virtual int CAsyncSearchRequest::GetResultCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncSearchRequest::GetResultCount(CAsyncSearchRequest *this)
{
  return this->m_nNumResults;
}

//------------------------------------------------------------------------------
// Address: 0x10016E20
// Name: public: virtual void __near * CAsyncFileRequest::GetUserBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CAsyncFileRequest::GetUserBuffer(CAsyncFileRequest *this)
{
  return this->m_pUserProvidedDataBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x10016E30
// Name: public: virtual unsigned int CAsyncFileRequest::GetUserBufferSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAsyncFileRequest::GetUserBufferSize(CAsyncFileRequest *this)
{
  return this->m_nUserProvidedBufferSize;
}

//------------------------------------------------------------------------------
// Address: 0x10016E40
// Name: public: virtual void __near * CAsyncFileRequest::GetResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CAsyncFileRequest::GetResultBuffer(CAsyncFileRequest *this)
{
  return this->m_pResultsBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x10016E50
// Name: public: virtual unsigned int CAsyncFileRequest::GetResultBufferSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAsyncFileRequest::GetResultBufferSize(CAsyncFileRequest *this)
{
  return this->m_nResultsBufferSize;
}

//------------------------------------------------------------------------------
// Address: 0x10016E60
// Name: public: virtual unsigned int CAsyncFileRequest::GetIOTransferredSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CAsyncFileRequest::GetIOTransferredSize(CAsyncFileRequest *this)
{
  return this->m_nIOActualSize;
}

//------------------------------------------------------------------------------
// Address: 0x10016E70
// Name: public: virtual void CAsyncFileRequest::KeepResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::KeepResultBuffer(CAsyncFileRequest *this)
{
  this->m_bDeleteBufferMemory = false;
}

//------------------------------------------------------------------------------
// Address: 0x10016E80
// Name: public: virtual void CAsyncFileRequest::ReleaseResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::ReleaseResultBuffer(CAsyncFileRequest *this)
{
  this->m_bDeleteBufferMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x10016E90
// Name: public: virtual void CAsyncGroupRequest::AssignResultQueue(class CIOCompletionQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::AssignResultQueue(CAsyncSearchRequest *this, CIOCompletionQueue *pMsgQueue)
{
  this->m_Base.m_pResultQueue = pMsgQueue;
}

//------------------------------------------------------------------------------
// Address: 0x10016EA0
// Name: public: virtual void CAsyncSearchRequest::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::Release(CAsyncSearchRequest *this)
{
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // eax

  if ( this->m_Base.m_RequestState != ASYNC_REQUEST_STATE_COMPLETED )
  {
    _Error(a1: "Async Request has not finished, unable to release");
    return;
  }
  m_pOuter = this->m_Base.m_pOuter;
  if ( m_pOuter != nullptr )
  {
    m_Operation = this->m_Base.m_Operation;
    if ( m_Operation > ASYNC_OP_UNDEFINED )
    {
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        return;
      }
      if ( m_Operation == ASYNC_OP_SCANDIR )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
        return;
      }
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016EF0
// Name: public: virtual CAsyncFileRequest::~CAsyncFileRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::~CAsyncFileRequest(CAsyncFileRequest *this)
{
  char *m_pFileName; // eax
  bool v3; // zf
  unsigned int m_pResultsBuffer; // eax
  CFunctor *m_pCallback; // ecx
  CAsyncRequestBase *p_m_Base; // esi

  m_pFileName = (char *)this->m_pFileName;
  this->__vftable = (CAsyncFileRequest_vtbl *)&CAsyncFileRequest::`vftable';
  if ( m_pFileName != nullptr )
    free(pMem: m_pFileName);
  v3 = !this->m_bDeleteBufferMemory;
  this->m_pFileName = nullptr;
  if ( !v3 )
  {
    m_pResultsBuffer = (unsigned int)this->m_pResultsBuffer;
    if ( m_pResultsBuffer != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((m_pResultsBuffer & 0xFFFFFFFC) - 4));
  }
  m_pCallback = this->m_Base.m_pCallback;
  p_m_Base = &this->m_Base;
  if ( m_pCallback != nullptr )
    m_pCallback->Release(this: m_pCallback);
  p_m_Base->m_pCallback = nullptr;
  CAsyncFileSystem::RemoveRequest(this: &g_FileSystem_Async, pRequest: p_m_Base);
}

//------------------------------------------------------------------------------
// Address: 0x10016F60
// Name: public: virtual char const __near * CAsyncSearchRequest::GetMatchedFile(int)
// Source: json
//------------------------------------------------------------------------------
CDirectoryEntryInfo_t *__thiscall CAsyncSearchRequest::GetMatchedFile(CAsyncSearchRequest *this, int rNum)
{
  AsyncRequestState_t m_RequestState; // eax

  m_RequestState = this->m_Base.m_RequestState;
  if ( m_RequestState < ASYNC_REQUEST_STATE_AWATING_FINISH
    || m_RequestState > ASYNC_REQUEST_STATE_COMPLETED
    || rNum < 0
    || rNum >= this->m_nNumResults )
  {
    return nullptr;
  }
  else
  {
    return &this->m_Results.m_Memory.m_pMemory[rNum];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016F90
// Name: public: virtual class IAsyncFileRequest __near * CAsyncFileSystem::CreateNewFileRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncFileRequest *__thiscall CAsyncFileSystem::CreateNewFileRequest(CAsyncFileSystem *this)
{
  CAsyncFileRequest *v2; // eax
  CAsyncFileRequest *v3; // esi

  v2 = (CAsyncFileRequest *)operator new(nSize: 0x68u);
  if ( v2 != nullptr )
  {
    v3 = CAsyncFileRequest::CAsyncFileRequest(this: v2);
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: &v3->m_Base);
    return v3;
  }
  else
  {
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: (CAsyncRequestBase *)4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016FD0
// Name: public: virtual void CAsyncFileSystem::ReleaseAsyncRequest(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::ReleaseAsyncRequest(CAsyncFileSystem *this, const IAsyncRequestBase *pRequest)
{
  CAsyncRequestBase *v3; // edi
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v6; // zf

  v3 = pRequest->GetBase(this: pRequest);
  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  if ( !CAsyncFileSystem::ValidateRequestPtr(this, pRequest: v3) )
  {
    _Error(a1: "Bad Release Request");
    goto LABEL_14;
  }
  if ( v3->m_RequestState == ASYNC_REQUEST_STATE_SERVICING )
  {
    v3->m_bAbortRequest = true;
    v6 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( !v6 )
      return;
  }
  else
  {
    if ( !v3->m_bProcessingCallback )
    {
      CAsyncRequestBase::DeleteOuter(this: v3);
LABEL_14:
      v6 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( !v6 )
        return;
      goto LABEL_15;
    }
    v3->m_bDontAutoRelease = false;
    v6 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( !v6 )
      return;
  }
LABEL_15:
  _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10017090
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::GetAsyncFileRequestStatus(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::GetAsyncFileRequestStatus(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest)
{
  CAsyncRequestBase *v3; // esi
  bool v4; // zf
  AsyncRequestStatus_t result; // eax

  v3 = pRequest->GetBase(this: pRequest);
  v4 = !CAsyncFileSystem::ValidateRequestPtr(this, pRequest: v3);
  result = ASYNC_REQUEST_ERROR_BADPTR;
  if ( !v4 )
    return v3->m_RequestStatus;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100170C0
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::AbortAsyncFileRequest(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::AbortAsyncFileRequest(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest)
{
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v5; // zf
  AsyncRequestStatus_t result; // eax
  CAsyncRequestBase *pRequestBase; // [esp+8h] [ebp-8h] BYREF
  AsyncRequestState_t CurrentStage; // [esp+Ch] [ebp-4h] BYREF

  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  pRequestBase = nullptr;
  CurrentStage = ASYNC_REQUEST_STATE_UNDEFINED;
  if ( CAsyncFileSystem::ResolveAsyncRequest(this, pRequest, &pRequestBase, &CurrentStage) != 0 )
  {
    switch ( CurrentStage )
    {
      case ASYNC_REQUEST_STATE_COMPOSING:
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        result = ASYNC_REQUEST_ERROR_NOTSUBMITTED;
        break;
      case ASYNC_REQUEST_STATE_SUBMITTED:
        CAsyncRequestBase::DeleteOuter(this: pRequestBase);
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        result = ASYNC_REQUEST_OK;
        break;
      case ASYNC_REQUEST_STATE_SERVICING:
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        result = ASYNC_REQUEST_ERROR_NOTSUBMITTED;
        break;
      case ASYNC_REQUEST_STATE_AWATING_FINISH:
      case ASYNC_REQUEST_STATE_COMPLETED:
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        result = ASYNC_REQUEST_ERROR_ALREADYSERVICED;
        break;
      default:
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        return ASYNC_REQUEST_ERROR_BADPTR;
    }
  }
  else
  {
    v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( v5 )
    {
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      return ASYNC_REQUEST_ERROR_BADPTR;
    }
    else
    {
      return ASYNC_REQUEST_ERROR_BADPTR;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100171E0
// Name: public: virtual void CAsyncFileSystem::SuspendAllAsyncIO(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::SuspendAllAsyncIO(CAsyncFileSystem *this, bool bWaitForIOCompletion)
{
  _InterlockedExchangeAdd(&this->m_nSuspendCount.m_value, 1u);
  if ( bWaitForIOCompletion && this->m_nSuspendCount.m_value > 0 && this->m_nJobsInflight.m_value > 0 )
  {
    do
      CThreadEvent::Wait(this: &this->m_CompletionSignal, a2: 0xAu);
    while ( this->m_nJobsInflight.m_value > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017230
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::AbortAllAsyncIO(bool)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::AbortAllAsyncIO(CAsyncFileSystem *this, bool bWaitForIOCompletion)
{
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v5; // zf
  DWORD v7; // ecx
  CAsyncRequestBase *m_pHead; // edi
  void *m_pOuter; // ecx
  int m_Operation; // eax
  DWORD v11; // ecx
  CAsyncRequestBase *v12; // edi

  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  if ( this->m_Submitted.m_nQueueSize > 0 )
  {
    while ( 1 )
    {
LABEL_11:
      v7 = GetCurrentThreadId();
      if ( v7 != this->m_Submitted.m_Mutex.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_Submitted, v7, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &this->m_Submitted, a2: v7, a3: 0);
      }
      else
      {
        ++this->m_Submitted.m_Mutex.m_depth;
      }
      if ( this->m_Submitted.m_nQueueSize != 0 && (m_pHead = this->m_Submitted.m_pHead) != nullptr )
      {
        CAsyncRequestQueue::Remove(this: &this->m_Submitted, pItem: this->m_Submitted.m_pHead);
        v5 = this->m_Submitted.m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)&this->m_Submitted, 0);
      }
      else
      {
        v5 = this->m_Submitted.m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)&this->m_Submitted, 0);
        m_pHead = nullptr;
      }
      m_pOuter = m_pHead->m_pOuter;
      if ( m_pHead->m_pOuter != nullptr )
      {
        m_Operation = m_pHead->m_Operation;
        if ( m_Operation <= 0 )
          break;
        if ( m_Operation <= 3 )
        {
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        }
        else
        {
          if ( m_Operation != 4 )
            break;
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
        }
      }
LABEL_29:
      if ( this->m_Submitted.m_nQueueSize <= 0 )
        goto LABEL_30;
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
    goto LABEL_29;
  }
  if ( this->m_nJobsInflight.m_value != 0 && bWaitForIOCompletion )
  {
    if ( this->m_Submitted.m_nQueueSize > 0 )
      goto LABEL_11;
LABEL_30:
    while ( this->m_InFlight.m_nQueueSize > 0 )
    {
      v11 = GetCurrentThreadId();
      if ( v11 != this->m_InFlight.m_Mutex.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_InFlight, v11, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &this->m_InFlight, a2: v11, a3: 0);
      }
      else
      {
        ++this->m_InFlight.m_Mutex.m_depth;
      }
      if ( this->m_InFlight.m_nQueueSize != 0 && (v12 = this->m_InFlight.m_pHead) != nullptr )
      {
        CAsyncRequestQueue::Remove(this: &this->m_InFlight, pItem: this->m_InFlight.m_pHead);
        v5 = this->m_InFlight.m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)&this->m_InFlight, 0);
      }
      else
      {
        v5 = this->m_InFlight.m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)&this->m_InFlight, 0);
        v12 = nullptr;
      }
      v12->m_bAbortRequest = true;
    }
    v5 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)&this->m_AsyncStateUpdateMutex, 0);
    if ( bWaitForIOCompletion && this->m_nJobsInflight.m_value > 0 )
    {
      do
        CThreadEvent::Wait(this: &this->m_CompletionSignal, a2: 0xAu);
      while ( this->m_nJobsInflight.m_value > 0 );
    }
  }
  else
  {
    v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( v5 )
    {
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      return ASYNC_REQUEST_OK;
    }
  }
  return ASYNC_REQUEST_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10017410
// Name: public: struct CTSQueue<struct CAsyncIOResult_t,0,1>::Node_t __near * CTSQueue<struct CAsyncIOResult_t,0,1>::Push(struct CTSQueue<struct CAsyncIOResult_t,0,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CAsyncIOResult_t,0,1>::Node_t *__thiscall CTSQueue<CAsyncIOResult_t,0,1>::Push(
        CTSQueue<CAsyncIOResult_t,0,1> *this,
        CTSQueue<CAsyncIOResult_t,0,1>::Node_t *pNode)
{
  CTSQueue<CAsyncIOResult_t,0,1>::Node_t *v3; // edi
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<CAsyncIOResult_t,0,1>::Node_t *)this;
  v3 = this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<CAsyncIOResult_t,0,1> *)_InterlockedCompareExchange(
                                            (volatile signed __int32 *)v3,
                                            (signed __int32)pNode,
                                            (signed __int32)this) != this;
        i = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: v3->pNext, a3: i + 1, a4: v3, a5: i);
    v3 = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: i + 1, a4: v3, a5: i);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100174F0
// Name: public: CAsyncRequestQueue::~CAsyncRequestQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::~CAsyncRequestQueue(CAsyncRequestQueue *this)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pHead; // esi
  CAsyncRequestBase *m_pNext; // ebx
  CFunctor *m_pCallback; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( this->m_pHead != nullptr )
  {
    _Warning(a1: " CAsyncRequestQueue destructor called while queue was not empty");
    if ( this->m_pHead != nullptr )
    {
      do
      {
        m_pHead = this->m_pHead;
        m_pNext = m_pHead->m_pNext;
        if ( m_pHead != nullptr )
        {
          m_pCallback = m_pHead->m_pCallback;
          if ( m_pCallback != nullptr )
            m_pCallback->Release(this: m_pCallback);
          m_pHead->m_pCallback = nullptr;
          CAsyncFileSystem::RemoveRequest(this: &g_FileSystem_Async, pRequest: m_pHead);
          free(pMem: m_pHead);
        }
        this->m_pHead = m_pNext;
      }
      while ( m_pNext != nullptr );
    }
  }
  if ( this->m_Mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10017590
// Name: public: CAsyncFileSystem::~CAsyncFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::~CAsyncFileSystem(CAsyncFileSystem *this)
{
  this->__vftable = (CAsyncFileSystem_vtbl *)&CAsyncFileSystem::`vftable';
  _InterlockedExchange(&this->m_nSuspendCount.m_value, 1);
  CAsyncFileSystem::AbortAllAsyncIO(this, bWaitForIOCompletion: true);
  CThreadSyncObject::~CThreadSyncObject(this: &this->m_CompletionSignal);
  CAsyncRequestQueue::~CAsyncRequestQueue(this: &this->m_Completed);
  CAsyncRequestQueue::~CAsyncRequestQueue(this: &this->m_InFlight);
  CAsyncRequestQueue::~CAsyncRequestQueue(this: &this->m_Submitted);
  CAsyncRequestQueue::~CAsyncRequestQueue(this: &this->m_Composing);
}

//------------------------------------------------------------------------------
// Address: 0x10017600
// Name: public: CUtlVector<class CZipPackFile::CPackFileEntry,class CUtlMemory<class CZipPackFile::CPackFileEntry,int>>::~CUtlVector<class CZipPackFile::CPackFileEntry,class CUtlMemory<class CZipPackFile::CPackFileEntry,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this)
{
  bool v2; // sf
  unsigned __int8 *m_pMemory; // eax

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
// Address: 0x10017670
// Name: public: int CUtlVector<struct CDirectoryEntryInfo_t,class CUtlMemory<struct CDirectoryEntryInfo_t,int>>::InsertBefore(int,struct CDirectoryEntryInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDirectoryEntryInfo_t,CUtlMemory<CDirectoryEntryInfo_t,int>>::InsertBefore(
        CUtlVector<CDirectoryEntryInfo_t,CUtlMemory<CDirectoryEntryInfo_t,int> > *this,
        int elem,
        const CDirectoryEntryInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDirectoryEntryInfo_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDirectoryEntryInfo_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 260 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100176F0
// Name: public: CAsyncGroupRequest::CAsyncGroupRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncGroupRequest *__thiscall CAsyncGroupRequest::CAsyncGroupRequest(CAsyncGroupRequest *this)
{
  this->__vftable = (CAsyncGroupRequest_vtbl *)&CAsyncGroupRequest::`vftable';
  this->m_Base.m_pOuter = nullptr;
  this->m_Base.m_pCallback = nullptr;
  this->m_Base.m_pResultQueue = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_UNDEFINED;
  this->m_Base.m_priority = 0;
  this->m_Base.m_pNext = nullptr;
  this->m_Base.m_pPrev = nullptr;
  this->m_Base.m_RequestState = ASYNC_REQUEST_STATE_COMPOSING;
  this->m_Base.m_RequestStatus = ASYNC_REQUEST_OK;
  *(_WORD *)&this->m_Base.m_bAbortRequest = 0;
  this->m_Base.m_bDontAutoRelease = false;
  this->m_Base.m_pSyncThreadEvent = nullptr;
  this->m_Base.m_pOldAsyncControl = nullptr;
  this->m_Base.m_pOldAsyncStatus = FSASYNC_OK;
  this->m_Base.m_pGroup = nullptr;
  this->m_RequestList.m_Memory.m_pMemory = nullptr;
  this->m_RequestList.m_Memory.m_nAllocationCount = 0;
  this->m_RequestList.m_Memory.m_nGrowSize = 0;
  this->m_RequestList.m_Size = 0;
  this->m_RequestList.m_pElements = nullptr;
  this->m_ValidList.m_Memory.m_pMemory = nullptr;
  this->m_ValidList.m_Memory.m_nAllocationCount = 0;
  this->m_ValidList.m_Memory.m_nGrowSize = 0;
  this->m_ValidList.m_Size = 0;
  this->m_ValidList.m_pElements = nullptr;
  this->m_nNumRequestsOutstanding.m_value = 0;
  this->m_Base.m_pOuter = this;
  _InterlockedExchange(&this->m_nNumRequestsOutstanding.m_value, 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017760
// Name: private: virtual class CAsyncRequestBase __near * CAsyncFileRequest::GetBase(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncRequestBase *__thiscall CAsyncFileRequest::GetBase(CAsyncSearchRequest *this)
{
  return &this->m_Base;
}

//------------------------------------------------------------------------------
// Address: 0x10017770
// Name: public: virtual void CAsyncSearchRequest::SetPriority(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetPriority(CAsyncSearchRequest *this, int nPriority)
{
  this->m_Base.m_priority = nPriority;
}

//------------------------------------------------------------------------------
// Address: 0x10017780
// Name: public: virtual int CAsyncGroupRequest::GetAsyncRequestCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncGroupRequest::GetAsyncRequestCount(CAsyncGroupRequest *this)
{
  return this->m_RequestList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10017790
// Name: public: virtual void CAsyncGroupRequest::ProcessCallback(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::ProcessCallback(CAsyncSearchRequest *this, bool bRelease)
{
  CAsyncRequestBase::ProcessCallback(this: &this->m_Base, bRelease);
}

//------------------------------------------------------------------------------
// Address: 0x100177A0
// Name: public: CAsyncSearchRequest::CAsyncSearchRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncSearchRequest *__thiscall CAsyncSearchRequest::CAsyncSearchRequest(CAsyncSearchRequest *this)
{
  this->__vftable = (CAsyncSearchRequest_vtbl *)&CAsyncSearchRequest::`vftable';
  this->m_Base.m_pCallback = nullptr;
  this->m_Base.m_pResultQueue = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_UNDEFINED;
  this->m_Base.m_priority = 0;
  this->m_Base.m_pNext = nullptr;
  this->m_Base.m_pPrev = nullptr;
  this->m_Base.m_RequestState = ASYNC_REQUEST_STATE_COMPOSING;
  this->m_Base.m_RequestStatus = ASYNC_REQUEST_OK;
  *(_WORD *)&this->m_Base.m_bAbortRequest = 0;
  this->m_Base.m_bDontAutoRelease = false;
  this->m_Base.m_pSyncThreadEvent = nullptr;
  this->m_Base.m_pOldAsyncControl = nullptr;
  this->m_Base.m_pOldAsyncStatus = FSASYNC_OK;
  this->m_Base.m_pGroup = nullptr;
  this->m_Results.m_Memory.m_pMemory = nullptr;
  this->m_Results.m_Memory.m_nAllocationCount = 0;
  this->m_Results.m_Memory.m_nGrowSize = 0;
  this->m_Results.m_Size = 0;
  this->m_Results.m_pElements = nullptr;
  this->m_Base.m_pOuter = this;
  _V_memset(dest: this->m_FileSpec, fill: 0, count: 260);
  _V_memset(dest: this->m_PathID, fill: 0, count: 260);
  _V_memset(dest: this->m_SearchPath, fill: 0, count: 260);
  _V_memset(dest: this->m_SearchSpec, fill: 0, count: 260);
  this->m_nNumResults = 0;
  this->m_bRecurseSubdirs = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017840
// Name: public: virtual void CAsyncGroupRequest::KeepRequestPostCallback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::KeepRequestPostCallback(CAsyncSearchRequest *this)
{
  this->m_Base.m_bDontAutoRelease = true;
}

//------------------------------------------------------------------------------
// Address: 0x10017860
// Name: public: virtual enum AsyncRequestState_t CAsyncSearchRequest::GetRequestState(void)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestState_t __thiscall CAsyncSearchRequest::GetRequestState(CAsyncSearchRequest *this)
{
  return this->m_Base.m_RequestState;
}

//------------------------------------------------------------------------------
// Address: 0x10017870
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileRequest::GetRequestStatus(void)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileRequest::GetRequestStatus(CAsyncSearchRequest *this)
{
  return this->m_Base.m_RequestStatus;
}

//------------------------------------------------------------------------------
// Address: 0x10017880
// Name: public: virtual bool CAsyncSearchRequest::GetSubdirectoryScan(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncSearchRequest::GetSubdirectoryScan(CAsyncSearchRequest *this)
{
  return this->m_bRecurseSubdirs;
}

//------------------------------------------------------------------------------
// Address: 0x10017890
// Name: public: virtual void CAsyncGroupRequest::AssignCallback(class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::AssignCallback(CAsyncSearchRequest *this, CFunctor *pCallback)
{
  CFunctor *m_pCallback; // ecx

  m_pCallback = this->m_Base.m_pCallback;
  if ( m_pCallback != nullptr )
    m_pCallback->Release(this: m_pCallback);
  this->m_Base.m_pCallback = pCallback;
}

//------------------------------------------------------------------------------
// Address: 0x100178C0
// Name: public: virtual void CAsyncFileRequest::AssignCallbackAndQueue(class CIOCompletionQueue __near *,class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::AssignCallbackAndQueue(
        CAsyncSearchRequest *this,
        CIOCompletionQueue *pMsgQueue,
        CFunctor *pCallback)
{
  CFunctor *m_pCallback; // ecx

  m_pCallback = this->m_Base.m_pCallback;
  if ( m_pCallback != nullptr )
    m_pCallback->Release(this: m_pCallback);
  this->m_Base.m_pCallback = pCallback;
  this->m_Base.m_pResultQueue = pMsgQueue;
}

//------------------------------------------------------------------------------
// Address: 0x10017900
// Name: public: virtual class IAsyncSearchRequest __near * CAsyncFileSystem::CreateNewSearchRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncSearchRequest *__thiscall CAsyncFileSystem::CreateNewSearchRequest(CAsyncFileSystem *this)
{
  CAsyncSearchRequest *v2; // eax
  CAsyncSearchRequest *v3; // esi

  v2 = (CAsyncSearchRequest *)operator new(nSize: 0x468u);
  if ( v2 != nullptr )
  {
    v3 = CAsyncSearchRequest::CAsyncSearchRequest(this: v2);
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: &v3->m_Base);
    return v3;
  }
  else
  {
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: (CAsyncRequestBase *)4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017950
// Name: public: virtual class IAsyncGroupRequest __near * CAsyncFileSystem::CreateNewAsyncRequestGroup(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncGroupRequest *__thiscall CAsyncFileSystem::CreateNewAsyncRequestGroup(CAsyncFileSystem *this)
{
  CAsyncGroupRequest *v2; // eax
  CAsyncGroupRequest *v3; // esi

  v2 = (CAsyncGroupRequest *)operator new(nSize: 0x68u);
  if ( v2 != nullptr )
  {
    v3 = CAsyncGroupRequest::CAsyncGroupRequest(this: v2);
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: &v3->m_Base);
    return v3;
  }
  else
  {
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: (CAsyncRequestBase *)4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017990
// Name: private: void CAsyncFileSystem::NotifyMessageQueueOrCallback(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::NotifyMessageQueueOrCallback(CAsyncFileSystem *this, CAsyncRequestBase *pRequest)
{
  void *m_pOuter; // ebx
  AsyncFileOperation_t m_Operation; // eax
  AsyncRequestStatus_t m_RequestStatus; // edi
  CIOCompletionQueue *m_pResultQueue; // esi
  TSLNodeBase_t *v6; // eax
  CFunctor *m_pCallback; // ecx
  bool v8; // zf

  if ( pRequest->m_pResultQueue != nullptr )
  {
    m_pOuter = pRequest->m_pOuter;
    if ( pRequest->m_pOuter != nullptr )
    {
      m_Operation = pRequest->m_Operation;
      if ( m_Operation > ASYNC_OP_UNDEFINED && m_Operation <= ASYNC_OP_SCANDIR )
      {
LABEL_7:
        m_RequestStatus = pRequest->m_RequestStatus;
        m_pResultQueue = pRequest->m_pResultQueue;
        v6 = CTSListBase::Pop(this: &m_pResultQueue->m_TSIOResultQueue.m_FreeNodes);
        if ( v6 != nullptr || (v6 = (TSLNodeBase_t *)operator new(nSize: 0x10u)) != nullptr )
        {
          *((_DWORD *)&v6->Next + 1) = m_pOuter;
          v6[1].Next = (TSLNodeBase_t *)m_RequestStatus;
          CTSQueue<CAsyncIOResult_t,0,1>::Push(
            this: &m_pResultQueue->m_TSIOResultQueue,
            pNode: (CTSQueue<CAsyncIOResult_t,0,1>::Node_t *)v6);
        }
        else
        {
          CTSQueue<CAsyncIOResult_t,0,1>::Push(this: &m_pResultQueue->m_TSIOResultQueue, pNode: nullptr);
        }
        return;
      }
      _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
    }
    m_pOuter = nullptr;
    goto LABEL_7;
  }
  if ( pRequest->m_RequestState == ASYNC_REQUEST_STATE_AWATING_FINISH )
  {
    m_pCallback = pRequest->m_pCallback;
    if ( m_pCallback != nullptr )
    {
      pRequest->m_bProcessingCallback = true;
      m_pCallback->operator()(this: m_pCallback);
      pRequest->m_pCallback->Release(this: pRequest->m_pCallback);
      pRequest->m_pCallback = nullptr;
      pRequest->m_bProcessingCallback = false;
    }
    v8 = !pRequest->m_bDontAutoRelease;
    pRequest->m_RequestState = ASYNC_REQUEST_STATE_COMPLETED;
    if ( v8 )
      CAsyncRequestBase::Release(this: pRequest);
  }
  else
  {
    _Error(a1: "Callback called at wrong time");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017A70
// Name: public: virtual bool CAsyncFileSystem::BlockUntilAsyncIOComplete(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncFileSystem::BlockUntilAsyncIOComplete(CAsyncFileSystem *this, const IAsyncRequestBase *pRequest)
{
  CAsyncFileSystem *v2; // ebx
  CAsyncRequestBase *(__thiscall *GetBase)(IAsyncRequestBase *); // edx
  int v4; // edi
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  char v8; // al
  CThreadEvent syncEvent; // [esp+8h] [ebp-Ch] BYREF
  CAsyncFileSystem *v11; // [esp+10h] [ebp-4h]

  v2 = this;
  GetBase = pRequest->GetBase;
  v11 = this;
  v4 = (int)GetBase(this: pRequest);
  if ( !CAsyncFileSystem::ValidateRequestPtr(this: v2, pRequest: (CAsyncRequestBase *)v4)
    || v2->m_bIOSuspended
    || *(int *)(v4 + 28) <= 1 )
  {
    return 0;
  }
  CThreadEvent::CThreadEvent(this: &syncEvent, a2: false);
  p_m_AsyncStateUpdateMutex = &v2->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != v2->m_AsyncStateUpdateMutex.m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
      v2 = v11;
      goto LABEL_10;
    }
    v2 = v11;
  }
  ++p_m_AsyncStateUpdateMutex->m_depth;
LABEL_10:
  if ( *(int *)(v4 + 28) >= 4 )
  {
    v8 = 0;
  }
  else
  {
    *(_DWORD *)(v4 + 40) = &syncEvent;
    v8 = 1;
  }
  if ( p_m_AsyncStateUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
  if ( v8 != 0 )
  {
    CThreadEvent::Wait(this: *(CThreadEvent **)(v4 + 40), a2: 0xFFFFFFFF);
    CAsyncFileSystem::NotifyMessageQueueOrCallback(this: v2, pRequest: (CAsyncRequestBase *)v4);
  }
  CThreadSyncObject::~CThreadSyncObject(this: &syncEvent);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10017BF0
// Name: public: virtual void CAsyncGroupRequest::AddAsyncRequest(class IAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::AddAsyncRequest(CAsyncGroupRequest *this, IAsyncRequestBase *pRequest)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IAsyncRequestBase **m_pMemory; // ecx
  int v6; // eax
  IAsyncRequestBase **v7; // eax
  int v8; // edi
  int v9; // eax
  bool *v10; // ecx
  int v11; // eax
  bool *v12; // esi

  m_nAllocationCount = this->m_RequestList.m_Memory.m_nAllocationCount;
  m_Size = this->m_RequestList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RequestList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_RequestList.m_Size;
  m_pMemory = this->m_RequestList.m_Memory.m_pMemory;
  v6 = this->m_RequestList.m_Size - m_Size - 1;
  this->m_RequestList.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_RequestList.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pRequest;
  v8 = this->m_ValidList.m_Size;
  v9 = this->m_ValidList.m_Memory.m_nAllocationCount;
  if ( v8 + 1 > v9 )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_ValidList, num: v8 - v9 + 1);
  ++this->m_ValidList.m_Size;
  v10 = this->m_ValidList.m_Memory.m_pMemory;
  v11 = this->m_ValidList.m_Size - v8 - 1;
  this->m_ValidList.m_pElements = v10;
  if ( v11 > 0 )
    _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: v11);
  v12 = &this->m_ValidList.m_Memory.m_pMemory[v8];
  if ( v12 != nullptr )
    *v12 = true;
}

//------------------------------------------------------------------------------
// Address: 0x10017CA0
// Name: private: void CAsyncFileSystem::AsyncIOCallBackHandler(class CAsyncRequestBase __near *,struct CAsyncResultInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::AsyncIOCallBackHandler(
        CAsyncFileSystem *this,
        CAsyncRequestBase *pRequest,
        CAsyncResultInfo_t *results)
{
  CAsyncFileSystem *v3; // ebx
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // edi
  DWORD CurrentThreadId; // ecx
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // esi
  bool v8; // zf
  CThreadEvent *m_pSyncThreadEvent; // ecx

  v3 = this;
  if ( CAsyncRequestQueue::IsInQueue(this: &this->m_InFlight, pItem: pRequest) == 0 )
  {
    _Error(a1: "Can't find completed Async IO request");
    return;
  }
  p_m_AsyncStateUpdateMutex = &v3->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == v3->m_AsyncStateUpdateMutex.m_ownerID )
    goto LABEL_6;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) == 0 )
  {
    v3 = this;
LABEL_6:
    ++p_m_AsyncStateUpdateMutex->m_depth;
    goto LABEL_8;
  }
  _mm_pause();
  CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  v3 = this;
LABEL_8:
  CAsyncRequestQueue::Remove(this: &v3->m_InFlight, pItem: pRequest);
  pRequest->m_RequestState = ASYNC_REQUEST_STATE_AWATING_FINISH;
  _InterlockedExchangeAdd(&v3->m_nJobsInflight.m_value, 0xFFFFFFFF);
  if ( pRequest->m_bAbortRequest )
  {
    CAsyncRequestBase::AbortAfterServicing(this: pRequest, results);
    m_pOuter = pRequest->m_pOuter;
    if ( pRequest->m_pOuter != nullptr )
    {
      m_Operation = pRequest->m_Operation;
      if ( m_Operation <= ASYNC_OP_UNDEFINED )
        goto LABEL_15;
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        goto LABEL_16;
      }
      if ( m_Operation != ASYNC_OP_SCANDIR )
      {
LABEL_15:
        _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
        goto LABEL_16;
      }
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
    }
LABEL_16:
    v8 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
    CAsyncFileSystem::KickOffFileJobs(this: v3);
    return;
  }
  CAsyncRequestBase::UpdateAfterServicing(this: pRequest, results);
  pRequest->m_pOldAsyncStatus = results->m_ErrorCode;
  switch ( results->m_ErrorCode )
  {
    case FSASYNC_ERR_ALIGNMENT:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_ALIGNMENT;
      break;
    case FSASYNC_ERR_FAILURE:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_FAILURE;
      break;
    case FSASYNC_ERR_READING:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_READING;
      break;
    case FSASYNC_ERR_NOMEMORY:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_NOMEMORY;
      break;
    case FSASYNC_ERR_UNKNOWNID:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_UNKNOWNID;
      break;
    case FSASYNC_ERR_FILEOPEN:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_FILEOPEN;
      break;
    case FSASYNC_OK:
      goto $LN4_4;
    default:
      _Error(a1: "Async result Status makes no sense");
$LN4_4:
      pRequest->m_RequestStatus = ASYNC_REQUEST_OK;
      break;
  }
  CAsyncRequestQueue::AddToTail(this: &v3->m_Completed, pItem: pRequest);
  v8 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
  if ( v8 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
  CThreadEvent::Set(this: &v3->m_CompletionSignal);
  CAsyncFileSystem::KickOffFileJobs(this: v3);
  m_pSyncThreadEvent = pRequest->m_pSyncThreadEvent;
  if ( m_pSyncThreadEvent != nullptr )
    CThreadEvent::Set(this: m_pSyncThreadEvent);
  else
    CAsyncFileSystem::NotifyMessageQueueOrCallback(this: v3, pRequest);
}

//------------------------------------------------------------------------------
// Address: 0x10017E60
// Name: private: static void CAsyncFileSystem::AsyncSearchCallbackAddItem(void __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAsyncFileSystem::AsyncSearchCallbackAddItem(int *pContext, char *pFoundPath, char *pFoundFile)
{
  int v3; // esi
  CDirectoryEntryInfo_t result; // [esp+4h] [ebp-104h] BYREF

  v3 = *pContext;
  V_ComposeFileName(path: pFoundPath, filename: pFoundFile, dest: result.m_FullFileName, destSize: 260);
  CUtlVector<CDirectoryEntryInfo_t,CUtlMemory<CDirectoryEntryInfo_t,int>>::InsertBefore(
    this: (CUtlVector<CDirectoryEntryInfo_t,CUtlMemory<CDirectoryEntryInfo_t,int> > *)(v3 + 68),
    elem: *(_DWORD *)(v3 + 80),
    src: &result);
}

//------------------------------------------------------------------------------
// Address: 0x10017EB0
// Name: public: CAsyncFileSystem::CAsyncFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncFileSystem *__thiscall CAsyncFileSystem::CAsyncFileSystem(CAsyncFileSystem *this)
{
  this->__vftable = (CAsyncFileSystem_vtbl *)&CAsyncFileSystem::`vftable';
  this->m_Composing.m_Mutex.m_ownerID = 0;
  this->m_Composing.m_Mutex.m_depth = 0;
  this->m_Composing.m_nQueueSize = 0;
  this->m_Composing.m_pHead = nullptr;
  this->m_Composing.m_pTail = nullptr;
  this->m_Submitted.m_Mutex.m_ownerID = 0;
  this->m_Submitted.m_Mutex.m_depth = 0;
  this->m_Submitted.m_nQueueSize = 0;
  this->m_Submitted.m_pHead = nullptr;
  this->m_Submitted.m_pTail = nullptr;
  this->m_InFlight.m_Mutex.m_ownerID = 0;
  this->m_InFlight.m_Mutex.m_depth = 0;
  this->m_InFlight.m_nQueueSize = 0;
  this->m_InFlight.m_pHead = nullptr;
  this->m_InFlight.m_pTail = nullptr;
  this->m_Completed.m_Mutex.m_ownerID = 0;
  this->m_Completed.m_Mutex.m_depth = 0;
  this->m_Completed.m_nQueueSize = 0;
  this->m_Completed.m_pHead = nullptr;
  this->m_Completed.m_pTail = nullptr;
  this->m_nJobsInflight.m_value = 0;
  this->m_nSuspendCount.m_value = 0;
  this->m_AsyncStateUpdateMutex.m_ownerID = 0;
  this->m_AsyncStateUpdateMutex.m_depth = 0;
  CThreadEvent::CThreadEvent(this: &this->m_CompletionSignal, a2: false);
  _InterlockedExchange(&this->m_nJobsInflight.m_value, 0);
  _InterlockedExchange(&this->m_nSuspendCount.m_value, 0);
  this->m_bIOSuspended = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017F30
// Name: private: static void CAsyncFileSystem::AsyncIOCallbackGateway(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAsyncFileSystem::AsyncIOCallbackGateway(
        const FileAsyncRequest_t *request,
        int nBytesRead,
        FSAsyncStatus_t err)
{
  CAsyncResultInfo_t results; // [esp+0h] [ebp-Ch] BYREF

  results.m_nBytesTransferred = nBytesRead;
  results.m_pAllocatedBuffer = request->pData;
  results.m_ErrorCode = err;
  CAsyncFileSystem::AsyncIOCallBackHandler(
    this: (CAsyncFileSystem *)g_pAsyncFileSystem,
    pRequest: (CAsyncRequestBase *)request->pContext,
    &results);
}

//------------------------------------------------------------------------------
// Address: 0x10017F70
// Name: private: static void CAsyncFileSystem::AsyncSearchCallbackGateway(void __near *,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAsyncFileSystem::AsyncSearchCallbackGateway(CAsyncRequestBase *pContext, FSAsyncStatus_t err)
{
  CAsyncResultInfo_t results; // [esp+0h] [ebp-Ch] BYREF

  results.m_pAllocatedBuffer = nullptr;
  results.m_nBytesTransferred = 0;
  results.m_ErrorCode = err;
  CAsyncFileSystem::AsyncIOCallBackHandler(this: (CAsyncFileSystem *)g_pAsyncFileSystem, pRequest: pContext, &results);
}

//------------------------------------------------------------------------------
// Address: 0x10017FA0
// Name: private: void CAsyncFileSystem::KickOffFileJobs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::KickOffFileJobs(CAsyncFileSystem *this)
{
  CAsyncFileSystem *v1; // ebx
  volatile int m_value; // eax
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // eax
  bool v5; // zf
  CAsyncRequestBase *v6; // edi
  AsyncFileOperation_t m_Operation; // eax
  __int64 *m_pOuter; // esi
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  char v13; // dl
  int v14; // eax
  int v15; // eax
  FSAsyncStatus_t v16; // eax
  IFileSystem_vtbl *v17; // ebx
  int v18; // eax
  volatile __int32 *v19; // eax
  FileAsyncRequest_t asJobReq; // [esp+4h] [ebp-3Ch] BYREF
  CThreadFastMutex *v21; // [esp+30h] [ebp-10h]
  CAsyncFileSystem *v22; // [esp+34h] [ebp-Ch]
  char *pSearchSpec; // [esp+38h] [ebp-8h]
  BOOL bRecurseFolders; // [esp+3Ch] [ebp-4h]

  v1 = this;
  m_value = this->m_nSuspendCount.m_value;
  v22 = this;
  if ( m_value > 0 )
    return;
  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  v21 = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &v1->m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++v1->m_AsyncStateUpdateMutex.m_depth;
  }
  if ( v1->m_Submitted.m_nQueueSize < 1 )
  {
    v5 = v1->m_AsyncStateUpdateMutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
    return;
  }
  v6 = CAsyncRequestQueue::RemoveHead(this: &v1->m_Submitted);
  memset(dst: (unsigned __int8 *)&asJobReq, value: 0, count: sizeof(asJobReq));
  asJobReq.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
  m_Operation = v6->m_Operation;
  m_pOuter = nullptr;
  pSearchSpec = nullptr;
  LOBYTE(bRecurseFolders) = 0;
  if ( m_Operation == ASYNC_OP_READFILE || m_Operation == ASYNC_OP_WRITEFILE || m_Operation == ASYNC_OP_APPENDFILE )
  {
    m_pOuter = (__int64 *)v6->m_pOuter;
    v9 = 0;
    if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v6->m_pOuter + 76))(a1: v6->m_pOuter) != 0 )
    {
      v10 = (*(int (__thiscall **)(__int64 *))(*(_DWORD *)m_pOuter + 80))(a1: m_pOuter);
      v9 = v10;
      if ( m_pOuter[10] > 0 && m_pOuter[10] > v10 )
        _Error(a1: "Buffer not big enough to hold requested File IO");
    }
    if ( m_pOuter[10] > 0 && m_pOuter[10] < v9 )
      v9 = *((_DWORD *)m_pOuter + 20);
    asJobReq.pszFilename = (const char *)(*(int (__thiscall **)(__int64 *))(*(_DWORD *)m_pOuter + 68))(a1: m_pOuter);
    asJobReq.pData = (void *)(*(int (__thiscall **)(__int64 *))(*(_DWORD *)m_pOuter + 76))(a1: m_pOuter);
    v11 = *((_DWORD *)m_pOuter + 18);
    asJobReq.nBytes = v9;
    asJobReq.nOffset = v11;
    asJobReq.pfnCallback = CAsyncFileSystem::AsyncIOCallbackGateway;
    asJobReq.pContext = v6;
    asJobReq.priority = 0;
    v12 = (*(int (__thiscall **)(__int64 *))(*(_DWORD *)m_pOuter + 76))(a1: m_pOuter);
    asJobReq.pszPathID = nullptr;
    v1 = v22;
    asJobReq.flags = v12 == 0;
    asJobReq.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
    asJobReq.pfnAlloc = CAsyncFileSystem::OldAsyncAllocatorCallback;
  }
  if ( v6->m_Operation == ASYNC_OP_SCANDIR )
  {
    v13 = *((_BYTE *)v6->m_pOuter + 64);
    pSearchSpec = (char *)v6->m_pOuter + 868;
    LOBYTE(bRecurseFolders) = v13;
  }
  CAsyncRequestQueue::AddToTail(this: &v1->m_InFlight, pItem: v6);
  _InterlockedExchangeAdd(&v1->m_nJobsInflight.m_value, 1u);
  v14 = v6->m_Operation - 1;
  v6->m_RequestState = ASYNC_REQUEST_STATE_SERVICING;
  if ( v14 == 0 )
  {
    v16 = g_pFullFileSystem->AsyncReadMultiple(
            this: g_pFullFileSystem,
            a2: &asJobReq,
            a3: 1,
            a4: &v6->m_pOldAsyncControl);
LABEL_29:
    if ( v16 != FSASYNC_OK )
      _Error(a1: "Basefilesystem Async Job submission failed");
    goto LABEL_31;
  }
  v15 = v14 - 1;
  if ( v15 == 0 )
  {
    v17 = g_pFullFileSystem->IAppSystem::__vftable;
    v18 = (*(int (__thiscall **)(__int64 *, _DWORD, _DWORD, FSAsyncControl_t__ **))(*(_DWORD *)m_pOuter + 92))(
            a1: m_pOuter,
            a2: 0,
            a3: 0,
            a4: &v6->m_pOldAsyncControl);
    v16 = ((int (__thiscall *)(IFileSystem *, const char *, void *, int))v17->AsyncWrite)(
            a1: g_pFullFileSystem,
            a2: asJobReq.pszFilename,
            a3: asJobReq.pData,
            a4: v18);
    goto LABEL_29;
  }
  if ( v15 == 2 )
  {
    v16 = g_pFullFileSystem->AsyncDirectoryScan(
            this: g_pFullFileSystem,
            a2: pSearchSpec,
            a3: bRecurseFolders,
            a4: v6,
            a5: (void (__cdecl *)(void *, char *, char *))CAsyncFileSystem::AsyncSearchCallbackAddItem,
            a6: (void (__cdecl *)(void *, FSAsyncStatus_t))CAsyncFileSystem::AsyncSearchCallbackGateway,
            a7: &v6->m_pOldAsyncControl);
    goto LABEL_29;
  }
  _Error(a1: "Unable to determing async job type");
LABEL_31:
  v19 = (volatile __int32 *)v21;
  v5 = v21->m_depth-- == 1;
  if ( v5 )
    _InterlockedExchange(v19, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100181F0
// Name: public: virtual void CAsyncFileSystem::ResumeAllAsyncIO(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::ResumeAllAsyncIO(CAsyncFileSystem *this)
{
  _InterlockedExchangeAdd(&this->m_nSuspendCount.m_value, 0xFFFFFFFF);
  if ( this->m_nSuspendCount.m_value <= 0 )
  {
    _InterlockedExchange(&this->m_nSuspendCount.m_value, 0);
    CAsyncFileSystem::KickOffFileJobs(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018220
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::SubmitAsyncFileRequest(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::SubmitAsyncFileRequest(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest)
{
  CAsyncRequestBase *v3; // esi
  int m_Operation; // eax
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // edi
  DWORD CurrentThreadId; // eax
  bool v7; // zf
  CThreadFastMutex *v9; // edi
  DWORD v10; // eax
  AsyncRequestStatus_t RStatus; // [esp+18h] [ebp+8h]

  v3 = pRequest->GetBase(this: pRequest);
  if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Composing, pItem: v3) == 0 )
  {
    if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Submitted, pItem: v3) != 0
      || CAsyncRequestQueue::IsInQueue(this: &this->m_InFlight, pItem: v3) != 0
      || CAsyncRequestQueue::IsInQueue(this: &this->m_Completed, pItem: v3) != 0 )
    {
      RStatus = ASYNC_REQUEST_ERROR_ALREADYSUBMITTED;
    }
    else
    {
      RStatus = ASYNC_REQUEST_ERROR_BADPTR;
    }
    goto LABEL_13;
  }
  m_Operation = v3->m_Operation;
  if ( m_Operation <= 0 || m_Operation >= 5 )
  {
    RStatus = ASYNC_REQUEST_ERROR_BADOPER;
    goto LABEL_13;
  }
  if ( v3->m_pResultQueue == nullptr && v3->m_pCallback == nullptr )
  {
    RStatus = ASYNC_REQUEST_ERROR_NONOTIFICATION;
    goto LABEL_13;
  }
  RStatus = CAsyncRequestBase::ValidateSubmittedRequest(this: v3, bPerformSync: false);
  if ( RStatus != ASYNC_REQUEST_OK )
  {
LABEL_13:
    p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_AsyncStateUpdateMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_AsyncStateUpdateMutex.m_depth;
    }
    CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: v3);
    CAsyncRequestQueue::AddToTail(this: &this->m_Completed, pItem: v3);
    v3->m_RequestState = ASYNC_REQUEST_STATE_COMPLETED;
    v3->m_RequestStatus = RStatus;
    v7 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
    CAsyncFileSystem::NotifyMessageQueueOrCallback(this, pRequest: v3);
    return RStatus;
  }
  v9 = &this->m_AsyncStateUpdateMutex;
  v10 = GetCurrentThreadId();
  if ( v10 != this->m_AsyncStateUpdateMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)v9, v10, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_AsyncStateUpdateMutex, a2: v10, a3: 0);
  }
  else
  {
    ++this->m_AsyncStateUpdateMutex.m_depth;
  }
  CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: v3);
  v3->m_RequestState = ASYNC_REQUEST_STATE_SUBMITTED;
  CAsyncRequestQueue::PriorityInsert(this: &this->m_Submitted, pItem: v3);
  v7 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)v9, 0);
  CAsyncFileSystem::KickOffFileJobs(this);
  return ASYNC_REQUEST_OK;
}

//------------------------------------------------------------------------------
// Address: 0x100183A0
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::SubmitSyncFileRequest(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::SubmitSyncFileRequest(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest)
{
  CAsyncRequestBase *v3; // esi
  int m_Operation; // eax
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // edi
  DWORD CurrentThreadId; // eax
  volatile unsigned int m_ownerID; // ecx
  AsyncRequestStatus_t result; // eax
  bool v9; // zf
  CThreadFastMutex *v10; // edi
  DWORD v11; // eax
  AsyncRequestStatus_t m_RequestStatus; // esi
  CThreadEvent syncEvent; // [esp+Ch] [ebp-Ch] BYREF
  DWORD v14; // [esp+14h] [ebp-4h]
  AsyncRequestStatus_t RStatus; // [esp+20h] [ebp+8h]

  v3 = pRequest->GetBase(this: pRequest);
  if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Composing, pItem: v3) == 0 )
  {
    if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Submitted, pItem: v3) != 0
      || CAsyncRequestQueue::IsInQueue(this: &this->m_InFlight, pItem: v3) != 0
      || CAsyncRequestQueue::IsInQueue(this: &this->m_Completed, pItem: v3) != 0 )
    {
      RStatus = ASYNC_REQUEST_ERROR_ALREADYSUBMITTED;
    }
    else
    {
      RStatus = ASYNC_REQUEST_ERROR_BADPTR;
    }
LABEL_10:
    p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
    CurrentThreadId = GetCurrentThreadId();
    m_ownerID = this->m_AsyncStateUpdateMutex.m_ownerID;
    v14 = CurrentThreadId;
    if ( CurrentThreadId != m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncStateUpdateMutex, a2: v14, a3: 0);
    }
    else
    {
      ++this->m_AsyncStateUpdateMutex.m_depth;
    }
    CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: v3);
    CAsyncRequestQueue::AddToTail(this: &this->m_Completed, pItem: v3);
    result = RStatus;
    v3->m_RequestState = ASYNC_REQUEST_STATE_COMPLETED;
    v3->m_RequestStatus = RStatus;
    v9 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
    return result;
  }
  m_Operation = v3->m_Operation;
  if ( m_Operation <= 0 || m_Operation >= 5 )
  {
    RStatus = ASYNC_REQUEST_ERROR_BADOPER;
    goto LABEL_10;
  }
  RStatus = CAsyncRequestBase::ValidateSubmittedRequest(this: v3, bPerformSync: true);
  if ( RStatus != ASYNC_REQUEST_OK )
    goto LABEL_10;
  CThreadEvent::CThreadEvent(this: &syncEvent, a2: false);
  v10 = &this->m_AsyncStateUpdateMutex;
  v11 = GetCurrentThreadId();
  if ( v11 != this->m_AsyncStateUpdateMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)v10, v11, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_AsyncStateUpdateMutex, a2: v11, a3: 0);
  }
  else
  {
    ++this->m_AsyncStateUpdateMutex.m_depth;
  }
  CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: v3);
  v3->m_RequestState = ASYNC_REQUEST_STATE_SUBMITTED;
  v3->m_pSyncThreadEvent = &syncEvent;
  CAsyncRequestQueue::PriorityInsert(this: &this->m_Submitted, pItem: v3);
  v9 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
  if ( v9 )
    _InterlockedExchange((volatile __int32 *)v10, 0);
  CAsyncFileSystem::KickOffFileJobs(this);
  CThreadEvent::Wait(this: v3->m_pSyncThreadEvent, a2: 0xFFFFFFFF);
  m_RequestStatus = v3->m_RequestStatus;
  CThreadSyncObject::~CThreadSyncObject(this: &syncEvent);
  return m_RequestStatus;
}

//------------------------------------------------------------------------------
// Address: 0x1002CF10
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::Sort(int (*)(char __near * const __near *,char __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::Sort(
        CUtlVector<char *,CUtlMemory<char *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  char *v6; // ecx
  char **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CF90
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::EnsureCapacity(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int num)
{
  unsigned __int8 *m_pMemory; // eax
  unsigned __int8 *v4; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D4F0
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetCount(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int count)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( count != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( count > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: count - m_nAllocationCount);
    this->m_Size += count;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - count;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && count > 0 )
      _V_memmove(dest: &m_pMemory[count], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D540
// Name: public: void CUtlVector<unsigned char,class CUtlBlockMemory<unsigned char,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlBlockMemory<unsigned char,int>>::EnsureCapacity(
        CUtlVector<unsigned char,CUtlBlockMemory<unsigned char,int> > *this,
        int num)
{
  int m_nBlocks; // edi
  int v4; // ecx

  m_nBlocks = this->m_Memory.m_nBlocks;
  v4 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( num - v4 * m_nBlocks > 0 )
    CUtlBlockMemory<unsigned char,int>::ChangeSize(
      this: &this->m_Memory,
      nBlocks: m_nBlocks + (v4 + num - v4 * m_nBlocks - 1) / v4);
  this->m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D940
// Name: public: int CUtlVector<unsigned char,class CUtlBlockMemory<unsigned char,int>>::InsertBefore(int,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned char,CUtlBlockMemory<unsigned char,int>>::InsertBefore(
        CUtlVector<unsigned char,CUtlBlockMemory<unsigned char,int> > *this,
        int elem,
        unsigned __int8 *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<unsigned char,int>::ChangeSize(this: &this->m_Memory, nBlocks: m_nBlocks + (v6 + v7 - 1) / v6);
  }
  v8 = ++this->m_Size - elem - 1;
  this->m_pElements = nullptr;
  if ( v8 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + 1) >> (*((int *)&this->m_Memory + 2) >> 27)][(elem + 1)
                                                                                   & ((32
                                                                                     * *((_DWORD *)&this->m_Memory + 2)) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                             & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)],
      count: v8);
  v9 = &this->m_Memory.m_pMemory[elem >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10003590
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class IDedicatedExports>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IDedicatedExports>::GetTier(CBaseAppSystem<IDedicatedExports> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10006550
// Name: public: virtual enum AsyncFileOperation_t CAsyncSearchRequest::GetAsyncOperationType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncSearchRequest::GetAsyncOperationType(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x10007BC0
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class IFileSystem>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IFileSystem>::GetDependencies(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D350
// Name: public: virtual bool CTier2AppSystem<class IAsyncFileSystem,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier2AppSystem<IAsyncFileSystem,0>::Connect(
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
// Address: 0x1001B0D0
// Name: public: void CAsyncRequestBase::DeleteOuter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::DeleteOuter(CAsyncRequestBase *this)
{
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation > ASYNC_OP_UNDEFINED )
    {
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        return;
      }
      if ( m_Operation == ASYNC_OP_SCANDIR )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
        return;
      }
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B110
// Name: public: virtual void CAsyncFileRequest::SetUserBuffer(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::SetUserBuffer(CAsyncFileRequest *this, void *pDataBuffer, unsigned int nBufferSize)
{
  this->m_pUserProvidedDataBuffer = pDataBuffer;
  this->m_nUserProvidedBufferSize = nBufferSize;
  this->m_bDeleteBufferMemory = false;
}

//------------------------------------------------------------------------------
// Address: 0x1001B130
// Name: public: virtual void CAsyncFileRequest::ProvideDataBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::ProvideDataBuffer(CAsyncFileRequest *this)
{
  this->m_pUserProvidedDataBuffer = nullptr;
  this->m_nUserProvidedBufferSize = 0;
  this->m_bDeleteBufferMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x1001B140
// Name: public: virtual void CAsyncFileRequest::ReadFileDataAt(__int64,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::ReadFileDataAt(CAsyncFileRequest *this, __int64 nOffset, unsigned int nReadSize)
{
  this->m_nFileSeekOffset = nOffset;
  this->m_nMaxIOSizeInBytes = nReadSize;
}

//------------------------------------------------------------------------------
// Address: 0x1001B160
// Name: public: virtual void CAsyncFileRequest::WriteFileDataAt(__int64,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::WriteFileDataAt(CAsyncFileRequest *this, __int64 nOffset, unsigned int nWriteSize)
{
  LODWORD(this->m_nFileSeekOffset) = nOffset;
  LODWORD(this->m_nMaxIOSizeInBytes) = nWriteSize;
  HIDWORD(this->m_nFileSeekOffset) = HIDWORD(nOffset);
  HIDWORD(this->m_nMaxIOSizeInBytes) = 0;
  this->m_bDeleteBufferMemory = false;
}

//------------------------------------------------------------------------------
// Address: 0x1001B190
// Name: public: enum AsyncRequestStatus_t CAsyncFileRequest::ValidateSubmittedRequest(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncFileRequest::ValidateSubmittedRequest(CAsyncFileRequest *this, bool bPerformSync)
{
  AsyncFileOperation_t m_Operation; // eax

  if ( this->GetFileName(this) == nullptr )
    return -97;
  if ( this->GetUserBuffer(this) != nullptr && this->GetUserBufferSize(this) == 0 )
    return -96;
  m_Operation = this->m_Base.m_Operation;
  if ( (m_Operation == ASYNC_OP_WRITEFILE || m_Operation == ASYNC_OP_APPENDFILE) && this->GetUserBuffer(this) == nullptr )
    return -95;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B200
// Name: public: virtual void CAsyncSearchRequest::SetSearchFilespec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetSearchFilespec(CAsyncSearchRequest *this, const char *pFullSearchSpec)
{
  _V_strcpy(dest: this->m_SearchSpec, src: pFullSearchSpec);
  this->m_Base.m_Operation = ASYNC_OP_SCANDIR;
}

//------------------------------------------------------------------------------
// Address: 0x1001B230
// Name: public: virtual void CAsyncSearchRequest::SetSearchPathAndFileSpec(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetSearchPathAndFileSpec(
        CAsyncSearchRequest *this,
        const char *pPathId,
        const char *pRelativeSearchSpec)
{
  char *m_FileSpec; // ebx
  const char *v5; // eax
  char pFixedupPath[260]; // [esp+Ch] [ebp-208h] BYREF
  char pTempPath[260]; // [esp+110h] [ebp-104h] BYREF

  m_FileSpec = this->m_FileSpec;
  v5 = V_UnqualifiedFileName(in: pRelativeSearchSpec);
  _V_strcpy(dest: m_FileSpec, src: v5);
  V_ExtractFilePath(path: pRelativeSearchSpec, dest: this->m_SearchPath, destSize: 260);
  V_StripTrailingSlash(ppath: this->m_SearchPath);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: this->m_SearchPath,
    a3: pPathId,
    a4: pTempPath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  V_FixupPathName(pOut: pFixedupPath, nOutLen: 0x104u, pPath: pTempPath);
  V_ComposeFileName(path: pFixedupPath, filename: m_FileSpec, dest: this->m_SearchSpec, destSize: 260);
  this->m_Base.m_Operation = ASYNC_OP_SCANDIR;
}

//------------------------------------------------------------------------------
// Address: 0x1001B2E0
// Name: public: virtual void CAsyncSearchRequest::SetSearchPathAndFileSpec(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetSearchPathAndFileSpec(
        CAsyncSearchRequest *this,
        const char *pPathId,
        const char *pRelativeSearchPath,
        const char *pSearchSpec)
{
  char *m_FileSpec; // ebx
  char pFixedupPath[260]; // [esp+Ch] [ebp-208h] BYREF
  char pTempPath[260]; // [esp+110h] [ebp-104h] BYREF

  m_FileSpec = this->m_FileSpec;
  _V_strcpy(dest: this->m_FileSpec, src: pSearchSpec);
  _V_strcpy(dest: this->m_SearchPath, src: pRelativeSearchPath);
  V_StripTrailingSlash(ppath: this->m_SearchPath);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: this->m_SearchPath,
    a3: pPathId,
    a4: pTempPath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  V_FixupPathName(pOut: pFixedupPath, nOutLen: 0x104u, pPath: pTempPath);
  V_ComposeFileName(path: pFixedupPath, filename: m_FileSpec, dest: this->m_SearchSpec, destSize: 260);
  this->m_Base.m_Operation = ASYNC_OP_SCANDIR;
}

//------------------------------------------------------------------------------
// Address: 0x1001B380
// Name: public: virtual void CAsyncSearchRequest::SetSubdirectoryScan(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetSubdirectoryScan(CAsyncSearchRequest *this, bool bInclude)
{
  this->m_bRecurseSubdirs = bInclude;
}

//------------------------------------------------------------------------------
// Address: 0x1001B390
// Name: public: virtual void __near * CAsyncFileSystem::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAsyncFileSystem *__thiscall CAsyncFileSystem::QueryInterface(CAsyncFileSystem *this, const char *pInterfaceName)
{
  int v3; // eax

  v3 = _V_strlen(str: "VNewAsyncFileSystem001");
  return V_strncmp(s1: pInterfaceName, s2: "VNewAsyncFileSystem001", count: v3 + 1) == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B3C0
// Name: private: static void __near * CAsyncFileSystem::OldAsyncAllocatorCallback(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CAsyncFileSystem::OldAsyncAllocatorCallback(const char *pszFilename, unsigned int nBytes)
{
  return g_pAsyncFileSystem->AllocateBuffer(this: g_pAsyncFileSystem, a2: nBytes, a3: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1001B3E0
// Name: public: virtual void __near * CAsyncFileSystem::AllocateBuffer(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CAsyncFileSystem::AllocateBuffer(
        CAsyncFileSystem *this,
        unsigned int nBufferSize,
        unsigned int nAlignment)
{
  unsigned int v3; // eax
  void *result; // eax
  unsigned int v5; // esi

  v3 = nAlignment;
  if ( ((nAlignment - 1) & nAlignment) != 0 )
    return nullptr;
  if ( nAlignment <= 4 )
    v3 = 4;
  v5 = v3 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v3 - 1 + nBufferSize + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v5 & ((unsigned int)result + v5 + 4)) - 4) = result;
    return (void *)(~v5 & ((unsigned int)result + v5 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B440
// Name: public: virtual void CAsyncFileSystem::ReleaseBuffer(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::ReleaseBuffer(CAsyncFileSystem *this, unsigned int pBuffer)
{
  if ( pBuffer != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((pBuffer & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x1001B470
// Name: public: void CAsyncRequestBase::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::Release(CAsyncRequestBase *this)
{
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // eax

  if ( this->m_RequestState != ASYNC_REQUEST_STATE_COMPLETED )
  {
    _Error(a1: "Async Request has not finished, unable to release");
    return;
  }
  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation > ASYNC_OP_UNDEFINED )
    {
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        return;
      }
      if ( m_Operation == ASYNC_OP_SCANDIR )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
        return;
      }
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B4C0
// Name: public: void CAsyncRequestBase::AbortAfterServicing(struct CAsyncResultInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::AbortAfterServicing(CAsyncRequestBase *this, CAsyncResultInfo_t *results)
{
  int (__thiscall ***m_pOuter)(void *); // esi
  AsyncFileOperation_t m_Operation; // ecx

  m_pOuter = (int (__thiscall ***)(void *))this->m_pOuter;
  if ( this->m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation <= ASYNC_OP_UNDEFINED )
    {
LABEL_5:
      _Error(a1: "Bad Outer in CAsyncRequestBase::AbortAfterServicing");
      return;
    }
    if ( m_Operation > ASYNC_OP_APPENDFILE )
    {
      if ( m_Operation == ASYNC_OP_SCANDIR )
        return;
      goto LABEL_5;
    }
    if ( (**m_pOuter)(a1: m_pOuter) == 1 && m_pOuter[16] == nullptr && results->m_pAllocatedBuffer != nullptr )
      free(pMem: results->m_pAllocatedBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B520
// Name: public: enum AsyncRequestStatus_t CAsyncRequestBase::ValidateSubmittedRequest(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncRequestBase::ValidateSubmittedRequest(CAsyncRequestBase *this, bool bPerformSync)
{
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation > ASYNC_OP_UNDEFINED )
    {
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
        return CAsyncFileRequest::ValidateSubmittedRequest(this: (CAsyncFileRequest *)m_pOuter, bPerformSync);
      if ( m_Operation == ASYNC_OP_SCANDIR )
        return _V_strlen(str: (const char *)m_pOuter + 88) >= 1 ? 0 : 0xFFFFFFA8;
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::ValidateSubmittedRequest");
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B580
// Name: public: virtual void CAsyncFileRequest::LoadFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::LoadFile(CAsyncFileRequest *this, const char *pFileName)
{
  if ( this->m_pFileName != nullptr )
    free(pMem: (void *)this->m_pFileName);
  if ( pFileName != nullptr )
    this->m_pFileName = MemAlloc_StrDup(pString: pFileName);
  else
    this->m_pFileName = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_READFILE;
}

//------------------------------------------------------------------------------
// Address: 0x1001B5D0
// Name: public: virtual void CAsyncFileRequest::SaveFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::SaveFile(CAsyncFileRequest *this, const char *pFileName)
{
  if ( this->m_pFileName != nullptr )
    free(pMem: (void *)this->m_pFileName);
  if ( pFileName != nullptr )
    this->m_pFileName = MemAlloc_StrDup(pString: pFileName);
  else
    this->m_pFileName = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_WRITEFILE;
}

//------------------------------------------------------------------------------
// Address: 0x1001B620
// Name: public: virtual void CAsyncFileRequest::AppendFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::AppendFile(CAsyncFileRequest *this, const char *pFileName)
{
  if ( this->m_pFileName != nullptr )
    free(pMem: (void *)this->m_pFileName);
  if ( pFileName != nullptr )
    this->m_pFileName = MemAlloc_StrDup(pString: pFileName);
  else
    this->m_pFileName = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_APPENDFILE;
}

//------------------------------------------------------------------------------
// Address: 0x1001B670
// Name: public: virtual void CAsyncFileRequest::SetFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::SetFileName(CAsyncFileRequest *this, const char *pFileName)
{
  if ( this->m_pFileName != nullptr )
    free(pMem: (void *)this->m_pFileName);
  if ( pFileName != nullptr )
    this->m_pFileName = MemAlloc_StrDup(pString: pFileName);
  else
    this->m_pFileName = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B6B0
// Name: public: bool CAsyncRequestQueue::IsInQueue(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncRequestQueue::IsInQueue(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pHead; // eax
  bool v5; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pItem != nullptr && (m_pHead = this->m_pHead) != nullptr )
  {
    do
    {
      if ( m_pHead == pItem )
      {
        v5 = this->m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)this, 0);
        return 1;
      }
      m_pHead = m_pHead->m_pNext;
    }
    while ( m_pHead != nullptr );
    v5 = this->m_Mutex.m_depth-- == 1;
    if ( !v5 )
      return 0;
    _InterlockedExchange((volatile __int32 *)this, 0);
    return 0;
  }
  else
  {
    v5 = this->m_Mutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B740
// Name: public: bool CAsyncRequestQueue::IsInQueueIp(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncRequestQueue::IsInQueueIp(CAsyncRequestQueue *this, const IAsyncRequestBase *pInterfaceBase)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pHead; // eax
  bool v5; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pInterfaceBase != nullptr && (m_pHead = this->m_pHead) != nullptr )
  {
    do
    {
      if ( (const IAsyncRequestBase *)m_pHead->m_pOuter == pInterfaceBase )
      {
        v5 = this->m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)this, 0);
        return 1;
      }
      m_pHead = m_pHead->m_pNext;
    }
    while ( m_pHead != nullptr );
    v5 = this->m_Mutex.m_depth-- == 1;
    if ( !v5 )
      return 0;
    _InterlockedExchange((volatile __int32 *)this, 0);
    return 0;
  }
  else
  {
    v5 = this->m_Mutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B7D0
// Name: public: void CAsyncRequestQueue::AddToHead(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::AddToHead(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( this->m_pHead != nullptr )
  {
    pItem->m_pPrev = nullptr;
    pItem->m_pNext = this->m_pHead;
    this->m_pHead = pItem;
    pItem->m_pNext->m_pPrev = pItem;
    ++this->m_nQueueSize;
  }
  else
  {
    this->m_pTail = pItem;
    this->m_pHead = pItem;
    pItem->m_pPrev = nullptr;
    pItem->m_pNext = nullptr;
    this->m_nQueueSize = 1;
  }
  if ( this->m_Mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001B860
// Name: public: void CAsyncRequestQueue::AddToTail(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::AddToTail(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pTail; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  m_pTail = this->m_pTail;
  if ( m_pTail != nullptr )
  {
    pItem->m_pPrev = m_pTail;
    pItem->m_pNext = nullptr;
    this->m_pTail = pItem;
    pItem->m_pPrev->m_pNext = pItem;
    ++this->m_nQueueSize;
  }
  else
  {
    this->m_pTail = pItem;
    this->m_pHead = pItem;
    pItem->m_pPrev = nullptr;
    pItem->m_pNext = nullptr;
    this->m_nQueueSize = 1;
  }
  if ( this->m_Mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001B8E0
// Name: public: void CAsyncRequestQueue::InsertBefore(class CAsyncRequestBase __near *,class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::InsertBefore(
        CAsyncRequestQueue *this,
        CAsyncRequestBase *pItem,
        CAsyncRequestBase *pInsertAt)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pPrev; // eax
  bool v6; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pInsertAt == nullptr
    || this->m_nQueueSize == 0
    || pItem == nullptr
    || CAsyncRequestQueue::IsInQueue(this, pItem: pInsertAt) == 0 )
  {
    v6 = this->m_Mutex.m_depth-- == 1;
    if ( !v6 )
      return;
    goto LABEL_15;
  }
  if ( pInsertAt == this->m_pHead )
  {
    CAsyncRequestQueue::AddToHead(this, pItem);
  }
  else
  {
    m_pPrev = pInsertAt->m_pPrev;
    m_pPrev->m_pNext = pItem;
    pInsertAt->m_pPrev = pItem;
    pItem->m_pPrev = m_pPrev;
    pItem->m_pNext = pInsertAt;
    ++this->m_nQueueSize;
  }
  v6 = this->m_Mutex.m_depth-- == 1;
  if ( v6 )
LABEL_15:
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001B980
// Name: public: void CAsyncRequestQueue::PriorityInsert(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::PriorityInsert(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx
  bool v4; // zf
  CAsyncRequestBase *m_pHead; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pItem != nullptr )
  {
    m_pHead = this->m_pHead;
    if ( m_pHead != nullptr )
    {
      while ( m_pHead->m_priority >= pItem->m_priority )
      {
        m_pHead = m_pHead->m_pNext;
        if ( m_pHead == nullptr )
          goto LABEL_11;
      }
      CAsyncRequestQueue::InsertBefore(this, pItem, pInsertAt: m_pHead);
    }
    else
    {
LABEL_11:
      CAsyncRequestQueue::AddToTail(this, pItem);
    }
    v4 = this->m_Mutex.m_depth-- == 1;
    if ( v4 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
  else
  {
    v4 = this->m_Mutex.m_depth-- == 1;
    if ( v4 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BA10
// Name: public: void CAsyncRequestQueue::Remove(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::Remove(CAsyncRequestQueue *this, CAsyncRequestBase *pItem)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pPrev; // eax
  CAsyncRequestBase *m_pNext; // eax
  bool v6; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( pItem == nullptr || this->m_nQueueSize == 0 || CAsyncRequestQueue::IsInQueue(this, pItem) == 0 )
  {
    v6 = this->m_Mutex.m_depth-- == 1;
    if ( !v6 )
      return;
    goto LABEL_19;
  }
  if ( this->m_nQueueSize == 1 )
  {
    this->m_pTail = nullptr;
    this->m_pHead = nullptr;
  }
  else
  {
    m_pPrev = pItem->m_pPrev;
    if ( m_pPrev != nullptr )
      m_pPrev->m_pNext = pItem->m_pNext;
    else
      this->m_pHead = pItem->m_pNext;
    m_pNext = pItem->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = pItem->m_pPrev;
    else
      this->m_pTail = pItem->m_pPrev;
  }
  --this->m_nQueueSize;
  pItem->m_pNext = nullptr;
  pItem->m_pPrev = nullptr;
  v6 = this->m_Mutex.m_depth-- == 1;
  if ( v6 )
LABEL_19:
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001BAD0
// Name: public: class CAsyncRequestBase __near * CAsyncRequestQueue::RemoveHead(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncRequestBase *__thiscall CAsyncRequestQueue::RemoveHead(CAsyncRequestQueue *this)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pHead; // edi
  bool v4; // zf

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( this->m_nQueueSize != 0 && (m_pHead = this->m_pHead) != nullptr )
  {
    CAsyncRequestQueue::Remove(this, pItem: this->m_pHead);
    v4 = this->m_Mutex.m_depth-- == 1;
    if ( v4 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    return m_pHead;
  }
  else
  {
    v4 = this->m_Mutex.m_depth-- == 1;
    if ( v4 )
      _InterlockedExchange((volatile __int32 *)this, 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BB50
// Name: public: bool CAsyncFileSystem::ResolveAsyncRequest(class IAsyncRequestBase const __near *,class CAsyncRequestBase __near * __near &,enum AsyncRequestState_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncFileSystem::ResolveAsyncRequest(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest,
        CAsyncRequestBase **pRequestBase,
        AsyncRequestState_t *CurrentStage)
{
  if ( CAsyncRequestQueue::IsInQueueIp(this: &this->m_Composing, pInterfaceBase: pRequest) != 0 )
  {
    *pRequestBase = pRequest->GetBase(this: pRequest);
    *CurrentStage = ASYNC_REQUEST_STATE_COMPOSING;
    return 1;
  }
  else if ( CAsyncRequestQueue::IsInQueueIp(this: &this->m_Submitted, pInterfaceBase: pRequest) != 0 )
  {
    *pRequestBase = pRequest->GetBase(this: pRequest);
    *CurrentStage = ASYNC_REQUEST_STATE_SUBMITTED;
    return 1;
  }
  else if ( CAsyncRequestQueue::IsInQueueIp(this: &this->m_InFlight, pInterfaceBase: pRequest) != 0 )
  {
    *pRequestBase = pRequest->GetBase(this: pRequest);
    *CurrentStage = ASYNC_REQUEST_STATE_SERVICING;
    return 1;
  }
  else if ( CAsyncRequestQueue::IsInQueueIp(this: &this->m_Completed, pInterfaceBase: pRequest) != 0 )
  {
    *pRequestBase = pRequest->GetBase(this: pRequest);
    *CurrentStage = pRequest->GetRequestState(this: pRequest);
    return 1;
  }
  else
  {
    *pRequestBase = nullptr;
    *CurrentStage = ASYNC_REQUEST_STATE_UNDEFINED;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BC30
// Name: public: void CAsyncFileSystem::RemoveRequest(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::RemoveRequest(CAsyncFileSystem *this, CAsyncRequestBase *pRequest)
{
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  switch ( pRequest->m_RequestState )
  {
    case ASYNC_REQUEST_STATE_COMPOSING:
      CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: pRequest);
      break;
    case ASYNC_REQUEST_STATE_SUBMITTED:
      CAsyncRequestQueue::Remove(this: &this->m_Submitted, pItem: pRequest);
      break;
    case ASYNC_REQUEST_STATE_SERVICING:
      CAsyncRequestQueue::Remove(this: &this->m_InFlight, pItem: pRequest);
      break;
    case ASYNC_REQUEST_STATE_AWATING_FINISH:
    case ASYNC_REQUEST_STATE_COMPLETED:
      CAsyncRequestQueue::Remove(this: &this->m_Completed, pItem: pRequest);
      break;
    default:
      _Error(a1: " Couldn't Find Async Request to Remove");
      break;
  }
  if ( p_m_AsyncStateUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001BCE0
// Name: public: bool CAsyncFileSystem::ValidateRequestPtr(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncFileSystem::ValidateRequestPtr(CAsyncFileSystem *this, CAsyncRequestBase *pRequest)
{
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v5; // zf
  bool result; // al

  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  switch ( pRequest->m_RequestState )
  {
    case ASYNC_REQUEST_STATE_COMPOSING:
      if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Composing, pItem: pRequest) == 0 )
        goto $LN8;
      goto LABEL_7;
    case ASYNC_REQUEST_STATE_SUBMITTED:
$LN8:
      if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Submitted, pItem: pRequest) == 0 )
        goto $LN6;
      v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( v5 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      return true;
    case ASYNC_REQUEST_STATE_SERVICING:
$LN6:
      if ( CAsyncRequestQueue::IsInQueue(this: &this->m_InFlight, pItem: pRequest) == 0 )
        goto $LN4_3;
      v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( v5 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      return true;
    case ASYNC_REQUEST_STATE_AWATING_FINISH:
    case ASYNC_REQUEST_STATE_COMPLETED:
$LN4_3:
      if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Completed, pItem: pRequest) == 0 )
        goto LABEL_19;
LABEL_7:
      v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( v5 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      result = true;
      break;
    default:
LABEL_19:
      v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( v5 )
        _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BE70
// Name: public: void CAsyncRequestBase::ProcessCallback(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::ProcessCallback(CAsyncRequestBase *this, bool bRelease)
{
  CFunctor *m_pCallback; // ecx

  if ( this->m_RequestState == ASYNC_REQUEST_STATE_AWATING_FINISH )
  {
    m_pCallback = this->m_pCallback;
    if ( m_pCallback != nullptr )
    {
      this->m_bProcessingCallback = true;
      m_pCallback->operator()(this: m_pCallback);
      this->m_pCallback->Release(this: this->m_pCallback);
      this->m_pCallback = nullptr;
      this->m_bProcessingCallback = false;
    }
    this->m_RequestState = ASYNC_REQUEST_STATE_COMPLETED;
    if ( bRelease && !this->m_bDontAutoRelease )
      CAsyncRequestBase::Release(this);
  }
  else
  {
    _Error(a1: "Callback called at wrong time");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BEE0
// Name: public: void CAsyncRequestBase::UpdateAfterServicing(struct CAsyncResultInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestBase::UpdateAfterServicing(CAsyncRequestBase *this, CAsyncResultInfo_t *results)
{
  _DWORD *m_pOuter; // eax
  AsyncFileOperation_t m_Operation; // ecx
  bool v4; // zf
  int m_nBytesTransferred; // ecx

  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter != nullptr )
  {
    m_Operation = this->m_Operation;
    if ( m_Operation <= ASYNC_OP_UNDEFINED )
    {
LABEL_10:
      _Error(a1: "Bad Outer in CAsyncRequestBase::UpdateAfterServicing");
      return;
    }
    if ( m_Operation > ASYNC_OP_APPENDFILE )
    {
      if ( m_Operation == ASYNC_OP_SCANDIR )
      {
        m_pOuter[15] = m_pOuter[20];
        return;
      }
      goto LABEL_10;
    }
    v4 = m_pOuter[16] == 0;
    m_pOuter[22] = results->m_pAllocatedBuffer;
    if ( v4 )
      m_nBytesTransferred = results->m_nBytesTransferred;
    else
      m_nBytesTransferred = m_pOuter[17];
    m_pOuter[23] = m_nBytesTransferred;
    m_pOuter[24] = results->m_nBytesTransferred;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BF50
// Name: public: virtual class IAsyncRequestBase __near * CAsyncGroupRequest::GetAsyncRequest(int)
// Source: json
//------------------------------------------------------------------------------
IAsyncRequestBase *__thiscall CAsyncGroupRequest::GetAsyncRequest(CAsyncGroupRequest *this, int nRNum)
{
  if ( nRNum < 0 || nRNum >= this->m_RequestList.m_Size )
    return nullptr;
  else
    return this->m_RequestList.m_Memory.m_pMemory[nRNum];
}

//------------------------------------------------------------------------------
// Address: 0x1001BF70
// Name: public: virtual class IAsyncFileRequest __near * CAsyncGroupRequest::GetAsyncFileRequest(int)
// Source: json
//------------------------------------------------------------------------------
IAsyncFileRequest *__thiscall CAsyncGroupRequest::GetAsyncFileRequest(CAsyncGroupRequest *this, int nRNum)
{
  IAsyncRequestBase *v2; // esi
  int v3; // eax

  if ( nRNum < 0 || nRNum >= this->m_RequestList.m_Size )
    return nullptr;
  v2 = this->m_RequestList.m_Memory.m_pMemory[nRNum];
  v3 = v2->GetAsyncOperationType(this: v2);
  if ( v3 == 1 || v3 == 2 || v3 == 3 )
    return (IAsyncFileRequest *)v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001BFC0
// Name: public: virtual class IAsyncSearchRequest __near * CAsyncGroupRequest::GetAsyncSearchRequest(int)
// Source: json
//------------------------------------------------------------------------------
IAsyncSearchRequest *__thiscall CAsyncGroupRequest::GetAsyncSearchRequest(CAsyncGroupRequest *this, int nRNum)
{
  IAsyncRequestBase *v2; // esi

  if ( nRNum < 0 || nRNum >= this->m_RequestList.m_Size )
    return nullptr;
  v2 = this->m_RequestList.m_Memory.m_pMemory[nRNum];
  return v2->GetAsyncOperationType(this: v2) == 4 ? (IAsyncSearchRequest *)v2 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001C000
// Name: public: CAsyncFileRequest::CAsyncFileRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncFileRequest *__thiscall CAsyncFileRequest::CAsyncFileRequest(CAsyncFileRequest *this)
{
  this->__vftable = (CAsyncFileRequest_vtbl *)&CAsyncFileRequest::`vftable';
  this->m_Base.m_pCallback = nullptr;
  this->m_Base.m_pResultQueue = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_UNDEFINED;
  this->m_Base.m_priority = 0;
  this->m_Base.m_pNext = nullptr;
  this->m_Base.m_pPrev = nullptr;
  this->m_Base.m_RequestState = ASYNC_REQUEST_STATE_COMPOSING;
  this->m_Base.m_RequestStatus = ASYNC_REQUEST_OK;
  *(_WORD *)&this->m_Base.m_bAbortRequest = 0;
  this->m_Base.m_bDontAutoRelease = false;
  this->m_Base.m_pSyncThreadEvent = nullptr;
  this->m_Base.m_pOldAsyncControl = nullptr;
  this->m_Base.m_pOldAsyncStatus = FSASYNC_OK;
  this->m_Base.m_pGroup = nullptr;
  this->m_Base.m_pOuter = this;
  this->m_pFileName = nullptr;
  this->m_pUserProvidedDataBuffer = nullptr;
  this->m_nUserProvidedBufferSize = 0;
  this->m_nFileSeekOffset = 0;
  this->m_nMaxIOSizeInBytes = 0;
  this->m_pResultsBuffer = nullptr;
  this->m_nResultsBufferSize = 0;
  this->m_nIOActualSize = 0;
  this->m_bDeleteBufferMemory = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001C060
// Name: public: virtual void CAsyncGroupRequest::KeepRequestPostCallback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::KeepRequestPostCallback(CAsyncSearchRequest *this)
{
  this->m_Base.m_bDontAutoRelease = true;
}

//------------------------------------------------------------------------------
// Address: 0x1001C070
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileRequest::GetRequestStatus(void)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileRequest::GetRequestStatus(CAsyncSearchRequest *this)
{
  return this->m_Base.m_RequestStatus;
}

//------------------------------------------------------------------------------
// Address: 0x1001C080
// Name: public: virtual int CAsyncSearchRequest::GetResultCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAsyncSearchRequest::GetResultCount(CAsyncSearchRequest *this)
{
  return this->m_nNumResults;
}

//------------------------------------------------------------------------------
// Address: 0x1001C090
// Name: public: virtual void __near * CAsyncFileRequest::GetUserBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CAsyncFileRequest::GetUserBuffer(CAsyncFileRequest *this)
{
  return this->m_pUserProvidedDataBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0B0
// Name: public: virtual void __near * CAsyncFileRequest::GetResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CAsyncFileRequest::GetResultBuffer(CAsyncFileRequest *this)
{
  return this->m_pResultsBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0D0
// Name: public: virtual unsigned int CAsyncFileRequest::GetIOTransferredSize(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAsyncFileRequest::GetIOTransferredSize(vgui::BuildGroup *this)
{
  return this->m_pResourceName;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0E0
// Name: public: virtual void CAsyncFileRequest::KeepResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::KeepResultBuffer(CAsyncFileRequest *this)
{
  this->m_bDeleteBufferMemory = false;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0F0
// Name: public: virtual void CAsyncFileRequest::ReleaseResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::ReleaseResultBuffer(CAsyncFileRequest *this)
{
  this->m_bDeleteBufferMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x1001C100
// Name: public: virtual void CAsyncGroupRequest::AssignResultQueue(class CIOCompletionQueue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::AssignResultQueue(CAsyncSearchRequest *this, CIOCompletionQueue *pMsgQueue)
{
  this->m_Base.m_pResultQueue = pMsgQueue;
}

//------------------------------------------------------------------------------
// Address: 0x1001C110
// Name: public: virtual CAsyncFileRequest::~CAsyncFileRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::~CAsyncFileRequest(CAsyncFileRequest *this)
{
  char *m_pFileName; // eax
  bool v3; // zf
  unsigned int m_pResultsBuffer; // eax
  CFunctor *m_pCallback; // ecx
  CAsyncRequestBase *p_m_Base; // esi

  m_pFileName = (char *)this->m_pFileName;
  this->__vftable = (CAsyncFileRequest_vtbl *)&CAsyncFileRequest::`vftable';
  if ( m_pFileName != nullptr )
    free(pMem: m_pFileName);
  v3 = !this->m_bDeleteBufferMemory;
  this->m_pFileName = nullptr;
  if ( !v3 )
  {
    m_pResultsBuffer = (unsigned int)this->m_pResultsBuffer;
    if ( m_pResultsBuffer != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((m_pResultsBuffer & 0xFFFFFFFC) - 4));
  }
  m_pCallback = this->m_Base.m_pCallback;
  p_m_Base = &this->m_Base;
  if ( m_pCallback != nullptr )
    m_pCallback->Release(this: m_pCallback);
  p_m_Base->m_pCallback = nullptr;
  CAsyncFileSystem::RemoveRequest(this: &g_FileSystem_Async, pRequest: p_m_Base);
}

//------------------------------------------------------------------------------
// Address: 0x1001C180
// Name: public: virtual char const __near * CAsyncSearchRequest::GetMatchedFile(int)
// Source: json
//------------------------------------------------------------------------------
CDirectoryEntryInfo_t *__thiscall CAsyncSearchRequest::GetMatchedFile(CAsyncSearchRequest *this, int rNum)
{
  AsyncRequestState_t m_RequestState; // eax

  m_RequestState = this->m_Base.m_RequestState;
  if ( m_RequestState < ASYNC_REQUEST_STATE_AWATING_FINISH
    || m_RequestState > ASYNC_REQUEST_STATE_COMPLETED
    || rNum < 0
    || rNum >= this->m_nNumResults )
  {
    return nullptr;
  }
  else
  {
    return &this->m_Results.m_Memory.m_pMemory[rNum];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C1B0
// Name: public: virtual void CBaseAppSystem<class IDedicatedExports>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IDedicatedExports>::Reconnect(
        CBaseAppSystem<IDedicatedExports> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1001C1D0
// Name: public: virtual class IAsyncFileRequest __near * CAsyncFileSystem::CreateNewFileRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncFileRequest *__thiscall CAsyncFileSystem::CreateNewFileRequest(CAsyncFileSystem *this)
{
  CAsyncFileRequest *v2; // eax
  CAsyncFileRequest *v3; // esi

  v2 = (CAsyncFileRequest *)operator new(nSize: 0x68u);
  if ( v2 != nullptr )
  {
    v3 = CAsyncFileRequest::CAsyncFileRequest(this: v2);
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: &v3->m_Base);
    return v3;
  }
  else
  {
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: (CAsyncRequestBase *)4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C210
// Name: public: virtual void CAsyncFileSystem::ReleaseAsyncRequest(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::ReleaseAsyncRequest(CAsyncFileSystem *this, const IAsyncRequestBase *pRequest)
{
  CAsyncRequestBase *v3; // edi
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v6; // zf

  v3 = pRequest->GetBase(this: pRequest);
  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  if ( !CAsyncFileSystem::ValidateRequestPtr(this, pRequest: v3) )
  {
    _Error(a1: "Bad Release Request");
    goto LABEL_14;
  }
  if ( v3->m_RequestState == ASYNC_REQUEST_STATE_SERVICING )
  {
    v3->m_bAbortRequest = true;
    v6 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( !v6 )
      return;
  }
  else
  {
    if ( !v3->m_bProcessingCallback )
    {
      CAsyncRequestBase::DeleteOuter(this: v3);
LABEL_14:
      v6 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
      if ( !v6 )
        return;
      goto LABEL_15;
    }
    v3->m_bDontAutoRelease = false;
    v6 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( !v6 )
      return;
  }
LABEL_15:
  _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001C2D0
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::GetAsyncFileRequestStatus(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::GetAsyncFileRequestStatus(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest)
{
  CAsyncRequestBase *v3; // esi
  bool v4; // zf
  AsyncRequestStatus_t result; // eax

  v3 = pRequest->GetBase(this: pRequest);
  v4 = !CAsyncFileSystem::ValidateRequestPtr(this, pRequest: v3);
  result = ASYNC_REQUEST_ERROR_BADPTR;
  if ( !v4 )
    return v3->m_RequestStatus;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C300
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::AbortAsyncFileRequest(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::AbortAsyncFileRequest(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest)
{
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v5; // zf
  AsyncRequestStatus_t result; // eax
  CAsyncRequestBase *pRequestBase; // [esp+8h] [ebp-8h] BYREF
  AsyncRequestState_t CurrentStage; // [esp+Ch] [ebp-4h] BYREF

  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  pRequestBase = nullptr;
  CurrentStage = ASYNC_REQUEST_STATE_UNDEFINED;
  if ( CAsyncFileSystem::ResolveAsyncRequest(this, pRequest, &pRequestBase, &CurrentStage) != 0 )
  {
    switch ( CurrentStage )
    {
      case ASYNC_REQUEST_STATE_COMPOSING:
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        result = ASYNC_REQUEST_ERROR_NOTSUBMITTED;
        break;
      case ASYNC_REQUEST_STATE_SUBMITTED:
        CAsyncRequestBase::DeleteOuter(this: pRequestBase);
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        result = ASYNC_REQUEST_OK;
        break;
      case ASYNC_REQUEST_STATE_SERVICING:
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        result = ASYNC_REQUEST_ERROR_NOTSUBMITTED;
        break;
      case ASYNC_REQUEST_STATE_AWATING_FINISH:
      case ASYNC_REQUEST_STATE_COMPLETED:
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        result = ASYNC_REQUEST_ERROR_ALREADYSERVICED;
        break;
      default:
        v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
        return ASYNC_REQUEST_ERROR_BADPTR;
    }
  }
  else
  {
    v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( v5 )
    {
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      return ASYNC_REQUEST_ERROR_BADPTR;
    }
    else
    {
      return ASYNC_REQUEST_ERROR_BADPTR;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C420
// Name: public: virtual void CAsyncFileSystem::SuspendAllAsyncIO(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::SuspendAllAsyncIO(CAsyncFileSystem *this, bool bWaitForIOCompletion)
{
  _InterlockedExchangeAdd(&this->m_nSuspendCount.m_value, 1u);
  if ( bWaitForIOCompletion && this->m_nSuspendCount.m_value > 0 && this->m_nJobsInflight.m_value > 0 )
  {
    do
      CThreadEvent::Wait(this: &this->m_CompletionSignal, a2: 0xAu);
    while ( this->m_nJobsInflight.m_value > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C470
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::AbortAllAsyncIO(bool)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::AbortAllAsyncIO(CAsyncFileSystem *this, bool bWaitForIOCompletion)
{
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  bool v5; // zf
  DWORD v7; // ecx
  CAsyncRequestBase *m_pHead; // edi
  void *m_pOuter; // ecx
  int m_Operation; // eax
  DWORD v11; // ecx
  CAsyncRequestBase *v12; // edi

  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_AsyncStateUpdateMutex->m_depth;
  }
  if ( this->m_Submitted.m_nQueueSize > 0 )
  {
    while ( 1 )
    {
LABEL_11:
      v7 = GetCurrentThreadId();
      if ( v7 != this->m_Submitted.m_Mutex.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_Submitted, v7, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &this->m_Submitted, a2: v7, a3: 0);
      }
      else
      {
        ++this->m_Submitted.m_Mutex.m_depth;
      }
      if ( this->m_Submitted.m_nQueueSize != 0 && (m_pHead = this->m_Submitted.m_pHead) != nullptr )
      {
        CAsyncRequestQueue::Remove(this: &this->m_Submitted, pItem: this->m_Submitted.m_pHead);
        v5 = this->m_Submitted.m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)&this->m_Submitted, 0);
      }
      else
      {
        v5 = this->m_Submitted.m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)&this->m_Submitted, 0);
        m_pHead = nullptr;
      }
      m_pOuter = m_pHead->m_pOuter;
      if ( m_pHead->m_pOuter != nullptr )
      {
        m_Operation = m_pHead->m_Operation;
        if ( m_Operation <= 0 )
          break;
        if ( m_Operation <= 3 )
        {
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        }
        else
        {
          if ( m_Operation != 4 )
            break;
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
        }
      }
LABEL_29:
      if ( this->m_Submitted.m_nQueueSize <= 0 )
        goto LABEL_30;
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
    goto LABEL_29;
  }
  if ( this->m_nJobsInflight.m_value != 0 && bWaitForIOCompletion )
  {
    if ( this->m_Submitted.m_nQueueSize > 0 )
      goto LABEL_11;
LABEL_30:
    while ( this->m_InFlight.m_nQueueSize > 0 )
    {
      v11 = GetCurrentThreadId();
      if ( v11 != this->m_InFlight.m_Mutex.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_InFlight, v11, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &this->m_InFlight, a2: v11, a3: 0);
      }
      else
      {
        ++this->m_InFlight.m_Mutex.m_depth;
      }
      if ( this->m_InFlight.m_nQueueSize != 0 && (v12 = this->m_InFlight.m_pHead) != nullptr )
      {
        CAsyncRequestQueue::Remove(this: &this->m_InFlight, pItem: this->m_InFlight.m_pHead);
        v5 = this->m_InFlight.m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)&this->m_InFlight, 0);
      }
      else
      {
        v5 = this->m_InFlight.m_Mutex.m_depth-- == 1;
        if ( v5 )
          _InterlockedExchange((volatile __int32 *)&this->m_InFlight, 0);
        v12 = nullptr;
      }
      v12->m_bAbortRequest = true;
    }
    v5 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)&this->m_AsyncStateUpdateMutex, 0);
    if ( bWaitForIOCompletion && this->m_nJobsInflight.m_value > 0 )
    {
      do
        CThreadEvent::Wait(this: &this->m_CompletionSignal, a2: 0xAu);
      while ( this->m_nJobsInflight.m_value > 0 );
    }
  }
  else
  {
    v5 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( v5 )
    {
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
      return ASYNC_REQUEST_OK;
    }
  }
  return ASYNC_REQUEST_OK;
}

//------------------------------------------------------------------------------
// Address: 0x1001C650
// Name: public: struct CTSQueue<struct CAsyncIOResult_t,0,1>::Node_t __near * CTSQueue<struct CAsyncIOResult_t,0,1>::Push(struct CTSQueue<struct CAsyncIOResult_t,0,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CAsyncIOResult_t,0,1>::Node_t *__thiscall CTSQueue<CAsyncIOResult_t,0,1>::Push(
        CTSQueue<CAsyncIOResult_t,0,1> *this,
        CTSQueue<CAsyncIOResult_t,0,1>::Node_t *pNode)
{
  CTSQueue<CAsyncIOResult_t,0,1>::Node_t *v3; // edi
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<CAsyncIOResult_t,0,1>::Node_t *)this;
  v3 = this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<CAsyncIOResult_t,0,1> *)_InterlockedCompareExchange(
                                            (volatile signed __int32 *)v3,
                                            (signed __int32)pNode,
                                            (signed __int32)this) != this;
        i = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: v3->pNext, a3: i + 1, a4: v3, a5: i);
    v3 = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: i + 1, a4: v3, a5: i);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001C730
// Name: public: CAsyncRequestQueue::~CAsyncRequestQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncRequestQueue::~CAsyncRequestQueue(CAsyncRequestQueue *this)
{
  DWORD CurrentThreadId; // ecx
  CAsyncRequestBase *m_pHead; // esi
  CAsyncRequestBase *m_pNext; // ebx
  CFunctor *m_pCallback; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  if ( this->m_pHead != nullptr )
  {
    _Warning(a1: " CAsyncRequestQueue destructor called while queue was not empty");
    if ( this->m_pHead != nullptr )
    {
      do
      {
        m_pHead = this->m_pHead;
        m_pNext = m_pHead->m_pNext;
        if ( m_pHead != nullptr )
        {
          m_pCallback = m_pHead->m_pCallback;
          if ( m_pCallback != nullptr )
            m_pCallback->Release(this: m_pCallback);
          m_pHead->m_pCallback = nullptr;
          CAsyncFileSystem::RemoveRequest(this: &g_FileSystem_Async, pRequest: m_pHead);
          free(pMem: m_pHead);
        }
        this->m_pHead = m_pNext;
      }
      while ( m_pNext != nullptr );
    }
  }
  if ( this->m_Mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001C7D0
// Name: public: CAsyncFileSystem::~CAsyncFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::~CAsyncFileSystem(CAsyncFileSystem *this)
{
  this->__vftable = (CAsyncFileSystem_vtbl *)&CAsyncFileSystem::`vftable';
  _InterlockedExchange(&this->m_nSuspendCount.m_value, 1);
  CAsyncFileSystem::AbortAllAsyncIO(this, bWaitForIOCompletion: true);
  CThreadSyncObject::~CThreadSyncObject(this: &this->m_CompletionSignal);
  CAsyncRequestQueue::~CAsyncRequestQueue(this: &this->m_Completed);
  CAsyncRequestQueue::~CAsyncRequestQueue(this: &this->m_InFlight);
  CAsyncRequestQueue::~CAsyncRequestQueue(this: &this->m_Submitted);
  CAsyncRequestQueue::~CAsyncRequestQueue(this: &this->m_Composing);
}

//------------------------------------------------------------------------------
// Address: 0x1001C820
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class IFileSystem,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IFileSystem,0>::GetTier(CTier2AppSystem<IFileSystem,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1001C830
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
// Address: 0x1001C850
// Name: public: virtual void CTier2AppSystem<class IAsyncFileSystem,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IAsyncFileSystem,0>::Shutdown(CTier2AppSystem<IAsyncFileSystem,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x1001C860
// Name: public: virtual void CTier2AppSystem<class IAsyncFileSystem,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IAsyncFileSystem,0>::Disconnect(CTier2AppSystem<IFileSystem,0> *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x1001C8F0
// Name: public: CAsyncGroupRequest::CAsyncGroupRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncGroupRequest *__thiscall CAsyncGroupRequest::CAsyncGroupRequest(CAsyncGroupRequest *this)
{
  this->__vftable = (CAsyncGroupRequest_vtbl *)&CAsyncGroupRequest::`vftable';
  this->m_Base.m_pOuter = nullptr;
  this->m_Base.m_pCallback = nullptr;
  this->m_Base.m_pResultQueue = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_UNDEFINED;
  this->m_Base.m_priority = 0;
  this->m_Base.m_pNext = nullptr;
  this->m_Base.m_pPrev = nullptr;
  this->m_Base.m_RequestState = ASYNC_REQUEST_STATE_COMPOSING;
  this->m_Base.m_RequestStatus = ASYNC_REQUEST_OK;
  *(_WORD *)&this->m_Base.m_bAbortRequest = 0;
  this->m_Base.m_bDontAutoRelease = false;
  this->m_Base.m_pSyncThreadEvent = nullptr;
  this->m_Base.m_pOldAsyncControl = nullptr;
  this->m_Base.m_pOldAsyncStatus = FSASYNC_OK;
  this->m_Base.m_pGroup = nullptr;
  this->m_RequestList.m_Memory.m_pMemory = nullptr;
  this->m_RequestList.m_Memory.m_nAllocationCount = 0;
  this->m_RequestList.m_Memory.m_nGrowSize = 0;
  this->m_RequestList.m_Size = 0;
  this->m_RequestList.m_pElements = nullptr;
  this->m_ValidList.m_Memory.m_pMemory = nullptr;
  this->m_ValidList.m_Memory.m_nAllocationCount = 0;
  this->m_ValidList.m_Memory.m_nGrowSize = 0;
  this->m_ValidList.m_Size = 0;
  this->m_ValidList.m_pElements = nullptr;
  this->m_nNumRequestsOutstanding.m_value = 0;
  this->m_Base.m_pOuter = this;
  _InterlockedExchange(&this->m_nNumRequestsOutstanding.m_value, 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001C960
// Name: public: virtual void CAsyncGroupRequest::DontKeepRequestPostCallback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::DontKeepRequestPostCallback(CAsyncSearchRequest *this)
{
  this->m_Base.m_bDontAutoRelease = false;
}

//------------------------------------------------------------------------------
// Address: 0x1001C970
// Name: public: virtual enum AsyncRequestState_t CAsyncSearchRequest::GetRequestState(void)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestState_t __thiscall CAsyncSearchRequest::GetRequestState(CAsyncSearchRequest *this)
{
  return this->m_Base.m_RequestState;
}

//------------------------------------------------------------------------------
// Address: 0x1001C980
// Name: public: virtual void CAsyncGroupRequest::AssignCallback(class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::AssignCallback(CAsyncSearchRequest *this, CFunctor *pCallback)
{
  CFunctor *m_pCallback; // ecx

  m_pCallback = this->m_Base.m_pCallback;
  if ( m_pCallback != nullptr )
    m_pCallback->Release(this: m_pCallback);
  this->m_Base.m_pCallback = pCallback;
}

//------------------------------------------------------------------------------
// Address: 0x1001C9B0
// Name: public: virtual void CAsyncFileRequest::AssignCallbackAndQueue(class CIOCompletionQueue __near *,class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileRequest::AssignCallbackAndQueue(
        CAsyncSearchRequest *this,
        CIOCompletionQueue *pMsgQueue,
        CFunctor *pCallback)
{
  CFunctor *m_pCallback; // ecx

  m_pCallback = this->m_Base.m_pCallback;
  if ( m_pCallback != nullptr )
    m_pCallback->Release(this: m_pCallback);
  this->m_Base.m_pCallback = pCallback;
  this->m_Base.m_pResultQueue = pMsgQueue;
}

//------------------------------------------------------------------------------
// Address: 0x1001C9F0
// Name: public: virtual void CAsyncGroupRequest::ProcessCallback(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::ProcessCallback(CAsyncSearchRequest *this, bool bRelease)
{
  CAsyncRequestBase::ProcessCallback(this: &this->m_Base, bRelease);
}

//------------------------------------------------------------------------------
// Address: 0x1001CA00
// Name: public: CAsyncSearchRequest::CAsyncSearchRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncSearchRequest *__thiscall CAsyncSearchRequest::CAsyncSearchRequest(CAsyncSearchRequest *this)
{
  this->__vftable = (CAsyncSearchRequest_vtbl *)&CAsyncSearchRequest::`vftable';
  this->m_Base.m_pCallback = nullptr;
  this->m_Base.m_pResultQueue = nullptr;
  this->m_Base.m_Operation = ASYNC_OP_UNDEFINED;
  this->m_Base.m_priority = 0;
  this->m_Base.m_pNext = nullptr;
  this->m_Base.m_pPrev = nullptr;
  this->m_Base.m_RequestState = ASYNC_REQUEST_STATE_COMPOSING;
  this->m_Base.m_RequestStatus = ASYNC_REQUEST_OK;
  *(_WORD *)&this->m_Base.m_bAbortRequest = 0;
  this->m_Base.m_bDontAutoRelease = false;
  this->m_Base.m_pSyncThreadEvent = nullptr;
  this->m_Base.m_pOldAsyncControl = nullptr;
  this->m_Base.m_pOldAsyncStatus = FSASYNC_OK;
  this->m_Base.m_pGroup = nullptr;
  this->m_Results.m_Memory.m_pMemory = nullptr;
  this->m_Results.m_Memory.m_nAllocationCount = 0;
  this->m_Results.m_Memory.m_nGrowSize = 0;
  this->m_Results.m_Size = 0;
  this->m_Results.m_pElements = nullptr;
  this->m_Base.m_pOuter = this;
  _V_memset(dest: this->m_FileSpec, fill: 0, count: 260);
  _V_memset(dest: this->m_PathID, fill: 0, count: 260);
  _V_memset(dest: this->m_SearchPath, fill: 0, count: 260);
  _V_memset(dest: this->m_SearchSpec, fill: 0, count: 260);
  this->m_nNumResults = 0;
  this->m_bRecurseSubdirs = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001CAA0
// Name: private: virtual class CAsyncRequestBase __near * CAsyncFileRequest::GetBase(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncRequestBase *__thiscall CAsyncFileRequest::GetBase(CAsyncSearchRequest *this)
{
  return &this->m_Base;
}

//------------------------------------------------------------------------------
// Address: 0x1001CAB0
// Name: public: virtual bool CAsyncSearchRequest::GetSubdirectoryScan(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAsyncSearchRequest::GetSubdirectoryScan(CAsyncSearchRequest *this)
{
  return this->m_bRecurseSubdirs;
}

//------------------------------------------------------------------------------
// Address: 0x1001CAC0
// Name: public: virtual void CAsyncSearchRequest::SetPriority(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::SetPriority(CAsyncSearchRequest *this, int nPriority)
{
  this->m_Base.m_priority = nPriority;
}

//------------------------------------------------------------------------------
// Address: 0x1001CAD0
// Name: public: virtual void CAsyncSearchRequest::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncSearchRequest::Release(CAsyncSearchRequest *this)
{
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // eax

  if ( this->m_Base.m_RequestState != ASYNC_REQUEST_STATE_COMPLETED )
  {
    _Error(a1: "Async Request has not finished, unable to release");
    return;
  }
  m_pOuter = this->m_Base.m_pOuter;
  if ( m_pOuter != nullptr )
  {
    m_Operation = this->m_Base.m_Operation;
    if ( m_Operation > ASYNC_OP_UNDEFINED )
    {
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        return;
      }
      if ( m_Operation == ASYNC_OP_SCANDIR )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
        return;
      }
    }
    _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CB20
// Name: public: virtual class IAsyncSearchRequest __near * CAsyncFileSystem::CreateNewSearchRequest(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncSearchRequest *__thiscall CAsyncFileSystem::CreateNewSearchRequest(CAsyncFileSystem *this)
{
  CAsyncSearchRequest *v2; // eax
  CAsyncSearchRequest *v3; // esi

  v2 = (CAsyncSearchRequest *)operator new(nSize: 0x468u);
  if ( v2 != nullptr )
  {
    v3 = CAsyncSearchRequest::CAsyncSearchRequest(this: v2);
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: &v3->m_Base);
    return v3;
  }
  else
  {
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: (CAsyncRequestBase *)4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CB70
// Name: public: virtual class IAsyncGroupRequest __near * CAsyncFileSystem::CreateNewAsyncRequestGroup(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncGroupRequest *__thiscall CAsyncFileSystem::CreateNewAsyncRequestGroup(CAsyncFileSystem *this)
{
  CAsyncGroupRequest *v2; // eax
  CAsyncGroupRequest *v3; // esi

  v2 = (CAsyncGroupRequest *)operator new(nSize: 0x68u);
  if ( v2 != nullptr )
  {
    v3 = CAsyncGroupRequest::CAsyncGroupRequest(this: v2);
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: &v3->m_Base);
    return v3;
  }
  else
  {
    CAsyncRequestQueue::AddToTail(this: &this->m_Composing, pItem: (CAsyncRequestBase *)4);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CBB0
// Name: private: void CAsyncFileSystem::NotifyMessageQueueOrCallback(class CAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::NotifyMessageQueueOrCallback(CAsyncFileSystem *this, CAsyncRequestBase *pRequest)
{
  void *m_pOuter; // ebx
  AsyncFileOperation_t m_Operation; // eax
  AsyncRequestStatus_t m_RequestStatus; // edi
  CIOCompletionQueue *m_pResultQueue; // esi
  TSLNodeBase_t *v6; // eax
  CFunctor *m_pCallback; // ecx
  bool v8; // zf

  if ( pRequest->m_pResultQueue != nullptr )
  {
    m_pOuter = pRequest->m_pOuter;
    if ( pRequest->m_pOuter != nullptr )
    {
      m_Operation = pRequest->m_Operation;
      if ( m_Operation > ASYNC_OP_UNDEFINED && m_Operation <= ASYNC_OP_SCANDIR )
      {
LABEL_7:
        m_RequestStatus = pRequest->m_RequestStatus;
        m_pResultQueue = pRequest->m_pResultQueue;
        v6 = CTSListBase::Pop(this: &m_pResultQueue->m_TSIOResultQueue.m_FreeNodes);
        if ( v6 != nullptr || (v6 = (TSLNodeBase_t *)operator new(nSize: 0x10u)) != nullptr )
        {
          *((_DWORD *)&v6->Next + 1) = m_pOuter;
          v6[1].Next = (TSLNodeBase_t *)m_RequestStatus;
          CTSQueue<CAsyncIOResult_t,0,1>::Push(
            this: &m_pResultQueue->m_TSIOResultQueue,
            pNode: (CTSQueue<CAsyncIOResult_t,0,1>::Node_t *)v6);
        }
        else
        {
          CTSQueue<CAsyncIOResult_t,0,1>::Push(this: &m_pResultQueue->m_TSIOResultQueue, pNode: nullptr);
        }
        return;
      }
      _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
    }
    m_pOuter = nullptr;
    goto LABEL_7;
  }
  if ( pRequest->m_RequestState == ASYNC_REQUEST_STATE_AWATING_FINISH )
  {
    m_pCallback = pRequest->m_pCallback;
    if ( m_pCallback != nullptr )
    {
      pRequest->m_bProcessingCallback = true;
      m_pCallback->operator()(this: m_pCallback);
      pRequest->m_pCallback->Release(this: pRequest->m_pCallback);
      pRequest->m_pCallback = nullptr;
      pRequest->m_bProcessingCallback = false;
    }
    v8 = !pRequest->m_bDontAutoRelease;
    pRequest->m_RequestState = ASYNC_REQUEST_STATE_COMPLETED;
    if ( v8 )
      CAsyncRequestBase::Release(this: pRequest);
  }
  else
  {
    _Error(a1: "Callback called at wrong time");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CC90
// Name: public: virtual bool CAsyncFileSystem::BlockUntilAsyncIOComplete(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAsyncFileSystem::BlockUntilAsyncIOComplete(CAsyncFileSystem *this, const IAsyncRequestBase *pRequest)
{
  CAsyncFileSystem *v2; // ebx
  CAsyncRequestBase *(__thiscall *GetBase)(IAsyncRequestBase *); // edx
  int v4; // edi
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // ecx
  char v8; // al
  CThreadEvent syncEvent; // [esp+8h] [ebp-Ch] BYREF
  CAsyncFileSystem *v11; // [esp+10h] [ebp-4h]

  v2 = this;
  GetBase = pRequest->GetBase;
  v11 = this;
  v4 = (int)GetBase(this: pRequest);
  if ( !CAsyncFileSystem::ValidateRequestPtr(this: v2, pRequest: (CAsyncRequestBase *)v4)
    || v2->m_bIOSuspended
    || *(int *)(v4 + 28) <= 1 )
  {
    return 0;
  }
  CThreadEvent::CThreadEvent(this: &syncEvent, a2: false);
  p_m_AsyncStateUpdateMutex = &v2->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != v2->m_AsyncStateUpdateMutex.m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
      v2 = v11;
      goto LABEL_10;
    }
    v2 = v11;
  }
  ++p_m_AsyncStateUpdateMutex->m_depth;
LABEL_10:
  if ( *(int *)(v4 + 28) >= 4 )
  {
    v8 = 0;
  }
  else
  {
    *(_DWORD *)(v4 + 40) = &syncEvent;
    v8 = 1;
  }
  if ( p_m_AsyncStateUpdateMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
  if ( v8 != 0 )
  {
    CThreadEvent::Wait(this: *(CThreadEvent **)(v4 + 40), a2: 0xFFFFFFFF);
    CAsyncFileSystem::NotifyMessageQueueOrCallback(this: v2, pRequest: (CAsyncRequestBase *)v4);
  }
  CThreadSyncObject::~CThreadSyncObject(this: &syncEvent);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001CE10
// Name: public: virtual void CAsyncGroupRequest::AddAsyncRequest(class IAsyncRequestBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncGroupRequest::AddAsyncRequest(CAsyncGroupRequest *this, IAsyncRequestBase *pRequest)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IAsyncRequestBase **m_pMemory; // ecx
  int v6; // eax
  IAsyncRequestBase **v7; // eax
  int v8; // edi
  int v9; // eax
  bool *v10; // ecx
  int v11; // eax
  bool *v12; // esi

  m_nAllocationCount = this->m_RequestList.m_Memory.m_nAllocationCount;
  m_Size = this->m_RequestList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPackedStore *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_RequestList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_RequestList.m_Size;
  m_pMemory = this->m_RequestList.m_Memory.m_pMemory;
  v6 = this->m_RequestList.m_Size - m_Size - 1;
  this->m_RequestList.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_RequestList.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pRequest;
  v8 = this->m_ValidList.m_Size;
  v9 = this->m_ValidList.m_Memory.m_nAllocationCount;
  if ( v8 + 1 > v9 )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&this->m_ValidList, num: v8 - v9 + 1);
  ++this->m_ValidList.m_Size;
  v10 = this->m_ValidList.m_Memory.m_pMemory;
  v11 = this->m_ValidList.m_Size - v8 - 1;
  this->m_ValidList.m_pElements = v10;
  if ( v11 > 0 )
    _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: v11);
  v12 = &this->m_ValidList.m_Memory.m_pMemory[v8];
  if ( v12 != nullptr )
    *v12 = true;
}

//------------------------------------------------------------------------------
// Address: 0x1001CEC0
// Name: private: void CAsyncFileSystem::AsyncIOCallBackHandler(class CAsyncRequestBase __near *,struct CAsyncResultInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::AsyncIOCallBackHandler(
        CAsyncFileSystem *this,
        CAsyncRequestBase *pRequest,
        CAsyncResultInfo_t *results)
{
  CAsyncFileSystem *v3; // ebx
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // edi
  DWORD CurrentThreadId; // ecx
  void *m_pOuter; // ecx
  AsyncFileOperation_t m_Operation; // esi
  bool v8; // zf
  CThreadEvent *m_pSyncThreadEvent; // ecx

  v3 = this;
  if ( CAsyncRequestQueue::IsInQueue(this: &this->m_InFlight, pItem: pRequest) == 0 )
  {
    _Error(a1: "Can't find completed Async IO request");
    return;
  }
  p_m_AsyncStateUpdateMutex = &v3->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == v3->m_AsyncStateUpdateMutex.m_ownerID )
    goto LABEL_6;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) == 0 )
  {
    v3 = this;
LABEL_6:
    ++p_m_AsyncStateUpdateMutex->m_depth;
    goto LABEL_8;
  }
  _mm_pause();
  CThreadFastMutex::Lock(a1: p_m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  v3 = this;
LABEL_8:
  CAsyncRequestQueue::Remove(this: &v3->m_InFlight, pItem: pRequest);
  pRequest->m_RequestState = ASYNC_REQUEST_STATE_AWATING_FINISH;
  _InterlockedExchangeAdd(&v3->m_nJobsInflight.m_value, 0xFFFFFFFF);
  if ( pRequest->m_bAbortRequest )
  {
    CAsyncRequestBase::AbortAfterServicing(this: pRequest, results);
    m_pOuter = pRequest->m_pOuter;
    if ( pRequest->m_pOuter != nullptr )
    {
      m_Operation = pRequest->m_Operation;
      if ( m_Operation <= ASYNC_OP_UNDEFINED )
        goto LABEL_15;
      if ( m_Operation <= ASYNC_OP_APPENDFILE )
      {
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 116))(a1: m_pOuter, a2: 1);
        goto LABEL_16;
      }
      if ( m_Operation != ASYNC_OP_SCANDIR )
      {
LABEL_15:
        _Error(a1: "Bad Outer in CAsyncRequestBase::DeleteOuter");
        goto LABEL_16;
      }
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)m_pOuter + 84))(a1: m_pOuter, a2: 1);
    }
LABEL_16:
    v8 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
    CAsyncFileSystem::KickOffFileJobs(this: v3);
    return;
  }
  CAsyncRequestBase::UpdateAfterServicing(this: pRequest, results);
  pRequest->m_pOldAsyncStatus = results->m_ErrorCode;
  switch ( results->m_ErrorCode )
  {
    case FSASYNC_ERR_ALIGNMENT:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_ALIGNMENT;
      break;
    case FSASYNC_ERR_FAILURE:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_FAILURE;
      break;
    case FSASYNC_ERR_READING:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_READING;
      break;
    case FSASYNC_ERR_NOMEMORY:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_NOMEMORY;
      break;
    case FSASYNC_ERR_UNKNOWNID:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_UNKNOWNID;
      break;
    case FSASYNC_ERR_FILEOPEN:
      pRequest->m_RequestStatus = ASYNC_REQUEST_ERROR_FILEOPEN;
      break;
    case FSASYNC_OK:
      goto $LN4_5;
    default:
      _Error(a1: "Async result Status makes no sense");
$LN4_5:
      pRequest->m_RequestStatus = ASYNC_REQUEST_OK;
      break;
  }
  CAsyncRequestQueue::AddToTail(this: &v3->m_Completed, pItem: pRequest);
  v8 = p_m_AsyncStateUpdateMutex->m_depth-- == 1;
  if ( v8 )
    _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
  CThreadEvent::Set(this: &v3->m_CompletionSignal);
  CAsyncFileSystem::KickOffFileJobs(this: v3);
  m_pSyncThreadEvent = pRequest->m_pSyncThreadEvent;
  if ( m_pSyncThreadEvent != nullptr )
    CThreadEvent::Set(this: m_pSyncThreadEvent);
  else
    CAsyncFileSystem::NotifyMessageQueueOrCallback(this: v3, pRequest);
}

//------------------------------------------------------------------------------
// Address: 0x1001D080
// Name: private: static void CAsyncFileSystem::AsyncSearchCallbackAddItem(void __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAsyncFileSystem::AsyncSearchCallbackAddItem(int *pContext, char *pFoundPath, char *pFoundFile)
{
  int v3; // esi
  CDirectoryEntryInfo_t result; // [esp+4h] [ebp-104h] BYREF

  v3 = *pContext;
  V_ComposeFileName(path: pFoundPath, filename: pFoundFile, dest: result.m_FullFileName, destSize: 260);
  CUtlVector<CDirectoryEntryInfo_t,CUtlMemory<CDirectoryEntryInfo_t,int>>::InsertBefore(
    this: (CUtlVector<CDirectoryEntryInfo_t,CUtlMemory<CDirectoryEntryInfo_t,int> > *)(v3 + 68),
    elem: *(_DWORD *)(v3 + 80),
    src: &result);
}

//------------------------------------------------------------------------------
// Address: 0x1001D0D0
// Name: public: CAsyncFileSystem::CAsyncFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CAsyncFileSystem *__thiscall CAsyncFileSystem::CAsyncFileSystem(CAsyncFileSystem *this)
{
  this->__vftable = (CAsyncFileSystem_vtbl *)&CAsyncFileSystem::`vftable';
  this->m_Composing.m_Mutex.m_ownerID = 0;
  this->m_Composing.m_Mutex.m_depth = 0;
  this->m_Composing.m_nQueueSize = 0;
  this->m_Composing.m_pHead = nullptr;
  this->m_Composing.m_pTail = nullptr;
  this->m_Submitted.m_Mutex.m_ownerID = 0;
  this->m_Submitted.m_Mutex.m_depth = 0;
  this->m_Submitted.m_nQueueSize = 0;
  this->m_Submitted.m_pHead = nullptr;
  this->m_Submitted.m_pTail = nullptr;
  this->m_InFlight.m_Mutex.m_ownerID = 0;
  this->m_InFlight.m_Mutex.m_depth = 0;
  this->m_InFlight.m_nQueueSize = 0;
  this->m_InFlight.m_pHead = nullptr;
  this->m_InFlight.m_pTail = nullptr;
  this->m_Completed.m_Mutex.m_ownerID = 0;
  this->m_Completed.m_Mutex.m_depth = 0;
  this->m_Completed.m_nQueueSize = 0;
  this->m_Completed.m_pHead = nullptr;
  this->m_Completed.m_pTail = nullptr;
  this->m_nJobsInflight.m_value = 0;
  this->m_nSuspendCount.m_value = 0;
  this->m_AsyncStateUpdateMutex.m_ownerID = 0;
  this->m_AsyncStateUpdateMutex.m_depth = 0;
  CThreadEvent::CThreadEvent(this: &this->m_CompletionSignal, a2: false);
  _InterlockedExchange(&this->m_nJobsInflight.m_value, 0);
  _InterlockedExchange(&this->m_nSuspendCount.m_value, 0);
  this->m_bIOSuspended = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001D150
// Name: private: static void CAsyncFileSystem::AsyncIOCallbackGateway(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAsyncFileSystem::AsyncIOCallbackGateway(
        const FileAsyncRequest_t *request,
        int nBytesRead,
        FSAsyncStatus_t err)
{
  CAsyncResultInfo_t results; // [esp+0h] [ebp-Ch] BYREF

  results.m_nBytesTransferred = nBytesRead;
  results.m_pAllocatedBuffer = request->pData;
  results.m_ErrorCode = err;
  CAsyncFileSystem::AsyncIOCallBackHandler(
    this: (CAsyncFileSystem *)g_pAsyncFileSystem,
    pRequest: (CAsyncRequestBase *)request->pContext,
    &results);
}

//------------------------------------------------------------------------------
// Address: 0x1001D190
// Name: private: static void CAsyncFileSystem::AsyncSearchCallbackGateway(void __near *,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAsyncFileSystem::AsyncSearchCallbackGateway(CAsyncRequestBase *pContext, FSAsyncStatus_t err)
{
  CAsyncResultInfo_t results; // [esp+0h] [ebp-Ch] BYREF

  results.m_pAllocatedBuffer = nullptr;
  results.m_nBytesTransferred = 0;
  results.m_ErrorCode = err;
  CAsyncFileSystem::AsyncIOCallBackHandler(this: (CAsyncFileSystem *)g_pAsyncFileSystem, pRequest: pContext, &results);
}

//------------------------------------------------------------------------------
// Address: 0x1001D1C0
// Name: private: void CAsyncFileSystem::KickOffFileJobs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::KickOffFileJobs(CAsyncFileSystem *this)
{
  CAsyncFileSystem *v1; // ebx
  volatile int m_value; // eax
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // esi
  DWORD CurrentThreadId; // eax
  bool v5; // zf
  CAsyncRequestBase *v6; // edi
  AsyncFileOperation_t m_Operation; // eax
  __int64 *m_pOuter; // esi
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  char v13; // dl
  int v14; // eax
  int v15; // eax
  FSAsyncStatus_t v16; // eax
  IFileSystem_vtbl *v17; // ebx
  int v18; // eax
  volatile __int32 *v19; // eax
  FileAsyncRequest_t asJobReq; // [esp+4h] [ebp-3Ch] BYREF
  CThreadFastMutex *v21; // [esp+30h] [ebp-10h]
  CAsyncFileSystem *v22; // [esp+34h] [ebp-Ch]
  char *pSearchSpec; // [esp+38h] [ebp-8h]
  BOOL bRecurseFolders; // [esp+3Ch] [ebp-4h]

  v1 = this;
  m_value = this->m_nSuspendCount.m_value;
  v22 = this;
  if ( m_value > 0 )
    return;
  p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
  v21 = &this->m_AsyncStateUpdateMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_AsyncStateUpdateMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &v1->m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++v1->m_AsyncStateUpdateMutex.m_depth;
  }
  if ( v1->m_Submitted.m_nQueueSize < 1 )
  {
    v5 = v1->m_AsyncStateUpdateMutex.m_depth-- == 1;
    if ( v5 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
    return;
  }
  v6 = CAsyncRequestQueue::RemoveHead(this: &v1->m_Submitted);
  memset(dst: (unsigned __int8 *)&asJobReq, value: 0, count: sizeof(asJobReq));
  asJobReq.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
  m_Operation = v6->m_Operation;
  m_pOuter = nullptr;
  pSearchSpec = nullptr;
  LOBYTE(bRecurseFolders) = 0;
  if ( m_Operation == ASYNC_OP_READFILE || m_Operation == ASYNC_OP_WRITEFILE || m_Operation == ASYNC_OP_APPENDFILE )
  {
    m_pOuter = (__int64 *)v6->m_pOuter;
    v9 = 0;
    if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v6->m_pOuter + 76))(a1: v6->m_pOuter) != 0 )
    {
      v10 = (*(int (__thiscall **)(__int64 *))(*(_DWORD *)m_pOuter + 80))(a1: m_pOuter);
      v9 = v10;
      if ( m_pOuter[10] > 0 && m_pOuter[10] > v10 )
        _Error(a1: "Buffer not big enough to hold requested File IO");
    }
    if ( m_pOuter[10] > 0 && m_pOuter[10] < v9 )
      v9 = *((_DWORD *)m_pOuter + 20);
    asJobReq.pszFilename = (const char *)(*(int (__thiscall **)(__int64 *))(*(_DWORD *)m_pOuter + 68))(a1: m_pOuter);
    asJobReq.pData = (void *)(*(int (__thiscall **)(__int64 *))(*(_DWORD *)m_pOuter + 76))(a1: m_pOuter);
    v11 = *((_DWORD *)m_pOuter + 18);
    asJobReq.nBytes = v9;
    asJobReq.nOffset = v11;
    asJobReq.pfnCallback = CAsyncFileSystem::AsyncIOCallbackGateway;
    asJobReq.pContext = v6;
    asJobReq.priority = 0;
    v12 = (*(int (__thiscall **)(__int64 *))(*(_DWORD *)m_pOuter + 76))(a1: m_pOuter);
    asJobReq.pszPathID = nullptr;
    v1 = v22;
    asJobReq.flags = v12 == 0;
    asJobReq.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
    asJobReq.pfnAlloc = CAsyncFileSystem::OldAsyncAllocatorCallback;
  }
  if ( v6->m_Operation == ASYNC_OP_SCANDIR )
  {
    v13 = *((_BYTE *)v6->m_pOuter + 64);
    pSearchSpec = (char *)v6->m_pOuter + 868;
    LOBYTE(bRecurseFolders) = v13;
  }
  CAsyncRequestQueue::AddToTail(this: &v1->m_InFlight, pItem: v6);
  _InterlockedExchangeAdd(&v1->m_nJobsInflight.m_value, 1u);
  v14 = v6->m_Operation - 1;
  v6->m_RequestState = ASYNC_REQUEST_STATE_SERVICING;
  if ( v14 == 0 )
  {
    v16 = g_pFullFileSystem->AsyncReadMultiple(
            this: g_pFullFileSystem,
            a2: &asJobReq,
            a3: 1,
            a4: &v6->m_pOldAsyncControl);
LABEL_29:
    if ( v16 != FSASYNC_OK )
      _Error(a1: "Basefilesystem Async Job submission failed");
    goto LABEL_31;
  }
  v15 = v14 - 1;
  if ( v15 == 0 )
  {
    v17 = g_pFullFileSystem->IAppSystem::__vftable;
    v18 = (*(int (__thiscall **)(__int64 *, _DWORD, _DWORD, FSAsyncControl_t__ **))(*(_DWORD *)m_pOuter + 92))(
            a1: m_pOuter,
            a2: 0,
            a3: 0,
            a4: &v6->m_pOldAsyncControl);
    v16 = ((int (__thiscall *)(IFileSystem *, const char *, void *, int))v17->AsyncWrite)(
            a1: g_pFullFileSystem,
            a2: asJobReq.pszFilename,
            a3: asJobReq.pData,
            a4: v18);
    goto LABEL_29;
  }
  if ( v15 == 2 )
  {
    v16 = g_pFullFileSystem->AsyncDirectoryScan(
            this: g_pFullFileSystem,
            a2: pSearchSpec,
            a3: bRecurseFolders,
            a4: v6,
            a5: (void (__cdecl *)(void *, char *, char *))CAsyncFileSystem::AsyncSearchCallbackAddItem,
            a6: (void (__cdecl *)(void *, FSAsyncStatus_t))CAsyncFileSystem::AsyncSearchCallbackGateway,
            a7: &v6->m_pOldAsyncControl);
    goto LABEL_29;
  }
  _Error(a1: "Unable to determing async job type");
LABEL_31:
  v19 = (volatile __int32 *)v21;
  v5 = v21->m_depth-- == 1;
  if ( v5 )
    _InterlockedExchange(v19, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001D410
// Name: public: virtual void CAsyncFileSystem::ResumeAllAsyncIO(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncFileSystem::ResumeAllAsyncIO(CAsyncFileSystem *this)
{
  _InterlockedExchangeAdd(&this->m_nSuspendCount.m_value, 0xFFFFFFFF);
  if ( this->m_nSuspendCount.m_value <= 0 )
  {
    _InterlockedExchange(&this->m_nSuspendCount.m_value, 0);
    CAsyncFileSystem::KickOffFileJobs(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D440
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::SubmitAsyncFileRequest(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::SubmitAsyncFileRequest(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest)
{
  CAsyncRequestBase *v3; // esi
  int m_Operation; // eax
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // edi
  DWORD CurrentThreadId; // eax
  bool v7; // zf
  CThreadFastMutex *v9; // edi
  DWORD v10; // eax
  AsyncRequestStatus_t RStatus; // [esp+18h] [ebp+8h]

  v3 = pRequest->GetBase(this: pRequest);
  if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Composing, pItem: v3) == 0 )
  {
    if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Submitted, pItem: v3) != 0
      || CAsyncRequestQueue::IsInQueue(this: &this->m_InFlight, pItem: v3) != 0
      || CAsyncRequestQueue::IsInQueue(this: &this->m_Completed, pItem: v3) != 0 )
    {
      RStatus = ASYNC_REQUEST_ERROR_ALREADYSUBMITTED;
    }
    else
    {
      RStatus = ASYNC_REQUEST_ERROR_BADPTR;
    }
    goto LABEL_13;
  }
  m_Operation = v3->m_Operation;
  if ( m_Operation <= 0 || m_Operation >= 5 )
  {
    RStatus = ASYNC_REQUEST_ERROR_BADOPER;
    goto LABEL_13;
  }
  if ( v3->m_pResultQueue == nullptr && v3->m_pCallback == nullptr )
  {
    RStatus = ASYNC_REQUEST_ERROR_NONOTIFICATION;
    goto LABEL_13;
  }
  RStatus = CAsyncRequestBase::ValidateSubmittedRequest(this: v3, bPerformSync: false);
  if ( RStatus != ASYNC_REQUEST_OK )
  {
LABEL_13:
    p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_AsyncStateUpdateMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncStateUpdateMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_AsyncStateUpdateMutex.m_depth;
    }
    CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: v3);
    CAsyncRequestQueue::AddToTail(this: &this->m_Completed, pItem: v3);
    v3->m_RequestState = ASYNC_REQUEST_STATE_COMPLETED;
    v3->m_RequestStatus = RStatus;
    v7 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
    CAsyncFileSystem::NotifyMessageQueueOrCallback(this, pRequest: v3);
    return RStatus;
  }
  v9 = &this->m_AsyncStateUpdateMutex;
  v10 = GetCurrentThreadId();
  if ( v10 != this->m_AsyncStateUpdateMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)v9, v10, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_AsyncStateUpdateMutex, a2: v10, a3: 0);
  }
  else
  {
    ++this->m_AsyncStateUpdateMutex.m_depth;
  }
  CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: v3);
  v3->m_RequestState = ASYNC_REQUEST_STATE_SUBMITTED;
  CAsyncRequestQueue::PriorityInsert(this: &this->m_Submitted, pItem: v3);
  v7 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)v9, 0);
  CAsyncFileSystem::KickOffFileJobs(this);
  return ASYNC_REQUEST_OK;
}

//------------------------------------------------------------------------------
// Address: 0x1001D5C0
// Name: public: virtual enum AsyncRequestStatus_t CAsyncFileSystem::SubmitSyncFileRequest(class IAsyncRequestBase const __near *)
// Source: json
//------------------------------------------------------------------------------
AsyncRequestStatus_t __thiscall CAsyncFileSystem::SubmitSyncFileRequest(
        CAsyncFileSystem *this,
        const IAsyncRequestBase *pRequest)
{
  CAsyncRequestBase *v3; // esi
  int m_Operation; // eax
  CThreadFastMutex *p_m_AsyncStateUpdateMutex; // edi
  DWORD CurrentThreadId; // eax
  volatile unsigned int m_ownerID; // ecx
  AsyncRequestStatus_t result; // eax
  bool v9; // zf
  CThreadFastMutex *v10; // edi
  DWORD v11; // eax
  AsyncRequestStatus_t m_RequestStatus; // esi
  CThreadEvent syncEvent; // [esp+Ch] [ebp-Ch] BYREF
  DWORD v14; // [esp+14h] [ebp-4h]
  AsyncRequestStatus_t RStatus; // [esp+20h] [ebp+8h]

  v3 = pRequest->GetBase(this: pRequest);
  if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Composing, pItem: v3) == 0 )
  {
    if ( CAsyncRequestQueue::IsInQueue(this: &this->m_Submitted, pItem: v3) != 0
      || CAsyncRequestQueue::IsInQueue(this: &this->m_InFlight, pItem: v3) != 0
      || CAsyncRequestQueue::IsInQueue(this: &this->m_Completed, pItem: v3) != 0 )
    {
      RStatus = ASYNC_REQUEST_ERROR_ALREADYSUBMITTED;
    }
    else
    {
      RStatus = ASYNC_REQUEST_ERROR_BADPTR;
    }
LABEL_10:
    p_m_AsyncStateUpdateMutex = &this->m_AsyncStateUpdateMutex;
    CurrentThreadId = GetCurrentThreadId();
    m_ownerID = this->m_AsyncStateUpdateMutex.m_ownerID;
    v14 = CurrentThreadId;
    if ( CurrentThreadId != m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_AsyncStateUpdateMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_AsyncStateUpdateMutex, a2: v14, a3: 0);
    }
    else
    {
      ++this->m_AsyncStateUpdateMutex.m_depth;
    }
    CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: v3);
    CAsyncRequestQueue::AddToTail(this: &this->m_Completed, pItem: v3);
    result = RStatus;
    v3->m_RequestState = ASYNC_REQUEST_STATE_COMPLETED;
    v3->m_RequestStatus = RStatus;
    v9 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)p_m_AsyncStateUpdateMutex, 0);
    return result;
  }
  m_Operation = v3->m_Operation;
  if ( m_Operation <= 0 || m_Operation >= 5 )
  {
    RStatus = ASYNC_REQUEST_ERROR_BADOPER;
    goto LABEL_10;
  }
  RStatus = CAsyncRequestBase::ValidateSubmittedRequest(this: v3, bPerformSync: true);
  if ( RStatus != ASYNC_REQUEST_OK )
    goto LABEL_10;
  CThreadEvent::CThreadEvent(this: &syncEvent, a2: false);
  v10 = &this->m_AsyncStateUpdateMutex;
  v11 = GetCurrentThreadId();
  if ( v11 != this->m_AsyncStateUpdateMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)v10, v11, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_AsyncStateUpdateMutex, a2: v11, a3: 0);
  }
  else
  {
    ++this->m_AsyncStateUpdateMutex.m_depth;
  }
  CAsyncRequestQueue::Remove(this: &this->m_Composing, pItem: v3);
  v3->m_RequestState = ASYNC_REQUEST_STATE_SUBMITTED;
  v3->m_pSyncThreadEvent = &syncEvent;
  CAsyncRequestQueue::PriorityInsert(this: &this->m_Submitted, pItem: v3);
  v9 = this->m_AsyncStateUpdateMutex.m_depth-- == 1;
  if ( v9 )
    _InterlockedExchange((volatile __int32 *)v10, 0);
  CAsyncFileSystem::KickOffFileJobs(this);
  CThreadEvent::Wait(this: v3->m_pSyncThreadEvent, a2: 0xFFFFFFFF);
  m_RequestStatus = v3->m_RequestStatus;
  CThreadSyncObject::~CThreadSyncObject(this: &syncEvent);
  return m_RequestStatus;
}

//------------------------------------------------------------------------------
// Address: 0x10033830
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
// Address: 0x100B2B10
// Name: _dynamic_initializer_for__async_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_mode__()
{
  ConVar::ConVar(
    this: &async_mode,
    pName: "async_mode",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set the async filesystem mode (0 = async, 1 = synchronous)");
  return atexit(func: dynamic_atexit_destructor_for__async_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2B40
// Name: _dynamic_initializer_for__async_simulate_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_simulate_delay__()
{
  ConVar::ConVar(
    this: &async_simulate_delay,
    pName: "async_simulate_delay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Simulate a delay of up to a set msec per file operation");
  return atexit(func: dynamic_atexit_destructor_for__async_simulate_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2B70
// Name: _dynamic_initializer_for__async_allow_held_files__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_allow_held_files__()
{
  ConVar::ConVar(
    this: &async_allow_held_files,
    pName: "async_allow_held_files",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Allow AsyncBegin/EndRead()");
  return atexit(func: dynamic_atexit_destructor_for__async_allow_held_files__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2BA0
// Name: _dynamic_initializer_for__async_suspend_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_suspend_command__()
{
  ConCommand::ConCommand(
    this: &async_suspend_command,
    pName: "async_suspend",
    callback: async_suspend,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__async_suspend_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2BD0
// Name: _dynamic_initializer_for__async_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__async_resume_command__()
{
  ConCommand::ConCommand(
    this: &async_resume_command,
    pName: "async_resume",
    callback: async_resume,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__async_resume_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B20
// Name: _dynamic_atexit_destructor_for__async_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_mode__()
{
  ConVar::~ConVar(this: &async_mode);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B30
// Name: _dynamic_atexit_destructor_for__async_simulate_delay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_simulate_delay__()
{
  ConVar::~ConVar(this: &async_simulate_delay);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B40
// Name: _dynamic_atexit_destructor_for__async_allow_held_files__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_allow_held_files__()
{
  ConVar::~ConVar(this: &async_allow_held_files);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B50
// Name: _dynamic_atexit_destructor_for__async_suspend_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_suspend_command__()
{
  ConCommand::~ConCommand(this: &async_suspend_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B60
// Name: _dynamic_atexit_destructor_for__async_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__async_resume_command__()
{
  ConCommand::~ConCommand(this: &async_resume_command);
}

//------------------------------------------------------------------------------
// Address: 0x100B2C00
// Name: _dynamic_initializer_for__g_AsyncOpenedFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncOpenedFiles__()
{
  g_AsyncOpenedFiles.m_mutex.m_ownerID = 0;
  g_AsyncOpenedFiles.m_mutex.m_depth = 0;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_pMemory = nullptr;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_nAllocationCount = 0;
  g_AsyncOpenedFiles.m_map.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&g_AsyncOpenedFiles.m_map.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&g_AsyncOpenedFiles.m_map.m_Tree.m_FirstFree = -1;
  g_AsyncOpenedFiles.m_map.m_Tree.m_pElements = nullptr;
  g_AsyncOpenedFiles.m_map.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncOpenedFiles__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2C50
// Name: _dynamic_initializer_for__g_AsyncFinishMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncFinishMutex__()
{
  CThreadMutex::CThreadMutex(this: &g_AsyncFinishMutex);
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncFinishMutex__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2C70
// Name: _dynamic_initializer_for__g_FileSystem_Stdio__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileSystem_Stdio__()
{
  CBaseFileSystem::CBaseFileSystem(this: &g_FileSystem_Stdio);
  g_FileSystem_Stdio.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystem_Stdio_vtbl *)&CFileSystem_Stdio::`vftable'{for `IAppSystem'};
  g_FileSystem_Stdio.CBaseFileSystem::CTier2AppSystem<IFileSystem,0>::CTier1AppSystem<IFileSystem,0>::CTier0AppSystem<IFileSystem>::CBaseAppSystem<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CFileSystem_Stdio::`vftable'{for `IBaseFileSystem'};
  *(_WORD *)&g_FileSystem_Stdio.m_bMounted = 256;
  return atexit(func: dynamic_atexit_destructor_for__g_FileSystem_Stdio__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2CB0
// Name: _dynamic_initializer_for__g_FileSystem_Async__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FileSystem_Async__()
{
  CAsyncFileSystem::CAsyncFileSystem(this: &g_FileSystem_Async);
  return atexit(func: dynamic_atexit_destructor_for__g_FileSystem_Async__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2CD0
// Name: _dynamic_initializer_for____g_CreateCAsyncFileSystemIAsyncFileSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCAsyncFileSystemIAsyncFileSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCAsyncFileSystemIAsyncFileSystem_reg,
           fn: _CreateCAsyncFileSystemIAsyncFileSystem_interface,
           pName: "VNewAsyncFileSystem001");
}

//------------------------------------------------------------------------------
// Address: 0x100B3B70
// Name: _dynamic_atexit_destructor_for__g_AsyncFinishMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncFinishMutex__()
{
  CThreadMutex::~CThreadMutex(this: &g_AsyncFinishMutex);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B80
// Name: _dynamic_atexit_destructor_for__g_AsyncOpenedFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AsyncOpenedFiles__()
{
  CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,AsyncOpenedFile_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_AsyncOpenedFiles.m_map.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100B3B90
// Name: _dynamic_atexit_destructor_for__g_FileSystem_Async__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileSystem_Async__()
{
  CAsyncFileSystem::~CAsyncFileSystem(this: &g_FileSystem_Async);
}

} // namespace dedicated
