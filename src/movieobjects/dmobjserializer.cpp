// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmobjserializer.cpp
// Functions: 26
// ============================================================

#include "movieobjects\dmobjserializer.h"

//------------------------------------------------------------------------------
// Address: 0x004AE580
// Name: private: static char const __near * CDmObjSerializer::SkipSpace(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmObjSerializer::SkipSpace(const char *pBuf)
{
  const char *result; // eax

  for ( result = pBuf; *result == 32 || *result == 9; ++result )
    ;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AE5A0
// Name: private: static bool CDmObjSerializer::ParseVertex(class CUtlBuffer __near &,struct characterset_t __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmObjSerializer::ParseVertex(CUtlBuffer *bufParse, characterset_t *breakSet, int *v, int *t, int *n)
{
  char cmd[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: 0) <= 0 )
    return 0;
  *v = atoi(nptr: cmd);
  *n = 0;
  *t = 0;
  if ( breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0 )
  {
    CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: 0);
    if ( breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0
      || (CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: 0),
          *t = atoi(nptr: cmd),
          breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0) )
    {
      CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: 0);
      CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: 0);
      *n = atoi(nptr: cmd);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE6C0
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AE7C0
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) != 0 )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AE970
// Name: protected: class CDmeVertexDataBase __near * CVertexData::Add(class CDmeMesh __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexData *__thiscall CVertexData::Add(CVertexData *this, CDmeMesh *pMesh, const char *pName)
{
  CDmeVertexData *result; // eax
  const char *v5; // ebx
  CDmeVertexData *BaseState; // edi
  CDmAttribute *m_pAttribute; // ecx
  int Field; // ebx
  int v9; // ebx
  int v10; // ebx

  result = nullptr;
  if ( this->m_positions.m_Size != 0 && this->m_pIndices.m_Size != 0 )
  {
    v5 = pName;
    BaseState = CDmeMesh::FindOrCreateBaseState(this: pMesh, pStateName: (int)pName);
    CDmeMesh::SetCurrentBaseState(this: pMesh, pStateName: v5);
    CDmeVertexData::AddVertexIndices(this: BaseState, nIndexCount: this->m_pIndices.m_Size);
    m_pAttribute = BaseState->m_bFlipVCoordinates.m_pAttribute;
    LOBYTE(pMesh) = 1;
    CDmAttribute::SetValue<bool>(this: m_pAttribute, value: (const bool *)&pMesh);
    Field = CDmeVertexDataBase::CreateField(this: BaseState, fieldId: FIELD_POSITION);
    CDmeVertexDataBase::AddVertexData(
      this: BaseState,
      nFieldIndex: (CDmrGenericArray)Field,
      nCount: this->m_positions.m_Size);
    CDmeVertexDataBase::SetVertexData(
      this: BaseState,
      nFieldIndex: (CDmrGenericArray)Field,
      nFirstVertex: 0,
      nCount: this->m_positions.m_Size,
      valueType: AT_VECTOR3,
      pData: this->m_positions.m_Memory.m_pMemory);
    CDmeVertexDataBase::SetVertexIndices(
      this: BaseState,
      nFieldIndex: Field,
      nFirstIndex: 0,
      nCount: this->m_pIndices.m_Size,
      pIndices: this->m_pIndices.m_Memory.m_pMemory);
    if ( this->m_normals.m_Size != 0 && this->m_nIndices.m_Size != 0 )
    {
      v9 = CDmeVertexDataBase::CreateField(this: BaseState, fieldId: FIELD_NORMAL);
      CDmeVertexDataBase::AddVertexData(
        this: BaseState,
        nFieldIndex: (CDmrGenericArray)v9,
        nCount: this->m_normals.m_Size);
      CDmeVertexDataBase::SetVertexData(
        this: BaseState,
        nFieldIndex: (CDmrGenericArray)v9,
        nFirstVertex: 0,
        nCount: this->m_normals.m_Size,
        valueType: AT_VECTOR3,
        pData: this->m_normals.m_Memory.m_pMemory);
      CDmeVertexDataBase::SetVertexIndices(
        this: BaseState,
        nFieldIndex: v9,
        nFirstIndex: 0,
        nCount: this->m_nIndices.m_Size,
        pIndices: this->m_nIndices.m_Memory.m_pMemory);
    }
    if ( this->m_uvs.m_Size != 0 && this->m_uvIndices.m_Size != 0 )
    {
      v10 = CDmeVertexDataBase::CreateField(this: BaseState, fieldId: FIELD_TEXCOORD);
      CDmeVertexDataBase::AddVertexData(this: BaseState, nFieldIndex: (CDmrGenericArray)v10, nCount: this->m_uvs.m_Size);
      CDmeVertexDataBase::SetVertexData(
        this: BaseState,
        nFieldIndex: (CDmrGenericArray)v10,
        nFirstVertex: 0,
        nCount: this->m_uvs.m_Size,
        valueType: AT_VECTOR2,
        pData: this->m_uvs.m_Memory.m_pMemory);
      CDmeVertexDataBase::SetVertexIndices(
        this: BaseState,
        nFieldIndex: v10,
        nFirstIndex: 0,
        nCount: this->m_uvIndices.m_Size,
        pIndices: this->m_uvIndices.m_Memory.m_pMemory);
    }
    return BaseState;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AEAA0
// Name: protected: class CDmeVertexDeltaData __near * CVertexData::AddDelta(class CDmeMesh __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CVertexData::AddDelta(CVertexData *this, CDmeMesh *pMesh, int bAbsolute, int pName)
{
  bool v5; // zf
  CDmeVertexData *BaseState; // eax
  int v8; // ecx
  CDmAttribute *m_pVertexData; // edi
  int m_Size; // ecx
  int v11; // eax
  int v12; // ecx
  Vector *m_pMemory; // edx
  Vector *v14; // eax
  Vector *v15; // edx
  Vector *v16; // eax
  Vector *v17; // edx
  Vector *v18; // eax
  float v19; // xmm0_4
  Vector *v20; // eax
  Vector *v21; // edx
  Vector *v22; // eax
  float v23; // xmm0_4
  int v24; // edx
  int v25; // edi
  Vector *v26; // ecx
  Vector *v27; // eax
  float v28; // xmm0_4
  void *v29; // esp
  int v30; // ebx
  int v31; // edi
  int v32; // eax
  int v33; // ecx
  Vector *v34; // edx
  Vector *v35; // edx
  Vector *v36; // edx
  Vector *v37; // edx
  int v38; // edx
  unsigned int v39; // ecx
  Vector *v40; // eax
  CDmeVertexDeltaData *DeltaState; // ebx
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *Attribute; // eax
  DmAttributeHandle_t m_Handle; // eax
  CDmAttribute *v45; // edi
  int v46; // eax
  unsigned int v47; // ecx
  Vector *v48; // eax
  DmeTime_t *v49; // edx
  DmeTime_t *v50; // edx
  Vector *v51; // eax
  Vector *v52; // eax
  DmeTime_t *v53; // edx
  float v54; // xmm0_4
  Vector *v55; // eax
  DmeTime_t *v56; // edx
  Vector *v57; // eax
  float v58; // xmm0_4
  float *p_x; // eax
  float v60; // xmm0_4
  unsigned int v61; // edx
  int v62; // edi
  Vector *v63; // eax
  DmeTime_t *v64; // ecx
  float v65; // xmm0_4
  float *v66; // eax
  float v67; // xmm0_4
  int v68; // edi
  void *v69; // esp
  CDmeMesh *v70; // ebx
  int v71; // edx
  int v72; // eax
  int v73; // ecx
  Vector *v74; // edi
  Vector *v75; // edi
  int *v76; // ebx
  Vector *v77; // edi
  int *v78; // ebx
  Vector *v79; // edi
  int *v80; // ebx
  int v81; // edi
  int v82; // ecx
  int *v83; // edx
  Vector *v84; // eax
  _DWORD v85[3]; // [esp+0h] [ebp-2Ch] BYREF
  CDmrArrayConst<Vector> pBindData; // [esp+Ch] [ebp-20h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v87; // [esp+14h] [ebp-18h] BYREF
  int *pNormalIndices; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int pCount; // [esp+24h] [ebp-8h]
  int v91; // [esp+28h] [ebp-4h]

  v5 = this->m_positions.m_Size == 0;
  pCount = 0;
  if ( !v5 )
  {
    BaseState = CDmeMesh::FindBaseState(this: pMesh, pStateName: "bind");
    v87.m_pAttribute = (CDmAttribute *)BaseState;
    if ( BaseState == nullptr )
      return nullptr;
    v8 = BaseState->m_pStandardFieldIndex[0];
    if ( v8 < 0 )
      return nullptr;
    m_pVertexData = BaseState->m_FieldInfo.m_Memory.m_pMemory[v8].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&pBindData);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &pBindData,
      pAttribute: m_pVertexData);
    m_Size = this->m_positions.m_Size;
    pCount = m_Size;
    if ( pBindData.m_pStorage->m_Size != m_Size )
      return nullptr;
    v11 = 0;
    if ( m_Size >= 4 )
    {
      v12 = 0;
      pNormalIndices = (int *)(((unsigned int)(pCount - 4) >> 2) + 1);
      i = 4 * (_DWORD)pNormalIndices;
      do
      {
        m_pMemory = pBindData.m_pStorage->m_Memory.m_pMemory;
        v14 = this->m_positions.m_Memory.m_pMemory;
        v14[v12].x = this->m_positions.m_Memory.m_pMemory[v12].x - pBindData.m_pStorage->m_Memory.m_pMemory[v12].x;
        v14[v12].y = v14[v12].y - m_pMemory[v12].y;
        v14[v12].z = v14[v12].z - m_pMemory[v12].z;
        v15 = &pBindData.m_pStorage->m_Memory.m_pMemory[v12 + 1];
        v16 = this->m_positions.m_Memory.m_pMemory;
        v16[v12 + 1].x = this->m_positions.m_Memory.m_pMemory[v12 + 1].x - v15->x;
        v16[v12 + 1].y = v16[v12 + 1].y - v15->y;
        v16[v12 + 1].z = v16[v12 + 1].z - v15->z;
        v17 = pBindData.m_pStorage->m_Memory.m_pMemory;
        v18 = this->m_positions.m_Memory.m_pMemory;
        v18[v12 + 2].x = this->m_positions.m_Memory.m_pMemory[v12 + 2].x
                       - pBindData.m_pStorage->m_Memory.m_pMemory[v12 + 2].x;
        v19 = v18[v12 + 2].y - v17[v12 + 2].y;
        v20 = &v18[v12 + 2];
        v20->y = v19;
        v20->z = v20->z - v17[v12 + 2].z;
        v21 = pBindData.m_pStorage->m_Memory.m_pMemory;
        v22 = &this->m_positions.m_Memory.m_pMemory[v12 + 3];
        v22->x = v22->x - pBindData.m_pStorage->m_Memory.m_pMemory[v12 + 3].x;
        v22->y = v22->y - v21[v12 + 3].y;
        v23 = v22->z - v21[v12 + 3].z;
        v12 += 4;
        v5 = pNormalIndices == (int *)1;
        pNormalIndices = (int *)((char *)pNormalIndices - 1);
        v22->z = v23;
      }
      while ( !v5 );
      v11 = i;
    }
    if ( v11 < pCount )
    {
      v24 = v11;
      v25 = pCount - v11;
      do
      {
        v26 = pBindData.m_pStorage->m_Memory.m_pMemory;
        v27 = &this->m_positions.m_Memory.m_pMemory[v24];
        v27->x = v27->x - pBindData.m_pStorage->m_Memory.m_pMemory[v24].x;
        v27->y = v27->y - v26[v24].y;
        v28 = v27->z - v26[v24++].z;
        --v25;
        v27->z = v28;
      }
      while ( v25 != 0 );
    }
    v29 = alloca(4 * pCount);
    v30 = 0;
    v31 = 0;
    i = (int)v85;
    v91 = 0;
    if ( pCount >= 4 )
    {
      v32 = 0;
      pNormalIndices = (int *)2;
      v33 = 0;
      do
      {
        v34 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v33].x) >= 0.00024414062
          || fabs(v34[v33].y) >= 0.00024414062
          || fabs(v34[v33].z) >= 0.00024414062 )
        {
          v34[v32].x = this->m_positions.m_Memory.m_pMemory[v33].x;
          v34[v32].y = v34[v33].y;
          ++v31;
          v34[v32++].z = v34[v33].z;
          v85[v31 - 1] = v30;
        }
        v35 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v33 + 1].x) >= 0.00024414062
          || fabs(v35[v33 + 1].y) >= 0.00024414062
          || fabs(v35[v33 + 1].z) >= 0.00024414062 )
        {
          v35[v32].x = this->m_positions.m_Memory.m_pMemory[v33 + 1].x;
          v35[v32].y = v35[v33 + 1].y;
          ++v31;
          v35[v32].z = v35[v33 + 1].z;
          v85[v31 - 1] = (char *)pNormalIndices - 1;
          v30 = v91;
          ++v32;
        }
        v36 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v33 + 2].x) >= 0.00024414062
          || fabs(v36[v33 + 2].y) >= 0.00024414062
          || fabs(v36[v33 + 2].z) >= 0.00024414062 )
        {
          v36[v32].x = this->m_positions.m_Memory.m_pMemory[v33 + 2].x;
          v36[v32].y = v36[v33 + 2].y;
          ++v31;
          v36[v32].z = v36[v33 + 2].z;
          v85[v31 - 1] = pNormalIndices;
          v30 = v91;
          ++v32;
        }
        v37 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v33 + 3].x) >= 0.00024414062
          || fabs(v37[v33 + 3].y) >= 0.00024414062
          || fabs(v37[v33 + 3].z) >= 0.00024414062 )
        {
          v37[v32].x = this->m_positions.m_Memory.m_pMemory[v33 + 3].x;
          v37[v32].y = v37[v33 + 3].y;
          ++v31;
          v37[v32].z = v37[v33 + 3].z;
          v85[v31 - 1] = (char *)pNormalIndices + 1;
          v30 = v91;
          ++v32;
        }
        ++pNormalIndices;
        v30 += 4;
        v33 += 4;
        v91 = v30;
      }
      while ( v30 < pCount - 3 );
    }
    if ( v30 < pCount )
    {
      v38 = v31;
      v39 = v30;
      do
      {
        v40 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v39].x) >= 0.00024414062
          || fabs(v40[v39].y) >= 0.00024414062
          || fabs(v40[v39].z) >= 0.00024414062 )
        {
          v40[v38].x = this->m_positions.m_Memory.m_pMemory[v39].x;
          v40[v38].y = v40[v39].y;
          ++v31;
          v40[v38++].z = v40[v39].z;
          v85[v31 - 1] = v30;
        }
        ++v30;
        ++v39;
      }
      while ( v30 < pCount );
    }
    DeltaState = CDmeMesh::FindOrCreateDeltaState(this: pMesh, pInDeltaName: (char *)pName, bSortDeltaName: 1);
    m_pAttribute = DeltaState->m_bFlipVCoordinates.m_pAttribute;
    pCount = (int)DeltaState;
    LOBYTE(pMesh) = 1;
    CDmAttribute::SetValue<bool>(this: m_pAttribute, value: (const bool *)&pMesh);
    HIBYTE(bAbsolute) = (_BYTE)bAbsolute == 0;
    Attribute = CDmElement::FindAttribute(this: DeltaState, pAttributeName: "corrected");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: DeltaState, pAttributeName: "corrected", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&bAbsolute + 3);
    }
    bAbsolute = CDmeVertexDataBase::CreateField(this: DeltaState, fieldId: FIELD_POSITION);
    CDmeVertexDataBase::AddVertexData(this: DeltaState, nFieldIndex: (CDmrGenericArray)bAbsolute, nCount: v31);
    CDmeVertexDataBase::SetVertexData(
      this: DeltaState,
      nFieldIndex: (CDmrGenericArray)bAbsolute,
      nFirstVertex: 0,
      nCount: v31,
      valueType: AT_VECTOR3,
      pData: this->m_positions.m_Memory.m_pMemory);
    CDmeVertexDataBase::SetVertexIndices(
      this: DeltaState,
      nFieldIndex: bAbsolute,
      nFirstIndex: 0,
      nCount: v31,
      pIndices: (const int *)i);
    m_Handle = v87.m_pAttribute[5].m_Handle;
    if ( m_Handle >= 0 )
    {
      v45 = *(CDmAttribute **)(v87.m_pAttribute[4].m_Handle + 48 * m_Handle + 16);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v87);
      CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
        this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v87,
        pAttribute: v45);
      bAbsolute = this->m_normals.m_Size;
      if ( v87.m_pStorage->m_Size == bAbsolute )
      {
        v46 = 0;
        if ( bAbsolute >= 4 )
        {
          pMesh = (CDmeMesh *)(((unsigned int)(bAbsolute - 4) >> 2) + 1);
          v47 = 0;
          pName = 4 * (_DWORD)pMesh;
          do
          {
            v48 = this->m_normals.m_Memory.m_pMemory;
            v49 = v87.m_pStorage->m_Memory.m_pMemory;
            v48[v47 / 0xC].x = v48[v47 / 0xC].x - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v47 / 4].m_tms;
            v48[v47 / 0xC].y = v48[v47 / 0xC].y - *(float *)&v49[v47 / 4 + 1].m_tms;
            v48[v47 / 0xC].z = v48[v47 / 0xC].z - *(float *)&v49[v47 / 4 + 2].m_tms;
            v50 = v87.m_pStorage->m_Memory.m_pMemory;
            v51 = this->m_normals.m_Memory.m_pMemory;
            v51[v47 / 0xC + 1].x = v51[v47 / 0xC + 1].x
                                 - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v47 / 4 + 3].m_tms;
            v51[v47 / 0xC + 1].y = v51[v47 / 0xC + 1].y - *(float *)&v50[v47 / 4 + 4].m_tms;
            v51[v47 / 0xC + 1].z = v51[v47 / 0xC + 1].z - *(float *)&v50[v47 / 4 + 5].m_tms;
            v52 = this->m_normals.m_Memory.m_pMemory;
            v53 = v87.m_pStorage->m_Memory.m_pMemory;
            v52[v47 / 0xC + 2].x = v52[v47 / 0xC + 2].x
                                 - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v47 / 4 + 6].m_tms;
            v54 = v52[v47 / 0xC + 2].y - *(float *)&v53[v47 / 4 + 7].m_tms;
            v55 = &v52[v47 / 0xC + 2];
            v55->y = v54;
            v55->z = v55->z - *(float *)&v53[v47 / 4 + 8].m_tms;
            v56 = v87.m_pStorage->m_Memory.m_pMemory;
            v57 = this->m_normals.m_Memory.m_pMemory;
            v58 = v57[v47 / 0xC + 3].x - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v47 / 4 + 9].m_tms;
            p_x = &v57[v47 / 0xC + 3].x;
            *p_x = v58;
            p_x[1] = p_x[1] - *(float *)&v56[v47 / 4 + 10].m_tms;
            v60 = p_x[2] - *(float *)&v56[v47 / 4 + 11].m_tms;
            v47 += 48;
            v5 = pMesh == (CDmeMesh *)1;
            pMesh = (CDmeMesh *)((char *)pMesh - 1);
            p_x[2] = v60;
          }
          while ( !v5 );
          v46 = pName;
        }
        if ( v46 < bAbsolute )
        {
          v61 = 12 * v46;
          v62 = bAbsolute - v46;
          do
          {
            v63 = this->m_normals.m_Memory.m_pMemory;
            v64 = v87.m_pStorage->m_Memory.m_pMemory;
            v65 = v63[v61 / 0xC].x - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v61 / 4].m_tms;
            v66 = &v63[v61 / 0xC].x;
            *v66 = v65;
            v66[1] = v66[1] - *(float *)&v64[v61 / 4 + 1].m_tms;
            v67 = v66[2] - *(float *)&v64[v61 / 4 + 2].m_tms;
            v61 += 12;
            --v62;
            v66[2] = v67;
          }
          while ( v62 != 0 );
        }
        v68 = bAbsolute;
        v69 = alloca(4 * bAbsolute);
        v70 = nullptr;
        v71 = 0;
        pNormalIndices = v85;
        pMesh = nullptr;
        if ( bAbsolute >= 4 )
        {
          v72 = 0;
          pName = 2;
          v73 = 0;
          do
          {
            v74 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v74[v73].x) >= 0.00024414062
              || fabs(v74[v73].y) >= 0.00024414062
              || fabs(v74[v73].z) >= 0.00024414062 )
            {
              v74[v72].x = v74[v73].x;
              v74[v72].y = v74[v73].y;
              ++v71;
              v74[v72++].z = v74[v73].z;
              pNormalIndices[v71 - 1] = (int)v70;
            }
            v75 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v75[v73 + 1].x) >= 0.00024414062
              || fabs(v75[v73 + 1].y) >= 0.00024414062
              || fabs(v75[v73 + 1].z) >= 0.00024414062 )
            {
              v76 = pNormalIndices;
              v75[v72].x = v75[v73 + 1].x;
              v75[v72].y = v75[v73 + 1].y;
              ++v71;
              v75[v72].z = v75[v73 + 1].z;
              v76[v71 - 1] = pName - 1;
              v70 = pMesh;
              ++v72;
            }
            v77 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v77[v73 + 2].x) >= 0.00024414062
              || fabs(v77[v73 + 2].y) >= 0.00024414062
              || fabs(v77[v73 + 2].z) >= 0.00024414062 )
            {
              v78 = pNormalIndices;
              v77[v72].x = v77[v73 + 2].x;
              v77[v72].y = v77[v73 + 2].y;
              ++v71;
              v77[v72++].z = v77[v73 + 2].z;
              v78[v71 - 1] = pName;
              v70 = pMesh;
            }
            v79 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v79[v73 + 3].x) >= 0.00024414062
              || fabs(v79[v73 + 3].y) >= 0.00024414062
              || fabs(v79[v73 + 3].z) >= 0.00024414062 )
            {
              v80 = pNormalIndices;
              v79[v72].x = v79[v73 + 3].x;
              v79[v72].y = v79[v73 + 3].y;
              ++v71;
              v79[v72].z = v79[v73 + 3].z;
              v80[v71 - 1] = pName + 1;
              v70 = pMesh;
              ++v72;
            }
            pName += 4;
            v70 = (CDmeMesh *)((char *)v70 + 4);
            v73 += 4;
            pMesh = v70;
          }
          while ( (int)v70 < bAbsolute - 3 );
          v68 = bAbsolute;
        }
        if ( (int)v70 < v68 )
        {
          v81 = v71;
          v82 = (int)v70;
          v83 = &pNormalIndices[v71];
          do
          {
            v84 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v84[v82].x) >= 0.00024414062
              || fabs(v84[v82].y) >= 0.00024414062
              || fabs(v84[v82].z) >= 0.00024414062 )
            {
              v84[v81].x = v84[v82].x;
              v84[v81].y = v84[v82].y;
              *v83 = (int)v70;
              v84[v81++].z = v84[v82].z;
              ++v83;
            }
            v70 = (CDmeMesh *)((char *)v70 + 1);
            ++v82;
          }
          while ( (int)v70 < bAbsolute );
        }
      }
    }
  }
  return (CDmeVertexDeltaData *)pCount;
}

//------------------------------------------------------------------------------
// Address: 0x004AF320
// Name: private: char const __near * CDmObjSerializer::FindMtlEntry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmObjSerializer::FindMtlEntry(CDmObjSerializer *this, const char *pTgaName)
{
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_mtlLib.m_Size;
  if ( nCount <= 0 )
    return pTgaName;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_mtlLib.m_Memory.m_pMemory[i].m_MtlName);
    if ( _V_stricmp(s1: v5, s2: pTgaName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return pTgaName;
  }
  return CUtlString::operator char const *(this: &this->m_mtlLib.m_Memory.m_pMemory[v3].m_TgaName);
}

