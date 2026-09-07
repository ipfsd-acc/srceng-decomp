// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeposeparameterlist.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmeposeparameterlist.h"

//------------------------------------------------------------------------------
// Address: 0x004A5CA0
// Name: public: virtual bool CDmePoseParameterList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePoseParameterList::IsA(CDmePoseParameterList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePoseParameterList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5CD0
// Name: public: virtual int CDmePoseParameterList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePoseParameterList::GetInheritanceDepth(CDmePoseParameterList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePoseParameterList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5D10
// Name: protected: virtual void CDmePoseParameterList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameterList::PerformConstruction(CDmePoseParameterList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_ePoseParameterList.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterList",
                                              type: AT_FIRST_ARRAY_TYPE,
                                              pMemory: &this->m_ePoseParameterList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ePoseParameterList.m_pAttribute,
    typeSymbol: CDmePoseParameter::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00599EA0
// Name: _dynamic_initializer_for__CDmePoseParameterList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePoseParameterList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePoseParameterList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePoseParameterList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E740
// Name: _dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePoseParameterList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599ED0
// Name: _dynamic_initializer_for__g_CDmePoseParameterList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePoseParameterList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599EE0
// Name: _dynamic_initializer_for__g_CDmePoseParameterList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePoseParameterList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePoseParameterList_Helper,
           classname: "DmePoseParameterList",
           pFactory: &g_CDmePoseParameterList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E750
// Name: _dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePoseParameterList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EA0D0
// Name: public: virtual bool CDmePoseParameterList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePoseParameterList::IsA(CDmePoseParameterList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePoseParameterList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA100
// Name: public: virtual int CDmePoseParameterList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePoseParameterList::GetInheritanceDepth(CDmePoseParameterList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePoseParameterList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA140
// Name: protected: virtual void CDmePoseParameterList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameterList::PerformConstruction(CDmePoseParameterList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_ePoseParameterList.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterList",
                                              type: AT_FIRST_ARRAY_TYPE,
                                              pMemory: &this->m_ePoseParameterList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ePoseParameterList.m_pAttribute,
    typeSymbol: CDmePoseParameter::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EE780
// Name: _dynamic_initializer_for__CDmePoseParameterList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePoseParameterList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePoseParameterList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePoseParameterList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3910
// Name: _dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePoseParameterList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EE7B0
// Name: _dynamic_initializer_for__g_CDmePoseParameterList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePoseParameterList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE7C0
// Name: _dynamic_initializer_for__g_CDmePoseParameterList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePoseParameterList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePoseParameterList_Helper,
           classname: "DmePoseParameterList",
           pFactory: &g_CDmePoseParameterList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3920
// Name: _dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePoseParameterList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005157F0
// Name: public: virtual bool CDmePoseParameterList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePoseParameterList::IsA(CDmePoseParameterList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePoseParameterList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515820
// Name: public: virtual int CDmePoseParameterList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePoseParameterList::GetInheritanceDepth(CDmePoseParameterList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePoseParameterList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515860
// Name: protected: virtual void CDmePoseParameterList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameterList::PerformConstruction(CDmePoseParameterList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_ePoseParameterList.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterList",
                                              type: AT_FIRST_ARRAY_TYPE,
                                              pMemory: &this->m_ePoseParameterList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ePoseParameterList.m_pAttribute,
    typeSymbol: CDmePoseParameter::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006AE2A0
// Name: _dynamic_initializer_for__CDmePoseParameterList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePoseParameterList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePoseParameterList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePoseParameterList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4510
// Name: _dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePoseParameterList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE2D0
// Name: _dynamic_initializer_for__g_CDmePoseParameterList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePoseParameterList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE2E0
// Name: _dynamic_initializer_for__g_CDmePoseParameterList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePoseParameterList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePoseParameterList_Helper,
           classname: "DmePoseParameterList",
           pFactory: &g_CDmePoseParameterList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4520
// Name: _dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePoseParameterList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E4E10
// Name: public: virtual bool CDmePoseParameterList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePoseParameterList::IsA(CDmePoseParameterList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePoseParameterList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4E40
// Name: public: virtual int CDmePoseParameterList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePoseParameterList::GetInheritanceDepth(CDmePoseParameterList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePoseParameterList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4E80
// Name: protected: virtual void CDmePoseParameterList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameterList::PerformConstruction(CDmePoseParameterList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_ePoseParameterList.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterList",
                                              type: AT_FIRST_ARRAY_TYPE,
                                              pMemory: &this->m_ePoseParameterList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ePoseParameterList.m_pAttribute,
    typeSymbol: CDmePoseParameter::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E7920
// Name: _dynamic_initializer_for__CDmePoseParameterList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePoseParameterList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePoseParameterList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePoseParameterList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC8B0
// Name: _dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePoseParameterList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePoseParameterList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7950
// Name: _dynamic_initializer_for__g_CDmePoseParameterList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePoseParameterList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7960
// Name: _dynamic_initializer_for__g_CDmePoseParameterList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePoseParameterList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePoseParameterList_Helper,
           classname: "DmePoseParameterList",
           pFactory: &g_CDmePoseParameterList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC8C0
// Name: _dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePoseParameterList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePoseParameterList_Factory.m_CallBackList);
}

} // namespace studiomdl
