// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeoperator.cpp
// Functions: 6
// ============================================================

#include "movieobjects\dmeoperator.h"

//------------------------------------------------------------------------------
// Address: 0x00568110
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568120
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x00568130
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x00568140
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x00568290
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(CDmeOperator *this, CDmeOperator *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  IDataModel_vtbl *v18; // edi
  int v19; // eax
  DmAttributeReferenceIterator_t v20; // eax
  CDmAttribute *v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **m_pMemory; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **v34; // edx
  int v35; // edi
  int v36; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = g_pDataModel->__vftable;
            v19 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
            v20 = v18->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v19);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v20);
              if ( v21 != nullptr )
              {
                v22 = (CExpressionCalculator *)v21->m_pOwner;
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  m_pMemory = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = m_pMemory;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = m_pMemory;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( *(int *)&operatorList->m_Id.m_Value[4] <= 0 )
          goto LABEL_66;
        v34 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
        while ( *v34 != pOperator )
        {
          ++v33;
          ++v34;
          if ( v33 >= *(_DWORD *)&operatorList->m_Id.m_Value[4] )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = *(_DWORD *)&operatorList->m_Id.m_Value[4];
          v36 = (int)operatorList->CDmElement::__vftable;
          if ( v35 + 1 > v36 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
              num: v35 - v36 + 1);
          ++*(_DWORD *)&operatorList->m_Id.m_Value[4];
          v37 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
          v38 = *(_DWORD *)&operatorList->m_Id.m_Value[4] - v35 - 1;
          *(_DWORD *)&operatorList->m_Id.m_Value[8] = operatorList->IDmeOperator::__vftable;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)(&operatorList->IsDirty + v35);
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    m_pMemory = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = m_pMemory;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x00568790
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  IDataModel_vtbl *v2; // esi
  int v3; // eax
  DmAttributeReferenceIterator_t v4; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v6; // ebx
  int v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  v3 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pRootElement);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v3);
  it = v4;
  if ( v4 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
      v6 = g_pDataModel->__vftable;
      v7 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v6->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v7) != nullptr )
      {
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: (CExpressionCalculator *)m_pOwner,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_18;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= operatorList->m_Size )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(this: Referring, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v14 = operatorList->m_Memory.m_pMemory;
            v15 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
            v16 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005C6F00
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C6F10
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x005C6F20
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x005C7070
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(CDmeOperator *this, CUtlMemory<vgui::TreeNode *,int> *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  IDataModel_vtbl *v18; // edi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v20; // eax
  CDmAttribute *v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **v28; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **m_pMemory; // edx
  int v35; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = g_pDataModel->__vftable;
            BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
            v20 = v18->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v20);
              if ( v21 != nullptr )
              {
                v22 = (CExpressionCalculator *)v21->m_pOwner;
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<vgui::TreeNode *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  v28 = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = v28;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = v28;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( (int)operatorList[1].m_pMemory <= 0 )
          goto LABEL_66;
        m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
        while ( *m_pMemory != pOperator )
        {
          ++v33;
          ++m_pMemory;
          if ( v33 >= (int)operatorList[1].m_pMemory )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = (int)operatorList[1].m_pMemory;
          m_nAllocationCount = operatorList->m_nAllocationCount;
          if ( v35 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v35 - m_nAllocationCount + 1);
          ++operatorList[1].m_pMemory;
          v37 = (CDmeOperator **)operatorList->m_pMemory;
          v38 = (int)operatorList[1].m_pMemory - v35 - 1;
          operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)&operatorList->m_pMemory[v35];
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    v28 = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      v28 = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = v28;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x005C7570
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(CDmElement *pRootElement, CUtlMemory<vgui::TreeNode *,int> *operatorList)
{
  IDataModel_vtbl *v2; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v4; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v6; // ebx
  int v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int v12; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pRootElement);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  it = v4;
  if ( v4 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
      v6 = g_pDataModel->__vftable;
      v7 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
      if ( v6->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v7) != nullptr )
      {
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: (CExpressionCalculator *)m_pOwner,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_18;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= (int)operatorList[1].m_pMemory )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(
              this: Referring,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v12 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v12 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v14 = (CDmeOperator **)operatorList->m_pMemory;
            v15 = (int)operatorList[1].m_pMemory - v12 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
            v16 = (CDmeOperator **)&operatorList->m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00638CA0
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CDmeOperator::GetSortKey(vgui::BuildGroup *this)
{
  return this->_currentPanel;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10059D50
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CDmeOperator::GetSortKey(vgui::BuildGroup *this)
{
  return this->_currentPanel;
}

//------------------------------------------------------------------------------
// Address: 0x10593F40
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10593F50
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x10593F60
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x105940B0
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(CDmeOperator *this, CUtlMemory<vgui::TreeNode *,int> *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  IDataModel_vtbl *v18; // edi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v20; // eax
  CDmAttribute *v21; // eax
  const CDmElement *v22; // esi
  CDmeOperator *v23; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **v28; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **m_pMemory; // edx
  int v35; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = g_pDataModel->__vftable;
            BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
            v20 = v18->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v20);
              if ( v21 != nullptr )
              {
                v22 = v21->m_pOwner;
                if ( v22 != nullptr && v22->IsA(this: (CDmElement *)v22, a2: CDmeOperator::m_classType) )
                  v23 = (CDmeOperator *)((char *)&v22[-1] + 64);
                else
                  v23 = nullptr;
                Referring = v23;
                if ( v23 != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<vgui::TreeNode *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  v28 = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = v28;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = v28;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( (int)operatorList[1].m_pMemory <= 0 )
          goto LABEL_66;
        m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
        while ( *m_pMemory != pOperator )
        {
          ++v33;
          ++m_pMemory;
          if ( v33 >= (int)operatorList[1].m_pMemory )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = (int)operatorList[1].m_pMemory;
          m_nAllocationCount = operatorList->m_nAllocationCount;
          if ( v35 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v35 - m_nAllocationCount + 1);
          ++operatorList[1].m_pMemory;
          v37 = (CDmeOperator **)operatorList->m_pMemory;
          v38 = (int)operatorList[1].m_pMemory - v35 - 1;
          operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)&operatorList->m_pMemory[v35];
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    v28 = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      v28 = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = v28;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x105945B0
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(CDmElement *pRootElement, CUtlMemory<vgui::TreeNode *,int> *operatorList)
{
  IDataModel_vtbl *v2; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v4; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v6; // ebx
  int v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int v12; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pRootElement);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  it = v4;
  if ( v4 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
      v6 = g_pDataModel->__vftable;
      v7 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
      if ( v6->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v7) != nullptr )
      {
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: m_pOwner,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_18;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= (int)operatorList[1].m_pMemory )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(
              this: Referring,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v12 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v12 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v14 = (CDmeOperator **)operatorList->m_pMemory;
            v15 = (int)operatorList[1].m_pMemory - v12 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
            v16 = (CDmeOperator **)&operatorList->m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0055EB10
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055EB20
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0055EB30
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x0055EB40
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x0055EC90
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(
        CDmeOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  int v18; // edi
  DmElementHandle_t Handle; // eax
  DmAttributeReferenceIterator_t v20; // eax
  int v21; // eax
  CDmElement *v22; // esi
  CDmeOperator *v23; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **v28; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **m_pMemory; // edx
  int v35; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = *(_DWORD *)g_pDataModel.u.m_Id;
            Handle = CDmElement::GetHandle(this: m_pOwner);
            v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v18 + 436))(
                    a1: g_pDataModel.u,
                    a2: Handle);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                      a1: g_pDataModel.u,
                      a2: v20);
              if ( v21 != 0 )
              {
                v22 = *(CDmElement **)(v21 + 8);
                if ( v22 != nullptr && v22->IsA(this: v22, a2: CDmeOperator::m_classType) )
                  v23 = (CDmeOperator *)((char *)&v22[-1] + 64);
                else
                  v23 = nullptr;
                Referring = v23;
                if ( v23 != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  v28 = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = v28;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = v28;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( (int)operatorList[1].m_pMemory <= 0 )
          goto LABEL_66;
        m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
        while ( *m_pMemory != pOperator )
        {
          ++v33;
          ++m_pMemory;
          if ( v33 >= (int)operatorList[1].m_pMemory )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = (int)operatorList[1].m_pMemory;
          m_nAllocationCount = operatorList->m_nAllocationCount;
          if ( v35 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v35 - m_nAllocationCount + 1);
          ++operatorList[1].m_pMemory;
          v37 = (CDmeOperator **)operatorList->m_pMemory;
          v38 = (int)operatorList[1].m_pMemory - v35 - 1;
          operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)&operatorList->m_pMemory[v35];
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    v28 = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      v28 = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = v28;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x0055F190
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  int v2; // esi
  DmElementHandle_t Handle; // eax
  int v4; // eax
  CDmElement *v5; // edi
  int v6; // ebx
  DmElementHandle_t v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int v12; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)g_pDataModel.u.m_Id;
  Handle = CDmElement::GetHandle(this: pRootElement);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v2 + 436))(
         a1: g_pDataModel.u,
         a2: Handle);
  it = v4;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v5 = *(CDmElement **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 332))(
                              a1: g_pDataModel.u,
                              a2: v4)
                          + 8);
      v6 = *(_DWORD *)g_pDataModel.u.m_Id;
      v7 = CDmElement::GetHandle(this: v5);
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v6 + 72))(
             a1: g_pDataModel.u,
             a2: v7) != 0 )
      {
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&v5[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( v5->IsA(this: v5, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: v5,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_18;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= (int)operatorList[1].m_pMemory )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(
              this: Referring,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v12 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v12 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v14 = (CDmeOperator **)operatorList->m_pMemory;
            v15 = (int)operatorList[1].m_pMemory - v12 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
            v16 = (CDmeOperator **)&operatorList->m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
             a1: g_pDataModel.u,
             a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004F3D80
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F3DA0
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x004F3DB0
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x004F3DC0
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x004F3F10
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(
        CDmeOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  int v18; // edi
  int v19; // eax
  DmAttributeReferenceIterator_t v20; // eax
  int v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **v28; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **m_pMemory; // edx
  int v35; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = *(_DWORD *)g_pDataModel.u.m_Id;
            v19 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
            v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v18 + 436))(
                    a1: g_pDataModel.u,
                    a2: v19);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                      a1: g_pDataModel.u,
                      a2: v20);
              if ( v21 != 0 )
              {
                v22 = *(CExpressionCalculator **)(v21 + 8);
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  v28 = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = v28;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = v28;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( (int)operatorList[1].m_pMemory <= 0 )
          goto LABEL_66;
        m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
        while ( *m_pMemory != pOperator )
        {
          ++v33;
          ++m_pMemory;
          if ( v33 >= (int)operatorList[1].m_pMemory )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = (int)operatorList[1].m_pMemory;
          m_nAllocationCount = operatorList->m_nAllocationCount;
          if ( v35 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v35 - m_nAllocationCount + 1);
          ++operatorList[1].m_pMemory;
          v37 = (CDmeOperator **)operatorList->m_pMemory;
          v38 = (int)operatorList[1].m_pMemory - v35 - 1;
          operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)&operatorList->m_pMemory[v35];
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    v28 = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      v28 = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = v28;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x004F4410
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  CExpressionCalculator *v5; // edi
  int v6; // ebx
  int v7; // eax
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int v12; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)g_pDataModel.u.m_Id;
  v3 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pRootElement);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v2 + 436))(a1: g_pDataModel.u, a2: v3);
  it = v4;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v5 = *(CExpressionCalculator **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                                         a1: g_pDataModel.u,
                                         a2: v4)
                                     + 8);
      v6 = *(_DWORD *)g_pDataModel.u.m_Id;
      v7 = CExpressionCalculator::VariableCount(this: v5);
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v6 + 72))(a1: g_pDataModel.u, a2: v7) != 0 )
      {
        if ( v5 != nullptr
          && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
              + 4))(
               a1: v5,
               a2: CDmeOperator::m_classType.u) != 0 )
        {
          p_m_bIsBuildingArgumentList = (CDmeOperator *)&v5[-1].m_bIsBuildingArgumentList;
        }
        else
        {
          p_m_bIsBuildingArgumentList = nullptr;
        }
        Referring = p_m_bIsBuildingArgumentList;
        if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
              + 4))(
               a1: v5,
               a2: CDmeAttributeReference::m_classType.u) != 0 )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: v5,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_18;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= (int)operatorList[1].m_pMemory )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(
              this: Referring,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v12 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v12 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v14 = (CDmeOperator **)operatorList->m_pMemory;
            v15 = (int)operatorList[1].m_pMemory - v12 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
            v16 = (CDmeOperator **)&operatorList->m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
             a1: g_pDataModel.u,
             a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0052B160
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B170
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0052B180
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x0052B190
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x0052B2E0
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(
        CDmeOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  IDataModel_vtbl *v18; // edi
  int v19; // eax
  DmAttributeReferenceIterator_t v20; // eax
  CDmAttribute *v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **v28; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **m_pMemory; // edx
  int v35; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = g_pDataModel->__vftable;
            v19 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
            v20 = v18->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v19);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v20);
              if ( v21 != nullptr )
              {
                v22 = (CExpressionCalculator *)v21->m_pOwner;
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  v28 = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = v28;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = v28;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( (int)operatorList[1].m_pMemory <= 0 )
          goto LABEL_66;
        m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
        while ( *m_pMemory != pOperator )
        {
          ++v33;
          ++m_pMemory;
          if ( v33 >= (int)operatorList[1].m_pMemory )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = (int)operatorList[1].m_pMemory;
          m_nAllocationCount = operatorList->m_nAllocationCount;
          if ( v35 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v35 - m_nAllocationCount + 1);
          ++operatorList[1].m_pMemory;
          v37 = (CDmeOperator **)operatorList->m_pMemory;
          v38 = (int)operatorList[1].m_pMemory - v35 - 1;
          operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)&operatorList->m_pMemory[v35];
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    v28 = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      v28 = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = v28;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x0052B7E0
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  IDataModel_vtbl *v2; // esi
  int v3; // eax
  DmAttributeReferenceIterator_t v4; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v6; // ebx
  int v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int v12; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  v3 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pRootElement);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v3);
  it = v4;
  if ( v4 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
      v6 = g_pDataModel->__vftable;
      v7 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v6->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v7) != nullptr )
      {
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: (CExpressionCalculator *)m_pOwner,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_18;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= (int)operatorList[1].m_pMemory )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(
              this: Referring,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v12 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v12 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v14 = (CDmeOperator **)operatorList->m_pMemory;
            v15 = (int)operatorList[1].m_pMemory - v12 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
            v16 = (CDmeOperator **)&operatorList->m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x005335E0
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x005335F0
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x00533600
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x00533610
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x00533760
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(CDmeOperator *this, CDmeOperator *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  IDataModel_vtbl *v18; // edi
  int v19; // eax
  DmAttributeReferenceIterator_t v20; // eax
  CDmAttribute *v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **m_pMemory; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **v34; // edx
  int v35; // edi
  int v36; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = g_pDataModel->__vftable;
            v19 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
            v20 = v18->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v19);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v20);
              if ( v21 != nullptr )
              {
                v22 = (CExpressionCalculator *)v21->m_pOwner;
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  m_pMemory = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = m_pMemory;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = m_pMemory;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( *(int *)&operatorList->m_Id.m_Value[4] <= 0 )
          goto LABEL_66;
        v34 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
        while ( *v34 != pOperator )
        {
          ++v33;
          ++v34;
          if ( v33 >= *(_DWORD *)&operatorList->m_Id.m_Value[4] )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = *(_DWORD *)&operatorList->m_Id.m_Value[4];
          v36 = (int)operatorList->CDmElement::__vftable;
          if ( v35 + 1 > v36 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
              num: v35 - v36 + 1);
          ++*(_DWORD *)&operatorList->m_Id.m_Value[4];
          v37 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
          v38 = *(_DWORD *)&operatorList->m_Id.m_Value[4] - v35 - 1;
          *(_DWORD *)&operatorList->m_Id.m_Value[8] = operatorList->IDmeOperator::__vftable;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)(&operatorList->IsDirty + v35);
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    m_pMemory = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = m_pMemory;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x00533C60
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  IDataModel_vtbl *v2; // esi
  int v3; // eax
  DmAttributeReferenceIterator_t v4; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v6; // ebx
  int v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  v3 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pRootElement);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v3);
  it = v4;
  if ( v4 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
      v6 = g_pDataModel->__vftable;
      v7 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v6->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v7) != nullptr )
      {
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: (CExpressionCalculator *)m_pOwner,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_18;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= operatorList->m_Size )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(this: Referring, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v14 = operatorList->m_Memory.m_pMemory;
            v15 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
            v16 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005F30D0
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F30E0
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x005F30F0
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x005F3100
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CDmeOperator::GetSortKey(vgui::BuildGroup *this)
{
  return this->_currentPanel;
}

//------------------------------------------------------------------------------
// Address: 0x005F3250
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(CDmeOperator *this, CUtlMemory<vgui::TreeNode *,int> *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  int v18; // edi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v20; // eax
  int v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **v28; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **m_pMemory; // edx
  int v35; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = *(_DWORD *)g_pDataModel.u.m_Id;
            BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
            v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v18 + 436))(
                    a1: g_pDataModel.u,
                    a2: BufferType);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                      a1: g_pDataModel.u,
                      a2: v20);
              if ( v21 != 0 )
              {
                v22 = *(CExpressionCalculator **)(v21 + 8);
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<vgui::TreeNode *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  v28 = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = v28;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = v28;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( (int)operatorList[1].m_pMemory <= 0 )
          goto LABEL_66;
        m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
        while ( *m_pMemory != pOperator )
        {
          ++v33;
          ++m_pMemory;
          if ( v33 >= (int)operatorList[1].m_pMemory )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = (int)operatorList[1].m_pMemory;
          m_nAllocationCount = operatorList->m_nAllocationCount;
          if ( v35 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v35 - m_nAllocationCount + 1);
          ++operatorList[1].m_pMemory;
          v37 = (CDmeOperator **)operatorList->m_pMemory;
          v38 = (int)operatorList[1].m_pMemory - v35 - 1;
          operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)&operatorList->m_pMemory[v35];
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    v28 = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      v28 = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = v28;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x005F3750
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(CDmElement *pRootElement, CUtlMemory<vgui::TreeNode *,int> *operatorList)
{
  int v2; // esi
  int BufferType; // eax
  int v4; // eax
  CExpressionCalculator *v5; // edi
  int v6; // ebx
  int v7; // eax
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int v12; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)g_pDataModel.u.m_Id;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pRootElement);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v2 + 436))(a1: g_pDataModel.u, a2: BufferType);
  it = v4;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v5 = *(CExpressionCalculator **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                                         a1: g_pDataModel.u,
                                         a2: v4)
                                     + 8);
      v6 = *(_DWORD *)g_pDataModel.u.m_Id;
      v7 = CCodecBuffer_Block::GetBufferType(this: v5);
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v6 + 72))(a1: g_pDataModel.u, a2: v7) != 0 )
      {
        if ( v5 != nullptr
          && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
              + 4))(
               a1: v5,
               a2: CDmeOperator::m_classType.u) != 0 )
        {
          p_m_bIsBuildingArgumentList = (CDmeOperator *)&v5[-1].m_bIsBuildingArgumentList;
        }
        else
        {
          p_m_bIsBuildingArgumentList = nullptr;
        }
        Referring = p_m_bIsBuildingArgumentList;
        if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
              + 4))(
               a1: v5,
               a2: CDmeAttributeReference::m_classType.u) != 0 )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: v5,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_18;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= (int)operatorList[1].m_pMemory )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(
              this: Referring,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v12 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v12 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v14 = (CDmeOperator **)operatorList->m_pMemory;
            v15 = (int)operatorList[1].m_pMemory - v12 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
            v16 = (CDmeOperator **)&operatorList->m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
             a1: g_pDataModel.u,
             a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00535210
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00535230
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x00535240
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x00535250
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x005353A0
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(CDmeOperator *this, CDmeOperator *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  IDataModel_vtbl *v18; // edi
  int v19; // eax
  DmAttributeReferenceIterator_t v20; // eax
  CDmAttribute *v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **m_pMemory; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **v34; // edx
  int v35; // edi
  int v36; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = g_pDataModel->__vftable;
            v19 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
            v20 = v18->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v19);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v20);
              if ( v21 != nullptr )
              {
                v22 = (CExpressionCalculator *)v21->m_pOwner;
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  m_pMemory = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = m_pMemory;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = m_pMemory;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( *(int *)&operatorList->m_Id.m_Value[4] <= 0 )
          goto LABEL_66;
        v34 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
        while ( *v34 != pOperator )
        {
          ++v33;
          ++v34;
          if ( v33 >= *(_DWORD *)&operatorList->m_Id.m_Value[4] )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = *(_DWORD *)&operatorList->m_Id.m_Value[4];
          v36 = (int)operatorList->CDmElement::__vftable;
          if ( v35 + 1 > v36 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
              num: v35 - v36 + 1);
          ++*(_DWORD *)&operatorList->m_Id.m_Value[4];
          v37 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
          v38 = *(_DWORD *)&operatorList->m_Id.m_Value[4] - v35 - 1;
          *(_DWORD *)&operatorList->m_Id.m_Value[8] = operatorList->IDmeOperator::__vftable;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)(&operatorList->IsDirty + v35);
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    m_pMemory = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = m_pMemory;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x005358A0
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  IDataModel_vtbl *v2; // esi
  int v3; // eax
  DmAttributeReferenceIterator_t v4; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v6; // ebx
  int v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  v3 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pRootElement);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v3);
  it = v4;
  if ( v4 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
      v6 = g_pDataModel->__vftable;
      v7 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v6->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v7) != nullptr )
      {
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: (CExpressionCalculator *)m_pOwner,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_18;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= operatorList->m_Size )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(this: Referring, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v14 = operatorList->m_Memory.m_pMemory;
            v15 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
            v16 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004ECE10
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECE20
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x004ECE30
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x004ECE40
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x004ECF90
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(
        CDmeOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  int v18; // edi
  int v19; // eax
  DmAttributeReferenceIterator_t v20; // eax
  int v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **v28; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **m_pMemory; // edx
  int v35; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = *(_DWORD *)g_pDataModel.u.m_Id;
            v19 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
            v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v18 + 436))(
                    a1: g_pDataModel.u,
                    a2: v19);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                      a1: g_pDataModel.u,
                      a2: v20);
              if ( v21 != 0 )
              {
                v22 = *(CExpressionCalculator **)(v21 + 8);
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  v28 = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = v28;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = v28;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( (int)operatorList[1].m_pMemory <= 0 )
          goto LABEL_66;
        m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
        while ( *m_pMemory != pOperator )
        {
          ++v33;
          ++m_pMemory;
          if ( v33 >= (int)operatorList[1].m_pMemory )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = (int)operatorList[1].m_pMemory;
          m_nAllocationCount = operatorList->m_nAllocationCount;
          if ( v35 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v35 - m_nAllocationCount + 1);
          ++operatorList[1].m_pMemory;
          v37 = (CDmeOperator **)operatorList->m_pMemory;
          v38 = (int)operatorList[1].m_pMemory - v35 - 1;
          operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)&operatorList->m_pMemory[v35];
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    v28 = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      v28 = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = v28;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v28 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v28);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x004ED490
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  CExpressionCalculator *v5; // edi
  int v6; // ebx
  int v7; // eax
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int v12; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)g_pDataModel.u.m_Id;
  v3 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pRootElement);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v2 + 436))(a1: g_pDataModel.u, a2: v3);
  it = v4;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v5 = *(CExpressionCalculator **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                                         a1: g_pDataModel.u,
                                         a2: v4)
                                     + 8);
      v6 = *(_DWORD *)g_pDataModel.u.m_Id;
      v7 = CExpressionCalculator::VariableCount(this: v5);
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v6 + 72))(a1: g_pDataModel.u, a2: v7) != 0 )
      {
        if ( v5 != nullptr
          && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
              + 4))(
               a1: v5,
               a2: CDmeOperator::m_classType.u) != 0 )
        {
          p_m_bIsBuildingArgumentList = (CDmeOperator *)&v5[-1].m_bIsBuildingArgumentList;
        }
        else
        {
          p_m_bIsBuildingArgumentList = nullptr;
        }
        Referring = p_m_bIsBuildingArgumentList;
        if ( (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v5->m_expr.m_Storage.m_Memory.m_pMemory
              + 4))(
               a1: v5,
               a2: CDmeAttributeReference::m_classType.u) != 0 )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: v5,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_18;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= (int)operatorList[1].m_pMemory )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(
              this: Referring,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v12 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v12 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v14 = (CDmeOperator **)operatorList->m_pMemory;
            v15 = (int)operatorList[1].m_pMemory - v12 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
            v16 = (CDmeOperator **)&operatorList->m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
             a1: g_pDataModel.u,
             a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00539AD0
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00539AE0
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x00539AF0
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x00539B00
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x00539C50
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(CDmeOperator *this, CDmeOperator *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  IDataModel_vtbl *v18; // edi
  int v19; // eax
  DmAttributeReferenceIterator_t v20; // eax
  CDmAttribute *v21; // eax
  CExpressionCalculator *v22; // esi
  CDmeOperator *p_m_bIsBuildingArgumentList; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **m_pMemory; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **v34; // edx
  int v35; // edi
  int v36; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = g_pDataModel->__vftable;
            v19 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
            v20 = v18->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v19);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v20);
              if ( v21 != nullptr )
              {
                v22 = (CExpressionCalculator *)v21->m_pOwner;
                if ( v22 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v22->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_m_bIsBuildingArgumentList = (CDmeOperator *)&v22[-1].m_bIsBuildingArgumentList;
                }
                else
                {
                  p_m_bIsBuildingArgumentList = nullptr;
                }
                Referring = p_m_bIsBuildingArgumentList;
                if ( p_m_bIsBuildingArgumentList != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  m_pMemory = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = m_pMemory;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = m_pMemory;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( *(int *)&operatorList->m_Id.m_Value[4] <= 0 )
          goto LABEL_66;
        v34 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
        while ( *v34 != pOperator )
        {
          ++v33;
          ++v34;
          if ( v33 >= *(_DWORD *)&operatorList->m_Id.m_Value[4] )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = *(_DWORD *)&operatorList->m_Id.m_Value[4];
          v36 = (int)operatorList->CDmElement::__vftable;
          if ( v35 + 1 > v36 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
              num: v35 - v36 + 1);
          ++*(_DWORD *)&operatorList->m_Id.m_Value[4];
          v37 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
          v38 = *(_DWORD *)&operatorList->m_Id.m_Value[4] - v35 - 1;
          *(_DWORD *)&operatorList->m_Id.m_Value[8] = operatorList->IDmeOperator::__vftable;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)(&operatorList->IsDirty + v35);
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    m_pMemory = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = m_pMemory;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x0053A150
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  IDataModel_vtbl *v2; // esi
  int v3; // eax
  DmAttributeReferenceIterator_t v4; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v6; // ebx
  int v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  v3 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pRootElement);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v3);
  it = v4;
  if ( v4 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
      v6 = g_pDataModel->__vftable;
      v7 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v6->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v7) != nullptr )
      {
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: (CExpressionCalculator *)m_pOwner,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_18;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= operatorList->m_Size )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(this: Referring, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v14 = operatorList->m_Memory.m_pMemory;
            v15 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
            v16 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0063CB80
// Name: protected: void CDmeOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::OnConstruction(CDmeOperator *this)
{
  this->m_nSortKey = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063CB90
// Name: public: virtual bool CDmeOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsDirty(CDmeOperator *this)
{
  return CDmElement::IsDirty(this: &this->CDmElement);
}

//------------------------------------------------------------------------------
// Address: 0x0063CBA0
// Name: public: virtual void CDmeOperator::SetSortKey(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::SetSortKey(CDmeOperator *this, int key)
{
  this->m_nSortKey = key;
}

//------------------------------------------------------------------------------
// Address: 0x0063CBB0
// Name: public: virtual int CDmeOperator::GetSortKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetSortKey(CDmeOperator *this)
{
  return this->m_nSortKey;
}

//------------------------------------------------------------------------------
// Address: 0x0063CD00
// Name: public: virtual void CDmeOperator::GatherInputOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::GatherInputOperators(CDmeOperator *this, CDmeOperator *operatorList)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CDmAttribute **v4; // eax
  void (__thiscall *GetInputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  int m_Size; // esi
  int v7; // ebx
  CDmAttribute *v8; // eax
  CDmElement *m_pOwner; // esi
  CDmeOperator *v10; // edi
  int v11; // esi
  CDmeOperator **v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  CDmElement **v17; // edi
  IDataModel_vtbl *v18; // edi
  int CenterVertIndex; // eax
  DmAttributeReferenceIterator_t v20; // eax
  CDmAttribute *v21; // eax
  CVTFTexture *v22; // esi
  CDmeOperator *p_fullAlphaAtMipLevel; // eax
  CDmeOperator *Referring; // edi
  int v25; // eax
  int v26; // esi
  CDmeOperator **v27; // eax
  CDmAttribute **m_pMemory; // eax
  CDmeOperator *v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // ecx
  CDmeOperator **v34; // edx
  int v35; // edi
  int v36; // eax
  CDmeOperator **v37; // ecx
  int v38; // eax
  CDmeOperator **v39; // edi
  CDmAttribute **v40; // eax
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > inputAttributes; // [esp+Ch] [ebp-60h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outputAttributes; // [esp+20h] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > inputOwnerList; // [esp+34h] [ebp-38h] BYREF
  CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > connectedOperators; // [esp+48h] [ebp-24h] BYREF
  int nInputAttributes; // [esp+5Ch] [ebp-10h]
  CDmeOperator *v46; // [esp+60h] [ebp-Ch]
  int iOper; // [esp+64h] [ebp-8h]
  DmAttributeReferenceIterator_t it; // [esp+68h] [ebp-4h]
  CDmeOperator *pOperator; // [esp+74h] [ebp+8h]

  inputAttributes.m_Memory.m_pMemory = nullptr;
  inputAttributes.m_Memory.m_nAllocationCount = 32;
  inputAttributes.m_Memory.m_nGrowSize = 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v46 = this;
  v4 = (CDmAttribute **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  GetInputAttributes = this->GetInputAttributes;
  inputAttributes.m_Memory.m_pMemory = v4;
  inputAttributes.m_pElements = v4;
  inputAttributes.m_Size = 0;
  GetInputAttributes(this, a2: &inputAttributes);
  m_Size = inputAttributes.m_Size;
  nInputAttributes = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_pMemory = nullptr;
  connectedOperators.m_Memory.m_nAllocationCount = inputAttributes.m_Size;
  connectedOperators.m_Memory.m_nGrowSize = 0;
  if ( inputAttributes.m_Size != 0 )
    connectedOperators.m_Memory.m_pMemory = (CDmeOperator **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * inputAttributes.m_Size);
  v7 = 0;
  connectedOperators.m_Size = 0;
  connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
  inputOwnerList.m_Memory.m_pMemory = nullptr;
  inputOwnerList.m_Memory.m_nAllocationCount = m_Size;
  inputOwnerList.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
    inputOwnerList.m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
  inputOwnerList.m_Size = 0;
  inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
  iOper = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v8 = inputAttributes.m_Memory.m_pMemory[iOper];
      if ( v8 != nullptr )
      {
        m_pOwner = v8->m_pOwner;
        if ( m_pOwner == &v46->CDmElement || !m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
        {
          v13 = 0;
          if ( inputOwnerList.m_Size <= 0 )
            goto LABEL_23;
          while ( inputOwnerList.m_Memory.m_pMemory[v13] != m_pOwner )
          {
            if ( ++v13 >= inputOwnerList.m_Size )
              goto LABEL_23;
          }
          if ( v13 == -1 )
          {
LABEL_23:
            v14 = inputOwnerList.m_Size;
            v15 = inputOwnerList.m_Size;
            if ( inputOwnerList.m_Size + 1 > inputOwnerList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<HemiLightData_t *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&inputOwnerList,
                num: inputOwnerList.m_Size - inputOwnerList.m_Memory.m_nAllocationCount + 1);
              v14 = inputOwnerList.m_Size;
            }
            inputOwnerList.m_Size = v14 + 1;
            v16 = v14 - v15;
            inputOwnerList.m_pElements = inputOwnerList.m_Memory.m_pMemory;
            if ( v16 > 0 )
              _V_memmove(
                dest: &inputOwnerList.m_Memory.m_pMemory[v15 + 1],
                src: &inputOwnerList.m_Memory.m_pMemory[v15],
                count: 4 * v16);
            v17 = &inputOwnerList.m_Memory.m_pMemory[v15];
            if ( v17 != nullptr )
              *v17 = m_pOwner;
            v18 = g_pDataModel->__vftable;
            CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)m_pOwner);
            v20 = v18->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
            for ( it = v20; v20 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID; it = v20 )
            {
              v21 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v20);
              if ( v21 != nullptr )
              {
                v22 = (CVTFTexture *)v21->m_pOwner;
                if ( v22 != nullptr
                  && ((unsigned __int8 (__thiscall *)(CVTFTexture *, CUtlSymbolLarge::<unnamed_type_u>))v22->InitLowResImage)(
                       a1: v22,
                       a2: CDmeOperator::m_classType.u) != 0 )
                {
                  p_fullAlphaAtMipLevel = (CDmeOperator *)&v22[-1].m_Options.fullAlphaAtMipLevel;
                }
                else
                {
                  p_fullAlphaAtMipLevel = nullptr;
                }
                Referring = p_fullAlphaAtMipLevel;
                if ( p_fullAlphaAtMipLevel != nullptr
                  || (Referring = FindReferringElement<CDmeOperator>(
                                    pElement: v22,
                                    symAttrName: (CUtlSymbolLarge)-1,
                                    bMustBeInSameFile: false,
                                    depth: TD_ALL)) != nullptr )
                {
                  v25 = 0;
                  if ( v7 <= 0 )
                    goto LABEL_42;
                  while ( connectedOperators.m_Memory.m_pMemory[v25] != Referring )
                  {
                    if ( ++v25 >= v7 )
                      goto LABEL_42;
                  }
                  if ( v25 == -1 )
                  {
LABEL_42:
                    v26 = v7;
                    if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<HemiLightData_t *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&connectedOperators,
                        num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
                      v7 = connectedOperators.m_Size;
                    }
                    ++v7;
                    connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
                    connectedOperators.m_Size = v7;
                    if ( v7 - v26 - 1 > 0 )
                      _V_memmove(
                        dest: &connectedOperators.m_Memory.m_pMemory[v26 + 1],
                        src: &connectedOperators.m_Memory.m_pMemory[v26],
                        count: 4 * (v7 - v26 - 1));
                    v27 = &connectedOperators.m_Memory.m_pMemory[v26];
                    if ( v27 != nullptr )
                      *v27 = Referring;
                  }
                }
              }
              v20 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
            }
          }
        }
        else
        {
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v10 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v10 = nullptr;
          v11 = v7;
          if ( v7 + 1 > connectedOperators.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&connectedOperators,
              num: v7 - connectedOperators.m_Memory.m_nAllocationCount + 1);
            v7 = connectedOperators.m_Size;
          }
          connectedOperators.m_Size = ++v7;
          connectedOperators.m_pElements = connectedOperators.m_Memory.m_pMemory;
          if ( v7 - v11 - 1 > 0 )
            _V_memmove(
              dest: &connectedOperators.m_Memory.m_pMemory[v11 + 1],
              src: &connectedOperators.m_Memory.m_pMemory[v11],
              count: 4 * (v7 - v11 - 1));
          v12 = &connectedOperators.m_Memory.m_pMemory[v11];
          if ( v12 != nullptr )
            *v12 = v10;
        }
      }
      ++iOper;
    }
    while ( iOper < nInputAttributes );
  }
  outputAttributes.m_Memory.m_pMemory = nullptr;
  outputAttributes.m_Memory.m_nAllocationCount = 32;
  outputAttributes.m_Memory.m_nGrowSize = 0;
  m_pMemory = (CDmAttribute **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  outputAttributes.m_Memory.m_pMemory = m_pMemory;
  outputAttributes.m_Size = 0;
  outputAttributes.m_pElements = m_pMemory;
  iOper = 0;
  if ( v7 > 0 )
  {
    do
    {
      v30 = connectedOperators.m_Memory.m_pMemory[iOper];
      v31 = 0;
      outputAttributes.m_Size = 0;
      pOperator = v30;
      ((void (__stdcall *)(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *))v30->GetOutputAttributes)(a1: &outputAttributes);
      if ( outputAttributes.m_Size > 0 )
      {
        while ( 1 )
        {
          v32 = 0;
          if ( inputAttributes.m_Size > 0 )
            break;
LABEL_58:
          if ( ++v31 >= outputAttributes.m_Size )
            goto LABEL_73;
        }
        while ( inputAttributes.m_Memory.m_pMemory[v32] != outputAttributes.m_Memory.m_pMemory[v31] )
        {
          if ( ++v32 >= inputAttributes.m_Size )
            goto LABEL_57;
        }
        if ( v32 == -1 )
        {
LABEL_57:
          v7 = connectedOperators.m_Size;
          goto LABEL_58;
        }
        v33 = 0;
        if ( *(int *)&operatorList->m_Id.m_Value[4] <= 0 )
          goto LABEL_66;
        v34 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
        while ( *v34 != pOperator )
        {
          ++v33;
          ++v34;
          if ( v33 >= *(_DWORD *)&operatorList->m_Id.m_Value[4] )
            goto LABEL_66;
        }
        if ( v33 == -1 )
        {
LABEL_66:
          pOperator->GatherInputOperators(
            this: pOperator,
            a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
          v35 = *(_DWORD *)&operatorList->m_Id.m_Value[4];
          v36 = (int)operatorList->CDmElement::__vftable;
          if ( v35 + 1 > v36 )
            CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)operatorList, num: v35 - v36 + 1);
          ++*(_DWORD *)&operatorList->m_Id.m_Value[4];
          v37 = (CDmeOperator **)operatorList->IDmeOperator::__vftable;
          v38 = *(_DWORD *)&operatorList->m_Id.m_Value[4] - v35 - 1;
          *(_DWORD *)&operatorList->m_Id.m_Value[8] = operatorList->IDmeOperator::__vftable;
          if ( v38 > 0 )
            _V_memmove(dest: &v37[v35 + 1], src: &v37[v35], count: 4 * v38);
          v39 = (CDmeOperator **)(&operatorList->IsDirty + v35);
          if ( v39 != nullptr )
            *v39 = pOperator;
        }
        v7 = connectedOperators.m_Size;
      }
LABEL_73:
      ++iOper;
    }
    while ( iOper < v7 );
    m_pMemory = outputAttributes.m_Memory.m_pMemory;
  }
  outputAttributes.m_Size = 0;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  outputAttributes.m_pElements = m_pMemory;
  if ( outputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      outputAttributes.m_Memory.m_pMemory = nullptr;
    }
    outputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  if ( inputOwnerList.m_Memory.m_nGrowSize >= 0 && inputOwnerList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputOwnerList.m_Memory.m_pMemory);
  if ( connectedOperators.m_Memory.m_nGrowSize >= 0 && connectedOperators.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: connectedOperators.m_Memory.m_pMemory);
  v40 = inputAttributes.m_Memory.m_pMemory;
  inputAttributes.m_Size = 0;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( inputAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inputAttributes.m_Memory.m_pMemory);
      v40 = nullptr;
      inputAttributes.m_Memory.m_pMemory = nullptr;
    }
    inputAttributes.m_Memory.m_nAllocationCount = 0;
  }
  inputAttributes.m_pElements = v40;
  if ( inputAttributes.m_Memory.m_nGrowSize >= 0 && v40 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
}

