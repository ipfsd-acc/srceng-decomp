// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeexpressionoperator.cpp
// Functions: 14
// ============================================================

#include "movieobjects\dmeexpressionoperator.h"

//------------------------------------------------------------------------------
// Address: 0x0055AED0
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x0055AF40
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  const char *m_pAsString; // eax
  CDmAttribute *i; // esi
  const char *v4; // eax
  const char *v5; // edi
  CDmaVar<float> *m_pData; // eax
  const char *v7; // eax
  float oldValue; // [esp+10h] [ebp-4h] BYREF

  m_pAsString = this->m_expr.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_pAsString);
  for ( i = CDmElement::FirstAttribute(this: &this->CDmElement); i != nullptr; i = i->m_pNext )
  {
    v4 = i->m_Name.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = var;
    if ( _V_strcmp(s1: v4, s2: "result") != 0 && (i->m_nFlags & 0x1F) == 3 )
    {
      v5 = var;
      if ( i->m_Name.u.m_Id != -1 )
        v5 = i->m_Name.u.m_pAsString;
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i->m_nFlags & 0x1F) == 3 )
      {
        m_pData = (CDmaVar<float> *)i->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: i) )
      {
        CDmAttribute::CopyDataOut<float>(this: i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: m_pData->m_Storage);
    }
  }
  oldValue = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: &oldValue);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: &oldValue);
  if ( this->m_bSpewResult.m_Storage )
  {
    v7 = this->m_Name.m_Storage.u.m_pAsString;
    if ( v7 == (const char *)-1 )
      v7 = var;
    _Msg(a1: "%s = '%f'\n", v7, this->m_result.m_Storage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055B090
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeExpressionOperator *v2; // edi
  CDmAttribute *Attribute; // ebx
  const char *m_pAsString; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  Attribute = CDmElement::FirstAttribute(this: &this->CDmElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v8 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = Attribute;
      }
      Attribute = Attribute->m_pNext;
    }
    while ( Attribute != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = attrs->m_Size;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v11 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v11 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0055B190
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
  m_Size = attrs->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: m_Size - m_nAllocationCount + 1);
  ++attrs->m_Size;
  m_pMemory = attrs->m_Memory.m_pMemory;
  v6 = attrs->m_Size - m_Size - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &attrs->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0055B260
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0055B330
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055B360
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055B3B0
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0055B3D0
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x005ADDD0
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B05F0
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADE00
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADE10
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0600
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005B2000
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x005B2070
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  const char *m_pAsString; // eax
  CDmAttribute *i; // esi
  const char *v4; // eax
  const char *v5; // edi
  CDmaVar<float> *m_pData; // eax
  const char *v7; // eax
  float oldValue; // [esp+10h] [ebp-4h] BYREF

  m_pAsString = this->m_expr.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_pAsString);
  for ( i = CDmElement::FirstAttribute(this: &this->CDmElement); i != nullptr; i = i->m_pNext )
  {
    v4 = i->m_Name.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = defaultValue;
    if ( _V_strcmp(s1: v4, s2: "result") != 0 && (i->m_nFlags & 0x1F) == 3 )
    {
      v5 = defaultValue;
      if ( i->m_Name.u.m_Id != -1 )
        v5 = i->m_Name.u.m_pAsString;
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i->m_nFlags & 0x1F) == 3 )
      {
        m_pData = (CDmaVar<float> *)i->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: i) )
      {
        CDmAttribute::CopyDataOut<float>(this: i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: m_pData->m_Storage);
    }
  }
  oldValue = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: &oldValue);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: &oldValue);
  if ( this->m_bSpewResult.m_Storage )
  {
    v7 = this->m_Name.m_Storage.u.m_pAsString;
    if ( v7 == (const char *)-1 )
      v7 = defaultValue;
    _Msg(a1: "%s = '%f'\n", v7, this->m_result.m_Storage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B21C0
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmeExpressionOperator *v2; // edi
  CDmAttribute *Attribute; // ebx
  const char *m_pAsString; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  Attribute = CDmElement::FirstAttribute(this: &this->CDmElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v7 = (CDmAttribute **)attrs->m_pMemory;
        v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
        v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v9 != nullptr )
          *v9 = Attribute;
      }
      Attribute = Attribute->m_pNext;
    }
    while ( Attribute != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = (int)attrs[1].m_pMemory;
  v12 = attrs->m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v11 - v12 + 1);
  ++attrs[1].m_pMemory;
  v13 = (CDmAttribute **)attrs->m_pMemory;
  v14 = (int)attrs[1].m_pMemory - v11 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = (CDmAttribute **)&attrs->m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005B22C0
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
  m_pMemory = (int)attrs[1].m_pMemory;
  if ( m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
  ++attrs[1].m_pMemory;
  v5 = (CDmAttribute **)attrs->m_pMemory;
  v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
  v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005B2390
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B2460
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B2490
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B24E0
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B2500
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_calc.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0067F5C0
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682B00
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F5F0
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F600
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682B10
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1058E5D0
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x1058E640
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  char *m_Id; // eax
  CDmAttribute *i; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi
  CDmaVar<float> *m_pData; // eax
  const char *v7; // eax
  float var10[2]; // [esp+4h] [ebp-4h] BYREF

  m_Id = (char *)this->m_expr.m_Storage.u.m_Id;
  if ( m_Id == (char *)-1 )
    m_Id = (char *)&var;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_Id);
  for ( i = CDmElement::FirstAttribute(this: &this->CDmElement); i != nullptr; i = i->m_pNext )
  {
    m_pAsString = i->m_Name.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (i->m_nFlags & 0x1F) == 3 )
    {
      v5 = &var;
      if ( i->m_Name.u.m_Id != -1 )
        v5 = i->m_Name.u.m_pAsString;
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i->m_nFlags & 0x1F) == 3 )
      {
        m_pData = (CDmaVar<float> *)i->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: i) )
      {
        CDmAttribute::CopyDataOut<float>(this: i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: m_pData->m_Storage);
    }
  }
  var10[0] = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: var10);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: var10);
  if ( this->m_bSpewResult.m_Storage )
  {
    v7 = this->m_Name.m_Storage.u.m_pAsString;
    if ( v7 == (const char *)-1 )
      v7 = &var;
    _Msg(a1: "%s = '%f'\n", v7, this->m_result.m_Storage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1058E790
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmeExpressionOperator *v2; // edi
  CDmAttribute *Attribute; // ebx
  const char *m_pAsString; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  Attribute = CDmElement::FirstAttribute(this: &this->CDmElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v7 = (CDmAttribute **)attrs->m_pMemory;
        v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: (unsigned __int8 *)&v7[m_pMemory + 1], src: (unsigned __int8 *)&v7[m_pMemory], count: 4 * v8);
        v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v9 != nullptr )
          *v9 = Attribute;
      }
      Attribute = Attribute->m_pNext;
    }
    while ( Attribute != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = (int)attrs[1].m_pMemory;
  v12 = attrs->m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v11 - v12 + 1);
  ++attrs[1].m_pMemory;
  v13 = (CDmAttribute **)attrs->m_pMemory;
  v14 = (int)attrs[1].m_pMemory - v11 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v13[v11 + 1], src: (unsigned __int8 *)&v13[v11], count: 4 * v14);
  v15 = (CDmAttribute **)&attrs->m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x1058E890
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
  m_pMemory = (int)attrs[1].m_pMemory;
  if ( m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
  ++attrs[1].m_pMemory;
  v5 = (CDmAttribute **)attrs->m_pMemory;
  v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
  v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x1058E960
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1058EA30
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1058EA60
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1058EAB0
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x1058EAD0
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_calc.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x105C8FF0
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 0xB4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD810
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9020
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9030
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD820
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051C750
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x0051C7C0
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  const char *m_pAsString; // eax
  CDmAttribute *i; // esi
  const char *v4; // eax
  const char *v5; // edi
  CDmaVar<float> *m_pData; // eax
  int v7; // ecx
  float oldValue; // [esp+10h] [ebp-4h] BYREF

  m_pAsString = this->m_expr.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = str;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_pAsString);
  for ( i = CDmElement::FirstAttribute(this: &this->CDmElement); i != nullptr; i = i->m_pNext )
  {
    v4 = i->m_Name.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = str;
    if ( _V_strcmp(s1: v4, s2: "result") != 0 && (i->m_nFlags & 0x1F) == 3 )
    {
      v5 = str;
      if ( i->m_Name.u.m_Id != -1 )
        v5 = i->m_Name.u.m_pAsString;
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i->m_nFlags & 0x1F) == 3 )
      {
        m_pData = (CDmaVar<float> *)i->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: i) )
      {
        CDmAttribute::CopyDataOut<float>(this: i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: m_pData->m_Storage);
    }
  }
  oldValue = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: &oldValue);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: &oldValue);
  if ( this->m_bSpewResult.m_Storage )
    _Msg(a1: v7, a2: "%s = '%f'\n");
}

