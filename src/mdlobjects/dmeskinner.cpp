// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeskinner.cpp
// Functions: 50
// ============================================================

#include "mdlobjects\dmeskinner.h"

//------------------------------------------------------------------------------
// Address: 0x004A5060
// Name: protected: void CDmeSkinnerVolume::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerVolume::OnConstruction(CDmeSkinnerVolume *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_mMatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "matrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_mMatrix);
  this->m_flStrength.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "strength",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flStrength);
  this->m_flFalloff.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "falloff",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flFalloff);
  this->m_nFalloffType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "falloffType",
                                        type: AT_INT,
                                        pMemory: &this->m_nFalloffType);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "powerY", type: AT_FLOAT, pMemory: &this->m_flPowerY);
  this->m_flPowerY.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "powerXZ", type: AT_FLOAT, pMemory: &this->m_flPowerXZ);
  this->m_flPowerXZ.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004A5220
// Name: protected: CDmeSkinnerVolume::CDmeSkinnerVolume(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSkinnerVolume *__thiscall CDmeSkinnerVolume::CDmeSkinnerVolume(
        CDmeSkinnerVolume *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSkinnerVolume_vtbl *)&CDmeSkinnerVolume::`vftable';
  this->m_mMatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_mMatrix.m_Storage);
  this->m_flStrength.m_pAttribute = nullptr;
  this->m_flStrength.m_Storage = 0.0;
  this->m_flFalloff.m_pAttribute = nullptr;
  this->m_flFalloff.m_Storage = 0.0;
  this->m_nFalloffType.m_pAttribute = nullptr;
  this->m_nFalloffType.m_Storage = 0;
  this->m_flPowerY.m_pAttribute = nullptr;
  this->m_flPowerY.m_Storage = 0.0;
  this->m_flPowerXZ.m_pAttribute = nullptr;
  this->m_flPowerXZ.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A52E0
// Name: public: virtual bool CDmeSkinnerVolume::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinnerVolume::IsA(CDmeSkinnerVolume *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinnerVolume::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5310
// Name: public: virtual int CDmeSkinnerVolume::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerVolume::GetInheritanceDepth(CDmeSkinnerVolume *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinnerVolume::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A53A0
// Name: protected: virtual void CDmeSkinnerVolume::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerVolume::PerformConstruction(CDmeSkinnerVolume *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSkinnerVolume::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A5470
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformConstruction(CDmeSkinner *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A5480
// Name: public: virtual bool CDmeDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsA(CDmeDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A54B0
// Name: public: virtual int CDmeDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::GetInheritanceDepth(CDmeDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5530
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A55A0
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A55D0
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5620
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x004A5680
// Name: protected: CDmeSkinnerJoint::CDmeSkinnerJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSkinnerJoint *__thiscall CDmeSkinnerJoint::CDmeSkinnerJoint(
        CDmeSkinnerJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeSkinnerJoint::`vftable';
  this->m_mBindWorldMatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_mBindWorldMatrix.m_Storage);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eVolumeList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A5720
// Name: public: virtual bool CDmeSkinnerJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinnerJoint::IsA(CDmeSkinnerJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinnerJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5760
// Name: public: virtual int CDmeSkinnerJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerJoint::GetInheritanceDepth(CDmeSkinnerJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinnerJoint::m_classType.u.m_Id )
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
// Address: 0x004A57C0
// Name: protected: virtual int CDmeSkinnerJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerJoint::AllocatedSize(CDmeSkinnerJoint *this)
{
  return 236;
}

//------------------------------------------------------------------------------
// Address: 0x004A57D0
// Name: protected: virtual void CDmeSkinnerJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerJoint::PerformConstruction(CDmeSkinnerJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  this->m_mBindWorldMatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "bindWorldMatrix",
                                            type: AT_VMATRIX,
                                            pMemory: &this->m_mBindWorldMatrix);
  this->m_eVolumeList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "volumeList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eVolumeList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eVolumeList.m_pAttribute, typeSymbol: CDmeSkinnerVolume::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004A5890
