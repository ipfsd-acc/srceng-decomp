// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmedag.cpp
// Functions: 40
// ============================================================

#include "movieobjects\dmedag.h"

//------------------------------------------------------------------------------
// Address: 0x0040D050
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004957B0
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x004957D0
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004958F0
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495A10
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x00495A60
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x00495AF0
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00495B10
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00495B30
// Name: public: class CDmeShape __near * CDmeDag::GetShape(void)
// Source: json
//------------------------------------------------------------------------------
CDmeShape *__thiscall CDmeDag::GetShape(CDmeDag *this)
{
  return (CDmeShape *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00495B50
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x00495C80
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: &this->CDmElement,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: &this->CDmElement,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "visible",
         type: AT_BOOL,
         pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this: &this->CDmElement,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x00495D50
// Name: public: void CDmeDag::SetShape(class CDmeShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetShape(CDmeDag *this, int pShape)
{
  CDmeShape *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pShape != 0 )
  {
    v3 = (CDmeShape *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pShape);
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pShape);
}

//------------------------------------------------------------------------------
// Address: 0x00495D90
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00495DB0
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: (CExpressionCalculator *)this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x00495E00
// Name: public: bool CDmeDag::IsAncestorOfDag(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::IsAncestorOfDag(CDmeDag *this, CExpressionCalculator *pDag)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeDag *Referring; // esi
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( pDag == nullptr )
    return 0;
  if ( (_S2_1 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_1 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: pDag,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    if ( (_S2_1 & 1) == 0 )
    {
      v5 = g_pDataModel->GetSymbol;
      _S2_1 |= 1u;
      v5(this: g_pDataModel, result: &symChildren_1, a3: "children");
    }
    Referring = FindReferringElement<CDmeDag>(
                  pElement: (CExpressionCalculator *)Referring,
                  symAttrName: symChildren_1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00495EC0
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495F10
// Name: public: bool CDmeDag::AddChild(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::AddChild(CDmeDag *this, CDmeDag *pDag)
{
  if ( pDag == nullptr || pDag == this || CDmeDag::IsAncestorOfDag(this: pDag, pDag: (CExpressionCalculator *)this) != 0 )
    return 0;
  CDmaElementArrayBase<CDmeDag,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Children,
    pValue: pDag);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00495F50
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00495F60
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004960A0
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)g_pDataModel->GetElement(
                                        this: g_pDataModel,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x00496100
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  CDmElement *v3; // esi
  unsigned int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != nullptr )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      ((void (__thiscall *)(CDmElement *, matrix3x4_t *, CDmeDrawSettings *))v3->__vftable[1].OnAttributeChanged)(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeDag::m_classType) )
          v7 = v6;
        else
          v7 = nullptr;
        v7->__vftable[1].OnAttributeChanged(this: v7, a2: (CDmAttribute *)pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004961C0
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  IDataModel_vtbl *v5; // edi
  int v6; // eax
  DmAttributeReferenceIterator_t v7; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = g_pDataModel->__vftable;
  v6 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  v7 = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
  it = v7;
  if ( v7 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v7)->m_pOwner;
      v9 = g_pDataModel->__vftable;
      v10 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v9->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v10) != nullptr
        && m_pOwner != nullptr
        && m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)m_pOwner);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496410
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: (CExpressionCalculator *)this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      localOrientation = *CDmeTransform::GetOrientation(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004966C0
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496770
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: (CExpressionCalculator *)this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x00496800
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x00496860
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496960
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x00496A40
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
// Address: 0x00496A70
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
// Address: 0x00496AB0
// Name: protected: virtual void CDmeDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformDestruction(CDmeDag *this, void *(__cdecl **a2)(const char *, int *), int a3)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeFXClip::OnDestruction(pFactoryList: a2, nFactoryCount: a3);
}

