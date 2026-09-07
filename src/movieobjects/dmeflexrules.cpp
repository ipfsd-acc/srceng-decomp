// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeflexrules.cpp
// Functions: 55
// ============================================================

#include "movieobjects\dmeflexrules.h"

//------------------------------------------------------------------------------
// Address: 0x0055D020
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_color.m_pAttribute;
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
// Address: 0x00565720
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = var;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565800
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00565920
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeFlexRuleBase::m_classType) && v7 != (CDmElement *)4 )
      {
        v8 = *(CDmAttribute **)&v7[1].m_Id.m_Value[4];
        if ( v8 != nullptr )
        {
          value.x = CDmAttribute::GetValue<float>(this: v8)->m_Storage;
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565A20
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFlexRuleBase::m_classType) )
      v6 = (char *)&v5[-1] + 64;
    else
      v6 = nullptr;
    v7 = *((const char **)v6 + 6);
    if ( v7 == (const char *)-1 )
      v7 = var;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00565AA0
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v9, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565B30
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v10, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CExpressionCalculator::VariableCount(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x00565C00
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(
        CDmeFlexRuleBase *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_Size; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v11, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_Size = attrs->m_Size;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v9 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565CA0
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  bool v9; // zf
  char *v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  const char *m_pAsString; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  char *v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFlexRuleBase::m_classType) )
        {
          v9 = v8 == (CDmElement *)4;
          v10 = (char *)&v8[-1] + 64;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = var;
              if ( *((_DWORD *)v10 + 6) != -1 )
                v13 = *((const char **)v10 + 6);
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              m_pAsString = v15->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = var;
              if ( _V_strcmp(s1: m_pAsString, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565E60
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  char *v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v8 - v9 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v8 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeFlexRuleBase::m_classType) )
      v17 = (char *)&v16[-1] + 64;
    else
      v17 = nullptr;
    (*(void (__thiscall **)(char *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))(*(_DWORD *)v17 + 16))(
      a1: v17,
      a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565F80
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005660D0
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566100
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566270
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005662B0
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566310
// Name: protected: virtual int CDmeFlexRuleBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x00566390
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x005664E0
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566520
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566650
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00566710
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566750
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005667B0
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x00566810
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x00566910
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005669B0
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005669E0
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566A30
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x00566A40
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005AECE0
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AED40
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEDA0
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEE00
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEE60
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0AF0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B00
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B10
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B20
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B30
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00565890
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeFlexRules *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AED10
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AED20
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AED70
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AED80
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AEDD0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEDE0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AEE30
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEE40
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AEE90
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEEA0
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B40
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B50
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B60
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B70
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0B80
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005C2C70
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = defaultValue;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C2D50
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005C2E70
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeFlexRuleBase::m_classType) && v7 != (CDmElement *)4 )
      {
        v8 = *(CDmAttribute **)&v7[1].m_Id.m_Value[4];
        if ( v8 != nullptr )
        {
          value.x = CDmAttribute::GetValue<float>(this: v8)->m_Storage;
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C2F70
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFlexRuleBase::m_classType) )
      v6 = (char *)&v5[-1] + 64;
    else
      v6 = nullptr;
    v7 = *((const char **)v6 + 6);
    if ( v7 == (const char *)-1 )
      v7 = defaultValue;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005C2FF0
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v9, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C3080
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v10, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CCodecBuffer_Block::GetBufferType(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x005C3150
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(CDmeFlexRuleBase *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_pMemory; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v11, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v8 = (CDmAttribute **)attrs->m_pMemory;
    v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
    v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C31F0
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_color.m_pAttribute;
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
// Address: 0x005C3250
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  bool v9; // zf
  char *v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  const char *m_pAsString; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  char *v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFlexRuleBase::m_classType) )
        {
          v9 = v8 == (CDmElement *)4;
          v10 = (char *)&v8[-1] + 64;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = defaultValue;
              if ( *((_DWORD *)v10 + 6) != -1 )
                v13 = *((const char **)v10 + 6);
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              m_pAsString = v15->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = defaultValue;
              if ( _V_strcmp(s1: m_pAsString, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C3410
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(CDmeFlexRules *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  char *v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v8 - v9 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v8 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeFlexRuleBase::m_classType) )
      v17 = (char *)&v16[-1] + 64;
    else
      v17 = nullptr;
    (*(void (__thiscall **)(char *, CUtlMemory<vgui::TreeNode *,int> *))(*(_DWORD *)v17 + 16))(a1: v17, a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C3530
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(CDmeFlexRules *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C3680
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C36B0
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C3780
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x005C3870
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C38B0
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C3A90
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C3AD0
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C3C00
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005C3CC0
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C3D00
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C3D70
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x005C3DD0
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x005C3ED0
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005C3F70
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C3FA0
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C3FF0
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x005C4000
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x006806A0
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00680700
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00680760
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006807C0
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00680820
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006830A0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006830B0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006830C0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006830D0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006830E0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005C2DE0
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeFlexRules *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006806D0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006806E0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00680730
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680740
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00680790
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006807A0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006807F0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680800
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00680850
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680860
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006830F0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683100
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683110
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683120
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683130
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104EFD60
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (char *)-1 )
      m_pAttribute = (char *)&var;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104EFE40
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x104EFF60
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeFlexRuleBase::m_classType) && v7 != (CDmElement *)4 )
      {
        v8 = *(CDmAttribute **)&v7[1].m_Id.m_Value[4];
        if ( v8 != nullptr )
        {
          value.x = CDmAttribute::GetValue<float>(this: v8)->m_Storage;
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F0060
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFlexRuleBase::m_classType) )
      v6 = (char *)&v5[-1] + 64;
    else
      v6 = nullptr;
    v7 = *((const char **)v6 + 6);
    if ( v7 == (const char *)-1 )
      v7 = &var;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x104F00E0
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v9, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F0170
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  _BYTE v10[4]; // [esp+10h] [ebp-Ch] BYREF
  float v11; // [esp+14h] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+18h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v10, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CCodecBuffer_Block::GetBufferType(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        x = 0.0;
      else
        x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value: x);
    }
    v1 = v12;
  }
  v11 = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &v11) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &v11);
}

