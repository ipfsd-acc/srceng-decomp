// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeeyelid.cpp
// Functions: 10
// ============================================================

#include "mdlobjects\dmeeyelid.h"

//------------------------------------------------------------------------------
// Address: 0x004ADD20
// Name: protected: void CDmeEyelid::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyelid::OnConstruction(CDmeEyelid *this)
{
  this->m_bUpper.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "upper",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bUpper);
  this->m_sLowererFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "lowererFlex",
                                        type: AT_STRING,
                                        pMemory: &this->m_sLowererFlex);
  this->m_flLowererHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "lowererHeight",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flLowererHeight);
  this->m_sNeutralFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "neutralFlex",
                                        type: AT_STRING,
                                        pMemory: &this->m_sNeutralFlex);
  this->m_flNeutralHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "neutralHeight",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flNeutralHeight);
  this->m_sRaiserFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "raiserFlex",
                                       type: AT_STRING,
                                       pMemory: &this->m_sRaiserFlex);
  this->m_flRaiserHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "raiserHeight",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flRaiserHeight);
  this->m_sRightEyeballName.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "rightEyeballName",
                                             type: AT_STRING,
                                             pMemory: &this->m_sRightEyeballName);
  this->m_sLeftEyeballName.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "leftEyeballName",
                                            type: AT_STRING,
                                            pMemory: &this->m_sLeftEyeballName);
}

//------------------------------------------------------------------------------
// Address: 0x004ADE50
// Name: protected: CDmeEyelid::CDmeEyelid(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEyelid *__thiscall CDmeEyelid::CDmeEyelid(
        CDmeEyelid *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeEyelid_vtbl *)&CDmeEyelid::`vftable';
  this->m_bUpper.m_pAttribute = nullptr;
  this->m_bUpper.m_Storage = false;
  this->m_sLowererFlex.m_pAttribute = nullptr;
  this->m_sLowererFlex.m_Storage.u.m_Id = -1;
  this->m_flLowererHeight = 0;
  this->m_sNeutralFlex.m_pAttribute = nullptr;
  this->m_sNeutralFlex.m_Storage.u.m_Id = -1;
  this->m_flNeutralHeight = 0;
  this->m_sRaiserFlex.m_pAttribute = nullptr;
  this->m_sRaiserFlex.m_Storage.u.m_Id = -1;
  this->m_flRaiserHeight = 0;
  this->m_sRightEyeballName.m_pAttribute = nullptr;
  this->m_sRightEyeballName.m_Storage.u.m_Id = -1;
  this->m_sLeftEyeballName.m_pAttribute = nullptr;
  this->m_sLeftEyeballName.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004ADF00
// Name: public: virtual bool CDmeEyelid::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyelid::IsA(CDmeEyelid *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyelid::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADF30
// Name: public: virtual int CDmeEyelid::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyelid::GetInheritanceDepth(CDmeEyelid *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyelid::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADF70
// Name: protected: virtual void CDmeEyelid::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyelid::PerformConstruction(CDmeEyelid *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEyelid::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059A700
// Name: _dynamic_initializer_for__CDmeEyelid::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyelid::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyelid::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyelid pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA00
// Name: _dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyelid::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A730
// Name: _dynamic_initializer_for__g_CDmeEyelid_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyelid_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A740
// Name: _dynamic_initializer_for__g_CDmeEyelid_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyelid_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyelid_Helper,
           classname: "DmeEyelid",
           pFactory: &g_CDmeEyelid_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA10
// Name: _dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyelid_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E6D10
// Name: protected: void CDmeEyelid::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyelid::OnConstruction(CDmeEyelid *this)
{
  this->m_bUpper.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "upper",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bUpper);
  this->m_sLowererFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "lowererFlex",
                                        type: AT_STRING,
                                        pMemory: &this->m_sLowererFlex);
  this->m_flLowererHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "lowererHeight",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flLowererHeight);
  this->m_sNeutralFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "neutralFlex",
                                        type: AT_STRING,
                                        pMemory: &this->m_sNeutralFlex);
  this->m_flNeutralHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "neutralHeight",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flNeutralHeight);
  this->m_sRaiserFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "raiserFlex",
                                       type: AT_STRING,
                                       pMemory: &this->m_sRaiserFlex);
  this->m_flRaiserHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "raiserHeight",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flRaiserHeight);
  this->m_sRightEyeballName.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "rightEyeballName",
                                             type: AT_STRING,
                                             pMemory: &this->m_sRightEyeballName);
  this->m_sLeftEyeballName.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "leftEyeballName",
                                            type: AT_STRING,
                                            pMemory: &this->m_sLeftEyeballName);
}

//------------------------------------------------------------------------------
// Address: 0x004E6E40
// Name: protected: CDmeEyelid::CDmeEyelid(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEyelid *__thiscall CDmeEyelid::CDmeEyelid(
        CDmeEyelid *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeEyelid_vtbl *)&CDmeEyelid::`vftable';
  this->m_bUpper.m_pAttribute = nullptr;
  this->m_bUpper.m_Storage = false;
  this->m_sLowererFlex.m_pAttribute = nullptr;
  this->m_sLowererFlex.m_Storage.u.m_Id = -1;
  this->m_flLowererHeight = 0;
  this->m_sNeutralFlex.m_pAttribute = nullptr;
  this->m_sNeutralFlex.m_Storage.u.m_Id = -1;
  this->m_flNeutralHeight = 0;
  this->m_sRaiserFlex.m_pAttribute = nullptr;
  this->m_sRaiserFlex.m_Storage.u.m_Id = -1;
  this->m_flRaiserHeight = 0;
  this->m_sRightEyeballName.m_pAttribute = nullptr;
  this->m_sRightEyeballName.m_Storage.u.m_Id = -1;
  this->m_sLeftEyeballName.m_pAttribute = nullptr;
  this->m_sLeftEyeballName.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E6EF0