// Name: public: virtual bool CDmeSkinner::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinner::IsA(CDmeSkinner *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinner::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A58C0
// Name: public: virtual int CDmeSkinner::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinner::GetInheritanceDepth(CDmeSkinner *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinner::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5920
// Name: protected: virtual int CDmeSkinner::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinner::AllocatedSize(CDmeSkinner *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x004A6EC0
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A6EE0
// Name: protected: virtual void CDmeSkinnerJoint::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerJoint::PerformDestruction(CDmeSkinnerJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00599D20
// Name: _dynamic_initializer_for__CDmeSkinnerVolume::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinnerVolume::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinnerVolume::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinnerVolume pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599D80
// Name: _dynamic_initializer_for__CDmeSkinnerJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinnerJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinnerJoint::s_Allocator,
    blockSize: 236,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinnerJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599DE0
// Name: _dynamic_initializer_for__CDmeSkinner::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinner::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinner::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinner pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AB00
// Name: _dynamic_initializer_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDag::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AB60
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AC50
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E6C0
// Name: _dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinnerVolume::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E6D0
// Name: _dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinnerJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E6E0
// Name: _dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinner::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EBA0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EBB0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC30
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004A5130
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CDmElement *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  DmElementHandle_t Handle; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_fileId; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    Handle = CDmElement::GetHandle(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v4 + 436))(
           a1: g_pDataModel.u,
           a2: Handle);
    m_fileId = pElement->m_fileId;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_fileId = DMFILEID_INVALID;
  }
  it.m_fileid = m_fileId;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00599D50
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolume_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinnerVolume_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599D60
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolume_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinnerVolume_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinnerVolume_Helper,
           classname: "DmeSkinnerVolume",
           pFactory: &g_CDmeSkinnerVolume_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599DB0
// Name: _dynamic_initializer_for__g_CDmeSkinnerJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinnerJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599DC0
// Name: _dynamic_initializer_for__g_CDmeSkinnerJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinnerJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinnerJoint_Helper,
           classname: "DmeSkinnerJoint",
           pFactory: &g_CDmeSkinnerJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599E10
// Name: _dynamic_initializer_for__g_CDmeSkinner_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinner_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599E20
// Name: _dynamic_initializer_for__g_CDmeSkinner_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinner_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinner_Helper,
           classname: "DmeSkinner",
           pFactory: &g_CDmeSkinner_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059AB30
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AB40
// Name: _dynamic_initializer_for__g_CDmeDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDag_Helper,
           classname: "DmeDag",
           pFactory: &g_CDmeDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059AC80
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AC90
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E6F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinnerJoint_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E700
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinner_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E710
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinnerVolume_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EBC0
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC40
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EC0F0
// Name: protected: void CDmeSkinnerVolume::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerVolume::OnConstruction(CDmeSkinnerVolume *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_mMatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "matrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_mMatrix);
  this->m_flStrength.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "strength",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flStrength);
  this->m_flFalloff.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "falloff",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flFalloff);
  this->m_nFalloffType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "falloffType",
                                        type: AT_INT,
                                        pMemory: &this->m_nFalloffType);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "powerY", type: AT_FLOAT, pMemory: &this->m_flPowerY);
  this->m_flPowerY.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "powerXZ", type: AT_FLOAT, pMemory: &this->m_flPowerXZ);
  this->m_flPowerXZ.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004EC2B0
// Name: protected: CDmeSkinnerVolume::CDmeSkinnerVolume(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSkinnerVolume *__thiscall CDmeSkinnerVolume::CDmeSkinnerVolume(
        CDmeSkinnerVolume *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSkinnerVolume_vtbl *)&CDmeSkinnerVolume::`vftable';
  this->m_mMatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_mMatrix.m_Storage);
  this->m_flStrength.m_pAttribute = nullptr;
  this->m_flStrength.m_Storage = 0.0;
  this->m_flFalloff.m_pAttribute = nullptr;
  this->m_flFalloff.m_Storage = 0.0;
  this->m_nFalloffType.m_pAttribute = nullptr;
  this->m_nFalloffType.m_Storage = 0;
  this->m_flPowerY.m_pAttribute = nullptr;
  this->m_flPowerY.m_Storage = 0.0;
  this->m_flPowerXZ.m_pAttribute = nullptr;
  this->m_flPowerXZ.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EC370
// Name: public: virtual bool CDmeSkinnerVolume::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinnerVolume::IsA(CDmeSkinnerVolume *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinnerVolume::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EC3A0
// Name: public: virtual int CDmeSkinnerVolume::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerVolume::GetInheritanceDepth(CDmeSkinnerVolume *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinnerVolume::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EC420
// Name: protected: virtual void CDmeSkinnerVolume::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerVolume::PerformConstruction(CDmeSkinnerVolume *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSkinnerVolume::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EC4F0
// Name: protected: CDmeSkinnerJoint::CDmeSkinnerJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSkinnerJoint *__thiscall CDmeSkinnerJoint::CDmeSkinnerJoint(
        CDmeSkinnerJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeSkinnerJoint::`vftable';
  this->m_mBindWorldMatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_mBindWorldMatrix.m_Storage);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eVolumeList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EC590