//------------------------------------------------------------------------------
// Address: 0x104F0240
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(CDmeFlexRuleBase *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_pMemory; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v11, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v8 = (CDmAttribute **)attrs->m_pMemory;
    v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v8[m_pMemory + 1], src: (unsigned __int8 *)&v8[m_pMemory], count: 4 * v9);
    v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F02E0
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  bool v9; // zf
  char *v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  const char *m_pAsString; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  char *v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFlexRuleBase::m_classType) )
        {
          v9 = v8 == (CDmElement *)4;
          v10 = (char *)&v8[-1] + 64;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = &var;
              if ( *((_DWORD *)v10 + 6) != -1 )
                v13 = *((const char **)v10 + 6);
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              m_pAsString = v15->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = &var;
              if ( _V_strcmp(s1: m_pAsString, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F04A0
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(CDmeFlexRules *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  char *v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v8 - v9 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v8 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[v8 + 1], src: (unsigned __int8 *)&v11[v8], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeFlexRuleBase::m_classType) )
      v17 = (char *)&v16[-1] + 64;
    else
      v17 = nullptr;
    (*(void (__thiscall **)(char *, CUtlMemory<vgui::TreeNode *,int> *))(*(_DWORD *)v17 + 16))(a1: v17, a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F05C0
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(CDmeFlexRules *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v6[m_pMemory + 1], src: (unsigned __int8 *)&v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F0710
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F0740
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F08C0
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F0900
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F09D0
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x104F0B20
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F0B60
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F0C90
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104F0D50
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F0D90
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F0DF0
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x104F0E50
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x104F0F50
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104F0FF0
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F1020
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F1090
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x104F10A0
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x1059AED0
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_flexWeight.m_pAttribute;
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
// Address: 0x105C7E90
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7EF0
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7F50
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 0xACu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7FB0
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C8020
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 0xA0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD250
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CD260
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CD270
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CD280
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CD290
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x104EFED0
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeFlexRules *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C7EC0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7ED0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7F20
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7F30
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7F80
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7F90
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7FE0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C8000
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C8050
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C8060
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD2A0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CD2B0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CD2C0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CD2D0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CD2E0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005AC5D0
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = pDeltaStateName;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AC6B0
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005AC7D0
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeFlexRuleBase::m_classType.u) != 0
        && v7 != 4 )
      {
        v8 = *(CDmAttribute **)(v7 - 4 + 80);
        if ( v8 != nullptr )
        {
          value.x = CDmAttribute::GetValue<float>(this: v8)->m_Storage;
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AC8D0
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeFlexRuleBase::m_classType.u) != 0 )
    {
      v6 = v5 - 4;
    }
    else
    {
      v6 = 0;
    }
    v7 = *(const char **)(v6 + 24);
    if ( v7 == (const char *)-1 )
      v7 = pDeltaStateName;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005AC950
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v9,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AC9E0
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v10,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CExpressionCalculator::VariableCount(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x005ACAB0
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(
        CDmeFlexRuleBase *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_pMemory; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v11,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v8 = (CDmAttribute **)attrs->m_pMemory;
    v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
    v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ACB50
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  int v14; // eax
  int v15; // esi
  const char *v16; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  int v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                         a1: g_pDataModel.u,
                         a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeFlexRuleBase::m_classType.u) != 0 )
        {
          v9 = v8 == 4;
          v10 = v8 - 4;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = pDeltaStateName;
              if ( *(_DWORD *)(v10 + 24) != -1 )
                v13 = *(const char **)(v10 + 24);
              v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
                     a1: v14,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v15 = 0;
              }
              v16 = *(const char **)(v15 + 20);
              if ( v16 == (const char *)-1 )
                v16 = pDeltaStateName;
              if ( _V_strcmp(s1: v16, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ACD10
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(
        CDmeFlexRules *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  int v15; // eax
  int v16; // edi
  int v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v8 - v9 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v8 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
           a1: v15,
           a2: CDmeFlexRuleBase::m_classType.u) != 0 )
    {
      v17 = v16 - 4;
    }
    else
    {
      v17 = 0;
    }
    (*(void (__thiscall **)(int, CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *))(*(_DWORD *)v17 + 16))(
      a1: v17,
      a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ACE30
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(
        CDmeFlexRules *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005ACFB0
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005ACFE0
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD170
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD1B0
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD280
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x005AD3D0
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD410
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD540
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AD600
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD640
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD6B0
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x005AD710
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_stack);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_varValues);
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x005AD810
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AD8B0
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD8E0
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD930
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x005AD940
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B4DC0
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_flexWeight.m_pAttribute;
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
// Address: 0x005F1A40
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1AA0
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1B00
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1B60
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1BC0
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A30
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A40
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A50
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A60
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A70
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AC740
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
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
  CDmeFlexRules *result; // eax
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
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
// Address: 0x005F1A70
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1A80
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1AD0
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1AE0
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1B30
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1B40
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1B90
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1BA0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1BF0
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1C00
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A80
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A90
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4AA0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4AB0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4AC0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051FE20
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_color.m_pAttribute;
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
// Address: 0x00523DD0
// Name: protected: virtual int CDmeFlexRuleBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x00529D70
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = str;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00529E50
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00529F80
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeFlexRuleBase::m_classType) && v7 != (CDmElement *)4 )
      {
        v8 = *(CDmAttribute **)&v7[1].m_Id.m_Value[4];
        if ( v8 != nullptr )
        {
          value.x = *CDmAttribute::GetValue<float>(this: v8);
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A080
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFlexRuleBase::m_classType) )
      v6 = (char *)&v5[-1] + 64;
    else
      v6 = nullptr;
    v7 = *((const char **)v6 + 6);
    if ( v7 == (const char *)-1 )
      v7 = str;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052A100
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v9, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A190
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v10, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CExpressionCalculator::VariableCount(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x0052A260
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(
        CDmeFlexRuleBase *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_pMemory; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v11, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v8 = (CDmAttribute **)attrs->m_pMemory;
    v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
    v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A300
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  bool v9; // zf
  char *v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  const char *m_pAsString; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  char *v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFlexRuleBase::m_classType) )
        {
          v9 = v8 == (CDmElement *)4;
          v10 = (char *)&v8[-1] + 64;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = str;
              if ( *((_DWORD *)v10 + 6) != -1 )
                v13 = *((const char **)v10 + 6);
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              m_pAsString = v15->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = str;
              if ( _V_strcmp(s1: m_pAsString, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A4C0
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(
        CDmeFlexRules *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  char *v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v8 - v9 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v8 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeFlexRuleBase::m_classType) )
      v17 = (char *)&v16[-1] + 64;
    else
      v17 = nullptr;
    (*(void (__thiscall **)(char *, CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *))(*(_DWORD *)v17 + 16))(
      a1: v17,
      a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A5E0
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(
        CDmeFlexRules *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A730
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052A760
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052A8D0
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052A910
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052AAF0
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052AB30
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052AC00
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x0052ACA0
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052AD60
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052ADA0
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052AE00
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x0052AE60
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0052AF60
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052B000
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B030
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B080
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x0052B090
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0056D280
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D2E0
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D340
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D3A0
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D400
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F280
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056F290
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056F2A0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056F2B0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056F2C0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00529EE0
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeFlexRules *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056D2B0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D2C0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056D310
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D320
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056D370
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D380
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056D3D0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D3E0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056D430
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D440
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F2D0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F2E0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F2F0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F300
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F310
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00524AB0
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_color.m_pAttribute;
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
// Address: 0x00532170
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = &pParentName;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532250
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00532370
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeFlexRuleBase::m_classType) && v7 != (CDmElement *)4 )
      {
        v8 = *(CDmAttribute **)&v7[1].m_Id.m_Value[4];
        if ( v8 != nullptr )
        {
          value.x = CDmAttribute::GetValue<float>(this: v8)->m_Storage;
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532470
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFlexRuleBase::m_classType) )
      v6 = (char *)&v5[-1] + 64;
    else
      v6 = nullptr;
    v7 = *((const char **)v6 + 6);
    if ( v7 == (const char *)-1 )
      v7 = &pParentName;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005324F0
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v9, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532580
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v10, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CExpressionCalculator::VariableCount(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x00532650
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(
        CDmeFlexRuleBase *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_Size; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v11, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_Size = attrs->m_Size;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v9 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005326F0
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  bool v9; // zf
  char *v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  const char *m_pAsString; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  char *v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFlexRuleBase::m_classType) )
        {
          v9 = v8 == (CDmElement *)4;
          v10 = (char *)&v8[-1] + 64;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = &pParentName;
              if ( *((_DWORD *)v10 + 6) != -1 )
                v13 = *((const char **)v10 + 6);
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              m_pAsString = v15->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = &pParentName;
              if ( _V_strcmp(s1: m_pAsString, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005328B0
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  char *v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v8 - v9 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v8 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeFlexRuleBase::m_classType) )
      v17 = (char *)&v16[-1] + 64;
    else
      v17 = nullptr;
    (*(void (__thiscall **)(char *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))(*(_DWORD *)v17 + 16))(
      a1: v17,
      a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005329D0
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532B20
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532B50
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532BA0
// Name: protected: virtual int CDmeFlexRuleBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x00532CD0
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532D10
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532EF0
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532F30
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533000
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x005330A0
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00533160
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005331A0
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533210
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x00533270
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x00533370
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00533410
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533440
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533490
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x005334A0
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057D3A0
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D400
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D460
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D4C0
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D520
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F3B0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F3C0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F3D0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F3E0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F3F0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005322E0
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeFlexRules *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057D3D0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D3E0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D430
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D440
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D490
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D4A0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D4F0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D500
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D550
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D560
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F400
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F410
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F420
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F430
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F440
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005F0460
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = defaultValue;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F0540
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005F0660
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeFlexRuleBase::m_classType.u) != 0
        && v7 != 4 )
      {
        v8 = *(CDmAttribute **)(v7 - 4 + 80);
        if ( v8 != nullptr )
        {
          value.x = *CDmAttribute::GetValue<float>(this: v8);
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F0760
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeFlexRuleBase::m_classType.u) != 0 )
    {
      v6 = v5 - 4;
    }
    else
    {
      v6 = 0;
    }
    v7 = *(const char **)(v6 + 24);
    if ( v7 == (const char *)-1 )
      v7 = defaultValue;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005F07E0
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v9,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F0870
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v10,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CCodecBuffer_Block::GetBufferType(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x005F0940
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(CDmeFlexRuleBase *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_pMemory; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v11,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v8 = (CDmAttribute **)attrs->m_pMemory;
    v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
    v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F09E0
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_color.m_pAttribute;
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
// Address: 0x005F0A40
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  int v14; // eax
  int v15; // esi
  const char *v16; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  int v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                         a1: g_pDataModel.u,
                         a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeFlexRuleBase::m_classType.u) != 0 )
        {
          v9 = v8 == 4;
          v10 = v8 - 4;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = defaultValue;
              if ( *(_DWORD *)(v10 + 24) != -1 )
                v13 = *(const char **)(v10 + 24);
              v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
                     a1: v14,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v15 = 0;
              }
              v16 = *(const char **)(v15 + 20);
              if ( v16 == (const char *)-1 )
                v16 = defaultValue;
              if ( _V_strcmp(s1: v16, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F0C00
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(CDmeFlexRules *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  int v15; // eax
  int v16; // edi
  int v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v8 - v9 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v8 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
           a1: v15,
           a2: CDmeFlexRuleBase::m_classType.u) != 0 )
    {
      v17 = v16 - 4;
    }
    else
    {
      v17 = 0;
    }
    (*(void (__thiscall **)(int, CUtlMemory<vgui::TreeNode *,int> *))(*(_DWORD *)v17 + 16))(a1: v17, a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F0D20
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(CDmeFlexRules *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F0E70
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F0EA0
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F1010
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F1050
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F1120
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x005F1270
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F12B0
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F13E0
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005F14A0
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F14E0
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F1540
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x005F15A0
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x005F16A0
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005F1740
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F1770
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F17C0
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x005F17D0
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x006B2500
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2560
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B25C0
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2620
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2680
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5BA0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5BB0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5BC0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5BD0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5BE0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F05D0
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
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
  CDmeFlexRules *result; // eax
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
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
// Address: 0x006B2530
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2540
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B2590
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B25A0
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B25F0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2600
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B2650
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2660
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B26B0
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B26C0
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5BF0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C00
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C10
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C20
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5C30
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00533300
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = &pch;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005333E0
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00533500
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeFlexRuleBase::m_classType) && v7 != (CDmElement *)4 )
      {
        v8 = *(CDmAttribute **)&v7[1].m_Id.m_Value[4];
        if ( v8 != nullptr )
        {
          value.x = *CDmAttribute::GetValue<float>(this: v8);
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533600
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFlexRuleBase::m_classType) )
      v6 = (char *)&v5[-1] + 64;
    else
      v6 = nullptr;
    v7 = *((const char **)v6 + 6);
    if ( v7 == (const char *)-1 )
      v7 = &pch;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00533680
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v9, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533710
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v10, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CExpressionCalculator::VariableCount(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x005337E0
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(
        CDmeFlexRuleBase *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_Size; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v11, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_Size = attrs->m_Size;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v9 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533880
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_color.m_pAttribute;
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
// Address: 0x005338E0
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  bool v9; // zf
  char *v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  const char *m_pAsString; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  char *v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFlexRuleBase::m_classType) )
        {
          v9 = v8 == (CDmElement *)4;
          v10 = (char *)&v8[-1] + 64;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = &pch;
              if ( *((_DWORD *)v10 + 6) != -1 )
                v13 = *((const char **)v10 + 6);
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              m_pAsString = v15->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = &pch;
              if ( _V_strcmp(s1: m_pAsString, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533AA0
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  char *v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v8 - v9 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v8 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeFlexRuleBase::m_classType) )
      v17 = (char *)&v16[-1] + 64;
    else
      v17 = nullptr;
    (*(void (__thiscall **)(char *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))(*(_DWORD *)v17 + 16))(
      a1: v17,
      a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533BC0
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533D10
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533D40
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533EB0
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533EF0
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005340E0
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00534120
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00534180
// Name: protected: virtual int CDmeFlexRuleBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x00534200
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x005342A0
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00534360
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005343A0
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00534400
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x00534460
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x00534560
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00534600
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00534630
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00534680
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x00534690
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057F380
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F4A0
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F500
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581390
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005813A0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005813B0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005813C0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005813D0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00533470
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeFlexRules *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057F470
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F480
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F4D0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F4E0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F530
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F540
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005813E0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005813F0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581400
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581410
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581420
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A5500
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = pDeltaStateName;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A55E0
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005A5700
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeFlexRuleBase::m_classType.u) != 0
        && v7 != 4 )
      {
        v8 = *(CDmAttribute **)(v7 - 4 + 80);
        if ( v8 != nullptr )
        {
          value.x = CDmAttribute::GetValue<float>(this: v8)->m_Storage;
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A5800
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeFlexRuleBase::m_classType.u) != 0 )
    {
      v6 = v5 - 4;
    }
    else
    {
      v6 = 0;
    }
    v7 = *(const char **)(v6 + 24);
    if ( v7 == (const char *)-1 )
      v7 = pDeltaStateName;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005A5880
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v9,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A5910
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v10,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CExpressionCalculator::VariableCount(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x005A59E0
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(
        CDmeFlexRuleBase *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_pMemory; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v11,
                            a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v8 = (CDmAttribute **)attrs->m_pMemory;
    v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
    v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A5A80
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeGlobalFlexControllerOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_flexWeight.m_pAttribute;
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
// Address: 0x005A5AE0
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  int v14; // eax
  int v15; // esi
  const char *v16; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  int v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmAttribute *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                         a1: g_pDataModel.u,
                         a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeFlexRuleBase::m_classType.u) != 0 )
        {
          v9 = v8 == 4;
          v10 = v8 - 4;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = pDeltaStateName;
              if ( *(_DWORD *)(v10 + 24) != -1 )
                v13 = *(const char **)(v10 + 24);
              v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
                     a1: v14,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v15 = 0;
              }
              v16 = *(const char **)(v15 + 20);
              if ( v16 == (const char *)-1 )
                v16 = pDeltaStateName;
              if ( _V_strcmp(s1: v16, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A5CA0
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(
        CDmeFlexRules *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  int v15; // eax
  int v16; // edi
  int v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v8 - v9 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v8 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
           a1: v15,
           a2: CDmeFlexRuleBase::m_classType.u) != 0 )
    {
      v17 = v16 - 4;
    }
    else
    {
      v17 = 0;
    }
    (*(void (__thiscall **)(int, CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *))(*(_DWORD *)v17 + 16))(
      a1: v17,
      a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A5DC0
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(
        CDmeFlexRules *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A5F10
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A5F40
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A60B0
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A60F0
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A62D0
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A6310
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A63E0
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x005A6480
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A6540
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A6580
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A6600
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x005A6660
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_stack);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_calc.m_varValues);
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x005A6760
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A6800
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A6830
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A6880
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x005A6890
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005EA8F0
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA950
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA9B0
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAA10
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAA70
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8D0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8E0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8F0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED900
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED910
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005A5670
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
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
  CDmeFlexRules *result; // eax
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
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
// Address: 0x005EA920
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA930
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EA980
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA990
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EA9E0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA9F0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EAA40
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAA50
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EAAA0
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAAB0
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED920
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED930
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED940
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED950
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED960
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00529300
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_color.m_pAttribute;
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
// Address: 0x00529F00
// Name: protected: virtual int CDmeFlexRuleBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x005386F0
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = Ptr;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005387D0
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005388F0
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeFlexRuleBase::m_classType) && v7 != (CDmElement *)4 )
      {
        v8 = *(CDmAttribute **)&v7[1].m_Id.m_Value[4];
        if ( v8 != nullptr )
        {
          value.x = *CDmAttribute::GetValue<float>(this: v8);
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005389F0
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFlexRuleBase::m_classType) )
      v6 = (char *)&v5[-1] + 64;
    else
      v6 = nullptr;
    v7 = *((const char **)v6 + 6);
    if ( v7 == (const char *)-1 )
      v7 = Ptr;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00538A70
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v9, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538B00
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v10, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CExpressionCalculator::VariableCount(this: p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x00538BD0
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(
        CDmeFlexRuleBase *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_Size; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v11, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_Size = attrs->m_Size;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v9 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538C70
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  bool v9; // zf
  char *v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  const char *m_pAsString; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  char *v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFlexRuleBase::m_classType) )
        {
          v9 = v8 == (CDmElement *)4;
          v10 = (char *)&v8[-1] + 64;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = Ptr;
              if ( *((_DWORD *)v10 + 6) != -1 )
                v13 = *((const char **)v10 + 6);
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              m_pAsString = v15->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = Ptr;
              if ( _V_strcmp(s1: m_pAsString, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538E30
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  char *v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v8 - v9 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v8 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeFlexRuleBase::m_classType) )
      v17 = (char *)&v16[-1] + 64;
    else
      v17 = nullptr;
    (*(void (__thiscall **)(char *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))(*(_DWORD *)v17 + 16))(
      a1: v17,
      a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00538F50
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005390A0
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005390D0
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00539190
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x00539280
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005392C0
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005394A0
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005394E0
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00539610
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005396D0
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00539710
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00539770
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x005397D0
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x005398D0
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00539970
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005399A0
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005399F0
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x00539A00
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057CBC0
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CC20
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CC80
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CCE0
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD40
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 160,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA80
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA90
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EAA0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EAB0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EAC0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00538860
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeFlexRules *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057CBF0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CC00
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CC50
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CC60
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CCB0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CCC0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD10
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD20
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD70
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD80
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EAD0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EAE0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EAF0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB00
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB10
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x006284B0
// Name: protected: virtual int CDmeFlexRuleBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x00631830
// Name: public: virtual void CDmeFlexRuleBase::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_color.m_pAttribute;
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
// Address: 0x0063B7A0
// Name: public: virtual void CDmeFlexRuleExpression::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Resolve(CDmeFlexRuleExpression *this)
{
  const char *m_pAttribute; // eax
  CDmAttribute **p_m_pAttribute; // esi

  if ( *(char *)(this->m_expr.m_Storage.u.m_Id + 16) < 0 )
  {
    m_pAttribute = (const char *)this->m_flResult.m_pAttribute;
    if ( m_pAttribute == (const char *)-1 )
      m_pAttribute = var;
    p_m_pAttribute = &this->m_expr.m_pAttribute;
    CUtlString::operator=(this: (CUtlString *)&this->m_expr.m_pAttribute, src: m_pAttribute);
    CExpressionCalculator::BuildVariableListFromExpression(this: (CExpressionCalculator *)p_m_pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063B880
// Name: protected: void CDmeFlexRules::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::OnConstruction(CDmeFlexRules *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmaElement<CDmElement> *p_m_eTarget; // esi

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_eDeltaStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v2,
                                        pAttributeName: "deltaStates",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eDeltaStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDeltaStates.m_pAttribute, typeSymbol: CDmeFlexRuleBase::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  CDmaDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataInternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &this->m_vDeltaStateWeights,
    pOwner: v3,
    pAttributeName: "deltaStateWeights",
    nFlags: 0);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_eTarget = &this->m_eTarget;
  p_m_eTarget->m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v4,
                                pAttributeName: "target",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: p_m_eTarget);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eTarget->m_pAttribute, typeSymbol: CDmElement::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0063B9A0
// Name: public: virtual void CDmeFlexRules::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Operate(CDmeFlexRules *this)
{
  int m_Size; // eax
  CDmElement *v3; // esi
  int v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmAttribute *v8; // ecx
  Vector2D value; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrArray<Vector2D> targetWeights; // [esp+14h] [ebp-14h] BYREF
  int nTargetIndex; // [esp+1Ch] [ebp-Ch]
  int nTargetWeightCount; // [esp+20h] [ebp-8h]
  int v13; // [esp+24h] [ebp-4h]

  if ( this->m_deltaToTargetMap.m_Size <= 0 )
    this->Resolve(this: &this->CDmElement);
  m_Size = this->m_deltaToTargetMap.m_Size;
  v13 = this->m_eDeltaStates.m_Storage.m_Size;
  if ( v13 >= m_Size )
    v13 = m_Size;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v3,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  v4 = 0;
  for ( nTargetWeightCount = targetWeights.m_pStorage->m_Size; v4 < v13; ++v4 )
  {
    v5 = this->m_deltaToTargetMap.m_Memory.m_pMemory[v4];
    nTargetIndex = v5;
    if ( v5 >= 0 && v5 < nTargetWeightCount )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v4]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeFlexRuleBase::m_classType) && v7 != (CDmElement *)4 )
      {
        v8 = *(CDmAttribute **)&v7[1].m_Id.m_Value[4];
        if ( v8 != nullptr )
        {
          value.x = CDmAttribute::GetValue<float>(this: v8)->m_Storage;
          value.y = value.x;
          CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::Set(
            this: &targetWeights,
            i: nTargetIndex,
            &value);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063BAA0
// Name: public: int CDmeFlexRules::GetDeltaStateIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetDeltaStateIndex(CDmeFlexRules *this, const char *pszDeltaName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  char *v6; // eax
  const char *v7; // eax

  v3 = 0;
  if ( this->m_eDeltaStates.m_Storage.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFlexRuleBase::m_classType) )
      v6 = (char *)&v5[-1] + 64;
    else
      v6 = nullptr;
    v7 = *((const char **)v6 + 6);
    if ( v7 == (const char *)-1 )
      v7 = var;
    if ( _V_strcmp(s1: pszDeltaName, s2: v7) == 0 )
      break;
    if ( ++v3 >= this->m_eDeltaStates.m_Storage.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0063BB20
// Name: public: virtual void CDmeFlexRulePassThrough::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::Operate(CDmeFlexRulePassThrough *this)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  const char *m_pAsString; // eax
  int DeltaStateIndex; // eax
  float x; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  _BYTE v9[4]; // [esp+8h] [ebp-8h] BYREF
  float flResult; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v9, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: m_pAsString);
    if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
      x = 0.0;
    else
      x = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
    m_pAttribute = this->m_flResult.m_pAttribute;
    flResult = x;
    CDmAttribute::SetValue<float>(this: m_pAttribute, value: &flResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063BBB0
// Name: public: virtual void CDmeFlexRuleExpression::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::Operate(CDmeFlexRuleExpression *this)
{
  CDmeFlexRuleExpression *v1; // ebx
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // esi
  CExpressionCalculator *p_m_calc; // ebx
  int i; // edi
  const char *v7; // eax
  int DeltaStateIndex; // eax
  float value; // xmm0_4
  _BYTE v10[4]; // [esp+18h] [ebp-Ch] BYREF
  float flVal; // [esp+1Ch] [ebp-8h] BYREF
  CDmeFlexRuleExpression *v12; // [esp+20h] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v10, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    p_m_calc = &v1->m_calc;
    for ( i = 0; i < CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)p_m_calc); ++i )
    {
      v7 = CExpressionCalculator::VariableName(this: p_m_calc, nIndex: i);
      DeltaStateIndex = CDmeFlexRules::GetDeltaStateIndex(this: Referring, pszDeltaName: v7);
      if ( DeltaStateIndex < 0 || DeltaStateIndex >= Referring->m_vDeltaStateWeights.m_Storage.m_Size )
        value = 0.0;
      else
        value = Referring->m_vDeltaStateWeights.m_Storage.m_Memory.m_pMemory[DeltaStateIndex].x;
      CExpressionCalculator::SetVariable(this: p_m_calc, nVariableIndex: i, value);
    }
    v1 = v12;
  }
  flVal = 0.0;
  if ( CExpressionCalculator::Evaluate(this: &v1->m_calc, value: &flVal) )
    CDmAttribute::SetValue<float>(this: v1->m_flResult.m_pAttribute, value: &flVal);
}

//------------------------------------------------------------------------------
// Address: 0x0063BC80
// Name: public: virtual void CDmeFlexRuleBase::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleBase::GetInputAttributes(
        CDmeFlexRuleBase *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CUtlSymbolLarge *v3; // eax
  CDmeFlexRules *Referring; // eax
  int m_Size; // edi
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v11, a3: "deltaStates");
  Referring = FindReferringElement<CDmeFlexRules>(
                pElement: v2,
                symAttrName: (CUtlSymbolLarge)v3->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    m_Size = attrs->m_Size;
    m_pAttribute = Referring->m_vDeltaStateWeights.m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v9 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063BD20
// Name: public: virtual void CDmeFlexRules::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::Resolve(CDmeFlexRules *this)
{
  CDmeFlexRules *v1; // ebx
  int v2; // edi
  int m_nGrowSize; // ecx
  int v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  bool v9; // zf
  char *v10; // esi
  int j; // edi
  int v12; // eax
  const char *v13; // ebx
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  const char *m_pAsString; // eax
  CDmeFlexRules *v17; // eax
  CDmrElementArrayConst<CDmElement> targetStates; // [esp+Ch] [ebp-14h] BYREF
  char *v19; // [esp+14h] [ebp-Ch]
  CDmeFlexRules *v20; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  v20 = this;
  if ( this->m_deltaToTargetMap.m_Memory.m_nGrowSize <= 0
    || *(char *)(this->m_eTarget.m_Storage.m_ElementType.u.m_Id + 16) < 0
    || *(char *)(this->m_eDeltaStates.m_Storage.m_ElementType.u.m_Id + 16) < 0 )
  {
    m_nGrowSize = this->m_deltaToTargetMap.m_Memory.m_nGrowSize;
    v4 = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize;
    if ( v4 <= 0 )
    {
      if ( v4 < 0 )
        v1->m_deltaToTargetMap.m_Memory.m_nGrowSize = v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize;
    }
    else
    {
      CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&v1->m_eTarget.m_pAttribute,
        elem: m_nGrowSize,
        num: v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize - m_nGrowSize);
    }
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_vDeltaStateWeights.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetStates);
    if ( v5 != nullptr
      && (Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "deltaStates")) != nullptr
      && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      targetStates.m_pAttribute = Attribute;
      targetStates.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      targetStates.m_pAttribute = nullptr;
      targetStates.m_pStorage = nullptr;
    }
    i = 0;
    if ( v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize > 0 )
    {
      do
      {
        *((_DWORD *)&v1->m_eTarget.m_pAttribute->m_pNext + v2) = -1;
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v1->m_nSortKey + 4 * v2));
        v8 = v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFlexRuleBase::m_classType) )
        {
          v9 = v8 == (CDmElement *)4;
          v10 = (char *)&v8[-1] + 64;
          v19 = v10;
          if ( !v9 )
          {
            for ( j = 0; ; ++j )
            {
              v12 = targetStates.m_pAttribute != nullptr ? targetStates.m_pStorage->m_Size : 0;
              if ( j >= v12 )
                break;
              v13 = var;
              if ( *((_DWORD *)v10 + 6) != -1 )
                v13 = *((const char **)v10 + 6);
              v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: targetStates.m_pStorage->m_Memory.m_pMemory[j]);
              v15 = v14;
              if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmElement::m_classType) )
                v15 = nullptr;
              m_pAsString = v15->m_Name.m_Storage.u.m_pAsString;
              if ( m_pAsString == (const char *)-1 )
                m_pAsString = var;
              if ( _V_strcmp(s1: m_pAsString, s2: v13) == 0 )
              {
                v17 = v20;
                *((_DWORD *)&v20->m_eTarget.m_pAttribute->m_pNext + i) = j;
                v1 = v17;
                break;
              }
              v10 = v19;
              v1 = v20;
            }
            v2 = i;
          }
        }
        i = ++v2;
      }
      while ( v2 < v1->m_eDeltaStates.m_Storage.m_Memory.m_nGrowSize );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063BEE0
