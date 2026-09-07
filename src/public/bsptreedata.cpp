// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/bsptreedata.cpp
// Functions: 20
// ============================================================

#include "public\bsptreedata.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10001050
// Name: void DestroyBSPTreeData(class IBSPTreeData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyBSPTreeData(IBSPTreeData *pTreeData)
{
  if ( pTreeData != nullptr )
    free(pMem: pTreeData);
}

//------------------------------------------------------------------------------
// Address: 0x10001070
// Name: public: virtual bool CBSPTreeData::EnumerateLeavesAtPoint(class Vector const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBSPTreeData::EnumerateLeavesAtPoint(
        CBSPTreeData *this,
        const Vector *pt,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  return this->m_pBSPTree->EnumerateLeavesAtPoint(this: this->m_pBSPTree, a2: pt, a3: pEnum, a4: context);
}

//------------------------------------------------------------------------------
// Address: 0x10001080
// Name: public: virtual bool CBSPTreeData::EnumerateLeavesInBox(class Vector const __near &,class Vector const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBSPTreeData::EnumerateLeavesInBox(
        CBSPTreeData *this,
        const Vector *mins,
        const Vector *maxs,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  return this->m_pBSPTree->EnumerateLeavesInBox(this: this->m_pBSPTree, a2: mins, a3: maxs, a4: pEnum, a5: context);
}

//------------------------------------------------------------------------------
// Address: 0x10001090
// Name: public: virtual bool CBSPTreeData::EnumerateLeavesInSphere(class Vector const __near &,float,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBSPTreeData::EnumerateLeavesInSphere(
        CBSPTreeData *this,
        const Vector *center,
        float radius,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  return ((bool (__stdcall *)(const Vector *, _DWORD, ISpatialLeafEnumerator *, int))this->m_pBSPTree->EnumerateLeavesInSphere)(
           a1: center,
           a2: LODWORD(radius),
           a3: pEnum,
           a4: context);
}

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: public: virtual bool CBSPTreeData::EnumerateLeavesAlongRay(struct Ray_t const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBSPTreeData::EnumerateLeavesAlongRay(
        CBSPTreeData *this,
        const Ray_t *ray,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  return this->m_pBSPTree->EnumerateLeavesAlongRay(this: this->m_pBSPTree, a2: ray, a3: pEnum, a4: context);
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short>::Grow(
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
// Address: 0x10001230
// Name: public: virtual bool CBSPTreeData::IsElementInTree(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBSPTreeData::IsElementInTree(CBSPTreeData *this, unsigned __int16 handle)
{
  return this->m_Handles.m_Memory.m_pMemory[handle].m_Element.m_LeafList != 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100018B0
// Name: public: virtual bool CBSPTreeData::EnumerateElementsInLeaf(int,class IBSPTreeDataEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBSPTreeData::EnumerateElementsInLeaf(
        CBSPTreeData *this,
        int leaf,
        IBSPTreeDataEnumerator *pEnum,
        int context)
{
  unsigned __int16 m_FirstElement; // ax
  int v6; // esi

  m_FirstElement = this->m_Leaf.m_Memory.m_pMemory[leaf].m_FirstElement;
  if ( m_FirstElement == 0xFFFF )
    return 1;
  while ( 1 )
  {
    v6 = m_FirstElement;
    if ( pEnum->EnumerateElement(
           this: pEnum,
           a2: this->m_Handles.m_Memory.m_pMemory[this->m_LeafElements.m_Memory.m_pMemory[v6].m_Element].m_Element.m_UserId,
           a3: context) == 0 )
      break;
    m_FirstElement = this->m_LeafElements.m_Memory.m_pMemory[v6].m_Next;
    if ( m_FirstElement == 0xFFFF )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A40
// Name: public: virtual void CBSPTreeData::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPTreeData::Shutdown(CBSPTreeData *this)
{
  UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short> *m_pMemory; // ecx
  CBSPTreeData::Leaf_t *v3; // ecx

  CUtlLinkedList<CBSPTreeData::HandleInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Handles);
  if ( this->m_Handles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Handles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Handles.m_Memory.m_pMemory);
      this->m_Handles.m_Memory.m_pMemory = nullptr;
    }
    this->m_Handles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Handles.m_FirstFree = -1;
  this->m_Handles.m_pElements = this->m_Handles.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Handles.m_NumAlloced = -65536;
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LeafElements);
  if ( this->m_LeafElements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LeafElements.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LeafElements.m_Memory.m_pMemory);
      this->m_LeafElements.m_Memory.m_pMemory = nullptr;
    }
    this->m_LeafElements.m_Memory.m_nAllocationCount = 0;
  }
  this->m_LeafElements.m_FirstFree = -1;
  this->m_LeafElements.m_pElements = this->m_LeafElements.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_LeafElements.m_NumAlloced = -65536;
  CUtlLinkedList<CBSPTreeData::HandleInLeaf_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_HandleLeafList);
  if ( this->m_HandleLeafList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HandleLeafList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HandleLeafList.m_Memory.m_pMemory);
      this->m_HandleLeafList.m_Memory.m_pMemory = nullptr;
    }
    this->m_HandleLeafList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_HandleLeafList.m_FirstFree = -1;
  m_pMemory = this->m_HandleLeafList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_HandleLeafList.m_NumAlloced = -65536;
  this->m_HandleLeafList.m_pElements = m_pMemory;
  this->m_Leaf.m_Size = 0;
  if ( this->m_Leaf.m_Memory.m_nGrowSize < 0 )
  {
    this->m_Leaf.m_pElements = this->m_Leaf.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Leaf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Leaf.m_Memory.m_pMemory);
      this->m_Leaf.m_Memory.m_pMemory = nullptr;
    }
    v3 = this->m_Leaf.m_Memory.m_pMemory;
    this->m_Leaf.m_Memory.m_nAllocationCount = 0;
    this->m_Leaf.m_pElements = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C60
