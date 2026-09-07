// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmelod.cpp
// Functions: 10
// ============================================================

#include "mdlobjects\dmelod.h"

//------------------------------------------------------------------------------
// Address: 0x0049CB10
// Name: protected: void CDmeLOD::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLOD::OnConstruction(CDmeLOD *this)
{
  this->m_Path.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "path",
                                type: AT_STRING,
                                pMemory: &this->m_Path);
  this->m_Model.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "model",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Model);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Model.m_pAttribute, typeSymbol: CDmeModel::m_classType);
  this->m_Skeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skeleton",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_Skeleton);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Skeleton.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_CombinationOperator.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "combinationOperator",
                                               type: AT_FIRST_VALUE_TYPE,
                                               pMemory: &this->m_CombinationOperator);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_CombinationOperator.m_pAttribute,
    typeSymbol: CDmeCombinationOperator::m_classType);
  this->m_flSwitchMetric.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "switchMetric",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flSwitchMetric);
  this->m_bNoFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "noFlex",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bNoFlex);
  this->m_bIsShadowLOD.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "isShadowLOD",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bIsShadowLOD);
}

//------------------------------------------------------------------------------
// Address: 0x0049CC50
// Name: protected: CDmeLOD::CDmeLOD(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLOD::CDmeLOD(
        CDmeLOD *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLOD_vtbl *)&CDmeLOD::`vftable';
  this->m_Path.m_pAttribute = nullptr;
  this->m_Path.m_Storage.u.m_Id = -1;
  this->m_Model.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Model.m_pAttribute = nullptr;
  this->m_Model.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Skeleton.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Skeleton.m_pAttribute = nullptr;
  this->m_Skeleton.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_CombinationOperator.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_CombinationOperator.m_pAttribute = nullptr;
  this->m_CombinationOperator.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_flSwitchMetric = 0;
  this->m_bNoFlex.m_pAttribute = nullptr;
  this->m_bNoFlex.m_Storage = false;
  this->m_bIsShadowLOD.m_pAttribute = nullptr;
  this->m_bIsShadowLOD.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049CD00
// Name: public: virtual bool CDmeLOD::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLOD::IsA(CDmeLOD *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLOD::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049CD30
// Name: public: virtual int CDmeLOD::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLOD::GetInheritanceDepth(CDmeLOD *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLOD::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049CDB0
// Name: protected: virtual void CDmeLOD::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLOD::PerformConstruction(CDmeLOD *this)
{
  CDmeFXClip::OnDestruction();
  CDmeLOD::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00598880
// Name: _dynamic_initializer_for__CDmeLOD::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLOD::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLOD::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLOD pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DFE0
// Name: _dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLOD::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005988B0
// Name: _dynamic_initializer_for__g_CDmeLOD_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLOD_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLOD_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005988C0
// Name: _dynamic_initializer_for__g_CDmeLOD_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLOD_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLOD_Helper,
           classname: "DmeLOD",
           pFactory: &g_CDmeLOD_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059DFF0
// Name: _dynamic_atexit_destructor_for__g_CDmeLOD_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLOD_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLOD_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E1F00
// Name: protected: void CDmeLOD::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLOD::OnConstruction(CDmeLOD *this)
{
  this->m_Path.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "path",
                                type: AT_STRING,
                                pMemory: &this->m_Path);
  this->m_Model.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "model",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Model);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Model.m_pAttribute, typeSymbol: CDmeModel::m_classType);
  this->m_Skeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skeleton",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_Skeleton);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Skeleton.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_CombinationOperator.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "combinationOperator",
                                               type: AT_FIRST_VALUE_TYPE,
                                               pMemory: &this->m_CombinationOperator);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_CombinationOperator.m_pAttribute,
    typeSymbol: CDmeCombinationOperator::m_classType);
  this->m_flSwitchMetric.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "switchMetric",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flSwitchMetric);
  this->m_bNoFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "noFlex",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bNoFlex);
  this->m_bIsShadowLOD.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "isShadowLOD",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bIsShadowLOD);
}

//------------------------------------------------------------------------------
// Address: 0x004E2040
// Name: protected: CDmeLOD::CDmeLOD(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLOD::CDmeLOD(
        CDmeLOD *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLOD_vtbl *)&CDmeLOD::`vftable';
  this->m_Path.m_pAttribute = nullptr;
  this->m_Path.m_Storage.u.m_Id = -1;
  this->m_Model.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Model.m_pAttribute = nullptr;
  this->m_Model.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Skeleton.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Skeleton.m_pAttribute = nullptr;
  this->m_Skeleton.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_CombinationOperator.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_CombinationOperator.m_pAttribute = nullptr;
  this->m_CombinationOperator.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_flSwitchMetric = 0;
  this->m_bNoFlex.m_pAttribute = nullptr;
  this->m_bNoFlex.m_Storage = false;
  this->m_bIsShadowLOD.m_pAttribute = nullptr;
  this->m_bIsShadowLOD.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E20F0