// Name: public: virtual bool CDmeEyelid::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyelid::IsA(CDmeEyelid *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyelid::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6F20
// Name: public: virtual int CDmeEyelid::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyelid::GetInheritanceDepth(CDmeEyelid *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyelid::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6F60
// Name: protected: virtual void CDmeEyelid::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyelid::PerformConstruction(CDmeEyelid *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEyelid::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EDD00
// Name: _dynamic_initializer_for__CDmeEyelid::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyelid::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyelid::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyelid pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3590
// Name: _dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyelid::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDD30
// Name: _dynamic_initializer_for__g_CDmeEyelid_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyelid_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDD40
// Name: _dynamic_initializer_for__g_CDmeEyelid_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyelid_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyelid_Helper,
           classname: "DmeEyelid",
           pFactory: &g_CDmeEyelid_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F35A0
// Name: _dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyelid_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0051D7F0
// Name: protected: void CDmeEyelid::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyelid::OnConstruction(CDmeEyelid *this)
{
  this->m_bUpper.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "upper",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bUpper);
  this->m_sLowererFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "lowererFlex",
                                        type: AT_STRING,
                                        pMemory: &this->m_sLowererFlex);
  this->m_flLowererHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "lowererHeight",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flLowererHeight);
  this->m_sNeutralFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "neutralFlex",
                                        type: AT_STRING,
                                        pMemory: &this->m_sNeutralFlex);
  this->m_flNeutralHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "neutralHeight",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flNeutralHeight);
  this->m_sRaiserFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "raiserFlex",
                                       type: AT_STRING,
                                       pMemory: &this->m_sRaiserFlex);
  this->m_flRaiserHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "raiserHeight",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flRaiserHeight);
  this->m_sRightEyeballName.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "rightEyeballName",
                                             type: AT_STRING,
                                             pMemory: &this->m_sRightEyeballName);
  this->m_sLeftEyeballName.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "leftEyeballName",
                                            type: AT_STRING,
                                            pMemory: &this->m_sLeftEyeballName);
}