//------------------------------------------------------------------------------
// Address: 0x004AF4B0
// Name: public: CVertexData::CVertexData(void)
// Source: json
//------------------------------------------------------------------------------
CVertexData *__thiscall CVertexData::CVertexData(CVertexData *this)
{
  this->m_positions.m_Memory.m_pMemory = nullptr;
  this->m_positions.m_Memory.m_nAllocationCount = 0;
  this->m_positions.m_Memory.m_nGrowSize = 0;
  this->m_positions.m_Size = 0;
  this->m_positions.m_pElements = nullptr;
  this->m_pIndices.m_Memory.m_pMemory = nullptr;
  this->m_pIndices.m_Memory.m_nAllocationCount = 0;
  this->m_pIndices.m_Memory.m_nGrowSize = 0;
  this->m_pIndices.m_Size = 0;
  this->m_pIndices.m_pElements = nullptr;
  this->m_normals.m_Memory.m_pMemory = nullptr;
  this->m_normals.m_Memory.m_nAllocationCount = 0;
  this->m_normals.m_Memory.m_nGrowSize = 0;
  this->m_normals.m_Size = 0;
  this->m_normals.m_pElements = nullptr;
  this->m_nIndices.m_Memory.m_pMemory = nullptr;
  this->m_nIndices.m_Memory.m_nAllocationCount = 0;
  this->m_nIndices.m_Memory.m_nGrowSize = 0;
  this->m_nIndices.m_Size = 0;
  this->m_nIndices.m_pElements = nullptr;
  this->m_uvs.m_Memory.m_pMemory = nullptr;
  this->m_uvs.m_Memory.m_nAllocationCount = 0;
  this->m_uvs.m_Memory.m_nGrowSize = 0;
  this->m_uvs.m_Size = 0;
  this->m_uvs.m_pElements = nullptr;
  this->m_uvIndexMap.m_Memory.m_pMemory = nullptr;
  this->m_uvIndexMap.m_Memory.m_nAllocationCount = 0;
  this->m_uvIndexMap.m_Memory.m_nGrowSize = 0;
  this->m_uvIndexMap.m_Size = 0;
  this->m_uvIndexMap.m_pElements = nullptr;
  this->m_uvIndices.m_Memory.m_pMemory = nullptr;
  this->m_uvIndices.m_Memory.m_nAllocationCount = 0;
  this->m_uvIndices.m_Memory.m_nGrowSize = 0;
  this->m_uvIndices.m_Size = 0;
  this->m_uvIndices.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004AF530
// Name: private: static int CDmObjSerializer::OutputVectors(class CUtlBuffer __near &,char const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmObjSerializer::OutputVectors(
        CUtlBuffer *b,
        char *pPrefix,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *vData,
        const matrix3x4_t *matrix)
{
  int result; // eax
  int v5; // esi
  int i; // ebx
  CUtlBuffer *v7; // eax
  Vector v; // [esp+0h] [ebp-10h] BYREF
  int nv; // [esp+Ch] [ebp-4h]

  result = vData->m_Size;
  nv = result;
  if ( result > 0 )
  {
    v5 = 0;
    for ( i = result; i != 0; --i )
    {
      VectorTransform(in1: &vData->m_Memory.m_pMemory[v5].x, in2: matrix, out: &v.x);
      CUtlBuffer::PutString(this: b, pString: pPrefix);
      v7 = operator<<(b, &v);
      CUtlBuffer::PutString(this: v7, pString: "\n");
      ++v5;
    }
    return nv;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AF5A0
// Name: private: static int CDmObjSerializer::OutputVectors(class CUtlBuffer __near &,char const __near *,class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmObjSerializer::OutputVectors(
        CUtlBuffer *b,
        char *pPrefix,
        const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *vData)
{
  int result; // eax
  int v4; // ebx
  Vector2D *v5; // edi
  bool v6; // zf
  float x; // xmm0_4
  float y; // [esp+14h] [ebp-14h]
  float v9; // [esp+18h] [ebp-10h] BYREF
  float v10; // [esp+1Ch] [ebp-Ch]
  float inputBuffer; // [esp+20h] [ebp-8h] BYREF
  int nv; // [esp+24h] [ebp-4h]

  result = vData->m_Size;
  v4 = 0;
  nv = result;
  if ( result > 0 )
  {
    do
    {
      v5 = &vData->m_Memory.m_pMemory[v4];
      CUtlBuffer::PutString(this: b, pString: pPrefix);
      v6 = (b->m_Flags & 1) == 0;
      x = v5->x;
      v10 = v5->x;
      if ( v6 )
      {
        inputBuffer = x;
        if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
        {
          if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<float>(
              this: &b->m_Byteswap,
              outputBuffer: (float *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
              &inputBuffer,
              count: 1);
          else
            *(float *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v10;
          b->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
        }
      }
      else
      {
        CUtlBuffer::Printf(this: b, pFmt: "%f", x);
      }
      CUtlBuffer::PutString(this: b, pString: " ");
      y = v5->y;
      if ( (b->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: b, pFmt: "%f", v5->y);
      }
      else
      {
        v9 = v5->y;
        if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
        {
          if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<float>(
              this: &b->m_Byteswap,
              outputBuffer: (float *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
              inputBuffer: &v9,
              count: 1);
          else
            *(float *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = y;
          b->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
        }
      }
      CUtlBuffer::PutString(this: b, pString: "\n");
      ++v4;
    }
    while ( v4 < nv );
    return nv;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AF720
// Name: protected: void CVertexData::AddUniqueValue<class Vector2D>(class Vector2D const __near &,class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexData::AddUniqueValue<Vector2D>(
        CVertexData *this,
        const Vector2D *v,
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *vs,
        CUtlVector<int,CUtlMemory<int,int> > *map,
        float flThresh)
{
  int m_Size; // edx
  int v7; // ebx
  Vector2D *v8; // eax
  int v9; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // ebx
  int v14; // esi
  int v15; // eax
  Vector2D *v16; // ecx
  int v17; // eax
  Vector2D *v18; // esi
  int v19; // edi
  int v20; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // eax
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *vsa; // [esp+18h] [ebp+Ch]

  m_Size = vs->m_Size;
  v7 = 0;
  vsa = (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)m_Size;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v9 = map->m_Size;
    m_nAllocationCount = map->m_Memory.m_nAllocationCount;
    if ( v9 + 1 > m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)map,
        num: v9 - m_nAllocationCount + 1);
      m_Size = (int)vsa;
    }
    ++map->m_Size;
    m_pMemory = map->m_Memory.m_pMemory;
    v12 = map->m_Size - v9 - 1;
    map->m_pElements = map->m_Memory.m_pMemory;
    if ( v12 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * v12);
      m_Size = (int)vsa;
    }
    v13 = &map->m_Memory.m_pMemory[v9];
    if ( v13 != nullptr )
      *v13 = m_Size;
    v14 = vs->m_Size;
    v15 = vs->m_Memory.m_nAllocationCount;
    if ( v14 + 1 > v15 )
      CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
        this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)vs,
        num: v14 - v15 + 1);
    ++vs->m_Size;
    v16 = vs->m_Memory.m_pMemory;
    v17 = vs->m_Size - v14 - 1;
    vs->m_pElements = vs->m_Memory.m_pMemory;
    if ( v17 > 0 )
      _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 8 * v17);
    v18 = &vs->m_Memory.m_pMemory[v14];
    if ( v18 != nullptr )
      *v18 = *v;
  }
  else
  {
    v8 = vs->m_Memory.m_pMemory;
    while ( flThresh <= (float)((float)((float)(v->x - v8->x) * (float)(v->x - v8->x))
                              + (float)((float)(v->y - v8->y) * (float)(v->y - v8->y))) )
    {
      ++v7;
      ++v8;
      if ( v7 >= m_Size )
        goto LABEL_5;
    }
    v19 = map->m_Size;
    v20 = map->m_Memory.m_nAllocationCount;
    if ( v19 + 1 > v20 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)map,
        num: v19 - v20 + 1);
    ++map->m_Size;
    v21 = map->m_Memory.m_pMemory;
    v22 = map->m_Size - v19 - 1;
    map->m_pElements = map->m_Memory.m_pMemory;
    if ( v22 > 0 )
      _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
    v23 = &map->m_Memory.m_pMemory[v19];
    if ( v23 != nullptr )
      *v23 = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AF890
// Name: public: void CVertexData::AddPositionIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexData::AddPositionIndex(CVertexData *this, CUtlSymbolTable::StringPool_t *i)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_pIndices; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_pIndices.m_Memory.m_nAllocationCount;
  p_m_pIndices = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_pIndices;
  m_Size = this->m_pIndices.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_pIndices, num: m_Size - m_nAllocationCount + 1);
  ++p_m_pIndices[1].m_pMemory;
  m_pMemory = p_m_pIndices->m_pMemory;
  v6 = (int)p_m_pIndices[1].m_pMemory - m_Size - 1;
  p_m_pIndices[1].m_nAllocationCount = (int)p_m_pIndices->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_pIndices->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = i;
}

//------------------------------------------------------------------------------
// Address: 0x004AF8F0
// Name: public: void CVertexData::AddNormalIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexData::AddNormalIndex(CVertexData *this, CUtlSymbolTable::StringPool_t *i)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_nIndices; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_nIndices.m_Memory.m_nAllocationCount;
  p_m_nIndices = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_nIndices;
  m_Size = this->m_nIndices.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_nIndices, num: m_Size - m_nAllocationCount + 1);
  ++p_m_nIndices[1].m_pMemory;
  m_pMemory = p_m_nIndices->m_pMemory;
  v6 = (int)p_m_nIndices[1].m_pMemory - m_Size - 1;
  p_m_nIndices[1].m_nAllocationCount = (int)p_m_nIndices->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_nIndices->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = i;
}

//------------------------------------------------------------------------------
// Address: 0x004AF950
// Name: private: static void CDmObjSerializer::FindDeltaMeshes(class CDmeDag __near *,class CUtlVector<class CDmeMesh __near *,class CUtlMemory<class CDmeMesh __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmObjSerializer::FindDeltaMeshes(CDmeDag *pDag, CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *meshes)
{
  CDmeShape *Shape; // eax
  CDmeMesh *v3; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmeMesh **v6; // ecx
  int v7; // eax
  CDmeMesh **v8; // edi
  int Phase; // ebx
  int i; // edi
  CDmeDag *Child; // eax

  Shape = CDmeDag::GetShape(this: pDag);
  v3 = (CDmeMesh *)Shape;
  if ( Shape != nullptr
    && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType)
    && CDmeMesh::DeltaStateCount(this: v3) != 0 )
  {
    m_pMemory = (int)meshes[1].m_pMemory;
    m_nAllocationCount = meshes->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: meshes, num: m_pMemory - m_nAllocationCount + 1);
    ++meshes[1].m_pMemory;
    v6 = (CDmeMesh **)meshes->m_pMemory;
    v7 = (int)meshes[1].m_pMemory - m_pMemory - 1;
    meshes[1].m_nAllocationCount = (int)meshes->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmeMesh **)&meshes->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = v3;
  }
  Phase = CDmElementFramework::GetPhase(this: pDag);
  for ( i = 0; i < Phase; ++i )
  {
    Child = CDmeDag::GetChild(this: pDag, i);
    CDmObjSerializer::FindDeltaMeshes(pDag: Child, (CUtlVector<CDmeMesh *,CUtlMemory<CDmeMesh *,int> > *)meshes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFAD0
// Name: private: void CDmObjSerializer::ParseMtlLib(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmObjSerializer::ParseMtlLib(CDmObjSerializer *this, CUtlBuffer *buf)
{
  CUtlBuffer *v3; // ecx
  int m_Size; // edi
  bool v5; // zf
  unsigned int v6; // eax
  char *v7; // edi
  int m_nAllocationCount; // eax
  CDmObjSerializer::MtlInfo_t *m_pMemory; // ecx
  int v10; // eax
  CDmObjSerializer::MtlInfo_t *v11; // ecx
  int v12; // ebx
  CUtlString *p_m_MtlName; // ecx
  char *v14; // ebx
  int v15; // eax
  char pLine[4096]; // [esp+8h] [ebp-190Ch] BYREF
  char str[1024]; // [esp+1008h] [ebp-90Ch] BYREF
  char out[1024]; // [esp+1408h] [ebp-50Ch] BYREF
  char pSrc[260]; // [esp+1808h] [ebp-10Ch] BYREF
  CDmObjSerializer *v20; // [esp+190Ch] [ebp-8h]
  CUtlString *v21; // [esp+1910h] [ebp-4h]

  v3 = buf;
  m_Size = -1;
  v5 = buf->m_Error == 0;
  v20 = this;
  if ( v5 )
  {
    do
    {
      CUtlBuffer::GetLine(this: v3, pLine, nMaxChars: 4096);
      if ( StringAfterPrefix(str: pLine, prefix: "newmtl ") != nullptr )
      {
        if ( sscanf(string: pLine, format: "newmtl %s", str) == 1 )
        {
          v6 = _V_strlen(str);
          if ( v6 > 2 )
          {
            v7 = &pLine[v6 + 4094];
            if ( _V_strcmp(s1: &pLine[v6 + 4094], s2: "SG") == 0 )
              *v7 = 0;
          }
          m_Size = this->m_mtlLib.m_Size;
          m_nAllocationCount = this->m_mtlLib.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(
              this: &this->m_mtlLib.m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_mtlLib.m_Size;
          m_pMemory = this->m_mtlLib.m_Memory.m_pMemory;
          v10 = this->m_mtlLib.m_Size - m_Size - 1;
          this->m_mtlLib.m_pElements = m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v10);
          v11 = this->m_mtlLib.m_Memory.m_pMemory;
          v12 = m_Size;
          v5 = &v11[m_Size] == nullptr;
          p_m_MtlName = &v11[m_Size].m_MtlName;
          v21 = p_m_MtlName;
          if ( !v5 )
          {
            CUtlString::CUtlString(this: p_m_MtlName);
            CUtlString::CUtlString(this: v21 + 1);
          }
          CUtlString::operator=(this: &this->m_mtlLib.m_Memory.m_pMemory[v12].m_MtlName, src: str);
          CUtlString::operator=(this: &this->m_mtlLib.m_Memory.m_pMemory[v12].m_TgaName, src: "debugempty");
          this = v20;
        }
      }
      else if ( StringAfterPrefix(str: pLine, prefix: "map_Kd ") != nullptr
             && m_Size >= 0
             && sscanf(string: pLine, format: "map_Kd %s", pSrc) == 1 )
      {
        V_strncpy(pDest: pLine, pSrc, maxLen: 4096);
        V_FixSlashes(pname: pLine, separator: 47);
        v14 = _V_strstr(s1: pLine, search: "/materialsrc/");
        if ( v14 != nullptr )
        {
          v15 = _V_strlen(str: "/materialsrc/");
          V_StripExtension(in: &v14[v15], out, outSize: 1024);
        }
        else
        {
          V_FileBase(in: pSrc, out, maxlen: 1024);
        }
        CUtlString::operator=(this: &this->m_mtlLib.m_Memory.m_pMemory[m_Size].m_TgaName, src: out);
      }
      v3 = buf;
    }
    while ( buf->m_Error == 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFD70
// Name: public: void CFaceSetData::AddToMesh(class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSetData::AddToMesh(CFaceSetData *this, CDmeMesh *pMesh)
{
  CFaceSetData *v2; // ebx
  char *v3; // edi
  int m_Id; // esi
  int m_Size; // eax
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmeFaceSet *v8; // esi
  CDmeFaceSet *v9; // ebx
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmeMaterial *v12; // esi
  int nFaceSets; // [esp+Ch] [ebp-14h]
  CUtlVector<int,CUtlMemory<int,int> > *faceSetIndices; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  CUtlSymbol result; // [esp+1Ch] [ebp-4h] BYREF

  v2 = this;
  nFaceSets = this->m_faceSetIndices.m_SymbolTable.m_Lookup.m_NumElements;
  i = 0;
  if ( this->m_faceSetIndices.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v3 = CUtlSymbolTable::String(this: &v2->m_faceSetIndices.m_SymbolTable, id: (CUtlSymbol)i);
      CUtlSymbolTable::AddString(this: &v2->m_faceSetIndices.m_SymbolTable, &result, pString: v3);
      m_Id = result.m_Id;
      m_Size = v2->m_faceSetIndices.m_Vector.m_Size;
      if ( m_Size <= result.m_Id && m_Size < result.m_Id + 1 )
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
          this: &v2->m_faceSetIndices.m_Vector,
          elem: m_Size,
          num: result.m_Id + 1 - m_Size);
      faceSetIndices = &v2->m_faceSetIndices.m_Vector.m_Memory.m_pMemory[m_Id];
      if ( faceSetIndices->m_Size != 0 )
      {
        v6 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
               a1: g_pDataModel,
               a2: (CUtlSymbolLarge)CDmeFaceSet::m_classType.u.m_Id,
               a3: v3,
               a4: pMesh->m_fileId,
               a5: nullptr);
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
        v8 = (CDmeFaceSet *)v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeFaceSet::m_classType) )
          v9 = v8;
        else
          v9 = nullptr;
        v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                a1: g_pDataModel,
                a2: (CUtlSymbolLarge)CDmeMaterial::m_classType.u.m_Id,
                a3: v3,
                a4: pMesh->m_fileId,
                a5: nullptr);
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
        v12 = (CDmeMaterial *)v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmeMaterial::m_classType) )
          v12 = nullptr;
        CDmeMaterial::SetMaterial(this: v12, pMaterialName: v3);
        CDmeFaceSet::AddIndices(this: v9, nCount: faceSetIndices->m_Size);
        CDmeFaceSet::SetIndices(
          this: v9,
          nFirstIndex: 0,
          nCount: faceSetIndices->m_Size,
          pIndices: faceSetIndices->m_Memory.m_pMemory);
        CDmeFaceSet::SetMaterial(this: v9, pMaterial: v12);
        CDmeMesh::AddFaceSet(this: pMesh, faceSet: (int)v9);
        v2 = this;
      }
      ++i;
    }
    while ( i < nFaceSets );
  }
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: &v2->m_faceSetIndices.m_Vector);
  CUtlSymbolTable::RemoveAll(this: &v2->m_faceSetIndices.m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x004AFEF0
// Name: public: struct CDmObjSerializer::DeltaInfo_t __near & CUtlStringMap<struct CDmObjSerializer::DeltaInfo_t>::operator[](char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmObjSerializer::DeltaInfo_t *__thiscall CUtlStringMap<CDmObjSerializer::DeltaInfo_t>::operator[](
        CUtlStringMap<CDmObjSerializer::DeltaInfo_t> *this,
        char *pString)
{
  int v3; // edi
  int m_Size; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  v3 = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString && m_Size < (unsigned __int16)pString + 1 )
    CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>::InsertMultipleBefore(
      this: &this->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pString + 1 - m_Size);
  return &this->m_Vector.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x004AFF40
// Name: private: class CDmElement __near * CDmObjSerializer::ReadOBJ(class CUtlBuffer __near &,enum DmFileId_t,char const __near *,char const __near *,class CDmeMesh __near *,class CDmeMesh __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmObjSerializer::ReadOBJ(
        CDmObjSerializer *this,
        CUtlBuffer *buf,
        DmElementHandle_t dmFileId,
        char *pName,
        char *pFilename,
        CDmeMesh *pBaseMesh,
        CDmeMesh **ppCreatedMesh,
        int bAbsolute)
{
  DmElementHandle_t v8; // ebx
  DmElementHandle_t v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v12; // edi
  DmElementHandle_t (__thiscall *CreateElement_2)(IDataModel *, CUtlSymbolLarge, const char *, DmFileId_t, const UniqueId_t *); // eax
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmeModel *v16; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v18; // eax
  CDmeMesh *v19; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *FaceSetIndices; // esi
  char *i; // edi
  CDmeMesh *v22; // esi
  int m_Size; // eax
  int v24; // edi
  int v25; // eax
  Vector *v26; // eax
  int v27; // eax
  int v28; // edi
  int v29; // eax
  Vector *v30; // eax
  int v31; // eax
  char *v32; // esi
  const char *MtlEntry; // eax
  char v34; // al
  const char *v35; // edi
  const char *v36; // eax
  const char *v37; // eax
  char *v38; // edi
  int v39; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v42; // ecx
  int v43; // eax
  int *v44; // eax
  CUtlSymbolTable::StringPool_t **v45; // edi
  int v46; // eax
  CUtlSymbolTable::StringPool_t **v47; // ecx
  int v48; // eax
  CUtlSymbolTable::StringPool_t **v49; // eax
  void *v50; // esi
  char pLine[4096]; // [esp+3Ch] [ebp-238Ch] BYREF
  char pString[4096]; // [esp+103Ch] [ebp-138Ch] BYREF
  char dest[260]; // [esp+203Ch] [ebp-38Ch] BYREF
  characterset_t pSetBuffer; // [esp+2140h] [ebp-288h] BYREF
  CUtlBuffer bufParse; // [esp+2240h] [ebp-188h] BYREF
  CUtlString v57; // [esp+2270h] [ebp-158h] BYREF
  CUtlBuffer bufa; // [esp+2280h] [ebp-148h] BYREF
  CFaceSetData v59; // [esp+22B0h] [ebp-118h] BYREF
  CVertexData v60; // [esp+22FCh] [ebp-CCh] BYREF
  Vector2D v; // [esp+2388h] [ebp-40h] BYREF
  int v62; // [esp+2390h] [ebp-38h] BYREF
  int n; // [esp+2394h] [ebp-34h] BYREF
  int t; // [esp+2398h] [ebp-30h] BYREF
  __int64 v65; // [esp+239Ch] [ebp-2Ch] BYREF
  float v66; // [esp+23A4h] [ebp-24h] BYREF
  CDmObjSerializer *v67; // [esp+23A8h] [ebp-20h]
  CUtlString v68; // [esp+23ACh] [ebp-1Ch] BYREF
  CDmElement *v69; // [esp+23BCh] [ebp-Ch]
  CDmeModel *v70; // [esp+23C0h] [ebp-8h]
  CDmeMesh *pMesh; // [esp+23C4h] [ebp-4h]

  v67 = this;
  v69 = nullptr;
  v70 = nullptr;
  if ( pBaseMesh == nullptr )
  {
    v8 = dmFileId;
    v9 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
           a3: "root",
           a4: (DmFileId_t)dmFileId,
           a5: nullptr);
    v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9);
    v11 = v10;
    if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
      v12 = v11;
    else
      v12 = nullptr;
    CreateElement_2 = g_pDataModel->CreateElement_2;
    v69 = v12;
    v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeModel::m_classType.u.m_Id,
            a3: "model",
            a4: (DmFileId_t)v8,
            a5: nullptr);
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
    v16 = (CDmeModel *)v15;
    if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmeModel::m_classType) )
      v16 = nullptr;
    v70 = v16;
    if ( v16 != nullptr )
      dmFileId = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v16);
    else
      dmFileId = DMELEMENT_HANDLE_INVALID;
    Attribute = CDmElement::FindAttribute(this: v12, pAttributeName: "skeleton");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v12, pAttributeName: "skeleton", type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &dmFileId);
    }
    if ( v16 != nullptr )
      dmFileId = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v16);
    else
      dmFileId = DMELEMENT_HANDLE_INVALID;
    v18 = CDmElement::FindAttribute(this: v12, pAttributeName: "model");
    if ( v18 != nullptr
      || (v18 = CDmElement::CreateAttribute(this: v12, pAttributeName: "model", type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: v18, value: &dmFileId);
    }
  }
  CUtlVector<CDmObjSerializer::MtlInfo_t,CUtlMemory<CDmObjSerializer::MtlInfo_t,int>>::RemoveAll(this: &v67->m_mtlLib);
  CharacterSetBuild(&pSetBuffer, pszSetString: "/\\");
  CVertexData::CVertexData(this: &v60);
  v59.m_faceSetIndices.m_Vector.m_Memory.m_pMemory = nullptr;
  v59.m_faceSetIndices.m_Vector.m_Memory.m_nAllocationCount = 0;
  v59.m_faceSetIndices.m_Vector.m_Memory.m_nGrowSize = 32;
  v59.m_faceSetIndices.m_Vector.m_Size = 0;
  v59.m_faceSetIndices.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &v59.m_faceSetIndices.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  CUtlString::CUtlString(this: &v68);
  v19 = nullptr;
  FaceSetIndices = nullptr;
  dmFileId = 0;
  pMesh = nullptr;
  if ( buf->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( sscanf(string: pLine, format: "v %f %f %f", &v65, (char *)&v65 + 4, &v66) == 3 )
      {
        if ( dmFileId != 0 )
        {
          v22 = pMesh;
          CVertexData::Add(this: &v60, pMesh, pName: "bind");
          CFaceSetData::AddToMesh(this: &v59, pMesh: v22);
          dmFileId = 0;
          pMesh = nullptr;
          FaceSetIndices = nullptr;
        }
        m_Size = v60.m_positions.m_Size;
        v24 = v60.m_positions.m_Size;
        if ( v60.m_positions.m_Size + 1 > v60.m_positions.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
            this: (CUtlMemory<CSelectionHelper::CVert,int> *)&v60,
            num: v60.m_positions.m_Size - v60.m_positions.m_Memory.m_nAllocationCount + 1);
          m_Size = v60.m_positions.m_Size;
        }
        v60.m_positions.m_Size = m_Size + 1;
        v25 = m_Size - v24;
        v60.m_positions.m_pElements = v60.m_positions.m_Memory.m_pMemory;
        if ( v25 > 0 )
          _V_memmove(
            dest: &v60.m_positions.m_Memory.m_pMemory[v24 + 1],
            src: &v60.m_positions.m_Memory.m_pMemory[v24],
            count: 12 * v25);
        v26 = &v60.m_positions.m_Memory.m_pMemory[v24];
        if ( v26 != nullptr )
        {
          *(_QWORD *)&v26->x = v65;
          v26->z = v66;
        }
        goto LABEL_105;
      }
      if ( sscanf(string: i, format: "vn %f %f %f", &v65, (char *)&v65 + 4, &v66) == 3 )
      {
        v27 = v60.m_normals.m_Size;
        v28 = v60.m_normals.m_Size;
        if ( v60.m_normals.m_Size + 1 > v60.m_normals.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
            this: (CUtlMemory<CSelectionHelper::CVert,int> *)&v60.m_normals,
            num: v60.m_normals.m_Size - v60.m_normals.m_Memory.m_nAllocationCount + 1);
          v27 = v60.m_normals.m_Size;
        }
        v60.m_normals.m_Size = v27 + 1;
        v29 = v27 - v28;
        v60.m_normals.m_pElements = v60.m_normals.m_Memory.m_pMemory;
        if ( v29 > 0 )
          _V_memmove(
            dest: &v60.m_normals.m_Memory.m_pMemory[v28 + 1],
            src: &v60.m_normals.m_Memory.m_pMemory[v28],
            count: 12 * v29);
        v30 = &v60.m_normals.m_Memory.m_pMemory[v28];
        if ( v30 != nullptr )
        {
          *(_QWORD *)&v30->x = v65;
          v30->z = v66;
        }
        goto LABEL_105;
      }
      if ( pBaseMesh == nullptr )
      {
        if ( sscanf(string: i, format: "vt %f %f", &v, &v.y) == 2 )
        {
          CVertexData::AddUniqueValue<Vector2D>(
            this: &v60,
            &v,
            vs: &v60.m_uvs,
            map: &v60.m_uvIndexMap,
            flThresh: 0.000000011920929);
        }
        else
        {
          if ( pFilename != nullptr && sscanf(string: i, format: "mtllib %4096s", pString) == 1 )
          {
            CUtlString::CUtlString(this: &v57, pString);
            V_strncpy(pDest: pLine, pSrc: pFilename, maxLen: 4096);
            V_FixSlashes(pname: pLine, separator: 92);
            V_StripFilename(path: pLine);
            V_ComposeFileName(path: pLine, filename: pString, dest, destSize: 260);
            CUtlBuffer::CUtlBuffer(this: &bufa, growSize: 0, initSize: 0, nFlags: 0);
            if ( g_pFullFileSystem->ReadFile(
                   this: &g_pFullFileSystem->IBaseFileSystem,
                   a2: dest,
                   a3: nullptr,
                   a4: &bufa,
                   a5: 0,
                   a6: 0,
                   a7: nullptr) )
            {
              CDmObjSerializer::ParseMtlLib(this: v67, buf: &bufa);
            }
            if ( bufa.m_Memory.m_nGrowSize >= 0 )
            {
              if ( bufa.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufa.m_Memory.m_pMemory);
                bufa.m_Memory.m_pMemory = nullptr;
              }
              bufa.m_Memory.m_nAllocationCount = 0;
            }
            CUtlString::~CUtlString(this: (CDmxEdit::delta *)&v57);
            goto LABEL_105;
          }
          if ( sscanf(string: i, format: "usemtl %4096s", pString) == 1 )
          {
            v31 = _V_strlen(str: pString);
            if ( v31 != 0 )
            {
              v32 = &pLine[v31 + 4094];
              if ( _V_strcmp(s1: &pLine[v31 + 4094], s2: "SG") == 0 )
                *v32 = 0;
            }
            MtlEntry = CDmObjSerializer::FindMtlEntry(this: v67, pTgaName: pString);
            if ( MtlEntry == nullptr )
              goto LABEL_62;
            FaceSetIndices = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)CFaceSetData::GetFaceSetIndices(
                                                                                  this: &v59,
                                                                                  pFaceSetName: MtlEntry);
          }
          else
          {
            if ( sscanf(string: i, format: "g %4096s", pString) != 1 )
            {
              if ( *i == 102 )
              {
                v34 = i[1];
                v35 = i + 1;
                if ( v34 == 32 || v34 == 9 )
                {
                  if ( dmFileId == 0 )
                  {
                    v36 = pName;
                    if ( pName == nullptr )
                    {
                      if ( CUtlString::Length(this: &v68) != 0 )
                        v36 = CUtlString::Get(this: &v68);
                      else
                        v36 = "obj";
                    }
                    dmFileId = (DmElementHandle_t)CreateElement<CDmeDag>(
                                                    pObjectName: v36,
                                                    fileid: v69->m_fileId,
                                                    pObjectID: nullptr);
                    if ( pName != nullptr )
                    {
                      v37 = pName;
                    }
                    else if ( CUtlString::Length(this: &v68) != 0 )
                    {
                      v37 = CUtlString::Get(this: &v68);
                    }
                    else
                    {
                      v37 = "obj";
                    }
                    pMesh = CreateElement<CDmeMesh>(pObjectName: v37, fileid: v69->m_fileId, pObjectID: nullptr);
                    if ( ppCreatedMesh != nullptr && *ppCreatedMesh == nullptr )
                      *ppCreatedMesh = pMesh;
                    CDmeDag::SetShape(this: (CDmeDag *)dmFileId, pShape: (int)pMesh);
                    if ( v70 != nullptr )
                    {
                      CDmeModel::AddJoint(this: v70, pJoint: dmFileId);
                      CDmeDag::AddChild(this: v70, pDag: (CDmeDag *)dmFileId);
                    }
                  }
                  if ( FaceSetIndices == nullptr )
                    FaceSetIndices = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)CFaceSetData::GetFaceSetIndices(
                                                                                          this: &v59,
                                                                                          pFaceSetName: "facetSet");
                  v38 = (char *)CDmObjSerializer::SkipSpace(pBuf: v35);
                  v39 = _V_strlen(str: v38);
                  CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: (unsigned __int8 *)v38, nSize: v39, nFlags: 9u);
                  while ( bufParse.m_Error == 0 )
                  {
                    if ( CDmObjSerializer::ParseVertex(&bufParse, breakSet: &pSetBuffer, v: &v62, &t, &n) == 0 )
                      break;
                    m_pMemory = FaceSetIndices[1].m_pMemory;
                    m_nAllocationCount = FaceSetIndices->m_nAllocationCount;
                    if ( (int)m_pMemory + 1 > m_nAllocationCount )
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(
                        this: FaceSetIndices,
                        num: (int)m_pMemory - m_nAllocationCount + 1);
                    ++FaceSetIndices[1].m_pMemory;
                    v42 = FaceSetIndices->m_pMemory;
                    v43 = (char *)FaceSetIndices[1].m_pMemory - (char *)m_pMemory - 1;
                    FaceSetIndices[1].m_nAllocationCount = (int)FaceSetIndices->m_pMemory;
                    if ( v43 > 0 )
                      _V_memmove(dest: &v42[(_DWORD)m_pMemory + 1], src: &v42[(_DWORD)m_pMemory], count: 4 * v43);
                    v44 = (int *)&FaceSetIndices->m_pMemory[(_DWORD)m_pMemory];
                    if ( v44 != nullptr )
                      *v44 = v60.m_pIndices.m_Size;
                    if ( v62 > 0 )
                      CVertexData::AddPositionIndex(this: &v60, i: (CUtlSymbolTable::StringPool_t *)(v62 - 1));
                    if ( n > 0 )
                      CVertexData::AddNormalIndex(this: &v60, i: (CUtlSymbolTable::StringPool_t *)(n - 1));
                    if ( t > 0 )
                      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
                        this: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&v60.m_uvIndices,
                        elem: v60.m_uvIndices.m_Size,
                        src: (const DmeTime_t *)&v60.m_uvIndexMap.m_Memory.m_pMemory[t - 1]);
                  }
                  v45 = FaceSetIndices[1].m_pMemory;
                  v46 = FaceSetIndices->m_nAllocationCount;
                  if ( (int)v45 + 1 > v46 )
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: FaceSetIndices, num: (int)v45 - v46 + 1);
                  ++FaceSetIndices[1].m_pMemory;
                  v47 = FaceSetIndices->m_pMemory;
                  v48 = (char *)FaceSetIndices[1].m_pMemory - (char *)v45 - 1;
                  FaceSetIndices[1].m_nAllocationCount = (int)FaceSetIndices->m_pMemory;
                  if ( v48 > 0 )
                    _V_memmove(dest: &v47[(_DWORD)v45 + 1], src: &v47[(_DWORD)v45], count: 4 * v48);
                  v49 = &FaceSetIndices->m_pMemory[(_DWORD)v45];
                  if ( v49 != nullptr )
                    *v49 = (CUtlSymbolTable::StringPool_t *)-1;
                  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &bufParse);
                }
              }
              goto LABEL_105;
            }
            CUtlString::operator=(this: &v68, src: pString);
            if ( FaceSetIndices == nullptr )
