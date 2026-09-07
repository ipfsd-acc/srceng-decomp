// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeasset.cpp
// Functions: 19
// ============================================================

#include "mdlobjects\dmeasset.h"

//------------------------------------------------------------------------------
// Address: 0x004A5FF0
// Name: protected: void CDmeRelatedAsset::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRelatedAsset::OnConstruction(CDmeRelatedAsset *this)
{
  this->m_sPath.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "path",
                                 type: AT_STRING,
                                 pMemory: &this->m_sPath);
  this->m_bIncludeModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "includeModel",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bIncludeModel);
  this->m_sNotes.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "notes",
                                  type: AT_STRING,
                                  pMemory: &this->m_sNotes);
  this->m_bUseSkeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "useSkeleton",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bUseSkeleton);
  this->m_bAlwaysIncludeAttachments.m_pAttribute = CDmElement::AddExternalAttribute(
                                                     this,
                                                     pAttributeName: "alwaysIncludeAttachments",
                                                     type: AT_BOOL,
                                                     pMemory: &this->m_bAlwaysIncludeAttachments);
  this->m_eAssembleCmds.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "assembleCmds",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_eAssembleCmds);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAssembleCmds.m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004A6090
// Name: protected: void CDmeAssetRoot::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAssetRoot::OnConstruction(CDmeAssetRoot *this)
{
  this->m_sMdlPath.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "mdlPath",
                                    type: AT_STRING,
                                    pMemory: &this->m_sMdlPath);
  this->m_sSurfaceProperty.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "surfaceProperty",
                                            type: AT_STRING,
                                            pMemory: &this->m_sSurfaceProperty);
  this->m_ePostAssembleCmds.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "postAssembleCmds",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_ePostAssembleCmds);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ePostAssembleCmds.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_eRelatedAssets.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "relatedAssets",
                                          type: AT_FIRST_ARRAY_TYPE,
                                          pMemory: &this->m_eRelatedAssets);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eRelatedAssets.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_sNameAtCreationTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "nameAtCreationTime",
                                               type: AT_STRING,
                                               pMemory: &this->m_sNameAtCreationTime);
  this->m_sNotes.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "notes",
                                  type: AT_STRING,
                                  pMemory: &this->m_sNotes);
  this->m_bAmbientBoost.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "ambientBoost",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bAmbientBoost);
  this->m_bCastTextureShadows.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "castTextureShadows",
                                               type: AT_BOOL,
                                               pMemory: &this->m_bCastTextureShadows);
  this->m_bDoNotCastShadows.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "doNotCastShadows",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bDoNotCastShadows);
  this->m_sDynamicLightingOrigin.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "dynamicLightingOrigin",
                                                  type: AT_STRING,
                                                  pMemory: &this->m_sDynamicLightingOrigin);
  this->m_nOpacity.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "opacity",
                                    type: AT_INT,
                                    pMemory: &this->m_nOpacity);
  this->m_bNoForcedFade.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "noForcedFace",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bNoForcedFade);
  this->m_bSubdivisionSurface.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "subdivisionSurface",
                                               type: AT_BOOL,
                                               pMemory: &this->m_bSubdivisionSurface);
  this->m_sContentsDescription.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "contentsDescription",
                                                type: AT_STRING,
                                                pMemory: &this->m_sContentsDescription);
}

