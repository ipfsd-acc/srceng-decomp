// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeboneflexdriver.cpp
// Functions: 27
// ============================================================

#include "mdlobjects\dmeboneflexdriver.h"

//------------------------------------------------------------------------------
// Address: 0x004A4A60
// Name: public: virtual class CDmAttribute __near * CDmeBoneFlexDriverList::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverList::GetListAttr(CDmeLogLayer *this)
{
  return this->m_times.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004A6780
// Name: protected: void CDmeBoneFlexDriverControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverControl::OnConstruction(CDmeBoneFlexDriverControl *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_sFlexControllerName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "flexControllerName",
                                               type: AT_STRING,
                                               pMemory: &this->m_sFlexControllerName);
  this->m_nBoneComponent.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "boneComponent",
                                          type: AT_INT,
                                          pMemory: &this->m_nBoneComponent);
  value = 0.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "min", type: AT_FLOAT, pMemory: &this->m_flMin);
  this->m_flMin.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "max", type: AT_FLOAT, pMemory: &this->m_flMax);
  this->m_flMax.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004A68A0
// Name: public: virtual bool CDmeBoneFlexDriverControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriverControl::IsA(CDmeBoneFlexDriverControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriverControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A68D0
// Name: public: virtual int CDmeBoneFlexDriverControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverControl::GetInheritanceDepth(
        CDmeBoneFlexDriverControl *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriverControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6990
// Name: protected: virtual void CDmeBoneFlexDriverControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverControl::PerformConstruction(CDmeBoneFlexDriverControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBoneFlexDriverControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A6A60
// Name: public: virtual bool CDmeBoneFlexDriverList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriverList::IsA(CDmeBoneFlexDriverList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriverList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6A90
// Name: public: virtual int CDmeBoneFlexDriverList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverList::GetInheritanceDepth(CDmeBoneFlexDriverList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriverList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6AE0
// Name: protected: virtual void CDmeBoneFlexDriverList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverList::PerformConstruction(CDmeBoneFlexDriverList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eBoneFlexDriverList.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "boneFlexDriverList",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_eBoneFlexDriverList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eBoneFlexDriverList.m_pAttribute,
    typeSymbol: CDmeBoneFlexDriver::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004A6BC0
// Name: public: virtual bool CDmeBoneFlexDriver::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriver::IsA(CDmeBoneFlexDriver *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriver::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6BF0
// Name: public: virtual int CDmeBoneFlexDriver::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriver::GetInheritanceDepth(CDmeBoneFlexDriver *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriver::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6C40
// Name: public: virtual class CDmAttribute __near * CDmeBoneFlexDriver::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeBoneFlexDriver::GetListAttr(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x004A6C50
// Name: protected: virtual void CDmeBoneFlexDriver::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriver::PerformConstruction(CDmeBoneFlexDriver *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_eControlList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "controlList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eControlList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eControlList.m_pAttribute,
    typeSymbol: CDmeBoneFlexDriverControl::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0059A080
// Name: _dynamic_initializer_for__CDmeBoneFlexDriverControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriverControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriverControl::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriverControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A0E0
// Name: _dynamic_initializer_for__CDmeBoneFlexDriver::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriver::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriver::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriver pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A140
// Name: _dynamic_initializer_for__CDmeBoneFlexDriverList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriverList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriverList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriverList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E7E0
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriverControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E7F0
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriver::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E800
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriverList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A0B0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A0C0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriverControl_Helper,
           classname: "DmeBoneFlexDriverControl",
           pFactory: &g_CDmeBoneFlexDriverControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A110
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriver_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriver_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A120
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriver_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriver_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriver_Helper,
           classname: "DmeBoneFlexDriver",
           pFactory: &g_CDmeBoneFlexDriver_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A170
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriverList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A180
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriverList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriverList_Helper,
           classname: "DmeBoneFlexDriverList",
           pFactory: &g_CDmeBoneFlexDriverList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E810
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriver_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E820
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriverList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E830
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriverControl_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E67C0
// Name: public: virtual class CDmAttribute __near * CDmeBoneFlexDriverList::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverList::GetListAttr(CDmeLogLayer *this)
{
  return this->m_times.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004EA420
// Name: protected: void CDmeBoneFlexDriverControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverControl::OnConstruction(CDmeBoneFlexDriverControl *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_sFlexControllerName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "flexControllerName",
                                               type: AT_STRING,
                                               pMemory: &this->m_sFlexControllerName);
  this->m_nBoneComponent.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "boneComponent",
                                          type: AT_INT,
                                          pMemory: &this->m_nBoneComponent);
  value = 0.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "min", type: AT_FLOAT, pMemory: &this->m_flMin);
  this->m_flMin.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "max", type: AT_FLOAT, pMemory: &this->m_flMax);
  this->m_flMax.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004EA4B0