// Name: public: virtual bool CDmeSkinnerJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinnerJoint::IsA(CDmeSkinnerJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinnerJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EC5D0
// Name: public: virtual int CDmeSkinnerJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerJoint::GetInheritanceDepth(CDmeSkinnerJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinnerJoint::m_classType.u.m_Id )
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
// Address: 0x004EC630
// Name: protected: virtual void CDmeSkinnerJoint::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerJoint::PerformDestruction(CDmeSkinnerJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004EC650
// Name: protected: virtual int CDmeSkinnerJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerJoint::AllocatedSize(CDmeSkinnerJoint *this)
{
  return 236;
}

//------------------------------------------------------------------------------
// Address: 0x004EC660
// Name: protected: virtual void CDmeSkinnerJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerJoint::PerformConstruction(CDmeSkinnerJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  this->m_mBindWorldMatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "bindWorldMatrix",
                                            type: AT_VMATRIX,
                                            pMemory: &this->m_mBindWorldMatrix);
  this->m_eVolumeList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "volumeList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eVolumeList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eVolumeList.m_pAttribute, typeSymbol: CDmeSkinnerVolume::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004EC720
// Name: public: virtual bool CDmeSkinner::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinner::IsA(CDmeSkinner *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinner::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EC750
// Name: public: virtual int CDmeSkinner::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinner::GetInheritanceDepth(CDmeSkinner *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinner::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EC7A0
// Name: protected: virtual int CDmeSkinner::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinner::AllocatedSize(CDmeSkinner *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x005EEB40
// Name: _dynamic_initializer_for__CDmeSkinnerVolume::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinnerVolume::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinnerVolume::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinnerVolume pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEBA0
// Name: _dynamic_initializer_for__CDmeSkinnerJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinnerJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinnerJoint::s_Allocator,
    blockSize: 236,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinnerJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEC00
// Name: _dynamic_initializer_for__CDmeSkinner::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinner::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinner::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinner pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A50
// Name: _dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinnerVolume::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A60
// Name: _dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinnerJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A70
// Name: _dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinner::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004EC1C0
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EEB70
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolume_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinnerVolume_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEB80
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolume_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinnerVolume_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinnerVolume_Helper,
           classname: "DmeSkinnerVolume",
           pFactory: &g_CDmeSkinnerVolume_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EEBD0
// Name: _dynamic_initializer_for__g_CDmeSkinnerJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinnerJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEBE0
// Name: _dynamic_initializer_for__g_CDmeSkinnerJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinnerJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinnerJoint_Helper,
           classname: "DmeSkinnerJoint",
           pFactory: &g_CDmeSkinnerJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EEC30
// Name: _dynamic_initializer_for__g_CDmeSkinner_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinner_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEC40
// Name: _dynamic_initializer_for__g_CDmeSkinner_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinner_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinner_Helper,
           classname: "DmeSkinner",
           pFactory: &g_CDmeSkinner_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A80
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinnerJoint_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A90
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinner_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3AA0
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinnerVolume_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050BFF0
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x00514BC0
// Name: protected: void CDmeSkinnerVolume::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerVolume::OnConstruction(CDmeSkinnerVolume *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_mMatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "matrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_mMatrix);
  this->m_flStrength.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "strength",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flStrength);
  this->m_flFalloff.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "falloff",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flFalloff);
  this->m_nFalloffType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "falloffType",
                                        type: AT_INT,
                                        pMemory: &this->m_nFalloffType);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "powerY", type: AT_FLOAT, pMemory: &this->m_flPowerY);
  this->m_flPowerY.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "powerXZ", type: AT_FLOAT, pMemory: &this->m_flPowerXZ);
  this->m_flPowerXZ.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00514D80
