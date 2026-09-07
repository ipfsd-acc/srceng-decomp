// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmerighandle.cpp
// Functions: 8
// ============================================================

#include "movieobjects\dmerighandle.h"

//------------------------------------------------------------------------------
// Address: 0x00565140
// Name: public: virtual bool CDmeRigHandle::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigHandle::IsA(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565170
// Name: public: virtual int CDmeRigHandle::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::GetInheritanceDepth(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005651D0
// Name: protected: virtual int CDmeRigHandle::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::AllocatedSize(CDmeRigHandle *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x005AEBC0
// Name: _dynamic_initializer_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigHandle::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigHandle pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0A90
// Name: _dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigHandle::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AEBF0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigHandle_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEC00
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigHandle_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigHandle_Helper,
           classname: "DmeRigHandle",
           pFactory: &g_CDmeRigHandle_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0AA0
// Name: _dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigHandle_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005C26C0
// Name: public: virtual bool CDmeRigHandle::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigHandle::IsA(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C26F0
// Name: public: virtual int CDmeRigHandle::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::GetInheritanceDepth(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C2760
// Name: protected: virtual int CDmeRigHandle::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::AllocatedSize(CDmeRigHandle *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x00680580
// Name: _dynamic_initializer_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigHandle::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigHandle pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00683040
// Name: _dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigHandle::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006805B0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigHandle_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006805C0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigHandle_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigHandle_Helper,
           classname: "DmeRigHandle",
           pFactory: &g_CDmeRigHandle_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00683050
// Name: _dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeRigHandle_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0046F0F0
// Name: protected: virtual int CDmeRigHandle::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::AllocatedSize(CDmeRigHandle *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x005297F0
// Name: public: virtual bool CDmeRigHandle::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigHandle::IsA(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529820
// Name: public: virtual int CDmeRigHandle::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::GetInheritanceDepth(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056D160
// Name: _dynamic_initializer_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigHandle::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigHandle pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F220
// Name: _dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigHandle::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056D190
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigHandle_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D1A0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigHandle_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigHandle_Helper,
           classname: "DmeRigHandle",
           pFactory: &g_CDmeRigHandle_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F230
// Name: _dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigHandle_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x005318F0
// Name: public: virtual bool CDmeRigHandle::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigHandle::IsA(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00531920
// Name: public: virtual int CDmeRigHandle::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::GetInheritanceDepth(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00531970
// Name: protected: virtual int CDmeRigHandle::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::AllocatedSize(CDmeRigHandle *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x0057D280
// Name: _dynamic_initializer_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigHandle::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigHandle pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F350
// Name: _dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigHandle::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D2B0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigHandle_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D2C0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigHandle_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigHandle_Helper,
           classname: "DmeRigHandle",
           pFactory: &g_CDmeRigHandle_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F360
// Name: _dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigHandle_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005EFEF0
// Name: public: virtual bool CDmeRigHandle::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigHandle::IsA(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005EFF20
// Name: public: virtual int CDmeRigHandle::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::GetInheritanceDepth(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006B23E0
// Name: _dynamic_initializer_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigHandle::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigHandle pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5B40
// Name: _dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigHandle::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B2410
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigHandle_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2420
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigHandle_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigHandle_Helper,
           classname: "DmeRigHandle",
           pFactory: &g_CDmeRigHandle_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5B50
// Name: _dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeRigHandle_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00473B10
// Name: protected: virtual int CDmeRigHandle::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::AllocatedSize(CDmeRigHandle *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x00532A90
// Name: public: virtual bool CDmeRigHandle::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigHandle::IsA(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532AC0
// Name: public: virtual int CDmeRigHandle::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::GetInheritanceDepth(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0057F260
// Name: _dynamic_initializer_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigHandle::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigHandle pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581330
// Name: _dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigHandle::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F290
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigHandle_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F2A0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigHandle_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigHandle_Helper,
           classname: "DmeRigHandle",
           pFactory: &g_CDmeRigHandle_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00581340
// Name: _dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigHandle_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00538150
// Name: public: virtual bool CDmeRigHandle::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigHandle::IsA(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00538180
// Name: public: virtual int CDmeRigHandle::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::GetInheritanceDepth(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005381E0
// Name: protected: virtual int CDmeRigHandle::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::AllocatedSize(CDmeRigHandle *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x0057CAA0
// Name: _dynamic_initializer_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigHandle::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigHandle pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA20
// Name: _dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigHandle::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CAD0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigHandle_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CAE0
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigHandle_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigHandle_Helper,
           classname: "DmeRigHandle",
           pFactory: &g_CDmeRigHandle_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA30
// Name: _dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigHandle_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0063B230
// Name: public: virtual bool CDmeRigHandle::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigHandle::IsA(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063B260
// Name: public: virtual int CDmeRigHandle::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::GetInheritanceDepth(CDmeRigHandle *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigHandle::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00656F80
// Name: protected: virtual int CDmeRigHandle::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigHandle::AllocatedSize(CDmeSceneObject *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x006BAA10
// Name: _dynamic_initializer_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigHandle::s_Allocator,
    blockSize: 0x88u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigHandle pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD840
// Name: _dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigHandle::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigHandle::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BAA40
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigHandle_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAA50
// Name: _dynamic_initializer_for__g_CDmeRigHandle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigHandle_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigHandle_Helper,
           classname: "DmeRigHandle",
           pFactory: &g_CDmeRigHandle_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD850
// Name: _dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigHandle_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeRigHandle_Factory.m_CallBackList);
}

} // namespace vmap