//------------------------------------------------------------------------------
// Address: 0x004A62C0
// Name: protected: CDmeAssetRoot::CDmeAssetRoot(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAssetRoot *__thiscall CDmeAssetRoot::CDmeAssetRoot(
        CDmeAssetRoot *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAssetRoot_vtbl *)&CDmeAssetRoot::`vftable';
  this->m_sMdlPath.m_pAttribute = nullptr;
  this->m_sMdlPath.m_Storage.u.m_Id = -1;
  this->m_sSurfaceProperty.m_pAttribute = nullptr;
  this->m_sSurfaceProperty.m_Storage.u.m_Id = -1;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ePostAssembleCmds);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eRelatedAssets);
  this->m_sNameAtCreationTime.m_pAttribute = nullptr;
  this->m_sNameAtCreationTime.m_Storage.u.m_Id = -1;
  this->m_sNotes.m_pAttribute = nullptr;
  this->m_sNotes.m_Storage.u.m_Id = -1;
  this->m_bAmbientBoost.m_pAttribute = nullptr;
  this->m_bAmbientBoost.m_Storage = false;
  this->m_bCastTextureShadows.m_pAttribute = nullptr;
  this->m_bCastTextureShadows.m_Storage = false;
  this->m_bDoNotCastShadows.m_pAttribute = nullptr;
  this->m_bDoNotCastShadows.m_Storage = false;
  this->m_sDynamicLightingOrigin.m_pAttribute = nullptr;
  this->m_sDynamicLightingOrigin.m_Storage.u.m_Id = -1;
  this->m_nOpacity.m_pAttribute = nullptr;
  this->m_nOpacity.m_Storage = 0;
  this->m_bNoForcedFade.m_pAttribute = nullptr;
  this->m_bNoForcedFade.m_Storage = false;
  this->m_bSubdivisionSurface.m_pAttribute = nullptr;
  this->m_bSubdivisionSurface.m_Storage = false;
  this->m_sContentsDescription.m_Storage.u.m_Id = -1;
  this->m_sContentsDescription.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A6390
// Name: public: virtual bool CDmeAssetRoot::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAssetRoot::IsA(CDmeAssetRoot *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAssetRoot::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A63C0
// Name: public: virtual int CDmeAssetRoot::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAssetRoot::GetInheritanceDepth(CDmeAssetRoot *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAssetRoot::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6400
// Name: protected: virtual void CDmeAssetRoot::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAssetRoot::PerformConstruction(CDmeAssetRoot *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAssetRoot::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A6490
// Name: public: virtual bool CDmeRelatedAsset::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRelatedAsset::IsA(CDmeRelatedAsset *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRelatedAsset::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A64C0
// Name: public: virtual int CDmeRelatedAsset::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRelatedAsset::GetInheritanceDepth(CDmeRelatedAsset *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRelatedAsset::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6500
// Name: protected: virtual void CDmeRelatedAsset::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRelatedAsset::PerformConstruction(CDmeRelatedAsset *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRelatedAsset::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00599F60
// Name: _dynamic_initializer_for__CDmeRelatedAsset::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRelatedAsset::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRelatedAsset::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRelatedAsset pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599FC0
// Name: _dynamic_initializer_for__CDmeAssetRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAssetRoot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAssetRoot::s_Allocator,
    blockSize: 220,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAssetRoot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E780
// Name: _dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRelatedAsset::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E790
// Name: _dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAssetRoot::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599F90
// Name: _dynamic_initializer_for__g_CDmeRelatedAsset_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRelatedAsset_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599FA0
// Name: _dynamic_initializer_for__g_CDmeRelatedAsset_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRelatedAsset_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRelatedAsset_Helper,
           classname: "DmeRelatedAsset",
           pFactory: &g_CDmeRelatedAsset_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599FF0
// Name: _dynamic_initializer_for__g_CDmeAssetRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAssetRoot_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A000
// Name: _dynamic_initializer_for__g_CDmeAssetRoot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAssetRoot_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAssetRoot_Helper,
           classname: "DmeAssetRoot",
           pFactory: &g_CDmeAssetRoot_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E7A0
// Name: _dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAssetRoot_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E7B0
// Name: _dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRelatedAsset_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EC8C0
// Name: protected: void CDmeRelatedAsset::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRelatedAsset::OnConstruction(CDmeRelatedAsset *this)
{
  this->m_sPath.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "path",
                                 type: AT_STRING,
                                 pMemory: &this->m_sPath);
  this->m_bIncludeModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "includeModel",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bIncludeModel);
  this->m_sNotes.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "notes",
                                  type: AT_STRING,
                                  pMemory: &this->m_sNotes);
  this->m_bUseSkeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "useSkeleton",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bUseSkeleton);
  this->m_bAlwaysIncludeAttachments.m_pAttribute = CDmElement::AddExternalAttribute(
                                                     this,
                                                     pAttributeName: "alwaysIncludeAttachments",
                                                     type: AT_BOOL,
                                                     pMemory: &this->m_bAlwaysIncludeAttachments);
  this->m_eAssembleCmds.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "assembleCmds",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_eAssembleCmds);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAssembleCmds.m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004EC960
// Name: protected: void CDmeAssetRoot::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAssetRoot::OnConstruction(CDmeAssetRoot *this)
{
  this->m_sMdlPath.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "mdlPath",
                                    type: AT_STRING,
                                    pMemory: &this->m_sMdlPath);
  this->m_sSurfaceProperty.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "surfaceProperty",
                                            type: AT_STRING,
                                            pMemory: &this->m_sSurfaceProperty);
  this->m_ePostAssembleCmds.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "postAssembleCmds",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_ePostAssembleCmds);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ePostAssembleCmds.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_eRelatedAssets.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "relatedAssets",
                                          type: AT_FIRST_ARRAY_TYPE,
                                          pMemory: &this->m_eRelatedAssets);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eRelatedAssets.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_sNameAtCreationTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "nameAtCreationTime",
                                               type: AT_STRING,
                                               pMemory: &this->m_sNameAtCreationTime);
  this->m_sNotes.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "notes",
                                  type: AT_STRING,
                                  pMemory: &this->m_sNotes);
  this->m_bAmbientBoost.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "ambientBoost",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bAmbientBoost);
  this->m_bCastTextureShadows.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "castTextureShadows",
                                               type: AT_BOOL,
                                               pMemory: &this->m_bCastTextureShadows);
  this->m_bDoNotCastShadows.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "doNotCastShadows",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bDoNotCastShadows);
  this->m_sDynamicLightingOrigin.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "dynamicLightingOrigin",
                                                  type: AT_STRING,
                                                  pMemory: &this->m_sDynamicLightingOrigin);
  this->m_nOpacity.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "opacity",
                                    type: AT_INT,
                                    pMemory: &this->m_nOpacity);
  this->m_bNoForcedFade.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "noForcedFace",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bNoForcedFade);
  this->m_bSubdivisionSurface.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "subdivisionSurface",
                                               type: AT_BOOL,
                                               pMemory: &this->m_bSubdivisionSurface);
  this->m_sContentsDescription.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "contentsDescription",
                                                type: AT_STRING,
                                                pMemory: &this->m_sContentsDescription);
}

//------------------------------------------------------------------------------
// Address: 0x004ECB90
// Name: protected: CDmeAssetRoot::CDmeAssetRoot(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAssetRoot *__thiscall CDmeAssetRoot::CDmeAssetRoot(
        CDmeAssetRoot *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAssetRoot_vtbl *)&CDmeAssetRoot::`vftable';
  this->m_sMdlPath.m_pAttribute = nullptr;
  this->m_sMdlPath.m_Storage.u.m_Id = -1;
  this->m_sSurfaceProperty.m_pAttribute = nullptr;
  this->m_sSurfaceProperty.m_Storage.u.m_Id = -1;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ePostAssembleCmds);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eRelatedAssets);
  this->m_sNameAtCreationTime.m_pAttribute = nullptr;
  this->m_sNameAtCreationTime.m_Storage.u.m_Id = -1;
  this->m_sNotes.m_pAttribute = nullptr;
  this->m_sNotes.m_Storage.u.m_Id = -1;
  this->m_bAmbientBoost.m_pAttribute = nullptr;
  this->m_bAmbientBoost.m_Storage = false;
  this->m_bCastTextureShadows.m_pAttribute = nullptr;
  this->m_bCastTextureShadows.m_Storage = false;
  this->m_bDoNotCastShadows.m_pAttribute = nullptr;
  this->m_bDoNotCastShadows.m_Storage = false;
  this->m_sDynamicLightingOrigin.m_pAttribute = nullptr;
  this->m_sDynamicLightingOrigin.m_Storage.u.m_Id = -1;
  this->m_nOpacity.m_pAttribute = nullptr;
  this->m_nOpacity.m_Storage = 0;
  this->m_bNoForcedFade.m_pAttribute = nullptr;
  this->m_bNoForcedFade.m_Storage = false;
  this->m_bSubdivisionSurface.m_pAttribute = nullptr;
  this->m_bSubdivisionSurface.m_Storage = false;
  this->m_sContentsDescription.m_Storage.u.m_Id = -1;
  this->m_sContentsDescription.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004ECC60
