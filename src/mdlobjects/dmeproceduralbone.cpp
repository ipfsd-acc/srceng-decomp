// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeproceduralbone.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmeproceduralbone.h"

//------------------------------------------------------------------------------
// Address: 0x004A6DA0
// Name: protected: CDmeProceduralBone::CDmeProceduralBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeProceduralBone *__thiscall CDmeProceduralBone::CDmeProceduralBone(
        CDmeProceduralBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeProceduralBone::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A6E20
// Name: public: virtual bool CDmeProceduralBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeProceduralBone::IsA(CDmeProceduralBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6E60
// Name: public: virtual int CDmeProceduralBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeProceduralBone::GetInheritanceDepth(CDmeProceduralBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0059A1A0
// Name: _dynamic_initializer_for__CDmeProceduralBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeProceduralBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeProceduralBone::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeProceduralBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E840
// Name: _dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeProceduralBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A1D0
// Name: _dynamic_initializer_for__g_CDmeProceduralBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeProceduralBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A1E0
// Name: _dynamic_initializer_for__g_CDmeProceduralBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeProceduralBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeProceduralBone_Helper,
           classname: "DmeProceduralBone",
           pFactory: &g_CDmeProceduralBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E850
// Name: _dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeProceduralBone_Factory.m_CallBackList);
}

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005168F0
// Name: protected: CDmeProceduralBone::CDmeProceduralBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeProceduralBone *__thiscall CDmeProceduralBone::CDmeProceduralBone(
        CDmeProceduralBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeProceduralBone::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00516970
// Name: public: virtual bool CDmeProceduralBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeProceduralBone::IsA(CDmeProceduralBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005169B0
// Name: public: virtual int CDmeProceduralBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeProceduralBone::GetInheritanceDepth(CDmeProceduralBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006AE5A0
// Name: _dynamic_initializer_for__CDmeProceduralBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeProceduralBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeProceduralBone::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeProceduralBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4610
// Name: _dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeProceduralBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE5D0
// Name: _dynamic_initializer_for__g_CDmeProceduralBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeProceduralBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE5E0
// Name: _dynamic_initializer_for__g_CDmeProceduralBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeProceduralBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeProceduralBone_Helper,
           classname: "DmeProceduralBone",
           pFactory: &g_CDmeProceduralBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4620
// Name: _dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeProceduralBone_Factory.m_CallBackList);
}

} // namespace sceneviewer
