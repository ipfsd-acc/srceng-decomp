// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/choreowidgetdrawhelper.cpp
// Functions: 106
// ============================================================

#include "utils\hlfaceposer\choreowidgetdrawhelper.h"

//------------------------------------------------------------------------------
// Address: 0x00403500
// Name: public: void CUtlMemory<struct VisibleStreamItem,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VisibleStreamItem,int>::Grow(CUtlMemory<CAudioMixerState,int> *this, int num)
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
// Address: 0x00403BC0
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
// Address: 0x00405400
// Name: public: void CUtlVector<struct GetTriangles_MaterialBatch_t,class CUtlMemory<struct GetTriangles_MaterialBatch_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::RemoveAll(
        CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    v7 = 44 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 9) = 0;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( *((_DWORD *)v3 + 6) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 6));
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      v4 = *((void **)v3 + 6);
      *((_DWORD *)v3 + 10) = v4;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v5 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v5;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 44;
      v7 -= 44;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004054F0
// Name: public: CUtlVector<struct GetTriangles_MaterialBatch_t,class CUtlMemory<struct GetTriangles_MaterialBatch_t,int>>::~CUtlVector<struct GetTriangles_MaterialBatch_t,class CUtlMemory<struct GetTriangles_MaterialBatch_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::~CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>(
        CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int> > *this)
{
  bool v2; // sf
  GetTriangles_MaterialBatch_t *m_pMemory; // eax

  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::RemoveAll(this);
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
// Address: 0x0040A030
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edx
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
    v7 = 100 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<JiggleData,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: m_pMemory,
                                                                            a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<JiggleData,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E380
// Name: public: void CUtlMemory<struct SceneImageEntry_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SceneImageEntry_t,int>::Grow(CUtlMemory<SceneImageEntry_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SceneImageEntry_t *m_pMemory; // edx
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
      this->m_pMemory = (SceneImageEntry_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SceneImageEntry_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E540
// Name: public: int CUtlVector<struct tagPOINT,class CUtlMemory<struct tagPOINT,int>>::InsertBefore(int,struct tagPOINT const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<tagPOINT,CUtlMemory<tagPOINT,int>>::InsertBefore(
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
    CUtlMemory<VisibleStreamItem,int>::Grow(
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
// Address: 0x0040E5B0
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
    CUtlMemory<SceneImageEntry_t,int>::Grow(
      (CUtlMemory<SceneImageEntry_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x0040EAE0
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
      (CUtlMemory<UtlRBTreeNode_t<CChoreoScene::ActiveList,int>,int> *)this,
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
// Address: 0x0040EB50
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
      (CUtlMemory<UtlRBTreeNode_t<CChoreoScene::ActiveList,int>,int> *)this,
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
// Address: 0x0040EBF0
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
// Address: 0x0040EC60
// Name: public: void CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CEventRelativeTag *v3; // esi
  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ECD0
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
// Address: 0x0040EF90
// Name: public: CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::~CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this)
{
  bool v2; // sf
  CEventRelativeTag *m_pMemory; // eax

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this);
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
// Address: 0x00410310
// Name: public: void CUtlVector<class Color,class CUtlMemory<class Color,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::Remove(
        CUtlVector<CPhonemeTag *,CUtlMemory<CPhonemeTag *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00410A70
// Name: public: int CUtlVector<class CPhonemeTag __near *,class CUtlMemory<class CPhonemeTag __near *,int>>::InsertBefore(int,class CPhonemeTag __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPhonemeTag *,CUtlMemory<CPhonemeTag *,int>>::InsertBefore(
        CUtlVector<CWordTag *,CUtlMemory<CWordTag *,int> > *this,
        int elem,
        CWordTag **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWordTag **m_pMemory; // ecx
  int v7; // eax
  CWordTag **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
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
// Address: 0x00410AE0
// Name: public: int CUtlVector<struct CEmphasisSample,class CUtlMemory<struct CEmphasisSample,int>>::InsertBefore(int,struct CEmphasisSample const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEmphasisSample,CUtlMemory<CEmphasisSample,int>>::InsertBefore(
        CUtlVector<CEmphasisSample,CUtlMemory<CEmphasisSample,int> > *this,
        int elem,
        const CEmphasisSample *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEmphasisSample *m_pMemory; // ecx
  int v7; // eax
  CEmphasisSample *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
      (CUtlMemory<CAppSystemGroup::Module_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004149B0
// Name: public: int CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(
        CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<SceneImageEntry_t,int>::Grow(
      (CUtlMemory<SceneImageEntry_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->activityIdx = -1;
          v11->startingIdx = -1;
          v11->count = -1;
          v11->totalWeight = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00414C40
// Name: public: int CUtlVector<struct studiohdr_t const __near *,class CUtlMemory<struct studiohdr_t const __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
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
// Address: 0x00414D80
// Name: public: int CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041ABB0
// Name: public: int CUtlVector<struct StudioLookTarget,class CUtlMemory<struct StudioLookTarget,int>>::InsertBefore(int,struct StudioLookTarget const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<StudioLookTarget,CUtlMemory<StudioLookTarget,int>>::InsertBefore(
        CUtlVector<StudioLookTarget,CUtlMemory<StudioLookTarget,int> > *this,
        int elem,
        const StudioLookTarget *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  StudioLookTarget *m_pMemory; // ecx
  int v7; // eax
  StudioLookTarget *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      (CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041ACE0
// Name: public: void CUtlVector<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,class CUtlMemory<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AD80
// Name: public: CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>::~CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this);
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
// Address: 0x0041D050
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  __int16 *m_pMemory; // edx
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
      this->m_pMemory = (__int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (__int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D440
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct HitboxInfo_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *m_pMemory; // edx
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
    v7 = 88 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                              this: _g_pMemAlloc,
                                                                              a2: m_pMemory,
                                                                              a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                              this: _g_pMemAlloc,
                                                                              a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D790
// Name: public: CUtlVector<struct IFaceposerModels::CFacePoserModel::AnimBitmap __near *,class CUtlMemory<struct IFaceposerModels::CFacePoserModel::AnimBitmap __near *,int>>::~CUtlVector<struct IFaceposerModels::CFacePoserModel::AnimBitmap __near *,class CUtlMemory<struct IFaceposerModels::CFacePoserModel::AnimBitmap __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(
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
// Address: 0x0041D9F0
// Name: public: int CUtlVector<struct HitboxSet_t,class CUtlMemory<struct HitboxSet_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::InsertBefore(
        CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  HitboxSet_t *m_pMemory; // ecx
  int v6; // eax
  HitboxSet_t *v7; // esi
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_Name);
    v7->m_Hitboxes.m_Memory.m_pMemory = nullptr;
    v7->m_Hitboxes.m_Memory.m_nAllocationCount = 0;
    v7->m_Hitboxes.m_Memory.m_nGrowSize = 0;
    v7->m_Hitboxes.m_LastAlloc.index = -1;
    *(_DWORD *)&v7->m_Hitboxes.m_FirstFree = 0xFFFF;
    v8 = v7->m_Hitboxes.m_Memory.m_pMemory;
    *(_DWORD *)&v7->m_Hitboxes.m_Head = -1;
    v7->m_Hitboxes.m_NumAlloced = 0;
    v7->m_Hitboxes.m_pElements = v8;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041DA80
// Name: public: void CUtlVector<struct HitboxSet_t,class CUtlMemory<struct HitboxSet_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::RemoveAll(
        CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int> > *this)
{
  int v1; // eax
  int v2; // eax
  char *v3; // esi
  CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int> > *v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    for ( j = v2; ; v2 = j )
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *)(v3 + 16));
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 4));
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      j -= 44;
      this = v4;
      if ( --i < 0 )
        break;
    }
    v4->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DFD0
// Name: public: CUtlVector<struct HitboxSet_t,class CUtlMemory<struct HitboxSet_t,int>>::~CUtlVector<struct HitboxSet_t,class CUtlMemory<struct HitboxSet_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::~CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>(
        CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int> > *this)
{
  bool v2; // sf
  HitboxSet_t *m_pMemory; // eax

  CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::RemoveAll(this);
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
// Address: 0x00422FC0
// Name: public: void CUtlMemory<struct ChoiceText,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ChoiceText,int>::Grow(CUtlMemory<ChoiceText,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ChoiceText *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 7;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ChoiceText *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ChoiceText *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004277B0
// Name: public: void CUtlMemory<struct CombinerEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CombinerEntry,int>::Grow(CUtlMemory<CombinerEntry,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CombinerEntry *m_pMemory; // edx
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
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CombinerEntry *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CombinerEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BCC0
// Name: public: void CUtlVector<struct CChoreoView::CFocusRect,class CUtlMemory<struct CChoreoView::CFocusRect,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CChoreoView::CFocusRect,CUtlMemory<CChoreoView::CFocusRect,int>>::Purge(
        CUtlVector<CChoreoView::CFocusRect,CUtlMemory<CChoreoView::CFocusRect,int> > *this)
{
  bool v2; // sf
  CChoreoView::CFocusRect *m_pMemory; // ecx

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
// Address: 0x0042C330
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SceneImageEntry_t,int>::Grow(
      (CUtlMemory<SceneImageEntry_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042C3A0
// Name: public: int CUtlVector<struct ChoiceText,class CUtlMemory<struct ChoiceText,int>>::InsertBefore(int,struct ChoiceText const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int>>::InsertBefore(
        CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int> > *this,
        int elem,
        const ChoiceText *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ChoiceText *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ChoiceText,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00444700
// Name: public: bool CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>>::FindAndRemove(class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::FindAndRemove(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *this,
        const CUtlSymbol *src)
{
  int m_Size; // edx
  int v4; // eax
  CUtlSymbol *m_pMemory; // ebx
  CUtlSymbol *i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; i->m_Id != src->m_Id; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 2 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00445850
// Name: public: void CUtlMemory<class CExpression,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CExpression,int>::Grow(CUtlMemory<CExpression,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CExpression *m_pMemory; // edx
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
    v7 = 3652 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CExpression *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CExpression *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004458F0
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
// Address: 0x00446710
// Name: public: int CUtlVector<class CExpression,class CUtlMemory<class CExpression,int>>::InsertBefore(int,class CExpression const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpression,CUtlMemory<CExpression,int>>::InsertBefore(
        CUtlVector<CExpression,CUtlMemory<CExpression,int> > *this,
        int elem,
        const CExpression *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpression *m_pMemory; // ecx
  int v7; // eax
  CExpression *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpression,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 3652 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CExpression::CExpression(this: v8, from: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00446790
// Name: public: void CUtlVector<class CExpression,class CUtlMemory<class CExpression,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CExpression,CUtlMemory<CExpression,int>>::Purge(
        CUtlVector<CExpression,CUtlMemory<CExpression,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CExpression *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CExpression::~CExpression(this: &this->m_Memory.m_pMemory[v3--]);
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
// Address: 0x004468F0
// Name: public: int CUtlVector<class CExpression,class CUtlMemory<class CExpression,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpression,CUtlMemory<CExpression,int>>::InsertBefore(
        CUtlVector<CExpression,CUtlMemory<CExpression,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpression *m_pMemory; // ecx
  int v6; // eax
  CExpression *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpression,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 3652 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CExpression::CExpression(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0044C8C0
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
// Address: 0x00450000
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertMultipleBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // edx
  CExpressionSample *v14; // ecx
  CExpressionSample *v15; // ecx
  CExpressionSample *v16; // ecx
  CExpressionSample *v17; // ecx
  int v18; // eax
  int v19; // edi
  CExpressionSample *v20; // ecx
  int i; // [esp+14h] [ebp+Ch]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 10 * v10);
  v11 = 0;
  if ( num >= 4 )
  {
    v12 = elem;
    v13 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v13;
    do
    {
      v14 = &this->m_Memory.m_pMemory[v12];
      if ( v14 != nullptr )
      {
        v14->value = 0.0;
        v14->time = 0.0;
        *((_WORD *)v14 + 4) = 0;
      }
      v15 = &this->m_Memory.m_pMemory[v12 + 1];
      if ( &this->m_Memory.m_pMemory[v12] != (CExpressionSample *)-10 )
      {
        v15->value = 0.0;
        v15->time = 0.0;
        *((_WORD *)v15 + 4) = 0;
      }
      v16 = &this->m_Memory.m_pMemory[v12 + 2];
      if ( &this->m_Memory.m_pMemory[v12] != (CExpressionSample *)-20 )
      {
        v16->value = 0.0;
        v16->time = 0.0;
        *((_WORD *)v16 + 4) = 0;
      }
      v17 = &this->m_Memory.m_pMemory[v12 + 3];
      if ( &this->m_Memory.m_pMemory[v12] != (CExpressionSample *)-30 )
      {
        v17->value = 0.0;
        v17->time = 0.0;
        *((_WORD *)v17 + 4) = 0;
      }
      v12 += 4;
      --v13;
    }
    while ( v13 != 0 );
    v9 = elem;
    v11 = i;
  }
  if ( v11 < num )
  {
    v18 = v11 + v9;
    v19 = num - v11;
    do
    {
      v20 = &this->m_Memory.m_pMemory[v18];
      if ( v20 != nullptr )
      {
        v20->value = 0.0;
        v20->time = 0.0;
        *((_WORD *)v20 + 4) = 0;
      }
      ++v18;
      --v19;
    }
    while ( v19 != 0 );
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00451710
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
// Address: 0x00456E90
// Name: public: bool CUtlVector<class IFacePoserToolWindow __near *,class CUtlMemory<class IFacePoserToolWindow __near *,int>>::FindAndRemove(class IFacePoserToolWindow __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<IFacePoserToolWindow *,CUtlMemory<IFacePoserToolWindow *,int>>::FindAndRemove(
        CUtlVector<IFacePoserToolWindow *,CUtlMemory<IFacePoserToolWindow *,int> > *this,
        IFacePoserToolWindow **src)
{
  int m_Size; // edx
  int v4; // eax
  IFacePoserToolWindow **m_pMemory; // ebx
  IFacePoserToolWindow **i; // ecx
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
// Address: 0x0047AAB0
// Name: public: int CUtlVector<struct PhonemeEditor::CFocusRect,class CUtlMemory<struct PhonemeEditor::CFocusRect,int>>::InsertBefore(int,struct PhonemeEditor::CFocusRect const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PhonemeEditor::CFocusRect,CUtlMemory<PhonemeEditor::CFocusRect,int>>::InsertBefore(
        CUtlVector<CChoreoView::CFocusRect,CUtlMemory<CChoreoView::CFocusRect,int> > *this,
        int elem,
        const CChoreoView::CFocusRect *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CChoreoView::CFocusRect *m_pMemory; // ecx
  int v7; // eax
  CChoreoView::CFocusRect *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoView::CFocusRect,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00488430
// Name: public: void CUtlMemory<class IFacePoserToolWindow __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IFacePoserToolWindow *,int>::Grow(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this,
        int num)
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

//------------------------------------------------------------------------------
// Address: 0x004884C0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *m_pMemory; // edx
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
      this->m_pMemory = (CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *)_g_pMemAlloc->Realloc_2(
                                                                                              this: _g_pMemAlloc,
                                                                                              a2: m_pMemory,
                                                                                              a3: v7);
    else
      this->m_pMemory = (CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *)_g_pMemAlloc->Alloc_2(
                                                                                              this: _g_pMemAlloc,
                                                                                              a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C800
// Name: public: int CChoreoWidgetDrawHelper::GetHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoWidgetDrawHelper::GetHeight(CChoreoActorWidget *this)
{
  return this->m_Channels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0048EBC0
// Name: public: int CUtlVector<struct CChoreoChannelWidget::CloseCaptionInfo,class CUtlMemory<struct CChoreoChannelWidget::CloseCaptionInfo,int>>::InsertBefore(int,struct CChoreoChannelWidget::CloseCaptionInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CChoreoChannelWidget::CloseCaptionInfo,CUtlMemory<CChoreoChannelWidget::CloseCaptionInfo,int>>::InsertBefore(
        CUtlVector<CChoreoChannelWidget::CloseCaptionInfo,CUtlMemory<CChoreoChannelWidget::CloseCaptionInfo,int> > *this,
        int elem,
        const CChoreoChannelWidget::CloseCaptionInfo *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CChoreoChannelWidget::CloseCaptionInfo *m_pMemory; // ecx
  int v7; // eax
  CChoreoChannelWidget::CloseCaptionInfo *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoChannelWidget::CloseCaptionInfo,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 40 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0048F420
// Name: public: int CUtlVector<class CUtlLinkedList<class CChoreoEventWidget __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEventWidget __near *,int>,int>>,class CUtlMemory<class CUtlLinkedList<class CChoreoEventWidget __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEventWidget __near *,int>,int>>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int>>,CUtlMemory<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int>>,int>>::InsertBefore(
        CUtlVector<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> >,CUtlMemory<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> >,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> > *m_pMemory; // ecx
  int v6; // eax
  CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> > *v7; // eax
  UtlLinkedListElem_t<CChoreoEventWidget *,int> *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoChannelWidget::CloseCaptionInfo,int>::Grow(
      (CUtlMemory<CChoreoChannelWidget::CloseCaptionInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 40 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Memory.m_pMemory = nullptr;
    v7->m_Memory.m_nAllocationCount = 0;
    v7->m_Memory.m_nGrowSize = 0;
    v7->m_LastAlloc.index = -1;
    v7->m_Head = -1;
    v7->m_Tail = -1;
    v7->m_FirstFree = -1;
    v8 = v7->m_Memory.m_pMemory;
    v7->m_ElementCount = 0;
    v7->m_NumAlloced = 0;
    v7->m_pElements = v8;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0048FCF0
// Name: public: void CUtlVector<class CUtlLinkedList<class CChoreoEventWidget __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEventWidget __near *,int>,int>>,class CUtlMemory<class CUtlLinkedList<class CChoreoEventWidget __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CChoreoEventWidget __near *,int>,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int>>,CUtlMemory<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int>>,int>>::RemoveAll(
        CUtlVector<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> >,CUtlMemory<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> >,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> > *v3; // esi
  CUtlVector<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> >,CUtlMemory<CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int> >,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlLinkedList<CChoreoEventWidget *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CChoreoEventWidget *,int>,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      this = v4;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00491EF0
// Name: public: void CChoreoWidgetDrawHelper::GetClientRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::GetClientRect(CChoreoWidgetDrawHelper *this, tagRECT *rc)
{
  rc->top = 0;
  rc->left = 0;
  rc->right = this->m_w;
  rc->bottom = this->m_h;
}

//------------------------------------------------------------------------------
// Address: 0x00491F20
// Name: public: void CChoreoWidgetDrawHelper::CalcTextRect(char const __near *,int,int,int,struct tagRECT __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CChoreoWidgetDrawHelper::CalcTextRect(
        CChoreoWidgetDrawHelper *this,
        const char *font,
        HFONT__ *pointsize,
        int weight,
        int maxwidth,
        tagRECT *rcText,
        const char *fmt,
        ...)
{
  HFONT FontA; // esi
  HFONT__ *oldFont; // [esp+1Ch] [ebp+10h]
  va_list ap; // [esp+30h] [ebp+24h] BYREF

  va_start(ap, fmt);
  vprintf(format: fmt, ap);
  vsprintf(string: output_3, format: fmt, ap);
  FontA = CreateFontA(
            cHeight: -(int)pointsize,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: weight,
            bItalic: 0,
            bUnderline: 0,
            bStrikeOut: 0,
            iCharSet: 0,
            iOutPrecision: 4u,
            iClipPrecision: 0,
            iQuality: 4u,
            iPitchAndFamily: 0,
            pszFaceName: font);
  oldFont = (HFONT__ *)SelectObject(hdc: this->m_dcMemory, h: FontA);
  DrawTextA(hdc: this->m_dcMemory, lpchText: output_3, cchText: -1, lprc: rcText, format: 0xC14u);
  SelectObject(hdc: this->m_dcMemory, h: oldFont);
  DeleteObject(ho: FontA);
}

//------------------------------------------------------------------------------
// Address: 0x00491FC0
// Name: public: static int CChoreoWidgetDrawHelper::CalcTextWidth(char const __near *,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CChoreoWidgetDrawHelper::CalcTextWidth(const char *font, HFONT__ *pointsize, int weight, const char *fmt, ...)
{
  HFONT FontA; // edi
  HDC DC; // esi
  tagRECT rcText; // [esp+Ch] [ebp-10h] BYREF
  HFONT__ *oldFont; // [esp+28h] [ebp+Ch]
  va_list ap; // [esp+34h] [ebp+18h] BYREF

  va_start(ap, fmt);
  vprintf(format: fmt, ap);
  vsprintf(string: output_4, format: fmt, ap);
  FontA = CreateFontA(
            cHeight: -(int)pointsize,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: weight,
            bItalic: 0,
            bUnderline: 0,
            bStrikeOut: 0,
            iCharSet: 0,
            iOutPrecision: 4u,
            iClipPrecision: 0,
            iQuality: 4u,
            iPitchAndFamily: 0,
            pszFaceName: font);
  DC = GetDC(hWnd: nullptr);
  oldFont = (HFONT__ *)SelectObject(hdc: DC, h: FontA);
  rcText.top = 0;
  rcText.left = 0;
  rcText.bottom = (int)pointsize + 5;
  rcText.right = 2048;
  DrawTextA(hdc: DC, lpchText: output_4, cchText: -1, lprc: &rcText, format: 0xC24u);
  SelectObject(hdc: DC, h: oldFont);
  DeleteObject(ho: FontA);
  ReleaseDC(hWnd: nullptr, hDC: DC);
  return rcText.right;
}

//------------------------------------------------------------------------------
// Address: 0x00492080
// Name: public: static int CChoreoWidgetDrawHelper::CalcTextWidthW(struct HFONT__ __near *,wchar_t const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CChoreoWidgetDrawHelper::CalcTextWidthW(HFONT__ *fnt, const wchar_t *fmt, ...)
{
  HDC DC; // esi
  HGDIOBJ v3; // ebx
  tagRECT rcText; // [esp+Ch] [ebp-10h] BYREF
  va_list ap; // [esp+2Ch] [ebp+10h] BYREF

  va_start(ap, fmt);
  vwprintf(format: fmt, ap);
  _vswprintf(string: output_5, format: fmt, ap);
  DC = GetDC(hWnd: nullptr);
  v3 = SelectObject(hdc: DC, h: fnt);
  rcText.top = 0;
  rcText.left = 0;
  rcText.bottom = 1000;
  rcText.right = 2048;
  DrawTextW(hdc: DC, lpchText: output_5, cchText: -1, lprc: &rcText, format: 0xC24u);
  SelectObject(hdc: DC, h: v3);
  ReleaseDC(hWnd: nullptr, hDC: DC);
  return rcText.right;
}

//------------------------------------------------------------------------------
// Address: 0x00492110
// Name: public: void CChoreoWidgetDrawHelper::DrawColoredLine(class Color const __near &,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawColoredLine(
        CChoreoWidgetDrawHelper *this,
        HPEN__ *clr,
        int style,
        int width,
        int x1,
        int y1,
        int x2,
        int y2)
{
  HPEN Pen; // edi
  HPEN__ *oldPen; // [esp+14h] [ebp+8h]

  Pen = CreatePen(iStyle: style, cWidth: width, color: *(_BYTE *)clr | (*(unsigned __int16 *)((char *)clr + 1) << 8));
  oldPen = (HPEN__ *)SelectObject(hdc: this->m_dcMemory, h: Pen);
  MoveToEx(hdc: this->m_dcMemory, x: x1 - this->m_x, y: y1 - this->m_y, lppt: nullptr);
  LineTo(hdc: this->m_dcMemory, x: x2 - this->m_x, y: y2 - this->m_y);
  SelectObject(hdc: this->m_dcMemory, h: oldPen);
  DeleteObject(ho: Pen);
}

//------------------------------------------------------------------------------
// Address: 0x004921A0
// Name: public: struct _POINTL CChoreoWidgetDrawHelper::DrawColoredRamp(class Color const __near &,int,int,int,int,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CChoreoWidgetDrawHelper::DrawColoredRamp(
        CChoreoWidgetDrawHelper *this,
        Color *clr,
        unsigned __int8 *style,
        int width,
        int x1,
        int y1,
        int x2,
        int y2,
        float rate,
        float sustain,
        float sustaina)
{
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  int v15; // edx
  HDC__ *m_dcMemory; // [esp-Ch] [ebp-20h]
  int v18; // [esp-4h] [ebp-18h]
  HPEN__ *pen; // [esp+Ch] [ebp-8h]
  HPEN__ *oldPen; // [esp+10h] [ebp-4h]
  float i; // [esp+20h] [ebp+Ch]

  pen = CreatePen(iStyle: width, cWidth: x1, color: *style | (*(unsigned __int16 *)(style + 1) << 8));
  oldPen = (HPEN__ *)SelectObject(hdc: this->m_dcMemory, h: pen);
  MoveToEx(hdc: this->m_dcMemory, x: y1 - this->m_x, y: x2 - this->m_y, lppt: nullptr);
  v12 = 0.1;
  v13 = 1.0 - sustain;
  v14 = (float)(LODWORD(rate) - x2) * sustaina;
  *clr = 0;
  clr[1] = 0;
  i = 0.1;
  while ( 1 )
  {
    v15 = (int)(float)((float)((float)(y2 - y1) * v12) * v13) - this->m_x;
    v18 = x2
        + (int)(float)((float)((float)((float)(v12 * 3.0) * v12) - (float)((float)((float)(v12 * 2.0) * v12) * v12))
                     * v14)
        - this->m_y;
    m_dcMemory = this->m_dcMemory;
    *clr = (Color)(v15 + y1);
    clr[1] = (Color)v18;
    LineTo(hdc: m_dcMemory, x: v15 + y1, y: v18);
    v12 = i + 0.1;
    i = i + 0.1;
    if ( i > 1.09 )
      break;
    v14 = (float)(LODWORD(rate) - x2) * sustaina;
    v13 = 1.0 - sustain;
  }
  SelectObject(hdc: this->m_dcMemory, h: oldPen);
  DeleteObject(ho: pen);
  return clr;
}

//------------------------------------------------------------------------------
// Address: 0x00492310
// Name: public: void CChoreoWidgetDrawHelper::DrawTriangleMarker(struct tagRECT __near &,class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawTriangleMarker(
        CChoreoWidgetDrawHelper *this,
        tagRECT *rc,
        const Color *fill,
        bool inverted)
{
  int left; // edx
  int m_x; // edi
  int v7; // eax
  int right; // eax
  int top; // ecx
  HRGN PolygonRgn; // edi
  HBRUSH SolidBrush; // ebx
  tagPOINT region[3]; // [esp+Ch] [ebp-18h] BYREF
  int oldPF; // [esp+34h] [ebp+10h]

  left = rc->left;
  m_x = this->m_x;
  v7 = rc->left - m_x;
  region[1].x = rc->right - m_x;
  region[0].x = v7;
  if ( inverted )
  {
    region[0].y = rc->bottom - this->m_y;
    region[1].y = region[0].y;
    right = rc->right;
    top = rc->top;
  }
  else
  {
    region[0].y = rc->top - this->m_y;
    region[1].y = region[0].y;
    right = rc->right;
    top = rc->bottom;
  }
  region[2].y = top - this->m_y;
  region[2].x = (left + right) / 2 - m_x;
  PolygonRgn = CreatePolygonRgn(pptl: region, cPoint: 3, iMode: 1);
  oldPF = SetPolyFillMode(hdc: this->m_dcMemory, mode: 1);
  SolidBrush = CreateSolidBrush(color: fill->_color[0] | ((fill->_color[1] | (fill->_color[2] << 8)) << 8));
  FillRgn(hdc: this->m_dcMemory, hrgn: PolygonRgn, hbr: SolidBrush);
  DeleteObject(ho: SolidBrush);
  SetPolyFillMode(hdc: this->m_dcMemory, mode: oldPF);
  DeleteObject(ho: PolygonRgn);
}

//------------------------------------------------------------------------------
// Address: 0x004923E0
// Name: public: void CChoreoWidgetDrawHelper::OffsetSubRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::OffsetSubRect(CChoreoWidgetDrawHelper *this, tagRECT *rc)
{
  OffsetRect(lprc: rc, dx: -this->m_x, dy: -this->m_y);
}

//------------------------------------------------------------------------------
// Address: 0x00492400
// Name: public: void CChoreoWidgetDrawHelper::DrawFilledRect(struct HBRUSH__ __near *,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawFilledRect(CChoreoWidgetDrawHelper *this, HBRUSH__ *br, tagRECT *rc)
{
  int m_x; // ecx
  int v5; // [esp-8h] [ebp-18h]
  tagRECT rcFill; // [esp+0h] [ebp-10h] BYREF

  m_x = this->m_x;
  *(_QWORD *)&rcFill.left = *(_QWORD *)&rc->left;
  v5 = -this->m_y;
  *(_QWORD *)&rcFill.right = *(_QWORD *)&rc->right;
  OffsetRect(lprc: &rcFill, dx: -m_x, dy: v5);
  FillRect(hDC: this->m_dcMemory, lprc: &rcFill, hbr: br);
}

//------------------------------------------------------------------------------
// Address: 0x00492450
// Name: public: void CChoreoWidgetDrawHelper::DrawCircle(class Color const __near &,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawCircle(
        CChoreoWidgetDrawHelper *this,
        const Color *clr,
        HPEN__ *x,
        HBRUSH__ *y,
        HBRUSH__ *radius,
        bool filled)
{
  int m_y; // ecx
  int v8; // edx
  HPEN Pen; // ebx
  tagRECT rc; // [esp+Ch] [ebp-10h] BYREF
  HPEN__ *oldPen; // [esp+28h] [ebp+Ch]
  HBRUSH__ *oldBr; // [esp+2Ch] [ebp+10h]
  HBRUSH__ *br; // [esp+30h] [ebp+14h]

  rc.left = (int)x - ((int)radius >> 1);
  rc.right = rc.left + 2 * ((int)radius >> 1);
  m_y = this->m_y;
  rc.top = (int)y - ((int)radius >> 1);
  v8 = -this->m_x;
  rc.bottom = (int)y + 2 * ((int)radius >> 1) - 1;
  OffsetRect(lprc: &rc, dx: v8, dy: -m_y);
  Pen = CreatePen(iStyle: 0, cWidth: 1, color: clr->_color[0] | (*(unsigned __int16 *)&clr->_color[1] << 8));
  br = CreateSolidBrush(color: clr->_color[0] | (*(unsigned __int16 *)&clr->_color[1] << 8));
  oldPen = (HPEN__ *)SelectObject(hdc: this->m_dcMemory, h: Pen);
  oldBr = (HBRUSH__ *)SelectObject(hdc: this->m_dcMemory, h: br);
  if ( filled )
    Ellipse(hdc: this->m_dcMemory, left: rc.left, top: rc.top, right: rc.right, bottom: rc.bottom);
  else
    Arc(
      hdc: this->m_dcMemory,
      x1: rc.left,
      y1: rc.top,
      x2: rc.right,
      y2: rc.bottom,
      x3: rc.left,
      y3: rc.top,
      x4: rc.left,
      y4: rc.top);
  SelectObject(hdc: this->m_dcMemory, h: oldPen);
  SelectObject(hdc: this->m_dcMemory, h: oldBr);
  DeleteObject(ho: Pen);
  DeleteObject(ho: br);
}

//------------------------------------------------------------------------------
// Address: 0x00492570
// Name: public: void CChoreoWidgetDrawHelper::DrawGradientFilledRect(struct tagRECT __near &,class Color const __near &,class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawGradientFilledRect(
        CChoreoWidgetDrawHelper *this,
        tagRECT *rc,
        const Color *clr1,
        const Color *clr2,
        bool vertical)
{
  int m_x; // ecx
  __int16 v7; // cx
  unsigned __int16 v8; // dx
  __int16 v9; // ax
  unsigned __int16 v10; // dx
  int v11; // [esp-8h] [ebp-40h]
  _TRIVERTEX vert[2]; // [esp+0h] [ebp-38h] BYREF
  tagRECT rcDraw; // [esp+20h] [ebp-18h] BYREF
  _GRADIENT_RECT gradient_rect; // [esp+30h] [ebp-8h] BYREF

  m_x = this->m_x;
  *(_QWORD *)&rcDraw.left = *(_QWORD *)&rc->left;
  v11 = -this->m_y;
  *(_QWORD *)&rcDraw.right = *(_QWORD *)&rc->right;
  OffsetRect(lprc: &rcDraw, dx: -m_x, dy: v11);
  *(_QWORD *)&vert[0].x = *(_QWORD *)&rcDraw.left;
  v7 = clr1->_color[1];
  vert[0].Red = clr1->_color[0] << 8;
  v8 = clr1->_color[2] << 8;
  vert[0].Green = v7 << 8;
  vert[0].Blue = v8;
  vert[0].Alpha = 0;
  *(_QWORD *)&vert[1].x = *(_QWORD *)&rcDraw.right;
  v9 = clr2->_color[2];
  v10 = clr2->_color[1] << 8;
  vert[1].Red = clr2->_color[0] << 8;
  vert[1].Green = v10;
  vert[1].Blue = v9 << 8;
  vert[1].Alpha = 0;
  gradient_rect.UpperLeft = 0;
  gradient_rect.LowerRight = 1;
  GradientFill(hdc: this->m_dcMemory, pVertex: vert, nVertex: 2u, pMesh: &gradient_rect, nMesh: 1u, ulMode: vertical);
}

//------------------------------------------------------------------------------
// Address: 0x00492650
// Name: private: void CChoreoWidgetDrawHelper::Init(class mxWindow __near *,int,int,int,int,class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::Init(
        CChoreoWidgetDrawHelper *this,
        mxWindow *widget,
        int x,
        int y,
        int w,
        int h,
        const Color *bgColor,
        _BOOL2 noPageFlip)
{
  bool v8; // bl
  int v10; // eax
  int v11; // eax
  HWND__ *Handle; // eax
  HDC__ *DC; // eax
  int m_x; // ecx
  int m_y; // edx
  int v16; // edi
  int v17; // ecx
  HDC__ *CompatibleDC; // eax
  int m_h; // edx
  HDC__ *m_dcReal; // ecx
  HBITMAP__ *CompatibleBitmap; // eax
  COLORREF v22; // eax
  HBRUSH SolidBrush; // edi
  HDC__ *m_dcMemory; // [esp-8h] [ebp-24h]
  int v25; // [esp-8h] [ebp-24h]
  int v26; // [esp-4h] [ebp-20h]
  tagRECT rcFill; // [esp+Ch] [ebp-10h] BYREF
  Color noPageFlipa; // [esp+3Ch] [ebp+20h]

  v8 = noPageFlip;
  this->m_x = x;
  v10 = w;
  this->m_bNoPageFlip = noPageFlip;
  this->m_y = y;
  if ( w == 0 )
    v10 = mxWidget::w2(this: widget);
  this->m_w = v10;
  v11 = h;
  if ( h == 0 )
    v11 = mxWidget::h2(this: widget);
  this->m_h = v11;
  Handle = (HWND__ *)mxWidget::getHandle(this: widget);
  this->m_hWnd = Handle;
  DC = GetDC(hWnd: Handle);
  m_x = this->m_x;
  m_y = this->m_y;
  v16 = m_x + this->m_w;
  this->m_rcClient.left = m_x;
  v17 = m_y + this->m_h;
  this->m_dcReal = DC;
  this->m_rcClient.top = m_y;
  this->m_rcClient.right = v16;
  this->m_rcClient.bottom = v17;
  if ( noPageFlip )
  {
    this->m_dcMemory = DC;
    this->m_y = 0;
    this->m_x = 0;
  }
  else
  {
    CompatibleDC = CreateCompatibleDC(hdc: DC);
    m_h = this->m_h;
    m_dcReal = this->m_dcReal;
    this->m_dcMemory = CompatibleDC;
    CompatibleBitmap = CreateCompatibleBitmap(hdc: m_dcReal, cx: this->m_w, cy: m_h);
    m_dcMemory = this->m_dcMemory;
    this->m_bmMemory = CompatibleBitmap;
    this->m_bmOld = (HBITMAP__ *)SelectObject(hdc: m_dcMemory, h: CompatibleBitmap);
  }
  v22 = SetBkColor(hdc: this->m_dcMemory, color: bgColor->_color[0] | (*(unsigned __int16 *)&bgColor->_color[1] << 8));
  *(_WORD *)noPageFlipa._color = v22;
  *(_WORD *)&noPageFlipa._color[2] = BYTE2(v22);
  this->m_clrOld = noPageFlipa;
  v26 = -this->m_rcClient.top;
  v25 = -this->m_rcClient.left;
  rcFill = this->m_rcClient;
  OffsetRect(lprc: &rcFill, dx: v25, dy: v26);
  if ( !v8 )
  {
    SolidBrush = CreateSolidBrush(color: bgColor->_color[0] | (*(unsigned __int16 *)&bgColor->_color[1] << 8));
    FillRect(hDC: this->m_dcMemory, lprc: &rcFill, hbr: SolidBrush);
    DeleteObject(ho: SolidBrush);
  }
  this->m_ClipRegion = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004927B0
// Name: public: void CChoreoWidgetDrawHelper::DrawColoredTextW(struct HFONT__ __near *,class Color const __near &,struct tagRECT __near &,wchar_t const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CChoreoWidgetDrawHelper::DrawColoredTextW(
        CChoreoWidgetDrawHelper *this,
        HFONT__ *font,
        const Color *clr,
        tagRECT *rcText,
        const wchar_t *fmt,
        ...)
{
  HFONT__ *v6; // eax
  int v7; // edx
  COLORREF v8; // eax
  unsigned __int8 v9; // bl
  int v10; // eax
  int m_x; // ecx
  int v12; // [esp-4h] [ebp-24h]
  tagRECT rcTextOffset; // [esp+Ch] [ebp-14h] BYREF
  HFONT__ *oldFont; // [esp+1Ch] [ebp-4h]
  unsigned __int16 oldColor_1; // [esp+29h] [ebp+9h]
  int oldMode; // [esp+30h] [ebp+10h]
  va_list ap; // [esp+3Ch] [ebp+1Ch] BYREF

  va_start(ap, fmt);
  _vswprintf(string: output_6, format: fmt, ap);
  v6 = (HFONT__ *)SelectObject(hdc: this->m_dcMemory, h: font);
  v7 = clr->_color[1];
  oldFont = v6;
  v8 = SetTextColor(hdc: this->m_dcMemory, color: clr->_color[0] | ((v7 | (clr->_color[2] << 8)) << 8));
  LOBYTE(oldColor_1) = BYTE1(v8);
  v9 = v8;
  HIBYTE(oldColor_1) = BYTE2(v8);
  v10 = SetBkMode(hdc: this->m_dcMemory, mode: 1);
  m_x = this->m_x;
  oldMode = v10;
  *(_QWORD *)&rcTextOffset.left = *(_QWORD *)&rcText->left;
  v12 = -this->m_y;
  *(_QWORD *)&rcTextOffset.right = *(_QWORD *)&rcText->right;
  OffsetRect(lprc: &rcTextOffset, dx: -m_x, dy: v12);
  DrawTextW(hdc: this->m_dcMemory, lpchText: output_6, cchText: -1, lprc: &rcTextOffset, format: 0x40824u);
  SetBkMode(hdc: this->m_dcMemory, mode: oldMode);
  SetTextColor(hdc: this->m_dcMemory, color: v9 | (oldColor_1 << 8));
  SelectObject(hdc: this->m_dcMemory, h: oldFont);
}

//------------------------------------------------------------------------------
// Address: 0x004928B0
// Name: public: void CChoreoWidgetDrawHelper::DrawColoredTextCharset(char const __near *,int,int,unsigned long,class Color const __near &,struct tagRECT __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CChoreoWidgetDrawHelper::DrawColoredTextCharset(
        CChoreoWidgetDrawHelper *this,
        const char *font,
        Color pointsize,
        int weight,
        DWORD charset,
        const Color *clr,
        tagRECT *rcText,
        const char *fmt,
        ...)
{
  HFONT FontA; // edi
  HFONT__ *v10; // eax
  int v11; // edx
  COLORREF v12; // eax
  unsigned __int8 v13; // bl
  int v14; // eax
  int m_x; // ecx
  int v16; // [esp-4h] [ebp-24h]
  tagRECT rcTextOffset; // [esp+Ch] [ebp-14h] BYREF
  HFONT__ *oldFont; // [esp+1Ch] [ebp-4h]
  int oldMode; // [esp+28h] [ebp+8h]
  unsigned __int16 oldColor_1; // [esp+31h] [ebp+11h]
  va_list ap; // [esp+48h] [ebp+28h] BYREF

  va_start(ap, fmt);
  vsprintf(string: output_7, format: fmt, ap);
  FontA = CreateFontA(
            cHeight: -*(int *)&pointsize,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: weight,
            bItalic: 0,
            bUnderline: 0,
            bStrikeOut: 0,
            iCharSet: charset,
            iOutPrecision: 4u,
            iClipPrecision: 0,
            iQuality: 4u,
            iPitchAndFamily: 0,
            pszFaceName: font);
  v10 = (HFONT__ *)SelectObject(hdc: this->m_dcMemory, h: FontA);
  v11 = clr->_color[1];
  oldFont = v10;
  v12 = SetTextColor(hdc: this->m_dcMemory, color: clr->_color[0] | ((v11 | (clr->_color[2] << 8)) << 8));
  LOBYTE(oldColor_1) = BYTE1(v12);
  v13 = v12;
  HIBYTE(oldColor_1) = BYTE2(v12);
  v14 = SetBkMode(hdc: this->m_dcMemory, mode: 1);
  m_x = this->m_x;
  oldMode = v14;
  *(_QWORD *)&rcTextOffset.left = *(_QWORD *)&rcText->left;
  v16 = -this->m_y;
  *(_QWORD *)&rcTextOffset.right = *(_QWORD *)&rcText->right;
  OffsetRect(lprc: &rcTextOffset, dx: -m_x, dy: v16);
  DrawTextA(hdc: this->m_dcMemory, lpchText: output_7, cchText: -1, lprc: &rcTextOffset, format: 0x40824u);
  SetBkMode(hdc: this->m_dcMemory, mode: oldMode);
  SetTextColor(hdc: this->m_dcMemory, color: v13 | (oldColor_1 << 8));
  SelectObject(hdc: this->m_dcMemory, h: oldFont);
  DeleteObject(ho: FontA);
}

//------------------------------------------------------------------------------
// Address: 0x004929E0
// Name: public: void CChoreoWidgetDrawHelper::DrawColoredTextCharsetW(char const __near *,int,int,unsigned long,class Color const __near &,struct tagRECT __near &,wchar_t const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CChoreoWidgetDrawHelper::DrawColoredTextCharsetW(
        CChoreoWidgetDrawHelper *this,
        const char *font,
        Color pointsize,
        int weight,
        DWORD charset,
        const Color *clr,
        tagRECT *rcText,
        const wchar_t *fmt,
        ...)
{
  HFONT FontA; // edi
  HFONT__ *v10; // eax
  int v11; // edx
  COLORREF v12; // eax
  unsigned __int8 v13; // bl
  int v14; // eax
  int m_x; // ecx
  int v16; // [esp-4h] [ebp-24h]
  tagRECT rcTextOffset; // [esp+Ch] [ebp-14h] BYREF
  HFONT__ *oldFont; // [esp+1Ch] [ebp-4h]
  int oldMode; // [esp+28h] [ebp+8h]
  unsigned __int16 oldColor_1; // [esp+31h] [ebp+11h]
  va_list ap; // [esp+48h] [ebp+28h] BYREF

  va_start(ap, fmt);
  _vswprintf(string: output_8, format: fmt, ap);
  FontA = CreateFontA(
            cHeight: -*(int *)&pointsize,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: weight,
            bItalic: 0,
            bUnderline: 0,
            bStrikeOut: 0,
            iCharSet: charset,
            iOutPrecision: 4u,
            iClipPrecision: 0,
            iQuality: 4u,
            iPitchAndFamily: 0,
            pszFaceName: font);
  v10 = (HFONT__ *)SelectObject(hdc: this->m_dcMemory, h: FontA);
  v11 = clr->_color[1];
  oldFont = v10;
  v12 = SetTextColor(hdc: this->m_dcMemory, color: clr->_color[0] | ((v11 | (clr->_color[2] << 8)) << 8));
  LOBYTE(oldColor_1) = BYTE1(v12);
  v13 = v12;
  HIBYTE(oldColor_1) = BYTE2(v12);
  v14 = SetBkMode(hdc: this->m_dcMemory, mode: 1);
  m_x = this->m_x;
  oldMode = v14;
  *(_QWORD *)&rcTextOffset.left = *(_QWORD *)&rcText->left;
  v16 = -this->m_y;
  *(_QWORD *)&rcTextOffset.right = *(_QWORD *)&rcText->right;
  OffsetRect(lprc: &rcTextOffset, dx: -m_x, dy: v16);
  DrawTextW(hdc: this->m_dcMemory, lpchText: output_8, cchText: -1, lprc: &rcTextOffset, format: 0x40824u);
  SetBkMode(hdc: this->m_dcMemory, mode: oldMode);
  SetTextColor(hdc: this->m_dcMemory, color: v13 | (oldColor_1 << 8));
  SelectObject(hdc: this->m_dcMemory, h: oldFont);
  DeleteObject(ho: FontA);
}

//------------------------------------------------------------------------------
// Address: 0x00492B10
// Name: public: void CChoreoWidgetDrawHelper::DrawColoredTextMultiline(char const __near *,int,int,class Color const __near &,struct tagRECT __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CChoreoWidgetDrawHelper::DrawColoredTextMultiline(
        CChoreoWidgetDrawHelper *this,
        const char *font,
        Color pointsize,
        int weight,
        const Color *clr,
        tagRECT *rcText,
        const char *fmt,
        ...)
{
  HFONT FontA; // edi
  HFONT__ *v9; // eax
  int v10; // edx
  COLORREF v11; // eax
  unsigned __int8 v12; // bl
  int v13; // eax
  int m_x; // ecx
  int v15; // [esp-4h] [ebp-24h]
  tagRECT rcTextOffset; // [esp+Ch] [ebp-14h] BYREF
  HFONT__ *oldFont; // [esp+1Ch] [ebp-4h]
  int oldMode; // [esp+28h] [ebp+8h]
  unsigned __int16 oldColor_1; // [esp+31h] [ebp+11h]
  va_list ap; // [esp+44h] [ebp+24h] BYREF

  va_start(ap, fmt);
  vprintf(format: fmt, ap);
  vsprintf(string: output_9, format: fmt, ap);
  FontA = CreateFontA(
            cHeight: -*(int *)&pointsize,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: weight,
            bItalic: 0,
            bUnderline: 0,
            bStrikeOut: 0,
            iCharSet: 0,
            iOutPrecision: 4u,
            iClipPrecision: 0,
            iQuality: 4u,
            iPitchAndFamily: 0,
            pszFaceName: font);
  v9 = (HFONT__ *)SelectObject(hdc: this->m_dcMemory, h: FontA);
  v10 = clr->_color[1];
  oldFont = v9;
  v11 = SetTextColor(hdc: this->m_dcMemory, color: clr->_color[0] | ((v10 | (clr->_color[2] << 8)) << 8));
  LOBYTE(oldColor_1) = BYTE1(v11);
  v12 = v11;
  HIBYTE(oldColor_1) = BYTE2(v11);
  v13 = SetBkMode(hdc: this->m_dcMemory, mode: 1);
  m_x = this->m_x;
  oldMode = v13;
  *(_QWORD *)&rcTextOffset.left = *(_QWORD *)&rcText->left;
  v15 = -this->m_y;
  *(_QWORD *)&rcTextOffset.right = *(_QWORD *)&rcText->right;
  OffsetRect(lprc: &rcTextOffset, dx: -m_x, dy: v15);
  DrawTextA(hdc: this->m_dcMemory, lpchText: output_9, cchText: -1, lprc: &rcTextOffset, format: 0x40814u);
  SetBkMode(hdc: this->m_dcMemory, mode: oldMode);
  SetTextColor(hdc: this->m_dcMemory, color: v12 | (oldColor_1 << 8));
  SelectObject(hdc: this->m_dcMemory, h: oldFont);
  DeleteObject(ho: FontA);
}

//------------------------------------------------------------------------------
// Address: 0x00492C50
// Name: public: void CChoreoWidgetDrawHelper::DrawFilledRect(class Color const __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawFilledRect(CChoreoWidgetDrawHelper *this, const Color *clr, tagRECT *rc)
{
  int v4; // edx
  HBRUSH SolidBrush; // edi
  COLORREF v6; // [esp-Ch] [ebp-1Ch]
  tagRECT rcCopy; // [esp+0h] [ebp-10h] BYREF

  v4 = clr->_color[1];
  *(_QWORD *)&rcCopy.left = *(_QWORD *)&rc->left;
  v6 = clr->_color[0] | ((v4 | (clr->_color[2] << 8)) << 8);
  *(_QWORD *)&rcCopy.right = *(_QWORD *)&rc->right;
  SolidBrush = CreateSolidBrush(color: v6);
  OffsetRect(lprc: &rcCopy, dx: -this->m_x, dy: -this->m_y);
  FillRect(hDC: this->m_dcMemory, lprc: &rcCopy, hbr: SolidBrush);
  DeleteObject(ho: SolidBrush);
}

//------------------------------------------------------------------------------
// Address: 0x00492CD0
// Name: public: void CChoreoWidgetDrawHelper::DrawFilledRect(class Color const __near &,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawFilledRect(
        CChoreoWidgetDrawHelper *this,
        const Color *clr,
        int x1,
        int y1,
        int x2,
        int y2)
{
  HBRUSH SolidBrush; // edi
  int m_y; // eax
  int m_x; // ecx
  tagRECT rc; // [esp+8h] [ebp-10h] BYREF

  SolidBrush = CreateSolidBrush(color: clr->_color[0] | (*(unsigned __int16 *)&clr->_color[1] << 8));
  rc.right = x2;
  m_y = this->m_y;
  rc.top = y1;
  m_x = this->m_x;
  rc.left = x1;
  rc.bottom = y2;
  OffsetRect(lprc: &rc, dx: -m_x, dy: -m_y);
  FillRect(hDC: this->m_dcMemory, lprc: &rc, hbr: SolidBrush);
  DeleteObject(ho: SolidBrush);
}

//------------------------------------------------------------------------------
// Address: 0x00492D50
// Name: public: void CChoreoWidgetDrawHelper::DrawOutlinedRect(class Color const __near &,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawOutlinedRect(
        CChoreoWidgetDrawHelper *this,
        HBRUSH__ *clr,
        int style,
        HBRUSH__ *width,
        int x1,
        int y1,
        int x2,
        int y2)
{
  HPEN Pen; // ebx
  int m_y; // eax
  int m_x; // ecx
  tagRECT rc; // [esp+Ch] [ebp-14h] BYREF
  HPEN__ *oldpen; // [esp+1Ch] [ebp-4h]
  HBRUSH__ *oldbrush; // [esp+28h] [ebp+8h]
  HBRUSH__ *brush; // [esp+30h] [ebp+10h]

  Pen = CreatePen(iStyle: 0, cWidth: (int)width, color: *(_BYTE *)clr | (*(unsigned __int16 *)((char *)clr + 1) << 8));
  oldpen = (HPEN__ *)SelectObject(hdc: this->m_dcMemory, h: Pen);
  brush = (HBRUSH__ *)GetStockObject(i: 5);
  oldbrush = (HBRUSH__ *)SelectObject(hdc: this->m_dcMemory, h: brush);
  rc.right = x2;
  m_y = this->m_y;
  rc.top = y1;
  m_x = this->m_x;
  rc.left = x1;
  rc.bottom = y2;
  OffsetRect(lprc: &rc, dx: -m_x, dy: -m_y);
  Rectangle(hdc: this->m_dcMemory, left: rc.left, top: rc.top, right: rc.right, bottom: rc.bottom);
  SelectObject(hdc: this->m_dcMemory, h: oldbrush);
  DeleteObject(ho: brush);
  SelectObject(hdc: this->m_dcMemory, h: oldpen);
  DeleteObject(ho: Pen);
}

//------------------------------------------------------------------------------
// Address: 0x00492E20
// Name: public: void CChoreoWidgetDrawHelper::DrawColoredText(char const __near *,int,int,class Color const __near &,struct tagRECT __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CChoreoWidgetDrawHelper::DrawColoredText(
        CChoreoWidgetDrawHelper *this,
        const char *font,
        int pointsize,
        int weight,
        const Color *clr,
        tagRECT *rcText,
        const char *fmt,
        ...)
{
  va_list ap; // [esp+24h] [ebp+24h] BYREF

  va_start(ap, fmt);
  vsprintf(string: output_10, format: fmt, ap);
  CChoreoWidgetDrawHelper::DrawColoredTextCharset(
    this,
    font,
    (Color)pointsize,
    weight,
    charset: 0,
    clr,
    rcText,
    fmt: output_10);
}