//------------------------------------------------------------------------------
// Address: 0x005651C0
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x005AB5B0
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
// Address: 0x005AB610
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF850
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AF860
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x00496320
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x005AB5E0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB5F0
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
// Address: 0x005AF870
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00403E00
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00501790
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x005017B0
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005018D0
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005019F0
// Name: public: static void CDmeDag::DrawUsingEngineCoordinates(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DrawUsingEngineCoordinates(bool bEnable)
{
  CDmeDag::s_bDrawUsingEngineCoordinates = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x00501A00
// Name: public: static void CDmeDag::DrawZUp(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DrawZUp(bool bZUp)
{
  CDmeDag::s_bDrawZUp = bZUp;
}

//------------------------------------------------------------------------------
// Address: 0x00501A10
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x00501A60
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x00501C10
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00501C30
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00501C50
// Name: public: class CDmeShape __near * CDmeDag::GetShape(void)
// Source: json
//------------------------------------------------------------------------------
CDmeShape *__thiscall CDmeDag::GetShape(CDmeDag *this)
{
  return (CDmeShape *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00501C70
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x00501D40
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x00501E10
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00501E30
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x00501E80
// Name: public: bool CDmeDag::IsAncestorOfDag(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::IsAncestorOfDag(CDmeDag *this, const CDmeDag *pDag)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeDag *Referring; // esi
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( pDag == nullptr )
    return 0;
  if ( (_S2_1 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_1 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: pDag,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    if ( (_S2_1 & 1) == 0 )
    {
      v5 = g_pDataModel->GetSymbol;
      _S2_1 |= 1u;
      v5(this: g_pDataModel, result: &symChildren_1, a3: "children");
    }
    Referring = FindReferringElement<CDmeDag>(
                  pElement: Referring,
                  symAttrName: symChildren_1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00501F40
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00501F90
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00501FA0
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005020E0
// Name: protected: void CDmeDag::GetBoundingSphere(class Vector __near &,float __near &,struct matrix3x4_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetBoundingSphere(CDmeDag *this, Vector *c0, float *r0, int pMat)
{
  CDmeTransform *v5; // eax
  const matrix3x4_t *v6; // edi
  Vector *v7; // esi
  float *v8; // ecx
  CDmElement *v9; // eax
  CDmElement *v10; // eax
  CDmeDag *v11; // edi
  CDmeDag *v12; // ecx
  float *v13; // edi
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  Vector *v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float y; // xmm2_4
  matrix3x4_t wMat; // [esp+Ch] [ebp-8Ch] BYREF
  matrix3x4_t lMat; // [esp+3Ch] [ebp-5Ch] BYREF
  float l01; // [esp+6Ch] [ebp-2Ch]
  int nChildren; // [esp+70h] [ebp-28h]
  Vector v01; // [esp+74h] [ebp-24h] BYREF
  Vector vTemp; // [esp+80h] [ebp-18h] BYREF
  Vector c1; // [esp+8Ch] [ebp-Ch] BYREF

  v5 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeTransform::GetTransform(this: v5, transform: &lMat);
  v6 = (const matrix3x4_t *)pMat;
  ConcatTransforms(in1: (const matrix3x4_t *)pMat, in2: &lMat, out: &wMat);
  v7 = c0;
  v8 = r0;
  *(_QWORD *)&c0->y = 0;
  v7->x = 0.0;
  *v8 = 0.0;
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
  if ( v9 != nullptr )
  {
    ((void (__thiscall *)(CDmElement *, Vector *, float *))v9->__vftable[1].OnAttributeArrayElementAdded)(
      a1: v9,
      a2: v7,
      a3: r0);
    VectorTransform(in1: &v7->x, in2: &lMat, out: &vTemp.x);
    *v7 = vTemp;
  }
  VectorTransform(in1: &v7->x, in2: v6, out: &vTemp.x);
  *v7 = vTemp;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren > 0 )
  {
    for ( pMat = 0; pMat < nChildren; ++pMat )
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[pMat]);
      v11 = (CDmeDag *)v10;
      if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmeDag::m_classType) )
        v12 = v11;
      else
        v12 = nullptr;
      CDmeDag::GetBoundingSphere(this: v12, c0: &c1, r0: (float *)&c0, pMat: &wMat);
      v13 = r0;
      if ( *r0 == 0.0 )
      {
        *v7 = c1;
        *v13 = *(float *)&c0;
      }
      else
      {
        v14 = c1.y - v7->y;
        v15 = c1.z - v7->z;
        v01.x = c1.x - v7->x;
        v01.y = v14;
        v01.z = v15;
        l01 = VectorNormalize(vec: &v01);
        v16 = l01;
        v17 = c0;
        v18 = *v13;
        if ( (float)(l01 + *(float *)&c0) > *v13 )
        {
          if ( (float)(v18 + l01) <= *(float *)&c0 )
          {
            *v7 = c1;
            *v13 = *(float *)&v17;
          }
          else
          {
            v19 = (float)((float)(l01 + *(float *)&c0) - v18) * 0.5;
            v20 = v01.y * v19;
            v21 = (float)(v01.z * v19) + v7->z;
            y = v7->y;
            v7->x = v7->x + (float)(v19 * v01.x);
            v7->y = y + v20;
            v7->z = v21;
            *v13 = (float)((float)(*v13 + v16) + *(float *)&v17) * 0.5;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00502360
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)g_pDataModel->GetElement(
                                        this: g_pDataModel,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x005023C0
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  CDmElement *v3; // esi
  unsigned int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != nullptr )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      ((void (__thiscall *)(CDmElement *, matrix3x4_t *, CDmeDrawSettings *))v3->__vftable[1].OnAttributeChanged)(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeDag::m_classType) )
          v7 = v6;
        else
          v7 = nullptr;
        v7->__vftable[1].OnAttributeChanged(this: v7, a2: (CDmAttribute *)pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00502570
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  IDataModel_vtbl *v5; // edi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v7; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  v7 = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  it = v7;
  if ( v7 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v7)->m_pOwner;
      v9 = g_pDataModel->__vftable;
      v10 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
      if ( v9->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v10) != nullptr
        && m_pOwner != nullptr
        && m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)m_pOwner);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005026D0
// Name: public: class CDmeDag const __near * CDmeDag::GetOverrideParent(bool __near &,bool __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetOverrideParent(CDmeDag *this, CDmeDag *bPosition, bool *bRotation, int bIgnoreEnable)
{
  CDmeDag *result; // eax
  CDmAttribute *Attribute; // eax
  bool *v8; // eax
  CDmAttribute *v9; // eax
  bool *v10; // eax
  CDmeDag *pOverrideParent; // [esp+10h] [ebp+8h]

  LOBYTE(bPosition->__vftable) = 0;
  *bRotation = false;
  if ( this->m_bDisableOverrideParent.m_Storage && (_BYTE)bIgnoreEnable == 0 )
    return nullptr;
  result = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  pOverrideParent = result;
  if ( result != nullptr )
  {
    HIBYTE(bIgnoreEnable) = 0;
    Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
    if ( Attribute != nullptr )
      v8 = (bool *)CDmAttribute::GetValue<bool>(this: Attribute);
    else
      v8 = (bool *)&bIgnoreEnable + 3;
    LOBYTE(bPosition->__vftable) = *v8;
    HIBYTE(bIgnoreEnable) = 0;
    v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
    if ( v9 != nullptr )
      v10 = (bool *)CDmAttribute::GetValue<bool>(this: v9);
    else
      v10 = (bool *)&bIgnoreEnable + 3;
    *bRotation = *v10;
    result = pOverrideParent;
  }
  if ( LOBYTE(bPosition->__vftable) == 0 && !*bRotation )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00502950
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransformControl *v13; // esi
  const Vector *Position; // eax
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v26; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v26 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v26;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v26, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
    v13 = (CDmeTransformControl *)v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      Position = CDmeTransformControl::GetPosition(this: v13);
      *(_QWORD *)&localOrientation.x = *(_QWORD *)&Position->x;
      *(_QWORD *)&localOrientation.z = *(_QWORD *)&Position->z;
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00502C00
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00502CB0
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x00502D40
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x00502DA0
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00502EA0
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x00502F80
// Name: public: void CDmeDag::FindTransformChannels(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindTransformChannels(
        CDmeDag *this,
        CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > *channelList)
{
  const CDmElement *v3; // eax
  int i; // esi
  CDmeConstraintSlave *v5; // eax
  CUtlVector<CDmeConstraintSlave *,CUtlMemory<CDmeConstraintSlave *,int> > slaveList; // [esp+Ch] [ebp-14h] BYREF

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  FindReferringElements<CDmeChannel>(
    list: channelList,
    pElement: v3,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  memset(&slaveList, 0, sizeof(slaveList));
  FindReferringElements<CDmeConstraintSlave>(
    list: &slaveList,
    pElement: this,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  for ( i = 0; i < slaveList.m_Size; ++i )
  {
    v5 = slaveList.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
      FindReferringElements<CDmeChannel>(
        list: channelList,
        pElement: v5,
        symAttrName: (CUtlSymbolLarge)-1,
        bMustBeInSameFile: false,
        depth: TD_ALL);
  }
  if ( slaveList.m_Memory.m_nGrowSize >= 0 && slaveList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: slaveList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00503030
// Name: public: class CDmeTransformControl __near * CDmeDag::FindTransformControl(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__thiscall CDmeDag::FindTransformControl(CDmeDag *this)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int v3; // edi
  CDmeChannel *v4; // ecx
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > channelList; // [esp+8h] [ebp-14h] BYREF

  Alloc_2 = _g_pMemAlloc->Alloc_2;
  channelList.m_Memory.m_nAllocationCount = 4;
  channelList.m_Memory.m_nGrowSize = 0;
  channelList.m_Memory.m_pMemory = (CDmeChannel **)Alloc_2(this: _g_pMemAlloc, a2: 16u);
  channelList.m_Size = 0;
  channelList.m_pElements = channelList.m_Memory.m_pMemory;
  CDmeDag::FindTransformChannels(this, &channelList);
  v3 = 0;
  if ( channelList.m_Size <= 0 )
  {
LABEL_6:
    if ( channelList.m_Memory.m_nGrowSize >= 0 && channelList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelList.m_Memory.m_pMemory);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v4 = channelList.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = CDmeChannel::GetFromElement(this: v4);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransformControl::m_classType) )
          break;
      }
      if ( ++v3 >= channelList.m_Size )
        goto LABEL_6;
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&channelList);
    return (CDmeTransformControl *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005030E0
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
// Address: 0x00503110
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
// Address: 0x00503150
// Name: protected: virtual void CDmeDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005C2740
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformConstruction(CDmeRigHandle *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067D0E0
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
// Address: 0x0067D140
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x00681EC0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00681ED0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x00502480
// Name: bool FindReferringElements<class CDmeChannel>(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeChannel>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeChannel *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeChannel **v11; // ecx
  int v12; // eax
  CDmeChannel **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeChannel>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeChannel **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeChannel **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00502770
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00502860
// Name: bool FindReferringElements<class CDmeConstraintSlave>(class CUtlVector<class CDmeConstraintSlave __near *,class CUtlMemory<class CDmeConstraintSlave __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeConstraintSlave>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeConstraintSlave *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeConstraintSlave **v11; // ecx
  int v12; // eax
  CDmeConstraintSlave **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeConstraintSlave>(
           this: &it,
           symAttrName,
           bMustBeInSameFile,
           depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeConstraintSlave **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeConstraintSlave **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0067D110
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D120
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
// Address: 0x00681EE0
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D8A80
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x104D8AA0
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  float angleDegrees; // [esp+0h] [ebp-8Ch] BYREF
  _BYTE rotation_60[68]; // [esp+40h] [ebp-4Ch] OVERLAPPED BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-8h]

  if ( bZUp )
  {
    *(_DWORD *)&rotation_60[64] = 0;
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(
      dst: (matrix3x4_t *)rotation_60,
      vAxisOfRot: (const Vector *)&rotation_60[64],
      angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)rotation_60;
  }
  else
  {
    *(_DWORD *)&rotation_60[64] = 1065353216;
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    MatrixBuildRotationAboutAxis(
      dst: (matrix3x4_t *)&angleDegrees,
      vAxisOfRot: (const Vector *)&rotation_60[64],
      angleDegrees: 90.0);
    *(_DWORD *)&rotation_60[64] = 0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.x = 1.0;
    MatrixBuildRotationAboutAxis(
      dst: (matrix3x4_t *)rotation_60,
      vAxisOfRot: (const Vector *)&rotation_60[64],
      angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&angleDegrees, in2: (const matrix3x4_t *)rotation_60, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D8BC0
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  float angleDegrees; // [esp+0h] [ebp-8Ch] BYREF
  _BYTE rotationZ_60[68]; // [esp+40h] [ebp-4Ch] OVERLAPPED BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-8h]

  if ( bZUp )
  {
    *(_DWORD *)&rotationZ_60[64] = 0;
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(
      dst: (matrix3x4_t *)rotationZ_60,
      vAxisOfRot: (const Vector *)&rotationZ_60[64],
      angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)rotationZ_60;
  }
  else
  {
    *(_DWORD *)&rotationZ_60[64] = 1065353216;
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    MatrixBuildRotationAboutAxis(
      dst: (matrix3x4_t *)rotationZ_60,
      vAxisOfRot: (const Vector *)&rotationZ_60[64],
      angleDegrees: -90.0);
    *(_DWORD *)&rotationZ_60[64] = 0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.x = 1.0;
    MatrixBuildRotationAboutAxis(
      dst: (matrix3x4_t *)&angleDegrees,
      vAxisOfRot: (const Vector *)&rotationZ_60[64],
      angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&angleDegrees, in2: (const matrix3x4_t *)rotationZ_60, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D8CE0
// Name: public: static void CDmeDag::DrawUsingEngineCoordinates(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DrawUsingEngineCoordinates(bool bEnable)
{
  CDmeDag::s_bDrawUsingEngineCoordinates = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x104D8CF0
// Name: public: static void CDmeDag::DrawZUp(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DrawZUp(bool bZUp)
{
  CDmeDag::s_bDrawZUp = bZUp;
}

//------------------------------------------------------------------------------
// Address: 0x104D8D00
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x104D8D50
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x104D8FB0
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x104D8FD0
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x104D8FF0
// Name: public: class CDmeShape __near * CDmeDag::GetShape(void)
// Source: json
//------------------------------------------------------------------------------
CDmeShape *__thiscall CDmeDag::GetShape(CDmeDag *this)
{
  return (CDmeShape *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x104D9010
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x104D9170
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D9230
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x104D9300
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x104D9320
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_21 & 1) == 0 )
  {
    _S2_21 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x104D9370
// Name: public: bool CDmeDag::IsAncestorOfDag(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::IsAncestorOfDag(CDmeDag *this, const CDmeDag *pDag)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeDag *Referring; // esi
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( pDag == nullptr )
    return 0;
  if ( (_S2_21 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_21 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: pDag,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    if ( (_S2_21 & 1) == 0 )
    {
      v5 = g_pDataModel->GetSymbol;
      _S2_21 |= 1u;
      v5(this: g_pDataModel, result: &symChildren_1, a3: "children");
    }
    Referring = FindReferringElement<CDmeDag>(
                  pElement: Referring,
                  symAttrName: symChildren_1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104D9430
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D9480
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x104D9490
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D95D0
// Name: protected: void CDmeDag::GetBoundingSphere(class Vector __near &,float __near &,struct matrix3x4_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetBoundingSphere(CDmeDag *this, Vector *c0, float *r0, int pMat)
{
  CDmeTransform *v5; // eax
  const matrix3x4_t *v6; // edi
  Vector *v7; // esi
  float *v8; // ecx
  CDmElement *v9; // eax
  CDmElement *v10; // eax
  CDmeDag *v11; // edi
  CDmeDag *v12; // ecx
  float *v13; // edi
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  Vector *v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float y; // xmm2_4
  matrix3x4_t wMat; // [esp+Ch] [ebp-8Ch] BYREF
  matrix3x4_t lMat; // [esp+3Ch] [ebp-5Ch] BYREF
  float l01; // [esp+6Ch] [ebp-2Ch]
  int nChildren; // [esp+70h] [ebp-28h]
  Vector v01; // [esp+74h] [ebp-24h] BYREF
  Vector vTemp; // [esp+80h] [ebp-18h] BYREF
  Vector c1; // [esp+8Ch] [ebp-Ch] BYREF

  v5 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeTransform::GetTransform(this: v5, transform: &lMat);
  v6 = (const matrix3x4_t *)pMat;
  ConcatTransforms(in1: (const matrix3x4_t *)pMat, in2: &lMat, out: &wMat);
  v7 = c0;
  v8 = r0;
  *(_QWORD *)&c0->y = 0;
  v7->x = 0.0;
  *v8 = 0.0;
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
  if ( v9 != nullptr )
  {
    ((void (__thiscall *)(CDmElement *, Vector *, float *))v9->__vftable[1].OnAttributeArrayElementAdded)(
      a1: v9,
      a2: v7,
      a3: r0);
    VectorTransform(in1: &v7->x, in2: &lMat, out: &vTemp.x);
    *v7 = vTemp;
  }
  VectorTransform(in1: &v7->x, in2: v6, out: &vTemp.x);
  *v7 = vTemp;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren > 0 )
  {
    for ( pMat = 0; pMat < nChildren; ++pMat )
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[pMat]);
      v11 = (CDmeDag *)v10;
      if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmeDag::m_classType) )
        v12 = v11;
      else
        v12 = nullptr;
      CDmeDag::GetBoundingSphere(this: v12, c0: &c1, r0: (float *)&c0, pMat: &wMat);
      v13 = r0;
      if ( *r0 == 0.0 )
      {
        *v7 = c1;
        *v13 = *(float *)&c0;
      }
      else
      {
        v14 = c1.y - v7->y;
        v15 = c1.z - v7->z;
        v01.x = c1.x - v7->x;
        v01.y = v14;
        v01.z = v15;
        l01 = VectorNormalize(vec: &v01);
        v16 = l01;
        v17 = c0;
        v18 = *v13;
        if ( (float)(l01 + *(float *)&c0) > *v13 )
        {
          if ( (float)(v18 + l01) <= *(float *)&c0 )
          {
            *v7 = c1;
            *v13 = *(float *)&v17;
          }
          else
          {
            v19 = (float)((float)(l01 + *(float *)&c0) - v18) * 0.5;
            v20 = v01.y * v19;
            v21 = (float)(v01.z * v19) + v7->z;
            y = v7->y;
            v7->x = v7->x + (float)(v19 * v01.x);
            v7->y = y + v20;
            v7->z = v21;
            *v13 = (float)((float)(*v13 + v16) + *(float *)&v17) * 0.5;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D9850
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)g_pDataModel->GetElement(
                                        this: g_pDataModel,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x104D98B0
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  CDmElement *v3; // esi
  unsigned int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != nullptr )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      ((void (__thiscall *)(CDmElement *, matrix3x4_t *, CDmeDrawSettings *))v3->__vftable[1].OnAttributeChanged)(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeDag::m_classType) )
          v7 = v6;
        else
          v7 = nullptr;
        v7->__vftable[1].OnAttributeChanged(this: v7, a2: (CDmAttribute *)pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D9A60
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(CDmeDag *this, CUtlMemory<vgui::TreeNode *,int> *operatorList)
{
  CDmElement *v3; // eax
  IDataModel_vtbl *v5; // edi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v7; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int v14; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = g_pDataModel->__vftable;
  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  v7 = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  it = v7;
  if ( v7 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v7)->m_pOwner;
      v9 = g_pDataModel->__vftable;
      v10 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pOwner);
      if ( v9->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v10) != nullptr
        && m_pOwner != nullptr
        && m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)m_pOwner);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_14;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= (int)operatorList[1].m_pMemory )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(
              this: Constraint,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v14 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v14 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v14 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v16 = (CDmeOperator **)operatorList->m_pMemory;
            v17 = (int)operatorList[1].m_pMemory - v14 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: (unsigned __int8 *)&v16[v14 + 1], src: (unsigned __int8 *)&v16[v14], count: 4 * v17);
            v18 = (CDmeOperator **)&operatorList->m_pMemory[v14];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D9BC0
// Name: public: class CDmeDag const __near * CDmeDag::GetOverrideParent(bool __near &,bool __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetOverrideParent(CDmeDag *this, CDmeDag *bPosition, bool *bRotation, int bIgnoreEnable)
{
  CDmeDag *result; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v8; // eax
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmeDag *pOverrideParent; // [esp+10h] [ebp+8h]

  LOBYTE(bPosition->__vftable) = 0;
  *bRotation = false;
  if ( this->m_bDisableOverrideParent.m_Storage && (_BYTE)bIgnoreEnable == 0 )
    return nullptr;
  result = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  pOverrideParent = result;
  if ( result != nullptr )
  {
    HIBYTE(bIgnoreEnable) = 0;
    Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
    if ( Attribute != nullptr )
      v8 = CDmAttribute::GetValue<bool>(this: Attribute);
    else
      v8 = (CDmaVar<bool> *)((char *)&bIgnoreEnable + 3);
    LOBYTE(bPosition->__vftable) = v8->m_Storage;
    HIBYTE(bIgnoreEnable) = 0;
    v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
    if ( v9 != nullptr )
      v10 = CDmAttribute::GetValue<bool>(this: v9);
    else
      v10 = (CDmaVar<bool> *)((char *)&bIgnoreEnable + 3);
    *bRotation = v10->m_Storage;
    result = pOverrideParent;
  }
  if ( LOBYTE(bPosition->__vftable) == 0 && !*bRotation )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D9E40
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool m_Storage; // bl
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v8; // eax
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransformControl *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_21 & 1) == 0 )
  {
    _S2_21 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  m_Storage = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (CDmaVar<bool> *)&bOverrideRot;
      m_Storage = v8->m_Storage;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : (CDmaVar<bool> *)&bOverrideRot;
      v11 = v10->m_Storage;
      bOverrideRot = v11;
      if ( m_Storage || v11 )
      {
        pOverrideParent = Value;
        if ( !m_Storage || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( m_Storage )
  {
    v12 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
    v13 = (CDmeTransformControl *)v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      localOrientation = (Quaternion)*CDmeTransformControl::GetPosition(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DA0F0
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax
  bool m_Storage; // bl
  CDmAttribute *v7; // eax
  CDmaVar<bool> *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (CDmaVar<bool> *)&v11;
  m_Storage = v5->m_Storage;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (CDmaVar<bool> *)&v11;
  v9 = v8->m_Storage;
  if ( !m_Storage || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DA1A0
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_21 & 1) == 0 )
  {
    _S2_21 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, (CUtlMemory<vgui::TreeNode *,int> *)operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x104DA230
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x104DA290
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DA390
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x104DA470
// Name: public: void CDmeDag::FindTransformChannels(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindTransformChannels(
        CDmeDag *this,
        CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > *channelList)
{
  const CDmElement *v3; // eax
  int i; // esi
  CDmeConstraintSlave *v5; // eax
  CUtlVector<CDmeConstraintSlave *,CUtlMemory<CDmeConstraintSlave *,int> > slaveList; // [esp+Ch] [ebp-14h] BYREF

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  FindReferringElements<CDmeChannel>(
    list: channelList,
    pElement: v3,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  memset(&slaveList, 0, sizeof(slaveList));
  FindReferringElements<CDmeConstraintSlave>(
    list: &slaveList,
    pElement: this,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  for ( i = 0; i < slaveList.m_Size; ++i )
  {
    v5 = slaveList.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
      FindReferringElements<CDmeChannel>(
        list: channelList,
        pElement: v5,
        symAttrName: (CUtlSymbolLarge)-1,
        bMustBeInSameFile: false,
        depth: TD_ALL);
  }
  if ( slaveList.m_Memory.m_nGrowSize >= 0 && slaveList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: slaveList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x104DA520
// Name: public: class CDmeTransformControl __near * CDmeDag::FindTransformControl(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__thiscall CDmeDag::FindTransformControl(CDmeDag *this)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int v3; // edi
  CDmeChannel *v4; // ecx
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > channelList; // [esp+8h] [ebp-14h] BYREF

  Alloc_2 = _g_pMemAlloc->Alloc_2;
  channelList.m_Memory.m_nAllocationCount = 4;
  channelList.m_Memory.m_nGrowSize = 0;
  channelList.m_Memory.m_pMemory = (CDmeChannel **)Alloc_2(this: _g_pMemAlloc, a2: 16u);
  channelList.m_Size = 0;
  channelList.m_pElements = channelList.m_Memory.m_pMemory;
  CDmeDag::FindTransformChannels(this, &channelList);
  v3 = 0;
  if ( channelList.m_Size <= 0 )
  {
LABEL_6:
    if ( channelList.m_Memory.m_nGrowSize >= 0 && channelList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelList.m_Memory.m_pMemory);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v4 = channelList.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = CDmeChannel::GetFromElement(this: v4);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransformControl::m_classType) )
          break;
      }
      if ( ++v3 >= channelList.m_Size )
        goto LABEL_6;
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&channelList);
    return (CDmeTransformControl *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DA5D0
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
// Address: 0x104DA600
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
// Address: 0x104DA640
// Name: protected: virtual int CDmeDag::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::AllocatedSize(CDmeDag *this)
{
  return 136;
}

//------------------------------------------------------------------------------
// Address: 0x104DA650
// Name: protected: virtual void CDmeDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x104DA670
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformConstruction(CDmeDag *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDag::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C73B0
// Name: _dynamic_initializer_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDag::s_Allocator,
    blockSize: 0x88u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7410
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCEB0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCEC0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x104D9970
// Name: bool FindReferringElements<class CDmeChannel>(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeChannel>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeChannel *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeChannel **v11; // ecx
  int v12; // eax
  CDmeChannel **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeChannel>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeChannel **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: 4 * v12);
      v13 = (CDmeChannel **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x104D9C60
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x104D9D50
// Name: bool FindReferringElements<class CDmeConstraintSlave>(class CUtlVector<class CDmeConstraintSlave __near *,class CUtlMemory<class CDmeConstraintSlave __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeConstraintSlave>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeConstraintSlave *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeConstraintSlave **v11; // ecx
  int v12; // eax
  CDmeConstraintSlave **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeConstraintSlave>(
           this: &it,
           symAttrName,
           bMustBeInSameFile,
           depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeConstraintSlave **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v11[v9 + 1], src: (unsigned __int8 *)&v11[v9], count: 4 * v12);
      v13 = (CDmeConstraintSlave **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x105C73E0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C73F0
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
// Address: 0x105CCED0
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00429F30
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5500
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x004B5520
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5640
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5760
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x004B57B0
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x004B5830
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 68))(
    a1: g_pDataModel.u,
    a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B5850
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (*(CDmeTransform *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B5870
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x004B5940
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x004B5A10
// Name: public: void CDmeDag::SetShape(class CDmeShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetShape(CDmeDag *this, CDmeShape *pShape)
{
  CDmeShape *Handle; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pShape != nullptr )
  {
    Handle = (CDmeShape *)CDmElement::GetHandle(this: pShape);
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = Handle;
  }
  else
  {
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = (CDmeShape *)-1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pShape);
}

//------------------------------------------------------------------------------
// Address: 0x004B5A50
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004B5A70
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x004B5AC0
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  int v2; // eax
  int v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5B10
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B5B20
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5C60
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                        a1: g_pDataModel.u,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x004B5CC0
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  int v3; // esi
  unsigned int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != 0 )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      (*(void (__thiscall **)(int, matrix3x4_t *, CDmeDrawSettings *))(*(_DWORD *)v3 + 56))(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeDag::m_classType.u) != 0 )
        {
          v7 = v6;
        }
        else
        {
          v7 = 0;
        }
        (*(void (__thiscall **)(int, CDmeDrawSettings *))(*(_DWORD *)v7 + 56))(a1: v7, a2: pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5E10
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  int v5; // edi
  DmElementHandle_t Handle; // eax
  int v7; // eax
  CDmeConstraintSlave *v8; // edi
  int v9; // ebx
  DmElementHandle_t v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = *(_DWORD *)g_pDataModel.u.m_Id;
  Handle = CDmElement::GetHandle(this);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v5 + 436))(
         a1: g_pDataModel.u,
         a2: Handle);
  it = v7;
  if ( v7 != 0 )
  {
    while ( 1 )
    {
      v8 = *(CDmeConstraintSlave **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                                       a1: g_pDataModel.u,
                                       a2: v7)
                                   + 8);
      v9 = *(_DWORD *)g_pDataModel.u.m_Id;
      v10 = CDmElement::GetHandle(this: v8);
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v9 + 72))(
             a1: g_pDataModel.u,
             a2: v10) != 0
        && v8 != nullptr
        && v8->IsA(this: v8, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: v8);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
             a1: g_pDataModel.u,
             a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6060
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      localOrientation = *CDmeTransform::GetOrientation(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6310
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B63C0
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x004B6450
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x004B64B0
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B65B0
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x004B5800
// Name: class CDmeTransformControl __near * CastElement<class CDmeTransformControl>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CastElement<CDmeTransformControl>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return (CDmeTransformControl *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5F70
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CDmElement *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  DmElementHandle_t Handle; // eax
  DmFileId_t m_fileId; // eax
  CDmeDag *v8; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    Handle = CDmElement::GetHandle(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v5 + 436))(
                  a1: g_pDataModel.u,
                  a2: Handle);
    m_fileId = pElement->m_fileId;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_fileId = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_fileId;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_pMemory + 1], src: &v11[m_pMemory], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[m_pMemory];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004F4F60
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x004F4F80
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F50A0
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F51C0
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x004F5210
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x004F5290
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 68))(
    a1: g_pDataModel.u,
    a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004F52B0
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (*(CDmeTransform *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004F52D0
// Name: public: class CDmeShape __near * CDmeDag::GetShape(void)
// Source: json
//------------------------------------------------------------------------------
CDmeShape *__thiscall CDmeDag::GetShape(CDmeDag *this)
{
  return (*(CDmeShape *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Shape.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004F52F0
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x004F53C0
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F5480
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x004F5550
// Name: public: void CDmeDag::SetShape(class CDmeShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetShape(CDmeDag *this, int pShape)
{
  CDmeShape *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pShape != 0 )
  {
    v3 = (CDmeShape *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pShape);
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&pShape);
}

//------------------------------------------------------------------------------
// Address: 0x004F5590
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004F55B0
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: (CExpressionCalculator *)this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x004F5600
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  int v2; // eax
  int v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F5650
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004F5660
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F57A0
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                        a1: g_pDataModel.u,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x004F5800
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  int v3; // esi
  unsigned int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != 0 )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      (*(void (__thiscall **)(int, matrix3x4_t *, CDmeDrawSettings *))(*(_DWORD *)v3 + 56))(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeDag::m_classType.u) != 0 )
        {
          v7 = v6;
        }
        else
        {
          v7 = 0;
        }
        (*(void (__thiscall **)(int, CDmeDrawSettings *))(*(_DWORD *)v7 + 56))(a1: v7, a2: pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F58C0
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList)
{
  CDmElement *v3; // eax
  int v5; // edi
  int v6; // eax
  int v7; // eax
  CExpressionCalculator *v8; // edi
  int v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int v14; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = *(_DWORD *)g_pDataModel.u.m_Id;
  v6 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(a1: g_pDataModel.u, a2: v6);
  it = v7;
  if ( v7 != 0 )
  {
    while ( 1 )
    {
      v8 = *(CExpressionCalculator **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                                         a1: g_pDataModel.u,
                                         a2: v7)
                                     + 8);
      v9 = *(_DWORD *)g_pDataModel.u.m_Id;
      v10 = CExpressionCalculator::VariableCount(this: v8);
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v9 + 72))(a1: g_pDataModel.u, a2: v10) != 0
        && v8 != nullptr
        && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
            + 4))(
             a1: v8,
             a2: CDmeConstraintSlave::m_classType.u) != 0 )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)v8);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( (int)operatorList[1].m_pMemory <= 0 )
            goto LABEL_14;
          m_pMemory = (CDmeOperator **)operatorList->m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= (int)operatorList[1].m_pMemory )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(
              this: Constraint,
              a2: (CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *)operatorList);
            v14 = (int)operatorList[1].m_pMemory;
            m_nAllocationCount = operatorList->m_nAllocationCount;
            if ( v14 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: operatorList, num: v14 - m_nAllocationCount + 1);
            ++operatorList[1].m_pMemory;
            v16 = (CDmeOperator **)operatorList->m_pMemory;
            v17 = (int)operatorList[1].m_pMemory - v14 - 1;
            operatorList[1].m_nAllocationCount = (int)operatorList->m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
            v18 = (CDmeOperator **)&operatorList->m_pMemory[v14];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
             a1: g_pDataModel.u,
             a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F5B10
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool m_Storage; // bl
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v8; // eax
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: (CExpressionCalculator *)this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  m_Storage = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (CDmaVar<bool> *)&bOverrideRot;
      m_Storage = v8->m_Storage;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : (CDmaVar<bool> *)&bOverrideRot;
      v11 = v10->m_Storage;
      bOverrideRot = v11;
      if ( m_Storage || v11 )
      {
        pOverrideParent = Value;
        if ( !m_Storage || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( m_Storage )
  {
    v12 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = CDmeTransform::GetPosition(this: v12)->m_Storage;
      localOrientation = CDmeTransform::GetOrientation(this: v13)->m_Storage;
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F5DC0
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax
  bool m_Storage; // bl
  CDmAttribute *v7; // eax
  CDmaVar<bool> *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (CDmaVar<bool> *)&v11;
  m_Storage = v5->m_Storage;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (CDmaVar<bool> *)&v11;
  v9 = v8->m_Storage;
  if ( !m_Storage || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F5E70
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: (CExpressionCalculator *)this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x004F5F00
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x004F5F60
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F6060
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x004F5260
// Name: class CDmeTransformControl __near * CastElement<class CDmeTransformControl>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CastElement<CDmeTransformControl>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return (CDmeTransformControl *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F5A20
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(a1: g_pDataModel.u, a2: v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00403D30
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DDA0
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x0046DDC0
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DEE0
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E000
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x0046E050
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x0046E0A0
// Name: class CDmeTransformControl __near * CastElement<class CDmeTransformControl>(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CastElement<CDmeTransformControl>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return (CDmeTransformControl *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E180
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0046E1A0
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0046E1C0
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x0046E290
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x0046E360
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0046E370
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x0046E3C0
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E410
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0046E420
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E560
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)g_pDataModel->GetElement(
                                        this: g_pDataModel,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x0046E5C0
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  CDmElement *v3; // esi
  unsigned int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != nullptr )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      ((void (__thiscall *)(CDmElement *, matrix3x4_t *, CDmeDrawSettings *))v3->__vftable[1].OnAttributeChanged)(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeDag::m_classType) )
          v7 = v6;
        else
          v7 = nullptr;
        v7->__vftable[1].OnAttributeChanged(this: v7, a2: (CDmAttribute *)pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E800
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  IDataModel_vtbl *v5; // edi
  int v6; // eax
  DmAttributeReferenceIterator_t v7; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = g_pDataModel->__vftable;
  v6 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  v7 = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
  it = v7;
  if ( v7 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v7)->m_pOwner;
      v9 = g_pDataModel->__vftable;
      v10 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v9->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v10) != nullptr
        && m_pOwner != nullptr
        && m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)m_pOwner);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046EA50
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      localOrientation = *CDmeTransform::GetOrientation(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046ED00
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046EDB0
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x0046EE40
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x0046EEA0
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046EFA0
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x0046F080
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
// Address: 0x0046F0B0
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
// Address: 0x0046F100
// Name: protected: virtual void CDmeDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformDestruction(CDmeDag *this, void *(__cdecl **a2)(const char *, int *), int a3)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeFXClip::OnDestruction(pFactoryList: a2, nFactoryCount: a3);
}

//------------------------------------------------------------------------------
// Address: 0x00529870
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00569CC0
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
// Address: 0x00569D20
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E0A0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E0B0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x0046E960
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00569CF0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569D00
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
// Address: 0x0056E0C0
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00405D40
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004711B0
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x004711D0
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004712F0
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471410
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x00471460
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x004714F0
// Name: class CDmeTransformControl __near * CastElement<class CDmeTransformControl>(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CastElement<CDmeTransformControl>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return (CDmeTransformControl *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471710
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00471730
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00471750
// Name: public: int CDmeDag::FindChild(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::FindChild(CDmeDag *this, CExpressionCalculator *pChild)
{
  pChild = (CExpressionCalculator *)CExpressionCalculator::VariableCount(this: pChild);
  return CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
           this: &this->m_Children,
           value: (const DmElementHandle_t *)&pChild);
}

//------------------------------------------------------------------------------
// Address: 0x00471780
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x00471A10
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x00471AE0
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00471AF0
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x00471B40
// Name: public: bool CDmeDag::IsAncestorOfDag(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::IsAncestorOfDag(CDmeDag *this, const CDmeDag *pDag)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeDag *Referring; // esi
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( pDag == nullptr )
    return 0;
  if ( (_S2_1 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_1 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: pDag,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    if ( (_S2_1 & 1) == 0 )
    {
      v5 = g_pDataModel->GetSymbol;
      _S2_1 |= 1u;
      v5(this: g_pDataModel, result: &symChildren_1, a3: "children");
    }
    Referring = FindReferringElement<CDmeDag>(
                  pElement: Referring,
                  symAttrName: symChildren_1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00471D20
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471D70
// Name: public: bool CDmeDag::AddChild(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::AddChild(CDmeDag *this, CDmeDag *pDag)
{
  if ( pDag == nullptr || pDag == this || CDmeDag::IsAncestorOfDag(this: pDag, pDag: this) != 0 )
    return 0;
  CDmaElementArrayBase<CDmeDag,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Children,
    pValue: pDag);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00471DB0
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00471DC0
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471F70
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)g_pDataModel->GetElement(
                                        this: g_pDataModel,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x00471FD0
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  CDmElement *v3; // esi
  unsigned int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != nullptr )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      ((void (__thiscall *)(CDmElement *, matrix3x4_t *, CDmeDrawSettings *))v3->__vftable[1].OnAttributeChanged)(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeDag::m_classType) )
          v7 = v6;
        else
          v7 = nullptr;
        v7->__vftable[1].OnAttributeChanged(this: v7, a2: (CDmAttribute *)pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472210
// Name: public: DmeClipStack_t::~DmeClipStack_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DmeClipStack_t::~DmeClipStack_t(DmeClipStack_t *this)
{
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &this->m_clips);
  if ( this->m_clips.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_clips.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_clips.m_Memory.m_pMemory);
      this->m_clips.m_Memory.m_pMemory = nullptr;
    }
    this->m_clips.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472250
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  IDataModel_vtbl *v5; // edi
  int v6; // eax
  DmAttributeReferenceIterator_t v7; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = g_pDataModel->__vftable;
  v6 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  v7 = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
  it = v7;
  if ( v7 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v7)->m_pOwner;
      v9 = g_pDataModel->__vftable;
      v10 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v9->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v10) != nullptr
        && m_pOwner != nullptr
        && m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)m_pOwner);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472590
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeBookmarkSet::GetBookmarks(this: v12);
      localOrientation = *CDmeTransform::GetOrientation(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472840
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004728F0
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x00472980
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x004729E0
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472AE0
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x00472BC0
// Name: public: void CDmeDag::FindTransformChannels(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindTransformChannels(
        CDmeDag *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *channelList)
{
  CExpressionCalculator *v3; // eax
  int i; // esi
  CExpressionCalculator *v5; // eax
  CUtlVector<CDmeConstraintSlave *,CUtlMemory<CDmeConstraintSlave *,int> > slaveList; // [esp+Ch] [ebp-14h] BYREF

  v3 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  FindReferringElements<CDmeChannel>(
    list: channelList,
    pElement: v3,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  memset(&slaveList, 0, sizeof(slaveList));
  FindReferringElements<CDmeConstraintSlave>(
    list: &slaveList,
    pElement: this,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  for ( i = 0; i < slaveList.m_Size; ++i )
  {
    v5 = (CExpressionCalculator *)slaveList.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
      FindReferringElements<CDmeChannel>(
        list: channelList,
        pElement: v5,
        symAttrName: (CUtlSymbolLarge)-1,
        bMustBeInSameFile: false,
        depth: TD_ALL);
  }
  if ( slaveList.m_Memory.m_nGrowSize >= 0 && slaveList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: slaveList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00472C70
// Name: public: class CDmeTransformControl __near * CDmeDag::FindTransformControl(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__thiscall CDmeDag::FindTransformControl(CDmeDag *this)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int v3; // edi
  CDmeChannel *v4; // ecx
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > channelList; // [esp+8h] [ebp-14h] BYREF

  Alloc_2 = _g_pMemAlloc->Alloc_2;
  channelList.m_Memory.m_nAllocationCount = 4;
  channelList.m_Memory.m_nGrowSize = 0;
  channelList.m_Memory.m_pMemory = (CDmeChannel **)Alloc_2(this: _g_pMemAlloc, a2: 16u);
  channelList.m_Size = 0;
  channelList.m_pElements = channelList.m_Memory.m_pMemory;
  CDmeDag::FindTransformChannels(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelList);
  v3 = 0;
  if ( channelList.m_Size <= 0 )
  {
LABEL_6:
    if ( channelList.m_Memory.m_nGrowSize >= 0 && channelList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelList.m_Memory.m_pMemory);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v4 = channelList.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = CDmeChannel::GetFromElement(this: v4);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransformControl::m_classType) )
          break;
      }
      if ( ++v3 >= channelList.m_Size )
        goto LABEL_6;
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&channelList);
    return (CDmeTransformControl *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472D20
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
// Address: 0x00472D50
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
// Address: 0x00472D90
// Name: protected: virtual void CDmeDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformDestruction(CDmeDag *this, void *(__cdecl **a2)(const char *, int *), int a3)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeFXClip::OnDestruction(pFactoryList: a2, nFactoryCount: a3);
}

//------------------------------------------------------------------------------
// Address: 0x00472DB0
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00531CE0
// Name: public: void CDmeDag::FindChildrenOfType<class CDmeRig>(class CUtlVector<class CDmeRig __near *,class CUtlMemory<class CDmeRig __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindChildrenOfType<CDmeRig>(
        CDmeDag *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *children)
{
  int v2; // edi
  CDmElement *v3; // eax
  CDmeDag *v4; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmeRig **v7; // ecx
  int v8; // eax
  CDmeRig **v9; // edi
  int nChildren; // [esp+Ch] [ebp-Ch]
  CDmeDag *v11; // [esp+10h] [ebp-8h]
  int iChild; // [esp+14h] [ebp-4h]

  v2 = 0;
  v11 = this;
  nChildren = this->m_Children.m_Storage.m_Size;
  iChild = 0;
  if ( nChildren > 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = (CDmeDag *)v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeDag::m_classType) )
      {
        if ( v4->IsA(this: v4, a2: CDmeRig::m_classType) )
        {
          m_pMemory = (int)children[1].m_pMemory;
          m_nAllocationCount = children->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: children, num: m_pMemory - m_nAllocationCount + 1);
          ++children[1].m_pMemory;
          v7 = (CDmeRig **)children->m_pMemory;
          v8 = (int)children[1].m_pMemory - m_pMemory - 1;
          children[1].m_nAllocationCount = (int)children->m_pMemory;
          if ( v8 > 0 )
            _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
          v9 = (CDmeRig **)&children->m_pMemory[m_pMemory];
          if ( v9 != nullptr )
            *v9 = (CDmeRig *)v4;
        }
        CDmeDag::FindChildrenOfType<CDmeRig>(this: v4, (CUtlVector<CDmeRig *,CUtlMemory<CDmeRig *,int> > *)children);
        v2 = iChild;
      }
      iChild = ++v2;
      if ( v2 >= nChildren )
        break;
      this = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00579DC0
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
// Address: 0x00579E20
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E1D0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E1E0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x00471C00
// Name: class CDmeFilmClip __near * FindReferringElement<class CDmeFilmClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFilmClip *__cdecl FindReferringElement<CDmeFilmClip>(
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
  CDmeFilmClip *result; // eax
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFilmClip>(
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
// Address: 0x00471C90
// Name: class CDmeChannelsClip __near * FindReferringElement<class CDmeChannelsClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *__cdecl FindReferringElement<CDmeChannelsClip>(
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
  CDmeChannelsClip *result; // eax
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
    result = CAttributeReferenceIterator::FilterReference<CDmeChannelsClip>(
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
// Address: 0x004723B0
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004724A0
// Name: bool FindReferringElements<class CDmeConstraintSlave>(class CUtlVector<class CDmeConstraintSlave __near *,class CUtlMemory<class CDmeConstraintSlave __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeConstraintSlave>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeConstraintSlave *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeConstraintSlave **v11; // ecx
  int v12; // eax
  CDmeConstraintSlave **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeConstraintSlave>(
           this: &it,
           symAttrName,
           bMustBeInSameFile,
           depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeConstraintSlave **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeConstraintSlave **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00579DF0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579E00
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
// Address: 0x0057E1F0
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0051E0C0
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x0051E0E0
// Name: public: void CDmeDag::RemoveChild(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::RemoveChild(CDmeDag *this, int i)
{
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::FastRemove(
    this: &this->m_Children,
    elem: i);
}

//------------------------------------------------------------------------------
// Address: 0x0051E0F0
// Name: public: void CDmeDag::RemoveAllChildren(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::RemoveAllChildren(CDmeDag *this)
{
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Children);
}

//------------------------------------------------------------------------------
// Address: 0x0051E100
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E220
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E340
// Name: public: static void CDmeDag::DrawUsingEngineCoordinates(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DrawUsingEngineCoordinates(bool bEnable)
{
  CDmeDag::s_bDrawUsingEngineCoordinates = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x0051E350
// Name: public: static void CDmeDag::DrawZUp(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DrawZUp(bool bZUp)
{
  CDmeDag::s_bDrawZUp = bZUp;
}

//------------------------------------------------------------------------------
// Address: 0x0051E360
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x0051E3B0
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x0051E580
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 68))(
    a1: g_pDataModel.u,
    a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0051E5A0
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (*(CDmeTransform *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0051E5C0
// Name: public: class CDmeShape __near * CDmeDag::GetShape(void)
// Source: json
//------------------------------------------------------------------------------
CDmeShape *__thiscall CDmeDag::GetShape(CDmeDag *this)
{
  return (*(CDmeShape *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Shape.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0051E5E0
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x0051E6B0
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051E770
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x0051E840
// Name: public: void CDmeDag::SetShape(class CDmeShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetShape(CDmeDag *this, int pShape)
{
  CDmeShape *BufferType; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pShape != 0 )
  {
    BufferType = (CDmeShape *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pShape);
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = (int)BufferType;
  }
  else
  {
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pShape);
}

//------------------------------------------------------------------------------
// Address: 0x0051E880
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0051E8A0
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: (CExpressionCalculator *)this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x0051E8F0
// Name: public: bool CDmeDag::IsAncestorOfDag(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::IsAncestorOfDag(CDmeDag *this, CExpressionCalculator *pDag)
{
  void (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeDag *Referring; // esi
  void (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // eax

  if ( pDag == nullptr )
    return 0;
  if ( (_S2_1 & 1) == 0 )
  {
    v3 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S2_1 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: pDag,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    if ( (_S2_1 & 1) == 0 )
    {
      v5 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
      _S2_1 |= 1u;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v5)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: &symChildren_1,
        a3: "children");
    }
    Referring = FindReferringElement<CDmeDag>(
                  pElement: (CExpressionCalculator *)Referring,
                  symAttrName: symChildren_1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E9B0
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  int v2; // eax
  int v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051EA00
// Name: public: bool CDmeDag::AddChild(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::AddChild(CDmeDag *this, CDmeDag *pDag)
{
  if ( pDag == nullptr || pDag == this || CDmeDag::IsAncestorOfDag(this: pDag, pDag: (CExpressionCalculator *)this) != 0 )
    return 0;
  CDmaElementArrayBase<CDmePresetGroup,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Children,
    pValue: pDag);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051EA40
// Name: public: int CDmeDag::FindChild(class CDmeDag __near * __near &,class CDmeDag const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::FindChild(CDmeDag *this, CDmeDag **pParent, CExpressionCalculator *pChild)
{
  CDmaElementArray<CDmeDag> *p_m_Children; // ebx
  int result; // eax
  int v6; // edi
  int v7; // eax
  CDmeDag *v8; // esi
  CDmeDag *v9; // ecx
  int nChildren; // [esp+Ch] [ebp-4h] BYREF

  nChildren = CCodecBuffer_Block::GetBufferType(this: pChild);
  p_m_Children = &this->m_Children;
  result = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
             this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_Children,
             src: (vgui::PageTab **)&nChildren);
  if ( result < 0 )
  {
    v6 = 0;
    nChildren = this->m_Children.m_Storage.m_Size;
    if ( nChildren <= 0 )
    {
LABEL_10:
      *pParent = nullptr;
      return -1;
    }
    else
    {
      while ( 1 )
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: p_m_Children->m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeDag *)v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeDag::m_classType.u) != 0 )
        {
          v9 = v8;
        }
        else
        {
          v9 = nullptr;
        }
        result = CDmeDag::FindChild(this: v9, pParent, (const CDmeDag *)pChild);
        if ( result >= 0 )
          break;
        if ( ++v6 >= nChildren )
          goto LABEL_10;
      }
    }
  }
  else
  {
    *pParent = this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051EAF0
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0051EB00
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051EC40
// Name: protected: void CDmeDag::GetBoundingSphere(class Vector __near &,float __near &,struct matrix3x4_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetBoundingSphere(CDmeDag *this, Vector *c0, float *r0, int pMat)
{
  CDmeTransform *v5; // eax
  const matrix3x4_t *v6; // edi
  Vector *v7; // esi
  float *v8; // ecx
  int v9; // eax
  int v10; // eax
  CDmeDag *v11; // edi
  CDmeDag *v12; // ecx
  float *v13; // edi
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  Vector *v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float y; // xmm2_4
  matrix3x4_t wMat; // [esp+Ch] [ebp-8Ch] BYREF
  matrix3x4_t lMat; // [esp+3Ch] [ebp-5Ch] BYREF
  float l01; // [esp+6Ch] [ebp-2Ch]
  int nChildren; // [esp+70h] [ebp-28h]
  Vector v01; // [esp+74h] [ebp-24h] BYREF
  Vector vTemp; // [esp+80h] [ebp-18h] BYREF
  Vector c1; // [esp+8Ch] [ebp-Ch] BYREF

  v5 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  CDmeTransform::GetTransform(this: v5, transform: &lMat);
  v6 = (const matrix3x4_t *)pMat;
  ConcatTransforms(in1: (const matrix3x4_t *)pMat, in2: &lMat, out: &wMat);
  v7 = c0;
  v8 = r0;
  *(_QWORD *)&c0->y = 0;
  v7->x = 0.0;
  *v8 = 0.0;
  v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Shape.m_Storage.m_Handle);
  if ( v9 != 0 )
  {
    (*(void (__thiscall **)(int, Vector *, float *))(*(_DWORD *)v9 + 60))(a1: v9, a2: v7, a3: r0);
    VectorTransform(in1: &v7->x, in2: &lMat, out: &vTemp.x);
    *v7 = vTemp;
  }
  VectorTransform(in1: &v7->x, in2: v6, out: &vTemp.x);
  *v7 = vTemp;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren > 0 )
  {
    for ( pMat = 0; pMat < nChildren; ++pMat )
    {
      v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_Children.m_Storage.m_Memory.m_pMemory[pMat]);
      v11 = (CDmeDag *)v10;
      if ( v10 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
             a1: v10,
             a2: CDmeDag::m_classType.u) != 0 )
      {
        v12 = v11;
      }
      else
      {
        v12 = nullptr;
      }
      CDmeDag::GetBoundingSphere(this: v12, c0: &c1, r0: (float *)&c0, pMat: &wMat);
      v13 = r0;
      if ( *r0 == 0.0 )
      {
        *v7 = c1;
        *v13 = *(float *)&c0;
      }
      else
      {
        v14 = c1.y - v7->y;
        v15 = c1.z - v7->z;
        v01.x = c1.x - v7->x;
        v01.y = v14;
        v01.z = v15;
        l01 = VectorNormalize(vec: &v01);
        v16 = l01;
        v17 = c0;
        v18 = *v13;
        if ( (float)(l01 + *(float *)&c0) > *v13 )
        {
          if ( (float)(v18 + l01) <= *(float *)&c0 )
          {
            *v7 = c1;
            *v13 = *(float *)&v17;
          }
          else
          {
            v19 = (float)((float)(l01 + *(float *)&c0) - v18) * 0.5;
            v20 = v01.y * v19;
            v21 = (float)(v01.z * v19) + v7->z;
            y = v7->y;
            v7->x = v7->x + (float)(v19 * v01.x);
            v7->y = y + v20;
            v7->z = v21;
            *v13 = (float)((float)(*v13 + v16) + *(float *)&v17) * 0.5;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051EEC0
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                        a1: g_pDataModel.u,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x0051EF20
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  int v3; // esi
  unsigned int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != 0 )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      (*(void (__thiscall **)(int, matrix3x4_t *, CDmeDrawSettings *))(*(_DWORD *)v3 + 56))(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeDag::m_classType.u) != 0 )
        {
          v7 = v6;
        }
        else
        {
          v7 = 0;
        }
        (*(void (__thiscall **)(int, CDmeDrawSettings *))(*(_DWORD *)v7 + 56))(a1: v7, a2: pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051EFE0
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  int v5; // edi
  int BufferType; // eax
  int v7; // eax
  CExpressionCalculator *v8; // edi
  int v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = *(_DWORD *)g_pDataModel.u.m_Id;
  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(a1: g_pDataModel.u, a2: BufferType);
  it = v7;
  if ( v7 != 0 )
  {
    while ( 1 )
    {
      v8 = *(CExpressionCalculator **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                                         a1: g_pDataModel.u,
                                         a2: v7)
                                     + 8);
      v9 = *(_DWORD *)g_pDataModel.u.m_Id;
      v10 = CCodecBuffer_Block::GetBufferType(this: v8);
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v9 + 72))(a1: g_pDataModel.u, a2: v10) != 0
        && v8 != nullptr
        && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
            + 4))(
             a1: v8,
             a2: CDmeConstraintSlave::m_classType.u) != 0 )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)v8);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
             a1: g_pDataModel.u,
             a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F140
// Name: public: class CDmeDag const __near * CDmeDag::GetOverrideParent(bool __near &,bool __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetOverrideParent(CDmeDag *this, CDmeDag *bPosition, bool *bRotation, int bIgnoreEnable)
{
  CDmeDag *result; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v8; // eax
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  CDmeDag *pOverrideParent; // [esp+10h] [ebp+8h]

  LOBYTE(bPosition->__vftable) = 0;
  *bRotation = false;
  if ( this->m_bDisableOverrideParent.m_Storage && (_BYTE)bIgnoreEnable == 0 )
    return nullptr;
  result = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  pOverrideParent = result;
  if ( result != nullptr )
  {
    HIBYTE(bIgnoreEnable) = 0;
    Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
    if ( Attribute != nullptr )
      v8 = CDmAttribute::GetValue<bool>(this: Attribute);
    else
      v8 = (CDmaVar<bool> *)((char *)&bIgnoreEnable + 3);
    LOBYTE(bPosition->__vftable) = v8->m_Storage;
    HIBYTE(bIgnoreEnable) = 0;
    v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
    if ( v9 != nullptr )
      v10 = CDmAttribute::GetValue<bool>(this: v9);
    else
      v10 = (CDmaVar<bool> *)((char *)&bIgnoreEnable + 3);
    *bRotation = v10->m_Storage;
    result = pOverrideParent;
  }
  if ( LOBYTE(bPosition->__vftable) == 0 && !*bRotation )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051F3C0
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool m_Storage; // bl
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v8; // eax
  CDmAttribute *v9; // eax
  CDmaVar<bool> *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransformControl *v13; // esi
  const Vector *Position; // eax
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v26; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: (CExpressionCalculator *)this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v26 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  m_Storage = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (CDmaVar<bool> *)&bOverrideRot;
      m_Storage = v8->m_Storage;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : (CDmaVar<bool> *)&bOverrideRot;
      v11 = v10->m_Storage;
      bOverrideRot = v11;
      if ( m_Storage || v11 )
      {
        pOverrideParent = Value;
        if ( !m_Storage || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v26;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v26, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( m_Storage )
  {
    v12 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_Transform.m_Storage.m_Handle);
    v13 = (CDmeTransformControl *)v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      Position = CDmeTransformControl::GetPosition(this: v13);
      *(_QWORD *)&localOrientation.x = *(_QWORD *)&Position->x;
      *(_QWORD *)&localOrientation.z = *(_QWORD *)&Position->z;
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F670
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax
  bool m_Storage; // bl
  CDmAttribute *v7; // eax
  CDmaVar<bool> *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (CDmaVar<bool> *)&v11;
  m_Storage = v5->m_Storage;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (CDmaVar<bool> *)&v11;
  v9 = v8->m_Storage;
  if ( !m_Storage || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F720
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: (CExpressionCalculator *)this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x0051F7B0
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x0051F810
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F910
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x0051F9F0
// Name: public: void CDmeDag::FindTransformChannels(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindTransformChannels(CDmeDag *this, CUtlMemory<vgui::TreeNode *,int> *channelList)
{
  CExpressionCalculator *v3; // eax
  int i; // esi
  CExpressionCalculator *v5; // eax
  CUtlVector<CDmeConstraintSlave *,CUtlMemory<CDmeConstraintSlave *,int> > slaveList; // [esp+Ch] [ebp-14h] BYREF

  v3 = (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                  a1: g_pDataModel.u,
                                  a2: this->m_Transform.m_Storage.m_Handle);
  FindReferringElements<CDmeChannel>(
    list: channelList,
    pElement: v3,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  memset(&slaveList, 0, sizeof(slaveList));
  FindReferringElements<CDmeConstraintSlave>(
    list: &slaveList,
    pElement: this,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  for ( i = 0; i < slaveList.m_Size; ++i )
  {
    v5 = (CExpressionCalculator *)slaveList.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
      FindReferringElements<CDmeChannel>(
        list: channelList,
        pElement: v5,
        symAttrName: (CUtlSymbolLarge)-1,
        bMustBeInSameFile: false,
        depth: TD_ALL);
  }
  if ( slaveList.m_Memory.m_nGrowSize >= 0 && slaveList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: slaveList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0051FAA0
// Name: public: class CDmeTransformControl __near * CDmeDag::FindTransformControl(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__thiscall CDmeDag::FindTransformControl(CDmeDag *this)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int v3; // edi
  CDmeChannel *v4; // ecx
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > channelList; // [esp+8h] [ebp-14h] BYREF

  Alloc_2 = _g_pMemAlloc->Alloc_2;
  channelList.m_Memory.m_nAllocationCount = 4;
  channelList.m_Memory.m_nGrowSize = 0;
  channelList.m_Memory.m_pMemory = (CDmeChannel **)Alloc_2(this: _g_pMemAlloc, a2: 16u);
  channelList.m_Size = 0;
  channelList.m_pElements = channelList.m_Memory.m_pMemory;
  CDmeDag::FindTransformChannels(this, (CUtlMemory<vgui::TreeNode *,int> *)&channelList);
  v3 = 0;
  if ( channelList.m_Size <= 0 )
  {
LABEL_6:
    if ( channelList.m_Memory.m_nGrowSize >= 0 && channelList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelList.m_Memory.m_pMemory);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v4 = channelList.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = CDmeChannel::GetFromElement(this: v4);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransformControl::m_classType) )
          break;
      }
      if ( ++v3 >= channelList.m_Size )
        goto LABEL_6;
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&channelList);
    return (CDmeTransformControl *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051F1E0
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(
                  a1: g_pDataModel.u,
                  a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051F2D0
// Name: bool FindReferringElements<class CDmeConstraintSlave>(class CUtlVector<class CDmeConstraintSlave __near *,class CUtlMemory<class CDmeConstraintSlave __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeConstraintSlave>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeConstraintSlave *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeConstraintSlave **v11; // ecx
  int v12; // eax
  CDmeConstraintSlave **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(
                  a1: g_pDataModel.u,
                  a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeConstraintSlave>(
           this: &it,
           symAttrName,
           bMustBeInSameFile,
           depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeConstraintSlave **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeConstraintSlave **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00406C10
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471DD0
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x00471DF0
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471F10
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472030
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x00472080
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x00472110
// Name: class CDmeTransformControl __near * CastElement<class CDmeTransformControl>(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CastElement<CDmeTransformControl>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return (CDmeTransformControl *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472330
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00472350
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00472370
// Name: public: int CDmeDag::FindChild(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::FindChild(CDmeDag *this, CExpressionCalculator *pChild)
{
  pChild = (CExpressionCalculator *)CExpressionCalculator::VariableCount(this: pChild);
  return CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
           this: &this->m_Children,
           value: (const DmElementHandle_t *)&pChild);
}

//------------------------------------------------------------------------------
// Address: 0x004723A0
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x00472630
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x00472700
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00472710
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x00472760
// Name: public: bool CDmeDag::IsAncestorOfDag(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::IsAncestorOfDag(CDmeDag *this, const CDmeDag *pDag)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeDag *Referring; // esi
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( pDag == nullptr )
    return 0;
  if ( (_S2_1 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_1 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: pDag,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    if ( (_S2_1 & 1) == 0 )
    {
      v5 = g_pDataModel->GetSymbol;
      _S2_1 |= 1u;
      v5(this: g_pDataModel, result: &symChildren_1, a3: "children");
    }
    Referring = FindReferringElement<CDmeDag>(
                  pElement: Referring,
                  symAttrName: symChildren_1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00472940
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472990
// Name: public: bool CDmeDag::AddChild(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::AddChild(CDmeDag *this, CDmeDag *pDag)
{
  if ( pDag == nullptr || pDag == this || CDmeDag::IsAncestorOfDag(this: pDag, pDag: this) != 0 )
    return 0;
  CDmaElementArrayBase<CDmeDag,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Children,
    pValue: (int)pDag);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004729D0
// Name: public: int CDmeDag::FindChild(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::FindChild(CDmeDag *this, const char *name)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  int nChildren; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( _V_strcmp(s1: m_pAsString, s2: name) == 0 )
      break;
    if ( ++v3 >= nChildren )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00472A60
// Name: public: class CDmeDag __near * CDmeDag::FindOrAddChild(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::FindOrAddChild(CDmeDag *this, const char *name)
{
  int Child; // eax
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  DmElementHandle_t v7; // eax
  CDmElement *v8; // eax

  Child = CDmeDag::FindChild(this, name);
  if ( Child < 0 )
  {
    v7 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id,
           a3: name,
           a4: this->m_fileId,
           a5: nullptr);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7);
    v5 = (CDmeDag *)v8;
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeDag::m_classType) )
      return nullptr;
    if ( v5 != this && CDmeDag::IsAncestorOfDag(this: v5, pDag: this) == 0 )
      CDmaElementArrayBase<CDmeDag,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Children,
        pValue: (int)v5);
  }
  else
  {
    if ( Child >= this->m_Children.m_Storage.m_Size )
      return nullptr;
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[Child]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00472B30
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00472B40
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472CF0
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)g_pDataModel->GetElement(
                                        this: g_pDataModel,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x00472F90
// Name: public: DmeClipStack_t::~DmeClipStack_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DmeClipStack_t::~DmeClipStack_t(DmeClipStack_t *this)
{
  CUtlVector<CDmeHandle<CDmeClip,0>,CUtlMemory<CDmeHandle<CDmeClip,0>,int>>::Purge(this: &this->m_clips);
  if ( this->m_clips.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_clips.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_clips.m_Memory.m_pMemory);
      this->m_clips.m_Memory.m_pMemory = nullptr;
    }
    this->m_clips.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472FD0
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  IDataModel_vtbl *v5; // edi
  int v6; // eax
  DmAttributeReferenceIterator_t v7; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = g_pDataModel->__vftable;
  v6 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  v7 = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
  it = v7;
  if ( v7 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v7)->m_pOwner;
      v9 = g_pDataModel->__vftable;
      v10 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v9->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v10) != nullptr
        && m_pOwner != nullptr
        && m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)m_pOwner);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473310
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeBookmarkSet::GetBookmarks(this: v12);
      localOrientation = *CDmeTransform::GetOrientation(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004735C0
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473670
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x00473700
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x00473760
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473860
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x00473940
// Name: public: void CDmeDag::FindTransformChannels(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindTransformChannels(
        CDmeDag *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *channelList)
{
  CExpressionCalculator *v3; // eax
  int i; // esi
  CExpressionCalculator *v5; // eax
  CUtlVector<CDmeConstraintSlave *,CUtlMemory<CDmeConstraintSlave *,int> > slaveList; // [esp+Ch] [ebp-14h] BYREF

  v3 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  FindReferringElements<CDmeChannel>(
    list: channelList,
    pElement: v3,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  memset(&slaveList, 0, sizeof(slaveList));
  FindReferringElements<CDmeConstraintSlave>(
    list: &slaveList,
    pElement: this,
    symAttrName: (CUtlSymbolLarge)-1,
    bMustBeInSameFile: false,
    depth: TD_ALL);
  for ( i = 0; i < slaveList.m_Size; ++i )
  {
    v5 = (CExpressionCalculator *)slaveList.m_Memory.m_pMemory[i];
    if ( v5 != nullptr )
      FindReferringElements<CDmeChannel>(
        list: channelList,
        pElement: v5,
        symAttrName: (CUtlSymbolLarge)-1,
        bMustBeInSameFile: false,
        depth: TD_ALL);
  }
  if ( slaveList.m_Memory.m_nGrowSize >= 0 && slaveList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: slaveList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004739F0
// Name: public: class CDmeTransformControl __near * CDmeDag::FindTransformControl(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__thiscall CDmeDag::FindTransformControl(CDmeDag *this)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int v3; // edi
  CDmeChannel *v4; // ecx
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CUtlVector<CDmeChannel *,CUtlMemory<CDmeChannel *,int> > channelList; // [esp+8h] [ebp-14h] BYREF

  Alloc_2 = _g_pMemAlloc->Alloc_2;
  channelList.m_Memory.m_nAllocationCount = 4;
  channelList.m_Memory.m_nGrowSize = 0;
  channelList.m_Memory.m_pMemory = (CDmeChannel **)Alloc_2(this: _g_pMemAlloc, a2: 16u);
  channelList.m_Size = 0;
  channelList.m_pElements = channelList.m_Memory.m_pMemory;
  CDmeDag::FindTransformChannels(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&channelList);
  v3 = 0;
  if ( channelList.m_Size <= 0 )
  {
LABEL_6:
    if ( channelList.m_Memory.m_nGrowSize >= 0 && channelList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: channelList.m_Memory.m_pMemory);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v4 = channelList.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = CDmeChannel::GetFromElement(this: v4);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransformControl::m_classType) )
          break;
      }
      if ( ++v3 >= channelList.m_Size )
        goto LABEL_6;
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&channelList);
    return (CDmeTransformControl *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473AA0
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
// Address: 0x00473AD0
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
// Address: 0x00473B20
// Name: protected: virtual void CDmeDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformDestruction(CDmeDag *this, void *(__cdecl **a2)(const char *, int *), int a3)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeFXClip::OnDestruction(pFactoryList: a2, nFactoryCount: a3);
}

//------------------------------------------------------------------------------
// Address: 0x00473B40
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00532E70
// Name: public: void CDmeDag::FindChildrenOfType<class CDmeRig>(class CUtlVector<class CDmeRig __near *,class CUtlMemory<class CDmeRig __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindChildrenOfType<CDmeRig>(
        CDmeDag *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *children)
{
  int v2; // edi
  CDmElement *v3; // eax
  CDmeDag *v4; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmeRig **v7; // ecx
  int v8; // eax
  CDmeRig **v9; // edi
  int nChildren; // [esp+Ch] [ebp-Ch]
  CDmeDag *v11; // [esp+10h] [ebp-8h]
  int iChild; // [esp+14h] [ebp-4h]

  v2 = 0;
  v11 = this;
  nChildren = this->m_Children.m_Storage.m_Size;
  iChild = 0;
  if ( nChildren > 0 )
  {
    while ( 1 )
    {
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v2]);
      v4 = (CDmeDag *)v3;
      if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeDag::m_classType) )
      {
        if ( v4->IsA(this: v4, a2: CDmeRig::m_classType) )
        {
          m_pMemory = (int)children[1].m_pMemory;
          m_nAllocationCount = children->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: children, num: m_pMemory - m_nAllocationCount + 1);
          ++children[1].m_pMemory;
          v7 = (CDmeRig **)children->m_pMemory;
          v8 = (int)children[1].m_pMemory - m_pMemory - 1;
          children[1].m_nAllocationCount = (int)children->m_pMemory;
          if ( v8 > 0 )
            _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
          v9 = (CDmeRig **)&children->m_pMemory[m_pMemory];
          if ( v9 != nullptr )
            *v9 = (CDmeRig *)v4;
        }
        CDmeDag::FindChildrenOfType<CDmeRig>(this: v4, (CUtlVector<CDmeRig *,CUtlMemory<CDmeRig *,int> > *)children);
        v2 = iChild;
      }
      iChild = ++v2;
      if ( v2 >= nChildren )
        break;
      this = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057BDB0
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
// Address: 0x0057BE10
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x005801B0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005801C0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x00472820
// Name: class CDmeFilmClip __near * FindReferringElement<class CDmeFilmClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFilmClip *__cdecl FindReferringElement<CDmeFilmClip>(
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
  CDmeFilmClip *result; // eax
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
    result = CAttributeReferenceIterator::FilterReference<CDmeFilmClip>(
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
// Address: 0x004728B0
// Name: class CDmeChannelsClip __near * FindReferringElement<class CDmeChannelsClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *__cdecl FindReferringElement<CDmeChannelsClip>(
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
  CDmeChannelsClip *result; // eax
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
    result = CAttributeReferenceIterator::FilterReference<CDmeChannelsClip>(
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
// Address: 0x00473130
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00473220
// Name: bool FindReferringElements<class CDmeConstraintSlave>(class CUtlVector<class CDmeConstraintSlave __near *,class CUtlMemory<class CDmeConstraintSlave __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeConstraintSlave>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeConstraintSlave *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeConstraintSlave **v11; // ecx
  int v12; // eax
  CDmeConstraintSlave **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeConstraintSlave>(
           this: &it,
           symAttrName,
           bMustBeInSameFile,
           depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeConstraintSlave **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeConstraintSlave **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0057BDE0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BDF0
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
// Address: 0x005801D0
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0046CE10
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EE000
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x004EE020
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EE140
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EE260
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x004EE2B0
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x004EE330
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 68))(
    a1: g_pDataModel.u,
    a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004EE350
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (*(CDmeTransform *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004EE370
// Name: public: class CDmeShape __near * CDmeDag::GetShape(void)
// Source: json
//------------------------------------------------------------------------------
CDmeShape *__thiscall CDmeDag::GetShape(CDmeDag *this)
{
  return (*(CDmeShape *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Shape.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004EE390
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x004EE460
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x004EE530
// Name: public: void CDmeDag::SetShape(class CDmeShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetShape(CDmeDag *this, int pShape)
{
  CDmeShape *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pShape != 0 )
  {
    v3 = (CDmeShape *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pShape);
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pShape);
}

//------------------------------------------------------------------------------
// Address: 0x004EE570
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x004EE590
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x004EE5E0
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  int v2; // eax
  int v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EE630
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004EE640
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EE780
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                        a1: g_pDataModel.u,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x004EE7E0
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  int v3; // esi
  unsigned int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != 0 )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      (*(void (__thiscall **)(int, matrix3x4_t *, CDmeDrawSettings *))(*(_DWORD *)v3 + 56))(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeDag::m_classType.u) != 0 )
        {
          v7 = v6;
        }
        else
        {
          v7 = 0;
        }
        (*(void (__thiscall **)(int, CDmeDrawSettings *))(*(_DWORD *)v7 + 56))(a1: v7, a2: pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EE8A0
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  int v5; // edi
  int v6; // eax
  int v7; // eax
  CExpressionCalculator *v8; // edi
  int v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = *(_DWORD *)g_pDataModel.u.m_Id;
  v6 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(a1: g_pDataModel.u, a2: v6);
  it = v7;
  if ( v7 != 0 )
  {
    while ( 1 )
    {
      v8 = *(CExpressionCalculator **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 332))(
                                         a1: g_pDataModel.u,
                                         a2: v7)
                                     + 8);
      v9 = *(_DWORD *)g_pDataModel.u.m_Id;
      v10 = CExpressionCalculator::VariableCount(this: v8);
      if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v9 + 72))(a1: g_pDataModel.u, a2: v10) != 0
        && v8 != nullptr
        && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v8->m_expr.m_Storage.m_Memory.m_pMemory
            + 4))(
             a1: v8,
             a2: CDmeConstraintSlave::m_classType.u) != 0 )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)v8);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
             a1: g_pDataModel.u,
             a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EEAF0
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      localOrientation = *CDmeTransform::GetOrientation(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EEDA0
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EEE50
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &symChildren_1,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x004EEEE0
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x004EEF40
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EF040
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x004EE300
// Name: class CDmeTransformControl __near * CastElement<class CDmeTransformControl>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CastElement<CDmeTransformControl>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return (CDmeTransformControl *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EEA00
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(a1: g_pDataModel.u, a2: v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x004124F0
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474560
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x00474580
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004746A0
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004747C0
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x00474810
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x004748A0
// Name: class CDmeTransformControl __near * CastElement<class CDmeTransformControl>(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CastElement<CDmeTransformControl>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return (CDmeTransformControl *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474A30
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00474A50
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00474A70
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x00474BD0
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: this,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x00474CA0
// Name: public: void CDmeDag::SetShape(class CDmeShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetShape(CDmeDag *this, int pShape)
{
  CDmeShape *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pShape != 0 )
  {
    v3 = (CDmeShape *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pShape);
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pShape);
}

//------------------------------------------------------------------------------
// Address: 0x00474CE0
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00474CF0
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x00474D40
// Name: public: bool CDmeDag::IsAncestorOfDag(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::IsAncestorOfDag(CDmeDag *this, const CDmeDag *pDag)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeDag *Referring; // esi
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( pDag == nullptr )
    return 0;
  if ( (_S2_1 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_1 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: pDag,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    if ( (_S2_1 & 1) == 0 )
    {
      v5 = g_pDataModel->GetSymbol;
      _S2_1 |= 1u;
      v5(this: g_pDataModel, result: &symChildren_1, a3: "children");
    }
    Referring = FindReferringElement<CDmeDag>(
                  pElement: Referring,
                  symAttrName: symChildren_1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00474E00
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474E50
// Name: public: bool CDmeDag::AddChild(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::AddChild(CDmeDag *this, CDmeDag *pDag)
{
  if ( pDag == nullptr || pDag == this || CDmeDag::IsAncestorOfDag(this: pDag, pDag: this) != 0 )
    return 0;
  CDmaElementArrayBase<CDmeDag,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Children,
    pValue: pDag);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00474E90
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00474EA0
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474FF0
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)g_pDataModel->GetElement(
                                        this: g_pDataModel,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x00475050
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  CDmElement *v3; // esi
  unsigned int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != nullptr )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      ((void (__thiscall *)(CDmElement *, matrix3x4_t *, CDmeDrawSettings *))v3->__vftable[1].OnAttributeChanged)(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeDag::m_classType) )
          v7 = v6;
        else
          v7 = nullptr;
        v7->__vftable[1].OnAttributeChanged(this: v7, a2: (CDmAttribute *)pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475290
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  IDataModel_vtbl *v5; // edi
  int v6; // eax
  DmAttributeReferenceIterator_t v7; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = g_pDataModel->__vftable;
  v6 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  v7 = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
  it = v7;
  if ( v7 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v7)->m_pOwner;
      v9 = g_pDataModel->__vftable;
      v10 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pOwner);
      if ( v9->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v10) != nullptr
        && m_pOwner != nullptr
        && m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)m_pOwner);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004754E0
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      localOrientation = *CDmeTransform::GetOrientation(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: (CDmeDag *)pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: (CDmeDag *)pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475790
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475840
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x004758D0
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x00475930
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475A30
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x00475B10
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
// Address: 0x00475B40
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
// Address: 0x00475B80
// Name: protected: virtual void CDmeDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005381D0
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformConstruction(CDmeRigHandle *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005792C0
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
// Address: 0x00579320
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D740
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D750
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x004753F0
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeDag *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeDag **v11; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeDag **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeDag **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x005792F0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579300
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
// Address: 0x0057D760
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0040E680
// Name: public: void CUtlMemory<struct CDmeDag::TransformInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(CUtlMemory<CDmeDag::TransformInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDmeDag::TransformInfo_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Realloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: m_pMemory,
                                                      a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CDmeDag::TransformInfo_t *)_g_pMemAlloc->Alloc_2(
                                                      this: _g_pMemAlloc,
                                                      a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057F330
// Name: public: virtual void CDmeDag::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Resolve(CDmeDag *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overrideParent");
  if ( Attribute != nullptr )
    Attribute->m_nFlags |= 0x1000u;
}

//------------------------------------------------------------------------------
// Address: 0x0057F350
// Name: public: static void CDmeDag::DmeToEngineMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::DmeToEngineMatrix(matrix3x4_t *dmeToEngine, bool bZUp)
{
  VMatrix rotation; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotationZ; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    *dmeToEngine = *(matrix3x4_t *)&rotationZ.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: 90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: 90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotation, in2: (const matrix3x4_t *)&rotationZ, out: dmeToEngine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057F470
// Name: public: static void CDmeDag::EngineToDmeMatrix(struct matrix3x4_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeDag::EngineToDmeMatrix(matrix3x4_t *engineToDme, bool bZUp)
{
  VMatrix rotationZ; // [esp+4h] [ebp-8Ch] BYREF
  VMatrix rotation; // [esp+44h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+84h] [ebp-Ch] BYREF

  if ( bZUp )
  {
    vAxisOfRot.x = 0.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    *engineToDme = *(matrix3x4_t *)&rotation.m[0][0];
  }
  else
  {
    vAxisOfRot.x = 1.0;
    vAxisOfRot.y = 0.0;
    vAxisOfRot.z = 0.0;
    MatrixBuildRotationAboutAxis(dst: &rotation, &vAxisOfRot, angleDegrees: -90.0);
    vAxisOfRot.x = 0.0;
    vAxisOfRot.z = 0.0;
    vAxisOfRot.y = 1.0;
    MatrixBuildRotationAboutAxis(dst: &rotationZ, &vAxisOfRot, angleDegrees: -90.0);
    ConcatTransforms(in1: (const matrix3x4_t *)&rotationZ, in2: (const matrix3x4_t *)&rotation, out: engineToDme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057F590
// Name: public: void CDmeDag::GetAbsPosition(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsPosition(CDmeDag *this, Vector *absPos)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixGetColumn(in: &abs, column: 3, out: absPos);
}

//------------------------------------------------------------------------------
// Address: 0x0057F5E0
// Name: public: void CDmeDag::GetAbsOrientation(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsOrientation(CDmeDag *this, Quaternion *absOrientation)
{
  matrix3x4_t abs; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t m; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t mParentToWorld; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  CDmeDag::GetLocalMatrix(this, &m);
  ConcatTransforms(in1: &mParentToWorld, in2: &m, out: &abs);
  MatrixQuaternion(mat: &abs, q: absOrientation);
}

//------------------------------------------------------------------------------
// Address: 0x0057F670
// Name: class CDmeTransformControl __near * CastElement<class CDmeTransformControl>(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformControl *__cdecl CastElement<CDmeTransformControl>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    return (CDmeTransformControl *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057F750
// Name: protected: void CDmeDag::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0057F770
// Name: public: class CDmeTransform __near * CDmeDag::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeDag::GetTransform(CDmeDag *this)
{
  return (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0057F790
// Name: public: void CDmeDag::GetLocalMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetLocalMatrix(CDmeDag *this, matrix3x4_t *m)
{
  CDmeTransform *v2; // eax

  v2 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
    CDmeTransform::GetTransform(this: v2, transform: m);
  else
    SetIdentityMatrix(matrix: m);
}

//------------------------------------------------------------------------------
// Address: 0x0057F860
// Name: protected: void CDmeDag::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::OnConstruction(CDmeDag *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmaElement<CDmeTransform>::InitAndCreate(
    this: &this->m_Transform,
    pOwner: &this->CDmElement,
    pAttributeName: "transform",
    pElementName: nullptr,
    flags: 0);
  this->m_Shape.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: &this->CDmElement,
                                 pAttributeName: "shape",
                                 type: AT_FIRST_VALUE_TYPE,
                                 pMemory: &this->m_Shape);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Shape.m_pAttribute, typeSymbol: CDmeShape::m_classType);
  value = true;
  v2 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "visible",
         type: AT_BOOL,
         pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  this->m_Visible.m_pAttribute->m_nFlags |= 0x100u;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this: &this->CDmElement,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Children.m_pAttribute, typeSymbol: CDmeDag::m_classType);
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this: &this->CDmElement,
         pAttributeName: "disableOverride",
         type: AT_BOOL,
         pMemory: &this->m_bDisableOverrideParent);
  this->m_bDisableOverrideParent.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bDisableOverrideParent.m_pAttribute->m_nFlags |= 0x8040u;
}

//------------------------------------------------------------------------------
// Address: 0x0057F930
// Name: public: void CDmeDag::SetShape(class CDmeShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetShape(CDmeDag *this, int pShape)
{
  CDmeShape *CenterVertIndex; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pShape != 0 )
  {
    CenterVertIndex = (CDmeShape *)CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)pShape);
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = (int)CenterVertIndex;
  }
  else
  {
    m_pAttribute = this->m_Shape.m_pAttribute;
    pShape = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pShape);
}

//------------------------------------------------------------------------------
// Address: 0x0057F970
// Name: public: bool CDmeDag::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsVisible(CDmeDag *this)
{
  return this->m_Visible.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0057F980
// Name: public: class CDmeDag __near * CDmeDag::GetParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetParent(CDmeDag *this)
{
  if ( (_S2_4 & 1) == 0 )
  {
    _S2_4 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symChildren_1,
           bMustBeInSameFile: false,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x0057F9D0
// Name: public: bool CDmeDag::IsAncestorOfDag(class CDmeDag const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::IsAncestorOfDag(CDmeDag *this, const CDmeDag *pDag)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeDag *Referring; // esi
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( pDag == nullptr )
    return 0;
  if ( (_S2_4 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_4 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: pDag,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    if ( (_S2_4 & 1) == 0 )
    {
      v5 = g_pDataModel->GetSymbol;
      _S2_4 |= 1u;
      v5(this: g_pDataModel, result: &symChildren_1, a3: "children");
    }
    Referring = FindReferringElement<CDmeDag>(
                  pElement: Referring,
                  symAttrName: symChildren_1,
                  bMustBeInSameFile: false,
                  depth: TD_ALL);
    if ( Referring == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0057FA90
// Name: public: class CDmeDag __near * CDmeDag::GetChild(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeDag::GetChild(CDmeDag *this, int i)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( i >= 0
    && i < this->m_Children.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[i]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
  {
    return (CDmeDag *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057FAE0
// Name: public: bool CDmeDag::AddChild(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDag::AddChild(CDmeDag *this, CDmeDag *pDag)
{
  if ( pDag == nullptr || pDag == this || CDmeDag::IsAncestorOfDag(this: pDag, pDag: this) != 0 )
    return 0;
  CDmaElementArrayBase<CDmeDag,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Children,
    pValue: pDag);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0057FB20
// Name: protected: void CDmeDag::PopDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PopDagTransform(CDmeDag *this)
{
  --CDmeDag::s_TransformStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0057FB30
// Name: public: void CDmeDag::GetShapeToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetShapeToWorldTransform(CDmeDag *this, matrix3x4_t *mat)
{
  int m_Size; // edi
  int v3; // esi
  bool *p_m_bComputedDagToWorld; // eax
  int v5; // ebx
  CDmeDag::TransformInfo_t *v6; // esi
  matrix3x4_t localToParent; // [esp+4h] [ebp-34h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size != 0 )
  {
    if ( CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_bComputedDagToWorld )
    {
      MatrixCopy(
        in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[CDmeDag::s_TransformStack.m_Size - 1].m_DagToWorld,
        out: mat);
    }
    else
    {
      v3 = 0;
      if ( CDmeDag::s_TransformStack.m_Size <= 0 )
        goto LABEL_12;
      p_m_bComputedDagToWorld = &CDmeDag::s_TransformStack.m_Memory.m_pMemory->m_bComputedDagToWorld;
      do
      {
        if ( !*p_m_bComputedDagToWorld )
          break;
        ++v3;
        p_m_bComputedDagToWorld += 56;
      }
      while ( v3 < CDmeDag::s_TransformStack.m_Size );
      if ( v3 != 0 )
      {
        MatrixCopy(in: &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1].m_DagToWorld, out: mat);
      }
      else
      {
LABEL_12:
        if ( CDmeDag::s_bDrawUsingEngineCoordinates )
          CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
        else
          SetIdentityMatrix(matrix: mat);
      }
      if ( v3 < m_Size )
      {
        v5 = v3;
        v8 = m_Size - v3;
        do
        {
          v6 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5];
          CDmeTransform::GetTransform(
            this: CDmeDag::s_TransformStack.m_Memory.m_pMemory[v5].m_pTransform,
            transform: &localToParent);
          ConcatTransforms(in1: mat, in2: &localToParent, out: &v6->m_DagToWorld);
          v6->m_bComputedDagToWorld = true;
          MatrixCopy(in: &v6->m_DagToWorld, out: mat);
          ++v5;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( CDmeDag::s_bDrawUsingEngineCoordinates )
  {
    CDmeDag::DmeToEngineMatrix(dmeToEngine: mat, bZUp: CDmeDag::s_bDrawZUp);
  }
  else
  {
    SetIdentityMatrix(matrix: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057FC70
// Name: protected: void CDmeDag::PushDagTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PushDagTransform(CDmeDag *this)
{
  int m_Size; // eax
  int v3; // eax
  CDmeDag::TransformInfo_t *v4; // esi

  m_Size = CDmeDag::s_TransformStack.m_Size;
  if ( CDmeDag::s_TransformStack.m_Size >= CDmeDag::s_TransformStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CDmeDag::TransformInfo_t,int>::Grow(this: &CDmeDag::s_TransformStack.m_Memory, num: 1);
    m_Size = CDmeDag::s_TransformStack.m_Size;
  }
  v3 = m_Size + 1;
  CDmeDag::s_TransformStack.m_pElements = CDmeDag::s_TransformStack.m_Memory.m_pMemory;
  v4 = &CDmeDag::s_TransformStack.m_Memory.m_pMemory[v3 - 1];
  CDmeDag::s_TransformStack.m_Size = v3;
  v4->m_pTransform = (CDmeTransform *)g_pDataModel->GetElement(
                                        this: g_pDataModel,
                                        a2: this->m_Transform.m_Storage.m_Handle);
  v4->m_bComputedDagToWorld = false;
}

//------------------------------------------------------------------------------
// Address: 0x0057FCD0
// Name: public: virtual void CDmeDag::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::Draw(CDmeDag *this, CDmeDrawSettings *pDrawSettings)
{
  CDmElement *v3; // esi
  unsigned int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-34h] BYREF
  unsigned int cn; // [esp+3Ch] [ebp-4h]

  if ( this->m_Visible.m_Storage )
  {
    CDmeDag::PushDagTransform(this);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Shape.m_Storage.m_Handle);
    if ( v3 != nullptr )
    {
      CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
      ((void (__thiscall *)(CDmElement *, matrix3x4_t *, CDmeDrawSettings *))v3->__vftable[1].OnAttributeChanged)(
        a1: v3,
        a2: &shapeToWorld,
        a3: pDrawSettings);
    }
    v4 = 0;
    cn = this->m_Children.m_Storage.m_Size;
    if ( cn != 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeDag::m_classType) )
          v7 = v6;
        else
          v7 = nullptr;
        v7->__vftable[1].OnAttributeChanged(this: v7, a2: (CDmAttribute *)pDrawSettings);
        ++v4;
      }
      while ( v4 < cn );
    }
    --CDmeDag::s_TransformStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057FF10
// Name: public: void CDmeDag::FindLocalOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindLocalOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmElement *v3; // eax
  IDataModel_vtbl *v5; // edi
  int CenterVertIndex; // eax
  DmAttributeReferenceIterator_t v7; // eax
  CDmElement *m_pOwner; // edi
  IDataModel_vtbl *v9; // ebx
  int v10; // eax
  CDmeRigBaseConstraintOperator *Constraint; // ebx
  int v12; // eax
  CDmeOperator **m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeOperator **v16; // ecx
  int v17; // eax
  CDmeOperator **v18; // edi
  DmAttributeReferenceIterator_t it; // [esp+14h] [ebp+8h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  GatherOperatorsForElement(pRootElement: v3, operatorList);
  v5 = g_pDataModel->__vftable;
  CenterVertIndex = CCoreDispNode::GetCenterVertIndex((CVTFTexture *)this);
  v7 = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
  it = v7;
  if ( v7 != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
  {
    while ( 1 )
    {
      m_pOwner = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v7)->m_pOwner;
      v9 = g_pDataModel->__vftable;
      v10 = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)m_pOwner);
      if ( v9->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v10) != nullptr
        && m_pOwner != nullptr
        && m_pOwner->IsA(this: m_pOwner, a2: CDmeConstraintSlave::m_classType) )
      {
        Constraint = CDmeConstraintSlave::GetConstraint(this: (CDmeConstraintSlave *)m_pOwner);
        if ( Constraint != nullptr )
        {
          v12 = 0;
          if ( operatorList->m_Size <= 0 )
            goto LABEL_14;
          m_pMemory = operatorList->m_Memory.m_pMemory;
          while ( *m_pMemory != Constraint )
          {
            ++v12;
            ++m_pMemory;
            if ( v12 >= operatorList->m_Size )
              goto LABEL_14;
          }
          if ( v12 == -1 )
          {
LABEL_14:
            Constraint->GatherInputOperators(this: Constraint, a2: operatorList);
            m_Size = operatorList->m_Size;
            m_nAllocationCount = operatorList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<HemiLightData_t *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)operatorList,
                num: m_Size - m_nAllocationCount + 1);
            ++operatorList->m_Size;
            v16 = operatorList->m_Memory.m_pMemory;
            v17 = operatorList->m_Size - m_Size - 1;
            operatorList->m_pElements = operatorList->m_Memory.m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 4 * v17);
            v18 = &operatorList->m_Memory.m_pMemory[m_Size];
            if ( v18 != nullptr )
              *v18 = Constraint;
          }
        }
      }
      it = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it);
      if ( it == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
        break;
      v7 = it;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00580160
// Name: public: void CDmeDag::GetParentWorldMatrix(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Referring; // eax
  bool v4; // zf
  CDmeDag *Value; // edi
  bool v6; // bl
  CDmAttribute *Attribute; // eax
  const bool *v8; // eax
  CDmAttribute *v9; // eax
  const bool *v10; // eax
  bool v11; // al
  CDmeTransform *v12; // eax
  CDmeTransform *v13; // esi
  matrix3x4_t mWorldTransform; // [esp+Ch] [ebp-10Ch] BYREF
  matrix3x4_t mInvLocalTransform; // [esp+3Ch] [ebp-DCh] BYREF
  matrix3x4_t mLocalTransform; // [esp+6Ch] [ebp-ACh] BYREF
  Quaternion absOrientation; // [esp+9Ch] [ebp-7Ch] BYREF
  Quaternion parentOrientation; // [esp+ACh] [ebp-6Ch] BYREF
  Quaternion worldOrientation; // [esp+BCh] [ebp-5Ch] BYREF
  Quaternion localOrientation; // [esp+CCh] [ebp-4Ch] BYREF
  Vector worldPosition; // [esp+DCh] [ebp-3Ch] BYREF
  Vector overridePosition; // [esp+E8h] [ebp-30h] BYREF
  Vector absPosition; // [esp+F4h] [ebp-24h] BYREF
  Vector localPosition; // [esp+100h] [ebp-18h] BYREF
  CDmeDag *v25; // [esp+10Ch] [ebp-Ch]
  const CDmeDag *pOverrideParent; // [esp+110h] [ebp-8h]
  bool bOverrideRot; // [esp+117h] [ebp-1h] BYREF

  if ( (_S2_4 & 1) == 0 )
  {
    _S2_4 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  v4 = !this->m_bDisableOverrideParent.m_Storage;
  Value = Referring;
  v25 = Referring;
  if ( !v4 || CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent") == nullptr )
  {
    if ( Value == nullptr )
    {
      SetIdentityMatrix(matrix: mParentToWorld);
      return;
    }
    goto LABEL_29;
  }
  v6 = false;
  bOverrideRot = false;
  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent");
    if ( Value != nullptr )
    {
      bOverrideRot = false;
      Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overridePos");
      v8 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : &bOverrideRot;
      v6 = *v8;
      bOverrideRot = false;
      v9 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overrideRot");
      v10 = v9 != nullptr ? CDmAttribute::GetValue<bool>(this: v9) : &bOverrideRot;
      v11 = *v10;
      bOverrideRot = v11;
      if ( v6 || v11 )
      {
        pOverrideParent = Value;
        if ( !v6 || !bOverrideRot )
          goto LABEL_19;
LABEL_29:
        CDmeDag::GetAbsTransform(this: Value, matAbsTransform: mParentToWorld);
        return;
      }
    }
    pOverrideParent = nullptr;
LABEL_19:
    Value = v25;
    goto LABEL_20;
  }
  pOverrideParent = nullptr;
LABEL_20:
  if ( Value != nullptr )
    CDmeDag::GetAbsTransform(this: v25, matAbsTransform: mParentToWorld);
  else
    SetIdentityMatrix(matrix: mParentToWorld);
  if ( v6 )
  {
    v12 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
    v13 = v12;
    if ( v12 != nullptr )
    {
      localPosition = *CDmeTransform::GetPosition(this: v12);
      localOrientation = *CDmeTransform::GetOrientation(this: v13);
      MatrixQuaternion(mat: mParentToWorld, q: &parentOrientation);
      QuaternionMult(p: &parentOrientation, q: &localOrientation, qt: &worldOrientation);
      CDmeDag::GetAbsPosition(this: pOverrideParent, absPos: &overridePosition);
      worldPosition.x = localPosition.x + overridePosition.x;
      worldPosition.y = localPosition.y + overridePosition.y;
      worldPosition.z = overridePosition.z + localPosition.z;
      QuaternionMatrix(q: &worldOrientation, pos: &worldPosition, matrix: &mWorldTransform);
      QuaternionMatrix(q: &localOrientation, pos: &localPosition, matrix: &mLocalTransform);
      MatrixInvert(in: &mLocalTransform, out: &mInvLocalTransform);
      ConcatTransforms(in1: &mWorldTransform, in2: &mInvLocalTransform, out: mParentToWorld);
    }
  }
  else if ( bOverrideRot )
  {
    CDmeDag::GetAbsOrientation(this: pOverrideParent, &absOrientation);
    absPosition.x = mParentToWorld->m_flMatVal[0][3];
    absPosition.y = mParentToWorld->m_flMatVal[1][3];
    absPosition.z = mParentToWorld->m_flMatVal[2][3];
    QuaternionMatrix(q: &absOrientation, pos: &absPosition, matrix: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00580410
// Name: public: void CDmeDag::GetTranslationParentWorldMatrix(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetTranslationParentWorldMatrix(CDmeDag *this, matrix3x4_t *mParentToWorld)
{
  CDmeDag *Value; // edi
  CDmAttribute *Attribute; // eax
  const bool *v5; // eax
  bool v6; // bl
  CDmAttribute *v7; // eax
  const bool *v8; // eax
  bool v9; // al
  Vector overridePosition; // [esp+8h] [ebp-10h] BYREF
  char v11; // [esp+17h] [ebp-1h] BYREF

  if ( this->m_bDisableOverrideParent.m_Storage )
    goto LABEL_12;
  Value = CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent");
  if ( Value == nullptr )
    goto LABEL_12;
  v11 = 0;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overridePos");
  v5 = Attribute != nullptr ? CDmAttribute::GetValue<bool>(this: Attribute) : (const bool *)&v11;
  v6 = *v5;
  v11 = 0;
  v7 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "overrideRot");
  v8 = v7 != nullptr ? CDmAttribute::GetValue<bool>(this: v7) : (const bool *)&v11;
  v9 = *v8;
  if ( !v6 || v9 )
  {
LABEL_12:
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld);
  }
  else
  {
    CDmeDag::GetAbsPosition(this: Value, absPos: &overridePosition);
    SetIdentityMatrix(matrix: mParentToWorld);
    MatrixSetColumn(in: &overridePosition, column: 3, out: mParentToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005804C0
// Name: public: void CDmeDag::FindRelevantOperators(class CUtlVector<class CDmeOperator __near *,class CUtlMemory<class CDmeOperator __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::FindRelevantOperators(
        CDmeDag *this,
        CUtlVector<CDmeOperator *,CUtlMemory<CDmeOperator *,int> > *operatorList)
{
  CDmeDag *Value; // eax
  CDmeDag *Referring; // eax

  if ( !this->m_bDisableOverrideParent.m_Storage )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent");
    if ( Value != nullptr )
      CDmeDag::FindRelevantOperators(this: Value, operatorList);
  }
  if ( (_S2_4 & 1) == 0 )
  {
    _S2_4 |= 1u;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &symChildren_1, a3: "children");
  }
  Referring = FindReferringElement<CDmeDag>(
                pElement: this,
                symAttrName: symChildren_1,
                bMustBeInSameFile: false,
                depth: TD_ALL);
  if ( Referring != nullptr )
    CDmeDag::FindRelevantOperators(this: Referring, operatorList);
  CDmeDag::FindLocalOperators(this, operatorList);
}

//------------------------------------------------------------------------------
// Address: 0x00580550
// Name: public: void CDmeDag::GetAbsTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::GetAbsTransform(CDmeDag *this, matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // eax
  matrix3x4_t parentToWorld; // [esp+4h] [ebp-60h] BYREF
  matrix3x4_t localMatrix; // [esp+34h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, transform: &localMatrix);
  else
    SetIdentityMatrix(matrix: &localMatrix);
  ConcatTransforms(in1: &parentToWorld, in2: &localMatrix, out: matAbsTransform);
}

//------------------------------------------------------------------------------
// Address: 0x005805B0
// Name: public: void CDmeDag::SetAbsTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsTransform(CDmeDag *this, const matrix3x4_t *matAbsTransform)
{
  CDmeTransform *v3; // edi
  matrix3x4_t mTranslationWorldToParent; // [esp+8h] [ebp-13Ch] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-10Ch] BYREF
  matrix3x4_t mTranslationParentToWorld; // [esp+68h] [ebp-DCh] BYREF
  matrix3x4_t localSpace; // [esp+98h] [ebp-ACh] BYREF
  matrix3x4_t parentToWorld; // [esp+C8h] [ebp-7Ch] BYREF
  matrix3x4_t mTranslationLocalSpace; // [esp+F8h] [ebp-4Ch] BYREF
  Quaternion localRot; // [esp+128h] [ebp-1Ch] BYREF
  Vector localPos; // [esp+138h] [ebp-Ch] BYREF

  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
  {
    CDmeDag::GetParentWorldMatrix(this, mParentToWorld: &parentToWorld);
    MatrixInvert(in: &parentToWorld, out: &worldToParent);
    ConcatTransforms(in1: &worldToParent, in2: matAbsTransform, out: &localSpace);
    MatrixAngles(matrix: &localSpace, q: &localRot, pos: &localPos);
    if ( !this->m_bDisableOverrideParent.m_Storage
      && CDmElement::GetValueElement<CDmeDag>(this: &this->CDmElement, pAttributeName: "overrideParent") != nullptr )
    {
      CDmeDag::GetTranslationParentWorldMatrix(this, mParentToWorld: &mTranslationParentToWorld);
      MatrixInvert(in: &mTranslationParentToWorld, out: &mTranslationWorldToParent);
      ConcatTransforms(in1: &mTranslationWorldToParent, in2: matAbsTransform, out: &mTranslationLocalSpace);
      localPos.x = mTranslationLocalSpace.m_flMatVal[0][3];
      localPos.y = mTranslationLocalSpace.m_flMatVal[1][3];
      localPos.z = mTranslationLocalSpace.m_flMatVal[2][3];
    }
    CDmeTransform::SetPosition(this: v3, vecPosition: &localPos);
    CDmeTransform::SetOrientation(this: v3, orientation: &localRot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005806B0
// Name: public: void CDmeDag::SetAbsPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::SetAbsPosition(CDmeDag *this, const Vector *absPos)
{
  CDmeTransform *v3; // eax
  matrix3x4_t mParentToWorld; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t transform; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t abs; // [esp+64h] [ebp-30h] BYREF

  CDmeDag::GetParentWorldMatrix(this, &mParentToWorld);
  v3 = (CDmeTransform *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  if ( v3 != nullptr )
    CDmeTransform::GetTransform(this: v3, &transform);
  else
    SetIdentityMatrix(matrix: &transform);
  ConcatTransforms(in1: &mParentToWorld, in2: &transform, out: &abs);
  MatrixSetColumn(in: absPos, column: 3, out: &abs);
  CDmeDag::SetAbsTransform(this, matAbsTransform: &abs);
}

//------------------------------------------------------------------------------
// Address: 0x00580790
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
// Address: 0x005807C0
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
// Address: 0x00580800
// Name: protected: virtual void CDmeDag::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformDestruction(CDmeDag *this)
{
  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Transform.m_Storage.m_Handle);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00580820
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformConstruction(CDmeRigHandle *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B7570
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
// Address: 0x006B75D0
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC6C0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC6D0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x00580070
// Name: bool FindReferringElements<class CDmeDag>(class CUtlVector<class CDmeDag __near *,class CUtlMemory<class CDmeDag __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeDag>(
        CUtlVector<CDmeDag *,CUtlMemory<CDmeDag *,int> > *list,
        CVTFTexture *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v5; // esi
  int CenterVertIndex; // eax
  DmFileId_t y_low; // eax
  CDmeDag *v8; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmeDag **m_pMemory; // ecx
  int v12; // eax
  CDmeDag **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = g_pDataModel->__vftable;
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: pElement);
    it.m_curr = v5->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
    y_low = LODWORD(pElement->m_vecReflectivity.y);
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    y_low = DMFILEID_INVALID;
  }
  for ( it.m_fileid = y_low;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      m_Size = list->m_Size;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v12 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &list->m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return list->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x006B75A0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B75B0
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
// Address: 0x006BC6E0
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

} // namespace vmap
