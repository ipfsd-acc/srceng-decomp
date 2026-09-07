// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmeutils/dmmeshutils.cpp
// Functions: 57
// ============================================================

#include "dmeutils\dmmeshutils.h"

//------------------------------------------------------------------------------
// Address: 0x00457340
// Name: public: class CDmeCombinationOperator __near * CDmeCombinationOperator::Copy(enum TraversalDepth_t)const
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationOperator *__thiscall CDmeCombinationOperator::Copy(
        CDmeCombinationOperator *this,
        TraversalDepth_t depth)
{
  CDmElement *v2; // eax

  v2 = CDmElement::CopyInternal(this: &this->CDmElement, depth);
  if ( v2 != nullptr )
    return (CDmeCombinationOperator *)((char *)&v2[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00457360
// Name: enum DmFileId_t CreateUniqueFileId(void)
// Source: json
//------------------------------------------------------------------------------
DmFileId_t __cdecl CreateUniqueFileId()
{
  char fileIdBuf[260]; // [esp+0h] [ebp-114h] BYREF
  UniqueId_t uniqueId; // [esp+104h] [ebp-10h] BYREF

  do
  {
    CreateUniqueId(pDest: &uniqueId);
    UniqueIdToString(id: &uniqueId, pBuf: fileIdBuf, nMaxLen: 260);
  }
  while ( g_pDataModel->GetFileId(this: g_pDataModel, a2: fileIdBuf) != DMFILEID_INVALID );
  return g_pDataModel->FindOrCreateFileId(this: g_pDataModel, a2: fileIdBuf);
}

//------------------------------------------------------------------------------
// Address: 0x004575E0
// Name: public: static bool CDmMeshUtils::RemapMaterial(class CDmeMesh __near *,class CUtlString const __near &,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDmMeshUtils::RemapMaterial(CDmeMesh *pMesh, CUtlString *src, CUtlString *dst)
{
  const char *v3; // eax
  const char *v4; // eax
  int v5; // ebx
  int i; // edi
  CDmeFaceSet *FaceSet; // eax
  CDmeMaterial *Material; // eax
  CDmeMaterial *v9; // esi
  const char *MaterialName; // eax
  char srcName[260]; // [esp+8h] [ebp-314h] BYREF
  char matName[260]; // [esp+10Ch] [ebp-210h] BYREF
  char dstName[260]; // [esp+210h] [ebp-10Ch] BYREF
  CUtlSymbolLarge value; // [esp+314h] [ebp-8h] BYREF
  bool retVal; // [esp+31Bh] [ebp-1h]

  retVal = false;
  v3 = CUtlString::operator char const *(this: src);
  V_StripExtension(in: v3, out: srcName, outSize: 260);
  V_FixSlashes(pname: srcName, separator: 47);
  v4 = CUtlString::operator char const *(this: dst);
  V_strncpy(pDest: dstName, pSrc: v4, maxLen: 260);
  V_FixSlashes(pname: dstName, separator: 47);
  v5 = CDmeMesh::FaceSetCount(this: pMesh);
  for ( i = 0; i < v5; ++i )
  {
    FaceSet = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: i);
    if ( FaceSet != nullptr )
    {
      Material = CDmeFaceSet::GetMaterial(this: FaceSet);
      v9 = Material;
      if ( Material != nullptr )
      {
        MaterialName = CDmeMaterial::GetMaterialName(this: Material);
        V_StripExtension(in: MaterialName, out: matName, outSize: 260);
        V_FixSlashes(pname: matName, separator: 47);
        if ( _V_stricmp(s1: srcName, s2: matName) == 0 )
        {
          CDmeMaterial::SetMaterial(this: v9, pMaterialName: dstName);
          g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: dstName);
          CDmAttribute::SetValue<CUtlSymbolLarge>(this: v9->m_Name.m_pAttribute, &value);
          retVal = true;
        }
      }
    }
  }
  return retVal;
}

//------------------------------------------------------------------------------
// Address: 0x00457710
// Name: public: static bool CDmMeshUtils::RemapMaterial(class CDmeMesh __near *,int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::RemapMaterial(CDmeMesh *pMesh, int nMaterialIndex, CUtlString *dst)
{
  int v3; // eax
  CDmeFaceSet *FaceSet; // eax
  CDmeMaterial *Material; // esi
  CUtlString *v7; // edi
  const char *v8; // eax
  const char *v9; // eax

  v3 = CDmeMesh::FaceSetCount(this: pMesh);
  if ( nMaterialIndex >= v3 )
    return 0;
  FaceSet = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: nMaterialIndex);
  if ( FaceSet == nullptr )
    return 0;
  Material = CDmeFaceSet::GetMaterial(this: FaceSet);
  if ( Material == nullptr )
    return 0;
  v7 = dst;
  v8 = CUtlString::operator char const *(this: dst);
  CDmeMaterial::SetMaterial(this: Material, pMaterialName: v8);
  v9 = CUtlString::operator char const *(this: v7);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&nMaterialIndex, a3: v9);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: Material->m_Name.m_pAttribute,
    value: (const CUtlSymbolLarge *)&nMaterialIndex);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00457790
// Name: void RemapData<class Vector>(class CDmrArray<class Vector>,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapData<Vector>(
        CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > data,
        const CUtlVector<int,CUtlMemory<int,int> > *newToOldMap)
{
  const CUtlVector<int,CUtlMemory<int,int> > *v2; // esi
  int m_Size; // edi
  void *v4; // esp
  int v5; // ecx
  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *p_data; // eax
  Vector *v7; // edx
  Vector *v8; // edx
  Vector *v9; // edx
  Vector *v10; // edx
  float *v11; // eax
  Vector *v12; // edx
  Vector v13; // [esp+0h] [ebp-Ch] BYREF

  v2 = newToOldMap;
  m_Size = newToOldMap->m_Size;
  v4 = alloca(12 * m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    p_data = &data;
    do
    {
      v7 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5]];
      *(float *)&p_data[-3].m_pAttribute = v7->x;
      v5 += 4;
      p_data += 6;
      *(float *)&p_data[-8].m_pStorage = v7->y;
      *(float *)&p_data[-8].m_pAttribute = v7->z;
      v8 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5 - 3]];
      *(float *)&p_data[-7].m_pStorage = v8->x;
      *(float *)&p_data[-7].m_pAttribute = v8->y;
      *(float *)&p_data[-6].m_pStorage = v8->z;
      v9 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5 - 2]];
      *(float *)&p_data[-6].m_pAttribute = v9->x;
      *(float *)&p_data[-5].m_pStorage = v9->y;
      *(float *)&p_data[-5].m_pAttribute = v9->z;
      v10 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5 - 1]];
      *(float *)&p_data[-4].m_pStorage = v10->x;
      *(float *)&p_data[-4].m_pAttribute = v10->y;
      *(float *)&p_data[-3].m_pStorage = v10->z;
    }
    while ( v5 < m_Size - 3 );
  }
  if ( v5 < m_Size )
  {
    v11 = &v13.z + 3 * v5;
    do
    {
      v12 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5]];
      *(v11 - 2) = v12->x;
      ++v5;
      v11 += 3;
      *(v11 - 4) = v12->y;
      *(v11 - 3) = v12->z;
    }
    while ( v5 < m_Size );
  }
  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::RemoveMultiple(
    this: &data,
    elem: m_Size,
    num: data.m_pStorage->m_Size - m_Size);
  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::SetMultiple(
    this: &data,
    i: 0,
    nCount: m_Size,
    pValue: &v13);
}

//------------------------------------------------------------------------------
// Address: 0x004578C0
// Name: void MirrorVertexData<class Vector>(class CDmeVertexData __near *,int,int,int,int,class CDmrArrayConst<class Vector> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MirrorVertexData<Vector>(
        CDmeVertexData *pBase,
        int fieldIndex,
        int axis,
        int nOrigVertexCount,
        int nMirrorCount,
        const CDmrArrayConst<Vector> *origData,
        const CUtlVector<int,CUtlMemory<int,int> > *origIndices,
        const CUtlVector<int,CUtlMemory<int,int> > *mirrorMap,
        const CUtlVector<int,CUtlMemory<int,int> > *dataMirrorMap)
{
  const CDmrArrayConst<Vector> *v9; // ebx
  int m_Size; // esi
  void *v11; // esp
  void *v12; // esp
  int v13; // edx
  int v14; // eax
  int v15; // edi
  int *m_pMemory; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  Vector *v20; // eax
  float x; // xmm1_4
  Vector *v22; // eax
  Vector *v23; // edx
  int v24; // ecx
  int *v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v28; // edx
  Vector *v29; // eax
  float v30; // xmm1_4
  Vector *v31; // eax
  Vector *v32; // edx
  int v33; // ecx
  int *v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // edx
  Vector *v38; // eax
  float v39; // xmm1_4
  Vector *v40; // eax
  Vector *v41; // edx
  int v42; // ecx
  int *v43; // ecx
  int v44; // eax
  int v45; // ecx
  int v46; // edx
  Vector *v47; // eax
  float v48; // xmm1_4
  Vector *v49; // eax
  Vector *v50; // edx
  int v51; // ecx
  int v52; // edx
  int v53; // edx
  int *v54; // edx
  int v55; // eax
  Vector *v56; // ebx
  float v57; // xmm1_4
  Vector *v58; // ecx
  Vector *v59; // ebx
  int *v60; // ecx
  int v61; // edi
  DmAttributeType_t v62; // ebx
  _DWORD v63[3]; // [esp+0h] [ebp-30h] BYREF
  Vector mirrorData; // [esp+Ch] [ebp-24h]
  int *v65; // [esp+18h] [ebp-18h]
  int v66; // [esp+1Ch] [ebp-14h]
  Vector *pMirrorData; // [esp+20h] [ebp-10h]
  int *pMirrorIndices; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]
  int nMirrorIndex; // [esp+2Ch] [ebp-4h]

  if ( nMirrorCount > 0 )
  {
    v9 = origData;
    m_Size = origData->m_pStorage->m_Size;
    v11 = alloca(12 * nMirrorCount);
    pMirrorData = (Vector *)v63;
    v12 = alloca(4 * nMirrorCount);
    v13 = 0;
    v14 = 0;
    v15 = -1;
    pMirrorIndices = v63;
    nMirrorIndex = 0;
    i = 0;
    if ( nOrigVertexCount >= 4 )
    {
      v66 = 2;
      do
      {
        if ( mirrorMap->m_Memory.m_pMemory[v14] != v14 )
        {
          m_pMemory = dataMirrorMap->m_Memory.m_pMemory;
          v65 = &origIndices->m_Memory.m_pMemory[v14];
          v17 = *v65;
          v18 = m_pMemory[*v65];
          if ( v18 == *v65 )
          {
            v63[v13] = v17;
          }
          else
          {
            v19 = v17;
            v20 = origData->m_pStorage->m_Memory.m_pMemory;
            x = v20[v19].x;
            v22 = &v20[v19];
            v23 = pMirrorData;
            mirrorData.x = x;
            mirrorData.y = v22->y;
            mirrorData.z = v22->z;
            *(&mirrorData.x + axis) = *(&mirrorData.x + axis) * -1.0;
            v23[v18 - m_Size] = mirrorData;
            v24 = dataMirrorMap->m_Memory.m_pMemory[*v65];
            v13 = nMirrorIndex;
            if ( v24 - m_Size > v15 )
              v15 = v24 - m_Size;
            v63[nMirrorIndex] = v24;
          }
          v14 = i;
          nMirrorIndex = v13 + 1;
        }
        if ( mirrorMap->m_Memory.m_pMemory[v14 + 1] != v66 - 1 )
        {
          v25 = dataMirrorMap->m_Memory.m_pMemory;
          v65 = &origIndices->m_Memory.m_pMemory[v14 + 1];
          v26 = *v65;
          v27 = v25[*v65];
          if ( v27 == *v65 )
          {
            v63[nMirrorIndex] = v26;
          }
          else
          {
            v28 = v26;
            v29 = origData->m_pStorage->m_Memory.m_pMemory;
            v30 = v29[v28].x;
            v31 = &v29[v28];
            v32 = pMirrorData;
            mirrorData.x = v30;
            mirrorData.y = v31->y;
            mirrorData.z = v31->z;
            *(&mirrorData.x + axis) = *(&mirrorData.x + axis) * -1.0;
            v32[v27 - m_Size] = mirrorData;
            v33 = dataMirrorMap->m_Memory.m_pMemory[*v65];
            if ( v33 - m_Size > v15 )
              v15 = v33 - m_Size;
            v63[nMirrorIndex] = v33;
          }
          ++nMirrorIndex;
          v14 = i;
        }
        if ( mirrorMap->m_Memory.m_pMemory[v14 + 2] != v66 )
        {
          v34 = dataMirrorMap->m_Memory.m_pMemory;
          v65 = &origIndices->m_Memory.m_pMemory[i + 2];
          v35 = *v65;
          v36 = v34[*v65];
          if ( v36 == *v65 )
          {
            v63[nMirrorIndex] = v35;
          }
          else
          {
            v37 = v35;
            v38 = origData->m_pStorage->m_Memory.m_pMemory;
            v39 = v38[v37].x;
            v40 = &v38[v37];
            v41 = pMirrorData;
            mirrorData.x = v39;
            mirrorData.y = v40->y;
            mirrorData.z = v40->z;
            *(&mirrorData.x + axis) = *(&mirrorData.x + axis) * -1.0;
            v41[v36 - m_Size] = mirrorData;
            v42 = dataMirrorMap->m_Memory.m_pMemory[*v65];
            if ( v42 - m_Size > v15 )
              v15 = v42 - m_Size;
            v63[nMirrorIndex] = v42;
          }
          ++nMirrorIndex;
        }
        if ( mirrorMap->m_Memory.m_pMemory[i + 3] == v66 + 1 )
        {
          v13 = nMirrorIndex;
        }
        else
        {
          v43 = dataMirrorMap->m_Memory.m_pMemory;
          v65 = &origIndices->m_Memory.m_pMemory[i + 3];
          v44 = *v65;
          v45 = v43[*v65];
          if ( v45 == *v65 )
          {
            v53 = nMirrorIndex;
            v63[nMirrorIndex] = v44;
            v13 = v53 + 1;
            nMirrorIndex = v13;
          }
          else
          {
            v46 = v44;
            v47 = origData->m_pStorage->m_Memory.m_pMemory;
            v48 = v47[v46].x;
            v49 = &v47[v46];
            v50 = pMirrorData;
            mirrorData.x = v48;
            mirrorData.y = v49->y;
            mirrorData.z = v49->z;
            *(&mirrorData.x + axis) = *(&mirrorData.x + axis) * -1.0;
            v50[v45 - m_Size] = mirrorData;
            v51 = dataMirrorMap->m_Memory.m_pMemory[*v65];
            v52 = nMirrorIndex;
            if ( v51 - m_Size > v15 )
              v15 = v51 - m_Size;
            v63[nMirrorIndex] = v51;
            v13 = v52 + 1;
            nMirrorIndex = v13;
          }
        }
        v66 += 4;
        v14 = i + 4;
        i = v14;
      }
      while ( v14 < nOrigVertexCount - 3 );
    }
    if ( v14 < nOrigVertexCount )
    {
      v66 = (int)&v63[v13];
      do
      {
        if ( mirrorMap->m_Memory.m_pMemory[v14] != v14 )
        {
          v54 = &origIndices->m_Memory.m_pMemory[v14];
          v55 = *v54;
          if ( dataMirrorMap->m_Memory.m_pMemory[v55] == v55 )
          {
            *(_DWORD *)v66 = *v54;
          }
          else
          {
            v56 = v9->m_pStorage->m_Memory.m_pMemory;
            v57 = v56[v55].x;
            v58 = &v56[v55];
            v59 = pMirrorData;
            mirrorData.x = v57;
            mirrorData.y = v58->y;
            mirrorData.z = v58->z;
            *(&mirrorData.x + axis) = *(&mirrorData.x + axis) * -1.0;
            v60 = dataMirrorMap->m_Memory.m_pMemory;
            v59[dataMirrorMap->m_Memory.m_pMemory[v55] - m_Size] = mirrorData;
            if ( v60[*v54] - m_Size > v15 )
              v15 = v60[*v54] - m_Size;
            v9 = origData;
            *(_DWORD *)v66 = v60[*v54];
          }
          v66 += 4;
          v14 = i;
        }
        i = ++v14;
      }
      while ( v14 < nOrigVertexCount );
    }
    v61 = v15 + 1;
    v62 = (v9->m_pAttribute->m_nFlags & 0x1F) - 14;
    CDmeVertexDataBase::AddVertexData(this: pBase, nFieldIndex: fieldIndex, nCount: v61);
    CDmeVertexDataBase::SetVertexData(
      this: pBase,
      nFieldIndex: fieldIndex,
      nFirstVertex: m_Size,
      nCount: v61,
      valueType: v62,
      pData: pMirrorData);
    CDmeVertexDataBase::SetVertexIndices(
      this: pBase,
      nFieldIndex: fieldIndex,
      nFirstIndex: nOrigVertexCount,
      nCount: nMirrorCount,
      pIndices: pMirrorIndices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457D80
// Name: void MirrorDeltaData<class Vector>(class CDmeVertexDeltaData __near *,int,int,class CDmrArrayConst<class Vector> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MirrorDeltaData<Vector>(
        CDmeVertexDeltaData *pDelta,
        int fieldIndex,
        int axis,
        const CDmrArrayConst<Vector> *origData,
        const CUtlVector<int,CUtlMemory<int,int> > *origIndices,
        const CUtlVector<int,CUtlMemory<int,int> > *dataMap)
{
  int v6; // ebx
  void *v7; // esp
  _DWORD *v8; // edi
  void *v9; // esp
  int v10; // edx
  int v11; // esi
  float *v12; // eax
  int v13; // edi
  float *v14; // ecx
  int *m_pMemory; // ebx
  Vector *v16; // edx
  double z; // st7
  int *v18; // edx
  int *v19; // ebx
  Vector *v20; // edx
  double x; // st7
  int v22; // edx
  double v23; // st7
  int *v24; // edx
  int *v25; // ebx
  Vector *v26; // edx
  double v27; // st7
  int v28; // edx
  double v29; // st7
  int *v30; // edx
  int *v31; // ebx
  Vector *v32; // edx
  double v33; // st7
  int v34; // edx
  double v35; // st7
  int *v36; // edx
  int v37; // ecx
  float *v38; // edi
  int *v39; // ebx
  float *v40; // eax
  double v41; // st7
  int *v42; // eax
  DmAttributeType_t v43; // edi
  _DWORD v44[4]; // [esp+0h] [ebp-24h] BYREF
  void *pData; // [esp+10h] [ebp-14h]
  int m_Size; // [esp+14h] [ebp-10h]
  int *v47; // [esp+18h] [ebp-Ch]
  int v48; // [esp+1Ch] [ebp-8h]
  int *pIndices; // [esp+20h] [ebp-4h]

  m_Size = origData->m_pStorage->m_Size;
  v6 = m_Size;
  v7 = alloca(12 * m_Size);
  v8 = v44;
  pData = v44;
  v9 = alloca(4 * m_Size);
  v10 = 0;
  v11 = 0;
  pIndices = v44;
  v48 = 0;
  if ( m_Size >= 4 )
  {
    v12 = (float *)pData;
    v13 = 0;
    v14 = (float *)((char *)pData + 4 * axis);
    do
    {
      m_pMemory = dataMap->m_Memory.m_pMemory;
      v47 = &origIndices->m_Memory.m_pMemory[v10];
      if ( m_pMemory[*v47] != *v47 )
      {
        v16 = origData->m_pStorage->m_Memory.m_pMemory;
        ++v11;
        *v12 = v16[v13].x;
        v12 += 3;
        v14 += 3;
        *(v12 - 2) = v16[v13].y;
        z = v16[v13].z;
        v18 = v47;
        *(v12 - 1) = z;
        *(v14 - 3) = *(v14 - 3) * -1.0;
        v44[v11 - 1] = m_pMemory[*v18];
      }
      v19 = dataMap->m_Memory.m_pMemory;
      v47 = &origIndices->m_Memory.m_pMemory[v48 + 1];
      if ( v19[*v47] != *v47 )
      {
        v20 = origData->m_pStorage->m_Memory.m_pMemory;
        x = v20[v13 + 1].x;
        v22 = (int)&v20[v13 + 1];
        *v12 = x;
        ++v11;
        v12 += 3;
        *(v12 - 2) = *(float *)(v22 + 4);
        v14 += 3;
        v23 = *(float *)(v22 + 8);
        v24 = v47;
        *(v12 - 1) = v23;
        *(v14 - 3) = *(v14 - 3) * -1.0;
        v44[v11 - 1] = v19[*v24];
      }
      v25 = dataMap->m_Memory.m_pMemory;
      v47 = &origIndices->m_Memory.m_pMemory[v48 + 2];
      if ( v25[*v47] != *v47 )
      {
        v26 = origData->m_pStorage->m_Memory.m_pMemory;
        v27 = v26[v13 + 2].x;
        v28 = (int)&v26[v13 + 2];
        *v12 = v27;
        ++v11;
        v12 += 3;
        *(v12 - 2) = *(float *)(v28 + 4);
        v14 += 3;
        v29 = *(float *)(v28 + 8);
        v30 = v47;
        *(v12 - 1) = v29;
        *(v14 - 3) = *(v14 - 3) * -1.0;
        v44[v11 - 1] = v25[*v30];
      }
      v31 = dataMap->m_Memory.m_pMemory;
      v47 = &origIndices->m_Memory.m_pMemory[v48 + 3];
      if ( v31[*v47] != *v47 )
      {
        v32 = origData->m_pStorage->m_Memory.m_pMemory;
        v33 = v32[v13 + 3].x;
        v34 = (int)&v32[v13 + 3];
        *v12 = v33;
        ++v11;
        v12 += 3;
        *(v12 - 2) = *(float *)(v34 + 4);
        v14 += 3;
        v35 = *(float *)(v34 + 8);
        v36 = v47;
        *(v12 - 1) = v35;
        *(v14 - 3) = *(v14 - 3) * -1.0;
        v44[v11 - 1] = v31[*v36];
      }
      v10 = v48 + 4;
      v13 += 4;
      v48 = v10;
    }
    while ( v10 < m_Size - 3 );
    v6 = m_Size;
    v8 = pData;
  }
  if ( v10 < v6 )
  {
    v48 = 12 * v10;
    v37 = (int)&v8[3 * v11 + 2];
    v38 = (float *)&v8[2 * v11 + v11 + axis];
    do
    {
      v39 = dataMap->m_Memory.m_pMemory;
      v47 = &origIndices->m_Memory.m_pMemory[v10];
      if ( v39[*v47] != *v47 )
      {
        v40 = (float *)((char *)&origData->m_pStorage->m_Memory.m_pMemory->x + v48);
        ++v11;
        v37 += 12;
        *(float *)(v37 - 20) = *v40;
        v38 += 3;
        *(float *)(v37 - 16) = v40[1];
        v41 = v40[2];
        v42 = v47;
        *(float *)(v37 - 12) = v41;
        *(v38 - 3) = *(v38 - 3) * -1.0;
        v44[v11 - 1] = v39[*v42];
      }
      v6 = m_Size;
      v48 += 12;
      ++v10;
    }
    while ( v10 < m_Size );
  }
  v43 = (origData->m_pAttribute->m_nFlags & 0x1F) - 14;
  CDmeVertexDataBase::AddVertexData(this: pDelta, nFieldIndex: fieldIndex, nCount: v11);
  CDmeVertexDataBase::SetVertexData(
    this: pDelta,
    nFieldIndex: fieldIndex,
    nFirstVertex: v6,
    nCount: v11,
    valueType: v43,
    pData);
  CDmeVertexDataBase::SetVertexIndices(this: pDelta, nFieldIndex: fieldIndex, nFirstIndex: v6, nCount: v11, pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x004582B0
// Name: int GetMaxVertexCount(class CDmeMesh const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaxVertexCount(CDmeMesh *pMesh)
{
  int v1; // esi
  int v2; // edi
  const CDmeFaceSet *FaceSet; // eax
  int m_Size; // ecx
  int *m_pMemory; // eax
  int i; // edx
  int nFaceSetCount; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v2 = 0;
  nFaceSetCount = CDmeMesh::FaceSetCount(this: pMesh);
  if ( nFaceSetCount > 0 )
  {
    do
    {
      FaceSet = CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: v2);
      m_Size = FaceSet->m_indices.m_Storage.m_Size;
      if ( m_Size > 0 )
      {
        m_pMemory = FaceSet->m_indices.m_Storage.m_Memory.m_pMemory;
        for ( i = m_Size; i != 0; --i )
        {
          if ( *m_pMemory > v1 )
            v1 = *m_pMemory;
          ++m_pMemory;
        }
      }
      ++v2;
    }
    while ( v2 < nFaceSetCount );
  }
  return v1 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00458310
// Name: protected: static void CDmMeshUtils::MirrorVertices(class CDmeVertexData __near *,int,int,int,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmMeshUtils::MirrorVertices(
        CDmeVertexData *pBase,
        int fieldIndex,
        int nOldVertexCount,
        int nMirrorCount,
        const CUtlVector<int,CUtlMemory<int,int> > *baseIndices,
        const CUtlVector<int,CUtlMemory<int,int> > *mirrorMap)
{
  int v6; // edi
  void *v7; // esp
  int v8; // ecx
  int *v9; // esi
  int v10; // eax
  int v11[4]; // [esp+0h] [ebp-10h] BYREF

  v6 = nMirrorCount;
  if ( nMirrorCount > 0 )
  {
    v7 = alloca(4 * nMirrorCount);
    v8 = 0;
    v9 = v11;
    if ( nOldVertexCount > 0 )
    {
      do
      {
        v10 = mirrorMap->m_Memory.m_pMemory[v8];
        if ( v10 != v8 )
          *v9++ = baseIndices->m_Memory.m_pMemory[v10 - nOldVertexCount];
        ++v8;
      }
      while ( v8 < nOldVertexCount );
      v6 = nMirrorCount;
    }
    CDmeVertexDataBase::SetVertexIndices(
      this: pBase,
      nFieldIndex: fieldIndex,
      nFirstIndex: nOldVertexCount,
      nCount: v6,
      pIndices: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458380
// Name: public: static int CDmMeshUtils::FindMergeSocket(class CUtlVector<class CUtlVector<class CDmMeshComp::CEdge __near *,class CUtlMemory<class CDmMeshComp::CEdge __near *,int>>,class CUtlMemory<class CUtlVector<class CDmMeshComp::CEdge __near *,class CUtlMemory<class CDmMeshComp::CEdge __near *,int>>,int>> const __near &,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmMeshUtils::FindMergeSocket(
        const CUtlVector<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,CUtlMemory<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,int> > *srcBorderEdgesList,
        CDmeMesh *pDstMesh)
{
  int v2; // esi
  int v3; // ecx
  int v4; // eax
  _DWORD *v5; // edi
  int v6; // esi
  CDmMeshComp::CEdge *v7; // ebx
  CDmMeshComp dstComp; // [esp+Ch] [ebp-6Ch] BYREF
  int v10; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]
  int j; // [esp+70h] [ebp-8h]
  int nEdgeMatch; // [esp+74h] [ebp-4h]

  CDmMeshComp::CDmMeshComp(this: &dstComp, pMesh: pDstMesh, pPassedBase: nullptr);
  v2 = srcBorderEdgesList->m_Size - 1;
  i = v2;
  if ( v2 < 0 )
  {
LABEL_13:
    CDmMeshComp::~CDmMeshComp(this: &dstComp);
    return -1;
  }
  else
  {
    v3 = 20 * v2;
    v10 = 20 * v2;
    while ( 1 )
    {
      v4 = 0;
      v5 = (CDmMeshComp::CEdge ***)((char *)&srcBorderEdgesList->m_Memory.m_pMemory->m_Memory.m_pMemory + v3);
      nEdgeMatch = 0;
      j = 0;
      if ( dstComp.m_edges.m_Size != 0 )
      {
        do
        {
          v6 = v5[3] - 1;
          v7 = dstComp.m_edges.m_Memory.m_pMemory[v4];
          if ( v6 >= 0 )
          {
            while ( !CDmMeshComp::CEdge::operator==(this: v7, rhs: *(const CDmMeshComp::CEdge **)(*v5 + 4 * v6)) )
            {
              if ( --v6 < 0 )
                goto LABEL_9;
            }
            ++nEdgeMatch;
          }
LABEL_9:
          v4 = j + 1;
          j = v4;
        }
        while ( v4 != dstComp.m_edges.m_Size );
        v2 = i;
        v3 = v10;
      }
      if ( nEdgeMatch == v5[3] )
        break;
      --v2;
      v3 -= 20;
      i = v2;
      v10 = v3;
      if ( v2 < 0 )
        goto LABEL_13;
    }
    CDmMeshComp::~CDmMeshComp(this: &dstComp);
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458440
// Name: void AppendData<class Vector>(class CDmrArrayConst<class Vector> const __near &,class CDmrArray<class Vector> __near &,struct matrix3x4_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppendData<Vector>(
        const CDmrArrayConst<Vector> *srcData,
        CDmrArray<Vector> *dstData,
        const matrix3x4_t *pMat)
{
  int m_Size; // ebx
  int v4; // esi
  int v5; // edi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *m_pStorage; // ecx
  Vector v; // [esp+Ch] [ebp-10h] BYREF
  int nDstCount; // [esp+18h] [ebp-4h]

  m_Size = srcData->m_pStorage->m_Size;
  nDstCount = dstData->m_pStorage->m_Size;
  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddMultipleToTail(
    this: dstData,
    num: m_Size);
  if ( pMat != nullptr )
  {
    v4 = 0;
    if ( m_Size > 0 )
    {
      v5 = 0;
      do
      {
        m_pStorage = srcData->m_pStorage;
        v = srcData->m_pStorage->m_Memory.m_pMemory[v5];
        VectorTransform(in1: &m_pStorage->m_Memory.m_pMemory[v5].x, in2: pMat, out: &v.x);
        CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::Set(
          this: dstData,
          i: v4 + nDstCount,
          value: &v);
        ++v4;
        ++v5;
      }
      while ( v4 < m_Size );
    }
  }
  else
  {
    CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::SetMultiple(
      this: dstData,
      i: nDstCount,
      nCount: m_Size,
      pValue: srcData->m_pStorage->m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004584F0
// Name: void RemapData<float>(class CDmrArray<float>,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapData<float>(
        CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > data,
        int newToOldMap)
{
  const CUtlVector<int,CUtlMemory<int,int> > *v2; // esi
  int v3; // edi
  void *v4; // esp
  int v5; // eax
  int v6; // edx
  unsigned int v7; // ecx
  float *v8; // eax
  char *v9; // edx
  double v10; // st7
  const CUtlVector<int,CUtlMemory<int,int> > *v11; // edx
  int v12; // edi
  int v13; // edx
  float v14[2]; // [esp+0h] [ebp-20h] BYREF
  int v15; // [esp+8h] [ebp-18h] BYREF
  int v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  int v19; // [esp+1Ch] [ebp-4h]

  v2 = (const CUtlVector<int,CUtlMemory<int,int> > *)newToOldMap;
  v17 = *(_DWORD *)(newToOldMap + 12);
  v3 = v17;
  v4 = alloca(4 * v17);
  v5 = 0;
  if ( v17 >= 4 )
  {
    v18 = 4 - (_DWORD)v14;
    v6 = -8 - (_DWORD)v14;
    v7 = ((unsigned int)(v17 - 4) >> 2) + 1;
    newToOldMap = 8;
    v8 = (float *)&v15;
    v19 = -8 - (_DWORD)v14;
    v16 = 4 * v7;
    while ( 1 )
    {
      v9 = (char *)v8 + v6;
      *(v8 - 2) = data.m_pStorage->m_Memory.m_pMemory[*(_DWORD *)&v9[(unsigned int)v2->m_Memory.m_pMemory]];
      v10 = data.m_pStorage->m_Memory.m_pMemory[*(_DWORD *)&v9[(unsigned int)v2->m_Memory.m_pMemory + 4]];
      v11 = (const CUtlVector<int,CUtlMemory<int,int> > *)newToOldMap;
      *(v8 - 1) = v10;
      v12 = v18;
      *v8 = data.m_pStorage->m_Memory.m_pMemory[*(int *)((char *)&v11->m_Memory.m_pMemory
                                                       + (unsigned int)v2->m_Memory.m_pMemory)];
      v8[1] = data.m_pStorage->m_Memory.m_pMemory[*(_DWORD *)((char *)v8 + v12 + (unsigned int)v2->m_Memory.m_pMemory)];
      v8 += 4;
      --v7;
      newToOldMap = (int)&v11->m_pElements;
      if ( v7 == 0 )
        break;
      v6 = v19;
    }
    v3 = v17;
    v5 = v16;
  }
  for ( ; v5 < v3; v14[v5 - 1] = data.m_pStorage->m_Memory.m_pMemory[v13] )
    v13 = v2->m_Memory.m_pMemory[v5++];
  CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveMultiple(
    this: &data,
    elem: v3,
    num: data.m_pStorage->m_Size - v3);
  CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::SetMultiple(
    this: &data,
    i: 0,
    nCount: v3,
    pValue: v14);
}

//------------------------------------------------------------------------------
// Address: 0x00458600
// Name: void RemapData<class Vector2D>(class CDmrArray<class Vector2D>,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapData<Vector2D>(
        CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > data,
        const CUtlVector<int,CUtlMemory<int,int> > *newToOldMap)
{
  const CUtlVector<int,CUtlMemory<int,int> > *v2; // esi
  int m_Size; // edi
  void *v4; // esp
  int v5; // ecx
  CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > *p_data; // eax
  int v7; // edx
  double x; // st7
  Vector2D *v9; // edx
  int v10; // edx
  double v11; // st7
  Vector2D *v12; // edx
  int v13; // edx
  double v14; // st7
  Vector2D *v15; // edx
  int v16; // edx
  double v17; // st7
  Vector2D *v18; // edx
  Vector2D *v19; // eax
  Vector2D v20; // [esp+0h] [ebp-Ch] BYREF

  v2 = newToOldMap;
  m_Size = newToOldMap->m_Size;
  v4 = alloca(8 * m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    p_data = &data;
    do
    {
      v7 = v2->m_Memory.m_pMemory[v5];
      x = data.m_pStorage->m_Memory.m_pMemory[v7].x;
      v9 = &data.m_pStorage->m_Memory.m_pMemory[v7];
      *(float *)&p_data[-3].m_pAttribute = x;
      v5 += 4;
      p_data += 4;
      *(float *)&p_data[-6].m_pStorage = v9->y;
      v10 = v2->m_Memory.m_pMemory[v5 - 3];
      v11 = data.m_pStorage->m_Memory.m_pMemory[v10].x;
      v12 = &data.m_pStorage->m_Memory.m_pMemory[v10];
      *(float *)&p_data[-6].m_pAttribute = v11;
      *(float *)&p_data[-5].m_pStorage = v12->y;
      v13 = v2->m_Memory.m_pMemory[v5 - 2];
      v14 = data.m_pStorage->m_Memory.m_pMemory[v13].x;
      v15 = &data.m_pStorage->m_Memory.m_pMemory[v13];
      *(float *)&p_data[-5].m_pAttribute = v14;
      *(float *)&p_data[-4].m_pStorage = v15->y;
      v16 = v2->m_Memory.m_pMemory[v5 - 1];
      v17 = data.m_pStorage->m_Memory.m_pMemory[v16].x;
      v18 = &data.m_pStorage->m_Memory.m_pMemory[v16];
      *(float *)&p_data[-4].m_pAttribute = v17;
      *(float *)&p_data[-3].m_pStorage = v18->y;
    }
    while ( v5 < m_Size - 3 );
  }
  for ( ; v5 < m_Size; *((float *)&v20 + 2 * v5 - 1) = v19->y )
  {
    v19 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5]];
    *(&v20.x + 2 * v5++) = v19->x;
  }
  CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::RemoveMultiple(
    this: &data,
    elem: m_Size,
    num: data.m_pStorage->m_Size - m_Size);
  CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::SetMultiple(
    this: &data,
    i: 0,
    nCount: m_Size,
    pValue: &v20);
}

//------------------------------------------------------------------------------
// Address: 0x004587B0
// Name: void MirrorVertexData<class Vector2D>(class CDmeVertexData __near *,int,int,int,int,class CDmrArrayConst<class Vector2D> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MirrorVertexData<Vector2D>(
        CDmeVertexData *pBase,
        int fieldIndex,
        int axis,
        int nOrigVertexCount,
        int nMirrorCount,
        const CDmrArrayConst<Vector2D> *origData,
        const CUtlVector<int,CUtlMemory<int,int> > *origIndices,
        const CUtlVector<int,CUtlMemory<int,int> > *mirrorMap,
        const CUtlVector<int,CUtlMemory<int,int> > *dataMirrorMap)
{
  const CDmrArrayConst<Vector2D> *v9; // ebx
  int m_Size; // esi
  void *v11; // esp
  void *v12; // esp
  int v13; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // eax
  Vector2D *m_pMemory; // edx
  float x; // xmm1_4
  Vector2D *v19; // ecx
  int *v20; // edx
  int v21; // edx
  int *v22; // eax
  int v23; // ecx
  int v24; // eax
  Vector2D *v25; // edx
  float v26; // xmm1_4
  Vector2D *v27; // ecx
  int *v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  Vector2D *v32; // edx
  float v33; // xmm1_4
  Vector2D *v34; // ecx
  int *v35; // edx
  int v36; // edx
  int v37; // ecx
  int *v38; // edx
  int v39; // eax
  Vector2D *v40; // ebx
  float y; // xmm1_4
  int v42; // eax
  bool v43; // cc
  int v44; // edx
  int *v45; // eax
  int *v46; // ecx
  Vector2D *v47; // ebx
  float v48; // xmm1_4
  Vector2D *v49; // ebx
  int v50; // edx
  int v51; // edi
  DmAttributeType_t v52; // ebx
  _DWORD v53[3]; // [esp+0h] [ebp-2Ch] BYREF
  Vector2D mirrorData; // [esp+Ch] [ebp-20h]
  int *v55; // [esp+14h] [ebp-18h]
  int v56; // [esp+18h] [ebp-14h]
  Vector2D *pMirrorData; // [esp+1Ch] [ebp-10h]
  int *pMirrorIndices; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  int nMirrorIndex; // [esp+28h] [ebp-4h]

  if ( nMirrorCount > 0 )
  {
    v9 = origData;
    m_Size = origData->m_pStorage->m_Size;
    v11 = alloca(8 * nMirrorCount);
    pMirrorData = (Vector2D *)v53;
    v12 = alloca(4 * nMirrorCount);
    v13 = 0;
    v14 = -1;
    pMirrorIndices = v53;
    nMirrorIndex = 0;
    i = 0;
    if ( nOrigVertexCount >= 4 )
    {
      v56 = 2;
      do
      {
        if ( mirrorMap->m_Memory.m_pMemory[v13] != v13 )
        {
          v15 = origIndices->m_Memory.m_pMemory[v13];
          v55 = &origIndices->m_Memory.m_pMemory[v13];
          v16 = dataMirrorMap->m_Memory.m_pMemory[v15];
          if ( v16 != v15 )
          {
            m_pMemory = v9->m_pStorage->m_Memory.m_pMemory;
            x = m_pMemory[v15].x;
            v19 = &m_pMemory[v15];
            v20 = v55;
            mirrorData.x = x;
            mirrorData.y = v19->y;
            *(&mirrorData.x + axis) = 0.5 - (float)(*(&mirrorData.x + axis) - 0.5);
            pMirrorData[v16 - m_Size] = mirrorData;
            v15 = dataMirrorMap->m_Memory.m_pMemory[*v20];
            if ( v15 - m_Size > v14 )
              v14 = v15 - m_Size;
          }
          v21 = nMirrorIndex++;
          v53[v21] = v15;
          v13 = i;
        }
        if ( mirrorMap->m_Memory.m_pMemory[v13 + 1] != v56 - 1 )
        {
          v22 = &origIndices->m_Memory.m_pMemory[v13 + 1];
          v23 = *v22;
          v55 = v22;
          v24 = dataMirrorMap->m_Memory.m_pMemory[v23];
          if ( v24 != v23 )
          {
            v25 = v9->m_pStorage->m_Memory.m_pMemory;
            v26 = v25[v23].x;
            v27 = &v25[v23];
            v28 = v55;
            mirrorData.x = v26;
            mirrorData.y = v27->y;
            *(&mirrorData.x + axis) = 0.5 - (float)(*(&mirrorData.x + axis) - 0.5);
            pMirrorData[v24 - m_Size] = mirrorData;
            v23 = dataMirrorMap->m_Memory.m_pMemory[*v28];
            if ( v23 - m_Size > v14 )
              v14 = v23 - m_Size;
          }
          v29 = nMirrorIndex++;
          v53[v29] = v23;
          v13 = i;
        }
        if ( mirrorMap->m_Memory.m_pMemory[v13 + 2] != v56 )
        {
          v30 = origIndices->m_Memory.m_pMemory[i + 2];
          v55 = &origIndices->m_Memory.m_pMemory[i + 2];
          v31 = dataMirrorMap->m_Memory.m_pMemory[v30];
          if ( v31 != v30 )
          {
            v32 = v9->m_pStorage->m_Memory.m_pMemory;
            v33 = v32[v30].x;
            v34 = &v32[v30];
            v35 = v55;
            mirrorData.x = v33;
            mirrorData.y = v34->y;
            *(&mirrorData.x + axis) = 0.5 - (float)(*(&mirrorData.x + axis) - 0.5);
            pMirrorData[v31 - m_Size] = mirrorData;
            v30 = dataMirrorMap->m_Memory.m_pMemory[*v35];
            if ( v30 - m_Size > v14 )
              v14 = v30 - m_Size;
          }
          v36 = nMirrorIndex++;
          v53[v36] = v30;
        }
        if ( mirrorMap->m_Memory.m_pMemory[i + 3] != v56 + 1 )
        {
          v37 = origIndices->m_Memory.m_pMemory[i + 3];
          v38 = &origIndices->m_Memory.m_pMemory[i + 3];
          v39 = dataMirrorMap->m_Memory.m_pMemory[v37];
          if ( v39 != v37 )
          {
            v40 = v9->m_pStorage->m_Memory.m_pMemory;
            mirrorData.x = v40[v37].x;
            y = v40[v37].y;
            v9 = origData;
            mirrorData.y = y;
            *(&mirrorData.x + axis) = 0.5 - (float)(*(&mirrorData.x + axis) - 0.5);
            pMirrorData[v39 - m_Size] = mirrorData;
            v37 = dataMirrorMap->m_Memory.m_pMemory[*v38];
            if ( v37 - m_Size > v14 )
              v14 = v37 - m_Size;
          }
          v42 = nMirrorIndex++;
          v53[v42] = v37;
        }
        v56 += 4;
        v43 = i + 4 < nOrigVertexCount - 3;
        i += 4;
        v13 = i;
      }
      while ( v43 );
    }
    if ( v13 < nOrigVertexCount )
    {
      v56 = (int)&v53[nMirrorIndex];
      do
      {
        if ( mirrorMap->m_Memory.m_pMemory[v13] != v13 )
        {
          v44 = origIndices->m_Memory.m_pMemory[v13];
          v45 = &origIndices->m_Memory.m_pMemory[v13];
          v46 = dataMirrorMap->m_Memory.m_pMemory;
          if ( dataMirrorMap->m_Memory.m_pMemory[v44] == v44 )
          {
            *(_DWORD *)v56 = v44;
          }
          else
          {
            v47 = v9->m_pStorage->m_Memory.m_pMemory;
            v48 = v47[v44].x;
            v49 = &v47[v44];
            v50 = v46[v44];
            mirrorData.x = v48;
            mirrorData.y = v49->y;
            *(&mirrorData.x + axis) = 0.5 - (float)(*(&mirrorData.x + axis) - 0.5);
            pMirrorData[v50 - m_Size] = mirrorData;
            if ( v46[*v45] - m_Size > v14 )
              v14 = v46[*v45] - m_Size;
            v9 = origData;
            *(_DWORD *)v56 = v46[*v45];
          }
          v56 += 4;
          v13 = i;
        }
        i = ++v13;
      }
      while ( v13 < nOrigVertexCount );
    }
    v51 = v14 + 1;
    v52 = (v9->m_pAttribute->m_nFlags & 0x1F) - 14;
    CDmeVertexDataBase::AddVertexData(this: pBase, nFieldIndex: fieldIndex, nCount: v51);
    CDmeVertexDataBase::SetVertexData(
      this: pBase,
      nFieldIndex: fieldIndex,
      nFirstVertex: m_Size,
      nCount: v51,
      valueType: v52,
      pData: pMirrorData);
    CDmeVertexDataBase::SetVertexIndices(
      this: pBase,
      nFieldIndex: fieldIndex,
      nFirstIndex: nOrigVertexCount,
      nCount: nMirrorCount,
      pIndices: pMirrorIndices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458BD0
// Name: void MirrorDeltaData<class Vector2D>(class CDmeVertexDeltaData __near *,int,int,class CDmrArrayConst<class Vector2D> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MirrorDeltaData<Vector2D>(
        CDmeVertexDeltaData *pDelta,
        int fieldIndex,
        int axis,
        const CDmrArrayConst<Vector2D> *origData,
        const CUtlVector<int,CUtlMemory<int,int> > *origIndices,
        const CUtlVector<int,CUtlMemory<int,int> > *dataMap)
{
  int v6; // edi
  void *v7; // esp
  _DWORD *v8; // ebx
  void *v9; // esp
  int v10; // esi
  int v11; // ecx
  float *v12; // eax
  int *m_pMemory; // ebx
  Vector2D *v14; // edi
  double y; // st7
  int *v16; // edi
  int *v17; // ebx
  Vector2D *v18; // edi
  double v19; // st7
  int *v20; // edi
  int *v21; // ebx
  Vector2D *v22; // edi
  double v23; // st7
  int *v24; // edi
  int *v25; // ebx
  Vector2D *v26; // edi
  double v27; // st7
  int *v28; // edi
  float *v29; // eax
  int *v30; // ebx
  Vector2D *v31; // edi
  double v32; // st7
  int *v33; // edi
  DmAttributeType_t v34; // ebx
  _DWORD v35[3]; // [esp+0h] [ebp-1Ch] BYREF
  void *pData; // [esp+Ch] [ebp-10h]
  int m_Size; // [esp+10h] [ebp-Ch]
  int *v38; // [esp+14h] [ebp-8h]
  int *pIndices; // [esp+18h] [ebp-4h]

  m_Size = origData->m_pStorage->m_Size;
  v6 = m_Size;
  v7 = alloca(8 * m_Size);
  v8 = v35;
  pData = v35;
  v9 = alloca(4 * m_Size);
  v10 = 0;
  v11 = 0;
  pIndices = v35;
  if ( m_Size >= 4 )
  {
    v12 = (float *)v35;
    do
    {
      m_pMemory = dataMap->m_Memory.m_pMemory;
      v38 = &origIndices->m_Memory.m_pMemory[v11];
      if ( m_pMemory[*v38] != *v38 )
      {
        v14 = origData->m_pStorage->m_Memory.m_pMemory;
        *v12 = v14[v11].x;
        y = v14[v11].y;
        v16 = v38;
        v12[1] = y;
        v12[axis] = 0.5 - (float)(v12[axis] - 0.5);
        v35[v10++] = m_pMemory[*v16];
        v12 += 2;
      }
      v17 = dataMap->m_Memory.m_pMemory;
      v38 = &origIndices->m_Memory.m_pMemory[v11 + 1];
      if ( v17[*v38] != *v38 )
      {
        v18 = origData->m_pStorage->m_Memory.m_pMemory;
        *v12 = v18[v11 + 1].x;
        v19 = v18[v11 + 1].y;
        v20 = v38;
        v12[1] = v19;
        v12[axis] = 0.5 - (float)(v12[axis] - 0.5);
        v35[v10++] = v17[*v20];
        v12 += 2;
      }
      v21 = dataMap->m_Memory.m_pMemory;
      v38 = &origIndices->m_Memory.m_pMemory[v11 + 2];
      if ( v21[*v38] != *v38 )
      {
        v22 = origData->m_pStorage->m_Memory.m_pMemory;
        *v12 = v22[v11 + 2].x;
        v23 = v22[v11 + 2].y;
        v24 = v38;
        v12[1] = v23;
        v12[axis] = 0.5 - (float)(v12[axis] - 0.5);
        v35[v10++] = v21[*v24];
        v12 += 2;
      }
      v25 = dataMap->m_Memory.m_pMemory;
      v38 = &origIndices->m_Memory.m_pMemory[v11 + 3];
      if ( v25[*v38] != *v38 )
      {
        v26 = origData->m_pStorage->m_Memory.m_pMemory;
        *v12 = v26[v11 + 3].x;
        v27 = v26[v11 + 3].y;
        v28 = v38;
        v12[1] = v27;
        v12[axis] = 0.5 - (float)(v12[axis] - 0.5);
        v35[v10++] = v25[*v28];
        v12 += 2;
      }
      v6 = m_Size;
      v11 += 4;
    }
    while ( v11 < m_Size - 3 );
    v8 = pData;
  }
  if ( v11 < v6 )
  {
    v29 = (float *)&v8[2 * v10];
    do
    {
      v30 = dataMap->m_Memory.m_pMemory;
      v38 = &origIndices->m_Memory.m_pMemory[v11];
      if ( v30[*v38] != *v38 )
      {
        v31 = origData->m_pStorage->m_Memory.m_pMemory;
        *v29 = v31[v11].x;
        v32 = v31[v11].y;
        v33 = v38;
        v29[1] = v32;
        v29[axis] = 0.5 - (float)(v29[axis] - 0.5);
        v35[v10++] = v30[*v33];
        v29 += 2;
      }
      v6 = m_Size;
      ++v11;
    }
    while ( v11 < m_Size );
  }
  v34 = (origData->m_pAttribute->m_nFlags & 0x1F) - 14;
  CDmeVertexDataBase::AddVertexData(this: pDelta, nFieldIndex: fieldIndex, nCount: v10);
  CDmeVertexDataBase::SetVertexData(
    this: pDelta,
    nFieldIndex: fieldIndex,
    nFirstVertex: v6,
    nCount: v10,
    valueType: v34,
    pData);
  CDmeVertexDataBase::SetVertexIndices(this: pDelta, nFieldIndex: fieldIndex, nFirstIndex: v6, nCount: v10, pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x00458ED0
// Name: void CopyFieldData<float>(class CDmrArrayConst<float> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CDmeVertexData __near *,int,class CUtlVector<struct VertexWeightMap_s,class CUtlMemory<struct VertexWeightMap_s,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyFieldData<float>(
        CDmAttribute *srcData,
        const CUtlVector<int,CUtlMemory<int,int> > *srcIndices,
        CDmeVertexData *pDstVertexData,
        int dstFieldIndex,
        const CUtlVector<VertexWeightMap_s,CUtlMemory<VertexWeightMap_s,int> > *vertexWeightMap)
{
  int v5; // edi
  void *v6; // esp
  float *v7; // eax
  VertexWeightMap_s *v8; // ecx
  bool v9; // cc
  float *p_m_vertexDataIndex; // edx
  float v11; // xmm1_4
  _DWORD *v12; // eax
  int v13; // ebx
  int v14; // edi
  float v15; // xmm0_4
  float *m_pNext; // esi
  int *m_pMemory; // edx
  _DWORD *v18; // eax
  unsigned int v19; // ecx
  _DWORD *v20; // ecx
  int v21; // eax
  int v22; // esi
  bool v23; // zf
  unsigned __int16 v24; // si
  _BYTE v25[12]; // [esp+0h] [ebp-38h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v26; // [esp+Ch] [ebp-2Ch] BYREF
  void *pData; // [esp+14h] [ebp-24h]
  int m_Size; // [esp+18h] [ebp-20h]
  int *v29; // [esp+1Ch] [ebp-1Ch]
  int v30; // [esp+20h] [ebp-18h]
  float *v31; // [esp+24h] [ebp-14h]
  float *v32; // [esp+28h] [ebp-10h]
  int v33; // [esp+2Ch] [ebp-Ch]
  VertexWeightMap_s *v34; // [esp+30h] [ebp-8h]
  unsigned int v35; // [esp+34h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+40h] [ebp+8h]

  m_Size = vertexWeightMap->m_Size;
  v5 = m_Size;
  v6 = alloca(4 * m_Size);
  v7 = (float *)v25;
  pData = v25;
  if ( m_Size > 0 )
  {
    v35 = 0;
    v31 = (float *)v25;
    v30 = m_Size;
    do
    {
      *v7 = 0.0;
      v8 = &vertexWeightMap->m_Memory.m_pMemory[v35 / 0x40];
      v33 = 0;
      v9 = v8->m_nVertexWeights <= 0;
      v34 = v8;
      if ( !v9 )
      {
        p_m_vertexDataIndex = (float *)&v8->m_vertexWeights[0].m_vertexDataIndex;
        v11 = 0.0;
        v32 = (float *)&v8->m_vertexWeights[0].m_vertexDataIndex;
        do
        {
          v12 = *((_DWORD **)p_m_vertexDataIndex + 1);
          v13 = v12[3];
          v14 = 0;
          v15 = 0.0;
          v29 = (int *)v13;
          if ( v13 >= 4 )
          {
            v18 = (_DWORD *)(*v12 + 8);
            v19 = ((unsigned int)(v13 - 4) >> 2) + 1;
            v14 = 4 * v19;
            do
            {
              m_pNext = (float *)srcData->m_pNext->m_pNext;
              m_pMemory = srcIndices->m_Memory.m_pMemory;
              v15 = (float)((float)((float)(v15 + m_pNext[m_pMemory[*(v18 - 2)]]) + m_pNext[m_pMemory[*(v18 - 1)]])
                          + m_pNext[m_pMemory[*v18]])
                  + m_pNext[m_pMemory[v18[1]]];
              v18 += 4;
              --v19;
            }
            while ( v19 != 0 );
            v8 = v34;
            v13 = (int)v29;
            p_m_vertexDataIndex = v32;
          }
          if ( v14 < v13 )
          {
            v29 = srcIndices->m_Memory.m_pMemory;
            v32 = (float *)srcData->m_pNext->m_pNext;
            v20 = (_DWORD *)(**((_DWORD **)p_m_vertexDataIndex + 1) + 4 * v14);
            v21 = v13 - v14;
            do
            {
              v15 = v15 + v32[v29[*v20++]];
              --v21;
            }
            while ( v21 != 0 );
            v8 = v34;
          }
          v7 = v31;
          v22 = v33 + 1;
          v11 = (float)((float)(v15 / (float)v13) * p_m_vertexDataIndex[2]) + v11;
          p_m_vertexDataIndex += 3;
          *v31 = v11;
          v33 = v22;
          v32 = p_m_vertexDataIndex;
        }
        while ( v22 < v8->m_nVertexWeights );
        v5 = m_Size;
      }
      v35 += 64;
      ++v7;
      v23 = v30-- == 1;
      v31 = v7;
    }
    while ( !v23 );
  }
  v24 = *((_WORD *)srcData->m_pData + 8);
  pAttribute = pDstVertexData->m_FieldInfo.m_Memory.m_pMemory[dstFieldIndex].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v26);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v26,
    pAttribute);
  CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::EnsureCount(
    this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v26,
    num: v5);
  CDmeVertexDataBase::SetVertexData(
    this: pDstVertexData,
    nFieldIndex: dstFieldIndex,
    nFirstVertex: 0,
    nCount: v5,
    valueType: (DmAttributeType_t)((v24 & 0x1F) - 14),
    pData);
}

//------------------------------------------------------------------------------
// Address: 0x00459080
// Name: void CopyFieldData<class Vector2D>(class CDmrArrayConst<class Vector2D> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CDmeVertexData __near *,int,class CUtlVector<struct VertexWeightMap_s,class CUtlMemory<struct VertexWeightMap_s,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyFieldData<Vector2D>(
        CDmAttribute *srcData,
        const CUtlVector<int,CUtlMemory<int,int> > *srcIndices,
        CDmeVertexData *pDstVertexData,
        int dstFieldIndex,
        const CUtlVector<VertexWeightMap_s,CUtlMemory<VertexWeightMap_s,int> > *vertexWeightMap)
{
  int v5; // ebx
  void *v6; // esp
  float *v7; // ecx
  VertexWeightMap_s *v8; // edx
  bool v9; // cc
  VertexWeightMap_s::VertexWeight_s *m_vertexWeights; // eax
  float v11; // xmm4_4
  float v12; // xmm5_4
  const CUtlVector<int,CUtlMemory<int,int> > *m_pVertexIndices; // edi
  int v14; // esi
  int v15; // ebx
  float v16; // xmm2_4
  float v17; // xmm0_4
  int *m_pMemory; // ecx
  Vector2D *m_pNext; // edx
  _DWORD *v20; // eax
  unsigned int v21; // esi
  int v22; // edi
  float v23; // xmm1_4
  float y; // xmm2_4
  int v25; // edi
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float *p_x; // edi
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  int v33; // edi
  int *v34; // edi
  int *v35; // eax
  int *v36; // edx
  int v37; // ecx
  int v38; // eax
  float v39; // xmm1_4
  int v40; // esi
  bool v41; // zf
  DmAttributeType_t v42; // esi
  _BYTE v43[12]; // [esp+0h] [ebp-38h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v44; // [esp+Ch] [ebp-2Ch] BYREF
  void *pData; // [esp+14h] [ebp-24h]
  int m_Size; // [esp+18h] [ebp-20h]
  Vector2D *v47; // [esp+1Ch] [ebp-1Ch]
  int v48; // [esp+20h] [ebp-18h]
  int v49; // [esp+24h] [ebp-14h]
  VertexWeightMap_s *v50; // [esp+28h] [ebp-10h]
  float *v51; // [esp+2Ch] [ebp-Ch]
  unsigned int v52; // [esp+30h] [ebp-8h]
  VertexWeightMap_s::VertexWeight_s *v53; // [esp+34h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+40h] [ebp+8h]

  m_Size = vertexWeightMap->m_Size;
  v5 = m_Size;
  v6 = alloca(8 * m_Size);
  v7 = (float *)v43;
  pData = v43;
  if ( m_Size > 0 )
  {
    v52 = 0;
    v51 = (float *)v43;
    v48 = m_Size;
    do
    {
      *v7 = 0.0;
      v7[1] = 0.0;
      v8 = &vertexWeightMap->m_Memory.m_pMemory[v52 / 0x40];
      v49 = 0;
      v9 = v8->m_nVertexWeights <= 0;
      v50 = v8;
      if ( !v9 )
      {
        m_vertexWeights = v8->m_vertexWeights;
        v11 = 0.0;
        v12 = 0.0;
        v53 = v8->m_vertexWeights;
        do
        {
          m_pVertexIndices = m_vertexWeights->m_pVertexIndices;
          v14 = m_pVertexIndices->m_Size;
          v15 = 0;
          v16 = 0.0;
          v17 = 0.0;
          v47 = (Vector2D *)v14;
          if ( v14 >= 4 )
          {
            m_pMemory = srcIndices->m_Memory.m_pMemory;
            m_pNext = (Vector2D *)srcData->m_pNext->m_pNext;
            v20 = m_pVertexIndices->m_Memory.m_pMemory + 2;
            v21 = ((unsigned int)(v14 - 4) >> 2) + 1;
            v15 = 4 * v21;
            do
            {
              v22 = m_pMemory[*(v20 - 2)];
              v23 = m_pNext[v22].x + v16;
              y = m_pNext[v22].y;
              v25 = m_pMemory[*(v20 - 1)];
              v26 = y + v17;
              v27 = m_pNext[v25].x + v23;
              v28 = m_pNext[v25].y;
              p_x = &m_pNext[m_pMemory[*v20]].x;
              v30 = v28 + v26;
              v31 = *p_x + v27;
              v32 = p_x[1];
              v33 = m_pMemory[v20[1]];
              v16 = v31 + m_pNext[v33].x;
              v20 += 4;
              --v21;
              v17 = (float)(v32 + v30) + m_pNext[v33].y;
            }
            while ( v21 != 0 );
            v14 = (int)v47;
            v7 = v51;
            m_vertexWeights = v53;
            v8 = v50;
          }
          if ( v15 < v14 )
          {
            v34 = srcIndices->m_Memory.m_pMemory;
            v35 = m_vertexWeights->m_pVertexIndices->m_Memory.m_pMemory;
            v47 = (Vector2D *)srcData->m_pNext->m_pNext;
            v36 = &v35[v15];
            v37 = v14 - v15;
            do
            {
              v38 = v34[*v36];
              v16 = v16 + v47[v38].x;
              v17 = v17 + v47[v38].y;
              ++v36;
              --v37;
            }
            while ( v37 != 0 );
            v7 = v51;
            m_vertexWeights = v53;
            v8 = v50;
          }
          v39 = 1.0 / (float)v14;
          v40 = v49 + 1;
          v11 = v11 + (float)(m_vertexWeights->m_vertexWeight * (float)(v39 * v16));
          v12 = v12 + (float)((float)(v17 * v39) * m_vertexWeights->m_vertexWeight);
          ++m_vertexWeights;
          *v7 = v11;
          v7[1] = v12;
          v49 = v40;
          v53 = m_vertexWeights;
        }
        while ( v40 < v8->m_nVertexWeights );
        v5 = m_Size;
      }
      v52 += 64;
      v7 += 2;
      v41 = v48-- == 1;
      v51 = v7;
    }
    while ( !v41 );
  }
  v42 = (*((_WORD *)srcData->m_pData + 8) & 0x1F) - 14;
  pAttribute = pDstVertexData->m_FieldInfo.m_Memory.m_pMemory[dstFieldIndex].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v44);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v44,
    pAttribute);
  CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::EnsureCount(
    this: (CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > *)&v44,
    num: v5);
  CDmeVertexDataBase::SetVertexData(
    this: pDstVertexData,
    nFieldIndex: dstFieldIndex,
    nFirstVertex: 0,
    nCount: v5,
    valueType: v42,
    pData);
}