//------------------------------------------------------------------------------
// Address: 0x0051C910
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmeExpressionOperator *v2; // edi
  CDmAttribute *Attribute; // ebx
  const char *m_pAsString; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  Attribute = CDmElement::FirstAttribute(this: &this->CDmElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = str;
      if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v7 = (CDmAttribute **)attrs->m_pMemory;
        v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
        v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v9 != nullptr )
          *v9 = Attribute;
      }
      Attribute = Attribute->m_pNext;
    }
    while ( Attribute != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = (int)attrs[1].m_pMemory;
  v12 = attrs->m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v11 - v12 + 1);
  ++attrs[1].m_pMemory;
  v13 = (CDmAttribute **)attrs->m_pMemory;
  v14 = (int)attrs[1].m_pMemory - v11 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = (CDmAttribute **)&attrs->m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0051CA10
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
  m_pMemory = (int)attrs[1].m_pMemory;
  if ( m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
  ++attrs[1].m_pMemory;
  v5 = (CDmAttribute **)attrs->m_pMemory;
  v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
  v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0051CAE0
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051CBB0
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051CBE0
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051CC30
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0051CC50
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0056C1A0
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056ECE0
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C1D0
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C1E0
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056ECF0
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00522970
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x005229E0
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  const char *m_pAsString; // eax
  CDmAttribute *i; // esi
  const char *v4; // eax
  const char *v5; // edi
  CDmaVar<float> *m_pData; // eax
  int v7; // ecx
  float oldValue; // [esp+10h] [ebp-4h] BYREF

  m_pAsString = this->m_expr.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pParentName;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_pAsString);
  for ( i = CDmElement::FirstAttribute(this: &this->CDmElement); i != nullptr; i = i->m_pNext )
  {
    v4 = i->m_Name.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = &pParentName;
    if ( _V_strcmp(s1: v4, s2: "result") != 0 && (i->m_nFlags & 0x1F) == 3 )
    {
      v5 = &pParentName;
      if ( i->m_Name.u.m_Id != -1 )
        v5 = i->m_Name.u.m_pAsString;
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i->m_nFlags & 0x1F) == 3 )
      {
        m_pData = (CDmaVar<float> *)i->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: i) )
      {
        CDmAttribute::CopyDataOut<float>(this: i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: m_pData->m_Storage);
    }
  }
  oldValue = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: &oldValue);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: &oldValue);
  if ( this->m_bSpewResult.m_Storage )
    _Msg(a1: v7, a2: "%s = '%f'\n");
}

