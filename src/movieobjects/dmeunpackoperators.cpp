// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeunpackoperators.cpp
// Functions: 68
// ============================================================

#include "movieobjects\dmeunpackoperators.h"

//------------------------------------------------------------------------------
// Address: 0x0055CBA0
// Name: protected: void CDmeUnpackVector2Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::OnConstruction(CDmeUnpackVector2Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR2,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x0055CC10
// Name: protected: void CDmeUnpackQAngleOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::OnConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_qangle.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "qangle",
                                  type: AT_QANGLE,
                                  pMemory: &this->m_qangle);
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
}

//------------------------------------------------------------------------------
// Address: 0x0055CE60
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeUnpackQuaternionOperator::IsDirty(CDmeUnpackQuaternionOperator *this)
{
  return this->m_quaternion.m_Storage.x != this->m_x.m_Storage
      || this->m_quaternion.m_Storage.y != this->m_y.m_Storage
      || this->m_quaternion.m_Storage.z != this->m_z.m_Storage
      || this->m_quaternion.m_Storage.w != this->m_w.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0055CF70
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeUnpackVMatrixOperator::IsDirty(CDmeUnpackVMatrixOperator *this)
{
  CDmaVar<VMatrix> *p_m_vmatrix; // esi
  unsigned int v2; // edx
  CDmaVar<float> *i; // ecx

  p_m_vmatrix = &this->m_vmatrix;
  v2 = 0;
  for ( i = this->m_cells; p_m_vmatrix->m_Storage.m[0][0] == i->m_Storage; ++i )
  {
    ++v2;
    p_m_vmatrix = (CDmaVar<VMatrix> *)((char *)p_m_vmatrix + 16);
    if ( v2 >= 0x10 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D080
// Name: public: virtual void CDmeUnpackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
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
  v10 = this->m_y.m_pAttribute;
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
}

//------------------------------------------------------------------------------
// Address: 0x0055D4B0
// Name: protected: virtual void CDmeUnpackQuaternionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQuaternionOperator::PerformDestruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0055DC90
// Name: protected: virtual void CDmeUnpackQAngleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::PerformConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
  CDmeUnpackQAngleOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0055E150
// Name: protected: void CDmeUnpackVector3Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::OnConstruction(CDmeUnpackVector3Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x0055E1D0
// Name: protected: void CDmeUnpackVector4Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::OnConstruction(CDmeUnpackVector4Operator *this)
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
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR4,
                                  pMemory: &this->m_vector);
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
// Address: 0x0055E2F0
// Name: public: virtual void CDmeUnpackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::Operate(CDmeUnpackVMatrixOperator *this)
{
  VMatrix *p_v; // esi
  CDmAttribute **p_m_pAttribute; // edi
  int i; // ebx
  VMatrix v; // [esp+Ch] [ebp-44h] BYREF
  CDmeUnpackVMatrixOperator *v5; // [esp+4Ch] [ebp-4h]

  v5 = this;
  p_v = &v;
  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( i = 16; i != 0; --i )
  {
    CDmAttribute::SetValue<float>(this: *p_m_pAttribute, value: (float *)p_v);
    p_v = (VMatrix *)((char *)p_v + 16);
    p_m_pAttribute += 2;
  }
  CDmAttribute::SetValue<VMatrix>(this: v5->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0055E3D0
// Name: public: virtual void CDmeUnpackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::Operate(CDmeUnpackColorOperator *this)
{
  float v2; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  CDmAttribute *v6; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (float)this->m_color.m_Storage._color[0] * 0.0039062654;
  m_pAttribute = this->m_red.m_pAttribute;
  value = v2;
  CDmAttribute::SetValue<float>(this: m_pAttribute, &value);
  v4 = this->m_green.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[1] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v4, &value);
  v5 = this->m_blue.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[2] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v5, &value);
  v6 = this->m_alpha.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[3] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055E4A0
// Name: public: virtual void CDmeUnpackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::Operate(CDmeUnpackVector2Operator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_vector.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_vector.m_Storage.y);
}

//------------------------------------------------------------------------------
// Address: 0x0055E500
// Name: public: virtual void CDmeUnpackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::Operate(CDmeUnpackQAngleOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_qangle.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_qangle.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_qangle.m_Storage.z);
}

//------------------------------------------------------------------------------
// Address: 0x0055E530
// Name: public: virtual void CDmeUnpackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::Operate(CDmeUnpackQuaternionOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_quaternion.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_quaternion.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_quaternion.m_Storage.z);
  CDmAttribute::SetValue<float>(this: this->m_w.m_pAttribute, value: &this->m_quaternion.m_Storage.w);
}

//------------------------------------------------------------------------------
// Address: 0x0055E570
// Name: public: virtual void CDmeUnpackColorOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_red.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_green.m_pAttribute;
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
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_blue.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_alpha.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x0055E730
// Name: public: virtual void CDmeUnpackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_x.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_y.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_w.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x0055E9C0
// Name: public: virtual bool CDmeUnpackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackColorOperator::IsA(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055E9F0
// Name: public: virtual int CDmeUnpackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackColorOperator::GetInheritanceDepth(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055EBA0
// Name: public: virtual bool CDmeUnpackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector2Operator::IsA(CDmeUnpackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055EBD0
// Name: public: virtual int CDmeUnpackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector2Operator::GetInheritanceDepth(
        CDmeUnpackVector2Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055ED60
// Name: public: virtual bool CDmeUnpackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector3Operator::IsA(CDmeUnpackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055ED90
// Name: public: virtual int CDmeUnpackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector3Operator::GetInheritanceDepth(
        CDmeUnpackVector3Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055EF40
// Name: public: virtual bool CDmeUnpackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector4Operator::IsA(CDmeUnpackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055EF70
// Name: public: virtual int CDmeUnpackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector4Operator::GetInheritanceDepth(
        CDmeUnpackVector4Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F060
// Name: protected: virtual void CDmeUnpackVector4Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::PerformConstruction(CDmeUnpackVector4Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
  CDmeUnpackVector4Operator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0055F130
