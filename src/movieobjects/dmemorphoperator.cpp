// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmemorphoperator.cpp
// Functions: 14
// ============================================================

#include "movieobjects\dmemorphoperator.h"

//------------------------------------------------------------------------------
// Address: 0x0055A050
// Name: public: virtual void CDmeMorphOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnAttributeChanged(CDmeMorphOperator *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_mesh.m_Storage.m_ElementType.u.m_Id )
    g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)this->m_nSortKey);
}

//------------------------------------------------------------------------------
// Address: 0x0055A080
// Name: protected: void CDmeMorphOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnConstruction(CDmeMorphOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmaString *p_m_baseStateName; // esi
  CDmAttribute *v6; // eax

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_mesh.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v2,
                                pAttributeName: "mesh",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: &this->m_mesh);
  CDmAttribute::SetElementTypeSymbol(this: this->m_mesh.m_pAttribute, typeSymbol: CDmeMesh::m_classType);
  this->m_mesh.m_pAttribute->m_nFlags |= 0x100u;
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_deltaStateWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this: v3,
                                             pAttributeName: "deltaStateWeights",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_deltaStateWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_deltaStateWeights.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_deltaStateWeights.m_pAttribute->m_nFlags |= 0x800u;
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_baseStateName = &this->m_baseStateName;
  v6 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "baseStateName",
         type: AT_STRING,
         pMemory: p_m_baseStateName);
  p_m_baseStateName->m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x0055A130
// Name: public: virtual void CDmeMorphOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::Operate(CDmeMorphOperator *this)
{
  CDmeMorphOperator *v1; // esi
  int v2; // ebx
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  char *m_Id; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // esi
  CDmaVar<float> *m_pData; // eax
  int DeltaStateIndex; // eax
  unsigned int mn; // [esp+18h] [ebp-10h]
  float deltaWeight; // [esp+1Ch] [ebp-Ch]
  CDmeMesh *mesh; // [esp+20h] [ebp-8h]

  v1 = this;
  mesh = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  v2 = 0;
  mn = v1->m_deltaStateWeights.m_Storage.m_Size;
  if ( mn != 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
        v5 = v4;
      else
        v5 = nullptr;
      m_Id = (char *)var;
      if ( v5->m_Name.m_Storage.u.m_Id != -1 )
        m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "weight");
      v8 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v8, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      deltaWeight = m_pData->m_Storage;
      DeltaStateIndex = CDmeMesh::FindDeltaStateIndex(this: mesh, pInDeltaName: m_Id, bSortDeltaName: true);
      if ( DeltaStateIndex == -1 )
        _Msg(a1: "MorphOperator::Operate: invalid delta state name: %s\n", m_Id);
      else
        CDmeMesh::SetDeltaStateWeight(
          this: mesh,
          nDeltaIndex: DeltaStateIndex,
          type: MESH_DELTA_WEIGHT_FIRST,
          flMorphWeight: deltaWeight);
      if ( ++v2 >= mn )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055A2A0
// Name: void MorphOp::AddAttr(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphOp::AddAttr(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs, CDmAttribute *pAttr)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v5; // eax
  CDmAttribute **v6; // eax

  if ( pAttr != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v5 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
    v6 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v6 != nullptr )
      *v6 = pAttr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055A310
// Name: public: virtual void CDmeMorphOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetInputAttributes(CDmeMorphOperator *this, CDmElement *attrs)
{
  CDmeMorphOperator *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CDmElement *v6; // ecx
  CDmAttribute *Attribute; // ebx
  int v8; // edi
  int v9; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax
  CDmeMesh *v13; // ecx
  const char *m_pAsString; // eax
  CDmAttribute *v15; // ebx
  int v16; // edi
  int v17; // eax
  CDmAttribute **v18; // ecx
  int v19; // eax
  CDmAttribute **v20; // eax
  CDmAttribute *v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmAttribute **v24; // ecx
  int v25; // eax
  CDmAttribute **v26; // eax
  CDmAttribute *v27; // ebx
  int v28; // edi
  int v29; // eax
  CDmAttribute **v30; // ecx
  int v31; // eax
  CDmAttribute **v32; // eax
  int v33; // eax
  unsigned int v34; // ecx
  CDmAttribute *v35; // ebx
  int v36; // edi
  int v37; // eax
  CDmAttribute **v38; // ecx
  int v39; // eax
  CDmAttribute **v40; // eax
  CDmAttribute *v41; // ebx
  int v42; // edi
  int v43; // eax
  CDmAttribute **v44; // ecx
  int v45; // eax
  CDmAttribute **v46; // eax
  CDmAttribute *v47; // ebx
  int v48; // edi
  int v49; // eax
  CDmAttribute **v50; // ecx
  int v51; // eax
  CDmAttribute **v52; // eax
  CDmAttribute *v53; // ebx
  int v54; // edi
  int v55; // eax
  CDmAttribute **v56; // ecx
  int v57; // eax
  CDmAttribute **v58; // eax
  unsigned int nDeltas; // [esp+Ch] [ebp-Ch]
  unsigned int nDeltasa; // [esp+Ch] [ebp-Ch]
  CDmeMesh *pMesha; // [esp+10h] [ebp-8h]
  unsigned int wi; // [esp+14h] [ebp-4h]
  unsigned int wia; // [esp+14h] [ebp-4h]
  CDmeVertexData *pDeltaState; // [esp+20h] [ebp+8h]
  CDmeVertexDeltaData *pDeltaStatea; // [esp+20h] [ebp+8h]

  v3 = this;
  nDeltas = this->m_deltaStateWeights.m_Storage.m_Size;
  for ( wi = 0; wi < nDeltas; ++wi )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[wi]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v6 = v5;
    else
      v6 = nullptr;
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: "weight");
    if ( Attribute != nullptr )
    {
      v8 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v9 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v8 + 1 > v9 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v8 - v9 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v10 = (CDmAttribute **)attrs->__vftable;
      v11 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v8 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: 4 * v11);
      v12 = (CDmAttribute **)(&attrs->OnAttributeChanged + v8);
      if ( v12 != nullptr )
        *v12 = Attribute;
    }
    v3 = this;
  }
  v13 = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_mesh.m_Storage.m_Handle);
  m_pAsString = v3->m_baseStateName.m_Storage.u.m_pAsString;
  pMesha = v13;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  pDeltaState = CDmeMesh::FindBaseState(this: v13, pStateName: m_pAsString);
  v15 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "coordinates");
  if ( v15 != nullptr )
  {
    v16 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v17 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v16 + 1 > v17 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v16 - v17 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v18 = (CDmAttribute **)attrs->__vftable;
    v19 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v16 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
    v20 = (CDmAttribute **)(&attrs->OnAttributeChanged + v16);
    if ( v20 != nullptr )
      *v20 = v15;
  }
  v21 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "normals");
  if ( v21 != nullptr )
  {
    v22 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v23 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v22 + 1 > v23 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v22 - v23 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v24 = (CDmAttribute **)attrs->__vftable;
    v25 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v22 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v25 > 0 )
      _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
    v26 = (CDmAttribute **)(&attrs->OnAttributeChanged + v22);
    if ( v26 != nullptr )
      *v26 = v21;
  }
  v27 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "textureCoordinates");
  if ( v27 != nullptr )
  {
    v28 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v29 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v28 + 1 > v29 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v28 - v29 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v30 = (CDmAttribute **)attrs->__vftable;
    v31 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v28 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
    v32 = (CDmAttribute **)(&attrs->OnAttributeChanged + v28);
    if ( v32 != nullptr )
      *v32 = v27;
  }
  v33 = CDmeMesh::DeltaStateCount(this: pMesha);
  v34 = 0;
  nDeltasa = v33;
  for ( wia = 0; v34 < nDeltasa; wia = v34 )
  {
    pDeltaStatea = CDmeMesh::GetDeltaState(this: pMesha, nDeltaIndex: v34);
    v35 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "indices");
    if ( v35 != nullptr )
    {
      v36 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v37 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v36 - v37 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v38 = (CDmAttribute **)attrs->__vftable;
      v39 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v36 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = (CDmAttribute **)(&attrs->OnAttributeChanged + v36);
      if ( v40 != nullptr )
        *v40 = v35;
    }
    v41 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "coordinates");
    if ( v41 != nullptr )
    {
      v42 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v43 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v42 + 1 > v43 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v42 - v43 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v44 = (CDmAttribute **)attrs->__vftable;
      v45 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v42 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v45 > 0 )
        _V_memmove(dest: &v44[v42 + 1], src: &v44[v42], count: 4 * v45);
      v46 = (CDmAttribute **)(&attrs->OnAttributeChanged + v42);
      if ( v46 != nullptr )
        *v46 = v41;
    }
    v47 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "normals");
    if ( v47 != nullptr )
    {
      v48 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v49 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v48 + 1 > v49 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v48 - v49 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v50 = (CDmAttribute **)attrs->__vftable;
      v51 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v48 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v51 > 0 )
        _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
      v52 = (CDmAttribute **)(&attrs->OnAttributeChanged + v48);
      if ( v52 != nullptr )
        *v52 = v47;
    }
    v53 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "textureCoordinates");
    if ( v53 != nullptr )
    {
      v54 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v55 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v54 + 1 > v55 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v54 - v55 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v56 = (CDmAttribute **)attrs->__vftable;
      v57 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v54 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v57 > 0 )
        _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
      v58 = (CDmAttribute **)(&attrs->OnAttributeChanged + v54);
      if ( v58 != nullptr )
        *v58 = v53;
    }
    v34 = wia + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055A6F0
// Name: public: virtual void CDmeMorphOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetOutputAttributes(
        CDmeMorphOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "coordinates");
  MorphOp::AddAttr(attrs, pAttr: Attribute);
  v4 = CDmElement::FindAttribute(this: v2, pAttributeName: "normals");
  MorphOp::AddAttr(attrs, pAttr: v4);
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "textureCoordinates");
  MorphOp::AddAttr(attrs, pAttr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0055A7D0
// Name: public: virtual bool CDmeMorphOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMorphOperator::IsA(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055A800
// Name: public: virtual int CDmeMorphOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMorphOperator::GetInheritanceDepth(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055A850
// Name: protected: virtual void CDmeMorphOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::PerformConstruction(CDmeMorphOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
  CDmeMorphOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005ADD10
// Name: _dynamic_initializer_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMorphOperator::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMorphOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B05B0
// Name: _dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMorphOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADD40
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMorphOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADD50
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMorphOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMorphOperator_Helper,
           classname: "DmeMorphOperator",
           pFactory: &g_CDmeMorphOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B05C0
// Name: _dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMorphOperator_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005B1180
// Name: public: virtual void CDmeMorphOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnAttributeChanged(CDmeMorphOperator *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_mesh.m_Storage.m_ElementType.u.m_Id )
    g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)this->m_nSortKey);
}

