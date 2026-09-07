// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/workspacemanager.cpp
// Functions: 91
// ============================================================

#include "utils\scenemanager\workspacemanager.h"

//------------------------------------------------------------------------------
// Address: 0x00404580
// Name: public: void CUtlMemory<struct CSoundFile,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSoundFile,int>::Grow(CUtlMemory<CSoundFile,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSoundFile *m_pMemory; // edx
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
    v7 = 520 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSoundFile *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CSoundFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405530
// Name: public: CUtlVector<struct CFileLoaderThread::SentenceRequest __near *,class CUtlMemory<struct CFileLoaderThread::SentenceRequest __near *,int>>::~CUtlVector<struct CFileLoaderThread::SentenceRequest __near *,class CUtlMemory<struct CFileLoaderThread::SentenceRequest __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

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
// Address: 0x00408AD0
// Name: public: bool CUtlVector<class CVCDFile __near *,class CUtlMemory<class CVCDFile __near *,int>>::FindAndRemove(class CVCDFile __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CVCDFile *,CUtlMemory<CVCDFile *,int>>::FindAndRemove(
        CUtlVector<CScene *,CUtlMemory<CScene *,int> > *this,
        CScene **src)
{
  int m_Size; // edx
  int v4; // eax
  CScene **m_pMemory; // ebx
  CScene **i; // ecx
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
// Address: 0x0040BD40
// Name: public: void CUtlMemory<class CAudioMixerState,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CAudioMixerState,int>::Grow(CUtlMemory<CAudioMixerState,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CAudioMixerState *m_pMemory; // edx
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
      this->m_pMemory = (CAudioMixerState *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CAudioMixerState *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BDE0
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
// Address: 0x0040BFA0
// Name: public: int CUtlVector<struct variable_t,class CUtlMemory<struct variable_t,int>>::InsertBefore(int,struct variable_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
        CUtlVector<variable_t,CUtlMemory<variable_t,int> > *this,
        int elem,
        const variable_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  variable_t *m_pMemory; // ecx
  int v7; // eax
  variable_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAudioMixerState,int>::Grow(
      (CUtlMemory<CAudioMixerState,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x0040C010
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v6; // eax
  CUtlString *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040C540
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  fileList_t *m_pMemory; // ecx
  int v6; // eax
  fileList_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<fileList_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->fileName);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040C5B0
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  fileList_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  fileList_t *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<fileList_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *)this,
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
          CUtlString::CUtlString(this: &v12->fileName);
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
// Address: 0x0040C650
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
// Address: 0x0040C6C0
// Name: public: void CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  fileList_t *v3; // esi
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->fileName.m_Storage.m_nActualLength = 0;
      if ( v3->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->fileName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C990
// Name: public: CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::~CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  bool v2; // sf
  fileList_t *m_pMemory; // eax

  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this);
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
// Address: 0x0040D2D0
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414820
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CSoundEntry *,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CSoundEntry *,int> *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CSoundEntry *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004197F0
// Name: public: int CUtlVector<class CSoundEntry __near *,class CUtlMemory<class CSoundEntry __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int>>::InsertMultipleBefore(
        CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSoundEntry **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
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
// Address: 0x0041AC50
// Name: class CWorkspaceManager __near * GetWorkspaceManager(void)
// Source: json
//------------------------------------------------------------------------------
CWorkspaceManager *__cdecl GetWorkspaceManager()
{
  return g_pManager;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC60
// Name: public: virtual void CWorkspaceWorkArea::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceWorkArea::redraw(CWorkspaceWorkArea *this)
{
  CDrawHelper helper; // [esp+0h] [ebp-54h] BYREF

  CDrawHelper::CDrawHelper(this: &helper, widget: this, bgColor: 0xC8C8C8u);
  CDrawHelper::~CDrawHelper(this: &helper);
}

//------------------------------------------------------------------------------
// Address: 0x0041AC80
// Name: private: void CWorkspaceManager::CreateFileMenu(class mxMenu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::CreateFileMenu(CWorkspaceManager *this, mxMenu *m)
{
  mxMenu *v3; // eax
  mxMenu *v4; // eax

  mxPopupMenu::add(this: (mxPopupMenu *)m, item: "&New Workspace", id: 1001);
  mxMenu::addSeparator(this: (mxPopupMenu *)m);
  mxPopupMenu::add(this: (mxPopupMenu *)m, item: "Open &Workspace...", id: 1002);
  mxPopupMenu::add(this: (mxPopupMenu *)m, item: "Sa&ve Workspace", id: 1004);
  mxPopupMenu::add(this: (mxPopupMenu *)m, item: "Close Wor&kspace", id: 1003);
  mxMenu::addSeparator(this: (mxPopupMenu *)m);
  mxPopupMenu::add(this: (mxPopupMenu *)m, item: "&Create New Scene...", id: 1009);
  mxMenu::addSeparator(this: (mxPopupMenu *)m);
  mxPopupMenu::add(this: (mxPopupMenu *)m, item: "V&SS Properties...", id: 1006);
  mxMenu::addSeparator(this: (mxPopupMenu *)m);
  mxPopupMenu::add(this: (mxPopupMenu *)m, item: "Refresh\tF5", id: 1005);
  mxMenu::addSeparator(this: (mxPopupMenu *)m);
  v3 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxMenu::mxMenu(this: v3);
  else
    v4 = nullptr;
  this->m_pRecentFileMenu = v4;
  mxMenu::addMenu(this: (mxMenuBar *)m, item: "Recent Files", menu: v4);
  mxMenu::addSeparator(this: (mxPopupMenu *)m);
  mxPopupMenu::add(this: (mxPopupMenu *)m, item: "E&xit", id: 1000);
}

//------------------------------------------------------------------------------
// Address: 0x0041AD70
// Name: public: class CWorkspaceBrowser __near * CWorkspaceManager::GetBrowser(void)
// Source: json
//------------------------------------------------------------------------------
CWorkspaceBrowser *__thiscall CWorkspaceManager::GetBrowser(CWorkspaceManager *this)
{
  return this->m_pBrowser;
}

//------------------------------------------------------------------------------
// Address: 0x0041AD80
// Name: public: class CSoundBrowser __near * CWorkspaceManager::GetSoundBrowser(void)
// Source: json
//------------------------------------------------------------------------------
CSoundBrowser *__thiscall CWorkspaceManager::GetSoundBrowser(CWorkspaceManager *this)
{
  return this->m_pSoundBrowser;
}

//------------------------------------------------------------------------------
// Address: 0x0041AD90
// Name: public: class CWaveBrowser __near * CWorkspaceManager::GetWaveBrowser(void)
// Source: json
//------------------------------------------------------------------------------
CWaveBrowser *__thiscall CWorkspaceManager::GetWaveBrowser(CWorkspaceManager *this)
{
  return this->m_pWaveBrowser;
}

//------------------------------------------------------------------------------
// Address: 0x0041ADA0
// Name: private: void CWorkspaceManager::PerformLayout(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::PerformLayout(CWorkspaceManager *this, bool movebrowsers)
{
  int v3; // ebx
  CWorkspaceBrowser *m_pBrowser; // edi
  int v5; // eax
  CSoundBrowser *m_pSoundBrowser; // edi
  int v7; // eax
  CWaveBrowser *m_pWaveBrowser; // edi
  int v9; // eax
  int v10; // [esp-Ch] [ebp-18h]
  int v11; // [esp-Ch] [ebp-18h]
  int v12; // [esp-8h] [ebp-14h]
  int v13; // [esp-8h] [ebp-14h]
  int v14; // [esp-8h] [ebp-14h]
  int y; // [esp+8h] [ebp-4h]

  v3 = mxWidget::w2(this);
  y = mxWidget::h2(this) - 100;
  mxWidget::setBounds(this: this->m_pWorkArea, x: 0, y: 0, w: v3, h: y);
  if ( movebrowsers )
  {
    m_pBrowser = this->m_pBrowser;
    v12 = mxWidget::h2(this: this->m_pWorkArea) / 3;
    v5 = mxWidget::w2(this: this->m_pWorkArea);
    mxWidget::setBounds(this: m_pBrowser, x: 0, y: 0, w: v5, h: v12);
    m_pSoundBrowser = this->m_pSoundBrowser;
    if ( m_pSoundBrowser != nullptr )
    {
      v13 = mxWidget::h2(this: this->m_pWorkArea) / 3;
      v10 = mxWidget::w2(this: this->m_pWorkArea);
      v7 = mxWidget::h2(this: this->m_pWorkArea);
      mxWidget::setBounds(this: m_pSoundBrowser, x: 0, y: v7 / 3, w: v10, h: v13);
    }
    m_pWaveBrowser = this->m_pWaveBrowser;
    if ( m_pWaveBrowser != nullptr )
    {
      v14 = mxWidget::h2(this: this->m_pWorkArea) / 3;
      v11 = mxWidget::w2(this: this->m_pWorkArea);
      v9 = mxWidget::h2(this: this->m_pWorkArea);
      mxWidget::setBounds(this: m_pWaveBrowser, x: 0, y: 2 * v9 / 3, w: v11, h: v14);
    }
  }
  mxWidget::setBounds(this: g_pStatusWindow, x: 0, y, w: v3, h: 100);
}

//------------------------------------------------------------------------------
// Address: 0x0041AEC0
// Name: public: void CWorkspaceManager::OnDoubleClicked(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnDoubleClicked(CWorkspaceManager *this, ITreeItem *item)
{
  CSoundEntry *v2; // eax

  v2 = item->GetSoundEntry(this: item);
  if ( v2 != nullptr )
    CSoundEntry::Play(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0041AEE0
// Name: private: void CWorkspaceManager::OnSoundPlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnSoundPlay(CWorkspaceManager *this)
{
  int Flags; // esi
  bool v2; // zf
  int v3; // eax
  CSoundEntry *v4; // eax
  CWaveFile *v5; // eax

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)Flags + 20))(a1: Flags) == 0;
  v3 = *(_DWORD *)Flags;
  if ( v2 )
  {
    if ( (*(int (__thiscall **)(int))(v3 + 24))(a1: Flags) != 0 )
    {
      v5 = (CWaveFile *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 24))(a1: Flags);
      CWaveFile::Play(this: v5);
    }
  }
  else
  {
    v4 = (CSoundEntry *)(*(int (__thiscall **)(int))(v3 + 20))(a1: Flags);
    CSoundEntry::Play(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AF30
// Name: private: void CWorkspaceManager::OnSoundToggleVoiceDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnSoundToggleVoiceDuck(CWorkspaceManager *this)
{
  int Flags; // esi
  CWaveFile *v2; // eax

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)Flags + 24))(a1: Flags) != 0 )
  {
    v2 = (CWaveFile *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 24))(a1: Flags);
    CWaveFile::ToggleVoiceDucking(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AF60
// Name: private: void CWorkspaceManager::ShowContextMenu_Workspace(int,int,class CWorkspace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::ShowContextMenu_Workspace(CWorkspaceManager *this, int x, int y, CWorkspace *ws)
{
  mxPopupMenu *v5; // eax
  mxPopupMenu *v6; // esi
  bool v7; // zf
  const char *(__thiscall *GetName)(ITreeItem *); // eax
  const char *v9; // eax
  int v10; // [esp-Ch] [ebp-14h]
  int v11; // [esp-Ch] [ebp-14h]
  int v12; // [esp-8h] [ebp-10h]

  if ( ws != nullptr )
  {
    v5 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v5 != nullptr )
      v6 = mxPopupMenu::mxPopupMenu(this: v5);
    else
      v6 = nullptr;
    mxPopupMenu::add(this: v6, item: "Create New Project...", id: 1010);
    mxPopupMenu::add(this: v6, item: "Insert Project...", id: 1011);
    mxMenu::addSeparator(this: v6);
    mxPopupMenu::add(this: v6, item: "VSS Properties...", id: 1006);
    v7 = !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: ws->m_szFile, a3: nullptr);
    GetName = ws->GetName;
    if ( v7 )
    {
      v12 = 1025;
      v10 = (int)GetName(this: ws);
      v9 = va(fmt: "Checkout '%s'", v10);
    }
    else
    {
      v12 = 1026;
      v11 = (int)GetName(this: ws);
      v9 = va(fmt: "Checkin '%s'", v11);
    }
    mxPopupMenu::add(this: v6, item: v9, id: v12);
    mxPopupMenu::popup(this: v6, widget: this, x, y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B030
// Name: private: void CWorkspaceManager::ShowContextMenu_Project(int,int,class CProject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::ShowContextMenu_Project(CWorkspaceManager *this, int x, int y, CProject *project)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  IBaseFileSystem_vtbl *v10; // ebx
  const char *FileName; // eax
  bool v12; // zf
  const char *(__thiscall *GetName)(ITreeItem *); // edx
  const char *v14; // eax
  int v15; // [esp-8h] [ebp-14h]
  int v16; // [esp-8h] [ebp-14h]
  int v17; // [esp-4h] [ebp-10h]

  v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxPopupMenu::mxPopupMenu(this: v4);
  else
    v5 = nullptr;
  mxPopupMenu::add(this: v5, item: "Create New Scene...", id: 1014);
  mxMenu::addSeparator(this: v5);
  mxPopupMenu::add(this: v5, item: "Remove Project...", id: 1012);
  mxMenu::addSeparator(this: v5);
  mxPopupMenu::add(this: v5, item: "Edit comments...", id: 1013);
  if ( !project->IsFirstChild(this: project) || !project->IsLastChild(this: project) )
  {
    mxMenu::addSeparator(this: v5);
    if ( !project->IsFirstChild(this: project) )
    {
      v6 = (const char *)project->GetName(this: project);
      v7 = va(fmt: "Move '%s' Up", v6);
      mxPopupMenu::add(this: v5, item: v7, id: 1027);
    }
    if ( !project->IsLastChild(this: project) )
    {
      v8 = (const char *)project->GetName(this: project);
      v9 = va(fmt: "Move '%s' Down", v8);
      mxPopupMenu::add(this: v5, item: v9, id: 1028);
    }
  }
  mxMenu::addSeparator(this: v5);
  v10 = filesystem->IBaseFileSystem::__vftable;
  FileName = CProject::GetFileName(this: project);
  v12 = !v10->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: FileName, a3: nullptr);
  GetName = project->GetName;
  if ( v12 )
  {
    v17 = 1025;
    v15 = (int)GetName(this: project);
    v14 = va(fmt: "Checkout '%s'", v15);
  }
  else
  {
    v17 = 1026;
    v16 = (int)GetName(this: project);
    v14 = va(fmt: "Checkin '%s'", v16);
  }
  mxPopupMenu::add(this: v5, item: v14, id: v17);
  mxPopupMenu::popup(this: v5, widget: this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x0041B1A0
// Name: private: void CWorkspaceManager::ShowContextMenu_Scene(int,int,class CScene __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::ShowContextMenu_Scene(CWorkspaceManager *this, int x, int y, CScene *scene)
{
  mxPopupMenu *v5; // eax
  mxPopupMenu *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax

  v5 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxPopupMenu::mxPopupMenu(this: v5);
  else
    v6 = nullptr;
  v7 = (const char *)scene->GetName(this: scene);
  v8 = va(fmt: "Add VCD to '%s'...", v7);
  mxPopupMenu::add(this: v6, item: v8, id: 1021);
  mxMenu::addSeparator(this: v6);
  mxPopupMenu::add(this: v6, item: "Remove Scene", id: 1015);
  mxMenu::addSeparator(this: v6);
  v9 = va(fmt: "Edit comments...");
  mxPopupMenu::add(this: v6, item: v9, id: 1023);
  if ( !scene->IsFirstChild(this: scene) || !scene->IsLastChild(this: scene) )
  {
    mxMenu::addSeparator(this: v6);
    if ( !scene->IsFirstChild(this: scene) )
    {
      v10 = (const char *)scene->GetName(this: scene);
      v11 = va(fmt: "Move '%s' Up", v10);
      mxPopupMenu::add(this: v6, item: v11, id: 1027);
    }
    if ( !scene->IsLastChild(this: scene) )
    {
      v12 = (const char *)scene->GetName(this: scene);
      v13 = va(fmt: "Move '%s' Down", v12);
      mxPopupMenu::add(this: v6, item: v13, id: 1028);
    }
  }
  mxPopupMenu::popup(this: v6, widget: this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x0041B2C0
// Name: private: void CWorkspaceManager::ShowContextMenu_VCD(int,int,class CVCDFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::ShowContextMenu_VCD(CWorkspaceManager *this, int x, int y, CVCDFile *vcd)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  IBaseFileSystem_vtbl *v12; // ebx
  int v13; // eax
  bool v14; // zf
  const char *(__thiscall *GetName)(ITreeItem *); // edx
  const char *v16; // eax
  int v17; // [esp-8h] [ebp-14h]
  int v18; // [esp-8h] [ebp-14h]
  int v19; // [esp-4h] [ebp-10h]

  v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxPopupMenu::mxPopupMenu(this: v4);
  else
    v5 = nullptr;
  v6 = va(fmt: "Remove VCD");
  mxPopupMenu::add(this: v5, item: v6, id: 1022);
  mxMenu::addSeparator(this: v5);
  v7 = va(fmt: "Edit comments...");
  mxPopupMenu::add(this: v5, item: v7, id: 1024);
  if ( !vcd->IsFirstChild(this: vcd) || !vcd->IsLastChild(this: vcd) )
  {
    mxMenu::addSeparator(this: v5);
    if ( !vcd->IsFirstChild(this: vcd) )
    {
      v8 = (const char *)vcd->GetName(this: vcd);
      v9 = va(fmt: "Move '%s' Up", v8);
      mxPopupMenu::add(this: v5, item: v9, id: 1027);
    }
    if ( !vcd->IsLastChild(this: vcd) )
    {
      v10 = (const char *)vcd->GetName(this: vcd);
      v11 = va(fmt: "Move '%s' Down", v10);
      mxPopupMenu::add(this: v5, item: v11, id: 1028);
    }
  }
  mxMenu::addSeparator(this: v5);
  v12 = filesystem->IBaseFileSystem::__vftable;
  v13 = ((int (__thiscall *)(CVCDFile *, _DWORD))vcd->GetName)(a1: vcd, a2: 0);
  v14 = ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, int))v12->IsFileWritable)(
          a1: &filesystem->IBaseFileSystem,
          a2: v13) == 0;
  GetName = vcd->GetName;
  if ( v14 )
  {
    v19 = 1025;
    v17 = (int)GetName(this: vcd);
    v16 = va(fmt: "Checkout '%s'", v17);
  }
  else
  {
    v19 = 1026;
    v18 = (int)GetName(this: vcd);
    v16 = va(fmt: "Checkin '%s'", v18);
  }
  mxPopupMenu::add(this: v5, item: v16, id: v19);
  mxPopupMenu::popup(this: v5, widget: this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x0041B420
// Name: private: void CWorkspaceManager::ShowContextMenu_SoundEntry(int,int,class CSoundEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::ShowContextMenu_SoundEntry(
        CWorkspaceManager *this,
        int x,
        int y,
        CSoundEntry *entry)
{
  mxPopupMenu *v5; // eax
  mxPopupMenu *v6; // esi

  v5 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxPopupMenu::mxPopupMenu(this: v5);
  else
    v6 = nullptr;
  mxPopupMenu::add(this: v6, item: "&Play", id: 1016);
  mxMenu::addSeparator(this: v6);
  mxPopupMenu::add(this: v6, item: "Properties...", id: 1020);
  mxPopupMenu::popup(this: v6, widget: this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x0041B490
// Name: private: void CWorkspaceManager::ShowContextMenu_WaveFile(int,int,class CWaveFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::ShowContextMenu_WaveFile(CWorkspaceManager *this, int x, int y, CWaveFile *entry)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // esi
  IBaseFileSystem_vtbl *v6; // ebx
  const char *FileName; // eax
  bool v8; // zf
  const char *(__thiscall *GetName)(struct CWaveFile *); // edx
  const char *v10; // eax
  int v11; // [esp-8h] [ebp-14h]
  int v12; // [esp-8h] [ebp-14h]
  int v13; // [esp-4h] [ebp-10h]

  v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxPopupMenu::mxPopupMenu(this: v4);
  else
    v5 = nullptr;
  mxPopupMenu::add(this: v5, item: "&Play", id: 1016);
  if ( CWaveFile::GetVoiceDuck(this: entry) )
    mxPopupMenu::add(this: v5, item: "Disable &voice duck", id: 1017);
  else
    mxPopupMenu::add(this: v5, item: "Enable &voice duck", id: 1017);
  mxPopupMenu::add(this: v5, item: "&Edit sentence text...", id: 1018);
  mxMenu::addSeparator(this: v5);
  v6 = filesystem->IBaseFileSystem::__vftable;
  FileName = CWaveFile::GetFileName(this: entry);
  v8 = !v6->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: FileName, a3: nullptr);
  GetName = entry->GetName;
  if ( v8 )
  {
    v13 = 1025;
    v11 = (int)GetName(this: entry);
    v10 = va(fmt: "Checkout '%s'", v11);
  }
  else
  {
    v13 = 1026;
    v12 = (int)GetName(this: entry);
    v10 = va(fmt: "Checkin '%s'", v12);
  }
  mxPopupMenu::add(this: v5, item: v10, id: v13);
  mxMenu::addSeparator(this: v5);
  mxPopupMenu::add(this: v5, item: "Properties...", id: 1029);
  mxPopupMenu::popup(this: v5, widget: this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x0041B590
// Name: private: void CWorkspaceManager::OnChangeVSSProperites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnChangeVSSProperites(CWorkspaceManager *this)
{
  CWorkspace *Count; // esi
  const char *VSSUserName; // eax
  const char *VSSProject; // eax
  const char *v4; // eax
  const char *v5; // [esp-4h] [ebp-294h]
  CVSSParams params; // [esp+4h] [ebp-28Ch] BYREF

  Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  if ( Count != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "VSS Properites");
    VSSUserName = CWorkspace::GetVSSUserName(this: Count);
    _V_strcpy(dest: params.m_szUserName, src: VSSUserName);
    VSSProject = CWorkspace::GetVSSProject(this: Count);
    _V_strcpy(dest: params.m_szProject, src: VSSProject);
    if ( VSSProperties(&params) != 0 )
    {
      if ( params.m_szUserName[0] != 0 )
      {
        if ( params.m_szProject[0] != 0 )
        {
          CWorkspace::SetVSSUserName(this: Count, username: params.m_szUserName);
          CWorkspace::SetVSSProject(this: Count, projectname: params.m_szProject);
          Count->SetDirty(this: Count, a2: true);
          v5 = CWorkspace::GetVSSProject(this: Count);
          v4 = CWorkspace::GetVSSUserName(this: Count);
          Con_Printf(fmt: "VSS user = '%s', project = '%s'\n", v4, v5);
        }
        else
        {
          Con_Printf(fmt: "You must enter a project name\n");
        }
      }
      else
      {
        Con_Printf(fmt: "You must enter a user name\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B6A0
// Name: private: void CWorkspaceManager::OnCheckoutWorkspace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnCheckoutWorkspace(CWorkspaceManager *this)
{
  unsigned int Count; // eax

  Count = CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  if ( Count != 0 )
    (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)Count + 32))(a1: Count, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041B6C0
// Name: private: void CWorkspaceManager::OnCheckinWorkspace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnCheckinWorkspace(CWorkspaceManager *this)
{
  unsigned int Count; // eax

  Count = CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  if ( Count != 0 )
    (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)Count + 36))(a1: Count, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041B6E0
// Name: public: struct _IMAGELIST __near * CWorkspaceManager::CreateImageList(void)
// Source: json
//------------------------------------------------------------------------------
_IMAGELIST *__thiscall CWorkspaceManager::CreateImageList(CWorkspaceManager *this)
{
  _IMAGELIST *v1; // esi
  HMODULE ModuleHandleA; // eax
  HMODULE v3; // eax
  HMODULE v4; // eax
  HMODULE v5; // eax
  HMODULE v6; // eax
  HMODULE v7; // eax
  HMODULE v8; // eax
  HMODULE v9; // eax
  HMODULE v10; // eax
  HMODULE v11; // eax
  HMODULE v12; // eax
  HICON IconA; // edi
  HICON__ *hicon; // [esp+Ch] [ebp-4h]
  HICON__ *hicona; // [esp+Ch] [ebp-4h]
  HICON__ *hiconb; // [esp+Ch] [ebp-4h]
  HICON__ *hiconc; // [esp+Ch] [ebp-4h]
  HICON__ *hicond; // [esp+Ch] [ebp-4h]
  HICON__ *hicone; // [esp+Ch] [ebp-4h]
  HICON__ *hiconf; // [esp+Ch] [ebp-4h]
  HICON__ *hicong; // [esp+Ch] [ebp-4h]
  HICON__ *hiconh; // [esp+Ch] [ebp-4h]
  HICON__ *hiconi; // [esp+Ch] [ebp-4h]

  v1 = ImageList_Create(cx: 16, cy: 16, flags: 0, cInitial: 11, cGrow: 0);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  hicon = LoadIconA(hInstance: ModuleHandleA, lpIconName: (LPCSTR)0x68);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon);
  DeleteObject(ho: hicon);
  v3 = GetModuleHandleA(lpModuleName: nullptr);
  hicona = LoadIconA(hInstance: v3, lpIconName: (LPCSTR)0x72);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hicona);
  DeleteObject(ho: hicona);
  v4 = GetModuleHandleA(lpModuleName: nullptr);
  hiconb = LoadIconA(hInstance: v4, lpIconName: (LPCSTR)0x69);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hiconb);
  DeleteObject(ho: hiconb);
  v5 = GetModuleHandleA(lpModuleName: nullptr);
  hiconc = LoadIconA(hInstance: v5, lpIconName: (LPCSTR)0x74);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hiconc);
  DeleteObject(ho: hiconc);
  v6 = GetModuleHandleA(lpModuleName: nullptr);
  hicond = LoadIconA(hInstance: v6, lpIconName: (LPCSTR)0x6A);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hicond);
  DeleteObject(ho: hicond);
  v7 = GetModuleHandleA(lpModuleName: nullptr);
  hicone = LoadIconA(hInstance: v7, lpIconName: (LPCSTR)0x6B);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hicone);
  DeleteObject(ho: hicone);
  v8 = GetModuleHandleA(lpModuleName: nullptr);
  hiconf = LoadIconA(hInstance: v8, lpIconName: (LPCSTR)0x73);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hiconf);
  DeleteObject(ho: hiconf);
  v9 = GetModuleHandleA(lpModuleName: nullptr);
  hicong = LoadIconA(hInstance: v9, lpIconName: (LPCSTR)0x6C);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hicong);
  DeleteObject(ho: hicong);
  v10 = GetModuleHandleA(lpModuleName: nullptr);
  hiconh = LoadIconA(hInstance: v10, lpIconName: (LPCSTR)0x71);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hiconh);
  DeleteObject(ho: hiconh);
  v11 = GetModuleHandleA(lpModuleName: nullptr);
  hiconi = LoadIconA(hInstance: v11, lpIconName: (LPCSTR)0x6D);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: hiconi);
  DeleteObject(ho: hiconi);
  v12 = GetModuleHandleA(lpModuleName: nullptr);
  IconA = LoadIconA(hInstance: v12, lpIconName: (LPCSTR)0x70);
  ImageList_ReplaceIcon(himl: v1, i: -1, hicon: IconA);
  DeleteObject(ho: IconA);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0041B870
