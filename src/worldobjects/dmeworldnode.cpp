// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: worldobjects/dmeworldnode.cpp
// Functions: 20
// ============================================================

#include "worldobjects\dmeworldnode.h"

//------------------------------------------------------------------------------
// Address: 0x0056A060
// Name: protected: virtual int CDmeWorldNode::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldNode::AllocatedSize(CDmeWorldNode *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x00656CC0
// Name: protected: void CDmeSceneObject::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSceneObject::OnConstruction(CDmeSceneObject *this)
{
  this->m_vTransform0.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform0",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform0);
  this->m_vTransform1.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform1",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform1);
  this->m_vTransform2.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "transform2",
                                       type: AT_VECTOR4,
                                       pMemory: &this->m_vTransform2);
  this->m_renderableFileName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "renderableFileName",
                                              type: AT_STRING,
                                              pMemory: &this->m_renderableFileName);
}

//------------------------------------------------------------------------------
// Address: 0x00656D20
// Name: protected: void CDmeWorldNode::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldNode::OnConstruction(CDmeWorldNode *this)
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
  this->m_SceneObjects.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sceneObjects",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_SceneObjects);
  CDmAttribute::SetElementTypeSymbol(this: this->m_SceneObjects.m_pAttribute, typeSymbol: CDmeSceneObject::m_classType);
  this->m_PointLights.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "pointLights",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_PointLights);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_PointLights.m_pAttribute,
    typeSymbol: CDmeWorldPointLight::m_classType);
  this->m_HemiLights.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hemiLights",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_HemiLights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HemiLights.m_pAttribute, typeSymbol: CDmeWorldHemiLight::m_classType);
  this->m_SpotLights.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "spotLight",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_SpotLights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_SpotLights.m_pAttribute, typeSymbol: CDmeWorldSpotLight::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00656F10
// Name: public: virtual bool CDmeSceneObject::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSceneObject::IsA(CDmeSceneObject *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSceneObject::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00656F40
// Name: public: virtual int CDmeSceneObject::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSceneObject::GetInheritanceDepth(CDmeSceneObject *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSceneObject::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00657040
// Name: protected: virtual void CDmeSceneObject::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSceneObject::PerformConstruction(CDmeSceneObject *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSceneObject::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006570B0
// Name: protected: CDmeWorldNode::CDmeWorldNode(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeWorldNode *__thiscall CDmeWorldNode::CDmeWorldNode(
        CDmeWorldNode *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeWorldNode_vtbl *)&CDmeWorldNode::`vftable';
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
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_SceneObjects);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_PointLights);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_HemiLights);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_SpotLights);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00657180
// Name: public: virtual bool CDmeWorldNode::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeWorldNode::IsA(CDmeWorldNode *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeWorldNode::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x006571B0
// Name: public: virtual int CDmeWorldNode::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeWorldNode::GetInheritanceDepth(CDmeWorldNode *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeWorldNode::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006571F0
// Name: protected: virtual void CDmeWorldNode::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeWorldNode::PerformConstruction(CDmeWorldNode *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeWorldNode::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006BB1B0
// Name: _dynamic_initializer_for__CDmeSceneObject::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSceneObject::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSceneObject::s_Allocator,
    blockSize: 0x88u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSceneObject pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSceneObject::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB210
// Name: _dynamic_initializer_for__CDmeWorldNode::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeWorldNode::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeWorldNode::s_Allocator,
    blockSize: 0x11Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeWorldNode pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeWorldNode::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BDB90
// Name: _dynamic_atexit_destructor_for__CDmeSceneObject::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSceneObject::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSceneObject::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BDBA0
// Name: _dynamic_atexit_destructor_for__CDmeWorldNode::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeWorldNode::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeWorldNode::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BB1E0
// Name: _dynamic_initializer_for__g_CDmeSceneObject_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSceneObject_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSceneObject_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB1F0
// Name: _dynamic_initializer_for__g_CDmeSceneObject_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSceneObject_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSceneObject_Helper,
           classname: "DmeSceneObject",
           pFactory: &g_CDmeSceneObject_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BB240
// Name: _dynamic_initializer_for__g_CDmeWorldNode_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeWorldNode_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeWorldNode_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB250
// Name: _dynamic_initializer_for__g_CDmeWorldNode_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeWorldNode_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeWorldNode_Helper,
           classname: "DmeWorldNode",
           pFactory: &g_CDmeWorldNode_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BDBB0
// Name: _dynamic_atexit_destructor_for__g_CDmeWorldNode_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeWorldNode_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeWorldNode_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BDBC0
// Name: _dynamic_atexit_destructor_for__g_CDmeSceneObject_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSceneObject_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSceneObject_Factory.m_CallBackList);
}