LABEL_62:
              FaceSetIndices = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)CFaceSetData::GetFaceSetIndices(
                                                                                    this: &v59,
                                                                                    pFaceSetName: pString);
          }
        }
      }
LABEL_105:
      if ( buf->m_Error != 0 )
      {
        v19 = pMesh;
        break;
      }
    }
  }
  if ( pBaseMesh != nullptr )
  {
    v50 = CVertexData::AddDelta(this: &v60, pMesh: pBaseMesh, bAbsolute, (int)pName);
  }
  else
  {
    v50 = CVertexData::Add(this: &v60, pMesh: v19, pName: "bind");
    CFaceSetData::AddToMesh(this: &v59, pMesh: v19);
  }
  if ( v70 != nullptr )
    CDmeModel::CaptureJointsToBaseState(this: v70, pBaseStateName: "bind");
  v68.m_Storage.m_nActualLength = 0;
  if ( pBaseMesh != nullptr )
  {
    if ( v68.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v68.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v68.m_Storage.m_Memory.m_pMemory);
        v68.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v68.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    CUtlSymbolTable::~CUtlSymbolTable(this: &v59.m_faceSetIndices.m_SymbolTable);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &v59.m_faceSetIndices.m_Vector);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_uvIndices);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_uvIndexMap);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v60.m_uvs);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_nIndices);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_normals);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_pIndices);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60);
    return (CDmElement *)v50;
  }
  else
  {
    if ( v68.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v68.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v68.m_Storage.m_Memory.m_pMemory);
        v68.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v68.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    CUtlSymbolTable::~CUtlSymbolTable(this: &v59.m_faceSetIndices.m_SymbolTable);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &v59.m_faceSetIndices.m_Vector);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_uvIndices);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_uvIndexMap);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v60.m_uvs);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_nIndices);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_normals);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60.m_pIndices);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&v60);
    return v69;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0890
