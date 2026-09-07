// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmevertexdata.cpp
// Functions: 61
// ============================================================

#include "movieobjects\dmevertexdata.h"

//------------------------------------------------------------------------------
// Address: 0x00496B90
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x00496C00
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x00496D10
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496D80
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00496E00
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00496E90
// Name: public: void CDmeVertexDataBase::SetVertexData(int,int,int,enum DmAttributeType_t,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexData(
        CDmeVertexDataBase *this,
        CDmrGenericArray nFieldIndex,
        int nFirstVertex,
        int nCount,
        DmAttributeType_t valueType,
        const void *pData)
{
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::SetMultiple(this: &nFieldIndex, i: nFirstVertex, nCount, valueType, pValue: pData);
}

//------------------------------------------------------------------------------
// Address: 0x00496ED0
// Name: public: int CDmeVertexDataBase::FindFieldIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::FindFieldIndex(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  CDmeVertexDataBase *v7; // [esp+Ch] [ebp-4h]

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  v7 = this;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_FieldInfo.m_Memory.m_pMemory[i].m_Name);
    if ( _V_stricmp(s1: v5, s2: pFieldName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    this = v7;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00497110
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004971B0
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x00497220
// Name: private: float CDmeVertexDeltaData::ComputeMaxDeflection(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CDmeVertexDeltaData::ComputeMaxDeflection@<st0>(CDmeVertexDeltaData *this@<ecx>, int a2@<ebp>)
{
  int v2; // eax
  float v3; // xmm3_4
  CDmAttribute *m_pVertexData; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v5; // eax
  int m_Size; // ecx
  float *p_x; // eax
  __int128 v8; // xmm0
  _QWORD v10[2]; // [esp-20h] [ebp-2Ch] BYREF
  float v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a2;
  v13 = retaddr;
  v2 = this->m_pStandardFieldIndex[0];
  v3 = 0.0;
  v11 = 0.0;
  if ( v2 < 0 || v2 >= this->m_FieldInfo.m_Size )
  {
    v5 = &s_EmptyVector;
  }
  else
  {
    m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v10[1]);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v10[1],
      pAttribute: m_pVertexData);
    v5 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)v10[1];
    v3 = v11;
  }
  m_Size = v5->m_Size;
  if ( m_Size > 0 )
  {
    p_x = &v5->m_Memory.m_pMemory->x;
    do
    {
      v8 = 0;
      *(float *)&v8 = fsqrt((float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])) + (float)(p_x[2] * p_x[2]));
      *(_OWORD *)v10 = v8;
      if ( *(float *)&v8 > v3 )
      {
        v3 = *(float *)v10;
        v11 = *(float *)v10;
      }
      p_x += 3;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x004972F0
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00497380
// Name: protected: void CDmeVertexDataBase::FindOrAddVertexField(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::FindOrAddVertexField(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v4; // esi
  const char *m_pAsString; // eax

  m_Size = this->m_VertexFormat.m_Storage.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFieldName, a3: pFieldName);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
      this: &this->m_VertexFormat,
      src: (const CUtlSymbolLarge *)&pFieldName);
  }
  else
  {
    while ( 1 )
    {
      m_pAsString = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[v4].u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      if ( _V_stricmp(s1: pFieldName, s2: m_pAsString) == 0 )
        break;
      if ( ++v4 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004973F0
// Name: public: int CDmeVertexDataBase::AddVertexData(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::AddVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex, int nCount)
{
  CDmrGenericArray v4; // edi
  int v5; // ebx
  CDmAttribute *v6; // edi
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v4.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  v5 = CDmrGenericArrayConst::Count(this: &nFieldIndex);
  nCount += v5;
  CDmrGenericArray::EnsureCount(this: &nFieldIndex, num: nCount);
  if ( this->IsVertexDeltaData(this) )
  {
    v6 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v4.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: v6);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(this: &indices, num: nCount);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00497470
// Name: public: void CDmeVertexDataBase::SetVertexIndices(int,int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexIndices(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nFirstIndex,
        int nCount,
        const int *pIndices)
{
  CDmAttribute *m_pIndexData; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-8h] BYREF

  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
    pAttribute: m_pIndexData);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &array,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x004974C0
// Name: public: void CDmeVertexDataBase::RemoveAllVertexData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::RemoveAllVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex)
{
  CDmrGenericArray v3; // edi
  CDmAttribute *v4; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+8h] [ebp-8h] BYREF

  v3.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::RemoveAll(this: &nFieldIndex);
  if ( this->IsVertexDeltaData(this) )
  {
    v4 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v3.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
      pAttribute: v4);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497520
// Name: public: char const __near * CDmeVertexDataBase::FieldName(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeVertexDataBase::FieldName(CDmeVertexDataBase *this, int i)
{
  const char *result; // eax

  if ( i < 0 || i >= this->m_VertexFormat.m_Storage.m_Size )
    return nullptr;
  result = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[i].u.m_pAsString;
  if ( result == (const char *)-1 )
    return var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00497550
// Name: public: int CDmeVertexData::AddVertexIndices(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::AddVertexIndices(CDmeVertexData *this, int nIndexCount)
{
  int m_nVertexCount; // ecx
  int m_Size; // eax
  int v5; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // eax
  bool v7; // zf
  CDmAttribute **p_m_pIndexData; // eax
  CDmAttribute *v9; // ebx
  CDmrArray<int> indices; // [esp+4h] [ebp-Ch] BYREF
  int v12; // [esp+Ch] [ebp-4h]
  int nIndexCounta; // [esp+18h] [ebp+8h]

  m_nVertexCount = this->m_nVertexCount;
  m_Size = this->m_FieldInfo.m_Size;
  v12 = m_nVertexCount;
  this->m_nVertexCount = m_nVertexCount + nIndexCount;
  if ( m_Size > 0 )
  {
    v5 = 0;
    for ( nIndexCounta = m_Size; nIndexCounta != 0; --nIndexCounta )
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      v7 = m_pMemory[v5].m_pIndexData == nullptr;
      p_m_pIndexData = &m_pMemory[v5].m_pIndexData;
      if ( !v7 )
      {
        v9 = *p_m_pIndexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
          pAttribute: v9);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
          this: &indices,
          num: this->m_nVertexCount);
        m_nVertexCount = v12;
      }
      ++v5;
    }
  }
  return m_nVertexCount;
}

//------------------------------------------------------------------------------
// Address: 0x004975D0
// Name: public: void CDmeVertexDataBase::CopyTo(class CDmeVertexDataBase __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::CopyTo(CDmeVertexDataBase *this, CDmeVertexDataBase *pDst)
{
  CDmeVertexDataBase *v2; // esi
  const char *m_pAsString; // eax
  const char *v5; // eax
  CUtlString dstName; // [esp+8h] [ebp-10h] BYREF

  v2 = pDst;
  m_pAsString = pDst->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  CUtlString::CUtlString(this: &dstName, pString: m_pAsString);
  CDmElement::CopyAttributesTo(this, pCopy: v2, depth: TD_DEEP);
  v5 = CUtlString::operator char const *(this: &dstName);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pDst, a3: v5);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v2->m_Name.m_pAttribute, value: (const CUtlSymbolLarge *)&pDst);
  v2->Resolve(this: v2);
  dstName.m_Storage.m_nActualLength = 0;
  if ( dstName.m_Storage.m_Memory.m_nGrowSize >= 0 && dstName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dstName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00497A20
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)var;
        s2 = (char *)var;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00497D20
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497D90
// Name: public: int CDmeVertexDataBase::CreateField(char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, char *pFieldName, DmAttributeType_t type)
{
  int v4; // edi
  void *v5; // esp
  int FieldIndex; // edi
  CDmAttribute *m_pIndexData; // ebx
  char v9[12]; // [esp+0h] [ebp-14h] BYREF
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  if ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[5]) == 0
    || _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[6]) == 0 )
  {
    return -1;
  }
  if ( CDmElement::FindAttribute(this, pAttributeName: pFieldName) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: pFieldName, type);
  v4 = _V_strlen(str: pFieldName) + 21;
  v5 = alloca(v4);
  V_snprintf(pDest: v9, maxLen: v4, pFormat: "%sIndices", pFieldName);
  if ( CDmElement::FindAttribute(this, pAttributeName: v9) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v9, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName);
  if ( !this->IsVertexDeltaData(this) && this->m_nVertexCount > 0 )
  {
    m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[FieldIndex].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: m_pIndexData);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
      this: &indices,
      num: this->m_nVertexCount);
  }
  return FieldIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00497EA0
// Name: public: int CDmeVertexDataBase::CreateField(enum CDmeVertexDataBase::StandardFields_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, CDmeVertexDataBase::StandardFields_t fieldId)
{
  return CDmeVertexDataBase::CreateField(
           this,
           pFieldName: g_pStandardFieldNames[fieldId],
           type: g_pStandardFieldTypes[fieldId]);
}

//------------------------------------------------------------------------------
// Address: 0x00497EC0
// Name: public: void CDmeVertexDataBase::CreateJointWeightsAndIndices(int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::CreateJointWeightsAndIndices(
        CDmeVertexDataBase *this,
        int nJointCount,
        int *pJointWeightsField,
        int *pJointIndicesField)
{
  const char *v5; // edi
  const char *v6; // edi
  int FieldIndex; // eax
  int v8; // eax

  CDmAttribute::SetValue<int>(this: this->m_nJointCount.m_pAttribute, value: &nJointCount);
  v5 = g_pStandardFieldNames[5];
  if ( CDmElement::FindAttribute(this, pAttributeName: g_pStandardFieldNames[5]) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v5, type: AT_FLOAT_ARRAY);
  v6 = g_pStandardFieldNames[6];
  if ( CDmElement::FindAttribute(this, pAttributeName: g_pStandardFieldNames[6]) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v6, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName: g_pStandardFieldNames[5]);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName: g_pStandardFieldNames[6]);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName: g_pStandardFieldNames[5]);
  *pJointWeightsField = FieldIndex;
  v8 = CDmeVertexDataBase::FindFieldIndex(this, pFieldName: g_pStandardFieldNames[6]);
  *pJointIndicesField = v8;
}

