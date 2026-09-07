// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: worldobjects/dmeworld.cpp
// Functions: 39
// ============================================================

#include "worldobjects\dmeworld.h"

//------------------------------------------------------------------------------
// Address: 0x005836D0
// Name: protected: virtual int CDmeWorldNodeReference::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldNodeReference::AllocatedSize(CDmeWorldNodeReference *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x006572B0
// Name: protected: void CDmeWorldBuilderParams::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldBuilderParams::OnConstruction(CDmeWorldBuilderParams *this)
{
  this->m_nSizeBytesPerVoxel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "sizeBytesPerVoxel",
                                              type: AT_INT,
                                              pMemory: &this->m_nSizeBytesPerVoxel);
  this->m_flMinDrawVolumeSize.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "minDrawVolumeSize",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flMinDrawVolumeSize);
  this->m_flMinDistToCamera.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "minDistToCamera",
                                             type: AT_FLOAT,
                                             pMemory: &this->m_flMinDistToCamera);
  this->m_flMinAtlasDist.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "minAtlasDist",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flMinAtlasDist);
  this->m_flMinSimplifiedDist.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "minSimplifiedDist",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flMinSimplifiedDist);
  this->m_flHorzFOV.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "horzFOV",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flHorzFOV);
  this->m_flHalfScreenWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "halfScreenWidth",
                                             type: AT_FLOAT,
                                             pMemory: &this->m_flHalfScreenWidth);
  this->m_nAtlasTextureSizeX.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "atlasTextureSizeX",
                                              type: AT_INT,
                                              pMemory: &this->m_nAtlasTextureSizeX);
  this->m_nAtlasTextureSizeY.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "atlasTextureSizeY",
                                              type: AT_INT,
                                              pMemory: &this->m_nAtlasTextureSizeY);
  this->m_nUniqueTextureSizeX.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "uniqueTextureSizeX",
                                               type: AT_INT,
                                               pMemory: &this->m_nUniqueTextureSizeX);
  this->m_nUniqueTextureSizeY.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "uniqueTextureSizeY",
                                               type: AT_INT,
                                               pMemory: &this->m_nUniqueTextureSizeY);
  this->m_nCompressedAtlasSize.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "compressedAtlasSize",
                                                type: AT_INT,
                                                pMemory: &this->m_nCompressedAtlasSize);
  this->m_flGutterSize.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "gutterSize",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flGutterSize);
  this->m_flUVMapThreshold.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "UVMapThreshold",
                                            type: AT_FLOAT,
                                            pMemory: &this->m_flUVMapThreshold);
  this->m_vWorldUnitsPerTile.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "worldUnitsPerTile",
                                              type: AT_VECTOR3,
                                              pMemory: &this->m_vWorldUnitsPerTile);
  this->m_nMaxTexScaleSlots.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "maxTexScaleSlots",
                                             type: AT_INT,
                                             pMemory: &this->m_nMaxTexScaleSlots);
  this->m_bWrapInAtlas.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "wrapInAtlas",
                                        type: AT_BOOL,
                                        pMemory: &this->m_bWrapInAtlas);
}

//------------------------------------------------------------------------------
// Address: 0x00657440
// Name: protected: void CDmeNodeData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeNodeData::OnConstruction(CDmeNodeData *this)
{
  this->m_nID.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "ID",
                               type: AT_INT,
                               pMemory: &this->m_nID);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_nParent.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "parent",
                                   type: AT_INT,
                                   pMemory: &this->m_nParent);
  this->m_vOrigin.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "origin",
                                   type: AT_VECTOR3,
                                   pMemory: &this->m_vOrigin);
  this->m_vMinBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "minBounds",
                                      type: AT_VECTOR3,
                                      pMemory: &this->m_vMinBounds);
  this->m_vMaxBounds.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "maxBounds",
                                      type: AT_VECTOR3,
                                      pMemory: &this->m_vMaxBounds);
  this->m_flMinimumDistance.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "minimumDistance",
                                             type: AT_FLOAT,
                                             pMemory: &this->m_flMinimumDistance);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_ChildNodeIndices,
    pOwner: this,
    pAttributeName: "childNodeIndices",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x006574F0
// Name: protected: void CDmeWorld::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorld::OnConstruction(CDmeWorld *this)
{
  CDmaElement<CDmeWorldBuilderParams> *p_m_builderParams; // edi

  p_m_builderParams = &this->m_builderParams;
  this->m_builderParams.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "builderParams",
                                         type: AT_FIRST_VALUE_TYPE,
                                         pMemory: &this->m_builderParams);
  CDmAttribute::SetElementTypeSymbol(
    this: p_m_builderParams->m_pAttribute,
    typeSymbol: CDmeWorldBuilderParams::m_classType);
  this->m_worldNodes.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "worldNodes",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_worldNodes);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_worldNodes.m_pAttribute,
    typeSymbol: CDmeWorldNodeReference::m_classType);
  this->m_entityString.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "entityString",
                                        type: AT_STRING,
                                        pMemory: &this->m_entityString);
}