// Name: public: virtual bool CDmeAssetRoot::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAssetRoot::IsA(CDmeAssetRoot *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAssetRoot::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECC90
// Name: public: virtual int CDmeAssetRoot::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAssetRoot::GetInheritanceDepth(CDmeAssetRoot *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAssetRoot::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECCD0
// Name: protected: virtual void CDmeAssetRoot::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAssetRoot::PerformConstruction(CDmeAssetRoot *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAssetRoot::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004ECD60
// Name: public: virtual bool CDmeRelatedAsset::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRelatedAsset::IsA(CDmeRelatedAsset *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRelatedAsset::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECD90
// Name: public: virtual int CDmeRelatedAsset::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRelatedAsset::GetInheritanceDepth(CDmeRelatedAsset *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRelatedAsset::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECDD0
// Name: protected: virtual void CDmeRelatedAsset::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRelatedAsset::PerformConstruction(CDmeRelatedAsset *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRelatedAsset::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EEC60
// Name: _dynamic_initializer_for__CDmeRelatedAsset::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRelatedAsset::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRelatedAsset::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRelatedAsset pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EECC0
// Name: _dynamic_initializer_for__CDmeAssetRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAssetRoot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAssetRoot::s_Allocator,
    blockSize: 220,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAssetRoot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3AB0
