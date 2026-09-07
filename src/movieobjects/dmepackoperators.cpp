// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmepackoperators.cpp
// Functions: 76
// ============================================================

#include "movieobjects\dmepackoperators.h"

//------------------------------------------------------------------------------
// Address: 0x004B2980
// Name: protected: virtual int CDmePackVector2Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::AllocatedSize(CDmeUnpackVector2Operator *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x004B48F0
// Name: protected: virtual int CDmePackVector3Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::AllocatedSize(CDmeUnpackQAngleOperator *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x0055CC90
// Name: protected: void CDmePackQuaternionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::OnConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_quaternion.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "quaternion",
                                      type: AT_QUATERNION,
                                      pMemory: &this->m_quaternion);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_x.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v3,
                             pAttributeName: "x",
                             type: AT_FLOAT,
                             pMemory: &this->m_x);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_y.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v4,
                             pAttributeName: "y",
                             type: AT_FLOAT,
                             pMemory: &this->m_y);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_z.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v5,
                             pAttributeName: "z",
                             type: AT_FLOAT,
                             pMemory: &this->m_z);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_w.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v6,
                             pAttributeName: "w",
                             type: AT_FLOAT,
                             pMemory: &this->m_w);
}

//------------------------------------------------------------------------------
// Address: 0x0055CD30
// Name: public: virtual void CDmePackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::Operate(CDmePackColorOperator *this)
{
  float v1; // xmm0_4
  int v2; // ebx
  float v3; // xmm0_4
  int v4; // edx
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Color value; // [esp+0h] [ebp-4h] BYREF

  value = (Color)this;
  v1 = this->m_red.m_Storage * 255.99899;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 255.0 )
      v1 = 255.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = (int)v1;
  v3 = this->m_green.m_Storage * 255.99899;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 255.0 )
      v3 = 255.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  v5 = this->m_blue.m_Storage * 255.99899;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 255.0 )
      v5 = 255.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)v5;
  v7 = this->m_alpha.m_Storage * 255.99899;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  m_pAttribute = this->m_color.m_pAttribute;
  value._color[1] = v4;
  value._color[2] = v6;
  value._color[0] = v2;
  value._color[3] = (int)v7;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055CDF0
// Name: public: virtual void CDmePackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::Operate(CDmePackVector2Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector2D value; // [esp+0h] [ebp-8h] BYREF

  value.x = this->m_x.m_Storage;
  m_Storage = this->m_y.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.y = m_Storage;
  CDmAttribute::SetValue<Vector2D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055CE20
// Name: public: virtual void CDmePackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::Operate(CDmePackVector3Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055CEB0
// Name: public: virtual void CDmePackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::Operate(CDmePackVector4Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector4D value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Vector4D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055CEF0
// Name: public: virtual void CDmePackQAngleOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::Operate(CDmePackQAngleOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  QAngle value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_qangle.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<QAngle>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055CF30
// Name: public: virtual void CDmePackQuaternionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::Operate(CDmePackQuaternionOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Quaternion value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_quaternion.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Quaternion>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055CFB0
// Name: public: virtual void CDmePackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::Operate(CDmePackVMatrixOperator *this)
{
  float *v1; // edx
  CDmaVar<float> *v2; // eax
  int v3; // esi
  double m_Storage; // st7
  VMatrix v; // [esp+4h] [ebp-40h] BYREF

  v1 = v.m[1];
  v2 = &this->m_cells[1];
  v3 = 2;
  do
  {
    m_Storage = v2[-1].m_Storage;
    v2 += 8;
    *(v1 - 4) = m_Storage;
    v1 += 32;
    --v3;
    *(v1 - 32) = v2[-8].m_Storage;
    *(v1 - 28) = v2[-7].m_Storage;
    *(v1 - 24) = v2[-6].m_Storage;
    *(v1 - 20) = v2[-5].m_Storage;
    *(v1 - 16) = v2[-4].m_Storage;
    *(v1 - 12) = v2[-3].m_Storage;
    *(v1 - 8) = v2[-2].m_Storage;
  }
  while ( v3 != 0 );
  CDmAttribute::SetValue<VMatrix>(this: this->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0055D140
// Name: public: virtual void CDmePackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vector.m_pAttribute;
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
// Address: 0x0055D1A0
// Name: public: virtual void CDmePackQAngleOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::GetInputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  int v9; // edi
  int v10; // eax
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v9 = attrs->m_Size;
  attrsa = this->m_y.m_pAttribute;
  v10 = attrs->m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v9 - v10 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v9 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = attrsa;
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_z.m_pAttribute;
  if ( v14 + 1 > v15 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v14 - v15 + 1);
  ++attrs->m_Size;
  v17 = attrs->m_Memory.m_pMemory;
  v18 = attrs->m_Size - v14 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
  v19 = &attrs->m_Memory.m_pMemory[v14];
  if ( v19 != nullptr )
    *v19 = v16;
}

//------------------------------------------------------------------------------
// Address: 0x0055D2B0
// Name: public: virtual void CDmePackVector3Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::GetOutputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_qangle.m_pAttribute;
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
// Address: 0x0055D310
// Name: public: virtual void CDmePackVMatrixOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetOutputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vmatrix.m_pAttribute;
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
// Address: 0x0055D430
// Name: public: virtual bool CDmePackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackColorOperator::IsA(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D460
// Name: public: virtual int CDmePackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackColorOperator::GetInheritanceDepth(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D610
// Name: public: virtual bool CDmePackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector2Operator::IsA(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D640
// Name: public: virtual int CDmePackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::GetInheritanceDepth(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D720
// Name: protected: virtual void CDmePackVector2Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::PerformConstruction(CDmeUnpackVector2Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
  CDmeUnpackVector2Operator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0055D7F0
// Name: public: virtual bool CDmePackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector3Operator::IsA(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D820
// Name: public: virtual int CDmePackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::GetInheritanceDepth(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D9B0
// Name: public: virtual bool CDmePackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector4Operator::IsA(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D9E0
// Name: public: virtual int CDmePackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector4Operator::GetInheritanceDepth(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055DB80
// Name: public: virtual bool CDmePackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQAngleOperator::IsA(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055DBB0
// Name: public: virtual int CDmePackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQAngleOperator::GetInheritanceDepth(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055DD60
// Name: public: virtual bool CDmePackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQuaternionOperator::IsA(CDmePackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055DD90
// Name: public: virtual int CDmePackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQuaternionOperator::GetInheritanceDepth(
        CDmePackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055DE90
// Name: protected: virtual void CDmePackQuaternionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::PerformConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
  CDmePackQuaternionOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0055DF10
// Name: protected: CDmePackVMatrixOperator::CDmePackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *__thiscall CDmePackVMatrixOperator::CDmePackVMatrixOperator(
        CDmePackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `CDmElement'};
  this->m_vmatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_vmatrix.m_Storage);
  m_cells = this->m_cells;
  for ( i = 15; i >= 0; --i )
  {
    m_cells->m_pAttribute = nullptr;
    m_cells->m_Storage = 0.0;
    ++m_cells;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0055DFD0
// Name: public: virtual bool CDmePackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVMatrixOperator::IsA(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055E000
// Name: public: virtual int CDmePackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::GetInheritanceDepth(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055E050
// Name: protected: virtual int CDmePackVMatrixOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::AllocatedSize(CDmeUnpackVMatrixOperator *this)
{
  return 272;
}

//------------------------------------------------------------------------------
// Address: 0x0055E0B0
// Name: protected: void CDmePackColorOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::OnConstruction(CDmeUnpackColorOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v2,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_red.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: v3,
                               pAttributeName: "red",
                               type: AT_FLOAT,
                               pMemory: &this->m_red);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_green.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v4,
                                 pAttributeName: "green",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_green);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_blue.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v5,
                                pAttributeName: "blue",
                                type: AT_FLOAT,
                                pMemory: &this->m_blue);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_alpha.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v6,
                                 pAttributeName: "alpha",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x0055E270
// Name: protected: void CDmePackVMatrixOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::OnConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmElement *v2; // ecx
  unsigned int v3; // esi
  CDmaVar<float> *m_cells; // edi
  CDmElement *v5; // ecx
  char name[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vmatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this: v2,
                                   pAttributeName: "vmatrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_vmatrix);
  v3 = 0;
  m_cells = this->m_cells;
  do
  {
    V_snprintf(pDest: name, maxLen: 4, pFormat: "m%d%d", v3 >> 2, v3 & 3);
    if ( this != nullptr )
      v5 = &this->CDmElement;
    else
      v5 = nullptr;
    m_cells->m_pAttribute = CDmElement::AddExternalAttribute(
                              this: v5,
                              pAttributeName: name,
                              type: AT_FLOAT,
                              pMemory: m_cells);
    ++v3;
    ++m_cells;
  }
  while ( v3 < 0x10 );
}

//------------------------------------------------------------------------------
// Address: 0x0055E340
// Name: public: virtual bool CDmePackColorOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackColorOperator::IsDirty(CDmeUnpackColorOperator *this)
{
  return (float)this->m_color.m_Storage._color[0] != (float)(this->m_red.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[1] != (float)(this->m_green.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[2] != (float)(this->m_blue.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[3] != (float)(this->m_alpha.m_Storage * 255.99899);
}

//------------------------------------------------------------------------------
// Address: 0x0055E470
// Name: public: virtual bool CDmePackVector2Operator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackVector2Operator::IsDirty(CDmeUnpackVector2Operator *this)
{
  return this->m_vector.m_Storage.x != this->m_x.m_Storage || this->m_vector.m_Storage.y != this->m_y.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0055E4C0
// Name: public: virtual bool CDmePackQAngleOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackQAngleOperator::IsDirty(CDmeUnpackQAngleOperator *this)
{
  return this->m_qangle.m_Storage.x != this->m_x.m_Storage
      || this->m_qangle.m_Storage.y != this->m_y.m_Storage
      || this->m_qangle.m_Storage.z != this->m_z.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0055E6D0
// Name: public: virtual void CDmePackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_quaternion.m_pAttribute;
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
// Address: 0x0055E890
// Name: public: virtual void CDmePackVMatrixOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetInputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute **p_m_pAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]
  int attrsa; // [esp+18h] [ebp+8h]

  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( attrsa = 16; attrsa != 0; --attrsa )
  {
    m_Size = attrs->m_Size;
    v9 = *p_m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
      *v8 = v9;
    p_m_pAttribute += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055EAD0
// Name: protected: virtual void CDmePackColorOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::PerformConstruction(CDmeUnpackColorOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
  CDmePackColorOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0055EE70
// Name: protected: virtual void CDmePackVector3Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::PerformConstruction(CDmeUnpackVector3Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
  CDmeUnpackVector3Operator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005AE0E0
// Name: _dynamic_initializer_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE140
// Name: _dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE1A0
// Name: _dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE200
// Name: _dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE260
// Name: _dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE2C0
// Name: _dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE320
// Name: _dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B06F0
// Name: _dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0700
// Name: _dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0710
// Name: _dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0720
// Name: _dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0730
// Name: _dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0740
// Name: _dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0750
// Name: _dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AE110
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE120
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackColorOperator_Helper,
           classname: "DmePackColorOperator",
           pFactory: &g_CDmePackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE170
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE180
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector2Operator_Helper,
           classname: "DmePackVector2Operator",
           pFactory: &g_CDmePackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE1D0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE1E0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector3Operator_Helper,
           classname: "DmePackVector3Operator",
           pFactory: &g_CDmePackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE230
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE240
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector4Operator_Helper,
           classname: "DmePackVector4Operator",
           pFactory: &g_CDmePackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE290
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE2A0
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQAngleOperator_Helper,
           classname: "DmePackQAngleOperator",
           pFactory: &g_CDmePackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE2F0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE300
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQuaternionOperator_Helper,
           classname: "DmePackQuaternionOperator",
           pFactory: &g_CDmePackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE350
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE360
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVMatrixOperator_Helper,
           classname: "DmePackVMatrixOperator",
           pFactory: &g_CDmePackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0760
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0770
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0780
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0790
// Name: _dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B07A0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B07B0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B07C0
// Name: _dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackColorOperator_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00506AD0
// Name: protected: virtual int CDmePackVector3Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::AllocatedSize(CDmeUnpackQAngleOperator *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x005B4030
// Name: public: virtual bool CDmePackColorOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackColorOperator::IsDirty(CDmeUnpackColorOperator *this)
{
  return (float)this->m_color.m_Storage._color[0] != (float)(this->m_red.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[1] != (float)(this->m_green.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[2] != (float)(this->m_blue.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[3] != (float)(this->m_alpha.m_Storage * 255.99899);
}

//------------------------------------------------------------------------------
// Address: 0x005B40C0
// Name: public: virtual void CDmePackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::Operate(CDmePackColorOperator *this)
{
  float v1; // xmm0_4
  int v2; // ebx
  float v3; // xmm0_4
  int v4; // edx
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Color value; // [esp+0h] [ebp-4h] BYREF

  value = (Color)this;
  v1 = this->m_red.m_Storage * 255.99899;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 255.0 )
      v1 = 255.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = (int)v1;
  v3 = this->m_green.m_Storage * 255.99899;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 255.0 )
      v3 = 255.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  v5 = this->m_blue.m_Storage * 255.99899;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 255.0 )
      v5 = 255.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)v5;
  v7 = this->m_alpha.m_Storage * 255.99899;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  m_pAttribute = this->m_color.m_pAttribute;
  value._color[1] = v4;
  value._color[2] = v6;
  value._color[0] = v2;
  value._color[3] = (int)v7;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005B4180
// Name: public: virtual bool CDmePackVector2Operator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackVector2Operator::IsDirty(CDmeUnpackVector2Operator *this)
{
  return this->m_vector.m_Storage.x != this->m_x.m_Storage || this->m_vector.m_Storage.y != this->m_y.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005B41B0
// Name: public: virtual void CDmePackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::Operate(CDmePackVector2Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector2D value; // [esp+0h] [ebp-8h] BYREF

  value.x = this->m_x.m_Storage;
  m_Storage = this->m_y.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.y = m_Storage;
  CDmAttribute::SetValue<Vector2D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005B41E0
// Name: public: virtual void CDmePackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::Operate(CDmePackVector3Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005B4220
// Name: public: virtual void CDmePackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::Operate(CDmePackVector4Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector4D value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Vector4D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005B4260
// Name: public: virtual bool CDmePackQAngleOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackQAngleOperator::IsDirty(CDmeUnpackQAngleOperator *this)
{
  return this->m_qangle.m_Storage.x != this->m_x.m_Storage
      || this->m_qangle.m_Storage.y != this->m_y.m_Storage
      || this->m_qangle.m_Storage.z != this->m_z.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005B42A0
// Name: public: virtual void CDmePackQAngleOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::Operate(CDmePackQAngleOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  QAngle value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_qangle.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<QAngle>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005B42E0
// Name: public: virtual void CDmePackQuaternionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::Operate(CDmePackQuaternionOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Quaternion value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_quaternion.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Quaternion>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005B4320
// Name: public: virtual void CDmePackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::Operate(CDmePackVMatrixOperator *this)
{
  float *v1; // edx
  CDmaVar<float> *v2; // eax
  int v3; // esi
  double m_Storage; // st7
  VMatrix v; // [esp+4h] [ebp-40h] BYREF

  v1 = v.m[1];
  v2 = &this->m_cells[1];
  v3 = 2;
  do
  {
    m_Storage = v2[-1].m_Storage;
    v2 += 8;
    *(v1 - 4) = m_Storage;
    v1 += 32;
    --v3;
    *(v1 - 32) = v2[-8].m_Storage;
    *(v1 - 28) = v2[-7].m_Storage;
    *(v1 - 24) = v2[-6].m_Storage;
    *(v1 - 20) = v2[-5].m_Storage;
    *(v1 - 16) = v2[-4].m_Storage;
    *(v1 - 12) = v2[-3].m_Storage;
    *(v1 - 8) = v2[-2].m_Storage;
  }
  while ( v3 != 0 );
  CDmAttribute::SetValue<VMatrix>(this: this->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x005B44F0
// Name: public: virtual void CDmePackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vector.m_pAttribute;
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
// Address: 0x005B4550
// Name: public: virtual void CDmePackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_quaternion.m_pAttribute;
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
// Address: 0x005B4660
// Name: public: virtual bool CDmePackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackColorOperator::IsA(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4690
// Name: public: virtual int CDmePackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackColorOperator::GetInheritanceDepth(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4820
// Name: public: virtual bool CDmePackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector2Operator::IsA(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4850
// Name: public: virtual int CDmePackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::GetInheritanceDepth(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4930
// Name: protected: virtual void CDmePackVector2Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::PerformConstruction(CDmeUnpackVector2Operator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
  CDmeUnpackVector2Operator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B4A00
// Name: public: virtual bool CDmePackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector3Operator::IsA(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4A30
// Name: public: virtual int CDmePackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::GetInheritanceDepth(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4BC0
// Name: public: virtual bool CDmePackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector4Operator::IsA(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4BF0
// Name: public: virtual int CDmePackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector4Operator::GetInheritanceDepth(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4DA0
// Name: public: virtual bool CDmePackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQAngleOperator::IsA(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4DD0
// Name: public: virtual int CDmePackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQAngleOperator::GetInheritanceDepth(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4F90
// Name: public: virtual bool CDmePackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQuaternionOperator::IsA(CDmePackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4FC0
// Name: public: virtual int CDmePackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQuaternionOperator::GetInheritanceDepth(
        CDmePackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5120
// Name: protected: CDmePackVMatrixOperator::CDmePackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *__thiscall CDmePackVMatrixOperator::CDmePackVMatrixOperator(
        CDmePackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `CDmElement'};
  this->m_vmatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_vmatrix.m_Storage);
  m_cells = this->m_cells;
  for ( i = 15; i >= 0; --i )
  {
    m_cells->m_pAttribute = nullptr;
    m_cells->m_Storage = 0.0;
    ++m_cells;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B51E0
// Name: public: virtual bool CDmePackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVMatrixOperator::IsA(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5210
// Name: public: virtual int CDmePackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::GetInheritanceDepth(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B52B0
// Name: protected: void CDmePackColorOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::OnConstruction(CDmeUnpackColorOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v2,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_red.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: v3,
                               pAttributeName: "red",
                               type: AT_FLOAT,
                               pMemory: &this->m_red);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_green.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v4,
                                 pAttributeName: "green",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_green);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_blue.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v5,
                                pAttributeName: "blue",
                                type: AT_FLOAT,
                                pMemory: &this->m_blue);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_alpha.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v6,
                                 pAttributeName: "alpha",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x005B54F0