// Name: public: class CDmeBoneFlexDriverControl __near * CDmeBoneFlexDriver::FindOrCreateControl(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeBoneFlexDriverControl *__thiscall CDmeBoneFlexDriver::FindOrCreateControl(
        CDmeBoneFlexDriver *this,
        const char *pszControlName)
{
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v7; // eax
  int v8; // eax

  v3 = 0;
  if ( this->m_eControlList.m_Storage.m_Size <= 0 )
  {
LABEL_8:
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
           a1: g_pDataModel.u,
           a2: CDmeBoneFlexDriverControl::m_classType.u,
           a3: pDeltaStateName,
           a4: this->m_fileId,
           a5: 0);
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: v7);
    v5 = v8;
    if ( v8 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
           a1: v8,
           a2: CDmeBoneFlexDriverControl::m_classType.u) == 0 )
    {
      return nullptr;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pszControlName,
      a3: pszControlName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: *(CDmAttribute **)(v5 + 72),
      value: (const CUtlSymbolLarge *)&pszControlName);
    pszControlName = (const char *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v5);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_eControlList,
      src: (DmElementHandle_t *)&pszControlName);
  }
  else
  {
    while ( 1 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_eControlList.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeBoneFlexDriverControl::m_classType.u) != 0 )
      {
        v6 = *(const char **)(v5 + 68);
        if ( v6 == (const char *)-1 )
          v6 = pDeltaStateName;
        if ( _V_stricmp(s1: pszControlName, s2: v6) == 0 )
          break;
      }
      if ( ++v3 >= this->m_eControlList.m_Storage.m_Size )
        goto LABEL_8;
    }
  }
  return (CDmeBoneFlexDriverControl *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004EA5C0
// Name: public: class CDmeBoneFlexDriver __near * CDmeBoneFlexDriverList::FindOrCreateBoneFlexDriver(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeBoneFlexDriver *__thiscall CDmeBoneFlexDriverList::FindOrCreateBoneFlexDriver(
        CDmeBoneFlexDriverList *this,
        const char *pszBoneName)
{
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v7; // eax
  int v8; // eax

  v3 = 0;
  if ( this->m_eBoneFlexDriverList.m_Storage.m_Size <= 0 )
  {
LABEL_8:
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
           a1: g_pDataModel.u,
           a2: CDmeBoneFlexDriver::m_classType.u,
           a3: pDeltaStateName,
           a4: this->m_fileId,
           a5: 0);
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: v7);
    v5 = v8;
    if ( v8 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
           a1: v8,
           a2: CDmeBoneFlexDriver::m_classType.u) == 0 )
    {
      return nullptr;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pszBoneName,
      a3: pszBoneName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: *(CDmAttribute **)(v5 + 72),
      value: (const CUtlSymbolLarge *)&pszBoneName);
    pszBoneName = (const char *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v5);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_eBoneFlexDriverList,
      src: (DmElementHandle_t *)&pszBoneName);
  }
  else
  {
    while ( 1 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_eBoneFlexDriverList.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeBoneFlexDriver::m_classType.u) != 0 )
      {
        v6 = *(const char **)(v5 + 68);
        if ( v6 == (const char *)-1 )
          v6 = pDeltaStateName;
        if ( _V_stricmp(s1: pszBoneName, s2: v6) == 0 )
          break;
      }
      if ( ++v3 >= this->m_eBoneFlexDriverList.m_Storage.m_Size )
        goto LABEL_8;
    }
  }
  return (CDmeBoneFlexDriver *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004EA760
// Name: public: virtual bool CDmeBoneFlexDriverControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriverControl::IsA(CDmeBoneFlexDriverControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriverControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA790
// Name: public: virtual int CDmeBoneFlexDriverControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverControl::GetInheritanceDepth(
        CDmeBoneFlexDriverControl *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriverControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA850
// Name: protected: virtual void CDmeBoneFlexDriverControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverControl::PerformConstruction(CDmeBoneFlexDriverControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBoneFlexDriverControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EA920
// Name: public: virtual bool CDmeBoneFlexDriverList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriverList::IsA(CDmeBoneFlexDriverList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriverList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA950
// Name: public: virtual int CDmeBoneFlexDriverList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverList::GetInheritanceDepth(CDmeBoneFlexDriverList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriverList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA9A0
// Name: protected: virtual void CDmeBoneFlexDriverList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverList::PerformConstruction(CDmeBoneFlexDriverList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eBoneFlexDriverList.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "boneFlexDriverList",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_eBoneFlexDriverList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eBoneFlexDriverList.m_pAttribute,
    typeSymbol: CDmeBoneFlexDriver::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004EAA80
// Name: public: virtual bool CDmeBoneFlexDriver::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriver::IsA(CDmeBoneFlexDriver *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriver::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EAAB0
// Name: public: virtual int CDmeBoneFlexDriver::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriver::GetInheritanceDepth(CDmeBoneFlexDriver *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriver::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EAB10
// Name: public: virtual class CDmAttribute __near * CDmeBoneFlexDriver::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeBoneFlexDriver::GetListAttr(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x004EAB20
// Name: protected: virtual void CDmeBoneFlexDriver::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriver::PerformConstruction(CDmeBoneFlexDriver *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_eControlList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "controlList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eControlList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eControlList.m_pAttribute,
    typeSymbol: CDmeBoneFlexDriverControl::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EE840
// Name: _dynamic_initializer_for__CDmeBoneFlexDriverControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriverControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriverControl::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriverControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE8A0
// Name: _dynamic_initializer_for__CDmeBoneFlexDriver::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriver::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriver::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriver pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE900
// Name: _dynamic_initializer_for__CDmeBoneFlexDriverList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriverList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriverList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriverList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3950
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriverControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3960
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriver::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3970
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriverList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EE870
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE880
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriverControl_Helper,
           classname: "DmeBoneFlexDriverControl",
           pFactory: &g_CDmeBoneFlexDriverControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE8D0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriver_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriver_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE8E0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriver_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriver_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriver_Helper,
           classname: "DmeBoneFlexDriver",
           pFactory: &g_CDmeBoneFlexDriver_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE930
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriverList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE940
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriverList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriverList_Helper,
           classname: "DmeBoneFlexDriverList",
           pFactory: &g_CDmeBoneFlexDriverList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3980
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriver_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3990
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriverList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F39A0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriverControl_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005162C0
// Name: protected: void CDmeBoneFlexDriverControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverControl::OnConstruction(CDmeBoneFlexDriverControl *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_sFlexControllerName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "flexControllerName",
                                               type: AT_STRING,
                                               pMemory: &this->m_sFlexControllerName);
  this->m_nBoneComponent.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "boneComponent",
                                          type: AT_INT,
                                          pMemory: &this->m_nBoneComponent);
  value = 0.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "min", type: AT_FLOAT, pMemory: &this->m_flMin);
  this->m_flMin.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "max", type: AT_FLOAT, pMemory: &this->m_flMax);
  this->m_flMax.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005163E0