// Name: _dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRelatedAsset::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3AC0
// Name: _dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAssetRoot::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EEC90
// Name: _dynamic_initializer_for__g_CDmeRelatedAsset_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRelatedAsset_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EECA0
// Name: _dynamic_initializer_for__g_CDmeRelatedAsset_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRelatedAsset_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRelatedAsset_Helper,
           classname: "DmeRelatedAsset",
           pFactory: &g_CDmeRelatedAsset_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EECF0
// Name: _dynamic_initializer_for__g_CDmeAssetRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAssetRoot_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EED00
// Name: _dynamic_initializer_for__g_CDmeAssetRoot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAssetRoot_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAssetRoot_Helper,
           classname: "DmeAssetRoot",
           pFactory: &g_CDmeAssetRoot_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3AD0
// Name: _dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAssetRoot_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3AE0
// Name: _dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRelatedAsset_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00515B30
// Name: protected: void CDmeRelatedAsset::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRelatedAsset::OnConstruction(CDmeRelatedAsset *this)
{
  this->m_sPath.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "path",
                                 type: AT_STRING,
                                 pMemory: &this->m_sPath);
  this->m_bIncludeModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "includeModel",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bIncludeModel);
  this->m_sNotes.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "notes",
                                  type: AT_STRING,
                                  pMemory: &this->m_sNotes);
  this->m_bUseSkeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "useSkeleton",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bUseSkeleton);
  this->m_bAlwaysIncludeAttachments.m_pAttribute = CDmElement::AddExternalAttribute(
                                                     this,
                                                     pAttributeName: "alwaysIncludeAttachments",
                                                     type: AT_BOOL,
                                                     pMemory: &this->m_bAlwaysIncludeAttachments);
  this->m_eAssembleCmds.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "assembleCmds",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_eAssembleCmds);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAssembleCmds.m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00515BD0
// Name: protected: void CDmeAssetRoot::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAssetRoot::OnConstruction(CDmeAssetRoot *this)
{
  this->m_sMdlPath.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "mdlPath",
                                    type: AT_STRING,
                                    pMemory: &this->m_sMdlPath);
  this->m_sSurfaceProperty.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "surfaceProperty",
                                            type: AT_STRING,
                                            pMemory: &this->m_sSurfaceProperty);
  this->m_ePostAssembleCmds.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "postAssembleCmds",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_ePostAssembleCmds);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ePostAssembleCmds.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_eRelatedAssets.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "relatedAssets",
                                          type: AT_FIRST_ARRAY_TYPE,
                                          pMemory: &this->m_eRelatedAssets);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eRelatedAssets.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_sNameAtCreationTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "nameAtCreationTime",
                                               type: AT_STRING,
                                               pMemory: &this->m_sNameAtCreationTime);
  this->m_sNotes.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "notes",
                                  type: AT_STRING,
                                  pMemory: &this->m_sNotes);
  this->m_bAmbientBoost.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "ambientBoost",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bAmbientBoost);
  this->m_bCastTextureShadows.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "castTextureShadows",
                                               type: AT_BOOL,
                                               pMemory: &this->m_bCastTextureShadows);
  this->m_bDoNotCastShadows.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "doNotCastShadows",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bDoNotCastShadows);
  this->m_sDynamicLightingOrigin.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "dynamicLightingOrigin",
                                                  type: AT_STRING,
                                                  pMemory: &this->m_sDynamicLightingOrigin);
  this->m_nOpacity.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "opacity",
                                    type: AT_INT,
                                    pMemory: &this->m_nOpacity);
  this->m_bNoForcedFade.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "noForcedFace",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bNoForcedFade);
  this->m_bSubdivisionSurface.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "subdivisionSurface",
                                               type: AT_BOOL,
                                               pMemory: &this->m_bSubdivisionSurface);
  this->m_sContentsDescription.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "contentsDescription",
                                                type: AT_STRING,
                                                pMemory: &this->m_sContentsDescription);
}