//------------------------------------------------------------------------------
// Address: 0x00492E60
// Name: public: void CChoreoWidgetDrawHelper::DrawColoredTextW(char const __near *,int,int,class Color const __near &,struct tagRECT __near &,wchar_t const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CChoreoWidgetDrawHelper::DrawColoredTextW(
        CChoreoWidgetDrawHelper *this,
        const char *font,
        int pointsize,
        int weight,
        const Color *clr,
        tagRECT *rcText,
        const wchar_t *fmt,
        ...)
{
  va_list ap; // [esp+24h] [ebp+24h] BYREF

  va_start(ap, fmt);
  _vswprintf(string: output_11, format: fmt, ap);
  CChoreoWidgetDrawHelper::DrawColoredTextCharsetW(
    this,
    font,
    (Color)pointsize,
    weight,
    charset: 0,
    clr,
    rcText,
    fmt: output_11);
}

//------------------------------------------------------------------------------
// Address: 0x00492EA0
// Name: public: void CChoreoWidgetDrawHelper::DrawColoredPolyLine(class Color const __near &,int,int,class CUtlVector<struct tagPOINT,class CUtlMemory<struct tagPOINT,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawColoredPolyLine(
        CChoreoWidgetDrawHelper *this,
        HPEN__ *clr,
        int style,
        HPEN__ *width,
        CUtlVector<tagPOINT,CUtlMemory<tagPOINT,int> > *points)
{
  int m_Size; // ebx
  void *v7; // esp
  int i; // edx
  tagPOINT *m_pMemory; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ebx
  POINT v13; // [esp+0h] [ebp-10h] BYREF
  int c; // [esp+Ch] [ebp-4h]
  HPEN__ *oldPen; // [esp+18h] [ebp+8h]
  HPEN__ *pen; // [esp+20h] [ebp+10h]

  m_Size = points->m_Size;
  c = m_Size;
  if ( m_Size >= 2 )
  {
    pen = CreatePen(
            iStyle: style,
            cWidth: (int)width,
            color: *(_BYTE *)clr | (*(unsigned __int16 *)((char *)clr + 1) << 8));
    oldPen = (HPEN__ *)SelectObject(hdc: this->m_dcMemory, h: pen);
    v7 = alloca(8 * m_Size);
    for ( i = 0; i < v12; ++i )
    {
      m_pMemory = points->m_Memory.m_pMemory;
      v10 = 8 * i;
      *(int *)((char *)&v13.x + v10) = points->m_Memory.m_pMemory[i].x - this->m_x;
      v11 = m_pMemory[i].y - this->m_y;
      v12 = c;
      *(int *)((char *)&v13.y + v10) = v11;
    }
    Polyline(hdc: this->m_dcMemory, apt: &v13, cpt: v12);
    SelectObject(hdc: this->m_dcMemory, h: oldPen);
    DeleteObject(ho: pen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00492F60
// Name: public: void CChoreoWidgetDrawHelper::DrawOutlinedRect(class Color const __near &,int,int,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::DrawOutlinedRect(
        CChoreoWidgetDrawHelper *this,
        Color *clr,
        int style,
        HBRUSH__ *width,
        tagRECT *rc)
{
  CChoreoWidgetDrawHelper::DrawOutlinedRect(
    this,
    (HBRUSH__ *)clr,
    style,
    width,
    x1: rc->left,
    y1: rc->top,
    x2: rc->right,
    y2: rc->bottom);
}

//------------------------------------------------------------------------------
// Address: 0x00492F90
// Name: private: void CChoreoWidgetDrawHelper::ClipToRects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::ClipToRects(CChoreoWidgetDrawHelper *this)
{
  HRGN (__stdcall *v2)(int, int, int, int); // ebx
  HRGN v3; // edi
  HRGN__ *v4; // ebx
  int i; // [esp+14h] [ebp-8h]
  int v6; // [esp+18h] [ebp-4h]

  SelectClipRgn(hdc: this->m_dcMemory, hrgn: nullptr);
  if ( this->m_ClipRegion != nullptr )
  {
    DeleteObject(ho: this->m_ClipRegion);
    this->m_ClipRegion = nullptr;
  }
  if ( this->m_ClipRects.m_Size > 0 )
  {
    v2 = CreateRectRgn;
    this->m_ClipRegion = CreateRectRgn(
                           x1: this->m_ClipRects.m_Memory.m_pMemory->left,
                           y1: this->m_ClipRects.m_Memory.m_pMemory->top,
                           x2: this->m_ClipRects.m_Memory.m_pMemory->right,
                           y2: this->m_ClipRects.m_Memory.m_pMemory->bottom);
    i = 1;
    if ( this->m_ClipRects.m_Size > 1 )
    {
      v6 = 1;
      while ( 1 )
      {
        v3 = v2(
               x1: this->m_ClipRects.m_Memory.m_pMemory[v6].left,
               y1: this->m_ClipRects.m_Memory.m_pMemory[v6].top,
               x2: this->m_ClipRects.m_Memory.m_pMemory[v6].right,
               y2: this->m_ClipRects.m_Memory.m_pMemory[v6].bottom);
        v4 = v2(x1: 0, y1: 0, x2: 100, y2: 100);
        CombineRgn(hrgnDst: v4, hrgnSrc1: this->m_ClipRegion, hrgnSrc2: v3, iMode: 1);
        DeleteObject(ho: this->m_ClipRegion);
        DeleteObject(ho: v3);
        ++v6;
        this->m_ClipRegion = v4;
        if ( ++i >= this->m_ClipRects.m_Size )
          break;
        v2 = CreateRectRgn;
      }
    }
  }
  SelectClipRgn(hdc: this->m_dcMemory, hrgn: this->m_ClipRegion);
}

//------------------------------------------------------------------------------
// Address: 0x004930A0
// Name: public: void CChoreoWidgetDrawHelper::StopClipping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::StopClipping(CChoreoWidgetDrawHelper *this)
{
  if ( this->m_ClipRects.m_Size > 0 )
  {
    --this->m_ClipRects.m_Size;
    CChoreoWidgetDrawHelper::ClipToRects(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004930E0
// Name: public: int CUtlVector<struct tagRECT,class CUtlMemory<struct tagRECT,int>>::InsertBefore(int,struct tagRECT const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<tagRECT,CUtlMemory<tagRECT,int>>::InsertBefore(
        CUtlVector<tagRECT,CUtlMemory<tagRECT,int> > *this,
        int elem,
        const tagRECT *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  tagRECT *m_pMemory; // ecx
  int v7; // eax
  tagRECT *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SceneImageEntry_t,int>::Grow(
      (CUtlMemory<SceneImageEntry_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00493160
// Name: public: CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoWidgetDrawHelper *__thiscall CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
        CChoreoWidgetDrawHelper *this,
        mxWindow *widget)
{
  Color bgColor; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (CChoreoWidgetDrawHelper_vtbl *)&CChoreoWidgetDrawHelper::`vftable';
  this->m_clrOld = 0;
  this->m_ClipRects.m_Memory.m_pMemory = nullptr;
  this->m_ClipRects.m_Memory.m_nAllocationCount = 0;
  this->m_ClipRects.m_Memory.m_nGrowSize = 0;
  this->m_ClipRects.m_Size = 0;
  this->m_ClipRects.m_pElements = nullptr;
  bgColor = (Color)14479600;
  CChoreoWidgetDrawHelper::Init(this, widget, x: 0, y: 0, w: 0, h: 0, &bgColor, noPageFlip: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004931B0
// Name: public: CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(class mxWindow __near *,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
CChoreoWidgetDrawHelper *__thiscall CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
        CChoreoWidgetDrawHelper *this,
        mxWindow *widget,
        const Color *bgColor)
{
  this->__vftable = (CChoreoWidgetDrawHelper_vtbl *)&CChoreoWidgetDrawHelper::`vftable';
  this->m_clrOld = 0;
  this->m_ClipRects.m_Memory.m_pMemory = nullptr;
  this->m_ClipRects.m_Memory.m_nAllocationCount = 0;
  this->m_ClipRects.m_Memory.m_nGrowSize = 0;
  this->m_ClipRects.m_Size = 0;
  this->m_ClipRects.m_pElements = nullptr;
  CChoreoWidgetDrawHelper::Init(this, widget, x: 0, y: 0, w: 0, h: 0, bgColor, noPageFlip: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004931F0
// Name: public: CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(class mxWindow __near *,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
CChoreoWidgetDrawHelper *__thiscall CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
        CChoreoWidgetDrawHelper *this,
        mxWindow *widget,
        tagRECT *bounds)
{
  int left; // [esp-18h] [ebp-24h]
  int top; // [esp-14h] [ebp-20h]
  int v7; // [esp-10h] [ebp-1Ch]
  int v8; // [esp-Ch] [ebp-18h]
  Color bgColor; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (CChoreoWidgetDrawHelper_vtbl *)&CChoreoWidgetDrawHelper::`vftable';
  this->m_clrOld = 0;
  this->m_ClipRects.m_Memory.m_pMemory = nullptr;
  this->m_ClipRects.m_Memory.m_nAllocationCount = 0;
  this->m_ClipRects.m_Memory.m_nGrowSize = 0;
  this->m_ClipRects.m_Size = 0;
  this->m_ClipRects.m_pElements = nullptr;
  v8 = bounds->bottom - bounds->top;
  v7 = bounds->right - bounds->left;
  top = bounds->top;
  left = bounds->left;
  bgColor = (Color)14479600;
  CChoreoWidgetDrawHelper::Init(this, widget, x: left, y: top, w: v7, h: v8, &bgColor, noPageFlip: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00493250
// Name: public: CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(class mxWindow __near *,struct tagRECT __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CChoreoWidgetDrawHelper *__thiscall CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
        CChoreoWidgetDrawHelper *this,
        mxWindow *widget,
        tagRECT *bounds,
        _BOOL2 noPageFlip)
{
  int left; // [esp-18h] [ebp-24h]
  int top; // [esp-14h] [ebp-20h]
  int v8; // [esp-10h] [ebp-1Ch]
  int v9; // [esp-Ch] [ebp-18h]
  Color bgColor; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (CChoreoWidgetDrawHelper_vtbl *)&CChoreoWidgetDrawHelper::`vftable';
  this->m_clrOld = 0;
  this->m_ClipRects.m_Memory.m_pMemory = nullptr;
  this->m_ClipRects.m_Memory.m_nAllocationCount = 0;
  this->m_ClipRects.m_Memory.m_nGrowSize = 0;
  this->m_ClipRects.m_Size = 0;
  this->m_ClipRects.m_pElements = nullptr;
  v9 = bounds->bottom - bounds->top;
  v8 = bounds->right - bounds->left;
  top = bounds->top;
  left = bounds->left;
  bgColor = (Color)14479600;
  CChoreoWidgetDrawHelper::Init(this, widget, x: left, y: top, w: v8, h: v9, &bgColor, noPageFlip);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004932B0
// Name: public: CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(class mxWindow __near *,struct tagRECT __near &,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
CChoreoWidgetDrawHelper *__thiscall CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
        CChoreoWidgetDrawHelper *this,
        mxWindow *widget,
        tagRECT *bounds,
        const Color *bgColor)
{
  this->__vftable = (CChoreoWidgetDrawHelper_vtbl *)&CChoreoWidgetDrawHelper::`vftable';
  this->m_clrOld = 0;
  this->m_ClipRects.m_Memory.m_pMemory = nullptr;
  this->m_ClipRects.m_Memory.m_nAllocationCount = 0;
  this->m_ClipRects.m_Memory.m_nGrowSize = 0;
  this->m_ClipRects.m_Size = 0;
  this->m_ClipRects.m_pElements = nullptr;
  CChoreoWidgetDrawHelper::Init(
    this,
    widget,
    x: bounds->left,
    y: bounds->top,
    w: bounds->right - bounds->left,
    h: bounds->bottom - bounds->top,
    bgColor,
    noPageFlip: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00493300
// Name: public: virtual CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(CChoreoWidgetDrawHelper *this)
{
  HDC__ *m_dcMemory; // [esp-8h] [ebp-10h]

  m_dcMemory = this->m_dcMemory;
  this->__vftable = (CChoreoWidgetDrawHelper_vtbl *)&CChoreoWidgetDrawHelper::`vftable';
  SelectClipRgn(hdc: m_dcMemory, hrgn: nullptr);
  while ( this->m_ClipRects.m_Size > 0 )
  {
    if ( this->m_ClipRects.m_Size > 0 )
    {
      --this->m_ClipRects.m_Size;
      CChoreoWidgetDrawHelper::ClipToRects(this);
    }
  }
  if ( !this->m_bNoPageFlip )
  {
    BitBlt(
      hdc: this->m_dcReal,
      x: this->m_x,
      y: this->m_y,
      cx: this->m_w,
      cy: this->m_h,
      hdcSrc: this->m_dcMemory,
      x1: 0,
      y1: 0,
      rop: 0xCC0020u);
    SetBkColor(
      hdc: this->m_dcMemory,
      color: this->m_clrOld._color[0] | (*(unsigned __int16 *)&this->m_clrOld._color[1] << 8));
    SelectObject(hdc: this->m_dcMemory, h: this->m_bmOld);
    DeleteObject(ho: this->m_bmMemory);
    DeleteObject(ho: this->m_dcMemory);
  }
  ReleaseDC(hWnd: this->m_hWnd, hDC: this->m_dcReal);
  ValidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rcClient);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ClipRects);
}

//------------------------------------------------------------------------------
// Address: 0x00493420
// Name: public: void CChoreoWidgetDrawHelper::StartClipping(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidgetDrawHelper::StartClipping(CChoreoWidgetDrawHelper *this, tagRECT *clipRect)
{
  int m_x; // ecx
  int v4; // [esp-8h] [ebp-18h]
  tagRECT fixed; // [esp+0h] [ebp-10h] BYREF

  m_x = this->m_x;
  *(_QWORD *)&fixed.left = *(_QWORD *)&clipRect->left;
  v4 = -this->m_y;
  *(_QWORD *)&fixed.right = *(_QWORD *)&clipRect->right;
  OffsetRect(lprc: &fixed, dx: -m_x, dy: v4);
  CUtlVector<tagRECT,CUtlMemory<tagRECT,int>>::InsertBefore(
    this: &this->m_ClipRects,
    elem: this->m_ClipRects.m_Size,
    src: &fixed);
  CChoreoWidgetDrawHelper::ClipToRects(this);
}

//------------------------------------------------------------------------------
// Address: 0x004936A0
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
// Address: 0x00493D20
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
// Address: 0x00493E90
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
// Address: 0x00494540
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
// Address: 0x0049B7D0
// Name: public: void CUtlMemory<struct ikcontextikrule_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ikcontextikrule_t,int>::Grow(CUtlMemory<ikcontextikrule_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ikcontextikrule_t *m_pMemory; // edx
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
    v7 = 132 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ikcontextikrule_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ikcontextikrule_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049C0A0
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::InsertMultipleBefore(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ikcontextikrule_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 132 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0049CCF0
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::AddToTail(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  ikcontextikrule_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 132 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004A5E40
// Name: public: void CUtlMemory<struct fileList_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<fileList_t,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CChoreoScene::ActiveList,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CChoreoScene::ActiveList,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CChoreoScene::ActiveList,int> *)_g_pMemAlloc->Realloc_2(
                                                                           this: _g_pMemAlloc,
                                                                           a2: m_pMemory,
                                                                           a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CChoreoScene::ActiveList,int> *)_g_pMemAlloc->Alloc_2(
                                                                           this: _g_pMemAlloc,
                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A73A0
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
// Address: 0x004AD1B0
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
// Address: 0x004AF3C0
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
      (CUtlMemory<UtlRBTreeNode_t<CChoreoScene::ActiveList,int>,int> *)this,
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
// Address: 0x004AF450
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
// Address: 0x004AF4F0
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
// Address: 0x004B04D0
// Name: public: void CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::Remove(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this,
        int elem)
{
  int v3; // ecx
  CEventRelativeTag *v4; // esi
  bool v5; // sf

  v3 = elem;
  v4 = &this->m_Memory.m_pMemory[elem];
  v5 = v4->m_Name.m_Storage.m_Memory.m_nGrowSize < 0;
  v4->m_Name.m_Storage.m_nActualLength = 0;
  if ( !v5 )
  {
    if ( v4->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Name.m_Storage.m_Memory.m_pMemory);
      v3 = elem;
      v4->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v4->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - v3 - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 24 * (this->m_Size - v3 - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B0550
// Name: public: void CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::Remove(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this,
        int elem)
{
  int v3; // ecx
  CEventAbsoluteTag *v4; // esi
  bool v5; // sf

  v3 = elem;
  v4 = &this->m_Memory.m_pMemory[elem];
  v5 = v4->m_Name.m_Storage.m_Memory.m_nGrowSize < 0;
  v4->m_Name.m_Storage.m_nActualLength = 0;
  if ( !v5 )
  {
    if ( v4->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Name.m_Storage.m_Memory.m_pMemory);
      v3 = elem;
      v4->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v4->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - v3 - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 28 * (this->m_Size - v3 - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B05E0
// Name: public: void CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::RemoveAll(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CEventAbsoluteTag *v3; // esi
  CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B1A00
// Name: public: CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::~CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::~CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>(
        CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int> > *this)
{
  bool v2; // sf
  CFlexTimingTag *m_pMemory; // eax

  CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::RemoveAll((CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *)this);
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
// Address: 0x004B2570
// Name: public: void CUtlMemory<struct SceneFile_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SceneFile_t,int>::Grow(CUtlMemory<SceneFile_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SceneFile_t *m_pMemory; // edx
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
    v7 = 96 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SceneFile_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SceneFile_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B26C0
// Name: public: int CUtlVector<short,class CUtlMemory<short,int>>::Find(short const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<short,CUtlMemory<short,int>>::Find(
        CUtlVector<short,CUtlMemory<short,int> > *this,
        const __int16 *src)
{
  int m_Size; // edx
  int result; // eax
  __int16 *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B2BB0
// Name: public: int CUtlVector<struct SceneFile_t,class CUtlMemory<struct SceneFile_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::InsertBefore(
        CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SceneFile_t *m_pMemory; // ecx
  int v6; // eax
  SceneFile_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SceneFile_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 96 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &v7->fileName);
    CUtlBuffer::CUtlBuffer(this: &v7->compiledBuffer, growSize: 0, initSize: 0, nFlags: 0);
    v7->soundList.m_Memory.m_pMemory = nullptr;
    v7->soundList.m_Memory.m_nAllocationCount = 0;
    v7->soundList.m_Memory.m_nGrowSize = 0;
    v7->soundList.m_Size = 0;
    v7->soundList.m_pElements = nullptr;
    v7->msecs = 0;
    v7->lastspeak_msecs = 0;
    v7->crcFileName = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004B2CA0
// Name: public: void CUtlVector<struct SceneFile_t,class CUtlMemory<struct SceneFile_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::RemoveAll(
        CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 96 * v1;
    v6 = 96 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 22) = 0;
      if ( *((int *)v3 + 21) >= 0 )
      {
        if ( *((_DWORD *)v3 + 19) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 19));
          *((_DWORD *)v3 + 19) = 0;
        }
        *((_DWORD *)v3 + 20) = 0;
      }
      v4 = *((void **)v3 + 19);
      *((_DWORD *)v3 + 23) = v4;
      if ( *((int *)v3 + 21) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 19) = 0;
        }
        *((_DWORD *)v3 + 20) = 0;
      }
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      this = v5;
      --v1;
      v2 = v6 - 96;
      v6 -= 96;
    }
    while ( v1 >= 0 );
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B41D0
// Name: public: CUtlVector<struct SceneFile_t,class CUtlMemory<struct SceneFile_t,int>>::~CUtlVector<struct SceneFile_t,class CUtlMemory<struct SceneFile_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::~CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>(
        CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int> > *this)
{
  bool v2; // sf
  SceneFile_t *m_pMemory; // eax

  CUtlVector<SceneFile_t,CUtlMemory<SceneFile_t,int>>::RemoveAll(this);
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