// Name: public: virtual bool CDmeUnpackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQAngleOperator::IsA(CDmeUnpackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F160
// Name: public: virtual int CDmeUnpackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQAngleOperator::GetInheritanceDepth(
        CDmeUnpackQAngleOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F2F0
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQuaternionOperator::IsA(CDmeUnpackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F320
// Name: public: virtual int CDmeUnpackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQuaternionOperator::GetInheritanceDepth(
        CDmeUnpackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F480
// Name: protected: CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *__thiscall CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(
        CDmeUnpackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `CDmElement'};
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
// Address: 0x0055F540
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVMatrixOperator::IsA(CDmeUnpackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F570
// Name: public: virtual int CDmeUnpackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVMatrixOperator::GetInheritanceDepth(
        CDmeUnpackVMatrixOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F610
// Name: protected: virtual void CDmeUnpackVMatrixOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::PerformConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
  CDmePackVMatrixOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005AE380
// Name: _dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE3E0
// Name: _dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE440
// Name: _dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE4A0
// Name: _dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE500
// Name: _dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE560
// Name: _dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE5C0
// Name: _dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B07D0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B07E0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B07F0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0800
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0810
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0820
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0830
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AE3B0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE3C0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackColorOperator_Helper,
           classname: "DmeUnpackColorOperator",
           pFactory: &g_CDmeUnpackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE410
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE420
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector2Operator_Helper,
           classname: "DmeUnpackVector2Operator",
           pFactory: &g_CDmeUnpackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE470
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE480
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector3Operator_Helper,
           classname: "DmeUnpackVector3Operator",
           pFactory: &g_CDmeUnpackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE4D0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE4E0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector4Operator_Helper,
           classname: "DmeUnpackVector4Operator",
           pFactory: &g_CDmeUnpackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE530
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE540
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQAngleOperator_Helper,
           classname: "DmeUnpackQAngleOperator",
           pFactory: &g_CDmeUnpackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE590
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE5A0
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQuaternionOperator_Helper,
           classname: "DmeUnpackQuaternionOperator",
           pFactory: &g_CDmeUnpackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AE5F0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE600
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVMatrixOperator_Helper,
           classname: "DmeUnpackVMatrixOperator",
           pFactory: &g_CDmeUnpackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0840
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0850
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0860
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0870
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0880
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0890
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B08A0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackColorOperator_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005B3FC0
// Name: protected: void CDmeUnpackVector2Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::OnConstruction(CDmeUnpackVector2Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR2,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x005B4390
// Name: public: virtual void CDmeUnpackColorOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_red.m_pAttribute;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_green.m_pAttribute;
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
  v14 = (int)attrs[1].m_pMemory;
  v15 = attrs->m_nAllocationCount;
  v16 = this->m_blue.m_pAttribute;
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
  v20 = (int)attrs[1].m_pMemory;
  v21 = attrs->m_nAllocationCount;
  v22 = this->m_alpha.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v20 - v21 + 1);
  ++attrs[1].m_pMemory;
  v23 = (CDmAttribute **)attrs->m_pMemory;
  v24 = (int)attrs[1].m_pMemory - v20 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = (CDmAttribute **)&attrs->m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x005B5350
// Name: protected: void CDmeUnpackVector3Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::OnConstruction(CDmeUnpackVector3Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x005B53D0
// Name: protected: void CDmeUnpackVector4Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::OnConstruction(CDmeUnpackVector4Operator *this)
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
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR4,
                                  pMemory: &this->m_vector);
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
// Address: 0x005B5470
// Name: protected: void CDmeUnpackQAngleOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::OnConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_qangle.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "qangle",
                                  type: AT_QANGLE,
                                  pMemory: &this->m_qangle);
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
}

//------------------------------------------------------------------------------
// Address: 0x005B5610
// Name: public: virtual void CDmeUnpackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::Operate(CDmeUnpackVMatrixOperator *this)
{
  VMatrix *p_v; // esi
  CDmAttribute **p_m_pAttribute; // edi
  int i; // ebx
  VMatrix v; // [esp+Ch] [ebp-44h] BYREF
  CDmeUnpackVMatrixOperator *v5; // [esp+4Ch] [ebp-4h]

  v5 = this;
  p_v = &v;
  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( i = 16; i != 0; --i )
  {
    CDmAttribute::SetValue<float>(this: *p_m_pAttribute, value: (const float *)p_v);
    p_v = (VMatrix *)((char *)p_v + 16);
    p_m_pAttribute += 2;
  }
  CDmAttribute::SetValue<VMatrix>(this: v5->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x005B5660
// Name: public: virtual void CDmeUnpackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::Operate(CDmeUnpackColorOperator *this)
{
  float v2; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  CDmAttribute *v6; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (float)this->m_color.m_Storage._color[0] * 0.0039062654;
  m_pAttribute = this->m_red.m_pAttribute;
  value = v2;
  CDmAttribute::SetValue<float>(this: m_pAttribute, &value);
  v4 = this->m_green.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[1] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v4, &value);
  v5 = this->m_blue.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[2] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v5, &value);
  v6 = this->m_alpha.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[3] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005B5700
// Name: public: virtual void CDmeUnpackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::Operate(CDmeUnpackVector2Operator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_vector.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_vector.m_Storage.y);
}

//------------------------------------------------------------------------------
// Address: 0x005B5720
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeUnpackQuaternionOperator::IsDirty(CDmeUnpackQuaternionOperator *this)
{
  return this->m_quaternion.m_Storage.x != this->m_x.m_Storage
      || this->m_quaternion.m_Storage.y != this->m_y.m_Storage
      || this->m_quaternion.m_Storage.z != this->m_z.m_Storage
      || this->m_quaternion.m_Storage.w != this->m_w.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005B5770
// Name: public: virtual void CDmeUnpackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::Operate(CDmeUnpackQAngleOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_qangle.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_qangle.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_qangle.m_Storage.z);
}

//------------------------------------------------------------------------------
// Address: 0x005B57A0
// Name: public: virtual void CDmeUnpackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::Operate(CDmeUnpackQuaternionOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_quaternion.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_quaternion.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_quaternion.m_Storage.z);
  CDmAttribute::SetValue<float>(this: this->m_w.m_pAttribute, value: &this->m_quaternion.m_Storage.w);
}

//------------------------------------------------------------------------------
// Address: 0x005B57E0
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeUnpackVMatrixOperator::IsDirty(CDmeUnpackVMatrixOperator *this)
{
  CDmaVar<VMatrix> *p_m_vmatrix; // esi
  unsigned int v2; // edx
  CDmaVar<float> *i; // ecx

  p_m_vmatrix = &this->m_vmatrix;
  v2 = 0;
  for ( i = this->m_cells; p_m_vmatrix->m_Storage.m[0][0] == i->m_Storage; ++i )
  {
    ++v2;
    p_m_vmatrix = (CDmaVar<VMatrix> *)((char *)p_m_vmatrix + 16);
    if ( v2 >= 0x10 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5820
// Name: public: virtual void CDmeUnpackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_x.m_pAttribute;
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
  v10 = this->m_y.m_pAttribute;
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
}

//------------------------------------------------------------------------------
// Address: 0x005B5A50
// Name: public: virtual void CDmeUnpackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_x.m_pAttribute;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_y.m_pAttribute;
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
  v20 = (int)attrs[1].m_pMemory;
  v21 = attrs->m_nAllocationCount;
  v22 = this->m_w.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v20 - v21 + 1);
  ++attrs[1].m_pMemory;
  v23 = (CDmAttribute **)attrs->m_pMemory;
  v24 = (int)attrs[1].m_pMemory - v20 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = (CDmAttribute **)&attrs->m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x005B5D50
// Name: public: virtual bool CDmeUnpackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackColorOperator::IsA(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5D80
// Name: public: virtual int CDmeUnpackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackColorOperator::GetInheritanceDepth(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5F30
// Name: public: virtual bool CDmeUnpackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector2Operator::IsA(CDmeUnpackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5F60
// Name: public: virtual int CDmeUnpackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector2Operator::GetInheritanceDepth(
        CDmeUnpackVector2Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B5FB0
// Name: protected: virtual void CDmeUnpackQuaternionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQuaternionOperator::PerformDestruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005B6120
// Name: public: virtual bool CDmeUnpackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector3Operator::IsA(CDmeUnpackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6150
// Name: public: virtual int CDmeUnpackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector3Operator::GetInheritanceDepth(
        CDmeUnpackVector3Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6300
// Name: public: virtual bool CDmeUnpackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector4Operator::IsA(CDmeUnpackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6330
// Name: public: virtual int CDmeUnpackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector4Operator::GetInheritanceDepth(
        CDmeUnpackVector4Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6420
// Name: protected: virtual void CDmeUnpackVector4Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::PerformConstruction(CDmeUnpackVector4Operator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
  CDmeUnpackVector4Operator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B64F0
// Name: public: virtual bool CDmeUnpackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQAngleOperator::IsA(CDmeUnpackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6520
// Name: public: virtual int CDmeUnpackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQAngleOperator::GetInheritanceDepth(
        CDmeUnpackQAngleOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6600
// Name: protected: virtual void CDmeUnpackQAngleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::PerformConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
  CDmeUnpackQAngleOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005B66D0
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQuaternionOperator::IsA(CDmeUnpackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6700
// Name: public: virtual int CDmeUnpackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQuaternionOperator::GetInheritanceDepth(
        CDmeUnpackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6880
// Name: protected: CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *__thiscall CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(
        CDmeUnpackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `CDmElement'};
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
// Address: 0x005B6940
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVMatrixOperator::IsA(CDmeUnpackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6970
// Name: public: virtual int CDmeUnpackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVMatrixOperator::GetInheritanceDepth(
        CDmeUnpackVMatrixOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B6A20
// Name: protected: virtual void CDmeUnpackVMatrixOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::PerformConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
  CDmePackVMatrixOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0067FB60
// Name: _dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FBC0
// Name: _dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FC20
// Name: _dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FC80
// Name: _dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FCE0
// Name: _dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FD40
// Name: _dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FDA0
// Name: _dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682CE0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682CF0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682D00
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682D10
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682D20
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682D30
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682D40
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067FB90
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FBA0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackColorOperator_Helper,
           classname: "DmeUnpackColorOperator",
           pFactory: &g_CDmeUnpackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FBF0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FC00
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector2Operator_Helper,
           classname: "DmeUnpackVector2Operator",
           pFactory: &g_CDmeUnpackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FC50
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FC60
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector3Operator_Helper,
           classname: "DmeUnpackVector3Operator",
           pFactory: &g_CDmeUnpackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FCB0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FCC0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector4Operator_Helper,
           classname: "DmeUnpackVector4Operator",
           pFactory: &g_CDmeUnpackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FD10
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FD20
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQAngleOperator_Helper,
           classname: "DmeUnpackQAngleOperator",
           pFactory: &g_CDmeUnpackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FD70
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FD80
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQuaternionOperator_Helper,
           classname: "DmeUnpackQuaternionOperator",
           pFactory: &g_CDmeUnpackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067FDD0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067FDE0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVMatrixOperator_Helper,
           classname: "DmeUnpackVMatrixOperator",
           pFactory: &g_CDmeUnpackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682D50
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682D60
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682D70
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682D80
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682D90
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682DA0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682DB0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackColorOperator_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004745C0
// Name: protected: virtual void CDmeUnpackQuaternionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQuaternionOperator::PerformDestruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0051E3F0
// Name: protected: void CDmeUnpackVector2Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::OnConstruction(CDmeUnpackVector2Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR2,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x0051E460
// Name: protected: void CDmeUnpackVector3Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::OnConstruction(CDmeUnpackVector3Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x0051E4E0
// Name: protected: void CDmeUnpackVector4Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::OnConstruction(CDmeUnpackVector4Operator *this)
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
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR4,
                                  pMemory: &this->m_vector);
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
// Address: 0x0051E580
// Name: protected: void CDmeUnpackQAngleOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::OnConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_qangle.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "qangle",
                                  type: AT_QANGLE,
                                  pMemory: &this->m_qangle);
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
}