// Name: public: void CWorkspaceManager::RefreshBrowsers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::RefreshBrowsers(CWorkspaceManager *this)
{
  CWorkspaceBrowser *m_pBrowser; // ecx
  CSoundBrowser *m_pSoundBrowser; // ecx
  CWaveBrowser *m_pWaveBrowser; // ecx

  m_pBrowser = this->m_pBrowser;
  if ( m_pBrowser != nullptr )
    CWorkspaceBrowser::PopulateTree(this: m_pBrowser);
  m_pSoundBrowser = this->m_pSoundBrowser;
  if ( m_pSoundBrowser != nullptr )
    CSoundBrowser::RepopulateTree(this: m_pSoundBrowser);
  m_pWaveBrowser = this->m_pWaveBrowser;
  if ( m_pWaveBrowser != nullptr )
    CWaveBrowser::RepopulateTree(this: m_pWaveBrowser);
}

//------------------------------------------------------------------------------
// Address: 0x0041B8A0
// Name: public: void CWorkspaceManager::OnSoundShowInBrowsers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnSoundShowInBrowsers(CWorkspaceManager *this)
{
  int Flags; // esi
  CSoundEntry *v3; // eax
  CWaveFile *v4; // eax
  CWaveFile *v5; // esi
  CSoundBrowser *m_pSoundBrowser; // edi
  CSoundEntry *OwnerSoundEntry; // eax

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CSoundEntry *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 20))(a1: Flags);
    if ( v3 != nullptr )
    {
      CSoundBrowser::JumpToItem(this: this->m_pSoundBrowser, se: v3);
    }
    else
    {
      v4 = (CWaveFile *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 24))(a1: Flags);
      v5 = v4;
      if ( v4 != nullptr )
      {
        CWaveBrowser::JumpToItem(this: this->m_pWaveBrowser, wav: v4);
        if ( CWaveFile::GetOwnerSoundEntry(this: v5) != nullptr )
        {
          m_pSoundBrowser = this->m_pSoundBrowser;
          OwnerSoundEntry = CWaveFile::GetOwnerSoundEntry(this: v5);
          CSoundBrowser::JumpToItem(this: m_pSoundBrowser, se: OwnerSoundEntry);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B910
// Name: public: void CWorkspaceManager::UpdateMenus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::UpdateMenus(CWorkspaceManager *this)
{
  unsigned int Count; // ebx
  int Flags; // edi
  bool v4; // bl
  int (__thiscall ***v5)(_DWORD); // eax
  const char *v6; // eax
  const char *v7; // [esp-4h] [ebp-18h]
  bool hasworkspace; // [esp+Ch] [ebp-8h]

  Count = CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  hasworkspace = Count != 0;
  v4 = Flags != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)Flags + 8))(a1: Flags) != 0;
  mxMenuBar::setEnabled(this: this->m_pMenuBar, id: 1004, b: true);
  mxMenuBar::setEnabled(this: this->m_pMenuBar, id: 1003, b: hasworkspace);
  if ( v4 )
  {
    v5 = (int (__thiscall ***)(_DWORD))(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 8))(a1: Flags);
    v6 = (const char *)(**v5)(a1: v5);
    v7 = va(fmt: "&Create Scene in '%s'", v6);
    mxMenuBar::modify(this: this->m_pMenuBar, id: 1009, newId: 1009, newItem: v7);
  }
  else
  {
    mxMenuBar::modify(this: this->m_pMenuBar, id: 1009, newId: 1009, newItem: "&Create New Scene...");
  }
  mxMenuBar::setEnabled(this: this->m_pMenuBar, id: 1009, b: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0041B9D0
// Name: private: void CWorkspaceManager::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::Think(CWorkspaceManager *this, float dt)
{
  int v3; // edi
  CWorkspaceBrowser *m_pBrowser; // ecx
  CSoundBrowser *m_pSoundBrowser; // ecx
  CWaveBrowser *m_pWaveBrowser; // ecx

  ((void (__stdcall *)(_DWORD))sound->Update)(a1: LODWORD(dt));
  v3 = fileloader->ProcessCompleted(this: fileloader);
  if ( v3 > 0 )
  {
    m_pBrowser = this->m_pBrowser;
    if ( m_pBrowser != nullptr )
      CWorkspaceBrowser::PopulateTree(this: m_pBrowser);
    m_pSoundBrowser = this->m_pSoundBrowser;
    if ( m_pSoundBrowser != nullptr )
      CSoundBrowser::RepopulateTree(this: m_pSoundBrowser);
    m_pWaveBrowser = this->m_pWaveBrowser;
    if ( m_pWaveBrowser != nullptr )
      CWaveBrowser::RepopulateTree(this: m_pWaveBrowser);
    Con_Printf(fmt: "Thread loaded %i sounds\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BA40
// Name: private: void CWorkspaceManager::Frame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::Frame(CWorkspaceManager *this)
{
  double v2; // xmm2_8
  double v3; // xmm0_8
  float v4; // xmm0_4
  double dt; // [esp+10h] [ebp-8h]

  v2 = (double)(int)mx::getTickCount() * 0.001;
  v3 = v2 - prev;
  dt = v2 - prev;
  if ( !recursion_guard )
  {
    recursion_guard = true;
    if ( v3 < 0.0 || v3 >= 0.004 )
    {
      if ( prev != 0.0 )
      {
        if ( v3 > 0.1 )
        {
          v3 = 0.1;
          dt = 0.1;
        }
        v4 = v3;
        CWorkspaceManager::Think(this, dt: v4);
        realtime = realtime + dt;
      }
      prev = v2;
      recursion_guard = false;
    }
    else
    {
      Sleep(dwMilliseconds: (int)((0.004 - v3) * 1000.0) < 0 ? 0 : (int)((0.004 - v3) * 1000.0));
      recursion_guard = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BB30
// Name: private: void CWorkspaceManager::OnUpdateTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnUpdateTitle(CWorkspaceManager *this)
{
  CWorkspace *Count; // eax
  CWorkspace *v3; // esi
  const char *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  char szTitle[256]; // [esp+8h] [ebp-100h] BYREF

  Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  v3 = Count;
  if ( Count != nullptr )
  {
    v4 = g_appTitleFmt;
    if ( CWorkspace::IsDirty(this: Count) )
      v4 = g_appTitleFmtModified;
    v5 = CSentence::NameForLanguage(language: this->m_nLanguageId);
    v6 = ((int (__thiscall *)(CWorkspace *, const char *))v3->GetName)(a1: v3, a2: v5);
    V_snprintf(pDest: szTitle, maxLen: 256, pFormat: v4, v6);
  }
  else
  {
    V_snprintf(pDest: szTitle, maxLen: 256, pFormat: g_appTitle);
  }
  mxWidget::setLabel(this, format: szTitle);
  CWorkspaceManager::UpdateMenus(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041BBD0
// Name: private: void CWorkspaceManager::OnSaveWorkspace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnSaveWorkspace(CWorkspaceManager *this)
{
  CWorkspace *Count; // eax

  Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  if ( Count != nullptr )
  {
    CWorkspace::SaveChanges(this: Count);
    CWorkspaceManager::OnUpdateTitle(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BBF0
// Name: private: void CWorkspaceManager::OnRemoveProject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnRemoveProject(CWorkspaceManager *this)
{
  int Flags; // eax
  CProject *v3; // esi
  CWorkspace *Count; // eax
  const char *v5; // eax
  const char *v6; // eax

  Con_Printf(fmt: "OnRemoveProject()\n");
  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CProject *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 8))(a1: Flags);
    if ( v3 != nullptr )
    {
      Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
      if ( Count != nullptr )
      {
        CWorkspace::RemoveProject(this: Count, project: v3);
        v6 = (const char *)v3->GetName(this: v3);
        Con_Printf(fmt: "Removed project '%s'\n", v6);
        CProject::~CProject(this: v3);
        free(pMem: v3);
        CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
        CWorkspaceManager::OnUpdateTitle(this);
      }
      else
      {
        v5 = (const char *)v3->GetName(this: v3);
        Con_Printf(fmt: "Can't remove project '%s', no current workspace?!\n", v5);
      }
    }
    else
    {
      Con_Printf(fmt: "Can't remove project, item is not a project\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BC90
// Name: private: void CWorkspaceManager::OnRemoveScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnRemoveScene(CWorkspaceManager *this)
{
  int Flags; // eax
  CScene *v3; // eax
  CScene *v4; // esi
  CProject *OwnerProject; // eax
  const char *v6; // eax
  const char *v7; // eax

  Con_Printf(fmt: "OnRemoveScene()\n");
  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CScene *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 12))(a1: Flags);
    v4 = v3;
    if ( v3 != nullptr )
    {
      OwnerProject = CScene::GetOwnerProject(this: v3);
      if ( OwnerProject != nullptr )
      {
        CProject::RemoveScene(this: OwnerProject, scene: v4);
        v7 = (const char *)v4->GetName(this: v4);
        Con_Printf(fmt: "Removed scene '%s'\n", v7);
        CScene::~CScene(this: v4);
        free(pMem: v4);
        CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
        CWorkspaceManager::OnUpdateTitle(this);
      }
      else
      {
        v6 = (const char *)v4->GetName(this: v4);
        Con_Printf(fmt: "Can't remove scene '%s', no current owner project?!\n", v6);
      }
    }
    else
    {
      Con_Printf(fmt: "Can't remove scene, item is not a scene\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BD30
// Name: private: void CWorkspaceManager::OnNewScene(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnNewScene(CWorkspaceManager *this)
{
  int Flags; // eax
  CProject *v3; // esi
  const char *v4; // eax
  CScene *v5; // eax
  CScene *v6; // edi
  int v7; // eax
  const char *v8; // eax
  const char *v9; // [esp-Ch] [ebp-59Ch]
  CInputParams params; // [esp+4h] [ebp-58Ch] BYREF

  Con_Printf(fmt: "OnNewScene()\n");
  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CProject *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 8))(a1: Flags);
    if ( v3 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      v4 = (const char *)v3->GetName(this: v3);
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Create scene in '%s'", v4);
      _V_strcpy(dest: params.m_szPrompt, src: "Scene Name:");
      _V_strcpy(dest: params.m_szInputText, src: &WindowName);
      if ( InputProperties(&params) != 0 )
      {
        if ( params.m_szInputText[0] != 0 )
        {
          v5 = (CScene *)operator new(nSize: 0xA8u);
          if ( v5 != nullptr )
            v6 = CScene::CScene(this: v5, proj: v3, name: params.m_szInputText);
          else
            v6 = nullptr;
          CProject::AddScene(this: v3, scene: v6);
          v7 = v3->GetName(this: v3);
          v8 = (const char *)((int (__thiscall *)(CScene *, int))v6->GetName)(a1: v6, a2: v7);
          Con_Printf(fmt: "Added scene '%s' to project '%s'\n", v8, v9);
          CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
          CWorkspaceManager::OnUpdateTitle(this);
        }
        else
        {
          Con_Printf(fmt: "You must name the scene!\n");
        }
      }
    }
    else
    {
      Con_Printf(fmt: "Can't add new scene, selected item is not a project\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BE70
// Name: private: void CWorkspaceManager::OnModifyProjectComments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnModifyProjectComments(CWorkspaceManager *this)
{
  int Flags; // eax
  CProject *v3; // esi
  const char *v4; // eax
  const char *Comments; // eax
  const char *v6; // eax
  CInputParams params; // [esp+4h] [ebp-58Ch] BYREF

  Con_Printf(fmt: "OnModifyProjectComments()\n");
  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CProject *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 8))(a1: Flags);
    if ( v3 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      v4 = (const char *)v3->GetName(this: v3);
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Edit comments for '%s'", v4);
      _V_strcpy(dest: params.m_szPrompt, src: "Comments:");
      Comments = CProject::GetComments(this: v3);
      V_strncpy(pDest: params.m_szInputText, pSrc: Comments, maxLen: 1024);
      if ( InputProperties(&params) != 0 )
      {
        v6 = CProject::GetComments(this: v3);
        if ( _V_strcmp(s1: params.m_szInputText, s2: v6) != 0 )
        {
          CProject::SetComments(this: v3, comments: params.m_szInputText);
          CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
          CWorkspaceManager::OnUpdateTitle(this);
        }
      }
    }
    else
    {
      Con_Printf(fmt: "Can't modify comments, item is not a project\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BF70
// Name: private: void CWorkspaceManager::OnChangeLanguage(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnChangeLanguage(CWorkspaceManager *this, int lang_index, bool force)
{
  bool v4; // zf
  int i; // edi
  char v6; // bl
  const char *v7; // edi
  int v8; // edi
  CWorkspaceBrowser *m_pBrowser; // ecx
  CSoundBrowser *m_pSoundBrowser; // ecx
  CWaveBrowser *m_pWaveBrowser; // ecx
  char fn[260]; // [esp+4h] [ebp-104h] BYREF

  v4 = this->m_nLanguageId == lang_index;
  this->m_nLanguageId = lang_index;
  if ( !v4 || force != !v4 )
  {
    for ( i = 0; i < 12; ++i )
      mxMenu::setChecked(this: this->m_pMenuCloseCaptionLanguages, id: i + 1600, b: i == this->m_nLanguageId);
    v6 = 0;
    v7 = CSentence::NameForLanguage(language: lang_index);
    if ( _V_stricmp(s1: v7, s2: "unknown_language") != 0 )
    {
      V_snprintf(pDest: fn, maxLen: 260, pFormat: "resource/closecaption_%s.txt", v7);
      v8 = filesystem->GetFileTime(this: &filesystem->IBaseFileSystem, a2: fn, a3: nullptr);
      if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: fn, a3: nullptr) )
      {
        if ( this->m_lEnglishCaptionsFileChangeTime != v8 )
        {
          this->m_lEnglishCaptionsFileChangeTime = v8;
          v6 = 1;
          g_pVGuiLocalize->RemoveAll(this: g_pVGuiLocalize);
          g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: fn, a3: nullptr, a4: false);
        }
      }
      else
      {
        Con_Printf(fmt: "CWorkspaceManager::OnChangeLanguage  Warning, can't find localization file %s\n", fn);
      }
    }
    if ( !force || v6 != 0 )
    {
      m_pBrowser = this->m_pBrowser;
      if ( m_pBrowser != nullptr )
        CWorkspaceBrowser::PopulateTree(this: m_pBrowser);
      m_pSoundBrowser = this->m_pSoundBrowser;
      if ( m_pSoundBrowser != nullptr )
        CSoundBrowser::RepopulateTree(this: m_pSoundBrowser);
      m_pWaveBrowser = this->m_pWaveBrowser;
      if ( m_pWaveBrowser != nullptr )
        CWaveBrowser::RepopulateTree(this: m_pWaveBrowser);
      CWorkspaceManager::OnUpdateTitle(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C0C0
// Name: private: void CWorkspaceManager::OnSoundEditText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnSoundEditText(CWorkspaceManager *this)
{
  int Flags; // eax
  CWaveFile *v3; // esi
  const char *v4; // eax
  const char *SentenceText; // eax
  const char *v6; // eax
  CInputParams params; // [esp+4h] [ebp-58Ch] BYREF

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CWaveFile *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 24))(a1: Flags);
    if ( v3 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      v4 = (const char *)v3->GetName(this: v3);
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Edit text of '%s'", v4);
      _V_strcpy(dest: params.m_szPrompt, src: "Sentence text:");
      SentenceText = CWaveFile::GetSentenceText(this: v3);
      _V_strcpy(dest: params.m_szInputText, src: SentenceText);
      if ( InputProperties(&params) != 0 )
      {
        v6 = CWaveFile::GetSentenceText(this: v3);
        if ( _V_stricmp(s1: params.m_szInputText, s2: v6) != 0 )
        {
          CWaveFile::SetSentenceText(this: v3, newText: params.m_szInputText);
          CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
          CWorkspaceManager::OnUpdateTitle(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C1A0
// Name: private: void CWorkspaceManager::OnSceneAddVCD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnSceneAddVCD(CWorkspaceManager *this)
{
  int Flags; // eax
  CScene *v3; // esi
  const char *OpenFileName; // eax
  const char *v5; // eax
  CVCDFile *v6; // eax
  CVCDFile *v7; // eax
  char vcd_name[512]; // [esp+4h] [ebp-200h] BYREF

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CScene *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 12))(a1: Flags);
    if ( v3 != nullptr )
    {
      OpenFileName = mxGetOpenFileName(parent: nullptr, path: ".", filter: "*.vcd");
      if ( OpenFileName != nullptr && *OpenFileName != 0 )
      {
        filesystem->FullPathToRelativePath(this: filesystem, a2: OpenFileName, a3: vcd_name, a4: 512);
        V_StripExtension(in: vcd_name, out: vcd_name, outSize: 512);
        V_DefaultExtension(path: vcd_name, extension: ".vcd", pathStringLength: 512);
        if ( CScene::FindVCD(this: v3, filename: vcd_name) != nullptr )
        {
          v5 = (const char *)v3->GetName(this: v3);
          Con_Printf(fmt: "File '%s' is already in scene '%s'\n", vcd_name, v5);
        }
        else
        {
          v6 = (CVCDFile *)operator new(nSize: 0xB0u);
          if ( v6 != nullptr )
            v7 = CVCDFile::CVCDFile(this: v6, scene: v3, filename: vcd_name);
          else
            v7 = nullptr;
          CScene::AddVCD(this: v3, vcd: v7);
          CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
          CWorkspaceManager::OnUpdateTitle(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C2B0
// Name: private: void CWorkspaceManager::OnModifySceneComments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnModifySceneComments(CWorkspaceManager *this)
{
  int Flags; // eax
  CScene *v3; // esi
  const char *v4; // eax
  const char *Comments; // eax
  const char *v6; // eax
  CInputParams params; // [esp+4h] [ebp-58Ch] BYREF

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CScene *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 12))(a1: Flags);
    if ( v3 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      v4 = (const char *)v3->GetName(this: v3);
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Edit comments for '%s'", v4);
      _V_strcpy(dest: params.m_szPrompt, src: "Comments:");
      Comments = CScene::GetComments(this: v3);
      V_strncpy(pDest: params.m_szInputText, pSrc: Comments, maxLen: 1024);
      if ( InputProperties(&params) != 0 )
      {
        v6 = CScene::GetComments(this: v3);
        if ( _V_strcmp(s1: params.m_szInputText, s2: v6) != 0 )
        {
          CScene::SetComments(this: v3, comments: params.m_szInputText);
          CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
          CWorkspaceManager::OnUpdateTitle(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C3A0
// Name: private: void CWorkspaceManager::OnModifyVCDComments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnModifyVCDComments(CWorkspaceManager *this)
{
  int Flags; // eax
  CVCDFile *v3; // esi
  const char *v4; // eax
  const char *Comments; // eax
  const char *v6; // eax
  CInputParams params; // [esp+4h] [ebp-58Ch] BYREF

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CVCDFile *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 16))(a1: Flags);
    if ( v3 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      v4 = (const char *)v3->GetName(this: v3);
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Edit comments for '%s'", v4);
      _V_strcpy(dest: params.m_szPrompt, src: "Comments:");
      Comments = CVCDFile::GetComments(this: v3);
      V_strncpy(pDest: params.m_szInputText, pSrc: Comments, maxLen: 1024);
      if ( InputProperties(&params) != 0 )
      {
        v6 = CVCDFile::GetComments(this: v3);
        if ( _V_strcmp(s1: params.m_szInputText, s2: v6) != 0 )
        {
          CVCDFile::SetComments(this: v3, comments: params.m_szInputText);
          CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
          CWorkspaceManager::OnUpdateTitle(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C490
// Name: private: void CWorkspaceManager::OnSceneRemoveVCD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnSceneRemoveVCD(CWorkspaceManager *this)
{
  int Flags; // eax
  CVCDFile *v3; // eax
  CVCDFile *v4; // esi
  CScene *OwnerScene; // eax

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v3 = (CVCDFile *)(*(int (__thiscall **)(int))(*(_DWORD *)Flags + 16))(a1: Flags);
    v4 = v3;
    if ( v3 != nullptr )
    {
      OwnerScene = CVCDFile::GetOwnerScene(this: v3);
      if ( OwnerScene != nullptr )
      {
        CScene::RemoveVCD(this: OwnerScene, vcd: v4);
        CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
        CWorkspaceManager::OnUpdateTitle(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C4E0
// Name: public: void CWorkspaceManager::ShowContextMenu(int,int,class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::ShowContextMenu(CWorkspaceManager *this, int x, int y, ITreeItem *p)
{
  CWorkspace *v5; // eax
  CProject *v6; // eax
  CScene *v7; // eax
  CVCDFile *v8; // eax
  CSoundEntry *v9; // eax
  CWaveFile *v10; // eax

  v5 = p->GetWorkspace(this: p);
  if ( v5 != nullptr )
  {
    CWorkspaceManager::ShowContextMenu_Workspace(this, x, y, ws: v5);
  }
  else
  {
    v6 = p->GetProject(this: p);
    if ( v6 != nullptr )
    {
      CWorkspaceManager::ShowContextMenu_Project(this, x, y, project: v6);
    }
    else
    {
      v7 = p->GetScene(this: p);
      if ( v7 != nullptr )
      {
        CWorkspaceManager::ShowContextMenu_Scene(this, x, y, scene: v7);
      }
      else
      {
        v8 = p->GetVCDFile(this: p);
        if ( v8 != nullptr )
        {
          CWorkspaceManager::ShowContextMenu_VCD(this, x, y, vcd: v8);
        }
        else
        {
          v9 = p->GetSoundEntry(this: p);
          if ( v9 != nullptr )
          {
            CWorkspaceManager::ShowContextMenu_SoundEntry(this, x, y, entry: v9);
          }
          else
          {
            v10 = p->GetWaveFile(this: p);
            if ( v10 != nullptr )
              CWorkspaceManager::ShowContextMenu_WaveFile(this, x, y, entry: v10);
            else
              Con_Printf(fmt: "unknown tree item type\n");
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C5D0
// Name: private: void CWorkspaceManager::OnCheckout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnCheckout(CWorkspaceManager *this)
{
  int Flags; // eax

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)Flags + 32))(a1: Flags, a2: 1);
    CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
    CWorkspaceManager::OnUpdateTitle(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C600
// Name: private: void CWorkspaceManager::OnCheckin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnCheckin(CWorkspaceManager *this)
{
  int Flags; // eax

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)Flags + 36))(a1: Flags, a2: 1);
    CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
    CWorkspaceManager::OnUpdateTitle(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C630
// Name: private: void CWorkspaceManager::OnMoveUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnMoveUp(CWorkspaceManager *this)
{
  ITreeItem *Flags; // eax
  ITreeItem *v3; // edi
  ITreeItem *ParentItem; // esi

  Flags = (ITreeItem *)ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  v3 = Flags;
  if ( Flags != nullptr )
  {
    ParentItem = ITreeItem::GetParentItem(this: Flags);
    if ( ParentItem != nullptr )
    {
      ParentItem->MoveChildUp(this: ParentItem, a2: v3);
      ParentItem->SetDirty(this: ParentItem, a2: true);
      CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
      CWorkspaceManager::OnUpdateTitle(this);
      CWorkspaceBrowser::JumpTo(this: this->m_pBrowser, item: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C690
// Name: private: void CWorkspaceManager::OnMoveDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnMoveDown(CWorkspaceManager *this)
{
  ITreeItem *Flags; // eax
  ITreeItem *v3; // edi
  ITreeItem *ParentItem; // esi

  Flags = (ITreeItem *)ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  v3 = Flags;
  if ( Flags != nullptr )
  {
    ParentItem = ITreeItem::GetParentItem(this: Flags);
    if ( ParentItem != nullptr )
    {
      ParentItem->MoveChildDown(this: ParentItem, a2: v3);
      ParentItem->SetDirty(this: ParentItem, a2: true);
      CWorkspaceBrowser::PopulateTree(this: this->m_pBrowser);
      CWorkspaceManager::OnUpdateTitle(this);
      CWorkspaceBrowser::JumpTo(this: this->m_pBrowser, item: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C6F0
// Name: public: void CWorkspaceManager::SetWorkspaceDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::SetWorkspaceDirty(CWorkspaceManager *this)
{
  unsigned int Count; // eax

  Count = CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  if ( Count != 0 )
    (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)Count + 64))(a1: Count, a2: 1);
  CWorkspaceManager::OnUpdateTitle(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041C720
// Name: public: void CUtlMemory<struct CWorkspaceManager::RecentFile,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CWorkspaceManager::RecentFile,int>::Grow(
        CUtlMemory<CWorkspaceManager::RecentFile,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CWorkspaceManager::RecentFile *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 8;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CWorkspaceManager::RecentFile *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v7);
    else
      this->m_pMemory = (CWorkspaceManager::RecentFile *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C7B0
// Name: private: void CWorkspaceManager::UpdateRecentFilesMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::UpdateRecentFilesMenu(CWorkspaceManager *this)
{
  int m_Size; // eax
  int m_nRecentMenuItems; // eax
  mxMenu *m_pRecentFileMenu; // ecx
  int v5; // edi
  int v6; // ebx
  int c; // [esp+4h] [ebp-4h]
  int ca; // [esp+4h] [ebp-4h]

  m_Size = this->m_RecentFiles.m_Size;
  for ( c = m_Size; c > this->m_nRecentMenuItems; m_Size = c )
  {
    m_nRecentMenuItems = this->m_nRecentMenuItems;
    m_pRecentFileMenu = this->m_pRecentFileMenu;
    this->m_nRecentMenuItems = m_nRecentMenuItems + 1;
    mxPopupMenu::add(this: (mxPopupMenu *)m_pRecentFileMenu, item: "(empty)", id: m_nRecentMenuItems + 1500);
  }
  if ( m_Size > 0 )
  {
    v5 = 1500;
    v6 = 0;
    for ( ca = m_Size; ca != 0; --ca )
    {
      mxMenuBar::modify(
        this: this->m_pMenuBar,
        id: v5,
        newId: v5,
        newItem: this->m_RecentFiles.m_Memory.m_pMemory[v6++].filename);
      ++v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C820
// Name: private: void CWorkspaceManager::OnCloseWorkspace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnCloseWorkspace(CWorkspaceManager *this)
{
  CWorkspace *Count; // eax
  CWorkspace *v3; // esi

  Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  v3 = Count;
  if ( Count != nullptr )
  {
    if ( !CWorkspace::CanClose(this: Count) )
      return;
    CWorkspace::~CWorkspace(this: v3);
    free(pMem: v3);
    CWorkspaceBrowser::SetWorkspace(this: this->m_pBrowser, w: nullptr);
    CWorkspaceManager::OnUpdateTitle(this);
  }
  Con_Printf(fmt: "Closed workspace\n");
}

//------------------------------------------------------------------------------
// Address: 0x0041C870
// Name: public: virtual bool CWorkspaceManager::Closing(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkspaceManager::Closing(CWorkspaceManager *this)
{
  CWorkspaceManager *v1; // ebx
  int v2; // edi
  const char *v3; // esi
  bool v4; // bl
  const char *v5; // eax
  int v6; // eax
  const char *v7; // eax
  const char *v9; // eax
  int v10; // eax
  CWorkspace *Count; // eax
  CWorkspace *v12; // esi
  int c; // [esp+10h] [ebp-4h]

  v1 = this;
  Con_Printf(fmt: "Checking for sound script changes...\n");
  MultipleRequestChangeContext();
  v2 = 0;
  c = g_pSoundEmitterSystem->GetNumSoundScripts(this: g_pSoundEmitterSystem);
  if ( c > 0 )
  {
    while ( 1 )
    {
      if ( !g_pSoundEmitterSystem->IsSoundScriptDirty(this: g_pSoundEmitterSystem, a2: v2) )
        goto LABEL_20;
      v3 = g_pSoundEmitterSystem->GetSoundScriptName(this: g_pSoundEmitterSystem, a2: v2);
      if ( v3 == nullptr )
        goto LABEL_20;
      v4 = true;
      if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v3, a3: nullptr) )
      {
LABEL_19:
        g_pSoundEmitterSystem->SaveChangesToSoundScript(this: g_pSoundEmitterSystem, a2: v2);
        goto LABEL_20;
      }
      if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v3, a3: nullptr) )
      {
        v5 = va(fmt: "Check out '%s'?", v3);
        v6 = MultipleRequest(prompt: v5);
        if ( v6 == 2 )
          return 0;
        if ( v6 != 0 )
        {
          v4 = v6 != 1;
        }
        else
        {
          VSS_Checkout(name: v3, updatestaticons: true);
          if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v3, a3: nullptr) )
            goto LABEL_9;
        }
      }
      if ( filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v3, a3: nullptr) )
      {
        v9 = va(fmt: "Save changes to out '%s'?", v3);
        v10 = mxMessageBox(parent: nullptr, msg: v9, title: g_appTitle, style: 2);
        if ( v10 == 2 )
          return 0;
        if ( v10 != 0 )
        {
          if ( v10 == 1 )
            goto LABEL_20;
        }
        else if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v3, a3: nullptr) )
        {
LABEL_9:
          v7 = va(fmt: "Aborting shutdown, %s, not writable!!", v3);
          mxMessageBox(parent: nullptr, msg: v7, title: g_appTitle, style: 0);
          return 0;
        }
      }
      if ( v4 )
        goto LABEL_19;
LABEL_20:
      if ( ++v2 >= c )
      {
        v1 = this;
        break;
      }
    }
  }
  Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)v1->m_pBrowser);
  v12 = Count;
  if ( Count != nullptr )
  {
    if ( !CWorkspace::CanClose(this: Count) )
      return 0;
    CWorkspace::~CWorkspace(this: v12);
    free(pMem: v12);
    CWorkspaceBrowser::SetWorkspace(this: v1->m_pBrowser, w: nullptr);
    CWorkspaceManager::OnUpdateTitle(this: v1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041CA60
// Name: private: void CWorkspaceManager::SaveRecentFilesMenuToDisk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::SaveRecentFilesMenuToDisk(CWorkspaceManager *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // edi
  int v5; // esi
  void *v6; // eax
  void *v7; // esi
  CUtlBuffer buf; // [esp+8h] [ebp-34h] BYREF
  int c; // [esp+38h] [ebp-4h]

  c = this->m_RecentFiles.m_Size;
  v2 = c;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CUtlBuffer::Printf(this: &buf, pFmt: "recentfiles\n{\n");
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = 0;
    do
    {
      v5 = v3 + 1;
      CUtlBuffer::Printf(
        this: &buf,
        pFmt: "\t\"%i\"\t\"%s\"\n",
        v3 + 1,
        this->m_RecentFiles.m_Memory.m_pMemory[v4].filename);
      v3 = v5;
      ++v4;
    }
    while ( v5 < c );
  }
  CUtlBuffer::Printf(this: &buf, pFmt: "}\n");
  v6 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: "scenemanager.rf", a3: "wt", a4: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v6);
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v7);
  }
  else
  {
    Con_Printf(fmt: "CWorkspace::SaveRecentFilesMenuToDisk:  Unable to write file %s!!!\n", "scenemanager.rf");
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041CBA0
// Name: private: virtual void CWorkspaceManager::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CWorkspaceManager::OnDelete(CWorkspaceManager *this)
{
  CWorkspaceManager::SaveRecentFilesMenuToDisk(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041CBB0
// Name: private: void CWorkspaceManager::AddFileToRecentWorkspaceList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::AddFileToRecentWorkspaceList(CWorkspaceManager *this, const char *filename)
{
  int m_Size; // edi
  int v3; // esi
  CUtlVector<CWorkspaceManager::RecentFile,CUtlMemory<CWorkspaceManager::RecentFile,int> > *p_m_RecentFiles; // ebx
  CWorkspaceManager *v5; // esi
  int v6; // eax
  int m_nAllocationCount; // ecx
  CWorkspaceManager::RecentFile *v8; // ecx
  int v9; // eax
  CWorkspaceManager::RecentFile *v10; // edi
  int j; // eax
  int v12; // ecx
  int v13; // eax
  CWorkspaceManager::RecentFile *m_pMemory; // edx
  CWorkspaceManager::RecentFile rf; // [esp+Ch] [ebp-108h] BYREF
  CWorkspaceManager *v16; // [esp+10Ch] [ebp-8h]
  int i; // [esp+110h] [ebp-4h]

  m_Size = this->m_RecentFiles.m_Size;
  v3 = 0;
  v16 = this;
  i = 0;
  if ( m_Size > 0 )
  {
    p_m_RecentFiles = &this->m_RecentFiles;
    while ( _V_stricmp(s1: p_m_RecentFiles->m_Memory.m_pMemory[v3].filename, s2: filename) != 0 )
    {
      ++v3;
      if ( ++i >= m_Size )
        goto LABEL_5;
    }
    if ( i < m_Size )
    {
      m_pMemory = p_m_RecentFiles->m_Memory.m_pMemory;
      rf = *p_m_RecentFiles->m_Memory.m_pMemory;
      qmemcpy(m_pMemory, &m_pMemory[i], sizeof(CWorkspaceManager::RecentFile));
      v10 = &p_m_RecentFiles->m_Memory.m_pMemory[i];
LABEL_10:
      *v10 = rf;
      v5 = v16;
      goto LABEL_11;
    }
  }
LABEL_5:
  _V_strcpy(dest: rf.filename, src: filename);
  v5 = v16;
  v6 = v16->m_RecentFiles.m_Size;
  m_nAllocationCount = v16->m_RecentFiles.m_Memory.m_nAllocationCount;
  p_m_RecentFiles = &v16->m_RecentFiles;
  if ( v6 + 1 > m_nAllocationCount )
    CUtlMemory<CWorkspaceManager::RecentFile,int>::Grow(
      this: &v16->m_RecentFiles.m_Memory,
      num: v6 - m_nAllocationCount + 1);
  ++p_m_RecentFiles->m_Size;
  v8 = p_m_RecentFiles->m_Memory.m_pMemory;
  v9 = p_m_RecentFiles->m_Size - 1;
  p_m_RecentFiles->m_pElements = p_m_RecentFiles->m_Memory.m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[1], src: v8, count: v9 << 8);
  v10 = p_m_RecentFiles->m_Memory.m_pMemory;
  if ( p_m_RecentFiles->m_Memory.m_pMemory != nullptr )
    goto LABEL_10;
LABEL_11:
  for ( j = v5->m_RecentFiles.m_Size; j > 10; j = v5->m_RecentFiles.m_Size )
  {
    v12 = j - 1;
    v13 = p_m_RecentFiles->m_Size - j;
    if ( v13 > 0 )
      _V_memmove(
        dest: &p_m_RecentFiles->m_Memory.m_pMemory[v12],
        src: &p_m_RecentFiles->m_Memory.m_pMemory[v12 + 1],
        count: v13 << 8);
    --p_m_RecentFiles->m_Size;
  }
  CWorkspaceManager::UpdateRecentFilesMenu(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0041CCF0
// Name: private: void CWorkspaceManager::LoadRecentFilesMenuFromDisk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::LoadRecentFilesMenuFromDisk(CWorkspaceManager *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // edi
  const char *String; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CWorkspaceManager::RecentFile *m_pMemory; // ecx
  int v10; // eax
  CWorkspaceManager::RecentFile *v11; // eax
  CWorkspaceManager::RecentFile rf; // [esp+8h] [ebp-10Ch] BYREF
  KeyValues *sub; // [esp+10Ch] [ebp-8h]
  KeyValues *kv; // [esp+110h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "recentfiles");
    kv = v3;
  }
  else
  {
    kv = nullptr;
    v3 = nullptr;
  }
  if ( filesystem != nullptr )
    v4 = &filesystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: "scenemanager.rf",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
    sub = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &WindowName);
        V_strncpy(pDest: rf.filename, pSrc: String, maxLen: 256);
        m_Size = this->m_RecentFiles.m_Size;
        m_nAllocationCount = this->m_RecentFiles.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CWorkspaceManager::RecentFile,int>::Grow(
            this: &this->m_RecentFiles.m_Memory,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_RecentFiles.m_Size;
        m_pMemory = this->m_RecentFiles.m_Memory.m_pMemory;
        v10 = this->m_RecentFiles.m_Size - m_Size - 1;
        this->m_RecentFiles.m_pElements = m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v10 << 8);
        v11 = &this->m_RecentFiles.m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
        {
          *v11 = rf;
          FirstSubKey = sub;
        }
        sub = KeyValues::GetNextKey(this: FirstSubKey);
        if ( sub == nullptr )
          break;
        FirstSubKey = sub;
      }
      v3 = kv;
    }
  }
  KeyValues::deleteThis(this: v3);
  CWorkspaceManager::UpdateRecentFilesMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041CE30
// Name: public: void CWorkspaceManager::LoadWorkspace(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::LoadWorkspace(CWorkspaceManager *this, const char *filename)
{
  CWorkspace *Count; // eax
  CWorkspace *v4; // edi
  CWorkspace *v5; // eax
  CWorkspace *v6; // eax

  Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
  v4 = Count;
  if ( Count != nullptr )
  {
    if ( !CWorkspace::CanClose(this: Count) )
      return;
    CWorkspace::~CWorkspace(this: v4);
    free(pMem: v4);
    CWorkspaceBrowser::SetWorkspace(this: this->m_pBrowser, w: nullptr);
    CWorkspaceManager::OnUpdateTitle(this);
  }
  Con_Printf(fmt: "Loading workspace %s\n", filename);
  v5 = (CWorkspace *)operator new(nSize: 0x2A4u);
  if ( v5 != nullptr )
    v6 = CWorkspace::CWorkspace(this: v5, filename);
  else
    v6 = nullptr;
  CWorkspaceBrowser::SetWorkspace(this: this->m_pBrowser, w: v6);
  CWorkspaceManager::OnUpdateTitle(this);
  CWorkspaceManager::AddFileToRecentWorkspaceList(this, filename);
  CWorkspaceManager::OnUpdateTitle(this);
  CWorkspaceManager::UpdateMenus(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041CED0
// Name: private: void CWorkspaceManager::OnOpenWorkspace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnOpenWorkspace(CWorkspaceManager *this)
{
  const char *OpenFileName; // eax
  char workspace_name[512]; // [esp+4h] [ebp-200h] BYREF

  OpenFileName = mxGetOpenFileName(parent: nullptr, path: ".", filter: "*.vsw");
  if ( OpenFileName != nullptr && *OpenFileName != 0 )
  {
    filesystem->FullPathToRelativePath(this: filesystem, a2: OpenFileName, a3: workspace_name, a4: 512);
    CWorkspaceManager::LoadWorkspace(this, filename: workspace_name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CF30
// Name: private: void CWorkspaceManager::OnNewProject(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWorkspaceManager::OnNewProject(CWorkspaceManager *this@<ecx>, const char *a2@<esi>)
{
  const char *SaveFileName; // eax
  CWorkspace *Count; // esi
  const char *v5; // eax
  CProject *v6; // eax
  CProject *v7; // eax
  char workspace_name[512]; // [esp+4h] [ebp-400h] BYREF
  char project_name[512]; // [esp+204h] [ebp-200h] BYREF

  Con_Printf(fmt: "OnNewProject()\n");
  SaveFileName = mxGetSaveFileName(parent: nullptr, path: ".", filter: "*.vsp");
  if ( SaveFileName != nullptr && *SaveFileName != 0 )
  {
    filesystem->FullPathToRelativePath(this: filesystem, a2: SaveFileName, a3: project_name, a4: 512);
    V_StripExtension(in: project_name, out: project_name, outSize: 512);
    V_DefaultExtension(path: project_name, extension: ".vsp", pathStringLength: 512);
    if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: project_name, a3: nullptr) )
    {
      Con_Printf(fmt: "%s exists already!\n", project_name);
      return;
    }
    Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
    if ( Count == nullptr )
    {
      V_StripExtension(in: project_name, out: workspace_name, outSize: 512);
      V_DefaultExtension(path: workspace_name, extension: ".vsw", pathStringLength: 512);
      if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: workspace_name, a3: nullptr) )
      {
        Con_Printf(fmt: "Found workspace '%s', automatically loading...\n", workspace_name);
      }
      else
      {
        v5 = va(fmt: "Automatically create workspace %s?", workspace_name);
        if ( mxMessageBox(parent: nullptr, msg: v5, title: g_appTitle, style: 2) != 0 )
        {
          Con_Printf(fmt: "Canceling project creation\n");
          return;
        }
      }
      CWorkspaceManager::LoadWorkspace(this, filename: workspace_name);
      Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
      if ( Count == nullptr )
        goto LABEL_13;
    }
    if ( CWorkspace::FindProjectFile(this: Count, filename: project_name) != nullptr )
    {
      Con_Printf(fmt: "Project %s already exists in workspace\n", a2);
    }
    else
    {
LABEL_13:
      v6 = (CProject *)operator new(nSize: 0x1ACu);
      if ( v6 != nullptr )
        v7 = CProject::CProject(this: v6, ws: Count, filename: project_name);
      else
        v7 = nullptr;
      if ( Count != nullptr )
        CWorkspaceBrowser::AddProject(this: this->m_pBrowser, project: v7);
      CWorkspaceManager::OnUpdateTitle(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D110
// Name: private: void CWorkspaceManager::OnInsertProject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnInsertProject(CWorkspaceManager *this)
{
  const char *OpenFileName; // eax
  CWorkspace *Count; // esi
  const char *v4; // eax
  CProject *v5; // eax
  CProject *v6; // eax
  char workspace_name[512]; // [esp+4h] [ebp-400h] BYREF
  char project_name[512]; // [esp+204h] [ebp-200h] BYREF

  Con_Printf(fmt: "OnInsertProject()\n");
  OpenFileName = mxGetOpenFileName(parent: nullptr, path: ".", filter: "*.vsp");
  if ( OpenFileName != nullptr && *OpenFileName != 0 )
  {
    filesystem->FullPathToRelativePath(this: filesystem, a2: OpenFileName, a3: project_name, a4: 512);
    V_StripExtension(in: project_name, out: project_name, outSize: 512);
    V_DefaultExtension(path: project_name, extension: ".vsp", pathStringLength: 512);
    Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
    if ( Count == nullptr )
    {
      V_StripExtension(in: project_name, out: workspace_name, outSize: 512);
      V_DefaultExtension(path: workspace_name, extension: ".vsw", pathStringLength: 512);
      if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: workspace_name, a3: nullptr) )
      {
        Con_Printf(fmt: "Found workspace '%s', automatically loading...\n", workspace_name);
      }
      else
      {
        v4 = va(fmt: "Automatically create workspace %s?", workspace_name);
        if ( mxMessageBox(parent: nullptr, msg: v4, title: g_appTitle, style: 2) != 0 )
        {
          Con_Printf(fmt: "Canceling project creation\n");
          return;
        }
      }
      CWorkspaceManager::LoadWorkspace(this, filename: workspace_name);
      Count = (CWorkspace *)CCurveData::GetCount(this: (IterateRIFF *)this->m_pBrowser);
      if ( Count == nullptr )
        goto LABEL_11;
    }
    if ( CWorkspace::FindProjectFile(this: Count, filename: project_name) != nullptr )
    {
      Con_Printf(fmt: "Project %s already exists in workspace\n", project_name);
    }
    else
    {
LABEL_11:
      v5 = (CProject *)operator new(nSize: 0x1ACu);
      if ( v5 != nullptr )
        v6 = CProject::CProject(this: v5, ws: Count, filename: project_name);
      else
        v6 = nullptr;
      if ( Count != nullptr )
        CWorkspaceBrowser::AddProject(this: this->m_pBrowser, project: v6);
      CWorkspaceManager::OnUpdateTitle(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D2D0
// Name: private: void CWorkspaceManager::OnRecentWorkspace(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnRecentWorkspace(CWorkspaceManager *this, int index)
{
  if ( index >= 0 && index < this->m_RecentFiles.m_Size )
    CWorkspaceManager::LoadWorkspace(this, filename: this->m_RecentFiles.m_Memory.m_pMemory[index].filename);
}

//------------------------------------------------------------------------------
// Address: 0x0041D2F0
// Name: private: void CWorkspaceManager::OnSoundProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnSoundProperties(CWorkspaceManager *this)
{
  int Flags; // eax
  int v2; // edi
  int m_Size; // eax
  int v4; // esi
  CSoundEntry **m_pMemory; // ecx
  int v6; // eax
  int *v7; // eax
  CSoundParams params; // [esp+0h] [ebp-A4h] BYREF

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v2 = (*(int (__thiscall **)(int))(*(_DWORD *)Flags + 20))(a1: Flags);
    if ( v2 != 0 )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Sound Properties");
      m_Size = params.items.m_Size;
      v4 = params.items.m_Size;
      if ( params.items.m_Size + 1 > params.items.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&params.items,
          num: params.items.m_Size - params.items.m_Memory.m_nAllocationCount + 1);
        m_Size = params.items.m_Size;
      }
      m_pMemory = params.items.m_Memory.m_pMemory;
      params.items.m_Size = m_Size + 1;
      v6 = m_Size - v4;
      params.items.m_pElements = params.items.m_Memory.m_pMemory;
      if ( v6 > 0 )
      {
        _V_memmove(
          dest: &params.items.m_Memory.m_pMemory[v4 + 1],
          src: &params.items.m_Memory.m_pMemory[v4],
          count: 4 * v6);
        m_pMemory = params.items.m_Memory.m_pMemory;
      }
      v7 = (int *)&m_pMemory[v4];
      if ( v7 != nullptr )
        *v7 = v2;
      SoundProperties(&params);
      CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&params.items);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D3C0
// Name: private: void CWorkspaceManager::OnWaveProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnWaveProperties(CWorkspaceManager *this)
{
  int Flags; // eax
  int v2; // edi
  int m_Size; // eax
  int v4; // esi
  CWaveFile **m_pMemory; // ecx
  int v6; // eax
  int *v7; // eax
  CWaveParams params; // [esp+0h] [ebp-A0h] BYREF

  Flags = ConCommandBase::GetFlags(this: (ConCommandBase *)this->m_pBrowser);
  if ( Flags != 0 )
  {
    v2 = (*(int (__thiscall **)(int))(*(_DWORD *)Flags + 24))(a1: Flags);
    if ( v2 != 0 )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Wave Properties");
      m_Size = params.items.m_Size;
      v4 = params.items.m_Size;
      if ( params.items.m_Size + 1 > params.items.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&params.items,
          num: params.items.m_Size - params.items.m_Memory.m_nAllocationCount + 1);
        m_Size = params.items.m_Size;
      }
      m_pMemory = params.items.m_Memory.m_pMemory;
      params.items.m_Size = m_Size + 1;
      v6 = m_Size - v4;
      params.items.m_pElements = params.items.m_Memory.m_pMemory;
      if ( v6 > 0 )
      {
        _V_memmove(
          dest: &params.items.m_Memory.m_pMemory[v4 + 1],
          src: &params.items.m_Memory.m_pMemory[v4],
          count: 4 * v6);
        m_pMemory = params.items.m_Memory.m_pMemory;
      }
      v7 = (int *)&m_pMemory[v4];
      if ( v7 != nullptr )
        *v7 = v2;
      WaveProperties(&params);
      CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&params.items);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D490
// Name: public: CWorkspaceManager::CWorkspaceManager(void)
// Source: json
//------------------------------------------------------------------------------
CWorkspaceManager *__thiscall CWorkspaceManager::CWorkspaceManager(CWorkspaceManager *this)
{
  CStatusWindow *v2; // eax
  CStatusWindow *v3; // eax
  mxWindow *v4; // eax
  CWorkspaceWorkArea *v5; // edi
  mxMenuBar *v6; // eax
  mxMenuBar *v7; // eax
  mxMenu *v8; // eax
  mxMenu *v9; // eax
  mxMenu *v10; // eax
  mxMenu *v11; // eax
  mxMenu *v12; // eax
  mxMenu *v13; // eax
  mxMenu *v14; // eax
  mxMenu *v15; // eax
  signed int i; // edi
  const char *v17; // eax
  mxMenu *m_pProjectMenu; // edi
  CWorkspaceBrowser *v19; // eax
  CWorkspaceBrowser *v20; // eax
  CWaveBrowser *v21; // eax
  CWaveBrowser *v22; // eax
  CSoundBrowser *v23; // eax
  CSoundBrowser *v24; // eax
  CWorkspaceBrowser *m_pBrowser; // ecx

  mxWindow::mxWindow(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: g_appTitle, style: 0);
  this->__vftable = (CWorkspaceManager_vtbl *)&CWorkspaceManager::`vftable';
  this->m_RecentFiles.m_Memory.m_pMemory = nullptr;
  this->m_RecentFiles.m_Memory.m_nAllocationCount = 0;
  this->m_RecentFiles.m_Memory.m_nGrowSize = 0;
  this->m_RecentFiles.m_Size = 0;
  this->m_RecentFiles.m_pElements = nullptr;
  this->m_lEnglishCaptionsFileChangeTime = -1;
  this->m_nLanguageId = 0;
  g_pManager = this;
  v2 = (CStatusWindow *)operator new(nSize: 0x84014u);
  if ( v2 != nullptr )
    v3 = CStatusWindow::CStatusWindow(this: v2, parent: this, x: 0, y: 0, w: 1024, h: 150, label: &WindowName);
  else
    v3 = nullptr;
  g_pStatusWindow = v3;
  mxWidget::setVisible(this: v3, b: true);
  v4 = (mxWindow *)operator new(nSize: 0xCu);
  v5 = (CWorkspaceWorkArea *)v4;
  if ( v4 != nullptr )
  {
    mxWindow::mxWindow(this: v4, parent: this, x: 0, y: 0, w: 0, h: 0, label: &WindowName, style: 0);
    v5->__vftable = (CWorkspaceWorkArea_vtbl *)&CWorkspaceWorkArea::`vftable';
    SceneManager_AddWindowStyle(w: v5, addbits: 369098752);
  }
  else
  {
    v5 = nullptr;
  }
  this->m_pWorkArea = v5;
  Con_Printf(fmt: "Initializing\n");
  Con_Printf(fmt: "CSoundEmitterSystemBase::Init()\n");
  this->m_nRecentMenuItems = 0;
  v6 = (mxMenuBar *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxMenuBar::mxMenuBar(this: v6, parent: this);
  else
    v7 = nullptr;
  this->m_pMenuBar = v7;
  v8 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v9 = mxMenu::mxMenu(this: v8);
  else
    v9 = nullptr;
  this->m_pFileMenu = v9;
  v10 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v11 = mxMenu::mxMenu(this: v10);
  else
    v11 = nullptr;
  this->m_pProjectMenu = v11;
  v12 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    v13 = mxMenu::mxMenu(this: v12);
  else
    v13 = nullptr;
  this->m_pOptionsMenu = v13;
  v14 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v14 != nullptr )
    v15 = mxMenu::mxMenu(this: v14);
  else
    v15 = nullptr;
  this->m_pMenuCloseCaptionLanguages = v15;
  for ( i = 0; i < 12; ++i )
  {
    v17 = CSentence::NameForLanguage(language: i);
    mxPopupMenu::add(this: (mxPopupMenu *)this->m_pMenuCloseCaptionLanguages, item: v17, id: i + 1600);
  }
  mxMenu::setChecked(this: this->m_pMenuCloseCaptionLanguages, id: 1600, b: true);
  mxMenu::addMenu(
    this: (mxMenuBar *)this->m_pOptionsMenu,
    item: "CC Language",
    menu: this->m_pMenuCloseCaptionLanguages);
  mxMenu::addMenu(this: this->m_pMenuBar, item: "File", menu: this->m_pFileMenu);
  mxMenu::addMenu(this: this->m_pMenuBar, item: "Project", menu: this->m_pProjectMenu);
  mxMenu::addMenu(this: this->m_pMenuBar, item: "Options", menu: this->m_pOptionsMenu);
  CWorkspaceManager::CreateFileMenu(this, m: this->m_pFileMenu);
  m_pProjectMenu = this->m_pProjectMenu;
  mxPopupMenu::add(this: (mxPopupMenu *)m_pProjectMenu, item: "Create New Project...", id: 1010);
  mxMenu::addSeparator(this: (mxPopupMenu *)m_pProjectMenu);
  mxPopupMenu::add(this: (mxPopupMenu *)m_pProjectMenu, item: "Insert Project...", id: 1011);
  mxPopupMenu::add(this: (mxPopupMenu *)m_pProjectMenu, item: "Remove Project...", id: 1012);
  mxMenu::addSeparator(this: (mxPopupMenu *)m_pProjectMenu);
  mxPopupMenu::add(this: (mxPopupMenu *)m_pProjectMenu, item: "Properties...", id: 1013);
  mxWindow::setMenuBar(this, menuBar: this->m_pMenuBar);
  Con_Printf(fmt: "Creating browser\n");
  v19 = (CWorkspaceBrowser *)operator new(nSize: 0x1Cu);
  if ( v19 != nullptr )
    v20 = CWorkspaceBrowser::CWorkspaceBrowser(this: v19, parent: this->m_pWorkArea, manager: this, id: 1030);
  else
    v20 = nullptr;
  this->m_pBrowser = v20;
  this->m_pSoundBrowser = nullptr;
  this->m_pWaveBrowser = nullptr;
  mxWidget::setBounds(this, x: 10, y: 10, w: 1280, h: 960);
  mxWidget::setVisible(this, b: true);
  Con_Printf(fmt: "Creating wave browser\n");
  v21 = (CWaveBrowser *)operator new(nSize: 0xA0u);
  if ( v21 != nullptr )
    v22 = CWaveBrowser::CWaveBrowser(this: v21, parent: this->m_pWorkArea, manager: this, id: 1032);
  else
    v22 = nullptr;
  this->m_pWaveBrowser = v22;
  Con_Printf(fmt: "Creating sound browser\n");
  v23 = (CSoundBrowser *)operator new(nSize: 0x90u);
  if ( v23 != nullptr )
    v24 = CSoundBrowser::CSoundBrowser(this: v23, parent: this->m_pWorkArea, manager: this, id: 1031);
  else
    v24 = nullptr;
  m_pBrowser = this->m_pBrowser;
  this->m_pSoundBrowser = v24;
  CWorkspaceBrowser::SetWorkspace(this: m_pBrowser, w: nullptr);
  CWorkspaceManager::PerformLayout(this, movebrowsers: true);
  CWorkspaceManager::LoadRecentFilesMenuFromDisk(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041D7B0
// Name: private: void CWorkspaceManager::OnNewWorkspace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::OnNewWorkspace(CWorkspaceManager *this)
{
  const char *SaveFileName; // eax
  char workspace_name[512]; // [esp+4h] [ebp-200h] BYREF

  SaveFileName = mxGetSaveFileName(parent: nullptr, path: ".", filter: "*.vsw");
  if ( SaveFileName != nullptr && *SaveFileName != 0 )
  {
    filesystem->FullPathToRelativePath(this: filesystem, a2: SaveFileName, a3: workspace_name, a4: 512);
    V_StripExtension(in: workspace_name, out: workspace_name, outSize: 512);
    V_DefaultExtension(path: workspace_name, extension: ".vsw", pathStringLength: 512);
    if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: workspace_name, a3: nullptr) )
      Con_Printf(fmt: "%s exists already!\n", workspace_name);
    else
      CWorkspaceManager::LoadWorkspace(this, filename: workspace_name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D870
// Name: public: void CWorkspaceManager::AutoLoad(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceManager::AutoLoad(CWorkspaceManager *this, CWorkspaceManager::RecentFile *workspace)
{
  CWorkspaceManager::RecentFile *m_pMemory; // eax

  m_pMemory = workspace;
  if ( workspace == nullptr )
  {
    if ( this->m_RecentFiles.m_Size <= 0 )
      return;
    m_pMemory = this->m_RecentFiles.m_Memory.m_pMemory;
  }
  CWorkspaceManager::LoadWorkspace(this, filename: m_pMemory->filename);
}

//------------------------------------------------------------------------------
// Address: 0x0041D890
// Name: public: virtual int CWorkspaceManager::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkspaceManager::handleEvent(CWorkspaceManager *this, mxEvent *event)
{
  int v3; // ecx
  int v4; // edi
  int result; // eax
  int action; // eax
  unsigned int v7; // ebx
  bool v8; // zf
  const char *v9; // edi
  int v10; // edi
  CWorkspaceBrowser *m_pBrowser; // ecx
  CSoundBrowser *m_pSoundBrowser; // ecx
  CWaveBrowser *m_pWaveBrowser; // ecx
  int v14; // edi
  int v15; // ebx
  char pDest[260]; // [esp+8h] [ebp-108h] BYREF
  int iret; // [esp+10Ch] [ebp-4h]

  v3 = event->event;
  v4 = 0;
  iret = 0;
  switch ( v3 )
  {
    case 0:
      action = event->action;
      iret = 1;
      switch ( action )
      {
        case 1000:
          mx::quit();
          return iret;
        case 1001:
          CWorkspaceManager::OnNewWorkspace(this);
          return iret;
        case 1002:
          CWorkspaceManager::OnOpenWorkspace(this);
          return iret;
        case 1003:
          CWorkspaceManager::OnCloseWorkspace(this);
          return iret;
        case 1004:
          CWorkspaceManager::OnSaveWorkspace(this);
          return iret;
        case 1005:
          goto $LN29;
        case 1006:
          CWorkspaceManager::OnChangeVSSProperites(this);
          return iret;
        case 1007:
          CWorkspaceManager::OnCheckoutWorkspace(this);
          return iret;
        case 1008:
          CWorkspaceManager::OnCheckinWorkspace(this);
          return iret;
        case 1010:
          CWorkspaceManager::OnNewProject(this, a2: (const char *)this);
          return iret;
        case 1011:
          CWorkspaceManager::OnInsertProject(this);
          return iret;
        case 1012:
          CWorkspaceManager::OnRemoveProject(this);
          return iret;
        case 1013:
          CWorkspaceManager::OnModifyProjectComments(this);
          return iret;
        case 1014:
          CWorkspaceManager::OnNewScene(this);
          return iret;
        case 1015:
          CWorkspaceManager::OnRemoveScene(this);
          return iret;
        case 1016:
          CWorkspaceManager::OnSoundPlay(this);
          return iret;
        case 1017:
          CWorkspaceManager::OnSoundToggleVoiceDuck(this);
          return iret;
        case 1018:
          CWorkspaceManager::OnSoundEditText(this);
          return iret;
        case 1019:
          CWorkspaceManager::OnSoundShowInBrowsers(this);
          return iret;
        case 1020:
          CWorkspaceManager::OnSoundProperties(this);
          return iret;
        case 1021:
          CWorkspaceManager::OnSceneAddVCD(this);
          return iret;
        case 1022:
          CWorkspaceManager::OnSceneRemoveVCD(this);
          return iret;
        case 1023:
          CWorkspaceManager::OnModifySceneComments(this);
          return iret;
        case 1024:
          CWorkspaceManager::OnModifyVCDComments(this);
          return iret;
        case 1025:
          CWorkspaceManager::OnCheckout(this);
          return iret;
        case 1026:
          CWorkspaceManager::OnCheckin(this);
          return iret;
        case 1027:
          CWorkspaceManager::OnMoveUp(this);
          return iret;
        case 1028:
          CWorkspaceManager::OnMoveDown(this);
          return iret;
        case 1029:
          CWorkspaceManager::OnWaveProperties(this);
          return iret;
        default:
          if ( action >= 1500 && action < 1510 )
          {
            CWorkspaceManager::OnRecentWorkspace(this, index: action - 1500);
            return iret;
          }
          if ( action < 1600 || action >= 1612 )
          {
            iret = 0;
            result = 0;
          }
          else
          {
            v7 = action - 1600;
            v8 = this->m_nLanguageId == action - 1600;
            this->m_nLanguageId = action - 1600;
            if ( v8 )
              goto LABEL_59;
            do
            {
              mxMenu::setChecked(this: this->m_pMenuCloseCaptionLanguages, id: v4 + 1600, b: v4 == this->m_nLanguageId);
              ++v4;
            }
            while ( v4 < 12 );
            v9 = CSentence::NameForLanguage(language: v7);
            if ( _V_stricmp(s1: v9, s2: "unknown_language") != 0 )
            {
              V_snprintf(pDest, maxLen: 260, pFormat: "resource/closecaption_%s.txt", v9);
              v10 = filesystem->GetFileTime(this: &filesystem->IBaseFileSystem, a2: pDest, a3: nullptr);
              if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
              {
                if ( this->m_lEnglishCaptionsFileChangeTime != v10 )
                {
                  this->m_lEnglishCaptionsFileChangeTime = v10;
                  g_pVGuiLocalize->RemoveAll(this: g_pVGuiLocalize);
                  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: pDest, a3: nullptr, a4: false);
                }
              }
              else
              {
                Con_Printf(
                  fmt: "CWorkspaceManager::OnChangeLanguage  Warning, can't find localization file %s\n",
                  pDest);
              }
            }
            m_pBrowser = this->m_pBrowser;
            if ( m_pBrowser != nullptr )
              CWorkspaceBrowser::PopulateTree(this: m_pBrowser);
            m_pSoundBrowser = this->m_pSoundBrowser;
            if ( m_pSoundBrowser != nullptr )
              CSoundBrowser::RepopulateTree(this: m_pSoundBrowser);
            m_pWaveBrowser = this->m_pWaveBrowser;
            if ( m_pWaveBrowser != nullptr )
              CWaveBrowser::RepopulateTree(this: m_pWaveBrowser);
            CWorkspaceManager::OnUpdateTitle(this);
            result = iret;
          }
          break;
      }
      return result;
    case 1:
      iret = 1;
      v14 = mxWidget::w2(this);
      v15 = mxWidget::h2(this) - 100;
      mxWidget::setBounds(this: this->m_pWorkArea, x: 0, y: 0, w: v14, h: v15);
      mxWidget::setBounds(this: g_pStatusWindow, x: 0, y: v15, w: v14, h: 100);
      goto LABEL_59;
    case 3:
      CWorkspaceManager::Frame(this);
      return 1;
    case 10:
      if ( event->key != 116 )
        goto LABEL_59;
$LN29:
      CWorkspaceManager::RefreshBrowsers(this);
      result = iret;
      break;
    case 14:
      if ( event->action != 0 )
      {
        mx::setIdleWindow(window: this);
        CWorkspaceManager::OnChangeLanguage(this, lang_index: this->m_nLanguageId, force: true);
      }
      else
      {
        mx::setIdleWindow(window: nullptr);
      }
      iret = 1;
      return 1;
    default:
LABEL_59:
      result = iret;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041DFE0
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E7B0
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
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
// Address: 0x0041E920
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
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
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
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
// Address: 0x0041EFD0
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004202F0
// Name: public: void CUtlMemory<struct CExpressionSample,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CExpressionSample,int>::Grow(CUtlMemory<CExpressionSample,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CExpressionSample *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CExpressionSample *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CExpressionSample *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420FC0
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v6; // eax
  CExpressionSample *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 10 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->value = 0.0;
    v7->time = 0.0;
    *((_WORD *)v7 + 4) = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00423FC0
// Name: public: void CUtlMemory<struct fileList_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<fileList_t,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: m_pMemory,
                                                                                        a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424060
// Name: public: void CUtlMemory<class CEventAbsoluteTag,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CEventAbsoluteTag,int>::Grow(CUtlMemory<CEventAbsoluteTag,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CEventAbsoluteTag *m_pMemory; // edx

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
      this->m_pMemory = (CEventAbsoluteTag *)_g_pMemAlloc->Realloc_2(
                                               this: _g_pMemAlloc,
                                               a2: m_pMemory,
                                               a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CEventAbsoluteTag *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424940
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertBefore(int,struct CExpressionSample const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem,
        const CExpressionSample *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v7; // eax
  CExpressionSample *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 10 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00424B70
// Name: public: int CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::InsertBefore(int,class CEventRelativeTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::InsertBefore(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this,
        int elem,
        const CEventRelativeTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEventRelativeTag *m_pMemory; // ecx
  int v7; // eax
  CEventRelativeTag *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<fileList_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->m_Name);
    CUtlString::operator=(this: &v8->m_Name, src: &src->m_Name);
    v8->m_flPercentage = src->m_flPercentage;
    v8->m_pOwner = src->m_pOwner;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00424C00
// Name: public: int CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::InsertBefore(int,class CFlexTimingTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::InsertBefore(
        CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int> > *this,
        int elem,
        const CFlexTimingTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFlexTimingTag *m_pMemory; // ecx
  int v7; // eax
  CFlexTimingTag *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEventAbsoluteTag,int>::Grow(
      (CUtlMemory<CEventAbsoluteTag,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->m_Name);
    CUtlString::operator=(this: &v8->m_Name, src: &src->m_Name);
    v8->m_flPercentage = src->m_flPercentage;
    v8->m_pOwner = src->m_pOwner;
    v8->m_bLocked = src->m_bLocked;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00424CA0
// Name: public: int CUtlVector<class CEventAbsoluteTag,class CUtlMemory<class CEventAbsoluteTag,int>>::InsertBefore(int,class CEventAbsoluteTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int>>::InsertBefore(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this,
        int elem,
        const CEventAbsoluteTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEventAbsoluteTag *m_pMemory; // ecx
  int v7; // eax
  CEventAbsoluteTag *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEventAbsoluteTag,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CEventAbsoluteTag::CEventAbsoluteTag(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00425680
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E710
// Name: public: void CUtlMemory<class CChoreoActor __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CChoreoActor *,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
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
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