// Name: public: CBSPTreeData::CBSPTreeData(void)
// Source: json
//------------------------------------------------------------------------------
CBSPTreeData *__thiscall CBSPTreeData::CBSPTreeData(CBSPTreeData *this)
{
  CBSPTreeData *result; // eax
  UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short> *m_pMemory; // ecx

  result = this;
  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&ISpatialLeafEnumerator::`vftable';
  this->IBSPTreeData::__vftable = (CBSPTreeData_vtbl *)&CBSPTreeData::`vftable'{for `IBSPTreeData'};
  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&CBSPTreeData::`vftable'{for `ISpatialLeafEnumerator'};
  this->m_Leaf.m_Memory.m_pMemory = nullptr;
  this->m_Leaf.m_Memory.m_nAllocationCount = 0;
  this->m_Leaf.m_Memory.m_nGrowSize = 0;
  this->m_Leaf.m_Size = 0;
  this->m_Leaf.m_pElements = nullptr;
  this->m_Handles.m_Memory.m_pMemory = nullptr;
  this->m_Handles.m_Memory.m_nAllocationCount = 0;
  this->m_Handles.m_Memory.m_nGrowSize = 0;
  this->m_Handles.m_LastAlloc.index = -1;
  this->m_Handles.m_Head = -1;
  this->m_Handles.m_Tail = -1;
  this->m_Handles.m_FirstFree = -1;
  this->m_Handles.m_ElementCount = 0;
  this->m_Handles.m_NumAlloced = 0;
  this->m_Handles.m_pElements = this->m_Handles.m_Memory.m_pMemory;
  this->m_LeafElements.m_Memory.m_pMemory = nullptr;
  this->m_LeafElements.m_Memory.m_nAllocationCount = 0;
  this->m_LeafElements.m_Memory.m_nGrowSize = 0;
  this->m_LeafElements.m_LastAlloc.index = -1;
  this->m_LeafElements.m_Head = -1;
  this->m_LeafElements.m_Tail = -1;
  this->m_LeafElements.m_FirstFree = -1;
  this->m_LeafElements.m_ElementCount = 0;
  this->m_LeafElements.m_NumAlloced = 0;
  this->m_LeafElements.m_pElements = this->m_LeafElements.m_Memory.m_pMemory;
  this->m_HandleLeafList.m_Memory.m_pMemory = nullptr;
  this->m_HandleLeafList.m_Memory.m_nAllocationCount = 0;
  this->m_HandleLeafList.m_Memory.m_nGrowSize = 0;
  this->m_HandleLeafList.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_HandleLeafList.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_HandleLeafList.m_Memory.m_pMemory;
  *(_DWORD *)&result->m_HandleLeafList.m_Head = -1;
  result->m_HandleLeafList.m_NumAlloced = 0;
  result->m_HandleLeafList.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001D10