// Name: public: void CDmObjSerializer::MeshToObj(class CUtlBuffer __near &,struct matrix3x4_t const __near &,class CDmeMesh __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmObjSerializer::MeshToObj(
        CDmObjSerializer *this,
        CUtlBuffer *b,
        const matrix3x4_t *parentWorldMatrix,
        CDmeMesh *pMesh,
        const char *pDeltaName,
        const int *absolute)
{
  CDmeVertexData *BaseState; // eax
  int v7; // edi
  const CUtlVector<int,CUtlMemory<int,int> > *m_Id; // eax
  CDmeVertexDeltaData *DeltaState; // edi
  const char *m_pAsString; // eax
  const CUtlVector<int,CUtlMemory<int,int> > *v12; // eax
  int v13; // edi
  const CUtlVector<int,CUtlMemory<int,int> > *v14; // eax
  CDmeVertexDeltaData *v15; // edi
  const char *v16; // eax
  int v17; // eax
  CDmeVertexDataBase *v18; // edi
  int v19; // eax
  int v20; // eax
  CDmeVertexDeltaData *v21; // edi
  const char *v22; // eax
  int v23; // edi
  CDmeVertexDeltaData *v24; // edi
  const char *v25; // eax
  CDmeFaceSet *FaceSet; // edi
  CDmeMaterial *Material; // ebx
  char *MaterialName; // eax
  const int *m_pMemory; // ebx
  const int *v30; // edi
  char *v31; // eax
  int v32; // ecx
  int v33; // ecx
  int *v34; // edi
  int v35; // ebx
  int m_Put; // eax
  CDmObjSerializer *v37; // edi
  int v38; // ebx
  int v39; // eax
  int v40; // ebx
  int v41; // ecx
  int v42; // ecx
  int *v43; // edi
  int v44; // ebx
  int v45; // eax
  char *v46; // edi
  int v47; // eax
  int v48; // ecx
  int v49; // ecx
  int *v50; // edi
  int v51; // ebx
  char *v52; // edi
  int v53; // ecx
  int v54; // edi
  CDmObjSerializer *v55; // eax
  int v56; // edx
  CDmeMesh::DeltaComputation_t *v57; // eax
  Vector *weight; // [esp+0h] [ebp-B8h]
  const QAngle *weighta; // [esp+0h] [ebp-B8h]
  int m_Size; // [esp+4h] [ebp-B4h]
  int v61; // [esp+4h] [ebp-B4h]
  matrix3x4_t normalMatrix; // [esp+14h] [ebp-A4h] BYREF
  CDmrArrayConst<Vector> nArray; // [esp+44h] [ebp-74h] BYREF
  CDmrArrayConst<Vector2D> uvArray; // [esp+4Ch] [ebp-6Ch] BYREF
  int nFaceSets; // [esp+54h] [ebp-64h]
  CDmrArrayConst<Vector> pArray; // [esp+58h] [ebp-60h] BYREF
  int nTextureCount; // [esp+60h] [ebp-58h]
  CUtlVector<CDmeMesh::DeltaComputation_t,CUtlMemory<CDmeMesh::DeltaComputation_t,int> > compList; // [esp+64h] [ebp-54h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *depDeltas; // [esp+78h] [ebp-40h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > nData; // [esp+7Ch] [ebp-3Ch] BYREF
  int nDepDeltas; // [esp+90h] [ebp-28h]
  int i; // [esp+94h] [ebp-24h]
  CDmObjSerializer *v73; // [esp+98h] [ebp-20h]
  int nCompList; // [esp+9Ch] [ebp-1Ch]
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *uvData; // [esp+A0h] [ebp-18h]
  int inputBuffer; // [esp+A4h] [ebp-14h] BYREF
  CDmeVertexDeltaData *pTmpDeltaState; // [esp+A8h] [ebp-10h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *puvIndices; // [esp+ACh] [ebp-Ch]
  const CUtlVector<int,CUtlMemory<int,int> > *pnIndices; // [esp+B0h] [ebp-8h]
  int uvIndex; // [esp+B4h] [ebp-4h]
  CDmAttribute *ppIndicesa; // [esp+C0h] [ebp+8h]
  const CUtlVector<int,CUtlMemory<int,int> > *ppIndices; // [esp+C0h] [ebp+8h]
  CDmAttribute *nConstDatae; // [esp+C4h] [ebp+Ch]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *nConstData; // [esp+C4h] [ebp+Ch]
  char *nConstDataa; // [esp+C4h] [ebp+Ch]
  char *nConstDatab; // [esp+C4h] [ebp+Ch]
  char *nConstDatac; // [esp+C4h] [ebp+Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *nConstDatad; // [esp+C4h] [ebp+Ch]
  const int *pEnd; // [esp+CCh] [ebp+14h]

  v73 = this;
  memset(&compList, 0, sizeof(compList));
  if ( pDeltaName != nullptr )
    CDmeMesh::ComputeDependentDeltaStateList(this: pMesh, &compList);
  nCompList = compList.m_Size;
  BaseState = CDmeMesh::FindBaseState(this: pMesh, pStateName: "bind");
  i = (int)BaseState;
  if ( BaseState != nullptr && (v7 = BaseState->m_pStandardFieldIndex[0]) >= 0 )
  {
    m_Id = (const CUtlVector<int,CUtlMemory<int,int> > *)pMesh->m_Name.m_Storage.u.CDmeShape::CDmElement::m_Id;
    nTextureCount = 0;
    nDepDeltas = 0;
    pnIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)var;
    if ( m_Id != (const CUtlVector<int,CUtlMemory<int,int> > *)-1 )
      pnIndices = m_Id;
    CUtlBuffer::PutString(this: b, pString: "g ");
    CUtlBuffer::PutString(this: b, pString: (char *)pnIndices);
    CUtlBuffer::PutString(this: b, pString: "\n");
    ppIndicesa = *(CDmAttribute **)(*(_DWORD *)(i + 108) + 48 * v7 + 16);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&pArray);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &pArray,
      pAttribute: ppIndicesa);
    ppIndices = CDmeVertexDataBase::GetVertexIndexData(this: (CDmeVertexDataBase *)i, nFieldIndex: v7);
    if ( nCompList != 0 )
    {
      m_Size = pArray.m_pStorage->m_Size;
      weight = pArray.m_pStorage->m_Memory.m_pMemory;
      memset(&nData, 0, sizeof(nData));
      CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&nData,
        pArray: (const QAngle *)weight,
        size: m_Size);
      if ( (_BYTE)absolute != 0 )
      {
        if ( nCompList > 0 )
        {
          puvIndices = nullptr;
          for ( uvIndex = nCompList; uvIndex != 0; --uvIndex )
          {
            DeltaState = CDmeMesh::GetDeltaState(
                           this: pMesh,
                           nDeltaIndex: *(int *)((char *)&puvIndices->m_Memory.m_pMemory + (unsigned int)compList.m_Memory.m_pMemory));
            m_pAsString = DeltaState->m_Name.m_Storage.u.m_pAsString;
            if ( m_pAsString == (const char *)-1 )
              m_pAsString = var;
            if ( _V_strcmp(s1: m_pAsString, s2: pDeltaName) == 0 )
            {
              v12 = (const CUtlVector<int,CUtlMemory<int,int> > *)DeltaState->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
              pnIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)var;
              if ( v12 != (const CUtlVector<int,CUtlMemory<int,int> > *)-1 )
                pnIndices = v12;
              CUtlBuffer::PutString(this: b, pString: "# Delta: ");
              CUtlBuffer::PutString(this: b, pString: (char *)pnIndices);
              CUtlBuffer::PutString(this: b, pString: "\n");
              CDmeMesh::AddDelta<Vector>(
                this: pMesh,
                pDelta: DeltaState,
                pFullData: nData.m_Memory.m_pMemory,
                nFullData: nData.m_Size,
                standardField: FIELD_POSITION,
                weight: 1.0,
                pMask: nullptr);
              depDeltas = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)&puvIndices->m_Memory.m_nGrowSize
                                                                       + (unsigned int)compList.m_Memory.m_pMemory);
              v13 = 0;
              uvData = *(const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > **)((char *)&puvIndices[1].m_Memory.m_pMemory
                                                                                + (unsigned int)compList.m_Memory.m_pMemory);
              if ( (int)uvData > 0 )
              {
                do
                {
                  pTmpDeltaState = CDmeMesh::GetDeltaState(this: pMesh, nDeltaIndex: depDeltas->m_Memory.m_pMemory[v13]);
                  v14 = (const CUtlVector<int,CUtlMemory<int,int> > *)pTmpDeltaState->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
                  pnIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)var;
                  if ( v14 != (const CUtlVector<int,CUtlMemory<int,int> > *)-1 )
                    pnIndices = v14;
                  CUtlBuffer::PutString(this: b, pString: "# Dependent Delta: ");
                  CUtlBuffer::PutString(this: b, pString: (char *)pnIndices);
                  CUtlBuffer::PutString(this: b, pString: "\n");
                  CDmeMesh::AddDelta<Vector>(
                    this: pMesh,
                    pDelta: pTmpDeltaState,
                    pFullData: nData.m_Memory.m_pMemory,
                    nFullData: nData.m_Size,
                    standardField: FIELD_POSITION,
                    weight: 1.0,
                    pMask: nullptr);
                  ++v13;
                }
                while ( v13 < (int)uvData );
              }
            }
            puvIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)puvIndices + 28);
          }
        }
      }
      else if ( nCompList > 0 )
      {
        pnIndices = nullptr;
        for ( puvIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)nCompList;
              puvIndices != nullptr;
              puvIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)puvIndices - 1) )
        {
          v15 = CDmeMesh::GetDeltaState(
                  this: pMesh,
                  nDeltaIndex: *(int *)((char *)&pnIndices->m_Memory.m_pMemory + (unsigned int)compList.m_Memory.m_pMemory));
          v16 = v15->m_Name.m_Storage.u.m_pAsString;
          if ( v16 == (const char *)-1 )
            v16 = var;
          if ( _V_strcmp(s1: v16, s2: pDeltaName) == 0 )
          {
            v17 = v15->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
            uvIndex = (int)var;
            if ( v17 != -1 )
              uvIndex = v17;
            CUtlBuffer::PutString(this: b, pString: "# Delta: ");
            CUtlBuffer::PutString(this: b, pString: (char *)uvIndex);
            CUtlBuffer::PutString(this: b, pString: "\n");
            CDmeMesh::AddDelta<Vector>(
              this: pMesh,
              pDelta: v15,
              pFullData: nData.m_Memory.m_pMemory,
              nFullData: nData.m_Size,
              standardField: FIELD_POSITION,
              weight: 1.0,
              pMask: nullptr);
          }
          pnIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)pnIndices + 28);
        }
      }
      depDeltas = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmObjSerializer::OutputVectors(
                                                                  b,
                                                                  pPrefix: "v ",
                                                                  vData: &nData,
                                                                  matrix: parentWorldMatrix);
      CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&nData);
    }
    else
    {
      depDeltas = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmObjSerializer::OutputVectors(
                                                                  b,
                                                                  pPrefix: "v ",
                                                                  vData: pArray.m_pStorage,
                                                                  matrix: parentWorldMatrix);
    }
    v18 = (CDmeVertexDataBase *)i;
    v19 = *(_DWORD *)(i + 140);
    puvIndices = nullptr;
    uvIndex = v19;
    if ( v19 >= 0 )
    {
      uvData = *(const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > **)(*(_DWORD *)(i + 108) + 48 * v19 + 16);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&uvArray);
      CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
        this: &uvArray,
        pAttribute: (CDmAttribute *)uvData);
      uvData = uvArray.m_pStorage;
      puvIndices = CDmeVertexDataBase::GetVertexIndexData(this: v18, nFieldIndex: uvIndex);
      nTextureCount = CDmObjSerializer::OutputVectors(b, pPrefix: "vt ", vData: uvData);
    }
    v20 = v18->m_pStandardFieldIndex[1];
    pnIndices = nullptr;
    uvIndex = v20;
    if ( v20 >= 0 )
    {
      MatrixInverseTranspose(src: parentWorldMatrix, dst: &normalMatrix);
      nConstDatae = v18->m_FieldInfo.m_Memory.m_pMemory[uvIndex].m_pVertexData;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&nArray);
      CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
        this: &nArray,
        pAttribute: nConstDatae);
      nConstData = nArray.m_pStorage;
      pnIndices = CDmeVertexDataBase::GetVertexIndexData(this: v18, nFieldIndex: uvIndex);
      if ( nCompList != 0 )
      {
        v61 = nConstData->m_Size;
        weighta = (const QAngle *)nConstData->m_Memory.m_pMemory;
        memset(&nData, 0, sizeof(nData));
        CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&nData,
          pArray: weighta,
          size: v61);
        if ( (_BYTE)absolute != 0 )
        {
          if ( nCompList > 0 )
          {
            absolute = nullptr;
            for ( uvIndex = nCompList; uvIndex != 0; --uvIndex )
            {
              v21 = CDmeMesh::GetDeltaState(
                      this: pMesh,
                      nDeltaIndex: *(const int *)((char *)absolute + (unsigned int)compList.m_Memory.m_pMemory));
              v22 = v21->m_Name.m_Storage.u.m_pAsString;
              if ( v22 == (const char *)-1 )
                v22 = var;
              if ( _V_strcmp(s1: v22, s2: pDeltaName) == 0 )
              {
                nConstDataa = (char *)var;
                if ( v21->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
                  nConstDataa = (char *)v21->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
                CUtlBuffer::PutString(this: b, pString: "# Delta: ");
                CUtlBuffer::PutString(this: b, pString: nConstDataa);
                CUtlBuffer::PutString(this: b, pString: "\n");
                CDmeMesh::AddDelta<Vector>(
                  this: pMesh,
                  pDelta: v21,
                  pFullData: nData.m_Memory.m_pMemory,
                  nFullData: nData.m_Size,
                  standardField: FIELD_NORMAL,
                  weight: 1.0,
                  pMask: nullptr);
                uvData = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)((char *)absolute
                                                                                + (unsigned int)compList.m_Memory.m_pMemory
                                                                                + 8);
                v23 = 0;
                nDepDeltas = *(const int *)((char *)absolute + (unsigned int)compList.m_Memory.m_pMemory + 20);
                if ( nDepDeltas > 0 )
                {
                  do
                  {
                    pTmpDeltaState = CDmeMesh::GetDeltaState(
                                       this: pMesh,
                                       nDeltaIndex: *((_DWORD *)&uvData->m_Memory.m_pMemory->x + v23));
                    nConstDatab = (char *)var;
                    if ( pTmpDeltaState->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
                      nConstDatab = (char *)pTmpDeltaState->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
                    CUtlBuffer::PutString(this: b, pString: "# Dependent Delta: ");
                    CUtlBuffer::PutString(this: b, pString: nConstDatab);
                    CUtlBuffer::PutString(this: b, pString: "\n");
                    CDmeMesh::AddDelta<Vector>(
                      this: pMesh,
                      pDelta: pTmpDeltaState,
                      pFullData: nData.m_Memory.m_pMemory,
                      nFullData: nData.m_Size,
                      standardField: FIELD_NORMAL,
                      weight: 1.0,
                      pMask: nullptr);
                    ++v23;
                  }
                  while ( v23 < nDepDeltas );
                }
              }
              absolute += 7;
            }
          }
        }
        else if ( nCompList > 0 )
        {
          absolute = nullptr;
          for ( uvIndex = nCompList; uvIndex != 0; --uvIndex )
          {
            v24 = CDmeMesh::GetDeltaState(
                    this: pMesh,
                    nDeltaIndex: *(const int *)((char *)absolute + (unsigned int)compList.m_Memory.m_pMemory));
            v25 = v24->m_Name.m_Storage.u.m_pAsString;
            if ( v25 == (const char *)-1 )
              v25 = var;
            if ( _V_strcmp(s1: v25, s2: pDeltaName) == 0 )
            {
              nConstDatac = (char *)var;
              if ( v24->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
                nConstDatac = (char *)v24->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
              CUtlBuffer::PutString(this: b, pString: "# Delta: ");
              CUtlBuffer::PutString(this: b, pString: nConstDatac);
              CUtlBuffer::PutString(this: b, pString: "\n");
              CDmeMesh::AddDelta<Vector>(
                this: pMesh,
                pDelta: v24,
                pFullData: nData.m_Memory.m_pMemory,
                nFullData: nData.m_Size,
                standardField: FIELD_NORMAL,
                weight: 1.0,
                pMask: nullptr);
            }
            absolute += 7;
          }
        }
        nDepDeltas = CDmObjSerializer::OutputVectors(b, pPrefix: "vn ", vData: &nData, matrix: &normalMatrix);
        CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&nData);
      }
      else
      {
        nDepDeltas = CDmObjSerializer::OutputVectors(b, pPrefix: "vn ", vData: nConstData, matrix: &normalMatrix);
      }
    }
    uvData = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)ppIndices->m_Size;
    if ( puvIndices != nullptr )
      uvIndex = puvIndices->m_Size;
    else
      uvIndex = 0;
    if ( pnIndices != nullptr )
      nConstDatad = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)pnIndices->m_Size;
    else
      nConstDatad = nullptr;
    nFaceSets = CDmeMesh::FaceSetCount(this: pMesh);
    for ( i = 0; i < nFaceSets; ++i )
    {
      FaceSet = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: i);
      Material = CDmeFaceSet::GetMaterial(this: FaceSet);
      if ( Material != nullptr )
      {
        CUtlBuffer::PutString(this: b, pString: "usemtl ");
        MaterialName = (char *)CDmeMaterial::GetMaterialName(this: Material);
        CUtlBuffer::PutString(this: b, pString: MaterialName);
        CUtlBuffer::PutString(this: b, pString: "\n");
      }
      m_pMemory = FaceSet->m_indices.m_Storage.m_Memory.m_pMemory;
      v30 = &m_pMemory[FaceSet->m_indices.m_Storage.m_Size];
      pEnd = v30;
      v31 = "f ";
      if ( uvData == (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)uvIndex )
      {
        if ( uvData == (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)nConstDatad )
        {
          while ( m_pMemory < v30 )
          {
            v32 = *m_pMemory++;
            absolute = m_pMemory;
            if ( v32 >= 0 )
            {
              v33 = v32;
              inputBuffer = (int)&pnIndices->m_Memory.m_pMemory[v33];
              nCompList = (int)&puvIndices->m_Memory.m_pMemory[v33];
              v34 = &ppIndices->m_Memory.m_pMemory[v33];
              CUtlBuffer::PutString(this: b, pString: v31);
              v35 = *v34 + v73->m_nPositionOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", *v34 + v73->m_nPositionOffset);
              }
              else
              {
                pTmpDeltaState = (CDmeVertexDeltaData *)(*v34 + v73->m_nPositionOffset);
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      inputBuffer: (int *)&pTmpDeltaState,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v35;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              if ( (b->m_Flags & 1) != 0 )
              {
                m_Put = b->m_Put;
                if ( m_Put != 0 && b->m_Memory.m_pMemory[m_Put - b->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: b);
              }
              if ( CUtlBuffer::CheckPut(this: b, nSize: 1) != 0 )
              {
                b->m_Memory.m_pMemory[b->m_Put++ - b->m_nOffset] = 47;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
              v37 = v73;
              v38 = *(_DWORD *)nCompList + v73->m_nTextureOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", *(_DWORD *)nCompList + v73->m_nTextureOffset);
              }
              else
              {
                pTmpDeltaState = (CDmeVertexDeltaData *)(*(_DWORD *)nCompList + v73->m_nTextureOffset);
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      inputBuffer: (int *)&pTmpDeltaState,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v38;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              if ( (b->m_Flags & 1) != 0 )
              {
                v39 = b->m_Put;
                if ( v39 != 0 && b->m_Memory.m_pMemory[v39 - b->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: b);
              }
              if ( CUtlBuffer::CheckPut(this: b, nSize: 1) != 0 )
              {
                b->m_Memory.m_pMemory[b->m_Put++ - b->m_nOffset] = 47;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
              v40 = *(_DWORD *)inputBuffer + v37->m_nNormalOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", *(_DWORD *)inputBuffer + v37->m_nNormalOffset);
              }
              else
              {
                inputBuffer = *(_DWORD *)inputBuffer + v37->m_nNormalOffset;
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      &inputBuffer,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v40;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              m_pMemory = absolute;
              v30 = pEnd;
              v31 = " ";
            }
            else
            {
              CUtlBuffer::PutString(this: b, pString: "\n");
              v31 = "f ";
            }
          }
        }
        else
        {
          while ( m_pMemory < v30 )
          {
            v41 = *m_pMemory++;
            absolute = m_pMemory;
            if ( v41 >= 0 )
            {
              v42 = v41;
              pTmpDeltaState = (CDmeVertexDeltaData *)&puvIndices->m_Memory.m_pMemory[v42];
              v43 = &ppIndices->m_Memory.m_pMemory[v42];
              CUtlBuffer::PutString(this: b, pString: v31);
              v44 = *v43 + v73->m_nPositionOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", *v43 + v73->m_nPositionOffset);
              }
              else
              {
                inputBuffer = *v43 + v73->m_nPositionOffset;
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      &inputBuffer,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v44;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              if ( (b->m_Flags & 1) != 0 )
              {
                v45 = b->m_Put;
                if ( v45 != 0 && b->m_Memory.m_pMemory[v45 - b->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: b);
              }
              if ( CUtlBuffer::CheckPut(this: b, nSize: 1) != 0 )
              {
                b->m_Memory.m_pMemory[b->m_Put++ - b->m_nOffset] = 47;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
              v46 = (char *)pTmpDeltaState->__vftable + v73->m_nTextureOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", (char *)pTmpDeltaState->__vftable + v73->m_nTextureOffset);
              }
              else
              {
                inputBuffer = (int)pTmpDeltaState->__vftable + v73->m_nTextureOffset;
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      &inputBuffer,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v46;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              if ( (b->m_Flags & 1) != 0 )
              {
                v47 = b->m_Put;
                if ( v47 != 0 && b->m_Memory.m_pMemory[v47 - b->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: b);
              }
              if ( CUtlBuffer::CheckPut(this: b, nSize: 1) != 0 )
              {
                b->m_Memory.m_pMemory[b->m_Put++ - b->m_nOffset] = 47;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
              m_pMemory = absolute;
              v30 = pEnd;
              v31 = " ";
            }
            else
            {
              CUtlBuffer::PutString(this: b, pString: "\n");
              v31 = "f ";
            }
          }
        }
      }
      else if ( uvData == (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)nConstDatad )
      {
        while ( m_pMemory < v30 )
        {
          v48 = *m_pMemory++;
          absolute = m_pMemory;
          if ( v48 >= 0 )
          {
            v49 = v48;
            pTmpDeltaState = (CDmeVertexDeltaData *)&pnIndices->m_Memory.m_pMemory[v49];
            v50 = &ppIndices->m_Memory.m_pMemory[v49];
            CUtlBuffer::PutString(this: b, pString: v31);
            v51 = *v50 + v73->m_nPositionOffset;
            if ( (b->m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: b, pFmt: "%d", *v50 + v73->m_nPositionOffset);
            }
            else
            {
              inputBuffer = *v50 + v73->m_nPositionOffset;
              if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
              {
                if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                  CByteswap::SwapBufferToTargetEndian<int>(
                    this: &b->m_Byteswap,
                    outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                    &inputBuffer,
                    count: 1);
                else
                  *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v51;
                b->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
            }
            CUtlBuffer::PutString(this: b, pString: "//");
            v52 = (char *)pTmpDeltaState->__vftable + v73->m_nNormalOffset;
            if ( (b->m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: b, pFmt: "%d", (char *)pTmpDeltaState->__vftable + v73->m_nNormalOffset);
            }
            else
            {
              inputBuffer = (int)pTmpDeltaState->__vftable + v73->m_nNormalOffset;
              if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
              {
                if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                  CByteswap::SwapBufferToTargetEndian<int>(
                    this: &b->m_Byteswap,
                    outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                    &inputBuffer,
                    count: 1);
                else
                  *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v52;
                b->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
            }
            m_pMemory = absolute;
            v30 = pEnd;
            v31 = " ";
          }
          else
          {
            CUtlBuffer::PutString(this: b, pString: "\n");
            v31 = "f ";
          }
        }
      }
      else
      {
        while ( m_pMemory < v30 )
        {
          v53 = *m_pMemory++;
          if ( v53 >= 0 )
          {
            absolute = &ppIndices->m_Memory.m_pMemory[v53];
            CUtlBuffer::PutString(this: b, pString: v31);
            v54 = *absolute + v73->m_nPositionOffset;
            if ( (b->m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: b, pFmt: "%d", *absolute + v73->m_nPositionOffset);
            }
            else
            {
              absolute = (const int *)(*absolute + v73->m_nPositionOffset);
              if ( CUtlBuffer::CheckPut(this: b, nSize: 4) != 0 )
              {
                if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                  CByteswap::SwapBufferToTargetEndian<int>(
                    this: &b->m_Byteswap,
                    outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                    inputBuffer: (int *)&absolute,
                    count: 1);
                else
                  *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v54;
                b->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
            }
            CUtlBuffer::PutString(this: b, pString: "//");
            v30 = pEnd;
            v31 = " ";
          }
          else
          {
            CUtlBuffer::PutString(this: b, pString: "\n");
            v31 = "f ";
          }
        }
      }
    }
    v55 = v73;
    v73->m_nPositionOffset += (int)depDeltas;
    v56 = nTextureCount;
    v55->m_nNormalOffset += nDepDeltas;
    v55->m_nTextureOffset += v56;
    CUtlVector<CDmeMesh::DeltaComputation_t,CUtlMemory<CDmeMesh::DeltaComputation_t,int>>::RemoveAll(this: &compList);
    v57 = compList.m_Memory.m_pMemory;
    if ( compList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( compList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: compList.m_Memory.m_pMemory);
        v57 = nullptr;
        compList.m_Memory.m_pMemory = nullptr;
      }
      compList.m_Memory.m_nAllocationCount = 0;
    }
    compList.m_pElements = v57;
    if ( compList.m_Memory.m_nGrowSize >= 0 && v57 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
  }
  else
  {
    CUtlVector<CDmeMesh::DeltaComputation_t,CUtlMemory<CDmeMesh::DeltaComputation_t,int>>::~CUtlVector<CDmeMesh::DeltaComputation_t,CUtlMemory<CDmeMesh::DeltaComputation_t,int>>(this: &compList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B16B0
// Name: private: void CDmObjSerializer::DagToObj(class CUtlBuffer __near &,struct matrix3x4_t const __near &,class CDmeDag __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmObjSerializer::DagToObj(
        CDmObjSerializer *this,
        CUtlBuffer *b,
        const matrix3x4_t *parentWorldMatrix,
        CDmeDag *pDag,
        const char *pDeltaName,
        const int *absolute)
{
  CDmeTransform *Transform; // eax
  CDmeShape *Shape; // eax
  CDmeMesh *v9; // esi
  int Phase; // ebx
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t inclusiveMatrix; // [esp+Ch] [ebp-34h] BYREF
  CDmObjSerializer *v14; // [esp+3Ch] [ebp-4h]

  v14 = this;
  Transform = CDmeDag::GetTransform(this: pDag);
  CDmeTransform::GetTransform(this: Transform, transform: &inclusiveMatrix);
  ConcatTransforms(in1: parentWorldMatrix, in2: &inclusiveMatrix, out: &inclusiveMatrix);
  Shape = CDmeDag::GetShape(this: pDag);
  v9 = (CDmeMesh *)Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
    CDmObjSerializer::MeshToObj(this, b, parentWorldMatrix: &inclusiveMatrix, pMesh: v9, pDeltaName, absolute);
  Phase = CDmElementFramework::GetPhase(this: pDag);
  for ( i = 0; i < Phase; ++i )
  {
    Child = CDmeDag::GetChild(this: pDag, i);
    CDmObjSerializer::DagToObj(
      this: v14,
      b,
      parentWorldMatrix: &inclusiveMatrix,
      pDag: Child,
      pDeltaName,
      (bool)absolute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B1770
// Name: public: bool CDmObjSerializer::WriteOBJ(char const __near *,class CDmElement __near *,bool,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmObjSerializer::WriteOBJ(
        CDmObjSerializer *this,
        CDmeMesh *pFilename,
        CDmElement *pRoot,
        bool bWriteOBJs,
        const char *pDeltaName,
        const int *absolute)
{
  CDmeDag *Value; // edi
  _WORD *v9; // eax
  int v10; // edi
  CDmeMesh *v11; // esi
  CDmeVertexDeltaData *DeltaState; // eax
  CDmeVertexDeltaData *v13; // edi
  const char *m_pAsString; // eax
  char *m_Id; // esi
  const char *v16; // eax
  char *k; // eax
  const char *v18; // eax
  const char *v19; // eax
  char path[260]; // [esp+8h] [ebp-39Ch] BYREF
  char base[260]; // [esp+10Ch] [ebp-298h] BYREF
  char filename[260]; // [esp+210h] [ebp-194h] BYREF
  matrix3x4_t identityMatrix; // [esp+314h] [ebp-90h] BYREF
  CUtlBuffer b; // [esp+344h] [ebp-60h] BYREF
  CDmeDag *pModel; // [esp+374h] [ebp-30h]
  int nDeltaMeshes; // [esp+378h] [ebp-2Ch]
  int nDeltas; // [esp+37Ch] [ebp-28h]
  CUtlVector<CDmeMesh *,CUtlMemory<CDmeMesh *,int> > deltaMeshes; // [esp+380h] [ebp-24h] BYREF
  CUtlString deltaFile; // [esp+394h] [ebp-10h] BYREF
  CDmeMesh *pDeltaMesh; // [esp+3ACh] [ebp+8h]
  int i; // [esp+3B0h] [ebp+Ch]
  int j; // [esp+3B4h] [ebp+10h]

  Value = CDmElement::GetValueElement<CDmeDag>(this: pRoot, pAttributeName: "model");
  pModel = Value;
  if ( Value == nullptr )
    return 0;
  SetIdentityMatrix(matrix: &identityMatrix);
  if ( pDeltaName == nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: &b, growSize: 0, initSize: 0, nFlags: 1u);
    CUtlBuffer::PutString(this: &b, pString: "# OBJ\n");
    CUtlBuffer::PutString(this: &b, pString: "#\n");
    this->m_nPositionOffset = 1;
    this->m_nTextureOffset = 1;
    this->m_nNormalOffset = 1;
    CDmObjSerializer::DagToObj(this, &b, parentWorldMatrix: &identityMatrix, pDag: Value, pDeltaName: nullptr, absolute);
    g_pFullFileSystem->WriteFile(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: (const char *)pFilename,
      a3: nullptr,
      a4: &b);
    rename(oldname: (const char *)pFilename, newname: (const char *)pFilename);
    if ( b.m_Memory.m_nGrowSize >= 0 && b.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: b.m_Memory.m_pMemory);
  }
  if ( bWriteOBJs )
  {
    memset(&deltaMeshes, 0, sizeof(deltaMeshes));
    CDmObjSerializer::FindDeltaMeshes(
      pDag: Value,
      meshes: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&deltaMeshes);
    if ( deltaMeshes.m_Size != 0 )
    {
      V_FileBase(in: (const char *)pFilename, out: base, maxlen: 260);
      V_ExtractFilePath(path: (const char *)pFilename, dest: path, destSize: 260);
      strchr(string: (unsigned __int8 *)base, chr: 0x3Du);
      if ( v9 != nullptr || (strchr(string: (unsigned __int8 *)base, chr: 0x5Fu), v9 != nullptr) )
        *v9 = 95;
      v10 = 0;
      nDeltaMeshes = deltaMeshes.m_Size;
      for ( i = 0; v10 < nDeltaMeshes; i = v10 )
      {
        v11 = deltaMeshes.m_Memory.m_pMemory[v10];
        pDeltaMesh = v11;
        nDeltas = CDmeMesh::DeltaStateCount(this: v11);
        j = 0;
        if ( nDeltas > 0 )
        {
          while ( 1 )
          {
            DeltaState = CDmeMesh::GetDeltaState(this: v11, nDeltaIndex: j);
            v13 = DeltaState;
            if ( pDeltaName == nullptr )
              goto LABEL_20;
            m_pAsString = DeltaState->m_Name.m_Storage.u.m_pAsString;
            if ( m_pAsString == (const char *)-1 )
              m_pAsString = var;
            if ( _V_strcmp(s1: pDeltaName, s2: m_pAsString) == 0 )
            {
LABEL_20:
              CUtlBuffer::CUtlBuffer(this: &b, growSize: 0, initSize: 0, nFlags: 1u);
              m_Id = (char *)var;
              if ( v13->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
                m_Id = (char *)v13->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
              CUtlBuffer::PutString(this: &b, pString: "# Delta OBJ: ");
              CUtlBuffer::PutString(this: &b, pString: m_Id);
              CUtlBuffer::PutString(this: &b, pString: "\n");
              CUtlBuffer::PutString(this: &b, pString: "#\n");
              v16 = v13->m_Name.m_Storage.u.m_pAsString;
              if ( v16 == (const char *)-1 )
                v16 = var;
              V_strncpy(pDest: filename, pSrc: v16, maxLen: 260);
              for ( k = filename; *k != 0; ++k )
              {
                if ( k >= (char *)&identityMatrix )
                  break;
                if ( *k == 95 )
                  *k = 43;
              }
              CUtlString::CUtlString(this: &deltaFile, pString: base);
              CUtlString::operator+=(this: &deltaFile, rhs: filename);
              CUtlString::operator+=(this: &deltaFile, rhs: ".obj");
              this->m_nPositionOffset = 1;
              this->m_nTextureOffset = 1;
              this->m_nNormalOffset = 1;
              v18 = v13->m_Name.m_Storage.u.m_pAsString;
              if ( v18 == (const char *)-1 )
                v18 = var;
              CDmObjSerializer::DagToObj(
                this,
                &b,
                parentWorldMatrix: &identityMatrix,
                pDag: pModel,
                pDeltaName: v18,
                absolute);
              v19 = CUtlString::Get(this: &deltaFile);
              V_ComposeFileName(path, filename: v19, dest: filename, destSize: 260);
              g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: nullptr, a4: &b);
              rename(oldname: filename, newname: filename);
              deltaFile.m_Storage.m_nActualLength = 0;
              if ( deltaFile.m_Storage.m_Memory.m_nGrowSize >= 0 )
              {
                if ( deltaFile.m_Storage.m_Memory.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: deltaFile.m_Storage.m_Memory.m_pMemory);
                  deltaFile.m_Storage.m_Memory.m_pMemory = nullptr;
                }
                deltaFile.m_Storage.m_Memory.m_nAllocationCount = 0;
              }
              if ( b.m_Memory.m_nGrowSize >= 0 && b.m_Memory.m_pMemory != nullptr )
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: b.m_Memory.m_pMemory);
            }
            if ( ++j >= nDeltas )
              break;
            v11 = pDeltaMesh;
          }
          v10 = i;
        }
        ++v10;
      }
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&deltaMeshes);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B1B10
// Name: public: class CDmeVertexDeltaData __near * CDmObjSerializer::GetDelta(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmObjSerializer::GetDelta(CDmObjSerializer *this, char *pDeltaName, int bAbsolute)
{
  CDmeVertexDeltaData *result; // eax
  int m_Id; // edi
  int m_Size; // ecx
  CDmObjSerializer::DeltaInfo_t *v7; // esi
  const char *v8; // eax
  int v9; // eax
  CDmElement *v10; // eax
  CDmeVertexDeltaData *v11; // edi
  const char *v12; // [esp-10h] [ebp-150h]
  char deltaPath[260]; // [esp+8h] [ebp-138h] BYREF
  CUtlBuffer utlBuf; // [esp+10Ch] [ebp-34h] BYREF
  CUtlSymbol v15; // [esp+13Ch] [ebp-4h] BYREF

  if ( CUtlSymbolTable::Find(this: &this->m_deltas.m_SymbolTable, result: &v15, pString: pDeltaName)->m_Id == 0xFFFF )
    return nullptr;
  CUtlSymbolTable::AddString(this: &this->m_deltas.m_SymbolTable, result: &v15, pString: pDeltaName);
  m_Id = v15.m_Id;
  m_Size = this->m_deltas.m_Vector.m_Size;
  if ( m_Size <= v15.m_Id && m_Size < v15.m_Id + 1 )
    CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>::InsertMultipleBefore(
      this: &this->m_deltas.m_Vector,
      elem: m_Size,
      num: v15.m_Id + 1 - m_Size);
  v7 = &this->m_deltas.m_Vector.m_Memory.m_pMemory[m_Id];
  result = v7->m_pDeltaData;
  if ( result == nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: &utlBuf, growSize: 0, initSize: 0, nFlags: 0);
    v12 = CUtlString::operator char const *(this: &v7->m_filename);
    v8 = CUtlString::operator char const *(this: &this->m_objDirectory);
    V_ComposeFileName(path: v8, filename: v12, dest: deltaPath, destSize: 260);
    V_FixSlashes(pname: deltaPath, separator: 92);
    if ( g_pFullFileSystem->ReadFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: deltaPath,
           a3: nullptr,
           a4: &utlBuf,
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      if ( v7->m_pComboOp != nullptr )
      {
        strchr(string: (unsigned __int8 *)pDeltaName, chr: 0x5Fu);
        if ( v9 == 0 )
          CDmeCombinationOperator::FindOrCreateControl(
            this: v7->m_pComboOp,
            pControlName: pDeltaName,
            bStereo: 0,
            bAutoAddRawControl: true);
      }
      v10 = CDmObjSerializer::ReadOBJ(
              this,
              buf: &utlBuf,
              dmFileId: (DmElementHandle_t)v7->m_pMesh->m_fileId,
              pName: pDeltaName,
              pFilename: deltaPath,
              pBaseMesh: v7->m_pMesh,
              ppCreatedMesh: nullptr,
              bAbsolute);
      v11 = CastElement<CDmeVertexDeltaData>(pElement: v10);
      v7->m_pDeltaData = v11;
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &utlBuf);
      return v11;
    }
    else
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &utlBuf);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B1C70
// Name: public: virtual bool CDmObjSerializer::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmObjSerializer::Unserialize(
        CDmObjSerializer *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement *OBJ; // eax

  OBJ = CDmObjSerializer::ReadOBJ(
          this,
          buf,
          dmFileId: (DmElementHandle_t)fileid,
          pName: "bind",
          pFilename: nullptr,
          pBaseMesh: nullptr,
          ppCreatedMesh: nullptr,
          bAbsolute: 1);
  *ppRoot = OBJ;
  return OBJ != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B1CA0
// Name: public: class CDmElement __near * CDmObjSerializer::ReadOBJ(char const __near *,class CDmeMesh __near * __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__userpurge CDmObjSerializer::ReadOBJ@<eax>(
        CDmObjSerializer *this@<ecx>,
        int a2@<ebx>,
        CDmeCombinationOperator *pFilename,
        CDmeMesh **ppCreatedMesh,
        bool bLoadAllDeltas,
        int bAbsolute)
{
  CDmElement *v8; // ebx
  char *v9; // eax
  char *v10; // esi
  char *v11; // eax
  char *v12; // esi
  const char *FileExtension; // eax
  const char *i; // ebx
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // edi
  unsigned __int8 *v17; // eax
  int v18; // eax
  CDmElement *v19; // esi
  CDmObjSerializer::DeltaInfo_t *v20; // esi
  bool v21; // zf
  CDmeMesh *v22; // esi
  char deltaPath[260]; // [esp+8h] [ebp-758h] BYREF
  char findPath[260]; // [esp+10Ch] [ebp-654h] BYREF
  char deltaFile[260]; // [esp+210h] [ebp-550h] BYREF
  char findGlob[260]; // [esp+314h] [ebp-44Ch] BYREF
  char path[260]; // [esp+418h] [ebp-348h] BYREF
  char filename[260]; // [esp+51Ch] [ebp-244h] BYREF
  char baseFile[260]; // [esp+620h] [ebp-140h] BYREF
  CUtlBuffer utlBuf; // [esp+724h] [ebp-3Ch] BYREF
  CDmObjSerializer *v32; // [esp+754h] [ebp-Ch]
  CDmElement *pRoot; // [esp+758h] [ebp-8h]
  CDmeMesh *pMesh; // [esp+75Ch] [ebp-4h] BYREF
  CDmeCombinationOperator *pCombo; // [esp+768h] [ebp+8h]

  v32 = this;
  V_strncpy(pDest: filename, pSrc: (const char *)pFilename, maxLen: 260);
  V_FixSlashes(pname: filename, separator: 92);
  CUtlBuffer::CUtlBuffer(this: &utlBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: filename,
         a3: nullptr,
         a4: &utlBuf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    V_FileBase(in: filename, out: baseFile, maxlen: 260);
    pMesh = nullptr;
    v8 = CDmObjSerializer::ReadOBJ(
           this,
           buf: &utlBuf,
           dmFileId: DMELEMENT_HANDLE_INVALID,
           pName: baseFile,
           pFilename: filename,
           pBaseMesh: nullptr,
           ppCreatedMesh: &pMesh,
           bAbsolute);
    pRoot = v8;
    if ( v8 != nullptr && pMesh != nullptr )
    {
      if ( ppCreatedMesh != nullptr )
        *ppCreatedMesh = pMesh;
      pCombo = nullptr;
      v9 = _V_strrchr(s: baseFile, c: 61);
      v10 = v9;
      if ( v9 == nullptr || *v9 == 0 )
      {
        v11 = _V_strrchr(s: baseFile, c: 95);
        v10 = v11;
        if ( v11 == nullptr || *v11 == 0 || _V_stricmp(s1: v11, s2: "_zero") != 0 )
        {
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &utlBuf);
          return v8;
        }
      }
      V_strncpy(pDest: findGlob, pSrc: baseFile, maxLen: 260);
      v12 = v10 - 780;
      *(_WORD *)v12 = 10847;
      v12[2] = 46;
      FileExtension = V_GetFileExtension(path: filename);
      V_strncpy(pDest: v12 + 3, pSrc: FileExtension, maxLen: &findGlob[257] - v12);
      V_ExtractFilePath(path: filename, dest: path, destSize: 260);
      CUtlString::operator=(this: &this->m_objDirectory, src: path);
      V_ComposeFileName(path, filename: findGlob, dest: findPath, destSize: 260);
      for ( i = (const char *)((int (__thiscall *)(IFileSystem *, char *, CDmeMesh ***, int))g_pFullFileSystem->FindFirst)(
                                a1: g_pFullFileSystem,
                                a2: findPath,
                                a3: &ppCreatedMesh,
                                a4: a2);
            i != nullptr;
            i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: ppCreatedMesh) )
      {
        if ( *i == 0 )
          break;
        V_FileBase(in: i, out: deltaFile, maxlen: 260);
        if ( _V_stricmp(s1: baseFile, s2: deltaFile) != 0 )
        {
          V_ComposeFileName(path, filename: i, dest: deltaPath, destSize: 260);
          if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: deltaPath, a3: nullptr) )
          {
            strchr(string: (unsigned __int8 *)deltaFile, chr: 0x5Fu);
            v16 = v15;
            if ( v15 != nullptr && v15[1] != 0 )
            {
              v16 = v15 + 1;
              strchr(string: v15 + 1, chr: 0x2Bu);
              while ( v17 != nullptr )
              {
                *v17 = 95;
                strchr(string: v17, chr: 0x2Bu);
              }
            }
            strchr(string: v16, chr: 0x5Fu);
            if ( v18 == 0 && pCombo == nullptr )
            {
              v19 = pRoot;
              pCombo = CreateElement<CDmeCombinationOperator>(
                         pObjectName: "combinationOperator",
                         fileid: pRoot->m_fileId,
                         pObjectID: nullptr);
              CDmElement::SetValue<CDmeCombinationOperator>(
                this: v19,
                pAttributeName: "combinationOperator",
                pElement: (DmElementHandle_t)pCombo,
                bCreateIfNotFound: true);
            }
            v20 = CUtlStringMap<CDmObjSerializer::DeltaInfo_t>::operator[](this: &v32->m_deltas, pString: (char *)v16);
            CUtlString::operator=(this: &v20->m_filename, src: i);
            v21 = !bLoadAllDeltas;
            v20->m_pMesh = pMesh;
            v20->m_pComboOp = pCombo;
            if ( !v21 )
              CDmObjSerializer::GetDelta(this: v32, pDeltaName: (char *)v16, bAbsolute);
          }
        }
      }
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)ppCreatedMesh);
      if ( pCombo != nullptr )
      {
        v22 = pMesh;
        CDmeCombinationOperator::AddTarget(this: pCombo, pElement: pMesh);
        CDmeMesh::ComputeAllCorrectedPositionsFromActualPositions(this: v22);
      }
      v8 = pRoot;
    }
    if ( utlBuf.m_Memory.m_nGrowSize >= 0 && utlBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: utlBuf.m_Memory.m_pMemory);
    return v8;
  }
  else
  {
    if ( utlBuf.m_Memory.m_nGrowSize >= 0 && utlBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: utlBuf.m_Memory.m_pMemory);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AE760
// Name: class CDmeMesh __near * CreateElement<class CDmeMesh>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *__cdecl CreateElement<CDmeMesh>(const char *pObjectName, DmFileId_t fileid, const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMesh::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeMesh::m_classType) )
    return (CDmeMesh *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AF380
// Name: class CDmeCombinationOperator __near * CreateElement<class CDmeCombinationOperator>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *__cdecl CreateElement<CDmeCombinationOperator>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeCombinationOperator::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeCombinationOperator::m_classType) )
    return (CDmeCombinationOperator *)((char *)&v5[-1] + 64);
  else
    return nullptr;
}

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D03A0
// Name: private: static char const __near * CDmObjSerializer::SkipSpace(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmObjSerializer::SkipSpace(const char *pBuf)
{
  const char *result; // eax

  for ( result = pBuf; *result == 32 || *result == 9; ++result )
    ;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D03C0
// Name: private: static bool CDmObjSerializer::ParseVertex(class CUtlBuffer __near &,struct characterset_t __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmObjSerializer::ParseVertex(CUtlBuffer *bufParse, characterset_t *breakSet, int *v, int *t, int *n)
{
  char cmd[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false) <= 0 )
    return 0;
  *v = atoi(nptr: cmd);
  *n = 0;
  *t = 0;
  if ( breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0 )
  {
    CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
    if ( breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0
      || (CUtlBuffer::ParseToken(
            this: bufParse,
            pBreaks: breakSet,
            pTokenBuf: cmd,
            nMaxLen: 1024,
            bParseComments: false),
          *t = atoi(nptr: cmd),
          breakSet->set[(char)bufParse->m_Memory.m_pMemory[bufParse->m_Get - bufParse->m_nOffset]] != 0) )
    {
      CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
      CUtlBuffer::ParseToken(this: bufParse, pBreaks: breakSet, pTokenBuf: cmd, nMaxLen: 1024, bParseComments: false);
      *n = atoi(nptr: cmd);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005D0550
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D0670
// Name: protected: class CDmeVertexDataBase __near * CVertexData::Add(class CDmeMesh __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexData *__thiscall CVertexData::Add(CVertexData *this, CDmeMesh *pMesh, const char *pName)
{
  CDmeVertexData *result; // eax
  const char *v5; // ebx
  CDmeVertexData *BaseState; // edi
  CDmAttribute *m_pAttribute; // ecx
  int Field; // ebx
  int v9; // ebx
  int v10; // ebx

  result = nullptr;
  if ( this->m_positions.m_Size != 0 && this->m_pIndices.m_Size != 0 )
  {
    v5 = pName;
    BaseState = CDmeMesh::FindOrCreateBaseState(this: pMesh, pStateName: (int)pName);
    CDmeMesh::SetCurrentBaseState(this: pMesh, pStateName: v5);
    CDmeVertexData::AddVertexIndices(this: BaseState, nIndexCount: this->m_pIndices.m_Size);
    m_pAttribute = BaseState->m_bFlipVCoordinates.m_pAttribute;
    LOBYTE(pMesh) = 1;
    CDmAttribute::SetValue<bool>(this: m_pAttribute, value: (bool *)&pMesh);
    Field = CDmeVertexDataBase::CreateField(this: BaseState, fieldId: FIELD_POSITION);
    CDmeVertexDataBase::AddVertexData(
      this: BaseState,
      nFieldIndex: (CDmrGenericArray)Field,
      nCount: this->m_positions.m_Size);
    CDmeVertexDataBase::SetVertexData(
      this: BaseState,
      nFieldIndex: (CDmrGenericArray)Field,
      nFirstVertex: 0,
      nCount: this->m_positions.m_Size,
      valueType: AT_VECTOR3,
      pData: this->m_positions.m_Memory.m_pMemory);
    CDmeVertexDataBase::SetVertexIndices(
      this: BaseState,
      nFieldIndex: Field,
      nFirstIndex: 0,
      nCount: this->m_pIndices.m_Size,
      pIndices: this->m_pIndices.m_Memory.m_pMemory);
    if ( this->m_normals.m_Size != 0 && this->m_nIndices.m_Size != 0 )
    {
      v9 = CDmeVertexDataBase::CreateField(this: BaseState, fieldId: FIELD_NORMAL);
      CDmeVertexDataBase::AddVertexData(
        this: BaseState,
        nFieldIndex: (CDmrGenericArray)v9,
        nCount: this->m_normals.m_Size);
      CDmeVertexDataBase::SetVertexData(
        this: BaseState,
        nFieldIndex: (CDmrGenericArray)v9,
        nFirstVertex: 0,
        nCount: this->m_normals.m_Size,
        valueType: AT_VECTOR3,
        pData: this->m_normals.m_Memory.m_pMemory);
      CDmeVertexDataBase::SetVertexIndices(
        this: BaseState,
        nFieldIndex: v9,
        nFirstIndex: 0,
        nCount: this->m_nIndices.m_Size,
        pIndices: this->m_nIndices.m_Memory.m_pMemory);
    }
    if ( this->m_uvs.m_Size != 0 && this->m_uvIndices.m_Size != 0 )
    {
      v10 = CDmeVertexDataBase::CreateField(this: BaseState, fieldId: FIELD_TEXCOORD);
      CDmeVertexDataBase::AddVertexData(this: BaseState, nFieldIndex: (CDmrGenericArray)v10, nCount: this->m_uvs.m_Size);
      CDmeVertexDataBase::SetVertexData(
        this: BaseState,
        nFieldIndex: (CDmrGenericArray)v10,
        nFirstVertex: 0,
        nCount: this->m_uvs.m_Size,
        valueType: AT_VECTOR2,
        pData: this->m_uvs.m_Memory.m_pMemory);
      CDmeVertexDataBase::SetVertexIndices(
        this: BaseState,
        nFieldIndex: v10,
        nFirstIndex: 0,
        nCount: this->m_uvIndices.m_Size,
        pIndices: this->m_uvIndices.m_Memory.m_pMemory);
    }
    return BaseState;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D07A0
// Name: protected: class CDmeVertexDeltaData __near * CVertexData::AddDelta(class CDmeMesh __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CVertexData::AddDelta(CVertexData *this, CDmeMesh *pMesh, int bAbsolute, int pName)
{
  bool v5; // zf
  CDmeVertexData *BaseState; // eax
  int v8; // ecx
  CDmAttribute *m_pVertexData; // edi
  int m_Size; // ecx
  int v11; // eax
  int v12; // ecx
  Vector *m_pMemory; // edx
  Vector *v14; // eax
  Vector *v15; // edx
  Vector *v16; // eax
  Vector *v17; // edx
  Vector *v18; // eax
  float v19; // xmm0_4
  Vector *v20; // eax
  Vector *v21; // edx
  Vector *v22; // eax
  float v23; // xmm0_4
  int v24; // edx
  int v25; // edi
  Vector *v26; // ecx
  Vector *v27; // eax
  float v28; // xmm0_4
  void *v29; // esp
  int v30; // ebx
  int v31; // edi
  int v32; // eax
  int v33; // ecx
  Vector *v34; // edx
  Vector *v35; // edx
  Vector *v36; // edx
  Vector *v37; // edx
  int v38; // edx
  unsigned int v39; // ecx
  Vector *v40; // eax
  CDmeVertexDeltaData *DeltaState; // ebx
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *Attribute; // eax
  DmAttributeHandle_t m_Handle; // eax
  CDmAttribute *v45; // edi
  int v46; // eax
  unsigned int v47; // ecx
  Vector *v48; // eax
  DmeTime_t *v49; // edx
  DmeTime_t *v50; // edx
  Vector *v51; // eax
  Vector *v52; // eax
  DmeTime_t *v53; // edx
  float v54; // xmm0_4
  Vector *v55; // eax
  DmeTime_t *v56; // edx
  Vector *v57; // eax
  float v58; // xmm0_4
  float *p_x; // eax
  float v60; // xmm0_4
  unsigned int v61; // edx
  int v62; // edi
  Vector *v63; // eax
  DmeTime_t *v64; // ecx
  float v65; // xmm0_4
  float *v66; // eax
  float v67; // xmm0_4
  int v68; // edi
  void *v69; // esp
  CDmeMesh *v70; // ebx
  int v71; // edx
  int v72; // eax
  int v73; // ecx
  Vector *v74; // edi
  Vector *v75; // edi
  int *v76; // ebx
  Vector *v77; // edi
  int *v78; // ebx
  Vector *v79; // edi
  int *v80; // ebx
  int v81; // edi
  int v82; // ecx
  int *v83; // edx
  Vector *v84; // eax
  _DWORD v85[3]; // [esp+0h] [ebp-2Ch] BYREF
  CDmrArrayConst<Vector> pBindData; // [esp+Ch] [ebp-20h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v87; // [esp+14h] [ebp-18h] BYREF
  int *pNormalIndices; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int pCount; // [esp+24h] [ebp-8h]
  int v91; // [esp+28h] [ebp-4h]

  v5 = this->m_positions.m_Size == 0;
  pCount = 0;
  if ( !v5 )
  {
    BaseState = CDmeMesh::FindBaseState(this: pMesh, pStateName: "bind");
    v87.m_pAttribute = (CDmAttribute *)BaseState;
    if ( BaseState == nullptr )
      return nullptr;
    v8 = BaseState->m_pStandardFieldIndex[0];
    if ( v8 < 0 )
      return nullptr;
    m_pVertexData = BaseState->m_FieldInfo.m_Memory.m_pMemory[v8].m_pVertexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&pBindData);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &pBindData,
      pAttribute: m_pVertexData);
    m_Size = this->m_positions.m_Size;
    pCount = m_Size;
    if ( pBindData.m_pStorage->m_Size != m_Size )
      return nullptr;
    v11 = 0;
    if ( m_Size >= 4 )
    {
      v12 = 0;
      pNormalIndices = (int *)(((unsigned int)(pCount - 4) >> 2) + 1);
      i = 4 * (_DWORD)pNormalIndices;
      do
      {
        m_pMemory = pBindData.m_pStorage->m_Memory.m_pMemory;
        v14 = this->m_positions.m_Memory.m_pMemory;
        v14[v12].x = this->m_positions.m_Memory.m_pMemory[v12].x - pBindData.m_pStorage->m_Memory.m_pMemory[v12].x;
        v14[v12].y = v14[v12].y - m_pMemory[v12].y;
        v14[v12].z = v14[v12].z - m_pMemory[v12].z;
        v15 = &pBindData.m_pStorage->m_Memory.m_pMemory[v12 + 1];
        v16 = this->m_positions.m_Memory.m_pMemory;
        v16[v12 + 1].x = this->m_positions.m_Memory.m_pMemory[v12 + 1].x - v15->x;
        v16[v12 + 1].y = v16[v12 + 1].y - v15->y;
        v16[v12 + 1].z = v16[v12 + 1].z - v15->z;
        v17 = pBindData.m_pStorage->m_Memory.m_pMemory;
        v18 = this->m_positions.m_Memory.m_pMemory;
        v18[v12 + 2].x = this->m_positions.m_Memory.m_pMemory[v12 + 2].x
                       - pBindData.m_pStorage->m_Memory.m_pMemory[v12 + 2].x;
        v19 = v18[v12 + 2].y - v17[v12 + 2].y;
        v20 = &v18[v12 + 2];
        v20->y = v19;
        v20->z = v20->z - v17[v12 + 2].z;
        v21 = pBindData.m_pStorage->m_Memory.m_pMemory;
        v22 = &this->m_positions.m_Memory.m_pMemory[v12 + 3];
        v22->x = v22->x - pBindData.m_pStorage->m_Memory.m_pMemory[v12 + 3].x;
        v22->y = v22->y - v21[v12 + 3].y;
        v23 = v22->z - v21[v12 + 3].z;
        v12 += 4;
        v5 = pNormalIndices == (int *)1;
        pNormalIndices = (int *)((char *)pNormalIndices - 1);
        v22->z = v23;
      }
      while ( !v5 );
      v11 = i;
    }
    if ( v11 < pCount )
    {
      v24 = v11;
      v25 = pCount - v11;
      do
      {
        v26 = pBindData.m_pStorage->m_Memory.m_pMemory;
        v27 = &this->m_positions.m_Memory.m_pMemory[v24];
        v27->x = v27->x - pBindData.m_pStorage->m_Memory.m_pMemory[v24].x;
        v27->y = v27->y - v26[v24].y;
        v28 = v27->z - v26[v24++].z;
        --v25;
        v27->z = v28;
      }
      while ( v25 != 0 );
    }
    v29 = alloca(4 * pCount);
    v30 = 0;
    v31 = 0;
    i = (int)v85;
    v91 = 0;
    if ( pCount >= 4 )
    {
      v32 = 0;
      pNormalIndices = (int *)2;
      v33 = 0;
      do
      {
        v34 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v33].x) >= 0.00024414062
          || fabs(v34[v33].y) >= 0.00024414062
          || fabs(v34[v33].z) >= 0.00024414062 )
        {
          v34[v32].x = this->m_positions.m_Memory.m_pMemory[v33].x;
          v34[v32].y = v34[v33].y;
          ++v31;
          v34[v32++].z = v34[v33].z;
          v85[v31 - 1] = v30;
        }
        v35 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v33 + 1].x) >= 0.00024414062
          || fabs(v35[v33 + 1].y) >= 0.00024414062
          || fabs(v35[v33 + 1].z) >= 0.00024414062 )
        {
          v35[v32].x = this->m_positions.m_Memory.m_pMemory[v33 + 1].x;
          v35[v32].y = v35[v33 + 1].y;
          ++v31;
          v35[v32].z = v35[v33 + 1].z;
          v85[v31 - 1] = (char *)pNormalIndices - 1;
          v30 = v91;
          ++v32;
        }
        v36 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v33 + 2].x) >= 0.00024414062
          || fabs(v36[v33 + 2].y) >= 0.00024414062
          || fabs(v36[v33 + 2].z) >= 0.00024414062 )
        {
          v36[v32].x = this->m_positions.m_Memory.m_pMemory[v33 + 2].x;
          v36[v32].y = v36[v33 + 2].y;
          ++v31;
          v36[v32].z = v36[v33 + 2].z;
          v85[v31 - 1] = pNormalIndices;
          v30 = v91;
          ++v32;
        }
        v37 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v33 + 3].x) >= 0.00024414062
          || fabs(v37[v33 + 3].y) >= 0.00024414062
          || fabs(v37[v33 + 3].z) >= 0.00024414062 )
        {
          v37[v32].x = this->m_positions.m_Memory.m_pMemory[v33 + 3].x;
          v37[v32].y = v37[v33 + 3].y;
          ++v31;
          v37[v32].z = v37[v33 + 3].z;
          v85[v31 - 1] = (char *)pNormalIndices + 1;
          v30 = v91;
          ++v32;
        }
        ++pNormalIndices;
        v30 += 4;
        v33 += 4;
        v91 = v30;
      }
      while ( v30 < pCount - 3 );
    }
    if ( v30 < pCount )
    {
      v38 = v31;
      v39 = v30;
      do
      {
        v40 = this->m_positions.m_Memory.m_pMemory;
        if ( fabs(this->m_positions.m_Memory.m_pMemory[v39].x) >= 0.00024414062
          || fabs(v40[v39].y) >= 0.00024414062
          || fabs(v40[v39].z) >= 0.00024414062 )
        {
          v40[v38].x = this->m_positions.m_Memory.m_pMemory[v39].x;
          v40[v38].y = v40[v39].y;
          ++v31;
          v40[v38++].z = v40[v39].z;
          v85[v31 - 1] = v30;
        }
        ++v30;
        ++v39;
      }
      while ( v30 < pCount );
    }
    DeltaState = CDmeMesh::FindOrCreateDeltaState(this: pMesh, pInDeltaName: (char *)pName, bSortDeltaName: 1);
    m_pAttribute = DeltaState->m_bFlipVCoordinates.m_pAttribute;
    pCount = (int)DeltaState;
    LOBYTE(pMesh) = 1;
    CDmAttribute::SetValue<bool>(this: m_pAttribute, value: (bool *)&pMesh);
    HIBYTE(bAbsolute) = (_BYTE)bAbsolute == 0;
    Attribute = CDmElement::FindAttribute(this: DeltaState, pAttributeName: "corrected");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: DeltaState, pAttributeName: "corrected", type: AT_BOOL)) != nullptr )
    {
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&bAbsolute + 3);
    }
    bAbsolute = CDmeVertexDataBase::CreateField(this: DeltaState, fieldId: FIELD_POSITION);
    CDmeVertexDataBase::AddVertexData(this: DeltaState, nFieldIndex: (CDmrGenericArray)bAbsolute, nCount: v31);
    CDmeVertexDataBase::SetVertexData(
      this: DeltaState,
      nFieldIndex: (CDmrGenericArray)bAbsolute,
      nFirstVertex: 0,
      nCount: v31,
      valueType: AT_VECTOR3,
      pData: this->m_positions.m_Memory.m_pMemory);
    CDmeVertexDataBase::SetVertexIndices(
      this: DeltaState,
      nFieldIndex: bAbsolute,
      nFirstIndex: 0,
      nCount: v31,
      pIndices: (const int *)i);
    m_Handle = v87.m_pAttribute[5].m_Handle;
    if ( m_Handle >= 0 )
    {
      v45 = *(CDmAttribute **)(v87.m_pAttribute[4].m_Handle + 48 * m_Handle + 16);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v87);
      CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
        this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v87,
        pAttribute: v45);
      bAbsolute = this->m_normals.m_Size;
      if ( v87.m_pStorage->m_Size == bAbsolute )
      {
        v46 = 0;
        if ( bAbsolute >= 4 )
        {
          pMesh = (CDmeMesh *)(((unsigned int)(bAbsolute - 4) >> 2) + 1);
          v47 = 0;
          pName = 4 * (_DWORD)pMesh;
          do
          {
            v48 = this->m_normals.m_Memory.m_pMemory;
            v49 = v87.m_pStorage->m_Memory.m_pMemory;
            v48[v47 / 0xC].x = v48[v47 / 0xC].x - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v47 / 4].m_tms;
            v48[v47 / 0xC].y = v48[v47 / 0xC].y - *(float *)&v49[v47 / 4 + 1].m_tms;
            v48[v47 / 0xC].z = v48[v47 / 0xC].z - *(float *)&v49[v47 / 4 + 2].m_tms;
            v50 = v87.m_pStorage->m_Memory.m_pMemory;
            v51 = this->m_normals.m_Memory.m_pMemory;
            v51[v47 / 0xC + 1].x = v51[v47 / 0xC + 1].x
                                 - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v47 / 4 + 3].m_tms;
            v51[v47 / 0xC + 1].y = v51[v47 / 0xC + 1].y - *(float *)&v50[v47 / 4 + 4].m_tms;
            v51[v47 / 0xC + 1].z = v51[v47 / 0xC + 1].z - *(float *)&v50[v47 / 4 + 5].m_tms;
            v52 = this->m_normals.m_Memory.m_pMemory;
            v53 = v87.m_pStorage->m_Memory.m_pMemory;
            v52[v47 / 0xC + 2].x = v52[v47 / 0xC + 2].x
                                 - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v47 / 4 + 6].m_tms;
            v54 = v52[v47 / 0xC + 2].y - *(float *)&v53[v47 / 4 + 7].m_tms;
            v55 = &v52[v47 / 0xC + 2];
            v55->y = v54;
            v55->z = v55->z - *(float *)&v53[v47 / 4 + 8].m_tms;
            v56 = v87.m_pStorage->m_Memory.m_pMemory;
            v57 = this->m_normals.m_Memory.m_pMemory;
            v58 = v57[v47 / 0xC + 3].x - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v47 / 4 + 9].m_tms;
            p_x = &v57[v47 / 0xC + 3].x;
            *p_x = v58;
            p_x[1] = p_x[1] - *(float *)&v56[v47 / 4 + 10].m_tms;
            v60 = p_x[2] - *(float *)&v56[v47 / 4 + 11].m_tms;
            v47 += 48;
            v5 = pMesh == (CDmeMesh *)1;
            pMesh = (CDmeMesh *)((char *)pMesh - 1);
            p_x[2] = v60;
          }
          while ( !v5 );
          v46 = pName;
        }
        if ( v46 < bAbsolute )
        {
          v61 = 12 * v46;
          v62 = bAbsolute - v46;
          do
          {
            v63 = this->m_normals.m_Memory.m_pMemory;
            v64 = v87.m_pStorage->m_Memory.m_pMemory;
            v65 = v63[v61 / 0xC].x - *(float *)&v87.m_pStorage->m_Memory.m_pMemory[v61 / 4].m_tms;
            v66 = &v63[v61 / 0xC].x;
            *v66 = v65;
            v66[1] = v66[1] - *(float *)&v64[v61 / 4 + 1].m_tms;
            v67 = v66[2] - *(float *)&v64[v61 / 4 + 2].m_tms;
            v61 += 12;
            --v62;
            v66[2] = v67;
          }
          while ( v62 != 0 );
        }
        v68 = bAbsolute;
        v69 = alloca(4 * bAbsolute);
        v70 = nullptr;
        v71 = 0;
        pNormalIndices = v85;
        pMesh = nullptr;
        if ( bAbsolute >= 4 )
        {
          v72 = 0;
          pName = 2;
          v73 = 0;
          do
          {
            v74 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v74[v73].x) >= 0.00024414062
              || fabs(v74[v73].y) >= 0.00024414062
              || fabs(v74[v73].z) >= 0.00024414062 )
            {
              v74[v72].x = v74[v73].x;
              v74[v72].y = v74[v73].y;
              ++v71;
              v74[v72++].z = v74[v73].z;
              pNormalIndices[v71 - 1] = (int)v70;
            }
            v75 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v75[v73 + 1].x) >= 0.00024414062
              || fabs(v75[v73 + 1].y) >= 0.00024414062
              || fabs(v75[v73 + 1].z) >= 0.00024414062 )
            {
              v76 = pNormalIndices;
              v75[v72].x = v75[v73 + 1].x;
              v75[v72].y = v75[v73 + 1].y;
              ++v71;
              v75[v72].z = v75[v73 + 1].z;
              v76[v71 - 1] = pName - 1;
              v70 = pMesh;
              ++v72;
            }
            v77 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v77[v73 + 2].x) >= 0.00024414062
              || fabs(v77[v73 + 2].y) >= 0.00024414062
              || fabs(v77[v73 + 2].z) >= 0.00024414062 )
            {
              v78 = pNormalIndices;
              v77[v72].x = v77[v73 + 2].x;
              v77[v72].y = v77[v73 + 2].y;
              ++v71;
              v77[v72++].z = v77[v73 + 2].z;
              v78[v71 - 1] = pName;
              v70 = pMesh;
            }
            v79 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v79[v73 + 3].x) >= 0.00024414062
              || fabs(v79[v73 + 3].y) >= 0.00024414062
              || fabs(v79[v73 + 3].z) >= 0.00024414062 )
            {
              v80 = pNormalIndices;
              v79[v72].x = v79[v73 + 3].x;
              v79[v72].y = v79[v73 + 3].y;
              ++v71;
              v79[v72].z = v79[v73 + 3].z;
              v80[v71 - 1] = pName + 1;
              v70 = pMesh;
              ++v72;
            }
            pName += 4;
            v70 = (CDmeMesh *)((char *)v70 + 4);
            v73 += 4;
            pMesh = v70;
          }
          while ( (int)v70 < bAbsolute - 3 );
          v68 = bAbsolute;
        }
        if ( (int)v70 < v68 )
        {
          v81 = v71;
          v82 = (int)v70;
          v83 = &pNormalIndices[v71];
          do
          {
            v84 = this->m_normals.m_Memory.m_pMemory;
            if ( fabs(v84[v82].x) >= 0.00024414062
              || fabs(v84[v82].y) >= 0.00024414062
              || fabs(v84[v82].z) >= 0.00024414062 )
            {
              v84[v81].x = v84[v82].x;
              v84[v81].y = v84[v82].y;
              *v83 = (int)v70;
              v84[v81++].z = v84[v82].z;
              ++v83;
            }
            v70 = (CDmeMesh *)((char *)v70 + 1);
            ++v82;
          }
          while ( (int)v70 < bAbsolute );
        }
      }
    }
  }
  return (CDmeVertexDeltaData *)pCount;
}