//------------------------------------------------------------------------------
// Address: 0x004592B0
// Name: void CopyFieldData<class Vector>(class CDmrArrayConst<class Vector> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CDmeVertexData __near *,int,class CUtlVector<struct VertexWeightMap_s,class CUtlMemory<struct VertexWeightMap_s,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyFieldData<Vector>(
        CDmAttribute *srcData,
        const CUtlVector<int,CUtlMemory<int,int> > *srcIndices,
        CDmeVertexData *pDstVertexData,
        int dstFieldIndex,
        const CUtlVector<VertexWeightMap_s,CUtlMemory<VertexWeightMap_s,int> > *vertexWeightMap)
{
  int v5; // edi
  void *v6; // esp
  float *v7; // eax
  float v8; // xmm0_4
  VertexWeightMap_s *v9; // edx
  bool v10; // cc
  VertexWeightMap_s::VertexWeight_s *m_vertexWeights; // ecx
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  const CUtlVector<int,CUtlMemory<int,int> > *m_pVertexIndices; // esi
  int v16; // edi
  int v17; // ebx
  float v18; // xmm3_4
  float v19; // xmm1_4
  int *m_pMemory; // ecx
  Vector *m_pNext; // edx
  _DWORD *v22; // eax
  unsigned int v23; // edi
  float *p_x; // esi
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float *v28; // esi
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float *v33; // esi
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float *v38; // esi
  float v39; // xmm2_4
  int *v40; // esi
  Vector *v41; // edi
  int *v42; // edx
  int v43; // ecx
  float v44; // xmm2_4
  float v45; // xmm4_4
  float m_vertexWeight; // xmm3_4
  int v47; // esi
  bool v48; // zf
  DmAttributeType_t v49; // esi
  int v50; // [esp+0h] [ebp-38h] BYREF
  int v51; // [esp+8h] [ebp-30h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v52; // [esp+Ch] [ebp-2Ch] BYREF
  void *pData; // [esp+14h] [ebp-24h]
  int m_Size; // [esp+18h] [ebp-20h]
  int v55; // [esp+1Ch] [ebp-1Ch]
  int v56; // [esp+20h] [ebp-18h]
  VertexWeightMap_s *v57; // [esp+24h] [ebp-14h]
  float *v58; // [esp+28h] [ebp-10h]
  unsigned int v59; // [esp+2Ch] [ebp-Ch]
  VertexWeightMap_s::VertexWeight_s *v60; // [esp+30h] [ebp-8h]
  int v61; // [esp+34h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+40h] [ebp+8h]

  m_Size = vertexWeightMap->m_Size;
  v5 = m_Size;
  v6 = alloca(12 * m_Size);
  pData = &v50;
  if ( m_Size > 0 )
  {
    v7 = (float *)&v51;
    v59 = 0;
    v58 = (float *)&v51;
    v55 = m_Size;
    do
    {
      v8 = 0.0;
      *(v7 - 2) = 0.0;
      *(v7 - 1) = 0.0;
      *v7 = 0.0;
      v9 = &vertexWeightMap->m_Memory.m_pMemory[v59 / 0x40];
      v56 = 0;
      v10 = v9->m_nVertexWeights <= 0;
      v57 = v9;
      if ( !v10 )
      {
        m_vertexWeights = v9->m_vertexWeights;
        v12 = 0.0;
        v13 = 0.0;
        v14 = 0.0;
        v60 = v9->m_vertexWeights;
        while ( 1 )
        {
          m_pVertexIndices = m_vertexWeights->m_pVertexIndices;
          v16 = m_pVertexIndices->m_Size;
          v17 = 0;
          v18 = 0.0;
          v19 = 0.0;
          v61 = v16;
          if ( v16 >= 4 )
          {
            m_pMemory = srcIndices->m_Memory.m_pMemory;
            m_pNext = (Vector *)srcData->m_pNext->m_pNext;
            v22 = m_pVertexIndices->m_Memory.m_pMemory + 2;
            v23 = ((unsigned int)(v16 - 4) >> 2) + 1;
            v17 = 4 * v23;
            do
            {
              p_x = &m_pNext[m_pMemory[*(v22 - 2)]].x;
              v25 = *p_x + v18;
              v26 = p_x[1] + v8;
              v27 = p_x[2];
              v28 = &m_pNext[m_pMemory[*(v22 - 1)]].x;
              v29 = v27 + v19;
              v30 = *v28 + v25;
              v31 = v28[1] + v26;
              v32 = v28[2];
              v33 = &m_pNext[m_pMemory[*v22]].x;
              v34 = v32 + v29;
              v35 = *v33 + v30;
              v36 = v33[1] + v31;
              v37 = v33[2];
              v38 = &m_pNext[m_pMemory[v22[1]]].x;
              v39 = v37 + v34;
              v18 = *v38 + v35;
              v8 = v38[1] + v36;
              v22 += 4;
              --v23;
              v19 = v38[2] + v39;
            }
            while ( v23 != 0 );
            v9 = v57;
            v16 = v61;
            m_vertexWeights = v60;
            v7 = v58;
          }
          if ( v17 < v16 )
          {
            v40 = srcIndices->m_Memory.m_pMemory;
            v41 = (Vector *)srcData->m_pNext->m_pNext;
            v42 = &m_vertexWeights->m_pVertexIndices->m_Memory.m_pMemory[v17];
            v43 = v61 - v17;
            do
            {
              v18 = v18 + v41[v40[*v42]].x;
              v8 = v8 + v41[v40[*v42]].y;
              v19 = v19 + v41[v40[*v42++]].z;
              --v43;
            }
            while ( v43 != 0 );
            v9 = v57;
            v16 = v61;
            m_vertexWeights = v60;
            v7 = v58;
          }
          v44 = 1.0 / (float)v16;
          v45 = v44 * v18;
          m_vertexWeight = m_vertexWeights->m_vertexWeight;
          v47 = v56 + 1;
          v12 = v12 + (float)(m_vertexWeight * v45);
          v13 = v13 + (float)((float)(v8 * v44) * m_vertexWeight);
          v14 = (float)((float)(v19 * v44) * m_vertexWeight) + v14;
          ++m_vertexWeights;
          *(v7 - 2) = v12;
          *(v7 - 1) = v13;
          *v7 = v14;
          v56 = v47;
          v60 = m_vertexWeights;
          if ( v47 >= v9->m_nVertexWeights )
            break;
          v8 = 0.0;
        }
        v5 = m_Size;
      }
      v59 += 64;
      v7 += 3;
      v48 = v55-- == 1;
      v58 = v7;
    }
    while ( !v48 );
  }
  v49 = (*((_WORD *)srcData->m_pData + 8) & 0x1F) - 14;
  pAttribute = pDstVertexData->m_FieldInfo.m_Memory.m_pMemory[dstFieldIndex].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v52);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v52,
    pAttribute);
  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::EnsureCount(
    this: (CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *)&v52,
    num: v5);
  CDmeVertexDataBase::SetVertexData(
    this: pDstVertexData,
    nFieldIndex: dstFieldIndex,
    nFirstVertex: 0,
    nCount: v5,
    valueType: v49,
    pData);
}