// Name: public: virtual CBSPTreeData::~CBSPTreeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPTreeData::~CBSPTreeData(CBSPTreeData *this)
{
  this->IBSPTreeData::__vftable = (CBSPTreeData_vtbl *)&CBSPTreeData::`vftable'{for `IBSPTreeData'};
  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&CBSPTreeData::`vftable'{for `ISpatialLeafEnumerator'};
  CUtlLinkedList<CBSPTreeData::HandleInLeaf_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_HandleLeafList);
  if ( this->m_HandleLeafList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HandleLeafList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HandleLeafList.m_Memory.m_pMemory);
      this->m_HandleLeafList.m_Memory.m_pMemory = nullptr;
    }
    this->m_HandleLeafList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LeafElements);
  if ( this->m_LeafElements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LeafElements.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LeafElements.m_Memory.m_pMemory);
      this->m_LeafElements.m_Memory.m_pMemory = nullptr;
    }
    this->m_LeafElements.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CBSPTreeData::HandleInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Handles);
  if ( this->m_Handles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Handles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Handles.m_Memory.m_pMemory);
      this->m_Handles.m_Memory.m_pMemory = nullptr;
    }
    this->m_Handles.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Leaf);
}

//------------------------------------------------------------------------------
// Address: 0x10001DD0
// Name: public: virtual void CBSPTreeData::Init(class ISpatialQuery __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPTreeData::Init(CBSPTreeData *this, ISpatialQuery *pBSPTree)
{
  UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short> *m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx
  UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short> *v5; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v6; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v7; // eax
  UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short> *v8; // eax
  UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short> *v9; // eax
  int v10; // ebx
  CBSPTreeData::Leaf_t *v11; // eax
  IMemAlloc_vtbl *v12; // edx
  CBSPTreeData::Leaf_t *v13; // eax
  int v14; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBSPTreeData::Leaf_t *v17; // ecx
  int v18; // eax
  CBSPTreeData::Leaf_t *v19; // eax

  this->m_pBSPTree = pBSPTree;
  if ( this->m_Handles.m_Memory.m_nAllocationCount < 1024 && this->m_Handles.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Handles.m_Memory.m_pMemory;
    this->m_Handles.m_Memory.m_nAllocationCount = 1024;
    v4 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v5 = (UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short> *)((int (__stdcall *)(UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short> *, int))v4->Realloc_2)(
                                                                               a1: m_pMemory,
                                                                               a2: 12288);
    else
      v5 = (UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short> *)((int (__stdcall *)(int))v4->Alloc_2)(a1: 12288);
    this->m_Handles.m_Memory.m_pMemory = v5;
  }
  this->m_Handles.m_pElements = this->m_Handles.m_Memory.m_pMemory;
  if ( this->m_LeafElements.m_Memory.m_nAllocationCount < 1024 && this->m_LeafElements.m_Memory.m_nGrowSize >= 0 )
  {
    v6 = this->m_LeafElements.m_Memory.m_pMemory;
    this->m_LeafElements.m_Memory.m_nAllocationCount = 1024;
    if ( v6 != nullptr )
      v7 = (UtlLinkedListElem_t<unsigned short,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                   this: _g_pMemAlloc,
                                                                   a2: v6,
                                                                   a3: 6144);
    else
      v7 = (UtlLinkedListElem_t<unsigned short,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 6144);
    this->m_LeafElements.m_Memory.m_pMemory = v7;
  }
  this->m_LeafElements.m_pElements = this->m_LeafElements.m_Memory.m_pMemory;
  if ( this->m_HandleLeafList.m_Memory.m_nAllocationCount < 1024 && this->m_HandleLeafList.m_Memory.m_nGrowSize >= 0 )
  {
    v8 = this->m_HandleLeafList.m_Memory.m_pMemory;
    this->m_HandleLeafList.m_Memory.m_nAllocationCount = 1024;
    if ( v8 != nullptr )
      v9 = (UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: v8,
                                                                                 a3: 12288);
    else
      v9 = (UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: 12288);
    this->m_HandleLeafList.m_Memory.m_pMemory = v9;
  }
  this->m_HandleLeafList.m_pElements = this->m_HandleLeafList.m_Memory.m_pMemory;
  v10 = this->m_pBSPTree->LeafCount(this: this->m_pBSPTree);
  if ( this->m_Leaf.m_Memory.m_nAllocationCount < v10 && this->m_Leaf.m_Memory.m_nGrowSize >= 0 )
  {
    v11 = this->m_Leaf.m_Memory.m_pMemory;
    this->m_Leaf.m_Memory.m_nAllocationCount = v10;
    v12 = _g_pMemAlloc->__vftable;
    if ( v11 != nullptr )
      v13 = (CBSPTreeData::Leaf_t *)((int (__stdcall *)(CBSPTreeData::Leaf_t *, int))v12->Realloc_2)(
                                      a1: v11,
                                      a2: 2 * v10);
    else
      v13 = (CBSPTreeData::Leaf_t *)((int (__stdcall *)(int))v12->Alloc_2)(a1: 2 * v10);
    this->m_Leaf.m_Memory.m_pMemory = v13;
  }
  v14 = v10 - 1;
  for ( this->m_Leaf.m_pElements = this->m_Leaf.m_Memory.m_pMemory; v14 >= 0; --v14 )
  {
    m_Size = this->m_Leaf.m_Size;
    m_nAllocationCount = this->m_Leaf.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CIncrementalHeader::CLMSize,int>::Grow(
        this: &this->m_Leaf.m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Leaf.m_Size;
    v17 = this->m_Leaf.m_Memory.m_pMemory;
    v18 = this->m_Leaf.m_Size - m_Size - 1;
    this->m_Leaf.m_pElements = v17;
    if ( v18 > 0 )
      _V_memmove(dest: &v17[m_Size + 1], src: &v17[m_Size], count: 2 * v18);
    v19 = &this->m_Leaf.m_Memory.m_pMemory[m_Size];
    if ( v19 != nullptr )
      v19->m_FirstElement = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F50
// Name: public: virtual unsigned short CBSPTreeData::Insert(int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CBSPTreeData::Insert(
        CBSPTreeData *this,
        int userId,
        const Vector *mins,
        const Vector *maxs)
{
  CUtlLinkedList<CBSPTreeData::HandleInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short>,unsigned short> > *p_m_Handles; // esi
  unsigned __int16 v5; // di
  int v6; // eax

  p_m_Handles = &this->m_Handles;
  v5 = CUtlLinkedList<CBSPTreeData::HandleInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_Handles,
         multilist: false);
  if ( v5 == 0xFFFF )
    v5 = -1;
  else
    CUtlLinkedList<CBSPTreeData::HandleInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CBSPTreeData::HandleInLeaf_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short> > *)p_m_Handles,
      before: 0xFFFFu,
      elem: v5);
  v6 = v5;
  p_m_Handles->m_Memory.m_pMemory[v6].m_Element.m_UserId = userId;
  p_m_Handles->m_Memory.m_pMemory[v6].m_Element.m_LeafList = -1;
  this->m_pBSPTree->EnumerateLeavesInBox(
    this: this->m_pBSPTree,
    a2: mins,
    a3: maxs,
    a4: &this->ISpatialLeafEnumerator,
    a5: v5);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10001FD0