//------------------------------------------------------------------------------
// Address: 0x005B11B0
// Name: protected: void CDmeMorphOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnConstruction(CDmeMorphOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmaString *p_m_baseStateName; // esi
  CDmAttribute *v6; // eax

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_mesh.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v2,
                                pAttributeName: "mesh",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: &this->m_mesh);
  CDmAttribute::SetElementTypeSymbol(this: this->m_mesh.m_pAttribute, typeSymbol: CDmeMesh::m_classType);
  this->m_mesh.m_pAttribute->m_nFlags |= 0x100u;
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_deltaStateWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this: v3,
                                             pAttributeName: "deltaStateWeights",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_deltaStateWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_deltaStateWeights.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_deltaStateWeights.m_pAttribute->m_nFlags |= 0x800u;
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_baseStateName = &this->m_baseStateName;
  v6 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "baseStateName",
         type: AT_STRING,
         pMemory: p_m_baseStateName);
  p_m_baseStateName->m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x005B1260
// Name: public: virtual void CDmeMorphOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::Operate(CDmeMorphOperator *this)
{
  CDmeMorphOperator *v1; // esi
  int v2; // ebx
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  char *m_Id; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // esi
  CDmaVar<float> *m_pData; // eax
  int DeltaStateIndex; // eax
  unsigned int mn; // [esp+18h] [ebp-10h]
  float deltaWeight; // [esp+1Ch] [ebp-Ch]
  CDmeMesh *mesh; // [esp+20h] [ebp-8h]

  v1 = this;
  mesh = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  v2 = 0;
  mn = v1->m_deltaStateWeights.m_Storage.m_Size;
  if ( mn != 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
        v5 = v4;
      else
        v5 = nullptr;
      m_Id = (char *)defaultValue;
      if ( v5->m_Name.m_Storage.u.m_Id != -1 )
        m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "weight");
      v8 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v8, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      deltaWeight = m_pData->m_Storage;
      DeltaStateIndex = CDmeMesh::FindDeltaStateIndex(this: mesh, pInDeltaName: m_Id, bSortDeltaName: true);
      if ( DeltaStateIndex == -1 )
        _Msg(a1: "MorphOperator::Operate: invalid delta state name: %s\n", m_Id);
      else
        CDmeMesh::SetDeltaStateWeight(
          this: mesh,
          nDeltaIndex: DeltaStateIndex,
          type: MESH_DELTA_WEIGHT_FIRST,
          flMorphWeight: deltaWeight);
      if ( ++v2 >= mn )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B13D0
// Name: public: virtual void CDmeMorphOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetInputAttributes(CDmeMorphOperator *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmeMorphOperator *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CDmElement *v6; // ecx
  CDmAttribute *Attribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax
  CDmeMesh *v13; // ecx
  const char *m_pAsString; // eax
  CDmAttribute *v15; // ebx
  int v16; // edi
  int v17; // eax
  CDmAttribute **v18; // ecx
  int v19; // eax
  CDmAttribute **v20; // eax
  CDmAttribute *v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmAttribute **v24; // ecx
  int v25; // eax
  CDmAttribute **v26; // eax
  CDmAttribute *v27; // ebx
  int v28; // edi
  int v29; // eax
  CDmAttribute **v30; // ecx
  int v31; // eax
  CDmAttribute **v32; // eax
  int ChoiceCount; // eax
  unsigned int v34; // ecx
  CDmAttribute *v35; // ebx
  int v36; // edi
  int v37; // eax
  CDmAttribute **v38; // ecx
  int v39; // eax
  CDmAttribute **v40; // eax
  CDmAttribute *v41; // ebx
  int v42; // edi
  int v43; // eax
  CDmAttribute **v44; // ecx
  int v45; // eax
  CDmAttribute **v46; // eax
  CDmAttribute *v47; // ebx
  int v48; // edi
  int v49; // eax
  CDmAttribute **v50; // ecx
  int v51; // eax
  CDmAttribute **v52; // eax
  CDmAttribute *v53; // ebx
  int v54; // edi
  int v55; // eax
  CDmAttribute **v56; // ecx
  int v57; // eax
  CDmAttribute **v58; // eax
  unsigned int nDeltas; // [esp+Ch] [ebp-Ch]
  unsigned int nDeltasa; // [esp+Ch] [ebp-Ch]
  CDmeMesh *pMesha; // [esp+10h] [ebp-8h]
  unsigned int wi; // [esp+14h] [ebp-4h]
  unsigned int wia; // [esp+14h] [ebp-4h]
  CDmeVertexData *pDeltaState; // [esp+20h] [ebp+8h]
  CDmeVertexDeltaData *pDeltaStatea; // [esp+20h] [ebp+8h]

  v3 = this;
  nDeltas = this->m_deltaStateWeights.m_Storage.m_Size;
  for ( wi = 0; wi < nDeltas; ++wi )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[wi]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v6 = v5;
    else
      v6 = nullptr;
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: "weight");
    if ( Attribute != nullptr )
    {
      m_pMemory = (int)attrs[1].m_pMemory;
      m_nAllocationCount = attrs->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v10 = (CDmAttribute **)attrs->m_pMemory;
      v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
      v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
        *v12 = Attribute;
    }
    v3 = this;
  }
  v13 = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_mesh.m_Storage.m_Handle);
  m_pAsString = v3->m_baseStateName.m_Storage.u.m_pAsString;
  pMesha = v13;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  pDeltaState = CDmeMesh::FindBaseState(this: v13, pStateName: m_pAsString);
  v15 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "coordinates");
  if ( v15 != nullptr )
  {
    v16 = (int)attrs[1].m_pMemory;
    v17 = attrs->m_nAllocationCount;
    if ( v16 + 1 > v17 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v16 - v17 + 1);
    ++attrs[1].m_pMemory;
    v18 = (CDmAttribute **)attrs->m_pMemory;
    v19 = (int)attrs[1].m_pMemory - v16 - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
    v20 = (CDmAttribute **)&attrs->m_pMemory[v16];
    if ( v20 != nullptr )
      *v20 = v15;
  }
  v21 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "normals");
  if ( v21 != nullptr )
  {
    v22 = (int)attrs[1].m_pMemory;
    v23 = attrs->m_nAllocationCount;
    if ( v22 + 1 > v23 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v22 - v23 + 1);
    ++attrs[1].m_pMemory;
    v24 = (CDmAttribute **)attrs->m_pMemory;
    v25 = (int)attrs[1].m_pMemory - v22 - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v25 > 0 )
      _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
    v26 = (CDmAttribute **)&attrs->m_pMemory[v22];
    if ( v26 != nullptr )
      *v26 = v21;
  }
  v27 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "textureCoordinates");
  if ( v27 != nullptr )
  {
    v28 = (int)attrs[1].m_pMemory;
    v29 = attrs->m_nAllocationCount;
    if ( v28 + 1 > v29 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v28 - v29 + 1);
    ++attrs[1].m_pMemory;
    v30 = (CDmAttribute **)attrs->m_pMemory;
    v31 = (int)attrs[1].m_pMemory - v28 - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
    v32 = (CDmAttribute **)&attrs->m_pMemory[v28];
    if ( v32 != nullptr )
      *v32 = v27;
  }
  ChoiceCount = CDmeEditorChoicesInfo::GetChoiceCount(this: pMesha);
  v34 = 0;
  nDeltasa = ChoiceCount;
  for ( wia = 0; v34 < nDeltasa; wia = v34 )
  {
    pDeltaStatea = CDmeMesh::GetDeltaState(this: pMesha, nDeltaIndex: v34);
    v35 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "indices");
    if ( v35 != nullptr )
    {
      v36 = (int)attrs[1].m_pMemory;
      v37 = attrs->m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v36 - v37 + 1);
      ++attrs[1].m_pMemory;
      v38 = (CDmAttribute **)attrs->m_pMemory;
      v39 = (int)attrs[1].m_pMemory - v36 - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = (CDmAttribute **)&attrs->m_pMemory[v36];
      if ( v40 != nullptr )
        *v40 = v35;
    }
    v41 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "coordinates");
    if ( v41 != nullptr )
    {
      v42 = (int)attrs[1].m_pMemory;
      v43 = attrs->m_nAllocationCount;
      if ( v42 + 1 > v43 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v42 - v43 + 1);
      ++attrs[1].m_pMemory;
      v44 = (CDmAttribute **)attrs->m_pMemory;
      v45 = (int)attrs[1].m_pMemory - v42 - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v45 > 0 )
        _V_memmove(dest: &v44[v42 + 1], src: &v44[v42], count: 4 * v45);
      v46 = (CDmAttribute **)&attrs->m_pMemory[v42];
      if ( v46 != nullptr )
        *v46 = v41;
    }
    v47 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "normals");
    if ( v47 != nullptr )
    {
      v48 = (int)attrs[1].m_pMemory;
      v49 = attrs->m_nAllocationCount;
      if ( v48 + 1 > v49 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v48 - v49 + 1);
      ++attrs[1].m_pMemory;
      v50 = (CDmAttribute **)attrs->m_pMemory;
      v51 = (int)attrs[1].m_pMemory - v48 - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v51 > 0 )
        _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
      v52 = (CDmAttribute **)&attrs->m_pMemory[v48];
      if ( v52 != nullptr )
        *v52 = v47;
    }
    v53 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "textureCoordinates");
    if ( v53 != nullptr )
    {
      v54 = (int)attrs[1].m_pMemory;
      v55 = attrs->m_nAllocationCount;
      if ( v54 + 1 > v55 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v54 - v55 + 1);
      ++attrs[1].m_pMemory;
      v56 = (CDmAttribute **)attrs->m_pMemory;
      v57 = (int)attrs[1].m_pMemory - v54 - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v57 > 0 )
        _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
      v58 = (CDmAttribute **)&attrs->m_pMemory[v54];
      if ( v58 != nullptr )
        *v58 = v53;
    }
    v34 = wia + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B17B0
// Name: public: virtual void CDmeMorphOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetOutputAttributes(
        CDmeMorphOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "coordinates");
  MorphOp::AddAttr(attrs, pAttr: Attribute);
  v4 = CDmElement::FindAttribute(this: v2, pAttributeName: "normals");
  MorphOp::AddAttr(attrs, pAttr: v4);
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "textureCoordinates");
  MorphOp::AddAttr(attrs, pAttr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x005B1890
// Name: public: virtual bool CDmeMorphOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMorphOperator::IsA(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B18C0
// Name: public: virtual int CDmeMorphOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMorphOperator::GetInheritanceDepth(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B1910
// Name: protected: virtual void CDmeMorphOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::PerformConstruction(CDmeMorphOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
  CDmeMorphOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B1C80
// Name: void MorphOp::AddAttr(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphOp::AddAttr(CUtlMemory<vgui::TreeNode *,int> *attrs, CDmAttribute *pAttr)
{
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v4; // ecx
  int v5; // eax
  CDmAttribute **v6; // eax

  if ( pAttr != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v4 = (CDmAttribute **)attrs->m_pMemory;
    v5 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &v4[m_pMemory + 1], src: &v4[m_pMemory], count: 4 * v5);
    v6 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v6 != nullptr )
      *v6 = pAttr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0067F500
// Name: _dynamic_initializer_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMorphOperator::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMorphOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682AC0
// Name: _dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMorphOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F530
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMorphOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F540
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMorphOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMorphOperator_Helper,
           classname: "DmeMorphOperator",
           pFactory: &g_CDmeMorphOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682AD0
// Name: _dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMorphOperator_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051B8D0
// Name: public: virtual void CDmeMorphOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnAttributeChanged(CDmeMorphOperator *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_mesh.m_Storage.m_ElementType.u.m_Id )
    g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)this->m_nSortKey);
}