//------------------------------------------------------------------------------
// Address: 0x004595B0
// Name: protected: static bool CDmMeshUtils::MirrorVertices(class CDmeVertexData __near *,int,int,int,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::MirrorVertices(
        CDmeVertexData *pBase,
        unsigned int axis,
        int nOldVertexCount,
        int nMirrorCount,
        const CUtlVector<int,CUtlMemory<int,int> > *mirrorMap,
        const CUtlVector<int,CUtlMemory<int,int> > *posMirrorMap,
        const CUtlVector<int,CUtlMemory<int,int> > *normalMirrorMap,
        const CUtlVector<int,CUtlMemory<int,int> > *uvMirrorMap)
{
  int v9; // edi
  int v10; // edx
  int v11; // eax
  CDmAttribute *m_pVertexData; // ebx
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndexData; // eax
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v15; // [esp+8h] [ebp-2Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v16; // [esp+10h] [ebp-24h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v17; // [esp+18h] [ebp-1Ch] BYREF
  int nFields; // [esp+20h] [ebp-14h]
  int uvFieldIndex; // [esp+24h] [ebp-10h]
  int normalFieldIndex; // [esp+28h] [ebp-Ch]
  int posFieldIndex; // [esp+2Ch] [ebp-8h]
  unsigned int v22; // [esp+30h] [ebp-4h]
  const CUtlVector<int,CUtlMemory<int,int> > *baseIndices; // [esp+3Ch] [ebp+8h]

  v9 = 0;
  if ( pBase == nullptr || axis > 2 )
    return 0;
  CDmeVertexData::AddVertexIndices(this: pBase, nIndexCount: nMirrorCount);
  v10 = pBase->m_pStandardFieldIndex[1];
  v11 = pBase->m_pStandardFieldIndex[3];
  posFieldIndex = pBase->m_pStandardFieldIndex[0];
  normalFieldIndex = v10;
  uvFieldIndex = v11;
  nFields = CDmeTrack::GetClipCount(this: pBase);
  if ( nFields > 0 )
  {
    v22 = 0;
    do
    {
      m_pVertexData = pBase->m_FieldInfo.m_Memory.m_pMemory[v22 / 0x30].m_pVertexData;
      VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this: pBase, nFieldIndex: v9);
      baseIndices = VertexIndexData;
      if ( (m_pVertexData->m_nFlags & 0x1F) == 0x17 )
      {
        if ( v9 != uvFieldIndex )
        {
LABEL_13:
          CDmMeshUtils::MirrorVertices(
            pBase,
            fieldIndex: v9,
            nOldVertexCount,
            nMirrorCount,
            baseIndices: VertexIndexData,
            mirrorMap);
          goto LABEL_14;
        }
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v15);
        CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
          this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v15,
          pAttribute: m_pVertexData);
        MirrorVertexData<Vector2D>(
          pBase,
          fieldIndex: v9,
          axis: axis & 0x80000001,
          nOrigVertexCount: nOldVertexCount,
          nMirrorCount,
          origData: (const CDmrArrayConst<Vector2D> *)&v15,
          origIndices: baseIndices,
          mirrorMap,
          dataMirrorMap: uvMirrorMap);
      }
      else
      {
        if ( (m_pVertexData->m_nFlags & 0x1F) != 0x18 )
          goto LABEL_13;
        if ( v9 == posFieldIndex )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v17);
          CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
            this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v17,
            pAttribute: m_pVertexData);
          MirrorVertexData<Vector>(
            pBase,
            fieldIndex: v9,
            axis,
            nOrigVertexCount: nOldVertexCount,
            nMirrorCount,
            origData: (const CDmrArrayConst<Vector> *)&v17,
            origIndices: baseIndices,
            mirrorMap,
            dataMirrorMap: posMirrorMap);
        }
        else
        {
          if ( v9 != normalFieldIndex )
            goto LABEL_13;
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v16);
          CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
            this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v16,
            pAttribute: m_pVertexData);
          MirrorVertexData<Vector>(
            pBase,
            fieldIndex: v9,
            axis,
            nOrigVertexCount: nOldVertexCount,
            nMirrorCount,
            origData: (const CDmrArrayConst<Vector> *)&v16,
            origIndices: baseIndices,
            mirrorMap,
            dataMirrorMap: normalMirrorMap);
        }
      }
LABEL_14:
      v22 += 48;
      ++v9;
    }
    while ( v9 < nFields );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00459740
// Name: protected: static bool CDmMeshUtils::MirrorDelta(class CDmeVertexDeltaData __near *,int,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::MirrorDelta(
        CDmeVertexDeltaData *pDelta,
        unsigned int axis,
        const CUtlVector<int,CUtlMemory<int,int> > *posMirrorMap,
        const CUtlVector<int,CUtlMemory<int,int> > *normalMirrorMap,
        const CUtlVector<int,CUtlMemory<int,int> > *uvMirrorMap)
{
  int v6; // esi
  int v7; // eax
  int v8; // edx
  CDmAttribute *m_pVertexData; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v11; // [esp+8h] [ebp-2Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v12; // [esp+10h] [ebp-24h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v13; // [esp+18h] [ebp-1Ch] BYREF
  int nFields; // [esp+20h] [ebp-14h]
  int uvFieldIndex; // [esp+24h] [ebp-10h]
  int normalFieldIndex; // [esp+28h] [ebp-Ch]
  int posFieldIndex; // [esp+2Ch] [ebp-8h]
  unsigned int v18; // [esp+30h] [ebp-4h]
  const CUtlVector<int,CUtlMemory<int,int> > *deltaIndices; // [esp+3Ch] [ebp+8h]

  v6 = 0;
  if ( pDelta == nullptr || axis > 2 )
    return 0;
  v7 = pDelta->m_pStandardFieldIndex[0];
  v8 = pDelta->m_pStandardFieldIndex[3];
  normalFieldIndex = pDelta->m_pStandardFieldIndex[1];
  posFieldIndex = v7;
  uvFieldIndex = v8;
  nFields = CDmeTrack::GetClipCount(this: pDelta);
  if ( nFields > 0 )
  {
    v18 = 0;
    do
    {
      m_pVertexData = pDelta->m_FieldInfo.m_Memory.m_pMemory[v18 / 0x30].m_pVertexData;
      deltaIndices = CDmeVertexDataBase::GetVertexIndexData(this: pDelta, nFieldIndex: v6);
      if ( (m_pVertexData->m_nFlags & 0x1F) == 0x17 )
      {
        if ( v6 == uvFieldIndex )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v11);
          CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
            this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v11,
            pAttribute: m_pVertexData);
          MirrorDeltaData<Vector2D>(
            pDelta,
            fieldIndex: v6,
            axis: axis & 0x80000001,
            origData: (const CDmrArrayConst<Vector2D> *)&v11,
            origIndices: deltaIndices,
            dataMap: uvMirrorMap);
        }
      }
      else if ( (m_pVertexData->m_nFlags & 0x1F) == 0x18 )
      {
        if ( v6 == posFieldIndex )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v13);
          CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
            this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v13,
            pAttribute: m_pVertexData);
          MirrorDeltaData<Vector>(
            pDelta,
            fieldIndex: v6,
            axis,
            origData: (const CDmrArrayConst<Vector> *)&v13,
            origIndices: deltaIndices,
            dataMap: posMirrorMap);
        }
        else if ( v6 == normalFieldIndex )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v12);
          CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
            this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v12,
            pAttribute: m_pVertexData);
          MirrorDeltaData<Vector>(
            pDelta,
            fieldIndex: v6,
            axis,
            origData: (const CDmrArrayConst<Vector> *)&v12,
            origIndices: deltaIndices,
            dataMap: normalMirrorMap);
        }
      }
      v18 += 48;
      ++v6;
    }
    while ( v6 < nFields );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00459880
// Name: bool CopyField(enum CDmeVertexDataBase::StandardFields_t,class CDmeVertexData __near *,class CDmeVertexData __near *,class CUtlVector<struct VertexWeightMap_s,class CUtlMemory<struct VertexWeightMap_s,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CopyField(
        CDmeVertexDataBase::StandardFields_t field,
        CDmeVertexData *pSrcData,
        CDmeVertexData *pDstData,
        const CUtlVector<VertexWeightMap_s,CUtlMemory<VertexWeightMap_s,int> > *vertexWeightMap)
{
  int v4; // ebx
  int v6; // esi
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *VertexIndexData; // ebx
  CDmAttribute *m_pAttribute; // ebx
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+4h] [ebp-20h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v10; // [esp+Ch] [ebp-18h] BYREF
  CDmrArray<int> dstIndices; // [esp+14h] [ebp-10h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v12; // [esp+1Ch] [ebp-8h] BYREF
  CDmAttribute *fielda; // [esp+2Ch] [ebp+8h]
  const CUtlVector<int,CUtlMemory<int,int> > *srcIndices; // [esp+30h] [ebp+Ch]

  v4 = pSrcData->m_pStandardFieldIndex[field];
  if ( v4 < 0 )
    return 0;
  v6 = CDmeVertexDataBase::CreateField(this: pDstData, fieldId: field);
  if ( v6 < 0 )
    return 0;
  v12.m_pAttribute = pSrcData->m_FieldInfo.m_Memory.m_pMemory[v4].m_pVertexData;
  srcIndices = CDmeVertexDataBase::GetVertexIndexData(this: pSrcData, nFieldIndex: v4);
  VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this: pDstData, fieldId: FIELD_POSITION);
  fielda = pDstData->m_FieldInfo.m_Memory.m_pMemory[v6].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&dstIndices);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&dstIndices,
    pAttribute: fielda);
  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
    this: &dstIndices,
    num: VertexIndexData->m_Size);
  CDmeVertexDataBase::SetVertexIndices(
    this: pDstData,
    nFieldIndex: v6,
    nFirstIndex: 0,
    nCount: VertexIndexData->m_Size,
    pIndices: &VertexIndexData->m_Memory.m_pMemory->m_tms);
  m_pAttribute = v12.m_pAttribute;
  switch ( v12.m_pAttribute->m_nFlags & 0x1F )
  {
    case 17:
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v9,
        pAttribute: m_pAttribute);
      CopyFieldData<float>(
        srcData: (CDmAttribute *)&v9,
        srcIndices,
        pDstVertexData: pDstData,
        dstFieldIndex: v6,
        vertexWeightMap);
      break;
    case 23:
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v10);
      CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
        this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v10,
        pAttribute: m_pAttribute);
      CopyFieldData<Vector2D>(
        srcData: (CDmAttribute *)&v10,
        srcIndices,
        pDstVertexData: pDstData,
        dstFieldIndex: v6,
        vertexWeightMap);
      return 1;
    case 24:
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v12);
      CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
        this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v12,
        pAttribute: m_pAttribute);
      CopyFieldData<Vector>(
        srcData: (CDmAttribute *)&v12,
        srcIndices,
        pDstVertexData: pDstData,
        dstFieldIndex: v6,
        vertexWeightMap);
      return 1;
    default:
      break;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004599D0
// Name: public: static bool CDmMeshUtils::CreateWrinkleDeltaFromBaseState(class CDmeVertexDeltaData __near *,float,enum CDmMeshUtils::WrinkleOp,class CDmeMesh __near *,class CDmeVertexData __near *,class CDmeVertexData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CDmMeshUtils::CreateWrinkleDeltaFromBaseState@<al>(
        float *a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CExpressionCalculator *pDelta,
        float flScale,
        CDmMeshUtils::WrinkleOp wrinkleOp,
        CDmeMesh *pPassedMesh,
        CDmeVertexData *pPassedBind,
        CDmeVertexData *pPassedCurrent,
        bool bUseNormalForSign)
{
  CDmeVertexData *BindBaseState; // esi
  CDmeVertexData *CurrentBaseState; // eax
  CUtlSymbolLarge *v12; // eax
  CUtlSymbolLarge *v13; // eax
  CUtlSymbolLarge *v14; // eax
  CUtlSymbolLarge *v15; // eax
  CDmeMesh *v16; // eax
  int v17; // eax
  CDmAttribute *m_Size; // ecx
  int v19; // edi
  CDmAttribute *v20; // esi
  int m_nAllocationCount; // eax
  int v22; // edi
  CDmAttribute *v23; // esi
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndexData; // esi
  int v25; // edi
  void *v26; // esp
  float v27; // edx
  _DWORD *v28; // ecx
  int v29; // eax
  bool result; // al
  void *v31; // esp
  void *v32; // esp
  CDmeVertexDataBase *v33; // edi
  int *v34; // esi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *NormalData; // eax
  Vector *m_pMemory; // edx
  const char *m_pAsString; // eax
  int v38; // esi
  int v39; // edi
  float v40; // edx
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  __int128 v44; // xmm0
  float v45; // xmm1_4
  float v46; // xmm2_4
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndicesFromDataIndex; // edi
  int v48; // eax
  int v49; // esi
  _DWORD *v50; // ecx
  double v51; // st7
  float v52; // xmm0_4
  _DWORD *v53; // eax
  CDmAttribute *m_pAttribute; // eax
  int v55; // ecx
  int v56; // esi
  void *v57; // esp
  float v58; // esi
  int v59; // edi
  _BYTE *v60; // eax
  int v61; // esi
  bool v62; // zf
  int v63; // [esp-94h] [ebp-A0h]
  _DWORD v64[4]; // [esp-90h] [ebp-9Ch] BYREF
  __int128 v65; // [esp-80h] [ebp-8Ch] BYREF
  Vector v66; // [esp-6Ch] [ebp-78h] BYREF
  CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > v67; // [esp-60h] [ebp-6Ch] BYREF
  double v68; // [esp-58h] [ebp-64h] BYREF
  CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > v69; // [esp-50h] [ebp-5Ch] BYREF
  int v70; // [esp-48h] [ebp-54h] BYREF
  const CUtlVector<int,CUtlMemory<int,int> > *v71; // [esp-44h] [ebp-50h] BYREF
  CDmAttribute *m_pVertexData; // [esp-40h] [ebp-4Ch]
  CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > v73; // [esp-3Ch] [ebp-48h] BYREF
  _DWORD *p_x; // [esp-34h] [ebp-40h]
  int v75; // [esp-30h] [ebp-3Ch] BYREF
  float v76; // [esp-2Ch] [ebp-38h] BYREF
  CDmeMesh *v77; // [esp-28h] [ebp-34h]
  float v78; // [esp-24h] [ebp-30h]
  CDmeMesh *Referring; // [esp-20h] [ebp-2Ch]
  CDmeMesh *v80; // [esp-1Ch] [ebp-28h]
  int Field; // [esp-18h] [ebp-24h]
  CDmAttribute *v82; // [esp-14h] [ebp-20h]
  int v83; // [esp-10h] [ebp-1Ch]
  _DWORD *v84; // [esp-Ch] [ebp-18h]
  CDmeVertexData *v85; // [esp-8h] [ebp-14h]
  CExpressionCalculator *v86; // [esp-4h] [ebp-10h]
  float *pOldWrinkleData; // [esp+0h] [ebp-Ch]
  CDmeVertexData *pBind; // [esp+4h] [ebp-8h]
  CDmeVertexData *retaddr; // [esp+Ch] [ebp+0h]

  pOldWrinkleData = a1;
  pBind = retaddr;
  v64[1] = a3;
  v64[0] = a2;
  if ( pPassedBind != nullptr )
  {
    v85 = pPassedBind;
    BindBaseState = pPassedBind;
  }
  else if ( pPassedMesh != nullptr )
  {
    BindBaseState = CDmeMesh::GetBindBaseState(this: pPassedMesh);
    v85 = BindBaseState;
  }
  else
  {
    v85 = nullptr;
    BindBaseState = nullptr;
  }
  CurrentBaseState = pPassedCurrent;
  if ( pPassedCurrent == nullptr )
  {
    if ( pPassedMesh == nullptr )
    {
      v86 = nullptr;
      goto LABEL_14;
    }
    CurrentBaseState = CDmeMesh::GetCurrentBaseState(this: pPassedMesh);
  }
  v86 = (CExpressionCalculator *)CurrentBaseState;
  if ( pPassedMesh != nullptr )
  {
    Referring = pPassedMesh;
    goto LABEL_11;
  }
LABEL_14:
  if ( BindBaseState == nullptr )
  {
    Referring = nullptr;
    goto LABEL_17;
  }
  v13 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &v71, a3: "baseStates");
  Referring = FindReferringElement<CDmeMesh>(
                pElement: (CExpressionCalculator *)BindBaseState,
                symAttrName: (CUtlSymbolLarge)v13->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
LABEL_11:
  if ( BindBaseState != nullptr )
  {
    v12 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &v71, a3: "baseStates");
    v76 = COERCE_FLOAT(
            FindReferringElement<CDmeMesh>(
              pElement: (CExpressionCalculator *)BindBaseState,
              symAttrName: (CUtlSymbolLarge)v12->u.m_Id,
              bMustBeInSameFile: true,
              depth: TD_ALL));
    goto LABEL_18;
  }
LABEL_17:
  v76 = 0.0;
LABEL_18:
  if ( v86 != nullptr )
  {
    v14 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &v71, a3: "baseStates");
    v77 = FindReferringElement<CDmeMesh>(
            pElement: v86,
            symAttrName: (CUtlSymbolLarge)v14->u.m_Id,
            bMustBeInSameFile: false,
            depth: TD_ALL);
  }
  else
  {
    v77 = nullptr;
  }
  if ( pDelta == nullptr )
    return false;
  v15 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &v70, a3: "deltaStates");
  v16 = FindReferringElement<CDmeMesh>(
          pElement: pDelta,
          symAttrName: (CUtlSymbolLarge)v15->u.m_Id,
          bMustBeInSameFile: true,
          depth: TD_ALL);
  v80 = v16;
  if ( BindBaseState == nullptr )
    return false;
  if ( v86 == nullptr )
    return false;
  if ( BindBaseState == (CDmeVertexData *)v86 )
    return false;
  if ( Referring == nullptr )
    return false;
  if ( Referring != (CDmeMesh *)LODWORD(v76) )
    return false;
  if ( Referring != v77 )
    return false;
  if ( Referring != v16 )
    return false;
  v17 = BindBaseState->m_pStandardFieldIndex[0];
  m_Size = (CDmAttribute *)v86[1].m_varValues.m_Size;
  v19 = BindBaseState->m_pStandardFieldIndex[3];
  v73.m_pAttribute = m_Size;
  if ( v17 < 0 )
    return false;
  if ( v19 < 0 )
    return false;
  if ( (int)m_Size < 0 )
    return false;
  m_pVertexData = BindBaseState->m_FieldInfo.m_Memory.m_pMemory[v17].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v68);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v68,
    pAttribute: m_pVertexData);
  m_pVertexData = *(CDmAttribute **)(v86[1].m_varNames.m_Size + 48 * (int)v73.m_pAttribute + 16);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v69);
  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
    this: &v69,
    pAttribute: m_pVertexData);
  m_pVertexData = (CDmAttribute *)CDmeVertexDataBase::GetVertexIndexData(this: BindBaseState, nFieldIndex: v19);
  v86 = *(CExpressionCalculator **)(LODWORD(v68) + 12);
  if ( v86 != (CExpressionCalculator *)v69.m_pStorage->m_Size )
    return false;
  v20 = BindBaseState->m_FieldInfo.m_Memory.m_pMemory[v19].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v67);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: &v67,
    pAttribute: v20);
  m_nAllocationCount = pDelta[2].m_expr.m_Storage.m_Memory.m_nAllocationCount;
  v22 = v67.m_pStorage->m_Size;
  v71 = (const CUtlVector<int,CUtlMemory<int,int> > *)v22;
  Field = m_nAllocationCount;
  if ( m_nAllocationCount < 0 )
    Field = CDmeVertexDataBase::CreateField(this: (CDmeVertexDataBase *)pDelta, fieldId: FIELD_WRINKLE);
  v84 = nullptr;
  if ( wrinkleOp == kAdd )
  {
    v23 = *(CDmAttribute **)(pDelta[1].m_varNames.m_Size + 48 * Field + 16);
    if ( v23 != nullptr )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v73);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: &v73,
        pAttribute: v23);
      if ( v73.m_pStorage->m_Size != 0 )
      {
        VertexIndexData = CDmeVertexDataBase::GetVertexIndexData(this: (CDmeVertexDataBase *)pDelta, nFieldIndex: Field);
        v25 = 4 * v22;
        v26 = alloca(v25);
        v84 = v64;
        memset(dst: (unsigned __int8 *)v64, value: 0, count: v25);
        v27 = *(float *)&VertexIndexData->m_Size;
        v28 = v84;
        v29 = 0;
        v76 = v27;
        if ( SLODWORD(v27) >= 4 )
        {
          v83 = 2;
          do
          {
            if ( v29 < (int)v86 )
              *(float *)&v28[VertexIndexData->m_Memory.m_pMemory[v29]] = v73.m_pStorage->m_Memory.m_pMemory[v29];
            if ( v83 - 1 < (int)v86 )
              *(float *)&v28[VertexIndexData->m_Memory.m_pMemory[v29 + 1]] = v73.m_pStorage->m_Memory.m_pMemory[v29 + 1];
            if ( v83 < (int)v86 )
              *(float *)&v28[VertexIndexData->m_Memory.m_pMemory[v29 + 2]] = v73.m_pStorage->m_Memory.m_pMemory[v29 + 2];
            if ( v83 + 1 < (int)v86 )
              *(float *)&v28[VertexIndexData->m_Memory.m_pMemory[v29 + 3]] = v73.m_pStorage->m_Memory.m_pMemory[v29 + 3];
            v27 = v76;
            v83 += 4;
            v29 += 4;
          }
          while ( v29 < LODWORD(v76) - 3 );
        }
        for ( ; v29 < SLODWORD(v27); ++v29 )
        {
          if ( v29 < (int)v86 )
          {
            v27 = v76;
            *(float *)&v28[VertexIndexData->m_Memory.m_pMemory[v29]] = v73.m_pStorage->m_Memory.m_pMemory[v29];
          }
        }
      }
    }
  }
  CDmeVertexDataBase::RemoveAllVertexData(this: (CDmeVertexDataBase *)pDelta, nFieldIndex: Field);
  if ( flScale != 0.0 || (result = true, wrinkleOp == kAdd) )
  {
    *(float *)&v83 = 0.0;
    v31 = alloca(4 * (_DWORD)v86);
    v76 = COERCE_FLOAT(v64);
    v32 = alloca(4 * (_DWORD)v86);
    v78 = COERCE_FLOAT(v64);
    v82 = nullptr;
    v75 = 0;
    p_x = nullptr;
    if ( bUseNormalForSign )
    {
      v33 = v85;
      v34 = (int *)CDmeVertexDataBase::GetVertexIndexData(this: v85, fieldId: FIELD_NORMAL);
      NormalData = CDmeVertexDataBase::GetNormalData(this: v33);
      if ( v34[3] <= 0 || NormalData->m_Size <= 0 )
      {
        m_pAsString = v80->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = var;
        _Warning(a1: "ComputeNormalWrinkle called but no normals on Mesh: %s\n", m_pAsString);
        bUseNormalForSign = false;
      }
      else
      {
        m_pMemory = NormalData->m_Memory.m_pMemory;
        v75 = *v34;
        p_x = (_DWORD *)&m_pMemory->x;
      }
    }
    v38 = 0;
    if ( v84 != nullptr || bUseNormalForSign )
    {
      v80 = nullptr;
      if ( (int)v86 > 0 )
      {
        v77 = nullptr;
        *(float *)&v73.m_pAttribute = v76;
        Referring = (CDmeMesh *)(LODWORD(v78) - LODWORD(v76));
        do
        {
          v45 = *(float *)&v77->m_Id.m_Value[*(_DWORD *)LODWORD(v68)]
              - *(float *)((char *)&v69.m_pStorage->m_Memory.m_pMemory->y + (unsigned int)v77);
          v46 = *(float *)&v77->m_Id.m_Value[*(_DWORD *)LODWORD(v68) + 4]
              - *(float *)((char *)&v69.m_pStorage->m_Memory.m_pMemory->z + (unsigned int)v77);
          v66.x = *(float *)((char *)&v77->__vftable + *(_DWORD *)LODWORD(v68))
                - *(float *)((char *)&v69.m_pStorage->m_Memory.m_pMemory->x + (unsigned int)v77);
          v66.y = v45;
          v66.z = v46;
          VertexIndicesFromDataIndex = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                         this: v85,
                                         fieldId: FIELD_POSITION,
                                         nDataIndex: (int)v80);
          v48 = VertexIndicesFromDataIndex->m_Size;
          v49 = 0;
          if ( v48 > 0 )
          {
            v50 = v84;
            while ( 1 )
            {
              if ( v50 != nullptr )
              {
                v50 = v84;
                if ( fabs(*(float *)&v84[*((_DWORD *)&m_pVertexData->m_pNext->m_pNext
                                         + VertexIndicesFromDataIndex->m_Memory.m_pMemory[v49])]) > 0.0001 )
                  break;
              }
              if ( fabs(v66.x) >= 0.00024414062 || fabs(v66.y) >= 0.00024414062 || fabs(v66.z) >= 0.00024414062 )
                break;
              if ( ++v49 >= v48 )
                goto LABEL_91;
            }
            v51 = VectorNormalize(vec: &v66);
            v78 = v51;
            v52 = v78;
            if ( v51 > *(float *)&v83 )
              *(float *)&v83 = v78;
            if ( bUseNormalForSign )
            {
              v53 = &p_x[3 * *(_DWORD *)(v75 + 4 * VertexIndicesFromDataIndex->m_Memory.m_pMemory[v49])];
              *(_QWORD *)((char *)&v65 + 4) = *(_QWORD *)v53;
              HIDWORD(v65) = v53[2];
              VectorNormalize(vec: (Vector *)((char *)&v65 + 4));
              v52 = v78;
              if ( (float)((float)((float)(*((float *)&v65 + 2) * v66.y) + (float)(*((float *)&v65 + 1) * v66.x))
                         + (float)(*((float *)&v65 + 3) * v66.z)) < 0.0 )
                v52 = -v78;
            }
            m_pAttribute = v73.m_pAttribute;
            v55 = (int)v80;
            v82 = (CDmAttribute *)((char *)v82 + 1);
            *(float *)((char *)&v73.m_pAttribute->m_pNext + (unsigned int)Referring) = v52;
            m_pAttribute->m_pNext = (CDmAttribute *)v55;
            v73.m_pAttribute = (CDmAttribute *)&m_pAttribute->m_pData;
          }
LABEL_91:
          v77 = (CDmeMesh *)((char *)v77 + 12);
          v80 = (CDmeMesh *)((char *)v80 + 1);
        }
        while ( (int)v80 < (int)v86 );
        goto LABEL_92;
      }
    }
    else
    {
      v39 = 0;
      if ( (int)v86 > 0 )
      {
        v40 = v76;
        Referring = (CDmeMesh *)(LODWORD(v78) - LODWORD(v76));
        do
        {
          v41 = *(float *)(*(_DWORD *)LODWORD(v68) + v38 * 12 + 4) - v69.m_pStorage->m_Memory.m_pMemory[v38].y;
          v42 = *(float *)(*(_DWORD *)LODWORD(v68) + v38 * 12 + 8) - v69.m_pStorage->m_Memory.m_pMemory[v38].z;
          v43 = *(float *)(*(_DWORD *)LODWORD(v68) + v38 * 12) - v69.m_pStorage->m_Memory.m_pMemory[v38].x;
          v66.x = v43;
          v66.y = v41;
          v66.z = v42;
          if ( fabs(v43) >= 0.00024414062 || fabs(v41) >= 0.00024414062 || fabs(v42) >= 0.00024414062 )
          {
            v44 = 0;
            *(float *)&v44 = fsqrt((float)((float)(v41 * v41) + (float)(v42 * v42)) + (float)(v43 * v43));
            v65 = v44;
            if ( *(float *)&v44 > *(float *)&v83 )
              v83 = v44;
            v82 = (CDmAttribute *)((char *)v82 + 1);
            *(CDmeMesh_vtbl **)((char *)&Referring->__vftable + LODWORD(v40)) = (CDmeMesh_vtbl *)v65;
            *(_DWORD *)LODWORD(v40) = v39;
            LODWORD(v40) += 4;
          }
          ++v39;
          ++v38;
        }
        while ( v39 < (int)v86 );
LABEL_92:
        if ( *(float *)&v83 != 0.0 )
        {
          v56 = ((int)&v71->m_Memory.m_nAllocationCount + 3) >> 3;
          v68 = (float)(flScale / *(float *)&v83);
          v57 = alloca(v56);
          p_x = v64;
          memset(dst: (unsigned __int8 *)v64, value: 0, count: v56);
          if ( (int)v82 > 0 )
          {
            v78 = v76;
            v73.m_pAttribute = v82;
            v58 = v76;
            do
            {
              v63 = *(_DWORD *)LODWORD(v58);
              v76 = *(float *)((char *)&Referring->__vftable + LODWORD(v58)) * v68;
              v71 = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                      this: v85,
                      fieldId: FIELD_POSITION,
                      nDataIndex: v63);
              v82 = (CDmAttribute *)v71->m_Size;
              v77 = nullptr;
              if ( (int)v82 > 0 )
              {
                do
                {
                  v59 = *((_DWORD *)&m_pVertexData->m_pNext->m_pNext + v71->m_Memory.m_pMemory[(_DWORD)v77]);
                  v60 = (char *)p_x + (v59 >> 3);
                  v75 = v59;
                  if ( ((unsigned __int8)(1 << (v59 & 7)) & *v60) == 0 )
                  {
                    *v60 |= 1 << (v59 & 7);
                    if ( v84 != nullptr )
                      v76 = *(float *)&v84[v59] + v76;
                    v61 = Field;
                    v80 = (CDmeMesh *)CDmeVertexDataBase::AddVertexData(
                                        this: (CDmeVertexDataBase *)pDelta,
                                        nFieldIndex: Field,
                                        nCount: 1);
                    CDmeVertexDataBase::SetVertexIndices(
                      this: (CDmeVertexDataBase *)pDelta,
                      nFieldIndex: v61,
                      nFirstIndex: (int)v80,
                      nCount: 1,
                      pIndices: &v75);
                    CDmeVertexDataBase::SetVertexData(
                      this: (CDmeVertexDataBase *)pDelta,
                      nFieldIndex: v61,
                      nFirstVertex: (int)v80,
                      nCount: 1,
                      valueType: AT_FLOAT,
                      pData: &v76);
                  }
                  v77 = (CDmeMesh *)((char *)v77 + 1);
                }
                while ( (int)v77 < (int)v82 );
                v58 = v78;
              }
              LODWORD(v58) += 4;
              v62 = v73.m_pAttribute-- == (CDmAttribute *)1;
              v78 = v58;
            }
            while ( !v62 );
          }
        }
      }
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045A240
// Name: protected: static void CDmMeshUtils::PurgeUnreferencedDeltas(class CDmeMesh __near *,class CUtlStringMap<class CDmePreset __near *> __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near *,class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmMeshUtils::PurgeUnreferencedDeltas(
        CDmeMesh *pMesh,
        CUtlStringMap<CDmePreset *> *presetMap,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pPurgeAllButThese,
        CDmeCombinationOperator *pComboOp)
{
  int v4; // esi
  CUtlSymbolLarge::<unnamed_type_u> v5; // eax
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v6; // edi
  const char *v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  int ControlIndex; // eax
  int v11; // esi
  int v12; // edi
  const char *RawControlName; // eax
  int v14; // esi
  int v15; // esi
  const char *v16; // eax
  char *v17; // edi
  CDmePreset *v18; // esi
  const char *m_pAsString; // eax
  const char *v20; // eax
  const char *v21; // eax
  CDmeVertexDeltaData *DeltaState; // eax
  const char *v23; // esi
  CDmeVertexDeltaData *pRenamedDelta; // [esp+Ch] [ebp-1Ch]
  int nOrigIndex; // [esp+10h] [ebp-18h]
  int nOrigIndexa; // [esp+10h] [ebp-18h]
  int nOrigIndexb; // [esp+10h] [ebp-18h]
  int nRenamedIndex; // [esp+14h] [ebp-14h]
  int nRenamedIndexa; // [esp+14h] [ebp-14h]
  int nRenamedIndexb; // [esp+14h] [ebp-14h]
  const char *pControlName; // [esp+18h] [ebp-10h]
  const char *pControlNamea; // [esp+18h] [ebp-10h]
  const char *pControlNameb; // [esp+18h] [ebp-10h]
  const char *pOrigDelta; // [esp+1Ch] [ebp-Ch]
  CDmeVertexDeltaData *pOrigDeltaa; // [esp+1Ch] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+20h] [ebp-8h] BYREF
  bool bDelete; // [esp+27h] [ebp-1h]

LABEL_1:
  v4 = 0;
  nOrigIndex = 0;
  if ( CDmeMesh::DeltaStateCount(this: pMesh) <= 0 )
  {
    v6 = pPurgeAllButThese;
    goto LABEL_23;
  }
  do
  {
    v5.m_Id = (int)CDmeMesh::GetDeltaState(this: pMesh, nDeltaIndex: v4)->m_Name.m_Storage.u;
    pOrigDelta = var;
    if ( v5.m_Id != -1 )
      pOrigDelta = (const char *)v5.m_Id;
    v6 = pPurgeAllButThese;
    if ( CUtlSymbolTable::Find(
           this: &presetMap->m_SymbolTable,
           result: (CUtlSymbol *)&value.u.m_pAsString + 1,
           pString: pOrigDelta)->m_Id == 0xFFFF )
    {
      v7 = nullptr;
      bDelete = true;
      if ( pPurgeAllButThese == nullptr || (nRenamedIndex = 0, pPurgeAllButThese->m_Size <= 0) )
      {
LABEL_21:
        CDmeMesh::DeleteDeltaState(this: pMesh, pDeltaName: pOrigDelta);
        goto LABEL_1;
      }
      for ( pControlName = nullptr; ; v7 = pControlName )
      {
        v8 = CUtlString::operator char const *(this: (CUtlString *)&v7[(unsigned int)v6->m_Memory.m_pMemory]);
        if ( _V_strcmp(s1: pOrigDelta, s2: v8) == 0 )
          break;
        v9 = CUtlString::operator char const *(this: (CUtlString *)&v7[(unsigned int)v6->m_Memory.m_pMemory]);
        ControlIndex = CDmeCombinationOperator::FindControlIndex(this: pComboOp, pControlName: v9);
        v11 = ControlIndex;
        if ( ControlIndex >= 0 )
        {
          v12 = 0;
          if ( CDmeCombinationOperator::GetRawControlCount(this: pComboOp, nControl: ControlIndex) > 0 )
          {
            while ( 1 )
            {
              RawControlName = CDmeCombinationOperator::GetRawControlName(this: pComboOp, nControl: v11, nIndex: v12);
              if ( _V_strcmp(s1: pOrigDelta, s2: RawControlName) == 0 )
                break;
              if ( ++v12 >= CDmeCombinationOperator::GetRawControlCount(this: pComboOp, nControl: v11) )
                goto LABEL_16;
            }
            bDelete = false;
          }
LABEL_16:
          v6 = pPurgeAllButThese;
        }
        pControlName += 16;
        if ( ++nRenamedIndex >= v6->m_Size )
        {
          if ( bDelete )
            goto LABEL_21;
          break;
        }
      }
    }
    v4 = ++nOrigIndex;
  }
  while ( nOrigIndex < CDmeMesh::DeltaStateCount(this: pMesh) );
LABEL_23:
  v14 = 0;
  for ( nRenamedIndexa = 0; v14 < CDmeCombinationOperator::GetControlCount(this: pComboOp); nRenamedIndexa = ++v14 )
  {
    pControlNamea = CDmeCombinationOperator::GetControlName(this: pComboOp, i: v14);
    if ( CUtlSymbolTable::Find(
           this: &presetMap->m_SymbolTable,
           result: (CUtlSymbol *)&value.u.m_pAsString + 1,
           pString: pControlNamea)->m_Id == 0xFFFF )
    {
      v15 = 0;
      if ( v6 == nullptr || (nOrigIndexa = 0, v6->m_Size <= 0) )
      {
LABEL_29:
        CDmeCombinationOperator::RemoveControl(this: pComboOp, pControlName: pControlNamea);
        goto LABEL_23;
      }
      while ( 1 )
      {
        v16 = CUtlString::operator char const *(this: &v6->m_Memory.m_pMemory[v15]);
        if ( _V_strcmp(s1: pControlNamea, s2: v16) == 0 )
          break;
        ++v15;
        if ( ++nOrigIndexa >= v6->m_Size )
          goto LABEL_29;
      }
      v14 = nRenamedIndexa;
    }
  }
  pControlNameb = nullptr;
  if ( presetMap->m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v17 = CUtlSymbolTable::String(this: &presetMap->m_SymbolTable, id: (CUtlSymbol)pControlNameb);
      v18 = presetMap->m_Vector.m_Memory.m_pMemory[(unsigned __int16)pControlNameb];
      m_pAsString = v18->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      if ( _V_strcmp(s1: m_pAsString, s2: v17) != 0 )
      {
        v20 = v18->m_Name.m_Storage.u.m_pAsString;
        if ( v20 == (const char *)-1 )
          v20 = var;
        nOrigIndexb = CDmeCombinationOperator::FindControlIndex(this: pComboOp, pControlName: v20);
        nRenamedIndexb = CDmeCombinationOperator::FindControlIndex(this: pComboOp, pControlName: v17);
        v21 = v18->m_Name.m_Storage.u.m_pAsString;
        if ( v21 == (const char *)-1 )
          v21 = var;
        pOrigDeltaa = CDmeMesh::FindDeltaState(this: pMesh, pDeltaName: v21, bSortDeltaName: true);
        DeltaState = CDmeMesh::FindDeltaState(this: pMesh, pDeltaName: v17, bSortDeltaName: true);
        pRenamedDelta = DeltaState;
        if ( nOrigIndexb < 0 && nRenamedIndexb >= 0 && pOrigDeltaa == nullptr && DeltaState != nullptr )
        {
          CDmeCombinationOperator::RemoveControl(this: pComboOp, pControlName: v17);
          v23 = v18->m_Name.m_Storage.u.m_pAsString;
          if ( v23 == (const char *)-1 )
            v23 = var;
          g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: v23);
          CDmAttribute::SetValue<CUtlSymbolLarge>(this: pRenamedDelta->m_Name.m_pAttribute, &value);
        }
      }
      ++pControlNameb;
    }
    while ( (int)pControlNameb < presetMap->m_SymbolTable.m_Lookup.m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A520
// Name: void RemapData<class Vector4D>(class CDmrArray<class Vector4D>,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapData<Vector4D>(
        CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > data,
        const CUtlVector<int,CUtlMemory<int,int> > *newToOldMap)
{
  const CUtlVector<int,CUtlMemory<int,int> > *v2; // esi
  int m_Size; // edi
  void *v4; // esp
  int v5; // edx
  CDmAttribute **p_m_pAttribute; // eax
  Vector4D *v7; // ecx
  Vector4D *v8; // ecx
  Vector4D *v9; // ecx
  Vector4D *v10; // ecx
  float *v11; // ecx
  Vector4D *v12; // eax
  _BYTE v13[12]; // [esp+0h] [ebp-Ch] BYREF

  v2 = newToOldMap;
  m_Size = newToOldMap->m_Size;
  v4 = alloca(16 * m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    p_m_pAttribute = &data.m_pAttribute;
    do
    {
      v7 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5]];
      v5 += 4;
      p_m_pAttribute += 16;
      *(p_m_pAttribute - 22) = (CDmAttribute *)LODWORD(v7->x);
      *(p_m_pAttribute - 21) = (CDmAttribute *)LODWORD(v7->y);
      *(p_m_pAttribute - 20) = (CDmAttribute *)LODWORD(v7->z);
      *(p_m_pAttribute - 19) = (CDmAttribute *)LODWORD(v7->w);
      v8 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5 - 3]];
      *(p_m_pAttribute - 18) = (CDmAttribute *)LODWORD(v8->x);
      *(p_m_pAttribute - 17) = (CDmAttribute *)LODWORD(v8->y);
      *(p_m_pAttribute - 16) = (CDmAttribute *)LODWORD(v8->z);
      *(p_m_pAttribute - 15) = (CDmAttribute *)LODWORD(v8->w);
      v9 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5 - 2]];
      *(p_m_pAttribute - 14) = (CDmAttribute *)LODWORD(v9->x);
      *(p_m_pAttribute - 13) = (CDmAttribute *)LODWORD(v9->y);
      *(p_m_pAttribute - 12) = (CDmAttribute *)LODWORD(v9->z);
      *(p_m_pAttribute - 11) = (CDmAttribute *)LODWORD(v9->w);
      v10 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5 - 1]];
      *(p_m_pAttribute - 10) = (CDmAttribute *)LODWORD(v10->x);
      *(p_m_pAttribute - 9) = (CDmAttribute *)LODWORD(v10->y);
      *(p_m_pAttribute - 8) = (CDmAttribute *)LODWORD(v10->z);
      *(p_m_pAttribute - 7) = (CDmAttribute *)LODWORD(v10->w);
    }
    while ( v5 < m_Size - 3 );
  }
  if ( v5 < m_Size )
  {
    v11 = (float *)&v13[16 * v5 + 8];
    do
    {
      v12 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5++]];
      v11 += 4;
      *(v11 - 6) = v12->x;
      *(v11 - 5) = v12->y;
      *(v11 - 4) = v12->z;
      *(v11 - 3) = v12->w;
    }
    while ( v5 < m_Size );
  }
  CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>::RemoveMultiple(
    this: &data,
    elem: m_Size,
    num: data.m_pStorage->m_Size - m_Size);
  CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>::SetMultiple(
    this: &data,
    i: 0,
    nCount: m_Size,
    pValue: (const Vector4D *)v13);
}

