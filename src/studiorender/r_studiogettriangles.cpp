// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/r_studiogettriangles.cpp
// Functions: 2
// ============================================================

#include "studiorender\r_studiogettriangles.h"

//------------------------------------------------------------------------------
// Address: 0x100144B0
// Name: public: virtual void CStudioRenderContext::GetTriangles(struct DrawModelInfo_t const __near &,struct matrix3x4_t __near *,struct GetTriangles_Output_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRenderContext::GetTriangles(
        CStudioRenderContext *this,
        const DrawModelInfo_t *info,
        studiomeshgroup_t *pBoneToWorld,
        GetTriangles_Output_t *out)
{
  GetTriangles_Output_t *v4; // edi
  const DrawModelInfo_t *v5; // esi
  studiohdr_t *m_pStudioHdr; // eax
  studiohwdata_t *m_pHardwareData; // ebx
  int m_NumLODs; // edx
  int m_Lod; // ecx
  int v10; // edx
  int m_Skin; // edx
  studioloddata_t *v12; // edx
  const studiohdr_t *v13; // eax
  int v14; // ebx
  mstudiomesh_t *v15; // ebx
  const mstudio_modelvertexdata_t *v16; // eax
  _DWORD **v17; // esi
  int v18; // edi
  GetTriangles_Vertex_t *v19; // ecx
  float *v20; // eax
  _DWORD *v21; // ebx
  float *v22; // eax
  float *v23; // eax
  float *v24; // eax
  int v25; // eax
  int v26; // ebx
  studiomeshdata_t *v27; // edx
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *p_m_TriListIndices; // esi
  studiomeshgroup_t *v29; // ecx
  int *p_numIndices; // eax
  char *v31; // ebx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edi
  int m_nAllocationCount; // eax
  void (__cdecl **v34)(IConVar *, const char *, float); // edx
  int v35; // eax
  void (__cdecl **v36)(IConVar *, const char *, float); // edi
  void (__cdecl **v37)(IConVar *, const char *, float); // edi
  int v38; // eax
  void (__cdecl **v39)(IConVar *, const char *, float); // edx
  int v40; // eax
  void (__cdecl **v41)(IConVar *, const char *, float); // edi
  void (__cdecl *v42)(IConVar *, const char *, float); // ebx
  void (__cdecl **v43)(IConVar *, const char *, float); // edi
  int v44; // eax
  void (__cdecl **v45)(IConVar *, const char *, float); // edx
  int v46; // eax
  void (__cdecl **v47)(IConVar *, const char *, float); // edi
  int m_Body; // [esp-10h] [ebp-54h]
  int numvertices; // [esp-8h] [ebp-4Ch]
  studiomeshdata_t *pMeshData; // [esp+8h] [ebp-3Ch]
  void (__cdecl *v51)(IConVar *, const char *, float); // [esp+Ch] [ebp-38h]
  void (__cdecl *v52)(IConVar *, const char *, float); // [esp+Ch] [ebp-38h]
  studiomeshdata_t *pStudioMeshes; // [esp+10h] [ebp-34h]
  IMaterial **ppMaterials; // [esp+14h] [ebp-30h]
  __int16 *pSkinRef; // [esp+18h] [ebp-2Ch]
  int ia; // [esp+1Ch] [ebp-28h]
  int k; // [esp+20h] [ebp-24h]
  int stripGroupID; // [esp+24h] [ebp-20h]
  int stripID; // [esp+28h] [ebp-1Ch]
  OptimizedModel::StripHeader_t *pStripData; // [esp+2Ch] [ebp-18h]
  int v62; // [esp+30h] [ebp-14h]
  mstudiomesh_t *pMesh; // [esp+34h] [ebp-10h]
  mstudiomesh_t *pMesha; // [esp+34h] [ebp-10h]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+38h] [ebp-Ch]
  GetTriangles_MaterialBatch_t *materialBatcha; // [esp+38h] [ebp-Ch]
  int v67; // [esp+3Ch] [ebp-8h]
  int v68; // [esp+3Ch] [ebp-8h]
  mstudiomodel_t *pModel; // [esp+40h] [ebp-4h] BYREF
  studiomeshgroup_t *pMeshGroup; // [esp+50h] [ebp+Ch]
  studiomeshgroup_t *pMeshGroupa; // [esp+50h] [ebp+Ch]

  v4 = out;
  CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::RemoveAll(this: &out->m_MaterialBatches);
  v5 = info;
  m_pStudioHdr = info->m_pStudioHdr;
  if ( info->m_pStudioHdr == nullptr )
    return;
  m_pHardwareData = info->m_pHardwareData;
  if ( m_pHardwareData == nullptr )
    return;
  m_NumLODs = m_pHardwareData->m_NumLODs;
  if ( m_NumLODs == 0 || m_pHardwareData->m_pLODs == nullptr )
    return;
  m_Lod = info->m_Lod;
  v10 = m_NumLODs - 1;
  if ( m_Lod == -2 )
    goto LABEL_9;
  if ( m_Lod >= 0 )
  {
    if ( m_Lod <= v10 )
      goto LABEL_10;
LABEL_9:
    m_Lod = v10;
    goto LABEL_10;
  }
  m_Lod = 0;
LABEL_10:
  if ( m_Lod < m_pHardwareData->m_RootLOD )
    m_Lod = m_pHardwareData->m_RootLOD;
  m_Skin = info->m_Skin;
  if ( m_Skin >= m_pStudioHdr->numskinfamilies )
    m_Skin = 0;
  pSkinRef = (__int16 *)((char *)m_pStudioHdr + 2 * m_Skin * m_pStudioHdr->numskinref + m_pStudioHdr->skinindex);
  v12 = &info->m_pHardwareData->m_pLODs[m_Lod];
  ppMaterials = v12->ppMaterials;
  pStudioMeshes = v12->m_pMeshData;
  ComputePoseToWorld(
    pPoseToWorld: out->m_PoseToWorld,
    pStudioHdr: m_pStudioHdr,
    boneMask: 1024 << m_Lod,
    vecViewOrigin: &this->m_RC.m_ViewOrigin,
    (const matrix3x4_t *)pBoneToWorld);
  v13 = info->m_pStudioHdr;
  v14 = 0;
  ia = 0;
  if ( info->m_pStudioHdr->numbodyparts > 0 )
  {
    do
    {
      m_Body = v5->m_Body;
      pModel = nullptr;
      R_StudioSetupModel(bodypart: v14, entity_body: m_Body, ppSubModel: &pModel, pStudioHdr: v13);
      k = 0;
      if ( pModel->nummeshes > 0 )
      {
        v62 = 0;
        do
        {
          materialBatch = &v4->m_MaterialBatches.m_Memory.m_pMemory[CUtlVector<GetTriangles_MaterialBatch_t,CUtlMemory<GetTriangles_MaterialBatch_t,int>>::InsertBefore(
                                                                      this: &v4->m_MaterialBatches,
                                                                      elem: v4->m_MaterialBatches.m_Size)];
          v15 = (mstudiomesh_t *)&pModel->name[v62 + pModel->meshindex];
          pMesh = v15;
          if ( mstudiomodel_t::CacheVertexData(this: pModel, pModelData: v5->m_pStudioHdr) != nullptr )
          {
            mstudiomodel_t::GetVertexData(
              this: (mstudiomodel_t *)((char *)v15 + v15->modelindex),
              pModelData: v5->m_pStudioHdr);
            v16 = (const mstudio_modelvertexdata_t *)((char *)&v15->unused[6] + v15->modelindex);
            v15->vertexdata.modelvertexdata = v16;
            v17 = v16->pVertexData != nullptr ? (_DWORD **)&v15->vertexdata : nullptr;
            v18 = 0;
            numvertices = v15->numvertices;
            materialBatch->m_Verts.m_Size = 0;
            CUtlVector<GetTriangles_Vertex_t,CUtlMemory<GetTriangles_Vertex_t,int>>::InsertMultipleBefore(
              this: &materialBatch->m_Verts,
              elem: 0,
              num: numvertices);
            if ( v15->numvertices > 0 )
            {
              v67 = 0;
              do
              {
                v19 = &materialBatch->m_Verts.m_Memory.m_pMemory[v67];
                v20 = (float *)(**v17 + 48 * ((_DWORD)*(v17 - 9) + *(*v17 - 6) / 0x30u + v18) + 16);
                v19->m_Position.x = *v20;
                v19->m_Position.y = v20[1];
                v19->m_Position.z = v20[2];
                v21 = *v17;
                v22 = (float *)(**v17 + 48 * ((_DWORD)*(v17 - 9) + *(*v17 - 6) / 0x30u + v18) + 28);
                v19->m_Normal.x = *v22;
                v19->m_Normal.y = v22[1];
                v19->m_Normal.z = v22[2];
                v23 = (float *)(*v21 + 48 * ((_DWORD)*(v17 - 9) + *(v21 - 6) / 0x30u + v18) + 40);
                v19->m_TexCoord.x = *v23;
                v19->m_TexCoord.y = v23[1];
                if ( v21[1] != 0 )
                {
                  v24 = (float *)(v21[1] + 16 * ((_DWORD)*(v17 - 9) + (*(v21 - 5) >> 4) + v18));
                  v19->m_TangentS.x = *v24;
                  v19->m_TangentS.y = v24[1];
                  v19->m_TangentS.z = v24[2];
                  v19->m_TangentS.w = v24[3];
                }
                v25 = *(unsigned __int8 *)(*v21 + 48 * ((_DWORD)*(v17 - 9) + *(v21 - 6) / 0x30u + v18) + 15);
                v26 = 0;
                v19->m_NumBones = v25;
                if ( v25 != 0 )
                {
                  pMeshGroup = (studiomeshgroup_t *)v19->m_BoneIndex;
                  do
                  {
                    pMeshGroup[-1].m_pIndices = *(unsigned __int16 **)(**v17
                                                                     + 4
                                                                     * (v26
                                                                      + 12
                                                                      * ((_DWORD)*(v17 - 9) + *(*v17 - 6) / 0x30u + v18)));
                    ++v26;
                    pMeshGroup->m_pMesh = (IMesh *)*(unsigned __int8 *)(**v17
                                                                      + 48
                                                                      * ((_DWORD)*(v17 - 9) + *(*v17 - 6) / 0x30u + v18)
                                                                      + v26
                                                                      + 11);
                    pMeshGroup = (studiomeshgroup_t *)((char *)pMeshGroup + 4);
                  }
                  while ( v26 < v19->m_NumBones );
                }
                ++v67;
                ++v18;
              }
              while ( v18 < pMesh->numvertices );
              v15 = pMesh;
            }
            materialBatch->m_pMaterial = ppMaterials[pSkinRef[v15->material]];
            v27 = &pStudioMeshes[v15->meshid];
            pMeshData = v27;
            if ( v27->m_NumGroup != 0 )
            {
              p_m_TriListIndices = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&materialBatch->m_TriListIndices;
              materialBatch->m_TriListIndices.m_Size = 0;
              stripGroupID = 0;
              if ( v27->m_NumGroup > 0 )
              {
                pMesha = nullptr;
                do
                {
                  v29 = (studiomeshgroup_t *)((char *)pMesha + (unsigned int)v27->m_pMeshGroup);
                  stripID = 0;
                  pMeshGroupa = v29;
                  if ( v29->m_NumStrips > 0 )
                  {
                    v68 = 0;
                    do
                    {
                      p_numIndices = &v29->m_pStripData[v68].numIndices;
                      materialBatcha = nullptr;
                      pStripData = (OptimizedModel::StripHeader_t *)p_numIndices;
                      if ( *p_numIndices > 0 )
                      {
                        while ( 1 )
                        {
                          v31 = (char *)materialBatcha + p_numIndices[1];
                          m_pMemory = p_m_TriListIndices[1].m_pMemory;
                          v51 = (void (__cdecl *)(IConVar *, const char *, float))v29->m_pGroupIndexToMeshIndex[v29->m_pIndices[(_DWORD)v31]];
                          m_nAllocationCount = p_m_TriListIndices->m_nAllocationCount;
                          if ( (int)m_pMemory + 1 > m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: p_m_TriListIndices,
                              num: (int)m_pMemory - m_nAllocationCount + 1);
                            v29 = pMeshGroupa;
                          }
                          ++p_m_TriListIndices[1].m_pMemory;
                          v34 = p_m_TriListIndices->m_pMemory;
                          v35 = (char *)p_m_TriListIndices[1].m_pMemory - (char *)m_pMemory - 1;
                          p_m_TriListIndices[1].m_nAllocationCount = (int)p_m_TriListIndices->m_pMemory;
                          if ( v35 > 0 )
                          {
                            _V_memmove(dest: &v34[(_DWORD)m_pMemory + 1], src: &v34[(_DWORD)m_pMemory], count: 4 * v35);
                            v29 = pMeshGroupa;
                          }
                          v36 = &p_m_TriListIndices->m_pMemory[(_DWORD)m_pMemory];
                          if ( v36 != nullptr )
                            *v36 = v51;
                          v37 = p_m_TriListIndices[1].m_pMemory;
                          v52 = (void (__cdecl *)(IConVar *, const char *, float))v29->m_pGroupIndexToMeshIndex[v29->m_pIndices[(_DWORD)v31 + 1]];
                          v38 = p_m_TriListIndices->m_nAllocationCount;
                          if ( (int)v37 + 1 > v38 )
                          {
                            CUtlMemory<int,int>::Grow(this: p_m_TriListIndices, num: (int)v37 - v38 + 1);
                            v29 = pMeshGroupa;
                          }
                          ++p_m_TriListIndices[1].m_pMemory;
                          v39 = p_m_TriListIndices->m_pMemory;
                          v40 = (char *)p_m_TriListIndices[1].m_pMemory - (char *)v37 - 1;
                          p_m_TriListIndices[1].m_nAllocationCount = (int)p_m_TriListIndices->m_pMemory;
                          if ( v40 > 0 )
                          {
                            _V_memmove(dest: &v39[(_DWORD)v37 + 1], src: &v39[(_DWORD)v37], count: 4 * v40);
                            v29 = pMeshGroupa;
                          }
                          v41 = &p_m_TriListIndices->m_pMemory[(_DWORD)v37];
                          if ( v41 != nullptr )
                            *v41 = v52;
                          v42 = (void (__cdecl *)(IConVar *, const char *, float))v29->m_pGroupIndexToMeshIndex[v29->m_pIndices[(_DWORD)v31 + 2]];
                          v43 = p_m_TriListIndices[1].m_pMemory;
                          v44 = p_m_TriListIndices->m_nAllocationCount;
                          if ( (int)v43 + 1 > v44 )
                          {
                            CUtlMemory<int,int>::Grow(this: p_m_TriListIndices, num: (int)v43 - v44 + 1);
                            v29 = pMeshGroupa;
                          }
                          ++p_m_TriListIndices[1].m_pMemory;
                          v45 = p_m_TriListIndices->m_pMemory;
                          v46 = (char *)p_m_TriListIndices[1].m_pMemory - (char *)v43 - 1;
                          p_m_TriListIndices[1].m_nAllocationCount = (int)p_m_TriListIndices->m_pMemory;
                          if ( v46 > 0 )
                          {
                            _V_memmove(dest: &v45[(_DWORD)v43 + 1], src: &v45[(_DWORD)v43], count: 4 * v46);
                            v29 = pMeshGroupa;
                          }
                          v47 = &p_m_TriListIndices->m_pMemory[(_DWORD)v43];
                          if ( v47 != nullptr )
                            *v47 = v42;
                          materialBatcha = (GetTriangles_MaterialBatch_t *)((char *)materialBatcha + 3);
                          if ( (int)materialBatcha >= pStripData->numIndices )
                            break;
                          p_numIndices = &pStripData->numIndices;
                        }
                        v27 = pMeshData;
                      }
                      ++v68;
                      ++stripID;
                    }
                    while ( stripID < v29->m_NumStrips );
                  }
                  pMesha = (mstudiomesh_t *)((char *)pMesha + 44);
                  ++stripGroupID;
                }
                while ( stripGroupID < v27->m_NumGroup );
              }
            }
            v4 = out;
            v5 = info;
          }
          v62 += 116;
          ++k;
        }
        while ( k < pModel->nummeshes );
        v14 = ia;
      }
      v13 = v5->m_pStudioHdr;
      ia = ++v14;
    }
    while ( v14 < v5->m_pStudioHdr->numbodyparts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058370
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}