//------------------------------------------------------------------------------
// Address: 0x0051B900
// Name: protected: void CDmeMorphOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnConstruction(CDmeMorphOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmaString *p_m_baseStateName; // esi
  CDmAttribute *v6; // eax

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_mesh.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v2,
                                pAttributeName: "mesh",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: &this->m_mesh);
  CDmAttribute::SetElementTypeSymbol(this: this->m_mesh.m_pAttribute, typeSymbol: CDmeMesh::m_classType);
  this->m_mesh.m_pAttribute->m_nFlags |= 0x100u;
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_deltaStateWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this: v3,
                                             pAttributeName: "deltaStateWeights",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_deltaStateWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_deltaStateWeights.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_deltaStateWeights.m_pAttribute->m_nFlags |= 0x800u;
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_baseStateName = &this->m_baseStateName;
  v6 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "baseStateName",
         type: AT_STRING,
         pMemory: p_m_baseStateName);
  p_m_baseStateName->m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x0051B9B0
// Name: public: virtual void CDmeMorphOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::Operate(CDmeMorphOperator *this)
{
  CDmeMorphOperator *v1; // esi
  int v2; // ebx
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  char *m_Id; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // esi
  CDmaVar<float> *m_pData; // eax
  int DeltaStateIndex; // eax
  int v11; // ecx
  unsigned int mn; // [esp+18h] [ebp-10h]
  float deltaWeight; // [esp+1Ch] [ebp-Ch]
  CDmeMesh *mesh; // [esp+20h] [ebp-8h]

  v1 = this;
  mesh = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  v2 = 0;
  mn = v1->m_deltaStateWeights.m_Storage.m_Size;
  if ( mn != 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
        v5 = v4;
      else
        v5 = nullptr;
      m_Id = (char *)str;
      if ( v5->m_Name.m_Storage.u.m_Id != -1 )
        m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "weight");
      v8 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v8, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      deltaWeight = m_pData->m_Storage;
      DeltaStateIndex = CDmeMesh::FindDeltaStateIndex(this: mesh, pInDeltaName: m_Id, bSortDeltaName: true);
      if ( DeltaStateIndex == -1 )
        _Msg(a1: v11, a2: "MorphOperator::Operate: invalid delta state name: %s\n");
      else
        CDmeMesh::SetDeltaStateWeight(
          this: mesh,
          nDeltaIndex: DeltaStateIndex,
          type: MESH_DELTA_WEIGHT_FIRST,
          flMorphWeight: deltaWeight);
      if ( ++v2 >= mn )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051BB20
// Name: public: virtual void CDmeMorphOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetInputAttributes(CDmeMorphOperator *this, CDmElement *attrs)
{
  CDmeMorphOperator *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CDmElement *v6; // ecx
  CDmAttribute *Attribute; // ebx
  int v8; // edi
  int v9; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax
  CDmeMesh *v13; // ecx
  const char *m_pAsString; // eax
  CDmAttribute *v15; // ebx
  int v16; // edi
  int v17; // eax
  CDmAttribute **v18; // ecx
  int v19; // eax
  CDmAttribute **v20; // eax
  CDmAttribute *v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmAttribute **v24; // ecx
  int v25; // eax
  CDmAttribute **v26; // eax
  CDmAttribute *v27; // ebx
  int v28; // edi
  int v29; // eax
  CDmAttribute **v30; // ecx
  int v31; // eax
  CDmAttribute **v32; // eax
  int v33; // eax
  unsigned int v34; // ecx
  CDmAttribute *v35; // ebx
  int v36; // edi
  int v37; // eax
  CDmAttribute **v38; // ecx
  int v39; // eax
  CDmAttribute **v40; // eax
  CDmAttribute *v41; // ebx
  int v42; // edi
  int v43; // eax
  CDmAttribute **v44; // ecx
  int v45; // eax
  CDmAttribute **v46; // eax
  CDmAttribute *v47; // ebx
  int v48; // edi
  int v49; // eax
  CDmAttribute **v50; // ecx
  int v51; // eax
  CDmAttribute **v52; // eax
  CDmAttribute *v53; // ebx
  int v54; // edi
  int v55; // eax
  CDmAttribute **v56; // ecx
  int v57; // eax
  CDmAttribute **v58; // eax
  unsigned int nDeltas; // [esp+Ch] [ebp-Ch]
  unsigned int nDeltasa; // [esp+Ch] [ebp-Ch]
  CDmeMesh *pMesha; // [esp+10h] [ebp-8h]
  unsigned int wi; // [esp+14h] [ebp-4h]
  unsigned int wia; // [esp+14h] [ebp-4h]
  CDmeVertexData *pDeltaState; // [esp+20h] [ebp+8h]
  CDmeVertexDeltaData *pDeltaStatea; // [esp+20h] [ebp+8h]

  v3 = this;
  nDeltas = this->m_deltaStateWeights.m_Storage.m_Size;
  for ( wi = 0; wi < nDeltas; ++wi )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[wi]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v6 = v5;
    else
      v6 = nullptr;
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: "weight");
    if ( Attribute != nullptr )
    {
      v8 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v9 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v8 + 1 > v9 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v8 - v9 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v10 = (CDmAttribute **)attrs->__vftable;
      v11 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v8 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: 4 * v11);
      v12 = (CDmAttribute **)(&attrs->OnAttributeChanged + v8);
      if ( v12 != nullptr )
        *v12 = Attribute;
    }
    v3 = this;
  }
  v13 = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_mesh.m_Storage.m_Handle);
  m_pAsString = v3->m_baseStateName.m_Storage.u.m_pAsString;
  pMesha = v13;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = str;
  pDeltaState = CDmeMesh::FindBaseState(this: v13, pStateName: m_pAsString);
  v15 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "coordinates");
  if ( v15 != nullptr )
  {
    v16 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v17 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v16 + 1 > v17 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v16 - v17 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v18 = (CDmAttribute **)attrs->__vftable;
    v19 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v16 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
    v20 = (CDmAttribute **)(&attrs->OnAttributeChanged + v16);
    if ( v20 != nullptr )
      *v20 = v15;
  }
  v21 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "normals");
  if ( v21 != nullptr )
  {
    v22 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v23 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v22 + 1 > v23 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v22 - v23 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v24 = (CDmAttribute **)attrs->__vftable;
    v25 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v22 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v25 > 0 )
      _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
    v26 = (CDmAttribute **)(&attrs->OnAttributeChanged + v22);
    if ( v26 != nullptr )
      *v26 = v21;
  }
  v27 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "textureCoordinates");
  if ( v27 != nullptr )
  {
    v28 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v29 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v28 + 1 > v29 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v28 - v29 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v30 = (CDmAttribute **)attrs->__vftable;
    v31 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v28 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
    v32 = (CDmAttribute **)(&attrs->OnAttributeChanged + v28);
    if ( v32 != nullptr )
      *v32 = v27;
  }
  v33 = CDmeMesh::DeltaStateCount(this: pMesha);
  v34 = 0;
  nDeltasa = v33;
  for ( wia = 0; v34 < nDeltasa; wia = v34 )
  {
    pDeltaStatea = CDmeMesh::GetDeltaState(this: pMesha, nDeltaIndex: v34);
    v35 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "indices");
    if ( v35 != nullptr )
    {
      v36 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v37 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v36 - v37 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v38 = (CDmAttribute **)attrs->__vftable;
      v39 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v36 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = (CDmAttribute **)(&attrs->OnAttributeChanged + v36);
      if ( v40 != nullptr )
        *v40 = v35;
    }
    v41 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "coordinates");
    if ( v41 != nullptr )
    {
      v42 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v43 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v42 + 1 > v43 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v42 - v43 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v44 = (CDmAttribute **)attrs->__vftable;
      v45 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v42 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v45 > 0 )
        _V_memmove(dest: &v44[v42 + 1], src: &v44[v42], count: 4 * v45);
      v46 = (CDmAttribute **)(&attrs->OnAttributeChanged + v42);
      if ( v46 != nullptr )
        *v46 = v41;
    }
    v47 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "normals");
    if ( v47 != nullptr )
    {
      v48 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v49 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v48 + 1 > v49 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v48 - v49 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v50 = (CDmAttribute **)attrs->__vftable;
      v51 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v48 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v51 > 0 )
        _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
      v52 = (CDmAttribute **)(&attrs->OnAttributeChanged + v48);
      if ( v52 != nullptr )
        *v52 = v47;
    }
    v53 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "textureCoordinates");
    if ( v53 != nullptr )
    {
      v54 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v55 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v54 + 1 > v55 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v54 - v55 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v56 = (CDmAttribute **)attrs->__vftable;
      v57 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v54 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v57 > 0 )
        _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
      v58 = (CDmAttribute **)(&attrs->OnAttributeChanged + v54);
      if ( v58 != nullptr )
        *v58 = v53;
    }
    v34 = wia + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051BF00
// Name: public: virtual void CDmeMorphOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetOutputAttributes(
        CDmeMorphOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "coordinates");
  MorphOp::AddAttr(attrs, pAttr: Attribute);
  v4 = CDmElement::FindAttribute(this: v2, pAttributeName: "normals");
  MorphOp::AddAttr(attrs, pAttr: v4);
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "textureCoordinates");
  MorphOp::AddAttr(attrs, pAttr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0051BFE0
// Name: public: virtual bool CDmeMorphOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMorphOperator::IsA(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C010
// Name: public: virtual int CDmeMorphOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMorphOperator::GetInheritanceDepth(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C060
// Name: protected: virtual void CDmeMorphOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::PerformConstruction(CDmeMorphOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
  CDmeMorphOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0051C3D0
// Name: void MorphOp::AddAttr(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphOp::AddAttr(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs, CDmAttribute *pAttr)
{
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v4; // ecx
  int v5; // eax
  CDmAttribute **v6; // eax

  if ( pAttr != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v4 = (CDmAttribute **)attrs->m_pMemory;
    v5 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &v4[m_pMemory + 1], src: &v4[m_pMemory], count: 4 * v5);
    v6 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v6 != nullptr )
      *v6 = pAttr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056C0E0
// Name: _dynamic_initializer_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMorphOperator::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMorphOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056ECA0
// Name: _dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMorphOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C110
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMorphOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C120
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMorphOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMorphOperator_Helper,
           classname: "DmeMorphOperator",
           pFactory: &g_CDmeMorphOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056ECB0
// Name: _dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMorphOperator_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00521AF0
// Name: public: virtual void CDmeMorphOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnAttributeChanged(CDmeMorphOperator *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_mesh.m_Storage.m_ElementType.u.m_Id )
    g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)this->m_nSortKey);
}