// Name: protected: void CDmePackQuaternionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::OnConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_quaternion.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "quaternion",
                                      type: AT_QUATERNION,
                                      pMemory: &this->m_quaternion);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_x.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v3,
                             pAttributeName: "x",
                             type: AT_FLOAT,
                             pMemory: &this->m_x);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_y.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v4,
                             pAttributeName: "y",
                             type: AT_FLOAT,
                             pMemory: &this->m_y);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_z.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v5,
                             pAttributeName: "z",
                             type: AT_FLOAT,
                             pMemory: &this->m_z);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_w.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v6,
                             pAttributeName: "w",
                             type: AT_FLOAT,
                             pMemory: &this->m_w);
}

//------------------------------------------------------------------------------
// Address: 0x005B5590
// Name: protected: void CDmePackVMatrixOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::OnConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmElement *v2; // ecx
  unsigned int v3; // esi
  CDmaVar<float> *m_cells; // edi
  CDmElement *v5; // ecx
  char name[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vmatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this: v2,
                                   pAttributeName: "vmatrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_vmatrix);
  v3 = 0;
  m_cells = this->m_cells;
  do
  {
    V_snprintf(pDest: name, maxLen: 4, pFormat: "m%d%d", v3 >> 2, v3 & 3);
    if ( this != nullptr )
      v5 = &this->CDmElement;
    else
      v5 = nullptr;
    m_cells->m_pAttribute = CDmElement::AddExternalAttribute(
                              this: v5,
                              pAttributeName: name,
                              type: AT_FLOAT,
                              pMemory: m_cells);
    ++v3;
    ++m_cells;
  }
  while ( v3 < 0x10 );
}

//------------------------------------------------------------------------------
// Address: 0x005B58E0
// Name: public: virtual void CDmePackQAngleOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::GetInputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  int v9; // edi
  int v10; // eax
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_x.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v9 = (int)attrs[1].m_pMemory;
  attrsa = this->m_y.m_pAttribute;
  v10 = attrs->m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v9 - v10 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v9 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = attrsa;
  v14 = (int)attrs[1].m_pMemory;
  v15 = attrs->m_nAllocationCount;
  v16 = this->m_z.m_pAttribute;
  if ( v14 + 1 > v15 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v14 - v15 + 1);
  ++attrs[1].m_pMemory;
  v17 = (CDmAttribute **)attrs->m_pMemory;
  v18 = (int)attrs[1].m_pMemory - v14 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
  v19 = (CDmAttribute **)&attrs->m_pMemory[v14];
  if ( v19 != nullptr )
    *v19 = v16;
}

//------------------------------------------------------------------------------
// Address: 0x005B59F0
// Name: public: virtual void CDmePackVector3Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::GetOutputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_qangle.m_pAttribute;
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
// Address: 0x005B5BB0
// Name: public: virtual void CDmePackVMatrixOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetOutputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vmatrix.m_pAttribute;
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
// Address: 0x005B5C20
// Name: public: virtual void CDmePackVMatrixOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetInputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute **p_m_pAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]
  int attrsa; // [esp+18h] [ebp+8h]

  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( attrsa = 16; attrsa != 0; --attrsa )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    v9 = *p_m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
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
      *v8 = v9;
    p_m_pAttribute += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B5E60
// Name: protected: virtual void CDmePackColorOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::PerformConstruction(CDmeUnpackColorOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
  CDmePackColorOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B5FD0
// Name: protected: virtual int CDmePackVector2Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::AllocatedSize(CDmeUnpackVector2Operator *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x005B6230
// Name: protected: virtual void CDmePackVector3Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::PerformConstruction(CDmeUnpackVector3Operator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
  CDmeUnpackVector3Operator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B6800
// Name: protected: virtual void CDmePackQuaternionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::PerformConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
  CDmePackQuaternionOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B69C0
// Name: protected: virtual int CDmePackVMatrixOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::AllocatedSize(CDmeUnpackVMatrixOperator *this)
{
  return 272;
}

//------------------------------------------------------------------------------
// Address: 0x0067F8C0
// Name: _dynamic_initializer_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F920
// Name: _dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F980
// Name: _dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F9E0
// Name: _dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FA40
// Name: _dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FAA0
// Name: _dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FB00
// Name: _dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682C00
// Name: _dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682C10
// Name: _dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682C20
// Name: _dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682C30
// Name: _dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682C40
// Name: _dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682C50
// Name: _dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682C60
// Name: _dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F8F0
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F900
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackColorOperator_Helper,
           classname: "DmePackColorOperator",
           pFactory: &g_CDmePackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F950
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F960
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector2Operator_Helper,
           classname: "DmePackVector2Operator",
           pFactory: &g_CDmePackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F9B0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F9C0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector3Operator_Helper,
           classname: "DmePackVector3Operator",
           pFactory: &g_CDmePackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FA10
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FA20
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector4Operator_Helper,
           classname: "DmePackVector4Operator",
           pFactory: &g_CDmePackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FA70
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FA80
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQAngleOperator_Helper,
           classname: "DmePackQAngleOperator",
           pFactory: &g_CDmePackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FAD0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FAE0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQuaternionOperator_Helper,
           classname: "DmePackQuaternionOperator",
           pFactory: &g_CDmePackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FB30
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FB40
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVMatrixOperator_Helper,
           classname: "DmePackVMatrixOperator",
           pFactory: &g_CDmePackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682C70
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682C80
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682C90
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682CA0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682CB0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682CC0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682CD0
// Name: _dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackColorOperator_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004752A0
// Name: protected: virtual int CDmePackVector3Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::AllocatedSize(CDmeUnpackQAngleOperator *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x0051E600
// Name: protected: void CDmePackVMatrixOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::OnConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmElement *v2; // ecx
  unsigned int v3; // esi
  CDmaVar<float> *m_cells; // edi
  CDmElement *v5; // ecx
  char name[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vmatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this: v2,
                                   pAttributeName: "vmatrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_vmatrix);
  v3 = 0;
  m_cells = this->m_cells;
  do
  {
    V_snprintf(pDest: name, maxLen: 4, pFormat: "m%d%d", v3 >> 2, v3 & 3);
    if ( this != nullptr )
      v5 = &this->CDmElement;
    else
      v5 = nullptr;
    m_cells->m_pAttribute = CDmElement::AddExternalAttribute(
                              this: v5,
                              pAttributeName: name,
                              type: AT_FLOAT,
                              pMemory: m_cells);
    ++v3;
    ++m_cells;
  }
  while ( v3 < 0x10 );
}