// Name: public: virtual bool CDmeBoneFlexDriverControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriverControl::IsA(CDmeBoneFlexDriverControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriverControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516410
// Name: public: virtual int CDmeBoneFlexDriverControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverControl::GetInheritanceDepth(
        CDmeBoneFlexDriverControl *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriverControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005164E0
// Name: protected: virtual void CDmeBoneFlexDriverControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverControl::PerformConstruction(CDmeBoneFlexDriverControl *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeBoneFlexDriverControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005165B0
// Name: public: virtual bool CDmeBoneFlexDriverList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriverList::IsA(CDmeBoneFlexDriverList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriverList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005165E0
// Name: public: virtual int CDmeBoneFlexDriverList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverList::GetInheritanceDepth(CDmeBoneFlexDriverList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriverList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516630
// Name: protected: virtual void CDmeBoneFlexDriverList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverList::PerformConstruction(CDmeBoneFlexDriverList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_eBoneFlexDriverList.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "boneFlexDriverList",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_eBoneFlexDriverList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eBoneFlexDriverList.m_pAttribute,
    typeSymbol: CDmeBoneFlexDriver::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00516710
// Name: public: virtual bool CDmeBoneFlexDriver::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriver::IsA(CDmeBoneFlexDriver *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriver::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516740
// Name: public: virtual int CDmeBoneFlexDriver::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriver::GetInheritanceDepth(CDmeBoneFlexDriver *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriver::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516790
// Name: public: virtual class CDmAttribute __near * CDmeBoneFlexDriver::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeBoneFlexDriver::GetListAttr(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005167A0
// Name: protected: virtual void CDmeBoneFlexDriver::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriver::PerformConstruction(CDmeBoneFlexDriver *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_eControlList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "controlList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eControlList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eControlList.m_pAttribute,
    typeSymbol: CDmeBoneFlexDriverControl::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0053BCD0