//------------------------------------------------------------------------------
// Address: 0x00522B30
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeExpressionOperator *v2; // edi
  CDmAttribute *Attribute; // ebx
  const char *m_pAsString; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  Attribute = CDmElement::FirstAttribute(this: &this->CDmElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v8 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = Attribute;
      }
      Attribute = Attribute->m_pNext;
    }
    while ( Attribute != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = attrs->m_Size;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v11 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v11 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00522C30
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
  m_Size = attrs->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: m_Size - m_nAllocationCount + 1);
  ++attrs->m_Size;
  m_pMemory = attrs->m_Memory.m_pMemory;
  v6 = attrs->m_Size - m_Size - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &attrs->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00522D00
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00522DD0
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522E00
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522E60
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00522E80
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2C0
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE10
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2F0
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C300
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE20
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DF880
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x005DF8F0
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  const char *m_pAsString; // eax
  CDmAttribute *i; // esi
  const char *v4; // eax
  const char *v5; // edi
  CDmaVar<float> *m_pData; // eax
  const char *v7; // eax
  float oldValue; // [esp+10h] [ebp-4h] BYREF

  m_pAsString = this->m_expr.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_pAsString);
  for ( i = CDmElement::FirstAttribute(this: &this->CDmElement); i != nullptr; i = i->m_pNext )
  {
    v4 = i->m_Name.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = defaultValue;
    if ( _V_strcmp(s1: v4, s2: "result") != 0 && (i->m_nFlags & 0x1F) == 3 )
    {
      v5 = defaultValue;
      if ( i->m_Name.u.m_Id != -1 )
        v5 = i->m_Name.u.m_pAsString;
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i->m_nFlags & 0x1F) == 3 )
      {
        m_pData = (CDmaVar<float> *)i->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: i) )
      {
        CDmAttribute::CopyDataOut<float>(this: i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: m_pData->m_Storage);
    }
  }
  oldValue = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: &oldValue);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: &oldValue);
  if ( this->m_bSpewResult.m_Storage )
  {
    v7 = this->m_Name.m_Storage.u.m_pAsString;
    if ( v7 == (const char *)-1 )
      v7 = defaultValue;
    _Msg(a1: "%s = '%f'\n", v7, this->m_result.m_Storage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DFA40
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmeExpressionOperator *v2; // edi
  CDmAttribute *Attribute; // ebx
  const char *m_pAsString; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v7; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  Attribute = CDmElement::FirstAttribute(this: &this->CDmElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v7 = (CDmAttribute **)attrs->m_pMemory;
        v8 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
        v9 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v9 != nullptr )
          *v9 = Attribute;
      }
      Attribute = Attribute->m_pNext;
    }
    while ( Attribute != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = (int)attrs[1].m_pMemory;
  v12 = attrs->m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v11 - v12 + 1);
  ++attrs[1].m_pMemory;
  v13 = (CDmAttribute **)attrs->m_pMemory;
  v14 = (int)attrs[1].m_pMemory - v11 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = (CDmAttribute **)&attrs->m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005DFB40
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
  m_pMemory = (int)attrs[1].m_pMemory;
  if ( m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
  ++attrs[1].m_pMemory;
  v5 = (CDmAttribute **)attrs->m_pMemory;
  v6 = (int)attrs[1].m_pMemory - m_pMemory - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
  v7 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005DFC10
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DFCE0
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DFD10
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DFD70
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005DFD90
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_calc.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x006B1410
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5600
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1440
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1450
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5610
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00523B80
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x00523BF0
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  const char *m_pAsString; // eax
  CDmAttribute *i; // esi
  const char *v4; // eax
  const char *v5; // edi
  CDmaVar<float> *m_pData; // eax
  int v7; // ecx
  float oldValue; // [esp+10h] [ebp-4h] BYREF

  m_pAsString = this->m_expr.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pch;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_pAsString);
  for ( i = CDmElement::FirstAttribute(this: &this->CDmElement); i != nullptr; i = i->m_pNext )
  {
    v4 = i->m_Name.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = &pch;
    if ( _V_strcmp(s1: v4, s2: "result") != 0 && (i->m_nFlags & 0x1F) == 3 )
    {
      v5 = &pch;
      if ( i->m_Name.u.m_Id != -1 )
        v5 = i->m_Name.u.m_pAsString;
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i->m_nFlags & 0x1F) == 3 )
      {
        m_pData = (CDmaVar<float> *)i->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: i) )
      {
        CDmAttribute::CopyDataOut<float>(this: i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: m_pData->m_Storage);
    }
  }
  oldValue = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: &oldValue);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: &oldValue);
  if ( this->m_bSpewResult.m_Storage )
    _Msg(a1: v7, a2: "%s = '%f'\n");
}