//------------------------------------------------------------------------------
// Address: 0x00515E00
// Name: protected: CDmeAssetRoot::CDmeAssetRoot(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAssetRoot *__thiscall CDmeAssetRoot::CDmeAssetRoot(
        CDmeAssetRoot *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAssetRoot_vtbl *)&CDmeAssetRoot::`vftable';
  this->m_sMdlPath.m_pAttribute = nullptr;
  this->m_sMdlPath.m_Storage.u.m_Id = -1;
  this->m_sSurfaceProperty.m_pAttribute = nullptr;
  this->m_sSurfaceProperty.m_Storage.u.m_Id = -1;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ePostAssembleCmds);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eRelatedAssets);
  this->m_sNameAtCreationTime.m_pAttribute = nullptr;
  this->m_sNameAtCreationTime.m_Storage.u.m_Id = -1;
  this->m_sNotes.m_pAttribute = nullptr;
  this->m_sNotes.m_Storage.u.m_Id = -1;
  this->m_bAmbientBoost.m_pAttribute = nullptr;
  this->m_bAmbientBoost.m_Storage = false;
  this->m_bCastTextureShadows.m_pAttribute = nullptr;
  this->m_bCastTextureShadows.m_Storage = false;
  this->m_bDoNotCastShadows.m_pAttribute = nullptr;
  this->m_bDoNotCastShadows.m_Storage = false;
  this->m_sDynamicLightingOrigin.m_pAttribute = nullptr;
  this->m_sDynamicLightingOrigin.m_Storage.u.m_Id = -1;
  this->m_nOpacity.m_pAttribute = nullptr;
  this->m_nOpacity.m_Storage = 0;
  this->m_bNoForcedFade.m_pAttribute = nullptr;
  this->m_bNoForcedFade.m_Storage = false;
  this->m_bSubdivisionSurface.m_pAttribute = nullptr;
  this->m_bSubdivisionSurface.m_Storage = false;
  this->m_sContentsDescription.m_Storage.u.m_Id = -1;
  this->m_sContentsDescription.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00515ED0
// Name: public: virtual bool CDmeAssetRoot::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAssetRoot::IsA(CDmeAssetRoot *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAssetRoot::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515F00
// Name: public: virtual int CDmeAssetRoot::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAssetRoot::GetInheritanceDepth(CDmeAssetRoot *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAssetRoot::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515F40
// Name: protected: virtual void CDmeAssetRoot::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAssetRoot::PerformConstruction(CDmeAssetRoot *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeAssetRoot::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00515FD0
// Name: public: virtual bool CDmeRelatedAsset::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRelatedAsset::IsA(CDmeRelatedAsset *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRelatedAsset::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516000
// Name: public: virtual int CDmeRelatedAsset::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRelatedAsset::GetInheritanceDepth(CDmeRelatedAsset *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRelatedAsset::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516040
// Name: protected: virtual void CDmeRelatedAsset::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRelatedAsset::PerformConstruction(CDmeRelatedAsset *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeRelatedAsset::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AE360
// Name: _dynamic_initializer_for__CDmeRelatedAsset::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRelatedAsset::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRelatedAsset::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRelatedAsset pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE3C0
// Name: _dynamic_initializer_for__CDmeAssetRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAssetRoot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAssetRoot::s_Allocator,
    blockSize: 220,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAssetRoot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4550
// Name: _dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRelatedAsset::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4560
// Name: _dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAssetRoot::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE390
// Name: _dynamic_initializer_for__g_CDmeRelatedAsset_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRelatedAsset_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE3A0
// Name: _dynamic_initializer_for__g_CDmeRelatedAsset_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRelatedAsset_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRelatedAsset_Helper,
           classname: "DmeRelatedAsset",
           pFactory: &g_CDmeRelatedAsset_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE3F0
// Name: _dynamic_initializer_for__g_CDmeAssetRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAssetRoot_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE400
// Name: _dynamic_initializer_for__g_CDmeAssetRoot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAssetRoot_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAssetRoot_Helper,
           classname: "DmeAssetRoot",
           pFactory: &g_CDmeAssetRoot_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4570
// Name: _dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAssetRoot_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4580
// Name: _dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeRelatedAsset_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E5150
// Name: protected: void CDmeRelatedAsset::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRelatedAsset::OnConstruction(CDmeRelatedAsset *this)
{
  this->m_sPath.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "path",
                                 type: AT_STRING,
                                 pMemory: &this->m_sPath);
  this->m_bIncludeModel.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "includeModel",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bIncludeModel);
  this->m_sNotes.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "notes",
                                  type: AT_STRING,
                                  pMemory: &this->m_sNotes);
  this->m_bUseSkeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "useSkeleton",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bUseSkeleton);
  this->m_bAlwaysIncludeAttachments.m_pAttribute = CDmElement::AddExternalAttribute(
                                                     this,
                                                     pAttributeName: "alwaysIncludeAttachments",
                                                     type: AT_BOOL,
                                                     pMemory: &this->m_bAlwaysIncludeAttachments);
  this->m_eAssembleCmds.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "assembleCmds",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_eAssembleCmds);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAssembleCmds.m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E51F0
// Name: protected: void CDmeAssetRoot::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAssetRoot::OnConstruction(CDmeAssetRoot *this)
{
  this->m_sMdlPath.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "mdlPath",
                                    type: AT_STRING,
                                    pMemory: &this->m_sMdlPath);
  this->m_sSurfaceProperty.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "surfaceProperty",
                                            type: AT_STRING,
                                            pMemory: &this->m_sSurfaceProperty);
  this->m_ePostAssembleCmds.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "postAssembleCmds",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_ePostAssembleCmds);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ePostAssembleCmds.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_eRelatedAssets.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "relatedAssets",
                                          type: AT_FIRST_ARRAY_TYPE,
                                          pMemory: &this->m_eRelatedAssets);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eRelatedAssets.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_sNameAtCreationTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "nameAtCreationTime",
                                               type: AT_STRING,
                                               pMemory: &this->m_sNameAtCreationTime);
  this->m_sNotes.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "notes",
                                  type: AT_STRING,
                                  pMemory: &this->m_sNotes);
  this->m_bAmbientBoost.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "ambientBoost",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bAmbientBoost);
  this->m_bCastTextureShadows.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "castTextureShadows",
                                               type: AT_BOOL,
                                               pMemory: &this->m_bCastTextureShadows);
  this->m_bDoNotCastShadows.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "doNotCastShadows",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bDoNotCastShadows);
  this->m_sDynamicLightingOrigin.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "dynamicLightingOrigin",
                                                  type: AT_STRING,
                                                  pMemory: &this->m_sDynamicLightingOrigin);
  this->m_nOpacity.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "opacity",
                                    type: AT_INT,
                                    pMemory: &this->m_nOpacity);
  this->m_bNoForcedFade.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "noForcedFace",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bNoForcedFade);
  this->m_bSubdivisionSurface.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "subdivisionSurface",
                                               type: AT_BOOL,
                                               pMemory: &this->m_bSubdivisionSurface);
  this->m_sContentsDescription.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "contentsDescription",
                                                type: AT_STRING,
                                                pMemory: &this->m_sContentsDescription);
}

//------------------------------------------------------------------------------
// Address: 0x004E5420
// Name: protected: CDmeAssetRoot::CDmeAssetRoot(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAssetRoot *__thiscall CDmeAssetRoot::CDmeAssetRoot(
        CDmeAssetRoot *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAssetRoot_vtbl *)&CDmeAssetRoot::`vftable';
  this->m_sMdlPath.m_pAttribute = nullptr;
  this->m_sMdlPath.m_Storage.u.m_Id = -1;
  this->m_sSurfaceProperty.m_pAttribute = nullptr;
  this->m_sSurfaceProperty.m_Storage.u.m_Id = -1;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ePostAssembleCmds);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eRelatedAssets);
  this->m_sNameAtCreationTime.m_pAttribute = nullptr;
  this->m_sNameAtCreationTime.m_Storage.u.m_Id = -1;
  this->m_sNotes.m_pAttribute = nullptr;
  this->m_sNotes.m_Storage.u.m_Id = -1;
  this->m_bAmbientBoost.m_pAttribute = nullptr;
  this->m_bAmbientBoost.m_Storage = false;
  this->m_bCastTextureShadows.m_pAttribute = nullptr;
  this->m_bCastTextureShadows.m_Storage = false;
  this->m_bDoNotCastShadows.m_pAttribute = nullptr;
  this->m_bDoNotCastShadows.m_Storage = false;
  this->m_sDynamicLightingOrigin.m_pAttribute = nullptr;
  this->m_sDynamicLightingOrigin.m_Storage.u.m_Id = -1;
  this->m_nOpacity.m_pAttribute = nullptr;
  this->m_nOpacity.m_Storage = 0;
  this->m_bNoForcedFade.m_pAttribute = nullptr;
  this->m_bNoForcedFade.m_Storage = false;
  this->m_bSubdivisionSurface.m_pAttribute = nullptr;
  this->m_bSubdivisionSurface.m_Storage = false;
  this->m_sContentsDescription.m_Storage.u.m_Id = -1;
  this->m_sContentsDescription.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E54F0