// Name: public: virtual void CDmeFlexRules::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetInputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // edi
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // edi
  int i; // ebx
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  char *v17; // ecx
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_eDeltaStates.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_vDeltaStateWeights.m_pAttribute;
  if ( v8 + 1 > v9 )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v8 - v9 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v8 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v8];
  if ( v13 != nullptr )
    *v13 = v10;
  for ( i = 0; i < this->m_eDeltaStates.m_Storage.m_Size; ++i )
  {
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eDeltaStates.m_Storage.m_Memory.m_pMemory[i]);
    v16 = v15;
    if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeFlexRuleBase::m_classType) )
      v17 = (char *)&v16[-1] + 64;
    else
      v17 = nullptr;
    (*(void (__thiscall **)(char *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))(*(_DWORD *)v17 + 16))(
      a1: v17,
      a2: attrs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063C000
// Name: public: virtual void CDmeFlexRules::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::GetOutputAttributes(
        CDmeFlexRules *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  int m_nAllocationCount; // eax
  CDmAttribute *m_pAttribute; // ebx
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmrArray<Vector2D> targetWeights; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_eTarget.m_Storage.m_Handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&targetWeights);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &targetWeights,
    pElement: v2,
    pAttributeName: "deltaStateWeights",
    bAddAttribute: false);
  if ( CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::IsValid(this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&targetWeights) )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_pAttribute = targetWeights.m_pAttribute;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = m_pAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063C150