//------------------------------------------------------------------------------
// Address: 0x00523D40
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeExpressionOperator *v2; // edi
  CDmAttribute *Attribute; // ebx
  const char *m_pAsString; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  Attribute = CDmElement::FirstAttribute(this: &this->CDmElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pch;
      if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v8 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = Attribute;
      }
      Attribute = Attribute->m_pNext;
    }
    while ( Attribute != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = attrs->m_Size;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v11 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v11 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00523E40
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
  m_Size = attrs->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: m_Size - m_nAllocationCount + 1);
  ++attrs->m_Size;
  m_pMemory = attrs->m_Memory.m_pMemory;
  v6 = attrs->m_Size - m_Size - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &attrs->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00523F10
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00523FE0
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524010
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524060
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00524080
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0057E290
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580DF0
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2C0
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2D0
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580E00
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0052B080
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x0052B0F0
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  const char *m_pAsString; // eax
  CDmAttribute *i; // esi
  const char *v4; // eax
  const char *v5; // edi
  CDmaVar<float> *m_pData; // eax
  const char *v7; // eax
  float oldValue; // [esp+10h] [ebp-4h] BYREF

  m_pAsString = this->m_expr.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = Ptr;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_pAsString);
  for ( i = CDmElement::FirstAttribute(this: &this->CDmElement); i != nullptr; i = i->m_pNext )
  {
    v4 = i->m_Name.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = Ptr;
    if ( _V_strcmp(s1: v4, s2: "result") != 0 && (i->m_nFlags & 0x1F) == 3 )
    {
      v5 = Ptr;
      if ( i->m_Name.u.m_Id != -1 )
        v5 = i->m_Name.u.m_pAsString;
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i->m_nFlags & 0x1F) == 3 )
      {
        m_pData = (CDmaVar<float> *)i->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: i) )
      {
        CDmAttribute::CopyDataOut<float>(this: i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: m_pData->m_Storage);
    }
  }
  oldValue = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: &oldValue);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: &oldValue);
  if ( this->m_bSpewResult.m_Storage )
  {
    v7 = this->m_Name.m_Storage.u.m_pAsString;
    if ( v7 == (const char *)-1 )
      v7 = Ptr;
    _Msg(a1: "%s = '%f'\n", v7, this->m_result.m_Storage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052B240
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeExpressionOperator *v2; // edi
  CDmAttribute *Attribute; // ebx
  const char *m_pAsString; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  Attribute = CDmElement::FirstAttribute(this: &this->CDmElement);
  if ( Attribute != nullptr )
  {
    do
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      if ( _V_strcmp(s1: m_pAsString, s2: "result") != 0 && (Attribute->m_nFlags & 0x1F) == 3 )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v8 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = Attribute;
      }
      Attribute = Attribute->m_pNext;
    }
    while ( Attribute != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = attrs->m_Size;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v11 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v11 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0052B340
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
  m_Size = attrs->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: m_Size - m_nAllocationCount + 1);
  ++attrs->m_Size;
  m_pMemory = attrs->m_Memory.m_pMemory;
  v6 = attrs->m_Size - m_Size - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &attrs->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0052B410
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052B4E0
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B510
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B560
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0052B580
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_stack);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0057BAE0
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 180,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4E0
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB10
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB20
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4F0
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062E090
// Name: protected: void CDmeExpressionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::OnConstruction(CDmeExpressionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_result.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "result",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_result);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_expr.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v3,
                                pAttributeName: "expr",
                                type: AT_STRING,
                                pMemory: &this->m_expr);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_bSpewResult.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this: v4,
                                       pAttributeName: "spewresult",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bSpewResult);
}

