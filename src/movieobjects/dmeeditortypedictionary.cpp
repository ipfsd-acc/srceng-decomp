// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeeditortypedictionary.cpp
// Functions: 33
// ============================================================

#include "movieobjects\dmeeditortypedictionary.h"

//------------------------------------------------------------------------------
// Address: 0x004AD8F0
// Name: protected: virtual int CDmeEditorAttributeInfo::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::AllocatedSize(CDmeUnpackQuaternionOperator *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x0055C440
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055C5B0
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C5E0
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C6B0
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0055C800
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C830
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C950
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C980
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C9C0
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0055CA40
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055CA70
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055CAC0
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorChoicesInfo *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEditorAttributeInfo::OnConstruction(this);
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Choices.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x005ADF50
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADFB0
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE020
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE080
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0670
// Name: _dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorAttributeInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0680
// Name: _dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0690
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B06A0
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADF80
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADF90
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ADFE0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE000
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE050
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE060
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE0B0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE0C0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B06B0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B06C0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B06D0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B06E0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004FB800
// Name: public: int CDmeEditorChoicesInfo::GetChoiceCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetChoiceCount(CDmeMesh *this)
{
  return this->m_DeltaStates.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005B3530
// Name: public: void CDmeEditorChoicesInfo::SetChoiceType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::SetChoiceType(CDmeEditorChoicesInfo *this, const char *pChoiceType)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pChoiceType, a3: pChoiceType);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_ChoiceType.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x005B3570
// Name: public: char const __near * CDmeEditorAttributeInfo::GetWidgetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorAttributeInfo::GetWidgetName(CDmeEditorAttributeInfo *this)
{
  const char *result; // eax

  result = this->m_Widget.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B3580
// Name: public: char const __near * CDmeEditorChoicesInfo::GetChoiceType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorChoicesInfo::GetChoiceType(CDmeEditorChoicesInfo *this)
{
  const char *result; // eax

  result = this->m_ChoiceType.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B35A0
// Name: public: bool CDmeEditorChoicesInfo::HasChoiceType(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::HasChoiceType(CDmeEditorChoicesInfo *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_ChoiceType.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  return _V_strlen(str: m_pAsString) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x005B35D0
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005B36B0
// Name: protected: void CDmeEditorChoicesInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::OnConstruction(CDmeEditorChoicesInfo *this)
{
  CDmaElementArray<CDmElement> *p_m_Choices; // edi

  p_m_Choices = &this->m_Choices;
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Choices->m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x005B3700
// Name: public: void CDmeEditorType::AddAttributeInfo(char const __near *,class CDmeEditorAttributeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorType::AddAttributeInfo(
        CDmeEditorType *this,
        int pAttributeName,
        CExpressionCalculator *pInfo)
{
  const char *v3; // esi
  CDmAttribute *Attribute; // eax

  v3 = (const char *)pAttributeName;
  if ( _V_stricmp(s1: "name", s2: (const char *)pAttributeName) == 0 )
    v3 = "__name";
  if ( pInfo != nullptr )
    pAttributeName = CCodecBuffer_Block::GetBufferType(this: pInfo);
  else
    pAttributeName = -1;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: v3);
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: v3, type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pAttributeName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B3770
// Name: public: void CDmeEditorTypeDictionary::AddEditorType(class CDmeEditorType __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorTypeDictionary::AddEditorType(
        CDmeEditorTypeDictionary *this,
        CExpressionCalculator *pEditorType)
{
  CExpressionCalculator *v2; // ebx
  const char *m_nAllocationCount; // esi
  CDmAttribute *Attribute; // eax

  v2 = pEditorType;
  m_nAllocationCount = (const char *)pEditorType->m_varNames.m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount == (const char *)-1 )
    m_nAllocationCount = defaultValue;
  if ( CDmElement::HasAttribute(this, pAttributeName: m_nAllocationCount, type: AT_UNKNOWN) )
  {
    _Warning(a1: "Editor type %s is already defined! Ignoring...\n", m_nAllocationCount);
  }
  else
  {
    pEditorType = (CExpressionCalculator *)CCodecBuffer_Block::GetBufferType(this: v2);
    Attribute = CDmElement::FindAttribute(this, pAttributeName: m_nAllocationCount);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: m_nAllocationCount, type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pEditorType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B37E0
// Name: protected: class CDmElement __near * CDmeEditorChoicesInfo::CreateChoice(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeEditorChoicesInfo::CreateChoice(
        CDmeEditorChoicesInfo *this,
        const char *pChoiceString)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CExpressionCalculator *v5; // esi
  CDmAttribute *Attribute; // eax
  CUtlSymbolLarge symbol; // [esp+8h] [ebp-8h] BYREF
  DmElementHandle_t src; // [esp+Ch] [ebp-4h] BYREF

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: defaultValue,
         a4: this->m_fileId,
         a5: nullptr);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = (CExpressionCalculator *)v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
  {
    src = CCodecBuffer_Block::GetBufferType(this: v5);
  }
  else
  {
    v5 = nullptr;
    src = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Choices,
    &src);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &symbol, a3: pChoiceString);
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)v5, pAttributeName: "string");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: (CDmElement *)v5, pAttributeName: "string", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: &symbol);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x005B38B0
// Name: public: char const __near * CDmeEditorChoicesInfo::GetChoiceString(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorChoicesInfo::GetChoiceString(CDmeEditorChoicesInfo *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmElement::m_classType) )
    return CDmElement::GetValueString(this: v3, pAttributeName: "string");
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x005B3A30
// Name: private: class CDmeEditorType __near * CDmeEditorTypeDictionary::GetEditorType(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorType *__thiscall CDmeEditorTypeDictionary::GetEditorType(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement)
{
  const char *ValueString; // eax
  const char *m_pAsString; // esi

  if ( pElement == nullptr )
    return nullptr;
  if ( !CDmElement::HasAttribute(this: pElement, pAttributeName: "editorType", type: AT_UNKNOWN)
    || (ValueString = CDmElement::GetValueString(this: pElement, pAttributeName: "editorType"),
        m_pAsString = ValueString,
        ValueString == nullptr)
    || *ValueString == 0 )
  {
    m_pAsString = defaultValue;
    if ( pElement->m_Type.u.m_Id != -1 )
      m_pAsString = pElement->m_Type.u.m_pAsString;
  }
  if ( m_pAsString != nullptr
    && *m_pAsString != 0
    && CDmElement::HasAttribute(this, pAttributeName: m_pAsString, type: AT_UNKNOWN) )
  {
    return CDmElement::GetValueElement<CDmeEditorType>(this, pAttributeName: m_pAsString);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B3AB0
// Name: public: class CDmeEditorAttributeInfo __near * CDmeEditorTypeDictionary::GetAttributeInfo(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__thiscall CDmeEditorTypeDictionary::GetAttributeInfo(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement,
        const char *pAttributeName)
{
  CDmeEditorAttributeInfo *result; // eax
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // edi

  result = (CDmeEditorAttributeInfo *)CDmeEditorTypeDictionary::GetEditorType(this, pElement);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = pAttributeName;
    if ( _V_stricmp(s1: "name", s2: pAttributeName) == 0 )
      v5 = "__name";
    if ( CDmElement::HasAttribute(this: v4, pAttributeName: v5, type: AT_UNKNOWN) )
      return CDmElement::GetValueElement<CDmeEditorAttributeInfo>(this: v4, pAttributeName: v5);
    else
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B3B10
// Name: public: class CDmeEditorAttributeInfo __near * CDmeEditorTypeDictionary::GetAttributeArrayInfo(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorType *__thiscall CDmeEditorTypeDictionary::GetAttributeArrayInfo(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement,
        const char *pAttributeName)
{
  CDmeEditorType *result; // eax
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // edi
  CDmeEditorAttributeInfo *Value; // eax

  result = CDmeEditorTypeDictionary::GetEditorType(this, pElement);
  v4 = (CDmeEditorAttributeInfo *)result;
  if ( result != nullptr )
  {
    v5 = pAttributeName;
    if ( _V_stricmp(s1: "name", s2: pAttributeName) == 0 )
      v5 = "__name";
    if ( CDmElement::HasAttribute(this: v4, pAttributeName: v5, type: AT_UNKNOWN)
      && (Value = CDmElement::GetValueElement<CDmeEditorAttributeInfo>(this: v4, pAttributeName: v5)) != nullptr )
    {
      return (CDmeEditorType *)g_pDataModel->GetElement(
                                 this: g_pDataModel,
                                 a2: Value->m_ArrayEntries.m_Storage.m_Handle);
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B3DB0
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B3DE0
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B3F00
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B3F30
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0067F800
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F860
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682BA0
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682BB0
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00683410
// Name: _GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_0.m_PanelMessageMapPool);
  CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::RemoveAll(this: &dictionary_0.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_0.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00683450
// Name: _GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CClassMemoryPool<PanelAnimationMap>::Clear(this: &dictionary_1.m_PanelAnimationMapPool);
  CUtlDict<CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::RemoveAll(this: &dictionary_1.m_AnimationMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_1.m_AnimationMaps.m_Elements.m_Tree);
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_1.m_PanelAnimationMapPool);
}

//------------------------------------------------------------------------------
// Address: 0x0067F830
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F840
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F890
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F8A0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682BC0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682BD0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682BE0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682BF0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683430
// Name: _dynamic_atexit_destructor_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KBMgr__()
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(this: &g_KBMgr.m_Bindings);
}

//------------------------------------------------------------------------------
// Address: 0x00683440
// Name: _dynamic_atexit_destructor_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ScriptSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x00683480
// Name: _dynamic_atexit_destructor_for__s_StartDirContexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_StartDirContexts__()
{
  CUtlDict<CUtlString,unsigned short>::RemoveAll(this: &s_StartDirContexts);
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_StartDirContexts.m_Elements.m_Tree);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D4A00
// Name: public: void CDmeEditorChoicesInfo::SetChoiceType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::SetChoiceType(CDmeEditorChoicesInfo *this, const char *pChoiceType)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pChoiceType, a3: pChoiceType);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_ChoiceType.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x104D4A40
// Name: public: char const __near * CDmeEditorAttributeInfo::GetWidgetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorAttributeInfo::GetWidgetName(CDmeEditorAttributeInfo *this)
{
  const char *result; // eax

  result = this->m_Widget.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D4A50
// Name: public: char const __near * CDmeEditorChoicesInfo::GetChoiceType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorChoicesInfo::GetChoiceType(CDmeEditorChoicesInfo *this)
{
  const char *result; // eax

  result = this->m_ChoiceType.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D4A70
// Name: public: bool CDmeEditorChoicesInfo::HasChoiceType(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::HasChoiceType(CDmeEditorChoicesInfo *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_ChoiceType.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  return (int)std::char_traits<char>::length(str: m_pAsString) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x104D4AA0
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x104D4B80
// Name: protected: void CDmeEditorChoicesInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::OnConstruction(CDmeEditorChoicesInfo *this)
{
  CDmaElementArray<CDmElement> *p_m_Choices; // edi

  p_m_Choices = &this->m_Choices;
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Choices->m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x104D4BD0
// Name: public: int CDmeEditorChoicesInfo::GetChoiceCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetChoiceCount(CDmeEditorChoicesInfo *this)
{
  return this->m_Choices.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x104D4BE0
// Name: public: void CDmeEditorType::AddAttributeInfo(char const __near *,class CDmeEditorAttributeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorType::AddAttributeInfo(
        CDmeEditorType *this,
        int pAttributeName,
        CDmeEditorAttributeInfo *pInfo)
{
  const char *v3; // esi
  CDmAttribute *Attribute; // eax

  v3 = (const char *)pAttributeName;
  if ( _V_stricmp(s1: "name", s2: (const char *)pAttributeName) == 0 )
    v3 = "__name";
  if ( pInfo != nullptr )
    pAttributeName = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pInfo);
  else
    pAttributeName = -1;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: v3);
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: v3, type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pAttributeName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D4C50
// Name: public: void CDmeEditorTypeDictionary::AddEditorType(class CDmeEditorType __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorTypeDictionary::AddEditorType(CDmeEditorTypeDictionary *this, CDmeEditorType *pEditorType)
{
  CExpressionCalculator *v2; // ebx
  const char *m_pAsString; // esi
  CDmAttribute *Attribute; // eax

  v2 = (CExpressionCalculator *)pEditorType;
  m_pAsString = pEditorType->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  if ( CDmElement::HasAttribute(this, pAttributeName: m_pAsString, type: AT_UNKNOWN) )
  {
    _Warning(a1: "Editor type %s is already defined! Ignoring...\n", m_pAsString);
  }
  else
  {
    pEditorType = (CDmeEditorType *)CCodecBuffer_Block::GetBufferType(this: v2);
    Attribute = CDmElement::FindAttribute(this, pAttributeName: m_pAsString);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: m_pAsString, type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&pEditorType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D4CC0
// Name: protected: class CDmElement __near * CDmeEditorChoicesInfo::CreateChoice(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeEditorChoicesInfo::CreateChoice(
        CDmeEditorChoicesInfo *this,
        const char *pChoiceString)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CExpressionCalculator *v5; // esi
  CDmAttribute *Attribute; // eax
  CUtlSymbolLarge symbol; // [esp+8h] [ebp-8h] BYREF
  DmElementHandle_t src; // [esp+Ch] [ebp-4h] BYREF

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: &var,
         a4: this->m_fileId,
         a5: nullptr);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = (CExpressionCalculator *)v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
  {
    src = CCodecBuffer_Block::GetBufferType(this: v5);
  }
  else
  {
    v5 = nullptr;
    src = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Choices,
    &src);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &symbol, a3: pChoiceString);
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)v5, pAttributeName: "string");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: (CDmElement *)v5, pAttributeName: "string", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: &symbol);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x104D4D90
// Name: public: char const __near * CDmeEditorChoicesInfo::GetChoiceString(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorChoicesInfo::GetChoiceString(CDmeEditorChoicesInfo *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmElement::m_classType) )
    return CDmElement::GetValueString(this: v3, pAttributeName: "string");
  else
    return &var;
}

