// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/disp_ivp.cpp
// Functions: 10
// ============================================================

#include "utils\vbsp\disp_ivp.h"

//------------------------------------------------------------------------------
// Address: 0x0040BF60
// Name: public: void CCoreDispNode::GetBoundingBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispNode::GetBoundingBox(CCoreDispNode *this, Vector *bMin, Vector *bMax)
{
  *bMin = this->m_BBox[0];
  *bMax = this->m_BBox[1];
}

//------------------------------------------------------------------------------
// Address: 0x0040BF90
// Name: public: virtual void CDispMeshEvent::GetTrianglesInSphere(void __near *,class Vector const __near &,float,struct virtualmeshtrianglelist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMeshEvent::GetTrianglesInSphere(
        CDispMeshEvent *this,
        void *userData,
        const Vector *center,
        float radius,
        virtualmeshtrianglelist_t *pList)
{
  int m_indexCount; // eax

  pList->triangleCount = this->m_indexCount / 3;
  m_indexCount = 3072;
  if ( this->m_indexCount < 3072 )
    m_indexCount = this->m_indexCount;
  _V_memcpy(dest: pList->triangleIndices, src: this->m_pIndices, count: 2 * m_indexCount);
}

//------------------------------------------------------------------------------
// Address: 0x0040C050
// Name: public: virtual void CDispMeshEvent::GetVirtualMesh(void __near *,struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMeshEvent::GetVirtualMesh(CDispMeshEvent *this, void *userData, virtualmeshlist_t *pList)
{
  int m_Size; // edx
  int m_indexCount; // eax

  pList->pVerts = this->m_verts.m_Memory.m_pMemory;
  pList->indexCount = this->m_indexCount;
  pList->triangleCount = this->m_indexCount / 3;
  m_Size = this->m_verts.m_Size;
  pList->surfacePropsIndex = 0;
  pList->pHull = nullptr;
  m_indexCount = 3072;
  pList->vertexCount = m_Size;
  if ( this->m_indexCount < 3072 )
    m_indexCount = this->m_indexCount;
  _V_memcpy(dest: pList->indices, src: this->m_pIndices, count: 2 * m_indexCount);
}