//------------------------------------------------------------------------------
// Address: 0x0045A650
// Name: void RemapData<class Quaternion>(class CDmrArray<class Quaternion>,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapData<Quaternion>(
        CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > data,
        const CUtlVector<int,CUtlMemory<int,int> > *newToOldMap)
{
  const CUtlVector<int,CUtlMemory<int,int> > *v2; // edi
  int m_Size; // esi
  void *v4; // esp
  int v5; // ecx
  _QWORD *v6; // edx
  Quaternion *v7; // eax
  _BYTE v8[12]; // [esp+0h] [ebp-Ch] BYREF

  v2 = newToOldMap;
  m_Size = newToOldMap->m_Size;
  v4 = alloca(16 * m_Size);
  v5 = 0;
  if ( m_Size > 0 )
  {
    v6 = v8;
    do
    {
      v7 = &data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5++]];
      *v6 = *(_QWORD *)&v7->x;
      v6[1] = *(_QWORD *)&v7->z;
      v6 += 2;
    }
    while ( v5 < m_Size );
  }
  CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::RemoveMultiple(
    this: &data,
    elem: m_Size,
    num: data.m_pStorage->m_Size - m_Size);
  CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::SetMultiple(
    this: &data,
    i: 0,
    nCount: m_Size,
    pValue: (const Quaternion *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x0045A6C0
// Name: void RemapData<class Color>(class CDmrArray<class Color>,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapData<Color>(
        CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > data,
        const CUtlVector<int,CUtlMemory<int,int> > *newToOldMap)
{
  const CUtlVector<int,CUtlMemory<int,int> > *v2; // ebx
  int m_Size; // esi
  void *v4; // esp
  int i; // eax
  Color v6[3]; // [esp+0h] [ebp-Ch] BYREF

  v2 = newToOldMap;
  m_Size = newToOldMap->m_Size;
  v4 = alloca(4 * m_Size);
  for ( i = 0; i < m_Size; ++i )
    v6[i] = data.m_pStorage->m_Memory.m_pMemory[v2->m_Memory.m_pMemory[i]];
  CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::RemoveMultiple(
    this: &data,
    elem: m_Size,
    num: data.m_pStorage->m_Size - m_Size);
  CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::SetMultiple(
    this: &data,
    i: 0,
    nCount: m_Size,
    pValue: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0045A820
// Name: public: int const __near & CDmElement::GetValue<int>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmElement::GetValue<int>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<int> *)CDmAttribute::GetValue<int>(this: Attribute);
  else
    return &`CDmElement::GetValue<int>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0045A8E0
// Name: void MergeDeltaState(class CDmeMesh __near *,class CDmeVertexDeltaData __near *,class CDmeVertexDeltaData __near *,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MergeDeltaState(
        CDmeMesh *pDmeMesh,
        CDmeVertexDeltaData *pSrcDelta,
        CDmeVertexDeltaData *pDstDelta,
        int *nPositionOffset,
        int *nNormalOffset,
        int *nWrinkleOffset)
{
  CDmeVertexDeltaData *v6; // ebx
  CDmeVertexDeltaData *v7; // esi
  const char *m_pAsString; // eax
  CDmeVertexDeltaData *DeltaState; // eax
  int v10; // edi
  const char *v11; // eax
  const char *v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // edi
  int *v16; // ecx
  int v17; // edi
  const char *v18; // eax
  CDmAttribute *m_pVertexData; // esi
  int v20; // ebx
  CDmAttribute *v21; // edi
  int m_Size; // esi
  int v23; // edi
  int v24; // esi
  int v25; // edi
  int v26; // esi
  int v27; // edi
  int v28; // esi
  int v29; // edi
  int v30; // esi
  int v31; // edi
  IUndoElement_vtbl *v32; // esi
  int v33; // edi
  CDmAttribute *m_pIndexData; // esi
  CDmAttribute *v35; // ebx
  IUndoElement_vtbl *v36; // edi
  int v37; // ebx
  int j; // esi
  int v39; // edi
  unsigned __int8 *m_Id; // edi
  int v41; // eax
  CUtlSymbolLarge *v42; // eax
  CDmeCombinationOperator *Referring; // eax
  CDmeCombinationOperator *v44; // esi
  const char *v45; // ebx
  const char *v46; // eax
  const char *v47; // [esp-4h] [ebp-9Ch]
  DmAttributeType_t v48; // [esp-4h] [ebp-9Ch]
  const char *v49; // [esp-4h] [ebp-9Ch]
  CDmrArray<int> srcIndices; // [esp+Ch] [ebp-8Ch] BYREF
  int value; // [esp+14h] [ebp-84h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v52; // [esp+18h] [ebp-80h] BYREF
  int nSrcPositionIndex; // [esp+20h] [ebp-78h]
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v54; // [esp+24h] [ebp-74h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v55; // [esp+2Ch] [ebp-6Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v56; // [esp+34h] [ebp-64h] BYREF
  int nSrcWrinkleIndex; // [esp+3Ch] [ebp-5Ch]
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v58; // [esp+40h] [ebp-58h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v59; // [esp+48h] [ebp-50h] BYREF
  int nSrcNormalIndex; // [esp+50h] [ebp-48h]
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v61; // [esp+54h] [ebp-44h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v62; // [esp+5Ch] [ebp-3Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v63; // [esp+64h] [ebp-34h] BYREF
  CDmrArray<int> dstIndices; // [esp+6Ch] [ebp-2Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v65; // [esp+74h] [ebp-24h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v66; // [esp+7Ch] [ebp-1Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v67; // [esp+84h] [ebp-14h] BYREF
  int i; // [esp+8Ch] [ebp-Ch]
  unsigned int v69; // [esp+90h] [ebp-8h]
  int nOffset; // [esp+94h] [ebp-4h]

  v6 = pDstDelta;
  v7 = pSrcDelta;
  if ( pDstDelta == nullptr )
  {
    m_pAsString = pSrcDelta->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    DeltaState = CDmeMesh::FindOrCreateDeltaState(this: pDmeMesh, pInDeltaName: m_pAsString, bSortDeltaName: true);
    pDstDelta = DeltaState;
    if ( DeltaState == nullptr )
      return;
    v6 = DeltaState;
  }
  nOffset = 0;
  if ( CDmeTrack::GetClipCount(this: pSrcDelta) > 0 )
  {
    v69 = 0;
    do
    {
      v10 = 0;
      if ( CDmeTrack::GetClipCount(this: v6) <= 0 )
      {
LABEL_11:
        v48 = pSrcDelta->m_FieldInfo.m_Memory.m_pMemory[v69 / 0x30].m_pVertexData->m_nFlags & 0x1F;
        v12 = CDmeVertexDataBase::FieldName(this: pSrcDelta, i: nOffset);
        CDmeVertexDataBase::CreateField(this: v6, pFieldName: v12, type: v48);
      }
      else
      {
        while ( 1 )
        {
          v47 = CDmeVertexDataBase::FieldName(this: v6, i: v10);
          v11 = CDmeVertexDataBase::FieldName(this: pSrcDelta, i: nOffset);
          if ( _V_strcmp(s1: v11, s2: v47) == 0 )
            break;
          if ( ++v10 >= CDmeTrack::GetClipCount(this: v6) )
            goto LABEL_11;
        }
      }
      v69 += 48;
      ++nOffset;
    }
    while ( nOffset < CDmeTrack::GetClipCount(this: pSrcDelta) );
  }
  v13 = pSrcDelta->m_pStandardFieldIndex[1];
  v14 = pSrcDelta->m_pStandardFieldIndex[9];
  nSrcPositionIndex = pSrcDelta->m_pStandardFieldIndex[0];
  v15 = 0;
  nSrcNormalIndex = v13;
  nSrcWrinkleIndex = v14;
  i = 0;
  if ( CDmeTrack::GetClipCount(this: pSrcDelta) > 0 )
  {
    v69 = 0;
    while ( 1 )
    {
      nOffset = 0;
      if ( v15 == nSrcPositionIndex )
      {
        v16 = nPositionOffset;
      }
      else if ( v15 == nSrcNormalIndex )
      {
        v16 = nNormalOffset;
      }
      else
      {
        if ( v15 != nSrcWrinkleIndex )
          goto LABEL_24;
        v16 = nWrinkleOffset;
      }
      nOffset = *v16;
      if ( nOffset < 0 )
        nOffset = 0;
LABEL_24:
      v17 = 0;
      if ( CDmeTrack::GetClipCount(this: v6) > 0 )
      {
        while ( 1 )
        {
          v49 = CDmeVertexDataBase::FieldName(this: v6, i: v17);
          v18 = CDmeVertexDataBase::FieldName(this: v7, i);
          if ( _V_strcmp(s1: v18, s2: v49) == 0 )
            break;
          if ( ++v17 >= CDmeTrack::GetClipCount(this: v6) )
            goto LABEL_38;
        }
        m_pVertexData = v7->m_FieldInfo.m_Memory.m_pMemory[v69 / 0x30].m_pVertexData;
        v20 = v17;
        v21 = pDstDelta->m_FieldInfo.m_Memory.m_pMemory[v17].m_pVertexData;
        switch ( m_pVertexData->m_nFlags & 0x1F )
        {
          case 0x11:
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v62);
            CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
              this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v62,
              pAttribute: v21);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v55);
            CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
              this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v55,
              pAttribute: m_pVertexData);
            m_Size = v55.m_pStorage->m_Size;
            v23 = v62.m_pStorage->m_Size;
            CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddMultipleToTail(
              this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v62,
              num: m_Size);
            CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::SetMultiple(
              this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v62,
              i: v23,
              nCount: m_Size,
              pValue: (const float *)v55.m_pStorage->m_Memory.m_pMemory);
            break;
          case 0x16:
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v66);
            CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
              this: (CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v66,
              pAttribute: v21);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v52);
            CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
              this: (CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v52,
              pAttribute: m_pVertexData);
            v32 = (IUndoElement_vtbl *)v52.m_pStorage->m_Size;
            v33 = v66.m_pStorage->m_Size;
            CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::AddMultipleToTail(
              this: (CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > *)&v66,
              num: v32);
            CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::SetMultiple(
              this: (CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > *)&v66,
              i: v33,
              nCount: (int)v32,
              pValue: (const Color *)v52.m_pStorage->m_Memory.m_pMemory);
            break;
          case 0x17:
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v65);
            CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
              this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v65,
              pAttribute: v21);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v59);
            CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
              this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v59,
              pAttribute: m_pVertexData);
            v24 = v59.m_pStorage->m_Size;
            v25 = v65.m_pStorage->m_Size;
            CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::AddMultipleToTail(
              this: (CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > *)&v65,
              num: v24);
            CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::SetMultiple(
              this: (CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > *)&v65,
              i: v25,
              nCount: v24,
              pValue: (const Vector2D *)v59.m_pStorage->m_Memory.m_pMemory);
            break;
          case 0x18:
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v63);
            CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
              this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v63,
              pAttribute: v21);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v58);
            CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
              this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v58,
              pAttribute: m_pVertexData);
            v26 = v58.m_pStorage->m_Size;
            v27 = v63.m_pStorage->m_Size;
            CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddMultipleToTail(
              this: (CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *)&v63,
              num: v26);
            CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::SetMultiple(
              this: (CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *)&v63,
              i: v27,
              nCount: v26,
              pValue: (const Vector *)v58.m_pStorage->m_Memory.m_pMemory);
            break;
          case 0x19:
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v67);
            CDmrDecorator<Vector4D,CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>>::Init(
              this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&v67,
              pAttribute: v21);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v56);
            CDmrDecorator<Vector4D,CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>>::Init(
              this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&v56,
              pAttribute: m_pVertexData);
            v28 = v56.m_pStorage->m_Size;
            v29 = v67.m_pStorage->m_Size;
            CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>::AddMultipleToTail(
              this: (CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > *)&v67,
              num: v28);
            CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>::SetMultiple(
              this: (CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > *)&v67,
              i: v29,
              nCount: v28,
              pValue: (const Vector4D *)v56.m_pStorage->m_Memory.m_pMemory);
            break;
          case 0x1B:
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v61);
            CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
              this: (CDmrDecoratorConst<Quaternion,CDmaArrayConstBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > > *)&v61,
              pAttribute: v21);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v54);
            CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
              this: (CDmrDecoratorConst<Quaternion,CDmaArrayConstBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > > *)&v54,
              pAttribute: m_pVertexData);
            v30 = v54.m_pStorage->m_Size;
            v31 = v61.m_pStorage->m_Size;
            CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddMultipleToTail(
              this: (CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *)&v61,
              num: v30);
            CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::SetMultiple(
              this: (CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *)&v61,
              i: v31,
              nCount: v30,
              pValue: (const Quaternion *)v54.m_pStorage->m_Memory.m_pMemory);
            break;
          default:
            break;
        }
        m_pIndexData = pSrcDelta->m_FieldInfo.m_Memory.m_pMemory[v69 / 0x30].m_pIndexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcIndices);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&srcIndices,
          pAttribute: m_pIndexData);
        v35 = pDstDelta->m_FieldInfo.m_Memory.m_pMemory[v20].m_pIndexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&dstIndices);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&dstIndices,
          pAttribute: v35);
        v36 = (IUndoElement_vtbl *)srcIndices.m_pStorage->m_Size;
        v37 = dstIndices.m_pStorage->m_Size;
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::AddMultipleToTail(
          this: &dstIndices,
          num: v36);
        for ( j = 0; j < (int)v36; ++j )
        {
          value = nOffset + srcIndices.m_pStorage->m_Memory.m_pMemory[j];
          CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
            this: &dstIndices,
            i: j + v37,
            &value);
        }
        v7 = pSrcDelta;
        v6 = pDstDelta;
      }
LABEL_38:
      v69 += 48;
      v39 = ++i;
      if ( v39 >= CDmeTrack::GetClipCount(this: v7) )
        break;
      v15 = i;
    }
  }
  m_Id = (unsigned __int8 *)var;
  if ( v6->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id != -1 )
    m_Id = (unsigned __int8 *)v6->m_Name.m_Storage.u.CDmeVertexDataBase::CDmElement::m_Id;
  strchr(string: m_Id, chr: 0x5Fu);
  if ( v41 == 0 && pDmeMesh != nullptr )
  {
    v42 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pDstDelta, a3: "targets");
    Referring = FindReferringElement<CDmeCombinationOperator>(
                  pElement: (CExpressionCalculator *)pDmeMesh,
                  symAttrName: (CUtlSymbolLarge)v42->u.m_Id,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    v44 = Referring;
    if ( Referring != nullptr
      && !CDmeCombinationOperator::HasRawControl(this: Referring, pRawControlName: (const char *)m_Id) )
    {
      v45 = v6->m_Name.m_Storage.u.m_pAsString;
      v46 = var;
      if ( v45 != (const char *)-1 )
        v46 = v45;
      CDmeCombinationOperator::FindOrCreateControl(
        this: v44,
        pControlName: v46,
        bStereo: false,
        bAutoAddRawControl: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045ADB0
// Name: bool CopyJointWeights(class CDmeVertexData __near *,class CDmeVertexData __near *,class CUtlVector<struct VertexWeightMap_s,class CUtlMemory<struct VertexWeightMap_s,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CopyJointWeights(
        CDmeVertexData *pSrcData,
        CDmeVertexData *pDstData,
        const CUtlVector<VertexWeightMap_s,CUtlMemory<VertexWeightMap_s,int> > *vertexWeightMap)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax
  int m_Storage; // edi
  int v7; // eax
  int v8; // ebx
  CDmAttribute *m_pVertexData; // esi
  int m_Size; // ebx
  int v11; // esi
  void *v12; // esp
  void *v13; // esp
  CDmAttribute *m_pAttribute; // edx
  unsigned int v15; // ecx
  VertexWeightMap_s *v16; // eax
  int v17; // ebx
  unsigned __int8 v19[12]; // [esp+0h] [ebp-34h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v20; // [esp+Ch] [ebp-28h] BYREF
  const int *pSrcJointIndices; // [esp+14h] [ebp-20h]
  const float *pSrcJointWeights; // [esp+18h] [ebp-1Ch]
  int nDstJointWeightsField; // [esp+1Ch] [ebp-18h] BYREF
  float *pDstJointWeights; // [esp+20h] [ebp-14h]
  int nDstJointIndicesField; // [esp+24h] [ebp-10h] BYREF
  int *pDstJointIndices; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  unsigned int v28; // [esp+30h] [ebp-4h]
  CDmAttribute *pSrcDatab; // [esp+3Ch] [ebp+8h]
  int *pSrcDataa; // [esp+3Ch] [ebp+8h]

  if ( (`CDmElement::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  Attribute = CDmElement::FindAttribute(this: pSrcData, pAttributeName: "jointCount");
  if ( Attribute != nullptr )
    v5 = (CDmaVar<int> *)CDmAttribute::GetValue<int>(this: Attribute);
  else
    v5 = &`CDmElement::GetValue<int>'::`2'::defaultVal;
  m_Storage = v5->m_Storage;
  v7 = pSrcData->m_pStandardFieldIndex[5];
  v8 = pSrcData->m_pStandardFieldIndex[6];
  if ( m_Storage <= 0 || v7 < 0 || v8 < 0 )
    return 0;
  pSrcDatab = pSrcData->m_FieldInfo.m_Memory.m_pMemory[v7].m_pVertexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v20);
  CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v20,
    pAttribute: pSrcDatab);
  m_pVertexData = pSrcData->m_FieldInfo.m_Memory.m_pMemory[v8].m_pVertexData;
  pSrcJointWeights = (const float *)&v20.m_pStorage->m_Memory.m_pMemory->m_tms;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v20);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v20,
    pAttribute: m_pVertexData);
  pSrcJointIndices = &v20.m_pStorage->m_Memory.m_pMemory->m_tms;
  CDmeVertexDataBase::CreateJointWeightsAndIndices(
    this: pDstData,
    nJointCount: m_Storage,
    pJointWeightsField: &nDstJointWeightsField,
    pJointIndicesField: &nDstJointIndicesField);
  m_Size = vertexWeightMap->m_Size;
  v11 = m_Storage * m_Size;
  v12 = alloca(4 * m_Storage * m_Size);
  pDstJointWeights = (float *)v19;
  memset(dst: v19, value: 0, count: m_Storage * m_Size);
  v13 = alloca(4 * m_Storage * m_Size);
  pDstJointIndices = (int *)v19;
  memset(dst: v19, value: 0, count: m_Storage * m_Size);
  if ( m_Size > 0 )
  {
    m_pAttribute = (CDmAttribute *)((char *)pDstJointWeights - (char *)pDstJointIndices);
    v28 = 0;
    v15 = 4 * m_Storage;
    pSrcDataa = pDstJointIndices;
    v20.m_pAttribute = (CDmAttribute *)((char *)pDstJointWeights - (char *)pDstJointIndices);
    for ( i = m_Size; i != 0; --i )
    {
      v16 = &vertexWeightMap->m_Memory.m_pMemory[v28 / 0x40];
      if ( v16->m_nVertexWeights > 0 )
      {
        v17 = m_Storage * v16->m_vertexWeights[0].m_vertexDataIndex;
        memcpy(
          dst: (unsigned __int8 *)m_pAttribute + (_DWORD)pSrcDataa,
          src: (unsigned __int8 *)&pSrcJointWeights[v17],
          count: v15);
        memcpy(dst: (unsigned __int8 *)pSrcDataa, src: (unsigned __int8 *)&pSrcJointIndices[v17], count: 4 * m_Storage);
        m_pAttribute = v20.m_pAttribute;
      }
      v28 += 64;
      v15 = 4 * m_Storage;
      pSrcDataa += m_Storage;
    }
  }
  CDmeVertexDataBase::AddVertexData(this: pDstData, nFieldIndex: nDstJointIndicesField, nCount: v11);
  CDmeVertexDataBase::SetVertexData(
    this: pDstData,
    nFieldIndex: nDstJointIndicesField,
    nFirstVertex: 0,
    nCount: v11,
    valueType: AT_INT,
    pData: pDstJointIndices);
  CDmeVertexDataBase::AddVertexData(this: pDstData, nFieldIndex: nDstJointWeightsField, nCount: v11);
  CDmeVertexDataBase::SetVertexData(
    this: pDstData,
    nFieldIndex: nDstJointWeightsField,
    nFirstVertex: 0,
    nCount: v11,
    valueType: AT_FLOAT,
    pData: pDstJointWeights);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045AFA0
