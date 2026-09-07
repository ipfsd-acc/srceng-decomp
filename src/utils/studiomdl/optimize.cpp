// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/optimize.cpp
// Functions: 219
// ============================================================

#include "utils\studiomdl\optimize.h"

//------------------------------------------------------------------------------
// Address: 0x004019B0
// Name: public: void CUtlLinkedList<void (*)(void),unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<void (*)(void),unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<void (__cdecl*)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl*)(void),unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<void (__cdecl*)(void),unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A4B0
// Name: public: mstudioiface_t::mstudioiface_t(void)
// Source: json
//------------------------------------------------------------------------------
mstudioiface_t *__thiscall mstudioiface_t::mstudioiface_t(mstudioiface_t *this)
{
  this->d = -1;
  this->c = -1;
  this->b = -1;
  this->a = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041A4F0
// Name: public: struct mstudio_modelvertexdata_t const __near * mstudiomodel_t::GetVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
const mstudio_modelvertexdata_t *__thiscall mstudiomodel_t::GetVertexData(mstudiomodel_t *this, void *pModelData)
{
  char *v4; // [esp+4h] [ebp-Ch]
  char *v5; // [esp+8h] [ebp-8h]
  const vertexFileHeader_t *pVertexHdr; // [esp+Ch] [ebp-4h]

  pVertexHdr = mstudiomodel_t::CacheVertexData(this, pModelData);
  if ( pVertexHdr == nullptr )
    return nullptr;
  if ( pVertexHdr->id == 1448297545 && pVertexHdr->vertexDataStart != 0 )
    v5 = (char *)pVertexHdr + pVertexHdr->vertexDataStart;
  else
    v5 = nullptr;
  this->vertexdata.pVertexData = v5;
  if ( pVertexHdr->id == 1448297545 && pVertexHdr->tangentDataStart != 0 )
    v4 = (char *)pVertexHdr + pVertexHdr->tangentDataStart;
  else
    v4 = nullptr;
  this->vertexdata.pTangentData = v4;
  if ( this->vertexdata.pVertexData != nullptr )
    return &this->vertexdata;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041A5A0
// Name: bool OptimizedModel::FaceIsRegular(struct OptimizedModel::SubD_Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl OptimizedModel::FaceIsRegular(OptimizedModel::SubD_Face_t *patch)
{
  return patch->valences[0] == 4
      && patch->valences[1] == 4
      && patch->valences[2] == 4
      && patch->valences[3] == 4
      && patch->bndVtx[0] == 0
      && patch->bndVtx[1] == 0
      && patch->bndVtx[2] == 0
      && patch->bndVtx[3] == 0
      && patch->bndEdge[0] == 0
      && patch->bndEdge[1] == 0
      && patch->bndEdge[2] == 0
      && patch->bndEdge[3] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A680
// Name: public: OptimizedModel::Face_t::Face_t(void)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__thiscall OptimizedModel::Face_t::Face_t(OptimizedModel::Face_t *this)
{
  int i; // [esp+4h] [ebp-4h]

  this->touched = false;
  for ( i = 0; i < 4; ++i )
  {
    this->neighborID[i] = -1;
    this->vertID[i] = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041A6D0
// Name: private: void OptimizedModel::COptimizedModel::CleanupEverything(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::CleanupEverything(OptimizedModel::COptimizedModel *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041A6E0
// Name: private: void OptimizedModel::COptimizedModel::OutputMemoryUsage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::OutputMemoryUsage(OptimizedModel::COptimizedModel *this)
{
  printf(format: "body parts:   %7d bytes\n", this->m_ModelsOffset - this->m_BodyPartsOffset);
  printf(format: "models:       %7d bytes\n", this->m_MeshesOffset - this->m_ModelsOffset);
  printf(format: "model LODs:   %7d bytes\n", this->m_MeshesOffset - this->m_ModelLODsOffset);
  printf(format: "meshes:       %7d bytes\n", this->m_StripGroupsOffset - this->m_MeshesOffset);
  printf(format: "strip groups: %7d bytes\n", this->m_StripsOffset - this->m_StripGroupsOffset);
  printf(format: "strips:       %7d bytes\n", this->m_VertsOffset - this->m_StripsOffset);
  printf(format: "verts:        %7d bytes\n", this->m_IndicesOffset - this->m_VertsOffset);
  printf(format: "indices:      %7d bytes\n", this->m_BoneStateChangesOffset - this->m_IndicesOffset);
  printf(format: "bone changes: %7d bytes\n", this->m_EndOfFileOffset - this->m_BoneStateChangesOffset);
  printf(format: "everything:   %7d bytes\n", this->m_EndOfFileOffset);
}

//------------------------------------------------------------------------------
// Address: 0x0041A7F0
// Name: private: void OptimizedModel::COptimizedModel::SanityCheckAgainstStudioHDR(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SanityCheckAgainstStudioHDR(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *phdr)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041A800
// Name: private: int OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(struct OptimizedModel::Face_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(
        OptimizedModel::COptimizedModel *this,
        const OptimizedModel::Face_t *face)
{
  int i; // [esp+4h] [ebp-8h]
  int numNewBones; // [esp+8h] [ebp-4h]

  numNewBones = 0;
  for ( i = 0; i < face->numBones; ++i )
  {
    if ( !CHardwareMatrixState::IsMatrixAllocated(this: &this->m_HardwareMatrixState, globalMatrixID: face->boneID[i]) )
      ++numNewBones;
  }
  return numNewBones;
}

//------------------------------------------------------------------------------
// Address: 0x0041A860
// Name: private: bool OptimizedModel::COptimizedModel::AllocateHardwareBonesForFace(struct OptimizedModel::Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::AllocateHardwareBonesForFace(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::Face_t *face)
{
  int bone; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < face->numBones; ++i )
  {
    bone = face->boneID[i];
    if ( !CHardwareMatrixState::IsMatrixAllocated(this: &this->m_HardwareMatrixState, globalMatrixID: bone)
      && !CHardwareMatrixState::AllocateMatrix(this: &this->m_HardwareMatrixState, globalMatrixID: bone) )
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A8D0
// Name: private: void OptimizedModel::COptimizedModel::SanityCheckVertBones(class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SanityCheckVertBones(
        OptimizedModel::COptimizedModel *this,
        const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *list,
        const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vertices)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041A8E0
// Name: private: bool OptimizedModel::COptimizedModel::IsVertexFlexed(struct mstudiomesh_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::IsVertexFlexed(
        OptimizedModel::COptimizedModel *this,
        mstudiomesh_t *pStudioMesh,
        int vertID)
{
  unsigned __int8 *pvanim; // [esp+10h] [ebp-14h]
  int j; // [esp+14h] [ebp-10h]
  mstudioflex_t *pflex; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]

  pflex = (mstudioflex_t *)((char *)pStudioMesh + pStudioMesh->flexindex);
  for ( i = 0; i < pStudioMesh->numflexes; ++i )
  {
    pvanim = (unsigned __int8 *)&pflex[i] + pflex[i].vertindex;
    for ( j = 0; j < pflex[i].numverts; ++j )
    {
      if ( *(unsigned __int16 *)pvanim == vertID )
        return 1;
      pvanim += pflex[i].vertanimtype != 0 ? 18 : 16;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A9B0
// Name: private: void OptimizedModel::COptimizedModel::ComputeStripGroupFlags(struct OptimizedModel::StripGroup_t __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ComputeStripGroupFlags(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::StripGroup_t *pStripGroup,
        bool bIsHWSkinned,
        bool bIsFlexed)
{
  pStripGroup->flags = 0;
  if ( bIsFlexed )
    pStripGroup->flags |= 4u;
  if ( bIsHWSkinned )
    pStripGroup->flags |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x0041AA00
// Name: OptimizedModel::TryToReduceBoneInfluence
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::TryToReduceBoneInfluence(
        OptimizedModel::Vertex_t *stripGroupVert,
        const mstudioboneweight_t *boneWeights,
        int maxBones)
{
  float minWeight; // [esp+4h] [ebp-Ch]
  int minIndex; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  while ( stripGroupVert->numBones > maxBones )
  {
    minWeight = 2.0;
    minIndex = -1;
    for ( i = 0; i < 3; ++i )
    {
      if ( stripGroupVert->boneID[i] != 255 && minWeight > boneWeights->weight[stripGroupVert->boneWeightIndex[i]] )
      {
        minWeight = boneWeights->weight[stripGroupVert->boneWeightIndex[i]];
        minIndex = i;
      }
    }
    if ( minWeight >= 1.0 )
      break;
    for ( ia = minIndex; ia < 2; ++ia )
    {
      stripGroupVert->boneID[ia] = stripGroupVert->boneID[ia + 1];
      stripGroupVert->boneWeightIndex[ia] = stripGroupVert->boneWeightIndex[ia + 1];
    }
    stripGroupVert->boneID[2] = -1;
    stripGroupVert->boneWeightIndex[2] = 0;
    --stripGroupVert->numBones;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AB00
// Name: private: int OptimizedModel::COptimizedModel::CountUniqueBones(int,struct OptimizedModel::Vertex_t __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::CountUniqueBones(
        OptimizedModel::COptimizedModel *this,
        int count,
        OptimizedModel::Vertex_t *pVertex)
{
  int j; // [esp+4h] [ebp-810h]
  int boneID; // [esp+8h] [ebp-80Ch]
  int i; // [esp+Ch] [ebp-808h]
  int uniqueBoneCount; // [esp+10h] [ebp-804h]
  int uniqueBoneList[512]; // [esp+14h] [ebp-800h]

  uniqueBoneCount = 0;
  while ( --count >= 0 )
  {
    for ( i = 0; i < pVertex[count].numBones; ++i )
    {
      boneID = pVertex[count].boneID[i];
      j = uniqueBoneCount;
      do
        --j;
      while ( j >= 0 && uniqueBoneList[j] != boneID );
      if ( j < 0 )
        uniqueBoneList[uniqueBoneCount++] = boneID;
    }
  }
  return uniqueBoneCount;
}

//------------------------------------------------------------------------------
// Address: 0x0041ABF0
// Name: private: int OptimizedModel::COptimizedModel::CountMaxVertBones(int,struct OptimizedModel::Vertex_t __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::CountMaxVertBones(
        OptimizedModel::COptimizedModel *this,
        int count,
        OptimizedModel::Vertex_t *pVertex)
{
  int maxBones; // [esp+4h] [ebp-4h]

  maxBones = 0;
  while ( --count >= 0 )
  {
    if ( maxBones < pVertex[count].numBones )
      maxBones = pVertex[count].numBones;
  }
  return maxBones;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC40
// Name: OptimizedModel::StripVertLookup_CompareFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl OptimizedModel::StripVertLookup_CompareFunc(
        const OptimizedModel::StripVertLookup_t *a,
        const OptimizedModel::StripVertLookup_t *b)
{
  return a->origMeshVertID == b->origMeshVertID;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC60
// Name: OptimizedModel::StripVertLookup_KeyFunc
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl OptimizedModel::StripVertLookup_KeyFunc(const OptimizedModel::StripVertLookup_t *a)
{
  return HashInt(n: a->origMeshVertID);
}

//------------------------------------------------------------------------------
// Address: 0x0041AC70
// Name: private: bool OptimizedModel::COptimizedModel::MeshIsTeeth(struct studiohdr_t __near *,struct mstudiomesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::MeshIsTeeth(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pStudioHeader,
        mstudiomesh_t *pStudioMesh)
{
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < pStudioHeader->numskinfamilies; ++i )
  {
    if ( *(int *)((char *)&pStudioHeader->version
                + 64
                * *(__int16 *)((char *)&pStudioHeader->id
                             + 2 * pStudioHeader->numskinref * i
                             + 2 * pStudioMesh->material
                             + pStudioHeader->skinindex)
                + pStudioHeader->textureindex) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AD00
// Name: private: void OptimizedModel::COptimizedModel::ComputeMeshFlags(struct OptimizedModel::Mesh_t __near *,struct studiohdr_t __near *,struct mstudiomesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ComputeMeshFlags(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::Mesh_t *pMesh,
        studiohdr_t *pStudioHeader,
        mstudiomesh_t *pStudioMesh)
{
  pMesh->flags = 0;
  if ( pStudioMesh->materialtype != 0 )
    pMesh->flags |= 2u;
  if ( OptimizedModel::COptimizedModel::MeshIsTeeth(this, pStudioHeader, pStudioMesh) != 0 )
    pMesh->flags |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x0041AD60
// Name: private: void OptimizedModel::COptimizedModel::SetupMeshProcessing(struct studiohdr_t __near *,int,bool,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SetupMeshProcessing(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        int vertexCacheSize,
        bool usesFixedFunction,
        int maxBonesPerVert,
        int maxBonesPerFace,
        int maxBonesPerStrip,
        const char *fileName)
{
  SetCacheSize(_cacheSize: vertexCacheSize);
  SetStitchStrips(_bStitchStrips: true);
  SetMinStripSize(_minStripSize: 0);
  SetListsOnly(_bListsOnly: true);
  if ( !g_quiet )
  {
    printf(format: "---------------------\n");
    printf(format: "Generating optimized mesh \"%s\":\n", fileName);
  }
  OptimizedModel::COptimizedModel::CleanupEverything(this);
  this->m_NumBones = pHdr->numbones;
  this->m_MaxBonesPerVert = maxBonesPerVert;
  this->m_MaxBonesPerFace = maxBonesPerFace;
  this->m_MaxBonesPerStrip = maxBonesPerStrip;
  this->m_bUsesFixedFunction = usesFixedFunction;
  this->m_VertexCacheSize = vertexCacheSize;
  this->m_NumSkinnedAndFlexedVerts = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AE10
// Name: OptimizedModel::RandomColor
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::RandomColor(Vector *color)
{
  color->x = (float)rand() / 32767.0;
  color->y = (float)rand() / 32767.0;
  color->z = (float)rand() / 32767.0;
  VectorNormalize(vec: color);
}

//------------------------------------------------------------------------------
// Address: 0x0041AE90
// Name: bool OptimizedModel::ComparePath(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl OptimizedModel::ComparePath(const char *a, const char *b)
{
  int v3; // esi

  if ( strlen(a) != strlen(b) )
    return 0;
  while ( *a != 0 )
  {
    if ( *a != *b )
    {
      v3 = tolower(c: *a);
      if ( v3 != tolower(c: *b) && (*a != 47 && *a != 92 || *b != 47 && *b != 92) )
        return 0;
    }
    ++a;
    ++b;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041AFA0
// Name: private: void OptimizedModel::COptimizedModel::ZeroNumBones(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ZeroNumBones(OptimizedModel::COptimizedModel *this)
{
  int v1; // eax
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+20h] [ebp-34h]
  OptimizedModel::MeshHeader_t *pMesh; // [esp+24h] [ebp-30h]
  OptimizedModel::ModelLODHeader_t *pLOD; // [esp+28h] [ebp-2Ch]
  OptimizedModel::ModelHeader_t *pModel; // [esp+2Ch] [ebp-28h]
  OptimizedModel::BodyPartHeader_t *pBodyPart; // [esp+30h] [ebp-24h]
  unsigned __int8 *header; // [esp+34h] [ebp-20h]
  int modelID; // [esp+38h] [ebp-1Ch]
  int meshID; // [esp+3Ch] [ebp-18h]
  int stripID; // [esp+40h] [ebp-14h]
  int stripGroupID; // [esp+44h] [ebp-10h]
  int vertID; // [esp+48h] [ebp-Ch]
  int bodyPartID; // [esp+4Ch] [ebp-8h]
  int lodID; // [esp+50h] [ebp-4h]

  header = this->m_FileBuffer->m_pData;
  for ( bodyPartID = 0; bodyPartID < *((_DWORD *)header + 7); ++bodyPartID )
  {
    pBodyPart = (OptimizedModel::BodyPartHeader_t *)&header[8 * bodyPartID + *((_DWORD *)header + 8)];
    for ( modelID = 0; modelID < pBodyPart->numModels; ++modelID )
    {
      pModel = (OptimizedModel::ModelHeader_t *)((char *)&pBodyPart[modelID] + pBodyPart->modelOffset);
      for ( lodID = 0; lodID < pModel->numLODs; ++lodID )
      {
        pLOD = (OptimizedModel::ModelLODHeader_t *)((char *)pModel + 12 * lodID + pModel->lodOffset);
        for ( meshID = 0; meshID < pLOD->numMeshes; ++meshID )
        {
          pMesh = (OptimizedModel::MeshHeader_t *)((char *)pLOD + 9 * meshID + pLOD->meshOffset);
          for ( stripGroupID = 0; stripGroupID < pMesh->numStripGroups; ++stripGroupID )
          {
            pStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)pMesh
                                                               + 33 * stripGroupID
                                                               + pMesh->stripGroupHeaderOffset);
            for ( vertID = 0; vertID < pStripGroup->numVerts; ++vertID )
              *((_BYTE *)&pStripGroup->numVerts + 9 * vertID + pStripGroup->vertOffset + 3) = 0;
            for ( stripID = 0; stripID < pStripGroup->numStrips; ++stripID )
            {
              v1 = (int)pStripGroup + 35 * stripID + pStripGroup->stripOffset;
              *(_WORD *)(v1 + 16) = 0;
              *(_DWORD *)(v1 + 19) = 0;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B170
// Name: OptimizedModel::MergeLikeBoneIndicesWithinVert
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::MergeLikeBoneIndicesWithinVert(mstudioboneweight_t *pBoneWeight)
{
  int k; // [esp+4h] [ebp-18h]
  int j; // [esp+8h] [ebp-14h]
  int ja; // [esp+8h] [ebp-14h]
  unsigned __int8 tmpIndex; // [esp+Ch] [ebp-10h]
  float tmpWeight; // [esp+10h] [ebp-Ch]
  unsigned __int8 realNumBones; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  if ( pBoneWeight->numbones != 1 )
  {
    realNumBones = pBoneWeight->numbones;
    for ( i = 0; i < pBoneWeight->numbones; ++i )
    {
      for ( j = i + 1; j < pBoneWeight->numbones; ++j )
      {
        if ( pBoneWeight->bone[i] == pBoneWeight->bone[j] && pBoneWeight->weight[i] != 0.0 )
        {
          pBoneWeight->weight[i] = pBoneWeight->weight[i] + pBoneWeight->weight[j];
          pBoneWeight->weight[j] = 0.0;
          --realNumBones;
        }
      }
    }
    for ( ja = pBoneWeight->numbones; ja > 1; --ja )
    {
      for ( k = 0; k < ja - 1; ++k )
      {
        if ( pBoneWeight->weight[k] == 0.0 && pBoneWeight->weight[k + 1] != 0.0 )
        {
          tmpIndex = pBoneWeight->bone[k];
          tmpWeight = pBoneWeight->weight[k];
          pBoneWeight->bone[k] = pBoneWeight->bone[k + 1];
          pBoneWeight->weight[k] = pBoneWeight->weight[k + 1];
          pBoneWeight->bone[k + 1] = tmpIndex;
          pBoneWeight->weight[k + 1] = tmpWeight;
        }
      }
    }
    pBoneWeight->numbones = realNumBones;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B340
// Name: OptimizedModel::MergeLikeBoneIndicesWithinVerts
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::MergeLikeBoneIndicesWithinVerts(studiohdr_t *pHdr)
{
  const mstudio_modelvertexdata_t *vertData; // [esp+10h] [ebp-1Ch]
  mstudiomodel_t *pModel; // [esp+18h] [ebp-14h]
  mstudiobodyparts_t *pBodyPart; // [esp+1Ch] [ebp-10h]
  int modelID; // [esp+20h] [ebp-Ch]
  int vertID; // [esp+24h] [ebp-8h]
  int bodyPartID; // [esp+28h] [ebp-4h]

  for ( bodyPartID = 0; bodyPartID < pHdr->numbodyparts; ++bodyPartID )
  {
    pBodyPart = (mstudiobodyparts_t *)((char *)pHdr + 16 * bodyPartID + pHdr->bodypartindex);
    for ( modelID = 0; modelID < pBodyPart->nummodels; ++modelID )
    {
      pModel = (mstudiomodel_t *)((char *)pBodyPart + 148 * modelID + pBodyPart->modelindex);
      for ( vertID = 0; vertID < pModel->numvertices; ++vertID )
      {
        vertData = mstudiomodel_t::GetVertexData(this: pModel, pModelData: nullptr);
        OptimizedModel::MergeLikeBoneIndicesWithinVert(
          pBoneWeight: (mstudioboneweight_t *)vertData->pVertexData
        + 3 * vertID
        + 3 * ((unsigned int)vertData[-3].pVertexData / 0x30));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B430
// Name: private: void OptimizedModel::COptimizedModel::SetMeshPropsColor(unsigned int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SetMeshPropsColor(
        OptimizedModel::COptimizedModel *this,
        char meshFlags,
        Vector *color)
{
  if ( (meshFlags & 1) != 0 )
  {
    color->x = 1.0;
    color->y = 0.0;
    color->z = 0.0;
  }
  else
  {
    if ( (meshFlags & 2) != 0 )
      color->x = 1.0;
    else
      color->x = 0.0;
    color->y = 1.0;
    color->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B530
// Name: private: void OptimizedModel::COptimizedModel::SetFlexedAndSkinColor(unsigned int,unsigned int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SetFlexedAndSkinColor(
        OptimizedModel::COptimizedModel *this,
        char glViewFlags,
        char stripGroupFlags,
        Vector *color)
{
  if ( (glViewFlags & 0x10) != 0 && (glViewFlags & 0x20) != 0 )
  {
    if ( (stripGroupFlags & 4) != 0 && (stripGroupFlags & 2) != 0 )
    {
      color->x = 1.0;
      color->y = 1.0;
      color->z = 0.0;
    }
    else if ( (stripGroupFlags & 4) != 0 || (stripGroupFlags & 2) == 0 )
    {
      if ( (stripGroupFlags & 4) != 0 || (stripGroupFlags & 2) != 0 )
      {
        if ( (stripGroupFlags & 4) != 0 && (stripGroupFlags & 2) == 0 )
        {
          color->x = 1.0;
          color->y = 0.0;
          color->z = 0.0;
        }
      }
      else
      {
        color->x = 0.0;
        color->y = 0.0;
        color->z = 1.0;
      }
    }
    else
    {
      color->x = 0.0;
      color->y = 1.0;
      color->z = 0.0;
    }
  }
  else if ( (glViewFlags & 0x10) != 0 )
  {
    if ( (stripGroupFlags & 4) != 0 )
    {
      color->x = 1.0;
      color->y = 0.0;
    }
    else
    {
      color->x = 0.0;
      color->y = 1.0;
    }
    color->z = 0.0;
  }
  else if ( (glViewFlags & 0x20) != 0 )
  {
    if ( (stripGroupFlags & 2) != 0 )
    {
      color->x = 0.0;
      color->y = 1.0;
    }
    else
    {
      color->x = 1.0;
      color->y = 0.0;
    }
    color->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B800
// Name: private: void OptimizedModel::COptimizedModel::DrawGLViewTriangle(struct _iobuf __near *,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::DrawGLViewTriangle(
        OptimizedModel::COptimizedModel *this,
        _iobuf *fp,
        Vector *pos1,
        Vector *pos2,
        Vector *pos3,
        Vector *color1,
        Vector *color2,
        Vector *color3)
{
  ++numGLViewTrangles;
  fprintf(str: fp, format: "3\n");
  fprintf(str: fp, format: "%f %f %f %f %f %f\n", pos1->x, pos1->y, pos1->z, color1->x, color1->y, color1->z);
  fprintf(str: fp, format: "%f %f %f %f %f %f\n", pos2->x, pos2->y, pos2->z, color2->x, color2->y, color2->z);
  fprintf(str: fp, format: "%f %f %f %f %f %f\n", pos3->x, pos3->y, pos3->z, color3->x, color3->y, color3->z);
}

//------------------------------------------------------------------------------
// Address: 0x0041BA40
// Name: private: void OptimizedModel::COptimizedModel::GLViewDrawEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::GLViewDrawEnd(OptimizedModel::COptimizedModel *this)
{
  s_DrawMode = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041BA60
// Name: private: void OptimizedModel::COptimizedModel::GLViewDrawBegin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::GLViewDrawBegin(OptimizedModel::COptimizedModel *this, int mode)
{
  s_DrawMode = mode;
  s_ListID = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041BA80
// Name: private: void OptimizedModel::COptimizedModel::ShrinkVerts(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ShrinkVerts(OptimizedModel::COptimizedModel *this, float shrinkFactor)
{
  Vector *v2; // eax
  float delta_4; // [esp+18h] [ebp-18h]
  float delta_8; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float center; // [esp+24h] [ebp-Ch]
  float center_4; // [esp+28h] [ebp-8h]
  float center_8; // [esp+2Ch] [ebp-4h]

  center = (float)((float)(s_LastThreePositions[0].x + s_LastThreePositions[1].x) + s_LastThreePositions[2].x)
         * 0.33333334;
  center_4 = (float)((float)(s_LastThreePositions[0].y + s_LastThreePositions[1].y) + s_LastThreePositions[2].y)
           * 0.33333334;
  center_8 = (float)((float)(s_LastThreePositions[0].z + s_LastThreePositions[1].z) + s_LastThreePositions[2].z)
           * 0.33333334;
  for ( i = 0; i < 3; ++i )
  {
    if ( !s_Shrunk[i] )
    {
      delta_4 = (float)(s_LastThreePositions[i].y - center_4) * shrinkFactor;
      delta_8 = (float)(s_LastThreePositions[i].z - center_8) * shrinkFactor;
      s_LastThreePositions[i].x = center + (float)((float)(s_LastThreePositions[i].x - center) * shrinkFactor);
      v2 = &s_LastThreePositions[i];
      v2->y = center_4 + delta_4;
      v2->z = center_8 + delta_8;
      s_Shrunk[i] = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BC60
// Name: private: void OptimizedModel::COptimizedModel::RemoveRedundantBoneStateChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::RemoveRedundantBoneStateChanges(OptimizedModel::COptimizedModel *this)
{
  OptimizedModel::BoneStateChangeHeader_t *boneStateChange; // [esp+18h] [ebp-C44h]
  int boneStateChangeID; // [esp+1Ch] [ebp-C40h]
  OptimizedModel::StripHeader_t *pStrip; // [esp+20h] [ebp-C3Ch]
  int stripID; // [esp+24h] [ebp-C38h]
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+28h] [ebp-C34h]
  int stripGroupID; // [esp+2Ch] [ebp-C30h]
  OptimizedModel::MeshHeader_t *mesh; // [esp+30h] [ebp-C2Ch]
  int meshID; // [esp+34h] [ebp-C28h]
  OptimizedModel::ModelLODHeader_t *pLOD; // [esp+38h] [ebp-C24h]
  int lodID; // [esp+3Ch] [ebp-C20h]
  OptimizedModel::ModelHeader_t *model; // [esp+40h] [ebp-C1Ch]
  int modelID; // [esp+44h] [ebp-C18h]
  OptimizedModel::BodyPartHeader_t *bodyPart; // [esp+48h] [ebp-C14h]
  int hardwareBoneState[512]; // [esp+4Ch] [ebp-C10h]
  bool allocated[516]; // [esp+84Ch] [ebp-410h]
  int i; // [esp+A50h] [ebp-20Ch]
  bool changed[512]; // [esp+A54h] [ebp-208h]
  int bodyPartID; // [esp+C54h] [ebp-8h]
  OptimizedModel::FileHeader_t *header; // [esp+C58h] [ebp-4h]

  header = (OptimizedModel::FileHeader_t *)this->m_FileBuffer->m_pData;
  for ( bodyPartID = 0; bodyPartID < header->numBodyParts; ++bodyPartID )
  {
    bodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)header + 8 * bodyPartID + header->bodyPartOffset);
    for ( i = 0; i < 512; ++i )
    {
      hardwareBoneState[i] = -1;
      allocated[i] = false;
    }
    for ( modelID = 0; modelID < bodyPart->numModels; ++modelID )
    {
      model = (OptimizedModel::ModelHeader_t *)((char *)&bodyPart[modelID] + bodyPart->modelOffset);
      for ( lodID = 0; lodID < model->numLODs; ++lodID )
      {
        pLOD = (OptimizedModel::ModelLODHeader_t *)((char *)model + 12 * lodID + model->lodOffset);
        for ( meshID = 0; meshID < pLOD->numMeshes; ++meshID )
        {
          mesh = (OptimizedModel::MeshHeader_t *)((char *)pLOD + 9 * meshID + pLOD->meshOffset);
          for ( stripGroupID = 0; stripGroupID < mesh->numStripGroups; ++stripGroupID )
          {
            pStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)mesh
                                                               + 33 * stripGroupID
                                                               + mesh->stripGroupHeaderOffset);
            if ( (pStripGroup->flags & 2) != 0 )
            {
              for ( stripID = 0; stripID < pStripGroup->numStrips; ++stripID )
              {
                pStrip = (OptimizedModel::StripHeader_t *)((char *)pStripGroup + 35 * stripID + pStripGroup->stripOffset);
                for ( i = 0; i < 512; ++i )
                  changed[i] = false;
                for ( boneStateChangeID = 0; boneStateChangeID < pStrip->numBoneStateChanges; ++boneStateChangeID )
                {
                  boneStateChange = (OptimizedModel::BoneStateChangeHeader_t *)((char *)pStrip
                                                                              + 8 * boneStateChangeID
                                                                              + pStrip->boneStateChangeOffset);
                  if ( !allocated[boneStateChange->hardwareID]
                    || hardwareBoneState[boneStateChange->hardwareID] != boneStateChange->newBoneID )
                  {
                    changed[boneStateChange->hardwareID] = true;
                    allocated[boneStateChange->hardwareID] = true;
                    hardwareBoneState[boneStateChange->hardwareID] = boneStateChange->newBoneID;
                  }
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
// Address: 0x0041BFF0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)MemAlloc_Alloc(nSize: 20 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C080
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  unsigned __int16 *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 2);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 2 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (unsigned __int16 *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C100
// Name: public: void CUtlMemory<struct OptimizedModel::SubD_Face_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
        CUtlMemory<OptimizedModel::SubD_Face_t,int> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::SubD_Face_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 300);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 300 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::SubD_Face_t *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v8);
    else
      this->m_pMemory = (OptimizedModel::SubD_Face_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C190
// Name: public: void CUtlMemory<struct OptimizedModel::Model_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Model_t,int>::Grow(CUtlMemory<OptimizedModel::Model_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::Model_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 20);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 20 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Model_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::Model_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C2F0
// Name: private: bool OptimizedModel::COptimizedModel::GenerateStripGroupVerticesFromFace(struct mstudioiface_t __near *,struct mstudiomesh_t __near *,int,struct OptimizedModel::Vertex_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall OptimizedModel::COptimizedModel::GenerateStripGroupVerticesFromFace(
        OptimizedModel::COptimizedModel *this,
        mstudioiface_t *pFace,
        mstudiomesh_t *pStudioMesh,
        int maxPreferredBones,
        OptimizedModel::Vertex_t *pStripGroupVert,
        bool bQuadSubd)
{
  bool v7; // [esp+0h] [ebp-54h]
  int boneID; // [esp+24h] [ebp-30h]
  mstudioboneweight_t *pBoneWeight; // [esp+28h] [ebp-2Ch]
  int bonesAffectingVertex; // [esp+2Ch] [ebp-28h]
  int vertex; // [esp+30h] [ebp-24h]
  int faceIndex; // [esp+34h] [ebp-20h]
  int vertIDs[4]; // [esp+38h] [ebp-1Ch]
  bool bFaceIsFlexed; // [esp+4Bh] [ebp-9h]
  const mstudio_meshvertexdata_t *vertData; // [esp+4Ch] [ebp-8h]
  int numVerts; // [esp+50h] [ebp-4h]

  vertIDs[0] = pFace->a;
  vertIDs[1] = pFace->b;
  vertIDs[2] = pFace->c;
  vertIDs[3] = pFace->d;
  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  bFaceIsFlexed = false;
  numVerts = bQuadSubd + 3;
  for ( faceIndex = 0; faceIndex < numVerts; ++faceIndex )
  {
    vertex = vertIDs[faceIndex];
    v7 = bFaceIsFlexed || OptimizedModel::COptimizedModel::IsVertexFlexed(this, pStudioMesh, vertID: vertex) != 0;
    bFaceIsFlexed = v7;
    pBoneWeight = (mstudioboneweight_t *)((char *)vertData->modelvertexdata->pVertexData
                                        + 48
                                        * ((int)vertData[-1].modelvertexdata
                                         + vertex
                                         + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30));
    bonesAffectingVertex = pBoneWeight->numbones;
    if ( g_staticprop || pBoneWeight->numbones != 0 )
    {
      if ( pBoneWeight->numbones > 3u )
        MdlError(fmt: "too many bones/vert (%d) : MAX_NUM_BONES_PER_VERT needs to be upped\n", bonesAffectingVertex);
    }
    else
    {
      MdlWarning(fmt: "too few bones/vert (%d) : it has no bones!\n", bonesAffectingVertex);
    }
    pStripGroupVert[faceIndex].origMeshVertID = vertex;
    pStripGroupVert[faceIndex].numBones = bonesAffectingVertex;
    for ( boneID = 0; boneID < bonesAffectingVertex; ++boneID )
    {
      pStripGroupVert[faceIndex].boneID[boneID] = pBoneWeight->bone[boneID];
      pStripGroupVert[faceIndex].boneWeightIndex[boneID] = boneID;
    }
    while ( boneID < 3 )
    {
      pStripGroupVert[faceIndex].boneID[boneID] = -1;
      pStripGroupVert[faceIndex].boneWeightIndex[boneID] = boneID;
      ++boneID;
    }
    if ( !this->m_bUsesFixedFunction && maxPreferredBones > 0 && bonesAffectingVertex > maxPreferredBones )
      OptimizedModel::TryToReduceBoneInfluence(
        stripGroupVert: &pStripGroupVert[faceIndex],
        boneWeights: pBoneWeight,
        maxBones: maxPreferredBones);
  }
  return bFaceIsFlexed;
}

//------------------------------------------------------------------------------
// Address: 0x0041C540
// Name: private: int OptimizedModel::COptimizedModel::GetTotalStripGroupsForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall OptimizedModel::COptimizedModel::GetTotalStripGroupsForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  return CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
}

//------------------------------------------------------------------------------
// Address: 0x0041C560
// Name: private: void OptimizedModel::COptimizedModel::WriteHeader(int,int,int,int,int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteHeader(
        OptimizedModel::COptimizedModel *this,
        int vertCacheSize,
        unsigned int maxBonesPerVert,
        int maxBonesPerFace,
        int maxBonesPerStrip,
        int numBodyParts,
        unsigned int checkSum)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-28h]
  OptimizedModel::FileHeader_t fileHeader; // 0:^14.36

  fileHeader.version = 7;
  fileHeader.vertCacheSize = vertCacheSize;
  fileHeader.maxBonesPerFace = IsUShort(val: maxBonesPerFace);
  *(_QWORD *)&fileHeader.maxBonesPerVert = __PAIR64__(checkSum, maxBonesPerVert);
  fileHeader.maxBonesPerStrip = IsUShort(val: maxBonesPerStrip);
  *(_QWORD *)&fileHeader.numBodyParts = (unsigned int)numBodyParts | 0x2400000000LL;
  fileHeader.numLODs = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  fileHeader.materialReplacementListOffset = this->m_MaterialReplacementsListOffset;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = m_FileBuffer->m_pData;
  *(OptimizedModel::FileHeader_t *)m_FileBuffer->m_pCurPos = fileHeader;
  m_FileBuffer->m_pCurPos += 36;
}

//------------------------------------------------------------------------------
// Address: 0x0041C610
// Name: private: void OptimizedModel::COptimizedModel::WriteBodyPart(int,struct mstudiobodyparts_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteBodyPart(
        OptimizedModel::COptimizedModel *this,
        int bodyPartID,
        mstudiobodyparts_t *pBodyPart,
        int modelID)
{
  _DWORD *m_pCurPos; // edx
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-14h]
  int bodyPartOffset; // [esp+Ch] [ebp-Ch]
  int bodyPart; // [esp+10h] [ebp-8h]
  int bodyPart_4; // [esp+14h] [ebp-4h]

  bodyPart = pBodyPart->nummodels;
  bodyPartOffset = this->m_BodyPartsOffset + 8 * bodyPartID;
  bodyPart_4 = this->m_ModelsOffset + 8 * modelID - bodyPartOffset;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[bodyPartOffset];
  m_pCurPos = m_FileBuffer->m_pCurPos;
  *m_pCurPos = bodyPart;
  m_pCurPos[1] = bodyPart_4;
  m_FileBuffer->m_pCurPos += 8;
}

//------------------------------------------------------------------------------
// Address: 0x0041C690
// Name: private: void OptimizedModel::COptimizedModel::WriteModel(int,struct mstudiomodel_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteModel(
        OptimizedModel::COptimizedModel *this,
        int modelID,
        mstudiomodel_t *pModel,
        int lodID)
{
  const char *v4; // eax
  char v5; // al
  unsigned __int8 *m_pCurPos; // edx
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-14h]
  int modelFileOffset; // [esp+8h] [ebp-10h]
  int model_4; // [esp+10h] [ebp-8h]

  v4 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  v5 = IsChar(val: (int)v4);
  modelFileOffset = this->m_ModelsOffset + 8 * modelID;
  model_4 = this->m_ModelLODsOffset + 12 * lodID - modelFileOffset;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[modelFileOffset];
  m_pCurPos = m_FileBuffer->m_pCurPos;
  *(_DWORD *)m_pCurPos = v5;
  *((_DWORD *)m_pCurPos + 1) = model_4;
  m_FileBuffer->m_pCurPos += 8;
}

//------------------------------------------------------------------------------
// Address: 0x0041C720
// Name: private: void OptimizedModel::COptimizedModel::WriteModelLOD(int,struct OptimizedModel::ModelLOD_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteModelLOD(
        OptimizedModel::COptimizedModel *this,
        int lodID,
        ConCommandBase *pLOD,
        int meshID)
{
  float *m_pCurPos; // eax
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-18h]
  const char *lod; // [esp+8h] [ebp-14h]
  int lod_4; // [esp+Ch] [ebp-10h]
  float lod_8; // [esp+10h] [ebp-Ch]
  int lodFileOffset; // [esp+14h] [ebp-8h]

  lodFileOffset = this->m_ModelLODsOffset + 12 * lodID;
  lod_4 = this->m_MeshesOffset + 9 * meshID - lodFileOffset;
  lod = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pLOD);
  lod_8 = *(float *)&pLOD->m_nFlags;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[lodFileOffset];
  m_pCurPos = (float *)m_FileBuffer->m_pCurPos;
  *(_DWORD *)m_pCurPos = lod;
  *((_DWORD *)m_pCurPos + 1) = lod_4;
  m_pCurPos[2] = lod_8;
  m_FileBuffer->m_pCurPos += 12;
}

//------------------------------------------------------------------------------
// Address: 0x0041C7B0
// Name: private: void OptimizedModel::COptimizedModel::WriteMesh(int,struct OptimizedModel::Mesh_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteMesh(
        OptimizedModel::COptimizedModel *this,
        int meshID,
        ConCommandBase *pMesh,
        int stripGroupID)
{
  const char *v4; // eax
  char v5; // al
  unsigned __int8 *m_pCurPos; // edx
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-18h]
  int mesh_4; // [esp+Ch] [ebp-10h]
  unsigned __int8 mesh_8; // [esp+10h] [ebp-Ch]
  int meshFileOffset; // [esp+14h] [ebp-8h]

  v4 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
  v5 = IsChar(val: (int)v4);
  meshFileOffset = this->m_MeshesOffset + 9 * meshID;
  mesh_4 = this->m_StripGroupsOffset + 33 * stripGroupID - meshFileOffset;
  mesh_8 = pMesh->m_nFlags;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[meshFileOffset];
  m_pCurPos = m_FileBuffer->m_pCurPos;
  *(_DWORD *)m_pCurPos = v5;
  *((_DWORD *)m_pCurPos + 1) = mesh_4;
  m_pCurPos[8] = mesh_8;
  m_FileBuffer->m_pCurPos += 9;
}

//------------------------------------------------------------------------------
// Address: 0x0041C850
// Name: private: void OptimizedModel::COptimizedModel::WriteStripGroup(int,struct OptimizedModel::StripGroup_t __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteStripGroup(
        OptimizedModel::COptimizedModel *this,
        int stripGroupID,
        ConCommandBase *pStripGroup,
        int vertID,
        int indexID,
        int topologyID,
        int stripID)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-3Ch]
  int stripGroupFileOffset; // [esp+3Ch] [ebp-4h]
  OptimizedModel::StripGroupHeader_t stripGroup; // 0:^1C.33

  stripGroup.numVerts = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 40));
  stripGroup.numIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
  stripGroup.numTopologyIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->m_nFlags);
  stripGroup.numStrips = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 60));
  stripGroup.flags = IsByte(val: *(_DWORD *)&pStripGroup[3].m_bRegistered);
  stripGroupFileOffset = this->m_StripGroupsOffset + 33 * stripGroupID;
  stripGroup.vertOffset = this->m_VertsOffset + 9 * vertID - stripGroupFileOffset;
  stripGroup.indexOffset = this->m_IndicesOffset + 2 * indexID - stripGroupFileOffset;
  stripGroup.topologyOffset = this->m_TopologyOffset + 2 * topologyID - stripGroupFileOffset;
  stripGroup.stripOffset = this->m_StripsOffset + 35 * stripID - stripGroupFileOffset;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[stripGroupFileOffset];
  *(OptimizedModel::StripGroupHeader_t *)m_FileBuffer->m_pCurPos = stripGroup;
  m_FileBuffer->m_pCurPos += 33;
}

//------------------------------------------------------------------------------
// Address: 0x0041C960
// Name: private: void OptimizedModel::COptimizedModel::WriteStrip(int,struct OptimizedModel::Strip_t __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteStrip(
        OptimizedModel::COptimizedModel *this,
        int stripID,
        OptimizedModel::Strip_t *pStrip,
        int indexID,
        int curTopology,
        int vertID,
        int boneID)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-30h]
  int stripFileOffset; // [esp+2Ch] [ebp-8h]
  OptimizedModel::StripHeader_t stripHeader; // 0:^14.35

  stripHeader.numIndices = pStrip->numStripGroupIndices;
  stripHeader.numTopologyIndices = pStrip->numStripGroupTopologyIndices;
  stripHeader.indexOffset = pStrip->stripGroupIndexOffset;
  stripHeader.topologyOffset = pStrip->stripGroupTopologyOffset;
  stripHeader.numVerts = pStrip->numStripGroupVerts;
  stripHeader.vertOffset = pStrip->stripGroupVertexOffset;
  stripHeader.numBoneStateChanges = pStrip->numBoneStateChanges;
  stripHeader.numBones = IsShort(val: pStrip->numBones);
  stripHeader.flags = IsByte(val: pStrip->flags);
  stripFileOffset = this->m_StripsOffset + 35 * stripID;
  stripHeader.boneStateChangeOffset = IsInt24(val: this->m_BoneStateChangesOffset + 8 * boneID - stripFileOffset);
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[stripFileOffset];
  *(OptimizedModel::StripHeader_t *)m_FileBuffer->m_pCurPos = stripHeader;
  m_FileBuffer->m_pCurPos += 35;
}

//------------------------------------------------------------------------------
// Address: 0x0041CA40
// Name: private: void OptimizedModel::COptimizedModel::WriteBoneStateChange(int,struct OptimizedModel::BoneStateChange_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteBoneStateChange(
        OptimizedModel::COptimizedModel *this,
        int boneID,
        OptimizedModel::BoneStateChange_t *boneStateChange)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-10h]
  OptimizedModel::BoneStateChange_t boneHeader; // 0:^8.8

  boneHeader = *boneStateChange;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[8 * boneID + this->m_BoneStateChangesOffset];
  *(OptimizedModel::BoneStateChange_t *)m_FileBuffer->m_pCurPos = boneHeader;
  m_FileBuffer->m_pCurPos += 8;
}

//------------------------------------------------------------------------------
// Address: 0x0041CB50
// Name: private: float OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::Vertex_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        OptimizedModel::Vertex_t *pVert,
        int boneID)
{
  mstudio_meshvertexdata_t *vertData; // [esp+24h] [ebp-4h]

  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  return *((float *)vertData->modelvertexdata->pVertexData
         + 12
         * ((int)vertData[-1].modelvertexdata
          + pVert->origMeshVertID
          + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30)
         + pVert->boneWeightIndex[boneID]);
}

//------------------------------------------------------------------------------
// Address: 0x0041CC00
// Name: private: struct mstudioboneweight_t __near & OptimizedModel::COptimizedModel::GetOrigVertBoneWeight(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::Vertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
mstudioboneweight_t *__thiscall OptimizedModel::COptimizedModel::GetOrigVertBoneWeight(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        OptimizedModel::Vertex_t *pVert)
{
  mstudio_meshvertexdata_t *vertData; // [esp+20h] [ebp-4h]

  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  return (mstudioboneweight_t *)((char *)vertData->modelvertexdata->pVertexData
                               + 48
                               * ((int)vertData[-1].modelvertexdata
                                + pVert->origMeshVertID
                                + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30));
}

//------------------------------------------------------------------------------
// Address: 0x0041CCA0
// Name: private: int OptimizedModel::COptimizedModel::GetOrigVertBoneIndex(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::Vertex_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetOrigVertBoneIndex(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        OptimizedModel::Vertex_t *pVert,
        int boneID)
{
  mstudio_meshvertexdata_t *vertData; // [esp+20h] [ebp-4h]

  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  return *((unsigned __int8 *)vertData->modelvertexdata->pVertexData
         + 48
         * ((int)vertData[-1].modelvertexdata
          + pVert->origMeshVertID
          + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30)
         + pVert->boneWeightIndex[boneID]
         + 12);
}

//------------------------------------------------------------------------------
// Address: 0x0041CD50
// Name: private: void OptimizedModel::COptimizedModel::GLViewVert(struct _iobuf __near *,struct OptimizedModel::Vertex_t,int,class Vector __near &,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::GLViewVert(
        OptimizedModel::COptimizedModel *this,
        _iobuf *fp,
        OptimizedModel::Vertex_t vert,
        int index,
        Vector *color,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        bool showSubStrips,
        float shrinkFactor)
{
  OptimizedModel::Vertex_t *v9; // ecx
  int id; // [esp+10h] [ebp-4h]

  id = s_ListID % 3;
  s_LastThreeIndices[s_ListID % 3] = index;
  v9 = &s_LastThreeVerts[id];
  *v9 = vert;
  s_Shrunk[id] = false;
  s_LastThreePositions[id] = *OptimizedModel::COptimizedModel::GetOrigVertPosition(
                                this,
                                pStudioModel,
                                pStudioMesh,
                                pVert: v9);
  if ( s_DrawMode != 0 )
  {
    if ( s_ListID >= 2 )
    {
      if ( s_LastThreeIndices[0] == s_LastThreeIndices[1]
        || s_LastThreeIndices[1] == s_LastThreeIndices[2]
        || s_LastThreeIndices[0] == s_LastThreeIndices[2] )
      {
        ++numGLViewHWDegenerates;
        if ( showSubStrips )
          OptimizedModel::RandomColor(color);
      }
      else if ( (s_ListID & 1) != 0 )
      {
        OptimizedModel::COptimizedModel::ShrinkVerts(this, shrinkFactor);
        OptimizedModel::COptimizedModel::DrawGLViewTriangle(
          this,
          fp,
          pos1: &s_LastThreePositions[(id + 3) % 3],
          pos2: &s_LastThreePositions[(id + 2) % 3],
          pos3: &s_LastThreePositions[(id + 1) % 3],
          color1: color,
          color2: color,
          color3: color);
      }
      else
      {
        OptimizedModel::COptimizedModel::ShrinkVerts(this, shrinkFactor);
        OptimizedModel::COptimizedModel::DrawGLViewTriangle(
          this,
          fp,
          pos1: &s_LastThreePositions[(id + 1) % 3],
          pos2: &s_LastThreePositions[(id + 2) % 3],
          pos3: &s_LastThreePositions[(id + 3) % 3],
          color1: color,
          color2: color,
          color3: color);
      }
    }
  }
  else if ( id == 2 )
  {
    OptimizedModel::COptimizedModel::ShrinkVerts(this, shrinkFactor);
    OptimizedModel::COptimizedModel::DrawGLViewTriangle(
      this,
      fp,
      pos1: s_LastThreePositions,
      pos2: &s_LastThreePositions[1],
      pos3: &s_LastThreePositions[2],
      color1: color,
      color2: color,
      color3: color);
  }
  ++s_ListID;
}

//------------------------------------------------------------------------------
// Address: 0x0041CFA0
// Name: private: void OptimizedModel::COptimizedModel::SortBonesWithinVertex(bool,struct OptimizedModel::Vertex_t __near *,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,int __near *,int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SortBonesWithinVertex(
        OptimizedModel::COptimizedModel *this,
        bool flexed,
        OptimizedModel::Vertex_t *vert,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        int *globalToHardwareBoneIndex,
        int *hardwareToGlobalBoneIndex,
        int maxBonesPerFace,
        int maxBonesPerVert)
{
  int OrigVertBoneIndex; // [esp+Ch] [ebp-30h]
  float v11; // [esp+10h] [ebp-2Ch]
  int globalBoneIndex; // [esp+1Ch] [ebp-20h]
  float OrigVertBoneWeightValue; // [esp+20h] [ebp-1Ch]
  float boneWeight; // [esp+24h] [ebp-18h]
  int origBoneWeightIndex[3]; // [esp+28h] [ebp-14h]
  int i; // [esp+34h] [ebp-8h]
  int zeroWeightIndex; // [esp+38h] [ebp-4h]

  zeroWeightIndex = -1;
  for ( i = 0; i < 3; ++i )
  {
    boneWeight = OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(
                   this,
                   pStudioModel,
                   pStudioMesh,
                   pVert: vert,
                   boneID: i);
    if ( boneWeight == 0.0 )
    {
      zeroWeightIndex = i;
      break;
    }
  }
  for ( i = 0; i < 3; ++i )
    origBoneWeightIndex[i] = zeroWeightIndex;
  for ( i = 0; i < vert->numBones; ++i )
  {
    OrigVertBoneWeightValue = OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(
                                this,
                                pStudioModel,
                                pStudioMesh,
                                pVert: vert,
                                boneID: i);
    globalBoneIndex = OptimizedModel::COptimizedModel::GetOrigVertBoneIndex(
                        this,
                        pStudioModel,
                        pStudioMesh,
                        pVert: vert,
                        boneID: i);
    if ( flexed )
    {
      printf(format: "boneWeight: %f\n", OrigVertBoneWeightValue);
      printf(format: "globalBoneIndex: %d\n", globalBoneIndex);
    }
    if ( OrigVertBoneWeightValue <= 0.0 )
      origBoneWeightIndex[globalToHardwareBoneIndex[globalBoneIndex]] = zeroWeightIndex;
    else
      origBoneWeightIndex[globalToHardwareBoneIndex[globalBoneIndex]] = vert->boneWeightIndex[i];
  }
  for ( i = 0; i < maxBonesPerFace; ++i )
  {
    vert->boneID[i] = i;
    vert->boneWeightIndex[i] = origBoneWeightIndex[i];
    v11 = OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(
            this,
            pStudioModel,
            pStudioMesh,
            pVert: vert,
            boneID: i);
    OrigVertBoneIndex = OptimizedModel::COptimizedModel::GetOrigVertBoneIndex(
                          this,
                          pStudioModel,
                          pStudioMesh,
                          pVert: vert,
                          boneID: i);
    if ( flexed )
    {
      printf(format: "boneWeight: %f ", v11);
      printf(format: "globalBoneIndex: %d ", OrigVertBoneIndex);
      printf(format: "hardwareBoneID: %d\n", i);
    }
  }
  vert->numBones = maxBonesPerFace;
}

//------------------------------------------------------------------------------
// Address: 0x0041D2B0
// Name: public: struct OptimizedModel::EdgeInfo_t __near & CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::EdgeInfo_t *__thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::operator[](
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int i)
{
  return (OptimizedModel::EdgeInfo_t *)i;
}

//------------------------------------------------------------------------------
// Address: 0x0041D2E0
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D360
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 20 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 20 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 20 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0041D3E0
// Name: public: void CUtlMemory<struct OptimizedModel::Vertex_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Vertex_t,int>::Grow(CUtlMemory<OptimizedModel::Vertex_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::Vertex_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 9);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 9 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Vertex_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::Vertex_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D460
// Name: public: void CUtlMemory<struct OptimizedModel::Strip_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Strip_t,int>::Grow(CUtlMemory<OptimizedModel::Strip_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::Strip_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 4168);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 4168 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Strip_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::Strip_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D4F0
// Name: public: void CUtlMemory<struct OptimizedModel::StripGroup_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::StripGroup_t,int>::Grow(
        CUtlMemory<OptimizedModel::StripGroup_t,int> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::StripGroup_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 84);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 84 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::StripGroup_t *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v8);
    else
      this->m_pMemory = (OptimizedModel::StripGroup_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D570
// Name: public: void CUtlMemory<struct OptimizedModel::Mesh_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Mesh_t,int>::Grow(CUtlMemory<OptimizedModel::ModelLOD_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::ModelLOD_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 24);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 24 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::ModelLOD_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::ModelLOD_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D5F0
// Name: public: void CUtlMemory<struct OptimizedModel::Face_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Face_t,int>::Grow(CUtlMemory<OptimizedModel::Face_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::Face_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 88);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 88 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Face_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::Face_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D670
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<bool,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  bool *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 1);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v6);
    else
      this->m_pMemory = (bool *)MemAlloc_Alloc(nSize: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D6F0
// Name: public: void CUtlMemory<struct OptimizedModel::StripVertLookup_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::StripVertLookup_t,int>::Grow(
        CUtlMemory<OptimizedModel::StripVertLookup_t,int> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::StripVertLookup_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 8);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 8 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::StripVertLookup_t *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v8);
    else
      this->m_pMemory = (OptimizedModel::StripVertLookup_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D770
// Name: public: int OptimizedModel::CStringTable::StringTableOffset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::CStringTable::StringTableOffset(OptimizedModel::CStringTable *this, const char *string)
{
  const char *j; // eax
  CUtlVector<char,CUtlMemory<char,int> > *v3; // eax
  const char *v4; // eax
  ConCommandBase *v6; // eax
  int size; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  size = 0;
  i = 0;
  for ( j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this);
        i < (int)j;
        j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this) )
  {
    v3 = (CUtlVector<char,CUtlMemory<char,int> > *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                                                     (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                                                     i);
    v4 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: v3);
    if ( _V_stricmp(s1: v4, s2: string) == 0 )
      return size;
    v6 = (ConCommandBase *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                             (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                             i);
    size += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: v6);
    ++i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041D7F0
// Name: public: bool OptimizedModel::CStringTable::StringPresent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::CStringTable::StringPresent(OptimizedModel::CStringTable *this, const char *string)
{
  const char *j; // eax
  CUtlVector<char,CUtlMemory<char,int> > *v3; // eax
  const char *v4; // eax
  int i; // [esp+4h] [ebp-4h]

  i = 0;
  for ( j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this);
        i < (int)j;
        j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this) )
  {
    v3 = (CUtlVector<char,CUtlMemory<char,int> > *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                                                     (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                                                     i);
    v4 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: v3);
    if ( _V_stricmp(s1: v4, s2: string) == 0 )
      return 1;
    ++i;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041D850
// Name: public: int OptimizedModel::CStringTable::CalcSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::CStringTable::CalcSize(OptimizedModel::CStringTable *this)
{
  const char *j; // eax
  ConCommandBase *v2; // eax
  int size; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  size = 0;
  i = 0;
  for ( j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this);
        i < (int)j;
        j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this) )
  {
    v2 = (ConCommandBase *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                             (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                             i);
    size += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: v2);
    ++i;
  }
  return size;
}

//------------------------------------------------------------------------------
// Address: 0x0041D8B0
// Name: public: void OptimizedModel::CStringTable::WriteToMem(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::CStringTable::WriteToMem(OptimizedModel::CStringTable *this, char *pDst)
{
  const char *j; // eax
  ConCommandBase *v3; // eax
  CUtlVector<char,CUtlMemory<char,int> > *v4; // eax
  unsigned __int8 *v5; // eax
  ConCommandBase *v6; // eax
  const char *v7; // [esp-4h] [ebp-10h]
  int size; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  size = 0;
  i = 0;
  for ( j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this);
        i < (int)j;
        j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this) )
  {
    v3 = (ConCommandBase *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                             (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                             i);
    v7 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: v3);
    v4 = (CUtlVector<char,CUtlMemory<char,int> > *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                                                     (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                                                     i);
    v5 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: v4);
    memcpy(dst: (unsigned __int8 *)&pDst[size], src: v5, count: (unsigned int)v7);
    v6 = (ConCommandBase *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                             (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                             i);
    size += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: v6);
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D940
// Name: OptimizedModel::GetNextUntouched
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__cdecl OptimizedModel::GetNextUntouched(
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faces)
{
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faces);
        ++i )
  {
    if ( !CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i)->touched )
      return CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041D990
// Name: private: struct OptimizedModel::Face_t __near * OptimizedModel::COptimizedModel::GetNextUntouchedWithoutBoneStateChange(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__thiscall OptimizedModel::COptimizedModel::GetNextUntouchedWithoutBoneStateChange(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faces)
{
  const OptimizedModel::Face_t *v2; // eax
  int numNewBones; // [esp+Ch] [ebp-14h]
  OptimizedModel::Face_t *bestFace; // [esp+10h] [ebp-10h]
  int bestNumNewBones; // [esp+14h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-4h]

  bestFace = nullptr;
  bestNumNewBones = 3
                  * ((CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                        this: faces,
                        i: 0)->vertID[3] != -1)
                   + 3)
                  + 1;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faces);
        ++i )
  {
    if ( !CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i)->touched )
    {
      v2 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
      numNewBones = OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(this, face: v2);
      if ( numNewBones <= CHardwareMatrixState::FreeMatrixCount(this: &this->m_HardwareMatrixState)
        && numNewBones < bestNumNewBones )
      {
        bestNumNewBones = numNewBones;
        bestFace = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
        if ( numNewBones == 0 )
          break;
      }
    }
  }
  return bestFace;
}

//------------------------------------------------------------------------------
// Address: 0x0041DA50
// Name: private: struct OptimizedModel::Face_t __near * OptimizedModel::COptimizedModel::GetNextUntouchedWithLeastBoneStateChanges(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__thiscall OptimizedModel::COptimizedModel::GetNextUntouchedWithLeastBoneStateChanges(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faces)
{
  const OptimizedModel::Face_t *v2; // eax
  int numNewBones; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  OptimizedModel::Face_t *bestFace; // [esp+14h] [ebp-Ch]
  int bestNumNewBones; // [esp+18h] [ebp-8h]

  bestFace = nullptr;
  bestNumNewBones = 3
                  * ((CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                        this: faces,
                        i: 0)->vertID[3] != -1)
                   + 3)
                  + 1;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faces);
        ++i )
  {
    if ( !CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i)->touched )
    {
      v2 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
      numNewBones = OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(this, face: v2);
      if ( numNewBones < bestNumNewBones )
      {
        bestNumNewBones = numNewBones;
        bestFace = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
      }
    }
  }
  if ( bestFace == nullptr )
    return nullptr;
  CHardwareMatrixState::DeallocateAll(this: &this->m_HardwareMatrixState);
  return bestFace;
}

//------------------------------------------------------------------------------
// Address: 0x0041DB10
// Name: private: struct OptimizedModel::Face_t __near * OptimizedModel::COptimizedModel::GetNextFace(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__thiscall OptimizedModel::COptimizedModel::GetNextFace(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faceList,
        bool allowNewStrip)
{
  OptimizedModel::Face_t *face; // [esp+4h] [ebp-4h]

  face = OptimizedModel::COptimizedModel::GetNextUntouchedWithoutBoneStateChange(this, faces: faceList);
  if ( face == nullptr && allowNewStrip )
    return OptimizedModel::COptimizedModel::GetNextUntouchedWithLeastBoneStateChanges(this, faces: faceList);
  return face;
}

//------------------------------------------------------------------------------
// Address: 0x0041DB50
// Name: private: void OptimizedModel::COptimizedModel::Stripify(class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &,bool,int __near *,int __near *,unsigned short __near * __near *,unsigned short __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::Stripify(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *sourceIndices,
        ConCommandBase *sourceTopologyIndices,
        bool bIsHWSkinned,
        unsigned int *pNumIndices,
        int *pNumTopologyIndices,
        unsigned __int16 **ppIndices,
        unsigned __int16 **ppTopologyIndices,
        bool bQuadSubd)
{
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  const unsigned __int16 *v11; // eax
  const char *v12; // [esp-Ch] [ebp-40h]
  unsigned int v13; // [esp-4h] [ebp-38h]
  unsigned int v14; // [esp-4h] [ebp-38h]
  PrimitiveGroup *primGroups; // [esp+2Ch] [ebp-8h] BYREF
  unsigned __int16 numPrimGroups; // [esp+30h] [ebp-4h] BYREF

  if ( CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: sourceIndices) != nullptr )
  {
    if ( pNumTopologyIndices != nullptr )
      *pNumTopologyIndices = 0;
    if ( ppTopologyIndices != nullptr )
      *ppTopologyIndices = nullptr;
    if ( bQuadSubd || g_bBuildPreview || !bIsHWSkinned || g_bPreserveTriangleOrder )
    {
      *pNumIndices = (unsigned int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: sourceIndices);
      *ppIndices = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)*pNumIndices >> 31 != 0 ? -1 : 2 * *pNumIndices);
      v13 = 2 * *pNumIndices;
      v9 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)sourceIndices);
      memcpy(dst: (unsigned __int8 *)*ppIndices, src: v9, count: v13);
      if ( bQuadSubd )
      {
        *pNumTopologyIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: sourceTopologyIndices);
        *ppTopologyIndices = (unsigned __int16 *)MemAlloc_Alloc(
                                                   nSize: (unsigned __int64)(unsigned int)*pNumTopologyIndices >> 31 != 0
                                                 ? -1
                                                 : 2 * *pNumTopologyIndices);
        v14 = 2 * *pNumTopologyIndices;
        v10 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)sourceTopologyIndices);
        memcpy(dst: (unsigned __int8 *)*ppTopologyIndices, src: v10, count: v14);
      }
    }
    else
    {
      v12 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: sourceIndices);
      v11 = CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::operator[](
              this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)sourceIndices,
              i: 0);
      GenerateStrips(in_indices: v11, in_numIndices: (const unsigned int)v12, &primGroups, numGroups: &numPrimGroups);
      *pNumIndices = primGroups->numIndices;
      *ppIndices = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)*pNumIndices >> 31 != 0 ? -1 : 2 * *pNumIndices);
      memcpy(dst: (unsigned __int8 *)*ppIndices, src: (unsigned __int8 *)primGroups->indices, count: 2 * *pNumIndices);
      if ( primGroups != nullptr )
        PrimitiveGroup::`vector deleting destructor'(this: primGroups, a2: 3u);
    }
  }
  else
  {
    *ppIndices = nullptr;
    *pNumIndices = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DD20
// Name: private: void OptimizedModel::COptimizedModel::BuildFaceBoneData(class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> __near &,struct OptimizedModel::Face_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildFaceBoneData(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *list,
        OptimizedModel::Face_t *face)
{
  int bone; // [esp+4h] [ebp-1Ch]
  OptimizedModel::Vertex_t *vert; // [esp+8h] [ebp-18h]
  int j; // [esp+Ch] [ebp-14h]
  int ja; // [esp+Ch] [ebp-14h]
  int l; // [esp+10h] [ebp-10h]
  int k; // [esp+14h] [ebp-Ch]
  int vertsPerFace; // [esp+1Ch] [ebp-4h]

  vertsPerFace = (face->vertID[3] != -1) + 3;
  face->numBones = 0;
  for ( j = 0; j < 3 * vertsPerFace; ++j )
    face->boneID[j] = -1;
  for ( ja = 0; ja < vertsPerFace; ++ja )
  {
    vert = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
             this: list,
             i: face->vertID[ja]);
    for ( k = 0; k < vert->numBones; ++k )
    {
      bone = vert->boneID[k];
      l = face->numBones;
      do
        --l;
      while ( l >= 0 && bone != face->boneID[l] );
      if ( l < 0 )
        face->boneID[face->numBones++] = bone;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DE30
// Name: private: int OptimizedModel::COptimizedModel::CountUniqueBonesInStrip(struct OptimizedModel::StripGroup_t __near *,struct OptimizedModel::Strip_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::CountUniqueBonesInStrip(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::StripGroup_t *pStripGroup,
        OptimizedModel::Strip_t *pStrip)
{
  void *v3; // esp
  int v5; // [esp+0h] [ebp-20h] BYREF
  OptimizedModel::COptimizedModel *v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-18h]
  int j; // [esp+Ch] [ebp-14h]
  OptimizedModel::Vertex_t *v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+14h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v6 = this;
  v3 = alloca(4 * this->m_NumBones);
  v5 = (int)&v5;
  dst = (unsigned __int8 *)&v5;
  memset(dst: (unsigned __int8 *)&v5, value: 0, count: 4 * this->m_NumBones);
  for ( i = 0; i < pStrip->numStripGroupVerts; ++i )
  {
    v9 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
           this: &pStripGroup->verts,
           i: pStrip->stripGroupVertexOffset + i);
    for ( j = 0; j < v9->numBones; ++j )
    {
      v7 = v9->boneID[j];
      ++*(_DWORD *)&dst[4 * v7];
    }
  }
  v10 = 0;
  for ( i = 0; i < v6->m_NumBones; ++i )
  {
    if ( *(_DWORD *)&dst[4 * i] != 0 )
      ++v10;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0041DF30
// Name: private: int OptimizedModel::COptimizedModel::GetTotalVertsForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalVertsForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int numVerts; // [esp+Ch] [ebp-4h]

  numVerts = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    numVerts += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->verts);
  }
  return numVerts;
}

//------------------------------------------------------------------------------
// Address: 0x0041DF90
// Name: private: int OptimizedModel::COptimizedModel::GetTotalIndicesForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalIndicesForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int numIndices; // [esp+Ch] [ebp-4h]

  numIndices = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    numIndices += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)pStripGroup);
  }
  return numIndices;
}

//------------------------------------------------------------------------------
// Address: 0x0041DFF0
// Name: private: int OptimizedModel::COptimizedModel::GetTotalTopologyIndicesForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalTopologyIndicesForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int numTopologyIndices; // [esp+Ch] [ebp-4h]

  numTopologyIndices = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    numTopologyIndices += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->topologyIndices);
  }
  return numTopologyIndices;
}

//------------------------------------------------------------------------------
// Address: 0x0041E050
// Name: private: int OptimizedModel::COptimizedModel::GetTotalStripsForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalStripsForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int numStrips; // [esp+Ch] [ebp-4h]

  numStrips = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    numStrips += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->strips);
  }
  return numStrips;
}

//------------------------------------------------------------------------------
// Address: 0x0041E0B0
// Name: private: int OptimizedModel::COptimizedModel::GetTotalBoneStateChangesForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalBoneStateChangesForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int numBoneStateChanges; // [esp+14h] [ebp-4h]

  numBoneStateChanges = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    for ( j = 0;
          j < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->strips);
          ++j )
    {
      numBoneStateChanges += CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                               this: &pStripGroup->strips,
                               i: j)->numBoneStateChanges;
    }
  }
  return numBoneStateChanges;
}

//------------------------------------------------------------------------------
// Address: 0x0041E140
// Name: private: bool OptimizedModel::COptimizedModel::MeshNeedsRemoval(struct studiohdr_t __near *,struct mstudiomesh_t __near *,struct LodScriptData_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::MeshNeedsRemoval(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        mstudiomesh_t *pStudioMesh,
        LodScriptData_t *scriptLOD)
{
  char *meshRemovalName; // [esp+8h] [ebp-14h]
  mstudiotexture_t *ptexture; // [esp+Ch] [ebp-10h]
  const char *meshName; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  ptexture = (mstudiotexture_t *)((char *)pHdr
                                + 64 * *(__int16 *)((char *)&pHdr->id + 2 * pStudioMesh->material + pHdr->skinindex)
                                + pHdr->textureindex);
  meshName = (const char *)((int (__thiscall *)(IMaterial *, OptimizedModel::COptimizedModel *))ptexture->material->GetName)(
                             a1: ptexture->material,
                             a2: this);
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->meshRemovals);
        ++i )
  {
    meshRemovalName = CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::operator[](
                        this: &scriptLOD->meshRemovals,
                        i)->m_pSrcName;
    if ( OptimizedModel::ComparePath(a: meshName, b: meshRemovalName) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E200
// Name: private: void OptimizedModel::COptimizedModel::MapGlobalBonesToHardwareBoneIDsAndSortBones(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::MapGlobalBonesToHardwareBoneIDsAndSortBones(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *phdr)
{
  void *v2; // esp
  int v3; // [esp+0h] [ebp-87Ch] BYREF
  OptimizedModel::COptimizedModel *v4; // [esp+4h] [ebp-878h]
  int v5; // [esp+8h] [ebp-874h]
  int v6; // [esp+Ch] [ebp-870h]
  int v7; // [esp+10h] [ebp-86Ch]
  int v8; // [esp+14h] [ebp-868h]
  int v9; // [esp+18h] [ebp-864h]
  int v10; // [esp+1Ch] [ebp-860h]
  int nn; // [esp+20h] [ebp-85Ch]
  OptimizedModel::Vertex_t *vert; // [esp+24h] [ebp-858h]
  int *v13; // [esp+28h] [ebp-854h]
  _DWORD *v14; // [esp+2Ch] [ebp-850h]
  int kk; // [esp+30h] [ebp-84Ch]
  int mm; // [esp+34h] [ebp-848h]
  int jj; // [esp+38h] [ebp-844h]
  _DWORD *v18; // [esp+3Ch] [ebp-840h]
  int ii; // [esp+40h] [ebp-83Ch]
  mstudiomesh_t *pStudioMesh; // [esp+44h] [ebp-838h]
  _DWORD *v21; // [esp+48h] [ebp-834h]
  int n; // [esp+4Ch] [ebp-830h]
  int v23; // [esp+50h] [ebp-82Ch]
  _DWORD *v24; // [esp+54h] [ebp-828h]
  mstudiomodel_t *pStudioModel; // [esp+58h] [ebp-824h]
  int m; // [esp+5Ch] [ebp-820h]
  int k; // [esp+60h] [ebp-81Ch]
  int j; // [esp+64h] [ebp-818h]
  char *v29; // [esp+68h] [ebp-814h]
  _DWORD *v30; // [esp+6Ch] [ebp-810h]
  int i; // [esp+70h] [ebp-80Ch]
  unsigned __int8 *m_pData; // [esp+74h] [ebp-808h]
  int *globalToHardwareBoneIndex; // [esp+78h] [ebp-804h]
  int hardwareToGlobalBoneIndex[512]; // [esp+7Ch] [ebp-800h] BYREF

  v4 = this;
  v2 = alloca(4 * this->m_NumBones);
  v3 = (int)&v3;
  globalToHardwareBoneIndex = &v3;
  m_pData = this->m_FileBuffer->m_pData;
  for ( i = 0; i < *((_DWORD *)m_pData + 7); ++i )
  {
    v9 = (int)&m_pData[8 * i + *((_DWORD *)m_pData + 8)];
    v30 = (_DWORD *)v9;
    v29 = (char *)phdr + 16 * i + phdr->bodypartindex;
    for ( j = 0; j < *((_DWORD *)m_pData + 5); ++j )
    {
      for ( k = 0; k < v4->m_NumBones; ++k )
        globalToHardwareBoneIndex[k] = -1;
      for ( k = 0; k < 512; ++k )
        hardwareToGlobalBoneIndex[k] = -1;
      for ( m = 0; m < *v30; ++m )
      {
        v8 = (int)&v30[2 * m] + v30[1];
        v23 = v8;
        pStudioModel = (mstudiomodel_t *)&v29[148 * m + *((_DWORD *)v29 + 3)];
        v7 = 12 * j + *(_DWORD *)(v8 + 4) + v8;
        v24 = (_DWORD *)v7;
        for ( n = 0; n < *v24; ++n )
        {
          v6 = (int)v24 + 9 * n + v24[1];
          v21 = (_DWORD *)v6;
          pStudioMesh = (mstudiomesh_t *)((char *)pStudioModel + 116 * n + pStudioModel->meshindex);
          for ( ii = 0; ii < *v21; ++ii )
          {
            v5 = (int)v21 + 33 * ii + v21[1];
            v18 = (_DWORD *)v5;
            if ( (*(_BYTE *)(v5 + 24) & 2) != 0 )
            {
              for ( jj = 0; jj < v18[4]; ++jj )
              {
                v14 = (_DWORD *)((char *)v18 + 35 * jj + v18[5]);
                for ( kk = 0; kk < *(_DWORD *)((char *)v14 + 19); ++kk )
                {
                  v13 = (_DWORD *)((char *)&v14[2 * kk] + *(_DWORD *)((char *)v14 + 23));
                  globalToHardwareBoneIndex[v13[1]] = *v13;
                  if ( *v13 != -1 )
                    hardwareToGlobalBoneIndex[*v13] = v13[1];
                }
                for ( mm = 0; mm < v14[2]; ++mm )
                {
                  vert = (OptimizedModel::Vertex_t *)((char *)v18 + 9 * v14[3] + 9 * mm + v18[1]);
                  for ( nn = 0; nn < *((_DWORD *)m_pData + 3); ++nn )
                  {
                    v10 = vert->boneID[nn];
                    if ( v10 == 255 )
                      vert->boneID[nn] = 0;
                    else
                      vert->boneID[nn] = globalToHardwareBoneIndex[v10];
                  }
                  if ( v4->m_bUsesFixedFunction )
                    OptimizedModel::COptimizedModel::SortBonesWithinVertex(
                      this: v4,
                      flexed: false,
                      vert,
                      pStudioModel,
                      pStudioMesh,
                      globalToHardwareBoneIndex,
                      hardwareToGlobalBoneIndex,
                      maxBonesPerFace: v4->m_MaxBonesPerFace,
                      maxBonesPerVert: v4->m_MaxBonesPerVert);
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
// Address: 0x0041E730
// Name: private: int OptimizedModel::COptimizedModel::WriteVerts(int,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::WriteVerts(
        OptimizedModel::COptimizedModel *this,
        int vertID,
        OptimizedModel::StripGroup_t *pStripGroup)
{
  OptimizedModel::Vertex_t *src; // [esp+8h] [ebp-10h]
  CFileBuffer *m_FileBuffer; // [esp+Ch] [ebp-Ch]
  int numVerts; // [esp+10h] [ebp-8h]
  int vertFileOffset; // [esp+14h] [ebp-4h]

  vertFileOffset = this->m_VertsOffset + 9 * vertID;
  numVerts = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->verts);
  src = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
          this: &pStripGroup->verts,
          i: 0);
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[vertFileOffset];
  memcpy(dst: m_FileBuffer->m_pCurPos, src: src->boneWeightIndex, count: 9 * numVerts);
  m_FileBuffer->m_pCurPos += 9 * numVerts;
  return numVerts;
}

//------------------------------------------------------------------------------
// Address: 0x0041E7C0
// Name: private: int OptimizedModel::COptimizedModel::WriteIndices(int,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::WriteIndices(
        OptimizedModel::COptimizedModel *this,
        int indexID,
        ConCommandBase *pStripGroup)
{
  unsigned __int8 *src; // [esp+8h] [ebp-10h]
  CFileBuffer *m_FileBuffer; // [esp+Ch] [ebp-Ch]
  int numIndices; // [esp+10h] [ebp-8h]
  int indexFileOffset; // [esp+14h] [ebp-4h]

  indexFileOffset = this->m_IndicesOffset + 2 * indexID;
  numIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
  src = (unsigned __int8 *)CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::operator[](
                             this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)pStripGroup,
                             i: 0);
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[indexFileOffset];
  memcpy(dst: m_FileBuffer->m_pCurPos, src, count: 2 * numIndices);
  m_FileBuffer->m_pCurPos += 2 * numIndices;
  return numIndices;
}

//------------------------------------------------------------------------------
// Address: 0x0041E840
// Name: private: int OptimizedModel::COptimizedModel::WriteTopology(int,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::WriteTopology(
        OptimizedModel::COptimizedModel *this,
        int topologyID,
        OptimizedModel::StripGroup_t *pStripGroup)
{
  unsigned __int8 *src; // [esp+8h] [ebp-10h]
  CFileBuffer *m_FileBuffer; // [esp+Ch] [ebp-Ch]
  int numTopologyIndices; // [esp+10h] [ebp-8h]
  int topologyIndexFileOffset; // [esp+14h] [ebp-4h]

  if ( CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->topologyIndices) == nullptr )
    return 0;
  topologyIndexFileOffset = this->m_TopologyOffset + 2 * topologyID;
  numTopologyIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->topologyIndices);
  src = (unsigned __int8 *)CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::operator[](
                             this: &pStripGroup->topologyIndices,
                             i: 0);
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[topologyIndexFileOffset];
  memcpy(dst: m_FileBuffer->m_pCurPos, src, count: 2 * numTopologyIndices);
  m_FileBuffer->m_pCurPos += 2 * numTopologyIndices;
  return numTopologyIndices;
}

//------------------------------------------------------------------------------
// Address: 0x0041E8E0
// Name: private: void OptimizedModel::COptimizedModel::WriteStringTable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteStringTable(
        OptimizedModel::COptimizedModel *this,
        int stringTableOffset)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-24h]
  char *pTmp; // [esp+20h] [ebp-8h]
  unsigned int stringTableSize; // [esp+24h] [ebp-4h]

  stringTableSize = OptimizedModel::CStringTable::CalcSize(this: &s_StringTable);
  if ( stringTableSize != 0 )
  {
    pTmp = (char *)MemAlloc_Alloc(nSize: stringTableSize);
    OptimizedModel::CStringTable::WriteToMem(this: &s_StringTable, pDst: pTmp);
    m_FileBuffer = this->m_FileBuffer;
    m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[stringTableOffset];
    memcpy(dst: m_FileBuffer->m_pCurPos, src: (unsigned __int8 *)pTmp, count: stringTableSize);
    m_FileBuffer->m_pCurPos += stringTableSize;
    free(pMem: pTmp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E980
// Name: private: void OptimizedModel::COptimizedModel::WriteMaterialReplacements(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteMaterialReplacements(
        OptimizedModel::COptimizedModel *this,
        int materialReplacementsOffset)
{
  unsigned __int8 *m_pCurPos; // eax
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-34h]
  CLodScriptReplacement_t *materialReplacement; // [esp+18h] [ebp-20h]
  OptimizedModel::MaterialReplacementHeader_t tmpHeader; // [esp+1Ch] [ebp-1Ch]
  LodScriptData_t *scriptLOD; // [esp+24h] [ebp-14h]
  int j; // [esp+28h] [ebp-10h]
  const char *numLODs; // [esp+2Ch] [ebp-Ch]
  int i; // [esp+34h] [ebp-4h]

  numLODs = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  for ( i = 0; i < (int)numLODs; ++i )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i);
    for ( j = 0;
          j < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->materialReplacements);
          ++j )
    {
      materialReplacement = CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::operator[](
                              this: &scriptLOD->materialReplacements,
                              i: j);
      tmpHeader.materialID = FindMaterialByName(pMaterialName: materialReplacement->m_pSrcName);
      tmpHeader.replacementMaterialNameOffset = OptimizedModel::CStringTable::StringTableOffset(
                                                  this: &s_StringTable,
                                                  string: materialReplacement->m_pDstName)
                                              + this->m_StringTableOffset
                                              - materialReplacementsOffset;
      m_FileBuffer = this->m_FileBuffer;
      m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[materialReplacementsOffset];
      m_pCurPos = m_FileBuffer->m_pCurPos;
      *(_DWORD *)m_pCurPos = *(_DWORD *)&tmpHeader.materialID;
      *((_WORD *)m_pCurPos + 2) = HIWORD(tmpHeader.replacementMaterialNameOffset);
      m_FileBuffer->m_pCurPos += 6;
      materialReplacementsOffset += 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EAA0
// Name: private: void OptimizedModel::COptimizedModel::WriteMaterialReplacementLists(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteMaterialReplacementLists(
        OptimizedModel::COptimizedModel *this,
        int materialReplacementsOffset,
        int materialReplacementListOffset)
{
  const char *v3; // eax
  unsigned __int8 *m_pCurPos; // ecx
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-24h]
  LodScriptData_t *scriptLOD; // [esp+Ch] [ebp-1Ch]
  int tmpHeader; // [esp+10h] [ebp-18h]
  int tmpHeader_4; // [esp+14h] [ebp-14h]
  const char *numLODs; // [esp+18h] [ebp-10h]
  int i; // [esp+20h] [ebp-8h]

  numLODs = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  for ( i = 0; i < (int)numLODs; ++i )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i);
    v3 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->materialReplacements);
    tmpHeader = IsChar(val: (int)v3);
    tmpHeader_4 = IsInt24(val: materialReplacementsOffset - materialReplacementListOffset);
    m_FileBuffer = this->m_FileBuffer;
    m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[materialReplacementListOffset];
    m_pCurPos = m_FileBuffer->m_pCurPos;
    *(_DWORD *)m_pCurPos = tmpHeader;
    *((_DWORD *)m_pCurPos + 1) = tmpHeader_4;
    m_FileBuffer->m_pCurPos += 8;
    materialReplacementsOffset += 6 * tmpHeader;
    materialReplacementListOffset += 8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EB90
// Name: private: void OptimizedModel::COptimizedModel::SanityCheckVertexBoneLODFlags(struct studiohdr_t __near *,struct OptimizedModel::FileHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SanityCheckVertexBoneLODFlags(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pStudioHdr,
        OptimizedModel::FileHeader_t *pVtxHeader)
{
  OptimizedModel::Vertex_t *pVertex; // [esp+28h] [ebp-44h]
  const mstudioboneweight_t *boneWeight; // [esp+2Ch] [ebp-40h]
  int i; // [esp+30h] [ebp-3Ch]
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+34h] [ebp-38h]
  int vertID; // [esp+38h] [ebp-34h]
  int stripGroupID; // [esp+3Ch] [ebp-30h]
  mstudiomesh_t *pMesh; // [esp+40h] [ebp-2Ch]
  OptimizedModel::MeshHeader_t *pVtxMesh; // [esp+44h] [ebp-28h]
  int meshID; // [esp+48h] [ebp-24h]
  OptimizedModel::ModelLODHeader_t *pVtxLOD; // [esp+4Ch] [ebp-20h]
  OptimizedModel::ModelHeader_t *pVtxModel; // [esp+50h] [ebp-1Ch]
  mstudiomodel_t *pModel; // [esp+54h] [ebp-18h]
  int lodID; // [esp+58h] [ebp-14h]
  int modelID; // [esp+5Ch] [ebp-10h]
  mstudiobodyparts_t *pBodyPart; // [esp+60h] [ebp-Ch]
  OptimizedModel::BodyPartHeader_t *pVtxBodyPart; // [esp+64h] [ebp-8h]
  int bodyPartID; // [esp+68h] [ebp-4h]

  for ( bodyPartID = 0; bodyPartID < pStudioHdr->numbodyparts; ++bodyPartID )
  {
    pBodyPart = (mstudiobodyparts_t *)((char *)pStudioHdr + 16 * bodyPartID + pStudioHdr->bodypartindex);
    pVtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)pVtxHeader + 8 * bodyPartID + pVtxHeader->bodyPartOffset);
    for ( modelID = 0; modelID < pBodyPart->nummodels; ++modelID )
    {
      pModel = (mstudiomodel_t *)((char *)pBodyPart + 148 * modelID + pBodyPart->modelindex);
      pVtxModel = (OptimizedModel::ModelHeader_t *)((char *)&pVtxBodyPart[modelID] + pVtxBodyPart->modelOffset);
      for ( lodID = 0; lodID < pVtxModel->numLODs; ++lodID )
      {
        pVtxLOD = (OptimizedModel::ModelLODHeader_t *)((char *)pVtxModel + 12 * lodID + pVtxModel->lodOffset);
        for ( meshID = 0; meshID < pVtxLOD->numMeshes; ++meshID )
        {
          pVtxMesh = (OptimizedModel::MeshHeader_t *)((char *)pVtxLOD + 9 * meshID + pVtxLOD->meshOffset);
          pMesh = (mstudiomesh_t *)((char *)pModel + 116 * meshID + pModel->meshindex);
          for ( stripGroupID = 0; stripGroupID < pVtxMesh->numStripGroups; ++stripGroupID )
          {
            pStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)pVtxMesh
                                                               + 33 * stripGroupID
                                                               + pVtxMesh->stripGroupHeaderOffset);
            for ( vertID = 0; vertID < pStripGroup->numVerts; ++vertID )
            {
              pVertex = (OptimizedModel::Vertex_t *)((char *)pStripGroup + 9 * vertID + pStripGroup->vertOffset);
              OptimizedModel::COptimizedModel::GetOrigVertPosition(
                this,
                pStudioModel: pModel,
                pStudioMesh: pMesh,
                pVert: pVertex);
              boneWeight = OptimizedModel::COptimizedModel::GetOrigVertBoneWeight(
                             this,
                             pStudioModel: pModel,
                             pStudioMesh: pMesh,
                             pVert: pVertex);
              for ( i = 0; i < boneWeight->numbones; ++i )
              {
                if ( (*(int *)((_BYTE *)&pStudioHdr->boneindex + 216 * boneWeight->bone[i] + pStudioHdr->boneindex)
                    & (1024 << lodID)) == 0 )
                  MdlError(fmt: "Mismarked Bone flag");
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EE00
// Name: OptimizedModel::CalcNumMaterialReplacements
// Source: json
//------------------------------------------------------------------------------
int __cdecl OptimizedModel::CalcNumMaterialReplacements()
{
  LodScriptData_t *scriptLOD; // [esp+0h] [ebp-10h]
  const char *numLODs; // [esp+4h] [ebp-Ch]
  int numReplacements; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  numReplacements = 0;
  numLODs = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  for ( i = 0; i < (int)numLODs; ++i )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i);
    numReplacements += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->materialReplacements);
  }
  return numReplacements;
}

//------------------------------------------------------------------------------
// Address: 0x0041EE60
// Name: void OptimizedModel::ValidateLODReplacements(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::ValidateLODReplacements(studiohdr_t *pHdr)
{
  int (__thiscall ***v1)(_DWORD, _DWORD); // ecx
  const char *v2; // eax
  int (__thiscall ***v3)(_DWORD); // [esp+4h] [ebp-28h]
  int k; // [esp+Ch] [ebp-20h]
  const char *pName2; // [esp+10h] [ebp-1Ch]
  int i; // [esp+14h] [ebp-18h]
  char *pName1; // [esp+18h] [ebp-14h]
  int j; // [esp+1Ch] [ebp-10h]
  LodScriptData_t *scriptLOD; // [esp+20h] [ebp-Ch]
  bool failed; // [esp+27h] [ebp-5h]
  int lodID; // [esp+28h] [ebp-4h]

  failed = false;
  for ( lodID = 0;
        lodID < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
        ++lodID )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i: lodID);
    for ( j = 0;
          j < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->meshRemovals);
          ++j )
    {
      pName1 = CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::operator[](
                 this: &scriptLOD->meshRemovals,
                 i: j)->m_pSrcName;
      for ( i = 0; i < pHdr->numtextures; ++i )
      {
        v3 = *(int (__thiscall ****)(_DWORD))&pHdr->name[64 * i + 4 + pHdr->textureindex];
        pName2 = (const char *)(**v3)(a1: v3);
        if ( OptimizedModel::ComparePath(a: pName1, b: pName2) != 0 )
          goto got_one;
      }
      MdlWarning(fmt: "\"%s\" doesn't match any of the materals in the model\n", pName1);
      failed = true;
got_one:
      ;
    }
  }
  if ( failed )
  {
    MdlWarning(fmt: "possible materials in model:\n");
    for ( k = 0; k < pHdr->numtextures; ++k )
    {
      v1 = *(int (__thiscall ****)(_DWORD, _DWORD))&pHdr->name[64 * k + 4 + pHdr->textureindex];
      v2 = (const char *)(**v1)(a1: v1, a2: v1);
      MdlWarning(fmt: "\t\"%s\"\n", v2);
    }
    MdlError(fmt: "Exiting due to errors\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EFE0
// Name: public: void CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::RemoveAll(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this)
{
  int m_Size; // esi
  int v2; // edx

  m_Size = this->m_Buckets.m_Size;
  if ( m_Size > 0 )
  {
    v2 = 0;
    do
    {
      this->m_Buckets.m_Memory.m_pMemory[v2++].m_Size = 0;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F010
// Name: public: struct OptimizedModel::StripVertLookup_t __near & CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::Element(unsigned int)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::StripVertLookup_t *__thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Element(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        unsigned int handle)
{
  return &this->m_Buckets.m_Memory.m_pMemory[HIWORD(handle)].m_Memory.m_pMemory[(unsigned __int16)handle];
}

//------------------------------------------------------------------------------
// Address: 0x0041F030
// Name: public: void CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::EnsureCapacity(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int num)
{
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::Grow(
    this: &this->m_Memory,
    num: num - this->m_Memory.m_nAllocationCount);
  this->m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041F050
// Name: public: int CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::Next(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Next(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int i)
{
  return *(_DWORD *)(i + 16);
}

//------------------------------------------------------------------------------
// Address: 0x0041F060
// Name: protected: bool CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::DoFind(struct OptimizedModel::StripVertLookup_t const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::DoFind(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        const OptimizedModel::StripVertLookup_t *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int> > *v7; // ebx
  int m_Size; // eax
  int v9; // esi
  int keyDataCount; // [esp+18h] [ebp+Ch]

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = &this->m_Buckets.m_Memory.m_pMemory[v6];
  m_Size = v7->m_Size;
  v9 = 0;
  keyDataCount = m_Size;
  if ( m_Size > 0 )
  {
    do
    {
      if ( this->m_CompareFunc(a1: &v7->m_Memory.m_pMemory[v9], a2: src) )
        break;
      ++v9;
    }
    while ( v9 < keyDataCount );
    m_Size = keyDataCount;
  }
  if ( v9 == m_Size )
    return 0;
  *pIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F0E0
// Name: protected: int CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 16);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 12) = 0;
    }
    else
    {
      *(_DWORD *)(result + 16) = result;
      *(_DWORD *)(result + 12) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)((char *)v8 + 20 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 20 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F310
// Name: public: void CFileBuffer::WriteToFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileBuffer::WriteToFile(CFileBuffer *this, const char *fileName, unsigned int size)
{
  CP4File *v3; // eax
  char *v4; // eax
  char *v5; // [esp+4h] [ebp-28h]
  CPlainAutoPtr<CP4File> spFile; // [esp+24h] [ebp-8h] BYREF
  _iobuf *fp; // [esp+28h] [ebp-4h]

  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename: fileName);
  CPlainAutoPtr<CP4File>::CPlainAutoPtr<CP4File>(this: &spFile, p: v3);
  v5 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&spFile);
  (*(void (__thiscall **)(char *))(*(_DWORD *)v5 + 4))(a1: v5);
  fp = fopen(file: fileName, mode: "wb");
  if ( fp != nullptr )
  {
    fwrite(buffer: this->m_pData, size: 1u, count: size, stream: fp);
    fclose(stream: fp);
    v4 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&spFile);
    (*(void (__thiscall **)(char *, char *))(*(_DWORD *)v4 + 8))(a1: v4, a2: v4);
  }
  else
  {
    MdlWarning(fmt: "Can't open \"%s\" for writing!\n", fileName);
  }
  CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: &spFile);
}

//------------------------------------------------------------------------------
// Address: 0x0041F3D0
// Name: private: void OptimizedModel::COptimizedModel::WriteVTXFile(struct studiohdr_t __near *,char const __near *,struct OptimizedModel::TotalMeshStats_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteVTXFile(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        const char *pFileName,
        const OptimizedModel::TotalMeshStats_t *stats)
{
  const char *i; // eax
  CFileBuffer *v5; // [esp+0h] [ebp-C0h]
  CFileBuffer *v7; // [esp+34h] [ebp-8Ch]
  int boneStateChangeID; // [esp+38h] [ebp-88h]
  OptimizedModel::Strip_t *pStrip; // [esp+3Ch] [ebp-84h]
  int stripID; // [esp+40h] [ebp-80h]
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+44h] [ebp-7Ch]
  const char *nStripCount; // [esp+48h] [ebp-78h]
  int stripGroupID; // [esp+4Ch] [ebp-74h]
  ConCommandBase *pMesh; // [esp+50h] [ebp-70h]
  int meshID; // [esp+54h] [ebp-6Ch]
  OptimizedModel::ModelLOD_t *pLOD; // [esp+58h] [ebp-68h]
  int lodID; // [esp+5Ch] [ebp-64h]
  OptimizedModel::Model_t *pModel; // [esp+60h] [ebp-60h]
  mstudiomodel_t *pStudioModel; // [esp+64h] [ebp-5Ch]
  int modelID; // [esp+68h] [ebp-58h]
  mstudiobodyparts_t *pBodyPart; // [esp+6Ch] [ebp-54h]
  int bodyPartID; // [esp+70h] [ebp-50h]
  int curStripGroup; // [esp+74h] [ebp-4Ch]
  int deltaIndex; // [esp+78h] [ebp-48h]
  int deltaTopology; // [esp+7Ch] [ebp-44h]
  int deltaVert; // [esp+80h] [ebp-40h]
  int deltaBoneStateChange; // [esp+84h] [ebp-3Ch]
  int curMesh; // [esp+8Ch] [ebp-34h]
  int curStrip; // [esp+90h] [ebp-30h]
  int deltaStrip; // [esp+94h] [ebp-2Ch]
  int deltaLOD; // [esp+98h] [ebp-28h]
  int curVert; // [esp+9Ch] [ebp-24h]
  int curIndex; // [esp+A0h] [ebp-20h]
  int curTopology; // [esp+A4h] [ebp-1Ch]
  int curLOD; // [esp+A8h] [ebp-18h]
  int deltaStripGroup; // [esp+ACh] [ebp-14h]
  int curBoneStateChange; // [esp+B0h] [ebp-10h]
  int deltaMesh; // [esp+B4h] [ebp-Ch]
  int curModel; // [esp+B8h] [ebp-8h]
  int deltaModel; // [esp+BCh] [ebp-4h]

  v7 = (CFileBuffer *)MemAlloc_Alloc(nSize: 0xCu);
  if ( v7 != nullptr )
  {
    v7->m_pData = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x400000u);
    v7->m_Size = 0x400000;
    v7->m_pCurPos = v7->m_pData;
    v5 = v7;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_FileBuffer = v5;
  this->m_BodyPartsOffset = 36;
  this->m_ModelsOffset = this->m_BodyPartsOffset + 8 * stats->m_TotalBodyParts;
  this->m_ModelLODsOffset = this->m_ModelsOffset + 8 * stats->m_TotalModels;
  this->m_MeshesOffset = this->m_ModelLODsOffset + 12 * stats->m_TotalModelLODs;
  this->m_StripGroupsOffset = this->m_MeshesOffset + 9 * stats->m_TotalMeshes;
  this->m_StripsOffset = this->m_StripGroupsOffset + 33 * stats->m_TotalStripGroups;
  this->m_VertsOffset = this->m_StripsOffset + 35 * stats->m_TotalStrips;
  this->m_IndicesOffset = this->m_VertsOffset + 9 * stats->m_TotalVerts;
  this->m_BoneStateChangesOffset = this->m_IndicesOffset + 2 * stats->m_TotalIndices;
  this->m_StringTableOffset = this->m_BoneStateChangesOffset + 8 * stats->m_TotalBoneStateChanges;
  this->m_MaterialReplacementsOffset = this->m_StringTableOffset
                                     + OptimizedModel::CStringTable::CalcSize(this: &s_StringTable);
  this->m_MaterialReplacementsListOffset = this->m_MaterialReplacementsOffset + 6 * stats->m_TotalMaterialReplacements;
  this->m_TopologyOffset = this->m_MaterialReplacementsListOffset
                         + 8
                         * (_DWORD)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  this->m_EndOfFileOffset = this->m_TopologyOffset + 2 * stats->m_TotalTopologyIndices;
  curModel = 0;
  curLOD = 0;
  curMesh = 0;
  curStrip = 0;
  curStripGroup = 0;
  curVert = 0;
  curIndex = 0;
  curTopology = 0;
  curBoneStateChange = 0;
  deltaModel = 0;
  deltaLOD = 0;
  deltaMesh = 0;
  deltaStrip = 0;
  deltaStripGroup = 0;
  deltaBoneStateChange = 0;
  OptimizedModel::COptimizedModel::WriteStringTable(this, stringTableOffset: this->m_StringTableOffset);
  OptimizedModel::COptimizedModel::WriteMaterialReplacements(
    this,
    materialReplacementsOffset: this->m_MaterialReplacementsOffset);
  OptimizedModel::COptimizedModel::WriteMaterialReplacementLists(
    this,
    materialReplacementsOffset: this->m_MaterialReplacementsOffset,
    materialReplacementListOffset: this->m_MaterialReplacementsListOffset);
  for ( bodyPartID = 0; bodyPartID < pHdr->numbodyparts; ++bodyPartID )
  {
    pBodyPart = (mstudiobodyparts_t *)((char *)pHdr + 16 * bodyPartID + pHdr->bodypartindex);
    for ( modelID = 0; modelID < pBodyPart->nummodels; ++modelID )
    {
      pStudioModel = (mstudiomodel_t *)((char *)pBodyPart + 148 * modelID + pBodyPart->modelindex);
      pModel = CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                 this: &this->m_Models,
                 i: deltaModel + curModel);
      for ( lodID = 0;
            lodID < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
            ++lodID )
      {
        pLOD = CUtlVector<OptimizedModel::Mesh_t,CUtlMemory<OptimizedModel::Mesh_t,int>>::operator[](
                 this: &pModel->modelLODs,
                 i: lodID);
        for ( meshID = 0; meshID < pStudioModel->nummeshes; ++meshID )
        {
          pMesh = (ConCommandBase *)CUtlVector<OptimizedModel::Mesh_t,CUtlMemory<OptimizedModel::Mesh_t,int>>::operator[](
                                      this: (CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int> > *)pLOD,
                                      i: meshID);
          stripGroupID = 0;
          for ( i = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
                stripGroupID < (int)i;
                i = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh) )
          {
            pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                            this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                            i: stripGroupID);
            deltaVert = OptimizedModel::COptimizedModel::WriteVerts(this, vertID: curVert, pStripGroup);
            deltaIndex = OptimizedModel::COptimizedModel::WriteIndices(
                           this,
                           indexID: curIndex,
                           (ConCommandBase *)pStripGroup);
            deltaTopology = OptimizedModel::COptimizedModel::WriteTopology(this, topologyID: curTopology, pStripGroup);
            nStripCount = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->strips);
            for ( stripID = 0; stripID < (int)nStripCount; ++stripID )
            {
              pStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                         this: &pStripGroup->strips,
                         i: stripID);
              for ( boneStateChangeID = 0; boneStateChangeID < pStrip->numBoneStateChanges; ++boneStateChangeID )
              {
                OptimizedModel::COptimizedModel::WriteBoneStateChange(
                  this,
                  boneID: deltaBoneStateChange + curBoneStateChange,
                  boneStateChange: &pStrip->boneStateChanges[boneStateChangeID]);
                ++deltaBoneStateChange;
              }
              OptimizedModel::COptimizedModel::WriteStrip(
                this,
                stripID: deltaStrip + curStrip,
                pStrip,
                indexID: curIndex,
                curTopology,
                vertID: curVert,
                boneID: curBoneStateChange);
              ++deltaStrip;
              curBoneStateChange += deltaBoneStateChange;
              deltaBoneStateChange = 0;
            }
            OptimizedModel::COptimizedModel::WriteStripGroup(
              this,
              stripGroupID: deltaStripGroup + curStripGroup,
              (ConCommandBase *)pStripGroup,
              vertID: curVert,
              indexID: curIndex,
              topologyID: curTopology,
              stripID: curStrip);
            ++deltaStripGroup;
            curStrip += deltaStrip;
            deltaStrip = 0;
            curVert += deltaVert;
            curIndex += deltaIndex;
            curTopology += deltaTopology;
            ++stripGroupID;
          }
          OptimizedModel::COptimizedModel::WriteMesh(
            this,
            meshID: deltaMesh + curMesh,
            pMesh,
            stripGroupID: curStripGroup);
          ++deltaMesh;
          curStripGroup += deltaStripGroup;
          deltaStripGroup = 0;
        }
        OptimizedModel::COptimizedModel::WriteModelLOD(
          this,
          lodID: deltaLOD + curLOD,
          (ConCommandBase *)pLOD,
          meshID: curMesh);
        ++deltaLOD;
        curMesh += deltaMesh;
        deltaMesh = 0;
      }
      OptimizedModel::COptimizedModel::WriteModel(
        this,
        modelID: deltaModel + curModel,
        pModel: pStudioModel,
        lodID: curLOD);
      ++deltaModel;
      curLOD += deltaLOD;
      deltaLOD = 0;
    }
    OptimizedModel::COptimizedModel::WriteBodyPart(this, bodyPartID, pBodyPart, modelID: curModel);
    curModel += deltaModel;
    deltaModel = 0;
  }
  OptimizedModel::COptimizedModel::WriteHeader(
    this,
    vertCacheSize: this->m_VertexCacheSize,
    maxBonesPerVert: this->m_MaxBonesPerVert,
    maxBonesPerFace: this->m_MaxBonesPerFace,
    maxBonesPerStrip: this->m_MaxBonesPerStrip,
    numBodyParts: pHdr->numbodyparts,
    checkSum: pHdr->checksum);
  OptimizedModel::COptimizedModel::MapGlobalBonesToHardwareBoneIDsAndSortBones(this, phdr: pHdr);
  OptimizedModel::COptimizedModel::SanityCheckAgainstStudioHDR(this, phdr: pHdr);
  if ( !g_quiet )
    OptimizedModel::COptimizedModel::OutputMemoryUsage(this);
  OptimizedModel::COptimizedModel::RemoveRedundantBoneStateChanges(this);
  if ( g_staticprop )
    OptimizedModel::COptimizedModel::ZeroNumBones(this);
  CFileBuffer::WriteToFile(this: this->m_FileBuffer, fileName: pFileName, size: this->m_EndOfFileOffset);
  OptimizedModel::COptimizedModel::SanityCheckVertexBoneLODFlags(
    this,
    pStudioHdr: pHdr,
    pVtxHeader: (OptimizedModel::FileHeader_t *)this->m_FileBuffer->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041FB10
// Name: private: void OptimizedModel::COptimizedModel::WriteGLViewFile(struct studiohdr_t __near *,char const __near *,unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteGLViewFile(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *phdr,
        const char *pFileName,
        __int16 flags,
        float shrinkFactor)
{
  CP4File *v5; // eax
  char *v6; // eax
  char *v7; // [esp+10h] [ebp-194h]
  OptimizedModel::Vertex_t *vert; // [esp+44h] [ebp-160h]
  int id; // [esp+48h] [ebp-15Ch]
  int indexID; // [esp+4Ch] [ebp-158h]
  OptimizedModel::StripHeader_t *pStrip; // [esp+50h] [ebp-154h]
  int stripID; // [esp+54h] [ebp-150h]
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+58h] [ebp-14Ch]
  int stripGroupID; // [esp+5Ch] [ebp-148h]
  mstudiomesh_t *pStudioMesh; // [esp+60h] [ebp-144h]
  OptimizedModel::MeshHeader_t *mesh; // [esp+64h] [ebp-140h]
  int meshID; // [esp+68h] [ebp-13Ch]
  OptimizedModel::ModelLODHeader_t *pLOD; // [esp+6Ch] [ebp-138h]
  CPlainAutoPtr<CP4File> spFile; // [esp+70h] [ebp-134h] BYREF
  char tmp[256]; // [esp+74h] [ebp-130h] BYREF
  _iobuf *fp; // [esp+174h] [ebp-30h]
  int lodID; // [esp+178h] [ebp-2Ch]
  OptimizedModel::ModelHeader_t *model; // [esp+17Ch] [ebp-28h]
  mstudiomodel_t *pStudioModel; // [esp+180h] [ebp-24h]
  int modelID; // [esp+184h] [ebp-20h]
  mstudiobodyparts_t *pStudioBodyPart; // [esp+188h] [ebp-1Ch]
  OptimizedModel::BodyPartHeader_t *bodyPart; // [esp+18Ch] [ebp-18h]
  int bodyPartID; // [esp+190h] [ebp-14h]
  OptimizedModel::FileHeader_t *header; // [esp+194h] [ebp-10h]
  Vector color; // [esp+198h] [ebp-Ch] BYREF

  OptimizedModel::RandomColor(&color);
  header = (OptimizedModel::FileHeader_t *)this->m_FileBuffer->m_pData;
  for ( bodyPartID = 0; bodyPartID < header->numBodyParts; ++bodyPartID )
  {
    bodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)header + 8 * bodyPartID + header->bodyPartOffset);
    pStudioBodyPart = (mstudiobodyparts_t *)((char *)phdr + 16 * bodyPartID + phdr->bodypartindex);
    for ( modelID = 0; modelID < bodyPart->numModels; ++modelID )
    {
      model = (OptimizedModel::ModelHeader_t *)((char *)&bodyPart[modelID] + bodyPart->modelOffset);
      pStudioModel = (mstudiomodel_t *)((char *)pStudioBodyPart + 148 * modelID + pStudioBodyPart->modelindex);
      for ( lodID = 0; lodID < model->numLODs; ++lodID )
      {
        sprintf(string: tmp, format: "%s.lod%d", pFileName, lodID);
        printf(format: "writing %s\n", tmp);
        v5 = CP4Factory::AccessFile(this: g_p4factory, szFilename: tmp);
        CPlainAutoPtr<CP4File>::CPlainAutoPtr<CP4File>(this: &spFile, p: v5);
        v7 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&spFile);
        (*(void (__thiscall **)(char *))(*(_DWORD *)v7 + 4))(a1: v7);
        fp = fopen(file: tmp, mode: "w");
        if ( fp == nullptr )
        {
          printf(format: "can't write glview file %s\n", tmp);
          CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: &spFile);
          return;
        }
        pLOD = (OptimizedModel::ModelLODHeader_t *)((char *)model + 12 * lodID + model->lodOffset);
        for ( meshID = 0; meshID < pLOD->numMeshes; ++meshID )
        {
          mesh = (OptimizedModel::MeshHeader_t *)((char *)pLOD + 9 * meshID + pLOD->meshOffset);
          pStudioMesh = (mstudiomesh_t *)((char *)pStudioModel + 116 * meshID + pStudioModel->meshindex);
          if ( (flags & 1) != 0 )
            OptimizedModel::RandomColor(&color);
          if ( (flags & 0x40) != 0 )
            OptimizedModel::COptimizedModel::SetMeshPropsColor(this, meshFlags: mesh->flags, &color);
          for ( stripGroupID = 0; stripGroupID < mesh->numStripGroups; ++stripGroupID )
          {
            if ( (flags & 2) != 0 )
              OptimizedModel::RandomColor(&color);
            pStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)mesh
                                                               + 33 * stripGroupID
                                                               + mesh->stripGroupHeaderOffset);
            OptimizedModel::COptimizedModel::SetFlexedAndSkinColor(
              this,
              glViewFlags: flags,
              stripGroupFlags: pStripGroup->flags,
              &color);
            for ( stripID = 0; stripID < pStripGroup->numStrips; ++stripID )
            {
              pStrip = (OptimizedModel::StripHeader_t *)((char *)pStripGroup + 35 * stripID + pStripGroup->stripOffset);
              if ( (flags & 4) != 0 )
                OptimizedModel::RandomColor(&color);
              if ( (flags & 0x100) != 0 )
              {
                switch ( pStrip->numBones )
                {
                  case 0:
                  case 1:
                    color.x = 0.0;
                    color.y = 0.0;
                    color.z = 255.0;
                    break;
                  case 2:
                    color.x = 0.0;
                    color.y = 255.0;
                    color.z = 0.0;
                    break;
                  case 3:
                    color.x = 255.0;
                    color.y = 255.0;
                    color.z = 0.0;
                    break;
                  case 4:
                    color.x = 255.0;
                    color.y = 0.0;
                    color.z = 0.0;
                    break;
                  default:
                    break;
                }
              }
              OptimizedModel::COptimizedModel::GLViewDrawBegin(this, mode: 0);
              for ( indexID = 0; indexID < pStrip->numIndices; ++indexID )
              {
                id = *(unsigned __int16 *)((char *)&pStripGroup->numVerts
                                         + 2 * pStrip->indexOffset
                                         + 2 * indexID
                                         + pStripGroup->indexOffset);
                vert = (OptimizedModel::Vertex_t *)((char *)pStripGroup + 9 * id + pStripGroup->vertOffset);
                if ( (flags & 0x80) != 0 )
                {
                  switch ( vert->numBones )
                  {
                    case 0u:
                    case 1u:
                      color.x = 0.0;
                      color.y = 0.0;
                      color.z = 255.0;
                      break;
                    case 2u:
                      color.x = 0.0;
                      color.y = 255.0;
                      color.z = 0.0;
                      break;
                    case 3u:
                      color.x = 255.0;
                      color.y = 255.0;
                      color.z = 0.0;
                      break;
                    case 4u:
                      color.x = 255.0;
                      color.y = 0.0;
                      color.z = 0.0;
                      break;
                    default:
                      break;
                  }
                }
                OptimizedModel::COptimizedModel::GLViewVert(
                  this,
                  fp,
                  vert: *vert,
                  index: id,
                  &color,
                  pStudioModel,
                  pStudioMesh,
                  showSubStrips: (flags & 8) != 0,
                  shrinkFactor);
              }
              OptimizedModel::COptimizedModel::GLViewDrawEnd(this);
            }
          }
        }
        fclose(stream: fp);
        v6 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&spFile);
        (*(void (__thiscall **)(char *, char *))(*(_DWORD *)v6 + 8))(a1: v6, a2: v6);
        CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: &spFile);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004201A0
// Name: private: void OptimizedModel::COptimizedModel::WriteGLViewFiles(struct studiohdr_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteGLViewFiles(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        const char *glViewFileName)
{
  char v3; // cl
  char v4; // dl
  char v5; // cl
  char v6; // al
  char v7; // dl
  char v8; // al
  char v9; // al
  char v10; // al
  char v11; // al
  char v12; // al
  char v13; // [esp+Bh] [ebp-171h]
  char *v14; // [esp+Ch] [ebp-170h]
  char *v15; // [esp+18h] [ebp-164h]
  const char *v16; // [esp+1Ch] [ebp-160h]
  char v17; // [esp+23h] [ebp-159h]
  char *v18; // [esp+24h] [ebp-158h]
  char *v19; // [esp+30h] [ebp-14Ch]
  const char *v20; // [esp+34h] [ebp-148h]
  char v21; // [esp+3Bh] [ebp-141h]
  char *v22; // [esp+3Ch] [ebp-140h]
  char *v23; // [esp+48h] [ebp-134h]
  const char *v24; // [esp+4Ch] [ebp-130h]
  char v25; // [esp+53h] [ebp-129h]
  char *v26; // [esp+54h] [ebp-128h]
  char *v27; // [esp+60h] [ebp-11Ch]
  const char *v28; // [esp+64h] [ebp-118h]
  char v29; // [esp+6Bh] [ebp-111h]
  char *v30; // [esp+6Ch] [ebp-110h]
  char *v31; // [esp+78h] [ebp-104h]
  const char *v32; // [esp+7Ch] [ebp-100h]
  char v33; // [esp+83h] [ebp-F9h]
  char *v34; // [esp+84h] [ebp-F8h]
  char *v35; // [esp+90h] [ebp-ECh]
  const char *v36; // [esp+94h] [ebp-E8h]
  char v37; // [esp+9Bh] [ebp-E1h]
  char *v38; // [esp+9Ch] [ebp-E0h]
  char *v39; // [esp+A8h] [ebp-D4h]
  const char *v40; // [esp+ACh] [ebp-D0h]
  char v41; // [esp+B3h] [ebp-C9h]
  char *v42; // [esp+B4h] [ebp-C8h]
  char *v43; // [esp+C0h] [ebp-BCh]
  const char *v44; // [esp+C4h] [ebp-B8h]
  char v45; // [esp+CBh] [ebp-B1h]
  _DWORD *v46; // [esp+CCh] [ebp-B0h]
  char *v47; // [esp+D8h] [ebp-A4h]
  const char *v48; // [esp+DCh] [ebp-A0h]
  char v49; // [esp+E3h] [ebp-99h]
  char *v50; // [esp+E4h] [ebp-98h]
  char *v51; // [esp+F0h] [ebp-8Ch]
  const char *v52; // [esp+F4h] [ebp-88h]
  OptimizedModel::COptimizedModel *thisa; // [esp+F8h] [ebp-84h] BYREF
  char tmpFileName[128]; // [esp+FCh] [ebp-80h] BYREF

  thisa = this;
  if ( g_bDumpGLViewFiles )
  {
    v52 = glViewFileName;
    v51 = tmpFileName;
    do
    {
      v3 = *v52;
      *v51++ = *v52++;
    }
    while ( v3 != 0 );
    v50 = (char *)&thisa + 3;
    do
      v49 = *++v50;
    while ( v49 != 0 );
    strcpy(v50, ".mesh");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 1,
      shrinkFactor: 0.80000001);
    v48 = glViewFileName;
    v47 = tmpFileName;
    do
    {
      v4 = *v48;
      *v47++ = *v48++;
    }
    while ( v4 != 0 );
    v46 = (OptimizedModel::COptimizedModel **)((char *)&thisa + 3);
    do
    {
      v45 = *((_BYTE *)v46 + 1);
      v46 = (_DWORD *)((char *)v46 + 1);
    }
    while ( v45 != 0 );
    *v46 = *(_DWORD *)aStr_0;
    v46[1] = 1919381609;
    v46[2] = &unk_70756F;
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 2,
      shrinkFactor: 0.80000001);
    v44 = glViewFileName;
    v43 = tmpFileName;
    do
    {
      v5 = *v44;
      *v43++ = *v44++;
    }
    while ( v5 != 0 );
    v42 = (char *)&thisa + 3;
    do
      v41 = *++v42;
    while ( v41 != 0 );
    strcpy(v42, ".strip");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 4,
      shrinkFactor: 0.80000001);
    v40 = glViewFileName;
    v39 = tmpFileName;
    do
    {
      v6 = *v40;
      *v39++ = *v40++;
    }
    while ( v6 != 0 );
    v38 = (char *)&thisa + 3;
    do
      v37 = *++v38;
    while ( v37 != 0 );
    strcpy(v38, ".substrip");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 8,
      shrinkFactor: 0.97000003);
    v36 = glViewFileName;
    v35 = tmpFileName;
    do
    {
      v7 = *v36;
      *v35++ = *v36++;
    }
    while ( v7 != 0 );
    v34 = (char *)&thisa + 3;
    do
      v33 = *++v34;
    while ( v33 != 0 );
    strcpy(v34, ".flexed");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 16,
      shrinkFactor: 0.80000001);
    v32 = glViewFileName;
    v31 = tmpFileName;
    do
    {
      v8 = *v32;
      *v31++ = *v32++;
    }
    while ( v8 != 0 );
    v30 = (char *)&thisa + 3;
    do
      v29 = *++v30;
    while ( v29 != 0 );
    strcpy(v30, ".sw");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 32,
      shrinkFactor: 0.80000001);
    v28 = glViewFileName;
    v27 = tmpFileName;
    do
    {
      v9 = *v28;
      *v27++ = *v28++;
    }
    while ( v9 != 0 );
    v26 = (char *)&thisa + 3;
    do
      v25 = *++v26;
    while ( v25 != 0 );
    strcpy(v26, ".flexedandsw");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 48,
      shrinkFactor: 0.80000001);
    v24 = glViewFileName;
    v23 = tmpFileName;
    do
    {
      v10 = *v24;
      *v23++ = *v24++;
    }
    while ( v10 != 0 );
    v22 = (char *)&thisa + 3;
    do
      v21 = *++v22;
    while ( v21 != 0 );
    strcpy(v22, ".meshprops");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 64,
      shrinkFactor: 0.80000001);
    v20 = glViewFileName;
    v19 = tmpFileName;
    do
    {
      v11 = *v20;
      *v19++ = *v20++;
    }
    while ( v11 != 0 );
    v18 = (char *)&thisa + 3;
    do
      v17 = *++v18;
    while ( v17 != 0 );
    strcpy(v18, ".vertnumbones");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 128,
      shrinkFactor: 1.0);
    v16 = glViewFileName;
    v15 = tmpFileName;
    do
    {
      v12 = *v16;
      *v15++ = *v16++;
    }
    while ( v12 != 0 );
    v14 = (char *)&thisa + 3;
    do
      v13 = *++v14;
    while ( v13 != 0 );
    strcpy(v14, ".stripnumbones");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 256,
      shrinkFactor: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420C20
// Name: public: unsigned int CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::Find(struct OptimizedModel::StripVertLookup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Find(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        unsigned int src)
{
  int ndxKeyData; // [esp+0h] [ebp-4h] BYREF

  ndxKeyData = 0;
  if ( CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::DoFind(
         this,
         (const OptimizedModel::StripVertLookup_t *)src,
         pBucket: &src,
         pIndex: &ndxKeyData) != 0 )
    return ndxKeyData | (src << 16);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00420C60
// Name: public: int CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::Alloc(bool)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Alloc(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        bool multilist)
{
  void *result; // eax
  void *v3; // esi

  result = (void *)CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal(
                     this,
                     multilist);
  v3 = result;
  if ( result != nullptr )
  {
    operator new(__formal: 0xCu, _Where: result);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420F10
// Name: public: void CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::RemoveAll(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)((char *)m_pBlockHeader + 20 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[1] + 20 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t **)&m_pBlockHeader[2].m_nBlockSize
               + 5 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex)
            && *(&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[2].m_nBlockSize + 5 * m_nIndex) = (int)m_pBlockHeader + 20 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 20 * m_nIndex;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
      {
        break;
      }
    }
    v1[1].m_pBlocks = nullptr;
    v1[1].m_nAllocationCount = 0;
    v1[2].m_pBlocks = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421150
// Name: public: OptimizedModel::Strip_t::Strip_t(void)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Strip_t *__thiscall OptimizedModel::Strip_t::Strip_t(OptimizedModel::Strip_t *this)
{
  CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>(
    this: &this->verts,
    growSize: 0,
    initSize: 0);
  this->numTopologyIndices = 0;
  this->numIndices = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004211E0
// Name: public: CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::~CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::~CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-Ch]

  CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421210
// Name: public: void CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Free(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 12);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v4 = *(_DWORD *)(elem + 16);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x00421280
// Name: public: void CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::LinkBefore(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 12);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v5 = *(_DWORD *)(elem + 16);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 12);
    *(_DWORD *)(before + 12) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 12) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 16) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421480
// Name: private: void OptimizedModel::COptimizedModel::BuildStripsRecursive(class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> __near &,class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,struct OptimizedModel::Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildStripsRecursive(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *indices,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faceList,
        OptimizedModel::Face_t *face)
{
  OptimizedModel::Face_t *v4; // eax
  OptimizedModel::Face_t *v5; // eax
  OptimizedModel::Face_t *v6; // eax
  OptimizedModel::Face_t *v7; // eax
  unsigned __int16 v9; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int16 v10; // [esp+Eh] [ebp-6h] BYREF
  unsigned __int16 v11; // [esp+10h] [ebp-4h] BYREF
  unsigned __int16 src; // [esp+12h] [ebp-2h] BYREF

  if ( !face->touched && OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(this, face) == 0 )
  {
    face->touched = true;
    src = face->vertID[0];
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: indices, &src);
    v11 = face->vertID[1];
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: indices, src: &v11);
    v10 = face->vertID[2];
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: indices, src: &v10);
    if ( face->vertID[3] != -1 )
    {
      v9 = face->vertID[3];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: indices, src: &v9);
    }
    if ( face->neighborID[0] != -1 )
    {
      v4 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: faceList,
             i: face->neighborID[0]);
      OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices, faceList, face: v4);
    }
    if ( face->neighborID[1] != -1 )
    {
      v5 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: faceList,
             i: face->neighborID[1]);
      OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices, faceList, face: v5);
    }
    if ( face->neighborID[2] != -1 )
    {
      v6 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: faceList,
             i: face->neighborID[2]);
      OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices, faceList, face: v6);
    }
    if ( face->neighborID[3] != -1 )
    {
      v7 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: faceList,
             i: face->neighborID[3]);
      OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices, faceList, face: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004215D0
// Name: OptimizedModel::FindMatchingEdge
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::FindMatchingEdge(
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *list,
        int nFaceId,
        int nEdgeIndex,
        const int *pVertIds,
        CUtlVector<int,CUtlMemory<int,int> > *vertexToEdges,
        CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t> *edges)
{
  ConVar *v6; // ecx
  int v7; // esi
  OptimizedModel::EdgeInfo_t *v8; // eax
  OptimizedModel::EdgeInfo_t *edge; // [esp+4h] [ebp-24h]
  int hEdge; // [esp+8h] [ebp-20h]
  OptimizedModel::Face_t *face; // [esp+Ch] [ebp-1Ch]
  int hFirstEdge; // [esp+10h] [ebp-18h]
  int nVertIndex; // [esp+14h] [ebp-14h]
  int nConnectedVertId; // [esp+1Ch] [ebp-Ch]
  void *hNewEdge; // [esp+20h] [ebp-8h]

  face = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: list, i: nFaceId);
  nVertIndex = pVertIds[*pVertIds >= pVertIds[1]];
  nConnectedVertId = pVertIds[*pVertIds < pVertIds[1]];
  hFirstEdge = *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: vertexToEdges, i: nVertIndex);
  v6 = (ConVar *)hFirstEdge;
  for ( hEdge = hFirstEdge;
        ;
        hEdge = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Next(
                  this: edges,
                  i: hEdge) )
  {
    if ( hEdge == CImportTex::GetCurrentVersion(this: v6) )
    {
      hNewEdge = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Alloc(
                   this: edges,
                   multilist: true);
      v8 = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::operator[](
             this: edges,
             i: (int)hNewEdge);
      v8->m_nConnectedVertId = nConnectedVertId;
      v8->m_nEdgeIndex = nEdgeIndex;
      v8->m_nFaceId = nFaceId;
      CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::LinkBefore(
        this: edges,
        before: hFirstEdge,
        elem: (int)hNewEdge);
      *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: vertexToEdges, i: nVertIndex) = (int)hNewEdge;
      return;
    }
    edge = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::operator[](
             this: edges,
             i: hEdge);
    if ( edge->m_nConnectedVertId == nConnectedVertId && edge->m_nFaceId != nFaceId )
      break;
  }
  face->neighborID[nEdgeIndex] = edge->m_nFaceId;
  CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: list, i: edge->m_nFaceId)->neighborID[edge->m_nEdgeIndex] = nFaceId;
  if ( hEdge == hFirstEdge )
  {
    v7 = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Next(
           this: edges,
           i: hFirstEdge);
    *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: vertexToEdges, i: nVertIndex) = v7;
  }
  CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Free(
    this: edges,
    elem: hEdge);
}

//------------------------------------------------------------------------------
// Address: 0x00421740
// Name: private: void OptimizedModel::COptimizedModel::BuildSubDFaceList(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::SubD_Face_t,class CUtlMemory<struct OptimizedModel::SubD_Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> __near &,struct mstudio_meshvertexdata_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildSubDFaceList(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *faceList,
        CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *subDFaceList,
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vtxList,
        const mstudio_meshvertexdata_t *pVertexData)
{
  OptimizedModel::Face_t *v5; // esi
  int j; // [esp+8h] [ebp-30h]
  int i; // [esp+Ch] [ebp-2Ch]
  OptimizedModel::COptimizeSubDBuilder subDBuilder; // [esp+10h] [ebp-28h] BYREF
  int nFaceCount; // [esp+34h] [ebp-4h]

  nFaceCount = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: faceList);
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::RemoveAll(this: subDFaceList);
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::EnsureCapacity(
    this: subDFaceList,
    num: nFaceCount);
  for ( i = 0; i < nFaceCount; ++i )
  {
    CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::AddToTail(this: subDFaceList);
    for ( j = 0; j < 4; ++j )
    {
      v5 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *)faceList,
             i);
      CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::operator[](
        this: subDFaceList,
        i)->vtxIDs[j] = v5->vertID[j];
    }
  }
  OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(
    this: &subDBuilder,
    subDFaceList,
    vertexList: vtxList,
    vertexData: &pVertexData,
    bIsTagged: false,
    bMendVertices: true);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&subDBuilder.m_IndexRemapTable);
}

//------------------------------------------------------------------------------
// Address: 0x00421800
// Name: private: void OptimizedModel::COptimizedModel::SourceMeshToFaceList(struct s_model_t __near *,struct s_mesh_t __near *,class CUtlVector<struct mstudioiface_t,class CUtlMemory<struct mstudioiface_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SourceMeshToFaceList(
        OptimizedModel::COptimizedModel *this,
        s_model_t *pSrcModel,
        s_mesh_t *pSrcMesh,
        CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int> > *meshFaceList)
{
  int j; // [esp+4h] [ebp-14h]
  mstudioiface_t *newFace; // [esp+8h] [ebp-10h]
  const s_face_t *pFace; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  s_face_t *pFaces; // [esp+14h] [ebp-4h]

  pFaces = &pSrcModel->source->face[pSrcMesh->faceoffset];
  for ( i = 0; i < pSrcMesh->numfaces; ++i )
  {
    pFace = &pFaces[i];
    j = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::AddToTail(this: meshFaceList);
    newFace = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::operator[](this: meshFaceList, i: j);
    newFace->a = pFace->a;
    newFace->b = pFace->b;
    newFace->c = pFace->c;
    newFace->d = pFace->d;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004218B0
// Name: private: void OptimizedModel::COptimizedModel::CreateLODFaceList(struct s_model_t __near *,int,struct s_source_t __near *,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,class CUtlVector<struct mstudioiface_t,class CUtlMemory<struct mstudioiface_t,int>> __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::CreateLODFaceList(
        OptimizedModel::COptimizedModel *this,
        s_model_t *pSrcModel,
        int nLodID,
        s_source_t *pSrc,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int> > *meshFaceList,
        bool bQuadSubd,
        bool writeDebug)
{
  int v9; // esi
  int *v10; // edi
  int v11; // [esp+8h] [ebp-3Ch]
  mstudioiface_t *newFace; // [esp+18h] [ebp-2Ch]
  const s_face_t *srcFace; // [esp+1Ch] [ebp-28h]
  int index; // [esp+20h] [ebp-24h]
  s_mesh_t *pSrcMesh; // [esp+24h] [ebp-20h]
  int textureSearchID; // [esp+28h] [ebp-1Ch]
  int i; // [esp+2Ch] [ebp-18h]
  int ia; // [esp+2Ch] [ebp-18h]
  int ib; // [esp+2Ch] [ebp-18h]
  CUtlVector<int,CUtlMemory<int,int> > indexMapping; // [esp+30h] [ebp-14h] BYREF

  if ( pSrc != nullptr && pSrcModel != nullptr )
  {
    textureSearchID = MaterialToTexture(material: pStudioMesh->material);
    pSrcMesh = nullptr;
    for ( i = 0; i < pStudioModel->nummeshes; ++i )
    {
      if ( pSrc->texmap[pSrc->meshindex[i]] == textureSearchID )
      {
        pSrcMesh = &pSrc->mesh[pSrc->meshindex[i]];
        break;
      }
    }
    if ( pSrcMesh != nullptr )
    {
      CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>(
        this: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&indexMapping,
        growSize: 0,
        initSize: 0);
      CUtlVector<int,CUtlMemory<int,int>>::AddMultipleToTail(this: &indexMapping, num: pSrcMesh->numvertices);
      for ( ia = 0; ia < pSrcMesh->numvertices; ++ia )
      {
        v9 = ia + pSrcMesh->vertexoffset;
        v10 = pSrcModel->m_pLodData->pMeshVertIndexMaps[nLodID];
        *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: ia) = v10[v9];
      }
      for ( ib = 0; ib < pSrcMesh->numfaces; ++ib )
      {
        index = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::AddToTail(this: meshFaceList);
        newFace = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::operator[](this: meshFaceList, i: index);
        srcFace = &pSrc->face[ib + pSrcMesh->faceoffset];
        newFace->a = *(_WORD *)CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: srcFace->a);
        newFace->b = *(_WORD *)CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: srcFace->b);
        newFace->c = *(_WORD *)CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: srcFace->c);
        if ( bQuadSubd )
          v11 = *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: srcFace->d);
        else
          LOWORD(v11) = -1;
        newFace->d = v11;
      }
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&indexMapping);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421A90
// Name: public: CUtlFixedLinkedList<struct OptimizedModel::EdgeInfo_t>::CUtlFixedLinkedList<struct OptimizedModel::EdgeInfo_t>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t> *__thiscall CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t>::CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t>(
        CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t> *this,
        int growSize,
        int initSize)
{
  this->m_Memory.m_pBlocks = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = growSize;
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::Grow(this: &this->m_Memory, num: initSize);
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
  this->m_Head = 0;
  this->m_Tail = 0;
  this->m_FirstFree = 0;
  this->m_ElementCount = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00421AF0
// Name: public: unsigned int CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::Insert(struct OptimizedModel::StripVertLookup_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Insert(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        unsigned int src)
{
  const OptimizedModel::StripVertLookup_t *v2; // ebx
  unsigned int v5; // esi
  int ndxKeyData; // [esp+8h] [ebp-4h] BYREF

  v2 = (const OptimizedModel::StripVertLookup_t *)src;
  ndxKeyData = 0;
  if ( CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::DoFind(
         this,
         (const OptimizedModel::StripVertLookup_t *)src,
         pBucket: &src,
         pIndex: &ndxKeyData) != 0 )
    return ndxKeyData | (src << 16);
  v5 = src;
  return (v5 << 16)
       | CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int>>::InsertBefore(
           this: &this->m_Buckets.m_Memory.m_pMemory[src],
           elem: this->m_Buckets.m_Memory.m_pMemory[src].m_Size,
           src: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00421BD0
// Name: public: void OptimizedModel::CStringTable::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::CStringTable::AddString(OptimizedModel::CStringTable *this, const char *newString)
{
  int v2; // eax
  char v3; // dl
  char *v4; // [esp+8h] [ebp-30h]
  const char *v5; // [esp+Ch] [ebp-2Ch]
  CUtlVector<char,CUtlMemory<char,int> > *s; // [esp+34h] [ebp-4h]

  if ( OptimizedModel::CStringTable::StringPresent(this, string: newString) == 0 )
  {
    v2 = CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::AddToTail((CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this);
    s = (CUtlVector<char,CUtlMemory<char,int> > *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                                                    (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                                                    i: v2);
    CUtlVector<char,CUtlMemory<char,int>>::AddMultipleToTail(this: s, num: strlen(newString) + 1);
    v5 = newString;
    v4 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: s);
    do
    {
      v3 = *v5;
      *v4++ = *v5++;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421C90
// Name: OptimizedModel::FindOrCreateVertex
// Source: json
//------------------------------------------------------------------------------
int __cdecl OptimizedModel::FindOrCreateVertex(
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *list,
        const OptimizedModel::Vertex_t *vert)
{
  CDmeClip *v2; // ecx
  int v4; // [esp+5Ch] [ebp-10h]
  int vertexHandle; // [esp+60h] [ebp-Ch]
  OptimizedModel::StripVertLookup_t stripVertLookup; // [esp+64h] [ebp-8h] BYREF

  stripVertLookup.origMeshVertID = vert->origMeshVertID;
  stripVertLookup.vertID = -1;
  vertexHandle = CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Find(
                   this: &OptimizedModel::g_StripGroupVertexLookup,
                   src: (unsigned int)&stripVertLookup);
  if ( vertexHandle != CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::InvalidHandle(this: v2) )
    return CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Element(
             this: &OptimizedModel::g_StripGroupVertexLookup,
             handle: vertexHandle)->vertID;
  v4 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(this: list, src: vert);
  stripVertLookup.vertID = v4;
  CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Insert(
    this: &OptimizedModel::g_StripGroupVertexLookup,
    src: (unsigned int)&stripVertLookup);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00421D10
// Name: private: void OptimizedModel::COptimizedModel::BuildNeighborInfo(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildNeighborInfo(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faceList,
        int nMaxVertexId)
{
  unsigned __int8 *v3; // eax
  OptimizedModel::Face_t *face; // [esp+4h] [ebp-58h]
  int i; // [esp+8h] [ebp-54h]
  CUtlVector<int,CUtlMemory<int,int> > vertexToEdges; // [esp+Ch] [ebp-50h] BYREF
  int numVerts; // [esp+20h] [ebp-3Ch]
  int pEdgeVertIds[2]; // [esp+24h] [ebp-38h] BYREF
  CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t> edges; // [esp+2Ch] [ebp-30h] BYREF
  int nFaceCount; // [esp+58h] [ebp-4h]

  CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t>::CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t>(
    this: &edges,
    growSize: 0,
    initSize: 0);
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>(
    this: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&vertexToEdges,
    growSize: 0,
    initSize: 0);
  CUtlVector<int,CUtlMemory<int,int>>::SetCount(this: &vertexToEdges, count: nMaxVertexId);
  v3 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&vertexToEdges);
  memset(dst: v3, value: 0, count: 4 * nMaxVertexId);
  numVerts = (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                this: faceList,
                i: 0)->vertID[3] != -1)
           + 3;
  nFaceCount = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faceList);
  CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::EnsureCapacity(
    this: &edges,
    num: 2 * nFaceCount);
  for ( i = 0; i < nFaceCount; ++i )
  {
    face = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faceList, i);
    *(_QWORD *)pEdgeVertIds = *(_QWORD *)face->vertID;
    OptimizedModel::FindMatchingEdge(
      list: faceList,
      nFaceId: i,
      nEdgeIndex: 0,
      pVertIds: pEdgeVertIds,
      &vertexToEdges,
      &edges);
    *(_QWORD *)pEdgeVertIds = *(_QWORD *)&face->vertID[1];
    OptimizedModel::FindMatchingEdge(
      list: faceList,
      nFaceId: i,
      nEdgeIndex: 1,
      pVertIds: pEdgeVertIds,
      &vertexToEdges,
      &edges);
    if ( numVerts == 3 )
    {
      pEdgeVertIds[0] = face->vertID[2];
      pEdgeVertIds[1] = face->vertID[0];
      OptimizedModel::FindMatchingEdge(
        list: faceList,
        nFaceId: i,
        nEdgeIndex: 2,
        pVertIds: pEdgeVertIds,
        &vertexToEdges,
        &edges);
    }
    else
    {
      *(_QWORD *)pEdgeVertIds = *(_QWORD *)&face->vertID[2];
      OptimizedModel::FindMatchingEdge(
        list: faceList,
        nFaceId: i,
        nEdgeIndex: 2,
        pVertIds: pEdgeVertIds,
        &vertexToEdges,
        &edges);
      pEdgeVertIds[0] = face->vertID[3];
      pEdgeVertIds[1] = face->vertID[0];
      OptimizedModel::FindMatchingEdge(
        list: faceList,
        nFaceId: i,
        nEdgeIndex: 3,
        pVertIds: pEdgeVertIds,
        &vertexToEdges,
        &edges);
    }
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vertexToEdges);
  CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::~CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>(this: &edges);
}

//------------------------------------------------------------------------------
// Address: 0x00421ED0
// Name: private: void OptimizedModel::COptimizedModel::PostProcessStripGroup(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::PostProcessStripGroup(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        ConCommandBase *pStripGroup)
{
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  CDmeClip *v10; // ecx
  DmeClipType_t v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  int v15; // eax
  bool v16; // [esp+0h] [ebp-8Ch]
  unsigned __int16 v18; // [esp+46h] [ebp-46h] BYREF
  int m; // [esp+48h] [ebp-44h]
  int newIndex; // [esp+4Ch] [ebp-40h]
  unsigned int vertexHandle; // [esp+50h] [ebp-3Ch]
  OptimizedModel::StripVertLookup_t src; // [esp+54h] [ebp-38h] BYREF
  int index; // [esp+5Ch] [ebp-30h]
  OptimizedModel::Vertex_t *pVert; // [esp+60h] [ebp-2Ch]
  int j; // [esp+64h] [ebp-28h]
  OptimizedModel::StripVertLookup_t stripVertLookup; // [esp+68h] [ebp-24h] BYREF
  int k; // [esp+70h] [ebp-1Ch]
  OptimizedModel::Strip_t *pStrip; // [esp+74h] [ebp-18h]
  int vertOffset; // [esp+78h] [ebp-14h]
  bool bSubDQuad; // [esp+7Fh] [ebp-Dh]
  int nSearch; // [esp+80h] [ebp-Ch]
  int maxNumBones; // [esp+84h] [ebp-8h]
  int i; // [esp+88h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v4 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 60));
    if ( i >= (int)v4 )
      break;
    pStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
               this: (CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int> > *)&pStripGroup[2].m_pszName,
               i);
    vertOffset = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 40));
    pStrip->stripGroupVertexOffset = vertOffset;
    v5 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
    pStrip->stripGroupIndexOffset = (int)v5;
    v6 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->m_nFlags);
    pStrip->stripGroupTopologyOffset = (int)v6;
    v7 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
      this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)pStripGroup,
      num: (int)&v7[pStrip->numIndices]);
    v8 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->m_nFlags);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
      this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&pStripGroup->m_nFlags,
      num: (int)&v8[pStrip->numTopologyIndices]);
    maxNumBones = 0;
    v16 = (pStrip->flags & 4) != 0 || (pStrip->flags & 2) != 0;
    bSubDQuad = v16;
    nSearch = vertOffset;
    if ( v16 )
    {
      pStrip->stripGroupVertexOffset = 0;
      nSearch = 0;
    }
    CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::RemoveAll(this: &OptimizedModel::g_StripGroupVertexLookup);
    for ( k = nSearch; ; ++k )
    {
      v9 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 40));
      if ( k >= (int)v9 )
        break;
      stripVertLookup.origMeshVertID = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
                                         this: (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)&pStripGroup[1].m_pszHelpString,
                                         i: k)->origMeshVertID;
      stripVertLookup.vertID = k;
      CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Insert(
        this: &OptimizedModel::g_StripGroupVertexLookup,
        src: (unsigned int)&stripVertLookup);
    }
    for ( j = 0; j < pStrip->numIndices; ++j )
    {
      newIndex = -1;
      index = pStrip->pIndices[j];
      pVert = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
                this: &pStrip->verts,
                i: index);
      src.origMeshVertID = pVert->origMeshVertID;
      src.vertID = -1;
      vertexHandle = CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Find(
                       this: &OptimizedModel::g_StripGroupVertexLookup,
                       (unsigned int)&src);
      v11 = CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::InvalidHandle(this: v10);
      if ( vertexHandle == v11 )
      {
        newIndex = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(
                     this: (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)&pStripGroup[1].m_pszHelpString,
                     src: pVert);
        src.vertID = newIndex;
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Insert(
          this: &OptimizedModel::g_StripGroupVertexLookup,
          (unsigned int)&src);
      }
      else
      {
        newIndex = CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Element(
                     this: &OptimizedModel::g_StripGroupVertexLookup,
                     handle: vertexHandle)->vertID;
      }
      v18 = newIndex;
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
        this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)pStripGroup,
        src: &v18);
      if ( pVert->numBones > maxNumBones )
        maxNumBones = pVert->numBones;
    }
    for ( m = 0; m < pStrip->numTopologyIndices; ++m )
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
        this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&pStripGroup->m_nFlags,
        src: &pStrip->pTopologyIndices[m]);
    v12 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
    pStrip->numStripGroupIndices = (int)&v12[-pStrip->stripGroupIndexOffset];
    v13 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->m_nFlags);
    pStrip->numStripGroupTopologyIndices = (int)&v13[-pStrip->stripGroupTopologyOffset];
    v14 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 40));
    pStrip->numStripGroupVerts = (int)&v14[-pStrip->stripGroupVertexOffset];
    if ( this->m_bUsesFixedFunction )
    {
      v15 = OptimizedModel::COptimizedModel::CountUniqueBonesInStrip(
              this,
              (OptimizedModel::StripGroup_t *)pStripGroup,
              pStrip);
      pStrip->numBones = v15;
    }
    else
    {
      pStrip->numBones = maxNumBones;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004221D0
// Name: OptimizedModel::AddMaterialReplacementsToStringTable
// Source: json
//------------------------------------------------------------------------------
const char *OptimizedModel::AddMaterialReplacementsToStringTable()
{
  const char *result; // eax
  const char *newString; // [esp+14h] [ebp-18h]
  LodScriptData_t *scriptLOD; // [esp+1Ch] [ebp-10h]
  int j; // [esp+20h] [ebp-Ch]
  int numLODs; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  result = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  numLODs = (int)result;
  for ( i = 0; i < numLODs; ++i )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i);
    for ( j = 0;
          j < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->materialReplacements);
          ++j )
    {
      newString = CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::operator[](
                    this: &scriptLOD->materialReplacements,
                    i: j)->m_pDstName;
      OptimizedModel::CStringTable::AddString(this: &s_StringTable, newString);
    }
    result = (const char *)(i + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422320
// Name: private: void OptimizedModel::COptimizedModel::BuildHWSkinnedStrips(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> __near &,struct OptimizedModel::StripGroup_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildHWSkinnedStrips(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faceList,
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vertices,
        OptimizedModel::StripGroup_t *pStripGroup,
        int maxBonesPerStrip)
{
  const char *v5; // eax
  const char *v6; // eax
  const OptimizedModel::Vertex_t *v7; // eax
  int v8; // eax
  int v9; // eax
  int NthBoneGlobalID; // eax
  ConCommandBase sourceTopologyIndices; // [esp+4h] [ebp-40h] BYREF
  int i; // [esp+1Ch] [ebp-28h]
  int stripIdx; // [esp+20h] [ebp-24h]
  OptimizedModel::Strip_t *newStrip; // [esp+24h] [ebp-20h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > facesToStrip; // [esp+28h] [ebp-1Ch] BYREF
  OptimizedModel::Face_t *pSeedFace; // [esp+3Ch] [ebp-8h]
  int numVerts; // [esp+40h] [ebp-4h]

  CHardwareMatrixState::Init(this: &this->m_HardwareMatrixState, numHardwareMatrices: maxBonesPerStrip);
  numVerts = (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                this: faceList,
                i: 0)->vertID[3] != -1)
           + 3;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
    this: &facesToStrip,
    growSize: 0,
    initSize: 0);
  v5 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faceList);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
    this: &facesToStrip,
    num: numVerts * (_DWORD)v5);
  pSeedFace = OptimizedModel::GetNextUntouched(faces: faceList);
  while ( pSeedFace != nullptr )
  {
    OptimizedModel::COptimizedModel::AllocateHardwareBonesForFace(this, face: pSeedFace);
    OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices: &facesToStrip, faceList, face: pSeedFace);
    pSeedFace = OptimizedModel::COptimizedModel::GetNextFace(this, faceList, allowNewStrip: false);
    if ( pSeedFace == nullptr )
    {
      stripIdx = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::AddToTail(this: &pStripGroup->strips);
      newStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                   this: &pStripGroup->strips,
                   i: stripIdx);
      newStrip->flags = numVerts != 3 ? 4 : 1;
      OptimizedModel::COptimizedModel::SanityCheckVertBones(this, list: &facesToStrip, vertices);
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
        this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&sourceTopologyIndices,
        growSize: 0,
        initSize: 0);
      OptimizedModel::COptimizedModel::Stripify(
        this,
        sourceIndices: (ConCommandBase *)&facesToStrip,
        &sourceTopologyIndices,
        bIsHWSkinned: true,
        pNumIndices: (unsigned int *)&newStrip->numIndices,
        pNumTopologyIndices: nullptr,
        ppIndices: &newStrip->pIndices,
        ppTopologyIndices: nullptr,
        bQuadSubd: numVerts == 4);
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sourceTopologyIndices);
      for ( i = 0; ; ++i )
      {
        v6 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)vertices);
        if ( i >= (int)v6 )
          break;
        v7 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
               this: vertices,
               i);
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(
          this: &newStrip->verts,
          src: v7);
      }
      v8 = CHardwareMatrixState::AllocatedMatrixCount(this: &this->m_HardwareMatrixState);
      newStrip->numBoneStateChanges = v8;
      for ( sourceTopologyIndices.m_nFlags = 0; ; ++sourceTopologyIndices.m_nFlags )
      {
        v9 = CHardwareMatrixState::AllocatedMatrixCount(this: &this->m_HardwareMatrixState);
        if ( sourceTopologyIndices.m_nFlags >= v9 )
          break;
        newStrip->boneStateChanges[sourceTopologyIndices.m_nFlags].hardwareID = sourceTopologyIndices.m_nFlags;
        NthBoneGlobalID = CHardwareMatrixState::GetNthBoneGlobalID(
                            this: &this->m_HardwareMatrixState,
                            n: sourceTopologyIndices.m_nFlags);
        newStrip->boneStateChanges[sourceTopologyIndices.m_nFlags].newBoneID = NthBoneGlobalID;
      }
      CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::RemoveAll(this: (CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *)&facesToStrip);
      pSeedFace = OptimizedModel::COptimizedModel::GetNextFace(this, faceList, allowNewStrip: true);
    }
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&facesToStrip);
}

//------------------------------------------------------------------------------
// Address: 0x00422510
// Name: private: void OptimizedModel::COptimizedModel::BuildSWSkinnedStrips(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::SubD_Face_t,class CUtlMemory<struct OptimizedModel::SubD_Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> const __near &,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildSWSkinnedStrips(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *faceList,
        ConCommandBase *subdFaceList,
        ConCommandBase *vertices,
        OptimizedModel::StripGroup_t *pStripGroup)
{
  const char *v5; // eax
  const OptimizedModel::Vertex_t *v6; // eax
  const char *v7; // eax
  const OptimizedModel::Vertex_t *v8; // eax
  unsigned __int16 v10; // [esp+Ah] [ebp-76h] BYREF
  unsigned __int16 v11; // [esp+Ch] [ebp-74h] BYREF
  unsigned __int16 v12; // [esp+Eh] [ebp-72h] BYREF
  unsigned __int16 v13; // [esp+10h] [ebp-70h] BYREF
  unsigned __int16 v14; // [esp+12h] [ebp-6Eh] BYREF
  unsigned __int16 v15; // [esp+14h] [ebp-6Ch] BYREF
  unsigned __int16 src; // [esp+16h] [ebp-6Ah] BYREF
  int k; // [esp+18h] [ebp-68h]
  int i; // [esp+1Ch] [ebp-64h]
  __int16 totalOneRingSize; // [esp+20h] [ebp-60h]
  int b; // [esp+24h] [ebp-5Ch]
  int v; // [esp+28h] [ebp-58h]
  int j; // [esp+2Ch] [ebp-54h]
  OptimizedModel::SubD_Face_t *subDFace; // [esp+30h] [ebp-50h]
  OptimizedModel::Face_t *face; // [esp+34h] [ebp-4Ch]
  int f; // [esp+38h] [ebp-48h]
  bool bSubDQuad; // [esp+3Fh] [ebp-41h]
  int stripIdx; // [esp+40h] [ebp-40h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > topologyIndices; // [esp+44h] [ebp-3Ch] BYREF
  OptimizedModel::Strip_t *pNewStrip; // [esp+58h] [ebp-28h]
  bool bExtraFaces; // [esp+5Fh] [ebp-21h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > indices; // [esp+60h] [ebp-20h] BYREF
  int nFaceCount; // [esp+74h] [ebp-Ch]
  int nVertsPerFace; // [esp+78h] [ebp-8h]
  int nSubDFaces; // [esp+7Ch] [ebp-4h]

  nSubDFaces = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: subdFaceList);
  stripIdx = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::AddToTail(this: &pStripGroup->strips);
  pNewStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                this: &pStripGroup->strips,
                i: stripIdx);
  nFaceCount = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: faceList);
  nVertsPerFace = (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                     this: (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *)faceList,
                     i: 0)->vertID[3] != -1)
                + 3;
  pNewStrip->flags = (nVertsPerFace != 3) + 1;
  bSubDQuad = nVertsPerFace == 4;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
    this: &indices,
    growSize: 0,
    initSize: 0);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
    this: &indices,
    num: nFaceCount * nVertsPerFace);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
    this: &topologyIndices,
    growSize: 0,
    initSize: 0);
  if ( bSubDQuad )
  {
    if ( nVertsPerFace == 4 )
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
        this: &topologyIndices,
        num: 40 * nFaceCount);
    else
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
        this: &topologyIndices,
        num: nVertsPerFace * nFaceCount);
  }
  bExtraFaces = false;
  for ( f = 0; f < nFaceCount; ++f )
  {
    face = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *)faceList,
             i: f);
    face->touched = true;
    if ( bSubDQuad )
    {
      subDFace = CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::operator[](
                   this: (CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *)subdFaceList,
                   i: f);
      if ( !bExtraFaces && !OptimizedModel::FaceIsRegular(patch: subDFace) )
      {
        if ( (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&topologyIndices) > 0
          && (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&indices) > 1200 )
        {
          OptimizedModel::COptimizedModel::Stripify(
            this,
            sourceIndices: (ConCommandBase *)&indices,
            sourceTopologyIndices: (ConCommandBase *)&topologyIndices,
            bIsHWSkinned: false,
            pNumIndices: (unsigned int *)&pNewStrip->numIndices,
            pNumTopologyIndices: &pNewStrip->numTopologyIndices,
            ppIndices: &pNewStrip->pIndices,
            ppTopologyIndices: &pNewStrip->pTopologyIndices,
            bQuadSubd: bSubDQuad);
          for ( v = 0; ; ++v )
          {
            v5 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: vertices);
            if ( v >= (int)v5 )
              break;
            v6 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
                   this: (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)vertices,
                   i: v);
            CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(
              this: &pNewStrip->verts,
              src: v6);
          }
          pNewStrip->numBoneStateChanges = 0;
          for ( b = 0; b < 512; ++b )
          {
            pNewStrip->boneStateChanges[b].hardwareID = -1;
            pNewStrip->boneStateChanges[b].newBoneID = -1;
          }
          stripIdx = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::AddToTail(this: &pStripGroup->strips);
          pNewStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                        this: &pStripGroup->strips,
                        i: stripIdx);
          CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::RemoveAll(this: (CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *)&indices);
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
            this: &indices,
            num: nFaceCount * nVertsPerFace);
          CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::RemoveAll(this: (CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *)&topologyIndices);
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
            this: &topologyIndices,
            num: 40 * nFaceCount);
        }
        pNewStrip->flags = 4;
        bExtraFaces = true;
      }
      src = face->vertID[0];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, &src);
      v15 = face->vertID[1];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v15);
      v14 = face->vertID[2];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v14);
      v13 = face->vertID[3];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v13);
      j = 0;
      if ( nSubDFaces == nFaceCount )
      {
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vtx1RingSize[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vtx1RingCenterQuadOffset[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->valences[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->minOneRingIndex[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->bndVtx[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->bndEdge[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->cornerVtx[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->loopGapAngle[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->nbCornerVtx[j]);
        for ( j = 0; j < 8; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->edgeBias[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vUV0[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vUV1[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vUV2[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vUV3[j]);
        totalOneRingSize = subDFace->vtx1RingSize[3]
                         + subDFace->vtx1RingSize[2]
                         + subDFace->vtx1RingSize[1]
                         + subDFace->vtx1RingSize[0];
        for ( j = 0; j < totalOneRingSize; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->oneRing[j]);
      }
    }
    else
    {
      v12 = face->vertID[0];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v12);
      v11 = face->vertID[1];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v11);
      v10 = face->vertID[2];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v10);
    }
  }
  OptimizedModel::COptimizedModel::Stripify(
    this,
    sourceIndices: (ConCommandBase *)&indices,
    sourceTopologyIndices: (ConCommandBase *)&topologyIndices,
    bIsHWSkinned: false,
    pNumIndices: (unsigned int *)&pNewStrip->numIndices,
    pNumTopologyIndices: &pNewStrip->numTopologyIndices,
    ppIndices: &pNewStrip->pIndices,
    ppTopologyIndices: &pNewStrip->pTopologyIndices,
    bQuadSubd: bSubDQuad);
  for ( i = 0; ; ++i )
  {
    v7 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: vertices);
    if ( i >= (int)v7 )
      break;
    v8 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
           this: (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)vertices,
           i);
    CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(
      this: &pNewStrip->verts,
      src: v8);
  }
  pNewStrip->numBoneStateChanges = 0;
  for ( k = 0; k < 512; ++k )
  {
    pNewStrip->boneStateChanges[k].hardwareID = -1;
    pNewStrip->boneStateChanges[k].newBoneID = -1;
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&topologyIndices);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&indices);
}

//------------------------------------------------------------------------------
// Address: 0x00422BF0
// Name: private: void OptimizedModel::COptimizedModel::ProcessStripGroup(struct OptimizedModel::StripGroup_t __near *,bool,bool,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,class CUtlVector<struct mstudioiface_t,class CUtlMemory<struct mstudioiface_t,int>> __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> __near &,int,int,int,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ProcessStripGroup(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::StripGroup_t *pStripGroup,
        bool bIsHWSkinned,
        bool bIsFlexed,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        ConCommandBase *srcFaces,
        CUtlVector<bool,CUtlMemory<bool,int> > *facesProcessed,
        int maxBonesPerVert,
        int maxBonesPerFace,
        int maxBonesPerStrip,
        bool bForceNoFlex,
        bool bHWFlex,
        bool bQuadSubd)
{
  const char *v14; // eax
  const char *v15; // eax
  int v16; // [esp+0h] [ebp-A4h]
  char v17; // [esp+4h] [ebp-A0h]
  int v18; // [esp+8h] [ebp-9Ch]
  int numVertexBones; // [esp+24h] [ebp-80h]
  bool bFaceIsFlexed; // [esp+2Fh] [ebp-75h]
  int nFaceIndex; // [esp+30h] [ebp-74h]
  OptimizedModel::Face_t *newFace; // [esp+34h] [ebp-70h]
  mstudioiface_t *pFace; // [esp+38h] [ebp-6Ch]
  OptimizedModel::Vertex_t stripGroupVert[4]; // [esp+40h] [ebp-64h] BYREF
  int n; // [esp+64h] [ebp-40h]
  CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > stripGroupSourceFaces; // [esp+68h] [ebp-3Ch] BYREF
  CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > stripGroupVertices; // [esp+7Ch] [ebp-28h] BYREF
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > stripGroupSubDFaces; // [esp+90h] [ebp-14h] BYREF

  OptimizedModel::COptimizedModel::ComputeStripGroupFlags(this, pStripGroup, bIsHWSkinned, bIsFlexed);
  CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>(
    this: &stripGroupSourceFaces,
    growSize: 0,
    initSize: 0);
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>(
    this: &stripGroupSubDFaces,
    growSize: 0,
    initSize: 0);
  CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>(
    this: &stripGroupVertices,
    growSize: 0,
    initSize: 0);
  CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::RemoveAll(this: &OptimizedModel::g_StripGroupVertexLookup);
  for ( n = 0; ; ++n )
  {
    v14 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: srcFaces);
    if ( n >= (int)v14 )
      break;
    if ( !*CUtlVector<bool,CUtlMemory<bool,int>>::operator[](this: facesProcessed, i: n) )
    {
      pFace = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::operator[](
                this: (CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int> > *)srcFaces,
                i: n);
      if ( bIsHWSkinned && (bHWFlex || !bIsFlexed) )
        v18 = maxBonesPerVert;
      else
        v18 = 0;
      bFaceIsFlexed = OptimizedModel::COptimizedModel::GenerateStripGroupVerticesFromFace(
                        this,
                        pFace,
                        pStudioMesh,
                        maxPreferredBones: v18,
                        pStripGroupVert: stripGroupVert,
                        bQuadSubd);
      if ( bForceNoFlex )
        bFaceIsFlexed = false;
      if ( bQuadSubd || bFaceIsFlexed == bIsFlexed )
      {
        if ( !bIsHWSkinned
          || ((numVertexBones = OptimizedModel::COptimizedModel::CountMaxVertBones(
                                  this,
                                  count: bQuadSubd + 3,
                                  pVertex: stripGroupVert),
               OptimizedModel::COptimizedModel::CountUniqueBones(this, count: bQuadSubd + 3, pVertex: stripGroupVert) > maxBonesPerFace)
           || numVertexBones > maxBonesPerVert
            ? (v17 = 0)
            : (v17 = 1),
              v17 != 0) )
        {
          nFaceIndex = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::AddToTail(this: &stripGroupSourceFaces);
          newFace = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                      this: &stripGroupSourceFaces,
                      i: nFaceIndex);
          newFace->vertID[0] = OptimizedModel::FindOrCreateVertex(list: &stripGroupVertices, vert: stripGroupVert);
          newFace->vertID[1] = OptimizedModel::FindOrCreateVertex(list: &stripGroupVertices, vert: &stripGroupVert[1]);
          newFace->vertID[2] = OptimizedModel::FindOrCreateVertex(list: &stripGroupVertices, vert: &stripGroupVert[2]);
          if ( bQuadSubd )
            v16 = OptimizedModel::FindOrCreateVertex(list: &stripGroupVertices, vert: &stripGroupVert[3]);
          else
            v16 = -1;
          newFace->vertID[3] = v16;
          OptimizedModel::COptimizedModel::BuildFaceBoneData(this, list: &stripGroupVertices, face: newFace);
          *CUtlVector<bool,CUtlMemory<bool,int>>::operator[](this: facesProcessed, i: n) = true;
        }
      }
    }
  }
  if ( CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&stripGroupSourceFaces) != nullptr )
  {
    v15 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&stripGroupVertices);
    OptimizedModel::COptimizedModel::BuildNeighborInfo(this, faceList: &stripGroupSourceFaces, nMaxVertexId: (int)v15);
    if ( bQuadSubd )
    {
      mstudiomodel_t::GetVertexData(
        this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
        pModelData: nullptr);
      pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                                  + pStudioMesh->modelindex);
      if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
        OptimizedModel::COptimizedModel::BuildSubDFaceList(
          this,
          faceList: (ConCommandBase *)&stripGroupSourceFaces,
          subDFaceList: &stripGroupSubDFaces,
          vtxList: &stripGroupVertices,
          pVertexData: &pStudioMesh->vertexdata);
      else
        OptimizedModel::COptimizedModel::BuildSubDFaceList(
          this,
          faceList: (ConCommandBase *)&stripGroupSourceFaces,
          subDFaceList: &stripGroupSubDFaces,
          vtxList: &stripGroupVertices,
          pVertexData: nullptr);
    }
    if ( bIsHWSkinned )
      OptimizedModel::COptimizedModel::BuildHWSkinnedStrips(
        this,
        faceList: &stripGroupSourceFaces,
        vertices: &stripGroupVertices,
        pStripGroup,
        maxBonesPerStrip);
    else
      OptimizedModel::COptimizedModel::BuildSWSkinnedStrips(
        this,
        faceList: (ConCommandBase *)&stripGroupSourceFaces,
        subdFaceList: (ConCommandBase *)&stripGroupSubDFaces,
        vertices: (ConCommandBase *)&stripGroupVertices,
        pStripGroup);
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&stripGroupVertices);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&stripGroupSubDFaces);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&stripGroupSourceFaces);
}

//------------------------------------------------------------------------------
// Address: 0x00423000
// Name: public: CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>(int,int,int,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &))
// Source: json
//------------------------------------------------------------------------------
CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *__thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        int bucketCount,
        int growCount,
        int initCount,
        bool (__cdecl *compareFunc)(const OptimizedModel::StripVertLookup_t *, const OptimizedModel::StripVertLookup_t *),
        unsigned int (__cdecl *keyFunc)(const OptimizedModel::StripVertLookup_t *))
{
  int v6; // ebx
  int v8; // edi
  CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int> > *v9; // ecx
  bool v10; // al

  v6 = bucketCount;
  v8 = 0;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  this->m_CompareFunc = compareFunc;
  this->m_KeyFunc = keyFunc;
  if ( bucketCount >= 0x10000 )
  {
    bucketCount = 0x10000;
    v6 = 0x10000;
  }
  CUtlVector<CUtlVectorAuto<s_animation_t *>,CUtlMemory<CUtlVectorAuto<s_animation_t *>,int>>::RemoveAll((CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int>>,CUtlMemory<CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int>>,int>>::InsertMultipleBefore(
    this: &this->m_Buckets,
    elem: this->m_Buckets.m_Size,
    num: v6);
  if ( v6 > 0 )
  {
    do
    {
      v9 = &this->m_Buckets.m_Memory.m_pMemory[v8];
      v9->m_Size = 0;
      CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int>>::InsertMultipleBefore(
        this: v9,
        elem: 0,
        num: initCount);
      this->m_Buckets.m_Memory.m_pMemory[v8++].m_Memory.m_nGrowSize = growCount;
      --v6;
    }
    while ( v6 != 0 );
    v6 = bucketCount;
  }
  v10 = IsPowerOfTwo(value: v6);
  this->m_bPowerOfTwo = v10;
  if ( v10 )
    this->m_ModMask = v6 - 1;
  else
    this->m_ModMask = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004230B0
// Name: public: CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::~CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::~CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this)
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge((CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)this);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>((CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004230C0
// Name: struct OptimizedModel::StripGroup_t __near * Construct<struct OptimizedModel::StripGroup_t>(struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::StripGroup_t *__cdecl Construct<OptimizedModel::StripGroup_t>(OptimizedModel::StripGroup_t *pMemory)
{
  OptimizedModel::StripGroup_t *result; // eax

  result = (OptimizedModel::StripGroup_t *)operator new(__formal: 0x54u, _Where: pMemory);
  if ( result == nullptr )
    return nullptr;
  result->indices.m_Memory.m_pMemory = nullptr;
  result->indices.m_Memory.m_nAllocationCount = 0;
  result->indices.m_Memory.m_nGrowSize = 0;
  result->indices.m_Size = 0;
  result->indices.m_pElements = nullptr;
  result->topologyIndices.m_Memory.m_pMemory = nullptr;
  result->topologyIndices.m_Memory.m_nAllocationCount = 0;
  result->topologyIndices.m_Memory.m_nGrowSize = 0;
  result->topologyIndices.m_Size = 0;
  result->topologyIndices.m_pElements = nullptr;
  result->verts.m_Memory.m_pMemory = nullptr;
  result->verts.m_Memory.m_nAllocationCount = 0;
  result->verts.m_Memory.m_nGrowSize = 0;
  result->verts.m_Size = 0;
  result->verts.m_pElements = nullptr;
  result->strips.m_Memory.m_pMemory = nullptr;
  result->strips.m_Memory.m_nAllocationCount = 0;
  result->strips.m_Memory.m_nGrowSize = 0;
  result->strips.m_Size = 0;
  result->strips.m_pElements = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423380
// Name: private: void OptimizedModel::COptimizedModel::ProcessMesh(struct OptimizedModel::Mesh_t __near *,struct studiohdr_t __near *,class CUtlVector<struct mstudioiface_t,class CUtlMemory<struct mstudioiface_t,int>> __near &,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ProcessMesh(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::Mesh_t *pMesh,
        studiohdr_t *pStudioHeader,
        ConCommandBase *srcFaces,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        bool bForceNoFlex,
        bool bForceSoftwareSkin,
        bool bHWFlex,
        bool bQuadSubd)
{
  const char *v10; // eax
  unsigned __int8 *v11; // eax
  const char *v12; // [esp-4h] [ebp-40h]
  int realMaxBonesPerFace; // [esp+Ch] [ebp-30h]
  int realMaxBonesPerVert; // [esp+10h] [ebp-2Ch]
  OptimizedModel::StripGroup_t *newStripGroup; // [esp+14h] [ebp-28h]
  int newStripGroupIndex; // [esp+18h] [ebp-24h]
  int realMaxBonesPerStrip; // [esp+1Ch] [ebp-20h]
  int isFlexed; // [esp+20h] [ebp-1Ch]
  int isHWSkinned; // [esp+24h] [ebp-18h]
  CUtlVector<bool,CUtlMemory<bool,int> > facesProcessed; // [esp+28h] [ebp-14h] BYREF

  OptimizedModel::COptimizedModel::ComputeMeshFlags(this, pMesh, pStudioHeader, pStudioMesh);
  CUtlVector<bool,CUtlMemory<bool,int>>::CUtlVector<bool,CUtlMemory<bool,int>>(
    this: &facesProcessed,
    growSize: 0,
    initSize: 0);
  v10 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: srcFaces);
  CUtlVector<bool,CUtlMemory<bool,int>>::AddMultipleToTail(this: &facesProcessed, num: (int)v10);
  v12 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&facesProcessed);
  v11 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&facesProcessed);
  memset(dst: v11, value: 0, count: (unsigned int)v12);
  for ( isHWSkinned = !bForceSoftwareSkin; isHWSkinned >= 0; --isHWSkinned )
  {
    for ( isFlexed = 1; isFlexed >= 0; --isFlexed )
    {
      if ( isFlexed == 0 || bHWFlex )
      {
        realMaxBonesPerFace = this->m_MaxBonesPerFace;
        realMaxBonesPerVert = this->m_MaxBonesPerVert;
        realMaxBonesPerStrip = this->m_MaxBonesPerStrip;
      }
      else
      {
        realMaxBonesPerFace = 1;
        realMaxBonesPerVert = 1;
        realMaxBonesPerStrip = 1;
      }
      newStripGroupIndex = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::AddToTail(this: &pMesh->stripGroups);
      newStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                        this: &pMesh->stripGroups,
                        i: newStripGroupIndex);
      OptimizedModel::COptimizedModel::ProcessStripGroup(
        this,
        pStripGroup: newStripGroup,
        bIsHWSkinned: isHWSkinned != 0,
        bIsFlexed: isFlexed != 0,
        pStudioModel,
        pStudioMesh,
        srcFaces,
        &facesProcessed,
        maxBonesPerVert: realMaxBonesPerVert,
        maxBonesPerFace: realMaxBonesPerFace,
        maxBonesPerStrip: realMaxBonesPerStrip,
        bForceNoFlex,
        bHWFlex,
        bQuadSubd);
      OptimizedModel::COptimizedModel::PostProcessStripGroup(
        this,
        pStudioModel,
        pStudioMesh,
        pStripGroup: (ConCommandBase *)newStripGroup);
      if ( CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)newStripGroup) == nullptr )
        CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::FastRemove(
          this: &pMesh->stripGroups,
          elem: newStripGroupIndex);
    }
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&facesProcessed);
}

//------------------------------------------------------------------------------
// Address: 0x00423780
// Name: private: void OptimizedModel::COptimizedModel::ProcessModel(struct studiohdr_t __near *,struct s_bodypart_t __near *,struct OptimizedModel::TotalMeshStats_t __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ProcessModel(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        s_bodypart_t *pSrcBodyParts,
        OptimizedModel::TotalMeshStats_t *stats,
        bool bForceSoftwareSkin,
        bool bHWFlex)
{
  const char *v6; // eax
  bool v7; // [esp+0h] [ebp-6Ch]
  mstudiomesh_t *pStudioMesh; // [esp+Ch] [ebp-60h]
  OptimizedModel::Mesh_t *newMesh; // [esp+10h] [ebp-5Ch]
  s_mesh_t *pSrcMesh; // [esp+14h] [ebp-58h]
  CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int> > meshFaceList; // [esp+18h] [ebp-54h] BYREF
  int v13; // [esp+2Ch] [ebp-40h]
  bool bQuadSubd; // [esp+33h] [ebp-39h]
  OptimizedModel::ModelLOD_t *newLOD; // [esp+34h] [ebp-38h]
  LodScriptData_t *scriptLOD; // [esp+38h] [ebp-34h]
  s_source_t *pLODSource; // [esp+3Ch] [ebp-30h]
  int v18; // [esp+40h] [ebp-2Ch]
  int i; // [esp+44h] [ebp-28h]
  mstudiomodel_t *pStudioModel; // [esp+48h] [ebp-24h]
  s_model_t *pSrcModel; // [esp+4Ch] [ebp-20h]
  OptimizedModel::Model_t *newModel; // [esp+50h] [ebp-1Ch]
  s_bodypart_t *pSrcBodyPart; // [esp+54h] [ebp-18h]
  mstudiobodyparts_t *pBodyPart; // [esp+58h] [ebp-14h]
  int modelID; // [esp+5Ch] [ebp-10h]
  int meshID; // [esp+60h] [ebp-Ch]
  int bodyPartID; // [esp+64h] [ebp-8h]
  int lodID; // [esp+68h] [ebp-4h]

  memset(dst: (unsigned __int8 *)stats, value: 0, count: sizeof(OptimizedModel::TotalMeshStats_t));
  CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::RemoveAll(this: &this->m_Models);
  bodyPartID = 0;
  while ( bodyPartID < pHdr->numbodyparts )
  {
    pBodyPart = (mstudiobodyparts_t *)((char *)pHdr + 16 * bodyPartID + pHdr->bodypartindex);
    pSrcBodyPart = &pSrcBodyParts[bodyPartID];
    modelID = 0;
    while ( modelID < pBodyPart->nummodels )
    {
      i = CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::AddToTail(this: &this->m_Models);
      newModel = CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                   this: &this->m_Models,
                   i);
      pStudioModel = (mstudiomodel_t *)((char *)pBodyPart + 148 * modelID + pBodyPart->modelindex);
      pSrcModel = (s_model_t *)*CUtlVectorAuto<s_bone_t *>::operator[](
                                  this: (CUtlVectorAuto<s_bone_t *> *)&pSrcBodyPart->pmodel,
                                  i: modelID);
      lodID = 0;
      while ( 1 )
      {
        v6 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
        if ( lodID >= (int)v6 )
          break;
        scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](
                      this: &g_ScriptLODs,
                      i: lodID);
        pLODSource = (s_source_t *)*CUtlVector<int,CUtlMemory<int,int>>::operator[](
                                      this: (CUtlVector<int,CUtlMemory<int,int> > *)&pSrcModel->m_LodSources,
                                      i: lodID);
        v18 = CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int>>::AddToTail(this: &newModel->modelLODs);
        newLOD = CUtlVector<OptimizedModel::Mesh_t,CUtlMemory<OptimizedModel::Mesh_t,int>>::operator[](
                   this: &newModel->modelLODs,
                   i: v18);
        newLOD->switchPoint = scriptLOD->switchValue;
        if ( pLODSource != nullptr )
        {
          meshID = 0;
          while ( meshID < pStudioModel->nummeshes )
          {
            pStudioMesh = (mstudiomesh_t *)((char *)pStudioModel + 116 * meshID + pStudioModel->meshindex);
            pSrcMesh = &pSrcModel->source->mesh[pSrcModel->source->meshindex[meshID]];
            v13 = CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int>>::AddToTail(this: (CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int> > *)newLOD);
            newMesh = (OptimizedModel::Mesh_t *)CUtlVector<OptimizedModel::Mesh_t,CUtlMemory<OptimizedModel::Mesh_t,int>>::operator[](
                                                  this: (CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int> > *)newLOD,
                                                  i: v13);
            if ( OptimizedModel::COptimizedModel::MeshNeedsRemoval(this, pHdr, pStudioMesh, scriptLOD) == 0 )
            {
              bQuadSubd = (gflags & 0x80000) != 0;
              v7 = (gflags & 0x80000) != 0 || bForceSoftwareSkin;
              bForceSoftwareSkin = v7;
              CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>(
                this: &meshFaceList,
                growSize: 0,
                initSize: 0);
              if ( pLODSource != nullptr )
                OptimizedModel::COptimizedModel::CreateLODFaceList(
                  this,
                  pSrcModel,
                  nLodID: lodID,
                  pSrc: pLODSource,
                  pStudioModel,
                  pStudioMesh,
                  &meshFaceList,
                  bQuadSubd,
                  writeDebug: false);
              else
                OptimizedModel::COptimizedModel::SourceMeshToFaceList(this, pSrcModel, pSrcMesh, &meshFaceList);
              OptimizedModel::COptimizedModel::ProcessMesh(
                this,
                pMesh: newMesh,
                pStudioHeader: pHdr,
                srcFaces: (ConCommandBase *)&meshFaceList,
                pStudioModel,
                pStudioMesh,
                bForceNoFlex: !scriptLOD->m_bFacialAnimation,
                bForceSoftwareSkin: v7,
                bHWFlex,
                bQuadSubd);
              stats->m_TotalVerts += OptimizedModel::COptimizedModel::GetTotalVertsForMesh(
                                       this,
                                       pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalIndices += OptimizedModel::COptimizedModel::GetTotalIndicesForMesh(
                                         this,
                                         pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalTopologyIndices += OptimizedModel::COptimizedModel::GetTotalTopologyIndicesForMesh(
                                                 this,
                                                 pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalStrips += OptimizedModel::COptimizedModel::GetTotalStripsForMesh(
                                        this,
                                        pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalStripGroups += (int)OptimizedModel::COptimizedModel::GetTotalStripGroupsForMesh(
                                                  this,
                                                  pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalBoneStateChanges += OptimizedModel::COptimizedModel::GetTotalBoneStateChangesForMesh(
                                                  this,
                                                  pMesh: (ConCommandBase *)newMesh);
              CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&meshFaceList);
            }
            ++meshID;
            ++stats->m_TotalMeshes;
          }
        }
        else if ( pSrcModel != nullptr )
        {
          _V_stricmp(s1: pSrcModel->name, s2: "blank");
        }
        ++lodID;
        ++stats->m_TotalModelLODs;
      }
      ++modelID;
      ++stats->m_TotalModels;
    }
    ++bodyPartID;
    ++stats->m_TotalBodyParts;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423B40
// Name: public: bool OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(struct studiohdr_t __near *,struct s_bodypart_t __near *,int,bool,bool,bool,int,int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        s_bodypart_t *pSrcBodyParts,
        int vertCacheSize,
        bool usesFixedFunction,
        bool bForceSoftwareSkin,
        bool bHWFlex,
        int maxBonesPerVert,
        int maxBonesPerFace,
        int maxBonesPerStrip,
        const char *pFileName,
        const char *glViewFileName)
{
  CFileBuffer *m_FileBuffer; // [esp+10h] [ebp-30h]
  OptimizedModel::TotalMeshStats_t stats; // [esp+14h] [ebp-2Ch] BYREF

  OptimizedModel::MergeLikeBoneIndicesWithinVerts(pHdr);
  OptimizedModel::COptimizedModel::SetupMeshProcessing(
    this,
    pHdr,
    vertexCacheSize: vertCacheSize,
    usesFixedFunction,
    maxBonesPerVert,
    maxBonesPerFace,
    maxBonesPerStrip,
    fileName: pFileName);
  OptimizedModel::COptimizedModel::ProcessModel(this, pHdr, pSrcBodyParts, &stats, bForceSoftwareSkin, bHWFlex);
  stats.m_TotalMaterialReplacements = OptimizedModel::CalcNumMaterialReplacements();
  OptimizedModel::COptimizedModel::WriteVTXFile(this, pHdr, pFileName, &stats);
  OptimizedModel::COptimizedModel::WriteGLViewFiles(this, pHdr, glViewFileName);
  m_FileBuffer = this->m_FileBuffer;
  if ( m_FileBuffer != nullptr )
  {
    free(pMem: m_FileBuffer->m_pData);
    free(pMem: m_FileBuffer);
  }
  this->m_FileBuffer = nullptr;
  if ( this->m_NumSkinnedAndFlexedVerts != 0 )
    MdlWarning(
      fmt: "!!!!WARNING!!!!: %d flexed verts had more than one bone influence. . will use SLOW path in engine\n",
      this->m_NumSkinnedAndFlexedVerts);
  OptimizedModel::COptimizedModel::CleanupEverything(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423C50
// Name: void OptimizedModel::WriteOptimizedFiles(struct studiohdr_t __near *,struct s_bodypart_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::WriteOptimizedFiles(studiohdr_t *phdr, s_bodypart_t *pSrcBodyParts)
{
  char v2; // [esp+Bh] [ebp-3E1h]
  char *v3; // [esp+Ch] [ebp-3E0h]
  char v4; // [esp+13h] [ebp-3D9h]
  char *v5; // [esp+18h] [ebp-3D4h]
  char *v6; // [esp+1Ch] [ebp-3D0h]
  char v7; // [esp+23h] [ebp-3C9h]
  char *v8; // [esp+24h] [ebp-3C8h]
  char v9; // [esp+2Bh] [ebp-3C1h]
  char *v10; // [esp+30h] [ebp-3BCh]
  char *v11; // [esp+34h] [ebp-3B8h]
  char v12; // [esp+3Bh] [ebp-3B1h]
  char *v13; // [esp+3Ch] [ebp-3B0h]
  char v14; // [esp+43h] [ebp-3A9h]
  char *v15; // [esp+48h] [ebp-3A4h]
  char *v16; // [esp+4Ch] [ebp-3A0h]
  char v17; // [esp+53h] [ebp-399h]
  char *v18; // [esp+54h] [ebp-398h]
  char v19; // [esp+5Bh] [ebp-391h]
  char *v20; // [esp+60h] [ebp-38Ch]
  char *v21; // [esp+64h] [ebp-388h]
  bool v22; // [esp+68h] [ebp-384h]
  char v23; // [esp+6Fh] [ebp-37Dh]
  char *v24; // [esp+70h] [ebp-37Ch]
  char v25; // [esp+77h] [ebp-375h]
  char *v26; // [esp+7Ch] [ebp-370h]
  char *v27; // [esp+80h] [ebp-36Ch]
  char v28; // [esp+87h] [ebp-365h]
  char *v29; // [esp+88h] [ebp-364h]
  char v30; // [esp+8Fh] [ebp-35Dh]
  char *v31; // [esp+94h] [ebp-358h]
  char *v32; // [esp+98h] [ebp-354h]
  char v33; // [esp+9Fh] [ebp-34Dh]
  bool *v34; // [esp+A0h] [ebp-34Ch]
  char *v35; // [esp+B4h] [ebp-338h]
  char v36; // [esp+BBh] [ebp-331h]
  bool *p_bForceSoftwareSkinning; // [esp+BCh] [ebp-330h]
  char v38; // [esp+C3h] [ebp-329h]
  char *v39; // [esp+C8h] [ebp-324h]
  char *v40; // [esp+CCh] [ebp-320h]
  bool bForceSoftwareSkinning; // [esp+D3h] [ebp-319h] BYREF
  char filename[263]; // [esp+D4h] [ebp-318h] BYREF
  char v43; // [esp+1DBh] [ebp-211h] BYREF
  char glViewFilename[263]; // [esp+1DCh] [ebp-210h] BYREF
  char v45; // [esp+2E3h] [ebp-109h] BYREF
  char tmpFileName[264]; // [esp+2E4h] [ebp-108h] BYREF

  OptimizedModel::ValidateLODReplacements(pHdr: phdr);
  CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Purge(this: &s_StringTable.m_Strings);
  OptimizedModel::AddMaterialReplacementsToStringTable();
  v40 = gamedir;
  v39 = filename;
  do
  {
    v38 = *v40;
    *v39++ = *v40++;
  }
  while ( v38 != 0 );
  p_bForceSoftwareSkinning = &bForceSoftwareSkinning;
  do
    v36 = *++p_bForceSoftwareSkinning;
  while ( v36 != 0 );
  strcpy((char *)p_bForceSoftwareSkinning, "models/");
  v35 = &g_outname[strlen(g_outname) + 1];
  v34 = &bForceSoftwareSkinning;
  do
    v33 = *++v34;
  while ( v33 != 0 );
  qmemcpy(v34, g_outname, v35 - g_outname);
  V_StripExtension(in: filename, out: filename, outSize: 260);
  if ( g_gameinfo.bSupportsDX8 && !g_bFastBuild )
  {
    v32 = filename;
    v31 = tmpFileName;
    do
    {
      v30 = *v32;
      *v31++ = *v32++;
    }
    while ( v30 != 0 );
    v29 = &v45;
    do
      v28 = *++v29;
    while ( v28 != 0 );
    strcpy(v29, ".sw.vtx");
    v27 = filename;
    v26 = glViewFilename;
    do
    {
      v25 = *v27;
      *v26++ = *v27++;
    }
    while ( v25 != 0 );
    v24 = &v43;
    do
      v23 = *++v24;
    while ( v23 != 0 );
    strcpy(v24, ".sw.glview");
    v22 = phdr->numbones > 0 && !g_staticprop;
    bForceSoftwareSkinning = v22;
    OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(
      this: &s_OptimizedModel,
      pHdr: phdr,
      pSrcBodyParts,
      vertCacheSize: 512,
      usesFixedFunction: false,
      bForceSoftwareSkin: v22,
      bHWFlex: false,
      maxBonesPerVert: 3,
      maxBonesPerFace: 9,
      maxBonesPerStrip: 512,
      pFileName: tmpFileName,
      glViewFileName: glViewFilename);
  }
  if ( g_gameinfo.bSupportsDX8 && !g_bFastBuild )
  {
    v21 = filename;
    v20 = tmpFileName;
    do
    {
      v19 = *v21;
      *v20++ = *v21++;
    }
    while ( v19 != 0 );
    v18 = &v45;
    do
      v17 = *++v18;
    while ( v17 != 0 );
    strcpy(v18, ".dx80.vtx");
    v16 = filename;
    v15 = glViewFilename;
    do
    {
      v14 = *v16;
      *v15++ = *v16++;
    }
    while ( v14 != 0 );
    v13 = &v43;
    do
      v12 = *++v13;
    while ( v12 != 0 );
    strcpy(v13, ".dx80.glview");
    OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(
      this: &s_OptimizedModel,
      pHdr: phdr,
      pSrcBodyParts,
      vertCacheSize: 24,
      usesFixedFunction: false,
      bForceSoftwareSkin: false,
      bHWFlex: false,
      maxBonesPerVert: 3,
      maxBonesPerFace: 9,
      maxBonesPerStrip: 16,
      pFileName: tmpFileName,
      glViewFileName: glViewFilename);
  }
  v11 = filename;
  v10 = tmpFileName;
  do
  {
    v9 = *v11;
    *v10++ = *v11++;
  }
  while ( v9 != 0 );
  v8 = &v45;
  do
    v7 = *++v8;
  while ( v7 != 0 );
  strcpy(v8, ".dx90.vtx");
  v6 = filename;
  v5 = glViewFilename;
  do
  {
    v4 = *v6;
    *v5++ = *v6++;
  }
  while ( v4 != 0 );
  v3 = &v43;
  do
    v2 = *++v3;
  while ( v2 != 0 );
  strcpy(v3, ".dx90.glview");
  OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(
    this: &s_OptimizedModel,
    pHdr: phdr,
    pSrcBodyParts,
    vertCacheSize: 24,
    usesFixedFunction: false,
    bForceSoftwareSkin: false,
    bHWFlex: true,
    maxBonesPerVert: 3,
    maxBonesPerFace: 9,
    maxBonesPerStrip: 53,
    pFileName: tmpFileName,
    glViewFileName: glViewFilename);
  CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Purge(this: &s_StringTable.m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x0048A540
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AC80
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0048AFC0
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
           this: &this->m_Memory,
           result: &v13,
           it: &this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
              this: &this->m_Memory,
              result: &v14,
              it: &this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0048B9E0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
                this: &v1->m_Memory,
                &result,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == v1->m_LastAlloc.m_pBlockHeader && m_nIndex == v1->m_LastAlloc.m_nIndex )
        break;
    }
    v1->m_Head = 0;
    v1->m_Tail = 0;
    v1->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C1C0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0048C210
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::LinkBefore(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 8);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Head = *(_DWORD *)(elem + 12);
      v5 = *(_DWORD *)(elem + 12);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Tail = *(_DWORD *)(elem + 8);
      *(_DWORD *)(elem + 12) = elem;
      *(_DWORD *)(elem + 8) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 12) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 8);
    *(_DWORD *)(before + 8) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 8) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 12) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9110
// Name: protected: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004B9280
// Name: public: void CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B92E0
// Name: public: void CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::Unlink(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<IUndoElement *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9BA0
// Name: public: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AddToTail(class IUndoElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        IUndoElement **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // esi

  result = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004FF3C0
// Name: public: static unsigned int CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::InvalidHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::InvalidHandle(
        CDmeClip *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C5390
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C5400
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x005C5580
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C5790
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EBDA0
// Name: OptimizedModel::_dynamic_initializer_for__s_StringTable__
// Source: json
//------------------------------------------------------------------------------
int OptimizedModel::_dynamic_initializer_for__s_StringTable__()
{
  CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>(
    this: (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)&s_StringTable,
    growSize: 0,
    initSize: 0);
  return atexit(func: OptimizedModel::_dynamic_atexit_destructor_for__s_StringTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBDC0
// Name: OptimizedModel::_dynamic_initializer_for__s_OptimizedModel__
// Source: json
//------------------------------------------------------------------------------
int OptimizedModel::_dynamic_initializer_for__s_OptimizedModel__()
{
  CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>(
    this: &s_OptimizedModel.m_Models,
    growSize: 0,
    initSize: 0);
  CHardwareMatrixState::CHardwareMatrixState(this: &s_OptimizedModel.m_HardwareMatrixState);
  return atexit(func: OptimizedModel::_dynamic_atexit_destructor_for__s_OptimizedModel__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBDF0
// Name: OptimizedModel::_dynamic_initializer_for__g_StripGroupVertexLookup__
// Source: json
//------------------------------------------------------------------------------
int OptimizedModel::_dynamic_initializer_for__g_StripGroupVertexLookup__()
{
  CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>(
    this: &OptimizedModel::g_StripGroupVertexLookup,
    bucketCount: 0x10000,
    growCount: 0,
    initCount: 0,
    compareFunc: (bool (__cdecl *)(const OptimizedModel::StripVertLookup_t *, const OptimizedModel::StripVertLookup_t *))OptimizedModel::StripVertLookup_CompareFunc,
    keyFunc: OptimizedModel::StripVertLookup_KeyFunc);
  return atexit(func: OptimizedModel::_dynamic_atexit_destructor_for__g_StripGroupVertexLookup__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBE20
// Name: OptimizedModel::_dynamic_initializer_for__s_LastThreePositions__
// Source: json
//------------------------------------------------------------------------------
int OptimizedModel::_dynamic_initializer_for__s_LastThreePositions__()
{
  int result; // eax
  int v1; // [esp+0h] [ebp-8h]
  Vector *i; // [esp+4h] [ebp-4h]

  v1 = 3;
  for ( i = s_LastThreePositions; ; ++i )
  {
    result = --v1;
    if ( v1 < 0 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC380
// Name: OptimizedModel::BoneStateChangeHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::BoneStateChangeHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::BoneStateChangeHeader_t>(__formal: nullptr);
  OptimizedModel::BoneStateChangeHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC390
// Name: OptimizedModel::Vertex_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::Vertex_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::Vertex_t>(__formal: nullptr);
  OptimizedModel::Vertex_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC3A0
// Name: OptimizedModel::StripHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::StripHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::StripHeader_t>(__formal: nullptr);
  OptimizedModel::StripHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC3B0
// Name: OptimizedModel::StripGroupHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::StripGroupHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::StripGroupHeader_t>(__formal: nullptr);
  OptimizedModel::StripGroupHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC3C0
// Name: OptimizedModel::MeshHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::MeshHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::MeshHeader_t>(__formal: nullptr);
  OptimizedModel::MeshHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC3D0
// Name: OptimizedModel::ModelLODHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::ModelLODHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::ModelLODHeader_t>(__formal: nullptr);
  OptimizedModel::ModelLODHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC3E0
// Name: OptimizedModel::ModelHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::ModelHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::ModelHeader_t>(__formal: nullptr);
  OptimizedModel::ModelHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC3F0
// Name: OptimizedModel::BodyPartHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::BodyPartHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::BodyPartHeader_t>(__formal: nullptr);
  OptimizedModel::BodyPartHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC400
// Name: OptimizedModel::MaterialReplacementHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::MaterialReplacementHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::MaterialReplacementHeader_t>(__formal: nullptr);
  OptimizedModel::MaterialReplacementHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC410
// Name: OptimizedModel::MaterialReplacementListHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::MaterialReplacementListHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::MaterialReplacementListHeader_t>(__formal: nullptr);
  OptimizedModel::MaterialReplacementListHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EC420
// Name: OptimizedModel::FileHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::FileHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::FileHeader_t>(__formal: nullptr);
  OptimizedModel::FileHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F2710
// Name: OptimizedModel::_dynamic_atexit_destructor_for__s_StringTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::_dynamic_atexit_destructor_for__s_StringTable__()
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&s_StringTable);
}

//------------------------------------------------------------------------------
// Address: 0x005F2720
// Name: OptimizedModel::_dynamic_atexit_destructor_for__g_StripGroupVertexLookup__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::_dynamic_atexit_destructor_for__g_StripGroupVertexLookup__()
{
  CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::~CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>(this: &OptimizedModel::g_StripGroupVertexLookup);
}

//------------------------------------------------------------------------------
// Address: 0x005F2730
// Name: OptimizedModel::_dynamic_atexit_destructor_for__s_OptimizedModel__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::_dynamic_atexit_destructor_for__s_OptimizedModel__()
{
  CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::~CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>(this: &s_OptimizedModel.m_Models);
}

//------------------------------------------------------------------------------
// Address: 0x005F2BE0
// Name: _OptimizedModel::DataMapInit_OptimizedModel::BoneStateChangeHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::BoneStateChangeHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_59);
}

//------------------------------------------------------------------------------
// Address: 0x005F2BF0
// Name: _OptimizedModel::DataMapInit_OptimizedModel::Vertex_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::Vertex_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_60);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C00
// Name: _OptimizedModel::DataMapInit_OptimizedModel::StripHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::StripHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_61);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C10
// Name: _OptimizedModel::DataMapInit_OptimizedModel::StripGroupHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::StripGroupHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_62);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C20
// Name: _OptimizedModel::DataMapInit_OptimizedModel::MeshHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::MeshHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_63);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C30
// Name: _OptimizedModel::DataMapInit_OptimizedModel::ModelLODHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::ModelLODHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_64);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C40
// Name: _OptimizedModel::DataMapInit_OptimizedModel::ModelHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::ModelHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_65);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C50
// Name: _OptimizedModel::DataMapInit_OptimizedModel::BodyPartHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::BodyPartHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_66);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C60
// Name: _OptimizedModel::DataMapInit_OptimizedModel::MaterialReplacementHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::MaterialReplacementHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_67);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C70
// Name: _OptimizedModel::DataMapInit_OptimizedModel::MaterialReplacementListHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::MaterialReplacementListHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_68);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C80
// Name: _OptimizedModel::DataMapInit_OptimizedModel::FileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::FileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_69);
}

//------------------------------------------------------------------------------
// Address: 0x005EBE50
// Name: _dynamic_initializer_for____g_CreateCStudioDataCacheIStudioDataCache_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCStudioDataCacheIStudioDataCache_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCStudioDataCacheIStudioDataCache_reg,
           fn: _CreateCStudioDataCacheIStudioDataCache_interface,
           pName: "VStudioDataCache005");
}

//------------------------------------------------------------------------------
// Address: 0x005EBE70
// Name: _dynamic_initializer_for__s_BufferedLoggingListener__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_BufferedLoggingListener__()
{
  CBufferedLoggingListener::CBufferedLoggingListener(this: &s_BufferedLoggingListener);
  return atexit(func: dynamic_atexit_destructor_for__s_BufferedLoggingListener__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBE90
// Name: _dynamic_initializer_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_definevariable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_definevariable__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBEA0
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBED0
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBF00
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBF20
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBF70
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x005EBF80
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005F2740
// Name: _dynamic_atexit_destructor_for__s_BufferedLoggingListener__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_BufferedLoggingListener__()
{
  if ( s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory);
      s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory = nullptr;
    }
    s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F2780
// Name: _dynamic_atexit_destructor_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_definevariable__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_definevariable);
}

//------------------------------------------------------------------------------
// Address: 0x005F2790
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x005F27A0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x005F27B0
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x005F27C0
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x005F27D0
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

//------------------------------------------------------------------------------
// Address: 0x005F2C90
// Name: _DataMapInit_phyheader_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_phyheader_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_70);
}

//------------------------------------------------------------------------------
// Address: 0x005F2CA0
// Name: _dynamic_atexit_destructor_for__g_BoneMerge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BoneMerge__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_BoneMerge);
}

//------------------------------------------------------------------------------
// Address: 0x005F2CB0
// Name: _dynamic_atexit_destructor_for__g_bonesaveframe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_bonesaveframe__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_bonesaveframe);
}

//------------------------------------------------------------------------------
// Address: 0x005F2CC0
// Name: _dynamic_atexit_destructor_for__g_normal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_normal__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_normal);
}

//------------------------------------------------------------------------------
// Address: 0x005F2CD0
// Name: _dynamic_atexit_destructor_for__g_collapse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_collapse__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_collapse);
}

//------------------------------------------------------------------------------
// Address: 0x005F2CE0
// Name: _dynamic_atexit_destructor_for__g_hitboxsets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_hitboxsets__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_hitboxsets);
}

//------------------------------------------------------------------------------
// Address: 0x005F2CF0
// Name: _dynamic_atexit_destructor_for__g_KeyValueText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KeyValueText__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_KeyValueText);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D00
// Name: _dynamic_atexit_destructor_for__m_CreateMakefileDependencies__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_CreateMakefileDependencies__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&m_CreateMakefileDependencies);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D10
// Name: _dynamic_atexit_destructor_for__s_JointSurfaceProp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_JointSurfaceProp__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_JointSurfaceProp);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D20
// Name: _dynamic_atexit_destructor_for__s_JointContents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_JointContents__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_JointContents);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D30
// Name: _dynamic_atexit_destructor_for__g_constraintBones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_constraintBones__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_constraintBones);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D40
// Name: _dynamic_atexit_destructor_for__g_vertex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_vertex__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_vertex);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D50
// Name: _dynamic_atexit_destructor_for__g_texcoord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_texcoord__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_texcoord);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D60
// Name: _dynamic_atexit_destructor_for__g_src_uface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_src_uface__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_src_uface);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D70
// Name: _dynamic_atexit_destructor_for__g_model__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_model__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_model);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D80
// Name: _dynamic_atexit_destructor_for__g_bone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_bone__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_bone);
}

//------------------------------------------------------------------------------
// Address: 0x005F2D90
// Name: _dynamic_atexit_destructor_for__g_face__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_face__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_face);
}

//------------------------------------------------------------------------------
// Address: 0x005F2DA0
// Name: _dynamic_atexit_destructor_for__g_ScriptLODs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptLODs__()
{
  CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::~CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>(this: &g_ScriptLODs);
}

//------------------------------------------------------------------------------
// Address: 0x005F2DB0
// Name: _dynamic_atexit_destructor_for__g_twistbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_twistbones__()
{
  CUtlVector<CTwistBone,CUtlMemory<CTwistBone,int>>::~CUtlVector<CTwistBone,CUtlMemory<CTwistBone,int>>(this: &g_twistbones);
}

//------------------------------------------------------------------------------
// Address: 0x005F2DC0
// Name: _dynamic_atexit_destructor_for__g_bodypart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_bodypart__()
{
  CUtlVector<s_bodypart_t,CUtlMemory<s_bodypart_t,int>>::~CUtlVector<s_bodypart_t,CUtlMemory<s_bodypart_t,int>>(this: &g_bodypart);
}

//------------------------------------------------------------------------------
// Address: 0x005F2DD0
// Name: _dynamic_atexit_destructor_for__g_FlexControllerRemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FlexControllerRemap__()
{
  CUtlVector<s_flexcontrollerremap_t,CUtlMemory<s_flexcontrollerremap_t,int>>::~CUtlVector<s_flexcontrollerremap_t,CUtlMemory<s_flexcontrollerremap_t,int>>(this: &g_FlexControllerRemap);
}

//------------------------------------------------------------------------------
// Address: 0x005F2DE0
// Name: _dynamic_atexit_destructor_for__g_sequence__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_sequence__()
{
  CUtlVector<s_sequence_t,CUtlMemory<s_sequence_t,int>>::~CUtlVector<s_sequence_t,CUtlMemory<s_sequence_t,int>>(this: &g_sequence);
}

//------------------------------------------------------------------------------
// Address: 0x005F2DF0
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x005F2E00
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x005F2E10
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x005F2E20
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x005F2E50
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x005F2E60
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x005F2E70
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x005F2E80
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x005F2E90
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004019C0
// Name: public: void CUtlLinkedList<void (*)(void),unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<void (*)(void),unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<void (__cdecl*)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl*)(void),unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<void (__cdecl*)(void),unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413120
// Name: public: mstudioiface_t::mstudioiface_t(void)
// Source: json
//------------------------------------------------------------------------------
mstudioiface_t *__thiscall mstudioiface_t::mstudioiface_t(mstudioiface_t *this)
{
  this->d = -1;
  this->c = -1;
  this->b = -1;
  this->a = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413160
// Name: public: struct mstudio_modelvertexdata_t const __near * mstudiomodel_t::GetVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
const mstudio_modelvertexdata_t *__thiscall mstudiomodel_t::GetVertexData(mstudiomodel_t *this, void *pModelData)
{
  char *v4; // [esp+4h] [ebp-Ch]
  char *v5; // [esp+8h] [ebp-8h]
  const vertexFileHeader_t *pVertexHdr; // [esp+Ch] [ebp-4h]

  pVertexHdr = mstudiomodel_t::CacheVertexData(this, pModelData);
  if ( pVertexHdr == nullptr )
    return nullptr;
  if ( pVertexHdr->id == 1448297545 && pVertexHdr->vertexDataStart != 0 )
    v5 = (char *)pVertexHdr + pVertexHdr->vertexDataStart;
  else
    v5 = nullptr;
  this->vertexdata.pVertexData = v5;
  if ( pVertexHdr->id == 1448297545 && pVertexHdr->tangentDataStart != 0 )
    v4 = (char *)pVertexHdr + pVertexHdr->tangentDataStart;
  else
    v4 = nullptr;
  this->vertexdata.pTangentData = v4;
  if ( this->vertexdata.pVertexData != nullptr )
    return &this->vertexdata;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00413210
// Name: bool OptimizedModel::FaceIsRegular(struct OptimizedModel::SubD_Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl OptimizedModel::FaceIsRegular(OptimizedModel::SubD_Face_t *patch)
{
  return patch->valences[0] == 4
      && patch->valences[1] == 4
      && patch->valences[2] == 4
      && patch->valences[3] == 4
      && patch->bndVtx[0] == 0
      && patch->bndVtx[1] == 0
      && patch->bndVtx[2] == 0
      && patch->bndVtx[3] == 0
      && patch->bndEdge[0] == 0
      && patch->bndEdge[1] == 0
      && patch->bndEdge[2] == 0
      && patch->bndEdge[3] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004132F0
// Name: public: OptimizedModel::Face_t::Face_t(void)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__thiscall OptimizedModel::Face_t::Face_t(OptimizedModel::Face_t *this)
{
  int i; // [esp+4h] [ebp-4h]

  this->touched = false;
  for ( i = 0; i < 4; ++i )
  {
    this->neighborID[i] = -1;
    this->vertID[i] = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413340
// Name: private: void OptimizedModel::COptimizedModel::CleanupEverything(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::CleanupEverything(OptimizedModel::COptimizedModel *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00413350
// Name: private: void OptimizedModel::COptimizedModel::OutputMemoryUsage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::OutputMemoryUsage(OptimizedModel::COptimizedModel *this)
{
  printf(format: "body parts:   %7d bytes\n", this->m_ModelsOffset - this->m_BodyPartsOffset);
  printf(format: "models:       %7d bytes\n", this->m_MeshesOffset - this->m_ModelsOffset);
  printf(format: "model LODs:   %7d bytes\n", this->m_MeshesOffset - this->m_ModelLODsOffset);
  printf(format: "meshes:       %7d bytes\n", this->m_StripGroupsOffset - this->m_MeshesOffset);
  printf(format: "strip groups: %7d bytes\n", this->m_StripsOffset - this->m_StripGroupsOffset);
  printf(format: "strips:       %7d bytes\n", this->m_VertsOffset - this->m_StripsOffset);
  printf(format: "verts:        %7d bytes\n", this->m_IndicesOffset - this->m_VertsOffset);
  printf(format: "indices:      %7d bytes\n", this->m_BoneStateChangesOffset - this->m_IndicesOffset);
  printf(format: "bone changes: %7d bytes\n", this->m_EndOfFileOffset - this->m_BoneStateChangesOffset);
  printf(format: "everything:   %7d bytes\n", this->m_EndOfFileOffset);
}

//------------------------------------------------------------------------------
// Address: 0x00413460
// Name: private: void OptimizedModel::COptimizedModel::SanityCheckAgainstStudioHDR(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SanityCheckAgainstStudioHDR(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *phdr)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00413470
// Name: private: int OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(struct OptimizedModel::Face_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(
        OptimizedModel::COptimizedModel *this,
        const OptimizedModel::Face_t *face)
{
  int i; // [esp+4h] [ebp-8h]
  int numNewBones; // [esp+8h] [ebp-4h]

  numNewBones = 0;
  for ( i = 0; i < face->numBones; ++i )
  {
    if ( !CHardwareMatrixState::IsMatrixAllocated(this: &this->m_HardwareMatrixState, globalMatrixID: face->boneID[i]) )
      ++numNewBones;
  }
  return numNewBones;
}

//------------------------------------------------------------------------------
// Address: 0x004134D0
// Name: private: bool OptimizedModel::COptimizedModel::AllocateHardwareBonesForFace(struct OptimizedModel::Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::AllocateHardwareBonesForFace(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::Face_t *face)
{
  int bone; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < face->numBones; ++i )
  {
    bone = face->boneID[i];
    if ( !CHardwareMatrixState::IsMatrixAllocated(this: &this->m_HardwareMatrixState, globalMatrixID: bone)
      && !CHardwareMatrixState::AllocateMatrix(this: &this->m_HardwareMatrixState, globalMatrixID: bone) )
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413540
// Name: private: void OptimizedModel::COptimizedModel::SanityCheckVertBones(class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SanityCheckVertBones(
        OptimizedModel::COptimizedModel *this,
        const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *list,
        const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vertices)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00413550
// Name: private: bool OptimizedModel::COptimizedModel::IsVertexFlexed(struct mstudiomesh_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::IsVertexFlexed(
        OptimizedModel::COptimizedModel *this,
        mstudiomesh_t *pStudioMesh,
        int vertID)
{
  unsigned __int8 *pvanim; // [esp+10h] [ebp-14h]
  int j; // [esp+14h] [ebp-10h]
  mstudioflex_t *pflex; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]

  pflex = (mstudioflex_t *)((char *)pStudioMesh + pStudioMesh->flexindex);
  for ( i = 0; i < pStudioMesh->numflexes; ++i )
  {
    pvanim = (unsigned __int8 *)&pflex[i] + pflex[i].vertindex;
    for ( j = 0; j < pflex[i].numverts; ++j )
    {
      if ( *(unsigned __int16 *)pvanim == vertID )
        return 1;
      pvanim += pflex[i].vertanimtype != 0 ? 18 : 16;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413620
// Name: private: void OptimizedModel::COptimizedModel::ComputeStripGroupFlags(struct OptimizedModel::StripGroup_t __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ComputeStripGroupFlags(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::StripGroup_t *pStripGroup,
        bool bIsHWSkinned,
        bool bIsFlexed)
{
  pStripGroup->flags = 0;
  if ( bIsFlexed )
    pStripGroup->flags |= 4u;
  if ( bIsHWSkinned )
    pStripGroup->flags |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x00413670
// Name: OptimizedModel::TryToReduceBoneInfluence
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::TryToReduceBoneInfluence(
        OptimizedModel::Vertex_t *stripGroupVert,
        const mstudioboneweight_t *boneWeights,
        int maxBones)
{
  float minWeight; // [esp+4h] [ebp-Ch]
  int minIndex; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  while ( stripGroupVert->numBones > maxBones )
  {
    minWeight = 2.0;
    minIndex = -1;
    for ( i = 0; i < 3; ++i )
    {
      if ( stripGroupVert->boneID[i] != 255 && minWeight > boneWeights->weight[stripGroupVert->boneWeightIndex[i]] )
      {
        minWeight = boneWeights->weight[stripGroupVert->boneWeightIndex[i]];
        minIndex = i;
      }
    }
    if ( minWeight >= 1.0 )
      break;
    for ( ia = minIndex; ia < 2; ++ia )
    {
      stripGroupVert->boneID[ia] = stripGroupVert->boneID[ia + 1];
      stripGroupVert->boneWeightIndex[ia] = stripGroupVert->boneWeightIndex[ia + 1];
    }
    stripGroupVert->boneID[2] = -1;
    stripGroupVert->boneWeightIndex[2] = 0;
    --stripGroupVert->numBones;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413770
// Name: private: int OptimizedModel::COptimizedModel::CountUniqueBones(int,struct OptimizedModel::Vertex_t __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::CountUniqueBones(
        OptimizedModel::COptimizedModel *this,
        int count,
        OptimizedModel::Vertex_t *pVertex)
{
  int j; // [esp+4h] [ebp-810h]
  int boneID; // [esp+8h] [ebp-80Ch]
  int i; // [esp+Ch] [ebp-808h]
  int uniqueBoneCount; // [esp+10h] [ebp-804h]
  int uniqueBoneList[512]; // [esp+14h] [ebp-800h]

  uniqueBoneCount = 0;
  while ( --count >= 0 )
  {
    for ( i = 0; i < pVertex[count].numBones; ++i )
    {
      boneID = pVertex[count].boneID[i];
      j = uniqueBoneCount;
      do
        --j;
      while ( j >= 0 && uniqueBoneList[j] != boneID );
      if ( j < 0 )
        uniqueBoneList[uniqueBoneCount++] = boneID;
    }
  }
  return uniqueBoneCount;
}

//------------------------------------------------------------------------------
// Address: 0x00413860
// Name: private: int OptimizedModel::COptimizedModel::CountMaxVertBones(int,struct OptimizedModel::Vertex_t __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::CountMaxVertBones(
        OptimizedModel::COptimizedModel *this,
        int count,
        OptimizedModel::Vertex_t *pVertex)
{
  int maxBones; // [esp+4h] [ebp-4h]

  maxBones = 0;
  while ( --count >= 0 )
  {
    if ( maxBones < pVertex[count].numBones )
      maxBones = pVertex[count].numBones;
  }
  return maxBones;
}

//------------------------------------------------------------------------------
// Address: 0x004138B0
// Name: OptimizedModel::StripVertLookup_CompareFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl OptimizedModel::StripVertLookup_CompareFunc(
        const OptimizedModel::StripVertLookup_t *a,
        const OptimizedModel::StripVertLookup_t *b)
{
  return a->origMeshVertID == b->origMeshVertID;
}

//------------------------------------------------------------------------------
// Address: 0x004138D0
// Name: OptimizedModel::StripVertLookup_KeyFunc
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl OptimizedModel::StripVertLookup_KeyFunc(const OptimizedModel::StripVertLookup_t *a)
{
  return HashInt(n: a->origMeshVertID);
}

//------------------------------------------------------------------------------
// Address: 0x004138E0
// Name: private: bool OptimizedModel::COptimizedModel::MeshIsTeeth(struct studiohdr_t __near *,struct mstudiomesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::MeshIsTeeth(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pStudioHeader,
        mstudiomesh_t *pStudioMesh)
{
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < pStudioHeader->numskinfamilies; ++i )
  {
    if ( *(int *)((char *)&pStudioHeader->version
                + 64
                * *(__int16 *)((char *)&pStudioHeader->id
                             + 2 * pStudioHeader->numskinref * i
                             + 2 * pStudioMesh->material
                             + pStudioHeader->skinindex)
                + pStudioHeader->textureindex) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413970
// Name: private: void OptimizedModel::COptimizedModel::ComputeMeshFlags(struct OptimizedModel::Mesh_t __near *,struct studiohdr_t __near *,struct mstudiomesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ComputeMeshFlags(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::Mesh_t *pMesh,
        studiohdr_t *pStudioHeader,
        mstudiomesh_t *pStudioMesh)
{
  pMesh->flags = 0;
  if ( pStudioMesh->materialtype != 0 )
    pMesh->flags |= 2u;
  if ( OptimizedModel::COptimizedModel::MeshIsTeeth(this, pStudioHeader, pStudioMesh) != 0 )
    pMesh->flags |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x004139D0
// Name: private: void OptimizedModel::COptimizedModel::SetupMeshProcessing(struct studiohdr_t __near *,int,bool,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SetupMeshProcessing(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        int vertexCacheSize,
        bool usesFixedFunction,
        int maxBonesPerVert,
        int maxBonesPerFace,
        int maxBonesPerStrip,
        const char *fileName)
{
  SetCacheSize(_cacheSize: vertexCacheSize);
  SetStitchStrips(_bStitchStrips: true);
  SetMinStripSize(_minStripSize: 0);
  SetListsOnly(_bListsOnly: true);
  if ( !g_quiet )
  {
    printf(format: "---------------------\n");
    printf(format: "Generating optimized mesh \"%s\":\n", fileName);
  }
  OptimizedModel::COptimizedModel::CleanupEverything(this);
  this->m_NumBones = pHdr->numbones;
  this->m_MaxBonesPerVert = maxBonesPerVert;
  this->m_MaxBonesPerFace = maxBonesPerFace;
  this->m_MaxBonesPerStrip = maxBonesPerStrip;
  this->m_bUsesFixedFunction = usesFixedFunction;
  this->m_VertexCacheSize = vertexCacheSize;
  this->m_NumSkinnedAndFlexedVerts = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413A80
// Name: OptimizedModel::RandomColor
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::RandomColor(Vector *color)
{
  color->x = (float)rand() / 32767.0;
  color->y = (float)rand() / 32767.0;
  color->z = (float)rand() / 32767.0;
  VectorNormalize(vec: color);
}

//------------------------------------------------------------------------------
// Address: 0x00413B00
// Name: bool OptimizedModel::ComparePath(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl OptimizedModel::ComparePath(const char *a, const char *b)
{
  int v3; // esi

  if ( strlen(a) != strlen(b) )
    return 0;
  while ( *a != 0 )
  {
    if ( *a != *b )
    {
      v3 = tolower(c: *a);
      if ( v3 != tolower(c: *b) && (*a != 47 && *a != 92 || *b != 47 && *b != 92) )
        return 0;
    }
    ++a;
    ++b;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413C10
// Name: private: void OptimizedModel::COptimizedModel::ZeroNumBones(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ZeroNumBones(OptimizedModel::COptimizedModel *this)
{
  int v1; // eax
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+20h] [ebp-34h]
  OptimizedModel::MeshHeader_t *pMesh; // [esp+24h] [ebp-30h]
  OptimizedModel::ModelLODHeader_t *pLOD; // [esp+28h] [ebp-2Ch]
  OptimizedModel::ModelHeader_t *pModel; // [esp+2Ch] [ebp-28h]
  OptimizedModel::BodyPartHeader_t *pBodyPart; // [esp+30h] [ebp-24h]
  unsigned __int8 *header; // [esp+34h] [ebp-20h]
  int modelID; // [esp+38h] [ebp-1Ch]
  int meshID; // [esp+3Ch] [ebp-18h]
  int stripID; // [esp+40h] [ebp-14h]
  int stripGroupID; // [esp+44h] [ebp-10h]
  int vertID; // [esp+48h] [ebp-Ch]
  int bodyPartID; // [esp+4Ch] [ebp-8h]
  int lodID; // [esp+50h] [ebp-4h]

  header = this->m_FileBuffer->m_pData;
  for ( bodyPartID = 0; bodyPartID < *((_DWORD *)header + 7); ++bodyPartID )
  {
    pBodyPart = (OptimizedModel::BodyPartHeader_t *)&header[8 * bodyPartID + *((_DWORD *)header + 8)];
    for ( modelID = 0; modelID < pBodyPart->numModels; ++modelID )
    {
      pModel = (OptimizedModel::ModelHeader_t *)((char *)&pBodyPart[modelID] + pBodyPart->modelOffset);
      for ( lodID = 0; lodID < pModel->numLODs; ++lodID )
      {
        pLOD = (OptimizedModel::ModelLODHeader_t *)((char *)pModel + 12 * lodID + pModel->lodOffset);
        for ( meshID = 0; meshID < pLOD->numMeshes; ++meshID )
        {
          pMesh = (OptimizedModel::MeshHeader_t *)((char *)pLOD + 9 * meshID + pLOD->meshOffset);
          for ( stripGroupID = 0; stripGroupID < pMesh->numStripGroups; ++stripGroupID )
          {
            pStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)pMesh
                                                               + 33 * stripGroupID
                                                               + pMesh->stripGroupHeaderOffset);
            for ( vertID = 0; vertID < pStripGroup->numVerts; ++vertID )
              *((_BYTE *)&pStripGroup->numVerts + 9 * vertID + pStripGroup->vertOffset + 3) = 0;
            for ( stripID = 0; stripID < pStripGroup->numStrips; ++stripID )
            {
              v1 = (int)pStripGroup + 35 * stripID + pStripGroup->stripOffset;
              *(_WORD *)(v1 + 16) = 0;
              *(_DWORD *)(v1 + 19) = 0;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413DE0
// Name: OptimizedModel::MergeLikeBoneIndicesWithinVert
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::MergeLikeBoneIndicesWithinVert(mstudioboneweight_t *pBoneWeight)
{
  int k; // [esp+4h] [ebp-18h]
  int j; // [esp+8h] [ebp-14h]
  int ja; // [esp+8h] [ebp-14h]
  unsigned __int8 tmpIndex; // [esp+Ch] [ebp-10h]
  float tmpWeight; // [esp+10h] [ebp-Ch]
  unsigned __int8 realNumBones; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  if ( pBoneWeight->numbones != 1 )
  {
    realNumBones = pBoneWeight->numbones;
    for ( i = 0; i < pBoneWeight->numbones; ++i )
    {
      for ( j = i + 1; j < pBoneWeight->numbones; ++j )
      {
        if ( pBoneWeight->bone[i] == pBoneWeight->bone[j] && pBoneWeight->weight[i] != 0.0 )
        {
          pBoneWeight->weight[i] = pBoneWeight->weight[i] + pBoneWeight->weight[j];
          pBoneWeight->weight[j] = 0.0;
          --realNumBones;
        }
      }
    }
    for ( ja = pBoneWeight->numbones; ja > 1; --ja )
    {
      for ( k = 0; k < ja - 1; ++k )
      {
        if ( pBoneWeight->weight[k] == 0.0 && pBoneWeight->weight[k + 1] != 0.0 )
        {
          tmpIndex = pBoneWeight->bone[k];
          tmpWeight = pBoneWeight->weight[k];
          pBoneWeight->bone[k] = pBoneWeight->bone[k + 1];
          pBoneWeight->weight[k] = pBoneWeight->weight[k + 1];
          pBoneWeight->bone[k + 1] = tmpIndex;
          pBoneWeight->weight[k + 1] = tmpWeight;
        }
      }
    }
    pBoneWeight->numbones = realNumBones;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413FB0
// Name: OptimizedModel::MergeLikeBoneIndicesWithinVerts
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::MergeLikeBoneIndicesWithinVerts(studiohdr_t *pHdr)
{
  const mstudio_modelvertexdata_t *vertData; // [esp+10h] [ebp-1Ch]
  mstudiomodel_t *pModel; // [esp+18h] [ebp-14h]
  mstudiobodyparts_t *pBodyPart; // [esp+1Ch] [ebp-10h]
  int modelID; // [esp+20h] [ebp-Ch]
  int vertID; // [esp+24h] [ebp-8h]
  int bodyPartID; // [esp+28h] [ebp-4h]

  for ( bodyPartID = 0; bodyPartID < pHdr->numbodyparts; ++bodyPartID )
  {
    pBodyPart = (mstudiobodyparts_t *)((char *)pHdr + 16 * bodyPartID + pHdr->bodypartindex);
    for ( modelID = 0; modelID < pBodyPart->nummodels; ++modelID )
    {
      pModel = (mstudiomodel_t *)((char *)pBodyPart + 148 * modelID + pBodyPart->modelindex);
      for ( vertID = 0; vertID < pModel->numvertices; ++vertID )
      {
        vertData = mstudiomodel_t::GetVertexData(this: pModel, pModelData: nullptr);
        OptimizedModel::MergeLikeBoneIndicesWithinVert(
          pBoneWeight: (mstudioboneweight_t *)vertData->pVertexData
        + 3 * vertID
        + 3 * ((unsigned int)vertData[-3].pVertexData / 0x30));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004140A0
// Name: private: void OptimizedModel::COptimizedModel::SetMeshPropsColor(unsigned int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SetMeshPropsColor(
        OptimizedModel::COptimizedModel *this,
        char meshFlags,
        Vector *color)
{
  if ( (meshFlags & 1) != 0 )
  {
    color->x = 1.0;
    color->y = 0.0;
    color->z = 0.0;
  }
  else
  {
    if ( (meshFlags & 2) != 0 )
      color->x = 1.0;
    else
      color->x = 0.0;
    color->y = 1.0;
    color->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004141A0
// Name: private: void OptimizedModel::COptimizedModel::SetFlexedAndSkinColor(unsigned int,unsigned int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SetFlexedAndSkinColor(
        OptimizedModel::COptimizedModel *this,
        char glViewFlags,
        char stripGroupFlags,
        Vector *color)
{
  if ( (glViewFlags & 0x10) != 0 && (glViewFlags & 0x20) != 0 )
  {
    if ( (stripGroupFlags & 4) != 0 && (stripGroupFlags & 2) != 0 )
    {
      color->x = 1.0;
      color->y = 1.0;
      color->z = 0.0;
    }
    else if ( (stripGroupFlags & 4) != 0 || (stripGroupFlags & 2) == 0 )
    {
      if ( (stripGroupFlags & 4) != 0 || (stripGroupFlags & 2) != 0 )
      {
        if ( (stripGroupFlags & 4) != 0 && (stripGroupFlags & 2) == 0 )
        {
          color->x = 1.0;
          color->y = 0.0;
          color->z = 0.0;
        }
      }
      else
      {
        color->x = 0.0;
        color->y = 0.0;
        color->z = 1.0;
      }
    }
    else
    {
      color->x = 0.0;
      color->y = 1.0;
      color->z = 0.0;
    }
  }
  else if ( (glViewFlags & 0x10) != 0 )
  {
    if ( (stripGroupFlags & 4) != 0 )
    {
      color->x = 1.0;
      color->y = 0.0;
    }
    else
    {
      color->x = 0.0;
      color->y = 1.0;
    }
    color->z = 0.0;
  }
  else if ( (glViewFlags & 0x20) != 0 )
  {
    if ( (stripGroupFlags & 2) != 0 )
    {
      color->x = 0.0;
      color->y = 1.0;
    }
    else
    {
      color->x = 1.0;
      color->y = 0.0;
    }
    color->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414470
// Name: private: void OptimizedModel::COptimizedModel::DrawGLViewTriangle(struct _iobuf __near *,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::DrawGLViewTriangle(
        OptimizedModel::COptimizedModel *this,
        _iobuf *fp,
        Vector *pos1,
        Vector *pos2,
        Vector *pos3,
        Vector *color1,
        Vector *color2,
        Vector *color3)
{
  ++numGLViewTrangles;
  fprintf(str: fp, format: "3\n");
  fprintf(str: fp, format: "%f %f %f %f %f %f\n", pos1->x, pos1->y, pos1->z, color1->x, color1->y, color1->z);
  fprintf(str: fp, format: "%f %f %f %f %f %f\n", pos2->x, pos2->y, pos2->z, color2->x, color2->y, color2->z);
  fprintf(str: fp, format: "%f %f %f %f %f %f\n", pos3->x, pos3->y, pos3->z, color3->x, color3->y, color3->z);
}

//------------------------------------------------------------------------------
// Address: 0x004146B0
// Name: private: void OptimizedModel::COptimizedModel::GLViewDrawEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::GLViewDrawEnd(OptimizedModel::COptimizedModel *this)
{
  s_DrawMode = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004146D0
// Name: private: void OptimizedModel::COptimizedModel::GLViewDrawBegin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::GLViewDrawBegin(OptimizedModel::COptimizedModel *this, int mode)
{
  s_DrawMode = mode;
  s_ListID = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004146F0
// Name: private: void OptimizedModel::COptimizedModel::ShrinkVerts(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ShrinkVerts(OptimizedModel::COptimizedModel *this, float shrinkFactor)
{
  Vector *v2; // eax
  float delta_4; // [esp+18h] [ebp-18h]
  float delta_8; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float center; // [esp+24h] [ebp-Ch]
  float center_4; // [esp+28h] [ebp-8h]
  float center_8; // [esp+2Ch] [ebp-4h]

  center = (float)((float)(s_LastThreePositions[0].x + s_LastThreePositions[1].x) + s_LastThreePositions[2].x)
         * 0.33333334;
  center_4 = (float)((float)(s_LastThreePositions[0].y + s_LastThreePositions[1].y) + s_LastThreePositions[2].y)
           * 0.33333334;
  center_8 = (float)((float)(s_LastThreePositions[0].z + s_LastThreePositions[1].z) + s_LastThreePositions[2].z)
           * 0.33333334;
  for ( i = 0; i < 3; ++i )
  {
    if ( !s_Shrunk[i] )
    {
      delta_4 = (float)(s_LastThreePositions[i].y - center_4) * shrinkFactor;
      delta_8 = (float)(s_LastThreePositions[i].z - center_8) * shrinkFactor;
      s_LastThreePositions[i].x = center + (float)((float)(s_LastThreePositions[i].x - center) * shrinkFactor);
      v2 = &s_LastThreePositions[i];
      v2->y = center_4 + delta_4;
      v2->z = center_8 + delta_8;
      s_Shrunk[i] = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004148D0
// Name: private: void OptimizedModel::COptimizedModel::RemoveRedundantBoneStateChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::RemoveRedundantBoneStateChanges(OptimizedModel::COptimizedModel *this)
{
  OptimizedModel::BoneStateChangeHeader_t *boneStateChange; // [esp+18h] [ebp-C44h]
  int boneStateChangeID; // [esp+1Ch] [ebp-C40h]
  OptimizedModel::StripHeader_t *pStrip; // [esp+20h] [ebp-C3Ch]
  int stripID; // [esp+24h] [ebp-C38h]
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+28h] [ebp-C34h]
  int stripGroupID; // [esp+2Ch] [ebp-C30h]
  OptimizedModel::MeshHeader_t *mesh; // [esp+30h] [ebp-C2Ch]
  int meshID; // [esp+34h] [ebp-C28h]
  OptimizedModel::ModelLODHeader_t *pLOD; // [esp+38h] [ebp-C24h]
  int lodID; // [esp+3Ch] [ebp-C20h]
  OptimizedModel::ModelHeader_t *model; // [esp+40h] [ebp-C1Ch]
  int modelID; // [esp+44h] [ebp-C18h]
  OptimizedModel::BodyPartHeader_t *bodyPart; // [esp+48h] [ebp-C14h]
  int hardwareBoneState[512]; // [esp+4Ch] [ebp-C10h]
  bool allocated[516]; // [esp+84Ch] [ebp-410h]
  int i; // [esp+A50h] [ebp-20Ch]
  bool changed[512]; // [esp+A54h] [ebp-208h]
  int bodyPartID; // [esp+C54h] [ebp-8h]
  OptimizedModel::FileHeader_t *header; // [esp+C58h] [ebp-4h]

  header = (OptimizedModel::FileHeader_t *)this->m_FileBuffer->m_pData;
  for ( bodyPartID = 0; bodyPartID < header->numBodyParts; ++bodyPartID )
  {
    bodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)header + 8 * bodyPartID + header->bodyPartOffset);
    for ( i = 0; i < 512; ++i )
    {
      hardwareBoneState[i] = -1;
      allocated[i] = false;
    }
    for ( modelID = 0; modelID < bodyPart->numModels; ++modelID )
    {
      model = (OptimizedModel::ModelHeader_t *)((char *)&bodyPart[modelID] + bodyPart->modelOffset);
      for ( lodID = 0; lodID < model->numLODs; ++lodID )
      {
        pLOD = (OptimizedModel::ModelLODHeader_t *)((char *)model + 12 * lodID + model->lodOffset);
        for ( meshID = 0; meshID < pLOD->numMeshes; ++meshID )
        {
          mesh = (OptimizedModel::MeshHeader_t *)((char *)pLOD + 9 * meshID + pLOD->meshOffset);
          for ( stripGroupID = 0; stripGroupID < mesh->numStripGroups; ++stripGroupID )
          {
            pStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)mesh
                                                               + 33 * stripGroupID
                                                               + mesh->stripGroupHeaderOffset);
            if ( (pStripGroup->flags & 2) != 0 )
            {
              for ( stripID = 0; stripID < pStripGroup->numStrips; ++stripID )
              {
                pStrip = (OptimizedModel::StripHeader_t *)((char *)pStripGroup + 35 * stripID + pStripGroup->stripOffset);
                for ( i = 0; i < 512; ++i )
                  changed[i] = false;
                for ( boneStateChangeID = 0; boneStateChangeID < pStrip->numBoneStateChanges; ++boneStateChangeID )
                {
                  boneStateChange = (OptimizedModel::BoneStateChangeHeader_t *)((char *)pStrip
                                                                              + 8 * boneStateChangeID
                                                                              + pStrip->boneStateChangeOffset);
                  if ( !allocated[boneStateChange->hardwareID]
                    || hardwareBoneState[boneStateChange->hardwareID] != boneStateChange->newBoneID )
                  {
                    changed[boneStateChange->hardwareID] = true;
                    allocated[boneStateChange->hardwareID] = true;
                    hardwareBoneState[boneStateChange->hardwareID] = boneStateChange->newBoneID;
                  }
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
// Address: 0x00414C60
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)MemAlloc_Alloc(nSize: 20 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414CF0
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  unsigned __int16 *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 2);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 2 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (unsigned __int16 *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414D70
// Name: public: void CUtlMemory<struct OptimizedModel::SubD_Face_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
        CUtlMemory<OptimizedModel::SubD_Face_t,int> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::SubD_Face_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 300);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 300 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::SubD_Face_t *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v8);
    else
      this->m_pMemory = (OptimizedModel::SubD_Face_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414E00
// Name: public: void CUtlMemory<struct OptimizedModel::Model_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Model_t,int>::Grow(CUtlMemory<OptimizedModel::Model_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::Model_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 20);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 20 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Model_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::Model_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414F60
// Name: private: bool OptimizedModel::COptimizedModel::GenerateStripGroupVerticesFromFace(struct mstudioiface_t __near *,struct mstudiomesh_t __near *,int,struct OptimizedModel::Vertex_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall OptimizedModel::COptimizedModel::GenerateStripGroupVerticesFromFace(
        OptimizedModel::COptimizedModel *this,
        mstudioiface_t *pFace,
        mstudiomesh_t *pStudioMesh,
        int maxPreferredBones,
        OptimizedModel::Vertex_t *pStripGroupVert,
        bool bQuadSubd)
{
  bool v7; // [esp+0h] [ebp-54h]
  int boneID; // [esp+24h] [ebp-30h]
  mstudioboneweight_t *pBoneWeight; // [esp+28h] [ebp-2Ch]
  int bonesAffectingVertex; // [esp+2Ch] [ebp-28h]
  int vertex; // [esp+30h] [ebp-24h]
  int faceIndex; // [esp+34h] [ebp-20h]
  int vertIDs[4]; // [esp+38h] [ebp-1Ch]
  bool bFaceIsFlexed; // [esp+4Bh] [ebp-9h]
  const mstudio_meshvertexdata_t *vertData; // [esp+4Ch] [ebp-8h]
  int numVerts; // [esp+50h] [ebp-4h]

  vertIDs[0] = pFace->a;
  vertIDs[1] = pFace->b;
  vertIDs[2] = pFace->c;
  vertIDs[3] = pFace->d;
  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  bFaceIsFlexed = false;
  numVerts = bQuadSubd + 3;
  for ( faceIndex = 0; faceIndex < numVerts; ++faceIndex )
  {
    vertex = vertIDs[faceIndex];
    v7 = bFaceIsFlexed || OptimizedModel::COptimizedModel::IsVertexFlexed(this, pStudioMesh, vertID: vertex) != 0;
    bFaceIsFlexed = v7;
    pBoneWeight = (mstudioboneweight_t *)((char *)vertData->modelvertexdata->pVertexData
                                        + 48
                                        * ((int)vertData[-1].modelvertexdata
                                         + vertex
                                         + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30));
    bonesAffectingVertex = pBoneWeight->numbones;
    if ( g_staticprop || pBoneWeight->numbones != 0 )
    {
      if ( pBoneWeight->numbones > 3u )
        MdlError(fmt: "too many bones/vert (%d) : MAX_NUM_BONES_PER_VERT needs to be upped\n", bonesAffectingVertex);
    }
    else
    {
      MdlWarning(fmt: "too few bones/vert (%d) : it has no bones!\n", bonesAffectingVertex);
    }
    pStripGroupVert[faceIndex].origMeshVertID = vertex;
    pStripGroupVert[faceIndex].numBones = bonesAffectingVertex;
    for ( boneID = 0; boneID < bonesAffectingVertex; ++boneID )
    {
      pStripGroupVert[faceIndex].boneID[boneID] = pBoneWeight->bone[boneID];
      pStripGroupVert[faceIndex].boneWeightIndex[boneID] = boneID;
    }
    while ( boneID < 3 )
    {
      pStripGroupVert[faceIndex].boneID[boneID] = -1;
      pStripGroupVert[faceIndex].boneWeightIndex[boneID] = boneID;
      ++boneID;
    }
    if ( !this->m_bUsesFixedFunction && maxPreferredBones > 0 && bonesAffectingVertex > maxPreferredBones )
      OptimizedModel::TryToReduceBoneInfluence(
        stripGroupVert: &pStripGroupVert[faceIndex],
        boneWeights: pBoneWeight,
        maxBones: maxPreferredBones);
  }
  return bFaceIsFlexed;
}

//------------------------------------------------------------------------------
// Address: 0x004151B0
// Name: private: int OptimizedModel::COptimizedModel::GetTotalStripGroupsForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall OptimizedModel::COptimizedModel::GetTotalStripGroupsForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  return CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
}

//------------------------------------------------------------------------------
// Address: 0x004151D0
// Name: private: void OptimizedModel::COptimizedModel::WriteHeader(int,int,int,int,int,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteHeader(
        OptimizedModel::COptimizedModel *this,
        int vertCacheSize,
        unsigned int maxBonesPerVert,
        unsigned int maxBonesPerFace,
        unsigned int maxBonesPerStrip,
        int numBodyParts,
        unsigned int checkSum)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-28h]
  OptimizedModel::FileHeader_t fileHeader; // 0:^14.36

  fileHeader.version = 7;
  fileHeader.vertCacheSize = vertCacheSize;
  fileHeader.maxBonesPerFace = IsUShort(val: maxBonesPerFace);
  *(_QWORD *)&fileHeader.maxBonesPerVert = __PAIR64__(checkSum, maxBonesPerVert);
  fileHeader.maxBonesPerStrip = IsUShort(val: maxBonesPerStrip);
  *(_QWORD *)&fileHeader.numBodyParts = (unsigned int)numBodyParts | 0x2400000000LL;
  fileHeader.numLODs = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  fileHeader.materialReplacementListOffset = this->m_MaterialReplacementsListOffset;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = m_FileBuffer->m_pData;
  *(OptimizedModel::FileHeader_t *)m_FileBuffer->m_pCurPos = fileHeader;
  m_FileBuffer->m_pCurPos += 36;
}

//------------------------------------------------------------------------------
// Address: 0x00415280
// Name: private: void OptimizedModel::COptimizedModel::WriteBodyPart(int,struct mstudiobodyparts_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteBodyPart(
        OptimizedModel::COptimizedModel *this,
        int bodyPartID,
        mstudiobodyparts_t *pBodyPart,
        int modelID)
{
  _DWORD *m_pCurPos; // edx
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-14h]
  int bodyPartOffset; // [esp+Ch] [ebp-Ch]
  int bodyPart; // [esp+10h] [ebp-8h]
  int bodyPart_4; // [esp+14h] [ebp-4h]

  bodyPart = pBodyPart->nummodels;
  bodyPartOffset = this->m_BodyPartsOffset + 8 * bodyPartID;
  bodyPart_4 = this->m_ModelsOffset + 8 * modelID - bodyPartOffset;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[bodyPartOffset];
  m_pCurPos = m_FileBuffer->m_pCurPos;
  *m_pCurPos = bodyPart;
  m_pCurPos[1] = bodyPart_4;
  m_FileBuffer->m_pCurPos += 8;
}

//------------------------------------------------------------------------------
// Address: 0x00415300
// Name: private: void OptimizedModel::COptimizedModel::WriteModel(int,struct mstudiomodel_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteModel(
        OptimizedModel::COptimizedModel *this,
        int modelID,
        mstudiomodel_t *pModel,
        int lodID)
{
  const char *v4; // eax
  char v5; // al
  unsigned __int8 *m_pCurPos; // edx
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-14h]
  int modelFileOffset; // [esp+8h] [ebp-10h]
  int model_4; // [esp+10h] [ebp-8h]

  v4 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  v5 = IsChar(val: (int)v4);
  modelFileOffset = this->m_ModelsOffset + 8 * modelID;
  model_4 = this->m_ModelLODsOffset + 12 * lodID - modelFileOffset;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[modelFileOffset];
  m_pCurPos = m_FileBuffer->m_pCurPos;
  *(_DWORD *)m_pCurPos = v5;
  *((_DWORD *)m_pCurPos + 1) = model_4;
  m_FileBuffer->m_pCurPos += 8;
}

//------------------------------------------------------------------------------
// Address: 0x00415390
// Name: private: void OptimizedModel::COptimizedModel::WriteModelLOD(int,struct OptimizedModel::ModelLOD_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteModelLOD(
        OptimizedModel::COptimizedModel *this,
        int lodID,
        ConCommandBase *pLOD,
        int meshID)
{
  float *m_pCurPos; // eax
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-18h]
  const char *lod; // [esp+8h] [ebp-14h]
  int lod_4; // [esp+Ch] [ebp-10h]
  float lod_8; // [esp+10h] [ebp-Ch]
  int lodFileOffset; // [esp+14h] [ebp-8h]

  lodFileOffset = this->m_ModelLODsOffset + 12 * lodID;
  lod_4 = this->m_MeshesOffset + 9 * meshID - lodFileOffset;
  lod = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pLOD);
  lod_8 = *(float *)&pLOD->m_nFlags;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[lodFileOffset];
  m_pCurPos = (float *)m_FileBuffer->m_pCurPos;
  *(_DWORD *)m_pCurPos = lod;
  *((_DWORD *)m_pCurPos + 1) = lod_4;
  m_pCurPos[2] = lod_8;
  m_FileBuffer->m_pCurPos += 12;
}

//------------------------------------------------------------------------------
// Address: 0x00415420
// Name: private: void OptimizedModel::COptimizedModel::WriteMesh(int,struct OptimizedModel::Mesh_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteMesh(
        OptimizedModel::COptimizedModel *this,
        int meshID,
        ConCommandBase *pMesh,
        int stripGroupID)
{
  const char *v4; // eax
  char v5; // al
  unsigned __int8 *m_pCurPos; // edx
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-18h]
  int mesh_4; // [esp+Ch] [ebp-10h]
  unsigned __int8 mesh_8; // [esp+10h] [ebp-Ch]
  int meshFileOffset; // [esp+14h] [ebp-8h]

  v4 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
  v5 = IsChar(val: (int)v4);
  meshFileOffset = this->m_MeshesOffset + 9 * meshID;
  mesh_4 = this->m_StripGroupsOffset + 33 * stripGroupID - meshFileOffset;
  mesh_8 = pMesh->m_nFlags;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[meshFileOffset];
  m_pCurPos = m_FileBuffer->m_pCurPos;
  *(_DWORD *)m_pCurPos = v5;
  *((_DWORD *)m_pCurPos + 1) = mesh_4;
  m_pCurPos[8] = mesh_8;
  m_FileBuffer->m_pCurPos += 9;
}

//------------------------------------------------------------------------------
// Address: 0x004154C0
// Name: private: void OptimizedModel::COptimizedModel::WriteStripGroup(int,struct OptimizedModel::StripGroup_t __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteStripGroup(
        OptimizedModel::COptimizedModel *this,
        int stripGroupID,
        ConCommandBase *pStripGroup,
        int vertID,
        int indexID,
        int topologyID,
        int stripID)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-3Ch]
  int stripGroupFileOffset; // [esp+3Ch] [ebp-4h]
  OptimizedModel::StripGroupHeader_t stripGroup; // 0:^1C.33

  stripGroup.numVerts = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 40));
  stripGroup.numIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
  stripGroup.numTopologyIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->m_nFlags);
  stripGroup.numStrips = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 60));
  stripGroup.flags = IsByte(val: *(_DWORD *)&pStripGroup[3].m_bRegistered);
  stripGroupFileOffset = this->m_StripGroupsOffset + 33 * stripGroupID;
  stripGroup.vertOffset = this->m_VertsOffset + 9 * vertID - stripGroupFileOffset;
  stripGroup.indexOffset = this->m_IndicesOffset + 2 * indexID - stripGroupFileOffset;
  stripGroup.topologyOffset = this->m_TopologyOffset + 2 * topologyID - stripGroupFileOffset;
  stripGroup.stripOffset = this->m_StripsOffset + 35 * stripID - stripGroupFileOffset;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[stripGroupFileOffset];
  *(OptimizedModel::StripGroupHeader_t *)m_FileBuffer->m_pCurPos = stripGroup;
  m_FileBuffer->m_pCurPos += 33;
}

//------------------------------------------------------------------------------
// Address: 0x004155D0
// Name: private: void OptimizedModel::COptimizedModel::WriteStrip(int,struct OptimizedModel::Strip_t __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteStrip(
        OptimizedModel::COptimizedModel *this,
        int stripID,
        OptimizedModel::Strip_t *pStrip,
        int indexID,
        int curTopology,
        int vertID,
        int boneID)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-30h]
  int stripFileOffset; // [esp+2Ch] [ebp-8h]
  OptimizedModel::StripHeader_t stripHeader; // 0:^14.35

  stripHeader.numIndices = pStrip->numStripGroupIndices;
  stripHeader.numTopologyIndices = pStrip->numStripGroupTopologyIndices;
  stripHeader.indexOffset = pStrip->stripGroupIndexOffset;
  stripHeader.topologyOffset = pStrip->stripGroupTopologyOffset;
  stripHeader.numVerts = pStrip->numStripGroupVerts;
  stripHeader.vertOffset = pStrip->stripGroupVertexOffset;
  stripHeader.numBoneStateChanges = pStrip->numBoneStateChanges;
  stripHeader.numBones = IsShort(val: pStrip->numBones);
  stripHeader.flags = IsByte(val: pStrip->flags);
  stripFileOffset = this->m_StripsOffset + 35 * stripID;
  stripHeader.boneStateChangeOffset = IsInt24(val: this->m_BoneStateChangesOffset + 8 * boneID - stripFileOffset);
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[stripFileOffset];
  *(OptimizedModel::StripHeader_t *)m_FileBuffer->m_pCurPos = stripHeader;
  m_FileBuffer->m_pCurPos += 35;
}

//------------------------------------------------------------------------------
// Address: 0x004156B0
// Name: private: void OptimizedModel::COptimizedModel::WriteBoneStateChange(int,struct OptimizedModel::BoneStateChange_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteBoneStateChange(
        OptimizedModel::COptimizedModel *this,
        int boneID,
        OptimizedModel::BoneStateChange_t *boneStateChange)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-10h]
  OptimizedModel::BoneStateChange_t boneHeader; // 0:^8.8

  boneHeader = *boneStateChange;
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[8 * boneID + this->m_BoneStateChangesOffset];
  *(OptimizedModel::BoneStateChange_t *)m_FileBuffer->m_pCurPos = boneHeader;
  m_FileBuffer->m_pCurPos += 8;
}

//------------------------------------------------------------------------------
// Address: 0x004157C0
// Name: private: float OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::Vertex_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        OptimizedModel::Vertex_t *pVert,
        int boneID)
{
  mstudio_meshvertexdata_t *vertData; // [esp+24h] [ebp-4h]

  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  return *((float *)vertData->modelvertexdata->pVertexData
         + 12
         * ((int)vertData[-1].modelvertexdata
          + pVert->origMeshVertID
          + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30)
         + pVert->boneWeightIndex[boneID]);
}

//------------------------------------------------------------------------------
// Address: 0x00415870
// Name: private: struct mstudioboneweight_t __near & OptimizedModel::COptimizedModel::GetOrigVertBoneWeight(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::Vertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
mstudioboneweight_t *__thiscall OptimizedModel::COptimizedModel::GetOrigVertBoneWeight(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        OptimizedModel::Vertex_t *pVert)
{
  mstudio_meshvertexdata_t *vertData; // [esp+20h] [ebp-4h]

  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  return (mstudioboneweight_t *)((char *)vertData->modelvertexdata->pVertexData
                               + 48
                               * ((int)vertData[-1].modelvertexdata
                                + pVert->origMeshVertID
                                + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30));
}

//------------------------------------------------------------------------------
// Address: 0x00415910
// Name: private: int OptimizedModel::COptimizedModel::GetOrigVertBoneIndex(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::Vertex_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetOrigVertBoneIndex(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        OptimizedModel::Vertex_t *pVert,
        int boneID)
{
  mstudio_meshvertexdata_t *vertData; // [esp+20h] [ebp-4h]

  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  return *((unsigned __int8 *)vertData->modelvertexdata->pVertexData
         + 48
         * ((int)vertData[-1].modelvertexdata
          + pVert->origMeshVertID
          + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30)
         + pVert->boneWeightIndex[boneID]
         + 12);
}

//------------------------------------------------------------------------------
// Address: 0x004159C0
// Name: private: void OptimizedModel::COptimizedModel::GLViewVert(struct _iobuf __near *,struct OptimizedModel::Vertex_t,int,class Vector __near &,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::GLViewVert(
        OptimizedModel::COptimizedModel *this,
        _iobuf *fp,
        OptimizedModel::Vertex_t vert,
        int index,
        Vector *color,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        bool showSubStrips,
        float shrinkFactor)
{
  OptimizedModel::Vertex_t *v9; // ecx
  int id; // [esp+10h] [ebp-4h]

  id = s_ListID % 3;
  s_LastThreeIndices[s_ListID % 3] = index;
  v9 = &s_LastThreeVerts[id];
  *v9 = vert;
  s_Shrunk[id] = false;
  s_LastThreePositions[id] = *OptimizedModel::COptimizedModel::GetOrigVertPosition(
                                this,
                                pStudioModel,
                                pStudioMesh,
                                pVert: v9);
  if ( s_DrawMode != 0 )
  {
    if ( s_ListID >= 2 )
    {
      if ( s_LastThreeIndices[0] == s_LastThreeIndices[1]
        || s_LastThreeIndices[1] == s_LastThreeIndices[2]
        || s_LastThreeIndices[0] == s_LastThreeIndices[2] )
      {
        ++numGLViewHWDegenerates;
        if ( showSubStrips )
          OptimizedModel::RandomColor(color);
      }
      else if ( (s_ListID & 1) != 0 )
      {
        OptimizedModel::COptimizedModel::ShrinkVerts(this, shrinkFactor);
        OptimizedModel::COptimizedModel::DrawGLViewTriangle(
          this,
          fp,
          pos1: &s_LastThreePositions[(id + 3) % 3],
          pos2: &s_LastThreePositions[(id + 2) % 3],
          pos3: &s_LastThreePositions[(id + 1) % 3],
          color1: color,
          color2: color,
          color3: color);
      }
      else
      {
        OptimizedModel::COptimizedModel::ShrinkVerts(this, shrinkFactor);
        OptimizedModel::COptimizedModel::DrawGLViewTriangle(
          this,
          fp,
          pos1: &s_LastThreePositions[(id + 1) % 3],
          pos2: &s_LastThreePositions[(id + 2) % 3],
          pos3: &s_LastThreePositions[(id + 3) % 3],
          color1: color,
          color2: color,
          color3: color);
      }
    }
  }
  else if ( id == 2 )
  {
    OptimizedModel::COptimizedModel::ShrinkVerts(this, shrinkFactor);
    OptimizedModel::COptimizedModel::DrawGLViewTriangle(
      this,
      fp,
      pos1: s_LastThreePositions,
      pos2: &s_LastThreePositions[1],
      pos3: &s_LastThreePositions[2],
      color1: color,
      color2: color,
      color3: color);
  }
  ++s_ListID;
}

//------------------------------------------------------------------------------
// Address: 0x00415C10
// Name: private: void OptimizedModel::COptimizedModel::SortBonesWithinVertex(bool,struct OptimizedModel::Vertex_t __near *,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,int __near *,int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SortBonesWithinVertex(
        OptimizedModel::COptimizedModel *this,
        bool flexed,
        OptimizedModel::Vertex_t *vert,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        int *globalToHardwareBoneIndex,
        int *hardwareToGlobalBoneIndex,
        int maxBonesPerFace,
        int maxBonesPerVert)
{
  int OrigVertBoneIndex; // [esp+Ch] [ebp-30h]
  float v11; // [esp+10h] [ebp-2Ch]
  int globalBoneIndex; // [esp+1Ch] [ebp-20h]
  float OrigVertBoneWeightValue; // [esp+20h] [ebp-1Ch]
  float boneWeight; // [esp+24h] [ebp-18h]
  int origBoneWeightIndex[3]; // [esp+28h] [ebp-14h]
  int i; // [esp+34h] [ebp-8h]
  int zeroWeightIndex; // [esp+38h] [ebp-4h]

  zeroWeightIndex = -1;
  for ( i = 0; i < 3; ++i )
  {
    boneWeight = OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(
                   this,
                   pStudioModel,
                   pStudioMesh,
                   pVert: vert,
                   boneID: i);
    if ( boneWeight == 0.0 )
    {
      zeroWeightIndex = i;
      break;
    }
  }
  for ( i = 0; i < 3; ++i )
    origBoneWeightIndex[i] = zeroWeightIndex;
  for ( i = 0; i < vert->numBones; ++i )
  {
    OrigVertBoneWeightValue = OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(
                                this,
                                pStudioModel,
                                pStudioMesh,
                                pVert: vert,
                                boneID: i);
    globalBoneIndex = OptimizedModel::COptimizedModel::GetOrigVertBoneIndex(
                        this,
                        pStudioModel,
                        pStudioMesh,
                        pVert: vert,
                        boneID: i);
    if ( flexed )
    {
      printf(format: "boneWeight: %f\n", OrigVertBoneWeightValue);
      printf(format: "globalBoneIndex: %d\n", globalBoneIndex);
    }
    if ( OrigVertBoneWeightValue <= 0.0 )
      origBoneWeightIndex[globalToHardwareBoneIndex[globalBoneIndex]] = zeroWeightIndex;
    else
      origBoneWeightIndex[globalToHardwareBoneIndex[globalBoneIndex]] = vert->boneWeightIndex[i];
  }
  for ( i = 0; i < maxBonesPerFace; ++i )
  {
    vert->boneID[i] = i;
    vert->boneWeightIndex[i] = origBoneWeightIndex[i];
    v11 = OptimizedModel::COptimizedModel::GetOrigVertBoneWeightValue(
            this,
            pStudioModel,
            pStudioMesh,
            pVert: vert,
            boneID: i);
    OrigVertBoneIndex = OptimizedModel::COptimizedModel::GetOrigVertBoneIndex(
                          this,
                          pStudioModel,
                          pStudioMesh,
                          pVert: vert,
                          boneID: i);
    if ( flexed )
    {
      printf(format: "boneWeight: %f ", v11);
      printf(format: "globalBoneIndex: %d ", OrigVertBoneIndex);
      printf(format: "hardwareBoneID: %d\n", i);
    }
  }
  vert->numBones = maxBonesPerFace;
}

//------------------------------------------------------------------------------
// Address: 0x00415F30
// Name: public: struct OptimizedModel::EdgeInfo_t __near & CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::EdgeInfo_t *__thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::operator[](
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int i)
{
  return (OptimizedModel::EdgeInfo_t *)i;
}

//------------------------------------------------------------------------------
// Address: 0x00415F60
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 20 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 20 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 20 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00415FE0
// Name: public: void CUtlMemory<struct OptimizedModel::Vertex_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Vertex_t,int>::Grow(CUtlMemory<OptimizedModel::Vertex_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::Vertex_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 9);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 9 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Vertex_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::Vertex_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416060
// Name: public: void CUtlMemory<struct OptimizedModel::Strip_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Strip_t,int>::Grow(CUtlMemory<OptimizedModel::Strip_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::Strip_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 4168);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 4168 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Strip_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::Strip_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004160F0
// Name: public: void CUtlMemory<struct OptimizedModel::StripGroup_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::StripGroup_t,int>::Grow(
        CUtlMemory<OptimizedModel::StripGroup_t,int> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::StripGroup_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 84);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 84 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::StripGroup_t *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v8);
    else
      this->m_pMemory = (OptimizedModel::StripGroup_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416170
// Name: public: void CUtlMemory<struct OptimizedModel::Mesh_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Mesh_t,int>::Grow(CUtlMemory<OptimizedModel::ModelLOD_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::ModelLOD_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 24);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 24 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::ModelLOD_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::ModelLOD_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004161F0
// Name: public: void CUtlMemory<struct OptimizedModel::Face_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Face_t,int>::Grow(CUtlMemory<OptimizedModel::Face_t,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::Face_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 88);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 88 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Face_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v8);
    else
      this->m_pMemory = (OptimizedModel::Face_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416270
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<bool,int> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  bool *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 1);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v6);
    else
      this->m_pMemory = (bool *)MemAlloc_Alloc(nSize: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004162F0
// Name: public: void CUtlMemory<struct OptimizedModel::StripVertLookup_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::StripVertLookup_t,int>::Grow(
        CUtlMemory<OptimizedModel::StripVertLookup_t,int> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // esi
  int v6; // eax
  OptimizedModel::StripVertLookup_t *m_pMemory; // edx
  unsigned int v8; // [esp-8h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    v6 = UtlMemory_CalcNewAllocationCount(
           nAllocationCount: m_nAllocationCount,
           nGrowSize: m_nGrowSize,
           nNewSize: m_nAllocationCount + num,
           nBytesItem: 8);
    if ( v6 < v5 )
    {
      if ( v6 != 0 || v5 > -1 )
      {
        do
          v6 = (v5 + v6) / 2;
        while ( v6 < v5 );
      }
      else
      {
        v6 = -1;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = v6;
    v8 = 8 * v6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::StripVertLookup_t *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v8);
    else
      this->m_pMemory = (OptimizedModel::StripVertLookup_t *)MemAlloc_Alloc(nSize: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416370
// Name: public: int OptimizedModel::CStringTable::StringTableOffset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::CStringTable::StringTableOffset(OptimizedModel::CStringTable *this, const char *string)
{
  const char *j; // eax
  CUtlVector<char,CUtlMemory<char,int> > *v3; // eax
  const char *v4; // eax
  ConCommandBase *v6; // eax
  int size; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  size = 0;
  i = 0;
  for ( j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this);
        i < (int)j;
        j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this) )
  {
    v3 = (CUtlVector<char,CUtlMemory<char,int> > *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                                                     (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                                                     i);
    v4 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: v3);
    if ( _V_stricmp(s1: v4, s2: string) == 0 )
      return size;
    v6 = (ConCommandBase *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                             (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                             i);
    size += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: v6);
    ++i;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004163F0
// Name: public: bool OptimizedModel::CStringTable::StringPresent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::CStringTable::StringPresent(OptimizedModel::CStringTable *this, const char *string)
{
  const char *j; // eax
  CUtlVector<char,CUtlMemory<char,int> > *v3; // eax
  const char *v4; // eax
  int i; // [esp+4h] [ebp-4h]

  i = 0;
  for ( j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this);
        i < (int)j;
        j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this) )
  {
    v3 = (CUtlVector<char,CUtlMemory<char,int> > *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                                                     (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                                                     i);
    v4 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: v3);
    if ( _V_stricmp(s1: v4, s2: string) == 0 )
      return 1;
    ++i;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00416450
// Name: public: int OptimizedModel::CStringTable::CalcSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::CStringTable::CalcSize(OptimizedModel::CStringTable *this)
{
  const char *j; // eax
  ConCommandBase *v2; // eax
  int size; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  size = 0;
  i = 0;
  for ( j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this);
        i < (int)j;
        j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this) )
  {
    v2 = (ConCommandBase *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                             (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                             i);
    size += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: v2);
    ++i;
  }
  return size;
}

//------------------------------------------------------------------------------
// Address: 0x004164B0
// Name: public: void OptimizedModel::CStringTable::WriteToMem(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::CStringTable::WriteToMem(OptimizedModel::CStringTable *this, char *pDst)
{
  const char *j; // eax
  ConCommandBase *v3; // eax
  CUtlVector<char,CUtlMemory<char,int> > *v4; // eax
  unsigned __int8 *v5; // eax
  ConCommandBase *v6; // eax
  const char *v7; // [esp-4h] [ebp-10h]
  int size; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  size = 0;
  i = 0;
  for ( j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this);
        i < (int)j;
        j = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count((ConCommandBase *)this) )
  {
    v3 = (ConCommandBase *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                             (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                             i);
    v7 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: v3);
    v4 = (CUtlVector<char,CUtlMemory<char,int> > *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                                                     (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                                                     i);
    v5 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: v4);
    memcpy(dst: (unsigned __int8 *)&pDst[size], src: v5, count: (unsigned int)v7);
    v6 = (ConCommandBase *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                             (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                             i);
    size += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: v6);
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416540
// Name: OptimizedModel::GetNextUntouched
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__cdecl OptimizedModel::GetNextUntouched(
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faces)
{
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faces);
        ++i )
  {
    if ( !CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i)->touched )
      return CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00416590
// Name: private: struct OptimizedModel::Face_t __near * OptimizedModel::COptimizedModel::GetNextUntouchedWithoutBoneStateChange(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__thiscall OptimizedModel::COptimizedModel::GetNextUntouchedWithoutBoneStateChange(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faces)
{
  const OptimizedModel::Face_t *v2; // eax
  int numNewBones; // [esp+Ch] [ebp-14h]
  OptimizedModel::Face_t *bestFace; // [esp+10h] [ebp-10h]
  int bestNumNewBones; // [esp+14h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-4h]

  bestFace = nullptr;
  bestNumNewBones = 3
                  * ((CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                        this: faces,
                        i: 0)->vertID[3] != -1)
                   + 3)
                  + 1;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faces);
        ++i )
  {
    if ( !CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i)->touched )
    {
      v2 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
      numNewBones = OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(this, face: v2);
      if ( numNewBones <= CHardwareMatrixState::FreeMatrixCount(this: &this->m_HardwareMatrixState)
        && numNewBones < bestNumNewBones )
      {
        bestNumNewBones = numNewBones;
        bestFace = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
        if ( numNewBones == 0 )
          break;
      }
    }
  }
  return bestFace;
}

//------------------------------------------------------------------------------
// Address: 0x00416650
// Name: private: struct OptimizedModel::Face_t __near * OptimizedModel::COptimizedModel::GetNextUntouchedWithLeastBoneStateChanges(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__thiscall OptimizedModel::COptimizedModel::GetNextUntouchedWithLeastBoneStateChanges(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faces)
{
  const OptimizedModel::Face_t *v2; // eax
  int numNewBones; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  OptimizedModel::Face_t *bestFace; // [esp+14h] [ebp-Ch]
  int bestNumNewBones; // [esp+18h] [ebp-8h]

  bestFace = nullptr;
  bestNumNewBones = 3
                  * ((CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                        this: faces,
                        i: 0)->vertID[3] != -1)
                   + 3)
                  + 1;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faces);
        ++i )
  {
    if ( !CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i)->touched )
    {
      v2 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
      numNewBones = OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(this, face: v2);
      if ( numNewBones < bestNumNewBones )
      {
        bestNumNewBones = numNewBones;
        bestFace = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faces, i);
      }
    }
  }
  if ( bestFace == nullptr )
    return nullptr;
  CHardwareMatrixState::DeallocateAll(this: &this->m_HardwareMatrixState);
  return bestFace;
}

//------------------------------------------------------------------------------
// Address: 0x00416710
// Name: private: struct OptimizedModel::Face_t __near * OptimizedModel::COptimizedModel::GetNextFace(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Face_t *__thiscall OptimizedModel::COptimizedModel::GetNextFace(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faceList,
        bool allowNewStrip)
{
  OptimizedModel::Face_t *face; // [esp+4h] [ebp-4h]

  face = OptimizedModel::COptimizedModel::GetNextUntouchedWithoutBoneStateChange(this, faces: faceList);
  if ( face == nullptr && allowNewStrip )
    return OptimizedModel::COptimizedModel::GetNextUntouchedWithLeastBoneStateChanges(this, faces: faceList);
  return face;
}

//------------------------------------------------------------------------------
// Address: 0x00416750
// Name: private: void OptimizedModel::COptimizedModel::Stripify(class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> const __near &,bool,int __near *,int __near *,unsigned short __near * __near *,unsigned short __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::Stripify(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *sourceIndices,
        ConCommandBase *sourceTopologyIndices,
        bool bIsHWSkinned,
        unsigned int *pNumIndices,
        int *pNumTopologyIndices,
        unsigned __int16 **ppIndices,
        unsigned __int16 **ppTopologyIndices,
        bool bQuadSubd)
{
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  const unsigned __int16 *v11; // eax
  const char *v12; // [esp-Ch] [ebp-40h]
  unsigned int v13; // [esp-4h] [ebp-38h]
  unsigned int v14; // [esp-4h] [ebp-38h]
  PrimitiveGroup *primGroups; // [esp+2Ch] [ebp-8h] BYREF
  unsigned __int16 numPrimGroups; // [esp+30h] [ebp-4h] BYREF

  if ( CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: sourceIndices) != nullptr )
  {
    if ( pNumTopologyIndices != nullptr )
      *pNumTopologyIndices = 0;
    if ( ppTopologyIndices != nullptr )
      *ppTopologyIndices = nullptr;
    if ( bQuadSubd || g_bBuildPreview || !bIsHWSkinned || g_bPreserveTriangleOrder )
    {
      *pNumIndices = (unsigned int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: sourceIndices);
      *ppIndices = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)*pNumIndices >> 31 != 0 ? -1 : 2 * *pNumIndices);
      v13 = 2 * *pNumIndices;
      v9 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)sourceIndices);
      memcpy(dst: (unsigned __int8 *)*ppIndices, src: v9, count: v13);
      if ( bQuadSubd )
      {
        *pNumTopologyIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: sourceTopologyIndices);
        *ppTopologyIndices = (unsigned __int16 *)MemAlloc_Alloc(
                                                   nSize: (unsigned __int64)(unsigned int)*pNumTopologyIndices >> 31 != 0
                                                 ? -1
                                                 : 2 * *pNumTopologyIndices);
        v14 = 2 * *pNumTopologyIndices;
        v10 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)sourceTopologyIndices);
        memcpy(dst: (unsigned __int8 *)*ppTopologyIndices, src: v10, count: v14);
      }
    }
    else
    {
      v12 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: sourceIndices);
      v11 = CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::operator[](
              this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)sourceIndices,
              i: 0);
      GenerateStrips(in_indices: v11, in_numIndices: (const unsigned int)v12, &primGroups, numGroups: &numPrimGroups);
      *pNumIndices = primGroups->numIndices;
      *ppIndices = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)*pNumIndices >> 31 != 0 ? -1 : 2 * *pNumIndices);
      memcpy(dst: (unsigned __int8 *)*ppIndices, src: (unsigned __int8 *)primGroups->indices, count: 2 * *pNumIndices);
      if ( primGroups != nullptr )
        PrimitiveGroup::`vector deleting destructor'(this: primGroups, a2: 3u);
    }
  }
  else
  {
    *ppIndices = nullptr;
    *pNumIndices = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416920
// Name: private: void OptimizedModel::COptimizedModel::BuildFaceBoneData(class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> __near &,struct OptimizedModel::Face_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildFaceBoneData(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *list,
        OptimizedModel::Face_t *face)
{
  int bone; // [esp+4h] [ebp-1Ch]
  OptimizedModel::Vertex_t *vert; // [esp+8h] [ebp-18h]
  int j; // [esp+Ch] [ebp-14h]
  int ja; // [esp+Ch] [ebp-14h]
  int l; // [esp+10h] [ebp-10h]
  int k; // [esp+14h] [ebp-Ch]
  int vertsPerFace; // [esp+1Ch] [ebp-4h]

  vertsPerFace = (face->vertID[3] != -1) + 3;
  face->numBones = 0;
  for ( j = 0; j < 3 * vertsPerFace; ++j )
    face->boneID[j] = -1;
  for ( ja = 0; ja < vertsPerFace; ++ja )
  {
    vert = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
             this: list,
             i: face->vertID[ja]);
    for ( k = 0; k < vert->numBones; ++k )
    {
      bone = vert->boneID[k];
      l = face->numBones;
      do
        --l;
      while ( l >= 0 && bone != face->boneID[l] );
      if ( l < 0 )
        face->boneID[face->numBones++] = bone;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416A30
// Name: private: int OptimizedModel::COptimizedModel::CountUniqueBonesInStrip(struct OptimizedModel::StripGroup_t __near *,struct OptimizedModel::Strip_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::CountUniqueBonesInStrip(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::StripGroup_t *pStripGroup,
        OptimizedModel::Strip_t *pStrip)
{
  void *v3; // esp
  int v5; // [esp+0h] [ebp-20h] BYREF
  OptimizedModel::COptimizedModel *v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-18h]
  int j; // [esp+Ch] [ebp-14h]
  OptimizedModel::Vertex_t *v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+14h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v6 = this;
  v3 = alloca(4 * this->m_NumBones);
  v5 = (int)&v5;
  dst = (unsigned __int8 *)&v5;
  memset(dst: (unsigned __int8 *)&v5, value: 0, count: 4 * this->m_NumBones);
  for ( i = 0; i < pStrip->numStripGroupVerts; ++i )
  {
    v9 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
           this: &pStripGroup->verts,
           i: pStrip->stripGroupVertexOffset + i);
    for ( j = 0; j < v9->numBones; ++j )
    {
      v7 = v9->boneID[j];
      ++*(_DWORD *)&dst[4 * v7];
    }
  }
  v10 = 0;
  for ( i = 0; i < v6->m_NumBones; ++i )
  {
    if ( *(_DWORD *)&dst[4 * i] != 0 )
      ++v10;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00416B30
// Name: private: int OptimizedModel::COptimizedModel::GetTotalVertsForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalVertsForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int numVerts; // [esp+Ch] [ebp-4h]

  numVerts = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    numVerts += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->verts);
  }
  return numVerts;
}

//------------------------------------------------------------------------------
// Address: 0x00416B90
// Name: private: int OptimizedModel::COptimizedModel::GetTotalIndicesForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalIndicesForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int numIndices; // [esp+Ch] [ebp-4h]

  numIndices = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    numIndices += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)pStripGroup);
  }
  return numIndices;
}

//------------------------------------------------------------------------------
// Address: 0x00416BF0
// Name: private: int OptimizedModel::COptimizedModel::GetTotalTopologyIndicesForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalTopologyIndicesForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int numTopologyIndices; // [esp+Ch] [ebp-4h]

  numTopologyIndices = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    numTopologyIndices += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->topologyIndices);
  }
  return numTopologyIndices;
}

//------------------------------------------------------------------------------
// Address: 0x00416C50
// Name: private: int OptimizedModel::COptimizedModel::GetTotalStripsForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalStripsForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int numStrips; // [esp+Ch] [ebp-4h]

  numStrips = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    numStrips += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->strips);
  }
  return numStrips;
}

//------------------------------------------------------------------------------
// Address: 0x00416CB0
// Name: private: int OptimizedModel::COptimizedModel::GetTotalBoneStateChangesForMesh(struct OptimizedModel::Mesh_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::GetTotalBoneStateChangesForMesh(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *pMesh)
{
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+8h] [ebp-10h]
  int j; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int numBoneStateChanges; // [esp+14h] [ebp-4h]

  numBoneStateChanges = 0;
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
        ++i )
  {
    pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                    this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                    i);
    for ( j = 0;
          j < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->strips);
          ++j )
    {
      numBoneStateChanges += CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                               this: &pStripGroup->strips,
                               i: j)->numBoneStateChanges;
    }
  }
  return numBoneStateChanges;
}

//------------------------------------------------------------------------------
// Address: 0x00416D40
// Name: private: bool OptimizedModel::COptimizedModel::MeshNeedsRemoval(struct studiohdr_t __near *,struct mstudiomesh_t __near *,struct LodScriptData_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::MeshNeedsRemoval(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        mstudiomesh_t *pStudioMesh,
        LodScriptData_t *scriptLOD)
{
  char *meshRemovalName; // [esp+8h] [ebp-14h]
  mstudiotexture_t *ptexture; // [esp+Ch] [ebp-10h]
  const char *meshName; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  ptexture = (mstudiotexture_t *)((char *)pHdr
                                + 64 * *(__int16 *)((char *)&pHdr->id + 2 * pStudioMesh->material + pHdr->skinindex)
                                + pHdr->textureindex);
  meshName = (const char *)((int (__thiscall *)(IMaterial *, OptimizedModel::COptimizedModel *))ptexture->material->GetName)(
                             a1: ptexture->material,
                             a2: this);
  for ( i = 0;
        i < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->meshRemovals);
        ++i )
  {
    meshRemovalName = CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::operator[](
                        this: &scriptLOD->meshRemovals,
                        i)->m_pSrcName;
    if ( OptimizedModel::ComparePath(a: meshName, b: meshRemovalName) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00416E00
// Name: private: void OptimizedModel::COptimizedModel::MapGlobalBonesToHardwareBoneIDsAndSortBones(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::MapGlobalBonesToHardwareBoneIDsAndSortBones(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *phdr)
{
  void *v2; // esp
  int v3; // [esp+0h] [ebp-87Ch] BYREF
  OptimizedModel::COptimizedModel *v4; // [esp+4h] [ebp-878h]
  int v5; // [esp+8h] [ebp-874h]
  int v6; // [esp+Ch] [ebp-870h]
  int v7; // [esp+10h] [ebp-86Ch]
  int v8; // [esp+14h] [ebp-868h]
  int v9; // [esp+18h] [ebp-864h]
  int v10; // [esp+1Ch] [ebp-860h]
  int nn; // [esp+20h] [ebp-85Ch]
  OptimizedModel::Vertex_t *vert; // [esp+24h] [ebp-858h]
  int *v13; // [esp+28h] [ebp-854h]
  _DWORD *v14; // [esp+2Ch] [ebp-850h]
  int kk; // [esp+30h] [ebp-84Ch]
  int mm; // [esp+34h] [ebp-848h]
  int jj; // [esp+38h] [ebp-844h]
  _DWORD *v18; // [esp+3Ch] [ebp-840h]
  int ii; // [esp+40h] [ebp-83Ch]
  mstudiomesh_t *pStudioMesh; // [esp+44h] [ebp-838h]
  _DWORD *v21; // [esp+48h] [ebp-834h]
  int n; // [esp+4Ch] [ebp-830h]
  int v23; // [esp+50h] [ebp-82Ch]
  _DWORD *v24; // [esp+54h] [ebp-828h]
  mstudiomodel_t *pStudioModel; // [esp+58h] [ebp-824h]
  int m; // [esp+5Ch] [ebp-820h]
  int k; // [esp+60h] [ebp-81Ch]
  int j; // [esp+64h] [ebp-818h]
  char *v29; // [esp+68h] [ebp-814h]
  _DWORD *v30; // [esp+6Ch] [ebp-810h]
  int i; // [esp+70h] [ebp-80Ch]
  unsigned __int8 *m_pData; // [esp+74h] [ebp-808h]
  int *globalToHardwareBoneIndex; // [esp+78h] [ebp-804h]
  int hardwareToGlobalBoneIndex[512]; // [esp+7Ch] [ebp-800h] BYREF

  v4 = this;
  v2 = alloca(4 * this->m_NumBones);
  v3 = (int)&v3;
  globalToHardwareBoneIndex = &v3;
  m_pData = this->m_FileBuffer->m_pData;
  for ( i = 0; i < *((_DWORD *)m_pData + 7); ++i )
  {
    v9 = (int)&m_pData[8 * i + *((_DWORD *)m_pData + 8)];
    v30 = (_DWORD *)v9;
    v29 = (char *)phdr + 16 * i + phdr->bodypartindex;
    for ( j = 0; j < *((_DWORD *)m_pData + 5); ++j )
    {
      for ( k = 0; k < v4->m_NumBones; ++k )
        globalToHardwareBoneIndex[k] = -1;
      for ( k = 0; k < 512; ++k )
        hardwareToGlobalBoneIndex[k] = -1;
      for ( m = 0; m < *v30; ++m )
      {
        v8 = (int)&v30[2 * m] + v30[1];
        v23 = v8;
        pStudioModel = (mstudiomodel_t *)&v29[148 * m + *((_DWORD *)v29 + 3)];
        v7 = 12 * j + *(_DWORD *)(v8 + 4) + v8;
        v24 = (_DWORD *)v7;
        for ( n = 0; n < *v24; ++n )
        {
          v6 = (int)v24 + 9 * n + v24[1];
          v21 = (_DWORD *)v6;
          pStudioMesh = (mstudiomesh_t *)((char *)pStudioModel + 116 * n + pStudioModel->meshindex);
          for ( ii = 0; ii < *v21; ++ii )
          {
            v5 = (int)v21 + 33 * ii + v21[1];
            v18 = (_DWORD *)v5;
            if ( (*(_BYTE *)(v5 + 24) & 2) != 0 )
            {
              for ( jj = 0; jj < v18[4]; ++jj )
              {
                v14 = (_DWORD *)((char *)v18 + 35 * jj + v18[5]);
                for ( kk = 0; kk < *(_DWORD *)((char *)v14 + 19); ++kk )
                {
                  v13 = (_DWORD *)((char *)&v14[2 * kk] + *(_DWORD *)((char *)v14 + 23));
                  globalToHardwareBoneIndex[v13[1]] = *v13;
                  if ( *v13 != -1 )
                    hardwareToGlobalBoneIndex[*v13] = v13[1];
                }
                for ( mm = 0; mm < v14[2]; ++mm )
                {
                  vert = (OptimizedModel::Vertex_t *)((char *)v18 + 9 * v14[3] + 9 * mm + v18[1]);
                  for ( nn = 0; nn < *((_DWORD *)m_pData + 3); ++nn )
                  {
                    v10 = vert->boneID[nn];
                    if ( v10 == 255 )
                      vert->boneID[nn] = 0;
                    else
                      vert->boneID[nn] = globalToHardwareBoneIndex[v10];
                  }
                  if ( v4->m_bUsesFixedFunction )
                    OptimizedModel::COptimizedModel::SortBonesWithinVertex(
                      this: v4,
                      flexed: false,
                      vert,
                      pStudioModel,
                      pStudioMesh,
                      globalToHardwareBoneIndex,
                      hardwareToGlobalBoneIndex,
                      maxBonesPerFace: v4->m_MaxBonesPerFace,
                      maxBonesPerVert: v4->m_MaxBonesPerVert);
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
// Address: 0x00417330
// Name: private: int OptimizedModel::COptimizedModel::WriteVerts(int,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::WriteVerts(
        OptimizedModel::COptimizedModel *this,
        int vertID,
        OptimizedModel::StripGroup_t *pStripGroup)
{
  OptimizedModel::Vertex_t *src; // [esp+8h] [ebp-10h]
  CFileBuffer *m_FileBuffer; // [esp+Ch] [ebp-Ch]
  int numVerts; // [esp+10h] [ebp-8h]
  int vertFileOffset; // [esp+14h] [ebp-4h]

  vertFileOffset = this->m_VertsOffset + 9 * vertID;
  numVerts = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->verts);
  src = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
          this: &pStripGroup->verts,
          i: 0);
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[vertFileOffset];
  memcpy(dst: m_FileBuffer->m_pCurPos, src: src->boneWeightIndex, count: 9 * numVerts);
  m_FileBuffer->m_pCurPos += 9 * numVerts;
  return numVerts;
}

//------------------------------------------------------------------------------
// Address: 0x004173C0
// Name: private: int OptimizedModel::COptimizedModel::WriteIndices(int,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::WriteIndices(
        OptimizedModel::COptimizedModel *this,
        int indexID,
        ConCommandBase *pStripGroup)
{
  unsigned __int8 *src; // [esp+8h] [ebp-10h]
  CFileBuffer *m_FileBuffer; // [esp+Ch] [ebp-Ch]
  int numIndices; // [esp+10h] [ebp-8h]
  int indexFileOffset; // [esp+14h] [ebp-4h]

  indexFileOffset = this->m_IndicesOffset + 2 * indexID;
  numIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
  src = (unsigned __int8 *)CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::operator[](
                             this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)pStripGroup,
                             i: 0);
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[indexFileOffset];
  memcpy(dst: m_FileBuffer->m_pCurPos, src, count: 2 * numIndices);
  m_FileBuffer->m_pCurPos += 2 * numIndices;
  return numIndices;
}

//------------------------------------------------------------------------------
// Address: 0x00417440
// Name: private: int OptimizedModel::COptimizedModel::WriteTopology(int,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall OptimizedModel::COptimizedModel::WriteTopology(
        OptimizedModel::COptimizedModel *this,
        int topologyID,
        OptimizedModel::StripGroup_t *pStripGroup)
{
  unsigned __int8 *src; // [esp+8h] [ebp-10h]
  CFileBuffer *m_FileBuffer; // [esp+Ch] [ebp-Ch]
  int numTopologyIndices; // [esp+10h] [ebp-8h]
  int topologyIndexFileOffset; // [esp+14h] [ebp-4h]

  if ( CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->topologyIndices) == nullptr )
    return 0;
  topologyIndexFileOffset = this->m_TopologyOffset + 2 * topologyID;
  numTopologyIndices = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->topologyIndices);
  src = (unsigned __int8 *)CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::operator[](
                             this: &pStripGroup->topologyIndices,
                             i: 0);
  m_FileBuffer = this->m_FileBuffer;
  m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[topologyIndexFileOffset];
  memcpy(dst: m_FileBuffer->m_pCurPos, src, count: 2 * numTopologyIndices);
  m_FileBuffer->m_pCurPos += 2 * numTopologyIndices;
  return numTopologyIndices;
}

//------------------------------------------------------------------------------
// Address: 0x004174E0
// Name: private: void OptimizedModel::COptimizedModel::WriteStringTable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteStringTable(
        OptimizedModel::COptimizedModel *this,
        int stringTableOffset)
{
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-24h]
  char *pTmp; // [esp+20h] [ebp-8h]
  unsigned int stringTableSize; // [esp+24h] [ebp-4h]

  stringTableSize = OptimizedModel::CStringTable::CalcSize(this: &s_StringTable);
  if ( stringTableSize != 0 )
  {
    pTmp = (char *)MemAlloc_Alloc(nSize: stringTableSize);
    OptimizedModel::CStringTable::WriteToMem(this: &s_StringTable, pDst: pTmp);
    m_FileBuffer = this->m_FileBuffer;
    m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[stringTableOffset];
    memcpy(dst: m_FileBuffer->m_pCurPos, src: (unsigned __int8 *)pTmp, count: stringTableSize);
    m_FileBuffer->m_pCurPos += stringTableSize;
    free(pMem: pTmp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417580
// Name: private: void OptimizedModel::COptimizedModel::WriteMaterialReplacements(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteMaterialReplacements(
        OptimizedModel::COptimizedModel *this,
        int materialReplacementsOffset)
{
  unsigned __int8 *m_pCurPos; // eax
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-34h]
  CLodScriptReplacement_t *materialReplacement; // [esp+18h] [ebp-20h]
  OptimizedModel::MaterialReplacementHeader_t tmpHeader; // [esp+1Ch] [ebp-1Ch]
  LodScriptData_t *scriptLOD; // [esp+24h] [ebp-14h]
  int j; // [esp+28h] [ebp-10h]
  const char *numLODs; // [esp+2Ch] [ebp-Ch]
  int i; // [esp+34h] [ebp-4h]

  numLODs = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  for ( i = 0; i < (int)numLODs; ++i )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i);
    for ( j = 0;
          j < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->materialReplacements);
          ++j )
    {
      materialReplacement = CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::operator[](
                              this: &scriptLOD->materialReplacements,
                              i: j);
      tmpHeader.materialID = FindMaterialByName(pMaterialName: materialReplacement->m_pSrcName);
      tmpHeader.replacementMaterialNameOffset = OptimizedModel::CStringTable::StringTableOffset(
                                                  this: &s_StringTable,
                                                  string: materialReplacement->m_pDstName)
                                              + this->m_StringTableOffset
                                              - materialReplacementsOffset;
      m_FileBuffer = this->m_FileBuffer;
      m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[materialReplacementsOffset];
      m_pCurPos = m_FileBuffer->m_pCurPos;
      *(_DWORD *)m_pCurPos = *(_DWORD *)&tmpHeader.materialID;
      *((_WORD *)m_pCurPos + 2) = HIWORD(tmpHeader.replacementMaterialNameOffset);
      m_FileBuffer->m_pCurPos += 6;
      materialReplacementsOffset += 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004176A0
// Name: private: void OptimizedModel::COptimizedModel::WriteMaterialReplacementLists(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteMaterialReplacementLists(
        OptimizedModel::COptimizedModel *this,
        int materialReplacementsOffset,
        int materialReplacementListOffset)
{
  const char *v3; // eax
  unsigned __int8 *m_pCurPos; // ecx
  CFileBuffer *m_FileBuffer; // [esp+4h] [ebp-24h]
  LodScriptData_t *scriptLOD; // [esp+Ch] [ebp-1Ch]
  int tmpHeader; // [esp+10h] [ebp-18h]
  int tmpHeader_4; // [esp+14h] [ebp-14h]
  const char *numLODs; // [esp+18h] [ebp-10h]
  int i; // [esp+20h] [ebp-8h]

  numLODs = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  for ( i = 0; i < (int)numLODs; ++i )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i);
    v3 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->materialReplacements);
    tmpHeader = IsChar(val: (int)v3);
    tmpHeader_4 = IsInt24(val: materialReplacementsOffset - materialReplacementListOffset);
    m_FileBuffer = this->m_FileBuffer;
    m_FileBuffer->m_pCurPos = &m_FileBuffer->m_pData[materialReplacementListOffset];
    m_pCurPos = m_FileBuffer->m_pCurPos;
    *(_DWORD *)m_pCurPos = tmpHeader;
    *((_DWORD *)m_pCurPos + 1) = tmpHeader_4;
    m_FileBuffer->m_pCurPos += 8;
    materialReplacementsOffset += 6 * tmpHeader;
    materialReplacementListOffset += 8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417790
// Name: private: void OptimizedModel::COptimizedModel::SanityCheckVertexBoneLODFlags(struct studiohdr_t __near *,struct OptimizedModel::FileHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SanityCheckVertexBoneLODFlags(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pStudioHdr,
        OptimizedModel::FileHeader_t *pVtxHeader)
{
  OptimizedModel::Vertex_t *pVertex; // [esp+28h] [ebp-44h]
  const mstudioboneweight_t *boneWeight; // [esp+2Ch] [ebp-40h]
  int i; // [esp+30h] [ebp-3Ch]
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+34h] [ebp-38h]
  int vertID; // [esp+38h] [ebp-34h]
  int stripGroupID; // [esp+3Ch] [ebp-30h]
  mstudiomesh_t *pMesh; // [esp+40h] [ebp-2Ch]
  OptimizedModel::MeshHeader_t *pVtxMesh; // [esp+44h] [ebp-28h]
  int meshID; // [esp+48h] [ebp-24h]
  OptimizedModel::ModelLODHeader_t *pVtxLOD; // [esp+4Ch] [ebp-20h]
  OptimizedModel::ModelHeader_t *pVtxModel; // [esp+50h] [ebp-1Ch]
  mstudiomodel_t *pModel; // [esp+54h] [ebp-18h]
  int lodID; // [esp+58h] [ebp-14h]
  int modelID; // [esp+5Ch] [ebp-10h]
  mstudiobodyparts_t *pBodyPart; // [esp+60h] [ebp-Ch]
  OptimizedModel::BodyPartHeader_t *pVtxBodyPart; // [esp+64h] [ebp-8h]
  int bodyPartID; // [esp+68h] [ebp-4h]

  for ( bodyPartID = 0; bodyPartID < pStudioHdr->numbodyparts; ++bodyPartID )
  {
    pBodyPart = (mstudiobodyparts_t *)((char *)pStudioHdr + 16 * bodyPartID + pStudioHdr->bodypartindex);
    pVtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)pVtxHeader + 8 * bodyPartID + pVtxHeader->bodyPartOffset);
    for ( modelID = 0; modelID < pBodyPart->nummodels; ++modelID )
    {
      pModel = (mstudiomodel_t *)((char *)pBodyPart + 148 * modelID + pBodyPart->modelindex);
      pVtxModel = (OptimizedModel::ModelHeader_t *)((char *)&pVtxBodyPart[modelID] + pVtxBodyPart->modelOffset);
      for ( lodID = 0; lodID < pVtxModel->numLODs; ++lodID )
      {
        pVtxLOD = (OptimizedModel::ModelLODHeader_t *)((char *)pVtxModel + 12 * lodID + pVtxModel->lodOffset);
        for ( meshID = 0; meshID < pVtxLOD->numMeshes; ++meshID )
        {
          pVtxMesh = (OptimizedModel::MeshHeader_t *)((char *)pVtxLOD + 9 * meshID + pVtxLOD->meshOffset);
          pMesh = (mstudiomesh_t *)((char *)pModel + 116 * meshID + pModel->meshindex);
          for ( stripGroupID = 0; stripGroupID < pVtxMesh->numStripGroups; ++stripGroupID )
          {
            pStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)pVtxMesh
                                                               + 33 * stripGroupID
                                                               + pVtxMesh->stripGroupHeaderOffset);
            for ( vertID = 0; vertID < pStripGroup->numVerts; ++vertID )
            {
              pVertex = (OptimizedModel::Vertex_t *)((char *)pStripGroup + 9 * vertID + pStripGroup->vertOffset);
              OptimizedModel::COptimizedModel::GetOrigVertPosition(
                this,
                pStudioModel: pModel,
                pStudioMesh: pMesh,
                pVert: pVertex);
              boneWeight = OptimizedModel::COptimizedModel::GetOrigVertBoneWeight(
                             this,
                             pStudioModel: pModel,
                             pStudioMesh: pMesh,
                             pVert: pVertex);
              for ( i = 0; i < boneWeight->numbones; ++i )
              {
                if ( (*(int *)((_BYTE *)&pStudioHdr->boneindex + 216 * boneWeight->bone[i] + pStudioHdr->boneindex)
                    & (1024 << lodID)) == 0 )
                  MdlError(fmt: "Mismarked Bone flag");
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417A00
// Name: OptimizedModel::CalcNumMaterialReplacements
// Source: json
//------------------------------------------------------------------------------
int __cdecl OptimizedModel::CalcNumMaterialReplacements()
{
  LodScriptData_t *scriptLOD; // [esp+0h] [ebp-10h]
  const char *numLODs; // [esp+4h] [ebp-Ch]
  int numReplacements; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  numReplacements = 0;
  numLODs = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  for ( i = 0; i < (int)numLODs; ++i )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i);
    numReplacements += (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->materialReplacements);
  }
  return numReplacements;
}

//------------------------------------------------------------------------------
// Address: 0x00417A60
// Name: void OptimizedModel::ValidateLODReplacements(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::ValidateLODReplacements(studiohdr_t *pHdr)
{
  int (__thiscall ***v1)(_DWORD, _DWORD); // ecx
  const char *v2; // eax
  int (__thiscall ***v3)(_DWORD); // [esp+4h] [ebp-28h]
  int k; // [esp+Ch] [ebp-20h]
  const char *pName2; // [esp+10h] [ebp-1Ch]
  int i; // [esp+14h] [ebp-18h]
  char *pName1; // [esp+18h] [ebp-14h]
  int j; // [esp+1Ch] [ebp-10h]
  LodScriptData_t *scriptLOD; // [esp+20h] [ebp-Ch]
  bool failed; // [esp+27h] [ebp-5h]
  int lodID; // [esp+28h] [ebp-4h]

  failed = false;
  for ( lodID = 0;
        lodID < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
        ++lodID )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i: lodID);
    for ( j = 0;
          j < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->meshRemovals);
          ++j )
    {
      pName1 = CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::operator[](
                 this: &scriptLOD->meshRemovals,
                 i: j)->m_pSrcName;
      for ( i = 0; i < pHdr->numtextures; ++i )
      {
        v3 = *(int (__thiscall ****)(_DWORD))&pHdr->name[64 * i + 4 + pHdr->textureindex];
        pName2 = (const char *)(**v3)(a1: v3);
        if ( OptimizedModel::ComparePath(a: pName1, b: pName2) != 0 )
          goto got_one;
      }
      MdlWarning(fmt: "\"%s\" doesn't match any of the materals in the model\n", pName1);
      failed = true;
got_one:
      ;
    }
  }
  if ( failed )
  {
    MdlWarning(fmt: "possible materials in model:\n");
    for ( k = 0; k < pHdr->numtextures; ++k )
    {
      v1 = *(int (__thiscall ****)(_DWORD, _DWORD))&pHdr->name[64 * k + 4 + pHdr->textureindex];
      v2 = (const char *)(**v1)(a1: v1, a2: v1);
      MdlWarning(fmt: "\t\"%s\"\n", v2);
    }
    MdlError(fmt: "Exiting due to errors\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417BF0
// Name: public: void CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::RemoveAll(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this)
{
  int m_Size; // esi
  int v2; // edx

  m_Size = this->m_Buckets.m_Size;
  if ( m_Size > 0 )
  {
    v2 = 0;
    do
    {
      this->m_Buckets.m_Memory.m_pMemory[v2++].m_Size = 0;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417C20
// Name: public: struct OptimizedModel::StripVertLookup_t __near & CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::Element(unsigned int)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::StripVertLookup_t *__thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Element(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        unsigned int handle)
{
  return &this->m_Buckets.m_Memory.m_pMemory[HIWORD(handle)].m_Memory.m_pMemory[(unsigned __int16)handle];
}

//------------------------------------------------------------------------------
// Address: 0x00417C40
// Name: public: void CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::EnsureCapacity(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int num)
{
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::Grow(
    this: &this->m_Memory,
    num: num - this->m_Memory.m_nAllocationCount);
  this->m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00417C60
// Name: public: int CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::Next(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Next(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int i)
{
  return *(_DWORD *)(i + 16);
}

//------------------------------------------------------------------------------
// Address: 0x00417C70
// Name: protected: bool CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::DoFind(struct OptimizedModel::StripVertLookup_t const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::DoFind(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        const OptimizedModel::StripVertLookup_t *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int> > *v7; // ebx
  int m_Size; // eax
  int v9; // esi
  int keyDataCount; // [esp+18h] [ebp+Ch]

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = &this->m_Buckets.m_Memory.m_pMemory[v6];
  m_Size = v7->m_Size;
  v9 = 0;
  keyDataCount = m_Size;
  if ( m_Size > 0 )
  {
    do
    {
      if ( this->m_CompareFunc(a1: &v7->m_Memory.m_pMemory[v9], a2: src) )
        break;
      ++v9;
    }
    while ( v9 < keyDataCount );
    m_Size = keyDataCount;
  }
  if ( v9 == m_Size )
    return 0;
  *pIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00417CF0
// Name: protected: int CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 16);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 12) = 0;
    }
    else
    {
      *(_DWORD *)(result + 16) = result;
      *(_DWORD *)(result + 12) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)((char *)v8 + 20 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 20 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00417F20
// Name: public: void CFileBuffer::WriteToFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileBuffer::WriteToFile(CFileBuffer *this, const char *fileName, unsigned int size)
{
  CP4File *v3; // eax
  char *v4; // eax
  char *v5; // [esp+4h] [ebp-28h]
  CPlainAutoPtr<CP4File> spFile; // [esp+24h] [ebp-8h] BYREF
  _iobuf *fp; // [esp+28h] [ebp-4h]

  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename: fileName);
  CPlainAutoPtr<CP4File>::CPlainAutoPtr<CP4File>(this: &spFile, p: v3);
  v5 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&spFile);
  (*(void (__thiscall **)(char *))(*(_DWORD *)v5 + 4))(a1: v5);
  fp = fopen(file: fileName, mode: "wb");
  if ( fp != nullptr )
  {
    fwrite(buffer: this->m_pData, size: 1u, count: size, stream: fp);
    fclose(stream: fp);
    v4 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&spFile);
    (*(void (__thiscall **)(char *, char *))(*(_DWORD *)v4 + 8))(a1: v4, a2: v4);
  }
  else
  {
    MdlWarning(fmt: "Can't open \"%s\" for writing!\n", fileName);
  }
  CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: &spFile);
}

//------------------------------------------------------------------------------
// Address: 0x00417FE0
// Name: private: void OptimizedModel::COptimizedModel::WriteVTXFile(struct studiohdr_t __near *,char const __near *,struct OptimizedModel::TotalMeshStats_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteVTXFile(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        const char *pFileName,
        const OptimizedModel::TotalMeshStats_t *stats)
{
  const char *i; // eax
  CFileBuffer *v5; // [esp+0h] [ebp-C0h]
  CFileBuffer *v7; // [esp+34h] [ebp-8Ch]
  int boneStateChangeID; // [esp+38h] [ebp-88h]
  OptimizedModel::Strip_t *pStrip; // [esp+3Ch] [ebp-84h]
  int stripID; // [esp+40h] [ebp-80h]
  OptimizedModel::StripGroup_t *pStripGroup; // [esp+44h] [ebp-7Ch]
  const char *nStripCount; // [esp+48h] [ebp-78h]
  int stripGroupID; // [esp+4Ch] [ebp-74h]
  ConCommandBase *pMesh; // [esp+50h] [ebp-70h]
  int meshID; // [esp+54h] [ebp-6Ch]
  OptimizedModel::ModelLOD_t *pLOD; // [esp+58h] [ebp-68h]
  int lodID; // [esp+5Ch] [ebp-64h]
  OptimizedModel::Model_t *pModel; // [esp+60h] [ebp-60h]
  mstudiomodel_t *pStudioModel; // [esp+64h] [ebp-5Ch]
  int modelID; // [esp+68h] [ebp-58h]
  mstudiobodyparts_t *pBodyPart; // [esp+6Ch] [ebp-54h]
  int bodyPartID; // [esp+70h] [ebp-50h]
  int curStripGroup; // [esp+74h] [ebp-4Ch]
  int deltaIndex; // [esp+78h] [ebp-48h]
  int deltaTopology; // [esp+7Ch] [ebp-44h]
  int deltaVert; // [esp+80h] [ebp-40h]
  int deltaBoneStateChange; // [esp+84h] [ebp-3Ch]
  int curMesh; // [esp+8Ch] [ebp-34h]
  int curStrip; // [esp+90h] [ebp-30h]
  int deltaStrip; // [esp+94h] [ebp-2Ch]
  int deltaLOD; // [esp+98h] [ebp-28h]
  int curVert; // [esp+9Ch] [ebp-24h]
  int curIndex; // [esp+A0h] [ebp-20h]
  int curTopology; // [esp+A4h] [ebp-1Ch]
  int curLOD; // [esp+A8h] [ebp-18h]
  int deltaStripGroup; // [esp+ACh] [ebp-14h]
  int curBoneStateChange; // [esp+B0h] [ebp-10h]
  int deltaMesh; // [esp+B4h] [ebp-Ch]
  int curModel; // [esp+B8h] [ebp-8h]
  int deltaModel; // [esp+BCh] [ebp-4h]

  v7 = (CFileBuffer *)MemAlloc_Alloc(nSize: 0xCu);
  if ( v7 != nullptr )
  {
    v7->m_pData = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x400000u);
    v7->m_Size = 0x400000;
    v7->m_pCurPos = v7->m_pData;
    v5 = v7;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_FileBuffer = v5;
  this->m_BodyPartsOffset = 36;
  this->m_ModelsOffset = this->m_BodyPartsOffset + 8 * stats->m_TotalBodyParts;
  this->m_ModelLODsOffset = this->m_ModelsOffset + 8 * stats->m_TotalModels;
  this->m_MeshesOffset = this->m_ModelLODsOffset + 12 * stats->m_TotalModelLODs;
  this->m_StripGroupsOffset = this->m_MeshesOffset + 9 * stats->m_TotalMeshes;
  this->m_StripsOffset = this->m_StripGroupsOffset + 33 * stats->m_TotalStripGroups;
  this->m_VertsOffset = this->m_StripsOffset + 35 * stats->m_TotalStrips;
  this->m_IndicesOffset = this->m_VertsOffset + 9 * stats->m_TotalVerts;
  this->m_BoneStateChangesOffset = this->m_IndicesOffset + 2 * stats->m_TotalIndices;
  this->m_StringTableOffset = this->m_BoneStateChangesOffset + 8 * stats->m_TotalBoneStateChanges;
  this->m_MaterialReplacementsOffset = this->m_StringTableOffset
                                     + OptimizedModel::CStringTable::CalcSize(this: &s_StringTable);
  this->m_MaterialReplacementsListOffset = this->m_MaterialReplacementsOffset + 6 * stats->m_TotalMaterialReplacements;
  this->m_TopologyOffset = this->m_MaterialReplacementsListOffset
                         + 8
                         * (_DWORD)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  this->m_EndOfFileOffset = this->m_TopologyOffset + 2 * stats->m_TotalTopologyIndices;
  curModel = 0;
  curLOD = 0;
  curMesh = 0;
  curStrip = 0;
  curStripGroup = 0;
  curVert = 0;
  curIndex = 0;
  curTopology = 0;
  curBoneStateChange = 0;
  deltaModel = 0;
  deltaLOD = 0;
  deltaMesh = 0;
  deltaStrip = 0;
  deltaStripGroup = 0;
  deltaBoneStateChange = 0;
  OptimizedModel::COptimizedModel::WriteStringTable(this, stringTableOffset: this->m_StringTableOffset);
  OptimizedModel::COptimizedModel::WriteMaterialReplacements(
    this,
    materialReplacementsOffset: this->m_MaterialReplacementsOffset);
  OptimizedModel::COptimizedModel::WriteMaterialReplacementLists(
    this,
    materialReplacementsOffset: this->m_MaterialReplacementsOffset,
    materialReplacementListOffset: this->m_MaterialReplacementsListOffset);
  for ( bodyPartID = 0; bodyPartID < pHdr->numbodyparts; ++bodyPartID )
  {
    pBodyPart = (mstudiobodyparts_t *)((char *)pHdr + 16 * bodyPartID + pHdr->bodypartindex);
    for ( modelID = 0; modelID < pBodyPart->nummodels; ++modelID )
    {
      pStudioModel = (mstudiomodel_t *)((char *)pBodyPart + 148 * modelID + pBodyPart->modelindex);
      pModel = CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                 this: &this->m_Models,
                 i: deltaModel + curModel);
      for ( lodID = 0;
            lodID < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
            ++lodID )
      {
        pLOD = CUtlVector<OptimizedModel::Mesh_t,CUtlMemory<OptimizedModel::Mesh_t,int>>::operator[](
                 this: &pModel->modelLODs,
                 i: lodID);
        for ( meshID = 0; meshID < pStudioModel->nummeshes; ++meshID )
        {
          pMesh = (ConCommandBase *)CUtlVector<OptimizedModel::Mesh_t,CUtlMemory<OptimizedModel::Mesh_t,int>>::operator[](
                                      this: (CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int> > *)pLOD,
                                      i: meshID);
          stripGroupID = 0;
          for ( i = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh);
                stripGroupID < (int)i;
                i = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pMesh) )
          {
            pStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                            this: (CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int> > *)pMesh,
                            i: stripGroupID);
            deltaVert = OptimizedModel::COptimizedModel::WriteVerts(this, vertID: curVert, pStripGroup);
            deltaIndex = OptimizedModel::COptimizedModel::WriteIndices(
                           this,
                           indexID: curIndex,
                           (ConCommandBase *)pStripGroup);
            deltaTopology = OptimizedModel::COptimizedModel::WriteTopology(this, topologyID: curTopology, pStripGroup);
            nStripCount = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->strips);
            for ( stripID = 0; stripID < (int)nStripCount; ++stripID )
            {
              pStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                         this: &pStripGroup->strips,
                         i: stripID);
              for ( boneStateChangeID = 0; boneStateChangeID < pStrip->numBoneStateChanges; ++boneStateChangeID )
              {
                OptimizedModel::COptimizedModel::WriteBoneStateChange(
                  this,
                  boneID: deltaBoneStateChange + curBoneStateChange,
                  boneStateChange: &pStrip->boneStateChanges[boneStateChangeID]);
                ++deltaBoneStateChange;
              }
              OptimizedModel::COptimizedModel::WriteStrip(
                this,
                stripID: deltaStrip + curStrip,
                pStrip,
                indexID: curIndex,
                curTopology,
                vertID: curVert,
                boneID: curBoneStateChange);
              ++deltaStrip;
              curBoneStateChange += deltaBoneStateChange;
              deltaBoneStateChange = 0;
            }
            OptimizedModel::COptimizedModel::WriteStripGroup(
              this,
              stripGroupID: deltaStripGroup + curStripGroup,
              (ConCommandBase *)pStripGroup,
              vertID: curVert,
              indexID: curIndex,
              topologyID: curTopology,
              stripID: curStrip);
            ++deltaStripGroup;
            curStrip += deltaStrip;
            deltaStrip = 0;
            curVert += deltaVert;
            curIndex += deltaIndex;
            curTopology += deltaTopology;
            ++stripGroupID;
          }
          OptimizedModel::COptimizedModel::WriteMesh(
            this,
            meshID: deltaMesh + curMesh,
            pMesh,
            stripGroupID: curStripGroup);
          ++deltaMesh;
          curStripGroup += deltaStripGroup;
          deltaStripGroup = 0;
        }
        OptimizedModel::COptimizedModel::WriteModelLOD(
          this,
          lodID: deltaLOD + curLOD,
          (ConCommandBase *)pLOD,
          meshID: curMesh);
        ++deltaLOD;
        curMesh += deltaMesh;
        deltaMesh = 0;
      }
      OptimizedModel::COptimizedModel::WriteModel(
        this,
        modelID: deltaModel + curModel,
        pModel: pStudioModel,
        lodID: curLOD);
      ++deltaModel;
      curLOD += deltaLOD;
      deltaLOD = 0;
    }
    OptimizedModel::COptimizedModel::WriteBodyPart(this, bodyPartID, pBodyPart, modelID: curModel);
    curModel += deltaModel;
    deltaModel = 0;
  }
  OptimizedModel::COptimizedModel::WriteHeader(
    this,
    vertCacheSize: this->m_VertexCacheSize,
    maxBonesPerVert: this->m_MaxBonesPerVert,
    maxBonesPerFace: this->m_MaxBonesPerFace,
    maxBonesPerStrip: this->m_MaxBonesPerStrip,
    numBodyParts: pHdr->numbodyparts,
    checkSum: pHdr->checksum);
  OptimizedModel::COptimizedModel::MapGlobalBonesToHardwareBoneIDsAndSortBones(this, phdr: pHdr);
  OptimizedModel::COptimizedModel::SanityCheckAgainstStudioHDR(this, phdr: pHdr);
  if ( !g_quiet )
    OptimizedModel::COptimizedModel::OutputMemoryUsage(this);
  OptimizedModel::COptimizedModel::RemoveRedundantBoneStateChanges(this);
  if ( g_staticprop )
    OptimizedModel::COptimizedModel::ZeroNumBones(this);
  CFileBuffer::WriteToFile(this: this->m_FileBuffer, fileName: pFileName, size: this->m_EndOfFileOffset);
  OptimizedModel::COptimizedModel::SanityCheckVertexBoneLODFlags(
    this,
    pStudioHdr: pHdr,
    pVtxHeader: (OptimizedModel::FileHeader_t *)this->m_FileBuffer->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x00418720
// Name: private: void OptimizedModel::COptimizedModel::WriteGLViewFile(struct studiohdr_t __near *,char const __near *,unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteGLViewFile(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *phdr,
        const char *pFileName,
        __int16 flags,
        float shrinkFactor)
{
  CP4File *v5; // eax
  char *v6; // eax
  char *v7; // [esp+10h] [ebp-194h]
  OptimizedModel::Vertex_t *vert; // [esp+44h] [ebp-160h]
  int id; // [esp+48h] [ebp-15Ch]
  int indexID; // [esp+4Ch] [ebp-158h]
  OptimizedModel::StripHeader_t *pStrip; // [esp+50h] [ebp-154h]
  int stripID; // [esp+54h] [ebp-150h]
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+58h] [ebp-14Ch]
  int stripGroupID; // [esp+5Ch] [ebp-148h]
  mstudiomesh_t *pStudioMesh; // [esp+60h] [ebp-144h]
  OptimizedModel::MeshHeader_t *mesh; // [esp+64h] [ebp-140h]
  int meshID; // [esp+68h] [ebp-13Ch]
  OptimizedModel::ModelLODHeader_t *pLOD; // [esp+6Ch] [ebp-138h]
  CPlainAutoPtr<CP4File> spFile; // [esp+70h] [ebp-134h] BYREF
  char tmp[256]; // [esp+74h] [ebp-130h] BYREF
  _iobuf *fp; // [esp+174h] [ebp-30h]
  int lodID; // [esp+178h] [ebp-2Ch]
  OptimizedModel::ModelHeader_t *model; // [esp+17Ch] [ebp-28h]
  mstudiomodel_t *pStudioModel; // [esp+180h] [ebp-24h]
  int modelID; // [esp+184h] [ebp-20h]
  mstudiobodyparts_t *pStudioBodyPart; // [esp+188h] [ebp-1Ch]
  OptimizedModel::BodyPartHeader_t *bodyPart; // [esp+18Ch] [ebp-18h]
  int bodyPartID; // [esp+190h] [ebp-14h]
  OptimizedModel::FileHeader_t *header; // [esp+194h] [ebp-10h]
  Vector color; // [esp+198h] [ebp-Ch] BYREF

  OptimizedModel::RandomColor(&color);
  header = (OptimizedModel::FileHeader_t *)this->m_FileBuffer->m_pData;
  for ( bodyPartID = 0; bodyPartID < header->numBodyParts; ++bodyPartID )
  {
    bodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)header + 8 * bodyPartID + header->bodyPartOffset);
    pStudioBodyPart = (mstudiobodyparts_t *)((char *)phdr + 16 * bodyPartID + phdr->bodypartindex);
    for ( modelID = 0; modelID < bodyPart->numModels; ++modelID )
    {
      model = (OptimizedModel::ModelHeader_t *)((char *)&bodyPart[modelID] + bodyPart->modelOffset);
      pStudioModel = (mstudiomodel_t *)((char *)pStudioBodyPart + 148 * modelID + pStudioBodyPart->modelindex);
      for ( lodID = 0; lodID < model->numLODs; ++lodID )
      {
        sprintf(string: tmp, format: "%s.lod%d", pFileName, lodID);
        printf(format: "writing %s\n", tmp);
        v5 = CP4Factory::AccessFile(this: g_p4factory, szFilename: tmp);
        CPlainAutoPtr<CP4File>::CPlainAutoPtr<CP4File>(this: &spFile, p: v5);
        v7 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&spFile);
        (*(void (__thiscall **)(char *))(*(_DWORD *)v7 + 4))(a1: v7);
        fp = fopen(file: tmp, mode: "w");
        if ( fp == nullptr )
        {
          printf(format: "can't write glview file %s\n", tmp);
          CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: &spFile);
          return;
        }
        pLOD = (OptimizedModel::ModelLODHeader_t *)((char *)model + 12 * lodID + model->lodOffset);
        for ( meshID = 0; meshID < pLOD->numMeshes; ++meshID )
        {
          mesh = (OptimizedModel::MeshHeader_t *)((char *)pLOD + 9 * meshID + pLOD->meshOffset);
          pStudioMesh = (mstudiomesh_t *)((char *)pStudioModel + 116 * meshID + pStudioModel->meshindex);
          if ( (flags & 1) != 0 )
            OptimizedModel::RandomColor(&color);
          if ( (flags & 0x40) != 0 )
            OptimizedModel::COptimizedModel::SetMeshPropsColor(this, meshFlags: mesh->flags, &color);
          for ( stripGroupID = 0; stripGroupID < mesh->numStripGroups; ++stripGroupID )
          {
            if ( (flags & 2) != 0 )
              OptimizedModel::RandomColor(&color);
            pStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)mesh
                                                               + 33 * stripGroupID
                                                               + mesh->stripGroupHeaderOffset);
            OptimizedModel::COptimizedModel::SetFlexedAndSkinColor(
              this,
              glViewFlags: flags,
              stripGroupFlags: pStripGroup->flags,
              &color);
            for ( stripID = 0; stripID < pStripGroup->numStrips; ++stripID )
            {
              pStrip = (OptimizedModel::StripHeader_t *)((char *)pStripGroup + 35 * stripID + pStripGroup->stripOffset);
              if ( (flags & 4) != 0 )
                OptimizedModel::RandomColor(&color);
              if ( (flags & 0x100) != 0 )
              {
                switch ( pStrip->numBones )
                {
                  case 0:
                  case 1:
                    color.x = 0.0;
                    color.y = 0.0;
                    color.z = 255.0;
                    break;
                  case 2:
                    color.x = 0.0;
                    color.y = 255.0;
                    color.z = 0.0;
                    break;
                  case 3:
                    color.x = 255.0;
                    color.y = 255.0;
                    color.z = 0.0;
                    break;
                  case 4:
                    color.x = 255.0;
                    color.y = 0.0;
                    color.z = 0.0;
                    break;
                  default:
                    break;
                }
              }
              OptimizedModel::COptimizedModel::GLViewDrawBegin(this, mode: 0);
              for ( indexID = 0; indexID < pStrip->numIndices; ++indexID )
              {
                id = *(unsigned __int16 *)((char *)&pStripGroup->numVerts
                                         + 2 * pStrip->indexOffset
                                         + 2 * indexID
                                         + pStripGroup->indexOffset);
                vert = (OptimizedModel::Vertex_t *)((char *)pStripGroup + 9 * id + pStripGroup->vertOffset);
                if ( (flags & 0x80) != 0 )
                {
                  switch ( vert->numBones )
                  {
                    case 0u:
                    case 1u:
                      color.x = 0.0;
                      color.y = 0.0;
                      color.z = 255.0;
                      break;
                    case 2u:
                      color.x = 0.0;
                      color.y = 255.0;
                      color.z = 0.0;
                      break;
                    case 3u:
                      color.x = 255.0;
                      color.y = 255.0;
                      color.z = 0.0;
                      break;
                    case 4u:
                      color.x = 255.0;
                      color.y = 0.0;
                      color.z = 0.0;
                      break;
                    default:
                      break;
                  }
                }
                OptimizedModel::COptimizedModel::GLViewVert(
                  this,
                  fp,
                  vert: *vert,
                  index: id,
                  &color,
                  pStudioModel,
                  pStudioMesh,
                  showSubStrips: (flags & 8) != 0,
                  shrinkFactor);
              }
              OptimizedModel::COptimizedModel::GLViewDrawEnd(this);
            }
          }
        }
        fclose(stream: fp);
        v6 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&spFile);
        (*(void (__thiscall **)(char *, char *))(*(_DWORD *)v6 + 8))(a1: v6, a2: v6);
        CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: &spFile);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418DB0
// Name: private: void OptimizedModel::COptimizedModel::WriteGLViewFiles(struct studiohdr_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::WriteGLViewFiles(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        const char *glViewFileName)
{
  char v3; // cl
  char v4; // dl
  char v5; // cl
  char v6; // al
  char v7; // dl
  char v8; // al
  char v9; // al
  char v10; // al
  char v11; // al
  char v12; // al
  char v13; // [esp+Bh] [ebp-171h]
  char *v14; // [esp+Ch] [ebp-170h]
  char *v15; // [esp+18h] [ebp-164h]
  const char *v16; // [esp+1Ch] [ebp-160h]
  char v17; // [esp+23h] [ebp-159h]
  char *v18; // [esp+24h] [ebp-158h]
  char *v19; // [esp+30h] [ebp-14Ch]
  const char *v20; // [esp+34h] [ebp-148h]
  char v21; // [esp+3Bh] [ebp-141h]
  char *v22; // [esp+3Ch] [ebp-140h]
  char *v23; // [esp+48h] [ebp-134h]
  const char *v24; // [esp+4Ch] [ebp-130h]
  char v25; // [esp+53h] [ebp-129h]
  char *v26; // [esp+54h] [ebp-128h]
  char *v27; // [esp+60h] [ebp-11Ch]
  const char *v28; // [esp+64h] [ebp-118h]
  char v29; // [esp+6Bh] [ebp-111h]
  char *v30; // [esp+6Ch] [ebp-110h]
  char *v31; // [esp+78h] [ebp-104h]
  const char *v32; // [esp+7Ch] [ebp-100h]
  char v33; // [esp+83h] [ebp-F9h]
  _DWORD *v34; // [esp+84h] [ebp-F8h]
  char *v35; // [esp+90h] [ebp-ECh]
  const char *v36; // [esp+94h] [ebp-E8h]
  char v37; // [esp+9Bh] [ebp-E1h]
  char *v38; // [esp+9Ch] [ebp-E0h]
  char *v39; // [esp+A8h] [ebp-D4h]
  const char *v40; // [esp+ACh] [ebp-D0h]
  char v41; // [esp+B3h] [ebp-C9h]
  char *v42; // [esp+B4h] [ebp-C8h]
  char *v43; // [esp+C0h] [ebp-BCh]
  const char *v44; // [esp+C4h] [ebp-B8h]
  char v45; // [esp+CBh] [ebp-B1h]
  _DWORD *v46; // [esp+CCh] [ebp-B0h]
  char *v47; // [esp+D8h] [ebp-A4h]
  const char *v48; // [esp+DCh] [ebp-A0h]
  char v49; // [esp+E3h] [ebp-99h]
  char *v50; // [esp+E4h] [ebp-98h]
  char *v51; // [esp+F0h] [ebp-8Ch]
  const char *v52; // [esp+F4h] [ebp-88h]
  OptimizedModel::COptimizedModel *thisa; // [esp+F8h] [ebp-84h] BYREF
  char tmpFileName[128]; // [esp+FCh] [ebp-80h] BYREF

  thisa = this;
  if ( g_bDumpGLViewFiles )
  {
    v52 = glViewFileName;
    v51 = tmpFileName;
    do
    {
      v3 = *v52;
      *v51++ = *v52++;
    }
    while ( v3 != 0 );
    v50 = (char *)&thisa + 3;
    do
      v49 = *++v50;
    while ( v49 != 0 );
    strcpy(v50, ".mesh");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 1,
      shrinkFactor: 0.80000001);
    v48 = glViewFileName;
    v47 = tmpFileName;
    do
    {
      v4 = *v48;
      *v47++ = *v48++;
    }
    while ( v4 != 0 );
    v46 = (OptimizedModel::COptimizedModel **)((char *)&thisa + 3);
    do
    {
      v45 = *((_BYTE *)v46 + 1);
      v46 = (_DWORD *)((char *)v46 + 1);
    }
    while ( v45 != 0 );
    *v46 = *(_DWORD *)aStr_0;
    v46[1] = 1919381609;
    v46[2] = &unk_70756F;
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 2,
      shrinkFactor: 0.80000001);
    v44 = glViewFileName;
    v43 = tmpFileName;
    do
    {
      v5 = *v44;
      *v43++ = *v44++;
    }
    while ( v5 != 0 );
    v42 = (char *)&thisa + 3;
    do
      v41 = *++v42;
    while ( v41 != 0 );
    strcpy(v42, ".strip");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 4,
      shrinkFactor: 0.80000001);
    v40 = glViewFileName;
    v39 = tmpFileName;
    do
    {
      v6 = *v40;
      *v39++ = *v40++;
    }
    while ( v6 != 0 );
    v38 = (char *)&thisa + 3;
    do
      v37 = *++v38;
    while ( v37 != 0 );
    strcpy(v38, ".substrip");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 8,
      shrinkFactor: 0.97000003);
    v36 = glViewFileName;
    v35 = tmpFileName;
    do
    {
      v7 = *v36;
      *v35++ = *v36++;
    }
    while ( v7 != 0 );
    v34 = (OptimizedModel::COptimizedModel **)((char *)&thisa + 3);
    do
    {
      v33 = *((_BYTE *)v34 + 1);
      v34 = (_DWORD *)((char *)v34 + 1);
    }
    while ( v33 != 0 );
    *v34 = *(_DWORD *)aFle_0;
    v34[1] = &dword_646578;
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 16,
      shrinkFactor: 0.80000001);
    v32 = glViewFileName;
    v31 = tmpFileName;
    do
    {
      v8 = *v32;
      *v31++ = *v32++;
    }
    while ( v8 != 0 );
    v30 = (char *)&thisa + 3;
    do
      v29 = *++v30;
    while ( v29 != 0 );
    strcpy(v30, ".sw");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 32,
      shrinkFactor: 0.80000001);
    v28 = glViewFileName;
    v27 = tmpFileName;
    do
    {
      v9 = *v28;
      *v27++ = *v28++;
    }
    while ( v9 != 0 );
    v26 = (char *)&thisa + 3;
    do
      v25 = *++v26;
    while ( v25 != 0 );
    strcpy(v26, ".flexedandsw");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 48,
      shrinkFactor: 0.80000001);
    v24 = glViewFileName;
    v23 = tmpFileName;
    do
    {
      v10 = *v24;
      *v23++ = *v24++;
    }
    while ( v10 != 0 );
    v22 = (char *)&thisa + 3;
    do
      v21 = *++v22;
    while ( v21 != 0 );
    strcpy(v22, ".meshprops");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 64,
      shrinkFactor: 0.80000001);
    v20 = glViewFileName;
    v19 = tmpFileName;
    do
    {
      v11 = *v20;
      *v19++ = *v20++;
    }
    while ( v11 != 0 );
    v18 = (char *)&thisa + 3;
    do
      v17 = *++v18;
    while ( v17 != 0 );
    strcpy(v18, ".vertnumbones");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 128,
      shrinkFactor: 1.0);
    v16 = glViewFileName;
    v15 = tmpFileName;
    do
    {
      v12 = *v16;
      *v15++ = *v16++;
    }
    while ( v12 != 0 );
    v14 = (char *)&thisa + 3;
    do
      v13 = *++v14;
    while ( v13 != 0 );
    strcpy(v14, ".stripnumbones");
    OptimizedModel::COptimizedModel::WriteGLViewFile(
      this: thisa,
      phdr: pHdr,
      pFileName: tmpFileName,
      flags: 256,
      shrinkFactor: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419830
// Name: public: unsigned int CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::Find(struct OptimizedModel::StripVertLookup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Find(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        unsigned int src)
{
  int ndxKeyData; // [esp+0h] [ebp-4h] BYREF

  ndxKeyData = 0;
  if ( CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::DoFind(
         this,
         (const OptimizedModel::StripVertLookup_t *)src,
         pBucket: &src,
         pIndex: &ndxKeyData) != 0 )
    return ndxKeyData | (src << 16);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00419870
// Name: public: int CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::Alloc(bool)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Alloc(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        bool multilist)
{
  void *result; // eax
  void *v3; // esi

  result = (void *)CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::AllocInternal(
                     this,
                     multilist);
  v3 = result;
  if ( result != nullptr )
  {
    operator new(__formal: 0xCu, _Where: result);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419B20
// Name: public: void CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::RemoveAll(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)((char *)m_pBlockHeader + 20 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[1] + 20 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t **)&m_pBlockHeader[2].m_nBlockSize
               + 5 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex)
            && *(&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[2].m_nBlockSize + 5 * m_nIndex) = (int)m_pBlockHeader + 20 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 20 * m_nIndex;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
      {
        break;
      }
    }
    v1[1].m_pBlocks = nullptr;
    v1[1].m_nAllocationCount = 0;
    v1[2].m_pBlocks = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419D60
// Name: public: OptimizedModel::Strip_t::Strip_t(void)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::Strip_t *__thiscall OptimizedModel::Strip_t::Strip_t(OptimizedModel::Strip_t *this)
{
  CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>(
    this: &this->verts,
    growSize: 0,
    initSize: 0);
  this->numTopologyIndices = 0;
  this->numIndices = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00419DF0
// Name: public: CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::~CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::~CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-Ch]

  CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419E20
// Name: public: void CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Free(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 12);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v4 = *(_DWORD *)(elem + 16);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x00419E90
// Name: public: void CUtlLinkedList<struct OptimizedModel::EdgeInfo_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct OptimizedModel::EdgeInfo_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::LinkBefore(
        CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 12);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v5 = *(_DWORD *)(elem + 16);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 12);
    *(_DWORD *)(before + 12) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 12) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 16) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A090
// Name: private: void OptimizedModel::COptimizedModel::BuildStripsRecursive(class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> __near &,class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,struct OptimizedModel::Face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildStripsRecursive(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *indices,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faceList,
        OptimizedModel::Face_t *face)
{
  OptimizedModel::Face_t *v4; // eax
  OptimizedModel::Face_t *v5; // eax
  OptimizedModel::Face_t *v6; // eax
  OptimizedModel::Face_t *v7; // eax
  unsigned __int16 v9; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int16 v10; // [esp+Eh] [ebp-6h] BYREF
  unsigned __int16 v11; // [esp+10h] [ebp-4h] BYREF
  unsigned __int16 src; // [esp+12h] [ebp-2h] BYREF

  if ( !face->touched && OptimizedModel::COptimizedModel::ComputeNewBonesNeeded(this, face) == 0 )
  {
    face->touched = true;
    src = face->vertID[0];
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: indices, &src);
    v11 = face->vertID[1];
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: indices, src: &v11);
    v10 = face->vertID[2];
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: indices, src: &v10);
    if ( face->vertID[3] != -1 )
    {
      v9 = face->vertID[3];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: indices, src: &v9);
    }
    if ( face->neighborID[0] != -1 )
    {
      v4 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: faceList,
             i: face->neighborID[0]);
      OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices, faceList, face: v4);
    }
    if ( face->neighborID[1] != -1 )
    {
      v5 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: faceList,
             i: face->neighborID[1]);
      OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices, faceList, face: v5);
    }
    if ( face->neighborID[2] != -1 )
    {
      v6 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: faceList,
             i: face->neighborID[2]);
      OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices, faceList, face: v6);
    }
    if ( face->neighborID[3] != -1 )
    {
      v7 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: faceList,
             i: face->neighborID[3]);
      OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices, faceList, face: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A1E0
// Name: OptimizedModel::FindMatchingEdge
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::FindMatchingEdge(
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *list,
        int nFaceId,
        int nEdgeIndex,
        const int *pVertIds,
        CUtlVector<int,CUtlMemory<int,int> > *vertexToEdges,
        CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t> *edges)
{
  ConVar *v6; // ecx
  int v7; // esi
  OptimizedModel::EdgeInfo_t *v8; // eax
  OptimizedModel::EdgeInfo_t *edge; // [esp+4h] [ebp-24h]
  int hEdge; // [esp+8h] [ebp-20h]
  OptimizedModel::Face_t *face; // [esp+Ch] [ebp-1Ch]
  int hFirstEdge; // [esp+10h] [ebp-18h]
  int nVertIndex; // [esp+14h] [ebp-14h]
  int nConnectedVertId; // [esp+1Ch] [ebp-Ch]
  void *hNewEdge; // [esp+20h] [ebp-8h]

  face = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: list, i: nFaceId);
  nVertIndex = pVertIds[*pVertIds >= pVertIds[1]];
  nConnectedVertId = pVertIds[*pVertIds < pVertIds[1]];
  hFirstEdge = *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: vertexToEdges, i: nVertIndex);
  v6 = (ConVar *)hFirstEdge;
  for ( hEdge = hFirstEdge;
        ;
        hEdge = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Next(
                  this: edges,
                  i: hEdge) )
  {
    if ( hEdge == CImportTex::GetCurrentVersion(this: v6) )
    {
      hNewEdge = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Alloc(
                   this: edges,
                   multilist: true);
      v8 = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::operator[](
             this: edges,
             i: (int)hNewEdge);
      v8->m_nConnectedVertId = nConnectedVertId;
      v8->m_nEdgeIndex = nEdgeIndex;
      v8->m_nFaceId = nFaceId;
      CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::LinkBefore(
        this: edges,
        before: hFirstEdge,
        elem: (int)hNewEdge);
      *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: vertexToEdges, i: nVertIndex) = (int)hNewEdge;
      return;
    }
    edge = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::operator[](
             this: edges,
             i: hEdge);
    if ( edge->m_nConnectedVertId == nConnectedVertId && edge->m_nFaceId != nFaceId )
      break;
  }
  face->neighborID[nEdgeIndex] = edge->m_nFaceId;
  CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: list, i: edge->m_nFaceId)->neighborID[edge->m_nEdgeIndex] = nFaceId;
  if ( hEdge == hFirstEdge )
  {
    v7 = CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Next(
           this: edges,
           i: hFirstEdge);
    *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: vertexToEdges, i: nVertIndex) = v7;
  }
  CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::Free(
    this: edges,
    elem: hEdge);
}

//------------------------------------------------------------------------------
// Address: 0x0041A350
// Name: private: void OptimizedModel::COptimizedModel::BuildSubDFaceList(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::SubD_Face_t,class CUtlMemory<struct OptimizedModel::SubD_Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> __near &,struct mstudio_meshvertexdata_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildSubDFaceList(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *faceList,
        CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *subDFaceList,
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vtxList,
        const mstudio_meshvertexdata_t *pVertexData)
{
  OptimizedModel::Face_t *v5; // esi
  int j; // [esp+8h] [ebp-30h]
  int i; // [esp+Ch] [ebp-2Ch]
  OptimizedModel::COptimizeSubDBuilder subDBuilder; // [esp+10h] [ebp-28h] BYREF
  int nFaceCount; // [esp+34h] [ebp-4h]

  nFaceCount = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: faceList);
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::RemoveAll(this: subDFaceList);
  CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::EnsureCapacity(
    this: subDFaceList,
    num: nFaceCount);
  for ( i = 0; i < nFaceCount; ++i )
  {
    CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::AddToTail(this: subDFaceList);
    for ( j = 0; j < 4; ++j )
    {
      v5 = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *)faceList,
             i);
      CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::operator[](
        this: subDFaceList,
        i)->vtxIDs[j] = v5->vertID[j];
    }
  }
  OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(
    this: &subDBuilder,
    subDFaceList,
    vertexList: vtxList,
    vertexData: &pVertexData,
    bIsTagged: false,
    bMendVertices: true);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&subDBuilder.m_IndexRemapTable);
}

//------------------------------------------------------------------------------
// Address: 0x0041A410
// Name: private: void OptimizedModel::COptimizedModel::SourceMeshToFaceList(struct s_model_t __near *,struct s_mesh_t __near *,class CUtlVector<struct mstudioiface_t,class CUtlMemory<struct mstudioiface_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::SourceMeshToFaceList(
        OptimizedModel::COptimizedModel *this,
        s_model_t *pSrcModel,
        s_mesh_t *pSrcMesh,
        CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int> > *meshFaceList)
{
  int j; // [esp+4h] [ebp-14h]
  mstudioiface_t *newFace; // [esp+8h] [ebp-10h]
  const s_face_t *pFace; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  s_face_t *pFaces; // [esp+14h] [ebp-4h]

  pFaces = &pSrcModel->source->face[pSrcMesh->faceoffset];
  for ( i = 0; i < pSrcMesh->numfaces; ++i )
  {
    pFace = &pFaces[i];
    j = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::AddToTail(this: meshFaceList);
    newFace = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::operator[](this: meshFaceList, i: j);
    newFace->a = pFace->a;
    newFace->b = pFace->b;
    newFace->c = pFace->c;
    newFace->d = pFace->d;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A4C0
// Name: private: void OptimizedModel::COptimizedModel::CreateLODFaceList(struct s_model_t __near *,int,struct s_source_t __near *,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,class CUtlVector<struct mstudioiface_t,class CUtlMemory<struct mstudioiface_t,int>> __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::CreateLODFaceList(
        OptimizedModel::COptimizedModel *this,
        s_model_t *pSrcModel,
        int nLodID,
        s_source_t *pSrc,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int> > *meshFaceList,
        bool bQuadSubd,
        bool writeDebug)
{
  int v9; // esi
  int *v10; // edi
  int v11; // [esp+8h] [ebp-3Ch]
  mstudioiface_t *newFace; // [esp+18h] [ebp-2Ch]
  const s_face_t *srcFace; // [esp+1Ch] [ebp-28h]
  int index; // [esp+20h] [ebp-24h]
  s_mesh_t *pSrcMesh; // [esp+24h] [ebp-20h]
  int textureSearchID; // [esp+28h] [ebp-1Ch]
  int i; // [esp+2Ch] [ebp-18h]
  int ia; // [esp+2Ch] [ebp-18h]
  int ib; // [esp+2Ch] [ebp-18h]
  CUtlVector<int,CUtlMemory<int,int> > indexMapping; // [esp+30h] [ebp-14h] BYREF

  if ( pSrc != nullptr && pSrcModel != nullptr )
  {
    textureSearchID = MaterialToTexture(material: pStudioMesh->material);
    pSrcMesh = nullptr;
    for ( i = 0; i < pStudioModel->nummeshes; ++i )
    {
      if ( pSrc->texmap[pSrc->meshindex[i]] == textureSearchID )
      {
        pSrcMesh = &pSrc->mesh[pSrc->meshindex[i]];
        break;
      }
    }
    if ( pSrcMesh != nullptr )
    {
      CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>(
        this: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&indexMapping,
        growSize: 0,
        initSize: 0);
      CUtlVector<int,CUtlMemory<int,int>>::AddMultipleToTail(this: &indexMapping, num: pSrcMesh->numvertices);
      for ( ia = 0; ia < pSrcMesh->numvertices; ++ia )
      {
        v9 = ia + pSrcMesh->vertexoffset;
        v10 = pSrcModel->m_pLodData->pMeshVertIndexMaps[nLodID];
        *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: ia) = v10[v9];
      }
      for ( ib = 0; ib < pSrcMesh->numfaces; ++ib )
      {
        index = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::AddToTail(this: meshFaceList);
        newFace = CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::operator[](this: meshFaceList, i: index);
        srcFace = &pSrc->face[ib + pSrcMesh->faceoffset];
        newFace->a = *(_WORD *)CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: srcFace->a);
        newFace->b = *(_WORD *)CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: srcFace->b);
        newFace->c = *(_WORD *)CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: srcFace->c);
        if ( bQuadSubd )
          v11 = *CUtlVector<int,CUtlMemory<int,int>>::operator[](this: &indexMapping, i: srcFace->d);
        else
          LOWORD(v11) = -1;
        newFace->d = v11;
      }
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&indexMapping);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A6A0
// Name: public: CUtlFixedLinkedList<struct OptimizedModel::EdgeInfo_t>::CUtlFixedLinkedList<struct OptimizedModel::EdgeInfo_t>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t> *__thiscall CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t>::CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t>(
        CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t> *this,
        int growSize,
        int initSize)
{
  this->m_Memory.m_pBlocks = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = growSize;
  CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>::Grow(this: &this->m_Memory, num: initSize);
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
  this->m_Head = 0;
  this->m_Tail = 0;
  this->m_FirstFree = 0;
  this->m_ElementCount = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041A700
// Name: public: unsigned int CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::Insert(struct OptimizedModel::StripVertLookup_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Insert(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        unsigned int src)
{
  const OptimizedModel::StripVertLookup_t *v2; // ebx
  unsigned int v5; // esi
  int ndxKeyData; // [esp+8h] [ebp-4h] BYREF

  v2 = (const OptimizedModel::StripVertLookup_t *)src;
  ndxKeyData = 0;
  if ( CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::DoFind(
         this,
         (const OptimizedModel::StripVertLookup_t *)src,
         pBucket: &src,
         pIndex: &ndxKeyData) != 0 )
    return ndxKeyData | (src << 16);
  v5 = src;
  return (v5 << 16)
       | CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int>>::InsertBefore(
           this: &this->m_Buckets.m_Memory.m_pMemory[src],
           elem: this->m_Buckets.m_Memory.m_pMemory[src].m_Size,
           src: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0041A7E0
// Name: public: void OptimizedModel::CStringTable::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::CStringTable::AddString(OptimizedModel::CStringTable *this, const char *newString)
{
  int v2; // eax
  char v3; // dl
  char *v4; // [esp+8h] [ebp-30h]
  const char *v5; // [esp+Ch] [ebp-2Ch]
  CUtlVector<char,CUtlMemory<char,int> > *s; // [esp+34h] [ebp-4h]

  if ( OptimizedModel::CStringTable::StringPresent(this, string: newString) == 0 )
  {
    v2 = CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::AddToTail((CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this);
    s = (CUtlVector<char,CUtlMemory<char,int> > *)CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                                                    (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)this,
                                                    i: v2);
    CUtlVector<char,CUtlMemory<char,int>>::AddMultipleToTail(this: s, num: strlen(newString) + 1);
    v5 = newString;
    v4 = CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: s);
    do
    {
      v3 = *v5;
      *v4++ = *v5++;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A8A0
// Name: OptimizedModel::FindOrCreateVertex
// Source: json
//------------------------------------------------------------------------------
int __cdecl OptimizedModel::FindOrCreateVertex(
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *list,
        const OptimizedModel::Vertex_t *vert)
{
  CDmeClip *v2; // ecx
  int v4; // [esp+5Ch] [ebp-10h]
  int vertexHandle; // [esp+60h] [ebp-Ch]
  OptimizedModel::StripVertLookup_t stripVertLookup; // [esp+64h] [ebp-8h] BYREF

  stripVertLookup.origMeshVertID = vert->origMeshVertID;
  stripVertLookup.vertID = -1;
  vertexHandle = CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Find(
                   this: &OptimizedModel::g_StripGroupVertexLookup,
                   src: (unsigned int)&stripVertLookup);
  if ( vertexHandle != CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::InvalidHandle(this: v2) )
    return CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Element(
             this: &OptimizedModel::g_StripGroupVertexLookup,
             handle: vertexHandle)->vertID;
  v4 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(this: list, src: vert);
  stripVertLookup.vertID = v4;
  CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Insert(
    this: &OptimizedModel::g_StripGroupVertexLookup,
    src: (unsigned int)&stripVertLookup);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041A920
// Name: private: void OptimizedModel::COptimizedModel::BuildNeighborInfo(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildNeighborInfo(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faceList,
        int nMaxVertexId)
{
  unsigned __int8 *v3; // eax
  OptimizedModel::Face_t *face; // [esp+4h] [ebp-58h]
  int i; // [esp+8h] [ebp-54h]
  CUtlVector<int,CUtlMemory<int,int> > vertexToEdges; // [esp+Ch] [ebp-50h] BYREF
  int numVerts; // [esp+20h] [ebp-3Ch]
  int pEdgeVertIds[2]; // [esp+24h] [ebp-38h] BYREF
  CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t> edges; // [esp+2Ch] [ebp-30h] BYREF
  int nFaceCount; // [esp+58h] [ebp-4h]

  CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t>::CUtlFixedLinkedList<OptimizedModel::EdgeInfo_t>(
    this: &edges,
    growSize: 0,
    initSize: 0);
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>(
    this: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&vertexToEdges,
    growSize: 0,
    initSize: 0);
  CUtlVector<int,CUtlMemory<int,int>>::SetCount(this: &vertexToEdges, count: nMaxVertexId);
  v3 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&vertexToEdges);
  memset(dst: v3, value: 0, count: 4 * nMaxVertexId);
  numVerts = (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                this: faceList,
                i: 0)->vertID[3] != -1)
           + 3;
  nFaceCount = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faceList);
  CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::EnsureCapacity(
    this: &edges,
    num: 2 * nFaceCount);
  for ( i = 0; i < nFaceCount; ++i )
  {
    face = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](this: faceList, i);
    *(_QWORD *)pEdgeVertIds = *(_QWORD *)face->vertID;
    OptimizedModel::FindMatchingEdge(
      list: faceList,
      nFaceId: i,
      nEdgeIndex: 0,
      pVertIds: pEdgeVertIds,
      &vertexToEdges,
      &edges);
    *(_QWORD *)pEdgeVertIds = *(_QWORD *)&face->vertID[1];
    OptimizedModel::FindMatchingEdge(
      list: faceList,
      nFaceId: i,
      nEdgeIndex: 1,
      pVertIds: pEdgeVertIds,
      &vertexToEdges,
      &edges);
    if ( numVerts == 3 )
    {
      pEdgeVertIds[0] = face->vertID[2];
      pEdgeVertIds[1] = face->vertID[0];
      OptimizedModel::FindMatchingEdge(
        list: faceList,
        nFaceId: i,
        nEdgeIndex: 2,
        pVertIds: pEdgeVertIds,
        &vertexToEdges,
        &edges);
    }
    else
    {
      *(_QWORD *)pEdgeVertIds = *(_QWORD *)&face->vertID[2];
      OptimizedModel::FindMatchingEdge(
        list: faceList,
        nFaceId: i,
        nEdgeIndex: 2,
        pVertIds: pEdgeVertIds,
        &vertexToEdges,
        &edges);
      pEdgeVertIds[0] = face->vertID[3];
      pEdgeVertIds[1] = face->vertID[0];
      OptimizedModel::FindMatchingEdge(
        list: faceList,
        nFaceId: i,
        nEdgeIndex: 3,
        pVertIds: pEdgeVertIds,
        &vertexToEdges,
        &edges);
    }
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&vertexToEdges);
  CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>::~CUtlLinkedList<OptimizedModel::EdgeInfo_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<OptimizedModel::EdgeInfo_t,int>>>(this: &edges);
}

//------------------------------------------------------------------------------
// Address: 0x0041AAE0
// Name: private: void OptimizedModel::COptimizedModel::PostProcessStripGroup(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::PostProcessStripGroup(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        ConCommandBase *pStripGroup)
{
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  CDmeClip *v10; // ecx
  DmeClipType_t v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  int v15; // eax
  bool v16; // [esp+0h] [ebp-8Ch]
  unsigned __int16 v18; // [esp+46h] [ebp-46h] BYREF
  int m; // [esp+48h] [ebp-44h]
  int newIndex; // [esp+4Ch] [ebp-40h]
  unsigned int vertexHandle; // [esp+50h] [ebp-3Ch]
  OptimizedModel::StripVertLookup_t src; // [esp+54h] [ebp-38h] BYREF
  int index; // [esp+5Ch] [ebp-30h]
  OptimizedModel::Vertex_t *pVert; // [esp+60h] [ebp-2Ch]
  int j; // [esp+64h] [ebp-28h]
  OptimizedModel::StripVertLookup_t stripVertLookup; // [esp+68h] [ebp-24h] BYREF
  int k; // [esp+70h] [ebp-1Ch]
  OptimizedModel::Strip_t *pStrip; // [esp+74h] [ebp-18h]
  int vertOffset; // [esp+78h] [ebp-14h]
  bool bSubDQuad; // [esp+7Fh] [ebp-Dh]
  int nSearch; // [esp+80h] [ebp-Ch]
  int maxNumBones; // [esp+84h] [ebp-8h]
  int i; // [esp+88h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v4 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 60));
    if ( i >= (int)v4 )
      break;
    pStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
               this: (CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int> > *)&pStripGroup[2].m_pszName,
               i);
    vertOffset = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 40));
    pStrip->stripGroupVertexOffset = vertOffset;
    v5 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
    pStrip->stripGroupIndexOffset = (int)v5;
    v6 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->m_nFlags);
    pStrip->stripGroupTopologyOffset = (int)v6;
    v7 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
      this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)pStripGroup,
      num: (int)&v7[pStrip->numIndices]);
    v8 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->m_nFlags);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
      this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&pStripGroup->m_nFlags,
      num: (int)&v8[pStrip->numTopologyIndices]);
    maxNumBones = 0;
    v16 = (pStrip->flags & 4) != 0 || (pStrip->flags & 2) != 0;
    bSubDQuad = v16;
    nSearch = vertOffset;
    if ( v16 )
    {
      pStrip->stripGroupVertexOffset = 0;
      nSearch = 0;
    }
    CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::RemoveAll(this: &OptimizedModel::g_StripGroupVertexLookup);
    for ( k = nSearch; ; ++k )
    {
      v9 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 40));
      if ( k >= (int)v9 )
        break;
      stripVertLookup.origMeshVertID = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
                                         this: (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)&pStripGroup[1].m_pszHelpString,
                                         i: k)->origMeshVertID;
      stripVertLookup.vertID = k;
      CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Insert(
        this: &OptimizedModel::g_StripGroupVertexLookup,
        src: (unsigned int)&stripVertLookup);
    }
    for ( j = 0; j < pStrip->numIndices; ++j )
    {
      newIndex = -1;
      index = pStrip->pIndices[j];
      pVert = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
                this: &pStrip->verts,
                i: index);
      src.origMeshVertID = pVert->origMeshVertID;
      src.vertID = -1;
      vertexHandle = CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Find(
                       this: &OptimizedModel::g_StripGroupVertexLookup,
                       (unsigned int)&src);
      v11 = CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::InvalidHandle(this: v10);
      if ( vertexHandle == v11 )
      {
        newIndex = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(
                     this: (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)&pStripGroup[1].m_pszHelpString,
                     src: pVert);
        src.vertID = newIndex;
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Insert(
          this: &OptimizedModel::g_StripGroupVertexLookup,
          (unsigned int)&src);
      }
      else
      {
        newIndex = CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::Element(
                     this: &OptimizedModel::g_StripGroupVertexLookup,
                     handle: vertexHandle)->vertID;
      }
      v18 = newIndex;
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
        this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)pStripGroup,
        src: &v18);
      if ( pVert->numBones > maxNumBones )
        maxNumBones = pVert->numBones;
    }
    for ( m = 0; m < pStrip->numTopologyIndices; ++m )
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
        this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&pStripGroup->m_nFlags,
        src: &pStrip->pTopologyIndices[m]);
    v12 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: pStripGroup);
    pStrip->numStripGroupIndices = (int)&v12[-pStrip->stripGroupIndexOffset];
    v13 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&pStripGroup->m_nFlags);
    pStrip->numStripGroupTopologyIndices = (int)&v13[-pStrip->stripGroupTopologyOffset];
    v14 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)((char *)pStripGroup + 40));
    pStrip->numStripGroupVerts = (int)&v14[-pStrip->stripGroupVertexOffset];
    if ( this->m_bUsesFixedFunction )
    {
      v15 = OptimizedModel::COptimizedModel::CountUniqueBonesInStrip(
              this,
              (OptimizedModel::StripGroup_t *)pStripGroup,
              pStrip);
      pStrip->numBones = v15;
    }
    else
    {
      pStrip->numBones = maxNumBones;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041ADE0
// Name: OptimizedModel::AddMaterialReplacementsToStringTable
// Source: json
//------------------------------------------------------------------------------
const char *OptimizedModel::AddMaterialReplacementsToStringTable()
{
  const char *result; // eax
  const char *newString; // [esp+14h] [ebp-18h]
  LodScriptData_t *scriptLOD; // [esp+1Ch] [ebp-10h]
  int j; // [esp+20h] [ebp-Ch]
  int numLODs; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  result = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
  numLODs = (int)result;
  for ( i = 0; i < numLODs; ++i )
  {
    scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](this: &g_ScriptLODs, i);
    for ( j = 0;
          j < (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&scriptLOD->materialReplacements);
          ++j )
    {
      newString = CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::operator[](
                    this: &scriptLOD->materialReplacements,
                    i: j)->m_pDstName;
      OptimizedModel::CStringTable::AddString(this: &s_StringTable, newString);
    }
    result = (const char *)(i + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041AF30
// Name: private: void OptimizedModel::COptimizedModel::BuildHWSkinnedStrips(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> __near &,struct OptimizedModel::StripGroup_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildHWSkinnedStrips(
        OptimizedModel::COptimizedModel *this,
        CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *faceList,
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *vertices,
        OptimizedModel::StripGroup_t *pStripGroup,
        int maxBonesPerStrip)
{
  const char *v5; // eax
  const char *v6; // eax
  const OptimizedModel::Vertex_t *v7; // eax
  int v8; // eax
  int v9; // eax
  int NthBoneGlobalID; // eax
  ConCommandBase sourceTopologyIndices; // [esp+4h] [ebp-40h] BYREF
  int i; // [esp+1Ch] [ebp-28h]
  int stripIdx; // [esp+20h] [ebp-24h]
  OptimizedModel::Strip_t *newStrip; // [esp+24h] [ebp-20h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > facesToStrip; // [esp+28h] [ebp-1Ch] BYREF
  OptimizedModel::Face_t *pSeedFace; // [esp+3Ch] [ebp-8h]
  int numVerts; // [esp+40h] [ebp-4h]

  CHardwareMatrixState::Init(this: &this->m_HardwareMatrixState, numHardwareMatrices: maxBonesPerStrip);
  numVerts = (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                this: faceList,
                i: 0)->vertID[3] != -1)
           + 3;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
    this: &facesToStrip,
    growSize: 0,
    initSize: 0);
  v5 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)faceList);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
    this: &facesToStrip,
    num: numVerts * (_DWORD)v5);
  pSeedFace = OptimizedModel::GetNextUntouched(faces: faceList);
  while ( pSeedFace != nullptr )
  {
    OptimizedModel::COptimizedModel::AllocateHardwareBonesForFace(this, face: pSeedFace);
    OptimizedModel::COptimizedModel::BuildStripsRecursive(this, indices: &facesToStrip, faceList, face: pSeedFace);
    pSeedFace = OptimizedModel::COptimizedModel::GetNextFace(this, faceList, allowNewStrip: false);
    if ( pSeedFace == nullptr )
    {
      stripIdx = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::AddToTail(this: &pStripGroup->strips);
      newStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                   this: &pStripGroup->strips,
                   i: stripIdx);
      newStrip->flags = numVerts != 3 ? 4 : 1;
      OptimizedModel::COptimizedModel::SanityCheckVertBones(this, list: &facesToStrip, vertices);
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
        this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&sourceTopologyIndices,
        growSize: 0,
        initSize: 0);
      OptimizedModel::COptimizedModel::Stripify(
        this,
        sourceIndices: (ConCommandBase *)&facesToStrip,
        &sourceTopologyIndices,
        bIsHWSkinned: true,
        pNumIndices: (unsigned int *)&newStrip->numIndices,
        pNumTopologyIndices: nullptr,
        ppIndices: &newStrip->pIndices,
        ppTopologyIndices: nullptr,
        bQuadSubd: numVerts == 4);
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&sourceTopologyIndices);
      for ( i = 0; ; ++i )
      {
        v6 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)vertices);
        if ( i >= (int)v6 )
          break;
        v7 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
               this: vertices,
               i);
        CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(
          this: &newStrip->verts,
          src: v7);
      }
      v8 = CHardwareMatrixState::AllocatedMatrixCount(this: &this->m_HardwareMatrixState);
      newStrip->numBoneStateChanges = v8;
      for ( sourceTopologyIndices.m_nFlags = 0; ; ++sourceTopologyIndices.m_nFlags )
      {
        v9 = CHardwareMatrixState::AllocatedMatrixCount(this: &this->m_HardwareMatrixState);
        if ( sourceTopologyIndices.m_nFlags >= v9 )
          break;
        newStrip->boneStateChanges[sourceTopologyIndices.m_nFlags].hardwareID = sourceTopologyIndices.m_nFlags;
        NthBoneGlobalID = CHardwareMatrixState::GetNthBoneGlobalID(
                            this: &this->m_HardwareMatrixState,
                            n: sourceTopologyIndices.m_nFlags);
        newStrip->boneStateChanges[sourceTopologyIndices.m_nFlags].newBoneID = NthBoneGlobalID;
      }
      CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::RemoveAll(this: (CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *)&facesToStrip);
      pSeedFace = OptimizedModel::COptimizedModel::GetNextFace(this, faceList, allowNewStrip: true);
    }
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&facesToStrip);
}

//------------------------------------------------------------------------------
// Address: 0x0041B120
// Name: private: void OptimizedModel::COptimizedModel::BuildSWSkinnedStrips(class CUtlVector<struct OptimizedModel::Face_t,class CUtlMemory<struct OptimizedModel::Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::SubD_Face_t,class CUtlMemory<struct OptimizedModel::SubD_Face_t,int>> __near &,class CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>> const __near &,struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::BuildSWSkinnedStrips(
        OptimizedModel::COptimizedModel *this,
        ConCommandBase *faceList,
        ConCommandBase *subdFaceList,
        ConCommandBase *vertices,
        OptimizedModel::StripGroup_t *pStripGroup)
{
  const char *v5; // eax
  const OptimizedModel::Vertex_t *v6; // eax
  const char *v7; // eax
  const OptimizedModel::Vertex_t *v8; // eax
  unsigned __int16 v10; // [esp+Ah] [ebp-76h] BYREF
  unsigned __int16 v11; // [esp+Ch] [ebp-74h] BYREF
  unsigned __int16 v12; // [esp+Eh] [ebp-72h] BYREF
  unsigned __int16 v13; // [esp+10h] [ebp-70h] BYREF
  unsigned __int16 v14; // [esp+12h] [ebp-6Eh] BYREF
  unsigned __int16 v15; // [esp+14h] [ebp-6Ch] BYREF
  unsigned __int16 src; // [esp+16h] [ebp-6Ah] BYREF
  int k; // [esp+18h] [ebp-68h]
  int i; // [esp+1Ch] [ebp-64h]
  __int16 totalOneRingSize; // [esp+20h] [ebp-60h]
  int b; // [esp+24h] [ebp-5Ch]
  int v; // [esp+28h] [ebp-58h]
  int j; // [esp+2Ch] [ebp-54h]
  OptimizedModel::SubD_Face_t *subDFace; // [esp+30h] [ebp-50h]
  OptimizedModel::Face_t *face; // [esp+34h] [ebp-4Ch]
  int f; // [esp+38h] [ebp-48h]
  bool bSubDQuad; // [esp+3Fh] [ebp-41h]
  int stripIdx; // [esp+40h] [ebp-40h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > topologyIndices; // [esp+44h] [ebp-3Ch] BYREF
  OptimizedModel::Strip_t *pNewStrip; // [esp+58h] [ebp-28h]
  bool bExtraFaces; // [esp+5Fh] [ebp-21h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > indices; // [esp+60h] [ebp-20h] BYREF
  int nFaceCount; // [esp+74h] [ebp-Ch]
  int nVertsPerFace; // [esp+78h] [ebp-8h]
  int nSubDFaces; // [esp+7Ch] [ebp-4h]

  nSubDFaces = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: subdFaceList);
  stripIdx = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::AddToTail(this: &pStripGroup->strips);
  pNewStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                this: &pStripGroup->strips,
                i: stripIdx);
  nFaceCount = (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: faceList);
  nVertsPerFace = (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
                     this: (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *)faceList,
                     i: 0)->vertID[3] != -1)
                + 3;
  pNewStrip->flags = (nVertsPerFace != 3) + 1;
  bSubDQuad = nVertsPerFace == 4;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
    this: &indices,
    growSize: 0,
    initSize: 0);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
    this: &indices,
    num: nFaceCount * nVertsPerFace);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
    this: &topologyIndices,
    growSize: 0,
    initSize: 0);
  if ( bSubDQuad )
  {
    if ( nVertsPerFace == 4 )
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
        this: &topologyIndices,
        num: 40 * nFaceCount);
    else
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
        this: &topologyIndices,
        num: nVertsPerFace * nFaceCount);
  }
  bExtraFaces = false;
  for ( f = 0; f < nFaceCount; ++f )
  {
    face = CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int>>::operator[](
             this: (CUtlVector<OptimizedModel::Face_t,CUtlMemory<OptimizedModel::Face_t,int> > *)faceList,
             i: f);
    face->touched = true;
    if ( bSubDQuad )
    {
      subDFace = CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::operator[](
                   this: (CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *)subdFaceList,
                   i: f);
      if ( !bExtraFaces && !OptimizedModel::FaceIsRegular(patch: subDFace) )
      {
        if ( (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&topologyIndices) > 0
          && (int)CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&indices) > 1200 )
        {
          OptimizedModel::COptimizedModel::Stripify(
            this,
            sourceIndices: (ConCommandBase *)&indices,
            sourceTopologyIndices: (ConCommandBase *)&topologyIndices,
            bIsHWSkinned: false,
            pNumIndices: (unsigned int *)&pNewStrip->numIndices,
            pNumTopologyIndices: &pNewStrip->numTopologyIndices,
            ppIndices: &pNewStrip->pIndices,
            ppTopologyIndices: &pNewStrip->pTopologyIndices,
            bQuadSubd: bSubDQuad);
          for ( v = 0; ; ++v )
          {
            v5 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: vertices);
            if ( v >= (int)v5 )
              break;
            v6 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
                   this: (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)vertices,
                   i: v);
            CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(
              this: &pNewStrip->verts,
              src: v6);
          }
          pNewStrip->numBoneStateChanges = 0;
          for ( b = 0; b < 512; ++b )
          {
            pNewStrip->boneStateChanges[b].hardwareID = -1;
            pNewStrip->boneStateChanges[b].newBoneID = -1;
          }
          stripIdx = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::AddToTail(this: &pStripGroup->strips);
          pNewStrip = CUtlVector<OptimizedModel::Strip_t,CUtlMemory<OptimizedModel::Strip_t,int>>::operator[](
                        this: &pStripGroup->strips,
                        i: stripIdx);
          CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::RemoveAll(this: (CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *)&indices);
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
            this: &indices,
            num: nFaceCount * nVertsPerFace);
          CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int>>::RemoveAll(this: (CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *)&topologyIndices);
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
            this: &topologyIndices,
            num: 40 * nFaceCount);
        }
        pNewStrip->flags = 4;
        bExtraFaces = true;
      }
      src = face->vertID[0];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, &src);
      v15 = face->vertID[1];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v15);
      v14 = face->vertID[2];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v14);
      v13 = face->vertID[3];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v13);
      j = 0;
      if ( nSubDFaces == nFaceCount )
      {
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vtx1RingSize[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vtx1RingCenterQuadOffset[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->valences[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->minOneRingIndex[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->bndVtx[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->bndEdge[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->cornerVtx[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->loopGapAngle[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->nbCornerVtx[j]);
        for ( j = 0; j < 8; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->edgeBias[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vUV0[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vUV1[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vUV2[j]);
        for ( j = 0; j < 4; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->vUV3[j]);
        totalOneRingSize = subDFace->vtx1RingSize[3]
                         + subDFace->vtx1RingSize[2]
                         + subDFace->vtx1RingSize[1]
                         + subDFace->vtx1RingSize[0];
        for ( j = 0; j < totalOneRingSize; ++j )
          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(
            this: &topologyIndices,
            src: &subDFace->oneRing[j]);
      }
    }
    else
    {
      v12 = face->vertID[0];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v12);
      v11 = face->vertID[1];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v11);
      v10 = face->vertID[2];
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::AddToTail(this: &indices, src: &v10);
    }
  }
  OptimizedModel::COptimizedModel::Stripify(
    this,
    sourceIndices: (ConCommandBase *)&indices,
    sourceTopologyIndices: (ConCommandBase *)&topologyIndices,
    bIsHWSkinned: false,
    pNumIndices: (unsigned int *)&pNewStrip->numIndices,
    pNumTopologyIndices: &pNewStrip->numTopologyIndices,
    ppIndices: &pNewStrip->pIndices,
    ppTopologyIndices: &pNewStrip->pTopologyIndices,
    bQuadSubd: bSubDQuad);
  for ( i = 0; ; ++i )
  {
    v7 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: vertices);
    if ( i >= (int)v7 )
      break;
    v8 = CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::operator[](
           this: (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)vertices,
           i);
    CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::AddToTail(
      this: &pNewStrip->verts,
      src: v8);
  }
  pNewStrip->numBoneStateChanges = 0;
  for ( k = 0; k < 512; ++k )
  {
    pNewStrip->boneStateChanges[k].hardwareID = -1;
    pNewStrip->boneStateChanges[k].newBoneID = -1;
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&topologyIndices);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&indices);
}

//------------------------------------------------------------------------------
// Address: 0x0041BC10
// Name: public: CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>(int,int,int,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &))
// Source: json
//------------------------------------------------------------------------------
CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *__thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this,
        int bucketCount,
        int growCount,
        int initCount,
        bool (__cdecl *compareFunc)(const OptimizedModel::StripVertLookup_t *, const OptimizedModel::StripVertLookup_t *),
        unsigned int (__cdecl *keyFunc)(const OptimizedModel::StripVertLookup_t *))
{
  int v6; // ebx
  int v8; // edi
  CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int> > *v9; // ecx
  bool v10; // al

  v6 = bucketCount;
  v8 = 0;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  this->m_CompareFunc = compareFunc;
  this->m_KeyFunc = keyFunc;
  if ( bucketCount >= 0x10000 )
  {
    bucketCount = 0x10000;
    v6 = 0x10000;
  }
  CUtlVector<CUtlVectorAuto<s_animation_t *>,CUtlMemory<CUtlVectorAuto<s_animation_t *>,int>>::RemoveAll((CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int>>,CUtlMemory<CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int>>,int>>::InsertMultipleBefore(
    this: &this->m_Buckets,
    elem: this->m_Buckets.m_Size,
    num: v6);
  if ( v6 > 0 )
  {
    do
    {
      v9 = &this->m_Buckets.m_Memory.m_pMemory[v8];
      v9->m_Size = 0;
      CUtlVector<OptimizedModel::StripVertLookup_t,CUtlMemory<OptimizedModel::StripVertLookup_t,int>>::InsertMultipleBefore(
        this: v9,
        elem: 0,
        num: initCount);
      this->m_Buckets.m_Memory.m_pMemory[v8++].m_Memory.m_nGrowSize = growCount;
      --v6;
    }
    while ( v6 != 0 );
    v6 = bucketCount;
  }
  v10 = IsPowerOfTwo(value: v6);
  this->m_bPowerOfTwo = v10;
  if ( v10 )
    this->m_ModMask = v6 - 1;
  else
    this->m_ModMask = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041BCC0
// Name: public: CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::~CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::~CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>(
        CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl*)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl*)(OptimizedModel::StripVertLookup_t const &)> *this)
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge((CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)this);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>((CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0041BCD0
// Name: struct OptimizedModel::StripGroup_t __near * Construct<struct OptimizedModel::StripGroup_t>(struct OptimizedModel::StripGroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
OptimizedModel::StripGroup_t *__cdecl Construct<OptimizedModel::StripGroup_t>(OptimizedModel::StripGroup_t *pMemory)
{
  OptimizedModel::StripGroup_t *result; // eax

  result = (OptimizedModel::StripGroup_t *)operator new(__formal: 0x54u, _Where: pMemory);
  if ( result == nullptr )
    return nullptr;
  result->indices.m_Memory.m_pMemory = nullptr;
  result->indices.m_Memory.m_nAllocationCount = 0;
  result->indices.m_Memory.m_nGrowSize = 0;
  result->indices.m_Size = 0;
  result->indices.m_pElements = nullptr;
  result->topologyIndices.m_Memory.m_pMemory = nullptr;
  result->topologyIndices.m_Memory.m_nAllocationCount = 0;
  result->topologyIndices.m_Memory.m_nGrowSize = 0;
  result->topologyIndices.m_Size = 0;
  result->topologyIndices.m_pElements = nullptr;
  result->verts.m_Memory.m_pMemory = nullptr;
  result->verts.m_Memory.m_nAllocationCount = 0;
  result->verts.m_Memory.m_nGrowSize = 0;
  result->verts.m_Size = 0;
  result->verts.m_pElements = nullptr;
  result->strips.m_Memory.m_pMemory = nullptr;
  result->strips.m_Memory.m_nAllocationCount = 0;
  result->strips.m_Memory.m_nGrowSize = 0;
  result->strips.m_Size = 0;
  result->strips.m_pElements = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BF90
// Name: private: void OptimizedModel::COptimizedModel::ProcessMesh(struct OptimizedModel::Mesh_t __near *,struct studiohdr_t __near *,class CUtlVector<struct mstudioiface_t,class CUtlMemory<struct mstudioiface_t,int>> __near &,struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ProcessMesh(
        OptimizedModel::COptimizedModel *this,
        OptimizedModel::Mesh_t *pMesh,
        studiohdr_t *pStudioHeader,
        ConCommandBase *srcFaces,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        bool bForceNoFlex,
        bool bForceSoftwareSkin,
        bool bHWFlex,
        bool bQuadSubd)
{
  const char *v10; // eax
  unsigned __int8 *v11; // eax
  const char *v12; // [esp-4h] [ebp-40h]
  int realMaxBonesPerFace; // [esp+Ch] [ebp-30h]
  int realMaxBonesPerVert; // [esp+10h] [ebp-2Ch]
  OptimizedModel::StripGroup_t *newStripGroup; // [esp+14h] [ebp-28h]
  int newStripGroupIndex; // [esp+18h] [ebp-24h]
  int realMaxBonesPerStrip; // [esp+1Ch] [ebp-20h]
  int isFlexed; // [esp+20h] [ebp-1Ch]
  int isHWSkinned; // [esp+24h] [ebp-18h]
  CUtlVector<bool,CUtlMemory<bool,int> > facesProcessed; // [esp+28h] [ebp-14h] BYREF

  OptimizedModel::COptimizedModel::ComputeMeshFlags(this, pMesh, pStudioHeader, pStudioMesh);
  CUtlVector<bool,CUtlMemory<bool,int>>::CUtlVector<bool,CUtlMemory<bool,int>>(
    this: &facesProcessed,
    growSize: 0,
    initSize: 0);
  v10 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: srcFaces);
  CUtlVector<bool,CUtlMemory<bool,int>>::AddMultipleToTail(this: &facesProcessed, num: (int)v10);
  v12 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&facesProcessed);
  v11 = (unsigned __int8 *)CUtlVector<bool,CUtlMemory<bool,int>>::Base(this: (CUtlVector<char,CUtlMemory<char,int> > *)&facesProcessed);
  memset(dst: v11, value: 0, count: (unsigned int)v12);
  for ( isHWSkinned = !bForceSoftwareSkin; isHWSkinned >= 0; --isHWSkinned )
  {
    for ( isFlexed = 1; isFlexed >= 0; --isFlexed )
    {
      if ( isFlexed == 0 || bHWFlex )
      {
        realMaxBonesPerFace = this->m_MaxBonesPerFace;
        realMaxBonesPerVert = this->m_MaxBonesPerVert;
        realMaxBonesPerStrip = this->m_MaxBonesPerStrip;
      }
      else
      {
        realMaxBonesPerFace = 1;
        realMaxBonesPerVert = 1;
        realMaxBonesPerStrip = 1;
      }
      newStripGroupIndex = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::AddToTail(this: &pMesh->stripGroups);
      newStripGroup = CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::operator[](
                        this: &pMesh->stripGroups,
                        i: newStripGroupIndex);
      OptimizedModel::COptimizedModel::ProcessStripGroup(
        this,
        pStripGroup: newStripGroup,
        bIsHWSkinned: isHWSkinned != 0,
        bIsFlexed: isFlexed != 0,
        pStudioModel,
        pStudioMesh,
        (CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int> > *)srcFaces,
        &facesProcessed,
        maxBonesPerVert: realMaxBonesPerVert,
        maxBonesPerFace: realMaxBonesPerFace,
        maxBonesPerStrip: realMaxBonesPerStrip,
        bForceNoFlex,
        bHWFlex,
        bQuadSubd);
      OptimizedModel::COptimizedModel::PostProcessStripGroup(
        this,
        pStudioModel,
        pStudioMesh,
        pStripGroup: (ConCommandBase *)newStripGroup);
      if ( CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)newStripGroup) == nullptr )
        CUtlVector<OptimizedModel::StripGroup_t,CUtlMemory<OptimizedModel::StripGroup_t,int>>::FastRemove(
          this: &pMesh->stripGroups,
          elem: newStripGroupIndex);
    }
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&facesProcessed);
}

//------------------------------------------------------------------------------
// Address: 0x0041C390
// Name: private: void OptimizedModel::COptimizedModel::ProcessModel(struct studiohdr_t __near *,struct s_bodypart_t __near *,struct OptimizedModel::TotalMeshStats_t __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizedModel::ProcessModel(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        s_bodypart_t *pSrcBodyParts,
        OptimizedModel::TotalMeshStats_t *stats,
        bool bForceSoftwareSkin,
        bool bHWFlex)
{
  const char *v6; // eax
  bool v7; // [esp+0h] [ebp-6Ch]
  mstudiomesh_t *pStudioMesh; // [esp+Ch] [ebp-60h]
  OptimizedModel::Mesh_t *newMesh; // [esp+10h] [ebp-5Ch]
  s_mesh_t *pSrcMesh; // [esp+14h] [ebp-58h]
  CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int> > meshFaceList; // [esp+18h] [ebp-54h] BYREF
  int v13; // [esp+2Ch] [ebp-40h]
  bool bQuadSubd; // [esp+33h] [ebp-39h]
  OptimizedModel::ModelLOD_t *newLOD; // [esp+34h] [ebp-38h]
  LodScriptData_t *scriptLOD; // [esp+38h] [ebp-34h]
  s_source_t *pLODSource; // [esp+3Ch] [ebp-30h]
  int v18; // [esp+40h] [ebp-2Ch]
  int i; // [esp+44h] [ebp-28h]
  mstudiomodel_t *pStudioModel; // [esp+48h] [ebp-24h]
  s_model_t *pSrcModel; // [esp+4Ch] [ebp-20h]
  OptimizedModel::Model_t *newModel; // [esp+50h] [ebp-1Ch]
  s_bodypart_t *pSrcBodyPart; // [esp+54h] [ebp-18h]
  mstudiobodyparts_t *pBodyPart; // [esp+58h] [ebp-14h]
  int modelID; // [esp+5Ch] [ebp-10h]
  int meshID; // [esp+60h] [ebp-Ch]
  int bodyPartID; // [esp+64h] [ebp-8h]
  int lodID; // [esp+68h] [ebp-4h]

  memset(dst: (unsigned __int8 *)stats, value: 0, count: sizeof(OptimizedModel::TotalMeshStats_t));
  CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::RemoveAll(this: &this->m_Models);
  bodyPartID = 0;
  while ( bodyPartID < pHdr->numbodyparts )
  {
    pBodyPart = (mstudiobodyparts_t *)((char *)pHdr + 16 * bodyPartID + pHdr->bodypartindex);
    pSrcBodyPart = &pSrcBodyParts[bodyPartID];
    modelID = 0;
    while ( modelID < pBodyPart->nummodels )
    {
      i = CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::AddToTail(this: &this->m_Models);
      newModel = CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::operator[](
                   this: &this->m_Models,
                   i);
      pStudioModel = (mstudiomodel_t *)((char *)pBodyPart + 148 * modelID + pBodyPart->modelindex);
      pSrcModel = (s_model_t *)*CUtlVectorAuto<s_bone_t *>::operator[](
                                  this: (CUtlVectorAuto<s_bone_t *> *)&pSrcBodyPart->pmodel,
                                  i: modelID);
      lodID = 0;
      while ( 1 )
      {
        v6 = CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Count(this: (ConCommandBase *)&g_ScriptLODs);
        if ( lodID >= (int)v6 )
          break;
        scriptLOD = CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::operator[](
                      this: &g_ScriptLODs,
                      i: lodID);
        pLODSource = (s_source_t *)*CUtlVector<int,CUtlMemory<int,int>>::operator[](
                                      this: (CUtlVector<int,CUtlMemory<int,int> > *)&pSrcModel->m_LodSources,
                                      i: lodID);
        v18 = CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int>>::AddToTail(this: &newModel->modelLODs);
        newLOD = CUtlVector<OptimizedModel::Mesh_t,CUtlMemory<OptimizedModel::Mesh_t,int>>::operator[](
                   this: &newModel->modelLODs,
                   i: v18);
        newLOD->switchPoint = scriptLOD->switchValue;
        if ( pLODSource != nullptr )
        {
          meshID = 0;
          while ( meshID < pStudioModel->nummeshes )
          {
            pStudioMesh = (mstudiomesh_t *)((char *)pStudioModel + 116 * meshID + pStudioModel->meshindex);
            pSrcMesh = &pSrcModel->source->mesh[pSrcModel->source->meshindex[meshID]];
            v13 = CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int>>::AddToTail(this: (CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int> > *)newLOD);
            newMesh = (OptimizedModel::Mesh_t *)CUtlVector<OptimizedModel::Mesh_t,CUtlMemory<OptimizedModel::Mesh_t,int>>::operator[](
                                                  this: (CUtlVector<OptimizedModel::ModelLOD_t,CUtlMemory<OptimizedModel::ModelLOD_t,int> > *)newLOD,
                                                  i: v13);
            if ( OptimizedModel::COptimizedModel::MeshNeedsRemoval(this, pHdr, pStudioMesh, scriptLOD) == 0 )
            {
              bQuadSubd = (gflags & 0x80000) != 0;
              v7 = (gflags & 0x80000) != 0 || bForceSoftwareSkin;
              bForceSoftwareSkin = v7;
              CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>::CUtlVector<mstudioiface_t,CUtlMemory<mstudioiface_t,int>>(
                this: &meshFaceList,
                growSize: 0,
                initSize: 0);
              if ( pLODSource != nullptr )
                OptimizedModel::COptimizedModel::CreateLODFaceList(
                  this,
                  pSrcModel,
                  nLodID: lodID,
                  pSrc: pLODSource,
                  pStudioModel,
                  pStudioMesh,
                  &meshFaceList,
                  bQuadSubd,
                  writeDebug: false);
              else
                OptimizedModel::COptimizedModel::SourceMeshToFaceList(this, pSrcModel, pSrcMesh, &meshFaceList);
              OptimizedModel::COptimizedModel::ProcessMesh(
                this,
                pMesh: newMesh,
                pStudioHeader: pHdr,
                srcFaces: (ConCommandBase *)&meshFaceList,
                pStudioModel,
                pStudioMesh,
                bForceNoFlex: !scriptLOD->m_bFacialAnimation,
                bForceSoftwareSkin: v7,
                bHWFlex,
                bQuadSubd);
              stats->m_TotalVerts += OptimizedModel::COptimizedModel::GetTotalVertsForMesh(
                                       this,
                                       pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalIndices += OptimizedModel::COptimizedModel::GetTotalIndicesForMesh(
                                         this,
                                         pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalTopologyIndices += OptimizedModel::COptimizedModel::GetTotalTopologyIndicesForMesh(
                                                 this,
                                                 pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalStrips += OptimizedModel::COptimizedModel::GetTotalStripsForMesh(
                                        this,
                                        pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalStripGroups += (int)OptimizedModel::COptimizedModel::GetTotalStripGroupsForMesh(
                                                  this,
                                                  pMesh: (ConCommandBase *)newMesh);
              stats->m_TotalBoneStateChanges += OptimizedModel::COptimizedModel::GetTotalBoneStateChangesForMesh(
                                                  this,
                                                  pMesh: (ConCommandBase *)newMesh);
              CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&meshFaceList);
            }
            ++meshID;
            ++stats->m_TotalMeshes;
          }
        }
        else if ( pSrcModel != nullptr )
        {
          _V_stricmp(s1: pSrcModel->name, s2: "blank");
        }
        ++lodID;
        ++stats->m_TotalModelLODs;
      }
      ++modelID;
      ++stats->m_TotalModels;
    }
    ++bodyPartID;
    ++stats->m_TotalBodyParts;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C750
// Name: public: bool OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(struct studiohdr_t __near *,struct s_bodypart_t __near *,int,bool,bool,bool,int,int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(
        OptimizedModel::COptimizedModel *this,
        studiohdr_t *pHdr,
        s_bodypart_t *pSrcBodyParts,
        int vertCacheSize,
        bool usesFixedFunction,
        bool bForceSoftwareSkin,
        bool bHWFlex,
        int maxBonesPerVert,
        int maxBonesPerFace,
        int maxBonesPerStrip,
        const char *pFileName,
        const char *glViewFileName)
{
  CFileBuffer *m_FileBuffer; // [esp+10h] [ebp-30h]
  OptimizedModel::TotalMeshStats_t stats; // [esp+14h] [ebp-2Ch] BYREF

  OptimizedModel::MergeLikeBoneIndicesWithinVerts(pHdr);
  OptimizedModel::COptimizedModel::SetupMeshProcessing(
    this,
    pHdr,
    vertexCacheSize: vertCacheSize,
    usesFixedFunction,
    maxBonesPerVert,
    maxBonesPerFace,
    maxBonesPerStrip,
    fileName: pFileName);
  OptimizedModel::COptimizedModel::ProcessModel(this, pHdr, pSrcBodyParts, &stats, bForceSoftwareSkin, bHWFlex);
  stats.m_TotalMaterialReplacements = OptimizedModel::CalcNumMaterialReplacements();
  OptimizedModel::COptimizedModel::WriteVTXFile(this, pHdr, pFileName, &stats);
  OptimizedModel::COptimizedModel::WriteGLViewFiles(this, pHdr, glViewFileName);
  m_FileBuffer = this->m_FileBuffer;
  if ( m_FileBuffer != nullptr )
  {
    free(pMem: m_FileBuffer->m_pData);
    free(pMem: m_FileBuffer);
  }
  this->m_FileBuffer = nullptr;
  if ( this->m_NumSkinnedAndFlexedVerts != 0 )
    MdlWarning(
      fmt: "!!!!WARNING!!!!: %d flexed verts had more than one bone influence. . will use SLOW path in engine\n",
      this->m_NumSkinnedAndFlexedVerts);
  OptimizedModel::COptimizedModel::CleanupEverything(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C860
// Name: void OptimizedModel::WriteOptimizedFiles(struct studiohdr_t __near *,struct s_bodypart_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::WriteOptimizedFiles(studiohdr_t *phdr, s_bodypart_t *pSrcBodyParts)
{
  char v2; // [esp+Bh] [ebp-3E1h]
  char *v3; // [esp+Ch] [ebp-3E0h]
  char v4; // [esp+13h] [ebp-3D9h]
  char *v5; // [esp+18h] [ebp-3D4h]
  char *v6; // [esp+1Ch] [ebp-3D0h]
  char v7; // [esp+23h] [ebp-3C9h]
  char *v8; // [esp+24h] [ebp-3C8h]
  char v9; // [esp+2Bh] [ebp-3C1h]
  char *v10; // [esp+30h] [ebp-3BCh]
  char *v11; // [esp+34h] [ebp-3B8h]
  char v12; // [esp+3Bh] [ebp-3B1h]
  char *v13; // [esp+3Ch] [ebp-3B0h]
  char v14; // [esp+43h] [ebp-3A9h]
  char *v15; // [esp+48h] [ebp-3A4h]
  char *v16; // [esp+4Ch] [ebp-3A0h]
  char v17; // [esp+53h] [ebp-399h]
  char *v18; // [esp+54h] [ebp-398h]
  char v19; // [esp+5Bh] [ebp-391h]
  char *v20; // [esp+60h] [ebp-38Ch]
  char *v21; // [esp+64h] [ebp-388h]
  bool v22; // [esp+68h] [ebp-384h]
  char v23; // [esp+6Fh] [ebp-37Dh]
  char *v24; // [esp+70h] [ebp-37Ch]
  char v25; // [esp+77h] [ebp-375h]
  char *v26; // [esp+7Ch] [ebp-370h]
  char *v27; // [esp+80h] [ebp-36Ch]
  char v28; // [esp+87h] [ebp-365h]
  char *v29; // [esp+88h] [ebp-364h]
  char v30; // [esp+8Fh] [ebp-35Dh]
  char *v31; // [esp+94h] [ebp-358h]
  char *v32; // [esp+98h] [ebp-354h]
  char v33; // [esp+9Fh] [ebp-34Dh]
  bool *v34; // [esp+A0h] [ebp-34Ch]
  char *v35; // [esp+B4h] [ebp-338h]
  char v36; // [esp+BBh] [ebp-331h]
  bool *p_bForceSoftwareSkinning; // [esp+BCh] [ebp-330h]
  char v38; // [esp+C3h] [ebp-329h]
  char *v39; // [esp+C8h] [ebp-324h]
  char *v40; // [esp+CCh] [ebp-320h]
  bool bForceSoftwareSkinning; // [esp+D3h] [ebp-319h] BYREF
  char filename[263]; // [esp+D4h] [ebp-318h] BYREF
  char v43; // [esp+1DBh] [ebp-211h] BYREF
  char glViewFilename[263]; // [esp+1DCh] [ebp-210h] BYREF
  char v45; // [esp+2E3h] [ebp-109h] BYREF
  char tmpFileName[264]; // [esp+2E4h] [ebp-108h] BYREF

  OptimizedModel::ValidateLODReplacements(pHdr: phdr);
  CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Purge(this: &s_StringTable.m_Strings);
  OptimizedModel::AddMaterialReplacementsToStringTable();
  v40 = gamedir;
  v39 = filename;
  do
  {
    v38 = *v40;
    *v39++ = *v40++;
  }
  while ( v38 != 0 );
  p_bForceSoftwareSkinning = &bForceSoftwareSkinning;
  do
    v36 = *++p_bForceSoftwareSkinning;
  while ( v36 != 0 );
  strcpy((char *)p_bForceSoftwareSkinning, "models/");
  v35 = &g_outname[strlen(g_outname) + 1];
  v34 = &bForceSoftwareSkinning;
  do
    v33 = *++v34;
  while ( v33 != 0 );
  qmemcpy(v34, g_outname, v35 - g_outname);
  V_StripExtension(in: filename, out: filename, outSize: 260);
  if ( g_gameinfo.bSupportsDX8 && !g_bFastBuild )
  {
    v32 = filename;
    v31 = tmpFileName;
    do
    {
      v30 = *v32;
      *v31++ = *v32++;
    }
    while ( v30 != 0 );
    v29 = &v45;
    do
      v28 = *++v29;
    while ( v28 != 0 );
    strcpy(v29, ".sw.vtx");
    v27 = filename;
    v26 = glViewFilename;
    do
    {
      v25 = *v27;
      *v26++ = *v27++;
    }
    while ( v25 != 0 );
    v24 = &v43;
    do
      v23 = *++v24;
    while ( v23 != 0 );
    strcpy(v24, ".sw.glview");
    v22 = phdr->numbones > 0 && !g_staticprop;
    bForceSoftwareSkinning = v22;
    OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(
      this: &s_OptimizedModel,
      pHdr: phdr,
      pSrcBodyParts,
      vertCacheSize: 512,
      usesFixedFunction: false,
      bForceSoftwareSkin: v22,
      bHWFlex: false,
      maxBonesPerVert: 3,
      maxBonesPerFace: 9,
      maxBonesPerStrip: 512,
      pFileName: tmpFileName,
      glViewFileName: glViewFilename);
  }
  if ( g_gameinfo.bSupportsDX8 && !g_bFastBuild )
  {
    v21 = filename;
    v20 = tmpFileName;
    do
    {
      v19 = *v21;
      *v20++ = *v21++;
    }
    while ( v19 != 0 );
    v18 = &v45;
    do
      v17 = *++v18;
    while ( v17 != 0 );
    strcpy(v18, ".dx80.vtx");
    v16 = filename;
    v15 = glViewFilename;
    do
    {
      v14 = *v16;
      *v15++ = *v16++;
    }
    while ( v14 != 0 );
    v13 = &v43;
    do
      v12 = *++v13;
    while ( v12 != 0 );
    strcpy(v13, ".dx80.glview");
    OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(
      this: &s_OptimizedModel,
      pHdr: phdr,
      pSrcBodyParts,
      vertCacheSize: 24,
      usesFixedFunction: false,
      bForceSoftwareSkin: false,
      bHWFlex: false,
      maxBonesPerVert: 3,
      maxBonesPerFace: 9,
      maxBonesPerStrip: 16,
      pFileName: tmpFileName,
      glViewFileName: glViewFilename);
  }
  v11 = filename;
  v10 = tmpFileName;
  do
  {
    v9 = *v11;
    *v10++ = *v11++;
  }
  while ( v9 != 0 );
  v8 = &v45;
  do
    v7 = *++v8;
  while ( v7 != 0 );
  strcpy(v8, ".dx90.vtx");
  v6 = filename;
  v5 = glViewFilename;
  do
  {
    v4 = *v6;
    *v5++ = *v6++;
  }
  while ( v4 != 0 );
  v3 = &v43;
  do
    v2 = *++v3;
  while ( v2 != 0 );
  strcpy(v3, ".dx90.glview");
  OptimizedModel::COptimizedModel::OptimizeFromStudioHdr(
    this: &s_OptimizedModel,
    pHdr: phdr,
    pSrcBodyParts,
    vertCacheSize: 24,
    usesFixedFunction: false,
    bForceSoftwareSkin: false,
    bHWFlex: true,
    maxBonesPerVert: 3,
    maxBonesPerFace: 9,
    maxBonesPerStrip: 53,
    pFileName: tmpFileName,
    glViewFileName: glViewFilename);
  CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::Purge(this: &s_StringTable.m_Strings);
}

//------------------------------------------------------------------------------
// Address: 0x004837A0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483F40
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483FC0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00484350
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
           this: &this->m_Memory,
           result: &v13,
           it: &this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
              this: &this->m_Memory,
              result: &v14,
              it: &this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00484DE0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
                this: &v1->m_Memory,
                &result,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == v1->m_LastAlloc.m_pBlockHeader && m_nIndex == v1->m_LastAlloc.m_nIndex )
        break;
    }
    v1->m_Head = 0;
    v1->m_Tail = 0;
    v1->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004855C0
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00485610
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::LinkBefore(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 8);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Head = *(_DWORD *)(elem + 12);
      v5 = *(_DWORD *)(elem + 12);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Tail = *(_DWORD *)(elem + 8);
      *(_DWORD *)(elem + 12) = elem;
      *(_DWORD *)(elem + 8) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 12) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 8);
    *(_DWORD *)(before + 8) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 8) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 12) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B24F0
// Name: protected: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004B2660
// Name: public: void CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B26C0
// Name: public: void CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::Unlink(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<IUndoElement *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2F80
// Name: public: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AddToTail(class IUndoElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        IUndoElement **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // esi

  result = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F83E0
// Name: public: static unsigned int CUtlHash<struct OptimizedModel::StripVertLookup_t,bool (*)(struct OptimizedModel::StripVertLookup_t const __near &,struct OptimizedModel::StripVertLookup_t const __near &),unsigned int (*)(struct OptimizedModel::StripVertLookup_t const __near &)>::InvalidHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::InvalidHandle(
        CDmeClip *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BDF90
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BE000
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x005BE180
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BE390
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E4C30
// Name: OptimizedModel::_dynamic_initializer_for__s_StringTable__
// Source: json
//------------------------------------------------------------------------------
int OptimizedModel::_dynamic_initializer_for__s_StringTable__()
{
  CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>(
    this: (CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int> > *)&s_StringTable,
    growSize: 0,
    initSize: 0);
  return atexit(func: OptimizedModel::_dynamic_atexit_destructor_for__s_StringTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4C50
// Name: OptimizedModel::_dynamic_initializer_for__s_OptimizedModel__
// Source: json
//------------------------------------------------------------------------------
int OptimizedModel::_dynamic_initializer_for__s_OptimizedModel__()
{
  CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>::CUtlVector<CUtlVector<char,CUtlMemory<char,int>>,CUtlMemory<CUtlVector<char,CUtlMemory<char,int>>,int>>(
    this: &s_OptimizedModel.m_Models,
    growSize: 0,
    initSize: 0);
  CHardwareMatrixState::CHardwareMatrixState(this: &s_OptimizedModel.m_HardwareMatrixState);
  return atexit(func: OptimizedModel::_dynamic_atexit_destructor_for__s_OptimizedModel__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4C80
// Name: OptimizedModel::_dynamic_initializer_for__g_StripGroupVertexLookup__
// Source: json
//------------------------------------------------------------------------------
int OptimizedModel::_dynamic_initializer_for__g_StripGroupVertexLookup__()
{
  CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>(
    this: &OptimizedModel::g_StripGroupVertexLookup,
    bucketCount: 0x10000,
    growCount: 0,
    initCount: 0,
    compareFunc: (bool (__cdecl *)(const OptimizedModel::StripVertLookup_t *, const OptimizedModel::StripVertLookup_t *))OptimizedModel::StripVertLookup_CompareFunc,
    keyFunc: OptimizedModel::StripVertLookup_KeyFunc);
  return atexit(func: OptimizedModel::_dynamic_atexit_destructor_for__g_StripGroupVertexLookup__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4CB0
// Name: OptimizedModel::_dynamic_initializer_for__s_LastThreePositions__
// Source: json
//------------------------------------------------------------------------------
int OptimizedModel::_dynamic_initializer_for__s_LastThreePositions__()
{
  int result; // eax
  int v1; // [esp+0h] [ebp-8h]
  Vector *i; // [esp+4h] [ebp-4h]

  v1 = 3;
  for ( i = s_LastThreePositions; ; ++i )
  {
    result = --v1;
    if ( v1 < 0 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5210
// Name: OptimizedModel::BoneStateChangeHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::BoneStateChangeHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::BoneStateChangeHeader_t>(__formal: nullptr);
  OptimizedModel::BoneStateChangeHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5220
// Name: OptimizedModel::Vertex_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::Vertex_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::Vertex_t>(__formal: nullptr);
  OptimizedModel::Vertex_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5230
// Name: OptimizedModel::StripHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::StripHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::StripHeader_t>(__formal: nullptr);
  OptimizedModel::StripHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5240
// Name: OptimizedModel::StripGroupHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::StripGroupHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::StripGroupHeader_t>(__formal: nullptr);
  OptimizedModel::StripGroupHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5250
// Name: OptimizedModel::MeshHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::MeshHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::MeshHeader_t>(__formal: nullptr);
  OptimizedModel::MeshHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5260
// Name: OptimizedModel::ModelLODHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::ModelLODHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::ModelLODHeader_t>(__formal: nullptr);
  OptimizedModel::ModelLODHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5270
// Name: OptimizedModel::ModelHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::ModelHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::ModelHeader_t>(__formal: nullptr);
  OptimizedModel::ModelHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5280
// Name: OptimizedModel::BodyPartHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::BodyPartHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::BodyPartHeader_t>(__formal: nullptr);
  OptimizedModel::BodyPartHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E5290
// Name: OptimizedModel::MaterialReplacementHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::MaterialReplacementHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::MaterialReplacementHeader_t>(__formal: nullptr);
  OptimizedModel::MaterialReplacementHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E52A0
// Name: OptimizedModel::MaterialReplacementListHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::MaterialReplacementListHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::MaterialReplacementListHeader_t>(__formal: nullptr);
  OptimizedModel::MaterialReplacementListHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E52B0
// Name: OptimizedModel::FileHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *OptimizedModel::FileHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = OptimizedModel::DataMapInit<OptimizedModel::FileHeader_t>(__formal: nullptr);
  OptimizedModel::FileHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EB5B0
// Name: OptimizedModel::_dynamic_atexit_destructor_for__s_StringTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::_dynamic_atexit_destructor_for__s_StringTable__()
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&s_StringTable);
}

//------------------------------------------------------------------------------
// Address: 0x005EB5C0
// Name: OptimizedModel::_dynamic_atexit_destructor_for__g_StripGroupVertexLookup__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::_dynamic_atexit_destructor_for__g_StripGroupVertexLookup__()
{
  CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>::~CUtlHash<OptimizedModel::StripVertLookup_t,bool (__cdecl *)(OptimizedModel::StripVertLookup_t const &,OptimizedModel::StripVertLookup_t const &),unsigned int (__cdecl *)(OptimizedModel::StripVertLookup_t const &)>(this: &OptimizedModel::g_StripGroupVertexLookup);
}

//------------------------------------------------------------------------------
// Address: 0x005EB5D0
// Name: OptimizedModel::_dynamic_atexit_destructor_for__s_OptimizedModel__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::_dynamic_atexit_destructor_for__s_OptimizedModel__()
{
  CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>::~CUtlVector<OptimizedModel::Model_t,CUtlMemory<OptimizedModel::Model_t,int>>(this: &s_OptimizedModel.m_Models);
}

//------------------------------------------------------------------------------
// Address: 0x005EBA80
// Name: _OptimizedModel::DataMapInit_OptimizedModel::BoneStateChangeHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::BoneStateChangeHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_59);
}

//------------------------------------------------------------------------------
// Address: 0x005EBA90
// Name: _OptimizedModel::DataMapInit_OptimizedModel::Vertex_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::Vertex_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_60);
}

//------------------------------------------------------------------------------
// Address: 0x005EBAA0
// Name: _OptimizedModel::DataMapInit_OptimizedModel::StripHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::StripHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_61);
}

//------------------------------------------------------------------------------
// Address: 0x005EBAB0
// Name: _OptimizedModel::DataMapInit_OptimizedModel::StripGroupHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::StripGroupHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_62);
}

//------------------------------------------------------------------------------
// Address: 0x005EBAC0
// Name: _OptimizedModel::DataMapInit_OptimizedModel::MeshHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::MeshHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_63);
}

//------------------------------------------------------------------------------
// Address: 0x005EBAD0
// Name: _OptimizedModel::DataMapInit_OptimizedModel::ModelLODHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::ModelLODHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_64);
}

//------------------------------------------------------------------------------
// Address: 0x005EBAE0
// Name: _OptimizedModel::DataMapInit_OptimizedModel::ModelHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::ModelHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_65);
}

//------------------------------------------------------------------------------
// Address: 0x005EBAF0
// Name: _OptimizedModel::DataMapInit_OptimizedModel::BodyPartHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::BodyPartHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_66);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB00
// Name: _OptimizedModel::DataMapInit_OptimizedModel::MaterialReplacementHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::MaterialReplacementHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_67);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB10
// Name: _OptimizedModel::DataMapInit_OptimizedModel::MaterialReplacementListHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::MaterialReplacementListHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_68);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB20
// Name: _OptimizedModel::DataMapInit_OptimizedModel::FileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: json
//------------------------------------------------------------------------------
void __cdecl OptimizedModel::DataMapInit_OptimizedModel::FileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_69);
}

//------------------------------------------------------------------------------
// Address: 0x005E4CE0
// Name: _dynamic_initializer_for____g_CreateCStudioDataCacheIStudioDataCache_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCStudioDataCacheIStudioDataCache_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCStudioDataCacheIStudioDataCache_reg,
           fn: _CreateCStudioDataCacheIStudioDataCache_interface,
           pName: "VStudioDataCache005");
}

//------------------------------------------------------------------------------
// Address: 0x005E4D00
// Name: _dynamic_initializer_for__s_BufferedLoggingListener__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_BufferedLoggingListener__()
{
  CBufferedLoggingListener::CBufferedLoggingListener(this: &s_BufferedLoggingListener);
  return atexit(func: dynamic_atexit_destructor_for__s_BufferedLoggingListener__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4D20
// Name: _dynamic_initializer_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_definevariable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_definevariable__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4D30
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4D60
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4D90
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4DB0
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4E00
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x005E4E10
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005EB5E0
// Name: _dynamic_atexit_destructor_for__s_BufferedLoggingListener__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_BufferedLoggingListener__()
{
  if ( s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory);
      s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory = nullptr;
    }
    s_BufferedLoggingListener.m_StoredSpew.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EB620
// Name: _dynamic_atexit_destructor_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_definevariable__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_definevariable);
}

//------------------------------------------------------------------------------
// Address: 0x005EB630
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x005EB640
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x005EB650
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x005EB660
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x005EB670
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB30
// Name: _DataMapInit_phyheader_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_phyheader_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_70);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB40
// Name: _dynamic_atexit_destructor_for__g_BoneMerge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BoneMerge__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_BoneMerge);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB50
// Name: _dynamic_atexit_destructor_for__g_bonesaveframe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_bonesaveframe__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_bonesaveframe);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB60
// Name: _dynamic_atexit_destructor_for__g_normal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_normal__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_normal);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB70
// Name: _dynamic_atexit_destructor_for__g_collapse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_collapse__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_collapse);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB80
// Name: _dynamic_atexit_destructor_for__g_hitboxsets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_hitboxsets__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_hitboxsets);
}

//------------------------------------------------------------------------------
// Address: 0x005EBB90
// Name: _dynamic_atexit_destructor_for__g_KeyValueText__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KeyValueText__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_KeyValueText);
}

//------------------------------------------------------------------------------
// Address: 0x005EBBA0
// Name: _dynamic_atexit_destructor_for__m_CreateMakefileDependencies__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_CreateMakefileDependencies__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&m_CreateMakefileDependencies);
}

//------------------------------------------------------------------------------
// Address: 0x005EBBB0
// Name: _dynamic_atexit_destructor_for__s_JointSurfaceProp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_JointSurfaceProp__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_JointSurfaceProp);
}

//------------------------------------------------------------------------------
// Address: 0x005EBBC0
// Name: _dynamic_atexit_destructor_for__s_JointContents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_JointContents__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_JointContents);
}

//------------------------------------------------------------------------------
// Address: 0x005EBBD0
// Name: _dynamic_atexit_destructor_for__g_constraintBones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_constraintBones__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_constraintBones);
}

//------------------------------------------------------------------------------
// Address: 0x005EBBE0
// Name: _dynamic_atexit_destructor_for__g_vertex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_vertex__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_vertex);
}

//------------------------------------------------------------------------------
// Address: 0x005EBBF0
// Name: _dynamic_atexit_destructor_for__g_texcoord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_texcoord__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_texcoord);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC00
// Name: _dynamic_atexit_destructor_for__g_src_uface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_src_uface__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_src_uface);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC10
// Name: _dynamic_atexit_destructor_for__g_model__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_model__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_model);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC20
// Name: _dynamic_atexit_destructor_for__g_bone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_bone__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_bone);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC30
// Name: _dynamic_atexit_destructor_for__g_face__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_face__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_face);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC40
// Name: _dynamic_atexit_destructor_for__g_ScriptLODs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptLODs__()
{
  CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>::~CUtlVector<LodScriptData_t,CUtlMemory<LodScriptData_t,int>>(this: &g_ScriptLODs);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC50
// Name: _dynamic_atexit_destructor_for__g_twistbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_twistbones__()
{
  CUtlVector<CTwistBone,CUtlMemory<CTwistBone,int>>::~CUtlVector<CTwistBone,CUtlMemory<CTwistBone,int>>(this: &g_twistbones);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC60
// Name: _dynamic_atexit_destructor_for__g_bodypart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_bodypart__()
{
  CUtlVector<s_bodypart_t,CUtlMemory<s_bodypart_t,int>>::~CUtlVector<s_bodypart_t,CUtlMemory<s_bodypart_t,int>>(this: &g_bodypart);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC70
// Name: _dynamic_atexit_destructor_for__g_FlexControllerRemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FlexControllerRemap__()
{
  CUtlVector<s_flexcontrollerremap_t,CUtlMemory<s_flexcontrollerremap_t,int>>::~CUtlVector<s_flexcontrollerremap_t,CUtlMemory<s_flexcontrollerremap_t,int>>(this: &g_FlexControllerRemap);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC80
// Name: _dynamic_atexit_destructor_for__g_sequence__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_sequence__()
{
  CUtlVector<s_sequence_t,CUtlMemory<s_sequence_t,int>>::~CUtlVector<s_sequence_t,CUtlMemory<s_sequence_t,int>>(this: &g_sequence);
}

//------------------------------------------------------------------------------
// Address: 0x005EBC90
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x005EBCA0
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x005EBCB0
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x005EBCC0
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x005EBCF0
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x005EBD00
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x005EBD10
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x005EBD20
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x005EBD30
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

} // namespace studiomdl
