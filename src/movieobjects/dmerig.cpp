// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmerig.cpp
// Functions: 19
// ============================================================

#include "movieobjects\dmerig.h"

//------------------------------------------------------------------------------
// Address: 0x005652B0
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00565420
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565450
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565490
// Name: protected: virtual int CDmeRigAnimSetElements::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x005654A0
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005654F0
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00565560
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565590
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005655E0
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005AEC20
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEC80
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0AB0
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0AC0
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AEC50
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEC60
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AECB0
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AECC0
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0AD0
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0AE0
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005C2840
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005C2970
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C29A0
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C29E0
// Name: protected: virtual int CDmeRigAnimSetElements::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x005C29F0
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005C2A40
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005C2AB0
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C2AE0
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C2B30
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006805E0
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00680640
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00683060
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00683070
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00680610
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680620
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00680670
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680680
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00683080
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683090
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10593B00
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10593C30
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10593C60
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10593CA0
// Name: protected: virtual int CDmeRigAnimSetElements::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x10593CB0
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x10593D00
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10593D70
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10593DA0
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10593E00
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x105C94D0
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 0x84u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9530
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD9B0
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CD9C0
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9500
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9510
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9560
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9570
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD9D0
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CD9E0
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00565530
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00565660
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565690
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005656E0
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00565730
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005657A0
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005657D0
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565820
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0059D050
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D0B0
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F800
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059F810
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D080
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D090
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059D0E0
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D0F0
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F820
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059F830
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005AE5E0
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005AE710
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE740
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE790
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AE7E0
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AE850
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE880
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE8D0
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005F1CE0
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1D40
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B10
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B20
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F1D10
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1D20
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1D70
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1D80
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B30
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B40
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004751A0
// Name: protected: virtual int CDmeRigAnimSetElements::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x00529950
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00529A80
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529AB0
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529AF0
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00529B40
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00529BB0
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529BE0
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529C30
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0056D1C0
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D220
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F240
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056F250
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056D1F0
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D200
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056D250
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D260
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F260
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F270
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00478ED0
// Name: protected: virtual int CDmeRigAnimSetElements::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x00531A50
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00531AC0
// Name: private: int CDmeRig::FindAnimSetElementList(class CDmeAnimationSet const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::FindAnimSetElementList(CDmeRig *this, const CDmeAnimationSet *pAnimationSet)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nAnimSets; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nAnimSets = this->m_AnimSetList.m_Storage.m_Size;
  if ( nAnimSets <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_AnimSetList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmeRigAnimSetElements::m_classType)
      && g_pDataModel->GetElement(this: g_pDataModel, a2: v5[1].__vftable) == pAnimationSet )
    {
      break;
    }
    if ( ++v3 >= nAnimSets )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00531B50