//------------------------------------------------------------------------------
// Address: 0x00497F70
// Name: public: void CDmeVertexDeltaData::GenerateWrinkleDelta(class CDmeVertexData __near *,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeVertexDeltaData::GenerateWrinkleDelta(
        CDmeVertexDeltaData *this@<ecx>,
        int a2@<ebp>,
        __int64 a3@<esi:edi>,
        CDmeVertexData *pBindState,
        float flScale,
        bool bOverwrite,
        bool bUseNormalForSign)
{
  int v8; // eax
  int v9; // esi
  double v10; // st7
  void *v11; // esp
  int m_Size; // eax
  float *v13; // eax
  __int128 v14; // xmm0
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndicesFromDataIndex; // edx
  int v16; // eax
  int v17; // ecx
  CDmAttribute *v18; // eax
  int *m_pMemory; // edx
  Vector *v20; // eax
  int v21; // esi
  float *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  int *v26; // eax
  float v27; // xmm2_4
  __int128 v28; // xmm0
  const CUtlVector<int,CUtlMemory<int,int> > *v29; // edx
  int v30; // eax
  int v31; // ecx
  int v32; // esi
  _QWORD v33[4]; // [esp-A0h] [ebp-ACh] BYREF
  CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > v34; // [esp-80h] [ebp-8Ch] BYREF
  double v35; // [esp-78h] [ebp-84h]
  Vector v36; // [esp-70h] [ebp-7Ch] BYREF
  Vector v37; // [esp-64h] [ebp-70h] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *NormalData; // [esp-58h] [ebp-64h]
  const CUtlVector<int,CUtlMemory<int,int> > *v39; // [esp-54h] [ebp-60h]
  const CUtlVector<int,CUtlMemory<int,int> > *v40; // [esp-50h] [ebp-5Ch]
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > v41; // [esp-4Ch] [ebp-58h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndexData; // [esp-44h] [ebp-50h]
  CDmrGenericArray v43; // [esp-40h] [ebp-4Ch] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v44; // [esp-3Ch] [ebp-48h]
  int v45; // [esp-38h] [ebp-44h] BYREF
  CDmAttribute *m_pIndexData; // [esp-34h] [ebp-40h]
  CDmrGenericArray v47; // [esp-30h] [ebp-3Ch] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // [esp-2Ch] [ebp-38h]
  CDmrGenericArray v49; // [esp-28h] [ebp-34h] BYREF
  int v50; // [esp-24h] [ebp-30h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v51; // [esp-20h] [ebp-2Ch]
  int Field; // [esp-1Ch] [ebp-28h]
  float v53; // [esp-18h] [ebp-24h]
  int v54; // [esp-14h] [ebp-20h]
  int v55; // [esp-10h] [ebp-1Ch]
  _BYTE *v56; // [esp-Ch] [ebp-18h]
  int v57; // [esp-8h] [ebp-14h]
  int v58; // [esp-4h] [ebp-10h]
  int nDeltaIndex; // [esp+0h] [ebp-Ch] BYREF
  int nNormalIndex; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  nDeltaIndex = a2;
  nNormalIndex = retaddr;
  v33[0] = a3;
  v51 = (const CUtlVector<int,CUtlMemory<int,int> > *)this->m_pStandardFieldIndex[0];
  if ( (int)v51 >= 0 )
  {
    v54 = pBindState->m_pStandardFieldIndex[3];
    if ( v54 >= 0 )
    {
      v8 = pBindState->m_pStandardFieldIndex[1];
      v57 = v8;
      if ( !bUseNormalForSign || v8 >= 0 )
      {
        v9 = this->m_pStandardFieldIndex[9];
        Field = v9;
        if ( v9 >= 0 )
        {
          if ( !bOverwrite )
            return;
        }
        else
        {
          Field = CDmeVertexDataBase::CreateField(
                    this,
                    pFieldName: g_pStandardFieldNames[9],
                    type: g_pStandardFieldTypes[9]);
          v9 = Field;
        }
        CDmeVertexDataBase::RemoveAllVertexData(this, nFieldIndex: (CDmrGenericArray)v9);
        if ( flScale != 0.0 )
        {
          v10 = CDmeVertexDeltaData::ComputeMaxDeflection(this, a2: (int)&nDeltaIndex);
          v53 = v10;
          if ( v10 != 0.0 )
          {
            v35 = (float)(flScale / v53);
            VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this, nFieldIndex: (int)v51);
            PositionData = CDmeVertexDataBase::GetPositionData(this);
            v51 = CDmeVertexDataBase::GetVertexIndexData(this: pBindState, nFieldIndex: v54);
            v53 = *(float *)&pBindState->m_FieldInfo.m_Memory.m_pMemory[v54].m_pVertexData;
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v34);
            CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
              this: &v34,
              pAttribute: (CDmAttribute *)LODWORD(v53));
            v58 = (v34.m_pStorage->m_Size + 7) >> 3;
            v11 = alloca(v58);
            v53 = COERCE_FLOAT(v33);
            memset(dst: (unsigned __int8 *)v33, value: 0, count: v58);
            m_Size = PositionData->m_Size;
            v54 = m_Size;
            if ( bUseNormalForSign )
            {
              v40 = CDmeVertexDataBase::GetVertexIndexData(this: pBindState, nFieldIndex: v57);
              NormalData = CDmeVertexDataBase::GetNormalData(this: pBindState);
              v55 = 0;
              if ( v54 > 0 )
              {
                v57 = 0;
                do
                {
                  v13 = (float *)((char *)&PositionData->m_Memory.m_pMemory->x + v57);
                  v14 = 0;
                  *(float *)&v14 = fsqrt((float)((float)(*v13 * *v13) + (float)(v13[1] * v13[1])) + (float)(v13[2] * v13[2]));
                  *(_OWORD *)&v33[2] = v14;
                  *(float *)&v14 = *(float *)&v14 * v35;
                  v45 = v14;
                  v49.m_pAttribute = (CDmAttribute *)(v14 ^ _mask__NegFloat_);
                  v36 = *(Vector *)v13;
                  VectorNormalize(vec: &v36);
                  VertexIndicesFromDataIndex = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                                 this: pBindState,
                                                 nFieldIndex: pBindState->m_pStandardFieldIndex[0],
                                                 nDataIndex: VertexIndexData->m_Memory.m_pMemory[v55]);
                  v16 = VertexIndicesFromDataIndex->m_Size;
                  v17 = 0;
                  v39 = VertexIndicesFromDataIndex;
                  v44 = (const CUtlVector<int,CUtlMemory<int,int> > *)v16;
                  v58 = 0;
                  if ( v16 > 0 )
                  {
                    while ( 1 )
                    {
                      v18 = (CDmAttribute *)&VertexIndicesFromDataIndex->m_Memory.m_pMemory[v17];
                      m_pMemory = v51->m_Memory.m_pMemory;
                      m_pIndexData = v18;
                      v50 = m_pMemory[(int)v18->m_pNext];
                      v56 = (_BYTE *)(LODWORD(v53) + (v50 >> 3));
                      if ( ((unsigned __int8)(1 << (v50 & 7)) & *v56) == 0 )
                      {
                        *v56 |= 1 << (v50 & 7);
                        v20 = &NormalData->m_Memory.m_pMemory[v40->m_Memory.m_pMemory[(int)m_pIndexData->m_pNext]];
                        v37 = *v20;
                        VectorNormalize(vec: &v37);
                        v56 = (_BYTE *)CDmeVertexDataBase::AddVertexData(
                                         this,
                                         nFieldIndex: (CDmrGenericArray)v9,
                                         nCount: 1);
                        v21 = v9;
                        m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pIndexData;
                        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v41);
                        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
                          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v41,
                          pAttribute: m_pIndexData);
                        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
                          this: &v41,
                          i: (int)v56,
                          nCount: 1,
                          pValue: &v50);
                        if ( (float)((float)((float)(v37.y * v36.y) + (float)(v37.x * v36.x)) + (float)(v36.z * v37.z)) >= 0.0 )
                        {
                          CDmrGenericArray::CDmrGenericArray(
                            this: &v43,
                            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pVertexData);
                          CDmrGenericArray::SetMultiple(
                            this: &v43,
                            i: (int)v56,
                            nCount: 1,
                            valueType: AT_FLOAT,
                            pValue: &v45);
                        }
                        else
                        {
                          CDmrGenericArray::CDmrGenericArray(
                            this: &v47,
                            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pVertexData);
                          CDmrGenericArray::SetMultiple(
                            this: &v47,
                            i: (int)v56,
                            nCount: 1,
                            valueType: AT_FLOAT,
                            pValue: &v49);
                        }
                        v9 = Field;
                      }
                      v17 = v58 + 1;
                      v58 = v17;
                      if ( v17 >= (int)v44 )
                        break;
                      VertexIndicesFromDataIndex = v39;
                    }
                  }
                  v57 += 12;
                  ++v55;
                }
                while ( v55 < v54 );
              }
            }
            else
            {
              v57 = 0;
              if ( m_Size > 0 )
              {
                v55 = 0;
                do
                {
                  v22 = (float *)((char *)&PositionData->m_Memory.m_pMemory->x + v55);
                  v23 = v22[2];
                  v24 = v22[1];
                  v25 = *v22;
                  v26 = VertexIndexData->m_Memory.m_pMemory;
                  v27 = (float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v23 * v23);
                  v28 = 0;
                  *(float *)&v28 = fsqrt(v27);
                  *(_OWORD *)&v33[2] = v28;
                  *(float *)&v47.m_pAttribute = *(float *)&v28 * v35;
                  v29 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                          this: pBindState,
                          nFieldIndex: pBindState->m_pStandardFieldIndex[0],
                          nDataIndex: v26[v57]);
                  v30 = v29->m_Size;
                  v31 = 0;
                  v44 = v29;
                  v50 = v30;
                  v56 = nullptr;
                  if ( v30 > 0 )
                  {
                    while ( 1 )
                    {
                      v45 = v51->m_Memory.m_pMemory[v29->m_Memory.m_pMemory[v31]];
                      v58 = LODWORD(v53) + (v45 >> 3);
                      if ( ((unsigned __int8)(1 << (v45 & 7)) & *(_BYTE *)v58) == 0 )
                      {
                        *(_BYTE *)v58 |= 1 << (v45 & 7);
                        v58 = CDmeVertexDataBase::AddVertexData(this, nFieldIndex: (CDmrGenericArray)v9, nCount: 1);
                        v32 = v9;
                        v43.m_pAttribute = this->m_FieldInfo.m_Memory.m_pMemory[v32].m_pIndexData;
                        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v41);
                        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
                          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v41,
                          pAttribute: v43.m_pAttribute);
                        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
                          this: &v41,
                          i: v58,
                          nCount: 1,
                          pValue: &v45);
                        CDmrGenericArray::CDmrGenericArray(
                          this: &v49,
                          pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v32].m_pVertexData);
                        CDmrGenericArray::SetMultiple(this: &v49, i: v58, nCount: 1, valueType: AT_FLOAT, pValue: &v47);
                        v9 = Field;
                      }
                      v31 = (int)(v56 + 1);
                      v56 = (_BYTE *)v31;
                      if ( v31 >= v50 )
                        break;
                      v29 = v44;
                    }
                  }
                  v55 += 12;
                  ++v57;
                }
                while ( v57 < v54 );
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00498490
// Name: public: void CDmeVertexDeltaData::UpdateWrinkleDelta(class CDmeVertexData __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeVertexDeltaData::UpdateWrinkleDelta(
        CDmeVertexDeltaData *this@<ecx>,
        __int64 a2@<esi:edi>,
        CDmeVertexData *pBindState,
        float flOldScale,
        float flScale)
{
  int v5; // ecx
  CDmAttribute *v6; // edi
  double dNewScale; // [esp+14h] [ebp-10h]
  CDmrArray<float> wrinkleData; // [esp+1Ch] [ebp-8h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  HIDWORD(a2) = this;
  v5 = this->m_pStandardFieldIndex[9];
  if ( v5 < 0 || flOldScale == 0.0 || flScale == 0.0 )
  {
    CDmeVertexDeltaData::GenerateWrinkleDelta(
      this: (CDmeVertexDeltaData *)HIDWORD(a2),
      a2: (int)&savedregs,
      a3: a2,
      pBindState,
      flScale,
      bOverwrite: true,
      bUseNormalForSign: false);
  }
  else
  {
    v6 = *(CDmAttribute **)(*(_DWORD *)(HIDWORD(a2) + 108) + 48 * v5 + 16);
    if ( v6 != nullptr )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&wrinkleData);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&wrinkleData,
        pAttribute: v6);
      LODWORD(a2) = wrinkleData.m_pStorage->m_Size;
      if ( (int)a2 <= 0 )
        CDmeVertexDeltaData::GenerateWrinkleDelta(
          this: (CDmeVertexDeltaData *)HIDWORD(a2),
          a2: (int)&savedregs,
          a3: a2,
          pBindState,
          flScale,
          bOverwrite: true,
          bUseNormalForSign: false);
      HIDWORD(a2) = 0;
      dNewScale = (float)(flScale / flOldScale);
      if ( (int)a2 > 0 )
      {
        do
        {
          flScale = wrinkleData.m_pStorage->m_Memory.m_pMemory[HIDWORD(a2)] * dNewScale;
          CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
            this: &wrinkleData,
            i: SHIDWORD(a2),
            value: &flScale);
          ++HIDWORD(a2);
        }
        while ( SHIDWORD(a2) < (int)a2 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004985F0
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00498620
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00498670
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004986C0
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004986F0
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00498780
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00498800
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00498830
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00498890
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x005AB620
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB6E0
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB740
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF880
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AF890
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AF8A0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AB650
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB660
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AB680
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB690
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB6A0
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB6B0
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB6C0
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB6D0
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB710
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB720
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AB770
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB780
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AF8B0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x005AF8C0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x005AF8D0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x005AF8E0
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x005AF8F0
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x005AF900
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x005AF910
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AF920
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AF930
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004F9470
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x004F94E0
// Name: public: bool CDmeVertexDataBase::NeedsTangentData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeVertexDataBase::NeedsTangentData(CDmeVertexDataBase *this)
{
  return this->m_pStandardFieldIndex[0] >= 0
      && this->m_pStandardFieldIndex[3] >= 0
      && this->m_pStandardFieldIndex[1] >= 0
      && this->m_pStandardFieldIndex[2] < 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F9510
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x004F9580
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F95F0
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x004F9670
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x004F9700
// Name: public: void CDmeVertexDataBase::SetVertexData(int,int,int,enum DmAttributeType_t,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexData(
        CDmeVertexDataBase *this,
        CDmrGenericArray nFieldIndex,
        int nFirstVertex,
        int nCount,
        DmAttributeType_t valueType,
        const void *pData)
{
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::SetMultiple(this: &nFieldIndex, i: nFirstVertex, nCount, valueType, pValue: pData);
}

//------------------------------------------------------------------------------
// Address: 0x004F9740
// Name: public: int CDmeVertexDataBase::FindFieldIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::FindFieldIndex(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  CDmeVertexDataBase *v7; // [esp+Ch] [ebp-4h]

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  v7 = this;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_FieldInfo.m_Memory.m_pMemory[i].m_Name);
    if ( _V_stricmp(s1: v5, s2: pFieldName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    this = v7;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004F9930
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F99D0
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x004F9A40
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x004F9AD0
// Name: public: class Vector2D const __near & CDmeVertexDataBase::GetTexCoord(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector2D *__thiscall CDmeVertexDataBase::GetTexCoord(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector2D> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[3];
  if ( v3 < 0 )
    return &vec2_origin_116;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x004F9B50
// Name: protected: void CDmeVertexDataBase::FindOrAddVertexField(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::FindOrAddVertexField(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v4; // esi
  const char *m_pAsString; // eax

  m_Size = this->m_VertexFormat.m_Storage.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFieldName, a3: pFieldName);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
      this: &this->m_VertexFormat,
      src: (vgui::PageTab **)&pFieldName);
  }
  else
  {
    while ( 1 )
    {
      m_pAsString = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[v4].u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_stricmp(s1: pFieldName, s2: m_pAsString) == 0 )
        break;
      if ( ++v4 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F9BC0
// Name: public: int CDmeVertexDataBase::AddVertexData(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::AddVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex, int nCount)
{
  CDmrGenericArray v4; // edi
  int v5; // ebx
  CDmAttribute *v6; // edi
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v4.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  v5 = CDmrGenericArrayConst::Count(this: &nFieldIndex);
  nCount += v5;
  CDmrGenericArray::EnsureCount(this: &nFieldIndex, num: nCount);
  if ( this->IsVertexDeltaData(this) )
  {
    v6 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v4.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: v6);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(this: &indices, num: nCount);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004F9C40
// Name: public: void CDmeVertexDataBase::SetVertexIndices(int,int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexIndices(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nFirstIndex,
        int nCount,
        const int *pIndices)
{
  CDmAttribute *m_pIndexData; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-8h] BYREF

  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
    pAttribute: m_pIndexData);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &array,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x004F9C90
// Name: public: void CDmeVertexDataBase::RemoveAllVertexData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::RemoveAllVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex)
{
  CDmrGenericArray v3; // edi
  CDmAttribute *v4; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+8h] [ebp-8h] BYREF

  v3.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::RemoveAll(this: &nFieldIndex);
  if ( this->IsVertexDeltaData(this) )
  {
    v4 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v3.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
      pAttribute: v4);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA090
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)defaultValue;
        s2 = (char *)defaultValue;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004FA390
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA400
// Name: public: int CDmeVertexDataBase::CreateField(char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, char *pFieldName, DmAttributeType_t type)
{
  int v4; // edi
  void *v5; // esp
  int FieldIndex; // edi
  CDmAttribute *m_pIndexData; // ebx
  char v9[12]; // [esp+0h] [ebp-14h] BYREF
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  if ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[5]) == 0
    || _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[6]) == 0 )
  {
    return -1;
  }
  if ( CDmElement::FindAttribute(this, pAttributeName: pFieldName) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: pFieldName, type);
  v4 = _V_strlen(str: pFieldName) + 21;
  v5 = alloca(v4);
  V_snprintf(pDest: v9, maxLen: v4, pFormat: "%sIndices", pFieldName);
  if ( CDmElement::FindAttribute(this, pAttributeName: v9) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v9, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName);
  if ( !this->IsVertexDeltaData(this) && this->m_nVertexCount > 0 )
  {
    m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[FieldIndex].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: m_pIndexData);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
      this: &indices,
      num: this->m_nVertexCount);
  }
  return FieldIndex;
}

//------------------------------------------------------------------------------
// Address: 0x004FA570
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FA5A0
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FA630
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FA660
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FA6B0
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004FA700
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004FA780
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FA7B0
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FA810
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067CE60
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CF20
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CF80
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681DA0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00681DB0
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00681DC0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067CE90
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CEA0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067CEC0
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CED0
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CEE0
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CEF0
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CF00
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CF10
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CF50
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CF60
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067CFB0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CFC0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00681DD0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x00681DE0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x00681DF0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x00681E00
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x00681E10
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x00681E20
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x00681E30
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00681E40
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00681E50
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10598710
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x10598780
// Name: public: bool CDmeVertexDataBase::NeedsTangentData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeVertexDataBase::NeedsTangentData(CDmeVertexDataBase *this)
{
  return this->m_pStandardFieldIndex[0] >= 0
      && this->m_pStandardFieldIndex[3] >= 0
      && this->m_pStandardFieldIndex[1] >= 0
      && this->m_pStandardFieldIndex[2] < 0;
}

//------------------------------------------------------------------------------
// Address: 0x105987B0
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x10598820
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10598890
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x10598910
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x105989A0
// Name: public: void CDmeVertexDataBase::SetVertexData(int,int,int,enum DmAttributeType_t,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexData(
        CDmeVertexDataBase *this,
        CDmrGenericArray nFieldIndex,
        int nFirstVertex,
        int nCount,
        DmAttributeType_t valueType,
        const void *pData)
{
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::SetMultiple(this: &nFieldIndex, i: nFirstVertex, nCount, valueType, pValue: pData);
}

//------------------------------------------------------------------------------
// Address: 0x105989E0
// Name: public: int CDmeVertexDataBase::FindFieldIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::FindFieldIndex(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  CDmeVertexDataBase *v7; // [esp+Ch] [ebp-4h]

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  v7 = this;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_FieldInfo.m_Memory.m_pMemory[i].m_Name);
    if ( _V_stricmp(s1: v5, s2: pFieldName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    this = v7;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10598BD0
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10598C70
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x10598CE0
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x10598D70
// Name: public: class Vector2D const __near & CDmeVertexDataBase::GetTexCoord(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector2D *__thiscall CDmeVertexDataBase::GetTexCoord(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector2D> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[3];
  if ( v3 < 0 )
    return &vec2_origin_511;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x10598DF0
// Name: protected: void CDmeVertexDataBase::FindOrAddVertexField(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::FindOrAddVertexField(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v4; // esi
  const char *m_pAsString; // eax

  m_Size = this->m_VertexFormat.m_Storage.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFieldName, a3: pFieldName);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
      this: &this->m_VertexFormat,
      src: (vgui::PageTab *const *)&pFieldName);
  }
  else
  {
    while ( 1 )
    {
      m_pAsString = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[v4].u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      if ( _V_stricmp(s1: pFieldName, s2: m_pAsString) == 0 )
        break;
      if ( ++v4 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10598E60
// Name: public: int CDmeVertexDataBase::AddVertexData(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::AddVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex, int nCount)
{
  CDmrGenericArray v4; // edi
  int v5; // ebx
  CDmAttribute *v6; // edi
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v4.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  v5 = CDmrGenericArrayConst::Count(this: &nFieldIndex);
  nCount += v5;
  CDmrGenericArray::EnsureCount(this: &nFieldIndex, num: nCount);
  if ( this->IsVertexDeltaData(this) )
  {
    v6 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v4.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: v6);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(this: &indices, num: nCount);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10598EE0
// Name: public: void CDmeVertexDataBase::SetVertexIndices(int,int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexIndices(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nFirstIndex,
        int nCount,
        const int *pIndices)
{
  CDmAttribute *m_pIndexData; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-8h] BYREF

  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
    pAttribute: m_pIndexData);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &array,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x10598F30
// Name: public: void CDmeVertexDataBase::RemoveAllVertexData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::RemoveAllVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex)
{
  CDmrGenericArray v3; // edi
  CDmAttribute *v4; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+8h] [ebp-8h] BYREF

  v3.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::RemoveAll(this: &nFieldIndex);
  if ( this->IsVertexDeltaData(this) )
  {
    v4 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v3.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
      pAttribute: v4);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10599320
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  signed int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)&var;
        s2 = (char *)&var;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(std::char_traits<char>::length(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: &indicesName.m_Memory, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&indicesName.m_Memory.m_pMemory[v28 + v11],
              src: (unsigned __int8 *)&indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (unsigned int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10599620
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10599690
// Name: public: int CDmeVertexDataBase::CreateField(char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, char *pFieldName, DmAttributeType_t type)
{
  unsigned int v4; // edi
  void *v5; // esp
  int FieldIndex; // edi
  CDmAttribute *m_pIndexData; // ebx
  char v9[12]; // [esp+0h] [ebp-14h] BYREF
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  if ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[5]) == 0
    || _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[6]) == 0 )
  {
    return -1;
  }
  if ( CDmElement::FindAttribute(this, pAttributeName: pFieldName) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: pFieldName, type);
  v4 = std::char_traits<char>::length(str: pFieldName) + 21;
  v5 = alloca(v4);
  V_snprintf(pDest: v9, maxLen: v4, pFormat: "%sIndices", pFieldName);
  if ( CDmElement::FindAttribute(this, pAttributeName: v9) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v9, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName);
  if ( !this->IsVertexDeltaData(this) && this->m_nVertexCount > 0 )
  {
    m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[FieldIndex].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: m_pIndexData);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
      this: &indices,
      num: this->m_nVertexCount);
  }
  return FieldIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10599800
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10599830
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x105998B0
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x105998E0
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10599940
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x10599990
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10599A10
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10599A40
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10599AA0
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C9A80
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 0xB0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9B40
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 0xB0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9BA0
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 0xC0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB90
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDBA0
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDBB0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9AB0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9AC0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9AE0
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9AF0
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9B00
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9B10
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9B20
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9B30
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9B70
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9B80
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9BD0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9BE0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDBC0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x105CDBD0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x105CDBE0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x105CDBF0
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC00
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC10
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC20
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC30
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC40
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004AE9F0
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x004AEA60
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x004AEAD0
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AEB40
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x004AEBC0
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x004AEDE0
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004AEE80
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x004AEEF0
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x004AF310
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)WindowName;
        s2 = (char *)WindowName;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004AF610
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AF6E0
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AF710
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AF790
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AF7C0
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AF810
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004AF860
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004AF8E0
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AF910
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AF960
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059A880
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A940
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A9A0
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA80
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA90
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EAA0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A8B0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A8C0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A8E0
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A8F0
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A900
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A910
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A920
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A930
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A970
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A980
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A9D0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A9E0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EAB0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x0059EAC0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x0059EAD0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x0059EAE0
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x0059EAF0
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x0059EB00
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x0059EB10
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EB20
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EB30
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x00509960
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x005099D0
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x00509A40
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00509AB0
// Name: public: int CDmeVertexDataBase::GetPositionIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetPositionIndex(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[0];
  if ( v2 < 0 )
    return -1;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage->m_Memory.m_pMemory[nVertexIndex].m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x00509B00
// Name: public: int CDmeVertexDataBase::GetNormalIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetNormalIndex(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[1];
  if ( v2 < 0 )
    return -1;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage->m_Memory.m_pMemory[nVertexIndex].m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x00509B50