//------------------------------------------------------------------------------
// Address: 0x0051E680
// Name: public: virtual bool CDmePackColorOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackColorOperator::IsDirty(CDmeUnpackColorOperator *this)
{
  return (float)this->m_color.m_Storage._color[0] != (float)(this->m_red.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[1] != (float)(this->m_green.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[2] != (float)(this->m_blue.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[3] != (float)(this->m_alpha.m_Storage * 255.99899);
}

//------------------------------------------------------------------------------
// Address: 0x0051E710
// Name: public: virtual void CDmePackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::Operate(CDmePackColorOperator *this)
{
  float v1; // xmm0_4
  int v2; // ebx
  float v3; // xmm0_4
  int v4; // edx
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Color value; // [esp+0h] [ebp-4h] BYREF

  value = (Color)this;
  v1 = this->m_red.m_Storage * 255.99899;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 255.0 )
      v1 = 255.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = (int)v1;
  v3 = this->m_green.m_Storage * 255.99899;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 255.0 )
      v3 = 255.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  v5 = this->m_blue.m_Storage * 255.99899;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 255.0 )
      v5 = 255.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)v5;
  v7 = this->m_alpha.m_Storage * 255.99899;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  m_pAttribute = this->m_color.m_pAttribute;
  value._color[1] = v4;
  value._color[2] = v6;
  value._color[0] = v2;
  value._color[3] = (int)v7;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051E7D0
// Name: public: virtual void CDmePackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::Operate(CDmePackVector2Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector2D value; // [esp+0h] [ebp-8h] BYREF

  value.x = this->m_x.m_Storage;
  m_Storage = this->m_y.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.y = m_Storage;
  CDmAttribute::SetValue<Vector2D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051E800
// Name: public: virtual void CDmePackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::Operate(CDmePackVector3Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051E840
// Name: public: virtual void CDmePackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::Operate(CDmePackVector4Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector4D value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Vector4D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051E880
// Name: public: virtual bool CDmePackQAngleOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackQAngleOperator::IsDirty(CDmeUnpackQAngleOperator *this)
{
  return this->m_qangle.m_Storage.x != this->m_x.m_Storage
      || this->m_qangle.m_Storage.y != this->m_y.m_Storage
      || this->m_qangle.m_Storage.z != this->m_z.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0051E8C0
// Name: public: virtual void CDmePackQAngleOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::Operate(CDmePackQAngleOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  QAngle value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_qangle.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<QAngle>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051E950
// Name: public: virtual void CDmePackQuaternionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::Operate(CDmePackQuaternionOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Quaternion value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_quaternion.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Quaternion>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051E9D0
// Name: public: virtual void CDmePackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::Operate(CDmePackVMatrixOperator *this)
{
  float *v1; // edx
  CDmaVar<float> *v2; // eax
  int v3; // esi
  double m_Storage; // st7
  VMatrix v; // [esp+4h] [ebp-40h] BYREF

  v1 = v.m[1];
  v2 = &this->m_cells[1];
  v3 = 2;
  do
  {
    m_Storage = v2[-1].m_Storage;
    v2 += 8;
    *(v1 - 4) = m_Storage;
    v1 += 32;
    --v3;
    *(v1 - 32) = v2[-8].m_Storage;
    *(v1 - 28) = v2[-7].m_Storage;
    *(v1 - 24) = v2[-6].m_Storage;
    *(v1 - 20) = v2[-5].m_Storage;
    *(v1 - 16) = v2[-4].m_Storage;
    *(v1 - 12) = v2[-3].m_Storage;
    *(v1 - 8) = v2[-2].m_Storage;
  }
  while ( v3 != 0 );
  CDmAttribute::SetValue<VMatrix>(this: this->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0051EC60
// Name: public: virtual void CDmePackQAngleOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::GetInputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  int v9; // edi
  int v10; // eax
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_x.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v9 = (int)attrs[1].m_pMemory;
  attrsa = this->m_y.m_pAttribute;
  v10 = attrs->m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v9 - v10 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v9 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = attrsa;
  v14 = (int)attrs[1].m_pMemory;
  v15 = attrs->m_nAllocationCount;
  v16 = this->m_z.m_pAttribute;
  if ( v14 + 1 > v15 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v14 - v15 + 1);
  ++attrs[1].m_pMemory;
  v17 = (CDmAttribute **)attrs->m_pMemory;
  v18 = (int)attrs[1].m_pMemory - v14 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
  v19 = (CDmAttribute **)&attrs->m_pMemory[v14];
  if ( v19 != nullptr )
    *v19 = v16;
}

//------------------------------------------------------------------------------
// Address: 0x0051ED70
// Name: public: virtual void CDmePackVector3Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::GetOutputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_qangle.m_pAttribute;
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
// Address: 0x0051EE80
// Name: public: virtual bool CDmePackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackColorOperator::IsA(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051EEB0
// Name: public: virtual int CDmePackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackColorOperator::GetInheritanceDepth(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F040
// Name: public: virtual bool CDmePackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector2Operator::IsA(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F070
// Name: public: virtual int CDmePackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::GetInheritanceDepth(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F150
// Name: protected: virtual void CDmePackVector2Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::PerformConstruction(CDmeUnpackVector2Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
  CDmeUnpackVector2Operator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0051F220
// Name: public: virtual bool CDmePackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector3Operator::IsA(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F250
// Name: public: virtual int CDmePackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::GetInheritanceDepth(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F330
// Name: protected: virtual void CDmePackVector3Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::PerformConstruction(CDmeUnpackVector3Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
  CDmeUnpackVector3Operator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0051F400
// Name: public: virtual bool CDmePackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector4Operator::IsA(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F430
// Name: public: virtual int CDmePackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector4Operator::GetInheritanceDepth(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F600
// Name: public: virtual bool CDmePackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQAngleOperator::IsA(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F630
// Name: public: virtual int CDmePackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQAngleOperator::GetInheritanceDepth(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F7E0
// Name: public: virtual bool CDmePackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQuaternionOperator::IsA(CDmePackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F810
// Name: public: virtual int CDmePackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQuaternionOperator::GetInheritanceDepth(
        CDmePackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F970
// Name: protected: CDmePackVMatrixOperator::CDmePackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *__thiscall CDmePackVMatrixOperator::CDmePackVMatrixOperator(
        CDmePackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `CDmElement'};
  this->m_vmatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_vmatrix.m_Storage);
  m_cells = this->m_cells;
  for ( i = 15; i >= 0; --i )
  {
    m_cells->m_pAttribute = nullptr;
    m_cells->m_Storage = 0.0;
    ++m_cells;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051FA30
// Name: public: virtual bool CDmePackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVMatrixOperator::IsA(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051FA60
// Name: public: virtual int CDmePackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::GetInheritanceDepth(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051FAB0
// Name: protected: virtual int CDmePackVMatrixOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::AllocatedSize(CDmeUnpackVMatrixOperator *this)
{
  return 272;
}

//------------------------------------------------------------------------------
// Address: 0x0051FB30
// Name: protected: void CDmePackColorOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::OnConstruction(CDmeUnpackColorOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v2,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_red.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: v3,
                               pAttributeName: "red",
                               type: AT_FLOAT,
                               pMemory: &this->m_red);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_green.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v4,
                                 pAttributeName: "green",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_green);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_blue.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v5,
                                pAttributeName: "blue",
                                type: AT_FLOAT,
                                pMemory: &this->m_blue);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_alpha.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v6,
                                 pAttributeName: "alpha",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x0051FBD0
// Name: protected: void CDmePackQuaternionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::OnConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_quaternion.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "quaternion",
                                      type: AT_QUATERNION,
                                      pMemory: &this->m_quaternion);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_x.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v3,
                             pAttributeName: "x",
                             type: AT_FLOAT,
                             pMemory: &this->m_x);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_y.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v4,
                             pAttributeName: "y",
                             type: AT_FLOAT,
                             pMemory: &this->m_y);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_z.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v5,
                             pAttributeName: "z",
                             type: AT_FLOAT,
                             pMemory: &this->m_z);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_w.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v6,
                             pAttributeName: "w",
                             type: AT_FLOAT,
                             pMemory: &this->m_w);
}

//------------------------------------------------------------------------------
// Address: 0x0051FD60
// Name: public: virtual bool CDmePackVector2Operator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackVector2Operator::IsDirty(CDmeUnpackVector2Operator *this)
{
  return this->m_vector.m_Storage.x != this->m_x.m_Storage || this->m_vector.m_Storage.y != this->m_y.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0051FE80
// Name: public: virtual void CDmePackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vector.m_pAttribute;
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
// Address: 0x00520040
// Name: public: virtual void CDmePackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_quaternion.m_pAttribute;
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
// Address: 0x005200A0
// Name: public: virtual void CDmePackVMatrixOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetOutputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vmatrix.m_pAttribute;
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
// Address: 0x00520110
// Name: public: virtual void CDmePackVMatrixOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetInputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute **p_m_pAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]
  int attrsa; // [esp+18h] [ebp+8h]

  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( attrsa = 16; attrsa != 0; --attrsa )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    v9 = *p_m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
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
      *v8 = v9;
    p_m_pAttribute += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520350
// Name: protected: virtual void CDmePackColorOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::PerformConstruction(CDmeUnpackColorOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
  CDmePackColorOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00520C60
// Name: protected: virtual void CDmePackQuaternionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::PerformConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
  CDmePackQuaternionOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00523AC0
// Name: protected: virtual int CDmePackVector2Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::AllocatedSize(CDmeUnpackVector2Operator *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x0056C4A0
// Name: _dynamic_initializer_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C500
// Name: _dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C560
// Name: _dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C5C0
// Name: _dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C620
// Name: _dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C680
// Name: _dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C6E0
// Name: _dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EDE0
// Name: _dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EDF0
// Name: _dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE00
// Name: _dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE10
// Name: _dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE20
// Name: _dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE30
// Name: _dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE40
// Name: _dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C4D0
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C4E0
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackColorOperator_Helper,
           classname: "DmePackColorOperator",
           pFactory: &g_CDmePackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C530
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C540
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector2Operator_Helper,
           classname: "DmePackVector2Operator",
           pFactory: &g_CDmePackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C590
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C5A0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector3Operator_Helper,
           classname: "DmePackVector3Operator",
           pFactory: &g_CDmePackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C5F0
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C600
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector4Operator_Helper,
           classname: "DmePackVector4Operator",
           pFactory: &g_CDmePackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C650
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C660
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQAngleOperator_Helper,
           classname: "DmePackQAngleOperator",
           pFactory: &g_CDmePackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C6B0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C6C0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQuaternionOperator_Helper,
           classname: "DmePackQuaternionOperator",
           pFactory: &g_CDmePackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C710
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C720
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVMatrixOperator_Helper,
           classname: "DmePackVMatrixOperator",
           pFactory: &g_CDmePackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE50
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE60
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE70
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE80
// Name: _dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EE90
// Name: _dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EEA0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EEB0
// Name: _dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackColorOperator_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00472FE0
// Name: protected: virtual int CDmePackVector2Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::AllocatedSize(CDmeUnpackVector2Operator *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x00524750
// Name: public: virtual void CDmePackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::Operate(CDmePackColorOperator *this)
{
  float v1; // xmm0_4
  int v2; // ebx
  float v3; // xmm0_4
  int v4; // edx
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Color value; // [esp+0h] [ebp-4h] BYREF

  value = (Color)this;
  v1 = this->m_red.m_Storage * 255.99899;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 255.0 )
      v1 = 255.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = (int)v1;
  v3 = this->m_green.m_Storage * 255.99899;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 255.0 )
      v3 = 255.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  v5 = this->m_blue.m_Storage * 255.99899;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 255.0 )
      v5 = 255.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)v5;
  v7 = this->m_alpha.m_Storage * 255.99899;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  m_pAttribute = this->m_color.m_pAttribute;
  value._color[1] = v4;
  value._color[2] = v6;
  value._color[0] = v2;
  value._color[3] = (int)v7;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00524810
// Name: public: virtual bool CDmePackVector2Operator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackVector2Operator::IsDirty(CDmeUnpackVector2Operator *this)
{
  return this->m_vector.m_Storage.x != this->m_x.m_Storage || this->m_vector.m_Storage.y != this->m_y.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00524840
// Name: public: virtual void CDmePackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::Operate(CDmePackVector2Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector2D value; // [esp+0h] [ebp-8h] BYREF

  value.x = this->m_x.m_Storage;
  m_Storage = this->m_y.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.y = m_Storage;
  CDmAttribute::SetValue<Vector2D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00524870
// Name: public: virtual bool CDmePackQAngleOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackQAngleOperator::IsDirty(CDmeUnpackQAngleOperator *this)
{
  return this->m_qangle.m_Storage.x != this->m_x.m_Storage
      || this->m_qangle.m_Storage.y != this->m_y.m_Storage
      || this->m_qangle.m_Storage.z != this->m_z.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005248B0
// Name: public: virtual void CDmePackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::Operate(CDmePackVector3Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005248F0
// Name: public: virtual void CDmePackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::Operate(CDmePackVector4Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector4D value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Vector4D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00524930
// Name: public: virtual void CDmePackQAngleOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::Operate(CDmePackQAngleOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  QAngle value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_qangle.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<QAngle>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005249C0
// Name: public: virtual void CDmePackQuaternionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::Operate(CDmePackQuaternionOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Quaternion value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_quaternion.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Quaternion>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00524A40
// Name: public: virtual void CDmePackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::Operate(CDmePackVMatrixOperator *this)
{
  float *v1; // edx
  CDmaVar<float> *v2; // eax
  int v3; // esi
  double m_Storage; // st7
  VMatrix v; // [esp+4h] [ebp-40h] BYREF

  v1 = v.m[1];
  v2 = &this->m_cells[1];
  v3 = 2;
  do
  {
    m_Storage = v2[-1].m_Storage;
    v2 += 8;
    *(v1 - 4) = m_Storage;
    v1 += 32;
    --v3;
    *(v1 - 32) = v2[-8].m_Storage;
    *(v1 - 28) = v2[-7].m_Storage;
    *(v1 - 24) = v2[-6].m_Storage;
    *(v1 - 20) = v2[-5].m_Storage;
    *(v1 - 16) = v2[-4].m_Storage;
    *(v1 - 12) = v2[-3].m_Storage;
    *(v1 - 8) = v2[-2].m_Storage;
  }
  while ( v3 != 0 );
  CDmAttribute::SetValue<VMatrix>(this: this->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x00524B10
// Name: public: virtual void CDmePackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vector.m_pAttribute;
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
// Address: 0x00524B70
// Name: public: virtual void CDmePackVector3Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::GetOutputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_qangle.m_pAttribute;
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
// Address: 0x00524D30
// Name: public: virtual void CDmePackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_quaternion.m_pAttribute;
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
// Address: 0x00524E40
// Name: public: virtual bool CDmePackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackColorOperator::IsA(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524E70
// Name: public: virtual int CDmePackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackColorOperator::GetInheritanceDepth(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525000
// Name: public: virtual bool CDmePackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector2Operator::IsA(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525030
// Name: public: virtual int CDmePackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::GetInheritanceDepth(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525110
// Name: protected: virtual void CDmePackVector2Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::PerformConstruction(CDmeUnpackVector2Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
  CDmeUnpackVector2Operator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005251E0
// Name: public: virtual bool CDmePackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector3Operator::IsA(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525210
// Name: public: virtual int CDmePackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::GetInheritanceDepth(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005253A0
// Name: public: virtual bool CDmePackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector4Operator::IsA(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005253D0
// Name: public: virtual int CDmePackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector4Operator::GetInheritanceDepth(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525580
// Name: public: virtual bool CDmePackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQAngleOperator::IsA(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005255B0
// Name: public: virtual int CDmePackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQAngleOperator::GetInheritanceDepth(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525770
// Name: public: virtual bool CDmePackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQuaternionOperator::IsA(CDmePackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005257A0
// Name: public: virtual int CDmePackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQuaternionOperator::GetInheritanceDepth(
        CDmePackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525900
// Name: protected: CDmePackVMatrixOperator::CDmePackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *__thiscall CDmePackVMatrixOperator::CDmePackVMatrixOperator(
        CDmePackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `CDmElement'};
  this->m_vmatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_vmatrix.m_Storage);
  m_cells = this->m_cells;
  for ( i = 15; i >= 0; --i )
  {
    m_cells->m_pAttribute = nullptr;
    m_cells->m_Storage = 0.0;
    ++m_cells;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005259C0
// Name: public: virtual bool CDmePackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVMatrixOperator::IsA(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005259F0
// Name: public: virtual int CDmePackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::GetInheritanceDepth(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525A40
// Name: protected: virtual int CDmePackVMatrixOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::AllocatedSize(CDmeUnpackVMatrixOperator *this)
{
  return 272;
}

//------------------------------------------------------------------------------
// Address: 0x00525AA0
// Name: protected: void CDmePackColorOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::OnConstruction(CDmeUnpackColorOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v2,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_red.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: v3,
                               pAttributeName: "red",
                               type: AT_FLOAT,
                               pMemory: &this->m_red);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_green.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v4,
                                 pAttributeName: "green",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_green);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_blue.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v5,
                                pAttributeName: "blue",
                                type: AT_FLOAT,
                                pMemory: &this->m_blue);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_alpha.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v6,
                                 pAttributeName: "alpha",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x00525C60