//------------------------------------------------------------------------------
// Address: 0x0051E900
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeUnpackQuaternionOperator::IsDirty(CDmeUnpackQuaternionOperator *this)
{
  return this->m_quaternion.m_Storage.x != this->m_x.m_Storage
      || this->m_quaternion.m_Storage.y != this->m_y.m_Storage
      || this->m_quaternion.m_Storage.z != this->m_z.m_Storage
      || this->m_quaternion.m_Storage.w != this->m_w.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0051E990
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeUnpackVMatrixOperator::IsDirty(CDmeUnpackVMatrixOperator *this)
{
  CDmaVar<VMatrix> *p_m_vmatrix; // esi
  unsigned int v2; // edx
  CDmaVar<float> *i; // ecx

  p_m_vmatrix = &this->m_vmatrix;
  v2 = 0;
  for ( i = this->m_cells; p_m_vmatrix->m_Storage.m[0][0] == i->m_Storage; ++i )
  {
    ++v2;
    p_m_vmatrix = (CDmaVar<VMatrix> *)((char *)p_m_vmatrix + 16);
    if ( v2 >= 0x10 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051EA40
// Name: public: virtual void CDmeUnpackColorOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_red.m_pAttribute;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_green.m_pAttribute;
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
  v14 = (int)attrs[1].m_pMemory;
  v15 = attrs->m_nAllocationCount;
  v16 = this->m_blue.m_pAttribute;
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
  v20 = (int)attrs[1].m_pMemory;
  v21 = attrs->m_nAllocationCount;
  v22 = this->m_alpha.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v20 - v21 + 1);
  ++attrs[1].m_pMemory;
  v23 = (CDmAttribute **)attrs->m_pMemory;
  v24 = (int)attrs[1].m_pMemory - v20 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = (CDmAttribute **)&attrs->m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x0051EBA0
// Name: public: virtual void CDmeUnpackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_x.m_pAttribute;
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
  v10 = this->m_y.m_pAttribute;
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
}

//------------------------------------------------------------------------------
// Address: 0x0051F520
// Name: protected: virtual void CDmeUnpackVector4Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::PerformConstruction(CDmeUnpackVector4Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
  CDmeUnpackVector4Operator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0051F710
// Name: protected: virtual void CDmeUnpackQAngleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::PerformConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
  CDmeUnpackQAngleOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0051FB10
// Name: protected: virtual void CDmeUnpackVMatrixOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::PerformConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
  CDmePackVMatrixOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0051FC70
// Name: public: virtual void CDmeUnpackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::Operate(CDmeUnpackVMatrixOperator *this)
{
  VMatrix *p_v; // esi
  CDmAttribute **p_m_pAttribute; // edi
  int i; // ebx
  VMatrix v; // [esp+Ch] [ebp-44h] BYREF
  CDmeUnpackVMatrixOperator *v5; // [esp+4Ch] [ebp-4h]

  v5 = this;
  p_v = &v;
  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( i = 16; i != 0; --i )
  {
    CDmAttribute::SetValue<float>(this: *p_m_pAttribute, value: (float *)p_v);
    p_v = (VMatrix *)((char *)p_v + 16);
    p_m_pAttribute += 2;
  }
  CDmAttribute::SetValue<VMatrix>(this: v5->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0051FCC0
// Name: public: virtual void CDmeUnpackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::Operate(CDmeUnpackColorOperator *this)
{
  float v2; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  CDmAttribute *v6; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (float)this->m_color.m_Storage._color[0] * 0.0039062654;
  m_pAttribute = this->m_red.m_pAttribute;
  value = v2;
  CDmAttribute::SetValue<float>(this: m_pAttribute, &value);
  v4 = this->m_green.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[1] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v4, &value);
  v5 = this->m_blue.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[2] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v5, &value);
  v6 = this->m_alpha.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[3] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051FD90
// Name: public: virtual void CDmeUnpackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::Operate(CDmeUnpackVector2Operator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_vector.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_vector.m_Storage.y);
}

//------------------------------------------------------------------------------
// Address: 0x0051FDB0
// Name: public: virtual void CDmeUnpackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::Operate(CDmeUnpackQAngleOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_qangle.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_qangle.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_qangle.m_Storage.z);
}

//------------------------------------------------------------------------------
// Address: 0x0051FDE0
// Name: public: virtual void CDmeUnpackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::Operate(CDmeUnpackQuaternionOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_quaternion.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_quaternion.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_quaternion.m_Storage.z);
  CDmAttribute::SetValue<float>(this: this->m_w.m_pAttribute, value: &this->m_quaternion.m_Storage.w);
}

//------------------------------------------------------------------------------
// Address: 0x0051FEE0
// Name: public: virtual void CDmeUnpackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_x.m_pAttribute;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_y.m_pAttribute;
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
  v20 = (int)attrs[1].m_pMemory;
  v21 = attrs->m_nAllocationCount;
  v22 = this->m_w.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v20 - v21 + 1);
  ++attrs[1].m_pMemory;
  v23 = (CDmAttribute **)attrs->m_pMemory;
  v24 = (int)attrs[1].m_pMemory - v20 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = (CDmAttribute **)&attrs->m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x00520240
// Name: public: virtual bool CDmeUnpackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackColorOperator::IsA(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520270
// Name: public: virtual int CDmeUnpackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackColorOperator::GetInheritanceDepth(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520420
// Name: public: virtual bool CDmeUnpackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector2Operator::IsA(CDmeUnpackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520450
// Name: public: virtual int CDmeUnpackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector2Operator::GetInheritanceDepth(
        CDmeUnpackVector2Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005205E0
// Name: public: virtual bool CDmeUnpackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector3Operator::IsA(CDmeUnpackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520610
// Name: public: virtual int CDmeUnpackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector3Operator::GetInheritanceDepth(
        CDmeUnpackVector3Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005207A0
// Name: public: virtual bool CDmeUnpackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector4Operator::IsA(CDmeUnpackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005207D0
// Name: public: virtual int CDmeUnpackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector4Operator::GetInheritanceDepth(
        CDmeUnpackVector4Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520970