// Name: public: int CDmeVertexDataBase::GetTexCoordIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetTexCoordIndex(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[3];
  if ( v2 < 0 )
    return -1;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage->m_Memory.m_pMemory[nVertexIndex].m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x00509BA0
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00509C20
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00509CB0
// Name: public: void CDmeVertexDataBase::SetVertexData(int,int,int,enum DmAttributeType_t,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexData(
        CDmeVertexDataBase *this,
        CDmrGenericArray nFieldIndex,
        int nFirstVertex,
        int nCount,
        DmAttributeType_t valueType,
        const void *pData)
{
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::SetMultiple(this: &nFieldIndex, i: nFirstVertex, nCount, valueType, pValue: pData);
}

//------------------------------------------------------------------------------
// Address: 0x00509CF0
// Name: public: int CDmeVertexDataBase::FindFieldIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::FindFieldIndex(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  CDmeVertexDataBase *v7; // [esp+Ch] [ebp-4h]

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  v7 = this;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_FieldInfo.m_Memory.m_pMemory[i].m_Name);
    if ( _V_stricmp(s1: v5, s2: pFieldName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    this = v7;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00509E90
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndexData(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndexData(CDmeVertexDataBase *this, int nDataIndex)
{
  int v3; // eax
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+4h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v3 >= this->m_FieldInfo.m_Size )
    return nullptr;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[nDataIndex * this->m_nJointCount.m_Storage];
}

//------------------------------------------------------------------------------
// Address: 0x0050A080
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0050A120
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x0050A190
// Name: private: float CDmeVertexDeltaData::ComputeMaxDeflection(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CDmeVertexDeltaData::ComputeMaxDeflection@<st0>(CDmeVertexDeltaData *this@<ecx>, int a2@<ebp>)
{
  int v2; // eax
  float v3; // xmm3_4
  CDmAttribute *m_pVertexData; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v5; // eax
  int m_Size; // ecx
  float *p_x; // eax
  __int128 v8; // xmm0
  _QWORD v10[2]; // [esp-20h] [ebp-2Ch] BYREF
  float v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a2;
  v13 = retaddr;
  v2 = this->m_pStandardFieldIndex[0];
  v3 = 0.0;
  v11 = 0.0;
  if ( v2 < 0 || v2 >= this->m_FieldInfo.m_Size )
  {
    v5 = &s_EmptyVector;
  }
  else
  {
    m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v10[1]);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v10[1],
      pAttribute: m_pVertexData);
    v5 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)v10[1];
    v3 = v11;
  }
  m_Size = v5->m_Size;
  if ( m_Size > 0 )
  {
    p_x = &v5->m_Memory.m_pMemory->x;
    do
    {
      v8 = 0;
      *(float *)&v8 = fsqrt((float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])) + (float)(p_x[2] * p_x[2]));
      *(_OWORD *)v10 = v8;
      if ( *(float *)&v8 > v3 )
      {
        v3 = *(float *)v10;
        v11 = *(float *)v10;
      }
      p_x += 3;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x0050A260
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x0050A2F0
// Name: protected: void CDmeVertexDataBase::FindOrAddVertexField(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::FindOrAddVertexField(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v4; // esi
  const char *m_pAsString; // eax

  m_Size = this->m_VertexFormat.m_Storage.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pFieldName,
      a3: pFieldName);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
      this: &this->m_VertexFormat,
      src: (const CUtlSymbolLarge *)&pFieldName);
  }
  else
  {
    while ( 1 )
    {
      m_pAsString = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[v4].u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      if ( _V_stricmp(s1: pFieldName, s2: m_pAsString) == 0 )
        break;
      if ( ++v4 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050A360
// Name: public: int CDmeVertexDataBase::AddVertexData(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::AddVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex, int nCount)
{
  CDmrGenericArray v4; // edi
  int v5; // ebx
  CDmAttribute *v6; // edi
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v4.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  v5 = CDmrGenericArrayConst::Count(this: &nFieldIndex);
  nCount += v5;
  CDmrGenericArray::EnsureCount(this: &nFieldIndex, num: nCount);
  if ( this->IsVertexDeltaData(this) )
  {
    v6 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v4.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: v6);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(this: &indices, num: nCount);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0050A3E0
// Name: public: void CDmeVertexDataBase::SetVertexIndices(int,int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexIndices(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nFirstIndex,
        int nCount,
        const int *pIndices)
{
  CDmAttribute *m_pIndexData; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-8h] BYREF

  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
    pAttribute: m_pIndexData);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &array,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x0050A430
// Name: public: void CDmeVertexDataBase::RemoveAllVertexData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::RemoveAllVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex)
{
  CDmrGenericArray v3; // edi
  CDmAttribute *v4; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+8h] [ebp-8h] BYREF

  v3.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::RemoveAll(this: &nFieldIndex);
  if ( this->IsVertexDeltaData(this) )
  {
    v4 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v3.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
      pAttribute: v4);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050A490
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeightData(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeightData(CDmeVertexDataBase *this, int nDataIndex)
{
  int v3; // eax
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+4h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v3 >= this->m_FieldInfo.m_Size )
    return nullptr;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[nDataIndex * this->m_nJointCount.m_Storage];
}

//------------------------------------------------------------------------------
// Address: 0x0050A8B0
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)pDeltaStateName;
        s2 = (char *)pDeltaStateName;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0050ABB0
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050AC20
// Name: public: int CDmeVertexDataBase::CreateField(char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, char *pFieldName, DmAttributeType_t type)
{
  int v4; // edi
  void *v5; // esp
  int FieldIndex; // edi
  CDmAttribute *m_pIndexData; // ebx
  char v9[12]; // [esp+0h] [ebp-14h] BYREF
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  if ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[5]) == 0
    || _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[6]) == 0 )
  {
    return -1;
  }
  if ( CDmElement::FindAttribute(this, pAttributeName: pFieldName) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: pFieldName, type);
  v4 = _V_strlen(str: pFieldName) + 21;
  v5 = alloca(v4);
  V_snprintf(pDest: v9, maxLen: v4, pFormat: "%sIndices", pFieldName);
  if ( CDmElement::FindAttribute(this, pAttributeName: v9) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v9, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName);
  if ( !this->IsVertexDeltaData(this) && this->m_nVertexCount > 0 )
  {
    m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[FieldIndex].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: m_pIndexData);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
      this: &indices,
      num: this->m_nVertexCount);
  }
  return FieldIndex;
}

//------------------------------------------------------------------------------
// Address: 0x0050AD30
// Name: public: int CDmeVertexDataBase::CreateField(enum CDmeVertexDataBase::StandardFields_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, CDmeVertexDataBase::StandardFields_t fieldId)
{
  return CDmeVertexDataBase::CreateField(
           this,
           pFieldName: g_pStandardFieldNames[fieldId],
           type: g_pStandardFieldTypes[fieldId]);
}

//------------------------------------------------------------------------------
// Address: 0x0050AD50
// Name: public: void CDmeVertexDeltaData::GenerateWrinkleDelta(class CDmeVertexData __near *,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeVertexDeltaData::GenerateWrinkleDelta(
        CDmeVertexDeltaData *this@<ecx>,
        int a2@<ebp>,
        __int64 a3@<esi:edi>,
        CDmeVertexData *pBindState,
        float flScale,
        bool bOverwrite,
        bool bUseNormalForSign)
{
  int v8; // eax
  int v9; // esi
  double v10; // st7
  void *v11; // esp
  int m_Size; // eax
  float *v13; // eax
  __int128 v14; // xmm0
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndicesFromDataIndex; // edx
  int v16; // eax
  int v17; // ecx
  CDmAttribute *v18; // eax
  int *m_pMemory; // edx
  Vector *v20; // eax
  int v21; // esi
  float *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  int *v26; // eax
  float v27; // xmm2_4
  __int128 v28; // xmm0
  const CUtlVector<int,CUtlMemory<int,int> > *v29; // edx
  int v30; // eax
  int v31; // ecx
  int v32; // esi
  _QWORD v33[4]; // [esp-A0h] [ebp-ACh] BYREF
  CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > v34; // [esp-80h] [ebp-8Ch] BYREF
  double v35; // [esp-78h] [ebp-84h]
  Vector v36; // [esp-70h] [ebp-7Ch] BYREF
  Vector v37; // [esp-64h] [ebp-70h] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *NormalData; // [esp-58h] [ebp-64h]
  const CUtlVector<int,CUtlMemory<int,int> > *v39; // [esp-54h] [ebp-60h]
  const CUtlVector<int,CUtlMemory<int,int> > *v40; // [esp-50h] [ebp-5Ch]
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > v41; // [esp-4Ch] [ebp-58h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndexData; // [esp-44h] [ebp-50h]
  CDmrGenericArray v43; // [esp-40h] [ebp-4Ch] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v44; // [esp-3Ch] [ebp-48h]
  int v45; // [esp-38h] [ebp-44h] BYREF
  CDmAttribute *m_pIndexData; // [esp-34h] [ebp-40h]
  CDmrGenericArray v47; // [esp-30h] [ebp-3Ch] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // [esp-2Ch] [ebp-38h]
  CDmrGenericArray v49; // [esp-28h] [ebp-34h] BYREF
  int v50; // [esp-24h] [ebp-30h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v51; // [esp-20h] [ebp-2Ch]
  int Field; // [esp-1Ch] [ebp-28h]
  float v53; // [esp-18h] [ebp-24h]
  int v54; // [esp-14h] [ebp-20h]
  int v55; // [esp-10h] [ebp-1Ch]
  _BYTE *v56; // [esp-Ch] [ebp-18h]
  int v57; // [esp-8h] [ebp-14h]
  int v58; // [esp-4h] [ebp-10h]
  int nDeltaIndex; // [esp+0h] [ebp-Ch] BYREF
  int nNormalIndex; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  nDeltaIndex = a2;
  nNormalIndex = retaddr;
  v33[0] = a3;
  v51 = (const CUtlVector<int,CUtlMemory<int,int> > *)this->m_pStandardFieldIndex[0];
  if ( (int)v51 >= 0 )
  {
    v54 = pBindState->m_pStandardFieldIndex[3];
    if ( v54 >= 0 )
    {
      v8 = pBindState->m_pStandardFieldIndex[1];
      v57 = v8;
      if ( !bUseNormalForSign || v8 >= 0 )
      {
        v9 = this->m_pStandardFieldIndex[9];
        Field = v9;
        if ( v9 >= 0 )
        {
          if ( !bOverwrite )
            return;
        }
        else
        {
          Field = CDmeVertexDataBase::CreateField(
                    this,
                    pFieldName: g_pStandardFieldNames[9],
                    type: g_pStandardFieldTypes[9]);
          v9 = Field;
        }
        CDmeVertexDataBase::RemoveAllVertexData(this, nFieldIndex: (CDmrGenericArray)v9);
        if ( flScale != 0.0 )
        {
          v10 = CDmeVertexDeltaData::ComputeMaxDeflection(this, a2: (int)&nDeltaIndex);
          v53 = v10;
          if ( v10 != 0.0 )
          {
            v35 = (float)(flScale / v53);
            VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this, nFieldIndex: (int)v51);
            PositionData = CDmeVertexDataBase::GetPositionData(this);
            v51 = CDmeVertexDataBase::GetVertexIndexData(this: pBindState, nFieldIndex: v54);
            v53 = *(float *)&pBindState->m_FieldInfo.m_Memory.m_pMemory[v54].m_pVertexData;
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v34);
            CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
              this: &v34,
              pAttribute: (CDmAttribute *)LODWORD(v53));
            v58 = (v34.m_pStorage->m_Size + 7) >> 3;
            v11 = alloca(v58);
            v53 = COERCE_FLOAT(v33);
            memset(dst: (unsigned __int8 *)v33, value: 0, count: v58);
            m_Size = PositionData->m_Size;
            v54 = m_Size;
            if ( bUseNormalForSign )
            {
              v40 = CDmeVertexDataBase::GetVertexIndexData(this: pBindState, nFieldIndex: v57);
              NormalData = CDmeVertexDataBase::GetNormalData(this: pBindState);
              v55 = 0;
              if ( v54 > 0 )
              {
                v57 = 0;
                do
                {
                  v13 = (float *)((char *)&PositionData->m_Memory.m_pMemory->x + v57);
                  v14 = 0;
                  *(float *)&v14 = fsqrt((float)((float)(*v13 * *v13) + (float)(v13[1] * v13[1])) + (float)(v13[2] * v13[2]));
                  *(_OWORD *)&v33[2] = v14;
                  *(float *)&v14 = *(float *)&v14 * v35;
                  v45 = v14;
                  v49.m_pAttribute = (CDmAttribute *)(v14 ^ _mask__NegFloat_);
                  v36 = *(Vector *)v13;
                  VectorNormalize(vec: &v36);
                  VertexIndicesFromDataIndex = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                                 this: pBindState,
                                                 nFieldIndex: pBindState->m_pStandardFieldIndex[0],
                                                 nDataIndex: VertexIndexData->m_Memory.m_pMemory[v55]);
                  v16 = VertexIndicesFromDataIndex->m_Size;
                  v17 = 0;
                  v39 = VertexIndicesFromDataIndex;
                  v44 = (const CUtlVector<int,CUtlMemory<int,int> > *)v16;
                  v58 = 0;
                  if ( v16 > 0 )
                  {
                    while ( 1 )
                    {
                      v18 = (CDmAttribute *)&VertexIndicesFromDataIndex->m_Memory.m_pMemory[v17];
                      m_pMemory = v51->m_Memory.m_pMemory;
                      m_pIndexData = v18;
                      v50 = m_pMemory[(int)v18->m_pNext];
                      v56 = (_BYTE *)(LODWORD(v53) + (v50 >> 3));
                      if ( ((unsigned __int8)(1 << (v50 & 7)) & *v56) == 0 )
                      {
                        *v56 |= 1 << (v50 & 7);
                        v20 = &NormalData->m_Memory.m_pMemory[v40->m_Memory.m_pMemory[(int)m_pIndexData->m_pNext]];
                        v37 = *v20;
                        VectorNormalize(vec: &v37);
                        v56 = (_BYTE *)CDmeVertexDataBase::AddVertexData(
                                         this,
                                         nFieldIndex: (CDmrGenericArray)v9,
                                         nCount: 1);
                        v21 = v9;
                        m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pIndexData;
                        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v41);
                        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
                          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v41,
                          pAttribute: m_pIndexData);
                        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
                          this: &v41,
                          i: (int)v56,
                          nCount: 1,
                          pValue: &v50);
                        if ( (float)((float)((float)(v37.y * v36.y) + (float)(v37.x * v36.x)) + (float)(v36.z * v37.z)) >= 0.0 )
                        {
                          CDmrGenericArray::CDmrGenericArray(
                            this: &v43,
                            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pVertexData);
                          CDmrGenericArray::SetMultiple(
                            this: &v43,
                            i: (int)v56,
                            nCount: 1,
                            valueType: AT_FLOAT,
                            pValue: &v45);
                        }
                        else
                        {
                          CDmrGenericArray::CDmrGenericArray(
                            this: &v47,
                            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pVertexData);
                          CDmrGenericArray::SetMultiple(
                            this: &v47,
                            i: (int)v56,
                            nCount: 1,
                            valueType: AT_FLOAT,
                            pValue: &v49);
                        }
                        v9 = Field;
                      }
                      v17 = v58 + 1;
                      v58 = v17;
                      if ( v17 >= (int)v44 )
                        break;
                      VertexIndicesFromDataIndex = v39;
                    }
                  }
                  v57 += 12;
                  ++v55;
                }
                while ( v55 < v54 );
              }
            }
            else
            {
              v57 = 0;
              if ( m_Size > 0 )
              {
                v55 = 0;
                do
                {
                  v22 = (float *)((char *)&PositionData->m_Memory.m_pMemory->x + v55);
                  v23 = v22[2];
                  v24 = v22[1];
                  v25 = *v22;
                  v26 = VertexIndexData->m_Memory.m_pMemory;
                  v27 = (float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v23 * v23);
                  v28 = 0;
                  *(float *)&v28 = fsqrt(v27);
                  *(_OWORD *)&v33[2] = v28;
                  *(float *)&v47.m_pAttribute = *(float *)&v28 * v35;
                  v29 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                          this: pBindState,
                          nFieldIndex: pBindState->m_pStandardFieldIndex[0],
                          nDataIndex: v26[v57]);
                  v30 = v29->m_Size;
                  v31 = 0;
                  v44 = v29;
                  v50 = v30;
                  v56 = nullptr;
                  if ( v30 > 0 )
                  {
                    while ( 1 )
                    {
                      v45 = v51->m_Memory.m_pMemory[v29->m_Memory.m_pMemory[v31]];
                      v58 = LODWORD(v53) + (v45 >> 3);
                      if ( ((unsigned __int8)(1 << (v45 & 7)) & *(_BYTE *)v58) == 0 )
                      {
                        *(_BYTE *)v58 |= 1 << (v45 & 7);
                        v58 = CDmeVertexDataBase::AddVertexData(this, nFieldIndex: (CDmrGenericArray)v9, nCount: 1);
                        v32 = v9;
                        v43.m_pAttribute = this->m_FieldInfo.m_Memory.m_pMemory[v32].m_pIndexData;
                        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v41);
                        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
                          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v41,
                          pAttribute: v43.m_pAttribute);
                        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
                          this: &v41,
                          i: v58,
                          nCount: 1,
                          pValue: &v45);
                        CDmrGenericArray::CDmrGenericArray(
                          this: &v49,
                          pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v32].m_pVertexData);
                        CDmrGenericArray::SetMultiple(this: &v49, i: v58, nCount: 1, valueType: AT_FLOAT, pValue: &v47);
                        v9 = Field;
                      }
                      v31 = (int)(v56 + 1);
                      v56 = (_BYTE *)v31;
                      if ( v31 >= v50 )
                        break;
                      v29 = v44;
                    }
                  }
                  v55 += 12;
                  ++v57;
                }
                while ( v57 < v54 );
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050B2D0
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B300
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B380
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B3B0
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B400
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050B450
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050B4D0
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B500
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B560
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EFF70
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0030
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0090
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F40E0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F40F0
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4100
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EFFA0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EFFB0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EFFD0
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x005EFFE0
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x005EFFF0
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0000
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0010
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0020
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0060
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0070
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F00C0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F00D0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4110
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x005F4120
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x005F4130
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x005F4140
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x005F4150
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x005F4160
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x005F4170
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4180
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4190
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004667D0
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x00466840
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x00466950
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004669C0
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00466A40
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00466C60
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00466D00
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x00466D70
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00467190
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)str;
        s2 = (char *)str;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00467490
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467560
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00467590
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00467610
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00467640
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00467690
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004676E0
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00467760
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00467790
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004677F0
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00569A40
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00569B00
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00569B60
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056DF80
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056DF90
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056DFA0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00569A70
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569A80
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00569AA0
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x00569AB0
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x00569AC0
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x00569AD0
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x00569AE0
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x00569AF0
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x00569B30
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569B40
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00569B90
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569BA0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056DFB0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x0056DFC0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x0056DFD0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x0056DFE0
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x0056DFF0
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x0056E000
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x0056E010
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E020
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E030
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00469C00
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x00469C70
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x00469CE0
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469D50
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00469DD0
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00469FF0
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046A090
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x0046A100
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x0046A520
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)&pParentName;
        s2 = (char *)&pParentName;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0046A820
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A8F0
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A920
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A9A0
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A9D0
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046AA20
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046AA70
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046AAF0
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046AB20
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046AB80
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00579B40
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579C00
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579C60
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0B0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0C0
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0D0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579B70
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579B80
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579BA0
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x00579BB0
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x00579BC0
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x00579BD0
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x00579BE0
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x00579BF0
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x00579C30
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579C40
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579C90
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579CA0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0E0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0F0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x0057E100
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x0057E110
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x0057E120
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x0057E130
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x0057E140
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E150
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E160
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005CE0D0
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x005CE140
// Name: public: bool CDmeVertexDataBase::NeedsTangentData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeVertexDataBase::NeedsTangentData(CDmeVertexDataBase *this)
{
  return this->m_pStandardFieldIndex[0] >= 0
      && this->m_pStandardFieldIndex[3] >= 0
      && this->m_pStandardFieldIndex[1] >= 0
      && this->m_pStandardFieldIndex[2] < 0;
}