//------------------------------------------------------------------------------
// Address: 0x005D1020
// Name: private: char const __near * CDmObjSerializer::FindMtlEntry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmObjSerializer::FindMtlEntry(CDmObjSerializer *this, const char *pTgaName)
{
  int v3; // esi
  int i; // edi
  const char *v5; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_mtlLib.m_Size;
  if ( nCount <= 0 )
    return pTgaName;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_mtlLib.m_Memory.m_pMemory[i].m_MtlName);
    if ( _V_stricmp(s1: v5, s2: pTgaName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return pTgaName;
  }
  return CUtlString::operator char const *(this: &this->m_mtlLib.m_Memory.m_pMemory[v3].m_TgaName);
}

//------------------------------------------------------------------------------
// Address: 0x005D11B0
// Name: public: CVertexData::CVertexData(void)
// Source: json
//------------------------------------------------------------------------------
CVertexData *__thiscall CVertexData::CVertexData(CVertexData *this)
{
  this->m_positions.m_Memory.m_pMemory = nullptr;
  this->m_positions.m_Memory.m_nAllocationCount = 0;
  this->m_positions.m_Memory.m_nGrowSize = 0;
  this->m_positions.m_Size = 0;
  this->m_positions.m_pElements = nullptr;
  this->m_pIndices.m_Memory.m_pMemory = nullptr;
  this->m_pIndices.m_Memory.m_nAllocationCount = 0;
  this->m_pIndices.m_Memory.m_nGrowSize = 0;
  this->m_pIndices.m_Size = 0;
  this->m_pIndices.m_pElements = nullptr;
  this->m_normals.m_Memory.m_pMemory = nullptr;
  this->m_normals.m_Memory.m_nAllocationCount = 0;
  this->m_normals.m_Memory.m_nGrowSize = 0;
  this->m_normals.m_Size = 0;
  this->m_normals.m_pElements = nullptr;
  this->m_nIndices.m_Memory.m_pMemory = nullptr;
  this->m_nIndices.m_Memory.m_nAllocationCount = 0;
  this->m_nIndices.m_Memory.m_nGrowSize = 0;
  this->m_nIndices.m_Size = 0;
  this->m_nIndices.m_pElements = nullptr;
  this->m_uvs.m_Memory.m_pMemory = nullptr;
  this->m_uvs.m_Memory.m_nAllocationCount = 0;
  this->m_uvs.m_Memory.m_nGrowSize = 0;
  this->m_uvs.m_Size = 0;
  this->m_uvs.m_pElements = nullptr;
  this->m_uvIndexMap.m_Memory.m_pMemory = nullptr;
  this->m_uvIndexMap.m_Memory.m_nAllocationCount = 0;
  this->m_uvIndexMap.m_Memory.m_nGrowSize = 0;
  this->m_uvIndexMap.m_Size = 0;
  this->m_uvIndexMap.m_pElements = nullptr;
  this->m_uvIndices.m_Memory.m_pMemory = nullptr;
  this->m_uvIndices.m_Memory.m_nAllocationCount = 0;
  this->m_uvIndices.m_Memory.m_nGrowSize = 0;
  this->m_uvIndices.m_Size = 0;
  this->m_uvIndices.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005D1230
// Name: private: static int CDmObjSerializer::OutputVectors(class CUtlBuffer __near &,char const __near *,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmObjSerializer::OutputVectors(
        CUtlBuffer *b,
        const char *pPrefix,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *vData,
        const matrix3x4_t *matrix)
{
  int result; // eax
  int v5; // esi
  int i; // ebx
  CUtlBuffer *v7; // eax
  Vector v; // [esp+0h] [ebp-10h] BYREF
  int nv; // [esp+Ch] [ebp-4h]

  result = vData->m_Size;
  nv = result;
  if ( result > 0 )
  {
    v5 = 0;
    for ( i = result; i != 0; --i )
    {
      VectorTransform(in1: &vData->m_Memory.m_pMemory[v5].x, in2: matrix, out: &v.x);
      CUtlBuffer::PutString(this: b, pString: pPrefix);
      v7 = operator<<(b, &v);
      CUtlBuffer::PutString(this: v7, pString: "\n");
      ++v5;
    }
    return nv;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D12A0
// Name: private: static int CDmObjSerializer::OutputVectors(class CUtlBuffer __near &,char const __near *,class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmObjSerializer::OutputVectors(
        CUtlBuffer *b,
        const char *pPrefix,
        const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *vData)
{
  int result; // eax
  int v4; // ebx
  Vector2D *v5; // edi
  bool v6; // zf
  float x; // xmm0_4
  float y; // [esp+14h] [ebp-14h]
  float v9; // [esp+18h] [ebp-10h] BYREF
  float v10; // [esp+1Ch] [ebp-Ch]
  float inputBuffer; // [esp+20h] [ebp-8h] BYREF
  int nv; // [esp+24h] [ebp-4h]

  result = vData->m_Size;
  v4 = 0;
  nv = result;
  if ( result > 0 )
  {
    do
    {
      v5 = &vData->m_Memory.m_pMemory[v4];
      CUtlBuffer::PutString(this: b, pString: pPrefix);
      v6 = (b->m_Flags & 1) == 0;
      x = v5->x;
      v10 = v5->x;
      if ( v6 )
      {
        inputBuffer = x;
        if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
        {
          if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<float>(
              this: &b->m_Byteswap,
              outputBuffer: (float *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
              &inputBuffer,
              count: 1);
          else
            *(float *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v10;
          b->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
        }
      }
      else
      {
        CUtlBuffer::Printf(this: b, pFmt: "%f", x);
      }
      CUtlBuffer::PutString(this: b, pString: " ");
      y = v5->y;
      if ( (b->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: b, pFmt: "%f", v5->y);
      }
      else
      {
        v9 = v5->y;
        if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
        {
          if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<float>(
              this: &b->m_Byteswap,
              outputBuffer: (float *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
              inputBuffer: &v9,
              count: 1);
          else
            *(float *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = y;
          b->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
        }
      }
      CUtlBuffer::PutString(this: b, pString: "\n");
      ++v4;
    }
    while ( v4 < nv );
    return nv;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D1420
// Name: protected: void CVertexData::AddUniqueValue<class Vector2D>(class Vector2D const __near &,class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexData::AddUniqueValue<Vector2D>(
        CVertexData *this,
        const Vector2D *v,
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *vs,
        CUtlVector<int,CUtlMemory<int,int> > *map,
        float flThresh)
{
  int m_Size; // edx
  int v7; // ebx
  Vector2D *v8; // eax
  int v9; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // ebx
  int v14; // esi
  int v15; // eax
  Vector2D *v16; // ecx
  int v17; // eax
  Vector2D *v18; // esi
  int v19; // edi
  int v20; // eax
  int *v21; // ecx
  int v22; // eax
  int *v23; // eax
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *vsa; // [esp+18h] [ebp+Ch]

  m_Size = vs->m_Size;
  v7 = 0;
  vsa = (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)m_Size;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v9 = map->m_Size;
    m_nAllocationCount = map->m_Memory.m_nAllocationCount;
    if ( v9 + 1 > m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)map,
        num: v9 - m_nAllocationCount + 1);
      m_Size = (int)vsa;
    }
    ++map->m_Size;
    m_pMemory = map->m_Memory.m_pMemory;
    v12 = map->m_Size - v9 - 1;
    map->m_pElements = map->m_Memory.m_pMemory;
    if ( v12 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * v12);
      m_Size = (int)vsa;
    }
    v13 = &map->m_Memory.m_pMemory[v9];
    if ( v13 != nullptr )
      *v13 = m_Size;
    v14 = vs->m_Size;
    v15 = vs->m_Memory.m_nAllocationCount;
    if ( v14 + 1 > v15 )
      CUtlMemory<MDLSquenceLayer_t,int>::Grow(
        this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)vs,
        num: v14 - v15 + 1);
    ++vs->m_Size;
    v16 = vs->m_Memory.m_pMemory;
    v17 = vs->m_Size - v14 - 1;
    vs->m_pElements = vs->m_Memory.m_pMemory;
    if ( v17 > 0 )
      _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 8 * v17);
    v18 = &vs->m_Memory.m_pMemory[v14];
    if ( v18 != nullptr )
      *v18 = *v;
  }
  else
  {
    v8 = vs->m_Memory.m_pMemory;
    while ( flThresh <= (float)((float)((float)(v->x - v8->x) * (float)(v->x - v8->x))
                              + (float)((float)(v->y - v8->y) * (float)(v->y - v8->y))) )
    {
      ++v7;
      ++v8;
      if ( v7 >= m_Size )
        goto LABEL_5;
    }
    v19 = map->m_Size;
    v20 = map->m_Memory.m_nAllocationCount;
    if ( v19 + 1 > v20 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)map, num: v19 - v20 + 1);
    ++map->m_Size;
    v21 = map->m_Memory.m_pMemory;
    v22 = map->m_Size - v19 - 1;
    map->m_pElements = map->m_Memory.m_pMemory;
    if ( v22 > 0 )
      _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
    v23 = &map->m_Memory.m_pMemory[v19];
    if ( v23 != nullptr )
      *v23 = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D1590
// Name: public: void CVertexData::AddPositionIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexData::AddPositionIndex(CVertexData *this, vgui::TreeNode *i)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_pIndices; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_pIndices.m_Memory.m_nAllocationCount;
  p_m_pIndices = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pIndices;
  m_Size = this->m_pIndices.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_pIndices, num: m_Size - m_nAllocationCount + 1);
  ++p_m_pIndices[1].m_pMemory;
  m_pMemory = p_m_pIndices->m_pMemory;
  v6 = (int)p_m_pIndices[1].m_pMemory - m_Size - 1;
  p_m_pIndices[1].m_nAllocationCount = (int)p_m_pIndices->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_pIndices->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = i;
}