// Name: class CDmeMesh __near * ReplaceMesh(class CDmeMesh __near *,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMesh *__cdecl ReplaceMesh(CDmeMesh *pSrcMesh, CDmeMesh *pDstMesh)
{
  CDmeDag *Parent; // edi
  CDmeDag *v3; // eax
  CDmeDag *v4; // esi
  CDmeTransform *Transform; // eax
  CDmeTransform *v6; // eax
  CDmeMesh *v7; // edi
  CDmeCombinationOperator *Referring; // eax
  CDmElement *v9; // eax
  IDataModel_vtbl *v10; // esi
  CDmElement *v11; // ebx
  int v12; // eax
  CDmeDag *i; // eax
  CDmeCombinationOperator *v14; // esi
  matrix3x4_t exclusiveMat; // [esp+10h] [ebp-C4h] BYREF
  matrix3x4_t inclusiveMat; // [esp+40h] [ebp-94h] BYREF
  matrix3x4_t localMat; // [esp+70h] [ebp-64h] BYREF
  matrix3x4_t inverseMat; // [esp+A0h] [ebp-34h] BYREF
  CDmeCombinationOperator *pSrcComboOp; // [esp+D0h] [ebp-4h]
  CExpressionCalculator *pSrcMesha; // [esp+DCh] [ebp+8h]

  if ( pSrcMesh == nullptr || pDstMesh == nullptr )
    return nullptr;
  Parent = CDmeShape::GetParent(this: pSrcMesh, nParentIndex: 0);
  v3 = CDmeShape::GetParent(this: pDstMesh, nParentIndex: 0);
  v4 = v3;
  if ( Parent == nullptr || v3 == nullptr )
    return nullptr;
  CDmeDag::GetShapeToWorldTransform(this: v3, mat: &inclusiveMat);
  Transform = CDmeDag::GetTransform(this: v4);
  CDmeTransform::GetTransform(this: Transform, transform: &localMat);
  MatrixInvert(in: &localMat, out: &inverseMat);
  ConcatTransforms(in1: &inclusiveMat, in2: &inverseMat, out: &exclusiveMat);
  MatrixInvert(in: &exclusiveMat, out: &inverseMat);
  CDmeDag::GetShapeToWorldTransform(this: Parent, mat: &inclusiveMat);
  ConcatTransforms(in1: &inverseMat, in2: &inclusiveMat, out: &localMat);
  v6 = CDmeDag::GetTransform(this: v4);
  CDmeTransform::SetTransform(this: v6, transform: &localMat);
  v7 = (CDmeMesh *)CDmElement::CopyInternal(this: pSrcMesh, depth: TD_DEEP);
  CDmElement::SetFileId(this: v7, fileid: pDstMesh->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
  CDmElement::RemoveAttribute(this: v7, pAttributeName: "selection");
  CDmeMesh::SetCurrentBaseState(this: v7, pStateName: "bind");
  CDmeMesh::DeleteBaseState(this: v7, pStateName: "__dmxEdit_work");
  CDmeDag::SetShape(this: v4, pShape: (int)v7);
  pSrcComboOp = FindReferringElement<CDmeCombinationOperator>(
                  pElement: (CExpressionCalculator *)pSrcMesh,
                  pAttrName: "targets",
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
  if ( pSrcComboOp != nullptr )
  {
    Referring = FindReferringElement<CDmeCombinationOperator>(
                  pElement: (CExpressionCalculator *)pDstMesh,
                  pAttrName: "targets",
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
    {
      pSrcMesha = (CExpressionCalculator *)&Referring->CDmElement;
      v9 = FindReferringElement<CDmElement>(
             pElement: &Referring->CDmElement,
             pAttrName: "combinationOperator",
             bMustBeInSameFile: true,
             depth: TD_ALL);
      v10 = g_pDataModel->__vftable;
      v11 = v9;
      v12 = CExpressionCalculator::VariableCount(this: pSrcMesha);
      v10->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v12);
    }
    else
    {
      for ( i = FindReferringElement<CDmeDag>(
                  pElement: v4,
                  pAttrName: "children",
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
            i != nullptr;
            i = FindReferringElement<CDmeDag>(
                  pElement: i,
                  pAttrName: "children",
                  bMustBeInSameFile: true,
                  depth: TD_ALL) )
      {
        v4 = i;
      }
      v11 = FindReferringElement<CDmElement>(pElement: v4, pAttrName: "model", bMustBeInSameFile: true, depth: TD_ALL);
    }
    if ( v11 != nullptr )
    {
      v14 = CDmeCombinationOperator::Copy(this: pSrcComboOp, depth: TD_DEEP);
      CDmElement::SetFileId(this: &v14->CDmElement, fileid: v11->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
      CDmElement::SetValue<CDmeCombinationOperator>(
        this: v11,
        pAttributeName: "combinationOperator",
        pElement: (DmElementHandle_t)v14,
        bCreateIfNotFound: true);
      CDmeCombinationOperator::RemoveAllTargets(this: v14);
      CDmeCombinationOperator::AddTarget(this: v14, pElement: v7);
      CDmeCombinationOperator::GenerateWrinkleDeltas(
        this: v14,
        bOverwrite: false,
        bUseNormalForSign: false,
        flScale: 1.0);
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0045B1E0
// Name: bool CreateExpressionFile(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near *,class CDmeCombinationOperator __near *,class CDmePresetGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateExpressionFile(
        const char *pExpressionFile,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pPurgeAllButThese,
        CDmeCombinationOperator *pComboOp,
        CDmeTransform *pPresetGroup)
{
  const CDmaElementArray<CDmePreset> *Orientation; // eax
  int m_Size; // edi
  DmFileId_t UniqueFileId; // eax
  CDmElement *v7; // eax
  CDmePreset *v8; // esi
  char *m_Id; // eax
  const CDmaElementArray<CDmElement> *Position; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // esi
  const char *v14; // eax
  int v15; // esi
  bool IsStereoControl; // bl
  bool IsMultiControl; // al
  const char *v18; // esi
  CDmElement *v19; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  CDmElement *v23; // esi
  CDmAttribute *v24; // eax
  float *v25; // edx
  int v26; // edi
  CDmElement *v27; // eax
  CDmElement *v28; // esi
  const char *m_pAsString; // eax
  CDmElement *v30; // ebx
  CDmAttribute *v31; // eax
  CDmaVar<float> *v32; // edi
  CDmAttribute *v33; // eax
  CDmAttribute *v34; // eax
  CDmaVar<float> *v35; // esi
  CDmAttribute *v36; // eax
  CDmAttribute *v37; // eax
  CDmElement *ControlValue; // esi
  float m_Storage; // xmm0_4
  CDmElement *v40; // edi
  CDmAttribute *v41; // eax
  CDmaVar<float> *v42; // eax
  CDmAttribute *v43; // eax
  CDmElement *v44; // esi
  double ControlDefaultValue; // st7
  CDmAttribute *v46; // eax
  CDmAttribute *v47; // eax
  CDmAttribute *v48; // eax
  CDmElement *v49; // esi
  CP4File *v50; // eax
  CP4File *v51; // eax
  CDmePresetGroup *v52; // esi
  CP4File *v53; // eax
  CP4File *v54; // eax
  char expName[260]; // [esp+Ch] [ebp-47Ch] BYREF
  char buf1[260]; // [esp+110h] [ebp-378h] BYREF
  CFmtStrN<256> multiControlName; // [esp+214h] [ebp-274h] BYREF
  char buf[260]; // [esp+320h] [ebp-168h] BYREF
  float v60; // [esp+424h] [ebp-64h] BYREF
  const CDmaElementArray<CDmElement> *controlValues; // [esp+428h] [ebp-60h]
  int v62; // [esp+42Ch] [ebp-5Ch] BYREF
  const CDmaElementArray<CDmePreset> *presets; // [esp+430h] [ebp-58h]
  int nPresetsCount; // [esp+434h] [ebp-54h]
  int v65; // [esp+438h] [ebp-50h] BYREF
  int v66; // [esp+43Ch] [ebp-4Ch] BYREF
  float v67; // [esp+440h] [ebp-48h] BYREF
  float v68; // [esp+444h] [ebp-44h] BYREF
  int v69; // [esp+448h] [ebp-40h] BYREF
  int v70; // [esp+44Ch] [ebp-3Ch] BYREF
  int v71; // [esp+450h] [ebp-38h] BYREF
  float value; // [esp+454h] [ebp-34h] BYREF
  CDmePresetGroup *pDstPresetGroup; // [esp+458h] [ebp-30h]
  int nControlValueCount; // [esp+45Ch] [ebp-2Ch]
  int nControlCount; // [esp+460h] [ebp-28h]
  CDmePreset *v76; // [esp+464h] [ebp-24h]
  float flValue; // [esp+468h] [ebp-20h] BYREF
  float v78; // [esp+46Ch] [ebp-1Ch] BYREF
  char *s2; // [esp+470h] [ebp-18h]
  int i; // [esp+474h] [ebp-14h]
  CDmePreset *pDstPreset; // [esp+478h] [ebp-10h]
  int j; // [esp+47Ch] [ebp-Ch]
  const char *pControlName; // [esp+480h] [ebp-8h]
  bool bStereo; // [esp+486h] [ebp-2h]
  bool bMulti; // [esp+487h] [ebp-1h]

  if ( pPresetGroup != nullptr )
  {
    nControlCount = CDmeCombinationOperator::GetControlCount(this: pComboOp);
    Orientation = (const CDmaElementArray<CDmePreset> *)CDmeTransform::GetOrientation(this: pPresetGroup);
    m_Size = Orientation->m_Storage.m_Size;
    presets = Orientation;
    nPresetsCount = m_Size;
    if ( nControlCount > 0 && m_Size > 0 )
    {
      V_FileBase(in: pExpressionFile, out: expName, maxlen: 260);
      UniqueFileId = CreateUniqueFileId();
      pDstPresetGroup = CreateElement<CDmePresetGroup>(pObjectName: expName, fileid: UniqueFileId, pObjectID: nullptr);
      if ( pDstPresetGroup != nullptr )
      {
        i = 0;
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: presets->m_Storage.m_Memory.m_pMemory[i]);
          v8 = (CDmePreset *)v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmePreset::m_classType) )
            v8 = nullptr;
          v76 = v8;
          if ( !CDmePreset::IsAnimated(this: v8) )
          {
            m_Id = (char *)v8->m_Name.m_Storage.u.CDmElement::m_Id;
            if ( m_Id == (char *)-1 )
              m_Id = (char *)var;
            s2 = m_Id;
            pDstPreset = CDmePresetGroup::FindOrAddPreset(this: pDstPresetGroup, pPresetName: m_Id);
            Position = (const CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: (CDmeTransform *)v8);
            v11 = Position->m_Storage.m_Size;
            controlValues = Position;
            nControlValueCount = v11;
            j = 0;
            if ( nControlCount > 0 )
            {
              while ( 1 )
              {
                pControlName = CDmeCombinationOperator::GetControlName(this: pComboOp, i: j);
                if ( pPurgeAllButThese != nullptr )
                {
                  v12 = 0;
                  if ( pPurgeAllButThese->m_Size > 0 )
                    break;
                }
LABEL_18:
                if ( CDmePresetGroup::FindPreset(this: (CDmePresetGroup *)pPresetGroup, pPresetName: pControlName) != nullptr )
                  goto LABEL_19;
LABEL_87:
                if ( ++j >= nControlCount )
                  goto LABEL_88;
              }
              v13 = 0;
              while ( 1 )
              {
                v14 = CUtlString::operator char const *(this: &pPurgeAllButThese->m_Memory.m_pMemory[v13]);
                if ( _V_strcmp(s1: pControlName, s2: v14) == 0 )
                  break;
                ++v12;
                ++v13;
                if ( v12 >= pPurgeAllButThese->m_Size )
                  goto LABEL_18;
              }
LABEL_19:
              v15 = j;
              IsStereoControl = CDmeCombinationOperator::IsStereoControl(this: pComboOp, nControlIndex: j);
              bStereo = IsStereoControl;
              IsMultiControl = CDmeCombinationOperator::IsMultiControl(this: pComboOp, nControlIndex: v15);
              v18 = pControlName;
              bMulti = IsMultiControl;
              if ( _V_strcmp(s1: pControlName, s2) == 0 )
              {
                v19 = CDmePreset::FindOrAddControlValue(this: pDstPreset, pControlName: v18);
                if ( IsStereoControl )
                {
                  value = 1.0;
                  Attribute = CDmElement::FindAttribute(this: v19, pAttributeName: "leftValue");
                  if ( Attribute != nullptr
                    || (Attribute = CDmElement::CreateAttribute(this: v19, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
                  {
                    CDmAttribute::SetValue<float>(this: Attribute, &value);
                  }
                  v69 = 1065353216;
                  v21 = CDmElement::FindAttribute(this: v19, pAttributeName: "rightValue");
                  if ( v21 != nullptr
                    || (v21 = CDmElement::CreateAttribute(this: v19, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
                  {
                    CDmAttribute::SetValue<float>(this: v21, value: (float *)&v69);
                  }
                }
                else
                {
                  v60 = 1.0;
                  v22 = CDmElement::FindAttribute(this: v19, pAttributeName: "value");
                  if ( v22 != nullptr
                    || (v22 = CDmElement::CreateAttribute(this: v19, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
                  {
                    CDmAttribute::SetValue<float>(this: v22, value: &v60);
                  }
                }
                if ( !bMulti )
                  goto LABEL_87;
                CFmtStrN<256>::CFmtStrN<256>(this: &multiControlName, pszFormat: "%s_multi", pControlName);
                v23 = CDmePreset::FindOrAddControlValue(this: pDstPreset, pControlName: multiControlName.m_szBuf);
                v67 = 0.5;
                v24 = CDmElement::FindAttribute(this: v23, pAttributeName: "value");
                if ( v24 == nullptr )
                {
                  v24 = CDmElement::CreateAttribute(this: v23, pAttributeName: "value", type: AT_FLOAT);
                  if ( v24 == nullptr )
                    goto LABEL_87;
                }
                v25 = &v67;
                goto LABEL_86;
              }
              v26 = 0;
              if ( nControlValueCount <= 0 )
              {
LABEL_72:
                v44 = CDmePreset::FindOrAddControlValue(this: pDstPreset, pControlName);
                ControlDefaultValue = CDmeCombinationOperator::GetControlDefaultValue(this: pComboOp, nControl: j);
                if ( IsStereoControl )
                {
                  flValue = ControlDefaultValue;
                  v46 = CDmElement::FindAttribute(this: v44, pAttributeName: "leftValue");
                  if ( v46 != nullptr
                    || (v46 = CDmElement::CreateAttribute(this: v44, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
                  {
                    CDmAttribute::SetValue<float>(this: v46, value: &flValue);
                  }
                  v47 = CDmElement::FindAttribute(this: v44, pAttributeName: "rightValue");
                  if ( v47 != nullptr
                    || (v47 = CDmElement::CreateAttribute(this: v44, pAttributeName: "rightValue", type: AT_FLOAT)) != nullptr )
                  {
                    CDmAttribute::SetValue<float>(this: v47, value: &flValue);
                  }
                }
                else
                {
                  v68 = ControlDefaultValue;
                  v48 = CDmElement::FindAttribute(this: v44, pAttributeName: "value");
                  if ( v48 != nullptr
                    || (v48 = CDmElement::CreateAttribute(this: v44, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
                  {
                    CDmAttribute::SetValue<float>(this: v48, value: &v68);
                  }
                }
                if ( !bMulti )
                  goto LABEL_87;
                CFmtStrN<256>::CFmtStrN<256>(this: &multiControlName, pszFormat: "%s_multi", pControlName);
                v49 = CDmePreset::FindOrAddControlValue(this: pDstPreset, pControlName: multiControlName.m_szBuf);
                v66 = 1056964608;
                v24 = CDmElement::FindAttribute(this: v49, pAttributeName: "value");
                if ( v24 == nullptr )
                {
                  v24 = CDmElement::CreateAttribute(this: v49, pAttributeName: "value", type: AT_FLOAT);
                  if ( v24 == nullptr )
                    goto LABEL_87;
                }
                v25 = (float *)&v66;
LABEL_86:
                CDmAttribute::SetValue<float>(this: v24, value: v25);
                goto LABEL_87;
              }
              while ( 1 )
              {
                v27 = g_pDataModel->GetElement(this: g_pDataModel, a2: controlValues->m_Storage.m_Memory.m_pMemory[v26]);
                v28 = v27;
                if ( v27 != nullptr && v27->IsA(this: v27, a2: CDmElement::m_classType) )
                {
                  m_pAsString = v28->m_Name.m_Storage.u.m_pAsString;
                  if ( m_pAsString == (const char *)-1 )
                    m_pAsString = var;
                  if ( _V_strcmp(s1: pControlName, s2: m_pAsString) == 0 )
                    break;
                }
                if ( ++v26 >= nControlValueCount )
                  goto LABEL_72;
              }
              v30 = CDmePreset::FindOrAddControlValue(this: pDstPreset, pControlName);
              if ( bStereo )
              {
                v65 = 0;
                v31 = CDmElement::FindAttribute(this: v28, pAttributeName: "leftValue");
                if ( v31 != nullptr )
                  v32 = CDmAttribute::GetValue<float>(this: v31);
                else
                  v32 = (CDmaVar<float> *)&v65;
                v33 = CDmElement::FindAttribute(this: v30, pAttributeName: "leftValue");
                if ( v33 != nullptr
                  || (v33 = CDmElement::CreateAttribute(this: v30, pAttributeName: "leftValue", type: AT_FLOAT)) != nullptr )
                {
                  CDmAttribute::SetValue<float>(this: v33, value: &v32->m_Storage);
                }
                v62 = 0;
                v34 = CDmElement::FindAttribute(this: v28, pAttributeName: "rightValue");
                if ( v34 != nullptr )
                  v35 = CDmAttribute::GetValue<float>(this: v34);
                else
                  v35 = (CDmaVar<float> *)&v62;
                v36 = CDmElement::FindAttribute(this: v30, pAttributeName: "rightValue");
                if ( v36 != nullptr )
                  goto LABEL_60;
                v36 = CDmElement::CreateAttribute(this: v30, pAttributeName: "rightValue", type: AT_FLOAT);
              }
              else
              {
                v71 = 0;
                v37 = CDmElement::FindAttribute(this: v28, pAttributeName: "value");
                if ( v37 != nullptr )
                  v35 = CDmAttribute::GetValue<float>(this: v37);
                else
                  v35 = (CDmaVar<float> *)&v71;
                v36 = CDmElement::FindAttribute(this: v30, pAttributeName: "value");
                if ( v36 != nullptr )
                  goto LABEL_60;
                v36 = CDmElement::CreateAttribute(this: v30, pAttributeName: "value", type: AT_FLOAT);
              }
              if ( v36 == nullptr )
              {
LABEL_61:
                if ( bMulti )
                {
                  CFmtStrN<256>::CFmtStrN<256>(this: &multiControlName, pszFormat: "%s_multi", pControlName);
                  ControlValue = CDmePreset::FindControlValue(this: v76, pControlName: multiControlName.m_szBuf);
                  m_Storage = 0.5;
                  v40 = CDmePreset::FindOrAddControlValue(this: pDstPreset, pControlName: multiControlName.m_szBuf);
                  if ( ControlValue != nullptr )
                  {
                    v70 = 1056964608;
                    v41 = CDmElement::FindAttribute(this: ControlValue, pAttributeName: "value");
                    if ( v41 != nullptr )
                      v42 = CDmAttribute::GetValue<float>(this: v41);
                    else
                      v42 = (CDmaVar<float> *)&v70;
                    m_Storage = v42->m_Storage;
                  }
                  v78 = m_Storage;
                  v43 = CDmElement::FindAttribute(this: v40, pAttributeName: "value");
                  if ( v43 != nullptr
                    || (v43 = CDmElement::CreateAttribute(this: v40, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
                  {
                    CDmAttribute::SetValue<float>(this: v43, value: &v78);
                  }
                }
                if ( v30 != nullptr )
                  goto LABEL_87;
                IsStereoControl = bStereo;
                goto LABEL_72;
              }
LABEL_60:
              CDmAttribute::SetValue<float>(this: v36, value: &v35->m_Storage);
              goto LABEL_61;
            }
          }
LABEL_88:
          ++i;
        }
        while ( i < nPresetsCount );
        V_strncpy(pDest: buf, pSrc: pExpressionFile, maxLen: 260);
        V_SetExtension(path: buf, extension: ".txt", pathStringLength: 260);
        V_ExtractFilePath(path: buf, dest: buf1, destSize: 260);
        V_FixSlashes(pname: buf1, separator: 92);
        g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: buf1, a3: nullptr);
        v50 = CP4Factory::AccessFile(this: g_p4factory, szFilename: buf);
        if ( !v50->Edit(this: v50) )
        {
          v51 = CP4Factory::AccessFile(this: g_p4factory, szFilename: buf);
          v51->Add(this: v51);
        }
        v52 = pDstPresetGroup;
        CDmePresetGroup::ExportToTXT(this: pDstPresetGroup, pFileName: buf, pAnimationSet: nullptr, pComboOp);
        V_SetExtension(path: buf, extension: ".vfe", pathStringLength: 260);
        V_ExtractFilePath(path: buf, dest: buf1, destSize: 260);
        V_FixSlashes(pname: buf1, separator: 92);
        g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: buf1, a3: nullptr);
        v53 = CP4Factory::AccessFile(this: g_p4factory, szFilename: buf);
        if ( !v53->Edit(this: v53) )
        {
          v54 = CP4Factory::AccessFile(this: g_p4factory, szFilename: buf);
          v54->Add(this: v54);
        }
        CDmePresetGroup::ExportToVFE(this: v52, pFileName: buf, pAnimationSet: nullptr, pComboOp);
        g_pDataModel->UnloadFile(this: g_pDataModel, a2: v52->m_fileId);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045B960
// Name: public: bool CUtlMap<int,int,unsigned short>::IsValidIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMap<int,int,unsigned short>::IsValidIndex(
        CUtlMap<int,int,unsigned short> *this,
        unsigned __int16 i)
{
  return i < this->m_Tree.m_Elements.m_nAllocationCount
      && i <= this->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &this->m_Tree,
           i) != i;
}

//------------------------------------------------------------------------------
// Address: 0x0045B9A0
// Name: MergeJointData
// Source: json
//------------------------------------------------------------------------------
void __usercall MergeJointData(
        CDmeVertexData *pDstBase@<ecx>,
        CDmeVertexData *pSrcBase@<eax>,
        CUtlMap<int,int,unsigned short> *jointMap)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ebx
  int m_Storage; // edx
  CDmrGenericArray *v10; // eax
  CDmAttribute *m_pVertexData; // ebx
  CDmAttribute *v12; // esi
  CDmAttribute *v13; // esi
  CDmAttribute *v14; // esi
  int v15; // ebx
  IUndoElement_vtbl *v16; // edi
  int m_Size; // esi
  int v18; // edi
  int v19; // edi
  unsigned __int16 v20; // ax
  int v21; // ebx
  float v22; // xmm0_4
  int v23; // edi
  float v24; // xmm0_4
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+8h] [ebp-50h] BYREF
  CDmrArrayConst<float> srcWeights; // [esp+10h] [ebp-48h] BYREF
  CDmrArrayConst<int> srcIndices; // [esp+18h] [ebp-40h] BYREF
  CDmrArray<int> dstIndices; // [esp+20h] [ebp-38h] BYREF
  CDmrArray<float> dstWeights; // [esp+28h] [ebp-30h] BYREF
  CDmrGenericArray v30; // [esp+30h] [ebp-28h] BYREF
  float j; // [esp+34h] [ebp-24h]
  float v32; // [esp+38h] [ebp-20h] BYREF
  int value; // [esp+3Ch] [ebp-1Ch] BYREF
  int nSrcJointCount; // [esp+40h] [ebp-18h]
  int nSrcPosCount; // [esp+44h] [ebp-14h] BYREF
  int i; // [esp+48h] [ebp-10h]
  int nDstJointCount; // [esp+4Ch] [ebp-Ch]
  float flTotalWeight; // [esp+50h] [ebp-8h]
  int nDstJointIndicesIndex; // [esp+54h] [ebp-4h]

  if ( pSrcBase != nullptr && pDstBase != nullptr )
  {
    v5 = pSrcBase->m_pStandardFieldIndex[0];
    v6 = pSrcBase->m_pStandardFieldIndex[6];
    flTotalWeight = *(float *)&pDstBase->m_pStandardFieldIndex[5];
    v7 = pDstBase->m_pStandardFieldIndex[6];
    v8 = pSrcBase->m_pStandardFieldIndex[5];
    i = v6;
    nDstJointIndicesIndex = v7;
    if ( v5 >= 0 && v8 >= 0 && v6 >= 0 && flTotalWeight >= 0.0 && v7 >= 0 )
    {
      m_Storage = pDstBase->m_nJointCount.m_Storage;
      nSrcJointCount = pSrcBase->m_nJointCount.m_Storage;
      nDstJointCount = m_Storage;
      if ( nSrcJointCount > 0 && m_Storage > 0 )
      {
        v10 = CDmrGenericArray::CDmrGenericArray(
                this: &v30,
                pAttribute: pSrcBase->m_FieldInfo.m_Memory.m_pMemory[v5].m_pVertexData);
        nSrcPosCount = CDmrGenericArrayConst::Count(this: v10);
        m_pVertexData = pSrcBase->m_FieldInfo.m_Memory.m_pMemory[v8].m_pVertexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcWeights);
        CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
          this: &srcWeights,
          pAttribute: m_pVertexData);
        v12 = pSrcBase->m_FieldInfo.m_Memory.m_pMemory[i].m_pVertexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcIndices);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: &srcIndices,
          pAttribute: v12);
        v13 = pDstBase->m_FieldInfo.m_Memory.m_pMemory[LODWORD(flTotalWeight)].m_pVertexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&dstWeights);
        CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
          this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&dstWeights,
          pAttribute: v13);
        v14 = pDstBase->m_FieldInfo.m_Memory.m_pMemory[nDstJointIndicesIndex].m_pVertexData;
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&dstIndices);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&dstIndices,
          pAttribute: v14);
        v15 = nDstJointCount;
        v16 = (IUndoElement_vtbl *)(nDstJointCount * nSrcPosCount);
        m_Size = dstWeights.m_pStorage->m_Size;
        nDstJointIndicesIndex = 0;
        CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddMultipleToTail(
          this: &dstWeights,
          num: nDstJointCount * nSrcPosCount);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::AddMultipleToTail(
          this: &dstIndices,
          num: v16);
        while ( m_Size < dstWeights.m_pStorage->m_Size )
        {
          v18 = 0;
          flTotalWeight = 0.0;
          i = 0;
          if ( v15 > 0 )
          {
            do
            {
              if ( v18 >= nSrcJointCount )
              {
                v32 = 0.0;
                CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
                  this: &dstWeights,
                  i: m_Size,
                  value: &v32);
                value = -1;
                CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
                  this: &dstIndices,
                  i: m_Size,
                  &value);
              }
              else
              {
                v19 = nDstJointIndicesIndex;
                search.key = srcIndices.m_pStorage->m_Memory.m_pMemory[nDstJointIndicesIndex];
                v20 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                        this: &jointMap->m_Tree,
                        &search);
                v21 = v20;
                if ( CUtlMap<int,int,unsigned short>::IsValidIndex(this: jointMap, i: v20) )
                {
                  CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
                    this: &dstWeights,
                    i: m_Size,
                    value: &srcWeights.m_pStorage->m_Memory.m_pMemory[v19]);
                  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
                    this: &dstIndices,
                    i: m_Size,
                    value: &jointMap->m_Tree.m_Elements.m_pMemory[v21].m_Data.elem);
                  v22 = dstWeights.m_pStorage->m_Memory.m_pMemory[m_Size] + flTotalWeight;
                  ++nDstJointIndicesIndex;
                  v18 = i;
                  v15 = nDstJointCount;
                  flTotalWeight = v22;
                }
                else
                {
                  _Warning(
                    a1: "Can't Joint Index %d On Src Isn't Mapped To Dst\n",
                    srcIndices.m_pStorage->m_Memory.m_pMemory[v19]);
                  nSrcPosCount = 0;
                  CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
                    this: &dstWeights,
                    i: m_Size,
                    value: (float *)&nSrcPosCount);
                  value = -1;
                  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
                    this: &dstIndices,
                    i: m_Size,
                    &value);
                  ++nDstJointIndicesIndex;
                  v18 = i;
                  v15 = nDstJointCount;
                }
              }
              ++v18;
              ++m_Size;
              i = v18;
            }
            while ( v18 < v15 );
            if ( flTotalWeight > 0.0
              && COERCE_FLOAT(COERCE_UNSIGNED_INT(flTotalWeight - 1.0) & _mask__AbsFloat_) > 0.00001192092895507812 )
            {
              v23 = m_Size - v15;
              if ( m_Size - v15 < m_Size )
              {
                v24 = 1.0 / flTotalWeight;
                for ( j = 1.0 / flTotalWeight; ; v24 = j )
                {
                  *(float *)&v30.m_pAttribute = dstWeights.m_pStorage->m_Memory.m_pMemory[v23] * v24;
                  CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
                    this: &dstWeights,
                    i: v23++,
                    value: (float *)&v30);
                  if ( v23 >= m_Size )
                    break;
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BCA0
// Name: int MergeBaseState(class CDmeVertexData __near *,class CDmeVertexData __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,int,int __near &,int __near &,int __near &,class CUtlMap<int,int,unsigned short> __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MergeBaseState(
        CDmeVertexData *pSrcBase,
        CDmeVertexData *pDstBase,
        const matrix3x4_t *pMat,
        const matrix3x4_t *nMat,
        int nSkinningJointIndex,
        int *nPositionOffset,
        int *nNormalOffset,
        int *nWrinkleOffset,
        CUtlMap<int,int,unsigned short> *pSkinMap)
{
  CDmeVertexData *v9; // ebx
  CDmeVertexData *v10; // edi
  int v11; // ecx
  int v12; // esi
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // eax
  int v17; // esi
  int v18; // esi
  int v19; // eax
  int v20; // esi
  int v21; // ecx
  int v22; // esi
  int v23; // esi
  const char *v24; // eax
  int v25; // esi
  const char *v26; // eax
  CDmAttribute *v27; // esi
  CDmAttribute *v28; // edi
  CDmrGenericArray *v29; // eax
  int m_Size; // esi
  int v31; // edi
  int v32; // esi
  int v33; // edi
  int v34; // esi
  int v35; // edi
  int v36; // esi
  int v37; // edi
  int v38; // esi
  int v39; // edi
  IUndoElement_vtbl *v40; // esi
  int v41; // edi
  CDmAttribute *v42; // esi
  CDmAttribute *v43; // esi
  IUndoElement_vtbl *v44; // edi
  int v45; // ebx
  int k; // esi
  const char *v47; // eax
  int v48; // esi
  CDmeVertexData *v49; // esi
  int v50; // esi
  const char *v51; // eax
  CDmeVertexDataBase::FieldInfo_t *v52; // eax
  CDmAttribute *v53; // esi
  int v54; // eax
  CDmrGenericArray *v55; // eax
  CDmeVertexDataBase::FieldInfo_t *v56; // edx
  CDmAttribute *v57; // esi
  int v58; // esi
  const char *v60; // [esp-4h] [ebp-ECh]
  const char *v61; // [esp-4h] [ebp-ECh]
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v62; // [esp+Ch] [ebp-DCh] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v63; // [esp+14h] [ebp-D4h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v64; // [esp+1Ch] [ebp-CCh] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v65; // [esp+24h] [ebp-C4h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v66; // [esp+2Ch] [ebp-BCh] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v67; // [esp+34h] [ebp-B4h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v68; // [esp+3Ch] [ebp-ACh] BYREF
  int nSrcJointWeightsIndex; // [esp+44h] [ebp-A4h]
  CDmrArray<int> srcIndices; // [esp+48h] [ebp-A0h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v71; // [esp+50h] [ebp-98h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v72; // [esp+58h] [ebp-90h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v73; // [esp+60h] [ebp-88h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v74; // [esp+68h] [ebp-80h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v75; // [esp+70h] [ebp-78h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v76; // [esp+78h] [ebp-70h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v77; // [esp+80h] [ebp-68h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v78; // [esp+88h] [ebp-60h] BYREF
  int nDstJointIndicesIndex; // [esp+90h] [ebp-58h]
  int nSrcNormalIndex; // [esp+94h] [ebp-54h]
  int nDstJointWeightsIndex; // [esp+98h] [ebp-50h]
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v82; // [esp+9Ch] [ebp-4Ch] BYREF
  int nSrcJointIndicesIndex; // [esp+A4h] [ebp-44h]
  int nSrcPositionIndex; // [esp+A8h] [ebp-40h]
  int nSrcWrinkleIndex; // [esp+ACh] [ebp-3Ch]
  CDmrArray<float> dstWeights; // [esp+B0h] [ebp-38h] BYREF
  int nRetVal; // [esp+B8h] [ebp-30h]
  CDmrArray<int> dstIndices; // [esp+BCh] [ebp-2Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v89; // [esp+C4h] [ebp-24h] BYREF
  int nOffset; // [esp+CCh] [ebp-1Ch] BYREF
  int j; // [esp+D0h] [ebp-18h] BYREF
  int nDstCount; // [esp+D4h] [ebp-14h]
  bool bMerged; // [esp+DBh] [ebp-Dh]
  int nJointCount; // [esp+DCh] [ebp-Ch]
  int nDstIndex; // [esp+E0h] [ebp-8h] BYREF
  int i; // [esp+E4h] [ebp-4h] BYREF
  CDmeVertexData *pSrcBasea; // [esp+F0h] [ebp+8h]
  CDmeVertexData *pDstBasea; // [esp+F4h] [ebp+Ch]

  v9 = pDstBase;
  v10 = pSrcBase;
  v11 = pSrcBase->m_pStandardFieldIndex[9];
  v12 = pSrcBase->m_pStandardFieldIndex[0];
  v13 = pSrcBase->m_pStandardFieldIndex[5];
  nSrcNormalIndex = pSrcBase->m_pStandardFieldIndex[1];
  nSrcJointIndicesIndex = pSrcBase->m_pStandardFieldIndex[6];
  v14 = pDstBase->m_pStandardFieldIndex[5];
  nSrcWrinkleIndex = v11;
  v15 = pDstBase->m_pStandardFieldIndex[6];
  nRetVal = -1;
  nSrcPositionIndex = v12;
  nSrcJointWeightsIndex = v13;
  nDstJointWeightsIndex = v14;
  nDstJointIndicesIndex = v15;
  if ( v14 >= 0 && v15 >= 0 )
  {
    if ( pSkinMap != nullptr && v13 >= 0 && nSrcJointIndicesIndex >= 0 )
    {
      MergeJointData(pDstBase, pSrcBase, jointMap: pSkinMap);
    }
    else
    {
      if ( nSkinningJointIndex < 0 )
      {
        _Msg(a1: "Warning: Destination mesh is skinned but no valid joint specified to skin to, using first joint\n");
        nSkinningJointIndex = 0;
      }
      m_pMemory = pSrcBase->m_FieldInfo.m_Memory.m_pMemory;
      nJointCount = pDstBase->m_nJointCount.m_Storage;
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&j, pAttribute: m_pMemory[v12].m_pVertexData);
      v17 = CDmrGenericArrayConst::Count(this: (CDmrGenericArrayConst *)&j);
      i = (int)pDstBase->m_FieldInfo.m_Memory.m_pMemory[nDstJointWeightsIndex].m_pVertexData;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&dstWeights);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&dstWeights,
        pAttribute: (CDmAttribute *)i);
      i = (int)pDstBase->m_FieldInfo.m_Memory.m_pMemory[nDstJointIndicesIndex].m_pVertexData;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&dstIndices);
      CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
        this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&dstIndices,
        pAttribute: (CDmAttribute *)i);
      v18 = nJointCount * v17;
      nDstCount = dstWeights.m_pStorage->m_Size;
      CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddMultipleToTail(
        this: &dstWeights,
        num: v18);
      CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::AddMultipleToTail(
        this: &dstIndices,
        num: (IUndoElement_vtbl *)v18);
      v19 = nDstCount;
      nDstIndex = v18 + nDstCount;
      v20 = nDstCount;
      if ( nDstCount < nDstIndex )
      {
        do
        {
          i = 1065353216;
          CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
            this: &dstWeights,
            i: v20,
            value: (float *)&i);
          CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
            this: &dstIndices,
            i: v20,
            value: &nSkinningJointIndex);
          v20 += nJointCount;
        }
        while ( v20 < nDstIndex );
        v19 = nDstCount;
      }
      v21 = 1;
      for ( i = 1; v21 < nJointCount; i = v21 )
      {
        v22 = v21 + v19;
        if ( v21 + v19 < nDstIndex )
        {
          do
          {
            nOffset = 0;
            CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
              this: &dstWeights,
              i: v22,
              value: (float *)&nOffset);
            CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
              this: &dstIndices,
              i: v22,
              value: &nSkinningJointIndex);
            v22 += nJointCount;
          }
          while ( v22 < nDstIndex );
          v19 = nDstCount;
          v21 = i;
        }
        ++v21;
      }
    }
  }
  i = -1;
  nJointCount = 0;
  if ( CDmeTrack::GetClipCount(this: pSrcBase) > 0 )
  {
    nDstIndex = 0;
    do
    {
      v23 = 0;
      bMerged = false;
      j = 0;
      if ( CDmeTrack::GetClipCount(this: v9) <= 0 )
        goto LABEL_50;
      nDstCount = 0;
      do
      {
        v24 = CDmeVertexDataBase::FieldName(this: v9, i: v23);
        v25 = nJointCount;
        v60 = v24;
        v26 = CDmeVertexDataBase::FieldName(this: v10, i: nJointCount);
        if ( _V_strcmp(s1: v26, s2: v60) == 0 )
        {
          bMerged = true;
          if ( v25 != nSrcJointWeightsIndex && v25 != nSrcJointIndicesIndex )
          {
            v27 = *(CDmAttribute **)((char *)&v10->m_FieldInfo.m_Memory.m_pMemory->m_pVertexData + nDstIndex);
            v28 = *(CDmAttribute **)((char *)&v9->m_FieldInfo.m_Memory.m_pMemory->m_pVertexData + nDstCount);
            v29 = CDmrGenericArray::CDmrGenericArray(
                    this: (CDmrGenericArray *)&dstWeights.m_pAttribute,
                    pAttribute: v28);
            nOffset = CDmrGenericArrayConst::Count(this: v29);
            switch ( v27->m_nFlags & 0x1F )
            {
              case 0x11:
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v78);
                CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
                  this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v78,
                  pAttribute: v28);
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v66);
                CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
                  this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v66,
                  pAttribute: v27);
                m_Size = v66.m_pStorage->m_Size;
                v31 = v78.m_pStorage->m_Size;
                CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddMultipleToTail(
                  this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v78,
                  num: m_Size);
                CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::SetMultiple(
                  this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v78,
                  i: v31,
                  nCount: m_Size,
                  pValue: (const float *)v66.m_pStorage->m_Memory.m_pMemory);
                break;
              case 0x16:
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v75);
                CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
                  this: (CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v75,
                  pAttribute: v28);
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v71);
                CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
                  this: (CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v71,
                  pAttribute: v27);
                v40 = (IUndoElement_vtbl *)v71.m_pStorage->m_Size;
                v41 = v75.m_pStorage->m_Size;
                CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::AddMultipleToTail(
                  this: (CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > *)&v75,
                  num: v40);
                CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::SetMultiple(
                  this: (CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > *)&v75,
                  i: v41,
                  nCount: (int)v40,
                  pValue: (const Color *)v71.m_pStorage->m_Memory.m_pMemory);
                break;
              case 0x17:
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v76);
                CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
                  this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v76,
                  pAttribute: v28);
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v68);
                CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
                  this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v68,
                  pAttribute: v27);
                v32 = v68.m_pStorage->m_Size;
                v33 = v76.m_pStorage->m_Size;
                CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::AddMultipleToTail(
                  this: (CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > *)&v76,
                  num: v32);
                CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>::SetMultiple(
                  this: (CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > *)&v76,
                  i: v33,
                  nCount: v32,
                  pValue: (const Vector2D *)v68.m_pStorage->m_Memory.m_pMemory);
                break;
              case 0x18:
                if ( nJointCount == nSrcPositionIndex )
                {
                  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v64);
                  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
                    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v64,
                    pAttribute: v28);
                  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v62);
                  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
                    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v62,
                    pAttribute: v27);
                  AppendData<Vector>(
                    srcData: (const CDmrArrayConst<Vector> *)&v62,
                    dstData: (CDmrArray<Vector> *)&v64,
                    pMat);
                }
                else if ( nJointCount == nSrcNormalIndex )
                {
                  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v63);
                  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
                    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v63,
                    pAttribute: v28);
                  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v82);
                  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
                    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v82,
                    pAttribute: v27);
                  AppendData<Vector>(
                    srcData: (const CDmrArrayConst<Vector> *)&v82,
                    dstData: (CDmrArray<Vector> *)&v63,
                    pMat: nMat);
                }
                else
                {
                  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v73);
                  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
                    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v73,
                    pAttribute: v28);
                  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v72);
                  CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
                    this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v72,
                    pAttribute: v27);
                  v34 = v72.m_pStorage->m_Size;
                  v35 = v73.m_pStorage->m_Size;
                  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::AddMultipleToTail(
                    this: (CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *)&v73,
                    num: v34);
                  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::SetMultiple(
                    this: (CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *)&v73,
                    i: v35,
                    nCount: v34,
                    pValue: (const Vector *)v72.m_pStorage->m_Memory.m_pMemory);
                }
                break;
              case 0x19:
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v74);
                CDmrDecorator<Vector4D,CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>>::Init(
                  this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&v74,
                  pAttribute: v28);
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v67);
                CDmrDecorator<Vector4D,CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>>::Init(
                  this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&v67,
                  pAttribute: v27);
                v36 = v67.m_pStorage->m_Size;
                v37 = v74.m_pStorage->m_Size;
                CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>::AddMultipleToTail(
                  this: (CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > *)&v74,
                  num: v36);
                CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>::SetMultiple(
                  this: (CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > *)&v74,
                  i: v37,
                  nCount: v36,
                  pValue: (const Vector4D *)v67.m_pStorage->m_Memory.m_pMemory);
                break;
              case 0x1B:
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v77);
                CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
                  this: (CDmrDecoratorConst<Quaternion,CDmaArrayConstBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > > *)&v77,
                  pAttribute: v28);
                CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v65);
                CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
                  this: (CDmrDecoratorConst<Quaternion,CDmaArrayConstBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > > *)&v65,
                  pAttribute: v27);
                v38 = v65.m_pStorage->m_Size;
                v39 = v77.m_pStorage->m_Size;
                CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::AddMultipleToTail(
                  this: (CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *)&v77,
                  num: v38);
                CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>::SetMultiple(
                  this: (CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > *)&v77,
                  i: v39,
                  nCount: v38,
                  pValue: (const Quaternion *)v65.m_pStorage->m_Memory.m_pMemory);
                break;
              default:
                break;
            }
            v42 = *(CDmAttribute **)((char *)&pSrcBase->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + nDstIndex);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&srcIndices);
            CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
              this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&srcIndices,
              pAttribute: v42);
            v43 = *(CDmAttribute **)((char *)&v9->m_FieldInfo.m_Memory.m_pMemory->m_pIndexData + nDstCount);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v89);
            CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
              this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v89,
              pAttribute: v43);
            v44 = (IUndoElement_vtbl *)srcIndices.m_pStorage->m_Size;
            v45 = v89.m_pStorage->m_Size;
            if ( nRetVal < 0 )
              nRetVal = v89.m_pStorage->m_Size;
            CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::AddMultipleToTail(
              this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v89,
              num: v44);
            if ( i < 0 )
              i = (int)v44;
            for ( k = 0; k < (int)v44; ++k )
            {
              dstIndices.m_pAttribute = (CDmAttribute *)(nOffset + srcIndices.m_pStorage->m_Memory.m_pMemory[k]);
              CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
                this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v89,
                i: k + v45,
                value: (int *)&dstIndices.m_pAttribute);
            }
            if ( nJointCount == nSrcPositionIndex )
            {
              *nPositionOffset = nOffset;
            }
            else if ( nJointCount == nSrcNormalIndex )
            {
              *nNormalOffset = nOffset;
            }
            else if ( nJointCount == nSrcWrinkleIndex )
            {
              *nWrinkleOffset = nOffset;
            }
            v10 = pSrcBase;
            v9 = pDstBase;
          }
        }
        nDstCount += 48;
        v23 = ++j;
      }
      while ( v23 < CDmeTrack::GetClipCount(this: v9) );
      if ( !bMerged )
      {
LABEL_50:
        v47 = CDmeVertexDataBase::FieldName(this: v10, i: nJointCount);
        _Msg(a1: "Warning: Not merging base data %s\n", v47);
      }
      nDstIndex += 48;
      v48 = ++nJointCount;
    }
    while ( v48 < CDmeTrack::GetClipCount(this: v10) );
  }
  v49 = nullptr;
  nSrcWrinkleIndex = v9->m_pStandardFieldIndex[8];
  pDstBasea = nullptr;
  if ( CDmeTrack::GetClipCount(this: v9) > 0 )
  {
    pSrcBasea = nullptr;
    do
    {
      if ( v49 != (CDmeVertexData *)nDstJointWeightsIndex && v49 != (CDmeVertexData *)nDstJointIndicesIndex )
      {
        v50 = 0;
        if ( CDmeTrack::GetClipCount(this: v10) <= 0 )
        {
LABEL_59:
          v52 = v9->m_FieldInfo.m_Memory.m_pMemory;
          nDstIndex = -1;
          if ( pDstBasea == (CDmeVertexData *)nSrcWrinkleIndex )
          {
            dstIndices.m_pAttribute = (CDmAttribute *)1065353216;
            v53 = *(CDmAttribute **)((char *)&v52->m_pVertexData + (_DWORD)pSrcBasea);
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v82);
            CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
              this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v82,
              pAttribute: v53);
            v54 = CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
                    this: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > *)&v82,
                    src: (float *)&dstIndices.m_pAttribute);
          }
          else
          {
            v55 = CDmrGenericArray::CDmrGenericArray(
                    this: (CDmrGenericArray *)&dstWeights.m_pAttribute,
                    pAttribute: *(CDmAttribute **)((char *)&v52->m_pVertexData + (_DWORD)pSrcBasea));
            v54 = CDmrGenericArray::AddToTail(this: v55);
          }
          v56 = v9->m_FieldInfo.m_Memory.m_pMemory;
          nDstIndex = v54;
          v57 = *(CDmAttribute **)((char *)&v56->m_pIndexData + (_DWORD)pSrcBasea);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v89);
          CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
            this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v89,
            pAttribute: v57);
          v58 = v89.m_pStorage->m_Size;
          j = v58 + i;
          CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::AddMultipleToTail(
            this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v89,
            num: (IUndoElement_vtbl *)i);
          for ( ; v58 < j; ++v58 )
            CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
              this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v89,
              i: v58,
              value: &nDstIndex);
        }
        else
        {
          while ( 1 )
          {
            v61 = CDmeVertexDataBase::FieldName(this: v10, i: v50);
            v51 = CDmeVertexDataBase::FieldName(this: v9, i: (int)pDstBasea);
            if ( _V_strcmp(s1: v51, s2: v61) == 0 )
              break;
            if ( ++v50 >= CDmeTrack::GetClipCount(this: v10) )
              goto LABEL_59;
          }
        }
      }
      pSrcBasea = (CDmeVertexData *)((char *)pSrcBasea + 48);
      pDstBasea = (CDmeVertexData *)((char *)pDstBasea + 1);
      v49 = pDstBasea;
    }
    while ( (int)pDstBasea < CDmeTrack::GetClipCount(this: v9) );
  }
  v9->Resolve(this: v9);
  return nRetVal;
}