// Name: public: virtual bool CDmeUnpackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQAngleOperator::IsA(CDmeUnpackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005209A0
// Name: public: virtual int CDmeUnpackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQAngleOperator::GetInheritanceDepth(
        CDmeUnpackQAngleOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520B30
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQuaternionOperator::IsA(CDmeUnpackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520B60
// Name: public: virtual int CDmeUnpackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQuaternionOperator::GetInheritanceDepth(
        CDmeUnpackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520CE0
// Name: protected: CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *__thiscall CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(
        CDmeUnpackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `CDmElement'};
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
// Address: 0x00520DA0
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVMatrixOperator::IsA(CDmeUnpackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520DD0
// Name: public: virtual int CDmeUnpackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVMatrixOperator::GetInheritanceDepth(
        CDmeUnpackVMatrixOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C740
// Name: _dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C7A0
// Name: _dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C800
// Name: _dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C860
// Name: _dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C8C0
// Name: _dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C920
// Name: _dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C980
// Name: _dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EEC0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EED0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EEE0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EEF0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF00
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF10
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF20
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C770
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C780
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackColorOperator_Helper,
           classname: "DmeUnpackColorOperator",
           pFactory: &g_CDmeUnpackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C7D0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C7E0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector2Operator_Helper,
           classname: "DmeUnpackVector2Operator",
           pFactory: &g_CDmeUnpackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C830
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C840
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector3Operator_Helper,
           classname: "DmeUnpackVector3Operator",
           pFactory: &g_CDmeUnpackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C890
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C8A0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector4Operator_Helper,
           classname: "DmeUnpackVector4Operator",
           pFactory: &g_CDmeUnpackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C8F0
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C900
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQAngleOperator_Helper,
           classname: "DmeUnpackQAngleOperator",
           pFactory: &g_CDmeUnpackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C950
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C960
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQuaternionOperator_Helper,
           classname: "DmeUnpackQuaternionOperator",
           pFactory: &g_CDmeUnpackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C9B0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C9C0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVMatrixOperator_Helper,
           classname: "DmeUnpackVMatrixOperator",
           pFactory: &g_CDmeUnpackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF30
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF40
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF50
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF60
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF70
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF80
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EF90
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackColorOperator_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00524660
// Name: protected: void CDmeUnpackVector2Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::OnConstruction(CDmeUnpackVector2Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR2,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x005246D0
// Name: protected: void CDmeUnpackQAngleOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::OnConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_qangle.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "qangle",
                                  type: AT_QANGLE,
                                  pMemory: &this->m_qangle);
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
}

//------------------------------------------------------------------------------
// Address: 0x00524970
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeUnpackQuaternionOperator::IsDirty(CDmeUnpackQuaternionOperator *this)
{
  return this->m_quaternion.m_Storage.x != this->m_x.m_Storage
      || this->m_quaternion.m_Storage.y != this->m_y.m_Storage
      || this->m_quaternion.m_Storage.z != this->m_z.m_Storage
      || this->m_quaternion.m_Storage.w != this->m_w.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00524A00
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeUnpackVMatrixOperator::IsDirty(CDmeUnpackVMatrixOperator *this)
{
  CDmaVar<VMatrix> *p_m_vmatrix; // esi
  unsigned int v2; // edx
  CDmaVar<float> *i; // ecx

  p_m_vmatrix = &this->m_vmatrix;
  v2 = 0;
  for ( i = this->m_cells; p_m_vmatrix->m_Storage.m[0][0] == i->m_Storage; ++i )
  {
    ++v2;
    p_m_vmatrix = (CDmaVar<VMatrix> *)((char *)p_m_vmatrix + 16);
    if ( v2 >= 0x10 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00524BD0
// Name: public: virtual void CDmeUnpackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_x.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_y.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_w.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x00525690
// Name: protected: virtual void CDmeUnpackQAngleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::PerformConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
  CDmeUnpackQAngleOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00525B40
// Name: protected: void CDmeUnpackVector3Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::OnConstruction(CDmeUnpackVector3Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x00525BC0
// Name: protected: void CDmeUnpackVector4Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::OnConstruction(CDmeUnpackVector4Operator *this)
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
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR4,
                                  pMemory: &this->m_vector);
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
// Address: 0x00525D80
// Name: public: virtual void CDmeUnpackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::Operate(CDmeUnpackVMatrixOperator *this)
{
  VMatrix *p_v; // esi
  CDmAttribute **p_m_pAttribute; // edi
  int i; // ebx
  VMatrix v; // [esp+Ch] [ebp-44h] BYREF
  CDmeUnpackVMatrixOperator *v5; // [esp+4Ch] [ebp-4h]

  v5 = this;
  p_v = &v;
  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( i = 16; i != 0; --i )
  {
    CDmAttribute::SetValue<float>(this: *p_m_pAttribute, value: (const float *)p_v);
    p_v = (VMatrix *)((char *)p_v + 16);
    p_m_pAttribute += 2;
  }
  CDmAttribute::SetValue<VMatrix>(this: v5->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x00525E60
// Name: public: virtual void CDmeUnpackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::Operate(CDmeUnpackColorOperator *this)
{
  float v2; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  CDmAttribute *v6; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (float)this->m_color.m_Storage._color[0] * 0.0039062654;
  m_pAttribute = this->m_red.m_pAttribute;
  value = v2;
  CDmAttribute::SetValue<float>(this: m_pAttribute, &value);
  v4 = this->m_green.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[1] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v4, &value);
  v5 = this->m_blue.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[2] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v5, &value);
  v6 = this->m_alpha.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[3] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00525F00
// Name: public: virtual void CDmeUnpackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::Operate(CDmeUnpackVector2Operator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_vector.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_vector.m_Storage.y);
}

//------------------------------------------------------------------------------
// Address: 0x00525F20
// Name: public: virtual void CDmeUnpackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::Operate(CDmeUnpackQAngleOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_qangle.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_qangle.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_qangle.m_Storage.z);
}

//------------------------------------------------------------------------------
// Address: 0x00525F50
// Name: public: virtual void CDmeUnpackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::Operate(CDmeUnpackQuaternionOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_quaternion.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_quaternion.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_quaternion.m_Storage.z);
  CDmAttribute::SetValue<float>(this: this->m_w.m_pAttribute, value: &this->m_quaternion.m_Storage.w);
}

//------------------------------------------------------------------------------
// Address: 0x00525F90
// Name: public: virtual void CDmeUnpackColorOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_red.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_green.m_pAttribute;
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
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_blue.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_alpha.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x005260F0
// Name: public: virtual void CDmeUnpackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
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
  v10 = this->m_y.m_pAttribute;
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
}

//------------------------------------------------------------------------------
// Address: 0x00526460
// Name: public: virtual bool CDmeUnpackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackColorOperator::IsA(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526490
// Name: public: virtual int CDmeUnpackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackColorOperator::GetInheritanceDepth(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526640
// Name: public: virtual bool CDmeUnpackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector2Operator::IsA(CDmeUnpackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526670
// Name: public: virtual int CDmeUnpackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector2Operator::GetInheritanceDepth(
        CDmeUnpackVector2Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526800
// Name: public: virtual bool CDmeUnpackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector3Operator::IsA(CDmeUnpackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526830
// Name: public: virtual int CDmeUnpackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector3Operator::GetInheritanceDepth(
        CDmeUnpackVector3Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526880
// Name: protected: virtual void CDmeUnpackQuaternionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQuaternionOperator::PerformDestruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00526A00
// Name: public: virtual bool CDmeUnpackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector4Operator::IsA(CDmeUnpackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526A30
// Name: public: virtual int CDmeUnpackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector4Operator::GetInheritanceDepth(
        CDmeUnpackVector4Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526B20
// Name: protected: virtual void CDmeUnpackVector4Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::PerformConstruction(CDmeUnpackVector4Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
  CDmeUnpackVector4Operator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00526BF0
// Name: public: virtual bool CDmeUnpackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQAngleOperator::IsA(CDmeUnpackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526C20
// Name: public: virtual int CDmeUnpackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQAngleOperator::GetInheritanceDepth(
        CDmeUnpackQAngleOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526DB0
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQuaternionOperator::IsA(CDmeUnpackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526DE0
// Name: public: virtual int CDmeUnpackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQuaternionOperator::GetInheritanceDepth(
        CDmeUnpackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526F60
// Name: protected: CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *__thiscall CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(
        CDmeUnpackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `CDmElement'};
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
// Address: 0x00527020
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVMatrixOperator::IsA(CDmeUnpackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527050
// Name: public: virtual int CDmeUnpackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVMatrixOperator::GetInheritanceDepth(
        CDmeUnpackVMatrixOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005270F0
// Name: protected: virtual void CDmeUnpackVMatrixOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::PerformConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
  CDmePackVMatrixOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057C860
// Name: _dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C8C0
// Name: _dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C920
// Name: _dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C980
// Name: _dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C9E0
// Name: _dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CA40
// Name: _dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CAA0
// Name: _dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EFF0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F000
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F010
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F020
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F030
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F040
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F050
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C890
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C8A0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackColorOperator_Helper,
           classname: "DmeUnpackColorOperator",
           pFactory: &g_CDmeUnpackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C8F0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C900
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector2Operator_Helper,
           classname: "DmeUnpackVector2Operator",
           pFactory: &g_CDmeUnpackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C950
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C960
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector3Operator_Helper,
           classname: "DmeUnpackVector3Operator",
           pFactory: &g_CDmeUnpackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C9B0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C9C0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector4Operator_Helper,
           classname: "DmeUnpackVector4Operator",
           pFactory: &g_CDmeUnpackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CA10
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CA20
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQAngleOperator_Helper,
           classname: "DmeUnpackQAngleOperator",
           pFactory: &g_CDmeUnpackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CA70
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CA80
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQuaternionOperator_Helper,
           classname: "DmeUnpackQuaternionOperator",
           pFactory: &g_CDmeUnpackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CAD0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CAE0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVMatrixOperator_Helper,
           classname: "DmeUnpackVMatrixOperator",
           pFactory: &g_CDmeUnpackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F060
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F070
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F080
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F090
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F0A0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F0B0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F0C0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackColorOperator_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DDD10
// Name: protected: virtual void CDmeUnpackQuaternionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQuaternionOperator::PerformDestruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005E18F0
// Name: protected: void CDmeUnpackVector2Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::OnConstruction(CDmeUnpackVector2Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR2,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x005E1960
// Name: protected: void CDmeUnpackVector3Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::OnConstruction(CDmeUnpackVector3Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x005E1D10
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeUnpackQuaternionOperator::IsDirty(CDmeUnpackQuaternionOperator *this)
{
  return this->m_quaternion.m_Storage.x != this->m_x.m_Storage
      || this->m_quaternion.m_Storage.y != this->m_y.m_Storage
      || this->m_quaternion.m_Storage.z != this->m_z.m_Storage
      || this->m_quaternion.m_Storage.w != this->m_w.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005E1E10
// Name: public: virtual void CDmeUnpackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_x.m_pAttribute;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_y.m_pAttribute;
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
  v20 = (int)attrs[1].m_pMemory;
  v21 = attrs->m_nAllocationCount;
  v22 = this->m_w.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v20 - v21 + 1);
  ++attrs[1].m_pMemory;
  v23 = (CDmAttribute **)attrs->m_pMemory;
  v24 = (int)attrs[1].m_pMemory - v20 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = (CDmAttribute **)&attrs->m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x005E2D10
// Name: protected: virtual void CDmeUnpackVMatrixOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::PerformConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
  CDmePackVMatrixOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005E2D30
// Name: protected: void CDmeUnpackVector4Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::OnConstruction(CDmeUnpackVector4Operator *this)
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
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR4,
                                  pMemory: &this->m_vector);
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
// Address: 0x005E2DD0
// Name: protected: void CDmeUnpackQAngleOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::OnConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_qangle.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "qangle",
                                  type: AT_QANGLE,
                                  pMemory: &this->m_qangle);
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
}

