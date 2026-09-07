// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: sfmobjects/dmegrapheditorcurve.cpp
// Functions: 48
// ============================================================

#include "sfmobjects\dmegrapheditorcurve.h"

//------------------------------------------------------------------------------
// Address: 0x00544230
// Name: protected: void CDmeCurveKey::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCurveKey::OnConstruction(CDmeCurveKey *this)
{
  CDmaVar<bool> *p_m_Selected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  DmeTime_t v16; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  p_m_Selected = &this->m_Selected;
  this->m_Component = 0;
  this->m_KeyDirtyFlags = 0;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "selected", type: AT_BOOL, pMemory: &this->m_Selected);
  p_m_Selected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "inSelected", type: AT_BOOL, pMemory: &this->m_InSelected);
  this->m_InSelected.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "outSelected",
         type: AT_BOOL,
         pMemory: &this->m_OutSelected);
  this->m_OutSelected.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v16.m_tms = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "inMode", type: AT_INT, pMemory: &this->m_InMode);
  this->m_InMode.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v16.m_tms);
  v16.m_tms = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "outMode", type: AT_INT, pMemory: &this->m_OutMode);
  this->m_OutMode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v16.m_tms);
  value = true;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "weighted", type: AT_BOOL, pMemory: &this->m_Weighted);
  this->m_Weighted.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, &value);
  value = true;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "unified", type: AT_BOOL, pMemory: &this->m_Unified);
  this->m_Unified.m_pAttribute = v9;
  CDmAttribute::SetValue<bool>(this: v9, &value);
  v16.m_tms = 0;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  this->m_Time.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v16);
  v16.m_tms = 0;
  v11 = CDmElement::AddExternalAttribute(this, pAttributeName: "value", type: AT_FLOAT, pMemory: &this->m_Value);
  this->m_Value.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (const float *)&v16.m_tms);
  v16.m_tms = 0;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "inTime", type: AT_TIME, pMemory: &this->m_InTime);
  this->m_InTime.m_pAttribute = v12;
  CDmAttribute::SetValue<DmeTime_t>(this: v12, value: &v16);
  v16.m_tms = 0;
  v13 = CDmElement::AddExternalAttribute(this, pAttributeName: "inDelta", type: AT_FLOAT, pMemory: &this->m_InDelta);
  this->m_InDelta.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (const float *)&v16.m_tms);
  v16.m_tms = 0;
  v14 = CDmElement::AddExternalAttribute(this, pAttributeName: "outTime", type: AT_TIME, pMemory: &this->m_OutTime);
  this->m_OutTime.m_pAttribute = v14;
  CDmAttribute::SetValue<DmeTime_t>(this: v14, value: &v16);
  v16.m_tms = 0;
  v15 = CDmElement::AddExternalAttribute(this, pAttributeName: "outDelta", type: AT_FLOAT, pMemory: &this->m_OutDelta);
  this->m_OutDelta.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (const float *)&v16.m_tms);
  this->m_bOldValuesValid = false;
  this->m_OldInMode = 0;
  this->m_OldOutMode = 0;
  this->m_OldTime.m_tms = 0x80000000;
  this->m_OldValue = 0.0;
  this->m_OldInTime.m_tms = 0x80000000;
  this->m_OldInDelta = 0.0;
  this->m_OldOutTime.m_tms = 0x80000000;
  this->m_OldOutDelta = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00544480