//------------------------------------------------------------------------------
// Address: 0x00521B20
// Name: protected: void CDmeMorphOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnConstruction(CDmeMorphOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmaString *p_m_baseStateName; // esi
  CDmAttribute *v6; // eax

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_mesh.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v2,
                                pAttributeName: "mesh",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: &this->m_mesh);
  CDmAttribute::SetElementTypeSymbol(this: this->m_mesh.m_pAttribute, typeSymbol: CDmeMesh::m_classType);
  this->m_mesh.m_pAttribute->m_nFlags |= 0x100u;
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_deltaStateWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this: v3,
                                             pAttributeName: "deltaStateWeights",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_deltaStateWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_deltaStateWeights.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_deltaStateWeights.m_pAttribute->m_nFlags |= 0x800u;
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_baseStateName = &this->m_baseStateName;
  v6 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "baseStateName",
         type: AT_STRING,
         pMemory: p_m_baseStateName);
  p_m_baseStateName->m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x00521BD0
// Name: public: virtual void CDmeMorphOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::Operate(CDmeMorphOperator *this)
{
  CDmeMorphOperator *v1; // esi
  int v2; // ebx
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  char *m_Id; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // esi
  CDmaVar<float> *m_pData; // eax
  int DeltaStateIndex; // eax
  int v11; // ecx
  unsigned int mn; // [esp+18h] [ebp-10h]
  float deltaWeight; // [esp+1Ch] [ebp-Ch]
  CDmeMesh *mesh; // [esp+20h] [ebp-8h]

  v1 = this;
  mesh = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  v2 = 0;
  mn = v1->m_deltaStateWeights.m_Storage.m_Size;
  if ( mn != 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
        v5 = v4;
      else
        v5 = nullptr;
      m_Id = (char *)&pParentName;
      if ( v5->m_Name.m_Storage.u.m_Id != -1 )
        m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "weight");
      v8 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v8, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      deltaWeight = m_pData->m_Storage;
      DeltaStateIndex = CDmeMesh::FindDeltaStateIndex(this: mesh, pInDeltaName: m_Id, bSortDeltaName: true);
      if ( DeltaStateIndex == -1 )
        _Msg(a1: v11, a2: "MorphOperator::Operate: invalid delta state name: %s\n");
      else
        CDmeMesh::SetDeltaStateWeight(
          this: mesh,
          nDeltaIndex: DeltaStateIndex,
          type: MESH_DELTA_WEIGHT_FIRST,
          flMorphWeight: deltaWeight);
      if ( ++v2 >= mn )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521D40
// Name: public: virtual void CDmeMorphOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetInputAttributes(CDmeMorphOperator *this, CDmElement *attrs)
{
  CDmeMorphOperator *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CDmElement *v6; // ecx
  CDmAttribute *Attribute; // ebx
  int v8; // edi
  int v9; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax
  CDmeMesh *v13; // ecx
  const char *m_pAsString; // eax
  CDmAttribute *v15; // ebx
  int v16; // edi
  int v17; // eax
  CDmAttribute **v18; // ecx
  int v19; // eax
  CDmAttribute **v20; // eax
  CDmAttribute *v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmAttribute **v24; // ecx
  int v25; // eax
  CDmAttribute **v26; // eax
  CDmAttribute *v27; // ebx
  int v28; // edi
  int v29; // eax
  CDmAttribute **v30; // ecx
  int v31; // eax
  CDmAttribute **v32; // eax
  int v33; // eax
  unsigned int v34; // ecx
  CDmAttribute *v35; // ebx
  int v36; // edi
  int v37; // eax
  CDmAttribute **v38; // ecx
  int v39; // eax
  CDmAttribute **v40; // eax
  CDmAttribute *v41; // ebx
  int v42; // edi
  int v43; // eax
  CDmAttribute **v44; // ecx
  int v45; // eax
  CDmAttribute **v46; // eax
  CDmAttribute *v47; // ebx
  int v48; // edi
  int v49; // eax
  CDmAttribute **v50; // ecx
  int v51; // eax
  CDmAttribute **v52; // eax
  CDmAttribute *v53; // ebx
  int v54; // edi
  int v55; // eax
  CDmAttribute **v56; // ecx
  int v57; // eax
  CDmAttribute **v58; // eax
  unsigned int nDeltas; // [esp+Ch] [ebp-Ch]
  unsigned int nDeltasa; // [esp+Ch] [ebp-Ch]
  CDmeMesh *pMesha; // [esp+10h] [ebp-8h]
  unsigned int wi; // [esp+14h] [ebp-4h]
  unsigned int wia; // [esp+14h] [ebp-4h]
  CDmeVertexData *pDeltaState; // [esp+20h] [ebp+8h]
  CDmeVertexDeltaData *pDeltaStatea; // [esp+20h] [ebp+8h]

  v3 = this;
  nDeltas = this->m_deltaStateWeights.m_Storage.m_Size;
  for ( wi = 0; wi < nDeltas; ++wi )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[wi]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v6 = v5;
    else
      v6 = nullptr;
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: "weight");
    if ( Attribute != nullptr )
    {
      v8 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v9 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v8 + 1 > v9 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v8 - v9 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v10 = (CDmAttribute **)attrs->__vftable;
      v11 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v8 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: 4 * v11);
      v12 = (CDmAttribute **)(&attrs->OnAttributeChanged + v8);
      if ( v12 != nullptr )
        *v12 = Attribute;
    }
    v3 = this;
  }
  v13 = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_mesh.m_Storage.m_Handle);
  m_pAsString = v3->m_baseStateName.m_Storage.u.m_pAsString;
  pMesha = v13;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pParentName;
  pDeltaState = CDmeMesh::FindBaseState(this: v13, pStateName: m_pAsString);
  v15 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "coordinates");
  if ( v15 != nullptr )
  {
    v16 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v17 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v16 + 1 > v17 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v16 - v17 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v18 = (CDmAttribute **)attrs->__vftable;
    v19 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v16 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
    v20 = (CDmAttribute **)(&attrs->OnAttributeChanged + v16);
    if ( v20 != nullptr )
      *v20 = v15;
  }
  v21 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "normals");
  if ( v21 != nullptr )
  {
    v22 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v23 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v22 + 1 > v23 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v22 - v23 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v24 = (CDmAttribute **)attrs->__vftable;
    v25 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v22 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v25 > 0 )
      _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
    v26 = (CDmAttribute **)(&attrs->OnAttributeChanged + v22);
    if ( v26 != nullptr )
      *v26 = v21;
  }
  v27 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "textureCoordinates");
  if ( v27 != nullptr )
  {
    v28 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v29 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v28 + 1 > v29 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v28 - v29 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v30 = (CDmAttribute **)attrs->__vftable;
    v31 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v28 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
    v32 = (CDmAttribute **)(&attrs->OnAttributeChanged + v28);
    if ( v32 != nullptr )
      *v32 = v27;
  }
  v33 = CDmeMesh::DeltaStateCount(this: pMesha);
  v34 = 0;
  nDeltasa = v33;
  for ( wia = 0; v34 < nDeltasa; wia = v34 )
  {
    pDeltaStatea = CDmeMesh::GetDeltaState(this: pMesha, nDeltaIndex: v34);
    v35 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "indices");
    if ( v35 != nullptr )
    {
      v36 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v37 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v36 - v37 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v38 = (CDmAttribute **)attrs->__vftable;
      v39 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v36 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = (CDmAttribute **)(&attrs->OnAttributeChanged + v36);
      if ( v40 != nullptr )
        *v40 = v35;
    }
    v41 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "coordinates");
    if ( v41 != nullptr )
    {
      v42 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v43 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v42 + 1 > v43 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v42 - v43 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v44 = (CDmAttribute **)attrs->__vftable;
      v45 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v42 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v45 > 0 )
        _V_memmove(dest: &v44[v42 + 1], src: &v44[v42], count: 4 * v45);
      v46 = (CDmAttribute **)(&attrs->OnAttributeChanged + v42);
      if ( v46 != nullptr )
        *v46 = v41;
    }
    v47 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "normals");
    if ( v47 != nullptr )
    {
      v48 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v49 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v48 + 1 > v49 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v48 - v49 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v50 = (CDmAttribute **)attrs->__vftable;
      v51 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v48 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v51 > 0 )
        _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
      v52 = (CDmAttribute **)(&attrs->OnAttributeChanged + v48);
      if ( v52 != nullptr )
        *v52 = v47;
    }
    v53 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "textureCoordinates");
    if ( v53 != nullptr )
    {
      v54 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v55 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v54 + 1 > v55 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v54 - v55 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v56 = (CDmAttribute **)attrs->__vftable;
      v57 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v54 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v57 > 0 )
        _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
      v58 = (CDmAttribute **)(&attrs->OnAttributeChanged + v54);
      if ( v58 != nullptr )
        *v58 = v53;
    }
    v34 = wia + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00522120
// Name: public: virtual void CDmeMorphOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetOutputAttributes(
        CDmeMorphOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "coordinates");
  MorphOp::AddAttr(attrs, pAttr: Attribute);
  v4 = CDmElement::FindAttribute(this: v2, pAttributeName: "normals");
  MorphOp::AddAttr(attrs, pAttr: v4);
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "textureCoordinates");
  MorphOp::AddAttr(attrs, pAttr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00522200
// Name: public: virtual bool CDmeMorphOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMorphOperator::IsA(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522230
// Name: public: virtual int CDmeMorphOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMorphOperator::GetInheritanceDepth(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522280
// Name: protected: virtual void CDmeMorphOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::PerformConstruction(CDmeMorphOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
  CDmeMorphOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005225F0
// Name: void MorphOp::AddAttr(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphOp::AddAttr(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs, CDmAttribute *pAttr)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v5; // eax
  CDmAttribute **v6; // eax

  if ( pAttr != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v5 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
    v6 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v6 != nullptr )
      *v6 = pAttr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057C200
// Name: _dynamic_initializer_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMorphOperator::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMorphOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDD0
// Name: _dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMorphOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C230
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMorphOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C240
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMorphOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMorphOperator_Helper,
           classname: "DmeMorphOperator",
           pFactory: &g_CDmeMorphOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDE0
// Name: _dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMorphOperator_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DEA00
// Name: public: virtual void CDmeMorphOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnAttributeChanged(CDmeMorphOperator *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_mesh.m_Storage.m_ElementType.u.m_Id )
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
      a1: g_pDataModel.u,
      a2: this->m_nSortKey);
}

//------------------------------------------------------------------------------
// Address: 0x005DEA30
// Name: protected: void CDmeMorphOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnConstruction(CDmeMorphOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmaString *p_m_baseStateName; // esi
  CDmAttribute *v6; // eax

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_mesh.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v2,
                                pAttributeName: "mesh",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: &this->m_mesh);
  CDmAttribute::SetElementTypeSymbol(this: this->m_mesh.m_pAttribute, typeSymbol: CDmeMesh::m_classType);
  this->m_mesh.m_pAttribute->m_nFlags |= 0x100u;
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_deltaStateWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this: v3,
                                             pAttributeName: "deltaStateWeights",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_deltaStateWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_deltaStateWeights.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_deltaStateWeights.m_pAttribute->m_nFlags |= 0x800u;
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_baseStateName = &this->m_baseStateName;
  v6 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "baseStateName",
         type: AT_STRING,
         pMemory: p_m_baseStateName);
  p_m_baseStateName->m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x005DEAE0