// Name: private: void CBSPTreeData::AddHandleToLeaf(int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPTreeData::AddHandleToLeaf(CBSPTreeData *this, int leaf, unsigned __int16 handle)
{
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_LeafElements; // ebx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // di
  unsigned __int16 m_FirstElement; // ax
  UtlLinkedListElem_t<unsigned short,unsigned short> *m_pMemory; // eax
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // cx
  int v12; // ebx
  unsigned __int16 m_LeafList; // ax
  int v14; // eax
  unsigned __int16 leafElement; // [esp+Ch] [ebp-4h]
  __int16 handleElement; // [esp+1Ch] [ebp+Ch]

  p_m_LeafElements = &this->m_LeafElements;
  v5 = CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_LeafElements,
         multilist: true);
  if ( v5 == 0xFFFF )
  {
    v6 = -1;
    leafElement = -1;
  }
  else
  {
    leafElement = v5;
    v6 = v5;
  }
  m_FirstElement = this->m_Leaf.m_Memory.m_pMemory[leaf].m_FirstElement;
  if ( m_FirstElement != 0xFFFF )
    CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_LeafElements,
      before: m_FirstElement,
      elem: v6);
  this->m_Leaf.m_Memory.m_pMemory[leaf].m_FirstElement = v6;
  m_pMemory = p_m_LeafElements->m_Memory.m_pMemory;
  m_pMemory[v6].m_Element = handle;
  v10 = CUtlLinkedList<CBSPTreeData::HandleInLeaf_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_HandleLeafList,
          multilist: true);
  v11 = -1;
  if ( v10 == 0xFFFF )
  {
    handleElement = -1;
  }
  else
  {
    handleElement = v10;
    v11 = v10;
  }
  v12 = handle;
  m_LeafList = this->m_Handles.m_Memory.m_pMemory[v12].m_Element.m_LeafList;
  if ( m_LeafList != 0xFFFF )
  {
    CUtlLinkedList<CBSPTreeData::HandleInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_HandleLeafList,
      before: m_LeafList,
      elem: v11);
    v11 = handleElement;
  }
  this->m_Handles.m_Memory.m_pMemory[v12].m_Element.m_LeafList = v11;
  v14 = v11;
  this->m_HandleLeafList.m_Memory.m_pMemory[v14].m_Element.m_Leaf = leaf;
  this->m_HandleLeafList.m_Memory.m_pMemory[v14].m_Element.m_LeafElementIndex = leafElement;
}