// Name: protected: void CDmeGraphEditorCurve::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorCurve::OnConstruction(CDmeGraphEditorCurve *this)
{
  CDmaElement<CDmeChannel> *p_m_Channel; // edi

  p_m_Channel = &this->m_Channel;
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Channel);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Channel->m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_EditLog.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "editLog",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_EditLog);
  CDmAttribute::SetElementTypeSymbol(this: this->m_EditLog.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_KeyList[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyList_0",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: this->m_KeyList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_KeyList[0].m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_KeyList[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyList_1",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_KeyList[1]);
  CDmAttribute::SetElementTypeSymbol(this: this->m_KeyList[1].m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_KeyList[2].m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyList_2",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_KeyList[2]);
  CDmAttribute::SetElementTypeSymbol(this: this->m_KeyList[2].m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_KeyList[3].m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyList_3",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_KeyList[3]);
  CDmAttribute::SetElementTypeSymbol(this: this->m_KeyList[3].m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_ComponentSelection.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "componentSelection",
                                              type: AT_INT,
                                              pMemory: &this->m_ComponentSelection);
  this->m_logCRC = 0;
  this->m_pEditLayer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00544610
// Name: protected: CDmeCurveKey::CDmeCurveKey(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCurveKey *__thiscall CDmeCurveKey::CDmeCurveKey(
        CDmeCurveKey *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCurveKey_vtbl *)&CDmeCurveKey::`vftable';
  this->m_Selected.m_pAttribute = nullptr;
  this->m_Selected.m_Storage = false;
  this->m_InSelected.m_pAttribute = nullptr;
  this->m_InSelected.m_Storage = false;
  this->m_OutSelected.m_pAttribute = nullptr;
  this->m_OutSelected.m_Storage = false;
  this->m_Weighted.m_pAttribute = nullptr;
  this->m_Weighted.m_Storage = false;
  this->m_Unified.m_pAttribute = nullptr;
  this->m_Unified.m_Storage = false;
  this->m_InMode.m_pAttribute = nullptr;
  this->m_InMode.m_Storage = 0;
  this->m_OutMode.m_pAttribute = nullptr;
  this->m_OutMode.m_Storage = 0;
  this->m_Time.m_pAttribute = nullptr;
  this->m_Time.m_Storage.m_tms = 0;
  this->m_Value = 0;
  this->m_InTime.m_pAttribute = nullptr;
  this->m_InTime.m_Storage.m_tms = 0;
  this->m_InDelta = 0;
  this->m_OutTime.m_pAttribute = nullptr;
  this->m_OutTime.m_Storage.m_tms = 0;
  this->m_OutDelta.m_pAttribute = nullptr;
  this->m_OutDelta.m_Storage = 0.0;
  this->m_OldTime.m_tms = 0x80000000;
  this->m_OldInTime.m_tms = 0x80000000;
  this->m_OldOutTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00544710
// Name: public: virtual bool CDmeCurveKey::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCurveKey::IsA(CDmeCurveKey *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCurveKey::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00544740
// Name: public: virtual int CDmeCurveKey::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCurveKey::GetInheritanceDepth(CDmeCurveKey *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCurveKey::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00544780
// Name: protected: virtual int CDmeCurveKey::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCurveKey::AllocatedSize(CDmeCurveKey *this)
{
  return 216;
}

//------------------------------------------------------------------------------
// Address: 0x005447D0
// Name: protected: virtual void CDmeCurveKey::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCurveKey::PerformConstruction(CDmeCurveKey *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCurveKey::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00544840
// Name: protected: CDmeGraphEditorCurve::CDmeGraphEditorCurve(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGraphEditorCurve *__thiscall CDmeGraphEditorCurve::CDmeGraphEditorCurve(
        CDmeGraphEditorCurve *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaElementArray<CDmeCurveKey> *m_KeyList; // ebx
  CUtlVector<CDmeCurveKey *,CUtlMemory<CDmeCurveKey *,int> > *m_OldKeyList; // eax
  int i; // ecx
  DmFileId_t fileida; // [esp+24h] [ebp+18h]

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGraphEditorCurve_vtbl *)&CDmeGraphEditorCurve::`vftable';
  this->m_Channel.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_EditLog.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_EditLog.m_pAttribute = nullptr;
  this->m_EditLog.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  m_KeyList = this->m_KeyList;
  for ( fileida = 3; fileida >= 0; --fileida )
    CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: m_KeyList++);
  this->m_ComponentSelection.m_pAttribute = nullptr;
  this->m_ComponentSelection.m_Storage = 0;
  m_OldKeyList = this->m_OldKeyList;
  for ( i = 3; i >= 0; --i )
  {
    m_OldKeyList->m_Memory.m_pMemory = nullptr;
    m_OldKeyList->m_Memory.m_nAllocationCount = 0;
    m_OldKeyList->m_Memory.m_nGrowSize = 0;
    m_OldKeyList->m_Size = 0;
    m_OldKeyList->m_pElements = nullptr;
    ++m_OldKeyList;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005448E0
// Name: public: virtual bool CDmeGraphEditorCurve::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGraphEditorCurve::IsA(CDmeGraphEditorCurve *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGraphEditorCurve::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00544910
// Name: public: virtual int CDmeGraphEditorCurve::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGraphEditorCurve::GetInheritanceDepth(CDmeGraphEditorCurve *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGraphEditorCurve::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00544950
// Name: protected: virtual int CDmeGraphEditorCurve::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGraphEditorCurve::AllocatedSize(CDmeGraphEditorCurve *this)
{
  return 300;
}

//------------------------------------------------------------------------------
// Address: 0x00544960
// Name: protected: virtual void CDmeGraphEditorCurve::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorCurve::PerformConstruction(CDmeGraphEditorCurve *this)
{
  CDmeFXClip::OnDestruction();
  CDmeGraphEditorCurve::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00544970
// Name: protected: virtual CDmeGraphEditorCurve::~CDmeGraphEditorCurve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorCurve::~CDmeGraphEditorCurve(CDmeGraphEditorCurve *this)
{
  CDmeGraphEditorCurve *v2; // esi
  CDmeGraphEditorCurve_vtbl *v3; // eax
  CDmaVar<int> *p_m_ComponentSelection; // esi
  int j; // ebx
  void *m_Storage; // eax
  int i; // [esp+10h] [ebp-4h]

  this->__vftable = (CDmeGraphEditorCurve_vtbl *)&CDmeGraphEditorCurve::`vftable';
  v2 = this + 1;
  for ( i = 3; i >= 0; --i )
  {
    v2 = (CDmeGraphEditorCurve *)((char *)v2 - 20);
    *(_DWORD *)&v2->m_Id.m_Value[8] = 0;
    if ( *(int *)&v2->m_Id.m_Value[4] >= 0 )
    {
      if ( v2->__vftable != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->__vftable);
        v2->__vftable = nullptr;
      }
      *(_DWORD *)v2->m_Id.m_Value = 0;
    }
    v3 = v2->__vftable;
    *(_DWORD *)&v2->m_Id.m_Value[12] = v2->__vftable;
    if ( *(int *)&v2->m_Id.m_Value[4] >= 0 )
    {
      if ( v3 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
        v2->__vftable = nullptr;
      }
      *(_DWORD *)v2->m_Id.m_Value = 0;
    }
  }
  p_m_ComponentSelection = &this->m_ComponentSelection;
  for ( j = 3; j >= 0; --j )
  {
    p_m_ComponentSelection = (CDmaVar<int> *)((char *)p_m_ComponentSelection - 28);
    p_m_ComponentSelection[1].m_pAttribute = nullptr;
    if ( p_m_ComponentSelection[1].m_Storage >= 0 )
    {
      if ( p_m_ComponentSelection->m_Storage != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_ComponentSelection->m_Storage);
        p_m_ComponentSelection->m_Storage = 0;
      }
      p_m_ComponentSelection->m_pAttribute = nullptr;
    }
    m_Storage = (void *)p_m_ComponentSelection->m_Storage;
    p_m_ComponentSelection[2].m_Storage = p_m_ComponentSelection->m_Storage;
    if ( p_m_ComponentSelection[1].m_Storage >= 0 )
    {
      if ( m_Storage != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Storage);
        p_m_ComponentSelection->m_Storage = 0;
      }
      p_m_ComponentSelection->m_pAttribute = nullptr;
    }
  }
  CDmElement::~CDmElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9B0
// Name: _dynamic_initializer_for__CDmeCurveKey::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCurveKey::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCurveKey::s_Allocator,
    blockSize: 216,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCurveKey pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCurveKey::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA10
// Name: _dynamic_initializer_for__CDmeGraphEditorCurve::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGraphEditorCurve::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGraphEditorCurve::s_Allocator,
    blockSize: 300,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGraphEditorCurve pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGraphEditorCurve::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F600
// Name: _dynamic_atexit_destructor_for__CDmeCurveKey::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCurveKey::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCurveKey::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F610
// Name: _dynamic_atexit_destructor_for__CDmeGraphEditorCurve::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGraphEditorCurve::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGraphEditorCurve::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9E0
// Name: _dynamic_initializer_for__g_CDmeCurveKey_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCurveKey_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCurveKey_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9F0
// Name: _dynamic_initializer_for__g_CDmeCurveKey_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCurveKey_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCurveKey_Helper,
           classname: "DmeCurveKey",
           pFactory: &g_CDmeCurveKey_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA40
// Name: _dynamic_initializer_for__g_CDmeGraphEditorCurve_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGraphEditorCurve_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGraphEditorCurve_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA50
// Name: _dynamic_initializer_for__g_CDmeGraphEditorCurve_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGraphEditorCurve_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGraphEditorCurve_Helper,
           classname: "DmeGraphEditorCurve",
           pFactory: &g_CDmeGraphEditorCurve_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA70
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057DAD0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057DB00
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB20
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB30
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB50
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0057DB60
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB70
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuaternionPool__()
{
  if ( ((unsigned __int8)&g_QuaternionPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_QuaternionPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_QuaternionPool__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DBA0
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VectorPool__()
{
  if ( ((unsigned __int8)&g_VectorPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_VectorPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_VectorPool__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DBD0
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatrixPool__()
{
  if ( ((unsigned __int8)&g_MatrixPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_MatrixPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_MatrixPool__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC00
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC40
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC70
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DCA0
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F620
// Name: _dynamic_atexit_destructor_for__g_CDmeGraphEditorCurve_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGraphEditorCurve_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGraphEditorCurve_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F630
// Name: _dynamic_atexit_destructor_for__g_CDmeCurveKey_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCurveKey_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCurveKey_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F640
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0057F690
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0057F6D0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F6E0
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0057F6F0
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x0057F700
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x0057F710
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x0057F720
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x0057F750
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x0057F760
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x0057F770
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0047A450
// Name: protected: virtual int CDmeGraphEditorCurve::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGraphEditorCurve::AllocatedSize(CDmeGraphEditorCurve *this)
{
  return 300;
}

//------------------------------------------------------------------------------
// Address: 0x00545FD0
// Name: protected: void CDmeCurveKey::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCurveKey::OnConstruction(CDmeCurveKey *this)
{
  CDmaVar<bool> *p_m_Selected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  DmeTime_t v16; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  p_m_Selected = &this->m_Selected;
  this->m_Component = 0;
  this->m_KeyDirtyFlags = 0;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "selected", type: AT_BOOL, pMemory: &this->m_Selected);
  p_m_Selected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "inSelected", type: AT_BOOL, pMemory: &this->m_InSelected);
  this->m_InSelected.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "outSelected",
         type: AT_BOOL,
         pMemory: &this->m_OutSelected);
  this->m_OutSelected.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  v16.m_tms = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "inMode", type: AT_INT, pMemory: &this->m_InMode);
  this->m_InMode.m_pAttribute = v6;
  CDmAttribute::SetValue<int>(this: v6, value: &v16.m_tms);
  v16.m_tms = 0;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "outMode", type: AT_INT, pMemory: &this->m_OutMode);
  this->m_OutMode.m_pAttribute = v7;
  CDmAttribute::SetValue<int>(this: v7, value: &v16.m_tms);
  value = true;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "weighted", type: AT_BOOL, pMemory: &this->m_Weighted);
  this->m_Weighted.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, &value);
  value = true;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "unified", type: AT_BOOL, pMemory: &this->m_Unified);
  this->m_Unified.m_pAttribute = v9;
  CDmAttribute::SetValue<bool>(this: v9, &value);
  v16.m_tms = 0;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  this->m_Time.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: &v16);
  v16.m_tms = 0;
  v11 = CDmElement::AddExternalAttribute(this, pAttributeName: "value", type: AT_FLOAT, pMemory: &this->m_Value);
  this->m_Value.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (const float *)&v16.m_tms);
  v16.m_tms = 0;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "inTime", type: AT_TIME, pMemory: &this->m_InTime);
  this->m_InTime.m_pAttribute = v12;
  CDmAttribute::SetValue<DmeTime_t>(this: v12, value: &v16);
  v16.m_tms = 0;
  v13 = CDmElement::AddExternalAttribute(this, pAttributeName: "inDelta", type: AT_FLOAT, pMemory: &this->m_InDelta);
  this->m_InDelta.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (const float *)&v16.m_tms);
  v16.m_tms = 0;
  v14 = CDmElement::AddExternalAttribute(this, pAttributeName: "outTime", type: AT_TIME, pMemory: &this->m_OutTime);
  this->m_OutTime.m_pAttribute = v14;
  CDmAttribute::SetValue<DmeTime_t>(this: v14, value: &v16);
  v16.m_tms = 0;
  v15 = CDmElement::AddExternalAttribute(this, pAttributeName: "outDelta", type: AT_FLOAT, pMemory: &this->m_OutDelta);
  this->m_OutDelta.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (const float *)&v16.m_tms);
  this->m_bOldValuesValid = false;
  this->m_OldInMode = 0;
  this->m_OldOutMode = 0;
  this->m_OldTime.m_tms = 0x80000000;
  this->m_OldValue = 0.0;
  this->m_OldInTime.m_tms = 0x80000000;
  this->m_OldInDelta = 0.0;
  this->m_OldOutTime.m_tms = 0x80000000;
  this->m_OldOutDelta = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00546220
// Name: protected: void CDmeGraphEditorCurve::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorCurve::OnConstruction(CDmeGraphEditorCurve *this)
{
  CDmaElement<CDmeChannel> *p_m_Channel; // edi

  p_m_Channel = &this->m_Channel;
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Channel);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Channel->m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_EditLog.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "editLog",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_EditLog);
  CDmAttribute::SetElementTypeSymbol(this: this->m_EditLog.m_pAttribute, typeSymbol: CDmeLog::m_classType);
  this->m_KeyList[0].m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyList_0",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: this->m_KeyList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_KeyList[0].m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_KeyList[1].m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyList_1",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_KeyList[1]);
  CDmAttribute::SetElementTypeSymbol(this: this->m_KeyList[1].m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_KeyList[2].m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyList_2",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_KeyList[2]);
  CDmAttribute::SetElementTypeSymbol(this: this->m_KeyList[2].m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_KeyList[3].m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyList_3",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_KeyList[3]);
  CDmAttribute::SetElementTypeSymbol(this: this->m_KeyList[3].m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_ComponentSelection.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "componentSelection",
                                              type: AT_INT,
                                              pMemory: &this->m_ComponentSelection);
  this->m_logCRC = 0;
  this->m_pEditLayer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005463B0
// Name: protected: CDmeCurveKey::CDmeCurveKey(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCurveKey *__thiscall CDmeCurveKey::CDmeCurveKey(
        CDmeCurveKey *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCurveKey_vtbl *)&CDmeCurveKey::`vftable';
  this->m_Selected.m_pAttribute = nullptr;
  this->m_Selected.m_Storage = false;
  this->m_InSelected.m_pAttribute = nullptr;
  this->m_InSelected.m_Storage = false;
  this->m_OutSelected.m_pAttribute = nullptr;
  this->m_OutSelected.m_Storage = false;
  this->m_Weighted.m_pAttribute = nullptr;
  this->m_Weighted.m_Storage = false;
  this->m_Unified.m_pAttribute = nullptr;
  this->m_Unified.m_Storage = false;
  this->m_InMode.m_pAttribute = nullptr;
  this->m_InMode.m_Storage = 0;
  this->m_OutMode.m_pAttribute = nullptr;
  this->m_OutMode.m_Storage = 0;
  this->m_Time.m_pAttribute = nullptr;
  this->m_Time.m_Storage.m_tms = 0;
  this->m_Value = 0;
  this->m_InTime.m_pAttribute = nullptr;
  this->m_InTime.m_Storage.m_tms = 0;
  this->m_InDelta = 0;
  this->m_OutTime.m_pAttribute = nullptr;
  this->m_OutTime.m_Storage.m_tms = 0;
  this->m_OutDelta.m_pAttribute = nullptr;
  this->m_OutDelta.m_Storage = 0.0;
  this->m_OldTime.m_tms = 0x80000000;
  this->m_OldInTime.m_tms = 0x80000000;
  this->m_OldOutTime.m_tms = 0x80000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005464B0
// Name: public: virtual bool CDmeCurveKey::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCurveKey::IsA(CDmeCurveKey *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCurveKey::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005464E0
// Name: public: virtual int CDmeCurveKey::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCurveKey::GetInheritanceDepth(CDmeCurveKey *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCurveKey::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00546520
// Name: protected: virtual int CDmeCurveKey::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCurveKey::AllocatedSize(CDmeCurveKey *this)
{
  return 216;
}

//------------------------------------------------------------------------------
// Address: 0x00546570
// Name: protected: virtual void CDmeCurveKey::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCurveKey::PerformConstruction(CDmeCurveKey *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCurveKey::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005465E0
// Name: protected: CDmeGraphEditorCurve::CDmeGraphEditorCurve(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGraphEditorCurve *__thiscall CDmeGraphEditorCurve::CDmeGraphEditorCurve(
        CDmeGraphEditorCurve *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaElementArray<CDmeCurveKey> *m_KeyList; // ebx
  CUtlVector<CDmeCurveKey *,CUtlMemory<CDmeCurveKey *,int> > *m_OldKeyList; // eax
  int i; // ecx
  DmFileId_t fileida; // [esp+24h] [ebp+18h]

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeGraphEditorCurve_vtbl *)&CDmeGraphEditorCurve::`vftable';
  this->m_Channel.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_EditLog.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_EditLog.m_pAttribute = nullptr;
  this->m_EditLog.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  m_KeyList = this->m_KeyList;
  for ( fileida = 3; fileida >= 0; --fileida )
    CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: m_KeyList++);
  this->m_ComponentSelection.m_pAttribute = nullptr;
  this->m_ComponentSelection.m_Storage = 0;
  m_OldKeyList = this->m_OldKeyList;
  for ( i = 3; i >= 0; --i )
  {
    m_OldKeyList->m_Memory.m_pMemory = nullptr;
    m_OldKeyList->m_Memory.m_nAllocationCount = 0;
    m_OldKeyList->m_Memory.m_nGrowSize = 0;
    m_OldKeyList->m_Size = 0;
    m_OldKeyList->m_pElements = nullptr;
    ++m_OldKeyList;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00546680
// Name: public: virtual bool CDmeGraphEditorCurve::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGraphEditorCurve::IsA(CDmeGraphEditorCurve *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGraphEditorCurve::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005466B0
// Name: public: virtual int CDmeGraphEditorCurve::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGraphEditorCurve::GetInheritanceDepth(CDmeGraphEditorCurve *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGraphEditorCurve::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005466F0
// Name: protected: virtual void CDmeGraphEditorCurve::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorCurve::PerformConstruction(CDmeGraphEditorCurve *this)
{
  CDmeFXClip::OnDestruction();
  CDmeGraphEditorCurve::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00546700
// Name: protected: virtual CDmeGraphEditorCurve::~CDmeGraphEditorCurve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorCurve::~CDmeGraphEditorCurve(CDmeGraphEditorCurve *this)
{
  CDmeGraphEditorCurve *v2; // esi
  CDmeGraphEditorCurve_vtbl *v3; // eax
  CDmaVar<int> *p_m_ComponentSelection; // esi
  int j; // ebx
  void *m_Storage; // eax
  int i; // [esp+10h] [ebp-4h]

  this->__vftable = (CDmeGraphEditorCurve_vtbl *)&CDmeGraphEditorCurve::`vftable';
  v2 = this + 1;
  for ( i = 3; i >= 0; --i )
  {
    v2 = (CDmeGraphEditorCurve *)((char *)v2 - 20);
    *(_DWORD *)&v2->m_Id.m_Value[8] = 0;
    if ( *(int *)&v2->m_Id.m_Value[4] >= 0 )
    {
      if ( v2->__vftable != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->__vftable);
        v2->__vftable = nullptr;
      }
      *(_DWORD *)v2->m_Id.m_Value = 0;
    }
    v3 = v2->__vftable;
    *(_DWORD *)&v2->m_Id.m_Value[12] = v2->__vftable;
    if ( *(int *)&v2->m_Id.m_Value[4] >= 0 )
    {
      if ( v3 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
        v2->__vftable = nullptr;
      }
      *(_DWORD *)v2->m_Id.m_Value = 0;
    }
  }
  p_m_ComponentSelection = &this->m_ComponentSelection;
  for ( j = 3; j >= 0; --j )
  {
    p_m_ComponentSelection = (CDmaVar<int> *)((char *)p_m_ComponentSelection - 28);
    p_m_ComponentSelection[1].m_pAttribute = nullptr;
    if ( p_m_ComponentSelection[1].m_Storage >= 0 )
    {
      if ( p_m_ComponentSelection->m_Storage != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_ComponentSelection->m_Storage);
        p_m_ComponentSelection->m_Storage = 0;
      }
      p_m_ComponentSelection->m_pAttribute = nullptr;
    }
    m_Storage = (void *)p_m_ComponentSelection->m_Storage;
    p_m_ComponentSelection[2].m_Storage = p_m_ComponentSelection->m_Storage;
    if ( p_m_ComponentSelection[1].m_Storage >= 0 )
    {
      if ( m_Storage != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Storage);
        p_m_ComponentSelection->m_Storage = 0;
      }
      p_m_ComponentSelection->m_pAttribute = nullptr;
    }
  }
  CDmElement::~CDmElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057F990
