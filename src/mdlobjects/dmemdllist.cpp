// Original: mdlobjects/dmemdllist.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "mdlobjects\dmemdllist.h"

// Stub: CDmeMdlList::OnConstruction
void OnConstruction() {}

// Stub: CDmeMdlList::OnDestruction
void OnDestruction() {}

// Stub: CDmElementFactory<CDmeMdlList>::Create
void Create() {}

// Stub: CDmElementFactory<CDmeMdlList>::Destroy
void Destroy() {}

// Stub: CDmElementFactory<CDmeMdlList>::SetElementTypeSymbol
void SetElementTypeSymbol() {}

// Stub: CDmElementFactory<CDmeMdlList>::IsAbstract
void IsAbstract() {}

// Stub: CDmElementFactory<CDmeMdlList>::GetElementTypeSymbol
void GetElementTypeSymbol() {}

// Stub: CDmElementFactory<CDmeMdlList>::GetParentElementTypeSymbol
void GetParentElementTypeSymbol() {}

// Stub: dynamic initializer for 'CDmeMdlList::s_Allocator''
void s_Allocator''() {}

// Stub: dynamic initializer for 'g_CDmeMdlList_Factory''
void dynamic initializer for 'g_CDmeMdlList_Factory''() {}

// Stub: dynamic initializer for 'g_CDmeMdlList_Helper''
void dynamic initializer for 'g_CDmeMdlList_Helper''() {}

// Stub: dynamic atexit destructor for 'CDmeMdlList::s_Allocator''
void s_Allocator''() {}

// Stub: dynamic atexit destructor for 'g_CDmeMdlList_Factory''
void dynamic atexit destructor for 'g_CDmeMdlList_Factory''() {}

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050B8B0
// Name: public: virtual bool CDmeMdlList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMdlList::IsA(CDmeMdlList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B8E0
// Name: public: virtual int CDmeMdlList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMdlList::GetInheritanceDepth(CDmeMdlList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006AC9E0
// Name: _dynamic_initializer_for__CDmeMdlList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMdlList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMdlList::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMdlList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3CD0
// Name: _dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMdlList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACA10
// Name: _dynamic_initializer_for__g_CDmeMdlList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMdlList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACA20
// Name: _dynamic_initializer_for__g_CDmeMdlList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMdlList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMdlList_Helper,
           classname: "DmeMdlList",
           pFactory: &g_CDmeMdlList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3CE0
// Name: _dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMdlList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DB360
// Name: public: virtual bool CDmeMdlList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMdlList::IsA(CDmeMdlList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DB390
// Name: public: virtual int CDmeMdlList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMdlList::GetInheritanceDepth(CDmeMdlList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E60B0
// Name: _dynamic_initializer_for__CDmeMdlList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMdlList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMdlList::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMdlList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC090
// Name: _dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMdlList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E60E0
// Name: _dynamic_initializer_for__g_CDmeMdlList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMdlList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E60F0
// Name: _dynamic_initializer_for__g_CDmeMdlList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMdlList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMdlList_Helper,
           classname: "DmeMdlList",
           pFactory: &g_CDmeMdlList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC0A0
// Name: _dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMdlList_Factory.m_CallBackList);
}

} // namespace studiomdl