// Name: public: virtual class CDmAttribute __near * CDmeBoneFlexDriverList::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall CDmeBoneFlexDriverList::GetListAttr(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x006AE480
// Name: _dynamic_initializer_for__CDmeBoneFlexDriverControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriverControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriverControl::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriverControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE4E0
// Name: _dynamic_initializer_for__CDmeBoneFlexDriver::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriver::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriver::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriver pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE540
// Name: _dynamic_initializer_for__CDmeBoneFlexDriverList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriverList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriverList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriverList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B45B0
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriverControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B45C0
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriver::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B45D0
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriverList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE4B0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE4C0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriverControl_Helper,
           classname: "DmeBoneFlexDriverControl",
           pFactory: &g_CDmeBoneFlexDriverControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE510
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriver_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriver_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE520
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriver_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriver_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriver_Helper,
           classname: "DmeBoneFlexDriver",
           pFactory: &g_CDmeBoneFlexDriver_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE570
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriverList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE580
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriverList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriverList_Helper,
           classname: "DmeBoneFlexDriverList",
           pFactory: &g_CDmeBoneFlexDriverList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B45E0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBoneFlexDriver_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B45F0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBoneFlexDriverList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4600
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBoneFlexDriverControl_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E4060
// Name: public: virtual class CDmAttribute __near * CDmeBoneFlexDriverList::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverList::GetListAttr(CDmeLogLayer *this)
{
  return this->m_times.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004E58F0
// Name: protected: void CDmeBoneFlexDriverControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverControl::OnConstruction(CDmeBoneFlexDriverControl *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_sFlexControllerName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "flexControllerName",
                                               type: AT_STRING,
                                               pMemory: &this->m_sFlexControllerName);
  this->m_nBoneComponent.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "boneComponent",
                                          type: AT_INT,
                                          pMemory: &this->m_nBoneComponent);
  value = 0.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "min", type: AT_FLOAT, pMemory: &this->m_flMin);
  this->m_flMin.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "max", type: AT_FLOAT, pMemory: &this->m_flMax);
  this->m_flMax.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004E5980