//------------------------------------------------------------------------------
// Address: 0x0045C480
// Name: public: static bool CDmMeshUtils::Merge(class CDmeMesh __near *,class CDmeMesh __near *,int,class CUtlMap<int,int,unsigned short> __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::Merge(
        CExpressionCalculator *pSrcMesh,
        CExpressionCalculator *pDstMesh,
        int nSkinningJointIndex,
        CUtlMap<int,int,unsigned short> *pJointMap)
{
  CDmeMesh *v4; // edi
  CUtlSymbolLarge *v5; // eax
  CDmeDag *Referring; // esi
  CUtlSymbolLarge *v7; // eax
  CDmeDag *v8; // eax
  CDmeDag *v9; // ebx
  bool v10; // cc
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  int v13; // ebx
  bool v14; // al
  CDmElement *v15; // eax
  CDmeVertexData *v16; // esi
  const char *m_pAsString; // eax
  const char *Name; // eax
  int v19; // eax
  const char *v20; // esi
  const char *v21; // eax
  CDmeFaceSet *FaceSet; // eax
  CDmeFaceSet *v23; // esi
  int m_Size; // ebx
  int j; // edi
  int v26; // eax
  int v27; // esi
  int k; // esi
  CDmeVertexDeltaData *DeltaState; // ebx
  const char *v30; // eax
  CDmeVertexDeltaData *v31; // eax
  const char *v33; // [esp-Ch] [ebp-C4h]
  const char *v34; // [esp-4h] [ebp-BCh]
  const char *v35; // [esp-4h] [ebp-BCh]
  matrix3x4_t dMatInv; // [esp+Ch] [ebp-ACh] BYREF
  matrix3x4_t nMat; // [esp+3Ch] [ebp-7Ch] BYREF
  matrix3x4_t pMat; // [esp+6Ch] [ebp-4Ch] BYREF
  int nWrinkleOffset; // [esp+9Ch] [ebp-1Ch] BYREF
  int nNormalOffset; // [esp+A0h] [ebp-18h] BYREF
  int nPositionOffset; // [esp+A4h] [ebp-14h] BYREF
  int nVertexOffset; // [esp+A8h] [ebp-10h]
  CDmElement *v43; // [esp+ACh] [ebp-Ch]
  int i; // [esp+B0h] [ebp-8h]
  bool bMerged; // [esp+B7h] [ebp-1h]

  if ( pSrcMesh == nullptr )
    return 0;
  v4 = (CDmeMesh *)pDstMesh;
  if ( pDstMesh == nullptr )
    return 0;
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &nPositionOffset, a3: "shape");
  Referring = FindReferringElement<CDmeDag>(
                pElement: pSrcMesh,
                symAttrName: (CUtlSymbolLarge)v5->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  v7 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &nNormalOffset, a3: "shape");
  v8 = FindReferringElement<CDmeDag>(
         pElement: pDstMesh,
         symAttrName: (CUtlSymbolLarge)v7->u.m_Id,
         bMustBeInSameFile: true,
         depth: TD_ALL);
  v9 = v8;
  if ( Referring == nullptr || v8 == nullptr )
    return 0;
  CDmeDag::GetAbsTransform(this: Referring, matAbsTransform: &nMat);
  CDmeDag::GetAbsTransform(this: v9, matAbsTransform: &pMat);
  MatrixInvert(in: &pMat, out: &dMatInv);
  ConcatTransforms(in1: &dMatInv, in2: &nMat, out: &pMat);
  MatrixInverseTranspose(src: &pMat, dst: &nMat);
  nPositionOffset = -1;
  nNormalOffset = -1;
  nWrinkleOffset = -1;
  nVertexOffset = -1;
  v10 = (int)pSrcMesh[1].m_varNames.m_pElements <= 0;
  i = 0;
  if ( !v10 )
  {
    do
    {
      v11 = g_pDataModel->GetElement(
              this: g_pDataModel,
              a2: *(_DWORD *)(pSrcMesh[1].m_varNames.m_Memory.m_nAllocationCount + 4 * i));
      v12 = v11;
      v13 = 0;
      if ( v11 == nullptr || (v14 = v11->IsA(this: v11, a2: CDmeVertexData::m_classType), v43 = v12, !v14) )
        v43 = nullptr;
      bMerged = false;
      if ( (int)pDstMesh[1].m_varNames.m_pElements <= 0 )
        goto LABEL_20;
      do
      {
        v15 = g_pDataModel->GetElement(
                this: g_pDataModel,
                a2: *(_DWORD *)(pDstMesh[1].m_varNames.m_Memory.m_nAllocationCount + 4 * v13));
        v16 = (CDmeVertexData *)v15;
        if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmeVertexData::m_classType) )
          v16 = nullptr;
        m_pAsString = v16->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = var;
        v34 = m_pAsString;
        Name = CDmElement::GetName(this: v43);
        if ( _V_strcmp(s1: Name, s2: v34) == 0 )
        {
          bMerged = true;
          v19 = MergeBaseState(
                  pSrcBase: (CDmeVertexData *)v43,
                  pDstBase: v16,
                  &pMat,
                  &nMat,
                  nSkinningJointIndex,
                  &nPositionOffset,
                  &nNormalOffset,
                  &nWrinkleOffset,
                  pSkinMap: pJointMap);
          if ( nVertexOffset < 0 )
            nVertexOffset = v19;
        }
        ++v13;
      }
      while ( v13 < (int)pDstMesh[1].m_varNames.m_pElements );
      if ( !bMerged )
      {
LABEL_20:
        v20 = v43->m_Name.m_Storage.u.m_pAsString;
        if ( v20 == (const char *)-1 )
          v20 = var;
        v35 = CDmElement::GetName(this: (CDmElement *)pDstMesh);
        v33 = CDmElement::GetName(this: (CDmElement *)pDstMesh);
        v21 = CDmElement::GetName(this: (CDmElement *)pSrcMesh);
        _Msg(a1: "Error: Merge( %s, %s ) - Can't Find Base State %s On %s\n", v21, v33, v20, v35);
      }
      ++i;
    }
    while ( i < (int)pSrcMesh[1].m_varNames.m_pElements );
  }
  i = 0;
  if ( CDmeMesh::FaceSetCount(this: (CDmeMesh *)pSrcMesh) > 0 )
  {
    do
    {
      FaceSet = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: (CDmeMesh *)pSrcMesh, faceSetIndex: i);
      v23 = (CDmeFaceSet *)CDmElement::CopyInternal(this: FaceSet, depth: TD_DEEP);
      CDmElement::SetFileId(this: v23, fileid: v4->m_fileId, depth: TD_DEEP, bOnlyIfMatch: false);
      m_Size = v23->m_indices.m_Storage.m_Size;
      for ( j = 0; j < m_Size; ++j )
      {
        v26 = v23->m_indices.m_Storage.m_Memory.m_pMemory[j];
        if ( v26 >= 0 )
          CDmeFaceSet::SetIndex(this: v23, i: j, nValue: nVertexOffset + v26);
      }
      CDmeMesh::AddFaceSet(this: (CDmeMesh *)pDstMesh, faceSet: v23);
      v27 = ++i;
      v4 = (CDmeMesh *)pDstMesh;
    }
    while ( v27 < CDmeMesh::FaceSetCount(this: (CDmeMesh *)pSrcMesh) );
  }
  for ( k = 0; k < CDmeMesh::DeltaStateCount(this: (CDmeMesh *)pSrcMesh); ++k )
  {
    DeltaState = CDmeMesh::GetDeltaState(this: (CDmeMesh *)pSrcMesh, nDeltaIndex: k);
    v30 = DeltaState->m_Name.m_Storage.u.m_pAsString;
    if ( v30 == (const char *)-1 )
      v30 = var;
    v31 = CDmeMesh::FindDeltaState(this: v4, pDeltaName: v30, bSortDeltaName: true);
    MergeDeltaState(
      pDmeMesh: v4,
      pSrcDelta: DeltaState,
      pDstDelta: v31,
      &nPositionOffset,
      &nNormalOffset,
      &nWrinkleOffset);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C7A0
// Name: void RampInit<int>(class CUtlVector<int,class CUtlMemory<int,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RampInit<int>(CUtlVector<int,CUtlMemory<int,int> > *utlVector, int nCount)
{
  int i; // eax

  utlVector->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)utlVector,
    elem: 0,
    num: nCount);
  for ( i = 0; i < nCount; ++i )
    utlVector->m_Memory.m_pMemory[i] = i;
}

//------------------------------------------------------------------------------
// Address: 0x0045C7D0
// Name: protected: static int const __near * CDmMeshUtils::BuildDataMirrorMap(class CDmeVertexData __near *,int,enum CDmeVertexDataBase::StandardFields_t,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
DmeTime_t *__cdecl CDmMeshUtils::BuildDataMirrorMap(
        CDmeVertexData *pBase,
        int axis,
        CDmeVertexDataBase::StandardFields_t standardField,
        CUtlVector<int,CUtlMemory<int,int> > *dataMirrorMap)
{
  int v4; // eax
  int v6; // edi
  CDmAttribute *m_pIndexData; // esi
  CDmAttribute **p_m_pVertexData; // eax
  CDmAttribute *v9; // edx
  int v10; // esi
  CDmAttribute *v11; // edi
  int v12; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v13; // edi
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *v14; // ecx
  int v15; // eax
  int v16; // ecx
  CDmeVertexDataBase::StandardFields_t v17; // esi
  int v18; // edx
  int *m_pMemory; // ebx
  int *v20; // ebx
  int *v21; // ebx
  int *v22; // ebx
  int v23; // edx
  int *v24; // esi
  CDmrGenericArrayConst *v25; // eax
  int v26; // eax
  CDmAttribute *v27; // xmm0_4
  CDmAttribute *v28; // edi
  int v29; // edi
  CUtlVector<int,CUtlMemory<int,int> > *v30; // ebx
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *v31; // ecx
  int v32; // eax
  int v33; // ecx
  Vector v; // [esp+4h] [ebp-30h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v35; // [esp+10h] [ebp-24h] BYREF
  Vector2D mirrorOrigin; // [esp+18h] [ebp-1Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v37; // [esp+20h] [ebp-14h] BYREF
  float mirrorAxisVal; // [esp+28h] [ebp-Ch]
  int nDataCount; // [esp+2Ch] [ebp-8h]
  int nMirrorDataCount; // [esp+30h] [ebp-4h]
  float pBasea; // [esp+3Ch] [ebp+8h]
  CDmeVertexData *pBaseb; // [esp+3Ch] [ebp+8h]

  v4 = pBase->m_pStandardFieldIndex[standardField];
  if ( v4 < 0 )
    return nullptr;
  v6 = v4;
  m_pIndexData = pBase->m_FieldInfo.m_Memory.m_pMemory[v4].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v35);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v35,
    pAttribute: m_pIndexData);
  p_m_pVertexData = &pBase->m_FieldInfo.m_Memory.m_pMemory[v6].m_pVertexData;
  v9 = *p_m_pVertexData;
  v10 = 0;
  if ( (unsigned int)standardField < FIELD_TANGENT )
  {
    memset(&v, 0, sizeof(v));
    v27 = *((CDmAttribute **)&v.x + axis);
    nDataCount = 4 * axis;
    v37.m_pAttribute = v27;
    mirrorAxisVal = *(float *)&v27;
    v28 = v9;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mirrorOrigin);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&mirrorOrigin,
      pAttribute: v28);
    v29 = *(_DWORD *)(LODWORD(mirrorOrigin.x) + 12);
    v30 = dataMirrorMap;
    v31 = (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)dataMirrorMap;
    dataMirrorMap->m_Size = 0;
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
      this: v31,
      elem: 0,
      num: v29);
    nMirrorDataCount = v29;
    if ( v29 > 0 )
    {
      pBaseb = nullptr;
      standardField = nDataCount;
      do
      {
        if ( COERCE_FLOAT(
               COERCE_UNSIGNED_INT(*(float *)(*(_DWORD *)LODWORD(mirrorOrigin.x) + standardField) - mirrorAxisVal)
             & _mask__AbsFloat_) <= 0.00011920929 )
        {
          v33 = nDataCount;
          v30->m_Memory.m_pMemory[v10] = v10;
          v = *(Vector *)((char *)&pBaseb->__vftable + *(_DWORD *)LODWORD(mirrorOrigin.x));
          *(_DWORD *)((char *)&v.x + v33) = v37.m_pAttribute;
          CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::Set(
            this: (CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *)&mirrorOrigin,
            i: v10,
            value: &v);
        }
        else
        {
          v32 = nMirrorDataCount;
          v30->m_Memory.m_pMemory[v10] = nMirrorDataCount;
          nMirrorDataCount = v32 + 1;
        }
        standardField += 12;
        pBaseb = (CDmeVertexData *)((char *)pBaseb + 12);
        ++v10;
      }
      while ( v10 < v29 );
    }
    return v35.m_pStorage->m_Memory.m_pMemory;
  }
  if ( standardField != FIELD_TEXCOORD )
  {
    v25 = CDmrGenericArrayConst::CDmrGenericArrayConst(
            this: (CDmrGenericArrayConst *)&standardField,
            pAttribute: *p_m_pVertexData);
    v26 = CDmrGenericArrayConst::Count(this: v25);
    RampInit<int>(utlVector: dataMirrorMap, nCount: v26);
    return v35.m_pStorage->m_Memory.m_pMemory;
  }
  mirrorOrigin.x = 0.5;
  mirrorOrigin.y = 0.5;
  pBasea = *(&mirrorOrigin.x + axis % 2);
  v11 = v9;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v37);
  CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
    this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v37,
    pAttribute: v11);
  v13 = dataMirrorMap;
  v14 = (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)dataMirrorMap;
  nDataCount = v37.m_pStorage->m_Size;
  v12 = nDataCount;
  dataMirrorMap->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: v14,
    elem: 0,
    num: v12);
  v15 = 0;
  v16 = v12;
  if ( v12 >= 4 )
  {
    v17 = 4 * axis + 16;
    v18 = 2;
    for ( standardField = v17; ; v17 = standardField )
    {
      m_pMemory = v13->m_Memory.m_pMemory;
      if ( fabs(*(float *)((char *)&v37.m_pStorage->m_Memory.m_pMemory[-4].m_tms + v17) - pBasea) <= 0.00011920929 )
        m_pMemory[v15] = v15;
      else
        m_pMemory[v15] = v16++;
      v20 = v13->m_Memory.m_pMemory;
      if ( fabs(*(float *)((char *)&v37.m_pStorage->m_Memory.m_pMemory[-2].m_tms + v17) - pBasea) <= 0.00011920929 )
      {
        v20[v15 + 1] = v18 - 1;
        v17 = standardField;
      }
      else
      {
        v20[v15 + 1] = v16++;
      }
      v21 = v13->m_Memory.m_pMemory;
      if ( fabs(*(float *)((char *)&v37.m_pStorage->m_Memory.m_pMemory->m_tms + v17) - pBasea) <= 0.00011920929 )
        v21[v15 + 2] = v18;
      else
        v21[v15 + 2] = v16++;
      v22 = v13->m_Memory.m_pMemory;
      if ( fabs(*(float *)((char *)&v37.m_pStorage->m_Memory.m_pMemory[2].m_tms + v17) - pBasea) <= 0.00011920929 )
      {
        v22[v15 + 3] = v18 + 1;
        v17 = standardField;
      }
      else
      {
        v22[v15 + 3] = v16++;
      }
      v12 = nDataCount;
      standardField = v17 + 32;
      v15 += 4;
      v18 += 4;
      if ( v15 >= nDataCount - 3 )
        break;
    }
  }
  if ( v15 >= v12 )
    return v35.m_pStorage->m_Memory.m_pMemory;
  v23 = axis + 2 * v15;
  do
  {
    v24 = v13->m_Memory.m_pMemory;
    if ( fabs(*(float *)&v37.m_pStorage->m_Memory.m_pMemory[v23].m_tms - pBasea) <= 0.00011920929 )
      v24[v15] = v15;
    else
      v24[v15] = v16++;
    ++v15;
    v23 += 2;
  }
  while ( v15 < v12 );
  return v35.m_pStorage->m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x0045CAF0
// Name: protected: static bool CDmMeshUtils::MirrorVertices(class CDmeMesh __near *,class CDmeVertexData __near *,int,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::MirrorVertices(
        CDmeMesh *pMesh,
        CDmeVertexData *pBase,
        unsigned int axis,
        CUtlVector<int,CUtlMemory<int,int> > *mirrorMap)
{
  int v4; // eax
  CDmAttribute *m_pIndexData; // esi
  int v6; // esi
  unsigned int v7; // esi
  CDmAttribute *v8; // edi
  CDmeVertexDataBase::FieldInfo_t *m_pMemory; // ecx
  CDmAttribute *m_pVertexData; // esi
  const int *m_Size; // edi
  int v12; // esi
  const int *v13; // ecx
  const int *v14; // ecx
  char *v15; // eax
  DmeTime_t *v17; // eax
  int v18; // esi
  int v19; // ebx
  int v20; // ecx
  bool v21; // dl
  int v23; // ebx
  CDmElement *v24; // eax
  CDmeVertexData *v25; // esi
  int v26; // ebx
  int i; // esi
  CDmeVertexDeltaData *DeltaState; // eax
  CUtlVector<int,CUtlMemory<int,int> > normalMirrorMap; // [esp+Ch] [ebp-70h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > posMirrorMap; // [esp+20h] [ebp-5Ch] BYREF
  CUtlVector<int,CUtlMemory<int,int> > uvMirrorMap; // [esp+34h] [ebp-48h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v32; // [esp+48h] [ebp-34h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v33; // [esp+50h] [ebp-2Ch] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v34; // [esp+58h] [ebp-24h] BYREF
  int nIndices; // [esp+60h] [ebp-1Ch]
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pStorage; // [esp+64h] [ebp-18h]
  int v37; // [esp+68h] [ebp-14h]
  float v38; // [esp+6Ch] [ebp-10h]
  const int *pNormalIndices; // [esp+70h] [ebp-Ch]
  const int *pUVIndices; // [esp+74h] [ebp-8h]
  int mirrorCount; // [esp+78h] [ebp-4h]
  int nBaseState; // [esp+84h] [ebp+8h]

  mirrorMap->m_Size = 0;
  if ( pMesh == nullptr )
    return 0;
  if ( pBase == nullptr )
    return 0;
  if ( axis > 2 )
    return 0;
  v4 = pBase->m_pStandardFieldIndex[0];
  if ( v4 < 0 )
    return 0;
  m_pIndexData = pBase->m_FieldInfo.m_Memory.m_pMemory[v4].m_pIndexData;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v33);
  CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v33,
    pAttribute: m_pIndexData);
  v6 = pBase->m_pStandardFieldIndex[0];
  nIndices = v33.m_pStorage->m_Size;
  memset(&posMirrorMap, 0, sizeof(posMirrorMap));
  if ( v6 >= 0 )
  {
    v7 = v6;
    v8 = pBase->m_FieldInfo.m_Memory.m_pMemory[v7].m_pIndexData;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v32);
    CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
      this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v32,
      pAttribute: v8);
    m_pMemory = pBase->m_FieldInfo.m_Memory.m_pMemory;
    m_pStorage = v32.m_pStorage;
    memset(&uvMirrorMap.m_Memory.m_nGrowSize, 0, 12);
    m_pVertexData = m_pMemory[v7].m_pVertexData;
    v37 = *(&uvMirrorMap.m_Memory.m_nGrowSize + axis);
    v38 = *(float *)&v37;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v34);
    CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
      this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v34,
      pAttribute: m_pVertexData);
    m_Size = (const int *)v34.m_pStorage->m_Size;
    v12 = 0;
    posMirrorMap.m_Size = 0;
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)&posMirrorMap,
      elem: 0,
      num: (int)m_Size);
    pUVIndices = m_Size;
    if ( (int)m_Size > 0 )
    {
      v13 = (const int *)(4 * axis);
      mirrorCount = 0;
      pNormalIndices = (const int *)(4 * axis);
      do
      {
        if ( COERCE_FLOAT(
               COERCE_UNSIGNED_INT(*(float *)((char *)&v34.m_pStorage->m_Memory.m_pMemory->m_tms + (unsigned int)v13) - v38)
             & _mask__AbsFloat_) <= 0.00011920929 )
        {
          posMirrorMap.m_Memory.m_pMemory[v12] = v12;
          v15 = (char *)v34.m_pStorage->m_Memory.m_pMemory + mirrorCount;
          uvMirrorMap.m_Memory.m_nGrowSize = *(_DWORD *)v15;
          uvMirrorMap.m_Size = *((_DWORD *)v15 + 1);
          uvMirrorMap.m_pElements = *((int **)v15 + 2);
          *(&uvMirrorMap.m_Memory.m_nGrowSize + axis) = v37;
          CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>::Set(
            this: (CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > *)&v34,
            i: v12,
            value: (const Vector *)&uvMirrorMap.m_Memory.m_nGrowSize);
        }
        else
        {
          v14 = pUVIndices;
          posMirrorMap.m_Memory.m_pMemory[v12] = (int)pUVIndices;
          pUVIndices = (const int *)((char *)v14 + 1);
        }
        mirrorCount += 12;
        ++v12;
        v13 = pNormalIndices + 3;
        pNormalIndices += 3;
      }
      while ( v12 < (int)m_Size );
    }
    if ( m_pStorage->m_Memory.m_pMemory != nullptr )
    {
      memset(&normalMirrorMap, 0, sizeof(normalMirrorMap));
      pNormalIndices = (const int *)CDmMeshUtils::BuildDataMirrorMap(
                                      pBase,
                                      axis,
                                      standardField: FIELD_NORMAL,
                                      dataMirrorMap: &normalMirrorMap);
      memset(&uvMirrorMap, 0, sizeof(uvMirrorMap));
      v17 = CDmMeshUtils::BuildDataMirrorMap(pBase, axis, standardField: FIELD_TEXCOORD, dataMirrorMap: &uvMirrorMap);
      v18 = nIndices;
      pUVIndices = &v17->m_tms;
      RampInit<int>(utlVector: mirrorMap, nCount: nIndices);
      v19 = 0;
      v20 = 0;
      mirrorCount = 0;
      if ( v18 > 0 )
      {
        mirrorCount = (int)pUVIndices;
        nIndices = (char *)pNormalIndices - (char *)pUVIndices;
        do
        {
          v21 = posMirrorMap.m_Memory.m_pMemory[v33.m_pStorage->m_Memory.m_pMemory[v20].m_tms] != v33.m_pStorage->m_Memory.m_pMemory[v20].m_tms;
          if ( pNormalIndices != nullptr
            && normalMirrorMap.m_Memory.m_pMemory[*(_DWORD *)(nIndices + mirrorCount)] != *(_DWORD *)(nIndices + mirrorCount) )
          {
            v21 = true;
          }
          if ( pUVIndices != nullptr && uvMirrorMap.m_Memory.m_pMemory[*(_DWORD *)mirrorCount] != *(_DWORD *)mirrorCount
            || v21 )
          {
            mirrorMap->m_Memory.m_pMemory[v20] = v19 + v18;
            ++v19;
          }
          mirrorCount += 4;
          ++v20;
        }
        while ( v20 < v18 );
        mirrorCount = v19;
      }
      v23 = 0;
      nBaseState = pMesh->m_BaseStates.m_Storage.m_Size;
      if ( nBaseState > 0 )
      {
        do
        {
          v24 = g_pDataModel->GetElement(this: g_pDataModel, a2: pMesh->m_BaseStates.m_Storage.m_Memory.m_pMemory[v23]);
          v25 = (CDmeVertexData *)v24;
          if ( v24 == nullptr || !v24->IsA(this: v24, a2: CDmeVertexData::m_classType) )
            v25 = nullptr;
          CDmMeshUtils::MirrorVertices(
            pBase: v25,
            axis,
            nOldVertexCount: v25->m_nVertexCount,
            nMirrorCount: mirrorCount,
            mirrorMap,
            &posMirrorMap,
            &normalMirrorMap,
            &uvMirrorMap);
          ++v23;
        }
        while ( v23 < nBaseState );
      }
      v26 = CDmeMesh::DeltaStateCount(this: pMesh);
      for ( i = 0; i < v26; ++i )
      {
        DeltaState = CDmeMesh::GetDeltaState(this: pMesh, nDeltaIndex: i);
        CDmMeshUtils::MirrorDelta(pDelta: DeltaState, axis, &posMirrorMap, &normalMirrorMap, &uvMirrorMap);
      }
      if ( uvMirrorMap.m_Memory.m_nGrowSize >= 0 && uvMirrorMap.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: uvMirrorMap.m_Memory.m_pMemory);
      if ( normalMirrorMap.m_Memory.m_nGrowSize >= 0 && normalMirrorMap.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: normalMirrorMap.m_Memory.m_pMemory);
      if ( posMirrorMap.m_Memory.m_nGrowSize >= 0 && posMirrorMap.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: posMirrorMap.m_Memory.m_pMemory);
      return 1;
    }
  }
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&posMirrorMap);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045CF30
// Name: void ComputeVertexIndexMap(class CDmeMesh __near *,int,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeVertexIndexMap(
        CDmeMesh *pMesh,
        int nMaxVertexCount,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *vertexIndexMap)
{
  void *v3; // esp
  int v4; // esi
  const CDmeFaceSet *FaceSet; // eax
  int m_Size; // edx
  int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int *v9; // ecx
  int v10; // eax
  int i; // eax
  int j; // edi
  void *v13; // esp
  int v14; // ebx
  int v15; // eax
  int *v16; // ecx
  CDmeFaceSet *v17; // edi
  int v18; // ebx
  int k; // esi
  int v20; // eax
  unsigned __int8 v21[12]; // [esp+0h] [ebp-10h] BYREF
  int v22; // [esp+Ch] [ebp-4h]
  signed int count; // [esp+1Ch] [ebp+Ch]

  v3 = alloca(nMaxVertexCount);
  memset(dst: v21, value: 0, count: nMaxVertexCount);
  v4 = 0;
  v22 = CDmeMesh::FaceSetCount(this: pMesh);
  if ( v22 > 0 )
  {
    do
    {
      FaceSet = CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: v4);
      m_Size = FaceSet->m_indices.m_Storage.m_Size;
      if ( m_Size > 0 )
      {
        m_pMemory = FaceSet->m_indices.m_Storage.m_Memory.m_pMemory;
        do
        {
          if ( *m_pMemory >= 0 )
            v21[*m_pMemory] = 1;
          ++m_pMemory;
          --m_Size;
        }
        while ( m_Size != 0 );
      }
      ++v4;
    }
    while ( v4 < v22 );
  }
  vertexIndexMap[1].m_pMemory = nullptr;
  if ( nMaxVertexCount != 0 )
  {
    m_nAllocationCount = vertexIndexMap->m_nAllocationCount;
    if ( nMaxVertexCount > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: vertexIndexMap, num: nMaxVertexCount - m_nAllocationCount);
    vertexIndexMap[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)vertexIndexMap[1].m_pMemory
                                                                   + nMaxVertexCount);
    v9 = (int *)vertexIndexMap->m_pMemory;
    v10 = (int)vertexIndexMap[1].m_pMemory - nMaxVertexCount;
    vertexIndexMap[1].m_nAllocationCount = (int)vertexIndexMap->m_pMemory;
    if ( v10 > 0 && nMaxVertexCount > 0 )
      _V_memmove(dest: &v9[nMaxVertexCount], src: v9, count: 4 * v10);
  }
  for ( i = 0; i < nMaxVertexCount; ++i )
    vertexIndexMap->m_pMemory[i] = (CUtlSymbolTable::StringPool_t *)i;
  for ( j = nMaxVertexCount - 1; j >= 0; --j )
  {
    if ( v21[j] == 0 )
    {
      if ( (int)vertexIndexMap[1].m_pMemory - j - 1 > 0 )
        _V_memmove(
          dest: &vertexIndexMap->m_pMemory[j],
          src: &vertexIndexMap->m_pMemory[j + 1],
          count: 4 * ((int)vertexIndexMap[1].m_pMemory - j - 1));
      --vertexIndexMap[1].m_pMemory;
    }
  }
  v13 = alloca(4 * nMaxVertexCount);
  v14 = v22;
  if ( v22 > 0 )
    memset(v21, 0xFFu, 4 * v22);
  v15 = (int)vertexIndexMap[1].m_pMemory - 1;
  if ( v15 >= 0 )
  {
    v16 = (int *)&vertexIndexMap->m_pMemory[v15];
    do
      *(_DWORD *)&v21[4 * *v16--] = v15--;
    while ( v15 >= 0 );
  }
  count = 0;
  if ( v14 > 0 )
  {
    do
    {
      v17 = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: count);
      v18 = v17->m_indices.m_Storage.m_Size;
      for ( k = 0; k < v18; ++k )
      {
        v20 = v17->m_indices.m_Storage.m_Memory.m_pMemory[k];
        if ( v20 >= 0 )
          CDmeFaceSet::SetIndex(this: v17, i: k, nValue: *(_DWORD *)&v21[4 * v20]);
      }
      ++count;
    }
    while ( count < v22 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D0C0
// Name: void RemoveUnusedData(class CDmeMesh __near *,class CDmeVertexData __near *,bool,char const __near *,int __near *,int,class CDmrGenericArray __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveUnusedData(
        CDmeMesh *pMesh,
        CDmeVertexData *pVertexData,
        bool bBind,
        char *pFieldName,
        int *pIndices,
        CDmrGenericArray nIndicesCount,
        CDmrGenericArray *data)
{
  int v7; // edi
  void *v8; // esp
  int m_pAttribute; // ecx
  int i; // eax
  int v11; // edx
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int j; // eax
  int v14; // esi
  CUtlSymbolTable::StringPool_t **v15; // ebx
  CDmAttribute *v16; // esi
  void *v17; // esp
  int k; // eax
  int v19; // esi
  int m; // eax
  int v21; // ebx
  CDmrGenericArray *v22; // esi
  CDmeVertexDeltaData *DeltaState; // edi
  int ClipCount; // eax
  int v25; // ecx
  int v26; // ebx
  const char *v27; // eax
  CDmAttribute *m_pIndexData; // esi
  int n; // esi
  int m_tms; // eax
  int v31; // edx
  CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > v32; // [esp-Ch] [ebp-40h] BYREF
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v33; // [esp-4h] [ebp-38h]
  unsigned __int8 v34[12]; // [esp+0h] [ebp-34h] BYREF
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> v35; // [esp+Ch] [ebp-28h] BYREF
  int v36; // [esp+18h] [ebp-1Ch]
  CUtlSymbolTable::StringPool_t **v37; // [esp+1Ch] [ebp-18h]
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v38; // [esp+20h] [ebp-14h] BYREF
  int v39; // [esp+28h] [ebp-Ch]
  int v40; // [esp+2Ch] [ebp-8h]
  unsigned __int8 *v41; // [esp+30h] [ebp-4h]
  int v42; // [esp+44h] [ebp+10h]

  v7 = CDmrGenericArrayConst::Count(this: data);
  v8 = alloca(v7);
  v41 = v34;
  memset(dst: v34, value: 0, count: v7);
  m_pAttribute = (int)nIndicesCount.m_pAttribute;
  for ( i = 0; i < m_pAttribute; v34[v11] = 1 )
    v11 = pIndices[i++];
  m_pMemory = nullptr;
  memset(&v35, 0, sizeof(v35));
  v37 = nullptr;
  v36 = 0;
  if ( v7 != 0 )
  {
    if ( v7 > 0 )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &v35, num: v7);
      m_pMemory = v35.m_pMemory;
    }
    v36 += v7;
    v37 = m_pMemory;
    if ( v36 - v7 > 0 && v7 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v7], src: m_pMemory, count: 4 * (v36 - v7));
      m_pMemory = v35.m_pMemory;
    }
  }
  for ( j = 0; j < v7; ++j )
    m_pMemory[j] = (CUtlSymbolTable::StringPool_t *)j;
  v14 = v7 - 1;
  if ( v7 - 1 >= 0 )
  {
    v15 = &m_pMemory[v14];
    do
    {
      if ( v41[v14] == 0 )
      {
        if ( v36 - v14 - 1 > 0 )
          _V_memmove(dest: v15, src: v15 + 1, count: 4 * (v36 - v14 - 1));
        --v36;
      }
      --v15;
      --v14;
    }
    while ( v14 >= 0 );
  }
  v16 = data->m_pAttribute;
  switch ( data->m_pAttribute->m_nFlags & 0x1F )
  {
    case 0x11:
      v33 = &v35;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v32);
      CDmrDecorator<float,CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
        this: (CDmrDecoratorConst<float,CDmaArrayConstBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > > > *)&v32,
        pAttribute: v16);
      RemapData<float>(
        data: (CDmaArrayBase<float,CDmaDataExternal<CUtlVector<float,CUtlMemory<float,int> > > >)v32,
        newToOldMap: (int)v33);
      break;
    case 0x16:
      v33 = &v35;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v32);
      CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
        this: (CDmrDecoratorConst<Color,CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v32,
        pAttribute: v16);
      RemapData<Color>(
        data: (CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > >)v32,
        newToOldMap: (const CUtlVector<int,CUtlMemory<int,int> > *)v33);
      break;
    case 0x17:
      v33 = &v35;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v32);
      CDmrDecorator<Vector2D,CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>>>::Init(
        this: (CDmrDecoratorConst<Vector2D,CDmaArrayConstBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > > > *)&v32,
        pAttribute: v16);
      RemapData<Vector2D>(
        data: (CDmaArrayBase<Vector2D,CDmaDataExternal<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > >)v32,
        newToOldMap: (const CUtlVector<int,CUtlMemory<int,int> > *)v33);
      break;
    case 0x18:
      v33 = &v35;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v32);
      CDmrDecorator<Vector,CDmaArrayBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int>>>>>::Init(
        this: (CDmrDecoratorConst<Vector,CDmaArrayConstBase<Vector,CDmaDataExternal<CUtlVector<Vector,CUtlMemory<Vector,int> > > > > *)&v32,
        pAttribute: v16);
      RemapData<Vector>(data: v32, newToOldMap: (const CUtlVector<int,CUtlMemory<int,int> > *)v33);
      break;
    case 0x19:
      v33 = &v35;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v32);
      CDmrDecorator<Vector4D,CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>>>::Init(
        this: (CDmrDecoratorConst<Vector4D,CDmaArrayConstBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > > > *)&v32,
        pAttribute: v16);
      RemapData<Vector4D>(
        data: (CDmaArrayBase<Vector4D,CDmaDataExternal<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > >)v32,
        newToOldMap: (const CUtlVector<int,CUtlMemory<int,int> > *)v33);
      break;
    case 0x1B:
      v33 = &v35;
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&v32);
      CDmrDecorator<Quaternion,CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>>>::Init(
        this: (CDmrDecoratorConst<Quaternion,CDmaArrayConstBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > > > *)&v32,
        pAttribute: v16);
      RemapData<Quaternion>(
        data: (CDmaArrayBase<Quaternion,CDmaDataExternal<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > >)v32,
        newToOldMap: (const CUtlVector<int,CUtlMemory<int,int> > *)v33);
      break;
    default:
      break;
  }
  v17 = alloca(4 * v7);
  v41 = v34;
  if ( v7 > 0 )
    memset(v34, 0xFFu, 4 * v7);
  for ( k = v36 - 1; k >= 0; --k )
    *(_DWORD *)&v34[4 * (int)v35.m_pMemory[k]] = k;
  v19 = (int)nIndicesCount.m_pAttribute;
  for ( m = 0; m < v19; ++m )
    pIndices[m] = *(_DWORD *)&v34[4 * pIndices[m]];
  if ( _V_strcmp(s1: pFieldName, s2: "position") == 0 )
    CDmeTrack::GetClipCount(this: pVertexData);
  if ( bBind )
  {
    v21 = CDmeMesh::DeltaStateCount(this: pMesh);
    v22 = nullptr;
    v39 = v21;
    for ( data = nullptr; (int)v22 < v21; data = v22 )
    {
      DeltaState = CDmeMesh::GetDeltaState(this: pMesh, nDeltaIndex: (int)v22);
      ClipCount = CDmeTrack::GetClipCount(this: DeltaState);
      v25 = 0;
      v40 = ClipCount;
      v42 = 0;
      if ( ClipCount > 0 )
      {
        v26 = 0;
        do
        {
          v27 = CDmeVertexDataBase::FieldName(this: DeltaState, i: v25);
          if ( _V_strcmp(s1: pFieldName, s2: v27) == 0 )
          {
            m_pIndexData = DeltaState->m_FieldInfo.m_Memory.m_pMemory[v26].m_pIndexData;
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v38);
            CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
              this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v38,
              pAttribute: m_pIndexData);
            CDmrGenericArray::CDmrGenericArray(
              this: &nIndicesCount,
              pAttribute: DeltaState->m_FieldInfo.m_Memory.m_pMemory[v26].m_pVertexData);
            for ( n = v38.m_pStorage->m_Size - 1; n >= 0; --n )
            {
              m_tms = v38.m_pStorage->m_Memory.m_pMemory[n].m_tms;
              v31 = *(_DWORD *)&v41[4 * m_tms];
              if ( v31 >= 0 )
              {
                if ( v31 != m_tms )
                  CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
                    this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v38,
                    i: n,
                    value: (int *)&v41[4 * m_tms]);
              }
              else
              {
                CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::Remove(
                  this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v38,
                  elem: n);
                CDmrGenericArray::Remove(this: &nIndicesCount, elem: n);
              }
            }
          }
          v25 = v42 + 1;
          ++v26;
          v42 = v25;
        }
        while ( v25 < v40 );
        v21 = v39;
        v22 = data;
      }
      v22 = (CDmrGenericArray *)((char *)v22 + 1);
    }
  }
  if ( v35.m_nGrowSize >= 0 && v35.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v35.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0045D430
// Name: void RemoveUnusedVerticesFromBaseState(class CDmeMesh __near *,class CDmeVertexData __near *,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveUnusedVerticesFromBaseState(
        CDmeMesh *pMesh,
        CDmeVertexData *pVertexData,
        const CUtlVector<int,CUtlMemory<int,int> > *newToOldIndexMap)
{
  CDmrGenericArray v3; // esi
  void *v4; // esp
  const char *m_pAsString; // eax
  int j; // eax
  CDmrGenericArray *v8; // eax
  int v9[3]; // [esp+0h] [ebp-30h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v10; // [esp+Ch] [ebp-24h] BYREF
  CDmrGenericArray v11; // [esp+14h] [ebp-1Ch] BYREF
  CDmrGenericArray v12; // [esp+18h] [ebp-18h] BYREF
  int ClipCount; // [esp+1Ch] [ebp-14h]
  bool bBind[4]; // [esp+20h] [ebp-10h]
  CDmAttribute *pAttribute; // [esp+24h] [ebp-Ch]
  char *s1; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]
  CDmeVertexDataBase *v18; // [esp+3Ch] [ebp+Ch]

  v3.m_pAttribute = (CDmAttribute *)newToOldIndexMap->m_Size;
  v4 = alloca(4 * (int)v3.m_pAttribute);
  m_pAsString = pVertexData->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  bBind[0] = _V_strcmp(s1: m_pAsString, s2: "bind") == 0;
  ClipCount = CDmeTrack::GetClipCount(this: pVertexData);
  i = 0;
  if ( ClipCount > 0 )
  {
    v18 = nullptr;
    do
    {
      s1 = (char *)CDmeVertexDataBase::FieldName(this: pVertexData, i);
      if ( _V_strcmp(s1, s2: "jointWeights") != 0 && _V_strcmp(s1, s2: "jointIndices") != 0 )
      {
        pAttribute = *(CDmAttribute **)((char *)&v18->m_Name.m_Storage.u.CDmElement::m_Id
                                      + (unsigned int)pVertexData->m_FieldInfo.m_Memory.m_pMemory);
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v10);
        CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
          this: (CDmrDecoratorConst<int,CDmaArrayConstBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > > *)&v10,
          pAttribute);
        for ( j = 0; j < (int)v3.m_pAttribute; ++j )
          v9[j] = v10.m_pStorage->m_Memory.m_pMemory[newToOldIndexMap->m_Memory.m_pMemory[j]].m_tms;
        CDmrGenericArray::CDmrGenericArray(
          this: &v12,
          pAttribute: *(CDmAttribute **)&v18->m_Id.m_Value[(unsigned int)pVertexData->m_FieldInfo.m_Memory.m_pMemory + 12]);
        v8 = CDmrGenericArray::CDmrGenericArray(
               this: &v11,
               pAttribute: *(CDmAttribute **)&v18->m_Id.m_Value[(unsigned int)pVertexData->m_FieldInfo.m_Memory.m_pMemory + 12]);
        RemoveUnusedData(pMesh, pVertexData, bBind: bBind[0], pFieldName: s1, pIndices: v9, nIndicesCount: v3, data: v8);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveMultiple(
          this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v10,
          elem: (int)v3.m_pAttribute,
          num: v10.m_pStorage->m_Size - (unsigned int)v3.m_pAttribute);
        CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
          this: (CDmaArrayBase<int,CDmaDataExternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v10,
          i: 0,
          nCount: (int)v3.m_pAttribute,
          pValue: v9);
      }
      v18 = (CDmeVertexDataBase *)((char *)v18 + 48);
      ++i;
    }
    while ( i < ClipCount );
  }
  pVertexData->Resolve(this: pVertexData);
}