//------------------------------------------------------------------------------
// Address: 0x104D4F10
// Name: private: class CDmeEditorType __near * CDmeEditorTypeDictionary::GetEditorType(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorType *__thiscall CDmeEditorTypeDictionary::GetEditorType(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement)
{
  const char *ValueString; // eax
  const char *m_pAsString; // esi

  if ( pElement == nullptr )
    return nullptr;
  if ( !CDmElement::HasAttribute(this: pElement, pAttributeName: "editorType", type: AT_UNKNOWN)
    || (ValueString = CDmElement::GetValueString(this: pElement, pAttributeName: "editorType"),
        m_pAsString = ValueString,
        ValueString == nullptr)
    || *ValueString == 0 )
  {
    m_pAsString = &var;
    if ( pElement->m_Type.u.m_Id != -1 )
      m_pAsString = pElement->m_Type.u.m_pAsString;
  }
  if ( m_pAsString != nullptr
    && *m_pAsString != 0
    && CDmElement::HasAttribute(this, pAttributeName: m_pAsString, type: AT_UNKNOWN) )
  {
    return CDmElement::GetValueElement<CDmeEditorType>(this, pAttributeName: m_pAsString);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D4F90
// Name: public: class CDmeEditorAttributeInfo __near * CDmeEditorTypeDictionary::GetAttributeInfo(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__thiscall CDmeEditorTypeDictionary::GetAttributeInfo(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement,
        const char *pAttributeName)
{
  CDmeEditorAttributeInfo *result; // eax
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // edi

  result = (CDmeEditorAttributeInfo *)CDmeEditorTypeDictionary::GetEditorType(this, pElement);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = pAttributeName;
    if ( _V_stricmp(s1: "name", s2: pAttributeName) == 0 )
      v5 = "__name";
    if ( CDmElement::HasAttribute(this: v4, pAttributeName: v5, type: AT_UNKNOWN) )
      return CDmElement::GetValueElement<CDmeEditorAttributeInfo>(this: v4, pAttributeName: v5);
    else
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D4FF0
// Name: public: class CDmeEditorAttributeInfo __near * CDmeEditorTypeDictionary::GetAttributeArrayInfo(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorType *__thiscall CDmeEditorTypeDictionary::GetAttributeArrayInfo(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement,
        const char *pAttributeName)
{
  CDmeEditorType *result; // eax
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // edi
  CDmeEditorAttributeInfo *Value; // eax

  result = CDmeEditorTypeDictionary::GetEditorType(this, pElement);
  v4 = (CDmeEditorAttributeInfo *)result;
  if ( result != nullptr )
  {
    v5 = pAttributeName;
    if ( _V_stricmp(s1: "name", s2: pAttributeName) == 0 )
      v5 = "__name";
    if ( CDmElement::HasAttribute(this: v4, pAttributeName: v5, type: AT_UNKNOWN)
      && (Value = CDmElement::GetValueElement<CDmeEditorAttributeInfo>(this: v4, pAttributeName: v5)) != nullptr )
    {
      return (CDmeEditorType *)g_pDataModel->GetElement(
                                 this: g_pDataModel,
                                 a2: Value->m_ArrayEntries.m_Storage.m_Handle);
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D5290
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D52C0
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D53E0
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D5410
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x105C6CF0
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 0x44u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6D50
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 0x44u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC020
// Name: _GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_0.m_PanelMessageMapPool);
  CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::RemoveAll(this: &dictionary_0.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_0.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x105CC060
// Name: _GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __usercall GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__(int a1@<edi>)
{
  CClassMemoryPool<PanelAnimationMap>::Clear(this: &dictionary_1.m_PanelAnimationMapPool, a2: a1);
  CUtlDict<CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::RemoveAll(this: &dictionary_1.m_AnimationMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_1.m_AnimationMaps.m_Elements.m_Tree);
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_1.m_PanelAnimationMapPool);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC50
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC60
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C6D20
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6D30
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C6D80
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6D90
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CC040
// Name: _dynamic_atexit_destructor_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KBMgr__()
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(this: &g_KBMgr.m_Bindings);
}

//------------------------------------------------------------------------------
// Address: 0x105CC050
// Name: _dynamic_atexit_destructor_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ScriptSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x105CC090
// Name: _dynamic_atexit_destructor_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ButtonSoundNames);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC70
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC80
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCC90
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCCA0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004727A0
// Name: protected: virtual int CDmeEditorAttributeInfo::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::AllocatedSize(CDmeUnpackQuaternionOperator *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x0051DC90
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051DE00
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051DE30
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051DF00
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051E050
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E080
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E1A0
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E1D0
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E210
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051E290
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E2C0
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E310
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorChoicesInfo *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEditorAttributeInfo::OnConstruction(this);
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Choices.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x0056C320
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C380
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C3E0
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C440
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED60
// Name: _dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorAttributeInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED70
// Name: _dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED80
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED90
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C350
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C360
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C3B0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C3C0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C410
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C420
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C470
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C480
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EDA0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EDB0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EDC0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EDD0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00523EF0
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00524060
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524090
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524160
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005242B0
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005242E0
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524400
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524430
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524480
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00524500
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524530
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524580
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorChoicesInfo *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEditorAttributeInfo::OnConstruction(this);
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Choices.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x00525420
// Name: protected: virtual int CDmeEditorAttributeInfo::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::AllocatedSize(CDmeUnpackQuaternionOperator *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x0057C440
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C4A0
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C500
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C560
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE90
// Name: _dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorAttributeInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EEA0
// Name: _dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EEB0
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EEC0
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C470
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C480
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C4D0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C4E0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C530
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C540
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C590
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C5A0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EED0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EEE0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EEF0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF00
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005E0DC0
// Name: public: void CDmeEditorChoicesInfo::SetChoiceType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::SetChoiceType(CDmeEditorChoicesInfo *this, const char *pChoiceType)
{
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pChoiceType,
    a3: pChoiceType);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_ChoiceType.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x005E0E00
// Name: public: char const __near * CDmeEditorAttributeInfo::GetWidgetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorAttributeInfo::GetWidgetName(CDmeEditorAttributeInfo *this)
{
  const char *result; // eax

  result = this->m_Widget.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E0E10
// Name: public: char const __near * CDmeEditorChoicesInfo::GetChoiceType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorChoicesInfo::GetChoiceType(CDmeEditorChoicesInfo *this)
{
  const char *result; // eax

  result = this->m_ChoiceType.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E0E30
// Name: public: bool CDmeEditorChoicesInfo::HasChoiceType(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::HasChoiceType(CDmeEditorChoicesInfo *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_ChoiceType.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  return _V_strlen(str: m_pAsString) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x005E0E60
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E0F40
// Name: protected: void CDmeEditorChoicesInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::OnConstruction(CDmeEditorChoicesInfo *this)
{
  CDmaElementArray<CDmElement> *p_m_Choices; // edi

  p_m_Choices = &this->m_Choices;
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Choices->m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x005E0F90
// Name: public: int CDmeEditorChoicesInfo::GetChoiceCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetChoiceCount(CDmeMesh *this)
{
  return this->m_DeltaStates.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005E0FA0
// Name: public: void CDmeEditorType::AddAttributeInfo(char const __near *,class CDmeEditorAttributeInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorType::AddAttributeInfo(
        CDmeEditorType *this,
        int pAttributeName,
        CExpressionCalculator *pInfo)
{
  const char *v3; // esi
  CDmAttribute *Attribute; // eax

  v3 = (const char *)pAttributeName;
  if ( _V_stricmp(s1: "name", s2: (const char *)pAttributeName) == 0 )
    v3 = "__name";
  if ( pInfo != nullptr )
    pAttributeName = CCodecBuffer_Block::GetBufferType(this: pInfo);
  else
    pAttributeName = -1;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: v3);
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: v3, type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (const DmElementHandle_t *)&pAttributeName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E1010
// Name: public: void CDmeEditorTypeDictionary::AddEditorType(class CDmeEditorType __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorTypeDictionary::AddEditorType(
        CDmeEditorTypeDictionary *this,
        CExpressionCalculator *pEditorType)
{
  CExpressionCalculator *v2; // ebx
  const char *m_nAllocationCount; // esi
  CDmAttribute *Attribute; // eax

  v2 = pEditorType;
  m_nAllocationCount = (const char *)pEditorType->m_varNames.m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount == (const char *)-1 )
    m_nAllocationCount = defaultValue;
  if ( CDmElement::HasAttribute(this, pAttributeName: m_nAllocationCount, type: AT_UNKNOWN) )
  {
    _Warning(a1: "Editor type %s is already defined! Ignoring...\n", m_nAllocationCount);
  }
  else
  {
    pEditorType = (CExpressionCalculator *)CCodecBuffer_Block::GetBufferType(this: v2);
    Attribute = CDmElement::FindAttribute(this, pAttributeName: m_nAllocationCount);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: m_nAllocationCount, type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (const DmElementHandle_t *)&pEditorType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E1080
// Name: protected: class CDmElement __near * CDmeEditorChoicesInfo::CreateChoice(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeEditorChoicesInfo::CreateChoice(
        CDmeEditorChoicesInfo *this,
        const char *pChoiceString)
{
  int v3; // eax
  int v4; // eax
  CExpressionCalculator *v5; // esi
  CDmAttribute *Attribute; // eax
  CUtlSymbolLarge symbol; // [esp+8h] [ebp-8h] BYREF
  DmElementHandle_t src; // [esp+Ch] [ebp-4h] BYREF

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmElement::m_classType.u,
         a3: defaultValue,
         a4: this->m_fileId,
         a5: 0);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = (CExpressionCalculator *)v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmElement::m_classType.u) != 0 )
  {
    src = CCodecBuffer_Block::GetBufferType(this: v5);
  }
  else
  {
    v5 = nullptr;
    src = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Choices,
    &src);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &symbol,
    a3: pChoiceString);
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)v5, pAttributeName: "string");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: (CDmElement *)v5, pAttributeName: "string", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: &symbol);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x005E1150
// Name: public: char const __near * CDmeEditorChoicesInfo::GetChoiceString(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeEditorChoicesInfo::GetChoiceString(CDmeEditorChoicesInfo *this, int nIndex)
{
  int v2; // eax
  CDmElement *v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Choices.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = (CDmElement *)v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return CDmElement::GetValueString(this: v3, pAttributeName: "string");
  }
  else
  {
    return defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E12D0
// Name: private: class CDmeEditorType __near * CDmeEditorTypeDictionary::GetEditorType(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorType *__thiscall CDmeEditorTypeDictionary::GetEditorType(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement)
{
  const char *ValueString; // eax
  const char *m_pAsString; // esi

  if ( pElement == nullptr )
    return nullptr;
  if ( !CDmElement::HasAttribute(this: pElement, pAttributeName: "editorType", type: AT_UNKNOWN)
    || (ValueString = CDmElement::GetValueString(this: pElement, pAttributeName: "editorType"),
        m_pAsString = ValueString,
        ValueString == nullptr)
    || *ValueString == 0 )
  {
    m_pAsString = defaultValue;
    if ( pElement->m_Type.u.m_Id != -1 )
      m_pAsString = pElement->m_Type.u.m_pAsString;
  }
  if ( m_pAsString != nullptr
    && *m_pAsString != 0
    && CDmElement::HasAttribute(this, pAttributeName: m_pAsString, type: AT_UNKNOWN) )
  {
    return CDmElement::GetValueElement<CDmeEditorType>(this, pAttributeName: m_pAsString);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E1350
// Name: public: class CDmeEditorAttributeInfo __near * CDmeEditorTypeDictionary::GetAttributeInfo(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__thiscall CDmeEditorTypeDictionary::GetAttributeInfo(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement,
        const char *pAttributeName)
{
  CDmeEditorAttributeInfo *result; // eax
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // edi

  result = (CDmeEditorAttributeInfo *)CDmeEditorTypeDictionary::GetEditorType(this, pElement);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = pAttributeName;
    if ( _V_stricmp(s1: "name", s2: pAttributeName) == 0 )
      v5 = "__name";
    if ( CDmElement::HasAttribute(this: v4, pAttributeName: v5, type: AT_UNKNOWN) )
      return CDmElement::GetValueElement<CDmeEditorAttributeInfo>(this: v4, pAttributeName: v5);
    else
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E13B0
// Name: public: class CDmeEditorAttributeInfo __near * CDmeEditorTypeDictionary::GetAttributeArrayInfo(class CDmElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorType *__thiscall CDmeEditorTypeDictionary::GetAttributeArrayInfo(
        CDmeEditorTypeDictionary *this,
        CDmElement *pElement,
        const char *pAttributeName)
{
  CDmeEditorType *result; // eax
  CDmeEditorAttributeInfo *v4; // esi
  const char *v5; // edi
  CDmeEditorAttributeInfo *Value; // eax

  result = CDmeEditorTypeDictionary::GetEditorType(this, pElement);
  v4 = (CDmeEditorAttributeInfo *)result;
  if ( result != nullptr )
  {
    v5 = pAttributeName;
    if ( _V_stricmp(s1: "name", s2: pAttributeName) == 0 )
      v5 = "__name";
    if ( CDmElement::HasAttribute(this: v4, pAttributeName: v5, type: AT_UNKNOWN)
      && (Value = CDmElement::GetValueElement<CDmeEditorAttributeInfo>(this: v4, pAttributeName: v5)) != nullptr )
    {
      return (CDmeEditorType *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                 a1: g_pDataModel.u,
                                 a2: Value->m_ArrayEntries.m_Storage.m_Handle);
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E1650
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E1680
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E17A0
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E17D0
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006B1650
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B16B0
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B56A0
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B56B0
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5E90
// Name: _GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_0.m_PanelMessageMapPool);
  CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::RemoveAll(this: &dictionary_0.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_0.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x006B5ED0
// Name: _GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CClassMemoryPool<PanelAnimationMap>::Clear(this: &dictionary_1.m_PanelAnimationMapPool);
  CUtlDict<CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::RemoveAll(this: &dictionary_1.m_AnimationMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_1.m_AnimationMaps.m_Elements.m_Tree);
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_1.m_PanelAnimationMapPool);
}

//------------------------------------------------------------------------------
// Address: 0x006B1680
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1690
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B16E0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B16F0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B56C0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B56D0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B56E0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B56F0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5EB0
// Name: _dynamic_atexit_destructor_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KBMgr__()
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(this: &g_KBMgr.m_Bindings);
}

//------------------------------------------------------------------------------
// Address: 0x006B5EC0
// Name: _dynamic_atexit_destructor_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ScriptSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x006B5F00
// Name: _dynamic_atexit_destructor_for__s_StartDirContexts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_StartDirContexts__()
{
  CUtlDict<CUtlString,unsigned short>::RemoveAll(this: &s_StartDirContexts);
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_StartDirContexts.m_Elements.m_Tree);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005250A0
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00525210
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525240
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525310
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00525460
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525490
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005255B0
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005255E0
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525620
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005256A0
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005256D0
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525720
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorChoicesInfo *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEditorAttributeInfo::OnConstruction(this);
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Choices.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x00527BE0
// Name: protected: virtual int CDmeEditorAttributeInfo::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::AllocatedSize(CDmeUnpackQuaternionOperator *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x0057E410
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E470
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4D0
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E530
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580E70
// Name: _dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorAttributeInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580E80
// Name: _dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580E90
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580EA0
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E440
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E450
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4A0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4B0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E500
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E510
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E560
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E570
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580EB0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580EC0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580ED0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580EE0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00481630
// Name: protected: virtual int CDmeEditorAttributeInfo::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::AllocatedSize(CDmeUnpackQuaternionOperator *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x0052C5E0
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0052C750
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C780
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C850
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0052C9B0
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C9E0
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CB00
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CB30
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CB80
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052CC00
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CC30
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CC80
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Choices.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC60
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCC0
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD20
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD80
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E580
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E590
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC90
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCA0
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCF0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD00
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD50
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD60
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BDB0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BDC0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E5A0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E5B0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E5C0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E5D0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062F5E0
// Name: protected: void CDmeEditorAttributeInfo::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::OnConstruction(CDmeEditorAttributeInfo *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  this->m_Widget.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "widget",
                                  type: AT_STRING,
                                  pMemory: &this->m_Widget);
  this->m_bIsVisible.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "isVisible",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bIsVisible);
  this->m_bIsReadOnly.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "isReadOnly",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bIsReadOnly);
  this->m_ArrayEntries.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "arrayEntries",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_ArrayEntries);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ArrayEntries.m_pAttribute,
    typeSymbol: CDmeEditorAttributeInfo::m_classType);
  this->m_bHideType.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "hideType",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bHideType);
  this->m_bHideValue.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hideValue",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bHideValue);
  this->m_Help.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "help",
                                type: AT_STRING,
                                pMemory: &this->m_Help);
  m_pAttribute = this->m_bIsVisible.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_bIsReadOnly.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0062F760