// Name: public: class CDmeBoneFlexDriverControl __near * CDmeBoneFlexDriver::FindOrCreateControl(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeBoneFlexDriverControl *__thiscall CDmeBoneFlexDriver::FindOrCreateControl(
        CDmeBoneFlexDriver *this,
        const char *pszControlName)
{
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v7; // eax
  int v8; // eax

  v3 = 0;
  if ( this->m_eControlList.m_Storage.m_Size <= 0 )
  {
LABEL_8:
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
           a1: g_pDataModel.u,
           a2: CDmeBoneFlexDriverControl::m_classType.u,
           a3: pDeltaStateName,
           a4: this->m_fileId,
           a5: 0);
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: v7);
    v5 = v8;
    if ( v8 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
           a1: v8,
           a2: CDmeBoneFlexDriverControl::m_classType.u) == 0 )
    {
      return nullptr;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pszControlName,
      a3: pszControlName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: *(CDmAttribute **)(v5 + 72),
      value: (const CUtlSymbolLarge *)&pszControlName);
    pszControlName = (const char *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v5);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_eControlList,
      src: (DmElementHandle_t *)&pszControlName);
  }
  else
  {
    while ( 1 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_eControlList.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeBoneFlexDriverControl::m_classType.u) != 0 )
      {
        v6 = *(const char **)(v5 + 68);
        if ( v6 == (const char *)-1 )
          v6 = pDeltaStateName;
        if ( _V_stricmp(s1: pszControlName, s2: v6) == 0 )
          break;
      }
      if ( ++v3 >= this->m_eControlList.m_Storage.m_Size )
        goto LABEL_8;
    }
  }
  return (CDmeBoneFlexDriverControl *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004E5A90
// Name: public: class CDmeBoneFlexDriver __near * CDmeBoneFlexDriverList::FindOrCreateBoneFlexDriver(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeBoneFlexDriver *__thiscall CDmeBoneFlexDriverList::FindOrCreateBoneFlexDriver(
        CDmeBoneFlexDriverList *this,
        const char *pszBoneName)
{
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v7; // eax
  int v8; // eax

  v3 = 0;
  if ( this->m_eBoneFlexDriverList.m_Storage.m_Size <= 0 )
  {
LABEL_8:
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
           a1: g_pDataModel.u,
           a2: CDmeBoneFlexDriver::m_classType.u,
           a3: pDeltaStateName,
           a4: this->m_fileId,
           a5: 0);
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: v7);
    v5 = v8;
    if ( v8 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
           a1: v8,
           a2: CDmeBoneFlexDriver::m_classType.u) == 0 )
    {
      return nullptr;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pszBoneName,
      a3: pszBoneName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: *(CDmAttribute **)(v5 + 72),
      value: (const CUtlSymbolLarge *)&pszBoneName);
    pszBoneName = (const char *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v5);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_eBoneFlexDriverList,
      src: (DmElementHandle_t *)&pszBoneName);
  }
  else
  {
    while ( 1 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_eBoneFlexDriverList.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeBoneFlexDriver::m_classType.u) != 0 )
      {
        v6 = *(const char **)(v5 + 68);
        if ( v6 == (const char *)-1 )
          v6 = pDeltaStateName;
        if ( _V_stricmp(s1: pszBoneName, s2: v6) == 0 )
          break;
      }
      if ( ++v3 >= this->m_eBoneFlexDriverList.m_Storage.m_Size )
        goto LABEL_8;
    }
  }
  return (CDmeBoneFlexDriver *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004E5C30
// Name: public: virtual bool CDmeBoneFlexDriverControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriverControl::IsA(CDmeBoneFlexDriverControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriverControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5C60
// Name: public: virtual int CDmeBoneFlexDriverControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverControl::GetInheritanceDepth(
        CDmeBoneFlexDriverControl *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriverControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5D20
// Name: protected: virtual void CDmeBoneFlexDriverControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverControl::PerformConstruction(CDmeBoneFlexDriverControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBoneFlexDriverControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E5DF0
// Name: public: virtual bool CDmeBoneFlexDriverList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriverList::IsA(CDmeBoneFlexDriverList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriverList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5E20
// Name: public: virtual int CDmeBoneFlexDriverList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriverList::GetInheritanceDepth(CDmeBoneFlexDriverList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriverList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5E80
// Name: protected: virtual void CDmeBoneFlexDriverList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriverList::PerformConstruction(CDmeBoneFlexDriverList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eBoneFlexDriverList.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "boneFlexDriverList",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_eBoneFlexDriverList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eBoneFlexDriverList.m_pAttribute,
    typeSymbol: CDmeBoneFlexDriver::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E5F60
// Name: public: virtual bool CDmeBoneFlexDriver::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneFlexDriver::IsA(CDmeBoneFlexDriver *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneFlexDriver::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5F90
// Name: public: virtual int CDmeBoneFlexDriver::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneFlexDriver::GetInheritanceDepth(CDmeBoneFlexDriver *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneFlexDriver::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5FE0
// Name: protected: virtual void CDmeBoneFlexDriver::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneFlexDriver::PerformConstruction(CDmeBoneFlexDriver *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_eControlList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "controlList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eControlList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eControlList.m_pAttribute,
    typeSymbol: CDmeBoneFlexDriverControl::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004EDDD0
// Name: public: virtual class CDmAttribute __near * CDmeBoneFlexDriver::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeBoneFlexDriver::GetListAttr(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005E7B00
// Name: _dynamic_initializer_for__CDmeBoneFlexDriverControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriverControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriverControl::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriverControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7B60
// Name: _dynamic_initializer_for__CDmeBoneFlexDriver::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriver::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriver::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriver pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7BC0
// Name: _dynamic_initializer_for__CDmeBoneFlexDriverList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneFlexDriverList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneFlexDriverList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneFlexDriverList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC950
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriverControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriverControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC960
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriver::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriver::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC970
// Name: _dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneFlexDriverList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneFlexDriverList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7B30
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7B40
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriverControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriverControl_Helper,
           classname: "DmeBoneFlexDriverControl",
           pFactory: &g_CDmeBoneFlexDriverControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7B90
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriver_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriver_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7BA0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriver_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriver_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriver_Helper,
           classname: "DmeBoneFlexDriver",
           pFactory: &g_CDmeBoneFlexDriver_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7BF0
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneFlexDriverList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7C00
// Name: _dynamic_initializer_for__g_CDmeBoneFlexDriverList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneFlexDriverList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneFlexDriverList_Helper,
           classname: "DmeBoneFlexDriverList",
           pFactory: &g_CDmeBoneFlexDriverList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC980
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriver_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriver_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC990
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriverList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC9A0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneFlexDriverControl_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneFlexDriverControl_Factory.m_CallBackList);
}

} // namespace studiomdl