// Name: protected: CDmeSkinnerVolume::CDmeSkinnerVolume(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSkinnerVolume *__thiscall CDmeSkinnerVolume::CDmeSkinnerVolume(
        CDmeSkinnerVolume *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSkinnerVolume_vtbl *)&CDmeSkinnerVolume::`vftable';
  this->m_mMatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_mMatrix.m_Storage);
  this->m_flStrength.m_pAttribute = nullptr;
  this->m_flStrength.m_Storage = 0.0;
  this->m_flFalloff.m_pAttribute = nullptr;
  this->m_flFalloff.m_Storage = 0.0;
  this->m_nFalloffType.m_pAttribute = nullptr;
  this->m_nFalloffType.m_Storage = 0;
  this->m_flPowerY.m_pAttribute = nullptr;
  this->m_flPowerY.m_Storage = 0.0;
  this->m_flPowerXZ.m_pAttribute = nullptr;
  this->m_flPowerXZ.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00514E40
// Name: public: virtual bool CDmeSkinnerVolume::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinnerVolume::IsA(CDmeSkinnerVolume *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinnerVolume::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514E70
// Name: public: virtual int CDmeSkinnerVolume::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerVolume::GetInheritanceDepth(CDmeSkinnerVolume *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinnerVolume::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514EF0
// Name: protected: virtual void CDmeSkinnerVolume::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerVolume::PerformConstruction(CDmeSkinnerVolume *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSkinnerVolume::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00514FC0
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformConstruction(CDmeRigHandle *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00514FD0
// Name: public: virtual bool CDmeDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsA(CDmeDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515000
// Name: public: virtual int CDmeDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::GetInheritanceDepth(CDmeDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515080
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005150F0
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515120
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005151C0
// Name: protected: CDmeSkinnerJoint::CDmeSkinnerJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSkinnerJoint *__thiscall CDmeSkinnerJoint::CDmeSkinnerJoint(
        CDmeSkinnerJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeSkinnerJoint::`vftable';
  this->m_mBindWorldMatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_mBindWorldMatrix.m_Storage);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eVolumeList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00515260
// Name: public: virtual bool CDmeSkinnerJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinnerJoint::IsA(CDmeSkinnerJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinnerJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005152A0
// Name: public: virtual int CDmeSkinnerJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerJoint::GetInheritanceDepth(CDmeSkinnerJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinnerJoint::m_classType.u.m_Id )
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
// Address: 0x00515300
// Name: protected: virtual void CDmeSkinnerJoint::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerJoint::PerformDestruction(CDmeSkinnerJoint *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00515320
// Name: protected: virtual int CDmeSkinnerJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerJoint::AllocatedSize(CDmeSkinnerJoint *this)
{
  return 236;
}

//------------------------------------------------------------------------------
// Address: 0x00515330
// Name: protected: virtual void CDmeSkinnerJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerJoint::PerformConstruction(CDmeSkinnerJoint *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  this->m_mBindWorldMatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "bindWorldMatrix",
                                            type: AT_VMATRIX,
                                            pMemory: &this->m_mBindWorldMatrix);
  this->m_eVolumeList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "volumeList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eVolumeList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eVolumeList.m_pAttribute, typeSymbol: CDmeSkinnerVolume::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005153F0
// Name: public: virtual bool CDmeSkinner::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinner::IsA(CDmeSkinner *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinner::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515420
// Name: public: virtual int CDmeSkinner::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinner::GetInheritanceDepth(CDmeSkinner *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinner::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515470
// Name: protected: virtual int CDmeSkinner::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinner::AllocatedSize(CDmeRigHandle *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x00516A10
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AE120
// Name: _dynamic_initializer_for__CDmeSkinnerVolume::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinnerVolume::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinnerVolume::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinnerVolume pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE180
// Name: _dynamic_initializer_for__CDmeSkinnerJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinnerJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinnerJoint::s_Allocator,
    blockSize: 236,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinnerJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE1E0