//------------------------------------------------------------------------------
// Address: 0x005D15F0
// Name: public: void CVertexData::AddNormalIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexData::AddNormalIndex(CVertexData *this, vgui::TreeNode *i)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_nIndices; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_nIndices.m_Memory.m_nAllocationCount;
  p_m_nIndices = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_nIndices;
  m_Size = this->m_nIndices.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_nIndices, num: m_Size - m_nAllocationCount + 1);
  ++p_m_nIndices[1].m_pMemory;
  m_pMemory = p_m_nIndices->m_pMemory;
  v6 = (int)p_m_nIndices[1].m_pMemory - m_Size - 1;
  p_m_nIndices[1].m_nAllocationCount = (int)p_m_nIndices->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_nIndices->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = i;
}

//------------------------------------------------------------------------------
// Address: 0x005D1650
// Name: private: static void CDmObjSerializer::FindDeltaMeshes(class CDmeDag __near *,class CUtlVector<class CDmeMesh __near *,class CUtlMemory<class CDmeMesh __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmObjSerializer::FindDeltaMeshes(CDmeDag *pDag, CUtlMemory<vgui::TreeNode *,int> *meshes)
{
  CDmeShape *Shape; // eax
  CDmeMesh *v3; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmeMesh **v6; // ecx
  int v7; // eax
  CDmeMesh **v8; // edi
  int Phase; // ebx
  int i; // edi
  CDmeDag *Child; // eax

  Shape = CDmeDag::GetShape(this: pDag);
  v3 = (CDmeMesh *)Shape;
  if ( Shape != nullptr
    && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType)
    && CDmeEditorChoicesInfo::GetChoiceCount(this: v3) != 0 )
  {
    m_pMemory = (int)meshes[1].m_pMemory;
    m_nAllocationCount = meshes->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: meshes, num: m_pMemory - m_nAllocationCount + 1);
    ++meshes[1].m_pMemory;
    v6 = (CDmeMesh **)meshes->m_pMemory;
    v7 = (int)meshes[1].m_pMemory - m_pMemory - 1;
    meshes[1].m_nAllocationCount = (int)meshes->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmeMesh **)&meshes->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = v3;
  }
  Phase = CDmElementFramework::GetPhase(this: pDag);
  for ( i = 0; i < Phase; ++i )
  {
    Child = CDmeDag::GetChild(this: pDag, i);
    CDmObjSerializer::FindDeltaMeshes(pDag: Child, (CUtlVector<CDmeMesh *,CUtlMemory<CDmeMesh *,int> > *)meshes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D17D0
// Name: private: void CDmObjSerializer::ParseMtlLib(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmObjSerializer::ParseMtlLib(CDmObjSerializer *this, CUtlBuffer *buf)
{
  CUtlBuffer *v3; // ecx
  int m_Size; // edi
  bool v5; // zf
  unsigned int v6; // eax
  char *v7; // edi
  int m_nAllocationCount; // eax
  CDmObjSerializer::MtlInfo_t *m_pMemory; // ecx
  int v10; // eax
  CDmObjSerializer::MtlInfo_t *v11; // ecx
  int v12; // ebx
  CUtlString *p_m_MtlName; // ecx
  char *v14; // ebx
  int v15; // eax
  char pLine[4096]; // [esp+8h] [ebp-190Ch] BYREF
  char str[1024]; // [esp+1008h] [ebp-90Ch] BYREF
  char out[1024]; // [esp+1408h] [ebp-50Ch] BYREF
  char pSrc[260]; // [esp+1808h] [ebp-10Ch] BYREF
  CDmObjSerializer *v20; // [esp+190Ch] [ebp-8h]
  CUtlString *v21; // [esp+1910h] [ebp-4h]

  v3 = buf;
  m_Size = -1;
  v5 = buf->m_Error == 0;
  v20 = this;
  if ( v5 )
  {
    do
    {
      CUtlBuffer::GetLine(this: v3, pLine, nMaxChars: 4096);
      if ( StringAfterPrefix(str: pLine, prefix: "newmtl ") != nullptr )
      {
        if ( sscanf(string: pLine, format: "newmtl %s", str) == 1 )
        {
          v6 = _V_strlen(str);
          if ( v6 > 2 )
          {
            v7 = &pLine[v6 + 4094];
            if ( _V_strcmp(s1: &pLine[v6 + 4094], s2: "SG") == 0 )
              *v7 = 0;
          }
          m_Size = this->m_mtlLib.m_Size;
          m_nAllocationCount = this->m_mtlLib.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ParticleChildrenInfo_t,int>::Grow(
              this: (CUtlMemory<vgui::RichText::TFormatStream,int> *)&this->m_mtlLib,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_mtlLib.m_Size;
          m_pMemory = this->m_mtlLib.m_Memory.m_pMemory;
          v10 = this->m_mtlLib.m_Size - m_Size - 1;
          this->m_mtlLib.m_pElements = m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v10);
          v11 = this->m_mtlLib.m_Memory.m_pMemory;
          v12 = m_Size;
          v5 = &v11[m_Size] == nullptr;
          p_m_MtlName = &v11[m_Size].m_MtlName;
          v21 = p_m_MtlName;
          if ( !v5 )
          {
            CUtlString::CUtlString(this: p_m_MtlName);
            CUtlString::CUtlString(this: v21 + 1);
          }
          CUtlString::operator=(this: &this->m_mtlLib.m_Memory.m_pMemory[v12].m_MtlName, src: str);
          CUtlString::operator=(this: &this->m_mtlLib.m_Memory.m_pMemory[v12].m_TgaName, src: "debugempty");
          this = v20;
        }
      }
      else if ( StringAfterPrefix(str: pLine, prefix: "map_Kd ") != nullptr
             && m_Size >= 0
             && sscanf(string: pLine, format: "map_Kd %s", pSrc) == 1 )
      {
        V_strncpy(pDest: pLine, pSrc, maxLen: 4096);
        V_FixSlashes(pname: pLine, separator: 47);
        v14 = _V_strstr(s1: pLine, search: "/materialsrc/");
        if ( v14 != nullptr )
        {
          v15 = _V_strlen(str: "/materialsrc/");
          V_StripExtension(in: &v14[v15], out, outSize: 1024);
        }
        else
        {
          V_FileBase(in: pSrc, out, maxlen: 1024);
        }
        CUtlString::operator=(this: &this->m_mtlLib.m_Memory.m_pMemory[m_Size].m_TgaName, src: out);
      }
      v3 = buf;
    }
    while ( buf->m_Error == 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D1A70
// Name: public: void CFaceSetData::AddToMesh(class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSetData::AddToMesh(CFaceSetData *this, CDmeMesh *pMesh)
{
  CFaceSetData *v2; // ebx
  const char *v3; // edi
  int m_Id; // esi
  int m_Size; // eax
  int v6; // eax
  int v7; // eax
  CDmeFaceSet *v8; // esi
  CDmeFaceSet *v9; // ebx
  int v10; // eax
  int v11; // eax
  CDmeMaterial *v12; // esi
  int nFaceSets; // [esp+Ch] [ebp-14h]
  CUtlVector<int,CUtlMemory<int,int> > *faceSetIndices; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  CUtlSymbol result; // [esp+1Ch] [ebp-4h] BYREF

  v2 = this;
  nFaceSets = this->m_faceSetIndices.m_SymbolTable.m_Lookup.m_NumElements;
  i = 0;
  if ( this->m_faceSetIndices.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v3 = CUtlSymbolTable::String(this: &v2->m_faceSetIndices.m_SymbolTable, id: (CUtlSymbol)i);
      CUtlSymbolTable::AddString(this: &v2->m_faceSetIndices.m_SymbolTable, &result, pString: v3);
      m_Id = result.m_Id;
      m_Size = v2->m_faceSetIndices.m_Vector.m_Size;
      if ( m_Size <= result.m_Id && m_Size < result.m_Id + 1 )
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
          this: &v2->m_faceSetIndices.m_Vector,
          elem: m_Size,
          num: result.m_Id + 1 - m_Size);
      faceSetIndices = &v2->m_faceSetIndices.m_Vector.m_Memory.m_pMemory[m_Id];
      if ( faceSetIndices->m_Size != 0 )
      {
        v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
               a1: g_pDataModel.u,
               a2: CDmeFaceSet::m_classType.u,
               a3: v3,
               a4: pMesh->m_fileId,
               a5: 0);
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: v6);
        v8 = (CDmeFaceSet *)v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeFaceSet::m_classType.u) != 0 )
        {
          v9 = v8;
        }
        else
        {
          v9 = nullptr;
        }
        v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                a1: g_pDataModel.u,
                a2: CDmeMaterial::m_classType.u,
                a3: v3,
                a4: pMesh->m_fileId,
                a5: 0);
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                a1: g_pDataModel.u,
                a2: v10);
        v12 = (CDmeMaterial *)v11;
        if ( v11 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: CDmeMaterial::m_classType.u) == 0 )
        {
          v12 = nullptr;
        }
        CDmeMaterial::SetMaterial(this: v12, pMaterialName: v3);
        CDmeFaceSet::AddIndices(this: v9, nCount: faceSetIndices->m_Size);
        CDmeFaceSet::SetIndices(
          this: v9,
          nFirstIndex: 0,
          nCount: faceSetIndices->m_Size,
          pIndices: faceSetIndices->m_Memory.m_pMemory);
        CDmeFaceSet::SetMaterial(this: v9, pMaterial: (int)v12);
        CDmeMesh::AddFaceSet(this: pMesh, faceSet: (int)v9);
        v2 = this;
      }
      ++i;
    }
    while ( i < nFaceSets );
  }
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: &v2->m_faceSetIndices.m_Vector);
  CUtlSymbolTable::RemoveAll(this: &v2->m_faceSetIndices.m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x005D1BF0
// Name: public: struct CDmObjSerializer::DeltaInfo_t __near & CUtlStringMap<struct CDmObjSerializer::DeltaInfo_t>::operator[](char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmObjSerializer::DeltaInfo_t *__thiscall CUtlStringMap<CDmObjSerializer::DeltaInfo_t>::operator[](
        CUtlStringMap<CDmObjSerializer::DeltaInfo_t> *this,
        const char *pString)
{
  int v3; // edi
  int m_Size; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  v3 = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString && m_Size < (unsigned __int16)pString + 1 )
    CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>::InsertMultipleBefore(
      this: &this->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pString + 1 - m_Size);
  return &this->m_Vector.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x005D1C40
// Name: private: class CDmElement __near * CDmObjSerializer::ReadOBJ(class CUtlBuffer __near &,enum DmFileId_t,char const __near *,char const __near *,class CDmeMesh __near *,class CDmeMesh __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmObjSerializer::ReadOBJ(
        CDmObjSerializer *this,
        CUtlBuffer *buf,
        DmElementHandle_t dmFileId,
        char *pName,
        char *pFilename,
        CDmeMesh *pBaseMesh,
        CDmeMesh **ppCreatedMesh,
        int bAbsolute)
{
  DmElementHandle_t v8; // ebx
  int v9; // eax
  int v10; // eax
  CDmElement *v11; // esi
  CDmElement *v12; // edi
  int (__thiscall *v13)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmElementHandle_t, _DWORD); // eax
  int v14; // eax
  int v15; // eax
  CDmeModel *v16; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v18; // eax
  CDmeMesh *v19; // edi
  CUtlMemory<vgui::TreeNode *,int> *v20; // esi
  char *i; // edi
  CDmeMesh *v22; // esi
  int m_Size; // eax
  int v24; // edi
  int v25; // eax
  Vector *v26; // eax
  int v27; // eax
  int v28; // edi
  int v29; // eax
  Vector *v30; // eax
  int v31; // eax
  char *v32; // esi
  const char *MtlEntry; // eax
  char v34; // al
  const char *v35; // edi
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // edi
  int v39; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v42; // ecx
  int v43; // eax
  int *v44; // eax
  vgui::TreeNode **v45; // edi
  int v46; // eax
  vgui::TreeNode **v47; // ecx
  int v48; // eax
  vgui::TreeNode **v49; // eax
  void *v50; // esi
  char pLine[4096]; // [esp+3Ch] [ebp-238Ch] BYREF
  char pString[4096]; // [esp+103Ch] [ebp-138Ch] BYREF
  char dest[260]; // [esp+203Ch] [ebp-38Ch] BYREF
  characterset_t pSetBuffer; // [esp+2140h] [ebp-288h] BYREF
  CUtlBuffer bufParse; // [esp+2240h] [ebp-188h] BYREF
  CUtlString v57; // [esp+2270h] [ebp-158h] BYREF
  CUtlBuffer bufa; // [esp+2280h] [ebp-148h] BYREF
  CFaceSetData v59; // [esp+22B0h] [ebp-118h] BYREF
  CVertexData v60; // [esp+22FCh] [ebp-CCh] BYREF
  Vector2D v; // [esp+2388h] [ebp-40h] BYREF
  int v62; // [esp+2390h] [ebp-38h] BYREF
  int n; // [esp+2394h] [ebp-34h] BYREF
  int t; // [esp+2398h] [ebp-30h] BYREF
  __int64 v65; // [esp+239Ch] [ebp-2Ch] BYREF
  float v66; // [esp+23A4h] [ebp-24h] BYREF
  CDmObjSerializer *v67; // [esp+23A8h] [ebp-20h]
  CUtlString v68; // [esp+23ACh] [ebp-1Ch] BYREF
  CDmElement *v69; // [esp+23BCh] [ebp-Ch]
  CDmeModel *v70; // [esp+23C0h] [ebp-8h]
  CDmeMesh *pMesh; // [esp+23C4h] [ebp-4h]

  v67 = this;
  v69 = nullptr;
  v70 = nullptr;
  if ( pBaseMesh == nullptr )
  {
    v8 = dmFileId;
    v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
           a1: g_pDataModel.u,
           a2: CDmElement::m_classType.u,
           a3: "root",
           a4: dmFileId,
           a5: 0);
    v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
            a1: g_pDataModel.u,
            a2: v9);
    v11 = (CDmElement *)v10;
    if ( v10 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
           a1: v10,
           a2: CDmElement::m_classType.u) != 0 )
    {
      v12 = v11;
    }
    else
    {
      v12 = nullptr;
    }
    v13 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64);
    v69 = v12;
    v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v13)(
            a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
            a2: (CUtlSymbolLarge::<unnamed_type_u>)CDmeModel::m_classType.u.m_Id,
            a3: "model",
            a4: v8,
            a5: 0);
    v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
            a1: g_pDataModel.u,
            a2: v14);
    v16 = (CDmeModel *)v15;
    if ( v15 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
           a1: v15,
           a2: CDmeModel::m_classType.u) == 0 )
    {
      v16 = nullptr;
    }
    v70 = v16;
    if ( v16 != nullptr )
      dmFileId = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v16);
    else
      dmFileId = DMELEMENT_HANDLE_INVALID;
    Attribute = CDmElement::FindAttribute(this: v12, pAttributeName: "skeleton");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v12, pAttributeName: "skeleton", type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &dmFileId);
    }
    if ( v16 != nullptr )
      dmFileId = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v16);
    else
      dmFileId = DMELEMENT_HANDLE_INVALID;
    v18 = CDmElement::FindAttribute(this: v12, pAttributeName: "model");
    if ( v18 != nullptr
      || (v18 = CDmElement::CreateAttribute(this: v12, pAttributeName: "model", type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: v18, value: &dmFileId);
    }
  }
  CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::RemoveAll(this: (CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int> > *)&v67->m_mtlLib);
  CharacterSetBuild(&pSetBuffer, pszSetString: "/\\");
  CVertexData::CVertexData(this: &v60);
  v59.m_faceSetIndices.m_Vector.m_Memory.m_pMemory = nullptr;
  v59.m_faceSetIndices.m_Vector.m_Memory.m_nAllocationCount = 0;
  v59.m_faceSetIndices.m_Vector.m_Memory.m_nGrowSize = 32;
  v59.m_faceSetIndices.m_Vector.m_Size = 0;
  v59.m_faceSetIndices.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &v59.m_faceSetIndices.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  CUtlString::CUtlString(this: &v68);
  v19 = nullptr;
  v20 = nullptr;
  dmFileId = 0;
  pMesh = nullptr;
  if ( buf->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( sscanf(string: pLine, format: "v %f %f %f", &v65, (char *)&v65 + 4, &v66) == 3 )
      {
        if ( dmFileId != 0 )
        {
          v22 = pMesh;
          CVertexData::Add(this: &v60, pMesh, pName: "bind");
          CFaceSetData::AddToMesh(this: &v59, pMesh: v22);
          dmFileId = 0;
          pMesh = nullptr;
          v20 = nullptr;
        }
        m_Size = v60.m_positions.m_Size;
        v24 = v60.m_positions.m_Size;
        if ( v60.m_positions.m_Size + 1 > v60.m_positions.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v60,
            num: v60.m_positions.m_Size - v60.m_positions.m_Memory.m_nAllocationCount + 1);
          m_Size = v60.m_positions.m_Size;
        }
        v60.m_positions.m_Size = m_Size + 1;
        v25 = m_Size - v24;
        v60.m_positions.m_pElements = v60.m_positions.m_Memory.m_pMemory;
        if ( v25 > 0 )
          _V_memmove(
            dest: &v60.m_positions.m_Memory.m_pMemory[v24 + 1],
            src: &v60.m_positions.m_Memory.m_pMemory[v24],
            count: 12 * v25);
        v26 = &v60.m_positions.m_Memory.m_pMemory[v24];
        if ( v26 != nullptr )
        {
          *(_QWORD *)&v26->x = v65;
          v26->z = v66;
        }
        goto LABEL_105;
      }
      if ( sscanf(string: i, format: "vn %f %f %f", &v65, (char *)&v65 + 4, &v66) == 3 )
      {
        v27 = v60.m_normals.m_Size;
        v28 = v60.m_normals.m_Size;
        if ( v60.m_normals.m_Size + 1 > v60.m_normals.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v60.m_normals,
            num: v60.m_normals.m_Size - v60.m_normals.m_Memory.m_nAllocationCount + 1);
          v27 = v60.m_normals.m_Size;
        }
        v60.m_normals.m_Size = v27 + 1;
        v29 = v27 - v28;
        v60.m_normals.m_pElements = v60.m_normals.m_Memory.m_pMemory;
        if ( v29 > 0 )
          _V_memmove(
            dest: &v60.m_normals.m_Memory.m_pMemory[v28 + 1],
            src: &v60.m_normals.m_Memory.m_pMemory[v28],
            count: 12 * v29);
        v30 = &v60.m_normals.m_Memory.m_pMemory[v28];
        if ( v30 != nullptr )
        {
          *(_QWORD *)&v30->x = v65;
          v30->z = v66;
        }
        goto LABEL_105;
      }
      if ( pBaseMesh == nullptr )
      {
        if ( sscanf(string: i, format: "vt %f %f", &v, &v.y) == 2 )
        {
          CVertexData::AddUniqueValue<Vector2D>(
            this: &v60,
            &v,
            vs: &v60.m_uvs,
            map: &v60.m_uvIndexMap,
            flThresh: 0.000000011920929);
        }
        else
        {
          if ( pFilename != nullptr && sscanf(string: i, format: "mtllib %4096s", pString) == 1 )
          {
            CUtlString::CUtlString(this: &v57, pString);
            V_strncpy(pDest: pLine, pSrc: pFilename, maxLen: 4096);
            V_FixSlashes(pname: pLine, separator: 92);
            V_StripFilename(path: pLine);
            V_ComposeFileName(path: pLine, filename: pString, dest, destSize: 260);
            CUtlBuffer::CUtlBuffer(this: &bufa, growSize: 0, initSize: 0, nFlags: 0);
            if ( g_pFullFileSystem->ReadFile(
                   this: &g_pFullFileSystem->IBaseFileSystem,
                   a2: dest,
                   a3: nullptr,
                   a4: &bufa,
                   a5: 0,
                   a6: 0,
                   a7: nullptr) )
            {
              CDmObjSerializer::ParseMtlLib(this: v67, buf: &bufa);
            }
            if ( bufa.m_Memory.m_nGrowSize >= 0 )
            {
              if ( bufa.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufa.m_Memory.m_pMemory);
                bufa.m_Memory.m_pMemory = nullptr;
              }
              bufa.m_Memory.m_nAllocationCount = 0;
            }
            CUtlString::~CUtlString(this: &v57);
            goto LABEL_105;
          }
          if ( sscanf(string: i, format: "usemtl %4096s", pString) == 1 )
          {
            v31 = _V_strlen(str: pString);
            if ( v31 != 0 )
            {
              v32 = &pLine[v31 + 4094];
              if ( _V_strcmp(s1: &pLine[v31 + 4094], s2: "SG") == 0 )
                *v32 = 0;
            }
            MtlEntry = CDmObjSerializer::FindMtlEntry(this: v67, pTgaName: pString);
            if ( MtlEntry == nullptr )
              goto LABEL_62;
            v20 = (CUtlMemory<vgui::TreeNode *,int> *)CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int>>>::operator[](
                                                        this: &v59,
                                                        pFaceSetName: MtlEntry);
          }
          else
          {
            if ( sscanf(string: i, format: "g %4096s", pString) != 1 )
            {
              if ( *i == 102 )
              {
                v34 = i[1];
                v35 = i + 1;
                if ( v34 == 32 || v34 == 9 )
                {
                  if ( dmFileId == 0 )
                  {
                    v36 = pName;
                    if ( pName == nullptr )
                    {
                      if ( CUtlString::Length(this: &v68) != 0 )
                        v36 = CUtlString::Get(this: &v68);
                      else
                        v36 = "obj";
                    }
                    dmFileId = (DmElementHandle_t)CreateElement<CDmeDag>(
                                                    pObjectName: v36,
                                                    fileid: v69->m_fileId,
                                                    pObjectID: nullptr);
                    if ( pName != nullptr )
                    {
                      v37 = pName;
                    }
                    else if ( CUtlString::Length(this: &v68) != 0 )
                    {
                      v37 = CUtlString::Get(this: &v68);
                    }
                    else
                    {
                      v37 = "obj";
                    }
                    pMesh = CreateElement<CDmeMesh>(pObjectName: v37, fileid: v69->m_fileId, pObjectID: nullptr);
                    if ( ppCreatedMesh != nullptr && *ppCreatedMesh == nullptr )
                      *ppCreatedMesh = pMesh;
                    CDmeDag::SetShape(this: (CDmeDag *)dmFileId, pShape: (int)pMesh);
                    if ( v70 != nullptr )
                    {
                      CDmeModel::AddJoint(this: v70, pJoint: dmFileId);
                      CDmeDag::AddChild(this: v70, pDag: (CDmeDag *)dmFileId);
                    }
                  }
                  if ( v20 == nullptr )
                    v20 = (CUtlMemory<vgui::TreeNode *,int> *)CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int>>>::operator[](
                                                                this: &v59,
                                                                pFaceSetName: "facetSet");
                  v38 = CDmObjSerializer::SkipSpace(pBuf: v35);
                  v39 = _V_strlen(str: v38);
                  CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: v38, nSize: v39, nFlags: 9);
                  while ( bufParse.m_Error == 0 )
                  {
                    if ( CDmObjSerializer::ParseVertex(&bufParse, breakSet: &pSetBuffer, v: &v62, &t, &n) == 0 )
                      break;
                    m_pMemory = v20[1].m_pMemory;
                    m_nAllocationCount = v20->m_nAllocationCount;
                    if ( (int)m_pMemory + 1 > m_nAllocationCount )
                      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v20, num: (int)m_pMemory - m_nAllocationCount + 1);
                    ++v20[1].m_pMemory;
                    v42 = v20->m_pMemory;
                    v43 = (char *)v20[1].m_pMemory - (char *)m_pMemory - 1;
                    v20[1].m_nAllocationCount = (int)v20->m_pMemory;
                    if ( v43 > 0 )
                      _V_memmove(dest: &v42[(_DWORD)m_pMemory + 1], src: &v42[(_DWORD)m_pMemory], count: 4 * v43);
                    v44 = (int *)&v20->m_pMemory[(_DWORD)m_pMemory];
                    if ( v44 != nullptr )
                      *v44 = v60.m_pIndices.m_Size;
                    if ( v62 > 0 )
                      CVertexData::AddPositionIndex(this: &v60, i: (vgui::TreeNode *)(v62 - 1));
                    if ( n > 0 )
                      CVertexData::AddNormalIndex(this: &v60, i: (vgui::TreeNode *)(n - 1));
                    if ( t > 0 )
                      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
                        this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&v60.m_uvIndices,
                        elem: v60.m_uvIndices.m_Size,
                        src: (vgui::PageTab **)&v60.m_uvIndexMap.m_Memory.m_pMemory[t - 1]);
                  }
                  v45 = v20[1].m_pMemory;
                  v46 = v20->m_nAllocationCount;
                  if ( (int)v45 + 1 > v46 )
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v20, num: (int)v45 - v46 + 1);
                  ++v20[1].m_pMemory;
                  v47 = v20->m_pMemory;
                  v48 = (char *)v20[1].m_pMemory - (char *)v45 - 1;
                  v20[1].m_nAllocationCount = (int)v20->m_pMemory;
                  if ( v48 > 0 )
                    _V_memmove(dest: &v47[(_DWORD)v45 + 1], src: &v47[(_DWORD)v45], count: 4 * v48);
                  v49 = &v20->m_pMemory[(_DWORD)v45];
                  if ( v49 != nullptr )
                    *v49 = (vgui::TreeNode *)-1;
                  CUtlBuffer::~CUtlBuffer(this: &bufParse);
                }
              }
              goto LABEL_105;
            }
            CUtlString::operator=(this: &v68, src: pString);
            if ( v20 == nullptr )