//------------------------------------------------------------------------------
// Address: 0x0062E100
// Name: public: virtual void CDmeExpressionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::Operate(CDmeExpressionOperator *this)
{
  const char *m_pAsString; // eax
  unsigned __int8 *i; // esi
  const char *v4; // eax
  const char *v5; // edi
  CDmaVar<float> *v6; // eax
  const char *v7; // eax
  float oldValue; // [esp+10h] [ebp-4h] BYREF

  m_pAsString = this->m_expr.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  CUtlString::operator=(this: &this->m_calc.m_expr, src: m_pAsString);
  for ( i = CVTFTexture::ImageData(this: (CVTFTexture *)&this->CDmElement); i != nullptr; i = *(unsigned __int8 **)i )
  {
    v4 = *((const char **)i + 5);
    if ( v4 == (const char *)-1 )
      v4 = var;
    if ( _V_strcmp(s1: v4, s2: "result") != 0 && (i[16] & 0x1F) == 3 )
    {
      v5 = var;
      if ( *((_DWORD *)i + 5) != -1 )
        v5 = *((const char **)i + 5);
      if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      if ( (i[16] & 0x1F) == 3 )
      {
        v6 = *((CDmaVar<float> **)i + 1);
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: (CDmAttribute *)i) )
      {
        CDmAttribute::CopyDataOut<float>(this: (CDmAttribute *)i, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
        v6 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
      }
      else
      {
        v6 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
      }
      CExpressionCalculator::SetVariable(this: &this->m_calc, var: v5, value: v6->m_Storage);
    }
  }
  oldValue = this->m_result.m_Storage;
  CExpressionCalculator::Evaluate(this: &this->m_calc, value: &oldValue);
  CDmAttribute::SetValue<float>(this: this->m_result.m_pAttribute, value: &oldValue);
  if ( this->m_bSpewResult.m_Storage )
  {
    v7 = this->m_Name.m_Storage.u.m_pAsString;
    if ( v7 == (const char *)-1 )
      v7 = var;
    _Msg(a1: "%s = '%f'\n", v7, this->m_result.m_Storage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E250
// Name: public: virtual void CDmeExpressionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetInputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeExpressionOperator *v2; // edi
  unsigned __int8 *v3; // ebx
  const char *v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v8; // eax
  CDmAttribute **v9; // eax
  CDmAttribute *m_pAttribute; // ebx
  int v11; // edi
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax

  v2 = this;
  v3 = CVTFTexture::ImageData(this: (CVTFTexture *)&this->CDmElement);
  if ( v3 != nullptr )
  {
    do
    {
      v4 = *((const char **)v3 + 5);
      if ( v4 == (const char *)-1 )
        v4 = var;
      if ( _V_strcmp(s1: v4, s2: "result") != 0 && (v3[16] & 0x1F) == 3 )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v8 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = (CDmAttribute *)v3;
      }
      v3 = *(unsigned __int8 **)v3;
    }
    while ( v3 != nullptr );
    v2 = this;
  }
  m_pAttribute = v2->m_expr.m_pAttribute;
  v11 = attrs->m_Size;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v11 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v11 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0062E350
// Name: public: virtual void CDmeExpressionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::GetOutputAttributes(
        CDmeExpressionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_result.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
  m_Size = attrs->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: m_Size - m_nAllocationCount + 1);
  ++attrs->m_Size;
  m_pMemory = attrs->m_Memory.m_pMemory;
  v6 = attrs->m_Size - m_Size - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &attrs->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0062E420
// Name: protected: CDmeExpressionOperator::CDmeExpressionOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeExpressionOperator *__thiscall CDmeExpressionOperator::CDmeExpressionOperator(
        CDmeExpressionOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlString::CUtlString(this: &this->m_calc.m_expr, pString: nullptr);
  this->m_calc.m_varNames.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varNames.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varNames.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varNames.m_Size = 0;
  this->m_calc.m_varNames.m_pElements = nullptr;
  this->m_calc.m_varValues.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_varValues.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_varValues.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_varValues.m_Size = 0;
  this->m_calc.m_varValues.m_pElements = nullptr;
  this->m_calc.m_stack.m_Memory.m_pMemory = nullptr;
  this->m_calc.m_stack.m_Memory.m_nAllocationCount = 0;
  this->m_calc.m_stack.m_Memory.m_nGrowSize = 0;
  this->m_calc.m_stack.m_Size = 0;
  this->m_calc.m_stack.m_pElements = nullptr;
  this->m_result.m_pAttribute = nullptr;
  this->m_result.m_Storage = 0.0;
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
  this->m_bSpewResult.m_pAttribute = nullptr;
  this->m_bSpewResult.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062E4F0
// Name: public: virtual bool CDmeExpressionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeExpressionOperator::IsA(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062E520
// Name: public: virtual int CDmeExpressionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeExpressionOperator::GetInheritanceDepth(CDmeExpressionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeExpressionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062E580
// Name: protected: virtual void CDmeExpressionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::PerformConstruction(CDmeExpressionOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
  CDmeExpressionOperator::OnConstruction(this: (CDmeExpressionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0062E5A0
// Name: protected: virtual CDmeExpressionOperator::~CDmeExpressionOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeExpressionOperator::~CDmeExpressionOperator(CDmeExpressionOperator *this)
{
  bool v2; // sf

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeExpressionOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeExpressionOperator::`vftable'{for `CDmElement'};
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_calc.m_stack);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_calc.m_varValues);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_calc.m_varNames);
  v2 = this->m_calc.m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_calc.m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_calc.m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_calc.m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeExpressionOperator_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x006B9A50
// Name: _dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeExpressionOperator::s_Allocator,
    blockSize: 0xB4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeExpressionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD300
// Name: _dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeExpressionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeExpressionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9A80
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeExpressionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9A90
// Name: _dynamic_initializer_for__g_CDmeExpressionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeExpressionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeExpressionOperator_Helper,
           classname: "DmeExpressionOperator",
           pFactory: &g_CDmeExpressionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD310
// Name: _dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeExpressionOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeExpressionOperator_Factory.m_CallBackList);
}

} // namespace vmap