//------------------------------------------------------------------------------
// Address: 0x0045D590
// Name: protected: static bool CDmMeshUtils::PurgeUnusedData(class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::PurgeUnusedData(CDmeMesh *pMesh)
{
  int MaxVertexCount; // eax
  int i; // edi
  CDmElement *v3; // eax
  CDmeVertexData *v4; // esi
  CUtlVector<int,CUtlMemory<int,int> > vertexIndexMap; // [esp+Ch] [ebp-14h] BYREF

  MaxVertexCount = GetMaxVertexCount(pMesh);
  memset(&vertexIndexMap, 0, sizeof(vertexIndexMap));
  ComputeVertexIndexMap(
    pMesh,
    nMaxVertexCount: MaxVertexCount,
    (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&vertexIndexMap);
  for ( i = pMesh->m_BaseStates.m_Storage.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: pMesh->m_BaseStates.m_Storage.m_Memory.m_pMemory[i]);
    v4 = (CDmeVertexData *)v3;
    if ( v3 == nullptr || !v3->IsA(this: v3, a2: CDmeVertexData::m_classType) )
      v4 = nullptr;
    RemoveUnusedVerticesFromBaseState(pMesh, pVertexData: v4, newToOldIndexMap: &vertexIndexMap);
  }
  if ( vertexIndexMap.m_Memory.m_nGrowSize >= 0 && vertexIndexMap.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertexIndexMap.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D640
// Name: public: static bool CDmMeshUtils::Mirror(class CDmeMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::Mirror(CDmeMesh *pMesh, unsigned int axis)
{
  CDmeMesh *v2; // edi
  CDmeVertexData *BaseState; // eax
  int *m_pMemory; // ebx
  int v6; // eax
  int v7; // ecx
  CDmeFaceSet *FaceSet; // eax
  int m_Size; // ecx
  CDmeMaterial *Material; // eax
  const char *v11; // edi
  int v12; // esi
  const char *v13; // eax
  CDmeFaceSet *v14; // esi
  const char *v15; // eax
  CDmeMaterial *v16; // edi
  const char *v17; // eax
  int v18; // eax
  int v19; // esi
  int v20; // ecx
  int v21; // edi
  int *v22; // eax
  int v23; // edi
  int v24; // esi
  int *v25; // edi
  int v26; // edi
  bool v27; // zf
  DmFileId_t m_fileId; // [esp-Ch] [ebp-74h]
  DmFileId_t v29; // [esp-Ch] [ebp-74h]
  CUtlVector<int,CUtlMemory<int,int> > mirrorMap; // [esp+8h] [ebp-60h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > newFaceIndices; // [esp+1Ch] [ebp-4Ch] BYREF
  CUtlString materialName; // [esp+30h] [ebp-38h] BYREF
  int nFaceSets; // [esp+40h] [ebp-28h]
  int *v34; // [esp+44h] [ebp-24h]
  int i; // [esp+48h] [ebp-20h]
  int nFaceSetIndices; // [esp+4Ch] [ebp-1Ch]
  int k; // [esp+50h] [ebp-18h]
  CDmeFaceSet *pSrcFaceSet; // [esp+54h] [ebp-14h]
  int v39; // [esp+58h] [ebp-10h]
  unsigned int v40; // [esp+5Ch] [ebp-Ch]
  int faceStart; // [esp+60h] [ebp-8h]
  CDmeFaceSet *pDstFaceSet; // [esp+64h] [ebp-4h]

  v2 = pMesh;
  BaseState = CDmeMesh::FindBaseState(this: pMesh, pStateName: "bind");
  if ( BaseState == nullptr )
    return 0;
  memset(&mirrorMap, 0, sizeof(mirrorMap));
  if ( CDmMeshUtils::MirrorVertices(pMesh, pBase: BaseState, axis, &mirrorMap) == 0 )
  {
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&mirrorMap);
    return 0;
  }
  m_pMemory = nullptr;
  memset(&newFaceIndices, 0, sizeof(newFaceIndices));
  v6 = CDmeMesh::FaceSetCount(this: pMesh);
  v7 = 0;
  nFaceSets = v6;
  i = 0;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      FaceSet = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: v2, faceSetIndex: v7);
      m_Size = FaceSet->m_indices.m_Storage.m_Size;
      pSrcFaceSet = FaceSet;
      nFaceSetIndices = m_Size;
      if ( m_Size > 0 )
      {
        pDstFaceSet = FaceSet;
        Material = CDmeFaceSet::GetMaterial(this: FaceSet);
        v11 = CDmeMaterial::GetMaterialName(this: Material);
        v12 = _V_strlen(str: v11);
        if ( v12 >= 2 )
        {
          CUtlString::CUtlString(this: &materialName);
          if ( _V_stricmp(s1: &v11[v12 - 2], s2: "_l") != 0 )
          {
            if ( _V_stricmp(s1: &v11[v12 - 2], s2: "_r") != 0 )
            {
              if ( v12 < 5 || _V_stricmp(s1: &v11[v12 - 5], s2: "_left") != 0 )
              {
                if ( v12 >= 6 && _V_stricmp(s1: &v11[v12 - 6], s2: "_right") == 0 )
                {
                  CUtlString::operator=(this: &materialName, src: v11);
                  CUtlString::SetLength(this: &materialName, nLen: v12 - 6);
                  CUtlString::operator+=(this: &materialName, rhs: "_left");
                }
              }
              else
              {
                CUtlString::operator=(this: &materialName, src: v11);
                CUtlString::SetLength(this: &materialName, nLen: v12 - 5);
                CUtlString::operator+=(this: &materialName, rhs: "_right");
              }
            }
            else
            {
              CUtlString::operator=(this: &materialName, src: v11);
              CUtlString::SetLength(this: &materialName, nLen: v12 - 2);
              CUtlString::operator+=(this: &materialName, rhs: "_l");
            }
          }
          else
          {
            CUtlString::operator=(this: &materialName, src: v11);
            CUtlString::SetLength(this: &materialName, nLen: v12 - 2);
            CUtlString::operator+=(this: &materialName, rhs: "_r");
          }
          if ( CUtlString::Length(this: &materialName) != 0 )
          {
            m_fileId = pMesh->m_fileId;
            v13 = CUtlString::operator char const *(this: &materialName);
            v14 = CreateElement<CDmeFaceSet>(pObjectName: v13, fileid: m_fileId, pObjectID: nullptr);
            v29 = v14->m_fileId;
            pDstFaceSet = v14;
            v15 = CUtlString::operator char const *(this: &materialName);
            v16 = CreateElement<CDmeMaterial>(pObjectName: v15, fileid: v29, pObjectID: nullptr);
            v17 = CUtlString::operator char const *(this: &materialName);
            CDmeMaterial::SetMaterial(this: v16, pMaterialName: v17);
            CDmeFaceSet::SetMaterial(this: v14, pMaterial: v16);
            CDmeMesh::AddFaceSet(this: pMesh, faceSet: v14);
          }
          materialName.m_Storage.m_nActualLength = 0;
          if ( materialName.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( materialName.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: materialName.m_Storage.m_Memory.m_pMemory);
              materialName.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            materialName.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
        faceStart = 0;
        if ( nFaceSetIndices > 0 )
        {
          v18 = -1;
          v39 = -1;
          v40 = 0;
          do
          {
            if ( pSrcFaceSet->m_indices.m_Storage.m_Memory.m_pMemory[v40 / 4] < 0 )
            {
              v19 = 0;
              newFaceIndices.m_Size = 0;
              v20 = v18;
              for ( k = v18; v20 >= faceStart; k = v20 )
              {
                v34 = &mirrorMap.m_Memory.m_pMemory[pSrcFaceSet->m_indices.m_Storage.m_Memory.m_pMemory[v20]];
                v21 = v19;
                if ( v19 + 1 > newFaceIndices.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<IDmFormatUpdater *,int>::Grow(
                    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newFaceIndices,
                    num: v19 - newFaceIndices.m_Memory.m_nAllocationCount + 1);
                  v19 = newFaceIndices.m_Size;
                  m_pMemory = newFaceIndices.m_Memory.m_pMemory;
                }
                newFaceIndices.m_Size = ++v19;
                newFaceIndices.m_pElements = m_pMemory;
                if ( v19 - v21 - 1 > 0 )
                  _V_memmove(dest: &m_pMemory[v21 + 1], src: &m_pMemory[v21], count: 4 * (v19 - v21 - 1));
                v22 = &m_pMemory[v21];
                if ( v22 != nullptr )
                  *v22 = *v34;
                v20 = k - 1;
              }
              v23 = v19;
              if ( v19 + 1 > newFaceIndices.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<IDmFormatUpdater *,int>::Grow(
                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newFaceIndices,
                  num: v19 - newFaceIndices.m_Memory.m_nAllocationCount + 1);
                v19 = newFaceIndices.m_Size;
                m_pMemory = newFaceIndices.m_Memory.m_pMemory;
              }
              v24 = v19 + 1;
              newFaceIndices.m_Size = v24;
              newFaceIndices.m_pElements = m_pMemory;
              if ( v24 - v23 - 1 > 0 )
                _V_memmove(dest: &m_pMemory[v23 + 1], src: &m_pMemory[v23], count: 4 * (v24 - v23 - 1));
              v25 = &m_pMemory[v23];
              if ( v25 != nullptr )
                *v25 = -1;
              v26 = pDstFaceSet->m_indices.m_Storage.m_Size;
              CDmeFaceSet::AddIndices(this: pDstFaceSet, nCount: v24);
              CDmeFaceSet::SetIndices(this: pDstFaceSet, nFirstIndex: v26, nCount: v24, pIndices: m_pMemory);
              faceStart = v39 + 2;
              v18 = v39;
            }
            v40 += 4;
            ++v18;
            v27 = nFaceSetIndices-- == 1;
            v39 = v18;
          }
          while ( !v27 );
        }
      }
      v7 = i + 1;
      i = v7;
      if ( v7 >= nFaceSets )
        break;
      v2 = pMesh;
    }
  }
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&newFaceIndices);
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&mirrorMap);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D9E0
// Name: public: static bool CDmMeshUtils::Merge(class CDmMeshComp __near &,class CUtlVector<class CDmMeshComp::CEdge __near *,class CUtlMemory<class CDmMeshComp::CEdge __near *,int>> const __near &,class CDmeMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::Merge(
        CDmMeshComp *srcComp,
        const CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *edgeList,
        CDmeMesh *pDstMesh)
{
  CDmeMesh *m_pMesh; // ecx
  CDmeMesh *v4; // esi
  CDmeVertexData *BaseState; // edi
  CDmeVertexData *v6; // eax
  CDmeVertexDataBase *v7; // esi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *PositionData; // edi
  int m_Size; // ebx
  int v10; // eax
  VertexWeightMap_s *m_pMemory; // esi
  int v12; // edx
  float *v13; // edi
  int v14; // ebx
  int v15; // eax
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  Vector *v19; // ecx
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  CDmeVertexData *v24; // ecx
  const CUtlVector<int,CUtlMemory<int,int> > *VertexIndicesFromDataIndex; // eax
  bool v26; // zf
  CDmeVertexData *v27; // ecx
  CDmeVertexData *v28; // esi
  CDmeMesh *v29; // edi
  CDmeMesh *v30; // eax
  CExpressionCalculator *v31; // ebx
  const char *m_pAsString; // eax
  const char *v33; // ecx
  CDmeVertexData *v35; // eax
  CDmeVertexData *v36; // edi
  CDmeCombinationOperator *Referring; // eax
  CDmAttribute *m_pAttribute; // ecx
  IDataModel_vtbl *v39; // esi
  int v40; // eax
  CUtlVector<VertexWeightMap_s,CUtlMemory<VertexWeightMap_s,int> > vertexWeightMap; // [esp+3Ch] [ebp-30h] BYREF
  CDmeMesh *pSrcMesh; // [esp+50h] [ebp-1Ch]
  int nDstCount; // [esp+54h] [ebp-18h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *srcPosData; // [esp+58h] [ebp-14h]
  int v45; // [esp+5Ch] [ebp-10h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *dstPosData; // [esp+60h] [ebp-Ch]
  float closest; // [esp+64h] [ebp-8h]
  CDmeVertexData *pDstData; // [esp+68h] [ebp-4h]

  m_pMesh = srcComp->m_pMesh;
  pSrcMesh = m_pMesh;
  if ( m_pMesh == nullptr )
    return 0;
  v4 = pDstMesh;
  if ( pDstMesh == nullptr )
    return 0;
  BaseState = CDmeMesh::FindBaseState(this: m_pMesh, pStateName: "bind");
  v6 = CDmeMesh::FindBaseState(this: v4, pStateName: "bind");
  v7 = v6;
  pDstData = v6;
  if ( BaseState == nullptr || v6 == nullptr )
    return 0;
  PositionData = CDmeVertexDataBase::GetPositionData(this: BaseState);
  m_Size = PositionData->m_Size;
  srcPosData = PositionData;
  dstPosData = CDmeVertexDataBase::GetPositionData(this: v7);
  v10 = dstPosData->m_Size;
  nDstCount = v10;
  if ( m_Size <= 0 || v10 <= 0 )
    return 0;
  memset(&vertexWeightMap, 0, sizeof(vertexWeightMap));
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(this: &vertexWeightMap, elem: 0, num: m_Size);
  m_pMemory = vertexWeightMap.m_Memory.m_pMemory;
  srcComp = nullptr;
  v45 = m_Size;
  while ( 1 )
  {
    v12 = nDstCount;
    m_pMemory->m_nVertexWeights = 0;
    v13 = (float *)((char *)srcComp + (unsigned int)PositionData->m_Memory.m_pMemory);
    v14 = -1;
    v15 = 0;
    closest = 3.4028235e38;
    if ( v12 <= 0 )
      goto LABEL_18;
    v16 = *v13;
    v17 = v13[1];
    v18 = v13[2];
    v19 = dstPosData->m_Memory.m_pMemory;
    while ( 1 )
    {
      v20 = v16 - v19->x;
      v21 = v17 - v19->y;
      v22 = v18 - v19->z;
      if ( (float)((float)((float)(v21 * v21) + (float)(v20 * v20)) + (float)(v22 * v22)) < 0.0000011920929 )
        break;
      v23 = (float)((float)(v21 * v21) + (float)(v20 * v20)) + (float)(v22 * v22);
      if ( closest > v23 )
      {
        closest = v23;
        v14 = v15;
      }
      ++v15;
      ++v19;
      if ( v15 >= v12 )
        goto LABEL_18;
    }
    v24 = pDstData;
    m_pMemory->m_nVertexWeights = 1;
    m_pMemory->m_vertexWeights[0].m_vertexDataIndex = v15;
    m_pMemory->m_vertexWeights[0].m_vertexWeight = 1.0;
    VertexIndicesFromDataIndex = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                   this: v24,
                                   fieldId: FIELD_POSITION,
                                   nDataIndex: v15);
    v26 = m_pMemory->m_nVertexWeights == 0;
    m_pMemory->m_vertexWeights[0].m_pVertexIndices = VertexIndicesFromDataIndex;
    if ( v26 )
    {
LABEL_18:
      _Warning(
        a1: "Warning: Merge() - No Match For Src Vertex: %f %f %f, Using Closest: %f %f %f\n",
        *v13,
        v13[1],
        v13[2],
        dstPosData->m_Memory.m_pMemory[v14].x,
        dstPosData->m_Memory.m_pMemory[v14].y,
        dstPosData->m_Memory.m_pMemory[v14].z);
      v27 = pDstData;
      m_pMemory->m_nVertexWeights = 1;
      m_pMemory->m_vertexWeights[0].m_vertexDataIndex = v14;
      m_pMemory->m_vertexWeights[0].m_vertexWeight = 1.0;
      m_pMemory->m_vertexWeights[0].m_pVertexIndices = CDmeVertexDataBase::FindVertexIndicesFromDataIndex(
                                                         this: v27,
                                                         fieldId: FIELD_POSITION,
                                                         nDataIndex: v14);
    }
    srcComp = (CDmMeshComp *)((char *)srcComp + 12);
    ++m_pMemory;
    if ( --v45 == 0 )
      break;
    PositionData = srcPosData;
  }
  v28 = pDstData;
  v29 = pSrcMesh;
  v30 = ReplaceMesh(pSrcMesh, pDstMesh);
  v31 = (CExpressionCalculator *)v30;
  if ( v30 == nullptr )
  {
    m_pAsString = v29->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    v33 = pDstMesh->m_Name.m_Storage.u.m_pAsString;
    if ( v33 == (const char *)-1 )
      v33 = var;
    _Error(a1: "Error: Merge() - Couldn't Replace Mesh %s With %s\n", v33, m_pAsString);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vertexWeightMap);
    return 0;
  }
  v35 = CDmeMesh::FindBaseState(this: v30, pStateName: "bind");
  v36 = v35;
  if ( v35 != nullptr )
  {
    CopyJointWeights(pSrcData: v28, pDstData: v35, &vertexWeightMap);
    CopyField(field: FIELD_BALANCE, pSrcData: v28, pDstData: v36, &vertexWeightMap);
    CopyField(field: FIELD_MORPH_SPEED, pSrcData: v28, pDstData: v36, &vertexWeightMap);
    if ( v36->m_pStandardFieldIndex[8] >= 0 )
    {
      Referring = FindReferringElement<CDmeCombinationOperator>(
                    pElement: v31,
                    pAttrName: "targets",
                    bMustBeInSameFile: true,
                    depth: TD_ALL);
      if ( Referring != nullptr )
      {
        m_pAttribute = Referring->m_bSpecifyingLaggedData.m_pAttribute;
        LOBYTE(srcComp) = 1;
        CDmAttribute::SetValue<bool>(this: m_pAttribute, value: (const bool *)&srcComp);
      }
    }
  }
  v39 = g_pDataModel->__vftable;
  v40 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pDstMesh);
  v39->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v40);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vertexWeightMap);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045DD30