//------------------------------------------------------------------------------
// Address: 0x005CE170
// Name: bool TempVertexLessFunc(struct TempVertex_t const __near &,struct TempVertex_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl TempVertexLessFunc(const TempVertex_t *left, const TempVertex_t *right)
{
  return left->m_nBoneIndex < right->m_nBoneIndex;
}

//------------------------------------------------------------------------------
// Address: 0x005CE190
// Name: bool WeightLessFunc(struct TempVertex_t const __near &,struct TempVertex_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl WeightLessFunc(const TempVertex_t *left, const TempVertex_t *right)
{
  return left->m_flBoneWeight > right->m_flBoneWeight;
}

//------------------------------------------------------------------------------
// Address: 0x005CE1B0
// Name: void std::_Push_heap<struct TempVertex_t __near *,int,struct TempVertex_t,bool (*)(struct TempVertex_t const __near &,struct TempVertex_t const __near &)>(struct TempVertex_t __near *,int,int,struct TempVertex_t __near &&,bool (*)(struct TempVertex_t const __near &,struct TempVertex_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<TempVertex_t *,int,TempVertex_t,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
        TempVertex_t *_First,
        int _Hole,
        int _Top,
        TempVertex_t *_Val,
        bool (__cdecl *_Pred)(const TempVertex_t *, const TempVertex_t *))
{
  int v5; // edi
  int i; // esi
  const TempVertex_t *v7; // ebx

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    _First[v5] = *v7;
    v5 = i;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x005CE220
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x005CE290
// Name: void std::_Adjust_heap<struct TempVertex_t __near *,int,struct TempVertex_t,bool (*)(struct TempVertex_t const __near &,struct TempVertex_t const __near &)>(struct TempVertex_t __near *,int,int,struct TempVertex_t __near &&,bool (*)(struct TempVertex_t const __near &,struct TempVertex_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<TempVertex_t *,int,TempVertex_t,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
        TempVertex_t *_First,
        int _Hole,
        int _Bottom,
        TempVertex_t *_Val,
        bool (__cdecl *_Pred)(const TempVertex_t *, const TempVertex_t *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  bool v8; // zf
  int i; // edi

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      _First[v6] = _First[v7];
      v6 = v7;
      v7 = 2 * v7 + 2;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  for ( i = (v6 - 1) / 2; _Hole < v6; i = (i - 1) / 2 )
  {
    if ( !_Pred(a1: &_First[i], a2: _Val) )
      break;
    _First[v6] = _First[i];
    v6 = i;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x005CE350
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CE3C0
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x005CE440
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x005CE4D0
// Name: public: void CDmeVertexDataBase::SetVertexData(int,int,int,enum DmAttributeType_t,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexData(
        CDmeVertexDataBase *this,
        CDmrGenericArray nFieldIndex,
        int nFirstVertex,
        int nCount,
        DmAttributeType_t valueType,
        const void *pData)
{
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::SetMultiple(this: &nFieldIndex, i: nFirstVertex, nCount, valueType, pValue: pData);
}

//------------------------------------------------------------------------------
// Address: 0x005CE510
// Name: public: int CDmeVertexDataBase::FindFieldIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::FindFieldIndex(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  CDmeVertexDataBase *v7; // [esp+Ch] [ebp-4h]

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  v7 = this;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_FieldInfo.m_Memory.m_pMemory[i].m_Name);
    if ( _V_stricmp(s1: v5, s2: pFieldName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    this = v7;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005CE750
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x005CE7F0
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x005CE860
// Name: private: float CDmeVertexDeltaData::ComputeMaxDeflection(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CDmeVertexDeltaData::ComputeMaxDeflection@<st0>(CDmeVertexDeltaData *this@<ecx>, int a2@<ebp>)
{
  int v2; // eax
  float v3; // xmm3_4
  CDmAttribute *m_pVertexData; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v5; // eax
  int m_Size; // ecx
  float *p_x; // eax
  __int128 v8; // xmm0
  _QWORD v10[2]; // [esp-20h] [ebp-2Ch] BYREF
  float v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a2;
  v13 = retaddr;
  v2 = this->m_pStandardFieldIndex[0];
  v3 = 0.0;
  v11 = 0.0;
  if ( v2 < 0 || v2 >= this->m_FieldInfo.m_Size )
  {
    v5 = &s_EmptyVector;
  }
  else
  {
    m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v10[1]);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v10[1],
      pAttribute: m_pVertexData);
    v5 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)v10[1];
    v3 = v11;
  }
  m_Size = v5->m_Size;
  if ( m_Size > 0 )
  {
    p_x = &v5->m_Memory.m_pMemory->x;
    do
    {
      v8 = 0;
      *(float *)&v8 = fsqrt((float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])) + (float)(p_x[2] * p_x[2]));
      *(_OWORD *)v10 = v8;
      if ( *(float *)&v8 > v3 )
      {
        v3 = *(float *)v10;
        v11 = *(float *)v10;
      }
      p_x += 3;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x005CE930
// Name: void std::_Make_heap<struct TempVertex_t __near *,int,struct TempVertex_t,bool (*)(struct TempVertex_t const __near &,struct TempVertex_t const __near &)>(struct TempVertex_t __near *,struct TempVertex_t __near *,bool (*)(struct TempVertex_t const __near &,struct TempVertex_t const __near &),int __near *,struct TempVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<TempVertex_t *,int,TempVertex_t,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
        TempVertex_t *_First,
        TempVertex_t *_Last,
        bool (__cdecl *_Pred)(const TempVertex_t *, const TempVertex_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  TempVertex_t *i; // edx
  float m_flBoneWeight; // ebx
  int v9; // eax
  int v10; // esi
  int m_nBoneIndex; // edx
  int v12; // ebx
  bool v13; // zf
  TempVertex_t _Val; // [esp+4h] [ebp-10h] BYREF
  int v15; // [esp+Ch] [ebp-8h]
  TempVertex_t *v16; // [esp+10h] [ebp-4h]
  int _Hole; // [esp+1Ch] [ebp+8h]
  int _Bottom; // [esp+20h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v16 )
    {
      m_flBoneWeight = i[-1].m_flBoneWeight;
      v9 = v5 - 1;
      v10 = v6 - 2;
      v16 = i - 1;
      m_nBoneIndex = i[-1].m_nBoneIndex;
      _Val.m_flBoneWeight = m_flBoneWeight;
      _Hole = v9;
      v15 = v10;
      _Val.m_nBoneIndex = m_nBoneIndex;
      v12 = v9;
      v13 = v10 == v4;
      if ( v10 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v10], a2: &_First[v10 - 1]) )
            --v10;
          _First[v12].m_flBoneWeight = _First[v10].m_flBoneWeight;
          _First[v12].m_nBoneIndex = _First[v10].m_nBoneIndex;
          v12 = v10;
          v10 = 2 * v10 + 2;
        }
        while ( v10 < _Bottom );
        v4 = _Bottom;
        v9 = _Hole;
        v13 = v10 == _Bottom;
      }
      if ( v13 )
      {
        _First[v12].m_flBoneWeight = _First[v4 - 1].m_flBoneWeight;
        _First[v12].m_nBoneIndex = _First[v4 - 1].m_nBoneIndex;
        v12 = v4 - 1;
      }
      std::_Push_heap<TempVertex_t *,int,TempVertex_t,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
        _First,
        _Hole: v12,
        _Top: v9,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CEA00
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x005CEA90
// Name: public: class Vector2D const __near & CDmeVertexDataBase::GetTexCoord(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector2D *__thiscall CDmeVertexDataBase::GetTexCoord(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector2D> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[3];
  if ( v3 < 0 )
    return &vec2_origin_179;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x005CEB10
// Name: protected: void CDmeVertexDataBase::FindOrAddVertexField(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::FindOrAddVertexField(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v4; // esi
  const char *m_pAsString; // eax

  m_Size = this->m_VertexFormat.m_Storage.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pFieldName,
      a3: pFieldName);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
      this: &this->m_VertexFormat,
      src: (const CUtlSymbolLarge *)&pFieldName);
  }
  else
  {
    while ( 1 )
    {
      m_pAsString = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[v4].u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      if ( _V_stricmp(s1: pFieldName, s2: m_pAsString) == 0 )
        break;
      if ( ++v4 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CEB80
// Name: public: int CDmeVertexDataBase::AddVertexData(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::AddVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex, int nCount)
{
  CDmrGenericArray v4; // edi
  int v5; // ebx
  CDmAttribute *v6; // edi
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v4.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  v5 = CDmrGenericArrayConst::Count(this: &nFieldIndex);
  nCount += v5;
  CDmrGenericArray::EnsureCount(this: &nFieldIndex, num: nCount);
  if ( this->IsVertexDeltaData(this) )
  {
    v6 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v4.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: v6);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(this: &indices, num: nCount);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x005CEC00
// Name: public: void CDmeVertexDataBase::SetVertexIndices(int,int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexIndices(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nFirstIndex,
        int nCount,
        const int *pIndices)
{
  CDmAttribute *m_pIndexData; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-8h] BYREF

  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
    pAttribute: m_pIndexData);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &array,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x005CEC50
// Name: public: void CDmeVertexDataBase::RemoveAllVertexData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::RemoveAllVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex)
{
  CDmrGenericArray v3; // edi
  CDmAttribute *v4; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+8h] [ebp-8h] BYREF

  v3.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::RemoveAll(this: &nFieldIndex);
  if ( this->IsVertexDeltaData(this) )
  {
    v4 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v3.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
      pAttribute: v4);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CECB0
// Name: public: int CDmeVertexData::AddVertexIndices(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::AddVertexIndices(CDmeVertexData *this, int nIndexCount)
{
  int m_nVertexCount; // ecx
  int m_Size; // eax
  int v5; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // eax
  bool v7; // zf
  const CDmAttribute **p_m_pIndexData; // eax
  const CDmAttribute *v9; // ebx
  CDmrArray<int> indices; // [esp+4h] [ebp-Ch] BYREF
  int v12; // [esp+Ch] [ebp-4h]
  int nIndexCounta; // [esp+18h] [ebp+8h]

  m_nVertexCount = this->m_nVertexCount;
  m_Size = this->m_FieldInfo.m_Size;
  v12 = m_nVertexCount;
  this->m_nVertexCount = m_nVertexCount + nIndexCount;
  if ( m_Size > 0 )
  {
    v5 = 0;
    for ( nIndexCounta = m_Size; nIndexCounta != 0; --nIndexCounta )
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      v7 = m_pMemory[v5].m_pIndexData == nullptr;
      p_m_pIndexData = (const CDmAttribute **)&m_pMemory[v5].m_pIndexData;
      if ( !v7 )
      {
        v9 = *p_m_pIndexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
          pAttribute: v9);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
          this: &indices,
          num: this->m_nVertexCount);
        m_nVertexCount = v12;
      }
      ++v5;
    }
  }
  return m_nVertexCount;
}