// Name: public: virtual bool CDmeEditorAttributeInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorAttributeInfo::IsA(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062F790
// Name: public: virtual int CDmeEditorAttributeInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::GetInheritanceDepth(CDmeEditorAttributeInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062F860
// Name: protected: virtual void CDmeEditorAttributeInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorAttributeInfo::PerformConstruction(CDmeEditorAttributeInfo *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062F9B0
// Name: public: virtual bool CDmeEditorType::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorType::IsA(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062F9E0
// Name: public: virtual int CDmeEditorType::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorType::GetInheritanceDepth(CDmeEditorType *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorType::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062FB00
// Name: public: virtual bool CDmeEditorTypeDictionary::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorTypeDictionary::IsA(CDmeEditorTypeDictionary *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062FB30
// Name: public: virtual int CDmeEditorTypeDictionary::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorTypeDictionary::GetInheritanceDepth(
        CDmeEditorTypeDictionary *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorTypeDictionary::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062FB70
// Name: protected: CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *__thiscall CDmeEditorChoicesInfo::CDmeEditorChoicesInfo(
        CDmeEditorChoicesInfo *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_Widget.m_pAttribute = nullptr;
  this->m_Widget.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bIsReadOnly.m_pAttribute = nullptr;
  this->m_bIsReadOnly.m_Storage = false;
  this->m_bHideType.m_pAttribute = nullptr;
  this->m_bHideType.m_Storage = false;
  this->m_bHideValue.m_pAttribute = nullptr;
  this->m_bHideValue.m_Storage = false;
  this->m_Help.m_pAttribute = nullptr;
  this->m_Help.m_Storage.u.CDmeEditorAttributeInfo::m_Id = -1;
  this->m_ArrayEntries.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ArrayEntries.m_pAttribute = nullptr;
  this->m_ArrayEntries.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->__vftable = (CDmeEditorChoicesInfo_vtbl *)&CDmeEditorChoicesInfo::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Choices);
  this->m_ChoiceType.m_Storage.u.m_Id = -1;
  this->m_ChoiceType.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062FBF0