//------------------------------------------------------------------------------
// Address: 0x0040C0B0
// Name: public: virtual void CDispMeshEvent::GetWorldspaceBounds(void __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMeshEvent::GetWorldspaceBounds(CDispMeshEvent *this, void *userData, Vector *pMins, Vector *pMaxs)
{
  int v5; // edi
  int v6; // ebx

  ClearBounds(mins: pMins, maxs: pMaxs);
  v5 = 0;
  if ( this->m_verts.m_Size > 0 )
  {
    v6 = 0;
    do
    {
      AddPointToBounds(v: &this->m_verts.m_Memory.m_pMemory[v6], mins: pMins, maxs: pMaxs);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_verts.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C1E0
// Name: public: CDispMeshEvent::CDispMeshEvent(unsigned short __near *,int,class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CDispMeshEvent *__thiscall CDispMeshEvent::CDispMeshEvent(
        CDispMeshEvent *this,
        unsigned __int16 *pIndices,
        int indexCount,
        CCoreDispInfo *pDispInfo)
{
  int v5; // eax
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *p_m_verts; // esi
  int v7; // ecx
  unsigned __int16 *v8; // edx
  unsigned __int16 v9; // ax
  int v10; // ebx
  int m_nAllocationCount; // eax
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // edx
  float *p_z; // eax
  unsigned int v17; // ebx
  CVTFTexture::ResourceMemorySection *v18; // ecx
  float *p_m_nDataAllocSize; // ecx
  float *v20; // ecx
  CVTFTexture::ResourceMemorySection *v21; // ecx
  int v22; // edx
  float *v23; // ecx
  int v24; // ebx
  CVTFTexture::ResourceMemorySection *v25; // eax
  int i; // [esp+18h] [ebp+8h]
  int ia; // [esp+18h] [ebp+8h]
  int count; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  p_m_verts = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_verts;
  this->__vftable = (CDispMeshEvent_vtbl *)&CDispMeshEvent::`vftable';
  this->m_verts.m_Memory.m_pMemory = nullptr;
  this->m_verts.m_Memory.m_nAllocationCount = 0;
  this->m_verts.m_Memory.m_nGrowSize = 0;
  this->m_verts.m_Size = 0;
  this->m_verts.m_pElements = nullptr;
  this->m_pIndices = pIndices;
  this->m_indexCount = indexCount;
  for ( i = 0; v5 < indexCount; ++v5 )
  {
    if ( pIndices[v5] > i )
      i = pIndices[v5];
  }
  v7 = 0;
  if ( indexCount / 2 > 0 )
  {
    v8 = &pIndices[indexCount - 1];
    do
    {
      v9 = pIndices[v7];
      pIndices[v7] = *v8;
      *v8 = v9;
      ++v7;
      --v8;
    }
    while ( v7 < indexCount / 2 );
  }
  v10 = i + 1;
  count = i + 1;
  p_m_verts[1].m_pMemory = nullptr;
  m_nAllocationCount = p_m_verts->m_nAllocationCount;
  if ( v10 > m_nAllocationCount )
    CUtlMemory<CVTFTexture::ResourceMemorySection,int>::Grow(this: p_m_verts, num: v10 - m_nAllocationCount);
  p_m_verts[1].m_pMemory = (CVTFTexture::ResourceMemorySection *)((char *)p_m_verts[1].m_pMemory + v10);
  m_pMemory = p_m_verts->m_pMemory;
  v13 = (int)p_m_verts[1].m_pMemory - v10;
  p_m_verts[1].m_nAllocationCount = (int)p_m_verts->m_pMemory;
  if ( v13 > 0 && v10 > 0 )
    _V_memmove(dest: &m_pMemory[v10], src: m_pMemory, count: 12 * v13);
  v14 = 0;
  if ( v10 >= 4 )
  {
    v15 = 0;
    p_z = &pDispInfo->m_pVerts->m_Vert.z;
    v17 = ((unsigned int)(i - 3) >> 2) + 1;
    ia = 4 * v17;
    do
    {
      v18 = p_m_verts->m_pMemory;
      v18[v15].m_nDataAllocSize = *(int *)(p_z - 2);
      p_z += 224;
      v18[v15].m_nDataLength = *(int *)(p_z - 225);
      v18[v15].m_pData = *(unsigned __int8 **)(p_z - 224);
      p_m_nDataAllocSize = (float *)&p_m_verts->m_pMemory[v15 + 1].m_nDataAllocSize;
      *p_m_nDataAllocSize = *(p_z - 170);
      p_m_nDataAllocSize[1] = *(p_z - 169);
      p_m_nDataAllocSize[2] = *(p_z - 168);
      v20 = (float *)&p_m_verts->m_pMemory[v15 + 2].m_nDataAllocSize;
      *v20 = *(p_z - 114);
      v15 += 4;
      --v17;
      v20[1] = *(p_z - 113);
      v20[2] = *(p_z - 112);
      v21 = p_m_verts->m_pMemory;
      v21[v15 - 1].m_nDataAllocSize = *(int *)(p_z - 58);
      v21[v15 - 1].m_nDataLength = *(int *)(p_z - 57);
      v21[v15 - 1].m_pData = *(unsigned __int8 **)(p_z - 56);
    }
    while ( v17 != 0 );
    v14 = ia;
    v10 = count;
  }
  if ( v14 < v10 )
  {
    v22 = v14;
    v23 = &pDispInfo->m_pVerts[v14].m_Vert.z;
    v24 = v10 - v14;
    do
    {
      v25 = p_m_verts->m_pMemory;
      v25[v22].m_nDataAllocSize = *(int *)(v23 - 2);
      v23 += 56;
      ++v22;
      --v24;
      v25[v22 - 1].m_nDataLength = *(int *)(v23 - 57);
      v25[v22 - 1].m_pData = *(unsigned __int8 **)(v23 - 56);
    }
    while ( v24 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040C3C0
// Name: void TesselateDisplacementNode<class CVBSPTesselateHelper>(class CVBSPTesselateHelper __near *,class CVertIndex const __near &,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacementNode<CVBSPTesselateHelper>(
        CVBSPTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        char iLevel,
        int *pActiveChildren)
{
  int v5; // eax
  __int16 v6; // dx
  __int16 v7; // di
  int m_iNode; // ecx
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *m_pIndices; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v13; // eax
  unsigned __int16 *v14; // ebx
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *v15; // edi
  int v16; // ebx
  int v17; // eax
  unsigned __int16 *v18; // ecx
  int v19; // eax
  unsigned __int16 *v20; // eax
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *v21; // edi
  int v22; // ebx
  int v23; // eax
  unsigned __int16 *v24; // ecx
  int v25; // eax
  unsigned __int16 *v26; // eax
  int iVert; // [esp+Ch] [ebp-8h]
  int vertInc; // [esp+10h] [ebp-4h]
  int iCurTriVert; // [esp+1Ch] [ebp+8h]
  int iLevela; // [esp+24h] [ebp+10h]

  vertInc = 1 << (pHelper->m_pPowerInfo->m_Power - iLevel - 1);
  v5 = 0;
  iCurTriVert = 0;
  iVert = 0;
  if ( g_TWinding.m_nVerts > 0 )
  {
    iLevela = 0;
    do
    {
      v6 = nodeIndex->x + vertInc * g_TWinding.m_Verts[iLevela].m_Index.x;
      v7 = nodeIndex->y + vertInc * g_TWinding.m_Verts[iLevela].m_Index.y;
      m_iNode = g_TWinding.m_Verts[iLevela].m_iNode;
      if ( m_iNode == -1 || pActiveChildren[m_iNode] == 0 )
      {
        if ( ((1 << ((v6 + LOBYTE(pHelper->m_pPowerInfo->m_SideLength) * v7) & 0x1F))
            & pHelper->m_pActiveVerts[(v6 + pHelper->m_pPowerInfo->m_SideLength * v7) >> 5]) != 0 )
        {
          pHelper->m_TempIndices[iCurTriVert] = v6 + v7 * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          v5 = iCurTriVert + 1;
          iCurTriVert = v5;
          if ( v5 == 2 )
          {
            pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: pHelper->m_TempIndices);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[1]);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[2]);
            pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
            v5 = 1;
            iCurTriVert = 1;
          }
        }
        else
        {
          v5 = iCurTriVert;
        }
      }
      else
      {
        if ( v5 == 2 )
        {
          m_pIndices = pHelper->m_pIndices;
          pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          m_Size = m_pIndices->m_Size;
          m_nAllocationCount = m_pIndices->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
              this: &m_pIndices->m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++m_pIndices->m_Size;
          m_pMemory = m_pIndices->m_Memory.m_pMemory;
          v13 = m_pIndices->m_Size - m_Size - 1;
          m_pIndices->m_pElements = m_pIndices->m_Memory.m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v13);
          v14 = &m_pIndices->m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = pHelper->m_TempIndices[0];
          v15 = pHelper->m_pIndices;
          v16 = v15->m_Size;
          v17 = v15->m_Memory.m_nAllocationCount;
          if ( v16 + 1 > v17 )
            CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: &v15->m_Memory, num: v16 - v17 + 1);
          ++v15->m_Size;
          v18 = v15->m_Memory.m_pMemory;
          v19 = v15->m_Size - v16 - 1;
          v15->m_pElements = v15->m_Memory.m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 2 * v19);
          v20 = &v15->m_Memory.m_pMemory[v16];
          if ( v20 != nullptr )
            *v20 = pHelper->m_TempIndices[1];
          v21 = pHelper->m_pIndices;
          v22 = v21->m_Size;
          v23 = v21->m_Memory.m_nAllocationCount;
          if ( v22 + 1 > v23 )
            CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: &v21->m_Memory, num: v22 - v23 + 1);
          ++v21->m_Size;
          v24 = v21->m_Memory.m_pMemory;
          v25 = v21->m_Size - v22 - 1;
          v21->m_pElements = v21->m_Memory.m_pMemory;
          if ( v25 > 0 )
            _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 2 * v25);
          v26 = &v21->m_Memory.m_pMemory[v22];
          if ( v26 != nullptr )
            *v26 = pHelper->m_TempIndices[2];
          pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
        }
        v5 = 0;
        iCurTriVert = 0;
      }
      ++iLevela;
      ++iVert;
    }
    while ( iVert < g_TWinding.m_nVerts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C640
// Name: struct disp_grid_t __near & FindOrInsertGrid(int)
// Source: json
//------------------------------------------------------------------------------
disp_grid_t *__cdecl FindOrInsertGrid(int gridIndex)
{
  int m_Size; // ecx
  int v2; // eax
  disp_grid_t *m_pMemory; // edi
  disp_grid_t *v4; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  disp_grid_t *v8; // ecx

  m_Size = gDispGridList.m_Size;
  v2 = gDispGridList.m_Size - 1;
  m_pMemory = gDispGridList.m_Memory.m_pMemory;
  if ( gDispGridList.m_Size - 1 < 0 )
  {
LABEL_5:
    v5 = gDispGridList.m_Size;
    if ( gDispGridList.m_Size + 1 > gDispGridList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<DetailObjectGroup_t,int>::Grow(
        this: (CUtlMemory<DetailObjectGroup_t,int> *)&gDispGridList,
        num: gDispGridList.m_Size - gDispGridList.m_Memory.m_nAllocationCount + 1);
      m_Size = gDispGridList.m_Size;
      m_pMemory = gDispGridList.m_Memory.m_pMemory;
    }
    gDispGridList.m_Size = m_Size + 1;
    v6 = m_Size - v5;
    gDispGridList.m_pElements = m_pMemory;
    if ( v6 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 24 * v6);
      m_pMemory = gDispGridList.m_Memory.m_pMemory;
    }
    v7 = v5;
    v8 = &m_pMemory[v5];
    if ( v8 != nullptr )
    {
      v8->dispList.m_Memory.m_pMemory = nullptr;
      v8->dispList.m_Memory.m_nAllocationCount = 0;
      v8->dispList.m_Memory.m_nGrowSize = 0;
      v8->dispList.m_Size = 0;
      v8->dispList.m_pElements = nullptr;
      m_pMemory = gDispGridList.m_Memory.m_pMemory;
    }
    m_pMemory[v7].gridIndex = gridIndex;
    return &gDispGridList.m_Memory.m_pMemory[v7];
  }
  else
  {
    v4 = &gDispGridList.m_Memory.m_pMemory[v2];
    while ( v4->gridIndex != gridIndex )
    {
      --v2;
      --v4;
      if ( v2 < 0 )
        goto LABEL_5;
    }
    return &gDispGridList.m_Memory.m_pMemory[v2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C720
// Name: void TesselateDisplacement_R<class CVBSPTesselateHelper>(class CVBSPTesselateHelper __near *,class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacement_R<CVBSPTesselateHelper>(
        CVBSPTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  const CPowerInfo *m_pPowerInfo; // ecx
  int v6; // edx
  int v7; // ebx
  const CPowerInfo *v8; // ecx
  const CVertIndex *v9; // esi
  unsigned int v10; // edx
  int bActiveChildren[4]; // [esp+0h] [ebp-18h] BYREF
  int oldIndexCount; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  int iChildNodeBit; // [esp+20h] [ebp+8h]

  if ( (`CVBSPTesselateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
    `CVBSPTesselateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
  m_pPowerInfo = pHelper->m_pPowerInfo;
  v6 = m_pPowerInfo->m_Power - 1;
  oldIndexCount = pHelper->m_nIndices;
  if ( iLevel < v6 )
  {
    v7 = 0;
    iChildNodeBit = iNodeBitIndex + 1;
    v13 = 16 * (nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y);
    do
    {
      v8 = pHelper->m_pPowerInfo;
      v9 = &v8->m_pChildVerts->m_Verts[v13 / 4u];
      v10 = pHelper->m_pActiveVerts[(v9->x + v8->m_SideLength * v9->y) >> 5]
          & (1 << ((v9->x + LOBYTE(v8->m_SideLength) * v9->y) & 0x1F));
      bActiveChildren[v7] = v10;
      if ( v10 != 0 )
      {
        TesselateDisplacement_R<CVBSPTesselateHelper>(
          pHelper,
          nodeIndex: v9,
          iNodeBitIndex: iChildNodeBit,
          iLevel: iLevel + 1);
      }
      else
      {
        if ( (`CVBSPTesselateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
          `CVBSPTesselateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
        word_53C642 = 0;
      }
      iChildNodeBit += pHelper->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      v13 += 4;
      ++v7;
    }
    while ( v7 < 4 );
  }
  else
  {
    memset(bActiveChildren, 0, sizeof(bActiveChildren));
  }
  if ( pHelper->m_nIndices == oldIndexCount )
  {
    HIBYTE(word_53C642) = 0;
  }
  else
  {
    HIBYTE(word_53C642) = 1;
    oldIndexCount = pHelper->m_nIndices;
  }
  TesselateDisplacementNode<CVBSPTesselateHelper>(pHelper, nodeIndex, iLevel, pActiveChildren: bActiveChildren);
  LOBYTE(word_53C642) = LOBYTE(pHelper->m_nIndices) - oldIndexCount;
  `CVBSPTesselateHelper::GetNodeInfo'::`2'::dummy = oldIndexCount;
}

//------------------------------------------------------------------------------
// Address: 0x0040C850
// Name: void Disp_AddCollisionModels(class CUtlVector<class CPhysCollisionEntry __near *,class CUtlMemory<class CPhysCollisionEntry __near *,int>> __near &,struct dmodel_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Disp_AddCollisionModels(
        CUtlVector<CPhysCollisionEntry *,CUtlMemory<CPhysCollisionEntry *,int> > *collisionList,
        dmodel_t *pModel,
        int contentsMask)
{
  int v3; // edi
  int v4; // eax
  float *m_Nodes; // eax
  disp_grid_t *inserted; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v10; // eax
  int *v11; // ebx
  struct CPhysPolysoup *(__thiscall *PolysoupCreate)(IPhysicsCollision *); // edx
  disp_grid_t *v13; // eax
  int v14; // eax
  CCoreDispInfo *v15; // esi
  dtexdata_t *TexData; // eax
  const char *String; // eax
  void *OriginalMaterial; // eax
  int v19; // ebx
  CPhysCollisionEntryStaticMesh *v20; // eax
  int v21; // ecx
  int v22; // eax
  CPhysCollisionEntry **v23; // edx
  int v24; // eax
  CPhysCollisionEntry **v25; // ecx
  CoreDispVert_t *m_pVerts; // edx
  int v27; // ecx
  float x; // xmm0_4
  int p_m_Vert; // ecx
  CoreDispVert_t *v30; // ecx
  float m_Alpha; // xmm1_4
  int v32; // edx
  float v33; // xmm0_4
  int v34; // ecx
  CoreDispVert_t *v35; // ecx
  float v36; // xmm0_4
  int v37; // ebx
  int SurfaceProperties2; // eax
  int v39; // eax
  unsigned __int16 *v40; // eax
  CPhysCollide *v41; // esi
  CPhysCollisionEntryStaticMesh *v42; // eax
  int v43; // ebx
  int v44; // eax
  CPhysCollisionEntry **v45; // ecx
  int v46; // eax
  CPhysCollisionEntry **v47; // ebx
  Vector tmpVerts[3]; // [esp+Ch] [ebp-74h] BYREF
  CVBSPTesselateHelper helper; // [esp+30h] [ebp-50h] BYREF
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > indices; // [esp+4Ch] [ebp-34h] BYREF
  void *matID; // [esp+60h] [ebp-20h]
  mapdispinfo_t *pMapDisp; // [esp+64h] [ebp-1Ch]
  int grid; // [esp+68h] [ebp-18h]
  CPhysCollide *pCollide; // [esp+6Ch] [ebp-14h]
  int listIndex; // [esp+70h] [ebp-10h]
  int triCount; // [esp+74h] [ebp-Ch]
  int dispIndex; // [esp+78h] [ebp-8h]
  struct CPhysPolysoup *pTerrainPhysics; // [esp+7Ch] [ebp-4h]

  v3 = 0;
  v4 = 0;
  dispIndex = 0;
  if ( g_CoreDispInfos.m_Size > 0 )
  {
    pTerrainPhysics = (struct CPhysPolysoup *)&unk_54E748;
    do
    {
      if ( (contentsMask & *(_DWORD *)pTerrainPhysics) != 0 )
      {
        m_Nodes = (float *)g_CoreDispInfos.m_Memory.m_pMemory[v4]->m_Nodes;
        inserted = FindOrInsertGrid(
                     gridIndex: (unsigned __int8)(int)(float)((float)((float)((float)(m_Nodes[3] + *m_Nodes) * 0.5) + 16384.0)
                                                 * 0.00024414062)
                   | (((unsigned __int8)(int)(float)((float)((float)((float)(m_Nodes[4] + m_Nodes[1]) * 0.5) + 16384.0)
                                                   * 0.00024414062)
                     | ((unsigned __int8)(int)(float)((float)((float)((float)(m_Nodes[5] + m_Nodes[2]) * 0.5) + 16384.0)
                                                    * 0.00012207031) << 8)) << 8));
        m_Size = inserted->dispList.m_Size;
        m_nAllocationCount = inserted->dispList.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CClassInput *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&inserted->dispList,
            num: m_Size - m_nAllocationCount + 1);
        ++inserted->dispList.m_Size;
        m_pMemory = inserted->dispList.m_Memory.m_pMemory;
        v10 = inserted->dispList.m_Size - m_Size - 1;
        inserted->dispList.m_pElements = m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
        v11 = &inserted->dispList.m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
          *v11 = dispIndex;
      }
      pTerrainPhysics = (struct CPhysPolysoup *)((char *)pTerrainPhysics + 33668);
      v4 = dispIndex + 1;
      dispIndex = v4;
    }
    while ( v4 < g_CoreDispInfos.m_Size );
  }
  grid = 0;
  if ( gDispGridList.m_Size > 0 )
  {
    dispIndex = 16;
    do
    {
      PolysoupCreate = physcollision->PolysoupCreate;
      triCount = 0;
      pTerrainPhysics = PolysoupCreate(this: physcollision);
      v13 = gDispGridList.m_Memory.m_pMemory;
      for ( listIndex = 0;
            listIndex < *(int *)((char *)&gDispGridList.m_Memory.m_pMemory->gridIndex + dispIndex);
            ++listIndex )
      {
        v14 = *(_DWORD *)(*(_DWORD *)((char *)v13 + dispIndex - 12) + 4 * listIndex);
        v15 = g_CoreDispInfos.m_Memory.m_pMemory[v14];
        pMapDisp = (mapdispinfo_t *)((char *)&mapdispinfo + 33668 * v14);
        TexData = GetTexData(index: texinfo.m_Memory.m_pMemory[pMapDisp->face.texinfo].texdata);
        String = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
        OriginalMaterial = FindOriginalMaterial(materialName: String, pFound: nullptr, bComplain: true);
        helper.m_pIndices = &indices;
        helper.m_pActiveVerts = v15->m_AllowedVerts.m_Ints;
        matID = OriginalMaterial;
        memset(&indices, 0, sizeof(indices));
        helper.m_pPowerInfo = (const CPowerInfo *)v15->GetPowerInfo(this: v15);
        helper.m_nIndices = 0;
        TesselateDisplacement_R<CVBSPTesselateHelper>(
          pHelper: &helper,
          nodeIndex: &helper.m_pPowerInfo->m_RootNode,
          iNodeBitIndex: 0,
          iLevel: 0);
        v19 = indices.m_Size / 3;
        triCount += indices.m_Size / 3;
        if ( triCount >= 0x10000 )
        {
          pCollide = physcollision->ConvertPolysoupToCollide(this: physcollision, a2: pTerrainPhysics, a3: 0);
          if ( pCollide != nullptr )
          {
            v20 = (CPhysCollisionEntryStaticMesh *)MemAlloc_Alloc(nSize: 0xCu);
            if ( v20 != nullptr )
              pCollide = (CPhysCollide *)CPhysCollisionEntryStaticMesh::CPhysCollisionEntryStaticMesh(
                                           this: v20,
                                           pCollide,
                                           pMaterialName: nullptr);
            else
              pCollide = nullptr;
            v22 = collisionList->m_Memory.m_nAllocationCount;
            triCount = collisionList->m_Size;
            v21 = triCount;
            if ( triCount + 1 > v22 )
            {
              CUtlMemory<CClassInput *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)collisionList,
                num: triCount - v22 + 1);
              v21 = triCount;
            }
            ++collisionList->m_Size;
            v23 = collisionList->m_Memory.m_pMemory;
            v24 = collisionList->m_Size - v21 - 1;
            collisionList->m_pElements = collisionList->m_Memory.m_pMemory;
            if ( v24 > 0 )
            {
              _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 4 * v24);
              v21 = triCount;
            }
            v25 = &collisionList->m_Memory.m_pMemory[v21];
            v3 = 0;
            if ( v25 != nullptr )
              *v25 = (CPhysCollisionEntry *)pCollide;
          }
          physcollision->PolysoupDestroy(this: physcollision, a2: pTerrainPhysics);
          pTerrainPhysics = physcollision->PolysoupCreate(this: physcollision);
          triCount = v19;
        }
        if ( v19 > 0 )
        {
          for ( pCollide = (CPhysCollide *)v19; pCollide != nullptr; pCollide = (CPhysCollide *)((char *)pCollide - 1) )
          {
            m_pVerts = v15->m_pVerts;
            v27 = indices.m_Memory.m_pMemory[v3];
            x = m_pVerts[v27].m_Vert.x;
            p_m_Vert = (int)&m_pVerts[v27].m_Vert;
            tmpVerts[0].x = x;
            tmpVerts[0].y = *(float *)(p_m_Vert + 4);
            tmpVerts[0].z = *(float *)(p_m_Vert + 8);
            v30 = v15->m_pVerts;
            m_Alpha = v30[indices.m_Memory.m_pMemory[v3]].m_Alpha;
            v32 = indices.m_Memory.m_pMemory[v3 + 1];
            v33 = v30[v32].m_Vert.x;
            v34 = (int)&v30[v32].m_Vert;
            tmpVerts[1].x = v33;
            tmpVerts[1].y = *(float *)(v34 + 4);
            tmpVerts[1].z = *(float *)(v34 + 8);
            v35 = v15->m_pVerts;
            v36 = v35[indices.m_Memory.m_pMemory[v3 + 1]].m_Alpha;
            tmpVerts[2] = v35[indices.m_Memory.m_pMemory[v3 + 2]].m_Vert;
            v37 = g_SurfaceProperties[texinfo.m_Memory.m_pMemory[pMapDisp->face.texinfo].texdata];
            if ( (float)(v15->m_pVerts[indices.m_Memory.m_pMemory[v3 + 2]].m_Alpha + (float)(v36 + m_Alpha)) > 382.5 )
            {
              SurfaceProperties2 = GetSurfaceProperties2(matID, pMatName: "surfaceprop2");
              if ( SurfaceProperties2 != -1 )
                v37 = SurfaceProperties2;
            }
            v39 = RemapWorldMaterial(materialIndexIn: v37);
            physcollision->PolysoupAddTriangle(
              this: physcollision,
              a2: pTerrainPhysics,
              a3: tmpVerts,
              a4: &tmpVerts[1],
              a5: &tmpVerts[2],
              a6: v39);
            v3 += 3;
          }
          v3 = 0;
        }
        v40 = indices.m_Memory.m_pMemory;
        indices.m_Size = 0;
        if ( indices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( indices.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indices.m_Memory.m_pMemory);
            v40 = nullptr;
            indices.m_Memory.m_pMemory = nullptr;
          }
          indices.m_Memory.m_nAllocationCount = 0;
        }
        indices.m_pElements = v40;
        if ( indices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v40 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
            indices.m_Memory.m_pMemory = nullptr;
          }
          indices.m_Memory.m_nAllocationCount = 0;
        }
        v13 = gDispGridList.m_Memory.m_pMemory;
      }
      v41 = physcollision->ConvertPolysoupToCollide(this: physcollision, a2: pTerrainPhysics, a3: 0);
      if ( v41 != nullptr )
      {
        v42 = (CPhysCollisionEntryStaticMesh *)MemAlloc_Alloc(nSize: 0xCu);
        if ( v42 != nullptr )
          pCollide = (CPhysCollide *)CPhysCollisionEntryStaticMesh::CPhysCollisionEntryStaticMesh(
                                       this: v42,
                                       pCollide: v41,
                                       pMaterialName: nullptr);
        else
          pCollide = nullptr;
        v43 = collisionList->m_Size;
        v44 = collisionList->m_Memory.m_nAllocationCount;
        if ( v43 + 1 > v44 )
          CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)collisionList, num: v43 - v44 + 1);
        ++collisionList->m_Size;
        v45 = collisionList->m_Memory.m_pMemory;
        v46 = collisionList->m_Size - v43 - 1;
        collisionList->m_pElements = collisionList->m_Memory.m_pMemory;
        if ( v46 > 0 )
          _V_memmove(dest: &v45[v43 + 1], src: &v45[v43], count: 4 * v46);
        v47 = &collisionList->m_Memory.m_pMemory[v43];
        if ( v47 != nullptr )
          *v47 = (CPhysCollisionEntry *)pCollide;
      }
      physcollision->PolysoupDestroy(this: physcollision, a2: pTerrainPhysics);
      dispIndex += 24;
      ++grid;
    }
    while ( grid < gDispGridList.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CDD0
// Name: void Disp_BuildVirtualMesh(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall Disp_BuildVirtualMesh(virtualmeshparams_t *p_params@<ebx>, int contentsMask)
{
  int m_Size; // eax
  int v3; // esi
  int v4; // ebx
  CCoreDispInfo *v5; // edi
  int v6; // eax
  unsigned __int16 *m_pMemory; // edx
  CoreDispVert_t *m_pVerts; // eax
  int v9; // ecx
  __int64 v10; // xmm0_8
  int p_m_Vert; // ecx
  __int64 v12; // xmm0_8
  int v13; // eax
  __int64 v14; // xmm0_8
  float v15; // eax
  dtexdata_t *TexData; // eax
  const char *String; // eax
  CPhysCollide *v18; // eax
  Vector *v19; // eax
  unsigned __int16 *v20; // eax
  unsigned __int16 numDisplacements; // ax
  int v22; // edi
  unsigned __int16 v23; // ax
  unsigned __int16 v24; // bx
  int v25; // eax
  unsigned __int8 *v26; // eax
  int v27; // eax
  int v28; // ebx
  CPhysCollide **v29; // edi
  int v30; // esi
  int v31; // eax
  unsigned __int16 *v32; // edi
  int v33; // eax
  CVBSPTesselateHelper helper; // [esp+24h] [ebp-D0h] BYREF
  virtualmeshparams_t params; // [esp+40h] [ebp-B4h] BYREF
  CDispMeshEvent meshHandler; // [esp+4Ch] [ebp-A8h] BYREF
  Vector v1; // [esp+6Ch] [ebp-88h]
  Vector v0; // [esp+78h] [ebp-7Ch]
  Vector v2; // [esp+84h] [ebp-70h]
  CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > virtualMeshes; // [esp+90h] [ebp-64h] BYREF
  CUtlBuffer buf; // [esp+A4h] [ebp-50h] BYREF
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > indices; // [esp+D4h] [ebp-20h] BYREF
  int v44; // [esp+E8h] [ebp-Ch] BYREF
  dphysdisp_t header; // [esp+ECh] [ebp-8h] BYREF
  int src; // [esp+F0h] [ebp-4h] BYREF

  m_Size = g_CoreDispInfos.m_Size;
  v3 = 0;
  memset(&virtualMeshes, 0, sizeof(virtualMeshes));
  if ( g_CoreDispInfos.m_Size > 0 )
  {
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&virtualMeshes,
      elem: 0,
      num: g_CoreDispInfos.m_Size);
    m_Size = g_CoreDispInfos.m_Size;
  }
  v4 = 0;
  if ( m_Size > 0 )
  {
    src = (int)&mapdispinfo;
    do
    {
      v5 = g_CoreDispInfos.m_Memory.m_pMemory[v4];
      v6 = src;
      virtualMeshes.m_Memory.m_pMemory[v4] = nullptr;
      if ( (contentsMask & *(_DWORD *)(v6 + 32632)) != 0 )
      {
        helper.m_pIndices = &indices;
        helper.m_pActiveVerts = v5->m_AllowedVerts.m_Ints;
        memset(&indices, 0, sizeof(indices));
        helper.m_pPowerInfo = (const CPowerInfo *)((int (__thiscall *)(CCoreDispInfo *, virtualmeshparams_t *))v5->GetPowerInfo)(
                                                    a1: v5,
                                                    a2: p_params);
        helper.m_nIndices = 0;
        TesselateDisplacement_R<CVBSPTesselateHelper>(
          pHelper: &helper,
          nodeIndex: &helper.m_pPowerInfo->m_RootNode,
          iNodeBitIndex: 0,
          iLevel: 0);
        m_pMemory = indices.m_Memory.m_pMemory;
        if ( indices.m_Size / 3 > 0 )
        {
          v44 = indices.m_Size / 3;
          do
          {
            m_pVerts = v5->m_pVerts;
            v9 = m_pMemory[v3];
            v10 = *(_QWORD *)&m_pVerts[v9].m_Vert.x;
            v0.z = m_pVerts[v9].m_Vert.z;
            p_m_Vert = (int)&m_pVerts[m_pMemory[v3 + 1]].m_Vert;
            *(_QWORD *)&v0.x = v10;
            v12 = *(_QWORD *)p_m_Vert;
            v1.z = *(float *)(p_m_Vert + 8);
            v13 = (int)&m_pVerts[m_pMemory[v3 + 2]].m_Vert;
            *(_QWORD *)&v1.x = v12;
            v14 = *(_QWORD *)v13;
            v15 = *(float *)(v13 + 8);
            *(_QWORD *)&v2.x = v14;
            v2.z = v15;
            if ( v1.x == v0.x && v1.y == v0.y && v1.z == v0.z
              || v2.x == v1.x && v2.y == v1.y && v2.z == v1.z
              || v0.x == v2.x && v0.y == v2.y && v0.z == v2.z )
            {
              _Warning(a1: "Displacement %d has bad geometry near %.2f %.2f %.2f\n", v4, v0.x, v0.y, v0.z);
              TexData = GetTexData(index: texinfo.m_Memory.m_pMemory[*(_DWORD *)(src + 24)].texdata);
              String = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
              _Error(a1: "Can't compile displacement physics, exiting.  Texture is %s\n", String);
              m_pMemory = indices.m_Memory.m_pMemory;
            }
            v3 += 3;
            --v44;
          }
          while ( v44 != 0 );
          v3 = 0;
        }
        CDispMeshEvent::CDispMeshEvent(
          this: &meshHandler,
          pIndices: m_pMemory,
          indexCount: indices.m_Size,
          pDispInfo: v5);
        params.pMeshEventHandler = &meshHandler;
        params.userData = &meshHandler;
        params.buildOuterHull = true;
        p_params = &params;
        v18 = (CPhysCollide *)((int (__thiscall *)(IPhysicsCollision *))physcollision->CreateVirtualMesh)(a1: physcollision);
        virtualMeshes.m_Memory.m_pMemory[v4] = v18;
        v19 = meshHandler.m_verts.m_Memory.m_pMemory;
        meshHandler.m_verts.m_Size = 0;
        if ( meshHandler.m_verts.m_Memory.m_nGrowSize >= 0 )
        {
          if ( meshHandler.m_verts.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: meshHandler.m_verts.m_Memory.m_pMemory);
            v19 = nullptr;
            meshHandler.m_verts.m_Memory.m_pMemory = nullptr;
          }
          meshHandler.m_verts.m_Memory.m_nAllocationCount = 0;
        }
        meshHandler.m_verts.m_pElements = v19;
        if ( meshHandler.m_verts.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v19 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
            meshHandler.m_verts.m_Memory.m_pMemory = nullptr;
          }
          meshHandler.m_verts.m_Memory.m_nAllocationCount = 0;
        }
        v20 = indices.m_Memory.m_pMemory;
        indices.m_Size = 0;
        if ( indices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( indices.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indices.m_Memory.m_pMemory);
            v20 = nullptr;
            indices.m_Memory.m_pMemory = nullptr;
          }
          indices.m_Memory.m_nAllocationCount = 0;
        }
        indices.m_pElements = v20;
        if ( indices.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
      }
      src += 33668;
      ++v4;
    }
    while ( v4 < g_CoreDispInfos.m_Size );
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  header.numDisplacements = g_CoreDispInfos.m_Size;
  CUtlBuffer::PutObjects<dphysdisp_t>(this: &buf, src: &header, count: 1);
  numDisplacements = header.numDisplacements;
  v22 = 0;
  memset(&indices, 0, sizeof(indices));
  if ( header.numDisplacements != 0 )
  {
    do
    {
      if ( virtualMeshes.m_Memory.m_pMemory[v22] != nullptr )
      {
        v23 = physcollision->CollideSize(this: physcollision, a2: virtualMeshes.m_Memory.m_pMemory[v22]);
        v24 = v23;
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%hd", (__int16)v23);
        }
        else
        {
          v44 = v23;
          if ( CUtlBuffer::CheckPut(this: &buf, nSize: 2) )
          {
            v25 = buf.m_Put - buf.m_nOffset;
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
            {
              v26 = &buf.m_Memory.m_pMemory[v25];
              if ( v26 != nullptr )
              {
                if ( (*(_BYTE *)&buf.m_Byteswap & 1) == 0 )
                  goto LABEL_52;
                HIWORD(src) = 0;
                LOBYTE(src) = HIBYTE(v24);
                BYTE1(src) = v24;
                _V_memcpy(dest: v26, &src, count: 2);
              }
            }
            else
            {
              *(_WORD *)&buf.m_Memory.m_pMemory[v25] = v24;
            }
            goto LABEL_55;
          }
        }
      }
      else
      {
        if ( (buf.m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: &buf, pFmt: "%hd", -1);
          goto LABEL_57;
        }
        v44 = -1;
        if ( CUtlBuffer::CheckPut(this: &buf, nSize: 2) )
        {
          v27 = buf.m_Put - buf.m_nOffset;
          if ( (*(_BYTE *)&buf.m_Byteswap & 1) == 0 )
          {
            *(_WORD *)&buf.m_Memory.m_pMemory[v27] = -1;
            goto LABEL_55;
          }
          v26 = &buf.m_Memory.m_pMemory[v27];
          if ( v26 != nullptr )
          {
            if ( (*(_BYTE *)&buf.m_Byteswap & 1) != 0 )
            {
              src = 0xFFFF;
              _V_memcpy(dest: v26, &src, count: 2);
              goto LABEL_55;
            }
LABEL_52:
            if ( v26 != (unsigned __int8 *)&v44 )
              *(_WORD *)v26 = v44;
          }
LABEL_55:
          buf.m_Put += 2;
          CUtlBuffer::AddNullTermination(this: &buf, nPut: buf.m_Put);
        }
      }
LABEL_57:
      numDisplacements = header.numDisplacements;
      ++v22;
    }
    while ( v22 < header.numDisplacements );
  }
  v28 = 0;
  if ( numDisplacements != 0 )
  {
    do
    {
      v29 = virtualMeshes.m_Memory.m_pMemory;
      if ( virtualMeshes.m_Memory.m_pMemory[v28] != nullptr )
      {
        v30 = ((int (__thiscall *)(IPhysicsCollision *, CPhysCollide *, virtualmeshparams_t *))physcollision->CollideSize)(
                a1: physcollision,
                a2: virtualMeshes.m_Memory.m_pMemory[v28],
                a3: p_params);
        v31 = 0;
        indices.m_Size = 0;
        if ( v30 <= 0 )
        {
          v32 = indices.m_Memory.m_pMemory;
        }
        else
        {
          if ( v30 > indices.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<bool,int>::Grow(
              this: (CUtlMemory<char,int> *)&indices,
              num: v30 - indices.m_Memory.m_nAllocationCount);
            v31 = indices.m_Size;
          }
          v32 = indices.m_Memory.m_pMemory;
          indices.m_pElements = indices.m_Memory.m_pMemory;
          if ( v31 > 0 )
            _V_memmove(dest: (char *)indices.m_Memory.m_pMemory + v30, src: indices.m_Memory.m_pMemory, count: v31);
        }
        p_params = nullptr;
        v33 = ((int (__thiscall *)(IPhysicsCollision *, unsigned __int16 *, CPhysCollide *))physcollision->CollideWrite)(
                a1: physcollision,
                a2: v32,
                a3: virtualMeshes.m_Memory.m_pMemory[v28]);
        CUtlBuffer::Put(this: &buf, pMem: v32, size: v33);
        numDisplacements = header.numDisplacements;
        v29 = virtualMeshes.m_Memory.m_pMemory;
      }
      ++v28;
    }
    while ( v28 < numDisplacements );
  }
  else
  {
    v29 = virtualMeshes.m_Memory.m_pMemory;
  }
  g_PhysDispSize = buf.m_nMaxPut;
  g_pPhysDisp = (unsigned __int8 *)MemAlloc_Alloc(nSize: buf.m_nMaxPut);
  _V_memcpy(dest: g_pPhysDisp, src: buf.m_Memory.m_pMemory, count: g_PhysDispSize);
  if ( indices.m_Memory.m_nGrowSize >= 0 && indices.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indices.m_Memory.m_pMemory);
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( virtualMeshes.m_Memory.m_nGrowSize >= 0 && v29 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
}