// Name: public: virtual void CDmeMorphOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::Operate(CDmeMorphOperator *this)
{
  CDmeMorphOperator *v1; // esi
  int v2; // ebx
  int v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  char *m_Id; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // esi
  CDmaVar<float> *m_pData; // eax
  int DeltaStateIndex; // eax
  unsigned int mn; // [esp+18h] [ebp-10h]
  float deltaWeight; // [esp+1Ch] [ebp-Ch]
  CDmeMesh *mesh; // [esp+20h] [ebp-8h]

  v1 = this;
  mesh = (CDmeMesh *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_mesh.m_Storage.m_Handle);
  v2 = 0;
  mn = v1->m_deltaStateWeights.m_Storage.m_Size;
  if ( mn != 0 )
  {
    while ( 1 )
    {
      v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v1->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = (CDmElement *)v3;
      if ( v3 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
             a1: v3,
             a2: CDmElement::m_classType.u) != 0 )
      {
        v5 = v4;
      }
      else
      {
        v5 = nullptr;
      }
      m_Id = (char *)defaultValue;
      if ( v5->m_Name.m_Storage.u.m_Id != -1 )
        m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "weight");
      v8 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v8, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      deltaWeight = m_pData->m_Storage;
      DeltaStateIndex = CDmeMesh::FindDeltaStateIndex(this: mesh, pInDeltaName: m_Id, bSortDeltaName: true);
      if ( DeltaStateIndex == -1 )
        _Msg(a1: "MorphOperator::Operate: invalid delta state name: %s\n", m_Id);
      else
        CDmeMesh::SetDeltaStateWeight(
          this: mesh,
          nDeltaIndex: DeltaStateIndex,
          type: MESH_DELTA_WEIGHT_FIRST,
          flMorphWeight: deltaWeight);
      if ( ++v2 >= mn )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DEC50
// Name: public: virtual void CDmeMorphOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetInputAttributes(CDmeMorphOperator *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmeMorphOperator *v3; // edi
  int v4; // eax
  CDmElement *v5; // edi
  CDmElement *v6; // ecx
  CDmAttribute *Attribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax
  CDmeMesh *v13; // ecx
  const char *m_pAsString; // eax
  CDmAttribute *v15; // ebx
  int v16; // edi
  int v17; // eax
  CDmAttribute **v18; // ecx
  int v19; // eax
  CDmAttribute **v20; // eax
  CDmAttribute *v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmAttribute **v24; // ecx
  int v25; // eax
  CDmAttribute **v26; // eax
  CDmAttribute *v27; // ebx
  int v28; // edi
  int v29; // eax
  CDmAttribute **v30; // ecx
  int v31; // eax
  CDmAttribute **v32; // eax
  int ChoiceCount; // eax
  unsigned int v34; // ecx
  CDmAttribute *v35; // ebx
  int v36; // edi
  int v37; // eax
  CDmAttribute **v38; // ecx
  int v39; // eax
  CDmAttribute **v40; // eax
  CDmAttribute *v41; // ebx
  int v42; // edi
  int v43; // eax
  CDmAttribute **v44; // ecx
  int v45; // eax
  CDmAttribute **v46; // eax
  CDmAttribute *v47; // ebx
  int v48; // edi
  int v49; // eax
  CDmAttribute **v50; // ecx
  int v51; // eax
  CDmAttribute **v52; // eax
  CDmAttribute *v53; // ebx
  int v54; // edi
  int v55; // eax
  CDmAttribute **v56; // ecx
  int v57; // eax
  CDmAttribute **v58; // eax
  unsigned int nDeltas; // [esp+Ch] [ebp-Ch]
  unsigned int nDeltasa; // [esp+Ch] [ebp-Ch]
  CDmeMesh *pMesha; // [esp+10h] [ebp-8h]
  unsigned int wi; // [esp+14h] [ebp-4h]
  unsigned int wia; // [esp+14h] [ebp-4h]
  CDmeVertexData *pDeltaState; // [esp+20h] [ebp+8h]
  CDmeVertexDeltaData *pDeltaStatea; // [esp+20h] [ebp+8h]

  v3 = this;
  nDeltas = this->m_deltaStateWeights.m_Storage.m_Size;
  for ( wi = 0; wi < nDeltas; ++wi )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v3->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[wi]);
    v5 = (CDmElement *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmElement::m_classType.u) != 0 )
    {
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: "weight");
    if ( Attribute != nullptr )
    {
      m_pMemory = (int)attrs[1].m_pMemory;
      m_nAllocationCount = attrs->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
      ++attrs[1].m_pMemory;
      v10 = (CDmAttribute **)attrs->m_pMemory;
      v11 = (int)attrs[1].m_pMemory - m_pMemory - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
      v12 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
        *v12 = Attribute;
    }
    v3 = this;
  }
  v13 = (CDmeMesh *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: v3->m_mesh.m_Storage.m_Handle);
  m_pAsString = v3->m_baseStateName.m_Storage.u.m_pAsString;
  pMesha = v13;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  pDeltaState = CDmeMesh::FindBaseState(this: v13, pStateName: m_pAsString);
  v15 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "coordinates");
  if ( v15 != nullptr )
  {
    v16 = (int)attrs[1].m_pMemory;
    v17 = attrs->m_nAllocationCount;
    if ( v16 + 1 > v17 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v16 - v17 + 1);
    ++attrs[1].m_pMemory;
    v18 = (CDmAttribute **)attrs->m_pMemory;
    v19 = (int)attrs[1].m_pMemory - v16 - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
    v20 = (CDmAttribute **)&attrs->m_pMemory[v16];
    if ( v20 != nullptr )
      *v20 = v15;
  }
  v21 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "normals");
  if ( v21 != nullptr )
  {
    v22 = (int)attrs[1].m_pMemory;
    v23 = attrs->m_nAllocationCount;
    if ( v22 + 1 > v23 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v22 - v23 + 1);
    ++attrs[1].m_pMemory;
    v24 = (CDmAttribute **)attrs->m_pMemory;
    v25 = (int)attrs[1].m_pMemory - v22 - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v25 > 0 )
      _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
    v26 = (CDmAttribute **)&attrs->m_pMemory[v22];
    if ( v26 != nullptr )
      *v26 = v21;
  }
  v27 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "textureCoordinates");
  if ( v27 != nullptr )
  {
    v28 = (int)attrs[1].m_pMemory;
    v29 = attrs->m_nAllocationCount;
    if ( v28 + 1 > v29 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v28 - v29 + 1);
    ++attrs[1].m_pMemory;
    v30 = (CDmAttribute **)attrs->m_pMemory;
    v31 = (int)attrs[1].m_pMemory - v28 - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
    v32 = (CDmAttribute **)&attrs->m_pMemory[v28];
    if ( v32 != nullptr )
      *v32 = v27;
  }
  ChoiceCount = CDmeEditorChoicesInfo::GetChoiceCount(this: pMesha);
  v34 = 0;
  nDeltasa = ChoiceCount;
  for ( wia = 0; v34 < nDeltasa; wia = v34 )
  {
    pDeltaStatea = CDmeMesh::GetDeltaState(this: pMesha, nDeltaIndex: v34);
    v35 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "indices");
    if ( v35 != nullptr )
    {
      v36 = (int)attrs[1].m_pMemory;
      v37 = attrs->m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v36 - v37 + 1);
      ++attrs[1].m_pMemory;
      v38 = (CDmAttribute **)attrs->m_pMemory;
      v39 = (int)attrs[1].m_pMemory - v36 - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = (CDmAttribute **)&attrs->m_pMemory[v36];
      if ( v40 != nullptr )
        *v40 = v35;
    }
    v41 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "coordinates");
    if ( v41 != nullptr )
    {
      v42 = (int)attrs[1].m_pMemory;
      v43 = attrs->m_nAllocationCount;
      if ( v42 + 1 > v43 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v42 - v43 + 1);
      ++attrs[1].m_pMemory;
      v44 = (CDmAttribute **)attrs->m_pMemory;
      v45 = (int)attrs[1].m_pMemory - v42 - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v45 > 0 )
        _V_memmove(dest: &v44[v42 + 1], src: &v44[v42], count: 4 * v45);
      v46 = (CDmAttribute **)&attrs->m_pMemory[v42];
      if ( v46 != nullptr )
        *v46 = v41;
    }
    v47 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "normals");
    if ( v47 != nullptr )
    {
      v48 = (int)attrs[1].m_pMemory;
      v49 = attrs->m_nAllocationCount;
      if ( v48 + 1 > v49 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v48 - v49 + 1);
      ++attrs[1].m_pMemory;
      v50 = (CDmAttribute **)attrs->m_pMemory;
      v51 = (int)attrs[1].m_pMemory - v48 - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v51 > 0 )
        _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
      v52 = (CDmAttribute **)&attrs->m_pMemory[v48];
      if ( v52 != nullptr )
        *v52 = v47;
    }
    v53 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "textureCoordinates");
    if ( v53 != nullptr )
    {
      v54 = (int)attrs[1].m_pMemory;
      v55 = attrs->m_nAllocationCount;
      if ( v54 + 1 > v55 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v54 - v55 + 1);
      ++attrs[1].m_pMemory;
      v56 = (CDmAttribute **)attrs->m_pMemory;
      v57 = (int)attrs[1].m_pMemory - v54 - 1;
      attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
      if ( v57 > 0 )
        _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
      v58 = (CDmAttribute **)&attrs->m_pMemory[v54];
      if ( v58 != nullptr )
        *v58 = v53;
    }
    v34 = wia + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DF030
// Name: public: virtual void CDmeMorphOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetOutputAttributes(
        CDmeMorphOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_mesh.m_Storage.m_Handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "coordinates");
  MorphOp::AddAttr(attrs, pAttr: Attribute);
  v4 = CDmElement::FindAttribute(this: v2, pAttributeName: "normals");
  MorphOp::AddAttr(attrs, pAttr: v4);
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "textureCoordinates");
  MorphOp::AddAttr(attrs, pAttr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x005DF110
// Name: public: virtual bool CDmeMorphOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMorphOperator::IsA(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DF140
// Name: public: virtual int CDmeMorphOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMorphOperator::GetInheritanceDepth(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DF190
// Name: protected: virtual void CDmeMorphOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::PerformConstruction(CDmeMorphOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
  CDmeMorphOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005DF500
// Name: void MorphOp::AddAttr(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphOp::AddAttr(CUtlMemory<vgui::TreeNode *,int> *attrs, CDmAttribute *pAttr)
{
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v4; // ecx
  int v5; // eax
  CDmAttribute **v6; // eax

  if ( pAttr != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v4 = (CDmAttribute **)attrs->m_pMemory;
    v5 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &v4[m_pMemory + 1], src: &v4[m_pMemory], count: 4 * v5);
    v6 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v6 != nullptr )
      *v6 = pAttr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B1350
// Name: _dynamic_initializer_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMorphOperator::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMorphOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B55C0
// Name: _dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMorphOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1380
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMorphOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1390
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMorphOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMorphOperator_Helper,
           classname: "DmeMorphOperator",
           pFactory: &g_CDmeMorphOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B55D0
// Name: _dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMorphOperator_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00522D00
// Name: public: virtual void CDmeMorphOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnAttributeChanged(CDmeMorphOperator *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_mesh.m_Storage.m_ElementType.u.m_Id )
    g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)this->m_nSortKey);
}