// Name: public: virtual bool CDmeEditorChoicesInfo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEditorChoicesInfo::IsA(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062FC20
// Name: public: virtual int CDmeEditorChoicesInfo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorChoicesInfo::GetInheritanceDepth(CDmeEditorChoicesInfo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEditorChoicesInfo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeEditorAttributeInfo::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062FC70
// Name: protected: virtual void CDmeEditorChoicesInfo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditorChoicesInfo::PerformConstruction(CDmeEditorChoicesInfo *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeEditorAttributeInfo::OnConstruction(this);
  this->m_Choices.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "choices",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Choices);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Choices.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_ChoiceType.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "choicetype",
                                      type: AT_STRING,
                                      pMemory: &this->m_ChoiceType);
}

//------------------------------------------------------------------------------
// Address: 0x00632540
// Name: protected: virtual int CDmeEditorAttributeInfo::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEditorAttributeInfo::AllocatedSize(CDmeUnpackQuaternionOperator *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x006B9BD0
// Name: _dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorAttributeInfo::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorAttributeInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9C30
// Name: _dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorChoicesInfo::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorChoicesInfo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9C90
// Name: _dynamic_initializer_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorType::s_Allocator,
    blockSize: 0x44u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorType pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9CF0
// Name: _dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEditorTypeDictionary::s_Allocator,
    blockSize: 0x44u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEditorTypeDictionary pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD380