LABEL_62:
              v20 = (CUtlMemory<vgui::TreeNode *,int> *)CUtlStringMap<CUtlVector<CDmePanel::EditorPanelMap_t,CUtlMemory<CDmePanel::EditorPanelMap_t,int>>>::operator[](
                                                          this: &v59,
                                                          pFaceSetName: pString);
          }
        }
      }
LABEL_105:
      if ( buf->m_Error != 0 )
      {
        v19 = pMesh;
        break;
      }
    }
  }
  if ( pBaseMesh != nullptr )
  {
    v50 = CVertexData::AddDelta(this: &v60, pMesh: pBaseMesh, bAbsolute, (int)pName);
  }
  else
  {
    v50 = CVertexData::Add(this: &v60, pMesh: v19, pName: "bind");
    CFaceSetData::AddToMesh(this: &v59, pMesh: v19);
  }
  if ( v70 != nullptr )
    CDmeModel::CaptureJointsToBaseState(this: v70, pBaseStateName: "bind");
  v68.m_Storage.m_nActualLength = 0;
  if ( pBaseMesh != nullptr )
  {
    if ( v68.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v68.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v68.m_Storage.m_Memory.m_pMemory);
        v68.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v68.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    CUtlSymbolTable::~CUtlSymbolTable(this: &v59.m_faceSetIndices.m_SymbolTable);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &v59.m_faceSetIndices.m_Vector);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_uvIndices);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_uvIndexMap);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_uvs);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_nIndices);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_normals);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_pIndices);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60);
    return (CDmElement *)v50;
  }
  else
  {
    if ( v68.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v68.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v68.m_Storage.m_Memory.m_pMemory);
        v68.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v68.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    CUtlSymbolTable::~CUtlSymbolTable(this: &v59.m_faceSetIndices.m_SymbolTable);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &v59.m_faceSetIndices.m_Vector);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_uvIndices);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_uvIndexMap);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_uvs);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_nIndices);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_normals);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60.m_pIndices);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v60);
    return v69;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D2590