//------------------------------------------------------------------------------
// Address: 0x005CED30
// Name: public: void CDmeVertexDataBase::CopyTo(class CDmeVertexDataBase __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::CopyTo(CDmeVertexDataBase *this, CDmeVertexDataBase *pDst)
{
  CDmeVertexDataBase *v2; // esi
  const char *m_pAsString; // eax
  const char *v5; // eax
  CUtlString dstName; // [esp+8h] [ebp-10h] BYREF

  v2 = pDst;
  m_pAsString = pDst->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CUtlString::CUtlString(this: &dstName, pString: m_pAsString);
  CDmElement::CopyAttributesTo(this, pCopy: v2, depth: TD_DEEP);
  v5 = CUtlString::operator char const *(this: &dstName);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmeVertexDataBase **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
    a1: g_pDataModel.u,
    a2: &pDst,
    a3: v5);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v2->m_Name.m_pAttribute, value: (const CUtlSymbolLarge *)&pDst);
  v2->Resolve(this: v2);
  dstName.m_Storage.m_nActualLength = 0;
  if ( dstName.m_Storage.m_Memory.m_nGrowSize >= 0 && dstName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dstName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005CEDC0
// Name: void std::_Sort_heap<struct TempVertex_t __near *,bool (*)(struct TempVertex_t const __near &,struct TempVertex_t const __near &)>(struct TempVertex_t __near *,struct TempVertex_t __near *,bool (*)(struct TempVertex_t const __near &,struct TempVertex_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<TempVertex_t *,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
        TempVertex_t *_First,
        TempVertex_t *_Last,
        bool (__cdecl *_Pred)(const TempVertex_t *, const TempVertex_t *))
{
  int v3; // eax
  TempVertex_t *v4; // esi
  int m_nBoneIndex; // edx
  TempVertex_t _Val; // [esp+4h] [ebp-8h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF8) > 8 )
  {
    v4 = _Last - 1;
    do
    {
      m_nBoneIndex = v4->m_nBoneIndex;
      _Val.m_flBoneWeight = v4->m_flBoneWeight;
      v4->m_flBoneWeight = _First->m_flBoneWeight;
      _Val.m_nBoneIndex = m_nBoneIndex;
      v4->m_nBoneIndex = _First->m_nBoneIndex;
      std::_Adjust_heap<TempVertex_t *,int,TempVertex_t,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 8) >> 3,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 8;
    }
    while ( (int)(v3 & 0xFFFFFFF8) > 8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CEE30
// Name: public: void CDmeVertexDataBase::Reskin(int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Reskin(CDmeVertexDataBase *this, const int *pJointTransformIndexRemap)
{
  int v3; // esi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v5; // esi
  int m_Storage; // ebx
  void *v7; // esp
  int v8; // eax
  int v9; // ecx
  TempVertex_t *v10; // eax
  int v11; // ecx
  int v12; // eax
  float *v13; // ebx
  float v14; // xmm0_4
  int v15; // ecx
  int v16; // edx
  TempVertex_t *v17; // eax
  int v18; // edx
  int v19; // eax
  TempVertex_t *v20; // ebx
  int m_nBoneIndex; // ecx
  TempVertex_t *k; // ebx
  TempVertex_t *p_Val; // [esp-8h] [ebp-44h]
  bool (__cdecl *v24)(const TempVertex_t *, const TempVertex_t *); // [esp-4h] [ebp-40h]
  TempVertex_t v25; // [esp+0h] [ebp-3Ch] BYREF
  int v26; // [esp+8h] [ebp-34h] BYREF
  TempVertex_t _Val; // [esp+Ch] [ebp-30h] BYREF
  CDmrArray<int> indexData; // [esp+14h] [ebp-28h] BYREF
  CDmrArray<float> weightData; // [esp+1Ch] [ebp-20h] BYREF
  int nOffset; // [esp+24h] [ebp-18h]
  int nRemapCount; // [esp+28h] [ebp-14h]
  int nVertexCount; // [esp+2Ch] [ebp-10h]
  int i; // [esp+30h] [ebp-Ch]
  int j; // [esp+34h] [ebp-8h]
  unsigned __int8 *src; // [esp+38h] [ebp-4h]

  if ( CDmeVertexDataBase::HasSkinningData(this) )
  {
    v3 = this->m_pStandardFieldIndex[6];
    m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[this->m_pStandardFieldIndex[5]].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
    CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
      this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&weightData,
      pAttribute: m_pVertexData);
    v5 = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indexData,
      pAttribute: v5);
    m_Storage = this->m_nJointCount.m_Storage;
    nVertexCount = weightData.m_pStorage->m_Size / m_Storage;
    v7 = alloca(8 * m_Storage);
    for ( i = 0; i < nVertexCount; ++i )
    {
      v8 = 0;
      nOffset = i * m_Storage;
      if ( m_Storage > 0 )
      {
        v9 = i * m_Storage;
        do
        {
          *(&v25.m_nBoneIndex + 2 * v8++) = pJointTransformIndexRemap[indexData.m_pStorage->m_Memory.m_pMemory[v9]];
          *((float *)&v25 + 2 * v8 - 2) = weightData.m_pStorage->m_Memory.m_pMemory[v9++];
        }
        while ( v8 < this->m_nJointCount.m_Storage );
      }
      v10 = &v25 + this->m_nJointCount.m_Storage;
      if ( 8 * this->m_nJointCount.m_Storage > 8 )
      {
        v24 = nullptr;
        p_Val = nullptr;
        std::_Make_heap<TempVertex_t *,int,TempVertex_t,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
          _First: &v25,
          _Last: v10,
          _Pred: (bool (__cdecl *)(const TempVertex_t *, const TempVertex_t *))TempVertexLessFunc);
      }
      std::_Sort_heap<TempVertex_t *,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
        _First: &v25,
        _Last: &v25 + this->m_nJointCount.m_Storage,
        _Pred: (bool (__cdecl *)(const TempVertex_t *, const TempVertex_t *))TempVertexLessFunc);
      v11 = this->m_nJointCount.m_Storage;
      v12 = 1;
      j = 1;
      if ( v11 > 1 )
      {
        v13 = (float *)&v26;
        src = (unsigned __int8 *)&_Val.m_nBoneIndex;
        do
        {
          if ( *((_DWORD *)v13 + 1) == *((_DWORD *)v13 - 1) )
          {
            v14 = *v13 + *(v13 - 2);
            nRemapCount = v11 - 1;
            *(v13 - 2) = v14;
            memmove(dst: (unsigned __int8 *)v13, src, count: 8 * (this->m_nJointCount.m_Storage - v12) - 8);
            v15 = this->m_nJointCount.m_Storage;
            v12 = --j;
            *((_DWORD *)&v25 + 2 * v15 - 2) = 0;
            v16 = this->m_nJointCount.m_Storage;
            v11 = nRemapCount;
            v13 -= 2;
            src -= 8;
            *((_DWORD *)&v25 + 2 * v16 - 1) = 0;
          }
          src += 8;
          ++v12;
          v13 += 2;
          j = v12;
        }
        while ( v12 < v11 );
      }
      v17 = &v25 + this->m_nJointCount.m_Storage;
      if ( 8 * this->m_nJointCount.m_Storage > 8 )
      {
        v24 = nullptr;
        p_Val = nullptr;
        std::_Make_heap<TempVertex_t *,int,TempVertex_t,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
          _First: &v25,
          _Last: v17,
          _Pred: (bool (__cdecl *)(const TempVertex_t *, const TempVertex_t *))WeightLessFunc);
      }
      v18 = this->m_nJointCount.m_Storage;
      v19 = 8 * v18;
      j = (int)(&v25 + v18);
      if ( 8 * v18 > 8 )
      {
        v20 = &v25 + v18 - 1;
        do
        {
          m_nBoneIndex = v20->m_nBoneIndex;
          _Val.m_flBoneWeight = v20->m_flBoneWeight;
          v20->m_flBoneWeight = v25.m_flBoneWeight;
          v24 = (bool (__cdecl *)(const TempVertex_t *, const TempVertex_t *))WeightLessFunc;
          p_Val = &_Val;
          _Val.m_nBoneIndex = m_nBoneIndex;
          v20->m_nBoneIndex = v25.m_nBoneIndex;
          std::_Adjust_heap<TempVertex_t *,int,TempVertex_t,bool (__cdecl *)(TempVertex_t const &,TempVertex_t const &)>(
            _First: &v25,
            _Hole: 0,
            _Bottom: (v19 - 8) >> 3,
            _Val: p_Val,
            _Pred: v24);
          j -= 8;
          v19 = j - (_DWORD)&v25;
          --v20;
        }
        while ( (int)((j - (_DWORD)&v25) & 0xFFFFFFF8) > 8 );
      }
      m_Storage = this->m_nJointCount.m_Storage;
      src = nullptr;
      if ( m_Storage > 0 )
      {
        j = nOffset;
        for ( k = &v25; ; k = (TempVertex_t *)nOffset )
        {
          CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
            this: &indexData,
            i: j,
            value: &k->m_nBoneIndex);
          CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
            this: &weightData,
            i: j++,
            value: &k->m_flBoneWeight);
          nOffset = (int)&k[1];
          m_Storage = this->m_nJointCount.m_Storage;
          if ( (int)++src >= m_Storage )
            break;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CF450
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)defaultValue;
        s2 = (char *)defaultValue;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005CF750
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CF7C0
// Name: public: int CDmeVertexDataBase::CreateField(char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, char *pFieldName, DmAttributeType_t type)
{
  int v4; // edi
  void *v5; // esp
  int FieldIndex; // edi
  CDmAttribute *m_pIndexData; // ebx
  char v9[12]; // [esp+0h] [ebp-14h] BYREF
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  if ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[5]) == 0
    || _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[6]) == 0 )
  {
    return -1;
  }
  if ( CDmElement::FindAttribute(this, pAttributeName: pFieldName) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: pFieldName, type);
  v4 = _V_strlen(str: pFieldName) + 21;
  v5 = alloca(v4);
  V_snprintf(pDest: v9, maxLen: v4, pFormat: "%sIndices", pFieldName);
  if ( CDmElement::FindAttribute(this, pAttributeName: v9) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v9, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName);
  if ( !this->IsVertexDeltaData(this) && this->m_nVertexCount > 0 )
  {
    m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[FieldIndex].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: m_pIndexData);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
      this: &indices,
      num: this->m_nVertexCount);
  }
  return FieldIndex;
}

//------------------------------------------------------------------------------
// Address: 0x005CF8D0
// Name: public: int CDmeVertexDataBase::CreateField(enum CDmeVertexDataBase::StandardFields_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, CDmeVertexDataBase::StandardFields_t fieldId)
{
  return CDmeVertexDataBase::CreateField(
           this,
           pFieldName: g_pStandardFieldNames[fieldId],
           type: g_pStandardFieldTypes[fieldId]);
}

//------------------------------------------------------------------------------
// Address: 0x005CF8F0
// Name: public: void CDmeVertexDeltaData::GenerateWrinkleDelta(class CDmeVertexData __near *,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeVertexDeltaData::GenerateWrinkleDelta(
        CDmeVertexDeltaData *this@<ecx>,
        int a2@<ebp>,
        __int64 a3@<esi:edi>,
        CDmeVertexData *pBindState,
        float flScale,
        bool bOverwrite,
        bool bUseNormalForSign)
{
  int v8; // eax
  int v9; // esi
  double v10; // st7
  void *v11; // esp
  int m_Size; // eax
  float *v13; // eax
  __int128 v14; // xmm0
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndicesFromDataIndex; // edx
  int v16; // eax
  int v17; // ecx
  const CDmAttribute *v18; // eax
  int *m_pMemory; // edx
  Vector *v20; // eax
  int v21; // esi
  float *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  int *v26; // eax
  float v27; // xmm2_4
  __int128 v28; // xmm0
  const CUtlVector<int,CUtlMemory<int,int> > *v29; // edx
  int v30; // eax
  int v31; // ecx
  int v32; // esi
  _QWORD v33[4]; // [esp-A0h] [ebp-ACh] BYREF
  CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > v34; // [esp-80h] [ebp-8Ch] BYREF
  double v35; // [esp-78h] [ebp-84h]
  Vector v36; // [esp-70h] [ebp-7Ch] BYREF
  Vector v37; // [esp-64h] [ebp-70h] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *NormalData; // [esp-58h] [ebp-64h]
  const CUtlVector<int,CUtlMemory<int,int> > *v39; // [esp-54h] [ebp-60h]
  const CUtlVector<int,CUtlMemory<int,int> > *v40; // [esp-50h] [ebp-5Ch]
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > v41; // [esp-4Ch] [ebp-58h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndexData; // [esp-44h] [ebp-50h]
  CDmrGenericArray v43; // [esp-40h] [ebp-4Ch] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v44; // [esp-3Ch] [ebp-48h]
  int v45; // [esp-38h] [ebp-44h] BYREF
  const CDmAttribute *m_pIndexData; // [esp-34h] [ebp-40h]
  CDmrGenericArray v47; // [esp-30h] [ebp-3Ch] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // [esp-2Ch] [ebp-38h]
  CDmrGenericArray v49; // [esp-28h] [ebp-34h] BYREF
  int v50; // [esp-24h] [ebp-30h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v51; // [esp-20h] [ebp-2Ch]
  int Field; // [esp-1Ch] [ebp-28h]
  float v53; // [esp-18h] [ebp-24h]
  int v54; // [esp-14h] [ebp-20h]
  int v55; // [esp-10h] [ebp-1Ch]
  _BYTE *v56; // [esp-Ch] [ebp-18h]
  int v57; // [esp-8h] [ebp-14h]
  int v58; // [esp-4h] [ebp-10h]
  int nDeltaIndex; // [esp+0h] [ebp-Ch] BYREF
  int nNormalIndex; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  nDeltaIndex = a2;
  nNormalIndex = retaddr;
  v33[0] = a3;
  v51 = (const CUtlVector<int,CUtlMemory<int,int> > *)this->m_pStandardFieldIndex[0];
  if ( (int)v51 >= 0 )
  {
    v54 = pBindState->m_pStandardFieldIndex[3];
    if ( v54 >= 0 )
    {
      v8 = pBindState->m_pStandardFieldIndex[1];
      v57 = v8;
      if ( !bUseNormalForSign || v8 >= 0 )
      {
        v9 = this->m_pStandardFieldIndex[9];
        Field = v9;
        if ( v9 >= 0 )
        {
          if ( !bOverwrite )
            return;
        }
        else
        {
          Field = CDmeVertexDataBase::CreateField(
                    this,
                    pFieldName: g_pStandardFieldNames[9],
                    type: g_pStandardFieldTypes[9]);
          v9 = Field;
        }
        CDmeVertexDataBase::RemoveAllVertexData(this, nFieldIndex: (CDmrGenericArray)v9);
        if ( flScale != 0.0 )
        {
          v10 = CDmeVertexDeltaData::ComputeMaxDeflection(this, a2: (int)&nDeltaIndex);
          v53 = v10;
          if ( v10 != 0.0 )
          {
            v35 = (float)(flScale / v53);
            VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this, nFieldIndex: (int)v51);
            PositionData = CDmeVertexDataBase::GetPositionData(this);
            v51 = CDmeVertexDataBase::GetVertexIndexData(this: pBindState, nFieldIndex: v54);
            v53 = *(float *)&pBindState->m_FieldInfo.m_Memory.m_pMemory[v54].m_pVertexData;
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v34);
            CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
              this: &v34,
              pAttribute: (CDmAttribute *)LODWORD(v53));
            v58 = (v34.m_pStorage->m_Size + 7) >> 3;
            v11 = alloca(v58);
            v53 = COERCE_FLOAT(v33);
            memset(dst: (unsigned __int8 *)v33, value: 0, count: v58);
            m_Size = PositionData->m_Size;
            v54 = m_Size;
            if ( bUseNormalForSign )
            {
              v40 = CDmeVertexDataBase::GetVertexIndexData(this: pBindState, nFieldIndex: v57);
              NormalData = CDmeVertexDataBase::GetNormalData(this: pBindState);
              v55 = 0;
              if ( v54 > 0 )
              {
                v57 = 0;
                do
                {
                  v13 = (float *)((char *)&PositionData->m_Memory.m_pMemory->x + v57);
                  v14 = 0;
                  *(float *)&v14 = fsqrt((float)((float)(*v13 * *v13) + (float)(v13[1] * v13[1])) + (float)(v13[2] * v13[2]));
                  *(_OWORD *)&v33[2] = v14;
                  *(float *)&v14 = *(float *)&v14 * v35;
                  v45 = v14;
                  v49.m_pAttribute = (CDmAttribute *)(v14 ^ _mask__NegFloat_);
                  v36 = *(Vector *)v13;
                  VectorNormalize(vec: &v36);
                  VertexIndicesFromDataIndex = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                                 this: pBindState,
                                                 nFieldIndex: pBindState->m_pStandardFieldIndex[0],
                                                 nDataIndex: VertexIndexData->m_Memory.m_pMemory[v55]);
                  v16 = VertexIndicesFromDataIndex->m_Size;
                  v17 = 0;
                  v39 = VertexIndicesFromDataIndex;
                  v44 = (const CUtlVector<int,CUtlMemory<int,int> > *)v16;
                  v58 = 0;
                  if ( v16 > 0 )
                  {
                    while ( 1 )
                    {
                      v18 = (const CDmAttribute *)&VertexIndicesFromDataIndex->m_Memory.m_pMemory[v17];
                      m_pMemory = v51->m_Memory.m_pMemory;
                      m_pIndexData = v18;
                      v50 = m_pMemory[(int)v18->m_pNext];
                      v56 = (_BYTE *)(LODWORD(v53) + (v50 >> 3));
                      if ( ((unsigned __int8)(1 << (v50 & 7)) & *v56) == 0 )
                      {
                        *v56 |= 1 << (v50 & 7);
                        v20 = &NormalData->m_Memory.m_pMemory[v40->m_Memory.m_pMemory[(int)m_pIndexData->m_pNext]];
                        v37 = *v20;
                        VectorNormalize(vec: &v37);
                        v56 = (_BYTE *)CDmeVertexDataBase::AddVertexData(
                                         this,
                                         nFieldIndex: (CDmrGenericArray)v9,
                                         nCount: 1);
                        v21 = v9;
                        m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pIndexData;
                        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v41);
                        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
                          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v41,
                          pAttribute: m_pIndexData);
                        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
                          this: &v41,
                          i: (int)v56,
                          nCount: 1,
                          pValue: &v50);
                        if ( (float)((float)((float)(v37.y * v36.y) + (float)(v37.x * v36.x)) + (float)(v36.z * v37.z)) >= 0.0 )
                        {
                          CDmrGenericArray::CDmrGenericArray(
                            this: &v43,
                            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pVertexData);
                          CDmrGenericArray::SetMultiple(
                            this: &v43,
                            i: (int)v56,
                            nCount: 1,
                            valueType: AT_FLOAT,
                            pValue: &v45);
                        }
                        else
                        {
                          CDmrGenericArray::CDmrGenericArray(
                            this: &v47,
                            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pVertexData);
                          CDmrGenericArray::SetMultiple(
                            this: &v47,
                            i: (int)v56,
                            nCount: 1,
                            valueType: AT_FLOAT,
                            pValue: &v49);
                        }
                        v9 = Field;
                      }
                      v17 = v58 + 1;
                      v58 = v17;
                      if ( v17 >= (int)v44 )
                        break;
                      VertexIndicesFromDataIndex = v39;
                    }
                  }
                  v57 += 12;
                  ++v55;
                }
                while ( v55 < v54 );
              }
            }
            else
            {
              v57 = 0;
              if ( m_Size > 0 )
              {
                v55 = 0;
                do
                {
                  v22 = (float *)((char *)&PositionData->m_Memory.m_pMemory->x + v55);
                  v23 = v22[2];
                  v24 = v22[1];
                  v25 = *v22;
                  v26 = VertexIndexData->m_Memory.m_pMemory;
                  v27 = (float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v23 * v23);
                  v28 = 0;
                  *(float *)&v28 = fsqrt(v27);
                  *(_OWORD *)&v33[2] = v28;
                  *(float *)&v47.m_pAttribute = *(float *)&v28 * v35;
                  v29 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                          this: pBindState,
                          nFieldIndex: pBindState->m_pStandardFieldIndex[0],
                          nDataIndex: v26[v57]);
                  v30 = v29->m_Size;
                  v31 = 0;
                  v44 = v29;
                  v50 = v30;
                  v56 = nullptr;
                  if ( v30 > 0 )
                  {
                    while ( 1 )
                    {
                      v45 = v51->m_Memory.m_pMemory[v29->m_Memory.m_pMemory[v31]];
                      v58 = LODWORD(v53) + (v45 >> 3);
                      if ( ((unsigned __int8)(1 << (v45 & 7)) & *(_BYTE *)v58) == 0 )
                      {
                        *(_BYTE *)v58 |= 1 << (v45 & 7);
                        v58 = CDmeVertexDataBase::AddVertexData(this, nFieldIndex: (CDmrGenericArray)v9, nCount: 1);
                        v32 = v9;
                        v43.m_pAttribute = this->m_FieldInfo.m_Memory.m_pMemory[v32].m_pIndexData;
                        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v41);
                        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
                          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v41,
                          pAttribute: v43.m_pAttribute);
                        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
                          this: &v41,
                          i: v58,
                          nCount: 1,
                          pValue: &v45);
                        CDmrGenericArray::CDmrGenericArray(
                          this: &v49,
                          pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v32].m_pVertexData);
                        CDmrGenericArray::SetMultiple(this: &v49, i: v58, nCount: 1, valueType: AT_FLOAT, pValue: &v47);
                        v9 = Field;
                      }
                      v31 = (int)(v56 + 1);
                      v56 = (_BYTE *)v31;
                      if ( v31 >= v50 )
                        break;
                      v29 = v44;
                    }
                  }
                  v55 += 12;
                  ++v57;
                }
                while ( v57 < v54 );
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CFE10
// Name: public: void CDmeVertexDeltaData::UpdateWrinkleDelta(class CDmeVertexData __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeVertexDeltaData::UpdateWrinkleDelta(
        CDmeVertexDeltaData *this@<ecx>,
        __int64 a2@<esi:edi>,
        CDmeVertexData *pBindState,
        float flOldScale,
        float flScale)
{
  int v5; // ecx
  CDmAttribute *v6; // edi
  double dNewScale; // [esp+14h] [ebp-10h]
  CDmrArray<float> wrinkleData; // [esp+1Ch] [ebp-8h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  HIDWORD(a2) = this;
  v5 = this->m_pStandardFieldIndex[9];
  if ( v5 < 0 || flOldScale == 0.0 || flScale == 0.0 )
  {
    CDmeVertexDeltaData::GenerateWrinkleDelta(
      this: (CDmeVertexDeltaData *)HIDWORD(a2),
      a2: (int)&savedregs,
      a3: a2,
      pBindState,
      flScale,
      bOverwrite: true,
      bUseNormalForSign: false);
  }
  else
  {
    v6 = *(CDmAttribute **)(*(_DWORD *)(HIDWORD(a2) + 108) + 48 * v5 + 16);
    if ( v6 != nullptr )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&wrinkleData);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&wrinkleData,
        pAttribute: v6);
      LODWORD(a2) = wrinkleData.m_pStorage->m_Size;
      if ( (int)a2 <= 0 )
        CDmeVertexDeltaData::GenerateWrinkleDelta(
          this: (CDmeVertexDeltaData *)HIDWORD(a2),
          a2: (int)&savedregs,
          a3: a2,
          pBindState,
          flScale,
          bOverwrite: true,
          bUseNormalForSign: false);
      HIDWORD(a2) = 0;
      dNewScale = (float)(flScale / flOldScale);
      if ( (int)a2 > 0 )
      {
        do
        {
          flScale = wrinkleData.m_pStorage->m_Memory.m_pMemory[HIDWORD(a2)] * dNewScale;
          CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
            this: &wrinkleData,
            i: SHIDWORD(a2),
            value: &flScale);
          ++HIDWORD(a2);
        }
        while ( SHIDWORD(a2) < (int)a2 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005CFF70
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005CFFA0
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D0020
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D0050
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D00B0
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005D0100
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005D0180
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D01B0
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D0200
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B0290
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0350
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B03B0
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4FD0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4FE0
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4FF0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B02C0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B02D0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B02F0
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0300
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0310
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0320
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0330
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0340
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0380
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0390
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B03E0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B03F0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5000
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x006B5010
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x006B5020
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x006B5030
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x006B5040
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x006B5050
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x006B5060
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5070
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5080
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0046A800
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n");
}