// Name: protected: static void CDmMeshUtils::CreateDeltasFromPresetGroup(class CDmePresetGroup __near *,class CDmeCombinationOperator __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near *,class CDmeMesh __near *,class CDmeVertexData __near *,class CUtlStringMap<class CUtlString> __near &,class CUtlStringMap<class CDmePreset __near *> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmMeshUtils::CreateDeltasFromPresetGroup(
        CDmeTransform *pPresetGroup,
        CDmeCombinationOperator *pComboOp,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pPurgeAllButThese,
        CDmeMesh *pMesh,
        CDmeVertexData *pDst,
        CUtlStringMap<CUtlString> *conflictingNames,
        CUtlStringMap<CDmePreset *> *presetMap)
{
  const CDmaElementArray<CDmePreset> *Orientation; // esi
  int m_Size; // eax
  int v9; // edi
  CDmElement *v10; // eax
  CDmeTransform *v11; // esi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmElement *v14; // edi
  const char *m_pAsString; // eax
  char v16; // bl
  int v17; // esi
  int v18; // edi
  const char *Name; // eax
  int v20; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v22; // esi
  CDmaVar<float> *m_pData; // ebx
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // esi
  CDmaVar<float> *v26; // esi
  CDmAttribute *v27; // eax
  CDmAttribute *v28; // esi
  CDmaVar<float> *v29; // esi
  CDmAttribute *v30; // eax
  CDmAttribute *v31; // esi
  CDmaVar<float> *v32; // esi
  CDmeMesh *v33; // ebx
  const char *v34; // eax
  CUtlStringMap<CDmePreset *> *v35; // edi
  int k; // esi
  const char *v37; // eax
  const char *v38; // eax
  const char *v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  const char *v42; // esi
  const char *v43; // eax
  const char *v44; // edi
  char *v45; // eax
  int m_Id; // esi
  int v47; // ecx
  char *v48; // eax
  int v49; // esi
  int v50; // ecx
  const char *v51; // eax
  const char *v52; // [esp+14h] [ebp-64h]
  CUtlString presetName; // [esp+24h] [ebp-54h] BYREF
  int nPresetsCount; // [esp+34h] [ebp-44h]
  int nControlValues; // [esp+38h] [ebp-40h]
  int v56; // [esp+3Ch] [ebp-3Ch] BYREF
  int v57; // [esp+40h] [ebp-38h] BYREF
  int v58; // [esp+44h] [ebp-34h] BYREF
  int v59; // [esp+48h] [ebp-30h] BYREF
  CDmaElementArray<CDmElement> *controlValues; // [esp+4Ch] [ebp-2Ch]
  const CDmaElementArray<CDmePreset> *presets; // [esp+50h] [ebp-28h]
  int i; // [esp+54h] [ebp-24h]
  int j; // [esp+58h] [ebp-20h]
  int nControlIndex; // [esp+5Ch] [ebp-1Ch]
  CDmElement *v65; // [esp+60h] [ebp-18h]
  CDmElement *v66; // [esp+64h] [ebp-14h]
  CUtlSymbol v67; // [esp+68h] [ebp-10h] BYREF
  CUtlSymbol result; // [esp+6Ah] [ebp-Eh] BYREF
  CUtlSymbol v69; // [esp+6Ch] [ebp-Ch] BYREF
  CUtlSymbol v70; // [esp+70h] [ebp-8h] BYREF
  bool bIsMulti; // [esp+77h] [ebp-1h] BYREF

  Orientation = (const CDmaElementArray<CDmePreset> *)CDmeTransform::GetOrientation(this: pPresetGroup);
  m_Size = Orientation->m_Storage.m_Size;
  presets = Orientation;
  nPresetsCount = m_Size;
  if ( m_Size > 0 )
  {
    v9 = 0;
    i = 0;
    while ( 1 )
    {
      CDmeCombinationOperator::SetToBase(this: pComboOp);
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: Orientation->m_Storage.m_Memory.m_pMemory[v9]);
      v11 = (CDmeTransform *)v10;
      if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmePreset::m_classType) )
        v11 = nullptr;
      v66 = v11;
      if ( !CDmePreset::IsAnimated(this: (CDmePreset *)v11) )
      {
        controlValues = (CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v11);
        nControlValues = controlValues->m_Storage.m_Size;
        for ( j = 0; j < nControlValues; ++j )
        {
          v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: controlValues->m_Storage.m_Memory.m_pMemory[j]);
          v13 = v12;
          if ( v12 != nullptr && v12->IsA(this: v12, a2: CDmElement::m_classType) )
          {
            v14 = v13;
            v65 = v13;
          }
          else
          {
            v14 = nullptr;
            v65 = nullptr;
          }
          m_pAsString = v14->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = var;
          nControlIndex = FindComboOpControlIndexForAnimSetControl(
                            pComboOp,
                            pControlName: m_pAsString,
                            pIsMulti: &bIsMulti);
          if ( nControlIndex < 0 )
            continue;
          v16 = 0;
          if ( pPurgeAllButThese != nullptr )
          {
            v17 = 0;
            if ( pPurgeAllButThese->m_Size > 0 )
            {
              v18 = 0;
              do
              {
                v52 = CUtlString::operator char const *(this: &pPurgeAllButThese->m_Memory.m_pMemory[v18]);
                Name = CDmElement::GetName(this: v65);
                if ( _V_strcmp(s1: Name, s2: v52) == 0 )
                  v16 = 1;
                ++v17;
                ++v18;
              }
              while ( v17 < pPurgeAllButThese->m_Size );
              if ( v16 != 0 )
                continue;
              v14 = v65;
            }
          }
          v20 = nControlIndex;
          if ( CDmeCombinationOperator::IsStereoControl(this: pComboOp, nControlIndex) )
          {
            v59 = 0;
            v58 = 0;
            Attribute = CDmElement::FindAttribute(this: v14, pAttributeName: "rightValue");
            v22 = Attribute;
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
                CDmAttribute::CopyDataOut<float>(this: v22, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                m_pData = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
              }
              else
              {
                m_pData = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
              }
            }
            else
            {
              m_pData = (CDmaVar<float> *)&v59;
            }
            v24 = CDmElement::FindAttribute(this: v14, pAttributeName: "leftValue");
            v25 = v24;
            if ( v24 != nullptr )
            {
              if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
              }
              if ( (v24->m_nFlags & 0x1F) == 3 )
              {
                v26 = (CDmaVar<float> *)v24->m_pData;
              }
              else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
              {
                CDmAttribute::CopyDataOut<float>(this: v25, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                v26 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
              }
              else
              {
                v26 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
              }
            }
            else
            {
              v26 = (CDmaVar<float> *)&v58;
            }
            CDmeCombinationOperator::SetControlValue(
              this: pComboOp,
              nControlIndex,
              flLeftValue: v26->m_Storage,
              flRightValue: m_pData->m_Storage,
              type: COMBO_CONTROL_FIRST);
          }
          else
          {
            v57 = 0;
            v27 = CDmElement::FindAttribute(this: v14, pAttributeName: "value");
            v28 = v27;
            if ( v27 != nullptr )
            {
              if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
              }
              if ( (v27->m_nFlags & 0x1F) == 3 )
              {
                v29 = (CDmaVar<float> *)v27->m_pData;
              }
              else if ( CDmAttribute::IsTypeConvertable<bool>(this: v27) )
              {
                CDmAttribute::CopyDataOut<float>(this: v28, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                v29 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
              }
              else
              {
                v29 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
              }
            }
            else
            {
              v29 = (CDmaVar<float> *)&v57;
            }
            CDmeCombinationOperator::SetControlValue(
              this: pComboOp,
              nControlIndex: v20,
              flValue: v29->m_Storage,
              type: COMBO_CONTROL_FIRST);
          }
          if ( bIsMulti )
          {
            v56 = 1056964608;
            v30 = CDmElement::FindAttribute(this: v14, pAttributeName: "value");
            v31 = v30;
            if ( v30 != nullptr )
            {
              if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
                `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
              }
              if ( (v30->m_nFlags & 0x1F) == 3 )
              {
                v32 = (CDmaVar<float> *)v30->m_pData;
              }
              else if ( CDmAttribute::IsTypeConvertable<bool>(this: v30) )
              {
                CDmAttribute::CopyDataOut<float>(this: v31, value: &`CDmAttribute::GetValue<float>'::`7'::tempVal);
                v32 = (CDmaVar<float> *)&`CDmAttribute::GetValue<float>'::`7'::tempVal;
              }
              else
              {
                v32 = &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
              }
            }
            else
            {
              v32 = (CDmaVar<float> *)&v56;
            }
            CDmeCombinationOperator::SetMultiControlLevel(
              this: pComboOp,
              nControlIndex,
              flMultiLevel: v32->m_Storage,
              type: COMBO_CONTROL_FIRST);
          }
        }
        pComboOp->Resolve(this: &pComboOp->CDmElement);
        pComboOp->Operate(this: pComboOp);
        v33 = pMesh;
        pMesh->Resolve(this: pMesh);
        CDmeMesh::SetBaseStateToDeltas(this: pMesh, pPassedBase: pDst);
        v34 = v66->m_Name.m_Storage.u.m_pAsString;
        if ( v34 == (const char *)-1 )
          v34 = var;
        CUtlString::CUtlString(this: &presetName, pString: v34);
        v35 = presetMap;
        for ( k = 1; ; ++k )
        {
          v37 = CUtlString::operator char const *(this: &presetName);
          if ( CDmeCombinationOperator::FindControlIndex(this: pComboOp, pControlName: v37) < 0 )
          {
            v38 = CUtlString::operator char const *(this: &presetName);
            if ( CDmeMesh::FindDeltaState(this: pMesh, pDeltaName: v38, bSortDeltaName: true) == nullptr )
            {
              v39 = CUtlString::operator char const *(this: &presetName);
              if ( CUtlSymbolTable::Find(this: &conflictingNames->m_SymbolTable, &result, pString: v39)->m_Id == 0xFFFF )
              {
                v40 = CUtlString::operator char const *(this: &presetName);
                if ( CUtlSymbolTable::Find(this: &presetMap->m_SymbolTable, result: &v67, pString: v40)->m_Id == 0xFFFF )
                  break;
              }
            }
          }
          v41 = CDmElement::GetName(this: v66);
          CUtlString::operator=(this: &presetName, src: v41);
          CUtlString::operator+=(this: &presetName, rhs: k);
        }
        v42 = var;
        if ( v66->m_Name.m_Storage.u.m_Id != -1 )
          v42 = v66->m_Name.m_Storage.u.m_pAsString;
        v43 = CUtlString::operator char const *(this: &presetName);
        if ( _V_strcmp(s1: v42, s2: v43) != 0 )
        {
          v44 = var;
          if ( v66->m_Name.m_Storage.u.m_Id != -1 )
            v44 = v66->m_Name.m_Storage.u.m_pAsString;
          v45 = (char *)CUtlString::operator char const *(this: &presetName);
          CUtlSymbolTable::AddString(this: &conflictingNames->m_SymbolTable, result: &v70, pString: v45);
          m_Id = v70.m_Id;
          v47 = conflictingNames->m_Vector.m_Size;
          if ( v47 <= v70.m_Id && v47 < v70.m_Id + 1 )
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
              this: &conflictingNames->m_Vector,
              elem: v47,
              num: v70.m_Id + 1 - v47);
          CUtlString::operator=(this: &conflictingNames->m_Vector.m_Memory.m_pMemory[m_Id], src: v44);
          v33 = pMesh;
          v35 = presetMap;
        }
        v48 = (char *)CUtlString::operator char const *(this: &presetName);
        CUtlSymbolTable::AddString(this: &v35->m_SymbolTable, result: &v69, pString: v48);
        v49 = v69.m_Id;
        v50 = v35->m_Vector.m_Size;
        if ( v50 <= v69.m_Id && v50 < v69.m_Id + 1 )
          CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
            this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)v35,
            elem: v50,
            num: v69.m_Id + 1 - v50);
        v35->m_Vector.m_Memory.m_pMemory[v49] = (CDmePreset *)v66;
        v51 = CUtlString::operator char const *(this: &presetName);
        CDmeMesh::ModifyOrCreateDeltaStateFromBaseState(this: v33, pDeltaName: v51, pPassedBase: pDst, absolute: true);
        presetName.m_Storage.m_nActualLength = 0;
        if ( presetName.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( presetName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetName.m_Storage.m_Memory.m_pMemory);
            presetName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          presetName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
      v9 = i + 1;
      i = v9;
      if ( v9 >= nPresetsCount )
        break;
      Orientation = presets;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E2F0
// Name: public: static bool CDmMeshUtils::RemoveFacesWithMaterial(class CDmeMesh __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::RemoveFacesWithMaterial(CDmeMesh *pMesh, const char *pMaterialName)
{
  int m_Size; // esi
  int *m_pMemory; // edi
  int v4; // ebx
  CDmeFaceSet *FaceSet; // eax
  CDmeMaterial *Material; // eax
  const char *MaterialName; // eax
  int v8; // ebx
  int *v9; // ebx
  int v10; // esi
  CUtlVector<int,CUtlMemory<int,int> > emptyFaceSets; // [esp+Ch] [ebp-20h] BYREF
  int nFaceSets; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  bool bMeshChanged; // [esp+2Bh] [ebp-1h]

  m_Size = 0;
  m_pMemory = nullptr;
  bMeshChanged = false;
  memset(&emptyFaceSets, 0, sizeof(emptyFaceSets));
  v4 = 0;
  nFaceSets = CDmeMesh::FaceSetCount(this: pMesh);
  i = 0;
  if ( nFaceSets > 0 )
  {
    do
    {
      FaceSet = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: pMesh, faceSetIndex: v4);
      Material = CDmeFaceSet::GetMaterial(this: FaceSet);
      MaterialName = CDmeMaterial::GetMaterialName(this: Material);
      if ( _V_strcmp(s1: MaterialName, s2: pMaterialName) == 0 )
      {
        v8 = m_Size;
        if ( m_Size + 1 > emptyFaceSets.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&emptyFaceSets,
            num: m_Size - emptyFaceSets.m_Memory.m_nAllocationCount + 1);
          m_Size = emptyFaceSets.m_Size;
          m_pMemory = emptyFaceSets.m_Memory.m_pMemory;
        }
        emptyFaceSets.m_Size = ++m_Size;
        emptyFaceSets.m_pElements = m_pMemory;
        if ( m_Size - v8 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * (m_Size - v8 - 1));
        v9 = &m_pMemory[v8];
        if ( v9 != nullptr )
          *v9 = i;
        v4 = i;
        bMeshChanged = true;
      }
      i = ++v4;
    }
    while ( v4 < nFaceSets );
  }
  v10 = m_Size - 1;
  if ( v10 >= 0 )
  {
    do
      CDmeMesh::RemoveFaceSet(this: pMesh, faceSetIndex: m_pMemory[v10--]);
    while ( v10 >= 0 );
  }
  else if ( !bMeshChanged )
  {
    if ( emptyFaceSets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return 0;
  }
  CDmMeshUtils::PurgeUnusedData(pMesh);
  if ( emptyFaceSets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E430
// Name: public: static bool CDmMeshUtils::RemoveFacesWithMoreThanNVerts(class CDmeMesh __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::RemoveFacesWithMoreThanNVerts(CDmeMesh *pMesh, int nVertexCount)
{
  CDmeMesh *v2; // esi
  int v4; // ebx
  int m_nGrowSize; // edi
  int v6; // eax
  int v7; // ecx
  CDmeFaceSet *FaceSet; // eax
  CDmeFaceSet *v9; // edi
  int m_Size; // esi
  int *m_pMemory; // eax
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // esi
  int *v16; // edi
  int *v17; // esi
  int v18; // esi
  int v19; // edi
  int *v20; // ecx
  int *v21; // edi
  int v22; // edi
  int *v23; // esi
  int v24; // ebx
  int v25; // esi
  int v26; // eax
  int *v27; // edi
  int v28; // eax
  int *v29; // esi
  int v30; // esi
  CUtlVector<int,CUtlMemory<int,int> > removeCount; // [esp+4h] [ebp-58h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > emptyFaceSets; // [esp+18h] [ebp-44h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > removeStart; // [esp+2Ch] [ebp-30h] BYREF
  int nFaceSets; // [esp+40h] [ebp-1Ch]
  int nFaceIndices; // [esp+44h] [ebp-18h]
  int i; // [esp+48h] [ebp-14h]
  CDmeFaceSet *pFaceSet; // [esp+4Ch] [ebp-10h]
  int faceStartIndex; // [esp+50h] [ebp-Ch]
  int j; // [esp+54h] [ebp-8h]
  bool bMeshChanged; // [esp+5Bh] [ebp-1h]

  v2 = pMesh;
  if ( CDmeMesh::FindBaseState(this: pMesh, pStateName: "bind") == nullptr )
    return 0;
  v4 = 0;
  m_nGrowSize = 0;
  bMeshChanged = false;
  memset(&emptyFaceSets, 0, sizeof(emptyFaceSets));
  memset(&removeStart, 0, sizeof(removeStart));
  memset(&removeCount, 0, sizeof(removeCount));
  v6 = CDmeMesh::FaceSetCount(this: pMesh);
  v7 = 0;
  nFaceSets = v6;
  i = 0;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      FaceSet = (CDmeFaceSet *)CDmeMesh::GetFaceSet(this: v2, faceSetIndex: v7);
      v9 = FaceSet;
      m_Size = FaceSet->m_indices.m_Storage.m_Size;
      pFaceSet = FaceSet;
      nFaceIndices = m_Size;
      if ( m_Size > 0 )
      {
        m_pMemory = FaceSet->m_indices.m_Storage.m_Memory.m_pMemory;
        faceStartIndex = 0;
        if ( *m_pMemory >= 0 )
        {
          v12 = 1;
          v13 = 0;
          v14 = 0;
          removeStart.m_Size = 0;
          removeCount.m_Size = 0;
          j = 1;
          if ( m_Size > 1 )
          {
            while ( 1 )
            {
              if ( v9->m_indices.m_Storage.m_Memory.m_pMemory[v12] >= 0 )
              {
                ++v14;
              }
              else
              {
                if ( v14 > nVertexCount )
                {
                  v15 = v13;
                  if ( v13 + 1 > removeStart.m_Memory.m_nAllocationCount )
                  {
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(
                      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&removeStart,
                      num: v13 - removeStart.m_Memory.m_nAllocationCount + 1);
                    v13 = removeStart.m_Size;
                  }
                  v16 = removeStart.m_Memory.m_pMemory;
                  removeStart.m_Size = ++v13;
                  removeStart.m_pElements = removeStart.m_Memory.m_pMemory;
                  if ( v13 - v15 - 1 > 0 )
                  {
                    _V_memmove(
                      dest: &removeStart.m_Memory.m_pMemory[v15 + 1],
                      src: &removeStart.m_Memory.m_pMemory[v15],
                      count: 4 * (v13 - v15 - 1));
                    v13 = removeStart.m_Size;
                  }
                  v17 = &v16[v15];
                  if ( v17 != nullptr )
                    *v17 = faceStartIndex;
                  v18 = j - faceStartIndex + 1;
                  v19 = v4;
                  if ( v4 + 1 > removeCount.m_Memory.m_nAllocationCount )
                  {
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(
                      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&removeCount,
                      num: v4 - removeCount.m_Memory.m_nAllocationCount + 1);
                    v4 = removeCount.m_Size;
                    v13 = removeStart.m_Size;
                  }
                  v20 = removeCount.m_Memory.m_pMemory;
                  removeCount.m_Size = ++v4;
                  removeCount.m_pElements = removeCount.m_Memory.m_pMemory;
                  if ( v4 - v19 - 1 > 0 )
                  {
                    _V_memmove(
                      dest: &removeCount.m_Memory.m_pMemory[v19 + 1],
                      src: &removeCount.m_Memory.m_pMemory[v19],
                      count: 4 * (v4 - v19 - 1));
                    v20 = removeCount.m_Memory.m_pMemory;
                    v13 = removeStart.m_Size;
                  }
                  v12 = j;
                  v21 = &v20[v19];
                  if ( v21 != nullptr )
                    *v21 = v18;
                }
                m_Size = nFaceIndices;
                faceStartIndex = v12 + 1;
                v14 = 0;
              }
              j = ++v12;
              if ( v12 >= m_Size )
                break;
              v9 = pFaceSet;
            }
          }
          v22 = v13 - 1;
          if ( v13 - 1 >= 0 )
          {
            bMeshChanged = true;
            v23 = &removeStart.m_Memory.m_pMemory[v22];
            v24 = (char *)removeCount.m_Memory.m_pMemory - (char *)removeStart.m_Memory.m_pMemory;
            do
            {
              CDmeFaceSet::RemoveMultiple(this: pFaceSet, elem: *v23, num: *(int *)((char *)v23 + v24));
              --v23;
              --v22;
            }
            while ( v22 >= 0 );
          }
          if ( CDmeFaceSet::GetIndexCount(this: pFaceSet) != 0 )
          {
            v4 = 0;
          }
          else
          {
            v25 = emptyFaceSets.m_Size;
            v26 = emptyFaceSets.m_Size;
            if ( emptyFaceSets.m_Size + 1 > emptyFaceSets.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&emptyFaceSets,
                num: emptyFaceSets.m_Size - emptyFaceSets.m_Memory.m_nAllocationCount + 1);
              v26 = emptyFaceSets.m_Size;
            }
            v27 = emptyFaceSets.m_Memory.m_pMemory;
            emptyFaceSets.m_Size = v26 + 1;
            v28 = v26 - v25;
            emptyFaceSets.m_pElements = emptyFaceSets.m_Memory.m_pMemory;
            if ( v28 > 0 )
              _V_memmove(
                dest: &emptyFaceSets.m_Memory.m_pMemory[v25 + 1],
                src: &emptyFaceSets.m_Memory.m_pMemory[v25],
                count: 4 * v28);
            v29 = &v27[v25];
            v4 = 0;
            if ( v29 != nullptr )
              *v29 = i;
          }
        }
      }
      v7 = i + 1;
      i = v7;
      if ( v7 >= nFaceSets )
        break;
      v2 = pMesh;
    }
    m_nGrowSize = removeCount.m_Memory.m_nGrowSize;
  }
  v30 = emptyFaceSets.m_Size - 1;
  if ( emptyFaceSets.m_Size - 1 >= 0 )
  {
    do
      CDmeMesh::RemoveFaceSet(this: pMesh, faceSetIndex: emptyFaceSets.m_Memory.m_pMemory[v30--]);
    while ( v30 >= 0 );
  }
  else if ( !bMeshChanged )
  {
    if ( m_nGrowSize >= 0 && removeCount.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: removeCount.m_Memory.m_pMemory);
    if ( removeStart.m_Memory.m_nGrowSize >= 0 && removeStart.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: removeStart.m_Memory.m_pMemory);
    if ( emptyFaceSets.m_Memory.m_nGrowSize >= 0 && emptyFaceSets.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: emptyFaceSets.m_Memory.m_pMemory);
    return 0;
  }
  CDmMeshUtils::PurgeUnusedData(pMesh);
  if ( m_nGrowSize >= 0 && removeCount.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: removeCount.m_Memory.m_pMemory);
  if ( removeStart.m_Memory.m_nGrowSize >= 0 && removeStart.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: removeStart.m_Memory.m_pMemory);
  if ( emptyFaceSets.m_Memory.m_nGrowSize >= 0 && emptyFaceSets.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: emptyFaceSets.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E7C0
// Name: public: static bool CDmMeshUtils::CreateDeltasFromPresets(class CDmeMesh __near *,class CDmeVertexData __near *,class CUtlStringMap<class CUtlString> const __near &,bool,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::CreateDeltasFromPresets(
        CDmeMesh *pMesh,
        CDmeVertexData *pPassedDst,
        const CUtlStringMap<CUtlString> *presetExpressionMap,
        bool bPurge,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pPurgeAllButThese)
{
  CDmeMesh *v5; // ebx
  int v6; // edi
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  CDmeVertexData *v8; // esi
  CDmeVertexData *BaseState; // eax
  CDmeCombinationOperator *Referring; // esi
  CDmePresetGroup **m_pMemory; // ebx
  char *v12; // esi
  CP4File *v13; // eax
  CDmeTransform *v14; // esi
  int m_Size; // edi
  int v16; // eax
  int v17; // eax
  CDmeTransform **v18; // eax
  int m_NumElements; // edx
  const char *m_pAsString; // ebx
  CDmeCombinationOperator *v21; // esi
  int ControlIndex; // eax
  int v23; // edi
  CDmeCombinationOperator *v24; // ecx
  int v25; // esi
  const char *RawControlName; // eax
  CDmAttribute *m_pAttribute; // ecx
  CUtlString *v28; // esi
  const char *v29; // eax
  int v30; // edi
  int j; // esi
  CDmePresetGroup *v32; // eax
  CUtlString *v33; // eax
  CDmePreset **v34; // eax
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v36; // [esp-Ch] [ebp-E0h]
  CDmeCombinationOperator *v37; // [esp-8h] [ebp-DCh]
  CDmeTransform *v38; // [esp-4h] [ebp-D8h]
  CUtlStringMap<CUtlString> conflictingNames; // [esp+Ch] [ebp-C8h] BYREF
  CUtlStringMap<CDmePreset *> presetMap; // [esp+58h] [ebp-7Ch] BYREF
  CUtlVector<CDmePresetGroup *,CUtlMemory<CDmePresetGroup *,int> > presetGroups; // [esp+A4h] [ebp-30h] BYREF
  CDisableUndoScopeGuard sgDisableUndo; // [esp+B8h] [ebp-1Ch] BYREF
  CDmeVertexData *pDst; // [esp+C0h] [ebp-14h]
  int i; // [esp+C4h] [ebp-10h]
  int nRawControls; // [esp+C8h] [ebp-Ch] BYREF
  CDmeCombinationOperator *pComboOp; // [esp+CCh] [ebp-8h]
  bool bSavedUsingLagged; // [esp+D3h] [ebp-1h]

  v5 = pMesh;
  v6 = 0;
  if ( pMesh == nullptr )
    return 0;
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  sgDisableUndo.m_bNotify = false;
  sgDisableUndo.m_pNotify = nullptr;
  *(_WORD *)&sgDisableUndo.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  presetMap.m_Vector.m_Memory.m_pMemory = nullptr;
  presetMap.m_Vector.m_Memory.m_nAllocationCount = 0;
  presetMap.m_Vector.m_Memory.m_nGrowSize = 32;
  presetMap.m_Vector.m_Size = 0;
  presetMap.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &presetMap.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  conflictingNames.m_Vector.m_Memory.m_pMemory = nullptr;
  conflictingNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  conflictingNames.m_Vector.m_Memory.m_nGrowSize = 32;
  conflictingNames.m_Vector.m_Size = 0;
  conflictingNames.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &conflictingNames.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  if ( pPassedDst != nullptr )
  {
    v8 = pPassedDst;
    pDst = pPassedDst;
  }
  else
  {
    pDst = CDmeMesh::GetCurrentBaseState(this: v5);
    v8 = pDst;
  }
  BaseState = CDmeMesh::FindBaseState(this: v5, pStateName: "bind");
  if ( v8 == nullptr
    || BaseState == nullptr
    || v8 == BaseState
    || (Referring = FindReferringElement<CDmeCombinationOperator>(
                      pElement: (CExpressionCalculator *)v5,
                      pAttrName: "targets",
                      bMustBeInSameFile: true,
                      depth: TD_ALL),
        pComboOp = Referring,
        Referring == nullptr) )
  {
    CUtlSymbolTable::~CUtlSymbolTable(this: &conflictingNames.m_SymbolTable);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &conflictingNames.m_Vector);
    CUtlSymbolTable::~CUtlSymbolTable(this: &presetMap.m_SymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&presetMap);
    CChangeUndoScopeGuard::Release(this: &sgDisableUndo);
    return 0;
  }
  m_pMemory = nullptr;
  bSavedUsingLagged = Referring->m_bSpecifyingLaggedData.m_Storage;
  memset(&presetGroups, 0, sizeof(presetGroups));
  i = 0;
  if ( presetExpressionMap->m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v12 = CUtlSymbolTable::String(this: &presetExpressionMap->m_SymbolTable, id: (CUtlSymbol)i);
      nRawControls = 0;
      v13 = CP4Factory::AccessFile(this: g_p4factory, szFilename: v12);
      v13->Add(this: v13);
      g_pDataModel->RestoreFromFile(
        this: g_pDataModel,
        a2: v12,
        a3: nullptr,
        a4: nullptr,
        a5: (CDmElement **)&nRawControls,
        a6: CR_DELETE_NEW,
        a7: nullptr);
      v14 = (CDmeTransform *)nRawControls;
      if ( nRawControls == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)nRawControls + 16))(
             a1: nRawControls,
             a2: CDmePresetGroup::m_classType.u) == 0 )
      {
        v14 = nullptr;
      }
      m_Size = presetGroups.m_Size;
      v16 = presetGroups.m_Size;
      if ( presetGroups.m_Size + 1 > presetGroups.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&presetGroups,
          num: presetGroups.m_Size - presetGroups.m_Memory.m_nAllocationCount + 1);
        v16 = presetGroups.m_Size;
        m_pMemory = presetGroups.m_Memory.m_pMemory;
      }
      presetGroups.m_Size = v16 + 1;
      v17 = v16 - m_Size;
      presetGroups.m_pElements = m_pMemory;
      if ( v17 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
      v18 = (CDmeTransform **)&m_pMemory[m_Size];
      if ( v18 != nullptr )
        *v18 = v14;
      if ( v14 != nullptr )
        CDmMeshUtils::CreateDeltasFromPresetGroup(
          pPresetGroup: v14,
          pComboOp,
          pPurgeAllButThese,
          pMesh,
          pDst,
          &conflictingNames,
          &presetMap);
      m_NumElements = presetExpressionMap->m_SymbolTable.m_Lookup.m_NumElements;
      v6 = 0;
      ++i;
    }
    while ( i < m_NumElements );
    Referring = pComboOp;
  }
  if ( bPurge )
    CDmMeshUtils::PurgeUnreferencedDeltas(pMesh, &presetMap, pPurgeAllButThese, pComboOp: Referring);
  pMesh = nullptr;
  if ( presetMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    while ( 1 )
    {
      m_pAsString = var;
      if ( presetMap.m_Vector.m_Memory.m_pMemory[(unsigned __int16)pMesh]->m_Name.m_Storage.u.CDmElement::m_Id != -1 )
        m_pAsString = presetMap.m_Vector.m_Memory.m_pMemory[(unsigned __int16)pMesh]->m_Name.m_Storage.u.m_pAsString;
      v21 = pComboOp;
      ControlIndex = CDmeCombinationOperator::FindControlIndex(this: pComboOp, pControlName: m_pAsString);
      v23 = ControlIndex;
      v24 = v21;
      if ( ControlIndex >= 0 )
      {
        if ( bPurge )
        {
          CDmeCombinationOperator::RemoveAllRawControls(this: v21, nControl: ControlIndex);
        }
        else
        {
          v25 = 0;
          nRawControls = CDmeCombinationOperator::GetRawControlCount(this: v24, nControl: ControlIndex);
          if ( nRawControls > 0 )
          {
            do
            {
              RawControlName = CDmeCombinationOperator::GetRawControlName(this: pComboOp, nControl: v23, nIndex: v25);
              if ( _V_strcmp(s1: RawControlName, s2: m_pAsString) == 0 )
                goto LABEL_37;
            }
            while ( ++v25 < nRawControls );
          }
          v21 = pComboOp;
        }
        CDmeCombinationOperator::AddRawControl(this: v21, nControl: v23, pRawControlName: m_pAsString);
      }
      else
      {
        CDmeCombinationOperator::FindOrCreateControl(
          this: v21,
          pControlName: m_pAsString,
          bStereo: false,
          bAutoAddRawControl: true);
      }
LABEL_37:
      pMesh = (CDmeMesh *)((char *)pMesh + 1);
      if ( (int)pMesh >= presetMap.m_SymbolTable.m_Lookup.m_NumElements )
      {
        m_pMemory = presetGroups.m_Memory.m_pMemory;
        Referring = pComboOp;
        v6 = 0;
        break;
      }
    }
  }
  m_pAttribute = Referring->m_bSpecifyingLaggedData.m_pAttribute;
  LOBYTE(pMesh) = bSavedUsingLagged;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, value: (const bool *)&pMesh);
  CDmeCombinationOperator::SetToDefault(this: Referring);
  if ( presetExpressionMap->m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v28 = &presetExpressionMap->m_Vector.m_Memory.m_pMemory[(unsigned __int16)v6];
      if ( CUtlString::Length(this: v28) != 0 )
      {
        v38 = (CDmeTransform *)m_pMemory[v6];
        v37 = pComboOp;
        v36 = pPurgeAllButThese;
        v29 = CUtlString::operator char const *(this: v28);
        CreateExpressionFile(pExpressionFile: v29, pPurgeAllButThese: v36, pComboOp: v37, pPresetGroup: v38);
      }
      ++v6;
    }
    while ( v6 < presetExpressionMap->m_SymbolTable.m_Lookup.m_NumElements );
  }
  v30 = presetGroups.m_Size;
  for ( j = 0; j < v30; ++j )
  {
    v32 = m_pMemory[j];
    if ( v32 != nullptr )
      g_pDataModel->UnloadFile(this: g_pDataModel, a2: v32->m_fileId);
  }
  if ( presetGroups.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  CUtlSymbolTable::~CUtlSymbolTable(this: &conflictingNames.m_SymbolTable);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&conflictingNames);
  v33 = conflictingNames.m_Vector.m_Memory.m_pMemory;
  if ( conflictingNames.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( conflictingNames.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: conflictingNames.m_Vector.m_Memory.m_pMemory);
      v33 = nullptr;
      conflictingNames.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    conflictingNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  conflictingNames.m_Vector.m_pElements = v33;
  if ( conflictingNames.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v33 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v33);
      conflictingNames.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    conflictingNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &presetMap.m_SymbolTable);
  v34 = presetMap.m_Vector.m_Memory.m_pMemory;
  presetMap.m_Vector.m_Size = 0;
  if ( presetMap.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( presetMap.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetMap.m_Vector.m_Memory.m_pMemory);
      v34 = nullptr;
      presetMap.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    presetMap.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  presetMap.m_Vector.m_pElements = v34;
  if ( presetMap.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v34 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34);
      presetMap.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    presetMap.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sgDisableUndo.m_bOldValue);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EC70
// Name: public: static bool CDmMeshUtils::Merge(class CDmeMesh __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmMeshUtils::Merge(CDmeMesh *pSrcMesh, CDmElement *pRoot)
{
  CDmeDag **m_pMemory; // edi
  int m_Size; // esi
  CDmeDag **v4; // eax
  void (__thiscall *GetBoundingSphere)(struct CDmeMesh *, Vector *, float *); // eax
  CDmeDag *v7; // edi
  int i; // ebx
  CDmeMesh *Shape; // edi
  int MergeSocket; // ebx
  float v11; // xmm2_4
  char v12; // bl
  CDmMeshComp srcComp; // [esp+Ch] [ebp-B4h] BYREF
  float srcRadius; // [esp+68h] [ebp-58h] BYREF
  Vector dstCenter; // [esp+6Ch] [ebp-54h] BYREF
  Vector srcCenter; // [esp+78h] [ebp-48h] BYREF
  CDmeDag *Child; // [esp+84h] [ebp-3Ch]
  float dstRadius; // [esp+88h] [ebp-38h] BYREF
  CUtlVector<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,CUtlMemory<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,int> > srcBorderEdgesList; // [esp+8Ch] [ebp-34h] BYREF
  CDmeMesh *pDstMesh; // [esp+A0h] [ebp-20h]
  float sqDist; // [esp+A4h] [ebp-1Ch]
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > traverseStack; // [esp+A8h] [ebp-18h] BYREF
  int nEdgeListIndex; // [esp+BCh] [ebp-4h]

  CDmMeshComp::CDmMeshComp(this: &srcComp, pMesh: pSrcMesh, pPassedBase: nullptr);
  memset(&srcBorderEdgesList, 0, sizeof(srcBorderEdgesList));
  if ( CDmMeshComp::GetBorderEdges(this: &srcComp, borderEdgesList: &srcBorderEdgesList) == 0 )
    goto LABEL_7;
  pDstMesh = nullptr;
  nEdgeListIndex = (int)CDmElement::GetValueElement<CDmeDag>(this: pRoot, pAttributeName: "model");
  if ( nEdgeListIndex == 0 )
    goto LABEL_7;
  memset(&traverseStack, 0, sizeof(traverseStack));
  CUtlMemory<IDmFormatUpdater *,int>::Grow(
    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&traverseStack,
    num: 1);
  m_pMemory = traverseStack.m_Memory.m_pMemory;
  m_Size = traverseStack.m_Size + 1;
  v4 = &traverseStack.m_Memory.m_pMemory[traverseStack.m_Size++];
  traverseStack.m_pElements = traverseStack.m_Memory.m_pMemory;
  if ( v4 != nullptr )
    *v4 = (CDmeDag *)nEdgeListIndex;
  GetBoundingSphere = pSrcMesh->GetBoundingSphere;
  sqDist = 3.4028235e38;
  GetBoundingSphere(this: pSrcMesh, a2: &srcCenter, a3: &srcRadius);
  nEdgeListIndex = -1;
  if ( m_Size != 0 )
  {
    while ( 1 )
    {
      v7 = m_pMemory[--m_Size];
      traverseStack.m_Size = m_Size;
      if ( v7 != nullptr )
      {
        for ( i = CDmElementFramework::GetPhase(this: v7) - 1; i >= 0; --i )
        {
          Child = CDmeDag::GetChild(this: v7, i);
          if ( m_Size >= traverseStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&traverseStack,
              num: 1);
            m_Size = traverseStack.m_Size;
          }
          ++m_Size;
          traverseStack.m_pElements = traverseStack.m_Memory.m_pMemory;
          traverseStack.m_Size = m_Size;
          if ( &traverseStack.m_Memory.m_pMemory[m_Size] != (CDmeDag **)4 )
            traverseStack.m_Memory.m_pMemory[m_Size - 1] = Child;
        }
        Shape = (CDmeMesh *)CDmeDag::GetShape(this: v7);
        if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
        {
          MergeSocket = CDmMeshUtils::FindMergeSocket(&srcBorderEdgesList, pDstMesh: Shape);
          if ( MergeSocket >= 0 )
          {
            Shape->GetBoundingSphere(this: Shape, a2: &dstCenter, a3: &dstRadius);
            v11 = (float)(dstCenter.z - srcCenter.z) * (float)(dstCenter.z - srcCenter.z);
            dstRadius = (float)((float)((float)(dstCenter.y - srcCenter.y) * (float)(dstCenter.y - srcCenter.y))
                              + (float)((float)(dstCenter.x - srcCenter.x) * (float)(dstCenter.x - srcCenter.x)))
                      + v11;
            if ( sqDist > dstRadius )
            {
              sqDist = (float)((float)((float)(dstCenter.y - srcCenter.y) * (float)(dstCenter.y - srcCenter.y))
                             + (float)((float)(dstCenter.x - srcCenter.x) * (float)(dstCenter.x - srcCenter.x)))
                     + v11;
              pDstMesh = Shape;
              nEdgeListIndex = MergeSocket;
            }
          }
        }
      }
      if ( m_Size == 0 )
        break;
      m_pMemory = traverseStack.m_Memory.m_pMemory;
    }
    if ( pDstMesh != nullptr )
    {
      v12 = CDmMeshUtils::Merge(&srcComp, edgeList: &srcBorderEdgesList.m_Memory.m_pMemory[nEdgeListIndex], pDstMesh);
      CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&traverseStack);
      CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&srcBorderEdgesList);
      CDmMeshComp::~CDmMeshComp(this: &srcComp);
      return v12;
    }
  }
  _Msg(
    a1: "Error: Merge() - No Merge Socket Found - i.e. A Set Of Border Edges On The Source Model That Are Found On The Merge Model");
  CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&traverseStack);
LABEL_7:
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&srcBorderEdgesList);
  CDmMeshComp::~CDmMeshComp(this: &srcComp);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005AB9C0
// Name: _dynamic_initializer_for__CDmeCombinationOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCombinationOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCombinationOperator::s_Allocator,
    blockSize: 300,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCombinationOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCombinationOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF9E0
// Name: _dynamic_atexit_destructor_for__CDmeCombinationOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCombinationOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCombinationOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004586F0
// Name: class CDmeFaceSet __near * CreateElement<class CDmeFaceSet>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFaceSet *__cdecl CreateElement<CDmeFaceSet>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeFaceSet::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeFaceSet::m_classType) )
    return (CDmeFaceSet *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00458750
// Name: class CDmeMaterial __near * CreateElement<class CDmeMaterial>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterial *__cdecl CreateElement<CDmeMaterial>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeMaterial::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeMaterial::m_classType) )
    return (CDmeMaterial *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00458E30
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,char const __near *,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        const char *pAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CUtlSymbolLarge *p_pAttrName; // eax

  if ( pAttrName != nullptr )
  {
    p_pAttrName = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pAttrName, a3: pAttrName);
  }
  else
  {
    pAttrName = (const char *)-1;
    p_pAttrName = (CUtlSymbolLarge *)&pAttrName;
  }
  return FindReferringElement<CDmeDag>(
           pElement,
           symAttrName: (CUtlSymbolLarge)p_pAttrName->u.m_Id,
           bMustBeInSameFile,
           depth);
}

//------------------------------------------------------------------------------
// Address: 0x00458E80
// Name: class CDmElement __near * FindReferringElement<class CDmElement>(class CDmElement const __near *,char const __near *,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl FindReferringElement<CDmElement>(
        CExpressionCalculator *pElement,
        const char *pAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CUtlSymbolLarge *p_pAttrName; // eax

  if ( pAttrName != nullptr )
  {
    p_pAttrName = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pAttrName, a3: pAttrName);
  }
  else
  {
    pAttrName = (const char *)-1;
    p_pAttrName = (CUtlSymbolLarge *)&pAttrName;
  }
  return FindReferringElement<CDmElement>(
           pElement,
           symAttrName: (CUtlSymbolLarge)p_pAttrName->u.m_Id,
           bMustBeInSameFile,
           depth);
}

//------------------------------------------------------------------------------
// Address: 0x005AB9F0
// Name: _dynamic_initializer_for__g_CDmeCombinationOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCombinationOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCombinationOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABA00
// Name: _dynamic_initializer_for__g_CDmeCombinationOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCombinationOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCombinationOperator_Helper,
           classname: "DmeCombinationOperator",
           pFactory: &g_CDmeCombinationOperator_Factory,
           bIsStandardFactory: true);
}