//------------------------------------------------------------------------------
// Address: 0x00522D30
// Name: protected: void CDmeMorphOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnConstruction(CDmeMorphOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmaString *p_m_baseStateName; // esi
  CDmAttribute *v6; // eax

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_mesh.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v2,
                                pAttributeName: "mesh",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: &this->m_mesh);
  CDmAttribute::SetElementTypeSymbol(this: this->m_mesh.m_pAttribute, typeSymbol: CDmeMesh::m_classType);
  this->m_mesh.m_pAttribute->m_nFlags |= 0x100u;
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_deltaStateWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this: v3,
                                             pAttributeName: "deltaStateWeights",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_deltaStateWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_deltaStateWeights.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_deltaStateWeights.m_pAttribute->m_nFlags |= 0x800u;
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_baseStateName = &this->m_baseStateName;
  v6 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "baseStateName",
         type: AT_STRING,
         pMemory: p_m_baseStateName);
  p_m_baseStateName->m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x00522DE0
// Name: public: virtual void CDmeMorphOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::Operate(CDmeMorphOperator *this)
{
  CDmeMorphOperator *v1; // esi
  int v2; // ebx
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  char *m_Id; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // esi
  CDmaVar<float> *m_pData; // eax
  int DeltaStateIndex; // eax
  int v11; // ecx
  unsigned int mn; // [esp+18h] [ebp-10h]
  float deltaWeight; // [esp+1Ch] [ebp-Ch]
  CDmeMesh *mesh; // [esp+20h] [ebp-8h]

  v1 = this;
  mesh = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  v2 = 0;
  mn = v1->m_deltaStateWeights.m_Storage.m_Size;
  if ( mn != 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
        v5 = v4;
      else
        v5 = nullptr;
      m_Id = (char *)&pch;
      if ( v5->m_Name.m_Storage.u.m_Id != -1 )
        m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "weight");
      v8 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v8, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      deltaWeight = m_pData->m_Storage;
      DeltaStateIndex = CDmeMesh::FindDeltaStateIndex(this: mesh, pInDeltaName: m_Id, bSortDeltaName: true);
      if ( DeltaStateIndex == -1 )
        _Msg(a1: v11, a2: "MorphOperator::Operate: invalid delta state name: %s\n");
      else
        CDmeMesh::SetDeltaStateWeight(
          this: mesh,
          nDeltaIndex: DeltaStateIndex,
          type: MESH_DELTA_WEIGHT_FIRST,
          flMorphWeight: deltaWeight);
      if ( ++v2 >= mn )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00522F50
// Name: void MorphOp::AddAttr(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphOp::AddAttr(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs, CDmAttribute *pAttr)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v5; // eax
  CDmAttribute **v6; // eax

  if ( pAttr != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v5 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
    v6 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v6 != nullptr )
      *v6 = pAttr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00522FC0
// Name: public: virtual void CDmeMorphOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetInputAttributes(CDmeMorphOperator *this, CDmElement *attrs)
{
  CDmeMorphOperator *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CDmElement *v6; // ecx
  CDmAttribute *Attribute; // ebx
  int v8; // edi
  int v9; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax
  CDmeMesh *v13; // ecx
  const char *m_pAsString; // eax
  CDmAttribute *v15; // ebx
  int v16; // edi
  int v17; // eax
  CDmAttribute **v18; // ecx
  int v19; // eax
  CDmAttribute **v20; // eax
  CDmAttribute *v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmAttribute **v24; // ecx
  int v25; // eax
  CDmAttribute **v26; // eax
  CDmAttribute *v27; // ebx
  int v28; // edi
  int v29; // eax
  CDmAttribute **v30; // ecx
  int v31; // eax
  CDmAttribute **v32; // eax
  int v33; // eax
  unsigned int v34; // ecx
  CDmAttribute *v35; // ebx
  int v36; // edi
  int v37; // eax
  CDmAttribute **v38; // ecx
  int v39; // eax
  CDmAttribute **v40; // eax
  CDmAttribute *v41; // ebx
  int v42; // edi
  int v43; // eax
  CDmAttribute **v44; // ecx
  int v45; // eax
  CDmAttribute **v46; // eax
  CDmAttribute *v47; // ebx
  int v48; // edi
  int v49; // eax
  CDmAttribute **v50; // ecx
  int v51; // eax
  CDmAttribute **v52; // eax
  CDmAttribute *v53; // ebx
  int v54; // edi
  int v55; // eax
  CDmAttribute **v56; // ecx
  int v57; // eax
  CDmAttribute **v58; // eax
  unsigned int nDeltas; // [esp+Ch] [ebp-Ch]
  unsigned int nDeltasa; // [esp+Ch] [ebp-Ch]
  CDmeMesh *pMesha; // [esp+10h] [ebp-8h]
  unsigned int wi; // [esp+14h] [ebp-4h]
  unsigned int wia; // [esp+14h] [ebp-4h]
  CDmeVertexData *pDeltaState; // [esp+20h] [ebp+8h]
  CDmeVertexDeltaData *pDeltaStatea; // [esp+20h] [ebp+8h]

  v3 = this;
  nDeltas = this->m_deltaStateWeights.m_Storage.m_Size;
  for ( wi = 0; wi < nDeltas; ++wi )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[wi]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v6 = v5;
    else
      v6 = nullptr;
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: "weight");
    if ( Attribute != nullptr )
    {
      v8 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v9 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v8 + 1 > v9 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v8 - v9 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v10 = (CDmAttribute **)attrs->__vftable;
      v11 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v8 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: 4 * v11);
      v12 = (CDmAttribute **)(&attrs->OnAttributeChanged + v8);
      if ( v12 != nullptr )
        *v12 = Attribute;
    }
    v3 = this;
  }
  v13 = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_mesh.m_Storage.m_Handle);
  m_pAsString = v3->m_baseStateName.m_Storage.u.m_pAsString;
  pMesha = v13;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pch;
  pDeltaState = CDmeMesh::FindBaseState(this: v13, pStateName: m_pAsString);
  v15 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "coordinates");
  if ( v15 != nullptr )
  {
    v16 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v17 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v16 + 1 > v17 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v16 - v17 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v18 = (CDmAttribute **)attrs->__vftable;
    v19 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v16 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
    v20 = (CDmAttribute **)(&attrs->OnAttributeChanged + v16);
    if ( v20 != nullptr )
      *v20 = v15;
  }
  v21 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "normals");
  if ( v21 != nullptr )
  {
    v22 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v23 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v22 + 1 > v23 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v22 - v23 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v24 = (CDmAttribute **)attrs->__vftable;
    v25 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v22 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v25 > 0 )
      _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
    v26 = (CDmAttribute **)(&attrs->OnAttributeChanged + v22);
    if ( v26 != nullptr )
      *v26 = v21;
  }
  v27 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "textureCoordinates");
  if ( v27 != nullptr )
  {
    v28 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v29 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v28 + 1 > v29 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v28 - v29 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v30 = (CDmAttribute **)attrs->__vftable;
    v31 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v28 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
    v32 = (CDmAttribute **)(&attrs->OnAttributeChanged + v28);
    if ( v32 != nullptr )
      *v32 = v27;
  }
  v33 = CDmeMesh::DeltaStateCount(this: pMesha);
  v34 = 0;
  nDeltasa = v33;
  for ( wia = 0; v34 < nDeltasa; wia = v34 )
  {
    pDeltaStatea = CDmeMesh::GetDeltaState(this: pMesha, nDeltaIndex: v34);
    v35 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "indices");
    if ( v35 != nullptr )
    {
      v36 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v37 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v36 - v37 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v38 = (CDmAttribute **)attrs->__vftable;
      v39 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v36 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = (CDmAttribute **)(&attrs->OnAttributeChanged + v36);
      if ( v40 != nullptr )
        *v40 = v35;
    }
    v41 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "coordinates");
    if ( v41 != nullptr )
    {
      v42 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v43 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v42 + 1 > v43 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v42 - v43 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v44 = (CDmAttribute **)attrs->__vftable;
      v45 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v42 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v45 > 0 )
        _V_memmove(dest: &v44[v42 + 1], src: &v44[v42], count: 4 * v45);
      v46 = (CDmAttribute **)(&attrs->OnAttributeChanged + v42);
      if ( v46 != nullptr )
        *v46 = v41;
    }
    v47 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "normals");
    if ( v47 != nullptr )
    {
      v48 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v49 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v48 + 1 > v49 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v48 - v49 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v50 = (CDmAttribute **)attrs->__vftable;
      v51 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v48 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v51 > 0 )
        _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
      v52 = (CDmAttribute **)(&attrs->OnAttributeChanged + v48);
      if ( v52 != nullptr )
        *v52 = v47;
    }
    v53 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "textureCoordinates");
    if ( v53 != nullptr )
    {
      v54 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v55 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v54 + 1 > v55 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v54 - v55 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v56 = (CDmAttribute **)attrs->__vftable;
      v57 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v54 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v57 > 0 )
        _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
      v58 = (CDmAttribute **)(&attrs->OnAttributeChanged + v54);
      if ( v58 != nullptr )
        *v58 = v53;
    }
    v34 = wia + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005233A0
// Name: public: virtual void CDmeMorphOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetOutputAttributes(
        CDmeMorphOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "coordinates");
  MorphOp::AddAttr(attrs, pAttr: Attribute);
  v4 = CDmElement::FindAttribute(this: v2, pAttributeName: "normals");
  MorphOp::AddAttr(attrs, pAttr: v4);
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "textureCoordinates");
  MorphOp::AddAttr(attrs, pAttr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00523480
// Name: public: virtual bool CDmeMorphOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMorphOperator::IsA(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005234B0
// Name: public: virtual int CDmeMorphOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMorphOperator::GetInheritanceDepth(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523500
// Name: protected: virtual void CDmeMorphOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::PerformConstruction(CDmeMorphOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
  CDmeMorphOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057E1D0
// Name: _dynamic_initializer_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMorphOperator::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMorphOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580DB0
// Name: _dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMorphOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E200
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMorphOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E210
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMorphOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMorphOperator_Helper,
           classname: "DmeMorphOperator",
           pFactory: &g_CDmeMorphOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580DC0
// Name: _dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMorphOperator_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0052A210
// Name: public: virtual void CDmeMorphOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnAttributeChanged(CDmeMorphOperator *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_mesh.m_Storage.m_ElementType.u.m_Id )
    g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)this->m_nSortKey);
}

//------------------------------------------------------------------------------
// Address: 0x0052A240
// Name: protected: void CDmeMorphOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnConstruction(CDmeMorphOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmaString *p_m_baseStateName; // esi
  CDmAttribute *v6; // eax

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_mesh.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v2,
                                pAttributeName: "mesh",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: &this->m_mesh);
  CDmAttribute::SetElementTypeSymbol(this: this->m_mesh.m_pAttribute, typeSymbol: CDmeMesh::m_classType);
  this->m_mesh.m_pAttribute->m_nFlags |= 0x100u;
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_deltaStateWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this: v3,
                                             pAttributeName: "deltaStateWeights",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_deltaStateWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_deltaStateWeights.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_deltaStateWeights.m_pAttribute->m_nFlags |= 0x800u;
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_baseStateName = &this->m_baseStateName;
  v6 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "baseStateName",
         type: AT_STRING,
         pMemory: p_m_baseStateName);
  p_m_baseStateName->m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x0052A2F0