// Name: public: virtual bool CDmeFlexRuleBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleBase::IsA(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063C180
// Name: public: virtual int CDmeFlexRuleBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleBase::GetInheritanceDepth(CDmeFlexRuleBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063C2F0
// Name: public: virtual bool CDmeFlexRulePassThrough::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRulePassThrough::IsA(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063C330
// Name: public: virtual int CDmeFlexRulePassThrough::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRulePassThrough::GetInheritanceDepth(CDmeFlexRulePassThrough *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRulePassThrough::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063C400
// Name: protected: virtual void CDmeFlexRulePassThrough::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRulePassThrough::PerformConstruction(CDmeFlexRuleLocalVar *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = (CDmeFlexRuleLocalVar *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
}

//------------------------------------------------------------------------------
// Address: 0x0063C550
// Name: public: virtual bool CDmeFlexRuleLocalVar::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleLocalVar::IsA(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063C590
// Name: public: virtual int CDmeFlexRuleLocalVar::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleLocalVar::GetInheritanceDepth(CDmeFlexRuleLocalVar *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleLocalVar::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063C6C0
// Name: protected: CDmeFlexRuleExpression::CDmeFlexRuleExpression(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *__thiscall CDmeFlexRuleExpression::CDmeFlexRuleExpression(
        CDmeFlexRuleExpression *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_flResult = 0;
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
  this->m_expr.m_pAttribute = nullptr;
  this->m_expr.m_Storage.u.m_Id = -1;
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063C780
// Name: public: virtual bool CDmeFlexRuleExpression::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRuleExpression::IsA(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063C7C0
// Name: public: virtual int CDmeFlexRuleExpression::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRuleExpression::GetInheritanceDepth(CDmeFlexRuleExpression *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRuleExpression::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFlexRuleBase::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063C820
// Name: protected: virtual void CDmeFlexRuleExpression::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::PerformConstruction(CDmeFlexRuleExpression *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = (CDmeFlexRuleExpression *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  v2[1].CDmElement::__vftable = (CDmElement_vtbl *)CDmElement::AddExternalAttribute(
                                                     this: v3,
                                                     pAttributeName: "result",
                                                     type: AT_FLOAT,
                                                     pMemory: &v2[1]);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v4,
                                        pAttributeName: "expr",
                                        type: AT_STRING,
                                        pMemory: &v2[1].m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x0063C880
