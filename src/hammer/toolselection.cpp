// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolselection.cpp
// Functions: 425
// ============================================================

#include "hammer\toolselection.h"

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: public: void CUtlMemory<class CAnchorDef,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CAnchorDef,int>::Grow(CUtlMemory<CAnchorDef,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CAnchorDef *m_pMemory; // ecx
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
      this->m_pMemory = (CAnchorDef *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (CAnchorDef *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: public: int CUtlVector<class CAnchorDef,class CUtlMemory<class CAnchorDef,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int>>::InsertMultipleBefore(
        CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAnchorDef *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CAnchorDef,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 44 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = 44 * elem;
      do
      {
        v10 += 44;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: void CUtlVector<class CAnchorDef,class CUtlMemory<class CAnchorDef,int>>::CopyArray(class CAnchorDef const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int>>::CopyArray(
        CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *this,
        const CAnchorDef *pArray,
        int size)
{
  int v4; // edx
  int v5; // ecx
  CAnchorDef *v6; // eax
  HWND__ *m_hWnd; // ebx

  this->m_Size = 0;
  CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  if ( size > 0 )
  {
    v4 = size;
    v5 = 0;
    do
    {
      v6 = &this->m_Memory.m_pMemory[v5];
      *(_QWORD *)&v6->m_DlgItemID = *(_QWORD *)&pArray[v5].m_DlgItemID;
      *(_QWORD *)&v6->m_AnchorLeft = *(_QWORD *)&pArray[v5].m_AnchorLeft;
      *(_QWORD *)&v6->m_AnchorTop = *(_QWORD *)&pArray[v5].m_AnchorTop;
      *(_OWORD *)v6->m_OriginalPos = *(_OWORD *)pArray[v5].m_OriginalPos;
      m_hWnd = pArray[v5++].m_hWnd;
      --v4;
      v6->m_hWnd = m_hWnd;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003170
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::SetSize(CUtlVector<char,CUtlMemory<char,int> > *this, int size)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ECE0
// Name: protected: void CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>::ShiftElementsRight(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::ShiftElementsRight(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + num) >> (*((int *)&this->m_Memory + 2) >> 27)][(elem + num)
                                                                                     & ((32
                                                                                       * *((_DWORD *)&this->m_Memory + 2)) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                             & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)],
      count: 12 * (this->m_Size - elem - num));
}

//------------------------------------------------------------------------------
// Address: 0x10010780
// Name: public: int CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int v5; // ebx
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  CUtlReference<CMapClass> *v9; // eax

  if ( num != 0 )
  {
    m_Size = this->m_Size;
    v5 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
    v6 = v5 * this->m_Memory.m_nBlocks;
    if ( m_Size + num > v6 )
    {
      v7 = num + m_Size - v6;
      if ( v7 > 0 )
        CUtlBlockMemory<CUtlReference<CMapEntity>,int>::ChangeSize(
          this: &this->m_Memory,
          nBlocks: (v5 + v7 - 1) / v5 + this->m_Memory.m_nBlocks);
    }
    this->m_Size += num;
    this->m_pElements = nullptr;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::ShiftElementsRight(
      this,
      elem,
      num);
    if ( num > 0 )
    {
      v8 = elem;
      do
      {
        v9 = &this->m_Memory.m_pMemory[v8 >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][v8 & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
        if ( v9 != nullptr )
        {
          v9->m_pPrev = nullptr;
          v9->m_pNext = nullptr;
          v9->m_pObject = nullptr;
        }
        ++v8;
        --num;
      }
      while ( num != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100113D0
// Name: public: void CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this)
{
  int v2; // esi
  CUtlReference<CMapClass> *v3; // eax
  CMapClass *m_pObject; // ecx
  CUtlReference<CMapClass> *m_pPrev; // edx
  CUtlReference<CMapClass> *m_pNext; // edx

  v2 = this->m_Size - 1;
  if ( v2 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][v2 & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
      m_pObject = v3->m_pObject;
      if ( m_pObject != nullptr )
      {
        m_pPrev = v3->m_pPrev;
        if ( m_pPrev != nullptr )
        {
          m_pPrev->m_pNext = v3->m_pNext;
          if ( v3->m_pNext != nullptr )
            v3->m_pNext->m_pPrev = v3->m_pPrev;
        }
        else if ( m_pObject->m_References.m_pHead == v3 )
        {
          m_pNext = v3->m_pNext;
          m_pObject->m_References.m_pHead = v3->m_pNext;
          if ( m_pNext != nullptr )
            m_pNext->m_pPrev = nullptr;
        }
        v3->m_pPrev = nullptr;
        v3->m_pNext = nullptr;
        v3->m_pObject = nullptr;
      }
      --v2;
    }
    while ( v2 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100136B0
// Name: public: class CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>> __near & CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>::operator=(class CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *__thiscall CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::operator=(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this,
        const CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *other)
{
  int m_Size; // edi
  int v4; // esi
  CUtlReference<CMapClass> *v5; // edx
  CMapClass *m_pObject; // ecx
  CMapClass *v7; // eax
  CUtlReference<CMapClass> *m_pPrev; // edi
  CUtlReference<CMapClass> *m_pNext; // edi
  CUtlReference<CMapClass> *m_pHead; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  m_Size = other->m_Size;
  nCount = m_Size;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this);
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertMultipleBefore(
    this,
    elem: this->m_Size,
    num: m_Size);
  v4 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v5 = &this->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
      m_pObject = other->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&other->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&other->m_Memory + 2)) >> 5)].m_pObject;
      v7 = v5->m_pObject;
      if ( v7 != m_pObject )
      {
        if ( v7 != nullptr )
        {
          m_pPrev = v5->m_pPrev;
          if ( m_pPrev != nullptr )
          {
            m_pPrev->m_pNext = v5->m_pNext;
            if ( v5->m_pNext != nullptr )
              v5->m_pNext->m_pPrev = v5->m_pPrev;
          }
          else if ( v7->m_References.m_pHead == v5 )
          {
            m_pNext = v5->m_pNext;
            v7->m_References.m_pHead = v5->m_pNext;
            if ( m_pNext != nullptr )
              m_pNext->m_pPrev = nullptr;
          }
          v5->m_pPrev = nullptr;
          v5->m_pNext = nullptr;
          v5->m_pObject = nullptr;
        }
        v5->m_pObject = m_pObject;
        if ( m_pObject != nullptr )
        {
          v5->m_pNext = m_pObject->m_References.m_pHead;
          m_pHead = m_pObject->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v5;
          v5->m_pPrev = nullptr;
          m_pObject->m_References.m_pHead = v5;
        }
      }
      ++v4;
    }
    while ( v4 < nCount );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10015910
// Name: public: void CUtlMemory<struct defaultConfigInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<defaultConfigInfo_t,int>::Grow(CUtlMemory<defaultConfigInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  defaultConfigInfo_t *m_pMemory; // edx
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
    v7 = 1564 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (defaultConfigInfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (defaultConfigInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015B00
// Name: public: int CUtlVector<struct defaultConfigInfo_t,class CUtlMemory<struct defaultConfigInfo_t,int>>::InsertBefore(int,struct defaultConfigInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::InsertBefore(
        CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *this,
        int elem,
        const defaultConfigInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  defaultConfigInfo_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<defaultConfigInfo_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 1564 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017BA0
// Name: public: int CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>::Find(class CUtlReference<class CMapClass> const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this,
        const CUtlReference<CMapClass> *src)
{
  int result; // eax
  int v4; // ecx
  int v5; // esi
  int v6; // ecx
  int v7; // esi
  int m_Size; // [esp+Ch] [ebp-8h]
  CUtlReference<CMapClass> **m_pMemory; // [esp+10h] [ebp-4h]
  CMapClass *srca; // [esp+1Ch] [ebp+8h]

  result = 0;
  m_Size = this->m_Size;
  if ( m_Size <= 0 )
    return -1;
  v4 = *((_DWORD *)&this->m_Memory + 2);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = 32 * v4;
  v6 = v4 >> 27;
  v7 = v5 >> 5;
  srca = src->m_pObject;
  while ( srca != m_pMemory[result >> v6][result & v7].m_pObject )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017D40
// Name: public: int CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>::InsertBefore(int,class CUtlReference<class CMapClass> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this,
        int elem,
        const CUtlReference<CMapClass> *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // eax
  CUtlReference<CMapClass> *v9; // eax
  CMapClass *m_pObject; // ecx
  CUtlReference<CMapClass> *m_pHead; // edx

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<CUtlReference<CMapEntity>,int>::ChangeSize(
        this: &this->m_Memory,
        nBlocks: (v6 + v7 - 1) / v6 + m_nBlocks);
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
      count: 12 * v8);
  v9 = &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                              & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v9 != nullptr )
  {
    m_pObject = src->m_pObject;
    if ( m_pObject != nullptr )
    {
      v9->m_pObject = m_pObject;
      v9->m_pNext = m_pObject->m_References.m_pHead;
      m_pHead = m_pObject->m_References.m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = v9;
      v9->m_pPrev = nullptr;
      m_pObject->m_References.m_pHead = v9;
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10017E70
// Name: public: void CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Purge(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this)
{
  int i; // edi
  CUtlReference<CMapClass> **m_pMemory; // [esp-8h] [ebp-Ch]

  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_Memory.m_nBlocks; ++i )
      free(pMem: this->m_Memory.m_pMemory[i]);
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_Memory.m_pMemory = nullptr;
  }
  this->m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10017F40
// Name: public: CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>::~CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this)
{
  int i; // edi
  CUtlReference<CMapClass> **m_pMemory; // [esp-8h] [ebp-1Ch]

  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Purge(this);
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_Memory.m_nBlocks; ++i )
      free(pMem: this->m_Memory.m_pMemory[i]);
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_Memory.m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018AC0
// Name: public: int CUtlVector<struct DetailObjects::DetailObject_t,class CUtlMemory<struct DetailObjects::DetailObject_t,int>>::Find(struct DetailObjects::DetailObject_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>::Find(
        CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int> > *this,
        const DetailObjects::DetailObject_t *src)
{
  int m_Size; // edx
  int result; // eax
  DetailObjects::DetailObject_t *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; src->m_Name.m_Id != i->m_Name.m_Id; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018BC0
// Name: public: void CUtlVector<class CSpriteModel __near *,class CUtlMemory<class CSpriteModel __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CSpriteModel *,CUtlMemory<CSpriteModel *,int>>::PurgeAndDeleteElements(
        CUtlVector<CSpriteModel *,CUtlMemory<CSpriteModel *,int> > *this)
{
  int i; // edi
  CSpriteModel *v3; // ebx
  bool v4; // sf
  CSpriteModel **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018C30
// Name: public: void CUtlVector<class StudioModel __near *,class CUtlMemory<class StudioModel __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<StudioModel *,CUtlMemory<StudioModel *,int>>::PurgeAndDeleteElements(
        CUtlVector<StudioModel *,CUtlMemory<StudioModel *,int> > *this)
{
  int i; // edi
  StudioModel *v3; // ebx
  bool v4; // sf
  StudioModel **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      StudioModel::~StudioModel(this: this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100194A0
// Name: public: int CUtlVector<struct DetailObjects::DetailObjectGroup_t,class CUtlMemory<struct DetailObjects::DetailObjectGroup_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>::InsertBefore(
        CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailObjects::DetailObjectGroup_t *m_pMemory; // ecx
  int v6; // eax
  DetailObjects::DetailObjectGroup_t *v7; // eax
  DetailObjects::DetailModel_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAMSTRUCT,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Models.m_Memory.m_pMemory = nullptr;
    v7->m_Models.m_Memory.m_nAllocationCount = 0;
    v7->m_Models.m_Memory.m_nGrowSize = 0;
    v8 = v7->m_Models.m_Memory.m_pMemory;
    v7->m_Models.m_Size = 0;
    v7->m_Models.m_pElements = v8;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10019560
// Name: public: void CUtlVector<struct DetailObjects::DetailObjectGroup_t,class CUtlMemory<struct DetailObjects::DetailObjectGroup_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>::RemoveAll(
        CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int> > *this)
{
  int v1; // edx
  int v2; // ebx
  DetailObjects::DetailObjectGroup_t *v3; // eax
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int> > *p_m_Models; // esi
  CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int> > *v5; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]

  v1 = this->m_Size - 1;
  v5 = this;
  i = v1;
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
      p_m_Models = &v3->m_Models;
      v3->m_Models.m_Size = 0;
      if ( v3->m_Models.m_Memory.m_nGrowSize >= 0 )
      {
        if ( p_m_Models->m_Memory.m_pMemory != nullptr )
        {
          free(pMem: p_m_Models->m_Memory.m_pMemory);
          this = v5;
          v1 = i;
          p_m_Models->m_Memory.m_pMemory = nullptr;
        }
        p_m_Models->m_Memory.m_nAllocationCount = 0;
      }
      p_m_Models->m_pElements = p_m_Models->m_Memory.m_pMemory;
      if ( p_m_Models->m_Memory.m_nGrowSize >= 0 )
      {
        if ( p_m_Models->m_Memory.m_pMemory != nullptr )
        {
          free(pMem: p_m_Models->m_Memory.m_pMemory);
          this = v5;
          v1 = i;
          p_m_Models->m_Memory.m_pMemory = nullptr;
        }
        p_m_Models->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
      i = v1;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019640
// Name: public: void CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *this)
{
  int v2; // esi
  CUtlReference<CMapEntity> *v3; // eax
  CMapEntity *m_pObject; // ecx
  CUtlReference<CMapEntity> *m_pPrev; // edx
  CUtlReference<CMapEntity> *m_pNext; // edx

  v2 = this->m_Size - 1;
  if ( v2 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][v2 & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
      m_pObject = v3->m_pObject;
      if ( m_pObject != nullptr )
      {
        m_pPrev = v3->m_pPrev;
        if ( m_pPrev != nullptr )
        {
          m_pPrev->m_pNext = v3->m_pNext;
          if ( v3->m_pNext != nullptr )
            v3->m_pNext->m_pPrev = v3->m_pPrev;
        }
        else if ( m_pObject->m_References.m_pHead == v3 )
        {
          m_pNext = v3->m_pNext;
          m_pObject->m_References.m_pHead = v3->m_pNext;
          if ( m_pNext != nullptr )
            m_pNext->m_pPrev = nullptr;
        }
        v3->m_pPrev = nullptr;
        v3->m_pNext = nullptr;
        v3->m_pObject = nullptr;
      }
      --v2;
    }
    while ( v2 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019D10
// Name: public: CUtlVector<struct DetailObjects::DetailObjectGroup_t,class CUtlMemory<struct DetailObjects::DetailObjectGroup_t,int>>::~CUtlVector<struct DetailObjects::DetailObjectGroup_t,class CUtlMemory<struct DetailObjects::DetailObjectGroup_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>::~CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>(
        CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int> > *this)
{
  CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019DA0
// Name: public: void CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::Purge(
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *this)
{
  int i; // edi
  CUtlReference<CMapEntity> **m_pMemory; // [esp-8h] [ebp-Ch]

  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_Memory.m_nBlocks; ++i )
      free(pMem: this->m_Memory.m_pMemory[i]);
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_Memory.m_pMemory = nullptr;
  }
  this->m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10019E30
// Name: public: CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>::~CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *this)
{
  int i; // edi
  CUtlReference<CMapEntity> **m_pMemory; // [esp-8h] [ebp-1Ch]

  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::Purge(this);
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_Memory.m_nBlocks; ++i )
      free(pMem: this->m_Memory.m_pMemory[i]);
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_Memory.m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019F70
// Name: public: int CUtlVector<struct DetailObjects::DetailObject_t,class CUtlMemory<struct DetailObjects::DetailObject_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>::InsertBefore(
        CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailObjects::DetailObject_t *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<BoundBox,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  Construct<DetailObjects::DetailObject_t>(pMemory: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001A310
// Name: public: void CUtlVector<struct DetailObjects::DetailObject_t,class CUtlMemory<struct DetailObjects::DetailObject_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>::RemoveAll(
        CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int> > *this)
{
  int v1; // eax
  int v2; // edi
  CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int> > *p_m_Groups; // esi
  CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int> > *v4; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]

  v1 = this->m_Size - 1;
  v4 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    while ( 1 )
    {
      p_m_Groups = &this->m_Memory.m_pMemory[v2].m_Groups;
      CUtlVector<DetailObjects::DetailObjectGroup_t,CUtlMemory<DetailObjects::DetailObjectGroup_t,int>>::RemoveAll(this: p_m_Groups);
      if ( p_m_Groups->m_Memory.m_nGrowSize >= 0 )
      {
        if ( p_m_Groups->m_Memory.m_pMemory != nullptr )
        {
          free(pMem: p_m_Groups->m_Memory.m_pMemory);
          p_m_Groups->m_Memory.m_pMemory = nullptr;
        }
        p_m_Groups->m_Memory.m_nAllocationCount = 0;
      }
      p_m_Groups->m_pElements = p_m_Groups->m_Memory.m_pMemory;
      if ( p_m_Groups->m_Memory.m_nGrowSize >= 0 )
      {
        if ( p_m_Groups->m_Memory.m_pMemory != nullptr )
        {
          free(pMem: p_m_Groups->m_Memory.m_pMemory);
          p_m_Groups->m_Memory.m_pMemory = nullptr;
        }
        p_m_Groups->m_Memory.m_nAllocationCount = 0;
      }
      --v2;
      if ( --i < 0 )
        break;
      this = v4;
    }
    v4->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AC60
// Name: public: CUtlVector<struct DetailObjects::DetailObject_t,class CUtlMemory<struct DetailObjects::DetailObject_t,int>>::~CUtlVector<struct DetailObjects::DetailObject_t,class CUtlMemory<struct DetailObjects::DetailObject_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>::~CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>(
        CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int> > *this)
{
  CUtlVector<DetailObjects::DetailObject_t,CUtlMemory<DetailObjects::DetailObject_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C140
// Name: public: CUtlVector<int,class CUtlMemory<int,int>>::CUtlVector<int,class CUtlMemory<int,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<int,CUtlMemory<int,int> > *__thiscall CUtlVector<int,CUtlMemory<int,int>>::CUtlVector<int,CUtlMemory<int,int>>(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int growSize,
        int initSize)
{
  int *m_pMemory; // eax

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001C1C0
// Name: public: CUtlVector<struct defaultConfigInfo_t,class CUtlMemory<struct defaultConfigInfo_t,int>>::~CUtlVector<struct defaultConfigInfo_t,class CUtlMemory<struct defaultConfigInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(
        CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *this)
{
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
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
// Address: 0x1001C250
// Name: public: int CUtlVector<class CDispBox,class CUtlMemory<class CDispBox,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispBox,CUtlMemory<CDispBox,int>>::InsertMultipleBefore(
        CUtlVector<CDispBox,CUtlMemory<CDispBox,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispBox *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = 24 * elem;
      do
      {
        v10 += 24;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001D310
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CMapDisp,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CMapDisp,unsigned short> *m_pMemory; // ecx
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
    v7 = 4988 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CMapDisp,unsigned short> *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CMapDisp,unsigned short> *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026830
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertMultipleBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100268A0
// Name: public: CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *__thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int growSize,
        int initSize)
{
  Vector2D *m_pMemory; // eax

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (Vector2D *)MemAlloc_Alloc(nSize: 8 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10026920
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertBefore(int,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        unsigned __int16 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int16 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlSymbol,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10026990
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UsedTexture_t,int>::Grow(
      (CUtlMemory<CDispPaintMgr::DispVertPair_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = 8 * elem;
      do
      {
        v10 += 8;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100287D0
// Name: public: void CUtlMemory<struct ShoreSegment_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ShoreSegment_t,int>::Grow(CUtlMemory<ShoreSegment_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ShoreSegment_t *m_pMemory; // ecx
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
    v7 = 308 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ShoreSegment_t *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (ShoreSegment_t *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028860
// Name: public: void CUtlMemory<class CMapOverlay,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMapOverlay,int>::Grow(CUtlMemory<CMapOverlay,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMapOverlay *m_pMemory; // ecx
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
    v7 = 532 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMapOverlay *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (CMapOverlay *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029A50
// Name: public: void CUtlVector<class CMapOverlay,class CUtlMemory<class CMapOverlay,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::Purge(
        CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CMapOverlay *m_pMemory; // eax

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      ((void (__thiscall *)(CMapOverlay *, _DWORD))this->m_Memory.m_pMemory[v3].~CMapClass)(
        a1: &this->m_Memory.m_pMemory[v3],
        a2: 0);
      --v3;
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
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029AB0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem,
        vgui::PageTab **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PageTab **m_pMemory; // ecx
  int v7; // eax
  vgui::PageTab **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
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
// Address: 0x10029B20
// Name: public: int CUtlVector<class CMapOverlay,class CUtlMemory<class CMapOverlay,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::InsertBefore(
        CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMapOverlay *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMapOverlay,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 532 * v6);
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    CMapOverlay::CMapOverlay(this: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10029BD0
// Name: public: CUtlVector<class CMapOverlay,class CUtlMemory<class CMapOverlay,int>>::~CUtlVector<class CMapOverlay,class CUtlMemory<class CMapOverlay,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::~CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>(
        CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int> > *this)
{
  CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::Purge(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BB80
// Name: public: int CUtlVector<struct Shoreline_t,class CUtlMemory<struct Shoreline_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>::InsertBefore(
        CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Shoreline_t *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CEditDispSubdivMesh::SubdivQuad_t,int>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 96 * v6);
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    Shoreline_t::Shoreline_t(this: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002BE20
// Name: public: void CUtlVector<struct Shoreline_t,class CUtlMemory<struct Shoreline_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>::Purge(
        CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  Shoreline_t *m_pMemory; // eax

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      Shoreline_t::~Shoreline_t(this: &this->m_Memory.m_pMemory[v3--]);
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
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BE70
// Name: public: CUtlVector<struct Shoreline_t,class CUtlMemory<struct Shoreline_t,int>>::~CUtlVector<struct Shoreline_t,class CUtlMemory<struct Shoreline_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>::~CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>(
        CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int> > *this)
{
  CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>::Purge(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030DB0
// Name: public: int CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>::InsertBefore(int,class CUtlReference<class CMapEntity> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *this,
        int elem,
        const CUtlReference<CMapEntity> *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // eax
  CUtlReference<CMapEntity> *v9; // eax
  CMapEntity *m_pObject; // ecx
  CUtlReference<CMapEntity> *m_pHead; // edx

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<CUtlReference<CMapEntity>,int>::ChangeSize(
        (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)this,
        nBlocks: (v6 + v7 - 1) / v6 + m_nBlocks);
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
      count: 12 * v8);
  v9 = &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                              & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v9 != nullptr )
  {
    m_pObject = src->m_pObject;
    if ( m_pObject != nullptr )
    {
      v9->m_pObject = m_pObject;
      v9->m_pNext = m_pObject->m_References.m_pHead;
      m_pHead = m_pObject->m_References.m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = v9;
      v9->m_pPrev = nullptr;
      m_pObject->m_References.m_pHead = v9;
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10030F70
// Name: public: class CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>> __near & CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>>::operator=(class CUtlVector<class CUtlReference<class CMapEntity>,class CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *__thiscall CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::operator=(
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *this,
        const CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > *other)
{
  int m_Size; // edi
  int v4; // esi
  CUtlReference<CMapEntity> *v5; // edx
  CMapEntity *m_pObject; // ecx
  CMapEntity *v7; // eax
  CUtlReference<CMapEntity> *m_pPrev; // edi
  CUtlReference<CMapEntity> *m_pNext; // edi
  CUtlReference<CMapEntity> *m_pHead; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  m_Size = other->m_Size;
  nCount = m_Size;
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(this);
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)this,
    elem: this->m_Size,
    num: m_Size);
  v4 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v5 = &this->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
      m_pObject = other->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&other->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&other->m_Memory + 2)) >> 5)].m_pObject;
      v7 = v5->m_pObject;
      if ( v7 != m_pObject )
      {
        if ( v7 != nullptr )
        {
          m_pPrev = v5->m_pPrev;
          if ( m_pPrev != nullptr )
          {
            m_pPrev->m_pNext = v5->m_pNext;
            if ( v5->m_pNext != nullptr )
              v5->m_pNext->m_pPrev = v5->m_pPrev;
          }
          else if ( v7->m_References.m_pHead == v5 )
          {
            m_pNext = v5->m_pNext;
            v7->m_References.m_pHead = v5->m_pNext;
            if ( m_pNext != nullptr )
              m_pNext->m_pPrev = nullptr;
          }
          v5->m_pPrev = nullptr;
          v5->m_pNext = nullptr;
          v5->m_pObject = nullptr;
        }
        v5->m_pObject = m_pObject;
        if ( m_pObject != nullptr )
        {
          v5->m_pNext = m_pObject->m_References.m_pHead;
          m_pHead = m_pObject->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v5;
          v5->m_pPrev = nullptr;
          m_pObject->m_References.m_pHead = v5;
        }
      }
      ++v4;
    }
    while ( v4 < nCount );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10031C60
// Name: public: CUtlMemory<class CMapClass __near *,int>::~CUtlMemory<class CMapClass __near *,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMapClass *,int>::~CUtlMemory<CMapClass *,int>(CUtlMemory<CAnchorDef,int> *this)
{
  if ( this->m_nGrowSize >= 0 )
  {
    if ( this->m_pMemory != nullptr )
    {
      free(pMem: this->m_pMemory);
      this->m_pMemory = nullptr;
    }
    this->m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035070
// Name: public: int CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *this,
        int elem,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // ecx
  int v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)src->m_pszData - 1)[1];
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10035120
// Name: public: int CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertMultipleBefore(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v11; // ebx
  ATL::IAtlStringMgr *StringManager; // eax
  int i; // [esp+Ch] [ebp-10h]
  int numa; // [esp+28h] [ebp+Ch]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v10);
  i = 0;
  if ( num > 0 )
  {
    numa = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[numa];
      if ( v11 != nullptr )
      {
        StringManager = AfxGetStringManager();
        if ( StringManager == nullptr )
          ATL::AtlThrowImpl(hr: -2147467259);
        v11->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      }
      ++numa;
      ++i;
    }
    while ( i < num );
    return elem;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10035230
// Name: public: void CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::RemoveAll(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *this)
{
  int i; // esi
  volatile signed __int32 *v3; // eax

  for ( i = this->m_Size - 1; i >= 0; --i )
  {
    v3 = (volatile signed __int32 *)(this->m_Memory.m_pMemory[i].m_pszData - 16);
    if ( _InterlockedDecrement(v3 + 3) <= 0 )
      (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035550
// Name: public: CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>::~CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::~CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *this)
{
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100355E0
// Name: public: void CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>::Sort(int (*)(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::Sort(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *v2; // edi
  signed int m_Size; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  const char **p_m_pszData; // ebx
  char *v8; // esi
  int (__thiscall ***v9)(_DWORD, _DWORD, int); // eax
  char *v10; // edi
  int v11; // eax
  const char *v12; // edi
  volatile signed __int32 *v13; // eax
  volatile signed __int32 *v14; // esi
  volatile signed __int32 *v15; // ebx
  volatile signed __int32 *v16; // esi
  ATL::CStringData *v17; // edi
  ATL::CStringData *v18; // [esp+8h] [ebp-20h]
  int i; // [esp+Ch] [ebp-1Ch]
  int j; // [esp+14h] [ebp-14h]
  ATL::CSimpleStringT<char,0> *v22; // [esp+18h] [ebp-10h]

  v2 = this;
  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( v2->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      for ( i = v5; v5 >= 0; i = v5 )
      {
        v6 = 1;
        j = 1;
        if ( v5 >= 1 )
        {
          do
          {
            if ( pfnCompare(a1: &v2->m_Memory.m_pMemory[v6 - 1], a2: &v2->m_Memory.m_pMemory[v6]) < 0 )
            {
              p_m_pszData = (const char **)&v2->m_Memory.m_pMemory[v6].m_pszData;
              v8 = (char *)*(p_m_pszData - 1);
              v22 = (ATL::CSimpleStringT<char,0> *)p_m_pszData;
              v9 = (int (__thiscall ***)(_DWORD, _DWORD, int))(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v8 - 4) + 16))(a1: *((_DWORD *)v8 - 4));
              if ( *((int *)v8 - 1) >= 0 && v9 == *((int (__thiscall ****)(_DWORD, _DWORD, int))v8 - 4) )
              {
                v10 = v8 - 16;
                _InterlockedExchangeAdd((volatile signed __int32 *)v8 - 1, 1u);
              }
              else
              {
                v11 = (**v9)(a1: v9, a2: *((_DWORD *)v8 - 3), a3: 1);
                v10 = (char *)v11;
                if ( v11 == 0 )
                  ATL::CSimpleStringT<char,0>::ThrowMemoryException();
                *(_DWORD *)(v11 + 4) = *((_DWORD *)v8 - 3);
                memcpy_s(
                  dst: (void *)(v11 + 16),
                  sizeInBytes: *((_DWORD *)v8 - 3) + 1,
                  src: v8,
                  count: *((_DWORD *)v8 - 3) + 1);
              }
              v12 = v10 + 16;
              v13 = (volatile signed __int32 *)(*p_m_pszData - 16);
              v14 = (volatile signed __int32 *)(*(p_m_pszData - 1) - 16);
              if ( v13 != v14 )
              {
                if ( *((int *)v14 + 3) >= 0 && *v13 == *v14 )
                {
                  v18 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)*p_m_pszData - 1);
                  if ( _InterlockedDecrement(v14 + 3) <= 0 )
                    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v14 + 4))(a1: v14);
                  *(p_m_pszData - 1) = (const char *)&v18[1];
                }
                else
                {
                  ATL::CSimpleStringT<char,0>::SetString(
                    this: (ATL::CSimpleStringT<char,0> *)p_m_pszData - 1,
                    pszSrc: *p_m_pszData,
                    nLength: *((_DWORD *)*p_m_pszData - 3));
                }
              }
              v15 = (volatile signed __int32 *)(v12 - 16);
              v16 = (volatile signed __int32 *)(v22->m_pszData - 16);
              if ( v12 - 16 != (const char *)v16 )
              {
                if ( *((int *)v16 + 3) >= 0 && *v15 == *v16 )
                {
                  v17 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v12 - 1);
                  if ( _InterlockedDecrement(v16 + 3) <= 0 )
                    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v16 + 4))(a1: v16);
                  v22->m_pszData = (char *)&v17[1];
                }
                else
                {
                  ATL::CSimpleStringT<char,0>::SetString(this: v22, pszSrc: v12, nLength: *((_DWORD *)v12 - 3));
                }
              }
              if ( _InterlockedDecrement(v15 + 3) <= 0 )
                (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v15 + 4))(a1: v15);
              v6 = j;
              v2 = this;
            }
            v5 = i;
            j = ++v6;
          }
          while ( v6 <= i );
        }
        --v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035FB0
// Name: public: class CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>> __near & CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>::operator=(class CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *__thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::operator=(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *this,
        const CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *other)
{
  int m_Size; // esi
  int v4; // eax
  int v5; // ecx
  char *m_pszData; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v7; // edi
  volatile signed __int32 *v8; // esi
  int nCount; // [esp+8h] [ebp-Ch]
  ATL::CStringData *v11; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  m_Size = other->m_Size;
  nCount = m_Size;
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::RemoveAll(this);
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertMultipleBefore(
    this,
    elem: this->m_Size,
    num: m_Size);
  v4 = 0;
  i = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v5 = v4;
      m_pszData = other->m_Memory.m_pMemory[v4].m_pszData;
      v7 = &this->m_Memory.m_pMemory[v5];
      v8 = (volatile signed __int32 *)(v7->m_pszData - 16);
      if ( m_pszData - 16 != (char *)v8 )
      {
        if ( *((int *)v8 + 3) >= 0 && *((_DWORD *)m_pszData - 4) == *v8 )
        {
          v11 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)m_pszData - 1);
          if ( _InterlockedDecrement(v8 + 3) <= 0 )
            (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v8 + 4))(a1: v8);
          v7->m_pszData = (char *)&v11[1];
        }
        else
        {
          ATL::CSimpleStringT<char,0>::SetString(this: v7, pszSrc: m_pszData, nLength: *((_DWORD *)m_pszData - 3));
        }
      }
      v4 = i + 1;
      i = v4;
    }
    while ( v4 < nCount );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10037550
// Name: public: void CUtlMemory<struct MatExlcusions_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MatExlcusions_s,int>::Grow(CUtlMemory<MatExlcusions_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MatExlcusions_s *m_pMemory; // ecx
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
    v7 = 261 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MatExlcusions_s *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (MatExlcusions_s *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038970
// Name: public: int CUtlVector<struct MatExlcusions_s,class CUtlMemory<struct MatExlcusions_s,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MatExlcusions_s,CUtlMemory<MatExlcusions_s,int>>::AddToTail(
        CUtlVector<MatExlcusions_s,CUtlMemory<MatExlcusions_s,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  MatExlcusions_s *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MatExlcusions_s,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 261 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB70
// Name: public: void CUtlMemory<class CGridNavCell,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CGridNavCell,int>::Grow(CUtlMemory<CGridNavCell,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CGridNavCell *m_pMemory; // ecx
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
      this->m_pMemory = (CGridNavCell *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (CGridNavCell *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BDA0
// Name: public: int CUtlVector<class CGridNavCell,class CUtlMemory<class CGridNavCell,int>>::InsertBefore(int,class CGridNavCell const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CGridNavCell,CUtlMemory<CGridNavCell,int>>::InsertBefore(
        CUtlVector<CGridNavCell,CUtlMemory<CGridNavCell,int> > *this,
        int elem,
        const CGridNavCell *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CGridNavCell *m_pMemory; // ecx
  int v7; // eax
  CGridNavCell *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CGridNavCell,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10046160
// Name: public: void CUtlVector<class CTrackEntry,class CUtlMemory<class CTrackEntry,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int>>::RemoveAll(
        CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *this)
{
  int v2; // esi
  int v3; // edi
  CTrackEntry *v4; // eax
  CTrackEntry::TrackType_t m_eType; // ecx
  CMapClass *pCurrent; // eax

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      v4 = &this->m_Memory.m_pMemory[v3];
      if ( v4->m_bAutoDestruct )
      {
        m_eType = v4->m_eType;
        if ( m_eType != ttNone )
        {
          if ( m_eType != ttCopy )
          {
            if ( m_eType == ttDelete && !v4->m_bUndone )
            {
              pCurrent = v4->m_Copy.pCurrent;
              goto LABEL_11;
            }
          }
          else if ( !v4->m_bUndone )
          {
            pCurrent = v4->m_Copy.pKeptObject;
LABEL_11:
            if ( pCurrent != nullptr )
              ((void (__thiscall *)(CMapClass *, int))pCurrent->~CMapClass)(a1: pCurrent, a2: 1);
          }
        }
      }
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10046270
// Name: public: CUtlVector<class CTrackEntry,class CUtlMemory<class CTrackEntry,int>>::~CUtlVector<class CTrackEntry,class CUtlMemory<class CTrackEntry,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int>>::~CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int>>(
        CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *this)
{
  CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100465B0
// Name: public: int CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>::AddVectorToTail(class CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::AddVectorToTail(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this,
        const CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *src)
{
  const CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *v2; // ebx
  int m_nBlocks; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // esi
  int v8; // ebx
  CUtlReference<CMapClass> *v9; // eax
  CMapClass *v10; // ecx
  CUtlReference<CMapClass> *m_pHead; // ebx
  int nSrcCount; // [esp+14h] [ebp-14h]
  int base; // [esp+18h] [ebp-10h]

  v2 = src;
  m_nBlocks = this->m_Memory.m_nBlocks;
  v5 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  base = this->m_Size;
  nSrcCount = src->m_Size;
  v6 = base + nSrcCount - v5 * m_nBlocks;
  if ( v6 > 0 )
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::ChangeSize(
      this: &this->m_Memory,
      nBlocks: (v5 + v6 - 1) / v5 + m_nBlocks);
  this->m_Size += nSrcCount;
  v7 = 0;
  this->m_pElements = nullptr;
  if ( nSrcCount > 0 )
  {
    while ( 1 )
    {
      v8 = (int)&v2->m_Memory.m_pMemory[v7 >> (*((int *)&v2->m_Memory + 2) >> 27)][v7
                                                                                 & ((32 * *((_DWORD *)&v2->m_Memory + 2)) >> 5)];
      v9 = &this->m_Memory.m_pMemory[(v7 + base) >> (*((int *)&this->m_Memory + 2) >> 27)][(v7 + base)
                                                                                         & ((32
                                                                                           * *((_DWORD *)&this->m_Memory
                                                                                             + 2)) >> 5)];
      if ( v9 != nullptr )
      {
        v10 = *(CMapClass **)(v8 + 8);
        if ( v10 != nullptr )
        {
          v9->m_pObject = v10;
          v9->m_pNext = v10->m_References.m_pHead;
          m_pHead = v10->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v9;
          v9->m_pPrev = nullptr;
          v10->m_References.m_pHead = v9;
        }
      }
      if ( ++v7 >= nSrcCount )
        break;
      v2 = src;
    }
  }
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x100468E0
// Name: public: void CUtlVector<class CHistoryTrack __near *,class CUtlMemory<class CHistoryTrack __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CHistoryTrack *,CUtlMemory<CHistoryTrack *,int>>::PurgeAndDeleteElements(
        CUtlVector<CHistoryTrack *,CUtlMemory<CHistoryTrack *,int> > *this)
{
  int i; // edi
  CHistoryTrack *v3; // ebx
  bool v4; // sf
  CHistoryTrack **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CHistoryTrack::~CHistoryTrack(this: this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100491C0
// Name: public: int CUtlVector<struct tagGF,class CUtlMemory<struct tagGF,int>>::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<tagGF,CUtlMemory<tagGF,int>>::Count(CUtlVector<tagGF,CUtlMemory<tagGF,int> > *this)
{
  return this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10049220
// Name: public: struct tagGF const __near & CUtlVector<struct tagGF,class CUtlMemory<struct tagGF,int>>::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
const tagGF *__thiscall CUtlVector<tagGF,CUtlMemory<tagGF,int>>::operator[](
        CUtlVector<tagGF,CUtlMemory<tagGF,int> > *this,
        int i)
{
  return &this->m_Memory.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x1004CB30
// Name: public: void CUtlMemory<class CVisGroup __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CVisGroup *,int>::Grow(CUtlMemory<CCullTreeNode *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CCullTreeNode **m_pMemory; // ecx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CCullTreeNode **)_realloc_crt(ptr: m_pMemory, size: 4 * m_nAllocationCount);
    else
      this->m_pMemory = (CCullTreeNode **)MemAlloc_Alloc(nSize: 4 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051670
// Name: public: CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CUtlVector<class Vector,class CUtlMemory<class Vector,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CUtlVector<Vector,CUtlMemory<Vector,int>>(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int growSize,
        int initSize)
{
  Vector *m_pMemory; // eax

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (Vector *)MemAlloc_Alloc(nSize: 12 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10051780
// Name: public: CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>::~CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::~CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>(
        CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int> > *this)
{
  int i; // edi
  int j; // edi
  CacheOptimizedTriangle **m_pMemory; // [esp-4h] [ebp-20h]
  CacheOptimizedTriangle **v5; // [esp-4h] [ebp-20h]

  this->m_Size = 0;
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_Memory.m_nBlocks; ++i )
      free(pMem: this->m_Memory.m_pMemory[i]);
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_Memory.m_pMemory = nullptr;
  }
  this->m_pElements = nullptr;
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    for ( j = 0; j < this->m_Memory.m_nBlocks; ++j )
      free(pMem: this->m_Memory.m_pMemory[j]);
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nBlocks = 0;
    free(pMem: v5);
    this->m_Memory.m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055D60
// Name: public: void CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::RemoveAll(
        CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *this)
{
  int v1; // ebx
  int v2; // edi
  AssetUsageInfo_t *v3; // esi
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *v4; // [esp+8h] [ebp-10h]

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
      v3->m_assetName.m_Storage.m_nActualLength = 0;
      if ( v3->m_assetName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_assetName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          free(pMem: v3->m_assetName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_assetName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_assetName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056040
// Name: public: CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>>::~CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(
        CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *this)
{
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059D60
// Name: public: void CUtlVector<class CManifestMap __near *,class CUtlMemory<class CManifestMap __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CManifestMap *,CUtlMemory<CManifestMap *,int>>::PurgeAndDeleteElements(
        CUtlVector<CManifestMap *,CUtlMemory<CManifestMap *,int> > *this)
{
  int i; // edi
  CManifestMap *v3; // ebx
  bool v4; // sf
  CManifestMap **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CManifestMap::~CManifestMap(this: this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060840
// Name: public: void CUtlMemory<struct CheckListItem,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CheckListItem,int>::Grow(CUtlMemory<Vector,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Vector *m_pMemory; // ecx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (Vector *)_realloc_crt(ptr: m_pMemory, size: 12 * m_nAllocationCount);
    else
      this->m_pMemory = (Vector *)MemAlloc_Alloc(nSize: 12 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061560
// Name: public: void CUtlMemory<struct Cordon_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Cordon_t,int>::Grow(CUtlMemory<Cordon_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Cordon_t *m_pMemory; // ecx

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
      this->m_pMemory = (Cordon_t *)_realloc_crt(ptr: m_pMemory, size: 40 * m_nAllocationCount);
    else
      this->m_pMemory = (Cordon_t *)MemAlloc_Alloc(nSize: 40 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100616A0
// Name: public: void CUtlMemory<class BoundBox,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<BoundBox,int>::Grow(CUtlMemory<DetailObjects::DetailObject_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailObjects::DetailObject_t *m_pMemory; // ecx

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
      this->m_pMemory = (DetailObjects::DetailObject_t *)_realloc_crt(ptr: m_pMemory, size: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (DetailObjects::DetailObject_t *)MemAlloc_Alloc(nSize: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061750
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class CMapClass __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CMapClass *,unsigned short> *m_pMemory; // ecx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CMapClass *,unsigned short> *)_realloc_crt(
                                                                         ptr: m_pMemory,
                                                                         size: 12 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CMapClass *,unsigned short> *)MemAlloc_Alloc(nSize: 12 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062A40
// Name: public: void CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::EnsureCapacity(
        CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *this,
        int num)
{
  BoundBox *m_pMemory; // ecx
  BoundBox *v4; // edx

  if ( this->m_Memory.m_nAllocationCount >= num )
    goto LABEL_5;
  m_pMemory = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = m_pMemory;
  }
  else
  {
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (BoundBox *)_realloc_crt(ptr: m_pMemory, size: 28 * num);
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    v4 = (BoundBox *)MemAlloc_Alloc(nSize: 28 * num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062CE0
// Name: public: int CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::InsertMultipleBefore(
        CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  BoundBox *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<BoundBox,int>::Grow(
      (CUtlMemory<DetailObjects::DetailObject_t,int> *)this,
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
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 28 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        if ( &this->m_Memory.m_pMemory[v11] != nullptr )
        {
          BoundBox::BoundBox(this: &this->m_Memory.m_pMemory[v11]);
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
// Address: 0x10064180
// Name: public: int CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>>::AddVectorToTail(class CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::AddVectorToTail(
        CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *this,
        const CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *src)
{
  int m_Size; // esi
  int v4; // ebx
  int v5; // ebx
  int v6; // edx
  BoundBox *v7; // ecx
  BoundBox *v8; // eax
  int base; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  m_Size = src->m_Size;
  v4 = this->m_Size;
  base = v4;
  CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::EnsureCapacity(this, num: m_Size + v4);
  this->m_Size += m_Size;
  if ( m_Size <= 0 )
    return v4;
  v5 = 0;
  v6 = base;
  for ( i = m_Size; i != 0; --i )
  {
    v7 = &src->m_Memory.m_pMemory[v5];
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
    {
      v8->__vftable = (BoundBox_vtbl *)&BoundBox::`vftable';
      *(_QWORD *)&v8->bmins.x = *(_QWORD *)&v7->bmins.x;
      v8->bmins.z = v7->bmins.z;
      *(_QWORD *)&v8->bmaxs.x = *(_QWORD *)&v7->bmaxs.x;
      v8->bmaxs.z = v7->bmaxs.z;
    }
    ++v5;
    ++v6;
  }
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x10064220
// Name: public: int CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>::Find(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::Find(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *this,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *src)
{
  int v3; // esi
  int v4; // eax

  v3 = 0;
  if ( this->m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    if ( src->m_pszData == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    _mbscmp(s1: (unsigned __int8 *)this->m_Memory.m_pMemory[v3].m_pszData, s2: (unsigned __int8 *)src->m_pszData);
    if ( v4 == 0 )
      break;
    if ( ++v3 >= this->m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100646E0
// Name: public: void CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char const *,CUtlMemory<char const *,int>>::PurgeAndDeleteElements(
        CUtlVector<char const *,CUtlMemory<char const *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  const char **m_pMemory; // eax
  const char **v5; // edx

  for ( i = 0; i < this->m_Size; ++i )
    operator delete(p: (void *)this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = m_pMemory;
  }
  else
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064740
// Name: public: int CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>>::InsertBefore(int,class BoundBox const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::InsertBefore(
        CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *this,
        int elem,
        const BoundBox *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BoundBox *m_pMemory; // ecx
  int v7; // eax
  BoundBox *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<BoundBox,int>::Grow(
      (CUtlMemory<DetailObjects::DetailObject_t,int> *)this,
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
    v8->__vftable = (BoundBox_vtbl *)&BoundBox::`vftable';
    v8->bmins = src->bmins;
    v8->bmaxs = src->bmaxs;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100647E0
// Name: public: int CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::InsertBefore(
        CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BoundBox *m_pMemory; // ecx
  int v6; // eax
  BoundBox *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<BoundBox,int>::Grow(
      (CUtlMemory<DetailObjects::DetailObject_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    BoundBox::BoundBox(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100648F0
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        const Vector *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v7; // eax
  Vector *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CheckListItem,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10067E30
// Name: public: void CUtlVector<class CVisGroup __near *,class CUtlMemory<class CVisGroup __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVisGroup *,CUtlMemory<CVisGroup *,int>>::PurgeAndDeleteElements(
        CUtlVector<CVisGroup *,CUtlMemory<CVisGroup *,int> > *this)
{
  int v2; // eax
  CVisGroup *v3; // esi
  CVisGroup **m_pMemory; // eax
  CVisGroup **v5; // edx
  int i; // [esp+Ch] [ebp-10h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      v3->m_Children.m_Size = 0;
      if ( v3->m_Children.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Children.m_Memory.m_pMemory != nullptr )
        {
          free(pMem: v3->m_Children.m_Memory.m_pMemory);
          v3->m_Children.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Children.m_Memory.m_nAllocationCount = 0;
      }
      v3->m_Children.m_pElements = v3->m_Children.m_Memory.m_pMemory;
      if ( v3->m_Children.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Children.m_Memory.m_pMemory != nullptr )
        {
          free(pMem: v3->m_Children.m_Memory.m_pMemory);
          v3->m_Children.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Children.m_Memory.m_nAllocationCount = 0;
      }
      operator delete(p: v3);
      v2 = i;
    }
    ++v2;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = m_pMemory;
  }
  else
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067F70
// Name: public: int CUtlVector<struct Cordon_t,class CUtlMemory<struct Cordon_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int>>::InsertBefore(
        CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Cordon_t *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Cordon_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 40 * v6);
  Construct<Cordon_t>(pMemory: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10068070
// Name: public: int CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::InsertBefore(
        CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AssetUsageInfo_t *m_pMemory; // ecx
  int v6; // eax
  AssetUsageInfo_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<int,int>,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->m_assetName);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006B3D0
// Name: public: class CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>> __near & CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>>::operator=(class CUtlVector<class BoundBox,class CUtlMemory<class BoundBox,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *__thiscall CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::operator=(
        CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *this,
        const CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *other)
{
  int m_Size; // ebx
  int v5; // eax
  int v6; // edx
  BoundBox *m_pMemory; // eax
  BoundBox *v8; // ecx
  float *v9; // eax
  float *v10; // ecx
  BoundBox *v11; // eax
  BoundBox *v12; // ecx
  float *v13; // ecx
  BoundBox *v14; // eax
  BoundBox *v15; // ecx
  float *v16; // eax
  float *v17; // ecx
  int v18; // ebx
  BoundBox *v19; // ecx
  float *v20; // eax
  float *v21; // ecx
  bool v22; // zf
  int v23; // edx
  int v24; // ebx
  BoundBox *v25; // ecx
  BoundBox *v26; // eax
  float *v27; // ecx
  int i; // [esp+Ch] [ebp-8h]
  int nCount; // [esp+10h] [ebp-4h]
  const CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *othera; // [esp+1Ch] [ebp+8h]

  m_Size = other->m_Size;
  nCount = m_Size;
  this->m_Size = 0;
  CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    v6 = 0;
    othera = (const CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *)(((unsigned int)(m_Size - 4) >> 2) + 1);
    i = 4 * (_DWORD)othera;
    do
    {
      m_pMemory = other->m_Memory.m_pMemory;
      v8 = this->m_Memory.m_pMemory;
      v8[v6].bmins.x = other->m_Memory.m_pMemory[v6].bmins.x;
      v9 = (float *)&m_pMemory[v6];
      v10 = (float *)&v8[v6];
      v10[2] = v9[2];
      v10[3] = v9[3];
      v10[4] = v9[4];
      v10[5] = v9[5];
      v10[6] = v9[6];
      v11 = &other->m_Memory.m_pMemory[v6 + 1];
      v12 = this->m_Memory.m_pMemory;
      v12[v6 + 1].bmins.x = other->m_Memory.m_pMemory[v6 + 1].bmins.x;
      v13 = (float *)&v12[v6 + 1];
      v13[2] = v11->bmins.y;
      v13[3] = v11->bmins.z;
      v13[4] = v11->bmaxs.x;
      v13[5] = v11->bmaxs.y;
      v13[6] = v11->bmaxs.z;
      v14 = other->m_Memory.m_pMemory;
      v15 = this->m_Memory.m_pMemory;
      v15[v6 + 2].bmins.x = other->m_Memory.m_pMemory[v6 + 2].bmins.x;
      v16 = (float *)&v14[v6 + 2];
      v17 = (float *)&v15[v6 + 2];
      v17[2] = v16[2];
      v18 = v6 * 28 + 84;
      v6 += 4;
      v17[3] = v16[3];
      v17[4] = v16[4];
      v17[5] = v16[5];
      v17[6] = v16[6];
      v19 = this->m_Memory.m_pMemory;
      v20 = (float *)((char *)other->m_Memory.m_pMemory + v18);
      *(float *)((char *)&v19->bmins.x + v18) = v20[1];
      v21 = (float *)((char *)v19 + v18);
      v22 = othera == (const CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *)1;
      othera = (const CUtlVector<BoundBox,CUtlMemory<BoundBox,int> > *)((char *)othera - 1);
      v21[2] = v20[2];
      v21[3] = v20[3];
      v21[4] = v20[4];
      v21[5] = v20[5];
      v21[6] = v20[6];
    }
    while ( !v22 );
    m_Size = nCount;
    v5 = i;
  }
  if ( v5 < m_Size )
  {
    v23 = v5;
    v24 = m_Size - v5;
    do
    {
      v25 = this->m_Memory.m_pMemory;
      v26 = &other->m_Memory.m_pMemory[v23];
      v25[v23].bmins.x = v26->bmins.x;
      v27 = (float *)&v25[v23];
      v27[2] = v26->bmins.y;
      ++v23;
      --v24;
      v27[3] = v26->bmins.z;
      v27[4] = v26->bmaxs.x;
      v27[5] = v26->bmaxs.y;
      v27[6] = v26->bmaxs.z;
    }
    while ( v24 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006B540
// Name: public: void CUtlVector<struct NotifyListEntry_t __near *,class CUtlMemory<struct NotifyListEntry_t __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<NotifyListEntry_t *,CUtlMemory<NotifyListEntry_t *,int>>::PurgeAndDeleteElements(
        CUtlVector<NotifyListEntry_t *,CUtlMemory<NotifyListEntry_t *,int> > *this)
{
  int i; // ebx
  NotifyListEntry_t *v3; // eax
  CMapClass *m_pObject; // edx
  CUtlReference<CMapClass> *m_pPrev; // ecx
  CUtlReference<CMapClass> *m_pNext; // ecx
  NotifyListEntry_t **m_pMemory; // eax

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      m_pObject = v3->pObject.m_pObject;
      if ( m_pObject != nullptr )
      {
        m_pPrev = v3->pObject.m_pPrev;
        if ( m_pPrev != nullptr )
        {
          m_pPrev->m_pNext = v3->pObject.m_pNext;
          if ( v3->pObject.m_pNext != nullptr )
            v3->pObject.m_pNext->m_pPrev = v3->pObject.m_pPrev;
        }
        else if ( (NotifyListEntry_t *)m_pObject->m_References.m_pHead == v3 )
        {
          m_pNext = v3->pObject.m_pNext;
          m_pObject->m_References.m_pHead = v3->pObject.m_pNext;
          if ( m_pNext != nullptr )
            m_pNext->m_pPrev = nullptr;
        }
        v3->pObject.m_pPrev = nullptr;
        v3->pObject.m_pNext = nullptr;
        v3->pObject.m_pObject = nullptr;
      }
      operator delete(p: v3);
    }
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
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B8E0
// Name: public: void CUtlVector<struct Cordon_t,class CUtlMemory<struct Cordon_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int>>::Purge(
        CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  Cordon_t *m_pMemory; // eax

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      Cordon_t::~Cordon_t(this: &this->m_Memory.m_pMemory[v3--]);
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
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D340
// Name: public: CUtlVector<struct Cordon_t,class CUtlMemory<struct Cordon_t,int>>::~CUtlVector<struct Cordon_t,class CUtlMemory<struct Cordon_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int>>::~CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int>>(
        CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int> > *this)
{
  CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int>>::Purge(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B810
// Name: public: void CUtlMemory<class CMapPathNode,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMapPathNode,int>::Grow(CUtlMemory<CMapPathNode,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMapPathNode *m_pMemory; // ecx
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
    v7 = 436 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMapPathNode *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (CMapPathNode *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B8A0
// Name: public: void CUtlVector<class CMapPathNode,class CUtlMemory<class CMapPathNode,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>::RemoveAll(
        CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int> > *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      WCKeyValuesT<WCKVBase_Dict>::~WCKeyValuesT<WCKVBase_Dict>(this: &this->m_Memory.m_pMemory[v3--].kv);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007B910
// Name: public: CUtlVector<class CMapPathNode,class CUtlMemory<class CMapPathNode,int>>::~CUtlVector<class CMapPathNode,class CUtlMemory<class CMapPathNode,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>::~CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>(
        CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int> > *this)
{
  CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C190
// Name: public: int CUtlVector<class CMapPathNode,class CUtlMemory<class CMapPathNode,int>>::InsertBefore(int,class CMapPathNode const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int>>::InsertBefore(
        CUtlVector<CMapPathNode,CUtlMemory<CMapPathNode,int> > *this,
        int elem,
        const CMapPathNode *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMapPathNode *m_pMemory; // ecx
  int v7; // eax
  CMapPathNode *v8; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMapPathNode,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 436 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    WCKeyValuesT<WCKVBase_Dict>::WCKeyValuesT<WCKVBase_Dict>(this: &v8->kv);
    CMapPathNode::operator=(this: v8, src);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100929C0
// Name: public: void CUtlMemory<struct SInstanceState,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SInstanceState,int>::Grow(CUtlMemory<SInstanceState,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SInstanceState *m_pMemory; // ecx
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
    v7 = 164 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SInstanceState *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (SInstanceState *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093D40
// Name: public: CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *__thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int growSize,
        int initSize)
{
  VMatrix *m_pMemory; // eax

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (VMatrix *)MemAlloc_Alloc(nSize: initSize << 6);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10093DB0
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        const VMatrix *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10093E20
// Name: public: int CUtlVector<struct SInstanceState,class CUtlMemory<struct SInstanceState,int>>::InsertBefore(int,struct SInstanceState const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SInstanceState,CUtlMemory<SInstanceState,int>>::InsertBefore(
        CUtlVector<SInstanceState,CUtlMemory<SInstanceState,int> > *this,
        int elem,
        const SInstanceState *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SInstanceState *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SInstanceState,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 164 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100966D0
// Name: public: void CUtlMemory<struct TranslucentObjects_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<TranslucentObjects_s,int>::Grow(CUtlMemory<TranslucentObjects_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  TranslucentObjects_s *m_pMemory; // ecx
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
    v7 = 176 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (TranslucentObjects_s *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (TranslucentObjects_s *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096760
// Name: public: void CUtlMemory<class CLightPreview_Light,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CLightPreview_Light,int>::Grow(CUtlMemory<CLightPreview_Light,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CLightPreview_Light *m_pMemory; // ecx
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
    v7 = 92 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CLightPreview_Light *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (CLightPreview_Light *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099860
// Name: public: int CUtlVector<struct TranslucentObjects_s,class CUtlMemory<struct TranslucentObjects_s,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<TranslucentObjects_s,CUtlMemory<TranslucentObjects_s,int>>::InsertBefore(
        CUtlVector<TranslucentObjects_s,CUtlMemory<TranslucentObjects_s,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  TranslucentObjects_s *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<TranslucentObjects_s,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 176 * v6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10099900
// Name: public: int CUtlVector<class CLightPreview_Light,class CUtlMemory<class CLightPreview_Light,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CLightPreview_Light,CUtlMemory<CLightPreview_Light,int>>::InsertBefore(
        CUtlVector<CLightPreview_Light,CUtlMemory<CLightPreview_Light,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CLightPreview_Light *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CLightPreview_Light,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 92 * v6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1009F390
// Name: public: void CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near *,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>> *,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>> *,int>>::PurgeAndDeleteElements(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *,int> > *this)
{
  int i; // ebx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v3; // edi
  volatile signed __int32 *v4; // eax
  bool v5; // sf
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      v4 = (volatile signed __int32 *)(v3->m_pszData - 16);
      if ( _InterlockedDecrement(v4 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
      operator delete(p: v3);
    }
  }
  v5 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v5 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1650
// Name: public: CUtlMemory<struct VmfSaveLoadHandlerInfo_t,int>::~CUtlMemory<struct VmfSaveLoadHandlerInfo_t,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VmfSaveLoadHandlerInfo_t,int>::~CUtlMemory<VmfSaveLoadHandlerInfo_t,int>(
        CUtlMemory<defaultConfigInfo_t,int> *this)
{
  if ( this->m_nGrowSize >= 0 )
  {
    if ( this->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
      this->m_pMemory = nullptr;
    }
    this->m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1680
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

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100A1BE0
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
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
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
// Address: 0x100A1C90
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

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
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
        if ( &this->m_Memory.m_pMemory[v11] != nullptr )
        {
          CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[v11].fileName);
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
// Address: 0x100A1D80
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // ebx
  int v2; // edi
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+8h] [ebp-10h]

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
// Address: 0x100A1E30
// Name: public: void CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  int v1; // ebx
  int v2; // edi
  fileList_t *v3; // esi
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v4; // [esp+8h] [ebp-10h]

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
// Address: 0x100A1EE0
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
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
  this->m_pElements = this->m_Memory.m_pMemory;
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
// Address: 0x100A21E0
// Name: public: CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::~CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
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
  this->m_pElements = this->m_Memory.m_pMemory;
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
// Address: 0x100A9040
// Name: public: int CUtlVector<unsigned long,class CUtlMemory<unsigned long,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned long,CUtlMemory<unsigned long,int>>::InsertMultipleBefore(
        CUtlVector<CLightingPreviewLightDescription *,CUtlMemory<CLightingPreviewLightDescription *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CLightingPreviewLightDescription **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x100B0B10
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
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
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
// Address: 0x100B0EF0
// Name: public: int CUtlVector<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,class CUtlMemory<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
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
          v11->m_pElements = v11->m_Memory.m_pMemory;
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
// Address: 0x100B1220
// Name: public: void CUtlVector<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,class CUtlMemory<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  int v4; // [esp+8h] [ebp-14h]
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *v5; // [esp+Ch] [ebp-10h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v4 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v5;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v5;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v4 - 20;
      v4 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1460
// Name: public: CUtlVector<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,class CUtlMemory<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::~CUtlVector<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,class CUtlMemory<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::~CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>(
        CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *this)
{
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
  this->m_pElements = this->m_Memory.m_pMemory;
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
// Address: 0x100BB170
// Name: public: int CUtlVector<struct VmfSaveLoadHandlerInfo_t,class CUtlMemory<struct VmfSaveLoadHandlerInfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VmfSaveLoadHandlerInfo_t,CUtlMemory<VmfSaveLoadHandlerInfo_t,int>>::InsertMultipleBefore(
        CUtlVector<VmfSaveLoadHandlerInfo_t,CUtlMemory<VmfSaveLoadHandlerInfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VmfSaveLoadHandlerInfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100C3930
// Name: public: void CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::Remove(
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *this,
        int elem)
{
  volatile signed __int32 *v3; // eax

  v3 = (volatile signed __int32 *)(this->m_Memory.m_pMemory[elem].m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 4 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100CE630
// Name: public: void CUtlVector<struct CFaceEditSheet::StoredFace_t,class CUtlMemory<struct CFaceEditSheet::StoredFace_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFaceEditSheet::StoredFace_t,CUtlMemory<CFaceEditSheet::StoredFace_t,int>>::Remove(
        CUtlVector<CFaceEditSheet::StoredFace_t,CUtlMemory<CFaceEditSheet::StoredFace_t,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 12 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100D9050
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddVectorToTail(class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddVectorToTail(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        const CUtlVector<int,CUtlMemory<int,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // edx
  int *v7; // ecx
  int base; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  base = m_Size;
  CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int>>::EnsureCapacity(
    (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this,
    num: v4 + m_Size);
  this->m_Size += v4;
  v5 = 0;
  if ( v4 > 0 )
  {
    v6 = m_Size;
    do
    {
      v7 = &this->m_Memory.m_pMemory[v6];
      if ( v7 != nullptr )
      {
        *v7 = src->m_Memory.m_pMemory[v5];
        m_Size = base;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < v4 );
  }
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100D91E0
// Name: public: int CUtlVector<class CAnchorDef,class CUtlMemory<class CAnchorDef,int>>::InsertBefore(int,class CAnchorDef const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int>>::InsertBefore(
        CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *this,
        int elem,
        const CAnchorDef *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAnchorDef *m_pMemory; // ecx
  int v7; // eax
  CAnchorDef *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAnchorDef,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100D9280
// Name: public: int CUtlVector<class CTextureGroup __near *,class CUtlMemory<class CTextureGroup __near *,int>>::InsertBefore(int,class CTextureGroup __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CTextureGroup *,CUtlMemory<CTextureGroup *,int>>::InsertBefore(
        CUtlVector<CVisGroup *,CUtlMemory<CVisGroup *,int> > *this,
        int elem,
        CVisGroup **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVisGroup **m_pMemory; // ecx
  int v7; // eax
  CVisGroup **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x100E7530
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<int,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<int,int>,int>::Grow(CUtlMemory<AssetUsageInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  AssetUsageInfo_t *m_pMemory; // ecx

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
      this->m_pMemory = (AssetUsageInfo_t *)_realloc_crt(ptr: m_pMemory, size: 20 * m_nAllocationCount);
    else
      this->m_pMemory = (AssetUsageInfo_t *)MemAlloc_Alloc(nSize: 20 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7E30
// Name: public: void CUtlVector<class CMapFace __near *,class CUtlMemory<class CMapFace __near *,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int>>::EnsureCapacity(
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *this,
        int num)
{
  CMapFace **m_pMemory; // eax
  CMapFace **v4; // edx
  CMapFace **v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
      this->m_pElements = m_pMemory;
    }
    else
    {
      this->m_Memory.m_nAllocationCount = num;
      if ( m_pMemory != nullptr )
      {
        v4 = (CMapFace **)_realloc_crt(ptr: m_pMemory, size: 4 * num);
        this->m_Memory.m_pMemory = v4;
        this->m_pElements = v4;
      }
      else
      {
        v5 = (CMapFace **)MemAlloc_Alloc(nSize: 4 * num);
        this->m_Memory.m_pMemory = v5;
        this->m_pElements = v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8900
// Name: public: int CUtlVector<class CEntityConnection __near *,class CUtlMemory<class CEntityConnection __near *,int>>::AddVectorToTail(class CUtlVector<class CEntityConnection __near *,class CUtlMemory<class CEntityConnection __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int>>::AddVectorToTail(
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *this,
        const CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // edx
  CMapFace **v7; // ecx
  int base; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  base = m_Size;
  CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int>>::EnsureCapacity(this, num: v4 + m_Size);
  this->m_Size += v4;
  v5 = 0;
  if ( v4 > 0 )
  {
    v6 = m_Size;
    do
    {
      v7 = &this->m_Memory.m_pMemory[v6];
      if ( v7 != nullptr )
      {
        *v7 = src->m_Memory.m_pMemory[v5];
        m_Size = base;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < v4 );
  }
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100FB810
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  Vector2D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UsedTexture_t,int>::Grow(
      (CUtlMemory<CDispPaintMgr::DispVertPair_t,int> *)this,
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
// Address: 0x101044E0
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int16 *m_pMemory; // ecx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_realloc_crt(ptr: m_pMemory, size: 2 * m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int16 *)MemAlloc_Alloc(nSize: 2 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104570
// Name: public: int CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>>::InsertBefore(int,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *this,
        int elem,
        const CUtlSymbol *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlSymbol,int>::Grow((CUtlMemory<unsigned short,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_Id = src->m_Id;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10108340
// Name: public: int CUtlVector<class CEntityRespawnInfo,class CUtlMemory<class CEntityRespawnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEntityRespawnInfo,CUtlMemory<CEntityRespawnInfo,int>>::InsertMultipleBefore(
        CUtlVector<CEntityRespawnInfo,CUtlMemory<CEntityRespawnInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEntityRespawnInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UsedTexture_t,int>::Grow(
      (CUtlMemory<CDispPaintMgr::DispVertPair_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10108460
// Name: public: CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *__thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>(
        CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *this,
        int growSize,
        int initSize)
{
  DmElementHandle_t *m_pMemory; // eax

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (DmElementHandle_t *)MemAlloc_Alloc(nSize: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101084E0
// Name: public: CUtlVector<class DetailObjects::DetailModel_t,class CUtlMemory<class DetailObjects::DetailModel_t,int>>::~CUtlVector<class DetailObjects::DetailModel_t,class CUtlMemory<class DetailObjects::DetailModel_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(
        CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *this)
{
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108560
// Name: public: int CUtlVector<struct vgui::KeyBindingMap_t,class CUtlMemory<struct vgui::KeyBindingMap_t,int>>::InsertBefore(int,struct vgui::KeyBindingMap_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
        CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int> > *this,
        int elem,
        const vgui::KeyBindingMap_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::KeyBindingMap_t *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::KeyBindingMap_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v7);
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    vgui::KeyBindingMap_t::KeyBindingMap_t(this: &this->m_Memory.m_pMemory[elem], src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10108610
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CGridNavCell,int>::Grow((CUtlMemory<CGridNavCell,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: &this->m_Memory.m_pMemory[elem], src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101087E0
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num,
        const char *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  char *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10108CD0
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::AddToTail(char const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::AddToTail(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        char *src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  char *m_pMemory; // ecx
  int v6; // eax
  char *v7; // esi

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1010A990
// Name: public: void CUtlVector<struct CToolsRecentFileList::RecentFileInfo_t,class CUtlMemory<struct CToolsRecentFileList::RecentFileInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::RemoveAll(
        CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int> > *this)
{
  int v1; // edx
  int v2; // eax
  char *v3; // esi
  void **v4; // edi
  int v5; // [esp+8h] [ebp-18h]
  CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int> > *v6; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]

  v1 = this->m_Size - 1;
  v6 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 32 * v1;
    v5 = 32 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      v4 = (void **)(v3 + 16);
      *((_DWORD *)v3 + 7) = 0;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *v4 != nullptr )
        {
          free(pMem: *v4);
          this = v6;
          v1 = i;
          *v4 = nullptr;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          free(pMem: *(void **)v3);
          this = v6;
          v1 = i;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 32;
      i = v1;
      v5 -= 32;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010AE40
// Name: public: CUtlVector<struct CToolsRecentFileList::RecentFileInfo_t,class CUtlMemory<struct CToolsRecentFileList::RecentFileInfo_t,int>>::~CUtlVector<struct CToolsRecentFileList::RecentFileInfo_t,class CUtlMemory<struct CToolsRecentFileList::RecentFileInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::~CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>(
        CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int> > *this)
{
  CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E470
// Name: public: void CUtlMemory<struct UsedTexture_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UsedTexture_t,int>::Grow(CUtlMemory<CDispPaintMgr::DispVertPair_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDispPaintMgr::DispVertPair_t *m_pMemory; // ecx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDispPaintMgr::DispVertPair_t *)_realloc_crt(ptr: m_pMemory, size: 8 * m_nAllocationCount);
    else
      this->m_pMemory = (CDispPaintMgr::DispVertPair_t *)MemAlloc_Alloc(nSize: 8 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F980
// Name: public: int CUtlVector<struct UsedTexture_t,class CUtlMemory<struct UsedTexture_t,int>>::InsertBefore(int,struct UsedTexture_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<UsedTexture_t,CUtlMemory<UsedTexture_t,int>>::InsertBefore(
        CUtlVector<MCMSTRUCT,CUtlMemory<MCMSTRUCT,int> > *this,
        int elem,
        const MCMSTRUCT *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MCMSTRUCT *m_pMemory; // ecx
  int v7; // eax
  MCMSTRUCT *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UsedTexture_t,int>::Grow(
      (CUtlMemory<CDispPaintMgr::DispVertPair_t,int> *)this,
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
// Address: 0x10127E40
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct MapFaceRender_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<MapFaceRender_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<MapFaceRender_t,int> *m_pMemory; // ecx

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
      this->m_pMemory = (UtlRBTreeNode_t<MapFaceRender_t,int> *)_realloc_crt(
                                                                  ptr: m_pMemory,
                                                                  size: 36 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<MapFaceRender_t,int> *)MemAlloc_Alloc(nSize: 36 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136710
// Name: public: void CUtlVector<class CMapFace __near *,class CUtlMemory<class CMapFace __near *,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int>>::Purge(
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *this)
{
  bool v2; // sf
  CMapFace **m_pMemory; // eax

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
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136750
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CheckListItem,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = 12 * elem;
      do
      {
        v10 += 12;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10136820
// Name: public: int CUtlVector<struct cplane_t,class CUtlMemory<struct cplane_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<cplane_t,CUtlMemory<cplane_t,int>>::InsertMultipleBefore(
        CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  cplane_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<int,int>,int>::Grow(
      (CUtlMemory<AssetUsageInfo_t,int> *)this,
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
      v10 = 20 * elem;
      do
      {
        v10 += 20;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10136BC0
// Name: public: int CUtlVector<struct CMapOverlay::BlendData_t,class CUtlMemory<struct CMapOverlay::BlendData_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMapOverlay::BlendData_t,CUtlMemory<CMapOverlay::BlendData_t,int>>::InsertMultipleBefore(
        CUtlVector<CMapOverlay::BlendData_t,CUtlMemory<CMapOverlay::BlendData_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMapOverlay::BlendData_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CAMSTRUCT,int>::Grow(
      (CUtlMemory<DetailObjects::DetailObjectGroup_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10137240
// Name: public: void CUtlVector<struct CMapOverlay::ClipFace_t __near *,class CUtlMemory<struct CMapOverlay::ClipFace_t __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int>>::PurgeAndDeleteElements(
        CUtlVector<CMapOverlay::ClipFace_t *,CUtlMemory<CMapOverlay::ClipFace_t *,int> > *this)
{
  int i; // edi
  CMapOverlay::ClipFace_t *v3; // ebx
  bool v4; // sf
  CMapOverlay::ClipFace_t **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CMapOverlay::ClipFace_t::~ClipFace_t(this: this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A430
// Name: public: void CUtlVector<class CMapPath __near *,class CUtlMemory<class CMapPath __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapPath *,CUtlMemory<CMapPath *,int>>::PurgeAndDeleteElements(
        CUtlVector<CMapPath *,CUtlMemory<CMapPath *,int> > *this)
{
  int i; // edi
  CMapPath *v3; // ebx
  bool v4; // sf
  CMapPath **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CMapPath::~CMapPath(this: this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B230
// Name: private: void CUtlVector<class CUtlReference<class CMapClass>,class CUtlBlockMemory<class CUtlReference<class CMapClass>,int>>::InPlaceQuickSort_r(int (*)(class CUtlReference<class CMapClass> const __near *,class CUtlReference<class CMapClass> const __near *),int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InPlaceQuickSort_r(
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *this,
        int (__cdecl *pfnCompare)(const CUtlReference<CMapClass> *, const CUtlReference<CMapClass> *),
        int nLeft,
        int nRight)
{
  int v4; // eax
  int v5; // ebx
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  CUtlReference<CMapClass> **m_pMemory; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  CUtlReference<CMapClass> **v17; // edx
  int v18; // ecx
  int v19; // ebx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  CUtlReference<CMapClass> *v24; // edx
  _DWORD *v25; // eax
  CUtlReference<CMapClass> *v26; // ecx
  CMapClass *v27; // edx
  int v28; // ecx
  int v29; // edx
  _DWORD *v30; // edx
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  CMapClass **v34; // eax
  CUtlReference<CMapClass> *v35; // ecx
  _DWORD *v36; // edx
  int v37; // edx
  CUtlReference<CMapClass> *v38; // ecx
  CMapClass *v39; // edx
  int v40; // ecx
  int v41; // eax
  CMapClass *m_pObject; // [esp+8h] [ebp-28h] BYREF
  CMapClass **v43; // [esp+Ch] [ebp-24h]
  CUtlReference<CMapClass> *v44; // [esp+10h] [ebp-20h]
  int v45; // [esp+14h] [ebp-1Ch]
  CUtlReference<CMapClass> *v46; // [esp+18h] [ebp-18h]
  int nLeftIdx; // [esp+1Ch] [ebp-14h]
  int nRightIdx; // [esp+20h] [ebp-10h]
  int v49; // [esp+2Ch] [ebp-4h]

  v4 = nRight;
  v5 = nLeft;
  nLeftIdx = nLeft;
  nRightIdx = nRight;
  if ( nRight - nLeft > 0 )
  {
    while ( 1 )
    {
      v7 = (nLeft + v4) / 2;
      if ( nLeft <= v7 )
        break;
LABEL_54:
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InPlaceQuickSort_r(
        this,
        pfnCompare,
        nLeft,
        nRight: v7 - 1);
      v5 = v7 + 1;
      nRightIdx = nRight;
      nLeft = v7 + 1;
      nLeftIdx = v7 + 1;
      if ( nRight - (v7 + 1) <= 0 )
        return;
      v4 = nRight;
    }
    while ( 1 )
    {
      if ( nRightIdx < v7 )
        goto LABEL_54;
      v8 = *((_DWORD *)&this->m_Memory + 2);
      v45 = v8 >> 27;
      v9 = (32 * v8) >> 5;
      v46 = &this->m_Memory.m_pMemory[v7 >> v45][v7 & v9];
      if ( pfnCompare(a1: &this->m_Memory.m_pMemory[v5 >> v45][v5 & v9], a2: v46) < 0 )
      {
        do
        {
          if ( v5 > v7 )
            break;
          v10 = *((_DWORD *)&this->m_Memory + 2);
          m_pMemory = this->m_Memory.m_pMemory;
          v12 = v10 >> 27;
          nLeftIdx = v5 + 1;
          v13 = (32 * v10) >> 5;
          ++v5;
          v46 = &m_pMemory[v7 >> v12][v7 & v13];
        }
        while ( pfnCompare(a1: &this->m_Memory.m_pMemory[v5 >> v12][v5 & v13], a2: v46) < 0 );
      }
      v14 = *((_DWORD *)&this->m_Memory + 2);
      v45 = v14 >> 27;
      v15 = (32 * v14) >> 5;
      v46 = &this->m_Memory.m_pMemory[v7 >> (v14 >> 27)][v7 & v15];
      if ( pfnCompare(a1: &this->m_Memory.m_pMemory[nRightIdx >> (v14 >> 27)][nRightIdx & v15], a2: v46) > 0 )
      {
        do
        {
          if ( nRightIdx < v7 )
            break;
          v16 = *((_DWORD *)&this->m_Memory + 2);
          v17 = this->m_Memory.m_pMemory;
          --nRightIdx;
          v18 = v16 >> 27;
          v19 = v7 >> (v16 >> 27);
          v20 = (32 * v16) >> 5;
          v46 = &v17[v19][v7 & v20];
          v21 = pfnCompare(a1: &this->m_Memory.m_pMemory[nRightIdx >> v18][nRightIdx & v20], a2: v46);
          v5 = nLeftIdx;
        }
        while ( v21 > 0 );
      }
      v22 = *((_DWORD *)&this->m_Memory + 2);
      v45 = v22 >> 27;
      v46 = this->m_Memory.m_pMemory[nRightIdx >> (v22 >> 27)];
      v23 = (32 * v22) >> 5;
      nLeftIdx = (int)this->m_Memory.m_pMemory[v5 >> v45];
      v24 = &v46[nRightIdx & v23];
      v25 = (_DWORD *)(nLeftIdx + 12 * (v5 & v23));
      v26 = (CUtlReference<CMapClass> *)v25[2];
      v45 = (int)v24;
      v46 = v26;
      if ( v26 != nullptr )
      {
        v44 = v26;
        m_pObject = v26[2].m_pObject;
        v27 = v26[2].m_pObject;
        if ( v27 != nullptr )
        {
          v27->m_nObjectID = (int)&m_pObject;
          v26 = v46;
        }
        v43 = nullptr;
        v26[2].m_pObject = (CMapClass *)&m_pObject;
      }
      v49 = 0;
      v28 = *(_DWORD *)(v45 + 8);
      v29 = v25[2];
      nLeftIdx = v28;
      if ( v29 != v28 )
      {
        if ( v29 != 0 )
          break;
LABEL_26:
        v25[2] = v28;
        if ( v28 != 0 )
        {
          *v25 = *(_DWORD *)(v28 + 32);
          v33 = *(_DWORD *)(v28 + 32);
          if ( v33 != 0 )
            *(_DWORD *)(v33 + 4) = v25;
          v25[1] = 0;
          *(_DWORD *)(v28 + 32) = v25;
        }
      }
      v34 = (CMapClass **)v45;
      v35 = *(CUtlReference<CMapClass> **)(v45 + 8);
      v46 = v44;
      if ( v35 != v44 )
      {
        if ( v35 != nullptr )
        {
          v36 = *(_DWORD **)(v45 + 4);
          if ( v36 != nullptr )
          {
            *v36 = *(_DWORD *)v45;
            if ( *v34 != nullptr )
              (*v34)->m_nObjectID = (int)v34[1];
          }
          else if ( v35[2].m_pObject == (CMapClass *)v45 )
          {
            v37 = *(_DWORD *)v45;
            v35[2].m_pObject = *(CMapClass **)v45;
            if ( v37 != 0 )
              *(_DWORD *)(v37 + 4) = 0;
          }
          v34[1] = nullptr;
          *v34 = nullptr;
          v34[2] = nullptr;
        }
        v38 = v46;
        v34[2] = (CMapClass *)v46;
        if ( v38 != nullptr )
        {
          *v34 = v38[2].m_pObject;
          v39 = v38[2].m_pObject;
          if ( v39 != nullptr )
            v39->m_nObjectID = (int)v34;
          v34[1] = nullptr;
          v38[2].m_pObject = (CMapClass *)v34;
        }
      }
      v49 = -1;
      if ( v44 != nullptr )
      {
        if ( v43 != nullptr )
        {
          *v43 = m_pObject;
          if ( m_pObject != nullptr )
            m_pObject->m_nObjectID = (int)v43;
        }
        else if ( (CMapClass **)v44[2].m_pObject == &m_pObject )
        {
          v44[2].m_pObject = m_pObject;
          if ( m_pObject != nullptr )
            m_pObject->m_nObjectID = 0;
        }
        v43 = nullptr;
        m_pObject = nullptr;
        v44 = nullptr;
      }
      ++v5;
      --nRightIdx;
      v40 = v5 - 1;
      v41 = nRightIdx + 1;
      nLeftIdx = v5;
      if ( v5 - 1 == v7 )
      {
        ++nRightIdx;
        v7 = v41;
LABEL_53:
        if ( v5 > v7 )
          goto LABEL_54;
      }
      else
      {
        if ( v41 != v7 )
          goto LABEL_53;
        --v5;
        nLeftIdx = v40;
        v7 = v40;
      }
    }
    v30 = (_DWORD *)v25[1];
    if ( v30 != nullptr )
    {
      *v30 = *v25;
      if ( *v25 != 0 )
        *(_DWORD *)(*v25 + 4) = v25[1];
    }
    else
    {
      v31 = v25[2];
      if ( *(_DWORD **)(v31 + 32) != v25 )
      {
LABEL_25:
        v25[1] = 0;
        *v25 = 0;
        v25[2] = 0;
        goto LABEL_26;
      }
      v32 = *v25;
      *(_DWORD *)(v31 + 32) = *v25;
      if ( v32 != 0 )
        *(_DWORD *)(v32 + 4) = 0;
    }
    v28 = nLeftIdx;
    goto LABEL_25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150C50
// Name: public: void CUtlMemory<struct tagGF,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<tagGF,int>::Grow(CUtlMemory<tagGF,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  tagGF *m_pMemory; // ecx
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
    v7 = 276 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (tagGF *)_realloc_crt(ptr: m_pMemory, size: v7);
    else
      this->m_pMemory = (tagGF *)MemAlloc_Alloc(nSize: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101512F0
// Name: public: void CUtlVector<class CMaterialFileChangeWatcher __near *,class CUtlMemory<class CMaterialFileChangeWatcher __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMaterialFileChangeWatcher *,CUtlMemory<CMaterialFileChangeWatcher *,int>>::PurgeAndDeleteElements(
        CUtlVector<CMaterialFileChangeWatcher *,CUtlMemory<CMaterialFileChangeWatcher *,int> > *this)
{
  int i; // ebx
  CMaterialFileChangeWatcher *v3; // edi
  bool v4; // sf
  CMaterialFileChangeWatcher **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CFileChangeWatcher::~CFileChangeWatcher(this: &v3->m_Watcher);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101513A0
// Name: public: int CUtlVector<struct tagGF,class CUtlMemory<struct tagGF,int>>::InsertBefore(int,struct tagGF const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<tagGF,CUtlMemory<tagGF,int>>::InsertBefore(
        CUtlVector<tagGF,CUtlMemory<tagGF,int> > *this,
        int elem,
        const tagGF *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  tagGF *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<tagGF,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 276 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10151910
// Name: public: int CUtlVector<struct TextureContext_t,class CUtlMemory<struct TextureContext_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int>>::InsertBefore(
        CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  TextureContext_t *m_pMemory; // ecx
  int v6; // eax
  TextureContext_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailObjects::DetailModel_t,int>::Grow(
      (CUtlMemory<DetailObjects::DetailModel_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    TextureContext_t::TextureContext_t(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10151DB0
// Name: public: void CUtlVector<struct TextureContext_t,class CUtlMemory<struct TextureContext_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int>>::Purge(
        CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  TextureContext_t *m_pMemory; // eax

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      TextureContext_t::~TextureContext_t(this: &this->m_Memory.m_pMemory[v3--]);
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
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101521C0
// Name: public: CUtlVector<struct TextureContext_t,class CUtlMemory<struct TextureContext_t,int>>::~CUtlVector<struct TextureContext_t,class CUtlMemory<struct TextureContext_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int>>::~CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int>>(
        CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int> > *this)
{
  CUtlVector<TextureContext_t,CUtlMemory<TextureContext_t,int>>::Purge(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158550
// Name: public: void CUtlMemory<struct CAMSTRUCT,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CAMSTRUCT,int>::Grow(CUtlMemory<DetailObjects::DetailObjectGroup_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailObjects::DetailObjectGroup_t *m_pMemory; // ecx

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
      this->m_pMemory = (DetailObjects::DetailObjectGroup_t *)_realloc_crt(
                                                                ptr: m_pMemory,
                                                                size: 24 * m_nAllocationCount);
    else
      this->m_pMemory = (DetailObjects::DetailObjectGroup_t *)MemAlloc_Alloc(nSize: 24 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158C10
// Name: public: void CUtlVector<struct CAMSTRUCT,class CUtlMemory<struct CAMSTRUCT,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CAMSTRUCT,CUtlMemory<CAMSTRUCT,int>>::EnsureCapacity(
        CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *this,
        int num)
{
  CTrackEntry *m_pMemory; // ecx
  CTrackEntry *v4; // eax

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
      v4 = (CTrackEntry *)_realloc_crt(ptr: m_pMemory, size: 24 * num);
    else
      v4 = (CTrackEntry *)MemAlloc_Alloc(nSize: 24 * num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158C80
// Name: public: int CUtlVector<struct ControlInfo_t,class CUtlMemory<struct ControlInfo_t,int>>::InsertBefore(int,struct ControlInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int>>::InsertBefore(
        CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *this,
        int elem,
        const CTrackEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CTrackEntry *m_pMemory; // ecx
  int v7; // eax
  CTrackEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAMSTRUCT,int>::Grow(
      (CUtlMemory<DetailObjects::DetailObjectGroup_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10158D10
// Name: public: int CUtlVector<struct CAMSTRUCT,class CUtlMemory<struct CAMSTRUCT,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAMSTRUCT,CUtlMemory<CAMSTRUCT,int>>::InsertBefore(
        CUtlVector<CAMSTRUCT,CUtlMemory<CAMSTRUCT,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAMSTRUCT *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAMSTRUCT,int>::Grow(
      (CUtlMemory<DetailObjects::DetailObjectGroup_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1015EDA0
// Name: public: void CUtlVector<class CBaseTool __near *,class CUtlMemory<class CBaseTool __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseTool *,CUtlMemory<CBaseTool *,int>>::PurgeAndDeleteElements(
        CUtlVector<CBaseTool *,CUtlMemory<CBaseTool *,int> > *this)
{
  int i; // edi
  CBaseTool *v3; // ecx
  bool v4; // sf
  CBaseTool **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CBaseTool *, int))v3->dtr_CBaseTool)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166900
// Name: public: virtual void Selection3D::Init(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::Init(Selection3D *this, CMapDoc *pDocument)
{
  CBaseTool::Init(this, pDocument);
  this->m_pSelection = pDocument->m_pSelection;
}

//------------------------------------------------------------------------------
// Address: 0x10166930
// Name: public: virtual void Selection3D::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::OnActivate(Selection3D *this)
{
  Box3D::EnableHandles(this, bEnable: true);
}

//------------------------------------------------------------------------------
// Address: 0x10166940
// Name: public: virtual void Selection3D::OnDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::OnDeactivate(Selection3D *this)
{
  Box3D::EnableHandles(this, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x10166950
// Name: protected: void Selection3D::UpdateHandleState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::UpdateHandleState(Selection3D *this)
{
  if ( this->m_bActiveTool && CSelection::IsEditable(this: this->m_pSelection) )
    Box3D::EnableHandles(this, bEnable: true);
  else
    Box3D::EnableHandles(this, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x10166980
// Name: protected: virtual int Selection3D::HitTest(class CMapView __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall Selection3D::HitTest(Selection3D *this, CMapView *pView, const Vector2D *ptClient, bool bTestHandles)
{
  if ( this->IsEmpty(this) )
    return 0;
  else
    return Box3D::HitTest(this, pView, ptClient, bTestHandles);
}

//------------------------------------------------------------------------------
// Address: 0x101669B0
// Name: protected: bool Selection3D::HitTestLogical(class CMapView __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge Selection3D::HitTestLogical@<al>(
        Selection3D *this@<ecx>,
        int a2@<esi>,
        CMapView *pView,
        const Vector2D *ptClient)
{
  bool result; // al
  void (__thiscall *WorldToClient)(CMapView *, Vector2D *, const Vector *); // eax
  POINT v6; // [esp-8h] [ebp-50h]
  CRect rect; // [esp+0h] [ebp-48h] BYREF
  Vector vecMaxs; // [esp+10h] [ebp-38h] BYREF
  Vector vecMins; // [esp+1Ch] [ebp-2Ch] BYREF
  Vector2D vecMaxClient; // [esp+28h] [ebp-20h] BYREF
  Vector2D vecMinClient; // [esp+30h] [ebp-18h] BYREF
  Vector2D vecLogicalMaxs; // [esp+38h] [ebp-10h] BYREF
  Vector2D vecLogicalMins; // [esp+40h] [ebp-8h] BYREF

  result = CSelection::GetLogicalBounds(this: this->m_pSelection, vecMins: &vecLogicalMins, vecMaxs: &vecLogicalMaxs);
  if ( result )
  {
    WorldToClient = pView->WorldToClient;
    vecMins.x = vecLogicalMins.x;
    vecMins.y = vecLogicalMins.y;
    vecMaxs.x = vecLogicalMaxs.x;
    vecMins.z = 0.0;
    vecMaxs.y = vecLogicalMaxs.y;
    vecMaxs.z = 0.0;
    ((void (__thiscall *)(CMapView *, Vector2D *, Vector *, int))WorldToClient)(
      a1: pView,
      a2: &vecMinClient,
      a3: &vecMins,
      a4: a2);
    pView->WorldToClient(this: pView, a2: &vecMaxClient, a3: &vecMaxs);
    rect.left = (int)vecMinClient.x;
    rect.top = (int)vecMinClient.y;
    rect.right = (int)vecMaxClient.x;
    rect.bottom = (int)vecMaxClient.y;
    if ( (int)vecMinClient.x > (int)vecMaxClient.x )
    {
      rect.left = (int)vecMaxClient.x;
      rect.right = (int)vecMinClient.x;
    }
    if ( (int)vecMinClient.y > (int)vecMaxClient.y )
    {
      rect.top = (int)vecMaxClient.y;
      rect.bottom = (int)vecMinClient.y;
    }
    v6.y = (int)ptClient->y;
    v6.x = (int)ptClient->x;
    return PtInRect(lprc: &rect, pt: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166A90
// Name: public: virtual bool Selection3D::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Selection3D::IsEmpty(Selection3D *this)
{
  return !this->m_bBoxSelection && CToolManager::GetActiveTool(this: this->m_pSelection) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10166AB0
// Name: public: void Selection3D::StartLogicalBoxSelection(class CMapViewLogical __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::StartLogicalBoxSelection(Selection3D *this, CMapViewLogical *pView, const Vector *vStart)
{
  this->m_bInLogicalBoxSelection = true;
  this->m_clrLogicalBox = 16777010;
  this->m_vecLogicalSelBoxMaxs.x = vStart->x;
  this->m_vecLogicalSelBoxMaxs.y = vStart->y;
  this->m_vecLogicalSelBoxMins = this->m_vecLogicalSelBoxMaxs;
}

//------------------------------------------------------------------------------
// Address: 0x10166B00
// Name: public: void Selection3D::EndLogicalBoxSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::EndLogicalBoxSelection(Selection3D *this)
{
  CMapDoc *m_pDocument; // ecx

  m_pDocument = this->m_pDocument;
  this->m_clrLogicalBox = Options.colors.clrToolSelection;
  CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 24, ub: nullptr);
  this->m_bInLogicalBoxSelection = false;
}

//------------------------------------------------------------------------------
// Address: 0x10166B30
// Name: DrawObject
// Source: json
//------------------------------------------------------------------------------
int __cdecl DrawObject(CMapClass *pobj, CRender *pRender)
{
  CRender2D *v2; // eax
  CRender3D *v3; // eax

  if ( (*((_BYTE *)pobj + 180) & 2) != 0 )
  {
    pobj->SetSelectionState(this: pobj, a2: SELECT_NONE);
    v2 = (CRender2D *)__RTDynamicCast(
                        inptr: pRender,
                        VfDelta: 0,
                        SrcType: &CRender `RTTI Type Descriptor',
                        TargetType: &CRender2D `RTTI Type Descriptor',
                        isReference: 0);
    if ( v2 != nullptr )
      pobj->Render2D(this: pobj, a2: v2);
    v3 = (CRender3D *)__RTDynamicCast(
                        inptr: pRender,
                        VfDelta: 0,
                        SrcType: &CRender `RTTI Type Descriptor',
                        TargetType: &CRender3D `RTTI Type Descriptor',
                        isReference: 0);
    if ( v3 != nullptr )
      pobj->Render3D(this: pobj, a2: v3);
    pobj->SetSelectionState(this: pobj, a2: SELECT_MODIFY);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10166BB0
// Name: DrawObjectLogical
// Source: json
//------------------------------------------------------------------------------
int __cdecl DrawObjectLogical(CMapClass *pObj, CRender2D *pRender2D)
{
  if ( pObj->IsVisibleLogical(this: pObj) )
  {
    pObj->SetSelectionState(this: pObj, a2: SELECT_NONE);
    if ( pRender2D != nullptr )
      pObj->RenderLogical(this: pObj, a2: pRender2D);
    pObj->SetSelectionState(this: pObj, a2: SELECT_MODIFY);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10166C00
// Name: protected: void Selection3D::SelectInLogicalBox(class CMapDoc __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::SelectInLogicalBox(Selection3D *this, CMapDoc *pDoc, bool bInsideOnly)
{
  float x; // xmm0_4
  float v5; // xmm1_4
  float y; // xmm2_4
  float v7; // xmm3_4
  int v8; // ecx
  Vector2D mins; // [esp+4h] [ebp-10h] BYREF
  Vector2D maxs; // [esp+Ch] [ebp-8h] BYREF

  x = this->m_vecLogicalSelBoxMins.x;
  v5 = this->m_vecLogicalSelBoxMaxs.x;
  y = this->m_vecLogicalSelBoxMins.y;
  v7 = this->m_vecLogicalSelBoxMaxs.y;
  v8 = 0;
  mins.x = x;
  maxs.x = v5;
  mins.y = y;
  maxs.y = v7;
  if ( v5 == x )
  {
    mins.x = -99999.0;
    maxs.x = 99999.0;
    v8 = 1;
  }
  if ( v7 == y )
  {
    mins.y = -99999.0;
    maxs.y = 99999.0;
    ++v8;
  }
  if ( v8 <= 1 )
    CMapDoc::SelectLogicalRegion(this: pDoc, vecMins: &mins, vecMaxs: &maxs, bInsideOnly);
  if ( !CSelection::GetBounds(this: this->m_pSelection, vecMins: &this->bmins, vecMaxs: &this->bmaxs) )
    BoundBox::ResetBounds(this: &this->BoundBox);
}

//------------------------------------------------------------------------------
// Address: 0x10166CC0
// Name: public: virtual bool Selection3D::OnLMouseDblClkLogical(class CMapViewLogical __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnLMouseDblClkLogical(
        Selection3D *this,
        CMapViewLogical *pView,
        CMapViewLogical *nFlags,
        const Vector2D *vPoint)
{
  CMainFrame *MainWnd; // eax

  if ( !CSelection::IsEmpty(this: this->m_pSelection) )
  {
    MainWnd = GetMainWnd();
    CWnd::ShowWindow(this: MainWnd->pObjectProperties, nCmdShow: 5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10166CF0
// Name: protected: class CMapEntity __near * Selection3D::FindEntityInTree(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall Selection3D::FindEntityInTree(Selection3D *this, CMapClass *pObject)
{
  CMapEntity *result; // eax

  do
  {
    result = (CMapEntity *)__RTDynamicCast(
                             inptr: pObject,
                             VfDelta: 0,
                             SrcType: &CMapClass `RTTI Type Descriptor',
                             TargetType: &CMapEntity `RTTI Type Descriptor',
                             isReference: 0);
    if ( result != nullptr )
      break;
    result = (CMapEntity *)pObject->GetParent(this: pObject);
    pObject = result;
  }
  while ( result != nullptr );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166D30
// Name: public: virtual void Selection3D::SetEmpty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::SetEmpty(Selection3D *this)
{
  CSelection *m_pSelection; // ecx

  this->m_vTranslation.x = 0.0;
  this->m_vTranslation.y = 0.0;
  this->m_vTranslation.z = 0.0;
  m_pSelection = this->m_pSelection;
  this->m_bIsTranslating = false;
  CSelection::SelectObject(this: m_pSelection, pObj: nullptr, cmd: 16);
  if ( !CSelection::GetBounds(this: this->m_pSelection, vecMins: &this->bmins, vecMaxs: &this->bmaxs) )
    BoundBox::ResetBounds(this: &this->BoundBox);
}

//------------------------------------------------------------------------------
// Address: 0x10166D80
// Name: protected: void Selection3D::SelectInBox(class CMapDoc __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::SelectInBox(Selection3D *this, CMapDoc *pDoc, bool bInsideOnly)
{
  BoundBox *v4; // eax
  float z; // ecx
  float v6; // edx
  CMapDoc *m_pDocument; // ecx
  int v8; // ecx
  bool v9; // zf
  BoundBox box; // [esp+4h] [ebp-1Ch] BYREF

  if ( this != nullptr )
    v4 = &this->BoundBox;
  else
    v4 = nullptr;
  z = v4->bmins.z;
  v6 = v4->bmaxs.z;
  *(_QWORD *)&box.bmins.x = *(_QWORD *)&v4->bmins.x;
  box.bmins.z = z;
  m_pDocument = this->m_pDocument;
  box.__vftable = (BoundBox_vtbl *)&BoundBox::`vftable';
  *(_QWORD *)&box.bmaxs.x = *(_QWORD *)&v4->bmaxs.x;
  box.bmaxs.z = v6;
  CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 24, ub: nullptr);
  v8 = 0;
  v9 = box.bmaxs.x == box.bmins.x;
  this->m_bBoxSelection = false;
  if ( v9 )
  {
    box.bmins.x = -99999.0;
    box.bmaxs.x = 99999.0;
    v8 = 1;
  }
  if ( box.bmaxs.y == box.bmins.y )
  {
    box.bmins.y = -99999.0;
    box.bmaxs.y = 99999.0;
    ++v8;
  }
  if ( box.bmaxs.z == box.bmins.z )
  {
    box.bmins.z = -99999.0;
    box.bmaxs.z = 99999.0;
    ++v8;
  }
  if ( v8 <= 1 )
    CMapDoc::SelectRegion(this: pDoc, pBox: &box, bInsideOnly, ResetSelection: true);
  if ( !CSelection::GetBounds(this: this->m_pSelection, vecMins: &this->bmins, vecMaxs: &this->bmaxs) )
    BoundBox::ResetBounds(this: &this->BoundBox);
}

//------------------------------------------------------------------------------
// Address: 0x10166E80
// Name: protected: void Selection3D::NudgeObjects(class CMapView __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::NudgeObjects(Selection3D *this, CMapView *pView, int nChar, bool bSnap, bool bClone)
{
  CMapView2DBase *v6; // eax
  CMapView2DBase *v7; // esi
  Vector *p_bmaxs; // ebx
  Vector *p_bmins; // edi
  Vector *flMargin; // [esp+Ch] [ebp-40h]
  Vector vThrd; // [esp+1Ch] [ebp-30h] BYREF
  Vector vecDelta; // [esp+28h] [ebp-24h] BYREF
  Vector vHorz; // [esp+34h] [ebp-18h] BYREF
  Vector vVert; // [esp+40h] [ebp-Ch] BYREF

  pView->GetBestTransformPlane(this: pView, a2: &vHorz, a3: &vVert, a4: &vThrd);
  CMapDoc::GetNudgeVector(this: this->m_pDocument, &vHorz, &vVert, nChar, bSnap, vecNudge: &vecDelta);
  CMapDoc::NudgeObjects(this: this->m_pDocument, Delta: &vecDelta, bClone);
  v6 = (CMapView2DBase *)__RTDynamicCast(
                           inptr: pView,
                           VfDelta: 0,
                           SrcType: &CMapView `RTTI Type Descriptor',
                           TargetType: &CMapView2DBase `RTTI Type Descriptor',
                           isReference: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    p_bmaxs = &this->bmaxs;
    flMargin = &this->bmaxs;
    p_bmins = &this->bmins;
    if ( CMapView2DBase::IsBoxFullyVisible(this: v6, minsWorld: p_bmins, maxsWorld: flMargin)
      && CMapView2DBase::CanBoxFitInView(this: v7, minsWorld: p_bmins, maxsWorld: p_bmaxs) )
    {
      LockWindowUpdate(hWndLock: v7->m_hWnd);
      CMapView2DBase::EnsureVisible(this: v7, vecPos: p_bmins, flMargin: 25.0);
      CMapView2DBase::EnsureVisible(this: v7, vecPos: p_bmaxs, flMargin: 25.0);
      LockWindowUpdate(hWndLock: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166F60
// Name: public: Selection3D::Selection3D(void)
// Source: json
//------------------------------------------------------------------------------
Selection3D *__thiscall Selection3D::Selection3D(Selection3D *this)
{
  Box3D::Box3D(this);
  this->Box3D::Tool3D::CBaseTool::__vftable = (Selection3D_vtbl *)&Selection3D::`vftable'{for `Tool3D'};
  this->Box3D::BoundBox::__vftable = (BoundBox_vtbl *)&Selection3D::`vftable'{for `BoundBox'};
  this->m_bInLogicalBoxSelection = false;
  this->m_bBoxSelection = false;
  this->m_bEyedropper = false;
  *(_WORD *)&this->m_bSelected = 0;
  *(_WORD *)&this->m_bIsLogicalTranslating = 0;
  this->m_bLeftDragged = false;
  this->m_bDrawAsSolidBox = false;
  Box3D::SetDrawFlags(this, dwFlags: 9u);
  Box3D::SetDrawColors(this, dwHandleColor: Options.colors.clrToolHandle, dwBoxColor: Options.colors.clrToolSelection);
  this->m_clrLogicalBox = Options.colors.clrToolSelection;
  this->m_vLDownLogicalClient.x = 0.0;
  this->m_vLDownLogicalClient.y = 0.0;
  this->m_pSelection = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10167080
// Name: protected: class GDinputvariable __near * Selection3D::ChooseEyedropperVar(class CMapView __near *,class CUtlVector<class GDinputvariable __near *,class CUtlMemory<class GDinputvariable __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall Selection3D::ChooseEyedropperVar(
        Selection3D *this,
        CMapView *pView,
        CUtlVector<GDinputvariable *,CUtlMemory<GDinputvariable *,int> > *VarList)
{
  HMENU PopupMenu; // eax
  int m_Size; // edi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  GDinputvariable *v9; // edi
  CPoint point; // [esp+Ch] [ebp-1Ch] BYREF
  CMenu menu; // [esp+14h] [ebp-14h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  menu.m_hMenu = nullptr;
  v12 = 0;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  m_Size = VarList->m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = v5 + 1;
      AppendMenuA(
        hMenu: menu.m_hMenu,
        uFlags: 0,
        uIDNewItem: v5 + 1,
        lpNewItem: VarList->m_Memory.m_pMemory[v5]->m_szLongName);
      v5 = v6;
    }
    while ( v6 < m_Size );
  }
  point.x = 0;
  point.y = 0;
  GetCursorPos(lpPoint: &point);
  v7 = CMenu::TrackPopupMenu(this: &menu, nFlags: 0x180u, x: point.x, y: point.y, pWnd: nullptr, lpRect: nullptr);
  if ( v7 != 0 )
  {
    v9 = VarList->m_Memory.m_pMemory[v7 - 1];
    v12 = -1;
    menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    CMenu::DestroyMenu(this: &menu);
    return v9;
  }
  else
  {
    v12 = -1;
    menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    CMenu::DestroyMenu(this: &menu);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167170
// Name: protected: void Selection3D::TransformSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::TransformSelection(Selection3D *this)
{
  Selection3D *v1; // esi
  CSelection *m_pSelection; // ecx
  const CUtlReferenceVector<CMapClass> *List; // ebx
  int v4; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CMapClass *v7; // esi
  int v8; // eax
  CUtlReference<CMapClass> ref; // [esp+Ch] [ebp-1Ch] BYREF
  Selection3D *v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  v1 = this;
  m_pSelection = this->m_pSelection;
  v10 = v1;
  List = CSelection::GetList(this: m_pSelection);
  v4 = 0;
  if ( List->m_Size > 0 )
  {
    do
    {
      m_pObject = List->m_Memory.m_pMemory[v4 >> (*((int *)&List->m_Memory + 2) >> 27)][v4
                                                                                      & ((32
                                                                                        * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        ref.m_pObject = List->m_Memory.m_pMemory[v4 >> (*((int *)&List->m_Memory + 2) >> 27)][v4
                                                                                            & ((32
                                                                                              * *((_DWORD *)&List->m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
        ref.m_pNext = m_pObject->m_References.m_pHead;
        m_pHead = m_pObject->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &ref;
        ref.m_pPrev = nullptr;
        m_pObject->m_References.m_pHead = &ref;
      }
      v11 = 0;
      v7 = ref.m_pObject;
      v8 = (int)v10->GetTransformMatrix(this: v10);
      v7->DoTransform(this: v7, a2: (const VMatrix *)v8);
      v7->PostUpdate(this: v7, a2: Notify_Transform);
      v11 = -1;
      if ( ref.m_pObject != nullptr )
      {
        if ( ref.m_pPrev != nullptr )
        {
          ref.m_pPrev->m_pNext = ref.m_pNext;
          if ( ref.m_pNext != nullptr )
            ref.m_pNext->m_pPrev = ref.m_pPrev;
        }
        else if ( ref.m_pObject->m_References.m_pHead == &ref )
        {
          ref.m_pObject->m_References.m_pHead = ref.m_pNext;
          if ( ref.m_pNext != nullptr )
            ref.m_pNext->m_pPrev = nullptr;
        }
        memset(&ref, 0, sizeof(ref));
      }
      ++v4;
    }
    while ( v4 < List->m_Size );
    v1 = v10;
  }
  v1->m_pDocument->SetModifiedFlag(this: v1->m_pDocument, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101672A0
// Name: protected: void Selection3D::TransformLogicalSelection(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::TransformLogicalSelection(Selection3D *this, const Vector2D *vecTranslation)
{
  const CUtlReferenceVector<CMapClass> *List; // ebx
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CMapClass *v6; // esi
  float *v7; // eax
  CMainFrame *MainWnd; // eax
  CUtlReference<CMapClass> ref; // [esp+8h] [ebp-20h] BYREF
  Vector2D vecNewPosition; // [esp+14h] [ebp-14h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  List = CSelection::GetList(this: this->m_pSelection);
  for ( i = 0; i < List->m_Size; ++i )
  {
    m_pObject = List->m_Memory.m_pMemory[i >> (*((int *)&List->m_Memory + 2) >> 27)][i
                                                                                   & ((32
                                                                                     * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      ref.m_pObject = List->m_Memory.m_pMemory[i >> (*((int *)&List->m_Memory + 2) >> 27)][i
                                                                                         & ((32
                                                                                           * *((_DWORD *)&List->m_Memory
                                                                                             + 2)) >> 5)].m_pObject;
      ref.m_pNext = m_pObject->m_References.m_pHead;
      m_pHead = m_pObject->m_References.m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = &ref;
      ref.m_pPrev = nullptr;
      m_pObject->m_References.m_pHead = &ref;
    }
    v11 = 0;
    v6 = ref.m_pObject;
    v7 = (float *)((int (*)(void))ref.m_pObject->GetLogicalPosition)();
    vecNewPosition.x = *v7 + vecTranslation->x;
    vecNewPosition.y = v7[1] + vecTranslation->y;
    v6->SetLogicalPosition(this: v6, a2: &vecNewPosition);
    v11 = -1;
    if ( ref.m_pObject != nullptr )
    {
      if ( ref.m_pPrev != nullptr )
      {
        ref.m_pPrev->m_pNext = ref.m_pNext;
        if ( ref.m_pNext != nullptr )
          ref.m_pNext->m_pPrev = ref.m_pPrev;
      }
      else if ( ref.m_pObject->m_References.m_pHead == &ref )
      {
        ref.m_pObject->m_References.m_pHead = ref.m_pNext;
        if ( ref.m_pNext != nullptr )
          ref.m_pNext->m_pPrev = nullptr;
      }
      memset(&ref, 0, sizeof(ref));
    }
  }
  MainWnd = GetMainWnd();
  CObjectProperties::MarkDataDirty(this: MainWnd->pObjectProperties);
}

//------------------------------------------------------------------------------
// Address: 0x101673F0
// Name: public: virtual void Selection3D::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::RenderTool2D(Selection3D *this, CRender2D *pRender)
{
  Selection3D *v2; // ebx
  CSelection *m_pSelection; // ecx
  const CUtlReferenceVector<CMapClass> *List; // edi
  int v5; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  CMapClass *v8; // ebx
  VMatrix matrix; // [esp+4h] [ebp-5Ch] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+44h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v11; // [esp+48h] [ebp-18h]
  CMapClass *pobj; // [esp+4Ch] [ebp-14h]
  Selection3D *v13; // [esp+50h] [ebp-10h]
  int v14; // [esp+5Ch] [ebp-4h]

  v2 = this;
  m_pSelection = this->m_pSelection;
  v13 = v2;
  if ( CSelection::IsEmpty(this: m_pSelection) || !v2->IsTranslating(this: v2) )
  {
    if ( !v2->m_bBoxSelection
      && !CSelection::GetBounds(this: v2->m_pSelection, vecMins: &v2->bmins, vecMaxs: &v2->bmaxs) )
    {
      BoundBox::ResetBounds(this: &v2->BoundBox);
    }
  }
  else if ( !v2->m_bBoxSelection )
  {
    CRender::SetDrawColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
    matrix = *v2->GetTransformMatrix(this: v2);
    CRender::BeginLocalTransfrom(this: pRender, &matrix, MultiplyCurrent: false);
    List = CSelection::GetList(this: v2->m_pSelection);
    v5 = 0;
    if ( List->m_Size > 0 )
    {
      do
      {
        m_pObject = List->m_Memory.m_pMemory[v5 >> (*((int *)&List->m_Memory + 2) >> 27)][v5
                                                                                        & ((32
                                                                                          * *((_DWORD *)&List->m_Memory
                                                                                            + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          pobj = List->m_Memory.m_pMemory[v5 >> (*((int *)&List->m_Memory + 2) >> 27)][v5
                                                                                     & ((32
                                                                                       * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v7 = m_pObject->m_References.m_pHead;
          if ( v7 != nullptr )
            v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v11 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v8 = pobj;
        v14 = -1;
        if ( pobj != nullptr )
        {
          if ( v11 != nullptr )
          {
            v11->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v11;
          }
          else if ( (CUtlReference<CMapClass> **)pobj->m_References.m_pHead == &m_pHead )
          {
            pobj->m_References.m_pHead = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v11 = nullptr;
          m_pHead = nullptr;
          pobj = nullptr;
        }
        DrawObject(pobj: v8, pRender);
        CMapClass::EnumChildren(
          this: v8,
          pfn: (int (__cdecl *)(CMapClass *, unsigned int))DrawObject,
          dwParam: (unsigned int)pRender,
          Type: nullptr);
        ++v5;
      }
      while ( v5 < List->m_Size );
      v2 = v13;
    }
    CRender::EndLocalTransfrom(this: pRender);
  }
  Box3D::RenderTool2D(this: v2, pRender);
}

//------------------------------------------------------------------------------
// Address: 0x101675C0
// Name: public: virtual void Selection3D::RenderToolLogical(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge Selection3D::RenderToolLogical(Selection3D *this@<ecx>, int a2@<edi>, CRender2D *pRender)
{
  Selection3D *v3; // ebx
  CSelection *m_pSelection; // ecx
  VMatrix *v5; // eax
  const CUtlReferenceVector<CMapClass> *List; // ebx
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v9; // ecx
  CMapClass *v10; // esi
  CRender2D *v11; // esi
  float x; // [esp+0h] [ebp-9Ch]
  float y; // [esp+4h] [ebp-98h]
  VMatrix matrix; // [esp+18h] [ebp-84h] BYREF
  Vector mins; // [esp+58h] [ebp-44h] BYREF
  Vector maxs; // [esp+64h] [ebp-38h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+70h] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> *v19; // [esp+74h] [ebp-28h]
  CMapClass *v20; // [esp+78h] [ebp-24h]
  Vector2D vecLogicalMaxs; // [esp+7Ch] [ebp-20h] BYREF
  Vector2D vecLogicalMins; // [esp+84h] [ebp-18h] BYREF
  Selection3D *v23; // [esp+8Ch] [ebp-10h]
  int v24; // [esp+98h] [ebp-4h]

  v3 = this;
  m_pSelection = this->m_pSelection;
  v23 = v3;
  if ( CSelection::IsEmpty(this: m_pSelection) || !v3->m_bIsLogicalTranslating || v3->m_bInLogicalBoxSelection )
  {
    v11 = pRender;
  }
  else
  {
    CRender::SetDrawColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
    v5 = (VMatrix *)v3->GetTransformMatrix(this: v3);
    y = v3->m_vLogicalTranslation.y;
    x = v3->m_vLogicalTranslation.x;
    matrix = *v5;
    MatrixBuildTranslation(dst: &matrix, x, y, z: 0.0);
    CRender::BeginLocalTransfrom(this: pRender, &matrix, MultiplyCurrent: false);
    List = CSelection::GetList(this: v3->m_pSelection);
    for ( i = 0; i < List->m_Size; ++i )
    {
      m_pObject = List->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        v20 = List->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v9 = m_pObject->m_References.m_pHead;
        if ( v9 != nullptr )
          v9->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v19 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v10 = v20;
      v24 = -1;
      if ( v20 != nullptr )
      {
        if ( v19 != nullptr )
        {
          v19->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v19;
        }
        else if ( (CUtlReference<CMapClass> **)v20->m_References.m_pHead == &m_pHead )
        {
          v20->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v19 = nullptr;
        m_pHead = nullptr;
        v20 = nullptr;
      }
      if ( v10->IsVisibleLogical(this: v10) )
      {
        ((void (__thiscall *)(CMapClass *, _DWORD, int))v10->SetSelectionState)(a1: v10, a2: 0, a3: a2);
        if ( pRender != nullptr )
          v10->RenderLogical(this: v10, a2: pRender);
        a2 = 4;
        ((void (__thiscall *)(CMapClass *))v10->SetSelectionState)(a1: v10);
      }
      CMapClass::EnumChildren(
        this: v10,
        pfn: (int (__cdecl *)(CMapClass *, unsigned int))DrawObjectLogical,
        dwParam: (unsigned int)pRender,
        Type: nullptr);
    }
    v11 = pRender;
    CRender::EndLocalTransfrom(this: pRender);
    v3 = v23;
  }
  if ( v3->m_bInLogicalBoxSelection )
  {
    vecLogicalMins = v3->m_vecLogicalSelBoxMins;
    vecLogicalMaxs = v3->m_vecLogicalSelBoxMaxs;
  }
  else if ( !CSelection::GetLogicalBounds(this: v3->m_pSelection, vecMins: &vecLogicalMins, vecMaxs: &vecLogicalMaxs) )
  {
    return;
  }
  mins.x = vecLogicalMins.x;
  mins.y = vecLogicalMins.y;
  maxs.x = vecLogicalMaxs.x;
  mins.z = 0.0;
  maxs.y = vecLogicalMaxs.y;
  maxs.z = 0.0;
  CRender::PushRenderMode(this: v11, eRenderMode: RENDER_MODE_DOTTED);
  CRender::SetDrawColor(
    this: v11,
    r: Options.colors.clrToolDrag,
    g: BYTE1(Options.colors.clrToolDrag),
    b: BYTE2(Options.colors.clrToolDrag));
  CRender2D::DrawRectangle(this: v11, vMins: &mins, vMaxs: &maxs, bFill: false, extent: 2);
  CRender::PopRenderMode(this: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10167890
// Name: public: virtual void Selection3D::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::RenderTool3D(Selection3D *this, CRender3D *pRender)
{
  Selection3D *v2; // esi
  CSelection *m_pSelection; // ecx
  const CUtlReferenceVector<CMapClass> *List; // eax
  int *v5; // ebx
  int v6; // eax
  int v7; // ecx
  int i; // esi
  int v9; // eax
  int v10; // ecx
  CMapClass *v11; // edi
  VMatrix matrix; // [esp+Ch] [ebp-5Ch] BYREF
  SelectionState_t v13; // [esp+4Ch] [ebp-1Ch] BYREF
  SelectionState_t *v14; // [esp+50h] [ebp-18h]
  CMapAtom *pObject; // [esp+54h] [ebp-14h]
  Tool3D *v16; // [esp+58h] [ebp-10h]
  int v17; // [esp+64h] [ebp-4h]

  v2 = this;
  m_pSelection = this->m_pSelection;
  v16 = v2;
  List = CSelection::GetList(this: m_pSelection);
  v5 = (int *)List;
  if ( v2->m_bDrawAsSolidBox )
  {
    if ( List->m_Size != 0 )
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_FLAT);
      v6 = *(_DWORD *)(*(_DWORD *)*v5 + 8);
      if ( v6 != 0 )
      {
        pObject = *(CMapAtom **)(*(_DWORD *)*v5 + 8);
        v13 = *(_DWORD *)(v6 + 32);
        v7 = *(_DWORD *)(v6 + 32);
        if ( v7 != 0 )
          *(_DWORD *)(v7 + 4) = &v13;
        v14 = nullptr;
        *(_DWORD *)(v6 + 32) = &v13;
      }
      v17 = 0;
      CRender3D::BeginRenderHitTarget(this: pRender, pObject, uHandle: 0);
      v17 = -1;
      if ( pObject != nullptr )
      {
        if ( v14 != nullptr )
        {
          *v14 = v13;
          if ( v13 != SELECT_NONE )
            *(_DWORD *)(v13 + 4) = v14;
        }
        else if ( (SelectionState_t *)pObject[1].m_eSelectionState == &v13 )
        {
          pObject[1].m_eSelectionState = v13;
          if ( v13 != SELECT_NONE )
            *(_DWORD *)(v13 + 4) = 0;
        }
        v14 = nullptr;
        v13 = SELECT_NONE;
        pObject = nullptr;
      }
      CRender3D::RenderBox(
        this: pRender,
        Mins: &v2->bmins,
        Maxs: &v2->bmaxs,
        chRed: 0xFFu,
        chGreen: 0xFFu,
        chBlue: 0xFFu,
        eBoxSelectionState: SELECT_NONE);
      CRender3D::EndRenderHitTarget(this: pRender);
      CRender::PopRenderMode(this: pRender);
    }
  }
  else
  {
    if ( CSelection::IsEmpty(this: v2->m_pSelection) || !v2->IsTranslating(this: v2) )
    {
      if ( !v2->m_bBoxSelection
        && !CSelection::GetBounds(this: v2->m_pSelection, vecMins: &v2->bmins, vecMaxs: &v2->bmaxs) )
      {
        BoundBox::ResetBounds(this: &v2->BoundBox);
      }
    }
    else if ( !v2->m_bBoxSelection )
    {
      CRender::SetDrawColor(
        this: pRender,
        r: Options.colors.clrSelection,
        g: BYTE1(Options.colors.clrSelection),
        b: BYTE2(Options.colors.clrSelection));
      matrix = *v2->GetTransformMatrix(this: v2);
      CRender::BeginLocalTransfrom(this: pRender, &matrix, MultiplyCurrent: false);
      for ( i = 0; i < v5[3]; ++i )
      {
        v9 = *(_DWORD *)(*(_DWORD *)(*v5 + 4 * (i >> ((unsigned __int64)v5[2] >> 27)))
                       + 12 * (i & ((32 * v5[2]) >> 5))
                       + 8);
        if ( v9 != 0 )
        {
          pObject = *(CMapAtom **)(*(_DWORD *)(*v5 + 4 * (i >> ((unsigned __int64)v5[2] >> 27)))
                                 + 12 * (i & ((32 * v5[2]) >> 5))
                                 + 8);
          v13 = *(_DWORD *)(v9 + 32);
          v10 = *(_DWORD *)(v9 + 32);
          if ( v10 != 0 )
            *(_DWORD *)(v10 + 4) = &v13;
          v14 = nullptr;
          *(_DWORD *)(v9 + 32) = &v13;
        }
        v11 = (CMapClass *)pObject;
        v17 = -1;
        if ( pObject != nullptr )
        {
          if ( v14 != nullptr )
          {
            *v14 = v13;
            if ( v13 != SELECT_NONE )
              *(_DWORD *)(v13 + 4) = v14;
          }
          else if ( (SelectionState_t *)pObject[1].m_eSelectionState == &v13 )
          {
            pObject[1].m_eSelectionState = v13;
            if ( v13 != SELECT_NONE )
              *(_DWORD *)(v13 + 4) = 0;
          }
          v14 = nullptr;
          v13 = SELECT_NONE;
          pObject = nullptr;
        }
        DrawObject(pobj: v11, pRender);
        CMapClass::EnumChildren(
          this: v11,
          pfn: (int (__cdecl *)(CMapClass *, unsigned int))DrawObject,
          dwParam: (unsigned int)pRender,
          Type: nullptr);
      }
      CRender::EndLocalTransfrom(this: pRender);
      if ( v16->m_pDocument->m_bShowGrid && BYTE2(v16[2].m_vPlaneVert.x) != 0 )
      {
        Tool3D::RenderTranslationPlane(this: v16, pRender);
        v2 = (Selection3D *)v16;
      }
      else
      {
        v2 = (Selection3D *)v16;
      }
    }
    if ( v2->m_b3DEditMode )
      Box3D::RenderTool3D(this: v2, pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167B80
// Name: protected: class CBaseTool __near * Selection3D::GetToolObject(class CMapView2D __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseTool *__thiscall Selection3D::GetToolObject(
        Selection3D *this,
        CMapView2D *pView,
        const Vector2D *vPoint,
        BOOL bAttach)
{
  const CUtlReferenceVector<CMapClass> *List; // edi
  int v5; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  CMapClass *v8; // ecx
  CBaseTool *result; // eax
  HitInfo_s HitData; // [esp+Ch] [ebp-64h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+58h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v12; // [esp+5Ch] [ebp-14h]
  CMapClass *v13; // [esp+60h] [ebp-10h]
  int v14; // [esp+6Ch] [ebp-4h]

  List = CSelection::GetList(this: this->m_pSelection);
  v5 = 0;
  if ( List->m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    m_pObject = List->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      v13 = List->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v7 = m_pObject->m_References.m_pHead;
      if ( v7 != nullptr )
        v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v12 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v8 = v13;
    v14 = -1;
    if ( v13 != nullptr )
    {
      if ( v12 != nullptr )
      {
        v12->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v12;
      }
      else if ( (CUtlReference<CMapClass> **)v13->m_References.m_pHead == &m_pHead )
      {
        v13->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v12 = nullptr;
      m_pHead = nullptr;
      v13 = nullptr;
    }
    if ( v8->HitTest2D(this: v8, a2: pView, a3: vPoint, a4: &HitData) )
    {
      result = HitData.pObject->GetToolObject(this: HitData.pObject, a2: HitData.uData, a3: bAttach);
      if ( result != nullptr )
        break;
    }
    if ( ++v5 >= List->m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10167CA0
// Name: protected: class CBaseTool __near * Selection3D::GetToolObjectLogical(class CMapViewLogical __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseTool *__thiscall Selection3D::GetToolObjectLogical(
        Selection3D *this,
        CMapViewLogical *pView,
        const Vector2D *vPoint,
        BOOL bAttach)
{
  const CUtlReferenceVector<CMapClass> *List; // edi
  int v5; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  CMapClass *v8; // ecx
  CBaseTool *result; // eax
  HitInfo_s HitData; // [esp+Ch] [ebp-64h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+58h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v12; // [esp+5Ch] [ebp-14h]
  CMapClass *v13; // [esp+60h] [ebp-10h]
  int v14; // [esp+6Ch] [ebp-4h]

  List = CSelection::GetList(this: this->m_pSelection);
  v5 = 0;
  if ( List->m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    m_pObject = List->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      v13 = List->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v7 = m_pObject->m_References.m_pHead;
      if ( v7 != nullptr )
        v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v12 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v8 = v13;
    v14 = -1;
    if ( v13 != nullptr )
    {
      if ( v12 != nullptr )
      {
        v12->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v12;
      }
      else if ( (CUtlReference<CMapClass> **)v13->m_References.m_pHead == &m_pHead )
      {
        v13->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v12 = nullptr;
      m_pHead = nullptr;
      v13 = nullptr;
    }
    if ( v8->HitTestLogical(this: v8, a2: pView, a3: vPoint, a4: &HitData) )
    {
      result = HitData.pObject->GetToolObject(this: HitData.pObject, a2: HitData.uData, a3: bAttach);
      if ( result != nullptr )
        break;
    }
    if ( ++v5 >= List->m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10167DC0
// Name: public: virtual bool Selection3D::OnContextMenu2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Selection3D::OnContextMenu2D(
        Selection3D *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CBaseTool *ToolObject; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  int v13; // eax
  HWND__ *m_hWnd; // edx
  CPoint ptScreen; // [esp+Ch] [ebp-14h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]
  const Vector2D *vPointa; // [esp+30h] [ebp+10h]

  ToolObject = Selection3D::GetToolObject(this, pView, vPoint, bAttach: true);
  if ( ToolObject != nullptr )
    return ToolObject->OnContextMenu2D(this: ToolObject, a2: pView, a3: nFlags, a4: vPoint);
  if ( (_S1_26 & 1) == 0 )
  {
    _S1_26 |= 1u;
    menu_4.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menu_4.m_hMenu = nullptr;
    atexit(func: Selection3D::OnContextMenu2D_::_5_::_dynamic_atexit_destructor_for__menu__);
    v16 = -1;
  }
  if ( (_S1_26 & 2) == 0 )
  {
    _S1_26 |= 2u;
    menuSelection.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menuSelection.m_hMenu = nullptr;
    atexit(func: Selection3D::OnContextMenu2D_::_5_::_dynamic_atexit_destructor_for__menuSelection__);
    v16 = -1;
  }
  if ( !bInit_10 )
  {
    bInit_10 = true;
    ModuleState = AfxGetModuleState();
    MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)0xB6);
    CMenu::Attach(this: &menu_4, hMenu: MenuW);
    SubMenu = GetSubMenu(hMenu: menu_4.m_hMenu, nPos: 0);
    CMenu::Attach(this: &menuSelection, hMenu: SubMenu);
  }
  x = vPoint->x;
  if ( vPoint->x < 0.0 )
    return false;
  y = vPoint->y;
  vPointa = (const Vector2D *)&vPoint->y;
  if ( y < 0.0
    || (float)pView->m_ClientWidth <= x
    || (float)pView->m_ClientHeight <= y
    || this->IsEmpty(this)
    || this->m_bBoxSelection
    || this->HitTest(this, a2: &pView->CMapView, a3: vPoint, a4: false) == 0 )
  {
    return false;
  }
  v13 = (int)vPointa->x;
  m_hWnd = pView->m_hWnd;
  ptScreen.x = (int)vPoint->x;
  ptScreen.y = v13;
  ClientToScreen(hWnd: m_hWnd, lpPoint: &ptScreen);
  CMenu::TrackPopupMenu(this: &menuSelection, nFlags: 2u, x: ptScreen.x, y: ptScreen.y, pWnd: pView, lpRect: nullptr);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10167FB0
// Name: public: virtual bool Selection3D::OnContextMenuLogical(class CMapViewLogical __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Selection3D::OnContextMenuLogical(
        Selection3D *this,
        CMapViewLogical *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CBaseTool *ToolObjectLogical; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  float y; // xmm0_4
  int v10; // edx
  HWND__ *m_hWnd; // [esp-8h] [ebp-28h]
  CPoint ptScreen; // [esp+Ch] [ebp-14h] BYREF
  int v13; // [esp+1Ch] [ebp-4h]

  ptScreen.y = (int)this;
  ToolObjectLogical = Selection3D::GetToolObjectLogical(this, pView, vPoint, bAttach: true);
  if ( ToolObjectLogical != nullptr )
    return ToolObjectLogical->OnContextMenuLogical(this: ToolObjectLogical, a2: pView, a3: nFlags, a4: vPoint);
  if ( (_S2_8 & 1) == 0 )
  {
    _S2_8 |= 1u;
    menu_5.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menu_5.m_hMenu = nullptr;
    atexit(func: Selection3D::OnContextMenuLogical_::_4_::_dynamic_atexit_destructor_for__menu__);
    v13 = -1;
  }
  if ( (_S2_8 & 2) == 0 )
  {
    _S2_8 |= 2u;
    menuSelection_0.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menuSelection_0.m_hMenu = nullptr;
    atexit(func: Selection3D::OnContextMenuLogical_::_4_::_dynamic_atexit_destructor_for__menuSelection__);
    v13 = -1;
  }
  if ( !bInit_11 )
  {
    bInit_11 = true;
    ModuleState = AfxGetModuleState();
    MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)0xB6);
    CMenu::Attach(this: &menu_5, hMenu: MenuW);
    SubMenu = GetSubMenu(hMenu: menu_5.m_hMenu, nPos: 8);
    CMenu::Attach(this: &menuSelection_0, hMenu: SubMenu);
  }
  if ( vPoint->x < 0.0 )
    return false;
  y = vPoint->y;
  if ( y < 0.0
    || (float)pView->m_ClientWidth <= vPoint->x
    || (float)pView->m_ClientHeight <= y
    || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)ptScreen.y + 16))(a1: ptScreen.y) != 0
    || *(_BYTE *)(ptScreen.y + 308) != 0
    || !Selection3D::HitTestLogical(
          this: (Selection3D *)ptScreen.y,
          a2: (int)pView,
          pView: &pView->CMapView,
          ptClient: vPoint) )
  {
    return false;
  }
  v10 = (int)vPoint->y;
  ptScreen.x = (int)vPoint->x;
  m_hWnd = pView->m_hWnd;
  ptScreen.y = v10;
  ClientToScreen(hWnd: m_hWnd, lpPoint: &ptScreen);
  CMenu::TrackPopupMenu(this: &menuSelection_0, nFlags: 2u, x: ptScreen.x, y: ptScreen.y, pWnd: pView, lpRect: nullptr);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10168190
// Name: public: virtual bool Selection3D::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Selection3D::OnLMouseDown2D(
        Selection3D *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CBaseTool *ToolObject; // eax
  bool v7; // zf
  CMapView *v8; // eax
  bool v9; // al
  CMapView *v10; // eax

  if ( (nFlags & 4) == 0 )
  {
    ToolObject = Selection3D::GetToolObject(this, pView, vPoint, bAttach: true);
    if ( ToolObject != nullptr )
      return ToolObject->OnLMouseDown2D(this: ToolObject, a2: pView, a3: nFlags, a4: vPoint);
  }
  Tool3D::OnLMouseDown2D(this, pView, nFlags, vPoint);
  v7 = !this->m_bBoxSelection;
  this->m_bSelected = false;
  if ( !v7 )
  {
    v8 = pView != nullptr ? &pView->CMapView : nullptr;
    if ( this->HitTest(this, a2: v8, a3: vPoint, a4: true) == 0 )
    {
      CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 24, ub: nullptr);
      this->m_bBoxSelection = false;
    }
  }
  if ( (nFlags & 8) != 0 )
  {
    v9 = CMapView::SelectAt(this: &pView->CMapView, ptClient: vPoint, bMakeFirst: false, bFace: false);
  }
  else
  {
    if ( !this->IsEmpty(this) )
    {
      v10 = pView != nullptr ? &pView->CMapView : nullptr;
      if ( this->HitTest(this, a2: v10, a3: vPoint, a4: true) != 0 )
        return true;
    }
    this->m_TranslateMode = modeScale;
    v9 = CMapView::SelectAt(this: &pView->CMapView, ptClient: vPoint, bMakeFirst: true, bFace: false);
  }
  v7 = !this->m_bActiveTool;
  this->m_bSelected = v9;
  if ( !v7 && CSelection::IsEditable(this: this->m_pSelection) )
  {
    Box3D::EnableHandles(this, bEnable: true);
    return true;
  }
  Box3D::EnableHandles(this, bEnable: false);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101682B0
// Name: protected: virtual unsigned int Selection3D::GetConstraints(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall Selection3D::GetConstraints(Selection3D *this, unsigned int nKeyFlags)
{
  char v2; // bl
  int result; // eax
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v6; // ecx
  CMapClass *v7; // ecx
  bool v8; // zf
  CUtlReference<CMapClass> *m_pHead; // [esp+Ch] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v10; // [esp+10h] [ebp-14h]
  CMapClass *v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+20h] [ebp-4h]
  unsigned int uConstraints; // [esp+2Ch] [ebp+8h]

  v2 = nKeyFlags;
  result = Tool3D::GetConstraints(this, nKeyFlags);
  uConstraints = result;
  if ( this->m_TranslateMode == modeRotate && ((v2 & 4) != 0 || Options.view2d.bRotateConstrain == 0) )
  {
    uConstraints = 0;
    result = 0;
  }
  if ( (result & 4) != 0 )
  {
    if ( CToolManager::GetActiveTool(this: this->m_pSelection) == 1 )
    {
      m_pObject = (*CSelection::GetList(this: this->m_pSelection)->m_Memory.m_pMemory)->m_pObject;
      if ( m_pObject != nullptr )
      {
        v11 = m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v6 = m_pObject->m_References.m_pHead;
        if ( v6 != nullptr )
          v6->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v10 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v7 = v11;
      v12 = -1;
      if ( v11 != nullptr )
      {
        if ( v10 != nullptr )
        {
          v10->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v10;
        }
        else if ( (CUtlReference<CMapClass> **)v11->m_References.m_pHead == &m_pHead )
        {
          v11->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v10 = nullptr;
        m_pHead = nullptr;
        v11 = nullptr;
      }
      v8 = !v7->ShouldSnapToHalfGrid(this: v7);
      result = uConstraints;
      if ( !v8 )
        return uConstraints | 0x10;
    }
    else
    {
      return uConstraints;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101683F0
// Name: protected: void Selection3D::FinishTranslation(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::FinishTranslation(Selection3D *this, bool bSave, bool bClone)
{
  const CUtlReferenceVector<CMapClass> *List; // eax
  const CUtlReferenceVector<CMapClass> *v5; // edi
  CHistory *History; // eax
  CHistory *v7; // eax
  CHistory *v8; // eax
  CHistory *v9; // eax
  const CUtlReferenceVector<CMapClass> *v10; // [esp-Ch] [ebp-14h]
  const CUtlReferenceVector<CMapClass> *v11; // [esp-Ch] [ebp-14h]

  List = CSelection::GetList(this: this->m_pSelection);
  v5 = List;
  if ( bClone && this->m_TranslateMode == modeMove )
  {
    v10 = List;
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: v10, pszName: "Clone Objects", bFromOpposite: 0);
    CMapDoc::CloneObjects(this: this->m_pDocument, Objects: v5);
    v7 = GetHistory();
    CHistory::KeepNew(this: v7, pList: v5, bKeepChildren: true);
  }
  else
  {
    v11 = List;
    v8 = GetHistory();
    CHistory::MarkUndoPosition(this: v8, pSelection: v11, pszName: "Translation", bFromOpposite: 0);
    v9 = GetHistory();
    CHistory::Keep(this: v9, pList: v5);
  }
  if ( bSave )
    Selection3D::TransformSelection(this);
  Box3D::FinishTranslation(this, bSave);
  if ( bSave )
  {
    if ( !CSelection::GetBounds(this: this->m_pSelection, vecMins: &this->bmins, vecMaxs: &this->bmaxs) )
      BoundBox::ResetBounds(this: &this->BoundBox);
    NotifyDuplicates(pList: v5);
  }
  CSelection::SetSelectionState(this: this->m_pSelection, eSelectionState: SELECT_NORMAL);
}

//------------------------------------------------------------------------------
// Address: 0x101684C0
// Name: protected: void Selection3D::StartTranslation(class CMapView __near *,class Vector2D const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::StartTranslation(
        Selection3D *this,
        CMapView *pView,
        const Vector2D *vPoint,
        const Vector *vHandleOrigin)
{
  CSelection *m_pSelection; // ecx
  float y; // xmm1_4
  float z; // xmm1_4
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v9; // ecx
  CMapClass *v10; // edi
  Vector *v11; // edi
  float v12; // xmm1_4
  float v13; // xmm1_4
  Vector vCustomHandleBox[2]; // [esp+Ch] [ebp-40h] BYREF
  Vector refPoint; // [esp+24h] [ebp-28h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+30h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v17; // [esp+34h] [ebp-18h]
  CMapClass *v18; // [esp+38h] [ebp-14h]
  Vector *pRefPoint; // [esp+3Ch] [ebp-10h]
  int v20; // [esp+48h] [ebp-4h]

  m_pSelection = this->m_pSelection;
  pRefPoint = nullptr;
  if ( CToolManager::GetActiveTool(this: m_pSelection) == 1
    && (vHandleOrigin->x > -0.0099999998
     && vHandleOrigin->x < 0.0099999998
     && (y = vHandleOrigin->y) > -0.0099999998
     && y < 0.0099999998
     && (z = vHandleOrigin->z) > -0.0099999998
     && z < 0.0099999998
     || this->m_TranslateMode == modeRotate) )
  {
    m_pObject = (*CSelection::GetList(this: this->m_pSelection)->m_Memory.m_pMemory)->m_pObject;
    if ( m_pObject != nullptr )
    {
      v18 = m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v9 = m_pObject->m_References.m_pHead;
      if ( v9 != nullptr )
        v9->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v17 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v10 = v18;
    v20 = -1;
    if ( v18 != nullptr )
    {
      if ( v17 != nullptr )
      {
        v17->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v17;
      }
      else if ( (CUtlReference<CMapClass> **)v18->m_References.m_pHead == &m_pHead )
      {
        v18->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v17 = nullptr;
      m_pHead = nullptr;
      v18 = nullptr;
    }
    if ( v10->IsMapClass(this: v10, a2: CMapEntity::__Type) != 0
      && (*((_BYTE *)&v10[1].m_Dependents.m_Memory + 8) & 1) != 0 )
    {
      v10->GetOrigin(this: v10, a2: &refPoint);
      pRefPoint = &refPoint;
    }
  }
  v11 = nullptr;
  if ( vHandleOrigin->x > -0.0099999998 && vHandleOrigin->x < 0.0099999998 )
  {
    v12 = vHandleOrigin->y;
    if ( v12 > -0.0099999998 && v12 < 0.0099999998 )
    {
      v13 = vHandleOrigin->z;
      if ( v13 > -0.0099999998 && v13 < 0.0099999998 )
      {
        v11 = vCustomHandleBox;
        CSelection::GetBoundsForTranslation(
          this: this->m_pSelection,
          vecMins: vCustomHandleBox,
          vecMaxs: &vCustomHandleBox[1]);
      }
    }
  }
  Box3D::StartTranslation(this, pView, vPoint, vHandleOrigin, pRefPoint, pCustomHandleBox: v11);
  if ( !CSelection::IsEmpty(this: this->m_pSelection)
    && !CSelection::GetBounds(this: this->m_pSelection, vecMins: &this->bmins, vecMaxs: &this->bmaxs) )
  {
    BoundBox::ResetBounds(this: &this->BoundBox);
  }
  CSelection::SetSelectionState(this: this->m_pSelection, eSelectionState: SELECT_MODIFY);
}

//------------------------------------------------------------------------------
// Address: 0x101686D0
// Name: public: virtual bool Selection3D::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnLMouseUp2D(
        Selection3D *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  bool IsEditable; // bl
  CMapView *v7; // eax
  CMapView *v8; // eax
  bool bShift; // [esp+18h] [ebp+Ch]

  bShift = (nFlags & 4) != 0;
  Tool3D::OnLMouseUp3D(this, (CMapView3D *)pView, nFlags, vPoint);
  IsEditable = CSelection::IsEditable(this: this->m_pSelection);
  if ( !this->IsTranslating(this) )
  {
    if ( !this->m_bSelected && !CSelection::IsEmpty(this: this->m_pSelection) && IsEditable )
    {
      v7 = pView != nullptr ? &pView->CMapView : nullptr;
      if ( this->HitTest(this, a2: v7, a3: vPoint, a4: false) != 0 )
      {
        this->ToggleTranslateMode(this);
        if ( pView != nullptr )
          v8 = &pView->CMapView;
        else
          v8 = nullptr;
        Box3D::UpdateCursor(
          this,
          pView: v8,
          vHandleHit: &this->m_LastHitTestHandle,
          eTransformMode: this->m_TranslateMode);
        CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
      }
    }
LABEL_20:
    CMapDoc::UpdateStatusbar(this: this->m_pDocument);
    return 1;
  }
  if ( !this->m_bBoxSelection )
  {
    Selection3D::FinishTranslation(this, bSave: true, bClone: bShift);
    CMapDoc::UpdateStatusbar(this: this->m_pDocument);
    return 1;
  }
  Box3D::FinishTranslation(this, bSave: true);
  if ( Options.view2d.bAutoSelect == 0 )
    goto LABEL_20;
  Selection3D::SelectInBox(this, pDoc: this->m_pDocument, bInsideOnly: bShift);
  if ( this->m_bActiveTool && CSelection::IsEditable(this: this->m_pSelection) )
  {
    Box3D::EnableHandles(this, bEnable: true);
    CMapDoc::UpdateStatusbar(this: this->m_pDocument);
    return 1;
  }
  else
  {
    Box3D::EnableHandles(this, bEnable: false);
    CMapDoc::UpdateStatusbar(this: this->m_pDocument);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168830
// Name: public: virtual bool Selection3D::OnLMouseDownLogical(class CMapViewLogical __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Selection3D::OnLMouseDownLogical(
        Selection3D *this,
        CMapViewLogical *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CBaseTool *ToolObjectLogical; // eax
  HWND v7; // eax
  bool v8; // zf

  if ( (nFlags & 4) == 0 )
  {
    ToolObjectLogical = Selection3D::GetToolObjectLogical(this, pView, vPoint, bAttach: true);
    if ( ToolObjectLogical != nullptr )
      return ToolObjectLogical->OnLMouseDownLogical(this: ToolObjectLogical, a2: pView, a3: nFlags, a4: vPoint);
  }
  this->m_bLButtonDown = true;
  this->m_vLDownLogicalClient = *vPoint;
  v7 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v7);
  v8 = !this->m_bInLogicalBoxSelection;
  this->m_bLeftDragged = false;
  this->m_bSelected = false;
  if ( !v8 )
  {
    this->m_clrLogicalBox = Options.colors.clrToolSelection;
    CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 24, ub: nullptr);
    this->m_bInLogicalBoxSelection = false;
  }
  if ( GetKeyState(nVirtKey: 18) < 0 )
  {
    this->m_bSelected = CMapViewLogical::SelectAtCascading(this: pView, ptClient: vPoint, bMakeFirst: (nFlags & 8) == 0);
    return true;
  }
  else
  {
    if ( (nFlags & 8) != 0
      || this->IsEmpty(this)
      || !Selection3D::HitTestLogical(this, a2: (int)this, pView: &pView->CMapView, ptClient: vPoint) )
    {
      this->m_bSelected = CMapView::SelectAt(
                            this: &pView->CMapView,
                            ptClient: vPoint,
                            bMakeFirst: (nFlags & 8) == 0,
                            bFace: false);
    }
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168960
// Name: public: virtual bool Selection3D::OnMouseMoveLogical(class CMapViewLogical __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnMouseMoveLogical(
        Selection3D *this,
        CMapViewLogical *pView,
        char nFlags,
        const Vector2D *vPoint)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float x; // xmm0_4
  float v10; // xmm1_4
  float y; // xmm0_4
  float v12; // xmm1_4
  HWND v13; // eax
  CMapView *v14; // eax
  char szBuf[128]; // [esp+1Ch] [ebp-94h] BYREF
  Vector ptOrg; // [esp+9Ch] [ebp-14h] BYREF
  Vector2D vecWorld; // [esp+A8h] [ebp-8h] BYREF
  unsigned int hCursor; // [esp+C0h] [ebp+10h]

  if ( this->m_bLButtonDown )
  {
    if ( !this->m_bLeftDragged
      && (fabs(vPoint->x - this->m_vLDownLogicalClient.x) > 2.0 || fabs(vPoint->y - this->m_vLDownLogicalClient.y) > 2.0) )
    {
      this->m_bLeftDragged = true;
    }
    CMapView2DBase::ToolScrollToPoint(this: pView, ptClient: vPoint);
  }
  CMapViewLogical::ClientToWorld(this: pView, vWorld: &vecWorld, vClient: vPoint);
  sprintf(string: szBuf, format: " @%.0f, %.0f ", vecWorld.x, vecWorld.y);
  SetStatusText(nIndex: 2, pszText: szBuf);
  if ( this->m_bIsLogicalTranslating )
  {
    v6 = vecWorld.x - this->m_vLastLogicalDragPoint.x;
    v7 = vecWorld.y - this->m_vLastLogicalDragPoint.y;
    this->m_vLastLogicalDragPoint = vecWorld;
    this->m_vLogicalTranslation.x = v6 + this->m_vLogicalTranslation.x;
    this->m_vLogicalTranslation.y = this->m_vLogicalTranslation.y + v7;
    pView->UpdateView(this: &pView->CMapView, a2: 16);
    return 1;
  }
  if ( this->m_bInLogicalBoxSelection && (nFlags & 1) != 0 )
  {
    pView->ClientToWorld(this: &pView->CMapView, a2: &ptOrg, a3: &this->m_vLDownLogicalClient);
    x = ptOrg.x;
    v10 = vecWorld.x;
    if ( ptOrg.x <= vecWorld.x )
    {
      this->m_vecLogicalSelBoxMins.x = ptOrg.x;
      this->m_vecLogicalSelBoxMaxs.x = v10;
    }
    else
    {
      this->m_vecLogicalSelBoxMins.x = vecWorld.x;
      this->m_vecLogicalSelBoxMaxs.x = x;
    }
    y = ptOrg.y;
    v12 = vecWorld.y;
    if ( ptOrg.y <= vecWorld.y )
    {
      this->m_vecLogicalSelBoxMins.y = ptOrg.y;
      this->m_vecLogicalSelBoxMaxs.y = v12;
    }
    else
    {
      this->m_vecLogicalSelBoxMins.y = vecWorld.y;
      this->m_vecLogicalSelBoxMaxs.y = y;
    }
    pView->UpdateView(this: &pView->CMapView, a2: 16);
    return 1;
  }
  else
  {
    if ( this->m_bLButtonDown && (nFlags & 1) != 0 && this->m_bLeftDragged )
    {
      v13 = SetCapture(hWnd: pView->m_hWnd);
      CWnd::FromHandle(hWnd: v13);
      if ( Selection3D::HitTestLogical(
             this,
             a2: (int)this,
             pView: &pView->CMapView,
             ptClient: &this->m_vLDownLogicalClient) )
      {
        CMapViewLogical::ClientToWorld(
          this: pView,
          vWorld: &this->m_vLastLogicalDragPoint,
          vClient: &this->m_vLDownLogicalClient);
        this->m_vLogicalTranslation.x = 0.0;
        this->m_vLogicalTranslation.y = 0.0;
        this->m_bIsLogicalTranslating = true;
        CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: 0xCu);
        CSelection::SetSelectionState(this: this->m_pSelection, eSelectionState: SELECT_MODIFY);
        return 1;
      }
      if ( !this->m_bSelected )
      {
        pView->ClientToWorld(this: &pView->CMapView, a2: &ptOrg, a3: &this->m_vLDownLogicalClient);
        Selection3D::StartLogicalBoxSelection(this, pView, vStart: &ptOrg);
        return 1;
      }
    }
    else
    {
      hCursor = 2;
      if ( !this->IsEmpty(this) )
      {
        if ( Selection3D::GetToolObjectLogical(this, pView, vPoint, bAttach: false) != nullptr )
        {
          hCursor = 6;
        }
        else
        {
          if ( pView != nullptr )
            v14 = &pView->CMapView;
          else
            v14 = nullptr;
          if ( Selection3D::HitTestLogical(this, a2: (int)this, pView: v14, ptClient: vPoint) )
            hCursor = 12;
        }
      }
      CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: hCursor);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168C80
// Name: public: virtual bool Selection3D::OnLMouseUpLogical(class CMapViewLogical __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnLMouseUpLogical(
        Selection3D *this,
        CMapViewLogical *pView,
        char nFlags,
        const Vector2D *vPoint)
{
  CSelection *m_pSelection; // ecx
  const CUtlReferenceVector<CMapClass> *List; // eax
  const CUtlReferenceVector<CMapClass> *v7; // edi
  CMapDoc *m_pDocument; // ecx
  CHistory *History; // eax
  CHistory *v10; // eax
  CHistory *v11; // eax
  CSelection *v12; // ecx
  const CUtlReferenceVector<CMapClass> *v14; // [esp-Ch] [ebp-18h]
  CMapDoc *v15; // [esp-8h] [ebp-14h]
  bool bShift; // [esp+8h] [ebp-4h]

  bShift = GetKeyState(nVirtKey: 16) < 0;
  ReleaseCapture();
  m_pSelection = this->m_pSelection;
  this->m_bLButtonDown = false;
  List = CSelection::GetList(this: m_pSelection);
  v7 = List;
  if ( this->m_bInLogicalBoxSelection )
  {
    if ( Options.view2d.bAutoSelect != 0 )
    {
      m_pDocument = this->m_pDocument;
      this->m_clrLogicalBox = Options.colors.clrToolSelection;
      CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 24, ub: nullptr);
      v15 = this->m_pDocument;
      this->m_bInLogicalBoxSelection = false;
      Selection3D::SelectInLogicalBox(this, pDoc: v15, bInsideOnly: bShift);
    }
LABEL_11:
    CSelection::SetSelectionState(this: this->m_pSelection, eSelectionState: SELECT_NORMAL);
    goto updateStatusBar;
  }
  if ( this->m_bIsLogicalTranslating )
  {
    v14 = List;
    History = GetHistory();
    if ( (nFlags & 4) != 0 )
    {
      CHistory::MarkUndoPosition(this: History, pSelection: v14, pszName: "Clone Objects", bFromOpposite: 0);
      CMapDoc::CloneObjects(this: this->m_pDocument, Objects: v7);
      v10 = GetHistory();
      CHistory::KeepNew(this: v10, pList: v7, bKeepChildren: true);
    }
    else
    {
      CHistory::MarkUndoPosition(this: History, pSelection: v14, pszName: "Logical Translation", bFromOpposite: 0);
      v11 = GetHistory();
      CHistory::Keep(this: v11, pList: v7);
    }
    Selection3D::TransformLogicalSelection(this, vecTranslation: &this->m_vLogicalTranslation);
    v12 = this->m_pSelection;
    this->m_bIsLogicalTranslating = false;
    if ( !CSelection::GetBounds(this: v12, vecMins: &this->bmins, vecMaxs: &this->bmaxs) )
      BoundBox::ResetBounds(this: &this->BoundBox);
    this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
    NotifyDuplicates(pList: v7);
    goto LABEL_11;
  }
updateStatusBar:
  CMapDoc::UpdateStatusbar(this: this->m_pDocument);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10168DD0
// Name: public: virtual bool Selection3D::OnLMouseDblClk3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnLMouseDblClk3D(
        Selection3D *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v6; // ecx
  void *v7; // edx
  CManifestMap **v8; // eax
  CMainFrame *MainWnd; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v12; // [esp+8h] [ebp-14h]
  void *inptr; // [esp+Ch] [ebp-10h]
  int v14; // [esp+18h] [ebp-4h]

  if ( !CSelection::IsEmpty(this: this->m_pSelection) )
  {
    if ( CToolManager::GetActiveTool(this: this->m_pSelection) == 1 )
    {
      m_pObject = (*CSelection::GetList(this: this->m_pSelection)->m_Memory.m_pMemory)->m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v6 = m_pObject->m_References.m_pHead;
        if ( v6 != nullptr )
          v6->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v12 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v7 = inptr;
      v14 = -1;
      if ( inptr != nullptr )
      {
        if ( v12 != nullptr )
        {
          v12->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v12;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v12 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      v8 = (CManifestMap **)__RTDynamicCast(
                              inptr: v7,
                              VfDelta: 0,
                              SrcType: &CMapClass `RTTI Type Descriptor',
                              TargetType: &CManifestInstance `RTTI Type Descriptor',
                              isReference: 0);
      if ( v8 != nullptr && CMapDoc::m_pManifest != nullptr )
      {
        CManifest::SetPrimaryMap(this: CMapDoc::m_pManifest, pManifestMap: v8[97]);
        return 1;
      }
    }
    MainWnd = GetMainWnd();
    CWnd::ShowWindow(this: MainWnd->pObjectProperties, nCmdShow: 5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10168F10
// Name: protected: void Selection3D::EyedropperPick(class CMapView __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::EyedropperPick(Selection3D *this, CMapView *pView, CMapClass *pObject)
{
  CMapEntity *EntityInTree; // eax
  int v5; // ebx
  const CUtlReferenceVector<CMapClass> *List; // esi
  int v7; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v9; // ecx
  void *v10; // edx
  void *v11; // eax
  GDclass *v12; // eax
  int m_nVariables; // ecx
  GDinputvariable *VariableAt; // eax
  GDinputvariable *v15; // edi
  GDIV_TYPE m_eType; // eax
  int m_Size; // esi
  GDinputvariable **m_pMemory; // ecx
  GDinputvariable **v19; // eax
  GDinputvariable *v20; // eax
  CHistory *History; // eax
  int v22; // edi
  CMapClass *v23; // eax
  CUtlReference<CMapClass> *v24; // ecx
  void *v25; // edx
  void *v26; // eax
  CMapClass *v27; // esi
  const char *v28; // ebx
  GDinputvariable *v29; // eax
  GDIV_TYPE v30; // eax
  CHistory *v31; // eax
  CMapDoc *v32; // eax
  GDinputvariable **v33; // eax
  CUtlVector<GDinputvariable *,CUtlMemory<GDinputvariable *,int> > VarList; // [esp+8h] [ebp-40h] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+1Ch] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> *v36; // [esp+20h] [ebp-28h]
  void *inptr; // [esp+24h] [ebp-24h]
  const char *pszClickName; // [esp+28h] [ebp-20h]
  const char *pszVarName; // [esp+2Ch] [ebp-1Ch]
  int nVarCount; // [esp+30h] [ebp-18h]
  GDclass *pClass; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  int v43; // [esp+44h] [ebp-4h]
  const CUtlReferenceVector<CMapClass> *pSelList; // [esp+54h] [ebp+Ch]

  pszVarName = (const char *)this;
  EntityInTree = Selection3D::FindEntityInTree(this, pObject);
  v5 = 0;
  if ( EntityInTree != nullptr )
  {
    pszClickName = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                     this: &EntityInTree->m_KeyValues,
                     pszKey: "targetname",
                     piIndex: nullptr);
    if ( pszClickName == nullptr )
    {
      MessageBoxA(hWnd: nullptr, lpText: "The chosen entity has no name.", lpCaption: "No name to pick", uType: 0);
      return;
    }
    memset(&VarList, 0, sizeof(VarList));
    v43 = 1;
    List = CSelection::GetList(this: this->m_pSelection);
    v7 = 0;
    pSelList = List;
    for ( i = 0; v7 < List->m_Size; i = v7 )
    {
      m_pObject = List->m_Memory.m_pMemory[v7 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v7 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = List->m_Memory.m_pMemory[v7 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v7 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v9 = m_pObject->m_References.m_pHead;
        if ( v9 != nullptr )
          v9->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v36 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v10 = inptr;
      LOBYTE(v43) = 1;
      if ( inptr != nullptr )
      {
        if ( v36 != nullptr )
        {
          v36->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v36;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v36 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      v11 = __RTDynamicCast(
              inptr: v10,
              VfDelta: 0,
              SrcType: &CMapClass `RTTI Type Descriptor',
              TargetType: &CMapEntity `RTTI Type Descriptor',
              isReference: 0);
      if ( v11 != nullptr )
      {
        v12 = *((GDclass **)v11 + 62);
        m_nVariables = v12->m_nVariables;
        pClass = v12;
        nVarCount = m_nVariables;
        if ( m_nVariables > 0 )
        {
          while ( 1 )
          {
            VariableAt = GDclass::GetVariableAt(this: v12, iIndex: v5);
            v15 = VariableAt;
            if ( VariableAt != nullptr )
            {
              m_eType = VariableAt->m_eType;
              if ( m_eType == ivTargetDest || m_eType == ivTargetNameOrClass )
              {
                m_Size = VarList.m_Size;
                if ( VarList.m_Size + 1 > VarList.m_Memory.m_nAllocationCount )
                  CUtlMemory<CVisGroup *,int>::Grow(
                    this: (CUtlMemory<CCullTreeNode *,int> *)&VarList,
                    num: VarList.m_Size - VarList.m_Memory.m_nAllocationCount + 1);
                ++VarList.m_Size;
                m_pMemory = VarList.m_Memory.m_pMemory;
                VarList.m_pElements = VarList.m_Memory.m_pMemory;
                if ( VarList.m_Size - m_Size - 1 > 0 )
                {
                  _V_memmove(
                    dest: &VarList.m_Memory.m_pMemory[m_Size + 1],
                    src: &VarList.m_Memory.m_pMemory[m_Size],
                    count: 4 * (VarList.m_Size - m_Size - 1));
                  m_pMemory = VarList.m_Memory.m_pMemory;
                }
                v19 = &m_pMemory[m_Size];
                List = pSelList;
                if ( v19 != nullptr )
                  *v19 = v15;
              }
            }
            if ( ++v5 >= nVarCount )
              break;
            v12 = pClass;
          }
          v7 = i;
        }
        v5 = 0;
      }
      ++v7;
    }
    if ( VarList.m_Size > 0 )
    {
      v20 = Selection3D::ChooseEyedropperVar(this: (Selection3D *)pszVarName, pView, &VarList);
      if ( v20 == nullptr || (pszVarName = v20->m_szName, v20 == (GDinputvariable *)-20) )
      {
        v43 = -1;
        CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&VarList);
        return;
      }
      History = GetHistory();
      CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Set Keyvalue", bFromOpposite: 0);
      v22 = 0;
      if ( List->m_Size > 0 )
      {
        while ( 1 )
        {
          v23 = List->m_Memory.m_pMemory[v22 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v22 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
          if ( v23 != nullptr )
          {
            inptr = List->m_Memory.m_pMemory[v22 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v22 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
            m_pHead = v23->m_References.m_pHead;
            v24 = v23->m_References.m_pHead;
            if ( v24 != nullptr )
              v24->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
            v36 = nullptr;
            v23->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
          }
          v25 = inptr;
          LOBYTE(v43) = 1;
          if ( inptr != nullptr )
          {
            if ( v36 != nullptr )
            {
              v36->m_pNext = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = v36;
            }
            else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
            {
              *((_DWORD *)inptr + 8) = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = nullptr;
            }
            v36 = nullptr;
            m_pHead = nullptr;
            inptr = nullptr;
          }
          v26 = __RTDynamicCast(
                  inptr: v25,
                  VfDelta: 0,
                  SrcType: &CMapClass `RTTI Type Descriptor',
                  TargetType: &CMapEntity `RTTI Type Descriptor',
                  isReference: 0);
          v27 = (CMapClass *)v26;
          if ( v26 != nullptr )
          {
            v28 = pszVarName;
            v29 = GDclass::VarForName(this: *((GDclass **)v26 + 62), pszName: pszVarName, piIndex: nullptr);
            if ( v29 != nullptr )
            {
              v30 = v29->m_eType;
              if ( v30 == ivTargetDest || v30 == ivTargetNameOrClass )
              {
                v31 = GetHistory();
                CHistory::Keep(this: v31, pObject: v27);
                ((void (__thiscall *)(CMapClass *, const char *, const char *))v27[1].IsSelected)(
                  a1: &v27[1],
                  a2: v28,
                  a3: pszClickName);
              }
            }
          }
          if ( ++v22 >= pSelList->m_Size )
            break;
          List = pSelList;
        }
      }
      v32 = pView->GetMapDoc(this: pView);
      if ( v32 != nullptr )
        v32->SetModifiedFlag(this: v32, a2: 1);
      v43 = 5;
    }
    else
    {
      MessageBoxA(
        hWnd: nullptr,
        lpText: "No selected entities have keyvalues that accept an entity name, so the eyedropper has nothing to assign to.",
        lpCaption: "No eligible keyvalues",
        uType: 0);
      v43 = 3;
    }
    v33 = VarList.m_Memory.m_pMemory;
    VarList.m_Size = 0;
    if ( VarList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( VarList.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: VarList.m_Memory.m_pMemory);
        v33 = nullptr;
        VarList.m_Memory.m_pMemory = nullptr;
      }
      VarList.m_Memory.m_nAllocationCount = 0;
    }
    VarList.m_pElements = v33;
    v43 = -1;
    if ( VarList.m_Memory.m_nGrowSize >= 0 && VarList.m_Memory.m_pMemory != nullptr )
      free(pMem: VarList.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169330
// Name: public: virtual bool Selection3D::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnLMouseUp3D(
        Selection3D *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  bool IsEditable; // bl
  CMapView *v6; // eax
  CMapView *v7; // eax
  bool bShift; // [esp+18h] [ebp+Ch]

  bShift = (nFlags & 4) != 0;
  Tool3D::OnLMouseUp3D(this, pView, nFlags, vPoint);
  IsEditable = CSelection::IsEditable(this: this->m_pSelection);
  if ( this->IsTranslating(this) )
  {
    if ( this->m_bBoxSelection )
    {
      Box3D::FinishTranslation(this, bSave: true);
      if ( Options.view2d.bAutoSelect != 0 )
      {
        Selection3D::SelectInBox(this, pDoc: this->m_pDocument, bInsideOnly: bShift);
        if ( this->m_bActiveTool && CSelection::IsEditable(this: this->m_pSelection) )
          Box3D::EnableHandles(this, bEnable: true);
        else
          Box3D::EnableHandles(this, bEnable: false);
      }
    }
    else
    {
      Selection3D::FinishTranslation(this, bSave: true, bClone: bShift);
    }
  }
  else if ( this->m_b3DEditMode && !this->m_bSelected && !CSelection::IsEmpty(this: this->m_pSelection) && IsEditable )
  {
    v6 = pView != nullptr ? &pView->CMapView : nullptr;
    if ( this->HitTest(this, a2: v6, a3: vPoint, a4: false) != 0 )
    {
      this->ToggleTranslateMode(this);
      if ( pView != nullptr )
        v7 = &pView->CMapView;
      else
        v7 = nullptr;
      Box3D::UpdateCursor(
        this,
        pView: v7,
        vHandleHit: &this->m_LastHitTestHandle,
        eTransformMode: this->m_TranslateMode);
      CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
    }
  }
  CMapView3D::EndPick(this: pView);
  CMapDoc::UpdateStatusbar(this: this->m_pDocument);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10169480
// Name: public: virtual bool Selection3D::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnMouseMove3D(
        Selection3D *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  HCURSOR CursorA; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  unsigned int v10; // eax
  bool m_b3DEditMode; // al
  CMapView *v12; // eax
  CMapView *v13; // eax
  CMapView *v14; // eax
  CMapView *v15; // eax
  unsigned int hCursor; // [esp+14h] [ebp+8h]
  bool IsEditable_3; // [esp+1Bh] [ebp+Fh]

  Tool3D::OnMouseMove3D(this, pView, nFlags, vPoint);
  IsEditable_3 = CSelection::IsEditable(this: this->m_pSelection);
  hCursor = 2;
  if ( this->m_bEyedropper )
  {
    CursorA = dword_107B38D4;
    if ( dword_107B38D4 == nullptr )
    {
      ModuleState = AfxGetModuleState();
      CursorA = LoadCursorA(hInstance: ModuleState->m_hCurrentInstanceHandle, lpCursorName: (LPCSTR)0x138);
      dword_107B38D4 = CursorA;
    }
    SetCursor(hCursor: CursorA);
    CMapView3D::SetCursor(this: pView, hCursor: 2u);
    return 1;
  }
  if ( !this->IsTranslating(this) )
  {
    m_b3DEditMode = this->m_b3DEditMode;
    if ( m_b3DEditMode && this->m_bMouseDragged[0] )
    {
      if ( !IsEditable_3 )
        goto LABEL_34;
      v12 = pView != nullptr ? &pView->CMapView : nullptr;
      if ( this->HitTest(this, a2: v12, a3: this->m_vMouseStart, a4: true) == 0 )
        goto LABEL_34;
      if ( pView != nullptr )
        v13 = &pView->CMapView;
      else
        v13 = nullptr;
      Selection3D::StartTranslation(this, pView: v13, vPoint, vHandleOrigin: &this->m_LastHitTestHandle);
      if ( pView != nullptr )
        v14 = &pView->CMapView;
      else
        v14 = nullptr;
    }
    else
    {
      if ( !IsEditable_3 || !m_b3DEditMode || this->IsEmpty(this) )
        goto LABEL_34;
      Selection3D::UpdateHandleState(this);
      v15 = pView != nullptr ? &pView->CMapView : nullptr;
      if ( this->HitTest(this, a2: v15, a3: vPoint, a4: true) == 0 )
        goto LABEL_34;
      if ( pView != nullptr )
        v14 = &pView->CMapView;
      else
        v14 = nullptr;
    }
    hCursor = Box3D::UpdateCursor(
                this,
                pView: v14,
                vHandleHit: &this->m_LastHitTestHandle,
                eTransformMode: this->m_TranslateMode);
    if ( hCursor == 1 )
      return 1;
LABEL_34:
    CMapView3D::SetCursor(this: pView, hCursor);
    return 1;
  }
  v10 = this->GetConstraints(this, a2: nFlags);
  if ( pView != nullptr )
    Tool3D::UpdateTranslation(this, pView: &pView->CMapView, vPoint, nFlags: v10);
  else
    Tool3D::UpdateTranslation(this, pView: nullptr, vPoint, nFlags: v10);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10169640
// Name: protected: void Selection3D::OnEscape(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::OnEscape(Selection3D *this, CMapDoc *pDoc)
{
  HCURSOR CursorA; // eax
  CSelection *m_pSelection; // ecx
  CMapDoc *m_pDocument; // ecx
  const CUtlReferenceVector<CMapClass> *List; // edi
  CHistory *History; // eax
  CHistory *v8; // eax

  if ( this->m_bEyedropper )
  {
    this->m_bEyedropper = false;
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    SetCursor(hCursor: CursorA);
  }
  else if ( this->m_bBoxSelection )
  {
    CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 24, ub: nullptr);
    m_pSelection = this->m_pSelection;
    this->m_bBoxSelection = false;
    if ( !CSelection::GetBounds(this: m_pSelection, vecMins: &this->bmins, vecMaxs: &this->bmaxs) )
      BoundBox::ResetBounds(this: &this->BoundBox);
  }
  else if ( this->m_bInLogicalBoxSelection )
  {
    m_pDocument = this->m_pDocument;
    this->m_clrLogicalBox = Options.colors.clrToolSelection;
    CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 24, ub: nullptr);
    this->m_bInLogicalBoxSelection = false;
  }
  else if ( this->IsTranslating(this) )
  {
    List = CSelection::GetList(this: this->m_pSelection);
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Translation", bFromOpposite: 0);
    v8 = GetHistory();
    CHistory::Keep(this: v8, pList: List);
    Box3D::FinishTranslation(this, bSave: false);
    CSelection::SetSelectionState(this: this->m_pSelection, eSelectionState: SELECT_NORMAL);
  }
  else if ( !this->IsEmpty(this) )
  {
    this->SetEmpty(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169760
// Name: public: virtual bool Selection3D::OnKeyDown2D(class CMapView2D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Selection3D::OnKeyDown2D(
        Selection3D *this,
        CMapView2D *pView,
        int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  bool v7; // bl
  CMapView *v8; // eax
  bool result; // al
  bool bShift; // [esp+Ch] [ebp-4h]
  bool bSnap; // [esp+1Ch] [ebp+Ch]

  bShift = GetKeyState(nVirtKey: 16) < 0;
  v7 = GetKeyState(nVirtKey: 17) < 0;
  if ( Options.view2d.bNudge != 0 && (nChar == 38 || nChar == 40 || nChar == 37 || nChar == 39) && !this->IsEmpty(this) )
  {
    if ( !this->m_pDocument->m_bSnapToGrid || (bSnap = true, v7) )
      bSnap = false;
    if ( pView != nullptr )
      v8 = &pView->CMapView;
    else
      v8 = nullptr;
    Selection3D::NudgeObjects(this, pView: v8, nChar, bSnap, bClone: bShift);
    return true;
  }
  else
  {
    switch ( nChar )
    {
      case 13:
        if ( this->m_bBoxSelection )
        {
          Selection3D::SelectInBox(this, pDoc: this->m_pDocument, bInsideOnly: bShift);
          Selection3D::UpdateHandleState(this);
        }
        result = true;
        break;
      case 27:
        Selection3D::OnEscape(this, pDoc: this->m_pDocument);
        result = true;
        break;
      case 33:
        this->m_pDocument->OnCmdMsg(this: this->m_pDocument, a2: 32924u, a3: 0, a4: nullptr, a5: nullptr);
        result = true;
        break;
      case 34:
        this->m_pDocument->OnCmdMsg(this: this->m_pDocument, a2: 32923u, a3: 0, a4: nullptr, a5: nullptr);
        result = true;
        break;
      case 46:
        this->m_pDocument->OnCmdMsg(this: this->m_pDocument, a2: 32858u, a3: 0, a4: nullptr, a5: nullptr);
        result = true;
        break;
      default:
        result = false;
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10169900
// Name: public: virtual bool Selection3D::OnKeyDownLogical(class CMapViewLogical __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Selection3D::OnKeyDownLogical(
        Selection3D *this,
        CMapViewLogical *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  bool v6; // al
  bool result; // al
  bool bShift; // [esp+8h] [ebp-4h]

  bShift = GetKeyState(nVirtKey: 16) < 0;
  v6 = GetKeyState(nVirtKey: 18) < 0;
  switch ( nChar )
  {
    case 0xDu:
      if ( this->m_bInLogicalBoxSelection )
      {
        Selection3D::EndLogicalBoxSelection(this);
        Selection3D::SelectInLogicalBox(this, pDoc: this->m_pDocument, bInsideOnly: bShift);
      }
      result = true;
      break;
    case 0x1Bu:
      Selection3D::OnEscape(this, pDoc: this->m_pDocument);
      result = true;
      break;
    case 0x21u:
      this->m_pDocument->OnCmdMsg(this: this->m_pDocument, a2: v6 ? 32927 : 32924, a3: 0, a4: nullptr, a5: nullptr);
      result = true;
      break;
    case 0x22u:
      this->m_pDocument->OnCmdMsg(this: this->m_pDocument, a2: v6 ? 32926 : 32923, a3: 0, a4: nullptr, a5: nullptr);
      result = true;
      break;
    case 0x2Eu:
      this->m_pDocument->OnCmdMsg(this: this->m_pDocument, a2: 32858u, a3: 0, a4: nullptr, a5: nullptr);
      result = true;
      break;
    default:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10169A40
// Name: public: virtual bool Selection3D::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnMouseMove2D(
        Selection3D *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  unsigned int v7; // eax
  void (__thiscall *ClientToWorld)(CMapView *, Vector *, const Vector2D *); // edx
  HWND v10; // eax
  unsigned int updated; // eax
  CMapDoc *m_pDocument; // ecx
  char v13; // al
  char szBuf[128]; // [esp+28h] [ebp-ACh] BYREF
  Vector vecWorld; // [esp+A8h] [ebp-2Ch] BYREF
  Vector vecSize; // [esp+B4h] [ebp-20h] BYREF
  Vector ptOrg; // [esp+C0h] [ebp-14h] BYREF
  unsigned int uConstraints; // [esp+CCh] [ebp-8h]
  unsigned int hCursor; // [esp+D0h] [ebp-4h]
  bool bCtrl_3; // [esp+DFh] [ebp+Bh]
  bool IsEditable_3; // [esp+E3h] [ebp+Fh]

  Tool3D::OnMouseMove2D(this, pView, nFlags, vPoint);
  IsEditable_3 = CSelection::IsEditable(this: this->m_pSelection);
  hCursor = 2;
  bCtrl_3 = GetAsyncKeyState(vKey: 17) < 0;
  v7 = this->GetConstraints(this, a2: nFlags);
  ClientToWorld = pView->ClientToWorld;
  uConstraints = v7;
  ClientToWorld(this: &pView->CMapView, a2: &vecWorld, a3: vPoint);
  sprintf(string: szBuf, format: " @%.0f, %.0f ", *(&vecWorld.x + pView->axHorz), *(&vecWorld.x + pView->axVert));
  SetStatusText(nIndex: 2, pszText: szBuf);
  if ( this->IsTranslating(this) )
  {
    Tool3D::UpdateTranslation(this, pView: &pView->CMapView, vPoint, nFlags: uConstraints);
    return 1;
  }
  if ( this->m_bMouseDragged[0] )
  {
    v10 = SetCapture(hWnd: pView->m_hWnd);
    CWnd::FromHandle(hWnd: v10);
    if ( !IsEditable_3 || bCtrl_3 || this->HitTest(this, a2: &pView->CMapView, a3: this->m_vMouseStart, a4: true) == 0 )
    {
      if ( !this->m_bSelected )
      {
        pView->ClientToWorld(this: &pView->CMapView, a2: &ptOrg, a3: this->m_vMouseStart);
        m_pDocument = this->m_pDocument;
        *((_DWORD *)&ptOrg.x + pView->axThird) = 1203982208;
        CMapDoc::GetBestVisiblePoint(this: m_pDocument, &ptOrg);
        if ( (uConstraints & 4) != 0 )
          CMapDoc::Snap(this: this->m_pDocument, pt: &ptOrg, nFlags: uConstraints);
        this->m_bBoxSelection = true;
        memset(&vecSize, 0, sizeof(vecSize));
        Box3D::StartNew(this, pView: &pView->CMapView, vPoint: this->m_vMouseStart, vecStart: &ptOrg, &vecSize);
        Box3D::EnableHandles(this, bEnable: true);
      }
      goto LABEL_26;
    }
    Selection3D::StartTranslation(
      this,
      pView: &pView->CMapView,
      vPoint: this->m_vMouseStart,
      vHandleOrigin: &this->m_LastHitTestHandle);
    updated = Box3D::UpdateCursor(
                this,
                pView: &pView->CMapView,
                vHandleHit: &this->m_LastHitTestHandle,
                eTransformMode: this->m_TranslateMode);
    goto LABEL_24;
  }
  if ( this->IsEmpty(this) )
  {
LABEL_26:
    CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: hCursor);
    return 1;
  }
  if ( this->m_bActiveTool && CSelection::IsEditable(this: this->m_pSelection) )
    Box3D::EnableHandles(this, bEnable: true);
  else
    Box3D::EnableHandles(this, bEnable: false);
  if ( Selection3D::GetToolObject(this, pView, vPoint, bAttach: false) != nullptr )
  {
    hCursor = 6;
    v13 = 1;
  }
  else
  {
    v13 = 0;
  }
  if ( IsEditable_3 && v13 == 0 && this->HitTest(this, a2: &pView->CMapView, a3: vPoint, a4: true) != 0 )
  {
    updated = Box3D::UpdateCursor(
                this,
                pView: &pView->CMapView,
                vHandleHit: &this->m_LastHitTestHandle,
                eTransformMode: this->m_TranslateMode);
LABEL_24:
    hCursor = updated;
  }
  if ( hCursor != 1 )
    goto LABEL_26;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10169CC0
// Name: public: virtual bool Selection3D::OnKeyDown3D(class CMapView3D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Selection3D::OnKeyDown3D(
        Selection3D *this,
        CMapView3D *pView,
        int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  bool v7; // bl
  bool result; // al
  CMapView *v9; // eax
  bool bShift; // [esp+Ch] [ebp-4h]
  bool bSnap; // [esp+1Ch] [ebp+Ch]

  bShift = GetKeyState(nVirtKey: 16) < 0;
  v7 = GetKeyState(nVirtKey: 17) < 0;
  switch ( nChar )
  {
    case 27:
      Selection3D::OnEscape(this, pDoc: this->m_pDocument);
      result = true;
      break;
    case 46:
      this->m_pDocument->OnCmdMsg(this: this->m_pDocument, a2: 32858u, a3: 0, a4: nullptr, a5: nullptr);
      result = true;
      break;
    case 88:
    case 120:
      this->m_b3DEditMode = !this->m_b3DEditMode;
      pView->UpdateView(this: &pView->CMapView, a2: 16);
      result = true;
      break;
    default:
      if ( Options.view2d.bNudge != 0
        && (nChar == 38 || nChar == 40 || nChar == 37 || nChar == 39)
        && !this->IsEmpty(this) )
      {
        if ( !this->m_pDocument->m_bSnapToGrid || (bSnap = true, v7) )
          bSnap = false;
        if ( pView != nullptr )
          v9 = &pView->CMapView;
        else
          v9 = nullptr;
        Selection3D::NudgeObjects(this, pView: v9, nChar, bSnap, bClone: bShift);
        result = true;
      }
      else
      {
        result = false;
      }
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10169E50
// Name: protected: void Selection3D::EyedropperPick3D(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Selection3D::EyedropperPick3D(Selection3D *this, CMapView3D *pView, const Vector2D *vPoint)
{
  CMapClass *v4; // eax
  unsigned int ulFace; // [esp+4h] [ebp-4h] BYREF

  if ( CSelection::IsAnEntitySelected(this: this->m_pSelection) )
  {
    v4 = CMapView3D::NearestObjectAt(this: pView, vPoint, &ulFace, nFlags: 0, pLocalMatrix: nullptr);
    if ( v4 != nullptr )
    {
      if ( pView != nullptr )
        Selection3D::EyedropperPick(this, pView: &pView->CMapView, pObject: v4);
      else
        Selection3D::EyedropperPick(this, pView: nullptr, pObject: v4);
    }
  }
  else
  {
    MessageBoxA(
      hWnd: nullptr,
      lpText: "No entities are selected, so the eyedropper has nothing to assign to.",
      lpCaption: "No selected entities",
      uType: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169ED0
// Name: public: virtual bool Selection3D::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Selection3D::OnLMouseDown3D(
        Selection3D *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapView3D *v4; // edi
  bool v6; // zf
  HCURSOR CursorA; // eax
  bool v9; // al
  CMapView *v10; // eax
  CMapView *v11; // edi
  unsigned int updated; // eax
  Box3D::TransformMode_t m_TranslateMode; // [esp-4h] [ebp-5Ch]
  HitInfo_s HitData; // [esp+Ch] [ebp-4Ch] BYREF

  v4 = pView;
  Tool3D::OnLMouseDown3D(this, pView, nFlags, vPoint);
  v6 = !this->m_bEyedropper;
  this->m_bSelected = false;
  if ( !v6 )
  {
    Selection3D::EyedropperPick3D(this, pView, vPoint);
    this->m_bEyedropper = false;
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    SetCursor(hCursor: CursorA);
    return 1;
  }
  if ( (nFlags & 8) != 0 )
  {
    v9 = CMapView::SelectAt(this: &pView->CMapView, ptClient: vPoint, bMakeFirst: false, bFace: false);
  }
  else
  {
    if ( this->m_b3DEditMode )
    {
      v10 = pView != nullptr ? &pView->CMapView : nullptr;
      if ( this->HitTest(this, a2: v10, a3: vPoint, a4: true) != 0 )
      {
        if ( !this->m_bBoxSelection && Vector::operator==(this: &this->m_LastHitTestHandle, src: &vec3_origin) )
        {
          v11 = &pView->CMapView;
          this->m_bDrawAsSolidBox = true;
          v11->ObjectsAt(this: v11, a2: vPoint, a3: &HitData, a4: 1, a5: 0);
          if ( HitData.pObject != nullptr && !HitData.pObject->IsSelected(this: HitData.pObject) )
          {
            this->m_bSelected = CMapView::SelectAt(this: v11, ptClient: vPoint, bMakeFirst: true, bFace: false);
            Selection3D::UpdateHandleState(this);
          }
          m_TranslateMode = this->m_TranslateMode;
          this->m_bDrawAsSolidBox = false;
          updated = Box3D::UpdateCursor(
                      this,
                      pView: v11,
                      vHandleHit: &this->m_LastHitTestHandle,
                      eTransformMode: m_TranslateMode);
          CMapView3D::SetCursor(this: pView, hCursor: updated);
          v4 = pView;
        }
        goto LABEL_21;
      }
    }
    this->m_TranslateMode = modeScale;
    v9 = CMapView::SelectAt(this: &pView->CMapView, ptClient: vPoint, bMakeFirst: true, bFace: false);
  }
  v6 = !this->m_bActiveTool;
  this->m_bSelected = v9;
  if ( v6 || !CSelection::IsEditable(this: this->m_pSelection) )
    Box3D::EnableHandles(this, bEnable: false);
  else
    Box3D::EnableHandles(this, bEnable: true);
LABEL_21:
  if ( this->m_bSelected && !this->m_b3DEditMode )
    CMapView3D::BeginPick(this: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A0FA0
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
// Address: 0x101A1870
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
// Address: 0x101A1D00
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
// Address: 0x101A1D60
// Name: public: int CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
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
// Address: 0x101A2730
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
// Address: 0x101A2D00
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
// Address: 0x101A65C0
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
// Address: 0x101A67F0
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
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
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
// Address: 0x101A6880
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
    CUtlMemory<vgui::CSizerBase::CSizerMember,int>::Grow(
      (CUtlMemory<vgui::CSizerBase::CSizerMember,int> *)this,
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
// Address: 0x101A6920
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
    CUtlMemory<vgui::CSizerBase::CSizerMember,int>::Grow(
      (CUtlMemory<vgui::CSizerBase::CSizerMember,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x101A6CA0
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
// Address: 0x101A7190
// Name: public: CUtlVector<struct CachedAssetInfo_t,class CUtlMemory<struct CachedAssetInfo_t,int>>::~CUtlVector<struct CachedAssetInfo_t,class CUtlMemory<struct CachedAssetInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>::~CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int>>(
        CUtlVector<CachedAssetInfo_t,CUtlMemory<CachedAssetInfo_t,int> > *this)
{
  bool v2; // sf
  CachedAssetInfo_t *m_pMemory; // eax

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll((CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Memory.m_pMemory);
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
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A71F0
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
// Address: 0x101AAC70
// Name: public: void CUtlMemory<struct CacheOptimizedKDNode,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CacheOptimizedKDNode,int>::Grow(CUtlMemory<vgui::PropertySheet::Page_t,int> *this, int num)
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
// Address: 0x101AAD10
// Name: public: void CUtlMemory<class CUtlVector<class CAttributeNode __near *,class CUtlMemory<class CAttributeNode __near *,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edx
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
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AB190
// Name: public: void CUtlVector<struct mstudioseqdesc_t __near *,class CUtlMemory<struct mstudioseqdesc_t __near *,int>>::Sort(int (*)(struct mstudioseqdesc_t __near * const __near *,struct mstudioseqdesc_t __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
        CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  vgui::CConsolePanel::CompletionItem *v6; // ecx
  vgui::CConsolePanel::CompletionItem **v7; // eax

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
// Address: 0x101ABD20
// Name: public: void CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::FastRemove(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  CDataModel::ElementIdHandlePair_t *m_pMemory; // edx
  int v4; // eax
  __int64 v5; // xmm0_8
  CDataModel::ElementIdHandlePair_t *v6; // eax
  CDataModel::ElementIdHandlePair_t *v7; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v4 = m_Size;
      v5 = *(_QWORD *)this->m_Memory.m_pMemory[v4 - 1].m_id.m_Value;
      v6 = &this->m_Memory.m_pMemory[v4 - 1];
      *(_QWORD *)m_pMemory[elem].m_id.m_Value = v5;
      v7 = &m_pMemory[elem];
      *(_QWORD *)&v7->m_id.m_Value[8] = *(_QWORD *)&v6->m_id.m_Value[8];
      v7->m_ref = v6->m_ref;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE290
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

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
// Address: 0x101AE650
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101AE6A0
// Name: public: int CUtlVector<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<CDmAttribute,21>::EntryType_t,CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101AE710
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(int,struct CDataModel::ElementIdHandlePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        const CDataModel::ElementIdHandlePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v7; // eax
  CDataModel::ElementIdHandlePair_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmeMesh::Triangle_t,int>::Grow(
      (CUtlMemory<CDmeMesh::Triangle_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CDataModel::ElementIdHandlePair_t::ElementIdHandlePair_t(this: v8, that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101B32F0
// Name: public: class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> __near & CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *__thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(
        CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *this,
        const CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *other)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v2; // esi
  int m_Size; // edi
  int v4; // eax
  int v5; // edi
  _DWORD *v6; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v7; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v10; // eax
  int i; // eax
  bool v12; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v2 = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)this;
  m_Size = other->m_Size;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll((CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)this);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: v2,
    elem: v2->m_Size,
    num: m_Size);
  if ( m_Size <= 0 )
    return v2;
  v4 = 0;
  v16 = 0;
  v15 = m_Size;
  while ( 1 )
  {
    v5 = *(int *)((char *)&other->m_Memory.m_pMemory->m_Size + v4);
    v6 = (DmElementHandle_t **)((char *)&other->m_Memory.m_pMemory->m_Memory.m_pMemory + v4);
    v7 = (CUtlMemory<vgui::TreeNode *,int> *)((char *)v2->m_Memory.m_pMemory + v4);
    v7[1].m_pMemory = nullptr;
    if ( v5 != 0 )
    {
      m_nAllocationCount = v7->m_nAllocationCount;
      if ( v5 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: v5 - m_nAllocationCount);
      v7[1].m_pMemory = (vgui::TreeNode **)((char *)v7[1].m_pMemory + v5);
      m_pMemory = v7->m_pMemory;
      v10 = (int)v7[1].m_pMemory - v5;
      v7[1].m_nAllocationCount = (int)v7->m_pMemory;
      if ( v10 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: 4 * v10);
    }
    for ( i = 0; i < v5; ++i )
      v7->m_pMemory[i] = *(vgui::TreeNode **)(*v6 + 4 * i);
    v4 = v16 + 20;
    v12 = v15-- == 1;
    v16 += 20;
    if ( v12 )
      break;
    v2 = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)this;
  }
  return (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)this;
}

//------------------------------------------------------------------------------
// Address: 0x101B3420
// Name: public: CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>::~CUtlVector<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,class CUtlMemory<class CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this);
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
// Address: 0x101B6AD0
// Name: public: int CUtlVector<struct ElementPathItem_t,class CUtlMemory<struct ElementPathItem_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int>>::InsertBefore(
        CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ElementPathItem_t *m_pMemory; // ecx
  int v6; // eax
  ElementPathItem_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->hElement = DMELEMENT_HANDLE_INVALID;
    v7->hAttribute = DMATTRIBUTE_HANDLE_INVALID;
    v7->nIndex = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101BB8D0
// Name: public: void CUtlVector<class CDmeHandle<class CDmElement,0>,class CUtlMemory<class CDmeHandle<class CDmElement,0>,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int>>::EnsureCapacity(
        CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *this,
        int num)
{
  CDmeHandle<CDmElement,0> *m_pMemory; // edx
  unsigned int v4; // eax
  CDmeHandle<CDmElement,0> *v5; // eax

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
      this->m_Memory.m_pMemory = (CDmeHandle<CDmElement,0> *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v4);
      goto LABEL_5;
    }
    v5 = (CDmeHandle<CDmElement,0> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC3B0
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int num)
{
  CUtlString *m_pMemory; // edx
  unsigned int v4; // eax
  CUtlString *v5; // eax

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
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC910
// Name: public: void CUtlVector<class CDmeHandle<class CDmElement,2>,class CUtlMemory<class CDmeHandle<class CDmElement,2>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int>>::Purge(
        CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CDmeHandle<CDmElement,2> *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel != nullptr )
      CDmeElementRefHelper::Unref(
        this: &this->m_Memory.m_pMemory[i],
        hElement: this->m_Memory.m_pMemory[i].m_handle,
        handleType: HT_UNDO);
  }
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
// Address: 0x101BC980
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  CUtlBinaryBlock *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v7, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101BD740
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CDmaArrayBase<bool,CDmaDataInternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool *v4; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Storage.m_Memory.m_pMemory = v4;
    this->m_Storage.m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BD820
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *this,
        int num)
{
  DmePickerInfo_t *m_pMemory; // edx
  unsigned int v4; // eax
  DmePickerInfo_t *v5; // eax

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
    v4 = 8 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (DmePickerInfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (DmePickerInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BD8C0
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *this,
        int num)
{
  QAngle *m_pMemory; // edx
  unsigned int v4; // eax
  QAngle *v5; // eax

  if ( this->m_Storage.m_Memory.m_nAllocationCount >= num )
  {
    this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Storage.m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_Storage.m_pElements = this->m_Storage.m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Storage.m_Memory.m_pMemory;
    this->m_Storage.m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Storage.m_Memory.m_pMemory = (QAngle *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (QAngle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Storage.m_Memory.m_pMemory = v5;
    this->m_Storage.m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2E60
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertBefore(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        float *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v7; // eax
  float *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
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
// Address: 0x101C2ED0
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertBefore(int,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        bool *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v7; // eax
  bool *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C2F30
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  Color *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = 0;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C2FC0
// Name: public: CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *__thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int growSize,
        int initSize)
{
  Quaternion *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (Quaternion *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C3010
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  Vector4D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
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
// Address: 0x101C3090
// Name: public: CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<QAngle,CUtlMemory<QAngle,int> > *__thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::CUtlVector<QAngle,CUtlMemory<QAngle,int>>(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int growSize,
        int initSize)
{
  QAngle *m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (QAngle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C30E0
// Name: public: int CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::InsertBefore(int,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        const QAngle *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v7; // eax
  QAngle *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
// Address: 0x101C3160
// Name: public: int CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C31E0
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertBefore(int,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        const Quaternion *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v7; // eax
  Quaternion *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
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
// Address: 0x101C3260
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C32D0
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9 << 6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C3340
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C33B0
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlBinaryBlock *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
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
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 16 * v10);
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
          CUtlBinaryBlock::CUtlBinaryBlock(this: v12, growSize: 0, initSize: 0);
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
// Address: 0x101C3450
// Name: public: CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>(
        CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *this,
        int growSize,
        int initSize)
{
  CDmxElement **m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (CDmxElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C34A0
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  DmeTime_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_tms = 0x80000000;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101D1C00
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlBinaryBlock *v3; // esi
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->m_nActualLength = 0;
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
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA260
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::FastRemove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf
  int m_Size; // eax
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  __int64 v8; // xmm0_8
  CUtlBinaryBlock *v9; // eax

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v7 = m_Size;
      v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v7 - 1].m_Memory.m_pMemory;
      v9 = &this->m_Memory.m_pMemory[v7 - 1];
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_pMemory = v8;
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_nGrowSize = *(_QWORD *)&v9->m_Memory.m_nGrowSize;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA2E0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::Remove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 16 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101DA350
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultiple(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int *v9; // esi
  bool v10; // sf
  bool v11; // zf
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]
  int elema; // [esp+18h] [ebp+8h]

  v5 = num;
  v6 = elem + num;
  v7 = elem + num - 1;
  v12 = elem + num;
  if ( v7 >= elem )
  {
    v8 = 16 * v7;
    elema = 16 * v7;
    v13 = num;
    do
    {
      v9 = (int *)((char *)this->m_Memory.m_pMemory + v8);
      v10 = v9[2] < 0;
      v9[3] = 0;
      if ( !v10 )
      {
        if ( *v9 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v9);
          v6 = v12;
          v8 = elema;
          *v9 = 0;
        }
        v9[1] = 0;
      }
      v8 -= 16;
      v11 = v13-- == 1;
      elema = v8;
    }
    while ( !v11 );
    v5 = num;
  }
  if ( this->m_Size - elem - v5 > 0 && v5 > 0 )
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[v6],
      count: 16 * (this->m_Size - elem - v5));
    v5 = num;
  }
  this->m_Size -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x101DFB80
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::CopyArray(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::CopyArray(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        const float *pArray,
        int size)
{
  int v3; // ebx
  int v4; // edi
  const float *v6; // ecx
  const float *v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  char *v10; // edx
  int v11; // ebx
  double v12; // st7
  char *v13; // edx
  int v14; // [esp+14h] [ebp-4h]

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)this,
    elem: 0,
    num: size);
  v6 = pArray;
  if ( size >= 4 )
  {
    v7 = pArray + 2;
    v8 = -8 - (_DWORD)pArray;
    v9 = ((unsigned int)(size - 4) >> 2) + 1;
    v14 = 8;
    v4 = 4 * v9;
    while ( 1 )
    {
      v10 = (char *)v7 + v8;
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory] = *(v7 - 2);
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 4] = *(v7 - 1);
      v11 = v14;
      v14 += 16;
      *(float *)((char *)this->m_Memory.m_pMemory + v11) = *v7;
      v12 = v7[1];
      v13 = (char *)v7 + 4 - (_DWORD)pArray;
      v7 += 4;
      *(float *)&v13[(unsigned int)this->m_Memory.m_pMemory] = v12;
      if ( --v9 == 0 )
        break;
      v8 = -8 - (_DWORD)pArray;
    }
    v3 = size;
    v6 = pArray;
  }
  for ( ; v4 < v3; ++v4 )
    this->m_Memory.m_pMemory[v4] = v6[v4];
}

//------------------------------------------------------------------------------
// Address: 0x101DFC30
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::CopyArray(bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::CopyArray(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        const bool *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x101DFCA0
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CopyArray(class Vector2D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CopyArray(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        const Vector2D *pArray,
        int size)
{
  int v3; // edi
  signed int v6; // edx
  int v7; // edx
  unsigned int v8; // edi
  float *p_y; // eax
  Vector2D *m_pMemory; // ecx
  char *v11; // edx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  Vector2D *v16; // eax
  unsigned int v17; // ecx
  double x; // st7
  int i; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]
  const Vector2D *pArraya; // [esp+20h] [ebp+8h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v6 = 0;
  if ( size >= 4 )
  {
    v21 = -4 - (_DWORD)pArray;
    v7 = -20 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    v20 = 4 - (_DWORD)pArray;
    p_y = &pArray[2].y;
    pArraya = (const Vector2D *)(-20 - (_DWORD)pArray);
    i = 4 * v8;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v11 = (char *)p_y + v7;
      *(float *)&v11[(_DWORD)m_pMemory] = *(p_y - 5);
      *(float *)&v11[(_DWORD)m_pMemory + 4] = *(p_y - 4);
      v12 = (float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 8];
      *v12 = *(p_y - 3);
      v12[1] = *(p_y - 2);
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v21);
      *v13 = *(p_y - 1);
      v13[1] = *p_y;
      v14 = p_y[1];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v20);
      p_y += 8;
      --v8;
      *v15 = v14;
      v15[1] = *(p_y - 6);
      if ( v8 == 0 )
        break;
      v7 = (int)pArraya;
    }
    v3 = size;
    v6 = i;
  }
  for ( ; v6 < v3; v16[v17].y = pArray[v17].y )
  {
    v16 = this->m_Memory.m_pMemory;
    v17 = v6;
    x = pArray[v6++].x;
    v16[v17].x = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DFD90
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        const Vector *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  double v13; // st7
  float *v14; // ecx
  float *v15; // ecx
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      *(float *)&v10[(_DWORD)m_pMemory + 4] = *(p_z - 4);
      *(float *)&v10[(_DWORD)m_pMemory + 8] = *(p_z - 3);
      v11 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v11 = *(p_z - 2);
      v11[1] = *(p_z - 1);
      v11[2] = *p_z;
      v12 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v12 = p_z[1];
      v12[1] = p_z[2];
      v12[2] = p_z[3];
      v13 = p_z[4];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      p_z += 12;
      --v7;
      *v14 = v13;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = i;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v15 = &pArray[v5].z;
    v16 = v3 - v5;
    do
    {
      v17 = *(v15 - 2);
      v18 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v15 - 8 - (_DWORD)pArray);
      v15 += 3;
      --v16;
      *v18 = v17;
      v18[1] = *(v15 - 4);
      v18[2] = *(v15 - 3);
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DFEA0
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CopyArray(class Vector4D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CopyArray(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        const Vector4D *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector4D *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  float *v16; // ecx
  int v17; // edi
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
    (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this,
    elem: 0,
    num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -24 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 6);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 5);
      v11[2] = *(p_z - 4);
      v11[3] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 16];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v12[3] = p_z[1];
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 8 - (_DWORD)pArray);
      *v13 = p_z[2];
      v13[1] = p_z[3];
      v13[2] = p_z[4];
      v13[3] = p_z[5];
      v14 = p_z[6];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      p_z += 16;
      --v7;
      *v15 = v14;
      v15[1] = *(p_z - 9);
      v15[2] = *(p_z - 8);
      v15[3] = *(p_z - 7);
      if ( v7 == 0 )
        break;
      v6 = -24 - (_DWORD)pArray;
    }
    v3 = size;
    v5 = i;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = (float *)((char *)v16 + (unsigned int)this->m_Memory.m_pMemory - 8 - (_DWORD)pArray);
      *v18 = *(v16 - 2);
      v16 += 4;
      --v17;
      v18[1] = *(v16 - 5);
      v18[2] = *(v16 - 4);
      v18[3] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DFFD0
// Name: public: void CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::CopyArray(class QAngle const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::CopyArray(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        const QAngle *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  QAngle *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  double v13; // st7
  float *v14; // ecx
  float *v15; // ecx
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      *(float *)&v10[(_DWORD)m_pMemory + 4] = *(p_z - 4);
      *(float *)&v10[(_DWORD)m_pMemory + 8] = *(p_z - 3);
      v11 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v11 = *(p_z - 2);
      v11[1] = *(p_z - 1);
      v11[2] = *p_z;
      v12 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v12 = p_z[1];
      v12[1] = p_z[2];
      v12[2] = p_z[3];
      v13 = p_z[4];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      p_z += 12;
      --v7;
      *v14 = v13;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = i;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v15 = &pArray[v5].z;
    v16 = v3 - v5;
    do
    {
      v17 = *(v15 - 2);
      v18 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v15 - 8 - (_DWORD)pArray);
      v15 += 3;
      --v16;
      *v18 = v17;
      v18[1] = *(v15 - 4);
      v18[2] = *(v15 - 3);
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E00E0
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  bool v2; // sf
  CUtlBinaryBlock *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
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
// Address: 0x101E1EA0
// Name: public: class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x13 )
    return (CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E1F00
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x101E1F20
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x101E3730
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0xF )
    return (CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E37A0
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmAttribute::GetValue<class CUtlVector<int,class CUtlMemory<int,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x10 )
    return (CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3800
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3860
// Name: public: class CUtlVector<bool,class CUtlMemory<bool,int>> const __near & CDmAttribute::GetValue<class CUtlVector<bool,class CUtlMemory<bool,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x12 )
    return (CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E38C0
// Name: public: class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Color,class CUtlMemory<class Color,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x16 )
    return (CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3920
// Name: public: class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x17 )
    return (CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3980
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x18 )
    return (CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E39E0
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x19 )
    return (CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3A40
// Name: public: class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1A )
    return (CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3AA0
// Name: public: class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1B )
    return (CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3B00
// Name: public: class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1C )
    return (CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3B60
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101E3C70
// Name: public: class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage);
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x14 )
    return (CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x101EAE60
// Name: public: void CUtlVector<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,class CUtlMemory<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v6; // [esp+8h] [ebp-4h]

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
// Address: 0x101ECD70
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(int,struct CDmElementDictionary::DmIdPair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(
        CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *this,
        int elem,
        const CDmElementDictionary::DmIdPair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::DmIdPair_t *m_pMemory; // ecx
  int v7; // eax
  CDmElementDictionary::DmIdPair_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ParticleChildrenInfo_t,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x101EDAA0
// Name: public: int CUtlVector<struct CDmElementDictionary::AttributeInfo_t,class CUtlMemory<struct CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::AttributeInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101EDB00
// Name: public: int CUtlVector<struct CDmElementDictionary::DeletionInfo_t,class CUtlMemory<struct CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::DeletionInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101F0BB0
// Name: public: void CUtlMemory<class MDkeyvalue,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MDkeyvalue,int>::Grow(CUtlMemory<MDkeyvalue,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MDkeyvalue *m_pMemory; // edx
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
    v7 = 592 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MDkeyvalue *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MDkeyvalue *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1810
// Name: public: int CUtlVector<class MDkeyvalue,class CUtlMemory<class MDkeyvalue,int>>::InsertBefore(int,class MDkeyvalue const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MDkeyvalue,CUtlMemory<MDkeyvalue,int>>::InsertBefore(
        CUtlVector<MDkeyvalue,CUtlMemory<MDkeyvalue,int> > *this,
        int elem,
        const MDkeyvalue *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MDkeyvalue *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MDkeyvalue,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 592 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F3510
// Name: public: void CUtlMemory<struct FGDAutoVisGroups_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<FGDAutoVisGroups_s,int>::Grow(CUtlMemory<FGDAutoVisGroups_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  FGDAutoVisGroups_s *m_pMemory; // edx
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
    v7 = 280 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (FGDAutoVisGroups_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (FGDAutoVisGroups_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F35B0
// Name: public: void CUtlMemory<struct FGDMatExlcusions_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<FGDMatExlcusions_s,int>::Grow(CUtlMemory<FGDMatExlcusions_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  FGDMatExlcusions_s *m_pMemory; // edx
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
    v7 = 261 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (FGDMatExlcusions_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (FGDMatExlcusions_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3C30
// Name: public: int CUtlVector<struct FGDVisGroupsBaseClass_s,class CUtlMemory<struct FGDVisGroupsBaseClass_s,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  FGDAutoVisGroups_s *m_pMemory; // ecx
  int v6; // eax
  FGDAutoVisGroups_s *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<FGDAutoVisGroups_s,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 280 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Classes.m_Memory.m_pMemory = nullptr;
    v7->m_Classes.m_Memory.m_nAllocationCount = 0;
    v7->m_Classes.m_Memory.m_nGrowSize = 0;
    v7->m_Classes.m_Size = 0;
    v7->m_Classes.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101F3CC0
// Name: public: void CUtlVector<struct FGDVisGroupsBaseClass_s,class CUtlMemory<struct FGDVisGroupsBaseClass_s,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::RemoveAll(
        CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int> > *v3; // esi
  CFoW_LineOccluder **m_pMemory; // eax
  CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 280 * v1;
    for ( i = 280 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int> > *)&this->m_Memory.m_pMemory->szClass[v2];
      CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int>>::PurgeAndDeleteElements(this: v3 + 13);
      v3[13].m_Size = 0;
      if ( v3[13].m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3[13].m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3[13].m_Memory.m_pMemory);
          v3[13].m_Memory.m_pMemory = nullptr;
        }
        v3[13].m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3[13].m_Memory.m_pMemory;
      v3[13].m_pElements = m_pMemory;
      if ( v3[13].m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3[13].m_Memory.m_pMemory = nullptr;
        }
        v3[13].m_Memory.m_nAllocationCount = 0;
      }
      i -= 280;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3D90
// Name: public: void CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::RemoveAll(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  FGDAutoVisGroups_s *v3; // esi
  bool v4; // sf
  FGDVisGroupsBaseClass_s *m_pMemory; // eax
  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::RemoveAll(this: &v3->m_Classes);
      if ( v3->m_Classes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Classes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Classes.m_Memory.m_pMemory);
          v3->m_Classes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Classes.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Classes.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Classes.m_Memory.m_pMemory;
      v3->m_Classes.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Classes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Classes.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F42C0
// Name: public: CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>::~CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::~CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this)
{
  bool v2; // sf
  FGDAutoVisGroups_s *m_pMemory; // eax

  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::RemoveAll(this);
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
// Address: 0x101F4BD0
// Name: public: void CUtlMemory<struct GDIVITEM,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<GDIVITEM,int>::Grow(CUtlMemory<GDIVITEM,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  GDIVITEM *m_pMemory; // edx
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
    v7 = 268 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (GDIVITEM *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (GDIVITEM *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4DB0
// Name: public: int CUtlVector<struct GDIVITEM,class CUtlMemory<struct GDIVITEM,int>>::InsertBefore(int,struct GDIVITEM const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
        CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int> > *this,
        int elem,
        const GDIVITEM *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  GDIVITEM *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 268 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F7F20
// Name: public: void CUtlMemory<class IDmFormatUpdater __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IDmFormatUpdater *,int>::Grow(CUtlMemory<vgui::TreeNode *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::TreeNode **m_pMemory; // edx
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
      this->m_pMemory = (vgui::TreeNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::TreeNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F91C0
// Name: public: void CUtlVector<class CFoW_Viewer __near *,class CUtlMemory<class CFoW_Viewer __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFoW_Viewer *,CUtlMemory<CFoW_Viewer *,int>>::PurgeAndDeleteElements(
        CUtlVector<CFoW_Viewer *,CUtlMemory<CFoW_Viewer *,int> > *this)
{
  int i; // edi
  CFoW_Viewer *v3; // ebx
  bool v4; // sf
  CFoW_Viewer **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CFoW_Viewer::~CFoW_Viewer(this: this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
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
// Address: 0x101F9230
// Name: public: void CUtlVector<class CFoW_TriSoupCollection __near *,class CUtlMemory<class CFoW_TriSoupCollection __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFoW_TriSoupCollection *,CUtlMemory<CFoW_TriSoupCollection *,int>>::PurgeAndDeleteElements(
        CUtlVector<CFoW_TriSoupCollection *,CUtlMemory<CFoW_TriSoupCollection *,int> > *this)
{
  int i; // edi
  CFoW_TriSoupCollection *v3; // ebx
  bool v4; // sf
  CFoW_TriSoupCollection **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CFoW_TriSoupCollection::~CFoW_TriSoupCollection(this: this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
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
// Address: 0x101F9F70
// Name: public: int CUtlVector<struct CUtlSphereTree::Node,class CUtlMemory<struct CUtlSphereTree::Node,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int>>::AddToTail(
        CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CUtlSphereTree::Node *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ParticleChildrenInfo_t,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101FC3B0
// Name: public: void CUtlVector<class CFoW_LineOccluder __near *,class CUtlMemory<class CFoW_LineOccluder __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int>>::PurgeAndDeleteElements(
        CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CFoW_LineOccluder **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    operator delete(p: this->m_Memory.m_pMemory[i]);
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
// Address: 0x10208A30
// Name: public: int CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>>::InsertMultipleBefore(int,int,char const __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
        CUtlVector<char const *,CUtlMemory<char const *,int> > *this,
        int elem,
        int num,
        const char *const *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  const char **m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  const char **v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &(&m_pMemory[elem])[num], src: &m_pMemory[elem], count: 4 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *v13 = pToInsert[v11];
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10209850
// Name: public: int CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>>::AddVectorToTail(class CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::AddVectorToTail(
        CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *this,
        const CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  IMemAlloc_vtbl *v6; // edx
  AssetUsageInfo_t *v7; // eax
  AssetUsageInfo_t *m_pMemory; // ecx
  int v9; // eax
  AssetUsageInfo_t *v10; // edi
  CUtlString *v11; // ebx
  bool v12; // zf
  int v14; // [esp-4h] [ebp-20h]
  int base; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  v5 = v4 + m_Size;
  base = m_Size;
  if ( this->m_Memory.m_nAllocationCount < v4 + m_Size && this->m_Memory.m_nGrowSize >= 0 )
  {
    this->m_Memory.m_nAllocationCount = v5;
    v6 = _g_pMemAlloc->__vftable;
    v14 = 20 * v5;
    if ( this->m_Memory.m_pMemory != nullptr )
      v7 = (AssetUsageInfo_t *)((int (__stdcall *)(AssetUsageInfo_t *, int))v6->Realloc_2)(
                                 a1: this->m_Memory.m_pMemory,
                                 a2: v14);
    else
      v7 = (AssetUsageInfo_t *)((int (__stdcall *)(int))v6->Alloc_2)(a1: v14);
    this->m_Memory.m_pMemory = v7;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size += v4;
  this->m_pElements = m_pMemory;
  if ( v4 <= 0 )
    return m_Size;
  v9 = 20 * m_Size;
  v18 = 0;
  v17 = 20 * m_Size;
  v16 = v4;
  do
  {
    v10 = &src->m_Memory.m_pMemory[v18];
    v11 = (CUtlString *)((char *)&this->m_Memory.m_pMemory->m_assetName + v9);
    if ( v11 != nullptr )
    {
      CUtlString::CUtlString(this: v11, string: &src->m_Memory.m_pMemory[v18].m_assetName);
      v11[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v10->m_nTimesUsed;
      v9 = v17;
    }
    ++v18;
    v9 += 20;
    v12 = v16-- == 1;
    v17 = v9;
  }
  while ( !v12 );
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x10209A20
// Name: public: void CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(
        CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  ExportedControl_t *v3; // esi
  CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int> > *v4; // [esp+4h] [ebp-4h]

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
// Address: 0x10209B90
// Name: public: void CUtlVector<struct CacheModInfo_t,class CUtlMemory<struct CacheModInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::RemoveAll(
        CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 32 * v1;
    v4 = 32 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 7) = 0;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 4));
          this = v5;
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
          this = v5;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v4 - 32;
      v4 -= 32;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AB40
// Name: public: CUtlVector<struct CacheModInfo_t,class CUtlMemory<struct CacheModInfo_t,int>>::~CUtlVector<struct CacheModInfo_t,class CUtlMemory<struct CacheModInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::~CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>(
        CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int> > *this)
{
  bool v2; // sf
  CacheModInfo_t *m_pMemory; // eax

  CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::RemoveAll(this);
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
// Address: 0x102110C0
// Name: public: class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> const __near & CDmxAttribute::GetArray<class CDmxElement __near *>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CDmxAttribute::GetArray<CDmxElement *>(
        CDmxAttribute *this)
{
  if ( this->m_Type == AT_FIRST_ARRAY_TYPE )
    return (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x10211110
// Name: public: void CUtlVector<struct PCFToLoad_t,class CUtlMemory<struct PCFToLoad_t,int>>::RemoveMultipleFromTail(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int>>::RemoveMultipleFromTail(
        CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int> > *this,
        int num)
{
  int m_Size; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // ecx
  int *v7; // esi
  bool v8; // sf
  int v9; // [esp+8h] [ebp-4h]

  m_Size = this->m_Size;
  v4 = num;
  v5 = m_Size - num;
  if ( m_Size - num < m_Size )
  {
    v6 = 20 * v5;
    v9 = 20 * v5;
    do
    {
      v7 = (int *)((char *)this->m_Memory.m_pMemory + v6);
      v8 = v7[2] < 0;
      v7[3] = 0;
      if ( !v8 )
      {
        if ( *v7 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v7);
          v6 = v9;
          *v7 = 0;
        }
        v7[1] = 0;
      }
      ++v5;
      v6 += 20;
      v9 = v6;
    }
    while ( v5 < this->m_Size );
    v4 = num;
  }
  this->m_Size -= v4;
}

//------------------------------------------------------------------------------
// Address: 0x10211190
// Name: public: void CUtlVector<struct PCFToLoad_t,class CUtlMemory<struct PCFToLoad_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int>>::RemoveAll(
        CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  PCFToLoad_t *v3; // esi
  CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->m_FileName.m_Storage.m_nActualLength = 0;
      if ( v3->m_FileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_FileName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_FileName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_FileName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_FileName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211200
// Name: public: int CUtlVector<struct CachedParticleInfo_t,class CUtlMemory<struct CachedParticleInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int>>::InsertBefore(
        CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CachedParticleInfo_t *m_pMemory; // ecx
  int v6; // eax
  CachedParticleInfo_t *v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CElementTreeViewListControl::ColumnPanels_t,int>,int>::Grow(
      (CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> *)this,
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
    CUtlString::CUtlString(this: &v7->m_AssetInfo.m_AssetName);
    CUtlString::CUtlString(this: &v7->m_FileName);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10211400
// Name: public: CUtlVector<struct PCFToLoad_t,class CUtlMemory<struct PCFToLoad_t,int>>::~CUtlVector<struct PCFToLoad_t,class CUtlMemory<struct PCFToLoad_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int>>::~CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int>>(
        CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int> > *this)
{
  bool v2; // sf
  PCFToLoad_t *m_pMemory; // eax

  CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int>>::RemoveAll(this);
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
// Address: 0x10211460
// Name: public: void CUtlVector<struct CachedParticleInfo_t,class CUtlMemory<struct CachedParticleInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int>>::RemoveAll(
        CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 40 * v1;
    v4 = 40 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 9) = 0;
      if ( *((int *)v3 + 8) >= 0 )
      {
        if ( *((_DWORD *)v3 + 6) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 6));
          this = v5;
          *((_DWORD *)v3 + 6) = 0;
        }
        *((_DWORD *)v3 + 7) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v5;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v4 - 40;
      v4 -= 40;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211880
// Name: public: CUtlVector<struct CachedParticleInfo_t,class CUtlMemory<struct CachedParticleInfo_t,int>>::~CUtlVector<struct CachedParticleInfo_t,class CUtlMemory<struct CachedParticleInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int>>::~CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int>>(
        CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int> > *this)
{
  bool v2; // sf
  CachedParticleInfo_t *m_pMemory; // eax

  CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int>>::RemoveAll(this);
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
// Address: 0x102118E0
// Name: public: void CUtlVector<class CUtlVector<struct CParticleSnapshotGrid::PSysRelativeInfo_t,class CUtlMemory<struct CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,class CUtlMemory<class CUtlVector<struct CParticleSnapshotGrid::PSysRelativeInfo_t,class CUtlMemory<struct CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> >,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> >,int> > *this)
{
  int v1; // edi
  int v2; // eax
  CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int> > *v3; // esi
  PCFToLoad_t *m_pMemory; // eax
  CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> >,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> >,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    for ( i = 20 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int> > *)((char *)this->m_Memory.m_pMemory + v2);
      CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      i -= 20;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211FB0
// Name: public: CUtlVector<class CUtlVector<struct CParticleSnapshotGrid::PSysRelativeInfo_t,class CUtlMemory<struct CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,class CUtlMemory<class CUtlVector<struct CParticleSnapshotGrid::PSysRelativeInfo_t,class CUtlMemory<struct CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>::~CUtlVector<class CUtlVector<struct CParticleSnapshotGrid::PSysRelativeInfo_t,class CUtlMemory<struct CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,class CUtlMemory<class CUtlVector<struct CParticleSnapshotGrid::PSysRelativeInfo_t,class CUtlMemory<struct CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>::~CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>(
        CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> >,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>::RemoveAll(this);
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
// Address: 0x10212C70
// Name: public: void CUtlVector<struct CMDLPanel::MDLData_t,class CUtlMemory<struct CMDLPanel::MDLData_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(
        CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CMDLPanel::MDLData_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CMDL::~CMDL(this: &this->m_Memory.m_pMemory[v3--].m_MDL);
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
// Address: 0x10215690
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10215720
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmxAttribute::GetArray<class Vector>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CDmxAttribute::GetArray<Vector>(CDmxAttribute *this)
{
  if ( this->m_Type == AT_VECTOR3_ARRAY )
    return (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<Vector>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<Vector>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<Vector>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<Vector>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x10215B80
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmxElement::GetArray<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CDmxElement::GetArray<Vector>(
        CDmxElement *this,
        const char *pAttributeName)
{
  CDmxAttribute *Attribute; // eax

  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmxAttribute::GetArray<Vector>(this: Attribute);
  if ( (`CDmxElement::GetArray<Vector>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxElement::GetArray<Vector>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
    `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
    `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
    `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Size = 0;
    `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_pElements = nullptr;
    atexit(func: `CDmxElement::GetArray<Vector>'::`4'::`dynamic atexit destructor for 'defaultValue'');
  }
  return &`CDmxElement::GetArray<Vector>'::`4'::defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10215BF0
// Name: public: class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> const __near & CDmxElement::GetArray<class CDmxElement __near *>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CDmxElement::GetArray<CDmxElement *>(
        CDmxElement *this,
        const char *pAttributeName)
{
  CDmxAttribute *Attribute; // eax

  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
  if ( (`CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Size = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_pElements = nullptr;
    atexit(func: `CDmxElement::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultValue'');
  }
  return &`CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10219CF0
// Name: public: class CUtlVector<class IParticleOperatorDefinition __near *,class CUtlMemory<class IParticleOperatorDefinition __near *,int>> __near & CParticleSystemMgr::GetAvailableParticleOperatorList(enum ParticleFunctionType_t)
// Source: json
//------------------------------------------------------------------------------
CParticleSystemMgr *__thiscall CParticleSystemMgr::GetAvailableParticleOperatorList(
        CParticleSystemMgr *this,
        ParticleFunctionType_t nWhichList)
{
  return (CParticleSystemMgr *)((char *)this + 20 * nWhichList);
}

//------------------------------------------------------------------------------
// Address: 0x1021A980
// Name: public: void CUtlMemory<struct ParticleChildrenInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ParticleChildrenInfo_t,int>::Grow(
        CUtlMemory<vgui::RichText::TFormatStream,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::RichText::TFormatStream *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v7);
    else
      this->m_pMemory = (vgui::RichText::TFormatStream *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021C5A0
// Name: public: void CUtlVector<class CSheet __near *,class CUtlMemory<class CSheet __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CSheet *,CUtlMemory<CSheet *,int>>::PurgeAndDeleteElements(
        CUtlVector<CSheet *,CUtlMemory<CSheet *,int> > *this)
{
  int i; // edi
  CSheet *v3; // ebx
  bool v4; // sf
  CSheet **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CSheet::~CSheet(this: this->m_Memory.m_pMemory[i]);
      operator delete(p: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
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
// Address: 0x1021C610
// Name: public: void CUtlVector<class CParticleOperatorInstance __near *,class CUtlMemory<class CParticleOperatorInstance __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleOperatorInstance *,CUtlMemory<CParticleOperatorInstance *,int>>::PurgeAndDeleteElements(
        CUtlVector<CParticleOperatorInstance *,CUtlMemory<CParticleOperatorInstance *,int> > *this)
{
  int i; // edi
  CParticleOperatorInstance *v3; // ecx
  bool v4; // sf
  CParticleOperatorInstance **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CParticleOperatorInstance *, int))v3->dtr_CParticleOperatorInstance)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
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
// Address: 0x1021C680
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CParticleSystemDefinition **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
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
// Address: 0x1021C6F0
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
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
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
// Address: 0x1021D990
// Name: public: void CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(
        CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021FAA0
// Name: public: CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>::~CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::~CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>(
        CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *this)
{
  bool v2; // sf
  CParticleSystemMgr::RenderCache_t *m_pMemory; // eax

  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(this);
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
// Address: 0x102A6D80
// Name: public: int CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>::InsertBefore(int,struct CacheOptimizedTriangle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
        CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int> > *this,
        int elem,
        const CacheOptimizedTriangle *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  CacheOptimizedTriangle *v10; // eax

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        this: &this->m_Memory,
        nBlocks: m_nBlocks + (v6 + v7 - 1) / v6);
  }
  v8 = ++this->m_Size - elem - 1;
  this->m_pElements = nullptr;
  if ( v8 > 0 )
  {
    v9 = *((_DWORD *)&this->m_Memory + 2);
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + 1) >> (v9 >> 27)][(elem + 1) & ((32 * v9) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (v9 >> 27)][elem & ((32 * v9) >> 5)],
      count: 48 * v8);
  }
  v10 = &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                               & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v10 != nullptr )
    *v10 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102BAFB0
// Name: public: void CUtlMemory<class CMDLAttachmentData,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMDLAttachmentData,int>::Grow(CUtlMemory<CMDLAttachmentData,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMDLAttachmentData *m_pMemory; // edx
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
    v7 = 52 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMDLAttachmentData *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CMDLAttachmentData *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BB210
// Name: public: int CUtlVector<class CMDLAttachmentData,class CUtlMemory<class CMDLAttachmentData,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int>>::InsertMultipleBefore(
        CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMDLAttachmentData *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMDLAttachmentData,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 52 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102BF110
// Name: public: int CUtlVector<struct CWindowPositionMgr::LoadInfo_t,class CUtlMemory<struct CWindowPositionMgr::LoadInfo_t,int>>::InsertBefore(int,struct CWindowPositionMgr::LoadInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWindowPositionMgr::LoadInfo_t,CUtlMemory<CWindowPositionMgr::LoadInfo_t,int>>::InsertBefore(
        CUtlVector<CWindowPositionMgr::LoadInfo_t,CUtlMemory<CWindowPositionMgr::LoadInfo_t,int> > *this,
        int elem,
        const CWindowPositionMgr::LoadInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWindowPositionMgr::LoadInfo_t *m_pMemory; // ecx
  int v7; // eax
  CWindowPositionMgr::LoadInfo_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
// Address: 0x102BF7B0
// Name: public: int CUtlVector<struct CToolsRecentFileList::RecentFileInfo_t,class CUtlMemory<struct CToolsRecentFileList::RecentFileInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::InsertBefore(
        CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CToolsRecentFileList::RecentFileInfo_t *m_pMemory; // ecx
  int v6; // eax
  CToolsRecentFileList::RecentFileInfo_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ParticleChildrenInfo_t,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_pFileName);
    CUtlString::CUtlString(this: &v7->m_pFileFormat);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102BF820
// Name: public: void CUtlVector<struct CToolsRecentFileList::RecentFileInfo_t,class CUtlMemory<struct CToolsRecentFileList::RecentFileInfo_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int>>::Remove(
        CUtlVector<CToolsRecentFileList::RecentFileInfo_t,CUtlMemory<CToolsRecentFileList::RecentFileInfo_t,int> > *this,
        int elem)
{
  CToolsRecentFileList::RecentFileInfo_t *v3; // esi
  int v4; // eax

  v3 = &this->m_Memory.m_pMemory[elem];
  v3->m_pFileFormat.m_Storage.m_nActualLength = 0;
  if ( v3->m_pFileFormat.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3->m_pFileFormat.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_pFileFormat.m_Storage.m_Memory.m_pMemory);
      v3->m_pFileFormat.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v3->m_pFileFormat.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v3->m_pFileName.m_Storage.m_nActualLength = 0;
  if ( v3->m_pFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3->m_pFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_pFileName.m_Storage.m_Memory.m_pMemory);
      v3->m_pFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v3->m_pFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_Size - elem - 1;
  if ( v4 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 32 * v4);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102CCDE0
// Name: public: void CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::Purge(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  vgui::BoundKey_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      if ( !this->m_Memory.m_pMemory[v3].isbuiltin )
        operator delete(p: (void *)this->m_Memory.m_pMemory[v3].bindingname);
      --v3;
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
// Address: 0x102CD600
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertMultipleBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::BoundKey_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CGridNavCell,int>::Grow((CUtlMemory<CGridNavCell,int> *)this, num: num + m_Size - m_nAllocationCount);
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
          v11->isbuiltin = true;
          v11->bindingname = nullptr;
          v11->keycode = 0;
          v11->modifiers = 0;
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
// Address: 0x102CE930
// Name: public: int CUtlVector<class vgui::CSizerBase::CSizerMember,class CUtlMemory<class vgui::CSizerBase::CSizerMember,int>>::InsertBefore(int,class vgui::CSizerBase::CSizerMember const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CSizerBase::CSizerMember,CUtlMemory<vgui::CSizerBase::CSizerMember,int>>::InsertBefore(
        CUtlVector<vgui::CSizerBase::CSizerMember,CUtlMemory<vgui::CSizerBase::CSizerMember,int> > *this,
        int elem,
        const vgui::CSizerBase::CSizerMember *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CSizerBase::CSizerMember *m_pMemory; // ecx
  int v7; // eax
  vgui::CSizerBase::CSizerMember *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::CSizerBase::CSizerMember,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102CEAC0
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102D0D90
// Name: public: void CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::SetCount(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int count)
{
  int v3; // esi
  int v4; // edi

  v3 = this->m_Size - 1;
  if ( v3 >= 0 )
  {
    v4 = v3;
    do
    {
      if ( !this->m_Memory.m_pMemory[v4].isbuiltin )
        operator delete(p: (void *)this->m_Memory.m_pMemory[v4].bindingname);
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  this->m_Size = 0;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertMultipleBefore(this, elem: 0, num: count);
}

//------------------------------------------------------------------------------
// Address: 0x102D41D0
// Name: public: class CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>> __near & CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::operator=(class CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *__thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::operator=(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        const CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *other)
{
  int m_Size; // esi
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *v3; // ebx
  int v4; // ecx
  bool *v5; // esi
  bool *v6; // edi
  bool v7; // al
  bool v8; // zf
  const char *v9; // eax
  unsigned int v10; // kr00_4
  char *v13; // [esp+Ch] [ebp-10h]
  char *pSrc; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  m_Size = other->m_Size;
  v3 = this;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::SetCount(this, count: m_Size);
  if ( m_Size > 0 )
  {
    v4 = 0;
    v16 = 0;
    v15 = m_Size;
    do
    {
      v5 = &other->m_Memory.m_pMemory->isbuiltin + v4;
      v6 = &v3->m_Memory.m_pMemory->isbuiltin + v4;
      if ( v6 != v5 )
      {
        v7 = *v5;
        *v6 = *v5;
        v8 = !v7;
        v9 = *((const char **)v5 + 1);
        if ( v8 )
        {
          pSrc = *((char **)v5 + 1);
          if ( v9 != nullptr )
          {
            v10 = strlen(v9);
            v13 = (char *)operator new(nSize: v10 + 1);
            V_strncpy(pDest: v13, pSrc, maxLen: v10 + 1);
            v9 = v13;
            v3 = this;
            v4 = v16;
          }
        }
        *((_DWORD *)v6 + 1) = v9;
        *((_DWORD *)v6 + 2) = *((_DWORD *)v5 + 2);
        *((_DWORD *)v6 + 3) = *((_DWORD *)v5 + 3);
      }
      v4 += 16;
      v8 = v15-- == 1;
      v16 = v4;
    }
    while ( !v8 );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102D9F90
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102DB220
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::Remove(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int v3; // eax

  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Memory.m_pMemory[elem].cmdList);
  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 28 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102DB280
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DC160
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
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
// Address: 0x102E2AC0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x102E44A0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

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
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4B00
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x103026B0
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ParticleChildrenInfo_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10309E20
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1030C3E0
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
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
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
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
// Address: 0x10312260
// Name: public: int CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::InsertBefore(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::FileData_t *m_pMemory; // ecx
  int v6; // eax
  vgui::FileData_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::FileData_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 288 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_FileAttributes);
    CUtlString::CUtlString(this: &v7->m_CreationTime);
    CUtlString::CUtlString(this: &v7->m_LastAccessTime);
    CUtlString::CUtlString(this: &v7->m_LastWriteTime);
    CUtlString::CUtlString(this: &v7->m_FileName);
    CUtlString::CUtlString(this: &v7->m_FullPath);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103131C0
// Name: public: void CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::Purge(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  vgui::FileData_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      vgui::FileData_t::~FileData_t(this: &this->m_Memory.m_pMemory[v3--]);
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
// Address: 0x1031BB60
// Name: public: void CUtlVector<struct vgui::PropertySheet::Page_t,class CUtlMemory<struct vgui::PropertySheet::Page_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int>>::Remove(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 8 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1031BBA0
// Name: public: int CUtlVector<class CMapSolid __near *,class CUtlMemory<class CMapSolid __near *,int>>::Find(class CMapSolid __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMapSolid *,CUtlMemory<CMapSolid *,int>>::Find(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        vgui::PageTab **src)
{
  int m_Size; // edx
  int result; // eax
  vgui::PageTab **i; // ecx

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
// Address: 0x1031BBD0
// Name: public: void CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::Remove(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103248E0
// Name: public: void CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  vgui::CHistoryItem *m_pMemory; // esi
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      operator delete(p: this->m_Memory.m_pMemory[v2].m_text);
      operator delete(p: m_pMemory[v2].m_extraText);
      m_pMemory[v2--].m_text = nullptr;
      if ( --v1 < 0 )
        break;
      this = v4;
    }
    v4->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324DC0
// Name: public: void CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this,
        int elem)
{
  vgui::CHistoryItem *m_pMemory; // esi

  m_pMemory = this->m_Memory.m_pMemory;
  operator delete(p: this->m_Memory.m_pMemory[elem].m_text);
  operator delete(p: m_pMemory[elem].m_extraText);
  m_pMemory[elem].m_text = nullptr;
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 12 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10324EF0
// Name: public: CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::~CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this)
{
  bool v2; // sf
  vgui::CHistoryItem *m_pMemory; // eax

  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this);
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
// Address: 0x10326C80
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10328240
// Name: public: int CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1032A990
// Name: public: void CUtlMemory<struct PanelItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PanelItem_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032B5C0
// Name: public: bool CUtlVector<class CMapView2D __near *,class CUtlMemory<class CMapView2D __near *,int>>::FindAndRemove(class CMapView2D __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CMapView2D *,CUtlMemory<CMapView2D *,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
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
// Address: 0x103322D0
// Name: public: void CUtlMemory<struct ActiveLayer_t<class QAngle>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *)_g_pMemAlloc->Realloc_2(
                                                                                       this: _g_pMemAlloc,
                                                                                       a2: m_pMemory,
                                                                                       a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *)_g_pMemAlloc->Alloc_2(
                                                                                       this: _g_pMemAlloc,
                                                                                       a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10463E80
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlString *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
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
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 16 * v10);
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
          CUtlString::CUtlString(this: v12);
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
// Address: 0x10463F10
// Name: public: int CUtlVector<struct vgui::AnimationController::RanEvent_t,class CUtlMemory<struct vgui::AnimationController::RanEvent_t,int>>::InsertBefore(int,struct vgui::AnimationController::RanEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem,
        const vgui::PropertySheet::Page_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // ecx
  int v7; // eax
  vgui::PropertySheet::Page_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10464570
// Name: public: class CUtlVector<struct CDmePanel::EditorPanelMap_t,class CUtlMemory<struct CDmePanel::EditorPanelMap_t,int>> __near & CUtlStringMap<class CUtlVector<struct CDmePanel::EditorPanelMap_t,class CUtlMemory<struct CDmePanel::EditorPanelMap_t,int>>>::operator[](char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > *__thiscall CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int>>>::operator[](
        CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int> > > *this,
        const char *pString)
{
  int v3; // edi
  int m_Size; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  v3 = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString && m_Size < (unsigned __int16)pString + 1 )
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
      (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)this,
      elem: m_Size,
      num: (unsigned __int16)pString + 1 - m_Size);
  return &this->m_Vector.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10467710
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct OwnerAttribute_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<OwnerAttribute_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<OwnerAttribute_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<OwnerAttribute_t,int> *m_pMemory; // edx

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
      this->m_pMemory = (UtlRBTreeNode_t<OwnerAttribute_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                   this: _g_pMemAlloc,
                                                                   a2: m_pMemory,
                                                                   a3: 60 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<OwnerAttribute_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                   this: _g_pMemAlloc,
                                                                   a2: 60 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10468790
// Name: public: void CUtlVector<class CDmeHandle<class CDmElement,0>,class CUtlMemory<class CDmeHandle<class CDmElement,0>,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int>>::RemoveMultiple(
        CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *this,
        int elem,
        int num)
{
  int v3; // edx
  int i; // edi

  v3 = num;
  for ( i = elem + num - 1; i >= elem; --i )
  {
    if ( g_pDataModel != nullptr )
    {
      CDmeElementRefHelper::Unref(
        this: &this->m_Memory.m_pMemory[i],
        hElement: this->m_Memory.m_pMemory[i].m_handle,
        handleType: HT_WEAK);
      v3 = num;
    }
  }
  if ( this->m_Size - elem - v3 <= 0 || v3 <= 0 )
  {
    this->m_Size -= v3;
  }
  else
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + v3],
      count: 4 * (this->m_Size - elem - v3));
    this->m_Size -= num;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10468810
// Name: public: int CUtlVector<struct CElementPropertiesTreeInternal::SearchResult_t,class CUtlMemory<struct CElementPropertiesTreeInternal::SearchResult_t,int>>::Find(struct CElementPropertiesTreeInternal::SearchResult_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int>>::Find(
        CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int> > *this,
        const CElementPropertiesTreeInternal::SearchResult_t *src)
{
  int v3; // ebx
  int i; // edi
  CElementPropertiesTreeInternal::SearchResult_t *v5; // eax

  v3 = 0;
  if ( this->m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = &this->m_Memory.m_pMemory[i];
    if ( src == v5
      || src->handle.m_handle == v5->handle.m_handle
      && CUtlString::operator==(this: &src->attributeName, src: &v5->attributeName) )
    {
      break;
    }
    if ( ++v3 >= this->m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10468C00
// Name: public: void CUtlVector<class CDmeHandle<class CDmeSource,0>,class CUtlMemory<class CDmeHandle<class CDmeSource,0>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeHandle<CDmeSource,0>,CUtlMemory<CDmeHandle<CDmeSource,0>,int>>::Purge(
        CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CDmeHandle<CDmElement,0> *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel != nullptr )
      CDmeElementRefHelper::Unref(
        this: &this->m_Memory.m_pMemory[i],
        hElement: this->m_Memory.m_pMemory[i].m_handle,
        handleType: HT_WEAK);
  }
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
// Address: 0x1046B2E0
// Name: public: bool CUtlVector<class CDmeHandle<class CDmElement,0>,class CUtlMemory<class CDmeHandle<class CDmElement,0>,int>>::FindAndRemove(class CDmeHandle<class CDmElement,0> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int>>::FindAndRemove(
        CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *this,
        const CDmeHandle<CDmElement,0> *src)
{
  int v3; // esi
  CDmeHandle<CDmElement,0> *i; // eax
  CDmeElementRefHelper *v6; // ecx

  v3 = 0;
  if ( this->m_Size <= 0 )
    return 0;
  for ( i = this->m_Memory.m_pMemory; i->m_handle != src->m_handle; ++i )
  {
    if ( ++v3 >= this->m_Size )
      return 0;
  }
  if ( v3 == -1 )
    return 0;
  v6 = &this->m_Memory.m_pMemory[v3];
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: v6, hElement: *(_DWORD *)v6, handleType: HT_WEAK);
  if ( this->m_Size - v3 - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[v3],
      src: &this->m_Memory.m_pMemory[v3 + 1],
      count: 4 * (this->m_Size - v3 - 1));
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1046BF40
// Name: public: int CUtlVector<class CDmeHandle<class CDmElement,0>,class CUtlMemory<class CDmeHandle<class CDmElement,0>,int>>::InsertBefore(int,class CDmeHandle<class CDmElement,0> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int>>::InsertBefore(
        CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *this,
        int elem,
        const CDmeHandle<CDmElement,0> *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeHandle<CDmElement,0> *m_pMemory; // ecx
  int v7; // eax
  CDmeHandle<CDmElement,0> *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->m_handle = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmElement,0>::Set(this: v8, h: src->m_handle);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x104744F0
// Name: public: void CUtlVector<struct CElementPropertiesTreeInternal::SearchResult_t,class CUtlMemory<struct CElementPropertiesTreeInternal::SearchResult_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int>>::RemoveAll(
        CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CElementPropertiesTreeInternal::SearchResult_t *v3; // esi
  bool v4; // sf
  CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int> > *v5; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v4 = v3->attributeName.m_Storage.m_Memory.m_nGrowSize < 0;
      v3->attributeName.m_Storage.m_nActualLength = 0;
      if ( !v4 )
      {
        if ( v3->attributeName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->attributeName.m_Storage.m_Memory.m_pMemory);
          this = v5;
          v3->attributeName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->attributeName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      if ( g_pDataModel != nullptr )
      {
        CDmeElementRefHelper::Unref(
          this: (CDmeElementRefHelper *)v3,
          hElement: v3->handle.m_handle,
          handleType: HT_WEAK);
        this = v5;
      }
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10474630
// Name: public: int CUtlVector<struct CElementPropertiesTreeInternal::SearchResult_t,class CUtlMemory<struct CElementPropertiesTreeInternal::SearchResult_t,int>>::InsertBefore(int,struct CElementPropertiesTreeInternal::SearchResult_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int>>::InsertBefore(
        CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int> > *this,
        int elem,
        const CElementPropertiesTreeInternal::SearchResult_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CElementPropertiesTreeInternal::SearchResult_t *m_pMemory; // ecx
  int v7; // eax
  CElementPropertiesTreeInternal::SearchResult_t *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->handle.m_handle = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmElement,0>::Set(this: &v8->handle, h: src->handle.m_handle);
    CUtlString::CUtlString(this: &v8->attributeName, string: &src->attributeName);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x104747B0
// Name: public: void CUtlVector<struct CElementPropertiesTreeInternal::TreeItem_t,class CUtlMemory<struct CElementPropertiesTreeInternal::TreeItem_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CElementPropertiesTreeInternal::TreeItem_t,CUtlMemory<CElementPropertiesTreeInternal::TreeItem_t,int>>::RemoveAll(
        CUtlVector<CElementPropertiesTreeInternal::TreeItem_t,CUtlMemory<CElementPropertiesTreeInternal::TreeItem_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CElementPropertiesTreeInternal::TreeItem_t *v3; // esi
  CUtlVector<CElementPropertiesTreeInternal::TreeItem_t,CUtlMemory<CElementPropertiesTreeInternal::TreeItem_t,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->m_pAttributeName.m_Storage.m_nActualLength = 0;
      if ( v3->m_pAttributeName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_pAttributeName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_pAttributeName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_pAttributeName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_pAttributeName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10474D90
// Name: public: CUtlVector<struct CElementPropertiesTreeInternal::SearchResult_t,class CUtlMemory<struct CElementPropertiesTreeInternal::SearchResult_t,int>>::~CUtlVector<struct CElementPropertiesTreeInternal::SearchResult_t,class CUtlMemory<struct CElementPropertiesTreeInternal::SearchResult_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int>>::~CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int>>(
        CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int> > *this)
{
  bool v2; // sf
  CElementPropertiesTreeInternal::SearchResult_t *m_pMemory; // eax

  CUtlVector<CElementPropertiesTreeInternal::SearchResult_t,CUtlMemory<CElementPropertiesTreeInternal::SearchResult_t,int>>::RemoveAll(this);
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
// Address: 0x10476600
// Name: public: CUtlVector<struct CElementPropertiesTreeInternal::TreeItem_t,class CUtlMemory<struct CElementPropertiesTreeInternal::TreeItem_t,int>>::~CUtlVector<struct CElementPropertiesTreeInternal::TreeItem_t,class CUtlMemory<struct CElementPropertiesTreeInternal::TreeItem_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CElementPropertiesTreeInternal::TreeItem_t,CUtlMemory<CElementPropertiesTreeInternal::TreeItem_t,int>>::~CUtlVector<CElementPropertiesTreeInternal::TreeItem_t,CUtlMemory<CElementPropertiesTreeInternal::TreeItem_t,int>>(
        CUtlVector<CElementPropertiesTreeInternal::TreeItem_t,CUtlMemory<CElementPropertiesTreeInternal::TreeItem_t,int> > *this)
{
  bool v2; // sf
  CElementPropertiesTreeInternal::TreeItem_t *m_pMemory; // eax

  CUtlVector<CElementPropertiesTreeInternal::TreeItem_t,CUtlMemory<CElementPropertiesTreeInternal::TreeItem_t,int>>::RemoveAll(this);
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
// Address: 0x10487620
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct SelectionInfo_t __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<SelectionInfo_t *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: m_pMemory,
                                                                                   a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<SelectionInfo_t *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10488790
// Name: public: int CUtlVector<struct AttributeValue_t,class CUtlMemory<struct AttributeValue_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AttributeValue_t,CUtlMemory<AttributeValue_t,int>>::InsertMultipleBefore(
        CUtlVector<AttributeValue_t,CUtlMemory<AttributeValue_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  AttributeValue_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  AttributeValue_t *v13; // ecx
  AttributeValue_t *v14; // ecx
  AttributeValue_t *v15; // ecx
  AttributeValue_t *v16; // ecx
  int v17; // ecx
  int v18; // edi
  AttributeValue_t *v19; // eax
  int i; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CElementTreeViewListControl::ColumnPanels_t,int>,int>::Grow(
      (CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  v10 = 0;
  if ( num >= 4 )
  {
    v11 = elem;
    v12 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v12;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v11];
      if ( v13 != nullptr )
      {
        v13->m_pValue[0] = 0.0;
        v13->m_pValue[1] = 0.0;
        v13->m_pValue[2] = 0.0;
        v13->m_Vector.x = 0.0;
        v13->m_Vector.y = 0.0;
        v13->m_Vector.z = 0.0;
        v13->m_Quaternion = quat_identity;
      }
      v14 = &this->m_Memory.m_pMemory[v11 + 1];
      if ( &this->m_Memory.m_pMemory[v11] != (AttributeValue_t *)-40 )
      {
        v14->m_pValue[0] = 0.0;
        v14->m_pValue[1] = 0.0;
        v14->m_pValue[2] = 0.0;
        v14->m_Vector.x = 0.0;
        v14->m_Vector.y = 0.0;
        v14->m_Vector.z = 0.0;
        v14->m_Quaternion = quat_identity;
      }
      v15 = &this->m_Memory.m_pMemory[v11 + 2];
      if ( &this->m_Memory.m_pMemory[v11] != (AttributeValue_t *)-80 )
      {
        v15->m_pValue[0] = 0.0;
        v15->m_pValue[1] = 0.0;
        v15->m_pValue[2] = 0.0;
        v15->m_Vector.x = 0.0;
        v15->m_Vector.y = 0.0;
        v15->m_Vector.z = 0.0;
        v15->m_Quaternion = quat_identity;
      }
      v16 = &this->m_Memory.m_pMemory[v11 + 3];
      if ( &this->m_Memory.m_pMemory[v11] != (AttributeValue_t *)-120 )
      {
        v16->m_pValue[0] = 0.0;
        v16->m_pValue[1] = 0.0;
        v16->m_pValue[2] = 0.0;
        v16->m_Vector.x = 0.0;
        v16->m_Vector.y = 0.0;
        v16->m_Vector.z = 0.0;
        v16->m_Quaternion = quat_identity;
      }
      v11 += 4;
      --v12;
    }
    while ( v12 != 0 );
    v10 = i;
  }
  if ( v10 < num )
  {
    v17 = v10 + elem;
    v18 = num - v10;
    do
    {
      v19 = &this->m_Memory.m_pMemory[v17];
      if ( v19 != nullptr )
      {
        v19->m_pValue[0] = 0.0;
        v19->m_pValue[1] = 0.0;
        v19->m_pValue[2] = 0.0;
        v19->m_Vector.x = 0.0;
        v19->m_Vector.y = 0.0;
        v19->m_Vector.z = 0.0;
        v19->m_Quaternion = quat_identity;
      }
      ++v17;
      --v18;
    }
    while ( v18 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1049B180
// Name: public: void CUtlMemory<class CPresetSlider __near *,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPresetSlider *,int>::ConvertToGrowableMemory(
        CUtlMemory<CPresetSlider *,int> *this,
        int nGrowSize)
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
      this->m_pMemory = (CPresetSlider **)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049BA30
// Name: public: int CUtlVector<struct PresetGroupInfo_t,class CUtlMemory<struct PresetGroupInfo_t,int>>::InsertBefore(int,struct PresetGroupInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int>>::InsertBefore(
        CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > *this,
        int elem,
        const PresetGroupInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PresetGroupInfo_t *m_pMemory; // ecx
  int v7; // eax
  PresetGroupInfo_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
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
// Address: 0x1049BAB0
// Name: public: int CUtlVector<class CPresetSlider __near *,class CUtlMemoryFixedGrowable<class CPresetSlider __near *,100,int>>::InsertBefore(int,class CPresetSlider __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPresetSlider *,CUtlMemoryFixedGrowable<CPresetSlider *,100,int>>::InsertBefore(
        CUtlVector<CPresetSlider *,CUtlMemoryFixedGrowable<CPresetSlider *,100,int> > *this,
        int elem,
        CPresetSlider **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  CPresetSlider **m_pMemory; // ecx
  int v8; // eax
  CPresetSlider **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<CPresetSlider *,int>::ConvertToGrowableMemory(
        this: &this->m_Memory,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v6);
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
// Address: 0x104A04F0
// Name: public: int CUtlVector<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,class CUtlMemory<struct CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int>>::AddToTail(
        CUtlVector<CBaseAnimSetControlGroupPanel::ElementExpansion_t,CUtlMemory<CBaseAnimSetControlGroupPanel::ElementExpansion_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CBaseAnimSetControlGroupPanel::ElementExpansion_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x104B5060
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmElement::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(this: Attribute);
  else
    return &`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x104B5160
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *,class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x104B51D0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *,class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x104B5BD0
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x104B5C30
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x104C0F90
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmxAttribute::GetArray<float>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmxAttribute::GetArray<float>(CDmxAttribute *this)
{
  if ( this->m_Type == AT_FLOAT_ARRAY )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<float>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<float>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<float>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<float>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x104DB050
// Name: public: int CUtlVector<struct matrix3x4_t,class CUtlMemory<struct matrix3x4_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
        CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  matrix3x4_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<matrix3x4_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 48 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x104E5680
// Name: public: int CUtlVector<struct CDmeMesh::FaceSet_t,class CUtlMemory<struct CDmeMesh::FaceSet_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeMesh::FaceSet_t,CUtlMemory<CDmeMesh::FaceSet_t,int>>::InsertMultipleBefore(
        CUtlVector<CDmeMesh::FaceSet_t,CUtlMemory<CDmeMesh::FaceSet_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeMesh::FaceSet_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CDmeMesh::FaceSet_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_bBuilt = false;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x104E7F10
// Name: public: void CUtlMemory<struct matrix3x4_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<matrix3x4_t,int>::Grow(
        CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::AnimationController::AnimCommand_t *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::AnimationController::AnimCommand_t *)_g_pMemAlloc->Realloc_2(
                                                                      this: _g_pMemAlloc,
                                                                      a2: m_pMemory,
                                                                      a3: v7);
    else
      this->m_pMemory = (vgui::AnimationController::AnimCommand_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104E8C50
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertMultipleBefore(int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num,
        const int *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int *v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *v13 = pToInsert[v11];
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x104E9150
// Name: public: void CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CDmeCombinationOperator::RawControlInfo_t *v3; // esi
  CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *v4; // [esp+4h] [ebp-4h]

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
// Address: 0x104E91C0
// Name: public: int CUtlVector<struct CDmeCombinationOperator::CombinationOperation_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationOperation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::InsertBefore(
        CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeCombinationOperator::CombinationOperation_t *m_pMemory; // ecx
  int v6; // eax
  CDmeCombinationOperator::CombinationOperation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> *)this,
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
    v7->m_ControlIndices.m_Memory.m_pMemory = nullptr;
    v7->m_ControlIndices.m_Memory.m_nAllocationCount = 0;
    v7->m_ControlIndices.m_Memory.m_nGrowSize = 0;
    v7->m_ControlIndices.m_Size = 0;
    v7->m_ControlIndices.m_pElements = nullptr;
    v7->m_DominatorIndices.m_Memory.m_pMemory = nullptr;
    v7->m_DominatorIndices.m_Memory.m_nAllocationCount = 0;
    v7->m_DominatorIndices.m_Memory.m_nGrowSize = 0;
    v7->m_DominatorIndices.m_Size = 0;
    v7->m_DominatorIndices.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x104E9240
// Name: public: void CUtlVector<struct CDmeCombinationOperator::CombinationOperation_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int> > *v6; // [esp+4h] [ebp-8h]
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
// Address: 0x104E9330
// Name: public: CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::RawControlInfo_t,class CUtlMemory<struct CDmeCombinationOperator::RawControlInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::RawControlInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::RawControlInfo_t,CUtlMemory<CDmeCombinationOperator::RawControlInfo_t,int>>::RemoveAll(this);
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
// Address: 0x104E9390
// Name: public: void CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 40 * v1;
    v7 = 40 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      v4 = *((void **)v3 + 5);
      *((_DWORD *)v3 + 9) = v4;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
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
      v5 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 40;
      v7 -= 40;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104E9750
// Name: public: CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::DominatorInfo_t,class CUtlMemory<struct CDmeCombinationOperator::DominatorInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::DominatorInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::DominatorInfo_t,CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int>>::RemoveAll(this);
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
// Address: 0x104E9A70
// Name: public: int CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::AnimSequence_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::AnimSequence_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::CSizerBase::CSizerMember,int>::Grow(
      (CUtlMemory<vgui::CSizerBase::CSizerMember,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->cmdList.m_Memory.m_pMemory = nullptr;
    v7->cmdList.m_Memory.m_nAllocationCount = 0;
    v7->cmdList.m_Memory.m_nGrowSize = 0;
    v7->cmdList.m_Size = 0;
    v7->cmdList.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x104EA0F0
// Name: public: void CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CDmeCombinationOperator::CombinationInfo_t *v3; // esi
  bool v4; // sf
  CDmeCombinationOperator::CombinationOperation_t *m_pMemory; // eax
  CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<CDmeCombinationOperator::CombinationOperation_t,CUtlMemory<CDmeCombinationOperator::CombinationOperation_t,int>>::RemoveAll(this: &v3->m_Outputs);
      if ( v3->m_Outputs.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Outputs.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Outputs.m_Memory.m_pMemory);
          v3->m_Outputs.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Outputs.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Outputs.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Outputs.m_Memory.m_pMemory;
      v3->m_Outputs.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Outputs.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Outputs.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x104EA190
// Name: public: CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>::~CUtlVector<struct CDmeCombinationOperator::CombinationInfo_t,class CUtlMemory<struct CDmeCombinationOperator::CombinationInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::~CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>(
        CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeCombinationOperator::CombinationInfo_t *m_pMemory; // eax

  CUtlVector<CDmeCombinationOperator::CombinationInfo_t,CUtlMemory<CDmeCombinationOperator::CombinationInfo_t,int>>::RemoveAll(this);
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
// Address: 0x104EDAA0
// Name: public: int CUtlVector<struct ExportedControl_t,class CUtlMemory<struct ExportedControl_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int>>::InsertBefore(
        CUtlVector<ExportedControl_t,CUtlMemory<ExportedControl_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ExportedControl_t *m_pMemory; // ecx
  int v6; // eax
  ExportedControl_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->m_Name);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x104F5A90
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct ActiveLayer_t<float> __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<float> *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<void *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<void *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F5BD0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class Vector2D>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: m_pMemory,
                                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Vector2D>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F5C80
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class Vector4D>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Vector4D>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *m_pMemory; // edx
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
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: m_pMemory,
                                                                                      a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<Quaternion>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F5E00
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class QAngle>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: m_pMemory,
                                                                                  a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<QAngle>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F5EB0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct LayerEvent_t<class VMatrix>,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: m_pMemory,
                                                                                   a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1051FE10
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int,class DmeTime_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num,
        const DmeTime_t *pToInsert)
{
  int v4; // esi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  DmeTime_t *v13; // eax
  int v14; // eax
  int v15; // edx
  DmeTime_t *v16; // ecx

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v11);
  if ( pToInsert != nullptr )
  {
    v14 = 0;
    if ( num > 0 )
    {
      v15 = elem;
      do
      {
        v16 = &this->m_Memory.m_pMemory[v15];
        if ( v16 != nullptr )
        {
          v16->m_tms = (int)pToInsert[v14];
          v10 = elem;
        }
        ++v14;
        ++v15;
      }
      while ( v14 < num );
    }
  }
  else if ( num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        v13->m_tms = 0x80000000;
      ++v12;
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10598A40
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmeVertexDataBase::GetPositionData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CDmeVertexDataBase::GetPositionData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[0];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x10598A90
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmeVertexDataBase::GetNormalData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CDmeVertexDataBase::GetNormalData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[1];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x10598AE0
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmeVertexDataBase::GetTangentData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *__thiscall CDmeVertexDataBase::GetTangentData(
        CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector4D> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[2];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyVector4D;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector4D,CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x10598B30
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmeVertexDataBase::GetBalanceData(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmeVertexDataBase::GetBalanceData(CDmeVertexDataBase *this)
{
  int v1; // eax
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<float> vertexData; // [esp+0h] [ebp-8h] BYREF

  v1 = this->m_pStandardFieldIndex[7];
  if ( v1 < 0 || v1 >= this->m_FieldInfo.m_Size )
    return &s_EmptyFloat;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v1].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return vertexData.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x10598B80
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmeVertexDataBase::GetVertexIndexData(enum CDmeVertexDataBase::StandardFields_t)const
// Source: json
//------------------------------------------------------------------------------
CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmeVertexDataBase::GetVertexIndexData(
        CDmeVertexDataBase *this,
        CDmeVertexDataBase::StandardFields_t fieldId)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[fieldId];
  if ( v2 < 0 || v2 >= this->m_FieldInfo.m_Size )
    return (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&s_EmptyInt;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x105990B0
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmeVertexDataBase::FindVertexIndicesFromDataIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<int,CUtlMemory<int,int> > *__thiscall CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nDataIndex)
{
  CDmeVertexDataBase::FieldInfo_t *v4; // esi
  bool v5; // zf
  const CDmAttribute *m_pIndexData; // edi
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_InverseMap; // ebx
  int v8; // edi
  int v9; // edx
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *v11; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v14; // eax
  int *v15; // edi
  CDmrArrayConst<int> array; // [esp+0h] [ebp-14h] BYREF
  CDmeVertexDataBase::FieldInfo_t *info; // [esp+8h] [ebp-Ch]
  CDmrGenericArray vertexArray; // [esp+Ch] [ebp-8h] BYREF
  int nCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  if ( nFieldIndex < 0 )
    return &s_EmptyInt;
  v4 = &this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex];
  v5 = !v4->m_bInverseMapDirty;
  info = v4;
  if ( !v5 )
  {
    m_pIndexData = v4->m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: &array,
      pAttribute: m_pIndexData);
    CDmrGenericArray::CDmrGenericArray(this: &vertexArray, pAttribute: v4->m_pVertexData);
    p_m_InverseMap = &v4->m_InverseMap;
    v8 = CDmrGenericArrayConst::Count(this: &vertexArray);
    nCount = array.m_pStorage->m_Size;
    CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: &v4->m_InverseMap);
    CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: &v4->m_InverseMap);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
      this: &v4->m_InverseMap,
      elem: v4->m_InverseMap.m_Size,
      num: v8);
    v9 = 0;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        m_Size = p_m_InverseMap->m_Memory.m_pMemory[array.m_pStorage->m_Memory.m_pMemory[v9]].m_Size;
        v11 = (CUtlMemory<vgui::TreeNode *,int> *)&p_m_InverseMap->m_Memory.m_pMemory[array.m_pStorage->m_Memory.m_pMemory[v9]];
        m_nAllocationCount = v11->m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v11, num: m_Size - m_nAllocationCount + 1);
          v9 = i;
        }
        ++v11[1].m_pMemory;
        m_pMemory = v11->m_pMemory;
        v14 = (int)v11[1].m_pMemory - m_Size - 1;
        v11[1].m_nAllocationCount = (int)v11->m_pMemory;
        if ( v14 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
          v9 = i;
        }
        v15 = (int *)&v11->m_pMemory[m_Size];
        if ( v15 != nullptr )
          *v15 = v9;
        i = ++v9;
      }
      while ( v9 < nCount );
      v4 = info;
    }
    v4->m_bInverseMapDirty = false;
  }
  return &v4->m_InverseMap.m_Memory.m_pMemory[nDataIndex];
}

//------------------------------------------------------------------------------
// Address: 0x105991D0
// Name: public: int CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  int v6; // eax
  CDmeVertexDataBase::FieldInfo_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<matrix3x4_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_Name);
    v7->m_InverseMap.m_Memory.m_pMemory = nullptr;
    v7->m_InverseMap.m_Memory.m_nAllocationCount = 0;
    v7->m_InverseMap.m_Memory.m_nGrowSize = 0;
    v7->m_InverseMap.m_Size = 0;
    v7->m_InverseMap.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10599250
// Name: public: void CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this)
{
  int v1; // eax
  int v2; // eax
  char *v3; // edi
  void *v4; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *v5; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 48 * v1;
    for ( j = v2; ; v2 = j )
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)(v3 + 24));
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
      j -= 48;
      this = v5;
      if ( --i < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105997A0
// Name: public: CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>::~CUtlVector<struct CDmeVertexDataBase::FieldInfo_t,class CUtlMemory<struct CDmeVertexDataBase::FieldInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::~CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>(
        CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *this)
{
  bool v2; // sf
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // eax

  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::RemoveAll(this);
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
// Address: 0x105CB930
// Name: _Selection3D::OnContextMenu2D_::_5_::_dynamic_atexit_destructor_for__menuSelection__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Selection3D::OnContextMenu2D_::_5_::_dynamic_atexit_destructor_for__menuSelection__()
{
  menuSelection.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menuSelection);
}

//------------------------------------------------------------------------------
// Address: 0x105CB950
// Name: _Selection3D::OnContextMenu2D_::_5_::_dynamic_atexit_destructor_for__menu__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Selection3D::OnContextMenu2D_::_5_::_dynamic_atexit_destructor_for__menu__()
{
  menu_4.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu_4);
}

//------------------------------------------------------------------------------
// Address: 0x105CB970
// Name: _Selection3D::OnContextMenuLogical_::_4_::_dynamic_atexit_destructor_for__menuSelection__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Selection3D::OnContextMenuLogical_::_4_::_dynamic_atexit_destructor_for__menuSelection__()
{
  menuSelection_0.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menuSelection_0);
}

//------------------------------------------------------------------------------
// Address: 0x105CB990
// Name: _Selection3D::OnContextMenuLogical_::_4_::_dynamic_atexit_destructor_for__menu__
// Source: json
//------------------------------------------------------------------------------
void __cdecl Selection3D::OnContextMenuLogical_::_4_::_dynamic_atexit_destructor_for__menu__()
{
  menu_5.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu_5);
}

//------------------------------------------------------------------------------
// Address: 0x10061600
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<class CMapClass __near *,unsigned short,bool (*)(class CMapClass __near * const __near &,class CMapClass __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CMapClass __near *,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CMapClass *,unsigned short> *__thiscall CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl*)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CMapClass *,unsigned short> *)&`CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x1046BFB0
// Name: bool FindReferringElements<class CDmElement>(class CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmElement>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmElement *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmElement **v11; // ecx
  int v12; // eax
  CDmElement **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmElement>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmElement **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmElement **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10476660
// Name: void CopyElements<class CDmElement>(class CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>> const __near &,class CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>> __near &,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CopyElements<CDmElement>(
        const CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *from,
        CUtlMemory<vgui::TreeNode *,int> *to,
        TraversalDepth_t depth)
{
  int m_Size; // ecx
  unsigned int m_NumElements; // eax
  CExpressionCalculator *v5; // edi
  int v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_nAllocationCount; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  int m_pMemory; // esi
  int v14; // eax
  CDmElement **v15; // ecx
  int v16; // eax
  CDmElement **v17; // esi
  unsigned int v18; // ecx
  int j; // edi
  CDmElement *v20; // ecx
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int>::Node_t,int> *v21; // eax
  bool sg_4; // [esp+10h] [ebp-80h]
  CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int>::Node_t search; // [esp+14h] [ebp-7Ch] BYREF
  CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash> visited; // [esp+1Ch] [ebp-74h] BYREF
  CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int> refmap; // [esp+60h] [ebp-30h] BYREF
  CDmElement *pCopy; // [esp+84h] [ebp-Ch]
  int i; // [esp+88h] [ebp-8h]
  int c; // [esp+8Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Size = from->m_Size;
  m_NumElements = 0;
  refmap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const DmElementHandle_t *, const DmElementHandle_t *))CDefOps<DmeTime_t>::LessFunc;
  memset(&refmap.m_Tree.m_Elements, 0, sizeof(refmap.m_Tree.m_Elements));
  refmap.m_Tree.m_Root = -1;
  refmap.m_Tree.m_NumElements = 0;
  refmap.m_Tree.m_FirstFree = -1;
  refmap.m_Tree.m_LastAlloc.index = -1;
  refmap.m_Tree.m_pElements = nullptr;
  c = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v5 = (CExpressionCalculator *)from->m_Memory.m_pMemory[i];
      pCopy = nullptr;
      if ( v5 != nullptr )
      {
        search.key = CCodecBuffer_Block::GetBufferType(this: v5);
        v6 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int>::Node_t,int>,int>>::Find(
               this: &refmap.m_Tree,
               &search);
        if ( v6 == -1 )
        {
          m_nAllocationCount = (const char *)v5->m_varNames.m_Memory.m_nAllocationCount;
          if ( m_nAllocationCount == (const char *)-1 )
            m_nAllocationCount = &szGroupName;
          v10 = ((int (__thiscall *)(IDataModel *, float *, const char *, float *, _DWORD))g_pDataModel->CreateElement_2)(
                  a1: g_pDataModel,
                  a2: v5->m_varValues.m_pElements,
                  a3: m_nAllocationCount,
                  a4: v5->m_stack.m_Memory.m_pMemory,
                  a5: 0);
          v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
          v12 = v11;
          if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
            v12 = nullptr;
          pCopy = v12;
          if ( v12 != nullptr )
            CDmElement::CopyAttributesTo(this: (CDmElement *)v5, pCopy: v12, &refmap, depth);
        }
        else
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: refmap.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          pCopy = v8;
        }
      }
      m_pMemory = (int)to[1].m_pMemory;
      v14 = to->m_nAllocationCount;
      if ( m_pMemory + 1 > v14 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: to, num: m_pMemory - v14 + 1);
      ++to[1].m_pMemory;
      v15 = (CDmElement **)to->m_pMemory;
      v16 = (int)to[1].m_pMemory - m_pMemory - 1;
      to[1].m_nAllocationCount = (int)to->m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &v15[m_pMemory + 1], src: &v15[m_pMemory], count: 4 * v16);
      v17 = (CDmElement **)&to->m_pMemory[m_pMemory];
      if ( v17 != nullptr )
        *v17 = pCopy;
      ++i;
    }
    while ( i < c );
    m_NumElements = refmap.m_Tree.m_NumElements;
  }
  visited.m_aDataPool.m_LastAlloc.m_nIndex = -1;
  v18 = 1;
  memset(&visited.m_aBuckets, 0, 56);
  visited.m_aDataPool.m_pElements = nullptr;
  if ( m_NumElements > 1 )
  {
    do
      v18 *= 2;
    while ( v18 < m_NumElements );
  }
  CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::Init(this: &visited, nBucketCount: v18);
  for ( j = 0; j < c; ++j )
  {
    v20 = (CDmElement *)to->m_pMemory[j];
    if ( v20 != nullptr )
      CDmElement::FixupReferences(this: v20, &visited, &refmap, depth);
  }
  CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::~CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>(this: &visited);
  CUtlRBTree<CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,enum DmElementHandle_t,int>::Node_t,int>,int>>::RemoveAll(this: &refmap.m_Tree);
  v21 = refmap.m_Tree.m_Elements.m_pMemory;
  refmap.m_Tree.m_FirstFree = -1;
  if ( refmap.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( refmap.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: refmap.m_Tree.m_Elements.m_pMemory);
      v21 = nullptr;
      refmap.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    refmap.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  refmap.m_Tree.m_LastAlloc.index = -1;
  if ( refmap.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( v21 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
      refmap.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    refmap.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x105CB9B0
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x105CB9C0
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x105CB9D0
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x105CB9E0
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
// Address: 0x105CBA10
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x105CBA20
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x105CBA30
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}