//------------------------------------------------------------------------------
// Address: 0x0046A870
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x0046A980
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A9F0
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x0046AC90
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046AD30
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x0046ADA0
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x0046B270
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)&pch;
        s2 = (char *)&pch;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0046B570
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B640
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B670
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B6B0
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046B700
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B730
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B7C0
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046B840
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B870
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B8C0
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB30
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBF0
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC50
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580090
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005800A0
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005800B0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB60
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB70
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB90
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBA0
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBB0
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBC0
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBD0
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBE0
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC20
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC30
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC80
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC90
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005800C0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x005800D0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x005800E0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x005800F0
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x00580100
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x00580110
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x00580120
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580130
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580140
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005029C0
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x00502A30
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x00502AA0
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00502B10
// Name: public: int CDmeVertexDataBase::GetPositionIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetPositionIndex(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[0];
  if ( v2 < 0 )
    return -1;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage->m_Memory.m_pMemory[nVertexIndex].m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x00502B60
// Name: public: int CDmeVertexDataBase::GetNormalIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetNormalIndex(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[1];
  if ( v2 < 0 )
    return -1;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage->m_Memory.m_pMemory[nVertexIndex].m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x00502BB0
// Name: public: int CDmeVertexDataBase::GetTexCoordIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetTexCoordIndex(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v2; // eax
  CDmAttribute *m_pIndexData; // esi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+0h] [ebp-8h] BYREF

  v2 = this->m_pStandardFieldIndex[3];
  if ( v2 < 0 )
    return -1;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
    pAttribute: m_pIndexData);
  return v5.m_pStorage->m_Memory.m_pMemory[nVertexIndex].m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x00502C00
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00502C80
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00502D10
// Name: public: void CDmeVertexDataBase::SetVertexData(int,int,int,enum DmAttributeType_t,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexData(
        CDmeVertexDataBase *this,
        CDmrGenericArray nFieldIndex,
        int nFirstVertex,
        int nCount,
        DmAttributeType_t valueType,
        const void *pData)
{
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::SetMultiple(this: &nFieldIndex, i: nFirstVertex, nCount, valueType, pValue: pData);
}

//------------------------------------------------------------------------------
// Address: 0x00502D50
// Name: public: int CDmeVertexDataBase::FindFieldIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::FindFieldIndex(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  CDmeVertexDataBase *v7; // [esp+Ch] [ebp-4h]

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  v7 = this;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_FieldInfo.m_Memory.m_pMemory[i].m_Name);
    if ( _V_stricmp(s1: v5, s2: pFieldName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    this = v7;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00502EF0
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndexData(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndexData(CDmeVertexDataBase *this, int nDataIndex)
{
  int v3; // eax
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+4h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v3 >= this->m_FieldInfo.m_Size )
    return nullptr;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[nDataIndex * this->m_nJointCount.m_Storage];
}

//------------------------------------------------------------------------------
// Address: 0x005030E0
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00503180
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x005031F0
// Name: private: float CDmeVertexDeltaData::ComputeMaxDeflection(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CDmeVertexDeltaData::ComputeMaxDeflection@<st0>(CDmeVertexDeltaData *this@<ecx>, int a2@<ebp>)
{
  int v2; // eax
  float v3; // xmm3_4
  CDmAttribute *m_pVertexData; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v5; // eax
  int m_Size; // ecx
  float *p_x; // eax
  __int128 v8; // xmm0
  _QWORD v10[2]; // [esp-20h] [ebp-2Ch] BYREF
  float v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a2;
  v13 = retaddr;
  v2 = this->m_pStandardFieldIndex[0];
  v3 = 0.0;
  v11 = 0.0;
  if ( v2 < 0 || v2 >= this->m_FieldInfo.m_Size )
  {
    v5 = &s_EmptyVector;
  }
  else
  {
    m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v2].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v10[1]);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v10[1],
      pAttribute: m_pVertexData);
    v5 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)v10[1];
    v3 = v11;
  }
  m_Size = v5->m_Size;
  if ( m_Size > 0 )
  {
    p_x = &v5->m_Memory.m_pMemory->x;
    do
    {
      v8 = 0;
      *(float *)&v8 = fsqrt((float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])) + (float)(p_x[2] * p_x[2]));
      *(_OWORD *)v10 = v8;
      if ( *(float *)&v8 > v3 )
      {
        v3 = *(float *)v10;
        v11 = *(float *)v10;
      }
      p_x += 3;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x005032C0
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00503350
// Name: protected: void CDmeVertexDataBase::FindOrAddVertexField(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::FindOrAddVertexField(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v4; // esi
  const char *m_pAsString; // eax

  m_Size = this->m_VertexFormat.m_Storage.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pFieldName,
      a3: pFieldName);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
      this: &this->m_VertexFormat,
      src: (const CUtlSymbolLarge *)&pFieldName);
  }
  else
  {
    while ( 1 )
    {
      m_pAsString = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[v4].u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      if ( _V_stricmp(s1: pFieldName, s2: m_pAsString) == 0 )
        break;
      if ( ++v4 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005033C0
// Name: public: int CDmeVertexDataBase::AddVertexData(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::AddVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex, int nCount)
{
  CDmrGenericArray v4; // edi
  int v5; // ebx
  CDmAttribute *v6; // edi
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v4.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  v5 = CDmrGenericArrayConst::Count(this: &nFieldIndex);
  nCount += v5;
  CDmrGenericArray::EnsureCount(this: &nFieldIndex, num: nCount);
  if ( this->IsVertexDeltaData(this) )
  {
    v6 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v4.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: v6);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(this: &indices, num: nCount);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00503440
// Name: public: void CDmeVertexDataBase::SetVertexIndices(int,int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexIndices(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nFirstIndex,
        int nCount,
        const int *pIndices)
{
  CDmAttribute *m_pIndexData; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-8h] BYREF

  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
    pAttribute: m_pIndexData);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &array,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x00503490
// Name: public: void CDmeVertexDataBase::RemoveAllVertexData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::RemoveAllVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex)
{
  CDmrGenericArray v3; // edi
  CDmAttribute *v4; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v5; // [esp+8h] [ebp-8h] BYREF

  v3.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::RemoveAll(this: &nFieldIndex);
  if ( this->IsVertexDeltaData(this) )
  {
    v4 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v3.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v5);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v5,
      pAttribute: v4);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005034F0
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeightData(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeightData(CDmeVertexDataBase *this, int nDataIndex)
{
  int v3; // eax
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+4h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v3 >= this->m_FieldInfo.m_Size )
    return nullptr;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[nDataIndex * this->m_nJointCount.m_Storage];
}

//------------------------------------------------------------------------------
// Address: 0x00503910
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)pDeltaStateName;
        s2 = (char *)pDeltaStateName;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00503C10
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00503C80
// Name: public: int CDmeVertexDataBase::CreateField(char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, char *pFieldName, DmAttributeType_t type)
{
  int v4; // edi
  void *v5; // esp
  int FieldIndex; // edi
  CDmAttribute *m_pIndexData; // ebx
  char v9[12]; // [esp+0h] [ebp-14h] BYREF
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  if ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[5]) == 0
    || _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[6]) == 0 )
  {
    return -1;
  }
  if ( CDmElement::FindAttribute(this, pAttributeName: pFieldName) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: pFieldName, type);
  v4 = _V_strlen(str: pFieldName) + 21;
  v5 = alloca(v4);
  V_snprintf(pDest: v9, maxLen: v4, pFormat: "%sIndices", pFieldName);
  if ( CDmElement::FindAttribute(this, pAttributeName: v9) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v9, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName);
  if ( !this->IsVertexDeltaData(this) && this->m_nVertexCount > 0 )
  {
    m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[FieldIndex].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: m_pIndexData);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
      this: &indices,
      num: this->m_nVertexCount);
  }
  return FieldIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00503D90
// Name: public: int CDmeVertexDataBase::CreateField(enum CDmeVertexDataBase::StandardFields_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, CDmeVertexDataBase::StandardFields_t fieldId)
{
  return CDmeVertexDataBase::CreateField(
           this,
           pFieldName: g_pStandardFieldNames[fieldId],
           type: g_pStandardFieldTypes[fieldId]);
}

//------------------------------------------------------------------------------
// Address: 0x00503DB0
// Name: public: void CDmeVertexDeltaData::GenerateWrinkleDelta(class CDmeVertexData __near *,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeVertexDeltaData::GenerateWrinkleDelta(
        CDmeVertexDeltaData *this@<ecx>,
        int a2@<ebp>,
        __int64 a3@<esi:edi>,
        CDmeVertexData *pBindState,
        float flScale,
        bool bOverwrite,
        bool bUseNormalForSign)
{
  int v8; // eax
  int v9; // esi
  double v10; // st7
  void *v11; // esp
  int m_Size; // eax
  float *v13; // eax
  __int128 v14; // xmm0
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndicesFromDataIndex; // edx
  int v16; // eax
  int v17; // ecx
  CDmAttribute *v18; // eax
  int *m_pMemory; // edx
  Vector *v20; // eax
  int v21; // esi
  float *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  int *v26; // eax
  float v27; // xmm2_4
  __int128 v28; // xmm0
  const CUtlVector<int,CUtlMemory<int,int> > *v29; // edx
  int v30; // eax
  int v31; // ecx
  int v32; // esi
  _QWORD v33[4]; // [esp-A0h] [ebp-ACh] BYREF
  CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > v34; // [esp-80h] [ebp-8Ch] BYREF
  double v35; // [esp-78h] [ebp-84h]
  Vector v36; // [esp-70h] [ebp-7Ch] BYREF
  Vector v37; // [esp-64h] [ebp-70h] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *NormalData; // [esp-58h] [ebp-64h]
  const CUtlVector<int,CUtlMemory<int,int> > *v39; // [esp-54h] [ebp-60h]
  const CUtlVector<int,CUtlMemory<int,int> > *v40; // [esp-50h] [ebp-5Ch]
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > v41; // [esp-4Ch] [ebp-58h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndexData; // [esp-44h] [ebp-50h]
  CDmrGenericArray v43; // [esp-40h] [ebp-4Ch] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v44; // [esp-3Ch] [ebp-48h]
  int v45; // [esp-38h] [ebp-44h] BYREF
  CDmAttribute *m_pIndexData; // [esp-34h] [ebp-40h]
  CDmrGenericArray v47; // [esp-30h] [ebp-3Ch] BYREF
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // [esp-2Ch] [ebp-38h]
  CDmrGenericArray v49; // [esp-28h] [ebp-34h] BYREF
  int v50; // [esp-24h] [ebp-30h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v51; // [esp-20h] [ebp-2Ch]
  int Field; // [esp-1Ch] [ebp-28h]
  float v53; // [esp-18h] [ebp-24h]
  int v54; // [esp-14h] [ebp-20h]
  int v55; // [esp-10h] [ebp-1Ch]
  _BYTE *v56; // [esp-Ch] [ebp-18h]
  int v57; // [esp-8h] [ebp-14h]
  int v58; // [esp-4h] [ebp-10h]
  int nDeltaIndex; // [esp+0h] [ebp-Ch] BYREF
  int nNormalIndex; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  nDeltaIndex = a2;
  nNormalIndex = retaddr;
  v33[0] = a3;
  v51 = (const CUtlVector<int,CUtlMemory<int,int> > *)this->m_pStandardFieldIndex[0];
  if ( (int)v51 >= 0 )
  {
    v54 = pBindState->m_pStandardFieldIndex[3];
    if ( v54 >= 0 )
    {
      v8 = pBindState->m_pStandardFieldIndex[1];
      v57 = v8;
      if ( !bUseNormalForSign || v8 >= 0 )
      {
        v9 = this->m_pStandardFieldIndex[9];
        Field = v9;
        if ( v9 >= 0 )
        {
          if ( !bOverwrite )
            return;
        }
        else
        {
          Field = CDmeVertexDataBase::CreateField(
                    this,
                    pFieldName: g_pStandardFieldNames[9],
                    type: g_pStandardFieldTypes[9]);
          v9 = Field;
        }
        CDmeVertexDataBase::RemoveAllVertexData(this, nFieldIndex: (CDmrGenericArray)v9);
        if ( flScale != 0.0 )
        {
          v10 = CDmeVertexDeltaData::ComputeMaxDeflection(this, a2: (int)&nDeltaIndex);
          v53 = v10;
          if ( v10 != 0.0 )
          {
            v35 = (float)(flScale / v53);
            VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this, nFieldIndex: (int)v51);
            PositionData = CDmeVertexDataBase::GetPositionData(this);
            v51 = CDmeVertexDataBase::GetVertexIndexData(this: pBindState, nFieldIndex: v54);
            v53 = *(float *)&pBindState->m_FieldInfo.m_Memory.m_pMemory[v54].m_pVertexData;
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v34);
            CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
              this: &v34,
              pAttribute: (CDmAttribute *)LODWORD(v53));
            v58 = (v34.m_pStorage->m_Size + 7) >> 3;
            v11 = alloca(v58);
            v53 = COERCE_FLOAT(v33);
            memset(dst: (unsigned __int8 *)v33, value: 0, count: v58);
            m_Size = PositionData->m_Size;
            v54 = m_Size;
            if ( bUseNormalForSign )
            {
              v40 = CDmeVertexDataBase::GetVertexIndexData(this: pBindState, nFieldIndex: v57);
              NormalData = CDmeVertexDataBase::GetNormalData(this: pBindState);
              v55 = 0;
              if ( v54 > 0 )
              {
                v57 = 0;
                do
                {
                  v13 = (float *)((char *)&PositionData->m_Memory.m_pMemory->x + v57);
                  v14 = 0;
                  *(float *)&v14 = fsqrt((float)((float)(*v13 * *v13) + (float)(v13[1] * v13[1])) + (float)(v13[2] * v13[2]));
                  *(_OWORD *)&v33[2] = v14;
                  *(float *)&v14 = *(float *)&v14 * v35;
                  v45 = v14;
                  v49.m_pAttribute = (CDmAttribute *)(v14 ^ _mask__NegFloat_);
                  v36 = *(Vector *)v13;
                  VectorNormalize(vec: &v36);
                  VertexIndicesFromDataIndex = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                                 this: pBindState,
                                                 nFieldIndex: pBindState->m_pStandardFieldIndex[0],
                                                 nDataIndex: VertexIndexData->m_Memory.m_pMemory[v55]);
                  v16 = VertexIndicesFromDataIndex->m_Size;
                  v17 = 0;
                  v39 = VertexIndicesFromDataIndex;
                  v44 = (const CUtlVector<int,CUtlMemory<int,int> > *)v16;
                  v58 = 0;
                  if ( v16 > 0 )
                  {
                    while ( 1 )
                    {
                      v18 = (CDmAttribute *)&VertexIndicesFromDataIndex->m_Memory.m_pMemory[v17];
                      m_pMemory = v51->m_Memory.m_pMemory;
                      m_pIndexData = v18;
                      v50 = m_pMemory[(int)v18->m_pNext];
                      v56 = (_BYTE *)(LODWORD(v53) + (v50 >> 3));
                      if ( ((unsigned __int8)(1 << (v50 & 7)) & *v56) == 0 )
                      {
                        *v56 |= 1 << (v50 & 7);
                        v20 = &NormalData->m_Memory.m_pMemory[v40->m_Memory.m_pMemory[(int)m_pIndexData->m_pNext]];
                        v37 = *v20;
                        VectorNormalize(vec: &v37);
                        v56 = (_BYTE *)CDmeVertexDataBase::AddVertexData(
                                         this,
                                         nFieldIndex: (CDmrGenericArray)v9,
                                         nCount: 1);
                        v21 = v9;
                        m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pIndexData;
                        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v41);
                        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
                          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v41,
                          pAttribute: m_pIndexData);
                        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
                          this: &v41,
                          i: (int)v56,
                          nCount: 1,
                          pValue: &v50);
                        if ( (float)((float)((float)(v37.y * v36.y) + (float)(v37.x * v36.x)) + (float)(v36.z * v37.z)) >= 0.0 )
                        {
                          CDmrGenericArray::CDmrGenericArray(
                            this: &v43,
                            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pVertexData);
                          CDmrGenericArray::SetMultiple(
                            this: &v43,
                            i: (int)v56,
                            nCount: 1,
                            valueType: AT_FLOAT,
                            pValue: &v45);
                        }
                        else
                        {
                          CDmrGenericArray::CDmrGenericArray(
                            this: &v47,
                            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v21].m_pVertexData);
                          CDmrGenericArray::SetMultiple(
                            this: &v47,
                            i: (int)v56,
                            nCount: 1,
                            valueType: AT_FLOAT,
                            pValue: &v49);
                        }
                        v9 = Field;
                      }
                      v17 = v58 + 1;
                      v58 = v17;
                      if ( v17 >= (int)v44 )
                        break;
                      VertexIndicesFromDataIndex = v39;
                    }
                  }
                  v57 += 12;
                  ++v55;
                }
                while ( v55 < v54 );
              }
            }
            else
            {
              v57 = 0;
              if ( m_Size > 0 )
              {
                v55 = 0;
                do
                {
                  v22 = (float *)((char *)&PositionData->m_Memory.m_pMemory->x + v55);
                  v23 = v22[2];
                  v24 = v22[1];
                  v25 = *v22;
                  v26 = VertexIndexData->m_Memory.m_pMemory;
                  v27 = (float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v23 * v23);
                  v28 = 0;
                  *(float *)&v28 = fsqrt(v27);
                  *(_OWORD *)&v33[2] = v28;
                  *(float *)&v47.m_pAttribute = *(float *)&v28 * v35;
                  v29 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                          this: pBindState,
                          nFieldIndex: pBindState->m_pStandardFieldIndex[0],
                          nDataIndex: v26[v57]);
                  v30 = v29->m_Size;
                  v31 = 0;
                  v44 = v29;
                  v50 = v30;
                  v56 = nullptr;
                  if ( v30 > 0 )
                  {
                    while ( 1 )
                    {
                      v45 = v51->m_Memory.m_pMemory[v29->m_Memory.m_pMemory[v31]];
                      v58 = LODWORD(v53) + (v45 >> 3);
                      if ( ((unsigned __int8)(1 << (v45 & 7)) & *(_BYTE *)v58) == 0 )
                      {
                        *(_BYTE *)v58 |= 1 << (v45 & 7);
                        v58 = CDmeVertexDataBase::AddVertexData(this, nFieldIndex: (CDmrGenericArray)v9, nCount: 1);
                        v32 = v9;
                        v43.m_pAttribute = this->m_FieldInfo.m_Memory.m_pMemory[v32].m_pIndexData;
                        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v41);
                        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
                          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v41,
                          pAttribute: v43.m_pAttribute);
                        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
                          this: &v41,
                          i: v58,
                          nCount: 1,
                          pValue: &v45);
                        CDmrGenericArray::CDmrGenericArray(
                          this: &v49,
                          pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v32].m_pVertexData);
                        CDmrGenericArray::SetMultiple(this: &v49, i: v58, nCount: 1, valueType: AT_FLOAT, pValue: &v47);
                        v9 = Field;
                      }
                      v31 = (int)(v56 + 1);
                      v56 = (_BYTE *)v31;
                      if ( v31 >= v50 )
                        break;
                      v29 = v44;
                    }
                  }
                  v55 += 12;
                  ++v57;
                }
                while ( v57 < v54 );
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00504330
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504360
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005043E0
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504410
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504460
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005044B0
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00504530
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504560
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005045B0
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction();
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E8E10
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8ED0
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8F30
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECF80
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECF90
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECFA0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E8E40
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8E50
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E8E70
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8E80
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8E90
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8EA0
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8EB0
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8EC0
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8F00
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8F10
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E8F60
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8F70
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ECFB0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x005ECFC0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x005ECFD0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x005ECFE0
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x005ECFF0
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x005ED000
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x005ED010
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED020
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED030
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047CF70
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x0047CFE0
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(
    dst: (int)this->m_pStandardFieldIndex,
    value: (unsigned __int8 *)0xFF,
    count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x0047D0F0
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D160
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x0047D1E0
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x0047D270
// Name: public: void CDmeVertexDataBase::SetVertexData(int,int,int,enum DmAttributeType_t,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexData(
        CDmeVertexDataBase *this,
        CDmrGenericArray nFieldIndex,
        int nFirstVertex,
        int nCount,
        DmAttributeType_t valueType,
        const void *pData)
{
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::SetMultiple(this: &nFieldIndex, i: nFirstVertex, nCount, valueType, pValue: pData);
}