//------------------------------------------------------------------------------
// Address: 0x005E2EF0
// Name: public: virtual void CDmeUnpackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::Operate(CDmeUnpackVMatrixOperator *this)
{
  VMatrix *p_v; // esi
  CDmAttribute **p_m_pAttribute; // edi
  int i; // ebx
  VMatrix v; // [esp+Ch] [ebp-44h] BYREF
  CDmeUnpackVMatrixOperator *v5; // [esp+4Ch] [ebp-4h]

  v5 = this;
  p_v = &v;
  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( i = 16; i != 0; --i )
  {
    CDmAttribute::SetValue<float>(this: *p_m_pAttribute, value: (const float *)p_v);
    p_v = (VMatrix *)((char *)p_v + 16);
    p_m_pAttribute += 2;
  }
  CDmAttribute::SetValue<VMatrix>(this: v5->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x005E2F40
// Name: public: virtual void CDmeUnpackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::Operate(CDmeUnpackColorOperator *this)
{
  float v2; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  CDmAttribute *v6; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (float)this->m_color.m_Storage._color[0] * 0.0039062654;
  m_pAttribute = this->m_red.m_pAttribute;
  value = v2;
  CDmAttribute::SetValue<float>(this: m_pAttribute, &value);
  v4 = this->m_green.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[1] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v4, &value);
  v5 = this->m_blue.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[2] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v5, &value);
  v6 = this->m_alpha.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[3] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E2FE0
// Name: public: virtual void CDmeUnpackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::Operate(CDmeUnpackVector2Operator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_vector.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_vector.m_Storage.y);
}

//------------------------------------------------------------------------------
// Address: 0x005E3000
// Name: public: virtual void CDmeUnpackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::Operate(CDmeUnpackQAngleOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_qangle.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_qangle.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_qangle.m_Storage.z);
}

//------------------------------------------------------------------------------
// Address: 0x005E3030
// Name: public: virtual void CDmeUnpackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::Operate(CDmeUnpackQuaternionOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_quaternion.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_quaternion.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_quaternion.m_Storage.z);
  CDmAttribute::SetValue<float>(this: this->m_w.m_pAttribute, value: &this->m_quaternion.m_Storage.w);
}