//------------------------------------------------------------------------------
// Address: 0x0063D200
// Name: void GatherOperatorsForElement(class CDmElement __near *,class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherOperatorsForElement(
        CDmElement *pRootElement,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  IDataModel_vtbl *v2; // esi
  int CenterVertIndex; // eax
  DmAttributeReferenceIterator_t v4; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v6; // ebx
  int v7; // eax
  CDmeOperator *v8; // eax
  CDmeOperator *Referring; // ebx
  int v10; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v14; // ecx
  int v15; // eax
  CDmeOperator **v16; // edi
  DmAttributeReferenceIterator_t it; // [esp+Ch] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)pRootElement);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
  it = v4;
  if ( v4 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4)->m_pOwner;
      v6 = g_pDataModel->__vftable;
      v7 = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)m_pOwner);
      if ( v6->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v7) != nullptr )
      {
        if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
          v8 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
        else
          v8 = nullptr;
        Referring = v8;
        if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeAttributeReference::m_classType) )
          Referring = FindReferringElement<CDmeOperator>(
                        pElement: (CVTFTexture *)m_pOwner,
                        symAttrName: (CUtlSymbolLarge)-1,
                        bMustBeInSameFile: false,
                        depth: TD_ALL);
        if ( Referring != nullptr )
        {
          v10 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_18;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Referring )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= operatorList->m_Size )
              goto LABEL_18;
          }
          if ( v10 == -1 )
          {
LABEL_18:
            Referring->GatherInputOperators(this: Referring, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<HemiLightData_t *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v14 = operatorList->m_Memory.m_pMemory;
            v15 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
            v16 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v16 != nullptr )
              *v16 = Referring;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v4 = it;
    }
  }
}

} // namespace vmap