// Name: public: virtual bool CDmeLOD::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLOD::IsA(CDmeLOD *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLOD::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2120
// Name: public: virtual int CDmeLOD::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLOD::GetInheritanceDepth(CDmeLOD *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLOD::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E21A0
// Name: protected: virtual void CDmeLOD::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLOD::PerformConstruction(CDmeLOD *this)
{
  CDmeFXClip::OnDestruction();
  CDmeLOD::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2E0
// Name: _dynamic_initializer_for__CDmeLOD::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLOD::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLOD::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLOD pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3230
// Name: _dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLOD::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED310
// Name: _dynamic_initializer_for__g_CDmeLOD_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLOD_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLOD_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED320
// Name: _dynamic_initializer_for__g_CDmeLOD_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLOD_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLOD_Helper,
           classname: "DmeLOD",
           pFactory: &g_CDmeLOD_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3240
// Name: _dynamic_atexit_destructor_for__g_CDmeLOD_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLOD_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLOD_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050C6B0
// Name: protected: void CDmeLOD::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLOD::OnConstruction(CDmeLOD *this)
{
  this->m_Path.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "path",
                                type: AT_STRING,
                                pMemory: &this->m_Path);
  this->m_Model.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "model",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Model);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Model.m_pAttribute, typeSymbol: CDmeModel::m_classType);
  this->m_Skeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skeleton",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_Skeleton);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Skeleton.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_CombinationOperator.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "combinationOperator",
                                               type: AT_FIRST_VALUE_TYPE,
                                               pMemory: &this->m_CombinationOperator);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_CombinationOperator.m_pAttribute,
    typeSymbol: CDmeCombinationOperator::m_classType);
  this->m_flSwitchMetric.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "switchMetric",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flSwitchMetric);
  this->m_bNoFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "noFlex",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bNoFlex);
  this->m_bIsShadowLOD.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "isShadowLOD",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bIsShadowLOD);
}