//------------------------------------------------------------------------------
// Address: 0x005E3070
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeUnpackVMatrixOperator::IsDirty(CDmeUnpackVMatrixOperator *this)
{
  CDmaVar<VMatrix> *p_m_vmatrix; // esi
  unsigned int v2; // edx
  CDmaVar<float> *i; // ecx

  p_m_vmatrix = &this->m_vmatrix;
  v2 = 0;
  for ( i = this->m_cells; p_m_vmatrix->m_Storage.m[0][0] == i->m_Storage; ++i )
  {
    ++v2;
    p_m_vmatrix = (CDmaVar<VMatrix> *)((char *)p_m_vmatrix + 16);
    if ( v2 >= 0x10 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E30B0
// Name: public: virtual void CDmeUnpackColorOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_red.m_pAttribute;
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
  v8 = (int)attrs[1].m_pMemory;
  v9 = attrs->m_nAllocationCount;
  v10 = this->m_green.m_pAttribute;
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
  v14 = (int)attrs[1].m_pMemory;
  v15 = attrs->m_nAllocationCount;
  v16 = this->m_blue.m_pAttribute;
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
  v20 = (int)attrs[1].m_pMemory;
  v21 = attrs->m_nAllocationCount;
  v22 = this->m_alpha.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v20 - v21 + 1);
  ++attrs[1].m_pMemory;
  v23 = (CDmAttribute **)attrs->m_pMemory;
  v24 = (int)attrs[1].m_pMemory - v20 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = (CDmAttribute **)&attrs->m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x005E3270
// Name: public: virtual void CDmeUnpackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v5; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]

  m_pMemory = (int)attrs[1].m_pMemory;
  m_pAttribute = this->m_x.m_pAttribute;
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
  v10 = this->m_y.m_pAttribute;
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
}

//------------------------------------------------------------------------------
// Address: 0x005E3620
// Name: public: virtual bool CDmeUnpackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackColorOperator::IsA(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3650
// Name: public: virtual int CDmeUnpackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackColorOperator::GetInheritanceDepth(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E37E0
// Name: public: virtual bool CDmeUnpackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector2Operator::IsA(CDmeUnpackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3810
// Name: public: virtual int CDmeUnpackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector2Operator::GetInheritanceDepth(
        CDmeUnpackVector2Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E39B0
// Name: public: virtual bool CDmeUnpackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector3Operator::IsA(CDmeUnpackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E39E0
// Name: public: virtual int CDmeUnpackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector3Operator::GetInheritanceDepth(
        CDmeUnpackVector3Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3B70
// Name: public: virtual bool CDmeUnpackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector4Operator::IsA(CDmeUnpackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3BA0
// Name: public: virtual int CDmeUnpackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector4Operator::GetInheritanceDepth(
        CDmeUnpackVector4Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3C90
// Name: protected: virtual void CDmeUnpackVector4Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::PerformConstruction(CDmeUnpackVector4Operator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
  CDmeUnpackVector4Operator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005E3D60
// Name: public: virtual bool CDmeUnpackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQAngleOperator::IsA(CDmeUnpackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3D90
// Name: public: virtual int CDmeUnpackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQAngleOperator::GetInheritanceDepth(
        CDmeUnpackQAngleOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3E70
// Name: protected: virtual void CDmeUnpackQAngleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::PerformConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
  CDmeUnpackQAngleOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005E3F40
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQuaternionOperator::IsA(CDmeUnpackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E3F70
// Name: public: virtual int CDmeUnpackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQuaternionOperator::GetInheritanceDepth(
        CDmeUnpackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E40F0
// Name: protected: CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *__thiscall CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(
        CDmeUnpackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `CDmElement'};
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
// Address: 0x005E41B0
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVMatrixOperator::IsA(CDmeUnpackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E41E0
// Name: public: virtual int CDmeUnpackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVMatrixOperator::GetInheritanceDepth(
        CDmeUnpackVMatrixOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006B19B0
// Name: _dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1A10
// Name: _dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1A70
// Name: _dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1AD0
// Name: _dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1B30
// Name: _dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1B90
// Name: _dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1BF0
// Name: _dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B57E0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B57F0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5800
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5810
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5820
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5830
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5840
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B19E0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B19F0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackColorOperator_Helper,
           classname: "DmeUnpackColorOperator",
           pFactory: &g_CDmeUnpackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1A40
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1A50
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector2Operator_Helper,
           classname: "DmeUnpackVector2Operator",
           pFactory: &g_CDmeUnpackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1AA0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1AB0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector3Operator_Helper,
           classname: "DmeUnpackVector3Operator",
           pFactory: &g_CDmeUnpackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1B00
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1B10
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector4Operator_Helper,
           classname: "DmeUnpackVector4Operator",
           pFactory: &g_CDmeUnpackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1B60
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1B70
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQAngleOperator_Helper,
           classname: "DmeUnpackQAngleOperator",
           pFactory: &g_CDmeUnpackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1BC0
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1BD0
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQuaternionOperator_Helper,
           classname: "DmeUnpackQuaternionOperator",
           pFactory: &g_CDmeUnpackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1C20
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1C30
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVMatrixOperator_Helper,
           classname: "DmeUnpackVMatrixOperator",
           pFactory: &g_CDmeUnpackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5850
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5860
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5870
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5880
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5890
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B58A0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B58B0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeUnpackColorOperator_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005258A0
// Name: protected: void CDmeUnpackVector2Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::OnConstruction(CDmeUnpackVector2Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR2,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x00525910
// Name: protected: void CDmeUnpackVector3Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::OnConstruction(CDmeUnpackVector3Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x00525C10
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeUnpackQuaternionOperator::IsDirty(CDmeUnpackQuaternionOperator *this)
{
  return this->m_quaternion.m_Storage.x != this->m_x.m_Storage
      || this->m_quaternion.m_Storage.y != this->m_y.m_Storage
      || this->m_quaternion.m_Storage.z != this->m_z.m_Storage
      || this->m_quaternion.m_Storage.w != this->m_w.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00525D60
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeUnpackVMatrixOperator::IsDirty(CDmeUnpackVMatrixOperator *this)
{
  CDmaVar<VMatrix> *p_m_vmatrix; // esi
  unsigned int v2; // edx
  CDmaVar<float> *i; // ecx

  p_m_vmatrix = &this->m_vmatrix;
  v2 = 0;
  for ( i = this->m_cells; p_m_vmatrix->m_Storage.m[0][0] == i->m_Storage; ++i )
  {
    ++v2;
    p_m_vmatrix = (CDmaVar<VMatrix> *)((char *)p_m_vmatrix + 16);
    if ( v2 >= 0x10 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00526D80
// Name: protected: virtual void CDmeUnpackVMatrixOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::PerformConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
  CDmePackVMatrixOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00526DA0
// Name: protected: void CDmeUnpackVector4Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::OnConstruction(CDmeUnpackVector4Operator *this)
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
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR4,
                                  pMemory: &this->m_vector);
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
// Address: 0x00526E40
// Name: protected: void CDmeUnpackQAngleOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::OnConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_qangle.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "qangle",
                                  type: AT_QANGLE,
                                  pMemory: &this->m_qangle);
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
}

//------------------------------------------------------------------------------
// Address: 0x00526EC0
// Name: public: virtual void CDmeUnpackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::Operate(CDmeUnpackVMatrixOperator *this)
{
  VMatrix *p_v; // esi
  CDmAttribute **p_m_pAttribute; // edi
  int i; // ebx
  VMatrix v; // [esp+Ch] [ebp-44h] BYREF
  CDmeUnpackVMatrixOperator *v5; // [esp+4Ch] [ebp-4h]

  v5 = this;
  p_v = &v;
  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( i = 16; i != 0; --i )
  {
    CDmAttribute::SetValue<float>(this: *p_m_pAttribute, value: (const float *)p_v);
    p_v = (VMatrix *)((char *)p_v + 16);
    p_m_pAttribute += 2;
  }
  CDmAttribute::SetValue<VMatrix>(this: v5->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x00526FB0
// Name: public: virtual void CDmeUnpackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::Operate(CDmeUnpackColorOperator *this)
{
  float v2; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  CDmAttribute *v6; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (float)this->m_color.m_Storage._color[0] * 0.0039062654;
  m_pAttribute = this->m_red.m_pAttribute;
  value = v2;
  CDmAttribute::SetValue<float>(this: m_pAttribute, &value);
  v4 = this->m_green.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[1] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v4, &value);
  v5 = this->m_blue.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[2] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v5, &value);
  v6 = this->m_alpha.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[3] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00527070
// Name: public: virtual void CDmeUnpackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::Operate(CDmeUnpackQuaternionOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_quaternion.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_quaternion.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_quaternion.m_Storage.z);
  CDmAttribute::SetValue<float>(this: this->m_w.m_pAttribute, value: &this->m_quaternion.m_Storage.w);
}

//------------------------------------------------------------------------------
// Address: 0x005270B0
// Name: public: virtual void CDmeUnpackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::Operate(CDmeUnpackQAngleOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_qangle.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_qangle.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_qangle.m_Storage.z);
}

//------------------------------------------------------------------------------
// Address: 0x005270E0
// Name: public: virtual void CDmeUnpackColorOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_red.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_green.m_pAttribute;
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
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_blue.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_alpha.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x00527240
// Name: public: virtual void CDmeUnpackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
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
  v10 = this->m_y.m_pAttribute;
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
}

//------------------------------------------------------------------------------
// Address: 0x00527300
// Name: public: virtual void CDmeUnpackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_x.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_y.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_w.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x005275F0
// Name: public: virtual bool CDmeUnpackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackColorOperator::IsA(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527620
// Name: public: virtual int CDmeUnpackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackColorOperator::GetInheritanceDepth(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527670
// Name: protected: virtual void CDmeUnpackQuaternionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQuaternionOperator::PerformDestruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005277E0
// Name: public: virtual bool CDmeUnpackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector2Operator::IsA(CDmeUnpackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527810
// Name: public: virtual int CDmeUnpackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector2Operator::GetInheritanceDepth(
        CDmeUnpackVector2Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005279A0
// Name: public: virtual bool CDmeUnpackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector3Operator::IsA(CDmeUnpackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005279D0
// Name: public: virtual int CDmeUnpackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector3Operator::GetInheritanceDepth(
        CDmeUnpackVector3Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527B60
// Name: public: virtual bool CDmeUnpackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector4Operator::IsA(CDmeUnpackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527B90
// Name: public: virtual int CDmeUnpackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector4Operator::GetInheritanceDepth(
        CDmeUnpackVector4Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527C90
// Name: protected: virtual void CDmeUnpackVector4Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::PerformConstruction(CDmeUnpackVector4Operator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
  CDmeUnpackVector4Operator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00527D60
// Name: public: virtual bool CDmeUnpackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQAngleOperator::IsA(CDmeUnpackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527D90
// Name: public: virtual int CDmeUnpackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQAngleOperator::GetInheritanceDepth(
        CDmeUnpackQAngleOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527E70
// Name: protected: virtual void CDmeUnpackQAngleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::PerformConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
  CDmeUnpackQAngleOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00527F40
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQuaternionOperator::IsA(CDmeUnpackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527F70
// Name: public: virtual int CDmeUnpackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQuaternionOperator::GetInheritanceDepth(
        CDmeUnpackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005280D0
// Name: protected: CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *__thiscall CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(
        CDmeUnpackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `CDmElement'};
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
// Address: 0x00528190
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVMatrixOperator::IsA(CDmeUnpackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005281C0
// Name: public: virtual int CDmeUnpackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVMatrixOperator::GetInheritanceDepth(
        CDmeUnpackVMatrixOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0057E830
// Name: _dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E890
// Name: _dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E8F0
// Name: _dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E950
// Name: _dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E9B0
// Name: _dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA10
// Name: _dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA70
// Name: _dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580FD0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580FE0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580FF0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00581000
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00581010
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00581020
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00581030
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E860
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E870
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackColorOperator_Helper,
           classname: "DmeUnpackColorOperator",
           pFactory: &g_CDmeUnpackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E8C0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E8D0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector2Operator_Helper,
           classname: "DmeUnpackVector2Operator",
           pFactory: &g_CDmeUnpackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E920
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E930
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector3Operator_Helper,
           classname: "DmeUnpackVector3Operator",
           pFactory: &g_CDmeUnpackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E980
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E990
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector4Operator_Helper,
           classname: "DmeUnpackVector4Operator",
           pFactory: &g_CDmeUnpackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E9E0
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E9F0
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQAngleOperator_Helper,
           classname: "DmeUnpackQAngleOperator",
           pFactory: &g_CDmeUnpackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA40
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EA50
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQuaternionOperator_Helper,
           classname: "DmeUnpackQuaternionOperator",
           pFactory: &g_CDmeUnpackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EAA0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EAB0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVMatrixOperator_Helper,
           classname: "DmeUnpackVMatrixOperator",
           pFactory: &g_CDmeUnpackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00581040
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581050
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581060
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581070
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581080
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581090
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005810A0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackColorOperator_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0052CE00
// Name: protected: void CDmeUnpackVector2Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::OnConstruction(CDmeUnpackVector2Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR2,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x0052CE70
// Name: protected: void CDmeUnpackVector3Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::OnConstruction(CDmeUnpackVector3Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x0052CEF0
// Name: protected: void CDmeUnpackQAngleOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::OnConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_qangle.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "qangle",
                                  type: AT_QANGLE,
                                  pMemory: &this->m_qangle);
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
}

//------------------------------------------------------------------------------
// Address: 0x0052D290
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeUnpackQuaternionOperator::IsDirty(CDmeUnpackQuaternionOperator *this)
{
  return this->m_quaternion.m_Storage.x != this->m_x.m_Storage
      || this->m_quaternion.m_Storage.y != this->m_y.m_Storage
      || this->m_quaternion.m_Storage.z != this->m_z.m_Storage
      || this->m_quaternion.m_Storage.w != this->m_w.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0052D320
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeUnpackVMatrixOperator::IsDirty(CDmeUnpackVMatrixOperator *this)
{
  CDmaVar<VMatrix> *p_m_vmatrix; // esi
  unsigned int v2; // edx
  CDmaVar<float> *i; // ecx

  p_m_vmatrix = &this->m_vmatrix;
  v2 = 0;
  for ( i = this->m_cells; p_m_vmatrix->m_Storage.m[0][0] == i->m_Storage; ++i )
  {
    ++v2;
    p_m_vmatrix = (CDmaVar<VMatrix> *)((char *)p_m_vmatrix + 16);
    if ( v2 >= 0x10 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0052D3D0
// Name: public: virtual void CDmeUnpackColorOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_red.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_green.m_pAttribute;
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
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_blue.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_alpha.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x0052DFC0
// Name: protected: virtual void CDmeUnpackQuaternionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQuaternionOperator::PerformDestruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0052E070
// Name: protected: virtual void CDmeUnpackQAngleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::PerformConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
  CDmeUnpackQAngleOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0052E480
// Name: protected: void CDmeUnpackVector4Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::OnConstruction(CDmeUnpackVector4Operator *this)
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
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR4,
                                  pMemory: &this->m_vector);
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
// Address: 0x0052E5A0
// Name: public: virtual void CDmeUnpackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::Operate(CDmeUnpackVMatrixOperator *this)
{
  VMatrix *p_v; // esi
  CDmAttribute **p_m_pAttribute; // edi
  int i; // ebx
  VMatrix v; // [esp+Ch] [ebp-44h] BYREF
  CDmeUnpackVMatrixOperator *v5; // [esp+4Ch] [ebp-4h]

  v5 = this;
  p_v = &v;
  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( i = 16; i != 0; --i )
  {
    CDmAttribute::SetValue<float>(this: *p_m_pAttribute, value: (const float *)p_v);
    p_v = (VMatrix *)((char *)p_v + 16);
    p_m_pAttribute += 2;
  }
  CDmAttribute::SetValue<VMatrix>(this: v5->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0052E5F0
// Name: public: virtual void CDmeUnpackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::Operate(CDmeUnpackColorOperator *this)
{
  float v2; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  CDmAttribute *v6; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (float)this->m_color.m_Storage._color[0] * 0.0039062654;
  m_pAttribute = this->m_red.m_pAttribute;
  value = v2;
  CDmAttribute::SetValue<float>(this: m_pAttribute, &value);
  v4 = this->m_green.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[1] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v4, &value);
  v5 = this->m_blue.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[2] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v5, &value);
  v6 = this->m_alpha.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[3] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0052E690
// Name: public: virtual void CDmeUnpackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::Operate(CDmeUnpackVector2Operator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_vector.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_vector.m_Storage.y);
}

//------------------------------------------------------------------------------
// Address: 0x0052E6F0
// Name: public: virtual void CDmeUnpackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::Operate(CDmeUnpackQAngleOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_qangle.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_qangle.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_qangle.m_Storage.z);
}

//------------------------------------------------------------------------------
// Address: 0x0052E720
// Name: public: virtual void CDmeUnpackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::Operate(CDmeUnpackQuaternionOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_quaternion.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_quaternion.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_quaternion.m_Storage.z);
  CDmAttribute::SetValue<float>(this: this->m_w.m_pAttribute, value: &this->m_quaternion.m_Storage.w);
}

//------------------------------------------------------------------------------
// Address: 0x0052E760
// Name: public: virtual void CDmeUnpackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
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
  v10 = this->m_y.m_pAttribute;
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
}

//------------------------------------------------------------------------------
// Address: 0x0052E8E0
// Name: public: virtual void CDmeUnpackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_x.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_y.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_w.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x0052EB60
// Name: public: virtual bool CDmeUnpackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackColorOperator::IsA(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052EB90
// Name: public: virtual int CDmeUnpackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackColorOperator::GetInheritanceDepth(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052ED20
// Name: public: virtual bool CDmeUnpackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector2Operator::IsA(CDmeUnpackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052ED50
// Name: public: virtual int CDmeUnpackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector2Operator::GetInheritanceDepth(
        CDmeUnpackVector2Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052EEE0
// Name: public: virtual bool CDmeUnpackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector3Operator::IsA(CDmeUnpackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052EF10
// Name: public: virtual int CDmeUnpackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector3Operator::GetInheritanceDepth(
        CDmeUnpackVector3Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F0A0
// Name: public: virtual bool CDmeUnpackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector4Operator::IsA(CDmeUnpackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F0D0
// Name: public: virtual int CDmeUnpackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector4Operator::GetInheritanceDepth(
        CDmeUnpackVector4Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F1C0
// Name: protected: virtual void CDmeUnpackVector4Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::PerformConstruction(CDmeUnpackVector4Operator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
  CDmeUnpackVector4Operator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0052F290
// Name: public: virtual bool CDmeUnpackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQAngleOperator::IsA(CDmeUnpackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F2C0
// Name: public: virtual int CDmeUnpackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQAngleOperator::GetInheritanceDepth(
        CDmeUnpackQAngleOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F450
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQuaternionOperator::IsA(CDmeUnpackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F480
// Name: public: virtual int CDmeUnpackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQuaternionOperator::GetInheritanceDepth(
        CDmeUnpackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F5E0
// Name: protected: CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *__thiscall CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(
        CDmeUnpackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `CDmElement'};
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
// Address: 0x0052F6A0
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVMatrixOperator::IsA(CDmeUnpackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F6D0
// Name: public: virtual int CDmeUnpackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVMatrixOperator::GetInheritanceDepth(
        CDmeUnpackVMatrixOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F780
// Name: protected: virtual void CDmeUnpackVMatrixOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::PerformConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
  CDmePackVMatrixOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057C080
// Name: _dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackColorOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0E0
// Name: _dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector2Operator::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C140
// Name: _dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector3Operator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1A0
// Name: _dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector4Operator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C200
// Name: _dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQAngleOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C260
// Name: _dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQuaternionOperator::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2C0
// Name: _dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVMatrixOperator::s_Allocator,
    blockSize: 272,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E6C0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E6D0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E6E0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E6F0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E700
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E710
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E720
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0B0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C0C0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackColorOperator_Helper,
           classname: "DmeUnpackColorOperator",
           pFactory: &g_CDmeUnpackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C110
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C120
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector2Operator_Helper,
           classname: "DmeUnpackVector2Operator",
           pFactory: &g_CDmeUnpackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C170
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C180
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector3Operator_Helper,
           classname: "DmeUnpackVector3Operator",
           pFactory: &g_CDmeUnpackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1D0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1E0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector4Operator_Helper,
           classname: "DmeUnpackVector4Operator",
           pFactory: &g_CDmeUnpackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C230
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C240
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQAngleOperator_Helper,
           classname: "DmeUnpackQAngleOperator",
           pFactory: &g_CDmeUnpackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C290
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2A0
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQuaternionOperator_Helper,
           classname: "DmeUnpackQuaternionOperator",
           pFactory: &g_CDmeUnpackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2F0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C300
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVMatrixOperator_Helper,
           classname: "DmeUnpackVMatrixOperator",
           pFactory: &g_CDmeUnpackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E730
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E740
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E750
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E760
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E770
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E780
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E790
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeUnpackColorOperator_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062FDF0
// Name: protected: void CDmeUnpackVector3Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::OnConstruction(CDmeUnpackVector3Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x0062FE70
// Name: protected: void CDmeUnpackQAngleOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::OnConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_qangle.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "qangle",
                                  type: AT_QANGLE,
                                  pMemory: &this->m_qangle);
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
}

//------------------------------------------------------------------------------
// Address: 0x006301D0
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeUnpackQuaternionOperator::IsDirty(CDmeUnpackQuaternionOperator *this)
{
  return this->m_quaternion.m_Storage.x != this->m_x.m_Storage
      || this->m_quaternion.m_Storage.y != this->m_y.m_Storage
      || this->m_quaternion.m_Storage.z != this->m_z.m_Storage
      || this->m_quaternion.m_Storage.w != this->m_w.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x006302E0
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeUnpackVMatrixOperator::IsDirty(CDmeUnpackVMatrixOperator *this)
{
  CDmaVar<VMatrix> *p_m_vmatrix; // esi
  unsigned int v2; // edx
  CDmaVar<float> *i; // ecx

  p_m_vmatrix = &this->m_vmatrix;
  v2 = 0;
  for ( i = this->m_cells; p_m_vmatrix->m_Storage.m[0][0] == i->m_Storage; ++i )
  {
    ++v2;
    p_m_vmatrix = (CDmaVar<VMatrix> *)((char *)p_m_vmatrix + 16);
    if ( v2 >= 0x10 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00630390
// Name: public: virtual void CDmeUnpackColorOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::GetOutputAttributes(
        CDmeUnpackColorOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_red.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_green.m_pAttribute;
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
  v14 = attrs->m_Size;
  v15 = attrs->m_Memory.m_nAllocationCount;
  v16 = this->m_blue.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_alpha.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x006304F0
// Name: public: virtual void CDmeUnpackVector2Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::GetOutputAttributes(
        CDmeUnpackVector2Operator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  CDmAttribute *m_pAttribute; // [esp+Ch] [ebp-4h]

  m_Size = attrs->m_Size;
  m_pAttribute = this->m_x.m_pAttribute;
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
  v10 = this->m_y.m_pAttribute;
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
}

//------------------------------------------------------------------------------
// Address: 0x006308F0
// Name: protected: virtual void CDmeUnpackQuaternionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQuaternionOperator::PerformDestruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00631100
// Name: protected: virtual void CDmeUnpackQAngleOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackQAngleOperator::PerformConstruction(CDmeUnpackQAngleOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
  CDmeUnpackQAngleOperator::OnConstruction(this: (CDmeUnpackQAngleOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00631510
// Name: protected: virtual void CDmeUnpackVMatrixOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::PerformConstruction(CDmeUnpackVMatrixOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
  CDmePackVMatrixOperator::OnConstruction(this: (CDmeUnpackVMatrixOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00631530
// Name: protected: void CDmeUnpackVector2Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::OnConstruction(CDmeUnpackVector2Operator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR2,
                                  pMemory: &this->m_vector);
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
}

//------------------------------------------------------------------------------
// Address: 0x006315A0
// Name: protected: void CDmeUnpackVector4Operator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::OnConstruction(CDmeUnpackVector4Operator *this)
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
  this->m_vector.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this: v2,
                                  pAttributeName: "vector",
                                  type: AT_VECTOR4,
                                  pMemory: &this->m_vector);
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
// Address: 0x00631640
// Name: public: virtual void CDmeUnpackVMatrixOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVMatrixOperator::Operate(CDmeUnpackVMatrixOperator *this)
{
  VMatrix *p_v; // esi
  CDmAttribute **p_m_pAttribute; // edi
  int i; // ebx
  VMatrix v; // [esp+Ch] [ebp-44h] BYREF
  CDmeUnpackVMatrixOperator *v5; // [esp+4Ch] [ebp-4h]

  v5 = this;
  p_v = &v;
  p_m_pAttribute = &this->m_cells[0].m_pAttribute;
  for ( i = 16; i != 0; --i )
  {
    CDmAttribute::SetValue<float>(this: *p_m_pAttribute, value: (float *)p_v);
    p_v = (VMatrix *)((char *)p_v + 16);
    p_m_pAttribute += 2;
  }
  CDmAttribute::SetValue<VMatrix>(this: v5->m_vmatrix.m_pAttribute, value: &v);
}

//------------------------------------------------------------------------------
// Address: 0x00631690
// Name: public: virtual void CDmeUnpackColorOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackColorOperator::Operate(CDmeUnpackColorOperator *this)
{
  float v2; // xmm0_4
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  CDmAttribute *v6; // ecx
  float value; // [esp+4h] [ebp-4h] BYREF

  v2 = (float)this->m_color.m_Storage._color[0] * 0.0039062654;
  m_pAttribute = this->m_red.m_pAttribute;
  value = v2;
  CDmAttribute::SetValue<float>(this: m_pAttribute, &value);
  v4 = this->m_green.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[1] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v4, &value);
  v5 = this->m_blue.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[2] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v5, &value);
  v6 = this->m_alpha.m_pAttribute;
  value = (float)this->m_color.m_Storage._color[3] * 0.0039062654;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00631760
// Name: public: virtual void CDmeUnpackVector2Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector2Operator::Operate(CDmeUnpackVector2Operator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_vector.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_vector.m_Storage.y);
}

//------------------------------------------------------------------------------
// Address: 0x006317C0
// Name: public: virtual void CDmeUnpackVector3Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector3Operator::Operate(CDmeUnpackQAngleOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_qangle.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_qangle.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_qangle.m_Storage.z);
}

//------------------------------------------------------------------------------
// Address: 0x006317F0
// Name: public: virtual void CDmeUnpackVector4Operator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::Operate(CDmeUnpackQuaternionOperator *this)
{
  CDmAttribute::SetValue<float>(this: this->m_x.m_pAttribute, value: &this->m_quaternion.m_Storage.x);
  CDmAttribute::SetValue<float>(this: this->m_y.m_pAttribute, value: &this->m_quaternion.m_Storage.y);
  CDmAttribute::SetValue<float>(this: this->m_z.m_pAttribute, value: &this->m_quaternion.m_Storage.z);
  CDmAttribute::SetValue<float>(this: this->m_w.m_pAttribute, value: &this->m_quaternion.m_Storage.w);
}

//------------------------------------------------------------------------------
// Address: 0x006319A0
// Name: public: virtual void CDmeUnpackVector4Operator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::GetOutputAttributes(
        CDmeUnpackQuaternionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmAttribute *m_pAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmAttribute **v7; // eax
  int v8; // edi
  int v9; // eax
  CDmAttribute *v10; // ebx
  CDmAttribute **v11; // ecx
  int v12; // eax
  CDmAttribute **v13; // eax
  int v14; // edi
  int v15; // eax
  CDmAttribute *v16; // ebx
  CDmAttribute **v17; // ecx
  int v18; // eax
  CDmAttribute **v19; // eax
  int v20; // edi
  int v21; // eax
  CDmAttribute *v22; // ebx
  CDmAttribute **v23; // ecx
  int v24; // eax
  CDmAttribute **v25; // eax

  m_pAttribute = this->m_x.m_pAttribute;
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
  v8 = attrs->m_Size;
  v9 = attrs->m_Memory.m_nAllocationCount;
  v10 = this->m_y.m_pAttribute;
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
  v20 = attrs->m_Size;
  v21 = attrs->m_Memory.m_nAllocationCount;
  v22 = this->m_w.m_pAttribute;
  if ( v20 + 1 > v21 )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v20 - v21 + 1);
  ++attrs->m_Size;
  v23 = attrs->m_Memory.m_pMemory;
  v24 = attrs->m_Size - v20 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[v20 + 1], src: &v23[v20], count: 4 * v24);
  v25 = &attrs->m_Memory.m_pMemory[v20];
  if ( v25 != nullptr )
    *v25 = v22;
}

//------------------------------------------------------------------------------
// Address: 0x00631BB0
// Name: public: virtual bool CDmeUnpackColorOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackColorOperator::IsA(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631BE0
// Name: public: virtual int CDmeUnpackColorOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackColorOperator::GetInheritanceDepth(CDmeUnpackColorOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackColorOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631D70
// Name: public: virtual bool CDmeUnpackVector2Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector2Operator::IsA(CDmeUnpackVector2Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631DA0
// Name: public: virtual int CDmeUnpackVector2Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector2Operator::GetInheritanceDepth(
        CDmeUnpackVector2Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector2Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631F50
// Name: public: virtual bool CDmeUnpackVector3Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector3Operator::IsA(CDmeUnpackVector3Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00631F80
// Name: public: virtual int CDmeUnpackVector3Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector3Operator::GetInheritanceDepth(
        CDmeUnpackVector3Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector3Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00632110
// Name: public: virtual bool CDmeUnpackVector4Operator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVector4Operator::IsA(CDmeUnpackVector4Operator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00632140
// Name: public: virtual int CDmeUnpackVector4Operator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVector4Operator::GetInheritanceDepth(
        CDmeUnpackVector4Operator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVector4Operator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00632230
// Name: protected: virtual void CDmeUnpackVector4Operator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeUnpackVector4Operator::PerformConstruction(CDmeUnpackVector4Operator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
  CDmeUnpackVector4Operator::OnConstruction(this: (CDmeUnpackVector4Operator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x00632300
// Name: public: virtual bool CDmeUnpackQAngleOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQAngleOperator::IsA(CDmeUnpackQAngleOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00632330
// Name: public: virtual int CDmeUnpackQAngleOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQAngleOperator::GetInheritanceDepth(
        CDmeUnpackQAngleOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQAngleOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006324C0
// Name: public: virtual bool CDmeUnpackQuaternionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackQuaternionOperator::IsA(CDmeUnpackQuaternionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x006324F0
// Name: public: virtual int CDmeUnpackQuaternionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackQuaternionOperator::GetInheritanceDepth(
        CDmeUnpackQuaternionOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackQuaternionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00632690
// Name: protected: CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *__thiscall CDmeUnpackVMatrixOperator::CDmeUnpackVMatrixOperator(
        CDmeUnpackVMatrixOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmaVar<float> *m_cells; // eax
  int i; // ecx

  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeUnpackVMatrixOperator_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeUnpackVMatrixOperator::`vftable'{for `CDmElement'};
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
// Address: 0x00632750
// Name: public: virtual bool CDmeUnpackVMatrixOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeUnpackVMatrixOperator::IsA(CDmeUnpackVMatrixOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00632780
// Name: public: virtual int CDmeUnpackVMatrixOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeUnpackVMatrixOperator::GetInheritanceDepth(
        CDmeUnpackVMatrixOperator *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeUnpackVMatrixOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006B9FF0
// Name: _dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackColorOperator::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackColorOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA050
// Name: _dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector2Operator::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector2Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA0B0
// Name: _dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector3Operator::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector3Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA110
// Name: _dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVector4Operator::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVector4Operator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA170
// Name: _dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQAngleOperator::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQAngleOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA1D0
// Name: _dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackQuaternionOperator::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackQuaternionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA230
// Name: _dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeUnpackVMatrixOperator::s_Allocator,
    blockSize: 0x110u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeUnpackVMatrixOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD4E0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackColorOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackColorOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD4F0
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector2Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector2Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD500
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector3Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector3Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD510
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVector4Operator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVector4Operator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD520
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQAngleOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQAngleOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD530
// Name: _dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackQuaternionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackQuaternionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD540
// Name: _dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeUnpackVMatrixOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeUnpackVMatrixOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BA020
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackColorOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA030
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackColorOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackColorOperator_Helper,
           classname: "DmeUnpackColorOperator",
           pFactory: &g_CDmeUnpackColorOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BA080
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector2Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA090
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector2Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector2Operator_Helper,
           classname: "DmeUnpackVector2Operator",
           pFactory: &g_CDmeUnpackVector2Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BA0E0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector3Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA0F0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector3Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector3Operator_Helper,
           classname: "DmeUnpackVector3Operator",
           pFactory: &g_CDmeUnpackVector3Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BA140
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVector4Operator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA150
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVector4Operator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVector4Operator_Helper,
           classname: "DmeUnpackVector4Operator",
           pFactory: &g_CDmeUnpackVector4Operator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BA1A0
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA1B0
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQAngleOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQAngleOperator_Helper,
           classname: "DmeUnpackQAngleOperator",
           pFactory: &g_CDmeUnpackQAngleOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BA200
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA210
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackQuaternionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackQuaternionOperator_Helper,
           classname: "DmeUnpackQuaternionOperator",
           pFactory: &g_CDmeUnpackQuaternionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BA260
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA270
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeUnpackVMatrixOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeUnpackVMatrixOperator_Helper,
           classname: "DmeUnpackVMatrixOperator",
           pFactory: &g_CDmeUnpackVMatrixOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD550
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector2Operator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeUnpackVector2Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD560
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector3Operator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeUnpackVector3Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD570
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVector4Operator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeUnpackVector4Operator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD580
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQAngleOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeUnpackQAngleOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD590
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackQuaternionOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeUnpackQuaternionOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD5A0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackVMatrixOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeUnpackVMatrixOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD5B0
// Name: _dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeUnpackColorOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeUnpackColorOperator_Factory.m_CallBackList);
}

} // namespace vmap
