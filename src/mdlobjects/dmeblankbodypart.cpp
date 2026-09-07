// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeblankbodypart.cpp
// Functions: 7
// ============================================================

#include "mdlobjects\dmeblankbodypart.h"

//------------------------------------------------------------------------------
// Address: 0x0049CA80
// Name: public: virtual bool CDmeBlankBodyPart::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBlankBodyPart::IsA(CDmeBlankBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBlankBodyPart::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049CAB0
// Name: public: virtual int CDmeBlankBodyPart::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBlankBodyPart::GetInheritanceDepth(CDmeBlankBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBlankBodyPart::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00598820
// Name: _dynamic_initializer_for__CDmeBlankBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBlankBodyPart::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBlankBodyPart::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBlankBodyPart pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DFC0
// Name: _dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBlankBodyPart::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598850
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBlankBodyPart_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598860
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPart_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBlankBodyPart_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBlankBodyPart_Helper,
           classname: "DmeBlankBodyPart",
           pFactory: &g_CDmeBlankBodyPart_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059DFD0
// Name: _dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBlankBodyPart_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EBFC0
// Name: public: virtual bool CDmeBlankBodyPart::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBlankBodyPart::IsA(CDmeBlankBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBlankBodyPart::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EBFF0
// Name: public: virtual int CDmeBlankBodyPart::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBlankBodyPart::GetInheritanceDepth(CDmeBlankBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBlankBodyPart::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005EEAE0
// Name: _dynamic_initializer_for__CDmeBlankBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBlankBodyPart::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBlankBodyPart::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBlankBodyPart pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A30
// Name: _dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBlankBodyPart::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EEB10
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBlankBodyPart_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEB20
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPart_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBlankBodyPart_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBlankBodyPart_Helper,
           classname: "DmeBlankBodyPart",
           pFactory: &g_CDmeBlankBodyPart_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A40
// Name: _dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBlankBodyPart_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050C630
// Name: public: virtual bool CDmeBlankBodyPart::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBlankBodyPart::IsA(CDmeBlankBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBlankBodyPart::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C660
// Name: public: virtual int CDmeBlankBodyPart::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBlankBodyPart::GetInheritanceDepth(CDmeBlankBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBlankBodyPart::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006ACC20
// Name: _dynamic_initializer_for__CDmeBlankBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBlankBodyPart::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBlankBodyPart::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBlankBodyPart pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D90
// Name: _dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBlankBodyPart::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACC50
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBlankBodyPart_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACC60
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPart_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBlankBodyPart_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBlankBodyPart_Helper,
           classname: "DmeBlankBodyPart",
           pFactory: &g_CDmeBlankBodyPart_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3DA0
// Name: _dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBlankBodyPart_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DC0A0
// Name: public: virtual bool CDmeBlankBodyPart::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBlankBodyPart::IsA(CDmeBlankBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBlankBodyPart::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DC0D0
// Name: public: virtual int CDmeBlankBodyPart::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBlankBodyPart::GetInheritanceDepth(CDmeBlankBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBlankBodyPart::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E62F0
// Name: _dynamic_initializer_for__CDmeBlankBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBlankBodyPart::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBlankBodyPart::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBlankBodyPart pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC150
// Name: _dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBlankBodyPart::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBlankBodyPart::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6320
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBlankBodyPart_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6330
// Name: _dynamic_initializer_for__g_CDmeBlankBodyPart_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBlankBodyPart_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBlankBodyPart_Helper,
           classname: "DmeBlankBodyPart",
           pFactory: &g_CDmeBlankBodyPart_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC160
// Name: _dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBlankBodyPart_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBlankBodyPart_Factory.m_CallBackList);
}

} // namespace studiomdl