//------------------------------------------------------------------------------
// Address: 0x0050C7F0
// Name: protected: CDmeLOD::CDmeLOD(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLOD::CDmeLOD(
        CDmeLOD *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLOD_vtbl *)&CDmeLOD::`vftable';
  this->m_Path.m_pAttribute = nullptr;
  this->m_Path.m_Storage.u.m_Id = -1;
  this->m_Model.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Model.m_pAttribute = nullptr;
  this->m_Model.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Skeleton.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Skeleton.m_pAttribute = nullptr;
  this->m_Skeleton.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_CombinationOperator.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_CombinationOperator.m_pAttribute = nullptr;
  this->m_CombinationOperator.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_flSwitchMetric = 0;
  this->m_bNoFlex.m_pAttribute = nullptr;
  this->m_bNoFlex.m_Storage = false;
  this->m_bIsShadowLOD.m_pAttribute = nullptr;
  this->m_bIsShadowLOD.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050C8A0
// Name: public: virtual bool CDmeLOD::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLOD::IsA(CDmeLOD *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLOD::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C8D0
// Name: public: virtual int CDmeLOD::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLOD::GetInheritanceDepth(CDmeLOD *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLOD::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C950
// Name: protected: virtual void CDmeLOD::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLOD::PerformConstruction(CDmeLOD *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeLOD::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006ACC80
// Name: _dynamic_initializer_for__CDmeLOD::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLOD::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLOD::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLOD pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3DB0
// Name: _dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLOD::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACCB0
// Name: _dynamic_initializer_for__g_CDmeLOD_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLOD_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLOD_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACCC0
// Name: _dynamic_initializer_for__g_CDmeLOD_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLOD_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLOD_Helper,
           classname: "DmeLOD",
           pFactory: &g_CDmeLOD_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3DC0
// Name: _dynamic_atexit_destructor_for__g_CDmeLOD_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLOD_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeLOD_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DC130
// Name: protected: void CDmeLOD::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLOD::OnConstruction(CDmeLOD *this)
{
  this->m_Path.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "path",
                                type: AT_STRING,
                                pMemory: &this->m_Path);
  this->m_Model.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "model",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Model);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Model.m_pAttribute, typeSymbol: CDmeModel::m_classType);
  this->m_Skeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "skeleton",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_Skeleton);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Skeleton.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_CombinationOperator.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "combinationOperator",
                                               type: AT_FIRST_VALUE_TYPE,
                                               pMemory: &this->m_CombinationOperator);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_CombinationOperator.m_pAttribute,
    typeSymbol: CDmeCombinationOperator::m_classType);
  this->m_flSwitchMetric.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "switchMetric",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flSwitchMetric);
  this->m_bNoFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "noFlex",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bNoFlex);
  this->m_bIsShadowLOD.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "isShadowLOD",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bIsShadowLOD);
}

//------------------------------------------------------------------------------
// Address: 0x004DC270
// Name: protected: CDmeLOD::CDmeLOD(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLOD *__thiscall CDmeLOD::CDmeLOD(
        CDmeLOD *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLOD_vtbl *)&CDmeLOD::`vftable';
  this->m_Path.m_pAttribute = nullptr;
  this->m_Path.m_Storage.u.m_Id = -1;
  this->m_Model.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Model.m_pAttribute = nullptr;
  this->m_Model.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Skeleton.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Skeleton.m_pAttribute = nullptr;
  this->m_Skeleton.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_CombinationOperator.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_CombinationOperator.m_pAttribute = nullptr;
  this->m_CombinationOperator.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_flSwitchMetric = 0;
  this->m_bNoFlex.m_pAttribute = nullptr;
  this->m_bNoFlex.m_Storage = false;
  this->m_bIsShadowLOD.m_pAttribute = nullptr;
  this->m_bIsShadowLOD.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DC320
// Name: public: virtual bool CDmeLOD::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLOD::IsA(CDmeLOD *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLOD::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DC350
// Name: public: virtual int CDmeLOD::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLOD::GetInheritanceDepth(CDmeLOD *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLOD::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DC3D0
// Name: protected: virtual void CDmeLOD::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLOD::PerformConstruction(CDmeLOD *this)
{
  CDmeFXClip::OnDestruction();
  CDmeLOD::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E6350
// Name: _dynamic_initializer_for__CDmeLOD::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLOD::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLOD::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLOD pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC170
// Name: _dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLOD::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLOD::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6380
// Name: _dynamic_initializer_for__g_CDmeLOD_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLOD_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLOD_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6390
// Name: _dynamic_initializer_for__g_CDmeLOD_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLOD_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLOD_Helper,
           classname: "DmeLOD",
           pFactory: &g_CDmeLOD_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC180
// Name: _dynamic_atexit_destructor_for__g_CDmeLOD_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLOD_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLOD_Factory.m_CallBackList);
}

} // namespace studiomdl