//------------------------------------------------------------------------------
// Address: 0x0051D920
// Name: protected: CDmeEyelid::CDmeEyelid(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEyelid *__thiscall CDmeEyelid::CDmeEyelid(
        CDmeEyelid *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeEyelid_vtbl *)&CDmeEyelid::`vftable';
  this->m_bUpper.m_pAttribute = nullptr;
  this->m_bUpper.m_Storage = false;
  this->m_sLowererFlex.m_pAttribute = nullptr;
  this->m_sLowererFlex.m_Storage.u.m_Id = -1;
  this->m_flLowererHeight = 0;
  this->m_sNeutralFlex.m_pAttribute = nullptr;
  this->m_sNeutralFlex.m_Storage.u.m_Id = -1;
  this->m_flNeutralHeight = 0;
  this->m_sRaiserFlex.m_pAttribute = nullptr;
  this->m_sRaiserFlex.m_Storage.u.m_Id = -1;
  this->m_flRaiserHeight = 0;
  this->m_sRightEyeballName.m_pAttribute = nullptr;
  this->m_sRightEyeballName.m_Storage.u.m_Id = -1;
  this->m_sLeftEyeballName.m_pAttribute = nullptr;
  this->m_sLeftEyeballName.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051D9D0
// Name: public: virtual bool CDmeEyelid::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyelid::IsA(CDmeEyelid *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyelid::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051DA00
// Name: public: virtual int CDmeEyelid::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyelid::GetInheritanceDepth(CDmeEyelid *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyelid::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051DA40
// Name: protected: virtual void CDmeEyelid::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyelid::PerformConstruction(CDmeEyelid *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeEyelid::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AEB00
// Name: _dynamic_initializer_for__CDmeEyelid::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyelid::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyelid::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyelid pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B47D0
// Name: _dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyelid::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AEB30
// Name: _dynamic_initializer_for__g_CDmeEyelid_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyelid_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEB40
// Name: _dynamic_initializer_for__g_CDmeEyelid_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyelid_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyelid_Helper,
           classname: "DmeEyelid",
           pFactory: &g_CDmeEyelid_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B47E0
// Name: _dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEyelid_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DA1A0
// Name: protected: void CDmeEyelid::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyelid::OnConstruction(CDmeEyelid *this)
{
  this->m_bUpper.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "upper",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bUpper);
  this->m_sLowererFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "lowererFlex",
                                        type: AT_STRING,
                                        pMemory: &this->m_sLowererFlex);
  this->m_flLowererHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "lowererHeight",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flLowererHeight);
  this->m_sNeutralFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "neutralFlex",
                                        type: AT_STRING,
                                        pMemory: &this->m_sNeutralFlex);
  this->m_flNeutralHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "neutralHeight",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flNeutralHeight);
  this->m_sRaiserFlex.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "raiserFlex",
                                       type: AT_STRING,
                                       pMemory: &this->m_sRaiserFlex);
  this->m_flRaiserHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "raiserHeight",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flRaiserHeight);
  this->m_sRightEyeballName.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "rightEyeballName",
                                             type: AT_STRING,
                                             pMemory: &this->m_sRightEyeballName);
  this->m_sLeftEyeballName.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "leftEyeballName",
                                            type: AT_STRING,
                                            pMemory: &this->m_sLeftEyeballName);
}

//------------------------------------------------------------------------------
// Address: 0x004DA2D0
// Name: protected: CDmeEyelid::CDmeEyelid(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEyelid *__thiscall CDmeEyelid::CDmeEyelid(
        CDmeEyelid *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeEyelid_vtbl *)&CDmeEyelid::`vftable';
  this->m_bUpper.m_pAttribute = nullptr;
  this->m_bUpper.m_Storage = false;
  this->m_sLowererFlex.m_pAttribute = nullptr;
  this->m_sLowererFlex.m_Storage.u.m_Id = -1;
  this->m_flLowererHeight = 0;
  this->m_sNeutralFlex.m_pAttribute = nullptr;
  this->m_sNeutralFlex.m_Storage.u.m_Id = -1;
  this->m_flNeutralHeight = 0;
  this->m_sRaiserFlex.m_pAttribute = nullptr;
  this->m_sRaiserFlex.m_Storage.u.m_Id = -1;
  this->m_flRaiserHeight = 0;
  this->m_sRightEyeballName.m_pAttribute = nullptr;
  this->m_sRightEyeballName.m_Storage.u.m_Id = -1;
  this->m_sLeftEyeballName.m_pAttribute = nullptr;
  this->m_sLeftEyeballName.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DA380
// Name: public: virtual bool CDmeEyelid::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyelid::IsA(CDmeEyelid *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyelid::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DA3B0
// Name: public: virtual int CDmeEyelid::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyelid::GetInheritanceDepth(CDmeEyelid *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyelid::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DA3F0
// Name: protected: virtual void CDmeEyelid::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyelid::PerformConstruction(CDmeEyelid *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEyelid::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E5F90
// Name: _dynamic_initializer_for__CDmeEyelid::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyelid::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyelid::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyelid pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC030
// Name: _dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyelid::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyelid::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E5FC0
// Name: _dynamic_initializer_for__g_CDmeEyelid_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyelid_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E5FD0
// Name: _dynamic_initializer_for__g_CDmeEyelid_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyelid_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyelid_Helper,
           classname: "DmeEyelid",
           pFactory: &g_CDmeEyelid_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC040
// Name: _dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyelid_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyelid_Factory.m_CallBackList);
}

} // namespace studiomdl