// Name: public: void CDmObjSerializer::MeshToObj(class CUtlBuffer __near &,struct matrix3x4_t const __near &,class CDmeMesh __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmObjSerializer::MeshToObj(
        CDmObjSerializer *this,
        CUtlBuffer *b,
        const matrix3x4_t *parentWorldMatrix,
        CDmeMesh *pMesh,
        const char *pDeltaName,
        const int *absolute)
{
  CDmeVertexData *BaseState; // eax
  int v7; // edi
  const CUtlVector<int,CUtlMemory<int,int> > *m_Id; // eax
  CDmeVertexDeltaData *DeltaState; // edi
  const char *m_pAsString; // eax
  const CUtlVector<int,CUtlMemory<int,int> > *v12; // eax
  int v13; // edi
  const CUtlVector<int,CUtlMemory<int,int> > *v14; // eax
  CDmeVertexDeltaData *v15; // edi
  const char *v16; // eax
  int v17; // eax
  CDmeVertexDataBase *v18; // edi
  int v19; // eax
  int v20; // eax
  CDmeVertexDeltaData *v21; // edi
  const char *v22; // eax
  int v23; // edi
  CDmeVertexDeltaData *v24; // edi
  const char *v25; // eax
  CDmeFaceSet *FaceSet; // edi
  CDmeMaterial *Material; // ebx
  const char *MaterialName; // eax
  const int *m_pMemory; // ebx
  const int *v30; // edi
  const char *v31; // eax
  int v32; // ecx
  int v33; // ecx
  int *v34; // edi
  int v35; // ebx
  int m_Put; // eax
  CDmObjSerializer *v37; // edi
  int v38; // ebx
  int v39; // eax
  int v40; // ebx
  int v41; // ecx
  int v42; // ecx
  int *v43; // edi
  int v44; // ebx
  int v45; // eax
  char *v46; // edi
  int v47; // eax
  int v48; // ecx
  int v49; // ecx
  int *v50; // edi
  int v51; // ebx
  char *v52; // edi
  int v53; // ecx
  int v54; // edi
  CDmObjSerializer *v55; // eax
  int v56; // edx
  CDmeMesh::DeltaComputation_t *v57; // eax
  Vector *weight; // [esp+0h] [ebp-B8h]
  const QAngle *weighta; // [esp+0h] [ebp-B8h]
  int m_Size; // [esp+4h] [ebp-B4h]
  int v61; // [esp+4h] [ebp-B4h]
  matrix3x4_t normalMatrix; // [esp+14h] [ebp-A4h] BYREF
  CDmrArrayConst<Vector> nArray; // [esp+44h] [ebp-74h] BYREF
  CDmrArrayConst<Vector2D> uvArray; // [esp+4Ch] [ebp-6Ch] BYREF
  int nFaceSets; // [esp+54h] [ebp-64h]
  CDmrArrayConst<Vector> pArray; // [esp+58h] [ebp-60h] BYREF
  int nTextureCount; // [esp+60h] [ebp-58h]
  CUtlVector<CDmeMesh::DeltaComputation_t,CUtlMemory<CDmeMesh::DeltaComputation_t,int> > compList; // [esp+64h] [ebp-54h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *depDeltas; // [esp+78h] [ebp-40h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > nData; // [esp+7Ch] [ebp-3Ch] BYREF
  int nDepDeltas; // [esp+90h] [ebp-28h]
  int i; // [esp+94h] [ebp-24h]
  CDmObjSerializer *v73; // [esp+98h] [ebp-20h]
  int nCompList; // [esp+9Ch] [ebp-1Ch]
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *uvData; // [esp+A0h] [ebp-18h]
  int inputBuffer; // [esp+A4h] [ebp-14h] BYREF
  CDmeVertexDeltaData *pTmpDeltaState; // [esp+A8h] [ebp-10h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *puvIndices; // [esp+ACh] [ebp-Ch]
  const CUtlVector<int,CUtlMemory<int,int> > *pnIndices; // [esp+B0h] [ebp-8h]
  int uvIndex; // [esp+B4h] [ebp-4h]
  CDmAttribute *ppIndicesa; // [esp+C0h] [ebp+8h]
  const CUtlVector<int,CUtlMemory<int,int> > *ppIndices; // [esp+C0h] [ebp+8h]
  CDmAttribute *nConstDatae; // [esp+C4h] [ebp+Ch]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *nConstData; // [esp+C4h] [ebp+Ch]
  const char *nConstDataa; // [esp+C4h] [ebp+Ch]
  const char *nConstDatab; // [esp+C4h] [ebp+Ch]
  const char *nConstDatac; // [esp+C4h] [ebp+Ch]
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *nConstDatad; // [esp+C4h] [ebp+Ch]
  const int *pEnd; // [esp+CCh] [ebp+14h]

  v73 = this;
  memset(&compList, 0, sizeof(compList));
  if ( pDeltaName != nullptr )
    CDmeMesh::ComputeDependentDeltaStateList(this: pMesh, &compList);
  nCompList = compList.m_Size;
  BaseState = CDmeMesh::FindBaseState(this: pMesh, pStateName: "bind");
  i = (int)BaseState;
  if ( BaseState != nullptr && (v7 = BaseState->m_pStandardFieldIndex[0]) >= 0 )
  {
    m_Id = (const CUtlVector<int,CUtlMemory<int,int> > *)pMesh->m_Name.m_Storage.u.CDmeShape::CDmElement::m_Id;
    nTextureCount = 0;
    nDepDeltas = 0;
    pnIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)defaultValue;
    if ( m_Id != (const CUtlVector<int,CUtlMemory<int,int> > *)-1 )
      pnIndices = m_Id;
    CUtlBuffer::PutString(this: b, pString: "g ");
    CUtlBuffer::PutString(this: b, pString: (const char *)pnIndices);
    CUtlBuffer::PutString(this: b, pString: "\n");
    ppIndicesa = *(CDmAttribute **)(*(_DWORD *)(i + 108) + 48 * v7 + 16);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&pArray);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: &pArray,
      pAttribute: ppIndicesa);
    ppIndices = CDmeVertexDataBase::GetVertexIndexData(this: (CDmeVertexDataBase *)i, nFieldIndex: v7);
    if ( nCompList != 0 )
    {
      m_Size = pArray.m_pStorage->m_Size;
      weight = pArray.m_pStorage->m_Memory.m_pMemory;
      memset(&nData, 0, sizeof(nData));
      CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&nData,
        pArray: (const QAngle *)weight,
        size: m_Size);
      if ( (_BYTE)absolute != 0 )
      {
        if ( nCompList > 0 )
        {
          puvIndices = nullptr;
          for ( uvIndex = nCompList; uvIndex != 0; --uvIndex )
          {
            DeltaState = CDmeMesh::GetDeltaState(
                           this: pMesh,
                           nDeltaIndex: *(int *)((char *)&puvIndices->m_Memory.m_pMemory + (unsigned int)compList.m_Memory.m_pMemory));
            m_pAsString = DeltaState->m_Name.m_Storage.u.m_pAsString;
            if ( m_pAsString == (const char *)-1 )
              m_pAsString = defaultValue;
            if ( _V_strcmp(s1: m_pAsString, s2: pDeltaName) == 0 )
            {
              v12 = (const CUtlVector<int,CUtlMemory<int,int> > *)DeltaState->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
              pnIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)defaultValue;
              if ( v12 != (const CUtlVector<int,CUtlMemory<int,int> > *)-1 )
                pnIndices = v12;
              CUtlBuffer::PutString(this: b, pString: "# Delta: ");
              CUtlBuffer::PutString(this: b, pString: (const char *)pnIndices);
              CUtlBuffer::PutString(this: b, pString: "\n");
              CDmeMesh::AddDelta<Vector>(
                this: pMesh,
                pDelta: DeltaState,
                pFullData: nData.m_Memory.m_pMemory,
                nFullData: nData.m_Size,
                standardField: FIELD_POSITION,
                weight: 1.0,
                pMask: nullptr);
              depDeltas = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)&puvIndices->m_Memory.m_nGrowSize
                                                                       + (unsigned int)compList.m_Memory.m_pMemory);
              v13 = 0;
              uvData = *(const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > **)((char *)&puvIndices[1].m_Memory.m_pMemory
                                                                                + (unsigned int)compList.m_Memory.m_pMemory);
              if ( (int)uvData > 0 )
              {
                do
                {
                  pTmpDeltaState = CDmeMesh::GetDeltaState(this: pMesh, nDeltaIndex: depDeltas->m_Memory.m_pMemory[v13]);
                  v14 = (const CUtlVector<int,CUtlMemory<int,int> > *)pTmpDeltaState->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
                  pnIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)defaultValue;
                  if ( v14 != (const CUtlVector<int,CUtlMemory<int,int> > *)-1 )
                    pnIndices = v14;
                  CUtlBuffer::PutString(this: b, pString: "# Dependent Delta: ");
                  CUtlBuffer::PutString(this: b, pString: (const char *)pnIndices);
                  CUtlBuffer::PutString(this: b, pString: "\n");
                  CDmeMesh::AddDelta<Vector>(
                    this: pMesh,
                    pDelta: pTmpDeltaState,
                    pFullData: nData.m_Memory.m_pMemory,
                    nFullData: nData.m_Size,
                    standardField: FIELD_POSITION,
                    weight: 1.0,
                    pMask: nullptr);
                  ++v13;
                }
                while ( v13 < (int)uvData );
              }
            }
            puvIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)puvIndices + 28);
          }
        }
      }
      else if ( nCompList > 0 )
      {
        pnIndices = nullptr;
        for ( puvIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)nCompList;
              puvIndices != nullptr;
              puvIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)puvIndices - 1) )
        {
          v15 = CDmeMesh::GetDeltaState(
                  this: pMesh,
                  nDeltaIndex: *(int *)((char *)&pnIndices->m_Memory.m_pMemory + (unsigned int)compList.m_Memory.m_pMemory));
          v16 = v15->m_Name.m_Storage.u.m_pAsString;
          if ( v16 == (const char *)-1 )
            v16 = defaultValue;
          if ( _V_strcmp(s1: v16, s2: pDeltaName) == 0 )
          {
            v17 = v15->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
            uvIndex = (int)defaultValue;
            if ( v17 != -1 )
              uvIndex = v17;
            CUtlBuffer::PutString(this: b, pString: "# Delta: ");
            CUtlBuffer::PutString(this: b, pString: (const char *)uvIndex);
            CUtlBuffer::PutString(this: b, pString: "\n");
            CDmeMesh::AddDelta<Vector>(
              this: pMesh,
              pDelta: v15,
              pFullData: nData.m_Memory.m_pMemory,
              nFullData: nData.m_Size,
              standardField: FIELD_POSITION,
              weight: 1.0,
              pMask: nullptr);
          }
          pnIndices = (const CUtlVector<int,CUtlMemory<int,int> > *)((char *)pnIndices + 28);
        }
      }
      depDeltas = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmObjSerializer::OutputVectors(
                                                                  b,
                                                                  pPrefix: "v ",
                                                                  vData: &nData,
                                                                  matrix: parentWorldMatrix);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&nData);
    }
    else
    {
      depDeltas = (const CUtlVector<int,CUtlMemory<int,int> > *)CDmObjSerializer::OutputVectors(
                                                                  b,
                                                                  pPrefix: "v ",
                                                                  vData: pArray.m_pStorage,
                                                                  matrix: parentWorldMatrix);
    }
    v18 = (CDmeVertexDataBase *)i;
    v19 = *(_DWORD *)(i + 140);
    puvIndices = nullptr;
    uvIndex = v19;
    if ( v19 >= 0 )
    {
      uvData = *(const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > **)(*(_DWORD *)(i + 108) + 48 * v19 + 16);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&uvArray);
      CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
        this: &uvArray,
        pAttribute: (CDmAttribute *)uvData);
      uvData = uvArray.m_pStorage;
      puvIndices = CDmeVertexDataBase::GetVertexIndexData(this: v18, nFieldIndex: uvIndex);
      nTextureCount = CDmObjSerializer::OutputVectors(b, pPrefix: "vt ", vData: uvData);
    }
    v20 = v18->m_pStandardFieldIndex[1];
    pnIndices = nullptr;
    uvIndex = v20;
    if ( v20 >= 0 )
    {
      MatrixInverseTranspose(src: parentWorldMatrix, dst: &normalMatrix);
      nConstDatae = v18->m_FieldInfo.m_Memory.m_pMemory[uvIndex].m_pVertexData;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&nArray);
      CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
        this: &nArray,
        pAttribute: nConstDatae);
      nConstData = nArray.m_pStorage;
      pnIndices = CDmeVertexDataBase::GetVertexIndexData(this: v18, nFieldIndex: uvIndex);
      if ( nCompList != 0 )
      {
        v61 = nConstData->m_Size;
        weighta = (const QAngle *)nConstData->m_Memory.m_pMemory;
        memset(&nData, 0, sizeof(nData));
        CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&nData,
          pArray: weighta,
          size: v61);
        if ( (_BYTE)absolute != 0 )
        {
          if ( nCompList > 0 )
          {
            absolute = nullptr;
            for ( uvIndex = nCompList; uvIndex != 0; --uvIndex )
            {
              v21 = CDmeMesh::GetDeltaState(
                      this: pMesh,
                      nDeltaIndex: *(const int *)((char *)absolute + (unsigned int)compList.m_Memory.m_pMemory));
              v22 = v21->m_Name.m_Storage.u.m_pAsString;
              if ( v22 == (const char *)-1 )
                v22 = defaultValue;
              if ( _V_strcmp(s1: v22, s2: pDeltaName) == 0 )
              {
                nConstDataa = defaultValue;
                if ( v21->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
                  nConstDataa = v21->m_Name.m_Storage.u.m_pAsString;
                CUtlBuffer::PutString(this: b, pString: "# Delta: ");
                CUtlBuffer::PutString(this: b, pString: nConstDataa);
                CUtlBuffer::PutString(this: b, pString: "\n");
                CDmeMesh::AddDelta<Vector>(
                  this: pMesh,
                  pDelta: v21,
                  pFullData: nData.m_Memory.m_pMemory,
                  nFullData: nData.m_Size,
                  standardField: FIELD_NORMAL,
                  weight: 1.0,
                  pMask: nullptr);
                uvData = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)((char *)absolute
                                                                                + (unsigned int)compList.m_Memory.m_pMemory
                                                                                + 8);
                v23 = 0;
                nDepDeltas = *(const int *)((char *)absolute + (unsigned int)compList.m_Memory.m_pMemory + 20);
                if ( nDepDeltas > 0 )
                {
                  do
                  {
                    pTmpDeltaState = CDmeMesh::GetDeltaState(
                                       this: pMesh,
                                       nDeltaIndex: *((_DWORD *)&uvData->m_Memory.m_pMemory->x + v23));
                    nConstDatab = defaultValue;
                    if ( pTmpDeltaState->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
                      nConstDatab = pTmpDeltaState->m_Name.m_Storage.u.m_pAsString;
                    CUtlBuffer::PutString(this: b, pString: "# Dependent Delta: ");
                    CUtlBuffer::PutString(this: b, pString: nConstDatab);
                    CUtlBuffer::PutString(this: b, pString: "\n");
                    CDmeMesh::AddDelta<Vector>(
                      this: pMesh,
                      pDelta: pTmpDeltaState,
                      pFullData: nData.m_Memory.m_pMemory,
                      nFullData: nData.m_Size,
                      standardField: FIELD_NORMAL,
                      weight: 1.0,
                      pMask: nullptr);
                    ++v23;
                  }
                  while ( v23 < nDepDeltas );
                }
              }
              absolute += 7;
            }
          }
        }
        else if ( nCompList > 0 )
        {
          absolute = nullptr;
          for ( uvIndex = nCompList; uvIndex != 0; --uvIndex )
          {
            v24 = CDmeMesh::GetDeltaState(
                    this: pMesh,
                    nDeltaIndex: *(const int *)((char *)absolute + (unsigned int)compList.m_Memory.m_pMemory));
            v25 = v24->m_Name.m_Storage.u.m_pAsString;
            if ( v25 == (const char *)-1 )
              v25 = defaultValue;
            if ( _V_strcmp(s1: v25, s2: pDeltaName) == 0 )
            {
              nConstDatac = defaultValue;
              if ( v24->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
                nConstDatac = v24->m_Name.m_Storage.u.m_pAsString;
              CUtlBuffer::PutString(this: b, pString: "# Delta: ");
              CUtlBuffer::PutString(this: b, pString: nConstDatac);
              CUtlBuffer::PutString(this: b, pString: "\n");
              CDmeMesh::AddDelta<Vector>(
                this: pMesh,
                pDelta: v24,
                pFullData: nData.m_Memory.m_pMemory,
                nFullData: nData.m_Size,
                standardField: FIELD_NORMAL,
                weight: 1.0,
                pMask: nullptr);
            }
            absolute += 7;
          }
        }
        nDepDeltas = CDmObjSerializer::OutputVectors(b, pPrefix: "vn ", vData: &nData, matrix: &normalMatrix);
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&nData);
      }
      else
      {
        nDepDeltas = CDmObjSerializer::OutputVectors(b, pPrefix: "vn ", vData: nConstData, matrix: &normalMatrix);
      }
    }
    uvData = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)ppIndices->m_Size;
    if ( puvIndices != nullptr )
      uvIndex = puvIndices->m_Size;
    else
      uvIndex = 0;
    if ( pnIndices != nullptr )
      nConstDatad = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)pnIndices->m_Size;
    else
      nConstDatad = nullptr;
    nFaceSets = CDmeMesh::FaceSetCount(this: pMesh);
    for ( i = 0; i < nFaceSets; ++i )
    {
      FaceSet = CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: i);
      Material = CDmeFaceSet::GetMaterial(this: FaceSet);
      if ( Material != nullptr )
      {
        CUtlBuffer::PutString(this: b, pString: "usemtl ");
        MaterialName = CDmeMaterial::GetMaterialName(this: Material);
        CUtlBuffer::PutString(this: b, pString: MaterialName);
        CUtlBuffer::PutString(this: b, pString: "\n");
      }
      m_pMemory = FaceSet->m_indices.m_Storage.m_Memory.m_pMemory;
      v30 = &m_pMemory[FaceSet->m_indices.m_Storage.m_Size];
      pEnd = v30;
      v31 = "f ";
      if ( uvData == (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)uvIndex )
      {
        if ( uvData == nConstDatad )
        {
          while ( m_pMemory < v30 )
          {
            v32 = *m_pMemory++;
            absolute = m_pMemory;
            if ( v32 >= 0 )
            {
              v33 = v32;
              inputBuffer = (int)&pnIndices->m_Memory.m_pMemory[v33];
              nCompList = (int)&puvIndices->m_Memory.m_pMemory[v33];
              v34 = &ppIndices->m_Memory.m_pMemory[v33];
              CUtlBuffer::PutString(this: b, pString: v31);
              v35 = *v34 + v73->m_nPositionOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", *v34 + v73->m_nPositionOffset);
              }
              else
              {
                pTmpDeltaState = (CDmeVertexDeltaData *)(*v34 + v73->m_nPositionOffset);
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      inputBuffer: (int *)&pTmpDeltaState,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v35;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              if ( (b->m_Flags & 1) != 0 )
              {
                m_Put = b->m_Put;
                if ( m_Put != 0 && b->m_Memory.m_pMemory[m_Put - b->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: b);
              }
              if ( CUtlBuffer::CheckPut(this: b, nSize: 1) )
              {
                b->m_Memory.m_pMemory[b->m_Put++ - b->m_nOffset] = 47;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
              v37 = v73;
              v38 = *(_DWORD *)nCompList + v73->m_nTextureOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", *(_DWORD *)nCompList + v73->m_nTextureOffset);
              }
              else
              {
                pTmpDeltaState = (CDmeVertexDeltaData *)(*(_DWORD *)nCompList + v73->m_nTextureOffset);
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      inputBuffer: (int *)&pTmpDeltaState,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v38;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              if ( (b->m_Flags & 1) != 0 )
              {
                v39 = b->m_Put;
                if ( v39 != 0 && b->m_Memory.m_pMemory[v39 - b->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: b);
              }
              if ( CUtlBuffer::CheckPut(this: b, nSize: 1) )
              {
                b->m_Memory.m_pMemory[b->m_Put++ - b->m_nOffset] = 47;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
              v40 = *(_DWORD *)inputBuffer + v37->m_nNormalOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", *(_DWORD *)inputBuffer + v37->m_nNormalOffset);
              }
              else
              {
                inputBuffer = *(_DWORD *)inputBuffer + v37->m_nNormalOffset;
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      &inputBuffer,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v40;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              m_pMemory = absolute;
              v30 = pEnd;
              v31 = " ";
            }
            else
            {
              CUtlBuffer::PutString(this: b, pString: "\n");
              v31 = "f ";
            }
          }
        }
        else
        {
          while ( m_pMemory < v30 )
          {
            v41 = *m_pMemory++;
            absolute = m_pMemory;
            if ( v41 >= 0 )
            {
              v42 = v41;
              pTmpDeltaState = (CDmeVertexDeltaData *)&puvIndices->m_Memory.m_pMemory[v42];
              v43 = &ppIndices->m_Memory.m_pMemory[v42];
              CUtlBuffer::PutString(this: b, pString: v31);
              v44 = *v43 + v73->m_nPositionOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", *v43 + v73->m_nPositionOffset);
              }
              else
              {
                inputBuffer = *v43 + v73->m_nPositionOffset;
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      &inputBuffer,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v44;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              if ( (b->m_Flags & 1) != 0 )
              {
                v45 = b->m_Put;
                if ( v45 != 0 && b->m_Memory.m_pMemory[v45 - b->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: b);
              }
              if ( CUtlBuffer::CheckPut(this: b, nSize: 1) )
              {
                b->m_Memory.m_pMemory[b->m_Put++ - b->m_nOffset] = 47;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
              v46 = (char *)pTmpDeltaState->__vftable + v73->m_nTextureOffset;
              if ( (b->m_Flags & 1) != 0 )
              {
                CUtlBuffer::Printf(this: b, pFmt: "%d", (char *)pTmpDeltaState->__vftable + v73->m_nTextureOffset);
              }
              else
              {
                inputBuffer = (int)pTmpDeltaState->__vftable + v73->m_nTextureOffset;
                if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
                {
                  if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                    CByteswap::SwapBufferToTargetEndian<int>(
                      this: &b->m_Byteswap,
                      outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                      &inputBuffer,
                      count: 1);
                  else
                    *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v46;
                  b->m_Put += 4;
                  CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
                }
              }
              if ( (b->m_Flags & 1) != 0 )
              {
                v47 = b->m_Put;
                if ( v47 != 0 && b->m_Memory.m_pMemory[v47 - b->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: b);
              }
              if ( CUtlBuffer::CheckPut(this: b, nSize: 1) )
              {
                b->m_Memory.m_pMemory[b->m_Put++ - b->m_nOffset] = 47;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
              m_pMemory = absolute;
              v30 = pEnd;
              v31 = " ";
            }
            else
            {
              CUtlBuffer::PutString(this: b, pString: "\n");
              v31 = "f ";
            }
          }
        }
      }
      else if ( uvData == nConstDatad )
      {
        while ( m_pMemory < v30 )
        {
          v48 = *m_pMemory++;
          absolute = m_pMemory;
          if ( v48 >= 0 )
          {
            v49 = v48;
            pTmpDeltaState = (CDmeVertexDeltaData *)&pnIndices->m_Memory.m_pMemory[v49];
            v50 = &ppIndices->m_Memory.m_pMemory[v49];
            CUtlBuffer::PutString(this: b, pString: v31);
            v51 = *v50 + v73->m_nPositionOffset;
            if ( (b->m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: b, pFmt: "%d", *v50 + v73->m_nPositionOffset);
            }
            else
            {
              inputBuffer = *v50 + v73->m_nPositionOffset;
              if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
              {
                if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                  CByteswap::SwapBufferToTargetEndian<int>(
                    this: &b->m_Byteswap,
                    outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                    &inputBuffer,
                    count: 1);
                else
                  *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v51;
                b->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
            }
            CUtlBuffer::PutString(this: b, pString: "//");
            v52 = (char *)pTmpDeltaState->__vftable + v73->m_nNormalOffset;
            if ( (b->m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: b, pFmt: "%d", (char *)pTmpDeltaState->__vftable + v73->m_nNormalOffset);
            }
            else
            {
              inputBuffer = (int)pTmpDeltaState->__vftable + v73->m_nNormalOffset;
              if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
              {
                if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                  CByteswap::SwapBufferToTargetEndian<int>(
                    this: &b->m_Byteswap,
                    outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                    &inputBuffer,
                    count: 1);
                else
                  *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v52;
                b->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
            }
            m_pMemory = absolute;
            v30 = pEnd;
            v31 = " ";
          }
          else
          {
            CUtlBuffer::PutString(this: b, pString: "\n");
            v31 = "f ";
          }
        }
      }
      else
      {
        while ( m_pMemory < v30 )
        {
          v53 = *m_pMemory++;
          if ( v53 >= 0 )
          {
            absolute = &ppIndices->m_Memory.m_pMemory[v53];
            CUtlBuffer::PutString(this: b, pString: v31);
            v54 = *absolute + v73->m_nPositionOffset;
            if ( (b->m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: b, pFmt: "%d", *absolute + v73->m_nPositionOffset);
            }
            else
            {
              absolute = (const int *)(*absolute + v73->m_nPositionOffset);
              if ( CUtlBuffer::CheckPut(this: b, nSize: 4) )
              {
                if ( (*(_BYTE *)&b->m_Byteswap & 1) != 0 )
                  CByteswap::SwapBufferToTargetEndian<int>(
                    this: &b->m_Byteswap,
                    outputBuffer: (int *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset],
                    inputBuffer: (int *)&absolute,
                    count: 1);
                else
                  *(_DWORD *)&b->m_Memory.m_pMemory[b->m_Put - b->m_nOffset] = v54;
                b->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: b, nPut: b->m_Put);
              }
            }
            CUtlBuffer::PutString(this: b, pString: "//");
            v30 = pEnd;
            v31 = " ";
          }
          else
          {
            CUtlBuffer::PutString(this: b, pString: "\n");
            v31 = "f ";
          }
        }
      }
    }
    v55 = v73;
    v73->m_nPositionOffset += (int)depDeltas;
    v56 = nTextureCount;
    v55->m_nNormalOffset += nDepDeltas;
    v55->m_nTextureOffset += v56;
    CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this: (CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *)&compList);
    v57 = compList.m_Memory.m_pMemory;
    if ( compList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( compList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: compList.m_Memory.m_pMemory);
        v57 = nullptr;
        compList.m_Memory.m_pMemory = nullptr;
      }
      compList.m_Memory.m_nAllocationCount = 0;
    }
    compList.m_pElements = v57;
    if ( compList.m_Memory.m_nGrowSize >= 0 && v57 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
  }
  else
  {
    CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(this: (CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *)&compList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D33B0
// Name: private: void CDmObjSerializer::DagToObj(class CUtlBuffer __near &,struct matrix3x4_t const __near &,class CDmeDag __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmObjSerializer::DagToObj(
        CDmObjSerializer *this,
        CUtlBuffer *b,
        const matrix3x4_t *parentWorldMatrix,
        CDmeDag *pDag,
        const char *pDeltaName,
        const int *absolute)
{
  CDmeTransform *Transform; // eax
  CDmeShape *Shape; // eax
  CDmeMesh *v9; // esi
  int Phase; // ebx
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t inclusiveMatrix; // [esp+Ch] [ebp-34h] BYREF
  CDmObjSerializer *v14; // [esp+3Ch] [ebp-4h]

  v14 = this;
  Transform = CDmeDag::GetTransform(this: pDag);
  CDmeTransform::GetTransform(this: Transform, transform: &inclusiveMatrix);
  ConcatTransforms(in1: parentWorldMatrix, in2: &inclusiveMatrix, out: &inclusiveMatrix);
  Shape = CDmeDag::GetShape(this: pDag);
  v9 = (CDmeMesh *)Shape;
  if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
    CDmObjSerializer::MeshToObj(this, b, parentWorldMatrix: &inclusiveMatrix, pMesh: v9, pDeltaName, absolute);
  Phase = CDmElementFramework::GetPhase(this: pDag);
  for ( i = 0; i < Phase; ++i )
  {
    Child = CDmeDag::GetChild(this: pDag, i);
    CDmObjSerializer::DagToObj(
      this: v14,
      b,
      parentWorldMatrix: &inclusiveMatrix,
      pDag: Child,
      pDeltaName,
      (bool)absolute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D3470
// Name: public: bool CDmObjSerializer::WriteOBJ(char const __near *,class CDmElement __near *,bool,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmObjSerializer::WriteOBJ(
        CDmObjSerializer *this,
        CDmeMesh *pFilename,
        CDmElement *pRoot,
        bool bWriteOBJs,
        const char *pDeltaName,
        const int *absolute)
{
  CDmeDag *Value; // edi
  _WORD *v9; // eax
  int v10; // edi
  CDmeMesh *v11; // esi
  CDmeVertexDeltaData *DeltaState; // eax
  CDmeVertexDeltaData *v13; // edi
  const char *m_pAsString; // eax
  const char *v15; // esi
  const char *v16; // eax
  char *k; // eax
  const char *v18; // eax
  const char *v19; // eax
  char path[260]; // [esp+8h] [ebp-39Ch] BYREF
  char base[260]; // [esp+10Ch] [ebp-298h] BYREF
  char filename[260]; // [esp+210h] [ebp-194h] BYREF
  matrix3x4_t identityMatrix; // [esp+314h] [ebp-90h] BYREF
  CUtlBuffer b; // [esp+344h] [ebp-60h] BYREF
  CDmeDag *pModel; // [esp+374h] [ebp-30h]
  int nDeltaMeshes; // [esp+378h] [ebp-2Ch]
  int nDeltas; // [esp+37Ch] [ebp-28h]
  CUtlVector<CDmeMesh *,CUtlMemory<CDmeMesh *,int> > deltaMeshes; // [esp+380h] [ebp-24h] BYREF
  CUtlString deltaFile; // [esp+394h] [ebp-10h] BYREF
  CDmeMesh *pDeltaMesh; // [esp+3ACh] [ebp+8h]
  int i; // [esp+3B0h] [ebp+Ch]
  int j; // [esp+3B4h] [ebp+10h]

  Value = CDmElement::GetValueElement<CDmeDag>(this: pRoot, pAttributeName: "model");
  pModel = Value;
  if ( Value == nullptr )
    return 0;
  SetIdentityMatrix(matrix: &identityMatrix);
  if ( pDeltaName == nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: &b, growSize: 0, initSize: 0, nFlags: 1);
    CUtlBuffer::PutString(this: &b, pString: "# OBJ\n");
    CUtlBuffer::PutString(this: &b, pString: "#\n");
    this->m_nPositionOffset = 1;
    this->m_nTextureOffset = 1;
    this->m_nNormalOffset = 1;
    CDmObjSerializer::DagToObj(this, &b, parentWorldMatrix: &identityMatrix, pDag: Value, pDeltaName: nullptr, absolute);
    g_pFullFileSystem->WriteFile(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: (const char *)pFilename,
      a3: nullptr,
      a4: &b);
    rename(oldname: (const char *)pFilename, newname: (const char *)pFilename);
    if ( b.m_Memory.m_nGrowSize >= 0 && b.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: b.m_Memory.m_pMemory);
  }
  if ( bWriteOBJs )
  {
    memset(&deltaMeshes, 0, sizeof(deltaMeshes));
    CDmObjSerializer::FindDeltaMeshes(pDag: Value, meshes: (CUtlMemory<vgui::TreeNode *,int> *)&deltaMeshes);
    if ( deltaMeshes.m_Size != 0 )
    {
      V_FileBase(in: (const char *)pFilename, out: base, maxlen: 260);
      V_ExtractFilePath(path: (const char *)pFilename, dest: path, destSize: 260);
      strchr(string: (unsigned __int8 *)base, chr: 0x3Du);
      if ( v9 != nullptr || (strchr(string: (unsigned __int8 *)base, chr: 0x5Fu), v9 != nullptr) )
        *v9 = 95;
      v10 = 0;
      nDeltaMeshes = deltaMeshes.m_Size;
      for ( i = 0; v10 < nDeltaMeshes; i = v10 )
      {
        v11 = deltaMeshes.m_Memory.m_pMemory[v10];
        pDeltaMesh = v11;
        nDeltas = CDmeEditorChoicesInfo::GetChoiceCount(this: v11);
        j = 0;
        if ( nDeltas > 0 )
        {
          while ( 1 )
          {
            DeltaState = CDmeMesh::GetDeltaState(this: v11, nDeltaIndex: j);
            v13 = DeltaState;
            if ( pDeltaName == nullptr )
              goto LABEL_20;
            m_pAsString = DeltaState->m_Name.m_Storage.u.m_pAsString;
            if ( m_pAsString == (const char *)-1 )
              m_pAsString = defaultValue;
            if ( _V_strcmp(s1: pDeltaName, s2: m_pAsString) == 0 )
            {
LABEL_20:
              CUtlBuffer::CUtlBuffer(this: &b, growSize: 0, initSize: 0, nFlags: 1);
              v15 = defaultValue;
              if ( v13->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
                v15 = v13->m_Name.m_Storage.u.m_pAsString;
              CUtlBuffer::PutString(this: &b, pString: "# Delta OBJ: ");
              CUtlBuffer::PutString(this: &b, pString: v15);
              CUtlBuffer::PutString(this: &b, pString: "\n");
              CUtlBuffer::PutString(this: &b, pString: "#\n");
              v16 = v13->m_Name.m_Storage.u.m_pAsString;
              if ( v16 == (const char *)-1 )
                v16 = defaultValue;
              V_strncpy(pDest: filename, pSrc: v16, maxLen: 260);
              for ( k = filename; *k != 0; ++k )
              {
                if ( k >= (char *)&identityMatrix )
                  break;
                if ( *k == 95 )
                  *k = 43;
              }
              CUtlString::CUtlString(this: &deltaFile, pString: base);
              CUtlString::operator+=(this: &deltaFile, rhs: filename);
              CUtlString::operator+=(this: &deltaFile, rhs: ".obj");
              this->m_nPositionOffset = 1;
              this->m_nTextureOffset = 1;
              this->m_nNormalOffset = 1;
              v18 = v13->m_Name.m_Storage.u.m_pAsString;
              if ( v18 == (const char *)-1 )
                v18 = defaultValue;
              CDmObjSerializer::DagToObj(
                this,
                &b,
                parentWorldMatrix: &identityMatrix,
                pDag: pModel,
                pDeltaName: v18,
                absolute);
              v19 = CUtlString::Get(this: &deltaFile);
              V_ComposeFileName(path, filename: v19, dest: filename, destSize: 260);
              g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: nullptr, a4: &b);
              rename(oldname: filename, newname: filename);
              deltaFile.m_Storage.m_nActualLength = 0;
              if ( deltaFile.m_Storage.m_Memory.m_nGrowSize >= 0 )
              {
                if ( deltaFile.m_Storage.m_Memory.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: deltaFile.m_Storage.m_Memory.m_pMemory);
                  deltaFile.m_Storage.m_Memory.m_pMemory = nullptr;
                }
                deltaFile.m_Storage.m_Memory.m_nAllocationCount = 0;
              }
              if ( b.m_Memory.m_nGrowSize >= 0 && b.m_Memory.m_pMemory != nullptr )
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: b.m_Memory.m_pMemory);
            }
            if ( ++j >= nDeltas )
              break;
            v11 = pDeltaMesh;
          }
          v10 = i;
        }
        ++v10;
      }
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&deltaMeshes);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005D3810
// Name: public: class CDmeVertexDeltaData __near * CDmObjSerializer::GetDelta(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmeVertexDeltaData *__thiscall CDmObjSerializer::GetDelta(CDmObjSerializer *this, char *pDeltaName, int bAbsolute)
{
  CDmeVertexDeltaData *result; // eax
  int m_Id; // edi
  int m_Size; // ecx
  CDmObjSerializer::DeltaInfo_t *v7; // esi
  const char *v8; // eax
  int v9; // eax
  CDmElement *v10; // eax
  CDmeVertexDeltaData *v11; // edi
  const char *v12; // [esp-10h] [ebp-150h]
  char deltaPath[260]; // [esp+8h] [ebp-138h] BYREF
  CUtlBuffer utlBuf; // [esp+10Ch] [ebp-34h] BYREF
  CUtlSymbol v15; // [esp+13Ch] [ebp-4h] BYREF

  if ( CUtlSymbolTable::Find(this: &this->m_deltas.m_SymbolTable, result: &v15, pString: pDeltaName)->m_Id == 0xFFFF )
    return nullptr;
  CUtlSymbolTable::AddString(this: &this->m_deltas.m_SymbolTable, result: &v15, pString: pDeltaName);
  m_Id = v15.m_Id;
  m_Size = this->m_deltas.m_Vector.m_Size;
  if ( m_Size <= v15.m_Id && m_Size < v15.m_Id + 1 )
    CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>::InsertMultipleBefore(
      this: &this->m_deltas.m_Vector,
      elem: m_Size,
      num: v15.m_Id + 1 - m_Size);
  v7 = &this->m_deltas.m_Vector.m_Memory.m_pMemory[m_Id];
  result = v7->m_pDeltaData;
  if ( result == nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: &utlBuf, growSize: 0, initSize: 0, nFlags: 0);
    v12 = CUtlString::operator char const *(this: &v7->m_filename);
    v8 = CUtlString::operator char const *(this: &this->m_objDirectory);
    V_ComposeFileName(path: v8, filename: v12, dest: deltaPath, destSize: 260);
    V_FixSlashes(pname: deltaPath, separator: 92);
    if ( g_pFullFileSystem->ReadFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: deltaPath,
           a3: nullptr,
           a4: &utlBuf,
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      if ( v7->m_pComboOp != nullptr )
      {
        strchr(string: (unsigned __int8 *)pDeltaName, chr: 0x5Fu);
        if ( v9 == 0 )
          CDmeCombinationOperator::FindOrCreateControl(
            this: v7->m_pComboOp,
            pControlName: pDeltaName,
            bStereo: 0,
            bAutoAddRawControl: true);
      }
      v10 = CDmObjSerializer::ReadOBJ(
              this,
              buf: &utlBuf,
              dmFileId: (DmElementHandle_t)v7->m_pMesh->m_fileId,
              pName: pDeltaName,
              pFilename: deltaPath,
              pBaseMesh: v7->m_pMesh,
              ppCreatedMesh: nullptr,
              bAbsolute);
      v11 = CastElement<CDmeVertexDeltaData>(pElement: v10);
      v7->m_pDeltaData = v11;
      CUtlBuffer::~CUtlBuffer(this: &utlBuf);
      return v11;
    }
    else
    {
      CUtlBuffer::~CUtlBuffer(this: &utlBuf);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D3970
// Name: public: virtual bool CDmObjSerializer::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmObjSerializer::Unserialize(
        CDmObjSerializer *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  CDmElement *OBJ; // eax

  OBJ = CDmObjSerializer::ReadOBJ(
          this,
          buf,
          dmFileId: (DmElementHandle_t)fileid,
          pName: "bind",
          pFilename: nullptr,
          pBaseMesh: nullptr,
          ppCreatedMesh: nullptr,
          bAbsolute: 1);
  *ppRoot = OBJ;
  return OBJ != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005D39A0
// Name: public: class CDmElement __near * CDmObjSerializer::ReadOBJ(char const __near *,class CDmeMesh __near * __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__userpurge CDmObjSerializer::ReadOBJ@<eax>(
        CDmObjSerializer *this@<ecx>,
        int a2@<ebx>,
        CDmeCombinationOperator *pFilename,
        CDmeMesh **ppCreatedMesh,
        bool bLoadAllDeltas,
        int bAbsolute)
{
  CDmElement *v8; // ebx
  char *v9; // eax
  char *v10; // esi
  char *v11; // eax
  char *v12; // esi
  const char *FileExtension; // eax
  const char *i; // ebx
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // edi
  unsigned __int8 *v17; // eax
  int v18; // eax
  CDmElement *v19; // esi
  CDmObjSerializer::DeltaInfo_t *v20; // esi
  bool v21; // zf
  CDmeMesh *v22; // esi
  char deltaPath[260]; // [esp+8h] [ebp-758h] BYREF
  char findPath[260]; // [esp+10Ch] [ebp-654h] BYREF
  char deltaFile[260]; // [esp+210h] [ebp-550h] BYREF
  char findGlob[260]; // [esp+314h] [ebp-44Ch] BYREF
  char path[260]; // [esp+418h] [ebp-348h] BYREF
  char filename[260]; // [esp+51Ch] [ebp-244h] BYREF
  char baseFile[260]; // [esp+620h] [ebp-140h] BYREF
  CUtlBuffer utlBuf; // [esp+724h] [ebp-3Ch] BYREF
  CDmObjSerializer *v32; // [esp+754h] [ebp-Ch]
  CDmElement *pRoot; // [esp+758h] [ebp-8h]
  CDmeMesh *pMesh; // [esp+75Ch] [ebp-4h] BYREF
  CDmeCombinationOperator *pCombo; // [esp+768h] [ebp+8h]

  v32 = this;
  V_strncpy(pDest: filename, pSrc: (const char *)pFilename, maxLen: 260);
  V_FixSlashes(pname: filename, separator: 92);
  CUtlBuffer::CUtlBuffer(this: &utlBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: filename,
         a3: nullptr,
         a4: &utlBuf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    V_FileBase(in: filename, out: baseFile, maxlen: 260);
    pMesh = nullptr;
    v8 = CDmObjSerializer::ReadOBJ(
           this,
           buf: &utlBuf,
           dmFileId: DMELEMENT_HANDLE_INVALID,
           pName: baseFile,
           pFilename: filename,
           pBaseMesh: nullptr,
           ppCreatedMesh: &pMesh,
           bAbsolute);
    pRoot = v8;
    if ( v8 != nullptr && pMesh != nullptr )
    {
      if ( ppCreatedMesh != nullptr )
        *ppCreatedMesh = pMesh;
      pCombo = nullptr;
      v9 = _V_strrchr(s: baseFile, c: 61);
      v10 = v9;
      if ( v9 == nullptr || *v9 == 0 )
      {
        v11 = _V_strrchr(s: baseFile, c: 95);
        v10 = v11;
        if ( v11 == nullptr || *v11 == 0 || _V_stricmp(s1: v11, s2: "_zero") != 0 )
        {
          CUtlBuffer::~CUtlBuffer(this: &utlBuf);
          return v8;
        }
      }
      V_strncpy(pDest: findGlob, pSrc: baseFile, maxLen: 260);
      v12 = v10 - 780;
      *(_WORD *)v12 = 10847;
      v12[2] = 46;
      FileExtension = V_GetFileExtension(path: filename);
      V_strncpy(pDest: v12 + 3, pSrc: FileExtension, maxLen: &findGlob[257] - v12);
      V_ExtractFilePath(path: filename, dest: path, destSize: 260);
      CUtlString::operator=(this: &this->m_objDirectory, src: path);
      V_ComposeFileName(path, filename: findGlob, dest: findPath, destSize: 260);
      for ( i = (const char *)((int (__thiscall *)(IFileSystem *, char *, CDmeMesh ***, int))g_pFullFileSystem->FindFirst)(
                                a1: g_pFullFileSystem,
                                a2: findPath,
                                a3: &ppCreatedMesh,
                                a4: a2);
            i != nullptr;
            i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: ppCreatedMesh) )
      {
        if ( *i == 0 )
          break;
        V_FileBase(in: i, out: deltaFile, maxlen: 260);
        if ( _V_stricmp(s1: baseFile, s2: deltaFile) != 0 )
        {
          V_ComposeFileName(path, filename: i, dest: deltaPath, destSize: 260);
          if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: deltaPath, a3: nullptr) )
          {
            strchr(string: (unsigned __int8 *)deltaFile, chr: 0x5Fu);
            v16 = v15;
            if ( v15 != nullptr && v15[1] != 0 )
            {
              v16 = v15 + 1;
              strchr(string: v15 + 1, chr: 0x2Bu);
              while ( v17 != nullptr )
              {
                *v17 = 95;
                strchr(string: v17, chr: 0x2Bu);
              }
            }
            strchr(string: v16, chr: 0x5Fu);
            if ( v18 == 0 && pCombo == nullptr )
            {
              v19 = pRoot;
              pCombo = CreateElement<CDmeCombinationOperator>(
                         pObjectName: "combinationOperator",
                         fileid: pRoot->m_fileId,
                         pObjectID: nullptr);
              CDmElement::SetValue<CDmeCombinationOperator>(
                this: v19,
                pAttributeName: "combinationOperator",
                pElement: (DmElementHandle_t)pCombo,
                bCreateIfNotFound: true);
            }
            v20 = CUtlStringMap<CDmObjSerializer::DeltaInfo_t>::operator[](
                    this: &v32->m_deltas,
                    pString: (const char *)v16);
            CUtlString::operator=(this: &v20->m_filename, src: i);
            v21 = !bLoadAllDeltas;
            v20->m_pMesh = pMesh;
            v20->m_pComboOp = pCombo;
            if ( !v21 )
              CDmObjSerializer::GetDelta(this: v32, pDeltaName: (char *)v16, bAbsolute);
          }
        }
      }
      g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)ppCreatedMesh);
      if ( pCombo != nullptr )
      {
        v22 = pMesh;
        CDmeCombinationOperator::AddTarget(this: pCombo, pElement: pMesh);
        CDmeMesh::ComputeAllCorrectedPositionsFromActualPositions(this: v22);
      }
      v8 = pRoot;
    }
    if ( utlBuf.m_Memory.m_nGrowSize >= 0 && utlBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: utlBuf.m_Memory.m_pMemory);
    return v8;
  }
  else
  {
    if ( utlBuf.m_Memory.m_nGrowSize >= 0 && utlBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: utlBuf.m_Memory.m_pMemory);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D1080
// Name: class CDmeCombinationOperator __near * CreateElement<class CDmeCombinationOperator>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *__cdecl CreateElement<CDmeCombinationOperator>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeCombinationOperator::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeCombinationOperator::m_classType.u) != 0 )
  {
    return (CDmeCombinationOperator *)(v5 - 4);
  }
  else
  {
    return nullptr;
  }
}

} // namespace sceneviewer
