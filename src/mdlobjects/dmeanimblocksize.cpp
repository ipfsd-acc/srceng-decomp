// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeanimblocksize.cpp
// Functions: 13
// ============================================================

#include "mdlobjects\dmeanimblocksize.h"

//------------------------------------------------------------------------------
// Address: 0x004A5DF0
// Name: protected: void CDmeAnimBlockSize::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimBlockSize::OnConstruction(CDmeAnimBlockSize *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int v4; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  this->m_nSize.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "size",
                                 type: AT_INT,
                                 pMemory: &this->m_nSize);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "stall", type: AT_BOOL, pMemory: &this->m_bStall);
  this->m_bStall.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  v4 = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "storageType",
         type: AT_INT,
         pMemory: &this->m_nStorageType);
  this->m_nStorageType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x004A5EF0
// Name: public: virtual bool CDmeAnimBlockSize::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimBlockSize::IsA(CDmeAnimBlockSize *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimBlockSize::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5F20
// Name: public: virtual int CDmeAnimBlockSize::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimBlockSize::GetInheritanceDepth(CDmeAnimBlockSize *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimBlockSize::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5FD0
// Name: protected: virtual void CDmeAnimBlockSize::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimBlockSize::PerformConstruction(CDmeAnimBlockSize *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimBlockSize::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00597C00
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x00599F00
// Name: _dynamic_initializer_for__CDmeAnimBlockSize::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimBlockSize::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimBlockSize::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimBlockSize pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DC00
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x0059E760
// Name: _dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimBlockSize::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00597C30
// Name: _dynamic_initializer_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &DmAttributeList_t::s_Allocator,
    blockSize: 8,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "DmAttributeList_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599F30
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSize_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimBlockSize_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599F40
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSize_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimBlockSize_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimBlockSize_Helper,
           classname: "DmeAnimBlockSize",
           pFactory: &g_CDmeAnimBlockSize_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059DC10
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E770
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimBlockSize_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EA220
// Name: protected: void CDmeAnimBlockSize::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimBlockSize::OnConstruction(CDmeAnimBlockSize *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int v4; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  this->m_nSize.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "size",
                                 type: AT_INT,
                                 pMemory: &this->m_nSize);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "stall", type: AT_BOOL, pMemory: &this->m_bStall);
  this->m_bStall.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  v4 = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "storageType",
         type: AT_INT,
         pMemory: &this->m_nStorageType);
  this->m_nStorageType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x004EA320
// Name: public: virtual bool CDmeAnimBlockSize::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimBlockSize::IsA(CDmeAnimBlockSize *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimBlockSize::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA350
// Name: public: virtual int CDmeAnimBlockSize::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimBlockSize::GetInheritanceDepth(CDmeAnimBlockSize *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimBlockSize::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA410
// Name: protected: virtual void CDmeAnimBlockSize::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimBlockSize::PerformConstruction(CDmeAnimBlockSize *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimBlockSize::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EE7E0
// Name: _dynamic_initializer_for__CDmeAnimBlockSize::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimBlockSize::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimBlockSize::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimBlockSize pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3930
// Name: _dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimBlockSize::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EE810
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSize_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimBlockSize_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE820
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSize_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimBlockSize_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimBlockSize_Helper,
           classname: "DmeAnimBlockSize",
           pFactory: &g_CDmeAnimBlockSize_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3940
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimBlockSize_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00515940
// Name: protected: void CDmeAnimBlockSize::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimBlockSize::OnConstruction(CDmeAnimBlockSize *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int v4; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  this->m_nSize.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "size",
                                 type: AT_INT,
                                 pMemory: &this->m_nSize);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "stall", type: AT_BOOL, pMemory: &this->m_bStall);
  this->m_bStall.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  v4 = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "storageType",
         type: AT_INT,
         pMemory: &this->m_nStorageType);
  this->m_nStorageType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x00515A40
// Name: public: virtual bool CDmeAnimBlockSize::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimBlockSize::IsA(CDmeAnimBlockSize *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimBlockSize::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515A70
// Name: public: virtual int CDmeAnimBlockSize::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimBlockSize::GetInheritanceDepth(CDmeAnimBlockSize *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimBlockSize::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515B20
// Name: protected: virtual void CDmeAnimBlockSize::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimBlockSize::PerformConstruction(CDmeAnimBlockSize *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeAnimBlockSize::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AE300
// Name: _dynamic_initializer_for__CDmeAnimBlockSize::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimBlockSize::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimBlockSize::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimBlockSize pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4530
// Name: _dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimBlockSize::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE330
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSize_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimBlockSize_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE340
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSize_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimBlockSize_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimBlockSize_Helper,
           classname: "DmeAnimBlockSize",
           pFactory: &g_CDmeAnimBlockSize_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4540
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimBlockSize_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E4F60
// Name: protected: void CDmeAnimBlockSize::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimBlockSize::OnConstruction(CDmeAnimBlockSize *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int v4; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  this->m_nSize.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "size",
                                 type: AT_INT,
                                 pMemory: &this->m_nSize);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "stall", type: AT_BOOL, pMemory: &this->m_bStall);
  this->m_bStall.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  v4 = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "storageType",
         type: AT_INT,
         pMemory: &this->m_nStorageType);
  this->m_nStorageType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x004E5060
// Name: public: virtual bool CDmeAnimBlockSize::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimBlockSize::IsA(CDmeAnimBlockSize *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimBlockSize::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5090
// Name: public: virtual int CDmeAnimBlockSize::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimBlockSize::GetInheritanceDepth(CDmeAnimBlockSize *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimBlockSize::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5140
// Name: protected: virtual void CDmeAnimBlockSize::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimBlockSize::PerformConstruction(CDmeAnimBlockSize *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimBlockSize::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E7980
// Name: _dynamic_initializer_for__CDmeAnimBlockSize::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimBlockSize::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimBlockSize::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimBlockSize pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC8D0
// Name: _dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimBlockSize::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimBlockSize::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E79B0
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSize_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimBlockSize_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E79C0
// Name: _dynamic_initializer_for__g_CDmeAnimBlockSize_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimBlockSize_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimBlockSize_Helper,
           classname: "DmeAnimBlockSize",
           pFactory: &g_CDmeAnimBlockSize_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC8E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimBlockSize_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimBlockSize_Factory.m_CallBackList);
}

} // namespace studiomdl
