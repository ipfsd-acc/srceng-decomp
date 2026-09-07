// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmedefinebone.cpp
// Functions: 10
// ============================================================

#include "mdlobjects\dmedefinebone.h"

//------------------------------------------------------------------------------
// Address: 0x004A4380
// Name: protected: void CDmeDefineBone::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBone::OnConstruction(CDmeDefineBone *this)
{
  this->m_Parent.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "parent",
                                  type: AT_STRING,
                                  pMemory: &this->m_Parent);
  this->m_Translation.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "translation",
                                       type: AT_VECTOR3,
                                       pMemory: &this->m_Translation);
  this->m_Rotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "rotation",
                                    type: AT_QANGLE,
                                    pMemory: &this->m_Rotation);
  this->m_RealignTranslation.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "realignTranslation",
                                              type: AT_VECTOR3,
                                              pMemory: &this->m_RealignTranslation);
  this->m_RealignRotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "realignRotation",
                                           type: AT_QANGLE,
                                           pMemory: &this->m_RealignRotation);
  this->m_sContentsDescription.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "contentsDescription",
                                                type: AT_STRING,
                                                pMemory: &this->m_sContentsDescription);
}

//------------------------------------------------------------------------------
// Address: 0x004A4470
// Name: protected: CDmeDefineBone::CDmeDefineBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDefineBone *__thiscall CDmeDefineBone::CDmeDefineBone(
        CDmeDefineBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDefineBone_vtbl *)&CDmeDefineBone::`vftable';
  this->m_Parent.m_pAttribute = nullptr;
  this->m_Parent.m_Storage.u.m_Id = -1;
  this->m_Translation.m_pAttribute = nullptr;
  this->m_Translation.m_Storage.x = 0.0;
  this->m_Translation.m_Storage.y = 0.0;
  this->m_Translation.m_Storage.z = 0.0;
  this->m_Rotation.m_pAttribute = nullptr;
  this->m_Rotation.m_Storage.x = 0.0;
  this->m_Rotation.m_Storage.y = 0.0;
  this->m_Rotation.m_Storage.z = 0.0;
  this->m_RealignTranslation.m_pAttribute = nullptr;
  this->m_RealignTranslation.m_Storage.x = 0.0;
  this->m_RealignTranslation.m_Storage.y = 0.0;
  this->m_RealignTranslation.m_Storage.z = 0.0;
  this->m_RealignRotation.m_pAttribute = nullptr;
  this->m_RealignRotation.m_Storage.x = 0.0;
  this->m_RealignRotation.m_Storage.y = 0.0;
  this->m_RealignRotation.m_Storage.z = 0.0;
  this->m_sContentsDescription.m_pAttribute = nullptr;
  this->m_sContentsDescription.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A4540
// Name: public: virtual bool CDmeDefineBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDefineBone::IsA(CDmeDefineBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDefineBone::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4570
// Name: public: virtual int CDmeDefineBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDefineBone::GetInheritanceDepth(CDmeDefineBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDefineBone::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A45B0
// Name: protected: virtual void CDmeDefineBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBone::PerformConstruction(CDmeDefineBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDefineBone::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00599AE0
// Name: _dynamic_initializer_for__CDmeDefineBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDefineBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDefineBone::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDefineBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E600
// Name: _dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDefineBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599B10
// Name: _dynamic_initializer_for__g_CDmeDefineBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDefineBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599B20
// Name: _dynamic_initializer_for__g_CDmeDefineBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDefineBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDefineBone_Helper,
           classname: "DmeDefineBone",
           pFactory: &g_CDmeDefineBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E610
// Name: _dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDefineBone_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E60E0
// Name: protected: void CDmeDefineBone::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBone::OnConstruction(CDmeDefineBone *this)
{
  this->m_Parent.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "parent",
                                  type: AT_STRING,
                                  pMemory: &this->m_Parent);
  this->m_Translation.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "translation",
                                       type: AT_VECTOR3,
                                       pMemory: &this->m_Translation);
  this->m_Rotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "rotation",
                                    type: AT_QANGLE,
                                    pMemory: &this->m_Rotation);
  this->m_RealignTranslation.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "realignTranslation",
                                              type: AT_VECTOR3,
                                              pMemory: &this->m_RealignTranslation);
  this->m_RealignRotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "realignRotation",
                                           type: AT_QANGLE,
                                           pMemory: &this->m_RealignRotation);
  this->m_sContentsDescription.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "contentsDescription",
                                                type: AT_STRING,
                                                pMemory: &this->m_sContentsDescription);
}

//------------------------------------------------------------------------------
// Address: 0x004E61D0
// Name: protected: CDmeDefineBone::CDmeDefineBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDefineBone *__thiscall CDmeDefineBone::CDmeDefineBone(
        CDmeDefineBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDefineBone_vtbl *)&CDmeDefineBone::`vftable';
  this->m_Parent.m_pAttribute = nullptr;
  this->m_Parent.m_Storage.u.m_Id = -1;
  this->m_Translation.m_pAttribute = nullptr;
  this->m_Translation.m_Storage.x = 0.0;
  this->m_Translation.m_Storage.y = 0.0;
  this->m_Translation.m_Storage.z = 0.0;
  this->m_Rotation.m_pAttribute = nullptr;
  this->m_Rotation.m_Storage.x = 0.0;
  this->m_Rotation.m_Storage.y = 0.0;
  this->m_Rotation.m_Storage.z = 0.0;
  this->m_RealignTranslation.m_pAttribute = nullptr;
  this->m_RealignTranslation.m_Storage.x = 0.0;
  this->m_RealignTranslation.m_Storage.y = 0.0;
  this->m_RealignTranslation.m_Storage.z = 0.0;
  this->m_RealignRotation.m_pAttribute = nullptr;
  this->m_RealignRotation.m_Storage.x = 0.0;
  this->m_RealignRotation.m_Storage.y = 0.0;
  this->m_RealignRotation.m_Storage.z = 0.0;
  this->m_sContentsDescription.m_pAttribute = nullptr;
  this->m_sContentsDescription.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E62A0