//------------------------------------------------------------------------------
// Address: 0x0047D2B0
// Name: public: int CDmeVertexDataBase::FindFieldIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::FindFieldIndex(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  CDmeVertexDataBase *v7; // [esp+Ch] [ebp-4h]

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  v7 = this;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_FieldInfo.m_Memory.m_pMemory[i].m_Name);
    if ( _V_stricmp(s1: v5, s2: pFieldName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    this = v7;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0047D4A0
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0047D540
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x0047D5B0
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x0047D640
// Name: protected: void CDmeVertexDataBase::FindOrAddVertexField(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::FindOrAddVertexField(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v4; // esi
  const char *m_pAsString; // eax

  m_Size = this->m_VertexFormat.m_Storage.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFieldName, a3: pFieldName);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
      this: &this->m_VertexFormat,
      src: (const CUtlSymbolLarge *)&pFieldName);
  }
  else
  {
    while ( 1 )
    {
      m_pAsString = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[v4].u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      if ( _V_stricmp(s1: pFieldName, s2: m_pAsString) == 0 )
        break;
      if ( ++v4 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D6B0
// Name: public: int CDmeVertexDataBase::AddVertexData(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::AddVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex, int nCount)
{
  CDmrGenericArray v4; // edi
  int v5; // ebx
  CDmAttribute *v6; // edi
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v4.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  v5 = CDmrGenericArrayConst::Count(this: &nFieldIndex);
  nCount += v5;
  CDmrGenericArray::EnsureCount(this: &nFieldIndex, num: nCount);
  if ( this->IsVertexDeltaData(this) )
  {
    v6 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v4.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: v6);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(this: &indices, num: nCount);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047D730
// Name: public: void CDmeVertexDataBase::SetVertexIndices(int,int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexIndices(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nFirstIndex,
        int nCount,
        const int *pIndices)
{
  CDmAttribute *m_pIndexData; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-8h] BYREF

  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
    pAttribute: m_pIndexData);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &array,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x0047D780
// Name: public: int CDmeVertexData::AddVertexIndices(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::AddVertexIndices(CDmeVertexData *this, int nIndexCount)
{
  int m_nVertexCount; // ecx
  int m_Size; // eax
  int v5; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // eax
  bool v7; // zf
  const CDmAttribute **p_m_pIndexData; // eax
  const CDmAttribute *v9; // ebx
  CDmrArray<int> indices; // [esp+4h] [ebp-Ch] BYREF
  int v12; // [esp+Ch] [ebp-4h]
  int nIndexCounta; // [esp+18h] [ebp+8h]

  m_nVertexCount = this->m_nVertexCount;
  m_Size = this->m_FieldInfo.m_Size;
  v12 = m_nVertexCount;
  this->m_nVertexCount = m_nVertexCount + nIndexCount;
  if ( m_Size > 0 )
  {
    v5 = 0;
    for ( nIndexCounta = m_Size; nIndexCounta != 0; --nIndexCounta )
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      v7 = m_pMemory[v5].m_pIndexData == nullptr;
      p_m_pIndexData = (const CDmAttribute **)&m_pMemory[v5].m_pIndexData;
      if ( !v7 )
      {
        v9 = *p_m_pIndexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
          pAttribute: v9);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
          this: &indices,
          num: this->m_nVertexCount);
        m_nVertexCount = v12;
      }
      ++v5;
    }
  }
  return m_nVertexCount;
}

//------------------------------------------------------------------------------
// Address: 0x0047DB90
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)Ptr;
        s2 = (char *)Ptr;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0047DE90
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DF00
// Name: public: int CDmeVertexDataBase::CreateField(char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, char *pFieldName, DmAttributeType_t type)
{
  int v4; // edi
  void *v5; // esp
  int FieldIndex; // edi
  CDmAttribute *m_pIndexData; // ebx
  char v9[12]; // [esp+0h] [ebp-14h] BYREF
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  if ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[5]) == 0
    || _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[6]) == 0 )
  {
    return -1;
  }
  if ( CDmElement::FindAttribute(this, pAttributeName: pFieldName) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: pFieldName, type);
  v4 = _V_strlen(str: pFieldName) + 21;
  v5 = alloca(v4);
  V_snprintf(pDest: v9, maxLen: v4, pFormat: "%sIndices", pFieldName);
  if ( CDmElement::FindAttribute(this, pAttributeName: v9) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v9, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName);
  if ( !this->IsVertexDeltaData(this) && this->m_nVertexCount > 0 )
  {
    m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[FieldIndex].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: m_pIndexData);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
      this: &indices,
      num: this->m_nVertexCount);
  }
  return FieldIndex;
}

//------------------------------------------------------------------------------
// Address: 0x0047E010
// Name: public: int CDmeVertexDataBase::CreateField(enum CDmeVertexDataBase::StandardFields_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, CDmeVertexDataBase::StandardFields_t fieldId)
{
  return CDmeVertexDataBase::CreateField(
           this,
           pFieldName: g_pStandardFieldNames[fieldId],
           type: g_pStandardFieldTypes[fieldId]);
}

//------------------------------------------------------------------------------
// Address: 0x0047E090
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E0C0
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E110
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047E160
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E190
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E220
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047E2A0
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E2D0
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E330
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00579510
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005795D0
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 176,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579630
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 192,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D830
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D840
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D850
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579540
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579550
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579570
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x00579580
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x00579590
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x005795A0
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x005795B0
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x005795C0
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x00579600
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579610
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579660
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579670
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D860
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x0057D870
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x0057D880
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x0057D890
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8A0
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8B0
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8C0
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8D0
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8E0
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00577A30
// Name: protected: void CDmeVertexDataBase::UpdateStandardFieldInfo(int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::UpdateStandardFieldInfo(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        const char *pFieldName,
        DmAttributeType_t attrType)
{
  int v5; // esi

  v5 = 0;
  while ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[v5]) != 0 )
  {
    if ( ++v5 >= 11 )
      return;
  }
  if ( attrType == g_pStandardFieldTypes[v5] )
    this->m_pStandardFieldIndex[v5] = nFieldIndex;
  else
    _Warning(a1: "Standard field %s has incorrect attribute type!\n", pFieldName);
}

//------------------------------------------------------------------------------
// Address: 0x00577AA0
// Name: protected: void CDmeVertexDataBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::OnConstruction(CDmeVertexDataBase *this)
{
  this->m_nVertexCount = 0;
  memset(dst: (unsigned __int8 *)this->m_pStandardFieldIndex, value: 0xFFu, count: sizeof(this->m_pStandardFieldIndex));
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_VertexFormat,
    pOwner: this,
    pAttributeName: "vertexFormat",
    nFlags: 0);
  this->m_nJointCount.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "jointCount",
                                       type: AT_INT,
                                       pMemory: &this->m_nJointCount);
  this->m_bFlipVCoordinates.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "flipVCoordinates",
                                             type: AT_BOOL,
                                             pMemory: &this->m_bFlipVCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x00577B10
// Name: protected: void CDmeVertexDataBase::ComputeVertexCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeVertexCount(CDmeVertexDataBase *this)
{
  int m_Size; // eax
  int v3; // edi
  int i; // ebx
  int v5; // eax
  CDmrGenericArray array; // [esp+8h] [ebp-4h] BYREF

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    this->m_nVertexCount = 0x7FFFFFFF;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        if ( this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData != nullptr )
        {
          CDmrGenericArray::CDmrGenericArray(
            this: &array,
            pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData);
          v5 = CDmrGenericArrayConst::Count(this: &array);
          if ( v5 < this->m_nVertexCount )
            this->m_nVertexCount = v5;
        }
        ++v3;
      }
    }
  }
  else
  {
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577B80
// Name: public: class Vector const __near & CDmeVertexDataBase::GetPosition(int)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmeVertexDataBase::GetPosition(CDmeVertexDataBase *this, int nIndex)
{
  int v3; // eax
  int v5; // esi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // esi
  CDmrArrayConst<Vector> vertexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  if ( v3 < 0 )
    return &vec3_origin;
  v5 = v3;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[indices.m_pStorage->m_Memory.m_pMemory[nIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00577C00
// Name: public: int const __near * CDmeVertexDataBase::GetJointIndices(int)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeVertexDataBase::GetJointIndices(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<int> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[6];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00577C90
// Name: public: void CDmeVertexDataBase::SetVertexData(int,int,int,enum DmAttributeType_t,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexData(
        CDmeVertexDataBase *this,
        CDmrGenericArray nFieldIndex,
        int nFirstVertex,
        int nCount,
        DmAttributeType_t valueType,
        const void *pData)
{
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  CDmrGenericArray::SetMultiple(this: &nFieldIndex, i: nFirstVertex, nCount, valueType, pValue: pData);
}

//------------------------------------------------------------------------------
// Address: 0x00577CD0
// Name: public: int CDmeVertexDataBase::FindFieldIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::FindFieldIndex(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  CDmeVertexDataBase *v7; // [esp+Ch] [ebp-4h]

  m_Size = this->m_FieldInfo.m_Size;
  v3 = 0;
  v7 = this;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_FieldInfo.m_Memory.m_pMemory[i].m_Name);
    if ( _V_stricmp(s1: v5, s2: pFieldName) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return -1;
    this = v7;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00577EC0
// Name: public: bool CDmeVertexDataBase::HasSkinningData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::HasSkinningData(CDmeVertexDataBase *this)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v6; // esi
  CDmrArrayConst<int> indexData; // [esp+4h] [ebp-10h] BYREF
  CDmrArrayConst<float> weightData; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_nJointCount.m_Storage == 0 )
    return false;
  v3 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 )
    return false;
  v4 = this->m_pStandardFieldIndex[6];
  if ( v4 < 0 )
    return false;
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&weightData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &weightData,
    pAttribute: m_pVertexData);
  v6 = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indexData);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indexData,
    pAttribute: v6);
  return weightData.m_pStorage->m_Size > 0 && indexData.m_pStorage->m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00577F60
// Name: protected: void CDmeVertexDeltaData::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::OnConstruction(CDmeVertexDeltaData *this)
{
  CDmaVar<bool> *p_m_bCorrected; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bCorrected = &this->m_bCorrected;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "corrected", type: AT_BOOL, pMemory: &this->m_bCorrected);
  p_m_bCorrected->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderVerts",
         type: AT_BOOL,
         pMemory: &this->m_bRenderVerts);
  this->m_bRenderVerts.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  this->m_bRenderVerts.m_pAttribute->m_nFlags |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x00577FD0
// Name: public: float const __near * CDmeVertexDataBase::GetJointWeights(int)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDmeVertexDataBase::GetJointWeights(CDmeVertexDataBase *this, int nVertexIndex)
{
  int v3; // eax
  int v4; // edi
  CDmAttribute *m_pIndexData; // ebx
  CDmAttribute *m_pVertexData; // edi
  CDmrArrayConst<float> vertexData; // [esp+8h] [ebp-10h] BYREF
  CDmrArrayConst<int> indices; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_pStandardFieldIndex[0];
  v4 = this->m_pStandardFieldIndex[5];
  if ( v3 < 0 || v4 < 0 )
    return nullptr;
  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &indices,
    pAttribute: m_pIndexData);
  m_pVertexData = this->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&vertexData);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &vertexData,
    pAttribute: m_pVertexData);
  return &vertexData.m_pStorage->m_Memory.m_pMemory[this->m_nJointCount.m_Storage
                                                  * indices.m_pStorage->m_Memory.m_pMemory[nVertexIndex]];
}

