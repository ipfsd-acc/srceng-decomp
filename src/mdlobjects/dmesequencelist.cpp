// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmesequencelist.cpp
// Functions: 9
// ============================================================

#include "mdlobjects\dmesequencelist.h"

//------------------------------------------------------------------------------
// Address: 0x004A3EC0
// Name: public: void CDmeSequenceList::GetSortedSequenceList(class CUtlVector<class CDmeSequenceBase __near *,class CUtlMemory<class CDmeSequenceBase __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceList::GetSortedSequenceList(
        CDmeSequenceList *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *sortedSequenceList)
{
  int m_Size; // edi
  CDmeSequenceBase **m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  CDmeSequenceBase **v6; // eax
  int v7; // eax
  CDmeSequenceBase *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeSequenceBase **v11; // ecx
  int v12; // eax
  CDmeSequenceBase **v13; // edi
  int nSequenceCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  sortedSequenceList[1].m_pMemory = nullptr;
  m_Size = this->m_Sequences.m_Storage.m_Size;
  nSequenceCount = m_Size;
  if ( sortedSequenceList->m_nAllocationCount < m_Size && sortedSequenceList->m_nGrowSize >= 0 )
  {
    m_pMemory = (CDmeSequenceBase **)sortedSequenceList->m_pMemory;
    sortedSequenceList->m_nAllocationCount = m_Size;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (CDmeSequenceBase **)((int (__stdcall *)(CDmeSequenceBase **, int))v5->Realloc_2)(
                                  a1: m_pMemory,
                                  a2: 4 * m_Size);
    else
      v6 = (CDmeSequenceBase **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * m_Size);
    sortedSequenceList->m_pMemory = (CUtlSymbolTable::StringPool_t **)v6;
  }
  sortedSequenceList[1].m_nAllocationCount = (int)sortedSequenceList->m_pMemory;
  for ( i = 0; i < m_Size; ++i )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
    v8 = (CDmeSequenceBase *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequenceBase::m_classType.u) != 0 )
    {
      v9 = (int)sortedSequenceList[1].m_pMemory;
      m_nAllocationCount = sortedSequenceList->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: sortedSequenceList, num: v9 - m_nAllocationCount + 1);
      ++sortedSequenceList[1].m_pMemory;
      v11 = (CDmeSequenceBase **)sortedSequenceList->m_pMemory;
      v12 = (int)sortedSequenceList[1].m_pMemory - v9 - 1;
      sortedSequenceList[1].m_nAllocationCount = (int)sortedSequenceList->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeSequenceBase **)&sortedSequenceList->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
      m_Size = nSequenceCount;
    }
  }
  qsort(
    base: sortedSequenceList->m_pMemory,
    num: (unsigned int)sortedSequenceList[1].m_pMemory,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))CDmeSequenceBase::QSortFunction);
}

//------------------------------------------------------------------------------
// Address: 0x004A4050
// Name: public: virtual bool CDmeSequenceList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceList::IsA(CDmeSequenceList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4080
// Name: public: virtual int CDmeSequenceList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceList::GetInheritanceDepth(CDmeSequenceList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A40D0
// Name: protected: virtual void CDmeSequenceList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceList::PerformConstruction(CDmeSequenceList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eIkChainList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "ikChainList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eIkChainList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkChainList.m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00599A20
// Name: _dynamic_initializer_for__CDmeSequenceList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceList::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E5C0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599A50
// Name: _dynamic_initializer_for__g_CDmeSequenceList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599A60
// Name: _dynamic_initializer_for__g_CDmeSequenceList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceList_Helper,
           classname: "DmeSequenceList",
           pFactory: &g_CDmeSequenceList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E5D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E5C20