// Name: private: void CDmeRig::SetHiddenControlGroupVisibility(class CDmeRigAnimSetElements __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::SetHiddenControlGroupVisibility(
        CDmeRig *this,
        CDmeRigAnimSetElements *pAnimSetElements,
        bool bVisible)
{
  CDmeAnimationSet *v4; // ebx
  int v5; // esi
  const char *m_pAsString; // eax
  CDmeControlGroup *ControlGroup; // eax
  int nNumGroups; // [esp+10h] [ebp+8h]

  v4 = (CDmeAnimationSet *)g_pDataModel->GetElement(
                             this: g_pDataModel,
                             a2: pAnimSetElements->m_AnimationSet.m_Storage.m_Handle);
  if ( v4 != nullptr )
  {
    v5 = 0;
    nNumGroups = pAnimSetElements->m_HiddenGroups.m_Storage.m_Size;
    if ( nNumGroups > 0 )
    {
      do
      {
        m_pAsString = pAnimSetElements->m_HiddenGroups.m_Storage.m_Memory.m_pMemory[v5].u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pParentName;
        ControlGroup = CDmeAnimationSet::FindControlGroup(this: v4, pControlGroupName: m_pAsString);
        if ( ControlGroup != nullptr )
          CDmeControlGroup::SetVisible(this: ControlGroup, bVisible);
        ++v5;
      }
      while ( v5 < nNumGroups );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531BC0
// Name: public: void CDmeRig::HideHiddenControlGroups(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::HideHiddenControlGroups(CDmeRig *this, CDmeAnimationSet *pAnimationSet)
{
  int AnimSetElementList; // eax
  CDmElement *v4; // eax
  CDmeRigAnimSetElements *v5; // esi

  AnimSetElementList = CDmeRig::FindAnimSetElementList(this, pAnimationSet);
  if ( AnimSetElementList != -1 )
  {
    v4 = g_pDataModel->GetElement(
           this: g_pDataModel,
           a2: this->m_AnimSetList.m_Storage.m_Memory.m_pMemory[AnimSetElementList]);
    v5 = (CDmeRigAnimSetElements *)v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeRigAnimSetElements::m_classType) )
      CDmeRig::SetHiddenControlGroupVisibility(this, pAnimSetElements: v5, bVisible: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531DD0
// Name: void CollectRigsOnAnimationSet(class CDmeAnimationSet __near *,class CUtlVector<class CDmeRig __near *,class CUtlMemory<class CDmeRig __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectRigsOnAnimationSet(
        CDmeAnimationSet *pAnimSet,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *rigList)
{
  CUtlSymbolLarge *v2; // eax
  CDmeFilmClip *Referring; // eax
  CDmeDag *Scene; // eax
  int i; // esi
  CDmeRig *v6; // ecx
  _BYTE v7[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v7, a3: "animationSets");
  Referring = FindReferringElement<CDmeFilmClip>(
                pElement: (CExpressionCalculator *)pAnimSet,
                symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    Scene = CDmeFilmClip::GetScene(this: Referring, bCreateIfNull: 0);
    if ( Scene != nullptr && pAnimSet != nullptr )
    {
      CDmeDag::FindChildrenOfType<CDmeRig>(this: Scene, children: rigList);
      for ( i = (int)rigList[1].m_pMemory - 1; i >= 0; --i )
      {
        v6 = (CDmeRig *)rigList->m_pMemory[i];
        if ( v6 == nullptr || CDmeRig::FindAnimSetElementList(this: v6, pAnimationSet: pAnimSet) == -1 )
        {
          if ( (int)rigList[1].m_pMemory - i - 1 > 0 )
            _V_memmove(
              dest: &rigList->m_pMemory[i],
              src: &rigList->m_pMemory[i + 1],
              count: 4 * ((int)rigList[1].m_pMemory - i - 1));
          --rigList[1].m_pMemory;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531E80
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00531EB0
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00531EF0
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00531F40
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00531FB0
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00531FE0
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532030
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0057D2E0
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D340
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F370
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F380
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D310
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D320
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D370
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D380
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F390
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F3A0
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005F0040
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005F0170
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F01A0
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F01E0
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F0230
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005F02A0
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F02D0
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F0320
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006B2440
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B24A0
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5B60
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5B70
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B2470
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2480
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B24D0
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B24E0
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5B80
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5B90
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00479C30
// Name: protected: virtual int CDmeRigAnimSetElements::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x00532BE0
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00532C50
// Name: private: int CDmeRig::FindAnimSetElementList(class CDmeAnimationSet const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::FindAnimSetElementList(CDmeRig *this, const CDmeAnimationSet *pAnimationSet)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nAnimSets; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nAnimSets = this->m_AnimSetList.m_Storage.m_Size;
  if ( nAnimSets <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_AnimSetList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmeRigAnimSetElements::m_classType)
      && g_pDataModel->GetElement(this: g_pDataModel, a2: v5[1].__vftable) == pAnimationSet )
    {
      break;
    }
    if ( ++v3 >= nAnimSets )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00532CE0
// Name: private: void CDmeRig::SetHiddenControlGroupVisibility(class CDmeRigAnimSetElements __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::SetHiddenControlGroupVisibility(
        CDmeRig *this,
        CDmeRigAnimSetElements *pAnimSetElements,
        bool bVisible)
{
  CDmeAnimationSet *v4; // ebx
  int v5; // esi
  const char *m_pAsString; // eax
  CDmeControlGroup *ControlGroup; // eax
  int nNumGroups; // [esp+10h] [ebp+8h]

  v4 = (CDmeAnimationSet *)g_pDataModel->GetElement(
                             this: g_pDataModel,
                             a2: pAnimSetElements->m_AnimationSet.m_Storage.m_Handle);
  if ( v4 != nullptr )
  {
    v5 = 0;
    nNumGroups = pAnimSetElements->m_HiddenGroups.m_Storage.m_Size;
    if ( nNumGroups > 0 )
    {
      do
      {
        m_pAsString = pAnimSetElements->m_HiddenGroups.m_Storage.m_Memory.m_pMemory[v5].u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pch;
        ControlGroup = CDmeAnimationSet::FindControlGroup(this: v4, pControlGroupName: m_pAsString);
        if ( ControlGroup != nullptr )
          CDmeControlGroup::SetVisible(this: ControlGroup, bVisible);
        ++v5;
      }
      while ( v5 < nNumGroups );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532D50
// Name: public: void CDmeRig::HideHiddenControlGroups(class CDmeAnimationSet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::HideHiddenControlGroups(CDmeRig *this, CDmeAnimationSet *pAnimationSet)
{
  int AnimSetElementList; // eax
  CDmElement *v4; // eax
  CDmeRigAnimSetElements *v5; // esi

  AnimSetElementList = CDmeRig::FindAnimSetElementList(this, pAnimationSet);
  if ( AnimSetElementList != -1 )
  {
    v4 = g_pDataModel->GetElement(
           this: g_pDataModel,
           a2: this->m_AnimSetList.m_Storage.m_Memory.m_pMemory[AnimSetElementList]);
    v5 = (CDmeRigAnimSetElements *)v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeRigAnimSetElements::m_classType) )
      CDmeRig::SetHiddenControlGroupVisibility(this, pAnimSetElements: v5, bVisible: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532F60
// Name: void CollectRigsOnAnimationSet(class CDmeAnimationSet __near *,class CUtlVector<class CDmeRig __near *,class CUtlMemory<class CDmeRig __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectRigsOnAnimationSet(
        CDmeAnimationSet *pAnimSet,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *rigList)
{
  CUtlSymbolLarge *v2; // eax
  CDmeFilmClip *Referring; // eax
  CDmeDag *Scene; // eax
  int i; // esi
  CDmeRig *v6; // ecx
  _BYTE v7[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v7, a3: "animationSets");
  Referring = FindReferringElement<CDmeFilmClip>(
                pElement: (CExpressionCalculator *)pAnimSet,
                symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    Scene = CDmeFilmClip::GetScene(this: Referring, bCreateIfNull: 0);
    if ( Scene != nullptr && pAnimSet != nullptr )
    {
      CDmeDag::FindChildrenOfType<CDmeRig>(this: Scene, children: rigList);
      for ( i = (int)rigList[1].m_pMemory - 1; i >= 0; --i )
      {
        v6 = (CDmeRig *)rigList->m_pMemory[i];
        if ( v6 == nullptr || CDmeRig::FindAnimSetElementList(this: v6, pAnimationSet: pAnimSet) == -1 )
        {
          if ( (int)rigList[1].m_pMemory - i - 1 > 0 )
            _V_memmove(
              dest: &rigList->m_pMemory[i],
              src: &rigList->m_pMemory[i + 1],
              count: 4 * ((int)rigList[1].m_pMemory - i - 1));
          --rigList[1].m_pMemory;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533010
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533040
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533080
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005330D0
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00533140
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533170
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005331C0
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0057F2C0
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F320
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581350
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00581360
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F2F0
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F300
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F350
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F360
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00581370
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581380
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A7530
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005A7660
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7690
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A76D0
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction();
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005A7720
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A7790
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A77C0
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7830
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EAB90
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EABF0
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9B0
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9C0
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EABC0
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EABD0
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EAC20
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAC30
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9D0
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9E0
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x005382C0
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005383F0
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00538420
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00538460
// Name: protected: virtual int CDmeRigAnimSetElements::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x00538470
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005384C0
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00538530
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00538560
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005385B0
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB00
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB60
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA40
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA50
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB30
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB40
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB90
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CBA0
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA60
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA70
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0063B380
// Name: protected: void CDmeRigAnimSetElements::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::OnConstruction(CDmeRigAnimSetElements *this)
{
  CDmaElement<CDmeAnimationSet> *p_m_AnimationSet; // edi

  p_m_AnimationSet = &this->m_AnimationSet;
  this->m_AnimationSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "animationSet",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_AnimationSet);
  CDmAttribute::SetElementTypeSymbol(this: p_m_AnimationSet->m_pAttribute, typeSymbol: CDmeAnimationSet::m_classType);
  this->m_ElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "elementList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_ElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ElementList.m_pAttribute, typeSymbol: CDmElement::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_HiddenGroups,
    pOwner: this,
    pAttributeName: "hiddenGroups",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0063B4B0
// Name: public: virtual bool CDmeRigAnimSetElements::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRigAnimSetElements::IsA(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063B4E0
// Name: public: virtual int CDmeRigAnimSetElements::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRigAnimSetElements::GetInheritanceDepth(CDmeRigAnimSetElements *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRigAnimSetElements::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063B520
// Name: protected: virtual void CDmeRigAnimSetElements::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRigAnimSetElements::PerformConstruction(CDmeRigAnimSetElements *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeRigAnimSetElements::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063B570
// Name: protected: CDmeRig::CDmeRig(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeRig *__thiscall CDmeRig::CDmeRig(
        CDmeRig *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeRig_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_pAttribute = nullptr;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeRig_vtbl *)&CDmeRig::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_AnimSetList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063B5E0
// Name: public: virtual bool CDmeRig::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeRig::IsA(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063B610
// Name: public: virtual int CDmeRig::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeRig::GetInheritanceDepth(CDmeRig *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeRig::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063B660
// Name: protected: virtual void CDmeRig::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRig::PerformConstruction(CDmeRig *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  this->m_AnimSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "animSetList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_AnimSetList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimSetList.m_pAttribute,
    typeSymbol: CDmeRigAnimSetElements::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006BAA70
// Name: _dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRigAnimSetElements::s_Allocator,
    blockSize: 0x84u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRigAnimSetElements pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAAD0
// Name: _dynamic_initializer_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeRig::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeRig pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeRig::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD860
// Name: _dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRigAnimSetElements::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRigAnimSetElements::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD870
// Name: _dynamic_atexit_destructor_for__CDmeRig::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeRig::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeRig::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BAAA0
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRigAnimSetElements_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAAB0
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRigAnimSetElements_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRigAnimSetElements_Helper,
           classname: "DmeRigAnimSetElements",
           pFactory: &g_CDmeRigAnimSetElements_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BAB00
// Name: _dynamic_initializer_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeRig_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeRig_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAB10
// Name: _dynamic_initializer_for__g_CDmeRig_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeRig_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeRig_Helper,
           classname: "DmeRig",
           pFactory: &g_CDmeRig_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD880
// Name: _dynamic_atexit_destructor_for__g_CDmeRig_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRig_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeRig_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD890
// Name: _dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeRigAnimSetElements_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeRigAnimSetElements_Factory.m_CallBackList);
}

} // namespace vmap