// Name: public: virtual bool CDmeDefineBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDefineBone::IsA(CDmeDefineBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDefineBone::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E62D0
// Name: public: virtual int CDmeDefineBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDefineBone::GetInheritanceDepth(CDmeDefineBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDefineBone::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6310
// Name: protected: virtual void CDmeDefineBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBone::PerformConstruction(CDmeDefineBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDefineBone::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EDAC0
// Name: _dynamic_initializer_for__CDmeDefineBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDefineBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDefineBone::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDefineBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F34D0
// Name: _dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDefineBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDAF0
// Name: _dynamic_initializer_for__g_CDmeDefineBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDefineBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDB00
// Name: _dynamic_initializer_for__g_CDmeDefineBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDefineBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDefineBone_Helper,
           classname: "DmeDefineBone",
           pFactory: &g_CDmeDefineBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F34E0
// Name: _dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDefineBone_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00513F00
// Name: protected: void CDmeDefineBone::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBone::OnConstruction(CDmeDefineBone *this)
{
  this->m_Parent.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "parent",
                                  type: AT_STRING,
                                  pMemory: &this->m_Parent);
  this->m_Translation.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "translation",
                                       type: AT_VECTOR3,
                                       pMemory: &this->m_Translation);
  this->m_Rotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "rotation",
                                    type: AT_QANGLE,
                                    pMemory: &this->m_Rotation);
  this->m_RealignTranslation.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "realignTranslation",
                                              type: AT_VECTOR3,
                                              pMemory: &this->m_RealignTranslation);
  this->m_RealignRotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "realignRotation",
                                           type: AT_QANGLE,
                                           pMemory: &this->m_RealignRotation);
  this->m_sContentsDescription.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "contentsDescription",
                                                type: AT_STRING,
                                                pMemory: &this->m_sContentsDescription);
}