// Name: _dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorAttributeInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorAttributeInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD390
// Name: _dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorChoicesInfo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorChoicesInfo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD3A0
// Name: _dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorType::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorType::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD3B0
// Name: _dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEditorTypeDictionary::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEditorTypeDictionary::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9C00
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorAttributeInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9C10
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorAttributeInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorAttributeInfo_Helper,
           classname: "DmeEditorAttributeInfo",
           pFactory: &g_CDmeEditorAttributeInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9C60
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorChoicesInfo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9C70
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorChoicesInfo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorChoicesInfo_Helper,
           classname: "DmeEditorChoicesInfo",
           pFactory: &g_CDmeEditorChoicesInfo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9CC0
// Name: _dynamic_initializer_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorType_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9CD0
// Name: _dynamic_initializer_for__g_CDmeEditorType_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorType_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorType_Helper,
           classname: "DmeEditorType",
           pFactory: &g_CDmeEditorType_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9D20
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEditorTypeDictionary_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9D30
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEditorTypeDictionary_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEditorTypeDictionary_Helper,
           classname: "DmeEditorTypeDictionary",
           pFactory: &g_CDmeEditorTypeDictionary_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD3C0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorChoicesInfo_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeEditorChoicesInfo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD3D0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorType_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeEditorType_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD3E0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorTypeDictionary_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeEditorTypeDictionary_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD3F0
// Name: _dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEditorAttributeInfo_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeEditorAttributeInfo_Factory.m_CallBackList);
}

} // namespace vmap
