// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmebodypart.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmebodypart.h"

//------------------------------------------------------------------------------
// Address: 0x0043B880
// Name: protected: virtual int CDmeBodyPart::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyPart::AllocatedSize(CDmeMdlList *this)
{
  return 68;
}

//------------------------------------------------------------------------------
// Address: 0x0049C930
// Name: public: virtual bool CDmeBodyPart::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyPart::IsA(CDmeBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C960
// Name: public: virtual int CDmeBodyPart::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyPart::GetInheritanceDepth(CDmeBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005987C0
// Name: _dynamic_initializer_for__CDmeBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyPart::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyPart::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyPart pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DFA0
// Name: _dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyPart::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005987F0
// Name: _dynamic_initializer_for__g_CDmeBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyPart_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598800
// Name: _dynamic_initializer_for__g_CDmeBodyPart_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyPart_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyPart_Helper,
           classname: "DmeBodyPart",
           pFactory: &g_CDmeBodyPart_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059DFB0
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyPart_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E2290
// Name: public: virtual bool CDmeBodyPart::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyPart::IsA(CDmeBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E22C0
// Name: public: virtual int CDmeBodyPart::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyPart::GetInheritanceDepth(CDmeBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3100
// Name: protected: virtual int CDmeBodyPart::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyPart::AllocatedSize(CDmeMdlList *this)
{
  return 68;
}

//------------------------------------------------------------------------------
// Address: 0x005ED340
// Name: _dynamic_initializer_for__CDmeBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyPart::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyPart::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyPart pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3250
// Name: _dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyPart::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED370
// Name: _dynamic_initializer_for__g_CDmeBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyPart_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED380
// Name: _dynamic_initializer_for__g_CDmeBodyPart_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyPart_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyPart_Helper,
           classname: "DmeBodyPart",
           pFactory: &g_CDmeBodyPart_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3260
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyPart_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00444050
// Name: protected: virtual int CDmeBodyPart::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyPart::AllocatedSize(CDmeEditorTypeDictionary *this)
{
  return 68;
}

//------------------------------------------------------------------------------
// Address: 0x0050C4E0
// Name: public: virtual bool CDmeBodyPart::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyPart::IsA(CDmeBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C510
// Name: public: virtual int CDmeBodyPart::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyPart::GetInheritanceDepth(CDmeBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006ACBC0
// Name: _dynamic_initializer_for__CDmeBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyPart::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyPart::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyPart pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D70
// Name: _dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyPart::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACBF0
// Name: _dynamic_initializer_for__g_CDmeBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyPart_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACC00
// Name: _dynamic_initializer_for__g_CDmeBodyPart_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyPart_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyPart_Helper,
           classname: "DmeBodyPart",
           pFactory: &g_CDmeBodyPart_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D80
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBodyPart_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DBF50
// Name: public: virtual bool CDmeBodyPart::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyPart::IsA(CDmeBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DBF80
// Name: public: virtual int CDmeBodyPart::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyPart::GetInheritanceDepth(CDmeBodyPart *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyPart::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DC120
// Name: protected: virtual int CDmeBodyPart::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyPart::AllocatedSize(CDmeMdlList *this)
{
  return 68;
}

//------------------------------------------------------------------------------
// Address: 0x005E6290
// Name: _dynamic_initializer_for__CDmeBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyPart::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyPart::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyPart pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC130
// Name: _dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyPart::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyPart::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E62C0
// Name: _dynamic_initializer_for__g_CDmeBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyPart_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E62D0
// Name: _dynamic_initializer_for__g_CDmeBodyPart_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyPart_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyPart_Helper,
           classname: "DmeBodyPart",
           pFactory: &g_CDmeBodyPart_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC140
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyPart_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyPart_Factory.m_CallBackList);
}

} // namespace studiomdl