//------------------------------------------------------------------------------
// Address: 0x00513FF0
// Name: protected: CDmeDefineBone::CDmeDefineBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDefineBone *__thiscall CDmeDefineBone::CDmeDefineBone(
        CDmeDefineBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDefineBone_vtbl *)&CDmeDefineBone::`vftable';
  this->m_Parent.m_pAttribute = nullptr;
  this->m_Parent.m_Storage.u.m_Id = -1;
  this->m_Translation.m_pAttribute = nullptr;
  this->m_Translation.m_Storage.x = 0.0;
  this->m_Translation.m_Storage.y = 0.0;
  this->m_Translation.m_Storage.z = 0.0;
  this->m_Rotation.m_pAttribute = nullptr;
  this->m_Rotation.m_Storage.x = 0.0;
  this->m_Rotation.m_Storage.y = 0.0;
  this->m_Rotation.m_Storage.z = 0.0;
  this->m_RealignTranslation.m_pAttribute = nullptr;
  this->m_RealignTranslation.m_Storage.x = 0.0;
  this->m_RealignTranslation.m_Storage.y = 0.0;
  this->m_RealignTranslation.m_Storage.z = 0.0;
  this->m_RealignRotation.m_pAttribute = nullptr;
  this->m_RealignRotation.m_Storage.x = 0.0;
  this->m_RealignRotation.m_Storage.y = 0.0;
  this->m_RealignRotation.m_Storage.z = 0.0;
  this->m_sContentsDescription.m_pAttribute = nullptr;
  this->m_sContentsDescription.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005140C0
// Name: public: virtual bool CDmeDefineBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDefineBone::IsA(CDmeDefineBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDefineBone::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005140F0
// Name: public: virtual int CDmeDefineBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDefineBone::GetInheritanceDepth(CDmeDefineBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDefineBone::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514140
// Name: protected: virtual void CDmeDefineBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBone::PerformConstruction(CDmeDefineBone *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDefineBone::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006ADEE0
// Name: _dynamic_initializer_for__CDmeDefineBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDefineBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDefineBone::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDefineBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B43D0
// Name: _dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDefineBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ADF10
// Name: _dynamic_initializer_for__g_CDmeDefineBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDefineBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADF20
// Name: _dynamic_initializer_for__g_CDmeDefineBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDefineBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDefineBone_Helper,
           classname: "DmeDefineBone",
           pFactory: &g_CDmeDefineBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B43E0
// Name: _dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDefineBone_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E3980
// Name: protected: void CDmeDefineBone::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBone::OnConstruction(CDmeDefineBone *this)
{
  this->m_Parent.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "parent",
                                  type: AT_STRING,
                                  pMemory: &this->m_Parent);
  this->m_Translation.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "translation",
                                       type: AT_VECTOR3,
                                       pMemory: &this->m_Translation);
  this->m_Rotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "rotation",
                                    type: AT_QANGLE,
                                    pMemory: &this->m_Rotation);
  this->m_RealignTranslation.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "realignTranslation",
                                              type: AT_VECTOR3,
                                              pMemory: &this->m_RealignTranslation);
  this->m_RealignRotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "realignRotation",
                                           type: AT_QANGLE,
                                           pMemory: &this->m_RealignRotation);
  this->m_sContentsDescription.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "contentsDescription",
                                                type: AT_STRING,
                                                pMemory: &this->m_sContentsDescription);
}

//------------------------------------------------------------------------------
// Address: 0x004E3A70
// Name: protected: CDmeDefineBone::CDmeDefineBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDefineBone *__thiscall CDmeDefineBone::CDmeDefineBone(
        CDmeDefineBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDefineBone_vtbl *)&CDmeDefineBone::`vftable';
  this->m_Parent.m_pAttribute = nullptr;
  this->m_Parent.m_Storage.u.m_Id = -1;
  this->m_Translation.m_pAttribute = nullptr;
  this->m_Translation.m_Storage.x = 0.0;
  this->m_Translation.m_Storage.y = 0.0;
  this->m_Translation.m_Storage.z = 0.0;
  this->m_Rotation.m_pAttribute = nullptr;
  this->m_Rotation.m_Storage.x = 0.0;
  this->m_Rotation.m_Storage.y = 0.0;
  this->m_Rotation.m_Storage.z = 0.0;
  this->m_RealignTranslation.m_pAttribute = nullptr;
  this->m_RealignTranslation.m_Storage.x = 0.0;
  this->m_RealignTranslation.m_Storage.y = 0.0;
  this->m_RealignTranslation.m_Storage.z = 0.0;
  this->m_RealignRotation.m_pAttribute = nullptr;
  this->m_RealignRotation.m_Storage.x = 0.0;
  this->m_RealignRotation.m_Storage.y = 0.0;
  this->m_RealignRotation.m_Storage.z = 0.0;
  this->m_sContentsDescription.m_pAttribute = nullptr;
  this->m_sContentsDescription.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E3B40
// Name: public: virtual bool CDmeDefineBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDefineBone::IsA(CDmeDefineBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDefineBone::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3B70
// Name: public: virtual int CDmeDefineBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDefineBone::GetInheritanceDepth(CDmeDefineBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDefineBone::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3BB0
// Name: protected: virtual void CDmeDefineBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBone::PerformConstruction(CDmeDefineBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDefineBone::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E75C0
// Name: _dynamic_initializer_for__CDmeDefineBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDefineBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDefineBone::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDefineBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC790
// Name: _dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDefineBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDefineBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E75F0
// Name: _dynamic_initializer_for__g_CDmeDefineBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDefineBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7600
// Name: _dynamic_initializer_for__g_CDmeDefineBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDefineBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDefineBone_Helper,
           classname: "DmeDefineBone",
           pFactory: &g_CDmeDefineBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7A0
// Name: _dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDefineBone_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDefineBone_Factory.m_CallBackList);
}

} // namespace studiomdl