// Name: protected: virtual CDmeFlexRuleExpression::~CDmeFlexRuleExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRuleExpression::~CDmeFlexRuleExpression(CDmeFlexRuleExpression *this)
{
  bool v2; // sf

  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRuleExpression::`vftable'{for `CDmElement'};
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
  this->CDmeFlexRuleBase::CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRuleExpression_vtbl *)&CDmeOperator::`vftable'{for `IDmeOperator'};
  this->CDmeFlexRuleBase::CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeOperator::`vftable'{for `CDmElement'};
  CDmElement::~CDmElement(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0063C980
// Name: protected: CDmeFlexRules::CDmeFlexRules(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeFlexRules *__thiscall CDmeFlexRules::CDmeFlexRules(
        CDmeFlexRules *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeFlexRules_vtbl *)&CDmeFlexRules::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeFlexRules::`vftable'{for `CDmElement'};
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eDeltaStates);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_vDeltaStateWeights);
  this->m_eTarget.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eTarget.m_pAttribute = nullptr;
  this->m_eTarget.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_deltaToTargetMap.m_Memory.m_pMemory = nullptr;
  this->m_deltaToTargetMap.m_Memory.m_nAllocationCount = 0;
  this->m_deltaToTargetMap.m_Memory.m_nGrowSize = 0;
  this->m_deltaToTargetMap.m_Size = 0;
  this->m_deltaToTargetMap.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063CA20