// Name: public: virtual bool CDmeAssetRoot::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAssetRoot::IsA(CDmeAssetRoot *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAssetRoot::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5520
// Name: public: virtual int CDmeAssetRoot::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAssetRoot::GetInheritanceDepth(CDmeAssetRoot *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAssetRoot::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5570
// Name: protected: virtual void CDmeAssetRoot::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAssetRoot::PerformConstruction(CDmeAssetRoot *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAssetRoot::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E5600
// Name: public: virtual bool CDmeRelatedAsset::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRelatedAsset::IsA(CDmeRelatedAsset *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRelatedAsset::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5630
// Name: public: virtual int CDmeRelatedAsset::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRelatedAsset::GetInheritanceDepth(CDmeRelatedAsset *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRelatedAsset::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5670
// Name: protected: virtual void CDmeRelatedAsset::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRelatedAsset::PerformConstruction(CDmeRelatedAsset *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRelatedAsset::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E79E0
// Name: _dynamic_initializer_for__CDmeRelatedAsset::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRelatedAsset::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRelatedAsset::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRelatedAsset pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7A40
// Name: _dynamic_initializer_for__CDmeAssetRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAssetRoot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAssetRoot::s_Allocator,
    blockSize: 220,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAssetRoot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC8F0
// Name: _dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRelatedAsset::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRelatedAsset::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC900
// Name: _dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAssetRoot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAssetRoot::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7A10
// Name: _dynamic_initializer_for__g_CDmeRelatedAsset_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRelatedAsset_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7A20
// Name: _dynamic_initializer_for__g_CDmeRelatedAsset_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRelatedAsset_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRelatedAsset_Helper,
           classname: "DmeRelatedAsset",
           pFactory: &g_CDmeRelatedAsset_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7A70
// Name: _dynamic_initializer_for__g_CDmeAssetRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAssetRoot_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7A80
// Name: _dynamic_initializer_for__g_CDmeAssetRoot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAssetRoot_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAssetRoot_Helper,
           classname: "DmeAssetRoot",
           pFactory: &g_CDmeAssetRoot_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC910
// Name: _dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAssetRoot_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAssetRoot_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC920
// Name: _dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRelatedAsset_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRelatedAsset_Factory.m_CallBackList);
}

} // namespace studiomdl