// Name: protected: void CDmePackQuaternionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::OnConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_quaternion.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "quaternion",
                                      type: AT_QUATERNION,
                                      pMemory: &this->m_quaternion);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_x.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v3,
                             pAttributeName: "x",
                             type: AT_FLOAT,
                             pMemory: &this->m_x);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_y.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v4,
                             pAttributeName: "y",
                             type: AT_FLOAT,
                             pMemory: &this->m_y);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_z.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v5,
                             pAttributeName: "z",
                             type: AT_FLOAT,
                             pMemory: &this->m_z);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_w.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v6,
                             pAttributeName: "w",
                             type: AT_FLOAT,
                             pMemory: &this->m_w);
}

//------------------------------------------------------------------------------
// Address: 0x00525D00
// Name: protected: void CDmePackVMatrixOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::OnConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmElement *v2; // ecx
  unsigned int v3; // esi
  CDmaVar<float> *m_cells; // edi
  CDmElement *v5; // ecx
  char name[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vmatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this: v2,
                                   pAttributeName: "vmatrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_vmatrix);
  v3 = 0;
  m_cells = this->m_cells;
  do
  {
    V_snprintf(pDest: name, maxLen: 4, pFormat: "m%d%d", v3 >> 2, v3 & 3);
    if ( this != nullptr )
      v5 = &this->CDmElement;
    else
      v5 = nullptr;
    m_cells->m_pAttribute = CDmElement::AddExternalAttribute(
                              this: v5,
                              pAttributeName: name,
                              type: AT_FLOAT,
                              pMemory: m_cells);
    ++v3;
    ++m_cells;
  }
  while ( v3 < 0x10 );
}

//------------------------------------------------------------------------------
// Address: 0x00525DD0
// Name: public: virtual bool CDmePackColorOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackColorOperator::IsDirty(CDmeUnpackColorOperator *this)
{
  return (float)this->m_color.m_Storage._color[0] != (float)(this->m_red.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[1] != (float)(this->m_green.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[2] != (float)(this->m_blue.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[3] != (float)(this->m_alpha.m_Storage * 255.99899);
}

//------------------------------------------------------------------------------
// Address: 0x005261B0
// Name: public: virtual void CDmePackQAngleOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::GetInputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  int v9; // edi
  int v10; // eax
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v9 = attrs->m_Size;
  attrsa = this->m_y.m_pAttribute;
  v10 = attrs->m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v9 - v10 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v9 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = attrsa;
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_z.m_pAttribute;
  if ( v14 + 1 > v15 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v14 - v15 + 1);
  ++attrs->m_Size;
  v17 = attrs->m_Memory.m_pMemory;
  v18 = attrs->m_Size - v14 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
  v19 = &attrs->m_Memory.m_pMemory[v14];
  if ( v19 != nullptr )
    *v19 = v16;
}

//------------------------------------------------------------------------------
// Address: 0x005262C0
// Name: public: virtual void CDmePackVMatrixOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetOutputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vmatrix.m_pAttribute;
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
// Address: 0x00526330
// Name: public: virtual void CDmePackVMatrixOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetInputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute **p_m_pAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]
  int attrsa; // [esp+18h] [ebp+8h]

  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( attrsa = 16; attrsa != 0; --attrsa )
  {
    m_Size = attrs->m_Size;
    v9 = *p_m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
      *v8 = v9;
    p_m_pAttribute += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00526570
// Name: protected: virtual void CDmePackColorOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::PerformConstruction(CDmeUnpackColorOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
  CDmePackColorOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00526930
// Name: protected: virtual void CDmePackVector3Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::PerformConstruction(CDmeUnpackVector3Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
  CDmeUnpackVector3Operator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00526EE0
// Name: protected: virtual void CDmePackQuaternionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::PerformConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
  CDmePackQuaternionOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0052FC40
// Name: protected: virtual int CDmePackVector3Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::AllocatedSize(CDmeUnpackQAngleOperator *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x0057C5C0
// Name: _dynamic_initializer_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C620
// Name: _dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C680
// Name: _dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C6E0
// Name: _dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C740
// Name: _dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C7A0
// Name: _dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C800
// Name: _dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF10
// Name: _dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF20
// Name: _dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF30
// Name: _dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF40
// Name: _dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF50
// Name: _dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF60
// Name: _dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF70
// Name: _dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C5F0
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C600
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackColorOperator_Helper,
           classname: "DmePackColorOperator",
           pFactory: &g_CDmePackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C650
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C660
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector2Operator_Helper,
           classname: "DmePackVector2Operator",
           pFactory: &g_CDmePackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C6B0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C6C0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector3Operator_Helper,
           classname: "DmePackVector3Operator",
           pFactory: &g_CDmePackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C710
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C720
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector4Operator_Helper,
           classname: "DmePackVector4Operator",
           pFactory: &g_CDmePackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C770
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C780
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQAngleOperator_Helper,
           classname: "DmePackQAngleOperator",
           pFactory: &g_CDmePackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C7D0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C7E0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQuaternionOperator_Helper,
           classname: "DmePackQuaternionOperator",
           pFactory: &g_CDmePackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C830
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C840
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVMatrixOperator_Helper,
           classname: "DmePackVMatrixOperator",
           pFactory: &g_CDmePackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF80
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EF90
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EFA0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EFB0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EFC0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EFD0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EFE0
// Name: _dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackColorOperator_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005E1850
// Name: protected: void CDmePackColorOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::OnConstruction(CDmeUnpackColorOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v2,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_red.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: v3,
                               pAttributeName: "red",
                               type: AT_FLOAT,
                               pMemory: &this->m_red);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_green.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v4,
                                 pAttributeName: "green",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_green);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_blue.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v5,
                                pAttributeName: "blue",
                                type: AT_FLOAT,
                                pMemory: &this->m_blue);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_alpha.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v6,
                                 pAttributeName: "alpha",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x005E19E0
// Name: protected: void CDmePackVMatrixOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::OnConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmElement *v2; // ecx
  unsigned int v3; // esi
  CDmaVar<float> *m_cells; // edi
  CDmElement *v5; // ecx
  char name[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vmatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this: v2,
                                   pAttributeName: "vmatrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_vmatrix);
  v3 = 0;
  m_cells = this->m_cells;
  do
  {
    V_snprintf(pDest: name, maxLen: 4, pFormat: "m%d%d", v3 >> 2, v3 & 3);
    if ( this != nullptr )
      v5 = &this->CDmElement;
    else
      v5 = nullptr;
    m_cells->m_pAttribute = CDmElement::AddExternalAttribute(
                              this: v5,
                              pAttributeName: name,
                              type: AT_FLOAT,
                              pMemory: m_cells);
    ++v3;
    ++m_cells;
  }
  while ( v3 < 0x10 );
}