//------------------------------------------------------------------------------
// Address: 0x006575C0
// Name: protected: CDmeWorldBuilderParams::CDmeWorldBuilderParams(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeWorldBuilderParams *__thiscall CDmeWorldBuilderParams::CDmeWorldBuilderParams(
        CDmeWorldBuilderParams *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeWorldBuilderParams_vtbl *)&CDmeWorldBuilderParams::`vftable';
  this->m_nSizeBytesPerVoxel.m_pAttribute = nullptr;
  this->m_nSizeBytesPerVoxel.m_Storage = 0;
  this->m_flMinDrawVolumeSize = 0;
  this->m_flMinDistToCamera = 0;
  this->m_flMinAtlasDist = 0;
  this->m_flMinSimplifiedDist = 0;
  this->m_flHorzFOV = 0;
  this->m_flHalfScreenWidth = 0;
  this->m_nAtlasTextureSizeX.m_pAttribute = nullptr;
  this->m_nAtlasTextureSizeX.m_Storage = 0;
  this->m_nAtlasTextureSizeY.m_pAttribute = nullptr;
  this->m_nAtlasTextureSizeY.m_Storage = 0;
  this->m_nUniqueTextureSizeX.m_pAttribute = nullptr;
  this->m_nUniqueTextureSizeX.m_Storage = 0;
  this->m_nUniqueTextureSizeY.m_pAttribute = nullptr;
  this->m_nUniqueTextureSizeY.m_Storage = 0;
  this->m_nCompressedAtlasSize.m_pAttribute = nullptr;
  this->m_nCompressedAtlasSize.m_Storage = 0;
  this->m_flGutterSize = 0;
  this->m_flUVMapThreshold = 0;
  this->m_vWorldUnitsPerTile.m_pAttribute = nullptr;
  this->m_vWorldUnitsPerTile.m_Storage.x = 0.0;
  this->m_vWorldUnitsPerTile.m_Storage.y = 0.0;
  this->m_vWorldUnitsPerTile.m_Storage.z = 0.0;
  this->m_nMaxTexScaleSlots.m_pAttribute = nullptr;
  this->m_nMaxTexScaleSlots.m_Storage = 0;
  this->m_bWrapInAtlas.m_pAttribute = nullptr;
  this->m_bWrapInAtlas.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006576F0
// Name: public: virtual bool CDmeWorldBuilderParams::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeWorldBuilderParams::IsA(CDmeWorldBuilderParams *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeWorldBuilderParams::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657720
// Name: public: virtual int CDmeWorldBuilderParams::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldBuilderParams::GetInheritanceDepth(CDmeWorldBuilderParams *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeWorldBuilderParams::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657760
// Name: protected: virtual int CDmeWorldBuilderParams::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldBuilderParams::AllocatedSize(CDmeWorldBuilderParams *this)
{
  return 212;
}

//------------------------------------------------------------------------------
// Address: 0x006577B0
// Name: protected: virtual void CDmeWorldBuilderParams::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldBuilderParams::PerformConstruction(CDmeWorldBuilderParams *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeWorldBuilderParams::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00657910
// Name: public: virtual bool CDmeWorldNodeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeWorldNodeReference::IsA(CDmeWorldNodeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeWorldNodeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657940
// Name: public: virtual int CDmeWorldNodeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldNodeReference::GetInheritanceDepth(CDmeWorldNodeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeWorldNodeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006579F0
// Name: protected: virtual void CDmeWorldNodeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldNodeReference::PerformConstruction(CDmeWorldNodeReference *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_worldNodeFileName.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "worldNodeFileName",
                                             type: AT_STRING,
                                             pMemory: &this->m_worldNodeFileName);
  this->m_nodeData.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "nodeData",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_nodeData);
  CDmAttribute::SetElementTypeSymbol(this: this->m_nodeData.m_pAttribute, typeSymbol: CDmeNodeData::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00657A40
// Name: protected: CDmeNodeData::CDmeNodeData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeNodeData *__thiscall CDmeNodeData::CDmeNodeData(
        CDmeNodeData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeNodeData_vtbl *)&CDmeNodeData::`vftable';
  this->m_nID.m_pAttribute = nullptr;
  this->m_nID.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_nParent.m_pAttribute = nullptr;
  this->m_nParent.m_Storage = 0;
  this->m_vOrigin.m_pAttribute = nullptr;
  this->m_vOrigin.m_Storage.x = 0.0;
  this->m_vOrigin.m_Storage.y = 0.0;
  this->m_vOrigin.m_Storage.z = 0.0;
  this->m_vMinBounds.m_pAttribute = nullptr;
  this->m_vMinBounds.m_Storage.x = 0.0;
  this->m_vMinBounds.m_Storage.y = 0.0;
  this->m_vMinBounds.m_Storage.z = 0.0;
  this->m_vMaxBounds.m_pAttribute = nullptr;
  this->m_vMaxBounds.m_Storage.x = 0.0;
  this->m_vMaxBounds.m_Storage.y = 0.0;
  this->m_vMaxBounds.m_Storage.z = 0.0;
  this->m_flMinimumDistance = 0;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_ChildNodeIndices);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00657AE0