// Name: public: virtual bool CDmeFlexRules::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFlexRules::IsA(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063CA50
// Name: public: virtual int CDmeFlexRules::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::GetInheritanceDepth(CDmeFlexRules *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFlexRules::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063CAA0
// Name: protected: virtual int CDmeFlexRules::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFlexRules::AllocatedSize(CDmeFlexRules *this)
{
  return 160;
}

//------------------------------------------------------------------------------
// Address: 0x0063CAB0
// Name: protected: virtual void CDmeFlexRules::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFlexRules::PerformConstruction(CDmeFlexRules *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
  CDmeFlexRules::OnConstruction(this: (CDmeFlexRules *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x006BAB30
// Name: _dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleBase::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAB90
// Name: _dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRulePassThrough::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRulePassThrough pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BABF0
// Name: _dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleExpression::s_Allocator,
    blockSize: 0xACu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleExpression pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAC50
// Name: _dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRuleLocalVar::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRuleLocalVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BACB0
// Name: _dynamic_initializer_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFlexRules::s_Allocator,
    blockSize: 0xA0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFlexRules pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD8A0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD8B0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRulePassThrough::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRulePassThrough::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD8C0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleExpression::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleExpression::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD8D0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRuleLocalVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRuleLocalVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD8E0
// Name: _dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFlexRules::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFlexRules::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0063B910
// Name: class CDmeFlexRules __near * FindReferringElement<class CDmeFlexRules>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *__cdecl FindReferringElement<CDmeFlexRules>(
        CVTFTexture *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int CenterVertIndex; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t y_low; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeFlexRules *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
    y_low = LODWORD(pElement->m_vecReflectivity.y);
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    y_low = DMFILEID_INVALID;
  }
  it.m_fileid = y_low;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeFlexRules>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006BAB60
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAB70
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleBase_Helper,
           classname: "DmeFlexRuleBase",
           pFactory: &g_CDmeFlexRuleBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BABC0
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRulePassThrough_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BABD0
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRulePassThrough_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRulePassThrough_Helper,
           classname: "DmeFlexRulePassThrough",
           pFactory: &g_CDmeFlexRulePassThrough_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BAC20
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleExpression_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAC30
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleExpression_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleExpression_Helper,
           classname: "DmeFlexRuleExpression",
           pFactory: &g_CDmeFlexRuleExpression_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BAC80
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAC90
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRuleLocalVar_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRuleLocalVar_Helper,
           classname: "DmeFlexRuleLocalVar",
           pFactory: &g_CDmeFlexRuleLocalVar_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BACE0
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFlexRules_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BACF0
// Name: _dynamic_initializer_for__g_CDmeFlexRules_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFlexRules_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFlexRules_Helper,
           classname: "DmeFlexRules",
           pFactory: &g_CDmeFlexRules_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD8F0
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRulePassThrough_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeFlexRulePassThrough_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD900
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleExpression_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeFlexRuleExpression_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD910
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleLocalVar_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeFlexRuleLocalVar_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD920
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRules_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeFlexRules_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD930
// Name: _dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFlexRuleBase_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeFlexRuleBase_Factory.m_CallBackList);
}

} // namespace vmap