//------------------------------------------------------------------------------
// Address: 0x005E1A60
// Name: public: virtual bool CDmePackColorOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackColorOperator::IsDirty(CDmeUnpackColorOperator *this)
{
  return (float)this->m_color.m_Storage._color[0] != (float)(this->m_red.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[1] != (float)(this->m_green.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[2] != (float)(this->m_blue.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[3] != (float)(this->m_alpha.m_Storage * 255.99899);
}

//------------------------------------------------------------------------------
// Address: 0x005E1AF0
// Name: public: virtual void CDmePackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::Operate(CDmePackColorOperator *this)
{
  float v1; // xmm0_4
  int v2; // ebx
  float v3; // xmm0_4
  int v4; // edx
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Color value; // [esp+0h] [ebp-4h] BYREF

  value = (Color)this;
  v1 = this->m_red.m_Storage * 255.99899;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 255.0 )
      v1 = 255.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = (int)v1;
  v3 = this->m_green.m_Storage * 255.99899;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 255.0 )
      v3 = 255.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  v5 = this->m_blue.m_Storage * 255.99899;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 255.0 )
      v5 = 255.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)v5;
  v7 = this->m_alpha.m_Storage * 255.99899;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  m_pAttribute = this->m_color.m_pAttribute;
  value._color[1] = v4;
  value._color[2] = v6;
  value._color[0] = v2;
  value._color[3] = (int)v7;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E1BB0