//------------------------------------------------------------------------------
// Address: 0x00578060
// Name: protected: void CDmeVertexDataBase::FindOrAddVertexField(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::FindOrAddVertexField(CDmeVertexDataBase *this, const char *pFieldName)
{
  int m_Size; // ebx
  int v4; // esi
  const char *m_pAsString; // eax

  m_Size = this->m_VertexFormat.m_Storage.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFieldName, a3: pFieldName);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
      this: &this->m_VertexFormat,
      src: (const CUtlSymbolLarge *)&pFieldName);
  }
  else
  {
    while ( 1 )
    {
      m_pAsString = this->m_VertexFormat.m_Storage.m_Memory.m_pMemory[v4].u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      if ( _V_stricmp(s1: pFieldName, s2: m_pAsString) == 0 )
        break;
      if ( ++v4 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005780D0
// Name: public: int CDmeVertexDataBase::AddVertexData(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::AddVertexData(CDmeVertexDataBase *this, CDmrGenericArray nFieldIndex, int nCount)
{
  CDmrGenericArray v4; // edi
  int v5; // ebx
  CDmAttribute *v6; // edi
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  v4.m_pAttribute = (CDmAttribute *)(6 * (int)nFieldIndex.m_pAttribute);
  CDmrGenericArray::CDmrGenericArray(
    this: &nFieldIndex,
    pAttribute: this->m_FieldInfo.m_Memory.m_pMemory[(int)nFieldIndex.m_pAttribute].m_pVertexData);
  v5 = CDmrGenericArrayConst::Count(this: &nFieldIndex);
  nCount += v5;
  CDmrGenericArray::EnsureCount(this: &nFieldIndex, num: nCount);
  if ( this->IsVertexDeltaData(this) )
  {
    v6 = *(&this->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + 2 * (int)v4.m_pAttribute);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: v6);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(this: &indices, num: nCount);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00578150
// Name: public: void CDmeVertexDataBase::SetVertexIndices(int,int,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::SetVertexIndices(
        CDmeVertexDataBase *this,
        int nFieldIndex,
        int nFirstIndex,
        int nCount,
        const int *pIndices)
{
  CDmAttribute *m_pIndexData; // esi
  CDmrArray<int> array; // [esp+4h] [ebp-8h] BYREF

  m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[nFieldIndex].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&array,
    pAttribute: m_pIndexData);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &array,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x005781A0
// Name: public: int CDmeVertexData::AddVertexIndices(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::AddVertexIndices(CDmeVertexData *this, int nIndexCount)
{
  int m_nVertexCount; // ecx
  int m_Size; // eax
  int v5; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // eax
  bool v7; // zf
  CDmAttribute **p_m_pIndexData; // eax
  CDmAttribute *v9; // ebx
  CDmrArray<int> indices; // [esp+4h] [ebp-Ch] BYREF
  int v12; // [esp+Ch] [ebp-4h]
  int nIndexCounta; // [esp+18h] [ebp+8h]

  m_nVertexCount = this->m_nVertexCount;
  m_Size = this->m_FieldInfo.m_Size;
  v12 = m_nVertexCount;
  this->m_nVertexCount = m_nVertexCount + nIndexCount;
  if ( m_Size > 0 )
  {
    v5 = 0;
    for ( nIndexCounta = m_Size; nIndexCounta != 0; --nIndexCounta )
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      v7 = m_pMemory[v5].m_pIndexData == nullptr;
      p_m_pIndexData = &m_pMemory[v5].m_pIndexData;
      if ( !v7 )
      {
        v9 = *p_m_pIndexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
          pAttribute: v9);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
          this: &indices,
          num: this->m_nVertexCount);
        m_nVertexCount = v12;
      }
      ++v5;
    }
  }
  return m_nVertexCount;
}

//------------------------------------------------------------------------------
// Address: 0x005785B0
// Name: protected: void CDmeVertexDataBase::ComputeFieldInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::ComputeFieldInfo(CDmeVertexDataBase *this)
{
  CDmeVertexDataBase *v1; // ebx
  int m_Size; // ecx
  int v3; // eax
  char *m_pFixedMemory; // eax
  int v5; // ecx
  CUtlSymbolLarge *m_pMemory; // edx
  char *m_Id; // eax
  char *v8; // esi
  CDmAttribute *v9; // edi
  int v10; // eax
  int v11; // esi
  IMemAlloc_vtbl *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  CDmAttribute *Attribute; // eax
  int v16; // edi
  CDmAttribute *v17; // eax
  CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int> > *p_m_FieldInfo; // esi
  int v19; // ebx
  const char *v20; // eax
  CDmAttribute *v21; // eax
  int v22; // edi
  char *v23; // [esp-8h] [ebp-148h]
  CUtlVectorFixedGrowable<char,256> indicesName; // [esp+8h] [ebp-138h] BYREF
  int nFieldCount; // [esp+120h] [ebp-20h]
  int num; // [esp+124h] [ebp-1Ch]
  int i; // [esp+128h] [ebp-18h]
  int v28; // [esp+12Ch] [ebp-14h]
  CDmeVertexDataBase *v29; // [esp+130h] [ebp-10h]
  CDmAttribute *pVerticesArray; // [esp+134h] [ebp-Ch]
  CDmAttribute *pIndicesArray; // [esp+138h] [ebp-8h]
  char *s2; // [esp+13Ch] [ebp-4h]

  v1 = this;
  m_Size = this->m_FieldInfo.m_Size;
  v29 = v1;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      v1->m_FieldInfo.m_Memory.m_pMemory[v3].m_pIndexData = nullptr;
      v1->m_FieldInfo.m_Memory.m_pMemory[v3++].m_pVertexData = nullptr;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  m_pFixedMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_pElements = indicesName.m_Memory.m_pFixedMemory;
  v5 = v1->m_VertexFormat.m_Storage.m_Size;
  indicesName.m_Memory.m_pMemory = indicesName.m_Memory.m_pFixedMemory;
  indicesName.m_Memory.m_nAllocationCount = 256;
  indicesName.m_Memory.m_nGrowSize = -1;
  indicesName.m_Memory.m_nMallocGrowSize = 0;
  indicesName.m_Size = 0;
  nFieldCount = v5;
  i = 0;
  if ( v5 > 0 )
  {
    do
    {
      m_pMemory = v1->m_VertexFormat.m_Storage.m_Memory.m_pMemory;
      m_Id = (char *)m_pMemory[i].u.m_Id;
      if ( m_Id == (char *)-1 )
      {
        v8 = (char *)var;
        s2 = (char *)var;
      }
      else
      {
        s2 = (char *)m_pMemory[i].u.m_Id;
        v8 = m_Id;
      }
      v9 = (CDmAttribute *)(_V_strlen(str: v8) + 21);
      v10 = indicesName.m_Size;
      pVerticesArray = v9;
      if ( indicesName.m_Size < (int)v9 )
      {
        v11 = (int)v9 - indicesName.m_Size;
        v28 = indicesName.m_Size;
        if ( v9 != (CDmAttribute *)indicesName.m_Size )
        {
          if ( (int)v9 > indicesName.m_Memory.m_nAllocationCount )
          {
            num = (int)v9 - indicesName.m_Memory.m_nAllocationCount;
            if ( indicesName.m_Memory.m_nGrowSize < 0 )
            {
              indicesName.m_Memory.m_nGrowSize = indicesName.m_Memory.m_nMallocGrowSize;
              if ( indicesName.m_Memory.m_nAllocationCount != 0 )
              {
                v12 = _g_pMemAlloc->__vftable;
                pIndicesArray = (CDmAttribute *)indicesName.m_Memory.m_nAllocationCount;
                v13 = (unsigned __int8 *)v12->Alloc_2(this: _g_pMemAlloc, a2: indicesName.m_Memory.m_nAllocationCount);
                memcpy(
                  dst: v13,
                  src: (unsigned __int8 *)indicesName.m_Memory.m_pMemory,
                  count: (unsigned int)pIndicesArray);
                indicesName.m_Memory.m_pMemory = (char *)v13;
                v9 = pVerticesArray;
              }
              else
              {
                indicesName.m_Memory.m_pMemory = nullptr;
              }
            }
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<bool,int> *)&indicesName, num);
            v10 = indicesName.m_Size;
          }
          indicesName.m_Size = v11 + v10;
          v14 = v10 - v28;
          indicesName.m_pElements = indicesName.m_Memory.m_pMemory;
          if ( v14 > 0 && v11 > 0 )
            _V_memmove(
              dest: &indicesName.m_Memory.m_pMemory[v28 + v11],
              src: &indicesName.m_Memory.m_pMemory[v28],
              count: v14);
        }
        v8 = s2;
      }
      V_snprintf(pDest: indicesName.m_Memory.m_pMemory, maxLen: (int)v9, pFormat: "%sIndices", v8);
      Attribute = CDmElement::FindAttribute(this: v1, pAttributeName: v8);
      v16 = 0;
      pVerticesArray = Attribute;
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1Fu) - 15 <= 0xD )
      {
        pIndicesArray = nullptr;
        if ( _V_stricmp(s1: v8, s2: g_pStandardFieldNames[5]) == 0
          || _V_stricmp(s1: v8, s2: g_pStandardFieldNames[6]) == 0
          || (v17 = CDmElement::FindAttribute(this: v1, pAttributeName: indicesName.m_Memory.m_pMemory),
              pIndicesArray = v17,
              v17 != nullptr)
          && (v17->m_nFlags & 0x1F) == 0x10 )
        {
          v28 = v1->m_FieldInfo.m_Size;
          if ( v28 > 0 )
          {
            p_m_FieldInfo = &v1->m_FieldInfo;
            v19 = 0;
            while ( 1 )
            {
              v23 = s2;
              v20 = CUtlString::operator char const *(this: &p_m_FieldInfo->m_Memory.m_pMemory[v19].m_Name);
              if ( _V_stricmp(s1: v20, s2: v23) == 0 )
                break;
              ++v16;
              ++v19;
              if ( v16 >= v28 )
                goto LABEL_32;
            }
            if ( v16 >= 0 )
              goto LABEL_34;
LABEL_32:
            v1 = v29;
          }
          p_m_FieldInfo = &v1->m_FieldInfo;
          v16 = CUtlVector<CDmeVertexDataBase::FieldInfo_t,CUtlMemory<CDmeVertexDataBase::FieldInfo_t,int>>::InsertBefore(
                  this: &v1->m_FieldInfo,
                  elem: v1->m_FieldInfo.m_Size);
          CUtlString::operator=(this: &v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_Name, src: s2);
          v21 = pVerticesArray;
          v1->m_FieldInfo.m_Memory.m_pMemory[v16].m_bInverseMapDirty = true;
          CDmeVertexDataBase::UpdateStandardFieldInfo(
            this: v29,
            nFieldIndex: v16,
            pFieldName: s2,
            attrType: (DmAttributeType_t)(v21->m_nFlags & 0x1F));
LABEL_34:
          v1 = v29;
          v22 = v16;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pVertexData = pVerticesArray;
          p_m_FieldInfo->m_Memory.m_pMemory[v22].m_pIndexData = pIndicesArray;
        }
      }
      ++i;
    }
    while ( i < nFieldCount );
    m_pFixedMemory = indicesName.m_Memory.m_pMemory;
  }
  indicesName.m_Size = 0;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      indicesName.m_Memory.m_pMemory = nullptr;
    }
    indicesName.m_Memory.m_nAllocationCount = 0;
  }
  indicesName.m_pElements = m_pFixedMemory;
  if ( indicesName.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005788B0
// Name: public: virtual void CDmeVertexDataBase::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::Resolve(CDmeVertexDataBase *this)
{
  int v2; // edx
  int m_Size; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pIndexData; // eax

  if ( SLOBYTE(this->m_VertexFormat.m_pAttribute->m_nFlags) < 0 )
    CDmeVertexDataBase::ComputeFieldInfo(this);
  if ( !this->IsVertexDeltaData(this) )
    CDmeVertexDataBase::ComputeVertexCount(this);
  if ( this->m_FieldInfo.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_FieldInfo.m_Size;
    do
    {
      m_pMemory = this->m_FieldInfo.m_Memory.m_pMemory;
      m_pIndexData = m_pMemory[v2].m_pIndexData;
      if ( m_pIndexData != nullptr && SLOBYTE(m_pIndexData->m_nFlags) < 0 )
        m_pMemory[v2].m_bInverseMapDirty = true;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00578920
// Name: public: int CDmeVertexDataBase::CreateField(char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, char *pFieldName, DmAttributeType_t type)
{
  int v4; // edi
  void *v5; // esp
  int FieldIndex; // edi
  CDmAttribute *m_pIndexData; // ebx
  char v9[12]; // [esp+0h] [ebp-14h] BYREF
  CDmrArray<int> indices; // [esp+Ch] [ebp-8h] BYREF

  if ( _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[5]) == 0
    || _V_stricmp(s1: pFieldName, s2: g_pStandardFieldNames[6]) == 0 )
  {
    return -1;
  }
  if ( CDmElement::FindAttribute(this, pAttributeName: pFieldName) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: pFieldName, type);
  v4 = _V_strlen(str: pFieldName) + 21;
  v5 = alloca(v4);
  V_snprintf(pDest: v9, maxLen: v4, pFormat: "%sIndices", pFieldName);
  if ( CDmElement::FindAttribute(this, pAttributeName: v9) == nullptr )
    CDmElement::CreateAttribute(this, pAttributeName: v9, type: AT_INT_ARRAY);
  CDmeVertexDataBase::FindOrAddVertexField(this, pFieldName);
  CDmeVertexDataBase::ComputeFieldInfo(this);
  FieldIndex = CDmeVertexDataBase::FindFieldIndex(this, pFieldName);
  if ( !this->IsVertexDeltaData(this) && this->m_nVertexCount > 0 )
  {
    m_pIndexData = this->m_FieldInfo.m_Memory.m_pMemory[FieldIndex].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&indices);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&indices,
      pAttribute: m_pIndexData);
    CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
      this: &indices,
      num: this->m_nVertexCount);
  }
  return FieldIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00578A30
// Name: public: int CDmeVertexDataBase::CreateField(enum CDmeVertexDataBase::StandardFields_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::CreateField(CDmeVertexDataBase *this, CDmeVertexDataBase::StandardFields_t fieldId)
{
  return CDmeVertexDataBase::CreateField(
           this,
           pFieldName: g_pStandardFieldNames[fieldId],
           type: g_pStandardFieldTypes[fieldId]);
}

//------------------------------------------------------------------------------
// Address: 0x00578AB0
// Name: public: virtual bool CDmeVertexDataBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDataBase::IsA(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00578AE0
// Name: public: virtual int CDmeVertexDataBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDataBase::GetInheritanceDepth(CDmeVertexDataBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00578B20
// Name: protected: virtual void CDmeVertexDataBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDataBase::PerformConstruction(CDmeVertexData *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeVertexDataBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00578B70
// Name: public: virtual bool CDmeVertexData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexData::IsA(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00578BA0
// Name: public: virtual int CDmeVertexData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexData::GetInheritanceDepth(CDmeVertexData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00578C40
// Name: protected: CDmeVertexDeltaData::CDmeVertexDeltaData(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmeVertexDeltaData::CDmeVertexDeltaData(
        CDmeVertexDeltaData *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDataBase::`vftable';
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_VertexFormat);
  this->m_nJointCount.m_pAttribute = nullptr;
  this->m_nJointCount.m_Storage = 0;
  this->m_bFlipVCoordinates.m_pAttribute = nullptr;
  this->m_bFlipVCoordinates.m_Storage = false;
  this->m_FieldInfo.m_Memory.m_pMemory = nullptr;
  this->m_FieldInfo.m_Memory.m_nAllocationCount = 0;
  this->m_FieldInfo.m_Memory.m_nGrowSize = 0;
  this->m_FieldInfo.m_Size = 0;
  this->m_FieldInfo.m_pElements = nullptr;
  this->__vftable = (CDmeVertexDeltaData_vtbl *)&CDmeVertexDeltaData::`vftable';
  this->m_bCorrected.m_pAttribute = nullptr;
  this->m_bCorrected.m_Storage = false;
  this->m_bRenderVerts.m_pAttribute = nullptr;
  this->m_bRenderVerts.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00578CC0
// Name: public: virtual bool CDmeVertexDeltaData::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeVertexDeltaData::IsA(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00578CF0
// Name: public: virtual int CDmeVertexDeltaData::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeVertexDeltaData::GetInheritanceDepth(CDmeVertexDeltaData *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeVertexDeltaData::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeVertexDataBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00578D50
// Name: protected: virtual void CDmeVertexDeltaData::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeVertexDeltaData::PerformConstruction(CDmeVertexDeltaData *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeVertexDataBase::OnConstruction(this);
  CDmeVertexDeltaData::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B72F0
// Name: _dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDataBase::s_Allocator,
    blockSize: 0xB0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDataBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B73B0
// Name: _dynamic_initializer_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexData::s_Allocator,
    blockSize: 0xB0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7410
// Name: _dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeVertexDeltaData::s_Allocator,
    blockSize: 0xC0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeVertexDeltaData pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC5A0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDataBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDataBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC5B0
// Name: _dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC5C0
// Name: _dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeVertexDeltaData::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeVertexDeltaData::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B7320
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDataBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7330
// Name: _dynamic_initializer_for__g_CDmeVertexDataBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDataBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDataBase_Helper,
           classname: "DmeVertexDataBase",
           pFactory: &g_CDmeVertexDataBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7350
// Name: _dynamic_initializer_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector4D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector4D__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7360
// Name: _dynamic_initializer_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7370
// Name: _dynamic_initializer_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyVector2D__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyVector2D__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7380
// Name: _dynamic_initializer_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyColor__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyColor__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7390
// Name: _dynamic_initializer_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyFloat__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyFloat__);
}

//------------------------------------------------------------------------------
// Address: 0x006B73A0
// Name: _dynamic_initializer_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyInt__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyInt__);
}

//------------------------------------------------------------------------------
// Address: 0x006B73E0
// Name: _dynamic_initializer_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B73F0
// Name: _dynamic_initializer_for__g_CDmeVertexData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexData_Helper,
           classname: "DmeVertexData",
           pFactory: &g_CDmeVertexData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7440
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeVertexDeltaData_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7450
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeVertexDeltaData_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeVertexDeltaData_Helper,
           classname: "DmeVertexDeltaData",
           pFactory: &g_CDmeVertexDeltaData_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC5D0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector4D__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyVector4D);
}

//------------------------------------------------------------------------------
// Address: 0x006BC5E0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyVector);
}

//------------------------------------------------------------------------------
// Address: 0x006BC5F0
// Name: _dynamic_atexit_destructor_for__s_EmptyVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyVector2D__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyVector2D);
}

//------------------------------------------------------------------------------
// Address: 0x006BC600
// Name: _dynamic_atexit_destructor_for__s_EmptyColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyColor__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyColor);
}

//------------------------------------------------------------------------------
// Address: 0x006BC610
// Name: _dynamic_atexit_destructor_for__s_EmptyFloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyFloat__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyFloat);
}

//------------------------------------------------------------------------------
// Address: 0x006BC620
// Name: _dynamic_atexit_destructor_for__s_EmptyInt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyInt__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyInt);
}

//------------------------------------------------------------------------------
// Address: 0x006BC630
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexData_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeVertexData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC640
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDeltaData_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeVertexDeltaData_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC650
// Name: _dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeVertexDataBase_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeVertexDataBase_Factory.m_CallBackList);
}

} // namespace vmap