// Name: _dynamic_initializer_for__CDmeCurveKey::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCurveKey::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCurveKey::s_Allocator,
    blockSize: 216,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCurveKey pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCurveKey::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F9F0
// Name: _dynamic_initializer_for__CDmeGraphEditorCurve::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGraphEditorCurve::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGraphEditorCurve::s_Allocator,
    blockSize: 300,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGraphEditorCurve pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGraphEditorCurve::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005815E0
// Name: _dynamic_atexit_destructor_for__CDmeCurveKey::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCurveKey::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCurveKey::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005815F0
// Name: _dynamic_atexit_destructor_for__CDmeGraphEditorCurve::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGraphEditorCurve::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGraphEditorCurve::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F9C0
// Name: _dynamic_initializer_for__g_CDmeCurveKey_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCurveKey_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCurveKey_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F9D0
// Name: _dynamic_initializer_for__g_CDmeCurveKey_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCurveKey_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCurveKey_Helper,
           classname: "DmeCurveKey",
           pFactory: &g_CDmeCurveKey_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x0057FA20
// Name: _dynamic_initializer_for__g_CDmeGraphEditorCurve_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGraphEditorCurve_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGraphEditorCurve_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FA30
// Name: _dynamic_initializer_for__g_CDmeGraphEditorCurve_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGraphEditorCurve_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGraphEditorCurve_Helper,
           classname: "DmeGraphEditorCurve",
           pFactory: &g_CDmeGraphEditorCurve_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x0057FA50
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057FAB0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057FAE0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FB00
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FB10
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FB30
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0057FB40
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FB50
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuaternionPool__()
{
  if ( ((unsigned __int8)&g_QuaternionPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_QuaternionPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_QuaternionPool__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FB80
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VectorPool__()
{
  if ( ((unsigned __int8)&g_VectorPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_VectorPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_VectorPool__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FBB0
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatrixPool__()
{
  if ( ((unsigned __int8)&g_MatrixPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_MatrixPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_MatrixPool__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FBE0
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FC20
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FC50
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x0057FC80
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x00581600
// Name: _dynamic_atexit_destructor_for__g_CDmeGraphEditorCurve_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGraphEditorCurve_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGraphEditorCurve_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581610
// Name: _dynamic_atexit_destructor_for__g_CDmeCurveKey_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCurveKey_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCurveKey_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581620
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00581670
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005816B0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x005816C0
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x005816D0
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x005816E0
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x005816F0
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x00581700
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x00581730
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x00581740
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x00581750
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

} // namespace sfmgen