// Name: public: virtual bool CDmePackVector2Operator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackVector2Operator::IsDirty(CDmeUnpackVector2Operator *this)
{
  return this->m_vector.m_Storage.x != this->m_x.m_Storage || this->m_vector.m_Storage.y != this->m_y.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005E1BE0
// Name: public: virtual void CDmePackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::Operate(CDmePackVector2Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector2D value; // [esp+0h] [ebp-8h] BYREF

  value.x = this->m_x.m_Storage;
  m_Storage = this->m_y.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.y = m_Storage;
  CDmAttribute::SetValue<Vector2D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E1C10
// Name: public: virtual void CDmePackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::Operate(CDmePackVector3Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E1C50
// Name: public: virtual void CDmePackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::Operate(CDmePackVector4Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector4D value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Vector4D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E1C90
// Name: public: virtual bool CDmePackQAngleOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackQAngleOperator::IsDirty(CDmeUnpackQAngleOperator *this)
{
  return this->m_qangle.m_Storage.x != this->m_x.m_Storage
      || this->m_qangle.m_Storage.y != this->m_y.m_Storage
      || this->m_qangle.m_Storage.z != this->m_z.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005E1CD0
// Name: public: virtual void CDmePackQAngleOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::Operate(CDmePackQAngleOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  QAngle value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_qangle.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<QAngle>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E1D60
// Name: public: virtual void CDmePackQuaternionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::Operate(CDmePackQuaternionOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Quaternion value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_quaternion.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Quaternion>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E1DA0
// Name: public: virtual void CDmePackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::Operate(CDmePackVMatrixOperator *this)
{
  float *v1; // edx
  CDmaVar<float> *v2; // eax
  int v3; // esi
  double m_Storage; // st7
  VMatrix v; // [esp+4h] [ebp-40h] BYREF

  v1 = v.m[1];
  v2 = &this->m_cells[1];
  v3 = 2;
  do
  {
    m_Storage = v2[-1].m_Storage;
    v2 += 8;
    *(v1 - 4) = m_Storage;
    v1 += 32;
    --v3;
    *(v1 - 32) = v2[-8].m_Storage;
    *(v1 - 28) = v2[-7].m_Storage;
    *(v1 - 24) = v2[-6].m_Storage;
    *(v1 - 20) = v2[-5].m_Storage;
    *(v1 - 16) = v2[-4].m_Storage;
    *(v1 - 12) = v2[-3].m_Storage;
    *(v1 - 8) = v2[-2].m_Storage;
  }
  while ( v3 != 0 );
  CDmAttribute::SetValue<VMatrix>(this: this->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x005E1F70
// Name: public: virtual void CDmePackVMatrixOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetInputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute **p_m_pAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]
  int attrsa; // [esp+18h] [ebp+8h]

  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( attrsa = 16; attrsa != 0; --attrsa )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    v9 = *p_m_pAttribute;
    m_nAllocationCount = attrs->m_nAllocationCount;
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
      *v8 = v9;
    p_m_pAttribute += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E20A0
// Name: public: virtual bool CDmePackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackColorOperator::IsA(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E20D0
// Name: public: virtual int CDmePackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackColorOperator::GetInheritanceDepth(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2120
// Name: protected: virtual int CDmePackVector3Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::AllocatedSize(CDmeUnpackQAngleOperator *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x005E21C0
// Name: protected: virtual void CDmePackColorOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::PerformConstruction(CDmeUnpackColorOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
  CDmePackColorOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005E2290
// Name: public: virtual bool CDmePackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector2Operator::IsA(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E22C0
// Name: public: virtual int CDmePackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::GetInheritanceDepth(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E23A0
// Name: protected: virtual void CDmePackVector2Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::PerformConstruction(CDmeUnpackVector2Operator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
  CDmeUnpackVector2Operator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005E2470
// Name: public: virtual bool CDmePackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector3Operator::IsA(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E24A0
// Name: public: virtual int CDmePackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::GetInheritanceDepth(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2580
// Name: protected: virtual void CDmePackVector3Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::PerformConstruction(CDmeUnpackVector3Operator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
  CDmeUnpackVector3Operator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005E2650
// Name: public: virtual bool CDmePackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector4Operator::IsA(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2680
// Name: public: virtual int CDmePackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector4Operator::GetInheritanceDepth(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2820
// Name: public: virtual bool CDmePackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQAngleOperator::IsA(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2850
// Name: public: virtual int CDmePackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQAngleOperator::GetInheritanceDepth(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E29E0
// Name: public: virtual bool CDmePackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQuaternionOperator::IsA(CDmePackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2A10
// Name: public: virtual int CDmePackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQuaternionOperator::GetInheritanceDepth(
        CDmePackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2B70
// Name: protected: CDmePackVMatrixOperator::CDmePackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *__thiscall CDmePackVMatrixOperator::CDmePackVMatrixOperator(
        CDmePackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `CDmElement'};
  this->m_vmatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_vmatrix.m_Storage);
  m_cells = this->m_cells;
  for ( i = 15; i >= 0; --i )
  {
    m_cells->m_pAttribute = nullptr;
    m_cells->m_Storage = 0.0;
    ++m_cells;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005E2C30
// Name: public: virtual bool CDmePackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVMatrixOperator::IsA(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2C60
// Name: public: virtual int CDmePackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::GetInheritanceDepth(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E2CB0
// Name: protected: virtual int CDmePackVMatrixOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::AllocatedSize(CDmeUnpackVMatrixOperator *this)
{
  return 272;
}

//------------------------------------------------------------------------------
// Address: 0x005E2E50
// Name: protected: void CDmePackQuaternionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::OnConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_quaternion.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "quaternion",
                                      type: AT_QUATERNION,
                                      pMemory: &this->m_quaternion);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_x.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v3,
                             pAttributeName: "x",
                             type: AT_FLOAT,
                             pMemory: &this->m_x);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_y.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v4,
                             pAttributeName: "y",
                             type: AT_FLOAT,
                             pMemory: &this->m_y);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_z.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v5,
                             pAttributeName: "z",
                             type: AT_FLOAT,
                             pMemory: &this->m_z);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_w.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v6,
                             pAttributeName: "w",
                             type: AT_FLOAT,
                             pMemory: &this->m_w);
}

//------------------------------------------------------------------------------
// Address: 0x005E3210
// Name: public: virtual void CDmePackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vector.m_pAttribute;
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
// Address: 0x005E3330
// Name: public: virtual void CDmePackVector3Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::GetOutputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_qangle.m_pAttribute;
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
// Address: 0x005E3390
// Name: public: virtual void CDmePackQAngleOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::GetInputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  int v9; // edi
  int v10; // eax
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_x.m_pAttribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
  v9 = (int)attrs[1].m_pMemory;
  attrsa = this->m_y.m_pAttribute;
  v10 = attrs->m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v9 - v10 + 1);
  ++attrs[1].m_pMemory;
  v11 = (CDmAttribute **)attrs->m_pMemory;
  v12 = (int)attrs[1].m_pMemory - v9 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = (CDmAttribute **)&attrs->m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = attrsa;
  v14 = (int)attrs[1].m_pMemory;
  v15 = attrs->m_nAllocationCount;
  v16 = this->m_z.m_pAttribute;
  if ( v14 + 1 > v15 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v14 - v15 + 1);
  ++attrs[1].m_pMemory;
  v17 = (CDmAttribute **)attrs->m_pMemory;
  v18 = (int)attrs[1].m_pMemory - v14 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
  v19 = (CDmAttribute **)&attrs->m_pMemory[v14];
  if ( v19 != nullptr )
    *v19 = v16;
}

//------------------------------------------------------------------------------
// Address: 0x005E34A0
// Name: public: virtual void CDmePackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_quaternion.m_pAttribute;
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
// Address: 0x005E3500
// Name: public: virtual void CDmePackVMatrixOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetOutputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vmatrix.m_pAttribute;
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
// Address: 0x005E3860
// Name: protected: virtual int CDmePackVector2Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::AllocatedSize(CDmeUnpackVector2Operator *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x005E4070
// Name: protected: virtual void CDmePackQuaternionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::PerformConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
  CDmePackQuaternionOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x006B1710
// Name: _dynamic_initializer_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1770
// Name: _dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B17D0
// Name: _dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1830
// Name: _dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1890
// Name: _dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B18F0
// Name: _dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1950
// Name: _dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5700
// Name: _dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5710
// Name: _dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5720
// Name: _dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5730
// Name: _dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5740
// Name: _dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5750
// Name: _dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5760
// Name: _dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1740
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1750
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackColorOperator_Helper,
           classname: "DmePackColorOperator",
           pFactory: &g_CDmePackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B17A0
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B17B0
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector2Operator_Helper,
           classname: "DmePackVector2Operator",
           pFactory: &g_CDmePackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1800
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1810
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector3Operator_Helper,
           classname: "DmePackVector3Operator",
           pFactory: &g_CDmePackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1860
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1870
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector4Operator_Helper,
           classname: "DmePackVector4Operator",
           pFactory: &g_CDmePackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B18C0
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B18D0
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQAngleOperator_Helper,
           classname: "DmePackQAngleOperator",
           pFactory: &g_CDmePackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1920
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1930
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQuaternionOperator_Helper,
           classname: "DmePackQuaternionOperator",
           pFactory: &g_CDmePackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1980
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1990
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVMatrixOperator_Helper,
           classname: "DmePackVMatrixOperator",
           pFactory: &g_CDmePackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5770
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5780
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5790
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B57A0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B57B0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B57C0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B57D0
// Name: _dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePackColorOperator_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00521F40
// Name: protected: virtual int CDmePackVector2Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::AllocatedSize(CDmeUnpackVector2Operator *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x00525800
// Name: protected: void CDmePackColorOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::OnConstruction(CDmeUnpackColorOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v2,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_red.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: v3,
                               pAttributeName: "red",
                               type: AT_FLOAT,
                               pMemory: &this->m_red);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_green.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v4,
                                 pAttributeName: "green",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_green);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_blue.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v5,
                                pAttributeName: "blue",
                                type: AT_FLOAT,
                                pMemory: &this->m_blue);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_alpha.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v6,
                                 pAttributeName: "alpha",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x00525990
// Name: protected: void CDmePackQuaternionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::OnConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_quaternion.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "quaternion",
                                      type: AT_QUATERNION,
                                      pMemory: &this->m_quaternion);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_x.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v3,
                             pAttributeName: "x",
                             type: AT_FLOAT,
                             pMemory: &this->m_x);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_y.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v4,
                             pAttributeName: "y",
                             type: AT_FLOAT,
                             pMemory: &this->m_y);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_z.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v5,
                             pAttributeName: "z",
                             type: AT_FLOAT,
                             pMemory: &this->m_z);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_w.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v6,
                             pAttributeName: "w",
                             type: AT_FLOAT,
                             pMemory: &this->m_w);
}

//------------------------------------------------------------------------------
// Address: 0x00525A30
// Name: protected: void CDmePackVMatrixOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::OnConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmElement *v2; // ecx
  unsigned int v3; // esi
  CDmaVar<float> *m_cells; // edi
  CDmElement *v5; // ecx
  char name[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vmatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this: v2,
                                   pAttributeName: "vmatrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_vmatrix);
  v3 = 0;
  m_cells = this->m_cells;
  do
  {
    V_snprintf(pDest: name, maxLen: 4, pFormat: "m%d%d", v3 >> 2, v3 & 3);
    if ( this != nullptr )
      v5 = &this->CDmElement;
    else
      v5 = nullptr;
    m_cells->m_pAttribute = CDmElement::AddExternalAttribute(
                              this: v5,
                              pAttributeName: name,
                              type: AT_FLOAT,
                              pMemory: m_cells);
    ++v3;
    ++m_cells;
  }
  while ( v3 < 0x10 );
}

//------------------------------------------------------------------------------
// Address: 0x00525AB0
// Name: public: virtual void CDmePackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::Operate(CDmePackColorOperator *this)
{
  float v1; // xmm0_4
  int v2; // ebx
  float v3; // xmm0_4
  int v4; // edx
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Color value; // [esp+0h] [ebp-4h] BYREF

  value = (Color)this;
  v1 = this->m_red.m_Storage * 255.99899;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 255.0 )
      v1 = 255.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = (int)v1;
  v3 = this->m_green.m_Storage * 255.99899;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 255.0 )
      v3 = 255.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  v5 = this->m_blue.m_Storage * 255.99899;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 255.0 )
      v5 = 255.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)v5;
  v7 = this->m_alpha.m_Storage * 255.99899;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  m_pAttribute = this->m_color.m_pAttribute;
  value._color[1] = v4;
  value._color[2] = v6;
  value._color[0] = v2;
  value._color[3] = (int)v7;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00525B70
// Name: public: virtual bool CDmePackVector2Operator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackVector2Operator::IsDirty(CDmeUnpackVector2Operator *this)
{
  return this->m_vector.m_Storage.x != this->m_x.m_Storage || this->m_vector.m_Storage.y != this->m_y.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00525BA0
// Name: public: virtual void CDmePackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::Operate(CDmePackVector2Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector2D value; // [esp+0h] [ebp-8h] BYREF

  value.x = this->m_x.m_Storage;
  m_Storage = this->m_y.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.y = m_Storage;
  CDmAttribute::SetValue<Vector2D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00525BD0
// Name: public: virtual void CDmePackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::Operate(CDmePackVector3Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00525CA0
// Name: public: virtual bool CDmePackQAngleOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackQAngleOperator::IsDirty(CDmeUnpackQAngleOperator *this)
{
  return this->m_qangle.m_Storage.x != this->m_x.m_Storage
      || this->m_qangle.m_Storage.y != this->m_y.m_Storage
      || this->m_qangle.m_Storage.z != this->m_z.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00525CE0
// Name: public: virtual void CDmePackQAngleOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::Operate(CDmePackQAngleOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  QAngle value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_qangle.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<QAngle>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00525D20
// Name: public: virtual void CDmePackQuaternionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::Operate(CDmePackQuaternionOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Quaternion value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_quaternion.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Quaternion>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00525DA0
// Name: public: virtual void CDmePackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::Operate(CDmePackVMatrixOperator *this)
{
  float *v1; // edx
  CDmaVar<float> *v2; // eax
  int v3; // esi
  double m_Storage; // st7
  VMatrix v; // [esp+4h] [ebp-40h] BYREF

  v1 = v.m[1];
  v2 = &this->m_cells[1];
  v3 = 2;
  do
  {
    m_Storage = v2[-1].m_Storage;
    v2 += 8;
    *(v1 - 4) = m_Storage;
    v1 += 32;
    --v3;
    *(v1 - 32) = v2[-8].m_Storage;
    *(v1 - 28) = v2[-7].m_Storage;
    *(v1 - 24) = v2[-6].m_Storage;
    *(v1 - 20) = v2[-5].m_Storage;
    *(v1 - 16) = v2[-4].m_Storage;
    *(v1 - 12) = v2[-3].m_Storage;
    *(v1 - 8) = v2[-2].m_Storage;
  }
  while ( v3 != 0 );
  CDmAttribute::SetValue<VMatrix>(this: this->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x00525E10
// Name: public: virtual void CDmePackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vector.m_pAttribute;
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
// Address: 0x00525E70
// Name: public: virtual void CDmePackQAngleOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::GetInputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  int v9; // edi
  int v10; // eax
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v9 = attrs->m_Size;
  attrsa = this->m_y.m_pAttribute;
  v10 = attrs->m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v9 - v10 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v9 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = attrsa;
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_z.m_pAttribute;
  if ( v14 + 1 > v15 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v14 - v15 + 1);
  ++attrs->m_Size;
  v17 = attrs->m_Memory.m_pMemory;
  v18 = attrs->m_Size - v14 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
  v19 = &attrs->m_Memory.m_pMemory[v14];
  if ( v19 != nullptr )
    *v19 = v16;
}

//------------------------------------------------------------------------------
// Address: 0x00525F80
// Name: public: virtual void CDmePackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_quaternion.m_pAttribute;
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
// Address: 0x00525FE0
// Name: public: virtual void CDmePackVMatrixOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetOutputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vmatrix.m_pAttribute;
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
// Address: 0x00526100
// Name: public: virtual bool CDmePackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackColorOperator::IsA(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526130
// Name: public: virtual int CDmePackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackColorOperator::GetInheritanceDepth(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526210
// Name: protected: virtual void CDmePackColorOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::PerformConstruction(CDmeUnpackColorOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
  CDmePackColorOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005262E0
// Name: public: virtual bool CDmePackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector2Operator::IsA(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526310
// Name: public: virtual int CDmePackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::GetInheritanceDepth(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005263F0
// Name: protected: virtual void CDmePackVector2Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::PerformConstruction(CDmeUnpackVector2Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
  CDmeUnpackVector2Operator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005264C0
// Name: public: virtual bool CDmePackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector3Operator::IsA(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005264F0
// Name: public: virtual int CDmePackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::GetInheritanceDepth(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005265D0
// Name: protected: virtual void CDmePackVector3Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::PerformConstruction(CDmeUnpackVector3Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
  CDmeUnpackVector3Operator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005266A0
// Name: public: virtual bool CDmePackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector4Operator::IsA(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005266D0
// Name: public: virtual int CDmePackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector4Operator::GetInheritanceDepth(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526870
// Name: public: virtual bool CDmePackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQAngleOperator::IsA(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005268A0
// Name: public: virtual int CDmePackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQAngleOperator::GetInheritanceDepth(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526A30
// Name: public: virtual bool CDmePackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQuaternionOperator::IsA(CDmePackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526A60
// Name: public: virtual int CDmePackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQuaternionOperator::GetInheritanceDepth(
        CDmePackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526B60
// Name: protected: virtual void CDmePackQuaternionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::PerformConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
  CDmePackQuaternionOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00526BE0
// Name: protected: CDmePackVMatrixOperator::CDmePackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *__thiscall CDmePackVMatrixOperator::CDmePackVMatrixOperator(
        CDmePackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `CDmElement'};
  this->m_vmatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_vmatrix.m_Storage);
  m_cells = this->m_cells;
  for ( i = 15; i >= 0; --i )
  {
    m_cells->m_pAttribute = nullptr;
    m_cells->m_Storage = 0.0;
    ++m_cells;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00526CA0
// Name: public: virtual bool CDmePackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVMatrixOperator::IsA(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526CD0
// Name: public: virtual int CDmePackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::GetInheritanceDepth(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526D20
// Name: protected: virtual int CDmePackVMatrixOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::AllocatedSize(CDmeUnpackVMatrixOperator *this)
{
  return 272;
}

//------------------------------------------------------------------------------
// Address: 0x00526F10
// Name: public: virtual bool CDmePackColorOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackColorOperator::IsDirty(CDmeUnpackColorOperator *this)
{
  return (float)this->m_color.m_Storage._color[0] != (float)(this->m_red.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[1] != (float)(this->m_green.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[2] != (float)(this->m_blue.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[3] != (float)(this->m_alpha.m_Storage * 255.99899);
}

//------------------------------------------------------------------------------
// Address: 0x00527460
// Name: public: virtual void CDmePackVector3Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::GetOutputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_qangle.m_pAttribute;
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
// Address: 0x005274C0
// Name: public: virtual void CDmePackVMatrixOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetInputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute **p_m_pAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]
  int attrsa; // [esp+18h] [ebp+8h]

  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( attrsa = 16; attrsa != 0; --attrsa )
  {
    m_Size = attrs->m_Size;
    v9 = *p_m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
      *v8 = v9;
    p_m_pAttribute += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00527690
// Name: protected: virtual int CDmePackVector3Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::AllocatedSize(CDmeUnpackQAngleOperator *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x0057E590
// Name: _dynamic_initializer_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E5F0
// Name: _dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E650
// Name: _dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E6B0
// Name: _dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E710
// Name: _dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E770
// Name: _dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E7D0
// Name: _dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580EF0
// Name: _dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580F00
// Name: _dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580F10
// Name: _dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580F20
// Name: _dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580F30
// Name: _dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580F40
// Name: _dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580F50
// Name: _dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E5C0
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E5D0
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackColorOperator_Helper,
           classname: "DmePackColorOperator",
           pFactory: &g_CDmePackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E620
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E630
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector2Operator_Helper,
           classname: "DmePackVector2Operator",
           pFactory: &g_CDmePackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E680
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E690
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector3Operator_Helper,
           classname: "DmePackVector3Operator",
           pFactory: &g_CDmePackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E6E0
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E6F0
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector4Operator_Helper,
           classname: "DmePackVector4Operator",
           pFactory: &g_CDmePackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E740
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E750
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQAngleOperator_Helper,
           classname: "DmePackQAngleOperator",
           pFactory: &g_CDmePackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E7A0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E7B0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQuaternionOperator_Helper,
           classname: "DmePackQuaternionOperator",
           pFactory: &g_CDmePackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E800
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E810
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVMatrixOperator_Helper,
           classname: "DmePackVMatrixOperator",
           pFactory: &g_CDmePackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580F60
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580F70
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580F80
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580F90
// Name: _dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580FA0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580FB0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580FC0
// Name: _dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackColorOperator_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00480560
// Name: protected: virtual int CDmePackVector2Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::AllocatedSize(CDmeUnpackVector2Operator *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x0052BB30
// Name: protected: virtual int CDmePackVector3Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::AllocatedSize(CDmeUnpackQAngleOperator *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x0052CD60
// Name: protected: void CDmePackColorOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::OnConstruction(CDmeUnpackColorOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v2,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_red.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: v3,
                               pAttributeName: "red",
                               type: AT_FLOAT,
                               pMemory: &this->m_red);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_green.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v4,
                                 pAttributeName: "green",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_green);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_blue.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v5,
                                pAttributeName: "blue",
                                type: AT_FLOAT,
                                pMemory: &this->m_blue);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_alpha.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v6,
                                 pAttributeName: "alpha",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x0052CF80
// Name: protected: void CDmePackQuaternionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::OnConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_quaternion.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "quaternion",
                                      type: AT_QUATERNION,
                                      pMemory: &this->m_quaternion);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_x.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v3,
                             pAttributeName: "x",
                             type: AT_FLOAT,
                             pMemory: &this->m_x);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_y.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v4,
                             pAttributeName: "y",
                             type: AT_FLOAT,
                             pMemory: &this->m_y);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_z.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v5,
                             pAttributeName: "z",
                             type: AT_FLOAT,
                             pMemory: &this->m_z);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_w.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v6,
                             pAttributeName: "w",
                             type: AT_FLOAT,
                             pMemory: &this->m_w);
}

//------------------------------------------------------------------------------
// Address: 0x0052D020
// Name: public: virtual bool CDmePackColorOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackColorOperator::IsDirty(CDmeUnpackColorOperator *this)
{
  return (float)this->m_color.m_Storage._color[0] != (float)(this->m_red.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[1] != (float)(this->m_green.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[2] != (float)(this->m_blue.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[3] != (float)(this->m_alpha.m_Storage * 255.99899);
}

//------------------------------------------------------------------------------
// Address: 0x0052D0B0
// Name: public: virtual void CDmePackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::Operate(CDmePackColorOperator *this)
{
  float v1; // xmm0_4
  int v2; // ebx
  float v3; // xmm0_4
  int v4; // edx
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Color value; // [esp+0h] [ebp-4h] BYREF

  value = (Color)this;
  v1 = this->m_red.m_Storage * 255.99899;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 255.0 )
      v1 = 255.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = (int)v1;
  v3 = this->m_green.m_Storage * 255.99899;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 255.0 )
      v3 = 255.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  v5 = this->m_blue.m_Storage * 255.99899;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 255.0 )
      v5 = 255.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)v5;
  v7 = this->m_alpha.m_Storage * 255.99899;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  m_pAttribute = this->m_color.m_pAttribute;
  value._color[1] = v4;
  value._color[2] = v6;
  value._color[0] = v2;
  value._color[3] = (int)v7;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0052D170