// Name: public: void CDmeSequenceList::GetSortedSequenceList(class CUtlVector<class CDmeSequenceBase __near *,class CUtlMemory<class CDmeSequenceBase __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceList::GetSortedSequenceList(
        CDmeSequenceList *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *sortedSequenceList)
{
  int m_Size; // edi
  CDmeSequenceBase **m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  CDmeSequenceBase **v6; // eax
  int v7; // eax
  CDmeSequenceBase *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeSequenceBase **v11; // ecx
  int v12; // eax
  CDmeSequenceBase **v13; // edi
  int nSequenceCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  sortedSequenceList[1].m_pMemory = nullptr;
  m_Size = this->m_Sequences.m_Storage.m_Size;
  nSequenceCount = m_Size;
  if ( sortedSequenceList->m_nAllocationCount < m_Size && sortedSequenceList->m_nGrowSize >= 0 )
  {
    m_pMemory = (CDmeSequenceBase **)sortedSequenceList->m_pMemory;
    sortedSequenceList->m_nAllocationCount = m_Size;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (CDmeSequenceBase **)((int (__stdcall *)(CDmeSequenceBase **, int))v5->Realloc_2)(
                                  a1: m_pMemory,
                                  a2: 4 * m_Size);
    else
      v6 = (CDmeSequenceBase **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * m_Size);
    sortedSequenceList->m_pMemory = (CUtlSymbolTable::StringPool_t **)v6;
  }
  sortedSequenceList[1].m_nAllocationCount = (int)sortedSequenceList->m_pMemory;
  for ( i = 0; i < m_Size; ++i )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
    v8 = (CDmeSequenceBase *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequenceBase::m_classType.u) != 0 )
    {
      v9 = (int)sortedSequenceList[1].m_pMemory;
      m_nAllocationCount = sortedSequenceList->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: sortedSequenceList, num: v9 - m_nAllocationCount + 1);
      ++sortedSequenceList[1].m_pMemory;
      v11 = (CDmeSequenceBase **)sortedSequenceList->m_pMemory;
      v12 = (int)sortedSequenceList[1].m_pMemory - v9 - 1;
      sortedSequenceList[1].m_nAllocationCount = (int)sortedSequenceList->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeSequenceBase **)&sortedSequenceList->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
      m_Size = nSequenceCount;
    }
  }
  qsort(
    base: sortedSequenceList->m_pMemory,
    num: (unsigned int)sortedSequenceList[1].m_pMemory,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))CDmeSequenceBase::QSortFunction);
}

//------------------------------------------------------------------------------
// Address: 0x004E5DB0
// Name: public: virtual bool CDmeSequenceList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceList::IsA(CDmeSequenceList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5DE0
// Name: public: virtual int CDmeSequenceList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceList::GetInheritanceDepth(CDmeSequenceList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5E30
// Name: protected: virtual void CDmeSequenceList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceList::PerformConstruction(CDmeSequenceList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eIkChainList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "ikChainList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eIkChainList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkChainList.m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA00
// Name: _dynamic_initializer_for__CDmeSequenceList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceList::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3490
// Name: _dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA30
// Name: _dynamic_initializer_for__g_CDmeSequenceList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA40
// Name: _dynamic_initializer_for__g_CDmeSequenceList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceList_Helper,
           classname: "DmeSequenceList",
           pFactory: &g_CDmeSequenceList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F34A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00513A30
// Name: public: void CDmeSequenceList::GetSortedSequenceList(class CUtlVector<class CDmeSequenceBase __near *,class CUtlMemory<class CDmeSequenceBase __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceList::GetSortedSequenceList(
        CDmeSequenceList *this,
        CUtlMemory<vgui::TreeNode *,int> *sortedSequenceList)
{
  int m_Size; // edi
  CDmeSequenceBase **m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  CDmeSequenceBase **v6; // eax
  int v7; // eax
  CDmeSequenceBase *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeSequenceBase **v11; // ecx
  int v12; // eax
  CDmeSequenceBase **v13; // edi
  int nSequenceCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  sortedSequenceList[1].m_pMemory = nullptr;
  m_Size = this->m_Sequences.m_Storage.m_Size;
  nSequenceCount = m_Size;
  if ( sortedSequenceList->m_nAllocationCount < m_Size && sortedSequenceList->m_nGrowSize >= 0 )
  {
    m_pMemory = (CDmeSequenceBase **)sortedSequenceList->m_pMemory;
    sortedSequenceList->m_nAllocationCount = m_Size;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (CDmeSequenceBase **)((int (__stdcall *)(CDmeSequenceBase **, int))v5->Realloc_2)(
                                  a1: m_pMemory,
                                  a2: 4 * m_Size);
    else
      v6 = (CDmeSequenceBase **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * m_Size);
    sortedSequenceList->m_pMemory = (vgui::TreeNode **)v6;
  }
  sortedSequenceList[1].m_nAllocationCount = (int)sortedSequenceList->m_pMemory;
  for ( i = 0; i < m_Size; ++i )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
    v8 = (CDmeSequenceBase *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequenceBase::m_classType.u) != 0 )
    {
      v9 = (int)sortedSequenceList[1].m_pMemory;
      m_nAllocationCount = sortedSequenceList->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: sortedSequenceList, num: v9 - m_nAllocationCount + 1);
      ++sortedSequenceList[1].m_pMemory;
      v11 = (CDmeSequenceBase **)sortedSequenceList->m_pMemory;
      v12 = (int)sortedSequenceList[1].m_pMemory - v9 - 1;
      sortedSequenceList[1].m_nAllocationCount = (int)sortedSequenceList->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeSequenceBase **)&sortedSequenceList->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
      m_Size = nSequenceCount;
    }
  }
  qsort(
    base: sortedSequenceList->m_pMemory,
    num: (unsigned int)sortedSequenceList[1].m_pMemory,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))CDmeSequenceBase::QSortFunction);
}