// Name: _dynamic_initializer_for__CDmeSkinner::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinner::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinner::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinner pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEBC0
// Name: _dynamic_initializer_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDag::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEC20
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x006B04D0
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4490
// Name: _dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinnerVolume::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B44A0
// Name: _dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinnerJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B44B0
// Name: _dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinner::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4810
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4820
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x006B50D0
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00514C90
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AE150
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolume_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinnerVolume_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE160
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolume_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinnerVolume_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinnerVolume_Helper,
           classname: "DmeSkinnerVolume",
           pFactory: &g_CDmeSkinnerVolume_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE1B0
// Name: _dynamic_initializer_for__g_CDmeSkinnerJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinnerJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE1C0
// Name: _dynamic_initializer_for__g_CDmeSkinnerJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinnerJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinnerJoint_Helper,
           classname: "DmeSkinnerJoint",
           pFactory: &g_CDmeSkinnerJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE210
// Name: _dynamic_initializer_for__g_CDmeSkinner_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinner_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE220
// Name: _dynamic_initializer_for__g_CDmeSkinner_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinner_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinner_Helper,
           classname: "DmeSkinner",
           pFactory: &g_CDmeSkinner_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AEBF0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEC00
// Name: _dynamic_initializer_for__g_CDmeDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDag_Helper,
           classname: "DmeDag",
           pFactory: &g_CDmeDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AEC30
// Name: _dynamic_initializer_for__s_MakefileUtils__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_MakefileUtils__()
{
  CDmeMakefileUtils::CDmeMakefileUtils(this: &s_MakefileUtils);
  return atexit(func: dynamic_atexit_destructor_for__s_MakefileUtils__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0500
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0510
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B44C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSkinnerJoint_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B44D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSkinner_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B44E0
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSkinnerVolume_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4830
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4840
// Name: _dynamic_atexit_destructor_for__s_MakefileUtils__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_MakefileUtils__()
{
  s_MakefileUtils.__vftable = (CDmeMakefileUtils_vtbl *)&CDmeMakefileUtils::`vftable';
  CUtlVector<CDmeMakefileUtils::CompileInfo_t,CUtlMemory<CDmeMakefileUtils::CompileInfo_t,int>>::Purge(this: &s_MakefileUtils.m_CompileTasks);
  if ( s_MakefileUtils.m_CompileTasks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_MakefileUtils.m_CompileTasks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_MakefileUtils.m_CompileTasks.m_Memory.m_pMemory);
      s_MakefileUtils.m_CompileTasks.m_Memory.m_pMemory = nullptr;
    }
    s_MakefileUtils.m_CompileTasks.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B50E0
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DA980
// Name: protected: virtual int CDmeSkinner::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinner::AllocatedSize(CDmeSkinner *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x004E43E0
// Name: protected: void CDmeSkinnerVolume::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerVolume::OnConstruction(CDmeSkinnerVolume *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_mMatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "matrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_mMatrix);
  this->m_flStrength.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "strength",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flStrength);
  this->m_flFalloff.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "falloff",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flFalloff);
  this->m_nFalloffType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "falloffType",
                                        type: AT_INT,
                                        pMemory: &this->m_nFalloffType);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "powerY", type: AT_FLOAT, pMemory: &this->m_flPowerY);
  this->m_flPowerY.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "powerXZ", type: AT_FLOAT, pMemory: &this->m_flPowerXZ);
  this->m_flPowerXZ.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004E45A0
// Name: protected: CDmeSkinnerVolume::CDmeSkinnerVolume(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSkinnerVolume *__thiscall CDmeSkinnerVolume::CDmeSkinnerVolume(
        CDmeSkinnerVolume *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSkinnerVolume_vtbl *)&CDmeSkinnerVolume::`vftable';
  this->m_mMatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_mMatrix.m_Storage);
  this->m_flStrength.m_pAttribute = nullptr;
  this->m_flStrength.m_Storage = 0.0;
  this->m_flFalloff.m_pAttribute = nullptr;
  this->m_flFalloff.m_Storage = 0.0;
  this->m_nFalloffType.m_pAttribute = nullptr;
  this->m_nFalloffType.m_Storage = 0;
  this->m_flPowerY.m_pAttribute = nullptr;
  this->m_flPowerY.m_Storage = 0.0;
  this->m_flPowerXZ.m_pAttribute = nullptr;
  this->m_flPowerXZ.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E4660
// Name: public: virtual bool CDmeSkinnerVolume::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinnerVolume::IsA(CDmeSkinnerVolume *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinnerVolume::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4690
// Name: public: virtual int CDmeSkinnerVolume::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerVolume::GetInheritanceDepth(CDmeSkinnerVolume *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinnerVolume::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4710
// Name: protected: virtual void CDmeSkinnerVolume::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerVolume::PerformConstruction(CDmeSkinnerVolume *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSkinnerVolume::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E47E0
// Name: protected: CDmeSkinnerJoint::CDmeSkinnerJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSkinnerJoint *__thiscall CDmeSkinnerJoint::CDmeSkinnerJoint(
        CDmeSkinnerJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeDag::`vftable';
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
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->__vftable = (CDmeSkinnerJoint_vtbl *)&CDmeSkinnerJoint::`vftable';
  this->m_mBindWorldMatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_mBindWorldMatrix.m_Storage);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eVolumeList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E4880
// Name: public: virtual bool CDmeSkinnerJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinnerJoint::IsA(CDmeSkinnerJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinnerJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E48C0
// Name: public: virtual int CDmeSkinnerJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerJoint::GetInheritanceDepth(CDmeSkinnerJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinnerJoint::m_classType.u.m_Id )
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
// Address: 0x004E4920
// Name: protected: virtual void CDmeSkinnerJoint::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerJoint::PerformDestruction(CDmeSkinnerJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004E4940
// Name: protected: virtual int CDmeSkinnerJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinnerJoint::AllocatedSize(CDmeSkinnerJoint *this)
{
  return 236;
}

//------------------------------------------------------------------------------
// Address: 0x004E4950
// Name: protected: virtual void CDmeSkinnerJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSkinnerJoint::PerformConstruction(CDmeSkinnerJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  this->m_mBindWorldMatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "bindWorldMatrix",
                                            type: AT_VMATRIX,
                                            pMemory: &this->m_mBindWorldMatrix);
  this->m_eVolumeList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "volumeList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eVolumeList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eVolumeList.m_pAttribute, typeSymbol: CDmeSkinnerVolume::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E4A10