// Name: public: virtual bool CDmePackVector2Operator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackVector2Operator::IsDirty(CDmeUnpackVector2Operator *this)
{
  return this->m_vector.m_Storage.x != this->m_x.m_Storage || this->m_vector.m_Storage.y != this->m_y.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0052D1A0
// Name: public: virtual void CDmePackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::Operate(CDmePackVector2Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector2D value; // [esp+0h] [ebp-8h] BYREF

  value.x = this->m_x.m_Storage;
  m_Storage = this->m_y.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.y = m_Storage;
  CDmAttribute::SetValue<Vector2D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0052D1D0
// Name: public: virtual void CDmePackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::Operate(CDmePackVector3Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0052D210
// Name: public: virtual void CDmePackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::Operate(CDmePackVector4Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector4D value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Vector4D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0052D250
// Name: public: virtual void CDmePackQAngleOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::Operate(CDmePackQAngleOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  QAngle value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_qangle.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<QAngle>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0052D2E0
// Name: public: virtual void CDmePackQuaternionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::Operate(CDmePackQuaternionOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Quaternion value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_quaternion.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Quaternion>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0052D360
// Name: public: virtual void CDmePackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::Operate(CDmePackVMatrixOperator *this)
{
  float *v1; // edx
  CDmaVar<float> *v2; // eax
  int v3; // esi
  double m_Storage; // st7
  VMatrix v; // [esp+4h] [ebp-40h] BYREF

  v1 = v.m[1];
  v2 = &this->m_cells[1];
  v3 = 2;
  do
  {
    m_Storage = v2[-1].m_Storage;
    v2 += 8;
    *(v1 - 4) = m_Storage;
    v1 += 32;
    --v3;
    *(v1 - 32) = v2[-8].m_Storage;
    *(v1 - 28) = v2[-7].m_Storage;
    *(v1 - 24) = v2[-6].m_Storage;
    *(v1 - 20) = v2[-5].m_Storage;
    *(v1 - 16) = v2[-4].m_Storage;
    *(v1 - 12) = v2[-3].m_Storage;
    *(v1 - 8) = v2[-2].m_Storage;
  }
  while ( v3 != 0 );
  CDmAttribute::SetValue<VMatrix>(this: this->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0052D530
// Name: public: virtual void CDmePackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vector.m_pAttribute;
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
// Address: 0x0052D590
// Name: public: virtual void CDmePackQAngleOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::GetInputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  int v9; // edi
  int v10; // eax
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
  v9 = attrs->m_Size;
  attrsa = this->m_y.m_pAttribute;
  v10 = attrs->m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v9 - v10 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v9 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = attrsa;
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_z.m_pAttribute;
  if ( v14 + 1 > v15 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v14 - v15 + 1);
  ++attrs->m_Size;
  v17 = attrs->m_Memory.m_pMemory;
  v18 = attrs->m_Size - v14 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
  v19 = &attrs->m_Memory.m_pMemory[v14];
  if ( v19 != nullptr )
    *v19 = v16;
}

//------------------------------------------------------------------------------
// Address: 0x0052D6A0
// Name: public: virtual void CDmePackVMatrixOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetInputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute **p_m_pAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]
  int attrsa; // [esp+18h] [ebp+8h]

  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( attrsa = 16; attrsa != 0; --attrsa )
  {
    m_Size = attrs->m_Size;
    v9 = *p_m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
      *v8 = v9;
    p_m_pAttribute += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D7D0
// Name: public: virtual bool CDmePackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackColorOperator::IsA(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052D800
// Name: public: virtual int CDmePackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackColorOperator::GetInheritanceDepth(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052D8E0
// Name: protected: virtual void CDmePackColorOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::PerformConstruction(CDmeUnpackColorOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
  CDmePackColorOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0052D9B0
// Name: public: virtual bool CDmePackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector2Operator::IsA(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052D9E0
// Name: public: virtual int CDmePackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::GetInheritanceDepth(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052DAC0
// Name: protected: virtual void CDmePackVector2Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::PerformConstruction(CDmeUnpackVector2Operator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
  CDmeUnpackVector2Operator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0052DB90
// Name: public: virtual bool CDmePackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector3Operator::IsA(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052DBC0
// Name: public: virtual int CDmePackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::GetInheritanceDepth(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052DCA0
// Name: protected: virtual void CDmePackVector3Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::PerformConstruction(CDmeUnpackVector3Operator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
  CDmeUnpackVector3Operator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0052DD70
// Name: public: virtual bool CDmePackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector4Operator::IsA(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052DDA0
// Name: public: virtual int CDmePackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector4Operator::GetInheritanceDepth(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052DF40
// Name: public: virtual bool CDmePackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQAngleOperator::IsA(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052DF70
// Name: public: virtual int CDmePackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQAngleOperator::GetInheritanceDepth(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052E140
// Name: public: virtual bool CDmePackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQuaternionOperator::IsA(CDmePackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052E170
// Name: public: virtual int CDmePackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQuaternionOperator::GetInheritanceDepth(
        CDmePackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052E270
// Name: protected: virtual void CDmePackQuaternionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::PerformConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
  CDmePackQuaternionOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0052E2F0
// Name: protected: CDmePackVMatrixOperator::CDmePackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *__thiscall CDmePackVMatrixOperator::CDmePackVMatrixOperator(
        CDmePackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `CDmElement'};
  this->m_vmatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_vmatrix.m_Storage);
  m_cells = this->m_cells;
  for ( i = 15; i >= 0; --i )
  {
    m_cells->m_pAttribute = nullptr;
    m_cells->m_Storage = 0.0;
    ++m_cells;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052E3B0
// Name: public: virtual bool CDmePackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVMatrixOperator::IsA(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052E3E0
// Name: public: virtual int CDmePackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::GetInheritanceDepth(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052E520
// Name: protected: void CDmePackVMatrixOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::OnConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmElement *v2; // ecx
  unsigned int v3; // esi
  CDmaVar<float> *m_cells; // edi
  CDmElement *v5; // ecx
  char name[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vmatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this: v2,
                                   pAttributeName: "vmatrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_vmatrix);
  v3 = 0;
  m_cells = this->m_cells;
  do
  {
    V_snprintf(pDest: name, maxLen: 4, pFormat: "m%d%d", v3 >> 2, v3 & 3);
    if ( this != nullptr )
      v5 = &this->CDmElement;
    else
      v5 = nullptr;
    m_cells->m_pAttribute = CDmElement::AddExternalAttribute(
                              this: v5,
                              pAttributeName: name,
                              type: AT_FLOAT,
                              pMemory: m_cells);
    ++v3;
    ++m_cells;
  }
  while ( v3 < 0x10 );
}

//------------------------------------------------------------------------------
// Address: 0x0052E6B0
// Name: public: virtual bool CDmePackQAngleOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackQAngleOperator::IsDirty(CDmeUnpackQAngleOperator *this)
{
  return this->m_qangle.m_Storage.x != this->m_x.m_Storage
      || this->m_qangle.m_Storage.y != this->m_y.m_Storage
      || this->m_qangle.m_Storage.z != this->m_z.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0052E820
// Name: public: virtual void CDmePackVector3Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::GetOutputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_qangle.m_pAttribute;
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
// Address: 0x0052E880
// Name: public: virtual void CDmePackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_quaternion.m_pAttribute;
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
// Address: 0x0052EA40
// Name: public: virtual void CDmePackVMatrixOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetOutputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vmatrix.m_pAttribute;
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
// Address: 0x0052F720
// Name: protected: virtual int CDmePackVMatrixOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::AllocatedSize(CDmeUnpackVMatrixOperator *this)
{
  return 272;
}

//------------------------------------------------------------------------------
// Address: 0x0057BDE0
// Name: _dynamic_initializer_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE40
// Name: _dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEA0
// Name: _dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF00
// Name: _dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF60
// Name: _dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BFC0
// Name: _dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C020
// Name: _dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E5E0
// Name: _dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E600
// Name: _dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E610
// Name: _dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E640
// Name: _dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE10
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE20
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackColorOperator_Helper,
           classname: "DmePackColorOperator",
           pFactory: &g_CDmePackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE70
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE80
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector2Operator_Helper,
           classname: "DmePackVector2Operator",
           pFactory: &g_CDmePackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BED0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEE0
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector3Operator_Helper,
           classname: "DmePackVector3Operator",
           pFactory: &g_CDmePackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF30
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF40
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector4Operator_Helper,
           classname: "DmePackVector4Operator",
           pFactory: &g_CDmePackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF90
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BFA0
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQAngleOperator_Helper,
           classname: "DmePackQAngleOperator",
           pFactory: &g_CDmePackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BFF0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C000
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQuaternionOperator_Helper,
           classname: "DmePackQuaternionOperator",
           pFactory: &g_CDmePackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C050
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C060
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVMatrixOperator_Helper,
           classname: "DmePackVMatrixOperator",
           pFactory: &g_CDmePackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E660
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E670
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E6A0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePackVMatrixOperator_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062EB50
// Name: protected: virtual int CDmePackVector3Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::AllocatedSize(CDmeWorld *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x0062FD50
// Name: protected: void CDmePackColorOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::OnConstruction(CDmeUnpackColorOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v2,
                                 pAttributeName: "color",
                                 type: AT_COLOR,
                                 pMemory: &this->m_color);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_red.m_pAttribute = CDmElement::AddExternalAttribute(
                               this: v3,
                               pAttributeName: "red",
                               type: AT_FLOAT,
                               pMemory: &this->m_red);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_green.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v4,
                                 pAttributeName: "green",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_green);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_blue.m_pAttribute = CDmElement::AddExternalAttribute(
                                this: v5,
                                pAttributeName: "blue",
                                type: AT_FLOAT,
                                pMemory: &this->m_blue);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_alpha.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this: v6,
                                 pAttributeName: "alpha",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x0062FEF0
// Name: protected: void CDmePackQuaternionOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::OnConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_quaternion.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this: v2,
                                      pAttributeName: "quaternion",
                                      type: AT_QUATERNION,
                                      pMemory: &this->m_quaternion);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_x.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v3,
                             pAttributeName: "x",
                             type: AT_FLOAT,
                             pMemory: &this->m_x);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_y.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v4,
                             pAttributeName: "y",
                             type: AT_FLOAT,
                             pMemory: &this->m_y);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_z.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v5,
                             pAttributeName: "z",
                             type: AT_FLOAT,
                             pMemory: &this->m_z);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_w.m_pAttribute = CDmElement::AddExternalAttribute(
                             this: v6,
                             pAttributeName: "w",
                             type: AT_FLOAT,
                             pMemory: &this->m_w);
}

//------------------------------------------------------------------------------
// Address: 0x0062FF90
// Name: protected: void CDmePackVMatrixOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::OnConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmElement *v2; // ecx
  unsigned int v3; // esi
  CDmaVar<float> *m_cells; // edi
  CDmElement *v5; // ecx
  char name[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vmatrix.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this: v2,
                                   pAttributeName: "vmatrix",
                                   type: AT_VMATRIX,
                                   pMemory: &this->m_vmatrix);
  v3 = 0;
  m_cells = this->m_cells;
  do
  {
    V_snprintf(pDest: name, maxLen: 4, pFormat: "m%d%d", v3 >> 2, v3 & 3);
    if ( this != nullptr )
      v5 = &this->CDmElement;
    else
      v5 = nullptr;
    m_cells->m_pAttribute = CDmElement::AddExternalAttribute(
                              this: v5,
                              pAttributeName: name,
                              type: AT_FLOAT,
                              pMemory: m_cells);
    ++v3;
    ++m_cells;
  }
  while ( v3 < 0x10 );
}

//------------------------------------------------------------------------------
// Address: 0x00630010
// Name: public: virtual bool CDmePackColorOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackColorOperator::IsDirty(CDmeUnpackColorOperator *this)
{
  return (float)this->m_color.m_Storage._color[0] != (float)(this->m_red.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[1] != (float)(this->m_green.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[2] != (float)(this->m_blue.m_Storage * 255.99899)
      || (float)this->m_color.m_Storage._color[3] != (float)(this->m_alpha.m_Storage * 255.99899);
}

//------------------------------------------------------------------------------
// Address: 0x006300A0
// Name: public: virtual void CDmePackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::Operate(CDmePackColorOperator *this)
{
  float v1; // xmm0_4
  int v2; // ebx
  float v3; // xmm0_4
  int v4; // edx
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Color value; // [esp+0h] [ebp-4h] BYREF

  value = (Color)this;
  v1 = this->m_red.m_Storage * 255.99899;
  if ( v1 >= 0.0 )
  {
    if ( v1 > 255.0 )
      v1 = 255.0;
  }
  else
  {
    v1 = 0.0;
  }
  v2 = (int)v1;
  v3 = this->m_green.m_Storage * 255.99899;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 255.0 )
      v3 = 255.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  v5 = this->m_blue.m_Storage * 255.99899;
  if ( v5 >= 0.0 )
  {
    if ( v5 > 255.0 )
      v5 = 255.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = (int)v5;
  v7 = this->m_alpha.m_Storage * 255.99899;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 255.0 )
      v7 = 255.0;
  }
  else
  {
    v7 = 0.0;
  }
  m_pAttribute = this->m_color.m_pAttribute;
  value._color[1] = v4;
  value._color[2] = v6;
  value._color[0] = v2;
  value._color[3] = (int)v7;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00630160
// Name: public: virtual void CDmePackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::Operate(CDmePackVector2Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector2D value; // [esp+0h] [ebp-8h] BYREF

  value.x = this->m_x.m_Storage;
  m_Storage = this->m_y.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.y = m_Storage;
  CDmAttribute::SetValue<Vector2D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00630190
// Name: public: virtual void CDmePackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::Operate(CDmePackVector3Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00630220
// Name: public: virtual void CDmePackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::Operate(CDmePackVector4Operator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Vector4D value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_vector.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Vector4D>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00630260
// Name: public: virtual void CDmePackQAngleOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::Operate(CDmePackQAngleOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  QAngle value; // [esp+0h] [ebp-Ch] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  m_Storage = this->m_z.m_Storage;
  m_pAttribute = this->m_qangle.m_pAttribute;
  value.z = m_Storage;
  CDmAttribute::SetValue<QAngle>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x006302A0
// Name: public: virtual void CDmePackQuaternionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::Operate(CDmePackQuaternionOperator *this)
{
  float m_Storage; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  Quaternion value; // [esp+0h] [ebp-10h] BYREF

  value.x = this->m_x.m_Storage;
  value.y = this->m_y.m_Storage;
  value.z = this->m_z.m_Storage;
  m_Storage = this->m_w.m_Storage;
  m_pAttribute = this->m_quaternion.m_pAttribute;
  value.w = m_Storage;
  CDmAttribute::SetValue<Quaternion>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00630320
// Name: public: virtual void CDmePackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::Operate(CDmePackVMatrixOperator *this)
{
  float *v1; // edx
  CDmaVar<float> *v2; // eax
  int v3; // esi
  double m_Storage; // st7
  VMatrix v; // [esp+4h] [ebp-40h] BYREF

  v1 = v.m[1];
  v2 = &this->m_cells[1];
  v3 = 2;
  do
  {
    m_Storage = v2[-1].m_Storage;
    v2 += 8;
    *(v1 - 4) = m_Storage;
    v1 += 32;
    --v3;
    *(v1 - 32) = v2[-8].m_Storage;
    *(v1 - 28) = v2[-7].m_Storage;
    *(v1 - 24) = v2[-6].m_Storage;
    *(v1 - 20) = v2[-5].m_Storage;
    *(v1 - 16) = v2[-4].m_Storage;
    *(v1 - 12) = v2[-3].m_Storage;
    *(v1 - 8) = v2[-2].m_Storage;
  }
  while ( v3 != 0 );
  CDmAttribute::SetValue<VMatrix>(this: this->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x006305B0
// Name: public: virtual void CDmePackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vector.m_pAttribute;
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
// Address: 0x00630610
// Name: public: virtual void CDmePackVector3Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::GetOutputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_qangle.m_pAttribute;
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
// Address: 0x00630670
// Name: public: virtual void CDmePackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_quaternion.m_pAttribute;
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
// Address: 0x006306D0
// Name: public: virtual void CDmePackVMatrixOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetInputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute **p_m_pAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // [esp+Ch] [ebp-4h]
  int attrsa; // [esp+18h] [ebp+8h]

  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( attrsa = 16; attrsa != 0; --attrsa )
  {
    m_Size = attrs->m_Size;
    v9 = *p_m_pAttribute;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
      *v8 = v9;
    p_m_pAttribute += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00630750
// Name: public: virtual void CDmePackVMatrixOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVMatrixOperator::GetOutputAttributes(
        CDmeUnpackVMatrixOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax

  m_pAttribute = this->m_vmatrix.m_pAttribute;
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
// Address: 0x00630870
// Name: public: virtual bool CDmePackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackColorOperator::IsA(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x006308A0
// Name: public: virtual int CDmePackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackColorOperator::GetInheritanceDepth(CDmePackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006309A0
// Name: protected: virtual void CDmePackColorOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackColorOperator::PerformConstruction(CDmeUnpackColorOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
  CDmePackColorOperator::OnConstruction(this: (CDmeUnpackColorOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00630A70
// Name: public: virtual bool CDmePackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector2Operator::IsA(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00630AA0
// Name: public: virtual int CDmePackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::GetInheritanceDepth(CDmePackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00630AF0
// Name: protected: virtual int CDmePackVector2Operator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector2Operator::AllocatedSize(CDmeUnpackVector2Operator *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x00630C40
// Name: public: virtual bool CDmePackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector3Operator::IsA(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00630C70
// Name: public: virtual int CDmePackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector3Operator::GetInheritanceDepth(CDmePackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00630D50
// Name: protected: virtual void CDmePackVector3Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector3Operator::PerformConstruction(CDmeUnpackVector3Operator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
  CDmeUnpackVector3Operator::OnConstruction(this: (CDmeUnpackVector3Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00630E20
// Name: public: virtual bool CDmePackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVector4Operator::IsA(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00630E50
// Name: public: virtual int CDmePackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVector4Operator::GetInheritanceDepth(CDmePackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00630FF0
// Name: public: virtual bool CDmePackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQAngleOperator::IsA(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631020
// Name: public: virtual int CDmePackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQAngleOperator::GetInheritanceDepth(CDmePackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006311D0
// Name: public: virtual bool CDmePackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackQuaternionOperator::IsA(CDmePackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631200
// Name: public: virtual int CDmePackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackQuaternionOperator::GetInheritanceDepth(
        CDmePackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631300
// Name: protected: virtual void CDmePackQuaternionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQuaternionOperator::PerformConstruction(CDmeUnpackQuaternionOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
  CDmePackQuaternionOperator::OnConstruction(this: (CDmeUnpackQuaternionOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00631380
// Name: protected: CDmePackVMatrixOperator::CDmePackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *__thiscall CDmePackVMatrixOperator::CDmePackVMatrixOperator(
        CDmePackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmePackVMatrixOperator_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmePackVMatrixOperator::`vftable'{for `CDmElement'};
  this->m_vmatrix.m_pAttribute = nullptr;
  MatrixSetIdentity(dst: &this->m_vmatrix.m_Storage);
  m_cells = this->m_cells;
  for ( i = 15; i >= 0; --i )
  {
    m_cells->m_pAttribute = nullptr;
    m_cells->m_Storage = 0.0;
    ++m_cells;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00631440
// Name: public: virtual bool CDmePackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePackVMatrixOperator::IsA(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631470
// Name: public: virtual int CDmePackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::GetInheritanceDepth(CDmePackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631730
// Name: public: virtual bool CDmePackVector2Operator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackVector2Operator::IsDirty(CDmeUnpackVector2Operator *this)
{
  return this->m_vector.m_Storage.x != this->m_x.m_Storage || this->m_vector.m_Storage.y != this->m_y.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00631780
// Name: public: virtual bool CDmePackQAngleOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmePackQAngleOperator::IsDirty(CDmeUnpackQAngleOperator *this)
{
  return this->m_qangle.m_Storage.x != this->m_x.m_Storage
      || this->m_qangle.m_Storage.y != this->m_y.m_Storage
      || this->m_qangle.m_Storage.z != this->m_z.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00631890
// Name: public: virtual void CDmePackQAngleOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackQAngleOperator::GetInputAttributes(
        CDmeUnpackQAngleOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  int v9; // edi
  int v10; // eax
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: m_Size - m_nAllocationCount + 1);
  ++attrs->m_Size;
  m_pMemory = attrs->m_Memory.m_pMemory;
  v7 = attrs->m_Size - m_Size - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &attrs->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = m_pAttribute;
  v9 = attrs->m_Size;
  attrsa = this->m_y.m_pAttribute;
  v10 = attrs->m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v9 - v10 + 1);
  ++attrs->m_Size;
  v11 = attrs->m_Memory.m_pMemory;
  v12 = attrs->m_Size - v9 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &attrs->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = attrsa;
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_z.m_pAttribute;
  if ( v14 + 1 > v15 )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v14 - v15 + 1);
  ++attrs->m_Size;
  v17 = attrs->m_Memory.m_pMemory;
  v18 = attrs->m_Size - v14 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &v17[v14 + 1], src: &v17[v14], count: 4 * v18);
  v19 = &attrs->m_Memory.m_pMemory[v14];
  if ( v19 != nullptr )
    *v19 = v16;
}