// Name: public: virtual void CDmeMorphOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::Operate(CDmeMorphOperator *this)
{
  CDmeMorphOperator *v1; // esi
  int v2; // ebx
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  char *m_Id; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // esi
  CDmaVar<float> *m_pData; // eax
  int DeltaStateIndex; // eax
  unsigned int mn; // [esp+18h] [ebp-10h]
  float deltaWeight; // [esp+1Ch] [ebp-Ch]
  CDmeMesh *mesh; // [esp+20h] [ebp-8h]

  v1 = this;
  mesh = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  v2 = 0;
  mn = v1->m_deltaStateWeights.m_Storage.m_Size;
  if ( mn != 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
        v5 = v4;
      else
        v5 = nullptr;
      m_Id = (char *)Ptr;
      if ( v5->m_Name.m_Storage.u.m_Id != -1 )
        m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "weight");
      v8 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v8, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      deltaWeight = m_pData->m_Storage;
      DeltaStateIndex = CDmeMesh::FindDeltaStateIndex(this: mesh, pInDeltaName: m_Id, bSortDeltaName: true);
      if ( DeltaStateIndex == -1 )
        _Msg(a1: "MorphOperator::Operate: invalid delta state name: %s\n", m_Id);
      else
        CDmeMesh::SetDeltaStateWeight(
          this: mesh,
          nDeltaIndex: DeltaStateIndex,
          type: MESH_DELTA_WEIGHT_FIRST,
          flMorphWeight: deltaWeight);
      if ( ++v2 >= mn )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A460
// Name: void MorphOp::AddAttr(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphOp::AddAttr(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs, CDmAttribute *pAttr)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v5; // eax
  CDmAttribute **v6; // eax

  if ( pAttr != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v5 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
    v6 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v6 != nullptr )
      *v6 = pAttr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A4D0
// Name: public: virtual void CDmeMorphOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetInputAttributes(CDmeMorphOperator *this, CDmElement *attrs)
{
  CDmeMorphOperator *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CDmElement *v6; // ecx
  CDmAttribute *Attribute; // ebx
  int v8; // edi
  int v9; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax
  CDmeMesh *v13; // ecx
  const char *m_pAsString; // eax
  CDmAttribute *v15; // ebx
  int v16; // edi
  int v17; // eax
  CDmAttribute **v18; // ecx
  int v19; // eax
  CDmAttribute **v20; // eax
  CDmAttribute *v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmAttribute **v24; // ecx
  int v25; // eax
  CDmAttribute **v26; // eax
  CDmAttribute *v27; // ebx
  int v28; // edi
  int v29; // eax
  CDmAttribute **v30; // ecx
  int v31; // eax
  CDmAttribute **v32; // eax
  int v33; // eax
  unsigned int v34; // ecx
  CDmAttribute *v35; // ebx
  int v36; // edi
  int v37; // eax
  CDmAttribute **v38; // ecx
  int v39; // eax
  CDmAttribute **v40; // eax
  CDmAttribute *v41; // ebx
  int v42; // edi
  int v43; // eax
  CDmAttribute **v44; // ecx
  int v45; // eax
  CDmAttribute **v46; // eax
  CDmAttribute *v47; // ebx
  int v48; // edi
  int v49; // eax
  CDmAttribute **v50; // ecx
  int v51; // eax
  CDmAttribute **v52; // eax
  CDmAttribute *v53; // ebx
  int v54; // edi
  int v55; // eax
  CDmAttribute **v56; // ecx
  int v57; // eax
  CDmAttribute **v58; // eax
  unsigned int nDeltas; // [esp+Ch] [ebp-Ch]
  unsigned int nDeltasa; // [esp+Ch] [ebp-Ch]
  CDmeMesh *pMesha; // [esp+10h] [ebp-8h]
  unsigned int wi; // [esp+14h] [ebp-4h]
  unsigned int wia; // [esp+14h] [ebp-4h]
  CDmeVertexData *pDeltaState; // [esp+20h] [ebp+8h]
  CDmeVertexDeltaData *pDeltaStatea; // [esp+20h] [ebp+8h]

  v3 = this;
  nDeltas = this->m_deltaStateWeights.m_Storage.m_Size;
  for ( wi = 0; wi < nDeltas; ++wi )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[wi]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v6 = v5;
    else
      v6 = nullptr;
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: "weight");
    if ( Attribute != nullptr )
    {
      v8 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v9 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v8 + 1 > v9 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v8 - v9 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v10 = (CDmAttribute **)attrs->__vftable;
      v11 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v8 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: 4 * v11);
      v12 = (CDmAttribute **)(&attrs->OnAttributeChanged + v8);
      if ( v12 != nullptr )
        *v12 = Attribute;
    }
    v3 = this;
  }
  v13 = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_mesh.m_Storage.m_Handle);
  m_pAsString = v3->m_baseStateName.m_Storage.u.m_pAsString;
  pMesha = v13;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = Ptr;
  pDeltaState = CDmeMesh::FindBaseState(this: v13, pStateName: m_pAsString);
  v15 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "coordinates");
  if ( v15 != nullptr )
  {
    v16 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v17 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v16 + 1 > v17 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v16 - v17 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v18 = (CDmAttribute **)attrs->__vftable;
    v19 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v16 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
    v20 = (CDmAttribute **)(&attrs->OnAttributeChanged + v16);
    if ( v20 != nullptr )
      *v20 = v15;
  }
  v21 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "normals");
  if ( v21 != nullptr )
  {
    v22 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v23 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v22 + 1 > v23 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v22 - v23 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v24 = (CDmAttribute **)attrs->__vftable;
    v25 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v22 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v25 > 0 )
      _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
    v26 = (CDmAttribute **)(&attrs->OnAttributeChanged + v22);
    if ( v26 != nullptr )
      *v26 = v21;
  }
  v27 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "textureCoordinates");
  if ( v27 != nullptr )
  {
    v28 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v29 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v28 + 1 > v29 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: v28 - v29 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v30 = (CDmAttribute **)attrs->__vftable;
    v31 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v28 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
    v32 = (CDmAttribute **)(&attrs->OnAttributeChanged + v28);
    if ( v32 != nullptr )
      *v32 = v27;
  }
  v33 = CDmeMesh::DeltaStateCount(this: pMesha);
  v34 = 0;
  nDeltasa = v33;
  for ( wia = 0; v34 < nDeltasa; wia = v34 )
  {
    pDeltaStatea = CDmeMesh::GetDeltaState(this: pMesha, nDeltaIndex: v34);
    v35 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "indices");
    if ( v35 != nullptr )
    {
      v36 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v37 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v36 - v37 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v38 = (CDmAttribute **)attrs->__vftable;
      v39 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v36 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = (CDmAttribute **)(&attrs->OnAttributeChanged + v36);
      if ( v40 != nullptr )
        *v40 = v35;
    }
    v41 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "coordinates");
    if ( v41 != nullptr )
    {
      v42 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v43 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v42 + 1 > v43 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v42 - v43 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v44 = (CDmAttribute **)attrs->__vftable;
      v45 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v42 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v45 > 0 )
        _V_memmove(dest: &v44[v42 + 1], src: &v44[v42], count: 4 * v45);
      v46 = (CDmAttribute **)(&attrs->OnAttributeChanged + v42);
      if ( v46 != nullptr )
        *v46 = v41;
    }
    v47 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "normals");
    if ( v47 != nullptr )
    {
      v48 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v49 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v48 + 1 > v49 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v48 - v49 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v50 = (CDmAttribute **)attrs->__vftable;
      v51 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v48 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v51 > 0 )
        _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
      v52 = (CDmAttribute **)(&attrs->OnAttributeChanged + v48);
      if ( v52 != nullptr )
        *v52 = v47;
    }
    v53 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "textureCoordinates");
    if ( v53 != nullptr )
    {
      v54 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v55 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v54 + 1 > v55 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
          num: v54 - v55 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v56 = (CDmAttribute **)attrs->__vftable;
      v57 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v54 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v57 > 0 )
        _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
      v58 = (CDmAttribute **)(&attrs->OnAttributeChanged + v54);
      if ( v58 != nullptr )
        *v58 = v53;
    }
    v34 = wia + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052A8B0
// Name: public: virtual void CDmeMorphOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetOutputAttributes(
        CDmeMorphOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "coordinates");
  MorphOp::AddAttr(attrs, pAttr: Attribute);
  v4 = CDmElement::FindAttribute(this: v2, pAttributeName: "normals");
  MorphOp::AddAttr(attrs, pAttr: v4);
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "textureCoordinates");
  MorphOp::AddAttr(attrs, pAttr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0052A990
// Name: public: virtual bool CDmeMorphOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMorphOperator::IsA(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052A9C0
// Name: public: virtual int CDmeMorphOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMorphOperator::GetInheritanceDepth(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052AA10
// Name: protected: virtual void CDmeMorphOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::PerformConstruction(CDmeMorphOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
  CDmeMorphOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057BA20
// Name: _dynamic_initializer_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMorphOperator::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMorphOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4A0
// Name: _dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMorphOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BA50
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMorphOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BA60
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMorphOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMorphOperator_Helper,
           classname: "DmeMorphOperator",
           pFactory: &g_CDmeMorphOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4B0
// Name: _dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMorphOperator_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062D210
// Name: public: virtual void CDmeMorphOperator::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnAttributeChanged(CDmeMorphOperator *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == (CDmAttribute *)this->m_mesh.m_Storage.m_ElementType.u.m_Id )
    g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)this->m_nSortKey);
}

//------------------------------------------------------------------------------
// Address: 0x0062D240
// Name: protected: void CDmeMorphOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::OnConstruction(CDmeMorphOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmaString *p_m_baseStateName; // esi
  CDmAttribute *v6; // eax

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_mesh.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v2,
                                pAttributeName: "mesh",
                                type: AT_FIRST_VALUE_TYPE,
                                pMemory: &this->m_mesh);
  CDmAttribute::SetElementTypeSymbol(this: this->m_mesh.m_pAttribute, typeSymbol: CDmeMesh::m_classType);
  this->m_mesh.m_pAttribute->m_nFlags |= 0x100u;
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_deltaStateWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this: v3,
                                             pAttributeName: "deltaStateWeights",
                                             type: AT_FIRST_ARRAY_TYPE,
                                             pMemory: &this->m_deltaStateWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_deltaStateWeights.m_pAttribute, typeSymbol: CDmElement::m_classType);
  this->m_deltaStateWeights.m_pAttribute->m_nFlags |= 0x800u;
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  p_m_baseStateName = &this->m_baseStateName;
  v6 = CDmElement::AddExternalAttribute(
         this: v4,
         pAttributeName: "baseStateName",
         type: AT_STRING,
         pMemory: p_m_baseStateName);
  p_m_baseStateName->m_pAttribute = v6;
  v6->m_nFlags |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x0062D2F0