// Name: public: virtual bool CDmeSkinner::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSkinner::IsA(CDmeSkinner *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSkinner::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4A40
// Name: public: virtual int CDmeSkinner::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSkinner::GetInheritanceDepth(CDmeSkinner *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSkinner::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E77A0
// Name: _dynamic_initializer_for__CDmeSkinnerVolume::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinnerVolume::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinnerVolume::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinnerVolume pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7800
// Name: _dynamic_initializer_for__CDmeSkinnerJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinnerJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinnerJoint::s_Allocator,
    blockSize: 236,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinnerJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7860
// Name: _dynamic_initializer_for__CDmeSkinner::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSkinner::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSkinner::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSkinner pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC830
// Name: _dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinnerVolume::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinnerVolume::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC840
// Name: _dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinnerJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinnerJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC850
// Name: _dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSkinner::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSkinner::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004E44B0
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E77D0
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolume_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinnerVolume_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E77E0
// Name: _dynamic_initializer_for__g_CDmeSkinnerVolume_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinnerVolume_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinnerVolume_Helper,
           classname: "DmeSkinnerVolume",
           pFactory: &g_CDmeSkinnerVolume_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7830
// Name: _dynamic_initializer_for__g_CDmeSkinnerJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinnerJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7840
// Name: _dynamic_initializer_for__g_CDmeSkinnerJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinnerJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinnerJoint_Helper,
           classname: "DmeSkinnerJoint",
           pFactory: &g_CDmeSkinnerJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7890
// Name: _dynamic_initializer_for__g_CDmeSkinner_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSkinner_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E78A0
// Name: _dynamic_initializer_for__g_CDmeSkinner_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSkinner_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSkinner_Helper,
           classname: "DmeSkinner",
           pFactory: &g_CDmeSkinner_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC860
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinnerJoint_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinnerJoint_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC870
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinner_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinner_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC880
// Name: _dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSkinnerVolume_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSkinnerVolume_Factory.m_CallBackList);
}

} // namespace studiomdl