//------------------------------------------------------------------------------
// Address: 0x00631E80
// Name: protected: virtual void CDmePackVector2Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePackVector2Operator::PerformConstruction(CDmeUnpackVector2Operator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
  CDmeUnpackVector2Operator::OnConstruction(this: (CDmeUnpackVector2Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x006327D0
// Name: protected: virtual int CDmePackVMatrixOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePackVMatrixOperator::AllocatedSize(CDmeUnpackVMatrixOperator *this)
{
  return 272;
}

//------------------------------------------------------------------------------
// Address: 0x006B9D50
// Name: _dynamic_initializer_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackColorOperator::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9DB0
// Name: _dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector2Operator::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9E10
// Name: _dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector3Operator::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9E70
// Name: _dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVector4Operator::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9ED0
// Name: _dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQAngleOperator::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9F30
// Name: _dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackQuaternionOperator::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9F90
// Name: _dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePackVMatrixOperator::s_Allocator,
    blockSize: 0x110u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD400
// Name: _dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD410
// Name: _dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD420
// Name: _dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD430
// Name: _dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD440
// Name: _dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD450
// Name: _dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD460
// Name: _dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9D80
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9D90
// Name: _dynamic_initializer_for__g_CDmePackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackColorOperator_Helper,
           classname: "DmePackColorOperator",
           pFactory: &g_CDmePackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9DE0
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9DF0
// Name: _dynamic_initializer_for__g_CDmePackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector2Operator_Helper,
           classname: "DmePackVector2Operator",
           pFactory: &g_CDmePackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9E40
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9E50
// Name: _dynamic_initializer_for__g_CDmePackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector3Operator_Helper,
           classname: "DmePackVector3Operator",
           pFactory: &g_CDmePackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9EA0
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9EB0
// Name: _dynamic_initializer_for__g_CDmePackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVector4Operator_Helper,
           classname: "DmePackVector4Operator",
           pFactory: &g_CDmePackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9F00
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9F10
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQAngleOperator_Helper,
           classname: "DmePackQAngleOperator",
           pFactory: &g_CDmePackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9F60
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9F70
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackQuaternionOperator_Helper,
           classname: "DmePackQuaternionOperator",
           pFactory: &g_CDmePackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9FC0
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9FD0
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePackVMatrixOperator_Helper,
           classname: "DmePackVMatrixOperator",
           pFactory: &g_CDmePackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD470
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector2Operator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD480
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector3Operator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD490
// Name: _dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVector4Operator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD4A0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQAngleOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD4B0
// Name: _dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackQuaternionOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD4C0
// Name: _dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackVMatrixOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD4D0
// Name: _dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePackColorOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePackColorOperator_Factory.m_CallBackList);
}

} // namespace vmap