// Name: public: virtual void CDmeMorphOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::Operate(CDmeMorphOperator *this)
{
  CDmeMorphOperator *v1; // esi
  int v2; // ebx
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  CDmElement *v5; // ecx
  char *m_Id; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v8; // esi
  CDmaVar<float> *m_pData; // eax
  int DeltaStateIndex; // eax
  unsigned int mn; // [esp+18h] [ebp-10h]
  float deltaWeight; // [esp+1Ch] [ebp-Ch]
  CDmeMesh *mesh; // [esp+20h] [ebp-8h]

  v1 = this;
  mesh = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  v2 = 0;
  mn = v1->m_deltaStateWeights.m_Storage.m_Size;
  if ( mn != 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType) )
        v5 = v4;
      else
        v5 = nullptr;
      m_Id = (char *)var;
      if ( v5->m_Name.m_Storage.u.m_Id != -1 )
        m_Id = (char *)v5->m_Name.m_Storage.u.m_Id;
      if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
      }
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "weight");
      v8 = Attribute;
      if ( Attribute != nullptr )
      {
        if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
        {
          `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
          `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
        }
        if ( (Attribute->m_nFlags & 0x1F) == 3 )
        {
          m_pData = (CDmaVar<float> *)Attribute->m_pData;
        }
        else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
        {
          CDmAttribute::CopyDataOut<float>(this: v8, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
          m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
        }
        else
        {
          m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
        }
      }
      else
      {
        m_pData = &`CDmElement::GetValue<float>'::`2'::defaultVal;
      }
      deltaWeight = m_pData->m_Storage;
      DeltaStateIndex = CDmeMesh::FindDeltaStateIndex(this: mesh, pInDeltaName: m_Id, bSortDeltaName: true);
      if ( DeltaStateIndex == -1 )
        _Msg(a1: "MorphOperator::Operate: invalid delta state name: %s\n", m_Id);
      else
        CDmeMesh::SetDeltaStateWeight(
          this: mesh,
          nDeltaIndex: DeltaStateIndex,
          type: MESH_DELTA_WEIGHT_FIRST,
          flMorphWeight: deltaWeight);
      if ( ++v2 >= mn )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062D460
// Name: void MorphOp::AddAttr(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MorphOp::AddAttr(CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs, CDmAttribute *pAttr)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v5; // eax
  CDmAttribute **v6; // eax

  if ( pAttr != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v5 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
    v6 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v6 != nullptr )
      *v6 = pAttr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062D4D0
// Name: public: virtual void CDmeMorphOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetInputAttributes(CDmeMorphOperator *this, CDmElement *attrs)
{
  CDmeMorphOperator *v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  CDmElement *v6; // ecx
  CDmAttribute *Attribute; // ebx
  int v8; // edi
  int v9; // eax
  CDmAttribute **v10; // ecx
  int v11; // eax
  CDmAttribute **v12; // eax
  CDmeMesh *v13; // ecx
  const char *m_pAsString; // eax
  CDmAttribute *v15; // ebx
  int v16; // edi
  int v17; // eax
  CDmAttribute **v18; // ecx
  int v19; // eax
  CDmAttribute **v20; // eax
  CDmAttribute *v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmAttribute **v24; // ecx
  int v25; // eax
  CDmAttribute **v26; // eax
  CDmAttribute *v27; // ebx
  int v28; // edi
  int v29; // eax
  CDmAttribute **v30; // ecx
  int v31; // eax
  CDmAttribute **v32; // eax
  int v33; // eax
  unsigned int v34; // ecx
  CDmAttribute *v35; // ebx
  int v36; // edi
  int v37; // eax
  CDmAttribute **v38; // ecx
  int v39; // eax
  CDmAttribute **v40; // eax
  CDmAttribute *v41; // ebx
  int v42; // edi
  int v43; // eax
  CDmAttribute **v44; // ecx
  int v45; // eax
  CDmAttribute **v46; // eax
  CDmAttribute *v47; // ebx
  int v48; // edi
  int v49; // eax
  CDmAttribute **v50; // ecx
  int v51; // eax
  CDmAttribute **v52; // eax
  CDmAttribute *v53; // ebx
  int v54; // edi
  int v55; // eax
  CDmAttribute **v56; // ecx
  int v57; // eax
  CDmAttribute **v58; // eax
  unsigned int nDeltas; // [esp+Ch] [ebp-Ch]
  unsigned int nDeltasa; // [esp+Ch] [ebp-Ch]
  CDmeMesh *pMesha; // [esp+10h] [ebp-8h]
  unsigned int wi; // [esp+14h] [ebp-4h]
  unsigned int wia; // [esp+14h] [ebp-4h]
  CDmeVertexData *pDeltaState; // [esp+20h] [ebp+8h]
  CDmeVertexDeltaData *pDeltaStatea; // [esp+20h] [ebp+8h]

  v3 = this;
  nDeltas = this->m_deltaStateWeights.m_Storage.m_Size;
  for ( wi = 0; wi < nDeltas; ++wi )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_deltaStateWeights.m_Storage.m_Memory.m_pMemory[wi]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v6 = v5;
    else
      v6 = nullptr;
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: "weight");
    if ( Attribute != nullptr )
    {
      v8 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v9 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v8 + 1 > v9 )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v8 - v9 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v10 = (CDmAttribute **)attrs->__vftable;
      v11 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v8 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: 4 * v11);
      v12 = (CDmAttribute **)(&attrs->OnAttributeChanged + v8);
      if ( v12 != nullptr )
        *v12 = Attribute;
    }
    v3 = this;
  }
  v13 = (CDmeMesh *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_mesh.m_Storage.m_Handle);
  m_pAsString = v3->m_baseStateName.m_Storage.u.m_pAsString;
  pMesha = v13;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  pDeltaState = CDmeMesh::FindBaseState(this: v13, pStateName: m_pAsString);
  v15 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "coordinates");
  if ( v15 != nullptr )
  {
    v16 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v17 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v16 + 1 > v17 )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v16 - v17 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v18 = (CDmAttribute **)attrs->__vftable;
    v19 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v16 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
    v20 = (CDmAttribute **)(&attrs->OnAttributeChanged + v16);
    if ( v20 != nullptr )
      *v20 = v15;
  }
  v21 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "normals");
  if ( v21 != nullptr )
  {
    v22 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v23 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v22 + 1 > v23 )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v22 - v23 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v24 = (CDmAttribute **)attrs->__vftable;
    v25 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v22 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v25 > 0 )
      _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
    v26 = (CDmAttribute **)(&attrs->OnAttributeChanged + v22);
    if ( v26 != nullptr )
      *v26 = v21;
  }
  v27 = CDmElement::FindAttribute(this: pDeltaState, pAttributeName: "textureCoordinates");
  if ( v27 != nullptr )
  {
    v28 = *(_DWORD *)&attrs->m_Id.m_Value[8];
    v29 = *(_DWORD *)attrs->m_Id.m_Value;
    if ( v28 + 1 > v29 )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v28 - v29 + 1);
    ++*(_DWORD *)&attrs->m_Id.m_Value[8];
    v30 = (CDmAttribute **)attrs->__vftable;
    v31 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v28 - 1;
    *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
    v32 = (CDmAttribute **)(&attrs->OnAttributeChanged + v28);
    if ( v32 != nullptr )
      *v32 = v27;
  }
  v33 = CDmeMesh::DeltaStateCount(this: pMesha);
  v34 = 0;
  nDeltasa = v33;
  for ( wia = 0; v34 < nDeltasa; wia = v34 )
  {
    pDeltaStatea = CDmeMesh::GetDeltaState(this: pMesha, nDeltaIndex: v34);
    v35 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "indices");
    if ( v35 != nullptr )
    {
      v36 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v37 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v36 + 1 > v37 )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v36 - v37 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v38 = (CDmAttribute **)attrs->__vftable;
      v39 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v36 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = (CDmAttribute **)(&attrs->OnAttributeChanged + v36);
      if ( v40 != nullptr )
        *v40 = v35;
    }
    v41 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "coordinates");
    if ( v41 != nullptr )
    {
      v42 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v43 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v42 + 1 > v43 )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v42 - v43 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v44 = (CDmAttribute **)attrs->__vftable;
      v45 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v42 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v45 > 0 )
        _V_memmove(dest: &v44[v42 + 1], src: &v44[v42], count: 4 * v45);
      v46 = (CDmAttribute **)(&attrs->OnAttributeChanged + v42);
      if ( v46 != nullptr )
        *v46 = v41;
    }
    v47 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "normals");
    if ( v47 != nullptr )
    {
      v48 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v49 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v48 + 1 > v49 )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v48 - v49 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v50 = (CDmAttribute **)attrs->__vftable;
      v51 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v48 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v51 > 0 )
        _V_memmove(dest: &v50[v48 + 1], src: &v50[v48], count: 4 * v51);
      v52 = (CDmAttribute **)(&attrs->OnAttributeChanged + v48);
      if ( v52 != nullptr )
        *v52 = v47;
    }
    v53 = CDmElement::FindAttribute(this: pDeltaStatea, pAttributeName: "textureCoordinates");
    if ( v53 != nullptr )
    {
      v54 = *(_DWORD *)&attrs->m_Id.m_Value[8];
      v55 = *(_DWORD *)attrs->m_Id.m_Value;
      if ( v54 + 1 > v55 )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v54 - v55 + 1);
      ++*(_DWORD *)&attrs->m_Id.m_Value[8];
      v56 = (CDmAttribute **)attrs->__vftable;
      v57 = *(_DWORD *)&attrs->m_Id.m_Value[8] - v54 - 1;
      *(_DWORD *)&attrs->m_Id.m_Value[12] = attrs->__vftable;
      if ( v57 > 0 )
        _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
      v58 = (CDmAttribute **)(&attrs->OnAttributeChanged + v54);
      if ( v58 != nullptr )
        *v58 = v53;
    }
    v34 = wia + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062D8B0
// Name: public: virtual void CDmeMorphOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::GetOutputAttributes(
        CDmeMorphOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mesh.m_Storage.m_Handle);
  Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "coordinates");
  MorphOp::AddAttr(attrs, pAttr: Attribute);
  v4 = CDmElement::FindAttribute(this: v2, pAttributeName: "normals");
  MorphOp::AddAttr(attrs, pAttr: v4);
  v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "textureCoordinates");
  MorphOp::AddAttr(attrs, pAttr: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0062D990
// Name: public: virtual bool CDmeMorphOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMorphOperator::IsA(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062D9C0
// Name: public: virtual int CDmeMorphOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMorphOperator::GetInheritanceDepth(CDmeMorphOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMorphOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062DA10
// Name: protected: virtual void CDmeMorphOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMorphOperator::PerformConstruction(CDmeMorphOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
  CDmeMorphOperator::OnConstruction(this: (CDmeMorphOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x006B9990
// Name: _dynamic_initializer_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMorphOperator::s_Allocator,
    blockSize: 0x7Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMorphOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD2C0
// Name: _dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMorphOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMorphOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B99C0
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMorphOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B99D0
// Name: _dynamic_initializer_for__g_CDmeMorphOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMorphOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMorphOperator_Helper,
           classname: "DmeMorphOperator",
           pFactory: &g_CDmeMorphOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD2D0
// Name: _dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMorphOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMorphOperator_Factory.m_CallBackList);
}

} // namespace vmap