//------------------------------------------------------------------------------
// Address: 0x00513BC0
// Name: public: virtual bool CDmeSequenceList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceList::IsA(CDmeSequenceList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513BF0
// Name: public: virtual int CDmeSequenceList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceList::GetInheritanceDepth(CDmeSequenceList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513C50
// Name: protected: virtual void CDmeSequenceList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceList::PerformConstruction(CDmeSequenceList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eIkChainList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "ikChainList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eIkChainList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkChainList.m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006ADE20
// Name: _dynamic_initializer_for__CDmeSequenceList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceList::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4390
// Name: _dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ADE50
// Name: _dynamic_initializer_for__g_CDmeSequenceList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADE60
// Name: _dynamic_initializer_for__g_CDmeSequenceList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceList_Helper,
           classname: "DmeSequenceList",
           pFactory: &g_CDmeSequenceList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B43A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E34B0
// Name: public: void CDmeSequenceList::GetSortedSequenceList(class CUtlVector<class CDmeSequenceBase __near *,class CUtlMemory<class CDmeSequenceBase __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceList::GetSortedSequenceList(
        CDmeSequenceList *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *sortedSequenceList)
{
  int m_Size; // edi
  CDmeSequenceBase **m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  CDmeSequenceBase **v6; // eax
  int v7; // eax
  CDmeSequenceBase *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeSequenceBase **v11; // ecx
  int v12; // eax
  CDmeSequenceBase **v13; // edi
  int nSequenceCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  sortedSequenceList[1].m_pMemory = nullptr;
  m_Size = this->m_Sequences.m_Storage.m_Size;
  nSequenceCount = m_Size;
  if ( sortedSequenceList->m_nAllocationCount < m_Size && sortedSequenceList->m_nGrowSize >= 0 )
  {
    m_pMemory = (CDmeSequenceBase **)sortedSequenceList->m_pMemory;
    sortedSequenceList->m_nAllocationCount = m_Size;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (CDmeSequenceBase **)((int (__stdcall *)(CDmeSequenceBase **, int))v5->Realloc_2)(
                                  a1: m_pMemory,
                                  a2: 4 * m_Size);
    else
      v6 = (CDmeSequenceBase **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * m_Size);
    sortedSequenceList->m_pMemory = (CUtlSymbolTable::StringPool_t **)v6;
  }
  sortedSequenceList[1].m_nAllocationCount = (int)sortedSequenceList->m_pMemory;
  for ( i = 0; i < m_Size; ++i )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
    v8 = (CDmeSequenceBase *)v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeSequenceBase::m_classType.u) != 0 )
    {
      v9 = (int)sortedSequenceList[1].m_pMemory;
      m_nAllocationCount = sortedSequenceList->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: sortedSequenceList, num: v9 - m_nAllocationCount + 1);
      ++sortedSequenceList[1].m_pMemory;
      v11 = (CDmeSequenceBase **)sortedSequenceList->m_pMemory;
      v12 = (int)sortedSequenceList[1].m_pMemory - v9 - 1;
      sortedSequenceList[1].m_nAllocationCount = (int)sortedSequenceList->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeSequenceBase **)&sortedSequenceList->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
      m_Size = nSequenceCount;
    }
  }
  qsort(
    base: sortedSequenceList->m_pMemory,
    num: (unsigned int)sortedSequenceList[1].m_pMemory,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))CDmeSequenceBase::QSortFunction);
}

//------------------------------------------------------------------------------
// Address: 0x004E3640
// Name: public: virtual bool CDmeSequenceList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceList::IsA(CDmeSequenceList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3670
// Name: public: virtual int CDmeSequenceList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceList::GetInheritanceDepth(CDmeSequenceList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E36D0
// Name: protected: virtual void CDmeSequenceList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceList::PerformConstruction(CDmeSequenceList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eIkChainList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "ikChainList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eIkChainList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkChainList.m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E7500
// Name: _dynamic_initializer_for__CDmeSequenceList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceList::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC750
// Name: _dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7530
// Name: _dynamic_initializer_for__g_CDmeSequenceList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7540
// Name: _dynamic_initializer_for__g_CDmeSequenceList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceList_Helper,
           classname: "DmeSequenceList",
           pFactory: &g_CDmeSequenceList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC760
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceList_Factory.m_CallBackList);
}

} // namespace studiomdl