// Name: public: virtual bool CDmeNodeData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeNodeData::IsA(CDmeNodeData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeNodeData::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657B10
// Name: public: virtual int CDmeNodeData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeNodeData::GetInheritanceDepth(CDmeNodeData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeNodeData::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657B50
// Name: protected: virtual void CDmeNodeData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeNodeData::PerformConstruction(CDmeNodeData *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeNodeData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00657BE0
// Name: public: virtual bool CDmeWorld::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeWorld::IsA(CDmeWorld *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeWorld::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657C10
// Name: public: virtual int CDmeWorld::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorld::GetInheritanceDepth(CDmeWorld *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeWorld::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657C50
// Name: protected: virtual void CDmeWorld::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorld::PerformConstruction(CDmeWorld *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeWorld::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006BB270
// Name: _dynamic_initializer_for__CDmeWorldBuilderParams::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeWorldBuilderParams::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeWorldBuilderParams::s_Allocator,
    blockSize: 0xD4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeWorldBuilderParams pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeWorldBuilderParams::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB2D0
// Name: _dynamic_initializer_for__CDmeNodeData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeNodeData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeNodeData::s_Allocator,
    blockSize: 0xACu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeNodeData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeNodeData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB330
// Name: _dynamic_initializer_for__CDmeWorld::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeWorld::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeWorld::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeWorld pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeWorld::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB390
// Name: _dynamic_initializer_for__CDmeWorldNodeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeWorldNodeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeWorldNodeReference::s_Allocator,
    blockSize: 0x58u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeWorldNodeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeWorldNodeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BDBD0
// Name: _dynamic_atexit_destructor_for__CDmeWorldBuilderParams::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeWorldBuilderParams::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeWorldBuilderParams::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BDBE0
// Name: _dynamic_atexit_destructor_for__CDmeNodeData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeNodeData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeNodeData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BDBF0
// Name: _dynamic_atexit_destructor_for__CDmeWorld::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeWorld::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeWorld::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC00
// Name: _dynamic_atexit_destructor_for__CDmeWorldNodeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeWorldNodeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeWorldNodeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BB2A0
// Name: _dynamic_initializer_for__g_CDmeWorldBuilderParams_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeWorldBuilderParams_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeWorldBuilderParams_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB2B0
// Name: _dynamic_initializer_for__g_CDmeWorldBuilderParams_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeWorldBuilderParams_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeWorldBuilderParams_Helper,
           classname: "DmeWorldBuilderParams",
           pFactory: &g_CDmeWorldBuilderParams_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BB300
// Name: _dynamic_initializer_for__g_CDmeNodeData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeNodeData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeNodeData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB310
// Name: _dynamic_initializer_for__g_CDmeNodeData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeNodeData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeNodeData_Helper,
           classname: "DmeNodeData",
           pFactory: &g_CDmeNodeData_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BB360
// Name: _dynamic_initializer_for__g_CDmeWorld_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeWorld_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeWorld_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB370
// Name: _dynamic_initializer_for__g_CDmeWorld_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeWorld_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeWorld_Helper,
           classname: "DmeWorld",
           pFactory: &g_CDmeWorld_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BB3C0
// Name: _dynamic_initializer_for__g_CDmeWorldNodeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeWorldNodeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeWorldNodeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB3D0
// Name: _dynamic_initializer_for__g_CDmeWorldNodeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeWorldNodeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeWorldNodeReference_Helper,
           classname: "DmeWorldNodeReference",
           pFactory: &g_CDmeWorldNodeReference_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC10
// Name: _dynamic_atexit_destructor_for__g_CDmeNodeData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeNodeData_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeNodeData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC20
// Name: _dynamic_atexit_destructor_for__g_CDmeWorld_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeWorld_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeWorld_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC30
// Name: _dynamic_atexit_destructor_for__g_CDmeWorldNodeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeWorldNodeReference_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeWorldNodeReference_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BDC40
// Name: _dynamic_atexit_destructor_for__g_CDmeWorldBuilderParams_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeWorldBuilderParams_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeWorldBuilderParams_Factory.m_CallBackList);
}