//------------------------------------------------------------------------------
// Address: 0x100020C0
// Name: public: virtual bool CBSPTreeData::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBSPTreeData::EnumerateLeaf(CBSPTreeData *this, int leaf, unsigned __int16 context)
{
  CBSPTreeData::AddHandleToLeaf(this: (CBSPTreeData *)((char *)this - 4), leaf, handle: context);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100020E0
// Name: private: void CBSPTreeData::RemoveFromTree(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPTreeData::RemoveFromTree(CBSPTreeData *this, unsigned __int16 handle)
{
  int v2; // edx
  unsigned __int16 v3; // ax
  CUtlLinkedList<CBSPTreeData::HandleInLeaf_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short> > *p_m_HandleLeafList; // esi
  int v5; // ebx
  int m_LeafElementIndex; // edi
  int v7; // edi
  unsigned __int16 v8; // [esp-Ch] [ebp-1Ch]
  int v9; // [esp+4h] [ebp-Ch]
  CBSPTreeData::Leaf_t *v10; // [esp+8h] [ebp-8h]
  CBSPTreeData *v11; // [esp+Ch] [ebp-4h]
  unsigned __int16 i; // [esp+18h] [ebp+8h]

  v2 = 12 * handle;
  v3 = *(unsigned __int16 *)((char *)&this->m_Handles.m_Memory.m_pMemory->m_Element.m_LeafList + v2);
  v11 = this;
  v9 = v2;
  i = v3;
  if ( v3 != 0xFFFF )
  {
    p_m_HandleLeafList = &this->m_HandleLeafList;
    while ( 1 )
    {
      v5 = v3;
      m_LeafElementIndex = p_m_HandleLeafList->m_Memory.m_pMemory[v5].m_Element.m_LeafElementIndex;
      v10 = &this->m_Leaf.m_Memory.m_pMemory[p_m_HandleLeafList->m_Memory.m_pMemory[v5].m_Element.m_Leaf];
      if ( (_WORD)m_LeafElementIndex == v10->m_FirstElement )
        v10->m_FirstElement = this->m_LeafElements.m_Memory.m_pMemory[m_LeafElementIndex].m_Next;
      CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_LeafElements,
        elem: m_LeafElementIndex);
      v11->m_LeafElements.m_Memory.m_pMemory[m_LeafElementIndex].m_Next = v11->m_LeafElements.m_FirstFree;
      v11->m_LeafElements.m_FirstFree = m_LeafElementIndex;
      v7 = i;
      v8 = i;
      i = p_m_HandleLeafList->m_Memory.m_pMemory[v5].m_Next;
      CUtlLinkedList<CBSPTreeData::HandleInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short>,unsigned short>>::Unlink(
        this: p_m_HandleLeafList,
        elem: v8);
      p_m_HandleLeafList->m_Memory.m_pMemory[v7].m_Next = p_m_HandleLeafList->m_FirstFree;
      this = v11;
      p_m_HandleLeafList->m_FirstFree = v7;
      if ( i == 0xFFFF )
        break;
      v3 = i;
    }
    v2 = v9;
  }
  *(unsigned __int16 *)((char *)&this->m_Handles.m_Memory.m_pMemory->m_Element.m_LeafList + v2) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100021D0
// Name: public: virtual void CBSPTreeData::ElementMoved(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPTreeData::ElementMoved(
        CBSPTreeData *this,
        unsigned __int16 handle,
        const Vector *mins,
        const Vector *maxs)
{
  ISpatialLeafEnumerator *v5; // eax

  if ( handle != 0xFFFF )
  {
    CBSPTreeData::RemoveFromTree(this, handle);
    if ( this != nullptr )
      v5 = &this->ISpatialLeafEnumerator;
    else
      v5 = nullptr;
    this->m_pBSPTree->EnumerateLeavesInBox(this: this->m_pBSPTree, a2: mins, a3: maxs, a4: v5, a5: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002220
// Name: class IBSPTreeData __near * CreateBSPTreeData(void)
// Source: json
//------------------------------------------------------------------------------
CBSPTreeData *__cdecl CreateBSPTreeData()
{
  CBSPTreeData *v0; // eax

  v0 = (CBSPTreeData *)MemAlloc_Alloc(nSize: 0x74u);
  if ( v0 != nullptr )
    return CBSPTreeData::CBSPTreeData(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002270
// Name: public: virtual void CBSPTreeData::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPTreeData::Remove(CBSPTreeData *this, unsigned __int16 handle)
{
  CUtlLinkedList<CBSPTreeData::HandleInLeaf_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short> > *p_m_Handles; // esi
  int v3; // ebx

  p_m_Handles = (CUtlLinkedList<CBSPTreeData::HandleInLeaf_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInLeaf_t,unsigned short>,unsigned short> > *)&this->m_Handles;
  if ( handle < this->m_Handles.m_Memory.m_nAllocationCount && handle <= this->m_Handles.m_LastAlloc.index )
  {
    v3 = handle;
    if ( p_m_Handles->m_Memory.m_pMemory[v3].m_Previous != handle
      || p_m_Handles->m_Memory.m_pMemory[v3].m_Next == handle )
    {
      CBSPTreeData::RemoveFromTree(this, handle);
      CUtlLinkedList<CBSPTreeData::HandleInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBSPTreeData::HandleInfo_t,unsigned short>,unsigned short>>::Unlink(
        this: p_m_Handles,
        elem: handle);
      p_m_Handles->m_Memory.m_pMemory[v3].m_Next = p_m_Handles->m_FirstFree;
      p_m_Handles->m_FirstFree = handle;
    }
  }
}
