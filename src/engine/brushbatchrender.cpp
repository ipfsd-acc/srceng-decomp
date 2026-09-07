// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/brushbatchrender.cpp
// Functions: 39
// ============================================================

#include "engine\brushbatchrender.h"

//------------------------------------------------------------------------------
// Address: 0x100634D0
// Name: private: void CBrushBatchRender::ClearRenderHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::ClearRenderHandles(CBrushBatchRender *this)
{
  int i; // esi
  model_t *v2; // eax
  char szBrushModel[8]; // [esp+4h] [ebp-8h] BYREF

  for ( i = 1; i < host_state.worldbrush->numsubmodels; ++i )
  {
    V_snprintf(pDest: szBrushModel, maxLen: 5, pFormat: "*%i", i);
    v2 = modelloader->GetModelForName(this: modelloader, a2: szBrushModel, a3: 2);
    if ( v2 != nullptr )
      v2->brush.renderHandle = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063530
// Name: private: static bool CBrushBatchRender::BatchSortLessFunc(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBrushBatchRender::BatchSortLessFunc(
        const CBrushBatchRender::BrushBatchRenderData_t *left,
        const CBrushBatchRender::BrushBatchRenderData_t *right)
{
  IMaterial *m_pMaterial; // ebx
  IMaterial *v3; // edi
  bool v4; // cf
  int sortID; // eax
  int v7; // ecx
  ShaderStencilState_t *m_pStencilState; // eax
  ShaderStencilState_t *v9; // ecx
  matrix3x4a_t *m_pBrushToWorld; // edx
  matrix3x4a_t *v11; // esi

  m_pMaterial = right->m_pMaterial;
  v3 = left->m_pMaterial;
  v4 = v3 < m_pMaterial;
  if ( v3 != m_pMaterial )
    return v4;
  sortID = left->m_pBrushRender->pBatches[*((_WORD *)left + 6) & 0x7FFF].sortID;
  v7 = right->m_pBrushRender->pBatches[*((_WORD *)right + 6) & 0x7FFF].sortID;
  if ( sortID != v7 )
    return sortID < v7;
  m_pStencilState = left->m_pInstanceData->m_pStencilState;
  v9 = right->m_pInstanceData->m_pStencilState;
  v4 = m_pStencilState < v9;
  if ( m_pStencilState != v9 )
    return v4;
  m_pBrushToWorld = left->m_pInstanceData->m_pBrushToWorld;
  v11 = right->m_pInstanceData->m_pBrushToWorld;
  v4 = m_pBrushToWorld < v11;
  if ( m_pBrushToWorld != v11 )
    return v4;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100635B0
// Name: private: void CBrushBatchRender::ComputeLightmapPages(int,struct CBrushBatchRender::BrushBatchRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::ComputeLightmapPages(
        CBrushBatchRender *this,
        int nCount,
        CBrushBatchRender::BrushBatchRenderData_t *pRenderData)
{
  int v3; // ecx
  _WORD *v4; // eax
  _WORD *v5; // eax

  v3 = nCount;
  if ( g_pMaterialSystemConfig->nFullbright == 1 )
  {
    if ( nCount > 0 )
    {
      v5 = (_WORD *)pRenderData + 7;
      do
      {
        *v5 = *v5 & 0x8000 | 0x7FFE;
        v5 += 8;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  else if ( nCount > 0 )
  {
    v4 = (_WORD *)pRenderData + 7;
    do
    {
      *v4 ^= (*v4
            ^ LOWORD(materialSortInfoArray[*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 - 3) + 8)
                                                     + 16 * (*(v4 - 1) & 0x7FFF)
                                                     + 8)].lightmapPageID))
           & 0x7FFF;
      v4 += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063640
// Name: private: static bool CBrushBatchRender::ShadowSortLessFunc(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBrushBatchRender::ShadowSortLessFunc(
        const CBrushBatchRender::BrushBatchRenderData_t *left,
        const CBrushBatchRender::BrushBatchRenderData_t *right)
{
  IMaterial *m_pMaterial; // eax
  IMaterial *v3; // ecx
  bool v4; // cf
  bool result; // al
  matrix3x4a_t *m_pBrushToWorld; // eax
  matrix3x4a_t *v7; // ecx

  m_pMaterial = left->m_pMaterial;
  v3 = right->m_pMaterial;
  v4 = m_pMaterial < v3;
  result = (m_pMaterial != v3
         || (m_pBrushToWorld = left->m_pInstanceData->m_pBrushToWorld,
             v7 = right->m_pInstanceData->m_pBrushToWorld,
             v4 = m_pBrushToWorld < v7,
             m_pBrushToWorld != v7))
        && v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063670
// Name: void std::_Push_heap<struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)>(struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,int,struct CBrushBatchRender::BrushBatchRenderData_t __near &&,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        CBrushBatchRender::BrushBatchRenderData_t *_First,
        int _Hole,
        int _Top,
        CBrushBatchRender::BrushBatchRenderData_t *_Val,
        bool (__cdecl *_Pred)(const CBrushBatchRender::BrushBatchRenderData_t *, const CBrushBatchRender::BrushBatchRenderData_t *))
{
  int v5; // ebx
  int i; // edi
  CBrushBatchRender::BrushBatchRenderData_t *v7; // esi
  CBrushBatchRender::BrushBatchRenderData_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    v8->m_pInstanceData = v7->m_pInstanceData;
    v8->m_pMaterial = v7->m_pMaterial;
    v8->m_pBrushRender = v7->m_pBrushRender;
    *((_DWORD *)v8 + 3) = *((_DWORD *)v7 + 3);
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10063700
// Name: public: void Vector4D::Init(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector4D::Init(Vector4D *this, float ix, float iy, float iz, float iw)
{
  this->x = ix;
  this->y = iy;
  this->z = iz;
  this->w = iw;
}

//------------------------------------------------------------------------------
// Address: 0x10063730
// Name: public: void CVertexBuilder::AttachBegin(class IMesh __near *,int,struct MeshDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AttachBegin(
        CVertexBuilder *this,
        IMesh *pMesh,
        int nMaxVertexCount,
        const MeshDesc_t *desc)
{
  bool v4; // zf

  this->m_pVertexBuffer = pMesh;
  this->VertexDesc_t = desc->VertexDesc_t;
  this->m_nMaxVertexCount = nMaxVertexCount;
  this->m_NumBoneWeights = this->m_NumBoneWeights != 0 ? 2 : 0;
  v4 = this->m_nBufferOffset == -1;
  this->m_nVertexCount = 0;
  this->m_bModify = false;
  if ( v4 )
  {
    this->m_nTotalVertexCount = 0;
    this->m_nBufferOffset = desc->VertexDesc_t::m_nOffset;
    this->m_nBufferFirstVertex = desc->m_nFirstVertex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100637A0
// Name: public: void CVertexBuilder::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::Reset(CVertexBuilder *this)
{
  float *m_pNormal; // edx
  float *v2; // edx
  float *v3; // eax
  float *v4; // edx
  float *v5; // eax
  float *v6; // edx
  float *v7; // eax
  float *v8; // edx

  m_pNormal = this->m_pNormal;
  this->m_pCurrPosition = this->m_pPosition;
  this->m_nCurrentVertex = 0;
  this->m_pCurrNormal = m_pNormal;
  v2 = this->m_pTexCoord[1];
  this->m_pCurrTexCoord[0] = this->m_pTexCoord[0];
  v3 = this->m_pTexCoord[2];
  this->m_pCurrTexCoord[1] = v2;
  v4 = this->m_pTexCoord[3];
  this->m_pCurrTexCoord[2] = v3;
  v5 = this->m_pTexCoord[4];
  this->m_pCurrTexCoord[3] = v4;
  v6 = this->m_pTexCoord[5];
  this->m_pCurrTexCoord[4] = v5;
  v7 = this->m_pTexCoord[6];
  this->m_pCurrTexCoord[5] = v6;
  v8 = this->m_pTexCoord[7];
  this->m_pCurrTexCoord[6] = v7;
  this->m_pCurrTexCoord[7] = v8;
  this->m_pCurrColor = this->m_pColor;
}

//------------------------------------------------------------------------------
// Address: 0x10063820
// Name: public: void CIndexBuilder::FastPolygon(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::FastPolygon(CIndexBuilder *this, int startVert, int triangleCount)
{
  unsigned int v3; // edi
  unsigned __int16 *v4; // eax
  int v5; // edx
  int v6; // esi
  int m_nCurrentIndex; // eax
  int triangleCounta; // [esp+14h] [ebp+Ch]

  v3 = triangleCount * this->m_nIndexSize;
  v4 = &this->m_pIndices[this->m_nCurrentIndex];
  v5 = this->m_nIndexOffset + startVert;
  v6 = 0;
  for ( triangleCounta = v3; v6 < triangleCounta; v4 += 3 )
  {
    *v4 = v5;
    v4[1] = v6 + v5 + 1;
    v4[2] = v6 + v5 + 2;
    v3 = triangleCounta;
    ++v6;
  }
  this->m_nCurrentIndex += 3 * v3 * this->m_nIndexSize;
  m_nCurrentIndex = this->m_nCurrentIndex;
  if ( m_nCurrentIndex > this->m_nIndexCount )
    this->m_nIndexCount = m_nCurrentIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10063890
// Name: public: void CIndexBuilder::GenerateIndices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::GenerateIndices(
        CIndexBuilder *this,
        MaterialPrimitiveType_t primitiveType,
        int nIndexCount)
{
  int v4; // edi
  unsigned __int16 *v5; // eax
  int m_nCurrentIndex; // eax

  if ( this->m_nIndexSize != 0 )
  {
    v4 = nIndexCount;
    if ( this->m_nMaxIndexCount - this->m_nCurrentIndex < nIndexCount )
      v4 = this->m_nMaxIndexCount - this->m_nCurrentIndex;
    if ( v4 != 0 )
    {
      v5 = &this->m_pIndices[this->m_nCurrentIndex];
      switch ( primitiveType )
      {
        case MATERIAL_POINTS:
        case MATERIAL_INSTANCED_QUADS:
          break;
        case MATERIAL_LINE_STRIP:
          GenerateLineStripIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_LINE_LOOP:
          GenerateLineLoopIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_POLYGON:
          GeneratePolygonIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_QUADS:
          GenerateQuadIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        default:
          GenerateSequentialIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
      }
      this->m_nCurrentIndex += v4 * this->m_nIndexSize;
      m_nCurrentIndex = this->m_nCurrentIndex;
      if ( m_nCurrentIndex > this->m_nIndexCount )
        this->m_nIndexCount = m_nCurrentIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063960
// Name: public: CMeshBuilder::~CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::~CMeshBuilder(CMeshBuilder *this)
{
  if ( this->m_VertexBuilder.m_pVertexBuffer != nullptr
    && this->m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: this->m_VertexBuilder.m_pVertexBuffer) )
  {
    this->m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: this->m_VertexBuilder.m_pVertexBuffer);
  }
  if ( this->m_IndexBuilder.m_pIndexBuffer != nullptr
    && this->m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: this->m_IndexBuilder.m_pIndexBuffer) )
  {
    this->m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: this->m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100639C0
// Name: public: CMeshBuilder::CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBuilder *__thiscall CMeshBuilder::CMeshBuilder(CMeshBuilder *this)
{
  this->m_pMesh = nullptr;
  this->m_bGenerateIndices = false;
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_IndexBuilder.m_nTotalIndexCount = 0;
  this->m_IndexBuilder.m_nBufferFirstIndex = 0;
  this->m_IndexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_nBufferFirstVertex = 0;
  this->m_VertexBuilder.m_nVertexCount = 0;
  this->m_VertexBuilder.m_nCurrentVertex = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_nTotalVertexCount = 0;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063A30
// Name: private: static int CBrushBatchRender::SurfaceCmp(struct CBrushBatchRender::surfacelist_t const __near *,struct CBrushBatchRender::surfacelist_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CBrushBatchRender::SurfaceCmp(
        const CBrushBatchRender::surfacelist_t *s0,
        const CBrushBatchRender::surfacelist_t *s1)
{
  return s0->surfID->materialSortID - s1->surfID->materialSortID;
}

//------------------------------------------------------------------------------
// Address: 0x10063A50
// Name: private: void CBrushBatchRender::AddSurfaceToBatch(struct CBrushBatchRender::transrender_t __near &,struct CBrushBatchRender::transnode_t __near *,struct CBrushBatchRender::transbatch_t __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::AddSurfaceToBatch(
        CBrushBatchRender *this,
        CBrushBatchRender::transrender_t *render,
        CBrushBatchRender::transnode_t *pNode,
        CBrushBatchRender::transbatch_t *pBatch,
        msurface2_t *surfID)
{
  ++pBatch->surfaceCount;
  pBatch->indexCount += 3 * HIBYTE(surfID->flags) - 6;
  render->surfaces[render->surfaceCount++] = surfID;
  if ( surfID->decals != 0xFFFF || surfID->m_ShadowDecals != 0xFFFF )
  {
    ++pNode->decalSurfaceCount;
    render->decalSurfaces[render->decalSurfaceCount++] = surfID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063AC0
// Name: private: void CBrushBatchRender::AddTransBatch(struct CBrushBatchRender::transrender_t __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::AddTransBatch(
        CBrushBatchRender *this,
        CBrushBatchRender::transrender_t *render,
        msurface2_t *surfID)
{
  CBrushBatchRender::transnode_t *pLastNode; // edx
  int firstBatch; // eax
  __int16 batchCount; // si
  CBrushBatchRender::transbatch_t *v6; // eax
  CBrushBatchRender::transnode_t *v7; // ebx

  pLastNode = render->pLastNode;
  firstBatch = pLastNode->firstBatch;
  batchCount = pLastNode->batchCount;
  pLastNode->batchCount = batchCount + 1;
  LOWORD(pLastNode) = render->surfaceCount;
  v6 = &render->batches[firstBatch + batchCount];
  ++render->batchCount;
  v6->firstSurface = (__int16)pLastNode;
  v6->surfaceCount = 0;
  v6->pMaterial = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
  v6->sortID = surfID->materialSortID;
  v6->indexCount = 0;
  v7 = render->pLastNode;
  render->pLastBatch = v6;
  ++v6->surfaceCount;
  v6->indexCount += 3 * HIBYTE(surfID->flags) - 6;
  render->surfaces[render->surfaceCount++] = surfID;
  if ( surfID->decals != 0xFFFF || surfID->m_ShadowDecals != 0xFFFF )
  {
    ++v7->decalSurfaceCount;
    render->decalSurfaces[render->decalSurfaceCount++] = surfID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063BA0
// Name: private: void CBrushBatchRender::DrawDecalsForBatches(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *,struct CBrushBatchRender::brushrender_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawDecalsForBatches(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        CBrushBatchRender::brushrender_t **ppBrushRender)
{
  int v5; // esi
  CBrushBatchRender::brushrender_t *v6; // ebx
  int v7; // edi
  float v8; // eax
  msurface2_t *v9; // esi
  int surfaceCount; // ecx
  float z; // edi
  CBrushModelTransform flFade; // [esp+10h] [ebp-1Ch] BYREF
  CBrushModelTransform pushTransform; // [esp+20h] [ebp-Ch]
  char v14; // [esp+3Fh] [ebp+13h]

  v5 = 0;
  pushTransform.m_savedModelorg.x = 0.0;
  if ( nCount > 0 )
  {
    LODWORD(pushTransform.m_savedModelorg.z) = &pInstanceData->m_pBrushModel;
    do
    {
      DecalSurfacesInit(bBrushModel: true);
      g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
      v6 = ppBrushRender[v5];
      if ( v6 != nullptr )
      {
        v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)LODWORD(pushTransform.m_savedModelorg.z) + 312) + 124)
           + 32 * *(_DWORD *)(*(_DWORD *)LODWORD(pushTransform.m_savedModelorg.z) + 316);
        v8 = 0.0;
        v14 = 0;
        pushTransform.m_savedModelorg.y = 0.0;
        if ( v6->surfaceCount > 0 )
        {
          do
          {
            v9 = (msurface2_t *)(v7 + 32 * v6->pSurfaces[LODWORD(v8)].surfaceIndex);
            if ( v9->decals != 0xFFFF )
            {
              v14 = 1;
              DecalSurfaceAdd(surfID: v9, iGroup: 4);
            }
            if ( v9->m_ShadowDecals != 0xFFFF )
            {
              v14 = 1;
              g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: v9->m_ShadowDecals);
            }
            surfaceCount = v6->surfaceCount;
            LODWORD(v8) = LODWORD(pushTransform.m_savedModelorg.y) + 1;
            pushTransform.m_savedModelorg.y = v8;
          }
          while ( SLODWORD(v8) < surfaceCount );
          if ( v14 != 0 )
          {
            z = pushTransform.m_savedModelorg.z;
            CBrushModelTransform::CBrushModelTransform(
              this: &flFade,
              matrix: *(const matrix3x4a_t **)(LODWORD(pushTransform.m_savedModelorg.z) - 4),
              pRenderContext);
            DecalSurfaceDraw(pRenderContext, renderGroup: 4, flFade: *(float *)(LODWORD(z) + 16));
            ((void (__thiscall *)(IShadowMgrInternal *, IMatRenderContext *, int, _DWORD, _DWORD))g_pShadowMgr->DrawFlashlightDecals)(
              a1: g_pShadowMgr,
              a2: pRenderContext,
              a3: 4,
              a4: 0,
              a5: *(float *)(LODWORD(z) + 16));
            R_DecalFlushDestroyList();
            g_pShadowMgr->RenderProjectedTextures(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
            CBrushModelTransform::~CBrushModelTransform(this: &flFade);
          }
        }
      }
      LODWORD(pushTransform.m_savedModelorg.z) += 28;
      v5 = LODWORD(pushTransform.m_savedModelorg.x) + 1;
      LODWORD(pushTransform.m_savedModelorg.x) = v5;
    }
    while ( v5 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063CF0
// Name: void std::_Adjust_heap<struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)>(struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,int,struct CBrushBatchRender::BrushBatchRenderData_t __near &&,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        CBrushBatchRender::BrushBatchRenderData_t *_First,
        int _Hole,
        int _Bottom,
        CBrushBatchRender::BrushBatchRenderData_t *_Val,
        bool (__cdecl *_Pred)(const CBrushBatchRender::BrushBatchRenderData_t *, const CBrushBatchRender::BrushBatchRenderData_t *))
{
  int v5; // edx
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  CBrushBatchRender::BrushBatchRenderData_t *v9; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v10; // ecx
  CBrushBatchRender::BrushBatchRenderData_t *v11; // ecx
  int v12; // ecx
  int v13; // ebx
  CBrushBatchRender::BrushBatchRenderData_t *v14; // esi
  CBrushBatchRender::BrushBatchRenderData_t *v15; // eax
  int _Top; // [esp+Ch] [ebp-4h]
  int _Bottoma; // [esp+20h] [ebp+10h]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  _Top = _Hole;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = &_First[v7];
      v10 = &_First[v6];
      v10->m_pInstanceData = v9->m_pInstanceData;
      v10->m_pMaterial = v9->m_pMaterial;
      _Hole = v7;
      v6 = v7;
      v10->m_pBrushRender = v9->m_pBrushRender;
      v7 = 2 * v7 + 2;
      *((_DWORD *)v10 + 3) = *((_DWORD *)v9 + 3);
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    v11 = &_First[v5 - 1];
    _First[v6] = *v11;
    _Hole = v5 - 1;
    v6 = v5 - 1;
  }
  v12 = v6;
  _Bottoma = v6;
  v13 = (v6 - 1) / 2;
  if ( _Top < _Hole )
  {
    do
    {
      v14 = &_First[v13];
      if ( !_Pred(a1: v14, a2: _Val) )
        break;
      v15 = &_First[_Bottoma];
      v15->m_pInstanceData = v14->m_pInstanceData;
      v15->m_pMaterial = v14->m_pMaterial;
      v15->m_pBrushRender = v14->m_pBrushRender;
      *((_DWORD *)v15 + 3) = *((_DWORD *)v14 + 3);
      _Bottoma = v13;
      v13 = (v13 - 1) / 2;
    }
    while ( _Top < _Bottoma );
    v12 = _Bottoma;
  }
  _First[v12] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10063E80
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x10063FC0
// Name: int BuildIndicesForSurface(class CIndexBuilder __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BuildIndicesForSurface(CIndexBuilder *meshBuilder, msurface2_t *surfID)
{
  int v2; // esi
  int vertBufferIndex; // edi
  int v5; // eax
  int v6; // edx
  unsigned __int16 *v7; // edi
  unsigned __int16 *v8; // eax
  int v9; // eax
  int m_nCurrentIndex; // edx
  unsigned __int16 v11; // cx
  unsigned __int16 *m_pIndices; // edi
  unsigned __int16 *v13; // edx
  int v14; // ecx

  v2 = HIBYTE(surfID->flags) - 2;
  vertBufferIndex = surfID->vertBufferIndex;
  if ( HIBYTE(surfID->flags) == 3 )
  {
    m_nCurrentIndex = meshBuilder->m_nCurrentIndex;
    v11 = vertBufferIndex + meshBuilder->m_nIndexOffset;
    m_pIndices = meshBuilder->m_pIndices;
    m_pIndices[m_nCurrentIndex] = v11;
    v13 = &m_pIndices[m_nCurrentIndex];
    v13[1] = ++v11;
    v13[2] = v11 + 1;
    meshBuilder->m_nCurrentIndex += 3 * meshBuilder->m_nIndexSize;
    v14 = meshBuilder->m_nCurrentIndex;
    if ( v14 > meshBuilder->m_nIndexCount )
      meshBuilder->m_nIndexCount = v14;
  }
  else
  {
    if ( HIBYTE(surfID->flags) != 4 )
    {
      CIndexBuilder::FastPolygon(this: meshBuilder, startVert: vertBufferIndex, triangleCount: v2);
      return v2;
    }
    v5 = meshBuilder->m_nCurrentIndex;
    v6 = vertBufferIndex + meshBuilder->m_nIndexOffset;
    v7 = meshBuilder->m_pIndices;
    v7[v5] = v6;
    v8 = &v7[v5];
    LOWORD(v6) = v6 + 1;
    v8[1] = v6;
    LOWORD(v6) = v6 + 1;
    v8[2] = v6;
    v8[3] = v6 - 2;
    v8[4] = v6;
    v8[5] = v6 + 1;
    meshBuilder->m_nCurrentIndex += 6 * meshBuilder->m_nIndexSize;
    v9 = meshBuilder->m_nCurrentIndex;
    if ( v9 > meshBuilder->m_nIndexCount )
    {
      meshBuilder->m_nIndexCount = v9;
      return 2;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10064070
// Name: private: bool CBrushBatchRender::DrawSortedBatchList(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushInstanceGroup_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBrushBatchRender::DrawSortedBatchList(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroup,
        int nMaxInstanceCount)
{
  IMatRenderContext *v5; // ebx
  void *v6; // esp
  char result; // al
  CBrushBatchRender::BrushInstanceGroup_t *v8; // edi
  IIndexBuffer_vtbl *v9; // edx
  int m_pRenderData_high; // eax
  unsigned int m_nOffset; // eax
  __int16 v12; // ax
  float *p_z; // esi
  IMaterial *v14; // edi
  __int16 *v15; // ebx
  msurface2_t *v16; // ecx
  const char *(__thiscall *GetName)(IMaterial *); // ecx
  int v18; // edx
  int v19; // ecx
  IMesh *v20; // edx
  IIndexBuffer *v21; // ecx
  int v22; // ecx
  void (__thiscall *DrawInstances)(IMatRenderContext *, int, const MeshInstanceData_t *); // eax
  bool v24; // zf
  int v25; // [esp-8h] [ebp-68h]
  int v26; // [esp+0h] [ebp-60h] BYREF
  CIndexBuilder indexBuilder; // [esp+Ch] [ebp-54h] BYREF
  IIndexBuffer *pBuildIndexBuffer; // [esp+40h] [ebp-20h]
  msurface2_t *surfID; // [esp+44h] [ebp-1Ch]
  msurface2_t *firstSurfID; // [esp+48h] [ebp-18h]
  int v31; // [esp+4Ch] [ebp-14h]
  MeshInstanceData_t *pInstance; // [esp+50h] [ebp-10h]
  int j; // [esp+54h] [ebp-Ch]
  unsigned int v34; // [esp+58h] [ebp-8h]
  int nIndexOffset; // [esp+5Ch] [ebp-4h]
  int k; // [esp+6Ch] [ebp+Ch]
  bool k_3; // [esp+6Fh] [ebp+Fh]
  CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroupa; // [esp+70h] [ebp+10h]
  char bHasPaintedSurfaces_3; // [esp+77h] [ebp+17h]

  v5 = pRenderContext;
  pRenderContext->BindLightmapPage(this: pRenderContext, a2: 0);
  v6 = alloca(76 * nMaxInstanceCount);
  result = 0;
  pInstance = (MeshInstanceData_t *)&v26;
  bHasPaintedSurfaces_3 = 0;
  if ( nCount > 0 )
  {
    v8 = (CBrushBatchRender::BrushInstanceGroup_t *)((char *)pInstanceGroup + 12);
    pInstanceGroupa = (CBrushBatchRender::BrushInstanceGroup_t *)((char *)pInstanceGroup + 12);
    v31 = nCount;
    while ( 1 )
    {
      v5->Bind(this: v5, a2: *((IMaterial **)&v8[-1] + 3), a3: nullptr);
      indexBuilder.m_pIndexBuffer = v5->GetDynamicIndexBuffer(this: v5);
      indexBuilder.m_nBufferOffset = -1;
      indexBuilder.m_nBufferFirstIndex = 0;
      indexBuilder.m_nIndexCount = 0;
      indexBuilder.m_nCurrentIndex = 0;
      indexBuilder.m_nMaxIndexCount = 0;
      indexBuilder.m_nTotalIndexCount = 0;
      v9 = indexBuilder.m_pIndexBuffer->__vftable;
      pBuildIndexBuffer = indexBuilder.m_pIndexBuffer;
      if ( v9->IsDynamic(this: indexBuilder.m_pIndexBuffer) )
        indexBuilder.m_pIndexBuffer->BeginCastBuffer(this: indexBuilder.m_pIndexBuffer, a2: MATERIAL_INDEX_FORMAT_16BIT);
      m_pRenderData_high = HIWORD(v8->m_pRenderData);
      indexBuilder.m_bModify = false;
      indexBuilder.m_nMaxIndexCount = m_pRenderData_high;
      memset(&indexBuilder.m_nIndexCount, 0, 16);
      k_3 = indexBuilder.m_nBufferOffset == -1;
      if ( indexBuilder.m_pIndexBuffer->Lock(
             this: indexBuilder.m_pIndexBuffer,
             a2: m_pRenderData_high,
             a3: false,
             a4: &indexBuilder) )
      {
        if ( k_3 )
        {
          m_nOffset = indexBuilder.m_nOffset;
          indexBuilder.m_nBufferOffset = indexBuilder.m_nOffset;
          indexBuilder.m_nBufferFirstIndex = indexBuilder.m_nFirstIndex;
          goto LABEL_8;
        }
      }
      else
      {
        indexBuilder.m_nMaxIndexCount = 0;
      }
      m_nOffset = indexBuilder.m_nBufferOffset;
LABEL_8:
      LOWORD(v8->m_pRenderData) &= ~0x8000u;
      nIndexOffset = m_nOffset >> 1;
      v12 = (int)v8->m_pRenderData & 0x7FFF;
      j = 0;
      if ( v12 != 0 )
      {
        v34 = 0;
        p_z = &pInstance->m_DiffuseModulation.z;
        do
        {
          v14 = &v8[-1].m_pActualMaterial[v34 / 4];
          v15 = (__int16 *)((char *)v14[2].GetPreviewImageProperties + 16 * ((int)v14[3].__vftable & 0x7FFF));
          LOWORD(v14[3].__vftable) &= ~0x8000u;
          v16 = (msurface2_t *)(*(_DWORD *)(*((_DWORD *)v14->GetTextureGroupName + 78) + 124)
                              + 32 * *((_DWORD *)v14->GetTextureGroupName + 79));
          firstSurfID = v16;
          k = 0;
          if ( v15[1] > 0 )
          {
            while ( 1 )
            {
              surfID = &v16[*((__int16 *)v14[2].GetPreviewImage + 2 * k + 2 * *v15)];
              BuildIndicesForSurface(meshBuilder: &indexBuilder, surfID);
              if ( (surfID->flags & 0x200000) != 0 )
              {
                LOWORD(pInstanceGroupa->m_pRenderData) |= 0x8000u;
                LOWORD(v14[3].__vftable) |= 0x8000u;
                bHasPaintedSurfaces_3 = 1;
              }
              if ( ++k >= v15[1] )
                break;
              v16 = firstSurfID;
            }
          }
          *(p_z - 11) = 0.0;
          GetName = v14->GetName;
          v18 = nIndexOffset;
          *(p_z - 10) = 0.0;
          *(p_z - 13) = 0.0;
          *((_DWORD *)p_z - 12) = GetName;
          *((_DWORD *)p_z - 16) = v18;
          *((_DWORD *)p_z - 14) = 1;
          v19 = *((_DWORD *)v15 + 3);
          *(p_z - 5) = 0.0;
          *(p_z - 4) = 0.0;
          *((_DWORD *)p_z - 15) = v19;
          *((_DWORD *)p_z - 9) = 2;
          *(p_z - 3) = *(float *)&v14->GetNumAnimationFrames;
          v20 = g_WorldStaticMeshes.m_Memory.m_pMemory[*((_DWORD *)v15 + 2)];
          v21 = pBuildIndexBuffer;
          *(p_z - 7) = 0.0;
          v34 += 16;
          *((_DWORD *)p_z - 8) = v20;
          *((_DWORD *)p_z - 6) = v21;
          *(p_z - 2) = 1.0;
          *(p_z - 1) = 1.0;
          *p_z = 1.0;
          p_z[1] = 1.0;
          *((_DWORD *)p_z + 2) = (__int16)(2 * HIWORD(v14[3].__vftable)) >> 1;
          nIndexOffset += *((_DWORD *)v15 + 3);
          v22 = (int)pInstanceGroupa->m_pRenderData & 0x7FFF;
          p_z += 19;
          ++j;
          v8 = pInstanceGroupa;
        }
        while ( j < v22 );
        v5 = pRenderContext;
      }
      indexBuilder.m_pIndexBuffer->Unlock(
        this: indexBuilder.m_pIndexBuffer,
        a2: indexBuilder.m_nIndexCount,
        a3: &indexBuilder);
      DrawInstances = v5->DrawInstances;
      v25 = (int)v8->m_pRenderData & 0x7FFF;
      indexBuilder.m_pIndexBuffer = nullptr;
      indexBuilder.m_nMaxIndexCount = 0;
      DrawInstances(this: v5, a2: v25, a3: pInstance);
      if ( indexBuilder.m_pIndexBuffer != nullptr
        && indexBuilder.m_pIndexBuffer->IsDynamic(this: indexBuilder.m_pIndexBuffer) )
      {
        indexBuilder.m_pIndexBuffer->EndCastBuffer(this: indexBuilder.m_pIndexBuffer);
      }
      ++v8;
      v24 = v31-- == 1;
      pInstanceGroupa = v8;
      if ( v24 )
        return bHasPaintedSurfaces_3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064360
// Name: private: void CBrushBatchRender::DrawPaintForBatches(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushInstanceGroup_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawPaintForBatches(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroup,
        int nMaxInstanceCount)
{
  void *v5; // esp
  IMatRenderContext *v6; // edi
  void (__thiscall *EndRender)(IMatRenderContext *); // edx
  IMaterial **v8; // ebx
  IIndexBuffer_vtbl *v9; // edx
  int v10; // eax
  unsigned int m_nOffset; // eax
  __int16 v12; // dx
  _DWORD *v13; // esi
  IMaterial *v14; // edi
  __int16 *v15; // ebx
  int v16; // ecx
  PreviewImageRetVal_t (__thiscall *GetPreviewImage)(IMaterial *, unsigned __int8 *, int, int, ImageFormat); // edx
  int v18; // eax
  unsigned int v19; // ecx
  IMesh *v20; // edx
  int v21; // ecx
  void (__thiscall *DrawInstances)(IMatRenderContext *, int, const MeshInstanceData_t *); // eax
  bool v23; // zf
  int v24; // [esp+0h] [ebp-60h] BYREF
  CIndexBuilder meshBuilder; // [esp+Ch] [ebp-54h] BYREF
  IIndexBuffer *m_pIndexBuffer; // [esp+40h] [ebp-20h]
  int v27; // [esp+44h] [ebp-1Ch]
  int v28; // [esp+48h] [ebp-18h]
  IMaterial **v29; // [esp+4Ch] [ebp-14h]
  int *v30; // [esp+50h] [ebp-10h]
  int v31; // [esp+54h] [ebp-Ch]
  unsigned int v32; // [esp+58h] [ebp-8h]
  int v33; // [esp+5Ch] [ebp-4h]
  int i; // [esp+6Ch] [ebp+Ch]
  int v35; // [esp+70h] [ebp+10h]
  int v36; // [esp+74h] [ebp+14h]
  bool v37; // [esp+77h] [ebp+17h]

  v5 = alloca(76 * nMaxInstanceCount);
  v6 = pRenderContext;
  EndRender = pRenderContext->__vftable[1].EndRender;
  v30 = &v24;
  ((void (__thiscall *)(IMatRenderContext *, int))EndRender)(a1: pRenderContext, a2: 1);
  if ( nCount > 0 )
  {
    v8 = (IMaterial **)pInstanceGroup + 3;
    v29 = (IMaterial **)pInstanceGroup + 3;
    v28 = nCount;
    while ( *(__int16 *)v8 >= 0 )
    {
LABEL_22:
      v8 += 4;
      v23 = v28-- == 1;
      v29 = v8;
      if ( v23 )
        goto LABEL_23;
    }
    v6->Bind(this: v6, a2: *(v8 - 1), a3: nullptr);
    meshBuilder.m_pIndexBuffer = v6->GetDynamicIndexBuffer(this: v6);
    meshBuilder.m_nBufferOffset = -1;
    meshBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_nIndexCount = 0;
    meshBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_nTotalIndexCount = 0;
    v9 = meshBuilder.m_pIndexBuffer->__vftable;
    m_pIndexBuffer = meshBuilder.m_pIndexBuffer;
    if ( v9->IsDynamic(this: meshBuilder.m_pIndexBuffer) )
      meshBuilder.m_pIndexBuffer->BeginCastBuffer(this: meshBuilder.m_pIndexBuffer, a2: MATERIAL_INDEX_FORMAT_16BIT);
    v10 = *((unsigned __int16 *)v8 + 1);
    meshBuilder.m_bModify = false;
    meshBuilder.m_nMaxIndexCount = v10;
    memset(&meshBuilder.m_nIndexCount, 0, 16);
    v37 = meshBuilder.m_nBufferOffset == -1;
    if ( meshBuilder.m_pIndexBuffer->Lock(this: meshBuilder.m_pIndexBuffer, a2: v10, a3: false, a4: &meshBuilder) )
    {
      if ( v37 )
      {
        m_nOffset = meshBuilder.m_nOffset;
        meshBuilder.m_nBufferOffset = meshBuilder.m_nOffset;
        meshBuilder.m_nBufferFirstIndex = meshBuilder.m_nFirstIndex;
        goto LABEL_9;
      }
    }
    else
    {
      meshBuilder.m_nMaxIndexCount = 0;
    }
    m_nOffset = meshBuilder.m_nBufferOffset;
LABEL_9:
    v12 = *(_WORD *)v8;
    v32 = m_nOffset >> 1;
    v33 = 0;
    v31 = 0;
    if ( (v12 & 0x7FFF) != 0 )
    {
      v35 = 0;
      v13 = v30 + 16;
      do
      {
        v14 = &(*(v8 - 3))[v35];
        if ( ((int)v14[3].__vftable & 0x8000) != 0 )
        {
          v15 = (__int16 *)((char *)v14[2].GetPreviewImageProperties + 16 * ((int)v14[3].__vftable & 0x7FFF));
          v16 = *(_DWORD *)(*((_DWORD *)v14->GetTextureGroupName + 78) + 124)
              + 32 * *((_DWORD *)v14->GetTextureGroupName + 79);
          v27 = v16;
          v36 = 0;
          for ( i = 0; i < v15[1]; ++i )
          {
            GetPreviewImage = v14[2].GetPreviewImage;
            if ( (*(_DWORD *)(v16 + 32 * *((__int16 *)GetPreviewImage + 2 * i + 2 * *v15)) & 0x200000) != 0 )
            {
              v18 = BuildIndicesForSurface(
                      &meshBuilder,
                      surfID: (msurface2_t *)(v16 + 32 * *((__int16 *)GetPreviewImage + 2 * i + 2 * *v15)));
              v16 = v27;
              v36 += v18 + 2 * v18;
            }
          }
          *(v13 - 11) = 0;
          v19 = v32;
          *(v13 - 12) = v14->GetName;
          *(v13 - 15) = v36;
          *(v13 - 10) = 0;
          *(v13 - 13) = 0;
          *(v13 - 16) = v19;
          *(v13 - 5) = 0;
          *(v13 - 4) = 0;
          *(v13 - 14) = 1;
          *(v13 - 9) = 2;
          *(v13 - 3) = v14->GetNumAnimationFrames;
          v20 = g_WorldStaticMeshes.m_Memory.m_pMemory[*((_DWORD *)v15 + 2)];
          ++v33;
          v8 = v29;
          *(v13 - 8) = v20;
          *(v13 - 6) = m_pIndexBuffer;
          *(v13 - 7) = 0;
          *(v13 - 2) = 1065353216;
          *(v13 - 1) = 1065353216;
          *v13 = 1065353216;
          v13[1] = 1065353216;
          v13[2] = (__int16)(2 * HIWORD(v14[3].__vftable)) >> 1;
          v32 = v36 + v19;
          v13 += 19;
        }
        v35 += 4;
        v21 = *(_WORD *)v8 & 0x7FFF;
        ++v31;
      }
      while ( v31 < v21 );
      v6 = pRenderContext;
    }
    meshBuilder.m_pIndexBuffer->Unlock(
      this: meshBuilder.m_pIndexBuffer,
      a2: meshBuilder.m_nIndexCount,
      a3: &meshBuilder);
    DrawInstances = v6->DrawInstances;
    meshBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_nMaxIndexCount = 0;
    DrawInstances(this: v6, a2: v33, a3: (const MeshInstanceData_t *)v30);
    if ( meshBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_pIndexBuffer);
    }
    goto LABEL_22;
  }
LABEL_23:
  ((void (__thiscall *)(IMatRenderContext *, _DWORD))v6->__vftable[1].EndRender)(a1: v6, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064650
// Name: private: void CBrushBatchRender::DrawShadowBatchList(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushInstanceGroup_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CBrushBatchRender::DrawShadowBatchList(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroup,
        int nMaxInstanceCount)
{
  IMatRenderContext *v5; // ebx
  void *v6; // esp
  IMaterial **p_m_pMaterial; // edi
  IMaterialVar *v9; // esi
  int v10; // eax
  int *v11; // ecx
  int v12; // edx
  int v13; // eax
  IMaterial *v14; // ecx
  IMaterial_vtbl *v15; // edx
  IMaterialVar *v16; // ebx
  int v17; // eax
  IMaterial *v18; // ecx
  IMaterial_vtbl *v19; // edx
  int v20; // eax
  int v21; // esi
  int v22; // eax
  IIndexBuffer_vtbl *v23; // edx
  int v24; // eax
  unsigned int m_nOffset; // eax
  __int16 v26; // dx
  _DWORD *v27; // esi
  IMaterial *v28; // ebx
  __int16 *v29; // edi
  int v30; // eax
  int v31; // eax
  __int16 v32; // dx
  void (__thiscall *DrawInstances)(IMatRenderContext *, int, const MeshInstanceData_t *); // edx
  bool v34; // zf
  int v35; // [esp-4h] [ebp-60h]
  float v36; // [esp+0h] [ebp-5Ch]
  int v37; // [esp+4h] [ebp-58h] BYREF
  CIndexBuilder meshBuilder; // [esp+10h] [ebp-4Ch] BYREF
  IIndexBuffer *m_pIndexBuffer; // [esp+44h] [ebp-18h]
  int v40; // [esp+48h] [ebp-14h]
  int v41; // [esp+4Ch] [ebp-10h]
  _BYTE indexBuilder[12]; // [esp+50h] [ebp-Ch] OVERLAPPED
  IMaterial **indexBuilder_24; // [esp+68h] [ebp+Ch]
  void (__thiscall **indexBuilder_28a)(IMaterialVar *, int); // [esp+6Ch] [ebp+10h]
  int indexBuilder_28; // [esp+6Ch] [ebp+10h]
  int indexBuilder_32; // [esp+70h] [ebp+14h]
  int indexBuilder_32a; // [esp+70h] [ebp+14h]
  bool indexBuilder_35; // [esp+73h] [ebp+17h]

  v5 = pRenderContext;
  pRenderContext->BindLightmapPage(this: pRenderContext, a2: -2);
  v6 = alloca(76 * nMaxInstanceCount);
  *(_DWORD *)indexBuilder = &v37;
  if ( nCount > 0 )
  {
    p_m_pMaterial = &pInstanceGroup->m_pMaterial;
    indexBuilder_24 = &pInstanceGroup->m_pMaterial;
    v41 = nCount;
    do
    {
      if ( SHIWORD((*(p_m_pMaterial - 2))[3].__vftable) < 0 )
      {
        v9 = (*(p_m_pMaterial - 1))->FindVarFast(
               this: *(p_m_pMaterial - 1),
               a2: "$basetexture",
               a3: &originalTextureVarCache);
        v10 = (int)(*(p_m_pMaterial - 1))->FindVarFast(
                     this: *(p_m_pMaterial - 1),
                     a2: "$frame",
                     a3: &originalTextureFrameVarCache);
        v11 = (int *)*(p_m_pMaterial - 1);
        v12 = *v11;
        *(_DWORD *)&indexBuilder[8] = v10;
        v13 = (*(int (__thiscall **)(int *, const char *, unsigned int *))(v12 + 188))(
                a1: v11,
                a2: "$AlphaTestReference",
                a3: &originalAlphaRefCache);
        v14 = *p_m_pMaterial;
        v15 = (*p_m_pMaterial)->__vftable;
        v40 = v13;
        v16 = v15->FindVarFast(this: v14, a2: "$basetexture", a3: &textureVarCache);
        v17 = (int)(*p_m_pMaterial)->FindVarFast(this: *p_m_pMaterial, a2: "$frame", a3: &textureFrameVarCache);
        v18 = *p_m_pMaterial;
        v19 = (*p_m_pMaterial)->__vftable;
        *(_DWORD *)&indexBuilder[4] = v17;
        indexBuilder_32 = (int)v19->FindVarFast(this: v18, a2: "$AlphaTestReference", a3: &alphaRefCache);
        if ( v16 != nullptr && v9 != nullptr )
        {
          indexBuilder_28a = (void (__thiscall **)(IMaterialVar *, int))&v16->SetTextureValue;
          v20 = v9->GetTextureValue(this: v9);
          (*indexBuilder_28a)(a1: v16, a2: v20);
        }
        v21 = *(_DWORD *)&indexBuilder[4];
        if ( *(_DWORD *)&indexBuilder[4] != 0 && *(_DWORD *)&indexBuilder[8] != 0 )
        {
          v22 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&indexBuilder[8] + 108))(a1: *(_DWORD *)&indexBuilder[8]);
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v21 + 20))(a1: v21, a2: v22);
        }
        if ( indexBuilder_32 != 0 && v40 != 0 )
        {
          v36 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v40 + 112))(a1: v40);
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)indexBuilder_32 + 16))(a1: LODWORD(v36));
        }
        v5 = pRenderContext;
      }
      v5->Bind(this: v5, a2: *p_m_pMaterial, a3: nullptr);
      meshBuilder.m_pIndexBuffer = v5->GetDynamicIndexBuffer(this: v5);
      meshBuilder.m_nBufferOffset = -1;
      meshBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_nIndexCount = 0;
      meshBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_nTotalIndexCount = 0;
      v23 = meshBuilder.m_pIndexBuffer->__vftable;
      m_pIndexBuffer = meshBuilder.m_pIndexBuffer;
      if ( v23->IsDynamic(this: meshBuilder.m_pIndexBuffer) )
        meshBuilder.m_pIndexBuffer->BeginCastBuffer(this: meshBuilder.m_pIndexBuffer, a2: MATERIAL_INDEX_FORMAT_16BIT);
      v24 = *((unsigned __int16 *)p_m_pMaterial + 3);
      meshBuilder.m_bModify = false;
      meshBuilder.m_nMaxIndexCount = v24;
      memset(&meshBuilder.m_nIndexCount, 0, 16);
      indexBuilder_35 = meshBuilder.m_nBufferOffset == -1;
      if ( meshBuilder.m_pIndexBuffer->Lock(this: meshBuilder.m_pIndexBuffer, a2: v24, a3: false, a4: &meshBuilder) )
      {
        if ( indexBuilder_35 )
        {
          m_nOffset = meshBuilder.m_nOffset;
          meshBuilder.m_nBufferOffset = meshBuilder.m_nOffset;
          meshBuilder.m_nBufferFirstIndex = meshBuilder.m_nFirstIndex;
          goto LABEL_19;
        }
      }
      else
      {
        meshBuilder.m_nMaxIndexCount = 0;
      }
      m_nOffset = meshBuilder.m_nBufferOffset;
LABEL_19:
      v26 = *((_WORD *)p_m_pMaterial + 2);
      *(_DWORD *)&indexBuilder[8] = m_nOffset >> 1;
      *(_DWORD *)&indexBuilder[4] = 0;
      if ( (v26 & 0x7FFF) != 0 )
      {
        indexBuilder_28 = 0;
        v27 = (_DWORD *)(*(_DWORD *)indexBuilder + 64);
        do
        {
          v28 = &(*(p_m_pMaterial - 2))[indexBuilder_28];
          v29 = (__int16 *)((char *)v28[2].GetPreviewImageProperties + 16 * ((int)v28[3].__vftable & 0x7FFF));
          v30 = *(_DWORD *)(*((_DWORD *)v28->GetTextureGroupName + 78) + 124)
              + 32 * *((_DWORD *)v28->GetTextureGroupName + 79);
          v40 = v30;
          indexBuilder_32a = 0;
          if ( v29[1] > 0 )
          {
            while ( 1 )
            {
              BuildIndicesForSurface(
                &meshBuilder,
                surfID: (msurface2_t *)(v30 + 32 * *((__int16 *)v28[2].GetPreviewImage + 2 * indexBuilder_32a + 2 * *v29)));
              if ( ++indexBuilder_32a >= v29[1] )
                break;
              v30 = v40;
            }
          }
          *(v27 - 11) = 0;
          *(v27 - 12) = v28->GetName;
          v31 = *(_DWORD *)&indexBuilder[8];
          *(v27 - 16) = *(_DWORD *)&indexBuilder[8];
          *(v27 - 10) = 0;
          *(v27 - 13) = 0;
          *(v27 - 14) = 1;
          *(v27 - 15) = *((_DWORD *)v29 + 3);
          *(v27 - 5) = 0;
          *(v27 - 4) = 0;
          *(v27 - 9) = 2;
          indexBuilder_28 += 4;
          *(v27 - 3) = v28->GetNumAnimationFrames;
          *(v27 - 8) = g_WorldStaticMeshes.m_Memory.m_pMemory[*((_DWORD *)v29 + 2)];
          *(v27 - 6) = m_pIndexBuffer;
          *(v27 - 7) = 0;
          *(v27 - 2) = 1065353216;
          *(v27 - 1) = 1065353216;
          *v27 = 1065353216;
          v27[1] = 1065353216;
          v27[2] = -2;
          v32 = *((_WORD *)indexBuilder_24 + 2);
          *(_DWORD *)&indexBuilder[8] = *((_DWORD *)v29 + 3) + v31;
          v27 += 19;
          ++*(_DWORD *)&indexBuilder[4];
          p_m_pMaterial = indexBuilder_24;
        }
        while ( *(int *)&indexBuilder[4] < (v32 & 0x7FFF) );
        v5 = pRenderContext;
      }
      meshBuilder.m_pIndexBuffer->Unlock(
        this: meshBuilder.m_pIndexBuffer,
        a2: meshBuilder.m_nIndexCount,
        a3: &meshBuilder);
      DrawInstances = v5->DrawInstances;
      v35 = (_WORD)p_m_pMaterial[1] & 0x7FFF;
      meshBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_nMaxIndexCount = 0;
      DrawInstances(this: v5, a2: v35, a3: *(const MeshInstanceData_t **)indexBuilder);
      if ( meshBuilder.m_pIndexBuffer != nullptr
        && meshBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_pIndexBuffer) )
      {
        meshBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_pIndexBuffer);
      }
      p_m_pMaterial += 4;
      v34 = v41-- == 1;
      indexBuilder_24 = p_m_pMaterial;
    }
    while ( !v34 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064AF0
// Name: void std::_Make_heap<struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)>(struct CBrushBatchRender::BrushBatchRenderData_t __near *,struct CBrushBatchRender::BrushBatchRenderData_t __near *,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &),int __near *,struct CBrushBatchRender::BrushBatchRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        CBrushBatchRender::BrushBatchRenderData_t *_First,
        CBrushBatchRender::BrushBatchRenderData_t *_Last,
        bool (__cdecl *_Pred)(const CBrushBatchRender::BrushBatchRenderData_t *, const CBrushBatchRender::BrushBatchRenderData_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  CBrushBatchRender::BrushBatchRenderData_t *i; // edx
  const BrushArrayInstanceData_t *m_pInstanceData; // ebx
  CBrushBatchRender::BrushBatchRenderData_t *v9; // edx
  CBrushBatchRender::brushrender_t *m_pBrushRender; // ebx
  int v11; // eax
  int v12; // esi
  int v13; // edx
  int v14; // ebx
  bool v15; // zf
  CBrushBatchRender::BrushBatchRenderData_t *v16; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v17; // ecx
  CBrushBatchRender::BrushBatchRenderData_t *v18; // edx
  CBrushBatchRender::BrushBatchRenderData_t *v19; // ebx
  CBrushBatchRender::BrushBatchRenderData_t _Val; // [esp+4h] [ebp-18h] BYREF
  int v21; // [esp+14h] [ebp-8h]
  CBrushBatchRender::BrushBatchRenderData_t *v22; // [esp+18h] [ebp-4h]
  int _Hole; // [esp+24h] [ebp+8h]
  int _Bottom; // [esp+28h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v22 )
    {
      m_pInstanceData = i[-1].m_pInstanceData;
      v9 = i - 1;
      _Val.m_pInstanceData = m_pInstanceData;
      _Val.m_pMaterial = v9->m_pMaterial;
      m_pBrushRender = v9->m_pBrushRender;
      v11 = v5 - 1;
      v12 = v6 - 2;
      v22 = v9;
      v13 = *((_DWORD *)v9 + 3);
      _Val.m_pBrushRender = m_pBrushRender;
      _Hole = v11;
      v21 = v12;
      *((_DWORD *)&_Val + 3) = v13;
      v14 = v11;
      v15 = v12 == v4;
      if ( v12 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v12], a2: &_First[v12 - 1]) )
            --v12;
          v16 = &_First[v12];
          v17 = &_First[v14];
          v17->m_pInstanceData = v16->m_pInstanceData;
          v17->m_pMaterial = v16->m_pMaterial;
          v17->m_pBrushRender = v16->m_pBrushRender;
          v14 = v12;
          v12 = 2 * v12 + 2;
          *((_DWORD *)v17 + 3) = *((_DWORD *)v16 + 3);
        }
        while ( v12 < _Bottom );
        v4 = _Bottom;
        v11 = _Hole;
        v15 = v12 == _Bottom;
      }
      if ( v15 )
      {
        v18 = &_First[v4 - 1];
        v19 = &_First[v14];
        v19->m_pInstanceData = v18->m_pInstanceData;
        v19->m_pMaterial = v18->m_pMaterial;
        v19->m_pBrushRender = v18->m_pBrushRender;
        *((_DWORD *)v19 + 3) = *((_DWORD *)v18 + 3);
        v14 = v4 - 1;
      }
      std::_Push_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        _First,
        _Hole: v14,
        _Top: v11,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064D80
// Name: public: void CUtlMemoryFixedGrowable<struct CBrushBatchRender::BrushInstanceGroup_t,512,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>::Grow(
        CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int> *this,
        int nCount)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = this->m_nMallocGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 16 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (CBrushBatchRender::BrushInstanceGroup_t *)v5;
      CUtlMemory<CPortalRect,int>::Grow(
        (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
        num: nCount);
      return;
    }
    this->m_pMemory = nullptr;
  }
  CUtlMemory<CPortalRect,int>::Grow(
    (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
    num: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x10064DF0
// Name: public: void CBrushBatchRender::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::LevelInit(CBrushBatchRender *this)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int16 m_Head; // ax
  int v4; // edx
  UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short> *m_pMemory; // eax
  void **p_pPlanes; // esi
  unsigned __int16 m_Next; // bx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  m_Head = this->m_renderList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      v4 = m_Head;
      m_pMemory = this->m_renderList.m_Memory.m_pMemory;
      p_pPlanes = (void **)&m_pMemory[v4].m_Element->pPlanes;
      m_Next = m_pMemory[v4].m_Next;
      if ( p_pPlanes != nullptr )
      {
        free(pMem: *p_pPlanes);
        free(pMem: p_pPlanes[1]);
        free(pMem: p_pPlanes[2]);
        free(pMem: p_pPlanes[3]);
        *p_pPlanes = nullptr;
        p_pPlanes[1] = nullptr;
        p_pPlanes[2] = nullptr;
        p_pPlanes[3] = nullptr;
        free(pMem: p_pPlanes);
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_renderList);
  if ( this->m_renderList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_renderList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_renderList.m_Memory.m_pMemory);
      this->m_renderList.m_Memory.m_pMemory = nullptr;
    }
    this->m_renderList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_renderList.m_FirstFree = -1;
  this->m_renderList.m_pElements = this->m_renderList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_renderList.m_NumAlloced = -65536;
  CBrushBatchRender::ClearRenderHandles(this);
  if ( this->m_Mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100650F0
// Name: void std::_Sort_heap<struct CBrushBatchRender::BrushBatchRenderData_t __near *,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)>(struct CBrushBatchRender::BrushBatchRenderData_t __near *,struct CBrushBatchRender::BrushBatchRenderData_t __near *,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<CBrushBatchRender::BrushBatchRenderData_t *,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        CBrushBatchRender::BrushBatchRenderData_t *_First,
        CBrushBatchRender::BrushBatchRenderData_t *_Last,
        bool (__cdecl *_Pred)(const CBrushBatchRender::BrushBatchRenderData_t *, const CBrushBatchRender::BrushBatchRenderData_t *))
{
  int v3; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v4; // esi
  IMaterial *m_pMaterial; // edx
  CBrushBatchRender::brushrender_t *m_pBrushRender; // ecx
  int v7; // edx
  CBrushBatchRender::BrushBatchRenderData_t _Val; // [esp+4h] [ebp-10h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF0) > 16 )
  {
    v4 = _Last - 1;
    do
    {
      m_pMaterial = v4->m_pMaterial;
      _Val.m_pInstanceData = v4->m_pInstanceData;
      m_pBrushRender = v4->m_pBrushRender;
      _Val.m_pMaterial = m_pMaterial;
      v7 = *((_DWORD *)v4 + 3);
      _Val.m_pBrushRender = m_pBrushRender;
      v4->m_pInstanceData = _First->m_pInstanceData;
      *((_DWORD *)&_Val + 3) = v7;
      v4->m_pMaterial = _First->m_pMaterial;
      v4->m_pBrushRender = _First->m_pBrushRender;
      *((_DWORD *)v4 + 3) = *((_DWORD *)_First + 3);
      std::_Adjust_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 16) >> 4,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 16;
    }
    while ( (int)(v3 & 0xFFFFFFF0) > 16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065200
// Name: private: void CBrushBatchRender::DrawTransLists(class IMatRenderContext __near *,struct CBrushBatchRender::transrender_t __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBrushBatchRender::DrawTransLists(
        CBrushBatchRender *this@<ecx>,
        CMeshBuilder *a2@<ebx>,
        int m_nIndexCount@<edi>,
        int a4@<esi>,
        IMatRenderContext *pRenderContext,
        CBrushBatchRender::transrender_t *render,
        void *pProxyData)
{
  bool v7; // zf
  __int16 *p_batchCount; // edi
  CBrushBatchRender::transbatch_t *v9; // esi
  IMaterial *pMaterial; // edi
  IMesh *v11; // eax
  int i; // edi
  int m_nVertexCount; // eax
  IMaterial *v14; // esi
  int v15; // edx
  __int16 v16; // ax
  int v17; // ecx
  msurface2_t *v18; // esi
  int v19; // edx
  int m_nAllocationCount; // ecx
  int v21; // esi
  int v22; // edx
  CBrushBatchRender::transbatch_t *v23; // ebx
  IMaterial *v24; // eax
  int v25; // edi
  S3RGBA *m_pMemory; // ecx
  msurface2_t **v27; // edi
  int surfaceCount; // edx
  int v29; // eax
  int nodeCount; // edx
  CMeshBuilder v34; // [esp+18h] [ebp-224h] BYREF
  int v35; // [esp+200h] [ebp-3Ch] BYREF
  int v36; // [esp+204h] [ebp-38h] BYREF
  int v37; // [esp+208h] [ebp-34h] BYREF
  float v38; // [esp+20Ch] [ebp-30h]
  msurface2_t **v39; // [esp+210h] [ebp-2Ch]
  int v40; // [esp+214h] [ebp-28h]
  CUtlMemory<S3RGBA,int> v41; // [esp+218h] [ebp-24h] BYREF
  int v42; // [esp+224h] [ebp-18h]
  S3RGBA *v43; // [esp+228h] [ebp-14h]
  IMaterial *v44; // [esp+22Ch] [ebp-10h]
  __int16 *v45; // [esp+230h] [ebp-Ch]
  int v46; // [esp+234h] [ebp-8h]
  char v47; // [esp+23Bh] [ebp-1h]

  v7 = g_pMaterialSystemConfig->nFullbright == 1;
  v47 = 0;
  if ( v7 )
  {
    pRenderContext->BindLightmapPage(this: pRenderContext, a2: -2);
    v47 = 1;
  }
  v40 = 0;
  if ( render->nodeCount > 0 )
  {
    p_batchCount = &render->nodes[0].batchCount;
    v45 = &render->nodes[0].batchCount;
    do
    {
      v46 = 0;
      if ( *p_batchCount > 0 )
      {
        do
        {
          v9 = &render->batches[*(p_batchCount - 1) + v46];
          v34.m_pMesh = nullptr;
          v34.m_bGenerateIndices = false;
          memset(&v34.m_IndexBuilder.m_pIndexBuffer, 0, 12);
          v34.m_IndexBuilder.m_nCurrentIndex = 0;
          v34.m_IndexBuilder.m_nTotalIndexCount = 0;
          v34.m_IndexBuilder.m_nBufferOffset = -1;
          v34.m_IndexBuilder.m_nBufferFirstIndex = 0;
          v34.m_VertexBuilder.m_pVertexBuffer = nullptr;
          v34.m_VertexBuilder.m_nBufferOffset = -1;
          v34.m_VertexBuilder.m_nBufferFirstVertex = 0;
          memset(&v34.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
          v34.m_VertexBuilder.m_nTotalVertexCount = 0;
          v34.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          pMaterial = v9->pMaterial;
          v44 = pMaterial;
          if ( g_bIsBlendingOrModulating )
          {
            v38 = pMaterial->GetAlphaModulation(this: pMaterial);
            pMaterial->GetColorModulation(this: pMaterial, a2: (float *)&v35, a3: (float *)&v36, a4: (float *)&v37);
            ((void (__thiscall *)(IMaterial *, _DWORD))pMaterial->AlphaModulate)(a1: pMaterial, a2: LODWORD(r_blend));
            ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))pMaterial->ColorModulate)(
              a1: pMaterial,
              a2: LODWORD(r_colormod.x),
              a3: LODWORD(r_colormod.y),
              a4: LODWORD(r_colormod.z));
          }
          if ( v47 == 0 )
            pRenderContext->BindLightmapPage(this: pRenderContext, a2: materialSortInfoArray[v9->sortID].lightmapPageID);
          ((void (__thiscall *)(IMatRenderContext *, IMaterial *, void *, int, int, CMeshBuilder *))pRenderContext->Bind)(
            a1: pRenderContext,
            a2: pMaterial,
            a3: pProxyData,
            a4,
            a5: m_nIndexCount,
            a6: a2);
          v11 = pRenderContext->GetDynamicMesh(
                  this: pRenderContext,
                  a2: 0,
                  a3: g_WorldStaticMeshes.m_Memory.m_pMemory[v9->sortID],
                  a4: 0,
                  a5: 0);
          CMeshBuilder::Begin(
            this: &v34,
            pMesh: v11,
            type: MATERIAL_TRIANGLES,
            nVertexCount: 0,
            nIndexCount: v9->indexCount,
            pMeshSettings: nullptr);
          for ( i = 0; i < v9->surfaceCount; ++i )
            BuildIndicesForSurface(meshBuilder: &v34.m_IndexBuilder, surfID: *(&render->surfaces[i] + v9->firstSurface));
          if ( v34.m_bGenerateIndices )
          {
            switch ( v34.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * v34.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * v34.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * v34.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * v34.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = v34.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &v34.m_IndexBuilder,
              primitiveType: v34.m_Type,
              nIndexCount: m_nVertexCount);
          }
          a2 = &v34;
          m_nIndexCount = v34.m_IndexBuilder.m_nIndexCount;
          a4 = v34.m_VertexBuilder.m_nVertexCount;
          ((void (__thiscall *)(IMesh *))v34.m_pMesh->UnlockMesh)(a1: v34.m_pMesh);
          v34.m_IndexBuilder.m_pIndexBuffer = nullptr;
          v34.m_IndexBuilder.m_nMaxIndexCount = 0;
          v34.m_VertexBuilder.m_nMaxVertexCount = 0;
          v34.m_VertexBuilder.m_pVertexBuffer = nullptr;
          v34.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          v34.m_pMesh->Draw_2(this: v34.m_pMesh, a2: -1, a3: 0);
          v34.m_pMesh = nullptr;
          if ( g_bIsBlendingOrModulating )
          {
            v14 = v44;
            v44->AlphaModulate(this: v44, a2: COERCE_FLOAT(LODWORD(v38)));
            ((void (__thiscall *)(IMaterial *, int, int, int))v14->ColorModulate)(a1: v14, a2: v35, a3: v36, a4: v37);
          }
          if ( v34.m_VertexBuilder.m_pVertexBuffer != nullptr
            && v34.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v34.m_VertexBuilder.m_pVertexBuffer) )
          {
            v34.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v34.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( v34.m_IndexBuilder.m_pIndexBuffer != nullptr
            && v34.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v34.m_IndexBuilder.m_pIndexBuffer) )
          {
            v34.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v34.m_IndexBuilder.m_pIndexBuffer);
          }
          v15 = *v45;
          ++v46;
          p_batchCount = v45;
        }
        while ( v46 < v15 );
      }
      v16 = p_batchCount[2];
      if ( v16 != 0 )
      {
        v17 = 0;
        v46 = 0;
        if ( v16 > 0 )
        {
          do
          {
            v18 = *(&render->decalSurfaces[v17] + p_batchCount[1]);
            if ( v18->decals != 0xFFFF )
              DecalSurfaceAdd(surfID: v18, iGroup: 4);
            if ( v18->m_ShadowDecals != 0xFFFF )
              g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: v18->m_ShadowDecals);
            v19 = p_batchCount[2];
            v17 = v46 + 1;
            v46 = v17;
          }
          while ( v17 < v19 );
        }
        DecalSurfaceDraw(pRenderContext, renderGroup: 4, flFade: 1.0);
        R_DecalFlushDestroyList();
        DecalSurfacesInit(bBrushModel: true);
        g_pShadowMgr->RenderProjectedTextures(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
      }
      if ( g_ShaderDebug.anydebug )
      {
        m_nAllocationCount = 0;
        v21 = 0;
        v22 = 0;
        memset(&v41, 0, sizeof(v41));
        v42 = 0;
        v43 = nullptr;
        v46 = 0;
        if ( *p_batchCount > 0 )
        {
          do
          {
            v23 = &render->batches[*(p_batchCount - 1) + v22];
            v24 = nullptr;
            v44 = nullptr;
            if ( v23->surfaceCount > 0 )
            {
              do
              {
                v39 = &render->surfaces[(_DWORD)v24 + v23->firstSurface];
                v25 = v21;
                if ( v21 + 1 > m_nAllocationCount )
                {
                  CUtlMemory<INetMessage *,int>::Grow(this: &v41, num: v21 - m_nAllocationCount + 1);
                  v21 = v42;
                }
                m_pMemory = v41.m_pMemory;
                v42 = ++v21;
                v43 = v41.m_pMemory;
                if ( v21 - v25 - 1 > 0 )
                {
                  _V_memmove(dest: &v41.m_pMemory[v25 + 1], src: &v41.m_pMemory[v25], count: 4 * (v21 - v25 - 1));
                  m_pMemory = v41.m_pMemory;
                }
                v27 = (msurface2_t **)&m_pMemory[v25];
                if ( v27 != nullptr )
                  *v27 = *v39;
                surfaceCount = v23->surfaceCount;
                m_nAllocationCount = v41.m_nAllocationCount;
                v24 = (IMaterial *)((char *)&v44->__vftable + 1);
                v44 = v24;
              }
              while ( (int)v24 < surfaceCount );
              v22 = v46;
            }
            v29 = *v45;
            p_batchCount = v45;
            v46 = ++v22;
          }
          while ( v22 < v29 );
        }
        DrawDebugInformation(pRenderContext, pList: (msurface2_t **)v41.m_pMemory, listCount: v21);
        if ( v41.m_nGrowSize >= 0 && v41.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41.m_pMemory);
      }
      nodeCount = render->nodeCount;
      p_batchCount += 4;
      ++v40;
      v45 = p_batchCount;
    }
    while ( v40 < nodeCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065740
// Name: private: void CBrushBatchRender::BuildTransLists_r(struct CBrushBatchRender::transrender_t __near &,struct model_t __near *,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::BuildTransLists_r(
        CBrushBatchRender *this,
        int render,
        model_t *model,
        mnode_t *node)
{
  mnode_t *v4; // ebx
  bool v5; // sf
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v9; // xmm0_4
  int firstsurface; // edi
  signed int m_Size; // eax
  worldbrushdata_t *pShared; // ecx
  msurface2_t *v14; // edi
  CBrushBatchRender::transbatch_t *v15; // ecx
  __int16 v16; // ax
  __int16 v17; // cx
  int v18; // ebx
  int v19; // eax
  int v20; // edi
  CBrushBatchRender::transbatch_t *v21; // ecx
  CBrushBatchRender::transnode_t *v22; // edi
  CUtlVectorFixed<CBrushBatchRender::surfacelist_t,256> sortList; // [esp+4h] [ebp-810h] BYREF
  CBrushBatchRender *v24; // [esp+80Ch] [ebp-8h]
  int side; // [esp+810h] [ebp-4h]
  int i; // [esp+81Ch] [ebp+8h]
  int ia; // [esp+81Ch] [ebp+8h]

  v4 = node;
  v5 = node->contents < 0;
  v24 = this;
  if ( v5 )
  {
    plane = node->plane;
    type = plane->type;
    if ( type > 2u )
      v9 = (float)((float)(plane->normal.y * modelorg.y) + (float)(plane->normal.x * modelorg.x))
         + (float)(plane->normal.z * modelorg.z);
    else
      v9 = *(&modelorg.x + type);
    side = (float)(v9 - plane->dist) < 0.0;
    CBrushBatchRender::BuildTransLists_r(
      this,
      (CBrushBatchRender::transrender_t *)render,
      model,
      node: node->children[side == 0]);
    firstsurface = node->firstsurface;
    m_Size = 0;
    sortList.m_pElements = (CBrushBatchRender::surfacelist_t *)&sortList;
    pShared = model->brush.pShared;
    sortList.m_Size = 0;
    v14 = &pShared->surfaces2[firstsurface];
    i = 0;
    if ( node->numsurfaces != 0 )
    {
      do
      {
        if ( (v14->flags & 0x20) != 0 && ((v14->flags & 0x200) != 0 || side == ((v14->flags & 0x40) != 0)) )
        {
          v15 = *(CBrushBatchRender::transbatch_t **)(render + 23552);
          if ( v15 != nullptr && v15->sortID == v14->materialSortID )
          {
            CBrushBatchRender::AddSurfaceToBatch(
              this: v24,
              (CBrushBatchRender::transrender_t *)render,
              pNode: *(CBrushBatchRender::transnode_t **)(render + 23556),
              pBatch: v15,
              surfID: v14);
          }
          else
          {
            sortList.m_Size = m_Size + 1;
            sortList.m_pElements = (CBrushBatchRender::surfacelist_t *)&sortList;
            *(_DWORD *)&sortList.m_Memory.m_Memory[8 * m_Size] = v14;
            v4 = node;
          }
          m_Size = sortList.m_Size;
        }
        ++v14;
        ++i;
      }
      while ( i < v4->numsurfaces );
      if ( m_Size != 0 )
      {
        if ( m_Size > 1 )
          qsort(
            base: &sortList,
            num: m_Size,
            width: 8u,
            comp: (int (__cdecl *)(const void *, const void *))CBrushBatchRender::SurfaceCmp);
        v16 = *(_WORD *)(render + 23560);
        *(_WORD *)(render + 23560) = v16 + 1;
        v17 = *(_WORD *)(render + 23562);
        *(_DWORD *)(render + 23556) = render + 8 * v16;
        *(_DWORD *)(render + 23552) = 0;
        *(_WORD *)(render + 8 * v16) = v17;
        *(_WORD *)(*(_DWORD *)(render + 23556) + 4) = *(_WORD *)(render + 23566);
        *(_WORD *)(*(_DWORD *)(render + 23556) + 2) = 0;
        *(_WORD *)(*(_DWORD *)(render + 23556) + 6) = 0;
        v18 = -1;
        for ( ia = 0; ia < sortList.m_Size; ++ia )
        {
          v19 = *(_DWORD *)&sortList.m_Memory.m_Memory[8 * ia];
          v20 = *(__int16 *)(v19 + 18);
          if ( v18 == v20 )
          {
            v21 = *(CBrushBatchRender::transbatch_t **)(render + 23552);
            v22 = *(CBrushBatchRender::transnode_t **)(render + 23556);
            ++v21->surfaceCount;
            v21->indexCount += 3 * *(unsigned __int8 *)(v19 + 3) - 6;
            *(_DWORD *)(render + 4 * (__int16)(*(_WORD *)(render + 23564))++ + 2048) = v19;
            if ( *(_WORD *)(v19 + 12) != 0xFFFF || *(_WORD *)(v19 + 14) != 0xFFFF )
            {
              ++v22->decalSurfaceCount;
              *(_DWORD *)(render + 4 * (__int16)(*(_WORD *)(render + 23566))++ + 6144) = v19;
            }
          }
          else
          {
            CBrushBatchRender::AddTransBatch(
              this: v24,
              (CBrushBatchRender::transrender_t *)render,
              surfID: *(msurface2_t **)&sortList.m_Memory.m_Memory[8 * ia]);
            v18 = v20;
          }
        }
        v4 = node;
        if ( *(_WORD *)(*(_DWORD *)(render + 23556) + 6) != 0 )
        {
          *(_DWORD *)(render + 23556) = 0;
          *(_DWORD *)(render + 23552) = 0;
        }
      }
    }
    CBrushBatchRender::BuildTransLists_r(
      this: v24,
      (CBrushBatchRender::transrender_t *)render,
      model,
      node: v4->children[side]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065A10
// Name: private: int CBrushBatchRender::ComputeInstanceGroups(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t __near *,class CUtlVectorFixedGrowable<struct CBrushBatchRender::BrushInstanceGroup_t,512> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBrushBatchRender::ComputeInstanceGroups(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        CBrushBatchRender::BrushBatchRenderData_t *nCount,
        CBrushBatchRender::BrushBatchRenderData_t *pRenderData,
        CUtlVectorFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512> *instanceGroups)
{
  IMaterial *v6; // edx
  CBrushBatchRender::brushrender_t **p_m_pBrushRender; // ecx
  int v8; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBrushBatchRender::BrushInstanceGroup_t *m_pMemory; // ecx
  int v12; // eax
  int v13; // eax
  IMaterial *v14; // eax
  bool v15; // zf
  int v16; // edi
  int v17; // eax
  CBrushBatchRender::BrushInstanceGroup_t *v18; // ecx
  int v19; // eax
  int v20; // eax
  int result; // eax
  int nMaxIndices; // [esp+0h] [ebp-18h]
  CBrushBatchRender::BrushBatchRenderData_t *pFirstInstance; // [esp+4h] [ebp-14h]
  int nMaxInstanceCount; // [esp+8h] [ebp-10h]
  IMaterial *pLastMaterial; // [esp+Ch] [ebp-Ch]
  IMaterial *pLastActualMaterial; // [esp+10h] [ebp-8h]
  int nIndexCount; // [esp+14h] [ebp-4h]
  int nInstanceCount; // [esp+20h] [ebp+8h]
  CBrushBatchRender::brushrender_t **nCounta; // [esp+24h] [ebp+Ch]
  CBrushBatchRender::BrushBatchRenderData_t *pRenderDataa; // [esp+28h] [ebp+10h]

  nMaxIndices = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  v6 = nullptr;
  nMaxInstanceCount = 0;
  pLastMaterial = nullptr;
  pLastActualMaterial = nullptr;
  pFirstInstance = nullptr;
  nInstanceCount = 0;
  nIndexCount = 0;
  if ( (int)nCount <= 0 )
    return 0;
  p_m_pBrushRender = &pRenderData->m_pBrushRender;
  nCounta = &pRenderData->m_pBrushRender;
  pRenderDataa = nCount;
  while ( 1 )
  {
    v8 = (int)&(*p_m_pBrushRender)->pBatches[(_WORD)p_m_pBrushRender[1] & 0x7FFF];
    if ( v6 == *(IMaterial **)(v8 + 4) && v6 == pLastActualMaterial && nIndexCount + *(_DWORD *)(v8 + 12) <= nMaxIndices )
    {
      nIndexCount += *(_DWORD *)(v8 + 12);
    }
    else
    {
      if ( nInstanceCount > 0 )
      {
        m_Size = instanceGroups->m_Size;
        m_nAllocationCount = instanceGroups->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>::Grow(
            this: &instanceGroups->m_Memory,
            nCount: m_Size - m_nAllocationCount + 1);
        ++instanceGroups->m_Size;
        m_pMemory = instanceGroups->m_Memory.m_pMemory;
        v12 = instanceGroups->m_Size - m_Size - 1;
        instanceGroups->m_pElements = instanceGroups->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v12);
        v13 = m_Size;
        instanceGroups->m_Memory.m_pMemory[v13].m_pRenderData = pFirstInstance;
        *((_WORD *)&instanceGroups->m_Memory.m_pMemory[m_Size] + 6) ^= (nInstanceCount
                                                                      ^ *((_WORD *)&instanceGroups->m_Memory.m_pMemory[m_Size]
                                                                        + 6))
                                                                     & 0x7FFF;
        instanceGroups->m_Memory.m_pMemory[v13].m_nIndexCount = nIndexCount;
        instanceGroups->m_Memory.m_pMemory[v13].m_pMaterial = pLastMaterial;
        instanceGroups->m_Memory.m_pMemory[v13].m_pActualMaterial = pLastActualMaterial;
        p_m_pBrushRender = nCounta;
        if ( nInstanceCount > nMaxInstanceCount )
          nMaxInstanceCount = nInstanceCount;
      }
      nIndexCount = *(_DWORD *)(v8 + 12);
      pFirstInstance = (CBrushBatchRender::BrushBatchRenderData_t *)(p_m_pBrushRender - 2);
      v14 = (IMaterial *)*(p_m_pBrushRender - 1);
      nInstanceCount = 0;
      pLastMaterial = v14;
      if ( *((__int16 *)p_m_pBrushRender + 3) < 0 )
        v14 = *(IMaterial **)(v8 + 4);
      pLastActualMaterial = v14;
    }
    ++nInstanceCount;
    p_m_pBrushRender += 4;
    v15 = pRenderDataa == (CBrushBatchRender::BrushBatchRenderData_t *)1;
    pRenderDataa = (CBrushBatchRender::BrushBatchRenderData_t *)((char *)pRenderDataa - 1);
    nCounta = p_m_pBrushRender;
    if ( v15 )
      break;
    v6 = pLastMaterial;
  }
  if ( nInstanceCount <= 0 )
    return nMaxInstanceCount;
  v16 = instanceGroups->m_Size;
  v17 = instanceGroups->m_Memory.m_nAllocationCount;
  if ( v16 + 1 > v17 )
    CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>::Grow(
      this: &instanceGroups->m_Memory,
      nCount: v16 - v17 + 1);
  ++instanceGroups->m_Size;
  v18 = instanceGroups->m_Memory.m_pMemory;
  v19 = instanceGroups->m_Size - v16 - 1;
  instanceGroups->m_pElements = instanceGroups->m_Memory.m_pMemory;
  if ( v19 > 0 )
    _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 16 * v19);
  v20 = v16;
  instanceGroups->m_Memory.m_pMemory[v20].m_pRenderData = pFirstInstance;
  *((_WORD *)&instanceGroups->m_Memory.m_pMemory[v20] + 6) ^= (nInstanceCount
                                                             ^ *((_WORD *)&instanceGroups->m_Memory.m_pMemory[v16] + 6))
                                                            & 0x7FFF;
  instanceGroups->m_Memory.m_pMemory[v20].m_nIndexCount = nIndexCount;
  instanceGroups->m_Memory.m_pMemory[v20].m_pMaterial = pLastMaterial;
  instanceGroups->m_Memory.m_pMemory[v20].m_pActualMaterial = pLastActualMaterial;
  result = nMaxInstanceCount;
  if ( nInstanceCount > nMaxInstanceCount )
    return nInstanceCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065C50
// Name: private: void CBrushBatchRender::DrawArrayDebugInformation(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawArrayDebugInformation(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const CBrushBatchRender::BrushBatchRenderData_t *pRenderData)
{
  const CBrushBatchRender::BrushBatchRenderData_t *v5; // edi
  CBrushBatchRender::brushrenderbatch_t *v6; // esi
  msurface2_t *v7; // ebx
  int v8; // edx
  int m_Size; // eax
  CBrushBatchRender::brushrender_t *m_pBrushRender; // ecx
  CBrushBatchRender::brushrendersurface_t *v11; // edx
  msurface2_t *v12; // edi
  float *p_x; // ecx
  int v14; // ebx
  unsigned int v15; // ebx
  msurface2_t **m_pMemory; // edx
  msurface2_t **v17; // ecx
  msurface2_t **v18; // eax
  bool v19; // zf
  const matrix3x4_t *m_pBrushToWorld; // [esp-14h] [ebp-850h]
  CUtlVectorFixedGrowable<msurface2_t *,512> surfaceList; // [esp+0h] [ebp-83Ch] BYREF
  Vector vecModelSpaceViewOrigin; // [esp+818h] [ebp-24h] BYREF
  msurface2_t *firstSurfID; // [esp+824h] [ebp-18h]
  const Vector *vecViewOrigin; // [esp+828h] [ebp-14h]
  int num; // [esp+82Ch] [ebp-10h]
  int v26; // [esp+830h] [ebp-Ch]
  unsigned __int8 *v27; // [esp+834h] [ebp-8h]
  int v28; // [esp+838h] [ebp-4h]
  const CBrushBatchRender::BrushBatchRenderData_t *nCounta; // [esp+848h] [ebp+Ch]
  int k; // [esp+84Ch] [ebp+10h]

  if ( g_ShaderDebug.anydebug )
  {
    vecViewOrigin = g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
    if ( nCount > 0 )
    {
      v5 = pRenderData;
      nCounta = pRenderData;
      v28 = nCount;
      do
      {
        v6 = &v5->m_pBrushRender->pBatches[*((_WORD *)v5 + 6) & 0x7FFF];
        v7 = (msurface2_t *)(*(_DWORD *)(v5->m_pInstanceData->m_pBrushModel->sprite.numframes + 124)
                           + 32 * v5->m_pInstanceData->m_pBrushModel->brush.firstmodelsurface);
        m_pBrushToWorld = v5->m_pInstanceData->m_pBrushToWorld;
        firstSurfID = v7;
        VectorITransform(in1: &vecViewOrigin->x, in2: m_pBrushToWorld, out: &vecModelSpaceViewOrigin.x);
        v8 = 0;
        surfaceList.m_Memory.m_pMemory = surfaceList.m_Memory.m_pFixedMemory;
        m_Size = 0;
        surfaceList.m_pElements = surfaceList.m_Memory.m_pFixedMemory;
        surfaceList.m_Memory.m_nAllocationCount = 512;
        surfaceList.m_Memory.m_nGrowSize = -1;
        surfaceList.m_Memory.m_nMallocGrowSize = 0;
        surfaceList.m_Size = 0;
        k = 0;
        if ( v6->surfaceCount > 0 )
        {
          while ( 1 )
          {
            m_pBrushRender = v5->m_pBrushRender;
            v11 = &m_pBrushRender->pSurfaces[v8 + v6->firstSurface];
            v12 = &v7[v11->surfaceIndex];
            if ( (v12->flags & 0x20) == 0
              && ((v12->flags & 0x200) != 0
               || (float)((float)((float)((float)((p_x = &m_pBrushRender->pPlanes[v11->planeIndex]->normal.x)[1]
                                                * vecModelSpaceViewOrigin.y)
                                        + (float)(vecModelSpaceViewOrigin.x * *p_x))
                                + (float)(p_x[2] * vecModelSpaceViewOrigin.z))
                        - p_x[3]) >= -0.0099999998) )
            {
              v14 = m_Size;
              v26 = m_Size;
              if ( m_Size + 1 > surfaceList.m_Memory.m_nAllocationCount )
              {
                num = m_Size - surfaceList.m_Memory.m_nAllocationCount + 1;
                if ( surfaceList.m_Memory.m_nGrowSize < 0 )
                {
                  surfaceList.m_Memory.m_nGrowSize = surfaceList.m_Memory.m_nMallocGrowSize;
                  if ( surfaceList.m_Memory.m_nAllocationCount != 0 )
                  {
                    v15 = 4 * surfaceList.m_Memory.m_nAllocationCount;
                    v27 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                               this: _g_pMemAlloc,
                                               a2: 4 * surfaceList.m_Memory.m_nAllocationCount);
                    memcpy(dst: v27, src: (unsigned __int8 *)surfaceList.m_Memory.m_pMemory, count: v15);
                    v14 = v26;
                    surfaceList.m_Memory.m_pMemory = (msurface2_t **)v27;
                  }
                  else
                  {
                    surfaceList.m_Memory.m_pMemory = nullptr;
                  }
                }
                CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&surfaceList, num);
                m_Size = surfaceList.m_Size;
              }
              m_pMemory = surfaceList.m_Memory.m_pMemory;
              surfaceList.m_Size = ++m_Size;
              surfaceList.m_pElements = surfaceList.m_Memory.m_pMemory;
              if ( m_Size - v14 - 1 > 0 )
              {
                _V_memmove(
                  dest: &surfaceList.m_Memory.m_pMemory[v14 + 1],
                  src: &surfaceList.m_Memory.m_pMemory[v14],
                  count: 4 * (m_Size - v14 - 1));
                m_Size = surfaceList.m_Size;
                m_pMemory = surfaceList.m_Memory.m_pMemory;
              }
              v17 = &m_pMemory[v14];
              if ( v17 != nullptr )
              {
                *v17 = v12;
                m_Size = surfaceList.m_Size;
              }
            }
            v5 = nCounta;
            v8 = k + 1;
            k = v8;
            if ( v8 >= v6->surfaceCount )
              break;
            v7 = firstSurfID;
          }
        }
        DrawDebugInformation(
          pRenderContext,
          brushToWorld: v5->m_pInstanceData->m_pBrushToWorld,
          pList: surfaceList.m_Memory.m_pMemory,
          listCount: m_Size);
        v18 = surfaceList.m_Memory.m_pMemory;
        surfaceList.m_Size = 0;
        if ( surfaceList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( surfaceList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfaceList.m_Memory.m_pMemory);
            v18 = nullptr;
            surfaceList.m_Memory.m_pMemory = nullptr;
          }
          surfaceList.m_Memory.m_nAllocationCount = 0;
        }
        surfaceList.m_pElements = v18;
        if ( surfaceList.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
        ++v5;
        v19 = v28-- == 1;
        nCounta = v5;
      }
      while ( !v19 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065EF0
// Name: public: void CBrushBatchRender::DrawTranslucentBrushModel(class IMatRenderContext __near *,struct model_t __near *,class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBrushBatchRender::DrawTranslucentBrushModel(
        CBrushBatchRender *this@<ecx>,
        CMeshBuilder *a2@<ebx>,
        int a3@<edi>,
        IMatRenderContext *pRenderContext,
        model_t *model,
        IClientEntity *baseentity)
{
  worldbrushdata_t *pShared; // edx
  int v8; // ecx
  IClientRenderable *v9; // eax
  CBrushBatchRender::transrender_t render; // [esp+4h] [ebp-5C10h] BYREF

  pShared = model->brush.pShared;
  v8 = model->brush.firstnode << 6;
  memset(&render.pLastBatch, 0, 16);
  CBrushBatchRender::BuildTransLists_r(this, (int)&render, model, node: (mnode_t *)((char *)pShared->nodes + v8));
  if ( baseentity != nullptr )
    v9 = baseentity->GetClientRenderable(this: baseentity);
  else
    v9 = nullptr;
  CBrushBatchRender::DrawTransLists(
    this,
    a2,
    m_nIndexCount: a3,
    a4: (int)this,
    pRenderContext,
    &render,
    pProxyData: (void *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x10065F70
// Name: public: struct CBrushBatchRender::brushrender_t __near * CBrushBatchRender::FindOrCreateRenderBatch(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBrushBatchRender::brushrender_t *__thiscall CBrushBatchRender::FindOrCreateRenderBatch(
        CBrushBatchRender *this,
        model_t *pModel)
{
  bool v2; // zf
  CBrushBatchRender::brushrender_t *result; // eax
  DWORD CurrentThreadId; // ecx
  unsigned __int16 v6; // cx
  CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short> > *p_m_renderList; // edi
  CBrushBatchRender::brushrender_t *v8; // eax
  CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short> > *v9; // ecx
  CBrushBatchRender::brushrender_t *v10; // esi
  cplane_t *v11; // eax
  __int16 v12; // ax
  cplane_t **m_pMemory; // edx
  __int16 v14; // cx
  UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short> *v15; // eax
  int m_Size; // edi
  msurface2_t *v17; // ebx
  cplane_t *v18; // ecx
  int v19; // eax
  int v20; // ecx
  cplane_t **v21; // eax
  unsigned __int8 *v22; // eax
  int v23; // edi
  int *v24; // eax
  int v25; // edx
  cplane_t *p_planeIndex; // ecx
  int materialSortID; // ecx
  CBrushBatchRender::brushrendermesh_t *v28; // edi
  int *v29; // edi
  int v30; // ecx
  IMesh *v31; // edi
  int flags_high; // ecx
  int v33; // edi
  cplane_t *v34; // ecx
  unsigned __int8 *v35; // eax
  __int16 v36; // di
  unsigned __int8 *v37; // eax
  CBrushBatchRender::surfacelist_t *v38; // eax
  int m_nGrowSize; // edi
  int v40; // edi
  cplane_t **v41; // eax
  volatile __int32 *v42; // eax
  unsigned __int8 *v43; // [esp-10h] [ebp-A70h]
  unsigned int v44; // [esp-Ch] [ebp-A6Ch]
  CBrushBatchRender::brushrenderbatch_t tmpBatch[128]; // [esp+8h] [ebp-A58h] BYREF
  CBrushBatchRender::brushrendermesh_t tmpMesh[128]; // [esp+808h] [ebp-258h] BYREF
  CBrushBatchRender *v47; // [esp+A08h] [ebp-58h]
  CBrushBatchRender::surfacelist_t tmp; // [esp+A0Ch] [ebp-54h] BYREF
  int sortID; // [esp+A14h] [ebp-4Ch]
  CBrushBatchRender::brushrendermesh_t *pMesh; // [esp+A18h] [ebp-48h]
  msurface2_t *surfID; // [esp+A1Ch] [ebp-44h]
  CBrushBatchRender::brushrendermesh_t *v52; // [esp+A20h] [ebp-40h]
  int *p_sortID; // [esp+A24h] [ebp-3Ch]
  IMesh *pLastMesh; // [esp+A28h] [ebp-38h]
  CUtlVector<CBrushBatchRender::surfacelist_t,CUtlMemory<CBrushBatchRender::surfacelist_t,int> > surfaceList; // [esp+A2Ch] [ebp-34h] BYREF
  CUtlVector<cplane_t *,CUtlMemory<cplane_t *,int> > planeList; // [esp+A40h] [ebp-20h] BYREF
  int lastSortID; // [esp+A54h] [ebp-Ch]
  cplane_t *plane; // [esp+A58h] [ebp-8h]
  int i; // [esp+A5Ch] [ebp-4h]
  int batchCount; // [esp+A68h] [ebp+8h]

  v2 = pModel->brush.nummodelsurfaces == 0;
  v47 = this;
  if ( v2 )
    return nullptr;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  v6 = pModel->brush.renderHandle - 1;
  p_m_renderList = &this->m_renderList;
  if ( v6 >= this->m_renderList.m_Memory.m_nAllocationCount
    || v6 > this->m_renderList.m_LastAlloc.index
    || p_m_renderList->m_Memory.m_pMemory[v6].m_Previous == v6 && p_m_renderList->m_Memory.m_pMemory[v6].m_Next != v6 )
  {
    v8 = (CBrushBatchRender::brushrender_t *)MemAlloc_Alloc(nSize: 0x1Cu);
    v9 = &this->m_renderList;
    v10 = v8;
    v11 = (cplane_t *)(unsigned __int16)CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal(
                                          this: v9,
                                          multilist: false);
    plane = v11;
    if ( (_WORD)v11 == 0xFFFF )
    {
      v12 = -1;
      m_pMemory = nullptr;
    }
    else
    {
      CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)p_m_renderList,
        before: 0xFFFFu,
        elem: (unsigned __int16)v11);
      v14 = (__int16)plane;
      v15 = &p_m_renderList->m_Memory.m_pMemory[(unsigned __int16)plane];
      m_pMemory = nullptr;
      if ( v15 != nullptr )
        v15->m_Element = v10;
      v12 = v14;
    }
    pModel->brush.renderHandle = v12 + 1;
    v10->pPlanes = nullptr;
    v10->pMeshes = nullptr;
    *(_DWORD *)&v10->planeCount = 0;
    *(_DWORD *)&v10->totalIndexCount = 0;
    m_Size = 0;
    v17 = (msurface2_t *)(*(_DWORD *)(pModel->sprite.numframes + 124) + 32 * pModel->brush.firstmodelsurface);
    memset(&planeList, 0, sizeof(planeList));
    memset(&surfaceList, 0, sizeof(surfaceList));
    for ( i = 0; i < pModel->brush.nummodelsurfaces; ++i )
    {
      if ( (v17->flags & 0x20) == 0 )
      {
        v18 = v17->plane;
        v19 = 0;
        plane = v18;
        if ( m_Size <= 0 )
          goto LABEL_25;
        while ( m_pMemory[v19] != v18 )
        {
          if ( ++v19 >= m_Size )
            goto LABEL_25;
        }
        if ( v19 == -1 )
        {
LABEL_25:
          v20 = m_Size;
          lastSortID = m_Size;
          if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&planeList,
              num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
            m_Size = planeList.m_Size;
            m_pMemory = planeList.m_Memory.m_pMemory;
            v20 = lastSortID;
          }
          planeList.m_Size = ++m_Size;
          planeList.m_pElements = m_pMemory;
          if ( m_Size - v20 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v20 + 1], src: &m_pMemory[v20], count: 4 * (m_Size - v20 - 1));
            m_pMemory = planeList.m_Memory.m_pMemory;
            v20 = lastSortID;
          }
          v21 = &m_pMemory[v20];
          if ( v21 != nullptr )
            *v21 = plane;
          LOWORD(v19) = v20;
        }
        tmp.planeIndex = v19;
        tmp.surfaceIndex = i;
        tmp.surfID = v17;
        CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
          this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&surfaceList,
          elem: surfaceList.m_Size,
          src: (const vgui::PropertySheet::Page_t *)&tmp);
        m_pMemory = planeList.m_Memory.m_pMemory;
      }
      ++v17;
    }
    CUtlVector<CBrushBatchRender::surfacelist_t,CUtlMemory<CBrushBatchRender::surfacelist_t,int>>::Sort(
      this: &surfaceList,
      pfnCompare: (int (__cdecl *)(const void *, const void *))CBrushBatchRender::SurfaceCmp);
    v22 = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)m_Size >> 30 != 0 ? -1 : 4 * m_Size);
    v43 = (unsigned __int8 *)planeList.m_Memory.m_pMemory;
    v10->pPlanes = (cplane_t **)v22;
    v10->planeCount = m_Size;
    memcpy(dst: v22, src: v43, count: 4 * m_Size);
    v23 = surfaceList.m_Size;
    v10->pSurfaces = (CBrushBatchRender::brushrendersurface_t *)MemAlloc_Alloc(
                                                                  nSize: (unsigned __int64)(unsigned int)surfaceList.m_Size >> 30 != 0
                                                                ? -1
                                                                : 4 * surfaceList.m_Size);
    v24 = nullptr;
    v25 = 0;
    v10->surfaceCount = v23;
    i = 0;
    batchCount = 0;
    lastSortID = -1;
    pLastMesh = nullptr;
    pMesh = nullptr;
    if ( v23 > 0 )
    {
      v52 = tmpMesh;
      p_sortID = &tmpBatch[0].sortID;
      p_planeIndex = (cplane_t *)&surfaceList.m_Memory.m_pMemory->planeIndex;
      plane = (cplane_t *)&surfaceList.m_Memory.m_pMemory->planeIndex;
      do
      {
        v10->pSurfaces[v25].surfaceIndex = *(_WORD *)p_planeIndex[-1].pad;
        v10->pSurfaces[v25].planeIndex = LOWORD(p_planeIndex->normal.x);
        surfID = *(msurface2_t **)((char *)&p_planeIndex[-1].dist + 2);
        materialSortID = surfID->materialSortID;
        sortID = materialSortID;
        if ( g_WorldStaticMeshes.m_Memory.m_pMemory[materialSortID] != pLastMesh )
        {
          v28 = v52;
          ++i;
          v52->firstBatch = batchCount;
          pMesh = v28;
          v28->batchCount = 0;
          lastSortID = -1;
          v52 = v28 + 1;
        }
        if ( materialSortID != lastSortID )
        {
          v29 = p_sortID;
          *p_sortID = materialSortID;
          v30 = *((unsigned __int16 *)surfID + 11) >> 1;
          *((_WORD *)v29 - 3) = 0;
          *(v29 - 1) = (int)host_state.worldbrush->texinfo[v30].material;
          ++pMesh->batchCount;
          ++batchCount;
          materialSortID = sortID;
          v24 = v29 - 2;
          v29[1] = 0;
          *((_WORD *)v29 - 4) = v25;
          p_sortID = v29 + 4;
        }
        v31 = g_WorldStaticMeshes.m_Memory.m_pMemory[materialSortID];
        ++*((_WORD *)v24 + 1);
        lastSortID = materialSortID;
        flags_high = HIBYTE(surfID->flags);
        v10->totalVertexCount += flags_high;
        pLastMesh = v31;
        v33 = 3 * flags_high - 6;
        v34 = plane;
        v24[3] += v33;
        v10->totalIndexCount += v33;
        ++v25;
        p_planeIndex = (cplane_t *)&v34->normal.z;
        plane = p_planeIndex;
      }
      while ( v25 < surfaceList.m_Size );
    }
    v35 = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)i >> 30 != 0 ? -1 : 4 * i);
    v36 = i;
    v44 = 4 * i;
    v10->pMeshes = (CBrushBatchRender::brushrendermesh_t *)v35;
    memcpy(dst: v35, src: (unsigned __int8 *)tmpMesh, count: v44);
    v10->meshCount = v36;
    v37 = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)batchCount >> 28 != 0 ? -1 : 16 * batchCount);
    v10->pBatches = (CBrushBatchRender::brushrenderbatch_t *)v37;
    memcpy(dst: v37, src: (unsigned __int8 *)tmpBatch, count: 16 * batchCount);
    v38 = surfaceList.m_Memory.m_pMemory;
    v10->batchCount = batchCount;
    m_nGrowSize = surfaceList.m_Memory.m_nGrowSize;
    surfaceList.m_Size = 0;
    if ( surfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v38 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v38);
        surfaceList.m_Memory.m_pMemory = nullptr;
        v38 = nullptr;
      }
      surfaceList.m_Memory.m_nAllocationCount = 0;
    }
    surfaceList.m_pElements = v38;
    if ( m_nGrowSize >= 0 )
    {
      if ( v38 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v38);
        surfaceList.m_Memory.m_pMemory = nullptr;
      }
      surfaceList.m_Memory.m_nAllocationCount = 0;
    }
    v40 = planeList.m_Memory.m_nGrowSize;
    v41 = planeList.m_Memory.m_pMemory;
    planeList.m_Size = 0;
    if ( planeList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( planeList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planeList.m_Memory.m_pMemory);
        planeList.m_Memory.m_pMemory = nullptr;
        v41 = nullptr;
      }
      planeList.m_Memory.m_nAllocationCount = 0;
    }
    planeList.m_pElements = v41;
    if ( v40 >= 0 )
    {
      if ( v41 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
        planeList.m_Memory.m_pMemory = nullptr;
      }
      planeList.m_Memory.m_nAllocationCount = 0;
    }
    v42 = (volatile __int32 *)v47;
    v2 = v47->m_Mutex.m_depth-- == 1;
    if ( v2 )
      _InterlockedExchange(v42, 0);
    return v10;
  }
  else
  {
    result = p_m_renderList->m_Memory.m_pMemory[v6].m_Element;
    v2 = this->m_Mutex.m_depth-- == 1;
    if ( v2 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066430
// Name: public: void CBrushBatchRender::DrawOpaqueBrushModel(class IMatRenderContext __near *,class IClientEntity __near *,struct model_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBrushBatchRender::DrawOpaqueBrushModel(
        CBrushBatchRender *this@<ecx>,
        CMeshBuilder *a2@<edi>,
        IMatRenderContext *pRenderContext,
        IClientEntity *baseentity,
        model_t *model,
        bool bShadowDepth)
{
  CBrushBatchRender::brushrender_t *RenderBatch; // ebx
  int planeCount; // ecx
  int v8; // edi
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  int v12; // edx
  _DWORD *v13; // eax
  char *v14; // esi
  int v15; // eax
  int v16; // edx
  S3RGBA *v17; // edx
  int m_nAllocationCount; // ecx
  __int16 *v19; // edi
  __int16 *v20; // esi
  int v21; // edi
  unsigned int v22; // ebx
  S3RGBA *v23; // eax
  int v24; // esi
  int v25; // edi
  unsigned int v26; // ebx
  S3RGBA *v27; // eax
  CBrushBatchRender::brushrenderbatch_t *v28; // edi
  int v29; // ebx
  int surfaceCount; // eax
  __int16 *p_planeIndex; // ecx
  BOOL v32; // ebx
  IMaterial *v33; // esi
  int v34; // eax
  IMaterial *pMaterial; // ecx
  IMaterial_vtbl *v36; // edx
  int v37; // eax
  IMaterial *v38; // ecx
  IMaterial_vtbl *v39; // edx
  int v40; // eax
  IMaterial_vtbl *v41; // edx
  unsigned __int8 *v42; // ebx
  IMaterialVar *(__thiscall *FindVarFast)(IMaterial *, const char *, unsigned int *); // eax
  int v44; // eax
  IMaterial_vtbl *v45; // edx
  int v46; // ebx
  int v47; // eax
  int v48; // eax
  IMesh *v49; // eax
  CBrushBatchRender::brushrendersurface_t *pSurfaces; // edx
  int v51; // eax
  int planeIndex; // ecx
  CBrushBatchRender::brushrendersurface_t *v53; // eax
  msurface2_t *v54; // esi
  unsigned __int8 *v55; // eax
  S3RGBA *v56; // ebx
  unsigned int v57; // ebx
  S3RGBA *v58; // ecx
  int v59; // eax
  msurface2_t **v60; // ecx
  CBrushBatchRender::brushrendermesh_t *v61; // ebx
  int v62; // ecx
  int m_nVertexCount; // eax
  int batchCount; // edx
  S3RGBA *v65; // eax
  S3RGBA *v66; // edx
  int v67; // ecx
  CBrushBatchRender::brushrendermesh_t *v68; // eax
  int v69; // edx
  int v70; // esi
  IMaterial *v71; // edi
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // edx
  IMesh *v73; // eax
  CBrushBatchRender::brushrendermesh_t *v74; // ebx
  S3RGBA *v75; // esi
  int v76; // eax
  int v77; // ecx
  int v78; // esi
  CBrushBatchRender::brushrendermesh_t *v79; // edx
  msurface2_t **v80; // ebx
  model_t *v81; // edi
  CBrushBatchRender::brushrenderbatch_t *v82; // eax
  int v83; // ecx
  CBrushBatchRender::brushrendersurface_t *v84; // eax
  int v85; // ebx
  int v86; // edi
  S3RGBA *v87; // edi
  S3RGBA *v88; // eax
  S3RGBA *v89; // eax
  S3RGBA *v90; // eax
  float v91; // [esp+8h] [ebp-1420h]
  int v93; // [esp+18h] [ebp-1410h] BYREF
  _DWORD v94[1023]; // [esp+1Ch] [ebp-140Ch] BYREF
  CUtlMemory<S3RGBA,int> v95; // [esp+1018h] [ebp-410h] BYREF
  int v96; // [esp+1024h] [ebp-404h]
  _BYTE v97[88]; // [esp+1028h] [ebp-400h] BYREF
  unsigned __int8 *v98; // [esp+1128h] [ebp-300h]
  S3RGBA *v99; // [esp+112Ch] [ebp-2FCh]
  CMeshBuilder v100; // [esp+1130h] [ebp-2F8h] BYREF
  int v101; // [esp+1318h] [ebp-110h] BYREF
  CUtlMemory<S3RGBA,int> v102; // [esp+131Ch] [ebp-10Ch] BYREF
  int v103; // [esp+1328h] [ebp-100h]
  _BYTE v104[64]; // [esp+132Ch] [ebp-FCh] BYREF
  int v105; // [esp+136Ch] [ebp-BCh]
  S3RGBA *v106; // [esp+1370h] [ebp-B8h]
  int v107; // [esp+1374h] [ebp-B4h] BYREF
  int v108; // [esp+1378h] [ebp-B0h] BYREF
  int v109; // [esp+137Ch] [ebp-ACh] BYREF
  int pVertexCount; // [esp+1380h] [ebp-A8h]
  CUtlMemory<S3RGBA,int> v111; // [esp+1384h] [ebp-A4h] BYREF
  int v112; // [esp+1390h] [ebp-98h]
  _BYTE v113[64]; // [esp+1394h] [ebp-94h] BYREF
  __int16 *v114; // [esp+13D4h] [ebp-54h]
  S3RGBA *m_pMemory; // [esp+13D8h] [ebp-50h]
  int v116; // [esp+13DCh] [ebp-4Ch]
  int v117; // [esp+13E0h] [ebp-48h]
  CUtlMemory<S3RGBA,int> v118; // [esp+13E4h] [ebp-44h] BYREF
  int v119; // [esp+13F0h] [ebp-38h]
  S3RGBA *v120; // [esp+13F4h] [ebp-34h]
  CBrushBatchRender::brushrendermesh_t *v121; // [esp+13F8h] [ebp-30h]
  IClientRenderable *v122; // [esp+13FCh] [ebp-2Ch]
  S3RGBA *v123; // [esp+1400h] [ebp-28h]
  int v124; // [esp+1404h] [ebp-24h] BYREF
  int v125; // [esp+1408h] [ebp-20h]
  int v126; // [esp+140Ch] [ebp-1Ch]
  int v127; // [esp+1410h] [ebp-18h]
  IMaterial *v128; // [esp+1414h] [ebp-14h]
  CBrushBatchRender::brushrendermesh_t *v129; // [esp+1418h] [ebp-10h]
  int v130; // [esp+141Ch] [ebp-Ch]
  S3RGBA *v131; // [esp+1420h] [ebp-8h]
  CBrushBatchRender::brushrender_t *v132; // [esp+1424h] [ebp-4h]
  char *v133; // [esp+1434h] [ebp+Ch]
  int v134; // [esp+1434h] [ebp+Ch]
  int i; // [esp+1434h] [ebp+Ch]
  int j; // [esp+1434h] [ebp+Ch]
  model_t *v137; // [esp+1438h] [ebp+10h]
  char v138; // [esp+143Bh] [ebp+13h]
  int v139; // [esp+143Ch] [ebp+14h]
  int v140; // [esp+143Ch] [ebp+14h]

  v117 = *(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface;
  RenderBatch = CBrushBatchRender::FindOrCreateRenderBatch(this, pModel: model);
  v132 = RenderBatch;
  if ( RenderBatch != nullptr )
  {
    v138 = 0;
    if ( g_pMaterialSystemConfig->nFullbright == 1 || bShadowDepth )
    {
      ((void (__stdcall *)(int))pRenderContext->BindLightmapPage)(a1: -2);
      v138 = 1;
    }
    if ( baseentity != nullptr )
      v122 = baseentity->GetClientRenderable(this: baseentity);
    else
      v122 = nullptr;
    if ( bShadowDepth )
    {
      planeCount = RenderBatch->planeCount;
      if ( planeCount > 0 )
        memset(&v93, 0, 4 * planeCount);
    }
    else
    {
      v8 = RenderBatch->planeCount;
      z = modelorg.z;
      y = modelorg.y;
      x = modelorg.x;
      v12 = 0;
      if ( v8 >= 4 )
      {
        v133 = (char *)((char *)&v93 - (char *)RenderBatch->pPlanes);
        v13 = RenderBatch->pPlanes + 2;
        v129 = (CBrushBatchRender::brushrendermesh_t *)((char *)v94 - (char *)RenderBatch->pPlanes);
        do
        {
          v94[v12 - 1] = (float)((float)((float)((float)(*(float *)(*(v13 - 2) + 4) * y)
                                               + (float)(*(float *)*(v13 - 2) * x))
                                       + (float)(*(float *)(*(v13 - 2) + 8) * z))
                               - *(float *)(*(v13 - 2) + 12)) < -0.0099999998;
          v94[v12] = (float)((float)((float)((float)(*(float *)(*(v13 - 1) + 4) * y) + (float)(*(float *)*(v13 - 1) * x))
                                   + (float)(*(float *)(*(v13 - 1) + 8) * z))
                           - *(float *)(*(v13 - 1) + 12)) < -0.0099999998;
          *(_DWORD *)((char *)v13 + (_DWORD)v133) = (float)((float)((float)((float)(*(float *)(*v13 + 4) * y)
                                                                          + (float)(*(float *)*v13 * x))
                                                                  + (float)(*(float *)(*v13 + 8) * z))
                                                          - *(float *)(*v13 + 12)) < -0.0099999998;
          *(_DWORD *)((char *)v13 + (_DWORD)v129) = (float)((float)((float)((float)(*(float *)(v13[1] + 4) * y)
                                                                          + (float)(*(float *)v13[1] * x))
                                                                  + (float)(*(float *)(v13[1] + 8) * z))
                                                          - *(float *)(v13[1] + 12)) < -0.0099999998;
          v12 += 4;
          v13 += 4;
        }
        while ( v12 < v8 - 3 );
      }
      if ( v12 < v8 )
      {
        v14 = (char *)((char *)&v93 - (char *)RenderBatch->pPlanes);
        v15 = (int)&RenderBatch->pPlanes[v12];
        v16 = v8 - v12;
        do
        {
          *(_DWORD *)&v14[v15] = (float)((float)((float)((float)(*(float *)(*(_DWORD *)v15 + 4) * y)
                                                       + (float)(**(float **)v15 * x))
                                               + (float)(*(float *)(*(_DWORD *)v15 + 8) * z))
                                       - *(float *)(*(_DWORD *)v15 + 12)) < -0.0099999998;
          v15 += 4;
          --v16;
        }
        while ( v16 != 0 );
      }
    }
    v95.m_pMemory = (S3RGBA *)v97;
    v95.m_nGrowSize = -1;
    v111.m_nGrowSize = -1;
    v99 = (S3RGBA *)v97;
    m_pMemory = (S3RGBA *)v113;
    v17 = (S3RGBA *)v104;
    v111.m_pMemory = (S3RGBA *)v113;
    m_nAllocationCount = 16;
    v19 = nullptr;
    v95.m_nAllocationCount = 64;
    v96 = 0;
    v98 = nullptr;
    v111.m_nAllocationCount = 16;
    v112 = 0;
    v114 = nullptr;
    v102.m_pMemory = (S3RGBA *)v104;
    v102.m_nAllocationCount = 16;
    v102.m_nGrowSize = -1;
    v103 = 0;
    v105 = 0;
    v106 = (S3RGBA *)v104;
    v134 = 0;
    if ( RenderBatch->meshCount > 0 )
    {
      do
      {
        v129 = &v132->pMeshes[v134];
        v125 = 0;
        if ( v129->batchCount > 0 )
        {
          do
          {
            v121 = (CBrushBatchRender::brushrendermesh_t *)v19;
            v20 = v19;
            if ( (int)v19 + 1 > m_nAllocationCount )
            {
              v21 = (int)v19 - m_nAllocationCount + 1;
              if ( v111.m_nGrowSize < 0 )
              {
                v111.m_nGrowSize = v112;
                if ( m_nAllocationCount != 0 )
                {
                  v22 = 4 * m_nAllocationCount;
                  v131 = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nAllocationCount);
                  memcpy(dst: (unsigned __int8 *)v131, src: (unsigned __int8 *)v111.m_pMemory, count: v22);
                  v111.m_pMemory = v131;
                }
                else
                {
                  v111.m_pMemory = nullptr;
                }
              }
              CUtlMemory<INetMessage *,int>::Grow(this: &v111, num: v21);
            }
            v114 = (__int16 *)((char *)v114 + 1);
            m_pMemory = v111.m_pMemory;
            if ( (char *)v114 - (char *)v20 - 1 > 0 )
              _V_memmove(
                dest: &v111.m_pMemory[(_DWORD)v20 + 1],
                src: &v111.m_pMemory[(_DWORD)v20],
                count: 4 * ((char *)v114 - (char *)v20 - 1));
            v23 = &v111.m_pMemory[(_DWORD)v20];
            if ( v23 != nullptr )
              *v23 = 0;
            v24 = v105;
            if ( v105 + 1 > v102.m_nAllocationCount )
            {
              v25 = v105 - v102.m_nAllocationCount + 1;
              if ( v102.m_nGrowSize < 0 )
              {
                v102.m_nGrowSize = v103;
                if ( v102.m_nAllocationCount != 0 )
                {
                  v26 = 4 * v102.m_nAllocationCount;
                  v131 = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v102.m_nAllocationCount);
                  memcpy(dst: (unsigned __int8 *)v131, src: (unsigned __int8 *)v102.m_pMemory, count: v26);
                  v102.m_pMemory = v131;
                }
                else
                {
                  v102.m_pMemory = nullptr;
                }
              }
              CUtlMemory<INetMessage *,int>::Grow(this: &v102, num: v25);
            }
            ++v105;
            v106 = v102.m_pMemory;
            if ( v105 - v24 - 1 > 0 )
              _V_memmove(dest: &v102.m_pMemory[v24 + 1], src: &v102.m_pMemory[v24], count: 4 * (v105 - v24 - 1));
            v27 = &v102.m_pMemory[v24];
            if ( v27 != nullptr )
              *v27 = 0;
            v28 = &v132->pBatches[v125 + v129->firstBatch];
            v29 = 0;
            surfaceCount = v28->surfaceCount;
            v127 = 0;
            if ( surfaceCount > 0 )
            {
              p_planeIndex = &v132->pSurfaces[v28->firstSurface].planeIndex;
              do
              {
                if ( v94[*p_planeIndex - 1] == 0 )
                  break;
                ++v29;
                p_planeIndex += 2;
              }
              while ( v29 < surfaceCount );
              v127 = v29;
            }
            if ( v29 != surfaceCount )
            {
              v100.m_pMesh = nullptr;
              v100.m_bGenerateIndices = false;
              memset(&v100.m_IndexBuilder.m_pIndexBuffer, 0, 12);
              v100.m_IndexBuilder.m_nCurrentIndex = 0;
              v100.m_IndexBuilder.m_nTotalIndexCount = 0;
              v100.m_IndexBuilder.m_nBufferOffset = -1;
              v100.m_IndexBuilder.m_nBufferFirstIndex = 0;
              v100.m_VertexBuilder.m_pVertexBuffer = nullptr;
              v100.m_VertexBuilder.m_nBufferOffset = -1;
              v100.m_VertexBuilder.m_nBufferFirstVertex = 0;
              memset(&v100.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
              v100.m_VertexBuilder.m_nTotalVertexCount = 0;
              v100.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
              if ( bShadowDepth )
              {
                v32 = v28->pMaterial->IsAlphaTested(this: v28->pMaterial);
                v33 = g_pMaterialDepthWrite[v32][(unsigned __int8)v28->pMaterial->IsTwoSided(this: v28->pMaterial)];
                if ( v32 )
                {
                  v34 = (int)v28->pMaterial->FindVarFast(
                               this: v28->pMaterial,
                               a2: "$basetexture",
                               a3: &originalTextureVarCache_0);
                  pMaterial = v28->pMaterial;
                  v36 = pMaterial->__vftable;
                  v128 = (IMaterial *)v34;
                  v37 = (int)v36->FindVarFast(this: pMaterial, a2: "$frame", a3: &originalTextureFrameVarCache_0);
                  v38 = v28->pMaterial;
                  v39 = v38->__vftable;
                  v116 = v37;
                  v40 = (int)v39->FindVarFast(this: v38, a2: "$AlphaTestReference", a3: &originalAlphaRefCache_0);
                  v41 = v33->__vftable;
                  v130 = v40;
                  v42 = (unsigned __int8 *)v41->FindVarFast(this: v33, a2: "$basetexture", a3: &textureVarCache_0);
                  FindVarFast = v33->FindVarFast;
                  v123 = (S3RGBA *)v42;
                  v44 = (int)FindVarFast(this: v33, a2: "$frame", a3: &textureFrameVarCache_0);
                  v45 = v33->__vftable;
                  v126 = v44;
                  v131 = (S3RGBA *)v45->FindVarFast(this: v33, a2: "$AlphaTestReference", a3: &alphaRefCache_0);
                  if ( v42 != nullptr && v128 != nullptr )
                  {
                    v46 = *(_DWORD *)v42;
                    v47 = v128->GetName(this: v128);
                    (*(void (__thiscall **)(S3RGBA *, int))(v46 + 60))(a1: v123, a2: v47);
                  }
                  if ( v126 != 0 && v116 != 0 )
                  {
                    v48 = (*(int (__thiscall **)(int))(*(_DWORD *)v116 + 108))(a1: v116);
                    (*(void (__thiscall **)(int, int))(*(_DWORD *)v126 + 20))(a1: v126, a2: v48);
                  }
                  if ( v131 != nullptr && v130 != 0 )
                  {
                    v91 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v130 + 112))(a1: v130);
                    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v131 + 16))(a1: LODWORD(v91));
                  }
                }
                v29 = v127;
                v128 = v33;
              }
              else
              {
                v33 = v28->pMaterial;
                v128 = v33;
                if ( g_bIsBlendingOrModulating )
                {
                  *(float *)&pVertexCount = v33->GetAlphaModulation(this: v33);
                  v33->GetColorModulation(this: v33, a2: (float *)&v107, a3: (float *)&v108, a4: (float *)&v109);
                  ((void (__thiscall *)(IMaterial *, _DWORD))v33->AlphaModulate)(a1: v33, a2: LODWORD(r_blend));
                  ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))v33->ColorModulate)(
                    a1: v33,
                    a2: LODWORD(r_colormod.x),
                    a3: LODWORD(r_colormod.y),
                    a4: LODWORD(r_colormod.z));
                }
                if ( v138 == 0 )
                  pRenderContext->BindLightmapPage(
                    this: pRenderContext,
                    a2: materialSortInfoArray[v28->sortID].lightmapPageID);
              }
              ((void (__thiscall *)(IMatRenderContext *, IMaterial *, IClientRenderable *, CMeshBuilder *))pRenderContext->Bind)(
                a1: pRenderContext,
                a2: v33,
                a3: v122,
                a4: a2);
              v49 = pRenderContext->GetDynamicMesh(
                      this: pRenderContext,
                      a2: 0,
                      a3: g_WorldStaticMeshes.m_Memory.m_pMemory[v28->sortID],
                      a4: 0,
                      a5: 0);
              CMeshBuilder::Begin(
                this: &v100,
                pMesh: v49,
                type: MATERIAL_TRIANGLES,
                nVertexCount: 0,
                nIndexCount: v28->indexCount,
                pMeshSettings: nullptr);
              if ( v29 < v28->surfaceCount )
              {
                while ( 1 )
                {
                  pSurfaces = v132->pSurfaces;
                  v51 = v29 + v28->firstSurface;
                  planeIndex = pSurfaces[v51].planeIndex;
                  v53 = &pSurfaces[v51];
                  if ( v94[planeIndex - 1] == 0 )
                  {
                    v54 = (msurface2_t *)(v117 + 32 * v53->surfaceIndex);
                    if ( !bShadowDepth && (v54->flags & 0x200000) != 0 )
                    {
                      v55 = v98;
                      v56 = (S3RGBA *)v98;
                      v131 = (S3RGBA *)v98;
                      if ( (int)(v98 + 1) > v95.m_nAllocationCount )
                      {
                        v130 = (int)&v98[-v95.m_nAllocationCount + 1];
                        if ( v95.m_nGrowSize < 0 )
                        {
                          v95.m_nGrowSize = v96;
                          if ( v95.m_nAllocationCount != 0 )
                          {
                            v57 = 4 * v95.m_nAllocationCount;
                            v123 = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v95.m_nAllocationCount);
                            memcpy(dst: (unsigned __int8 *)v123, src: (unsigned __int8 *)v95.m_pMemory, count: v57);
                            v56 = v131;
                            v95.m_pMemory = v123;
                          }
                          else
                          {
                            v95.m_pMemory = nullptr;
                          }
                        }
                        CUtlMemory<INetMessage *,int>::Grow(this: &v95, num: v130);
                        v55 = v98;
                      }
                      v58 = v95.m_pMemory;
                      v98 = v55 + 1;
                      v59 = v55 - (unsigned __int8 *)v56;
                      v99 = v95.m_pMemory;
                      if ( v59 > 0 )
                      {
                        _V_memmove(
                          dest: &v95.m_pMemory[(_DWORD)v56 + 1],
                          src: &v95.m_pMemory[(_DWORD)v56],
                          count: 4 * v59);
                        v58 = v95.m_pMemory;
                      }
                      v60 = (msurface2_t **)&v58[(_DWORD)v56];
                      if ( v60 != nullptr )
                        *v60 = v54;
                      v61 = v121;
                      ++*(_DWORD *)&v111.m_pMemory[(_DWORD)v121];
                      Shader_GetSurfVertexAndIndexCount(surfaceHandle: v54, pVertexCount: &v101, pIndexCount: &v124);
                      *(_DWORD *)&v102.m_pMemory[(_DWORD)v61] += v124;
                      v29 = v127;
                    }
                    BuildIndicesForSurface(meshBuilder: &v100.m_IndexBuilder, surfID: v54);
                    if ( v54->decals == 0xFFFF )
                    {
                      if ( !bShadowDepth )
                        goto LABEL_80;
                    }
                    else if ( !bShadowDepth )
                    {
                      DecalSurfaceAdd(surfID: v54, iGroup: 4);
LABEL_80:
                      if ( v54->m_ShadowDecals != 0xFFFF )
                        g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: v54->m_ShadowDecals);
                    }
                  }
                  v62 = v28->surfaceCount;
                  v127 = ++v29;
                  if ( v29 >= v62 )
                  {
                    v33 = v128;
                    break;
                  }
                }
              }
              if ( v100.m_bGenerateIndices )
              {
                switch ( v100.m_Type )
                {
                  case MATERIAL_LINE_STRIP:
                    m_nVertexCount = 2 * v100.m_VertexBuilder.m_nVertexCount - 2;
                    break;
                  case MATERIAL_LINE_LOOP:
                    m_nVertexCount = 2 * v100.m_VertexBuilder.m_nVertexCount;
                    break;
                  case MATERIAL_POLYGON:
                    m_nVertexCount = 3 * v100.m_VertexBuilder.m_nVertexCount - 6;
                    break;
                  case MATERIAL_QUADS:
                    m_nVertexCount = 6 * v100.m_VertexBuilder.m_nVertexCount / 4;
                    break;
                  case MATERIAL_INSTANCED_QUADS:
                    m_nVertexCount = 0;
                    break;
                  default:
                    m_nVertexCount = v100.m_VertexBuilder.m_nVertexCount;
                    break;
                }
                CIndexBuilder::GenerateIndices(
                  this: &v100.m_IndexBuilder,
                  primitiveType: v100.m_Type,
                  nIndexCount: m_nVertexCount);
              }
              a2 = &v100;
              ((void (__thiscall *)(IMesh *, int, int))v100.m_pMesh->UnlockMesh)(
                a1: v100.m_pMesh,
                a2: v100.m_VertexBuilder.m_nVertexCount,
                a3: v100.m_IndexBuilder.m_nIndexCount);
              v100.m_IndexBuilder.m_pIndexBuffer = nullptr;
              v100.m_IndexBuilder.m_nMaxIndexCount = 0;
              v100.m_VertexBuilder.m_nMaxVertexCount = 0;
              v100.m_VertexBuilder.m_pVertexBuffer = nullptr;
              v100.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
              v100.m_pMesh->Draw_2(this: v100.m_pMesh, a2: -1, a3: 0);
              v100.m_pMesh = nullptr;
              if ( !bShadowDepth && g_bIsBlendingOrModulating )
              {
                ((void (__thiscall *)(IMaterial *, int))v33->AlphaModulate)(a1: v33, a2: pVertexCount);
                ((void (__thiscall *)(IMaterial *, int, int, int))v33->ColorModulate)(
                  a1: v33,
                  a2: v107,
                  a3: v108,
                  a4: v109);
              }
              if ( v100.m_VertexBuilder.m_pVertexBuffer != nullptr
                && v100.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v100.m_VertexBuilder.m_pVertexBuffer) )
              {
                v100.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v100.m_VertexBuilder.m_pVertexBuffer);
              }
              if ( v100.m_IndexBuilder.m_pIndexBuffer != nullptr
                && v100.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v100.m_IndexBuilder.m_pIndexBuffer) )
              {
                v100.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v100.m_IndexBuilder.m_pIndexBuffer);
              }
            }
            batchCount = v129->batchCount;
            v19 = v114;
            m_nAllocationCount = v111.m_nAllocationCount;
            ++v125;
          }
          while ( v125 < batchCount );
          v17 = v102.m_pMemory;
        }
        ++v134;
      }
      while ( v134 < v132->meshCount );
    }
    if ( bShadowDepth )
    {
      v105 = 0;
      if ( v102.m_nGrowSize >= 0 )
      {
        if ( v17 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
          v17 = nullptr;
          v102.m_pMemory = nullptr;
        }
        v102.m_nAllocationCount = 0;
      }
      v106 = v17;
      if ( v102.m_nGrowSize >= 0 )
      {
        if ( v17 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
          v102.m_pMemory = nullptr;
        }
        v102.m_nAllocationCount = 0;
      }
      v65 = v111.m_pMemory;
      v114 = nullptr;
      if ( v111.m_nGrowSize >= 0 )
      {
        if ( v111.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v111.m_pMemory);
          v65 = nullptr;
          v111.m_pMemory = nullptr;
        }
        v111.m_nAllocationCount = 0;
      }
      v66 = v95.m_pMemory;
      m_pMemory = v65;
      if ( v111.m_nGrowSize >= 0 )
      {
        if ( v65 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v65);
          v111.m_pMemory = nullptr;
        }
        v66 = v95.m_pMemory;
        v111.m_nAllocationCount = 0;
      }
      v98 = nullptr;
      if ( v95.m_nGrowSize >= 0 )
      {
        if ( v66 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66);
          v66 = nullptr;
          v95.m_pMemory = nullptr;
        }
        v95.m_nAllocationCount = 0;
      }
      v99 = v66;
      if ( v95.m_nGrowSize >= 0 && v66 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66);
    }
    else
    {
      if ( v98 != nullptr )
      {
        ((void (__thiscall *)(IMatRenderContext *, int, CMeshBuilder *))pRenderContext->__vftable[1].EndRender)(
          a1: pRenderContext,
          a2: 1,
          a3: a2);
        v67 = 0;
        v139 = 0;
        v131 = nullptr;
        for ( i = 0; v67 < v132->meshCount; i = ++v67 )
        {
          v68 = &v132->pMeshes[v67];
          v69 = 0;
          v130 = (int)v68;
          v126 = 0;
          if ( v68->batchCount > 0 )
          {
            do
            {
              v129 = (CBrushBatchRender::brushrendermesh_t *)v111.m_pMemory[v139];
              if ( (int)v129 > 0 )
              {
                v70 = (int)&v132->pBatches[v69 + v68->firstBatch];
                v71 = *(IMaterial **)(v70 + 4);
                if ( v138 == 0 )
                  pRenderContext->BindLightmapPage(
                    this: pRenderContext,
                    a2: materialSortInfoArray[*(_DWORD *)(v70 + 8)].lightmapPageID);
                pRenderContext->Bind(this: pRenderContext, a2: v71, a3: (void *)v122);
                GetDynamicMesh = pRenderContext->GetDynamicMesh;
                v100.m_IndexBuilder.m_nBufferOffset = -1;
                v100.m_VertexBuilder.m_nBufferOffset = -1;
                v100.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                v100.m_pMesh = nullptr;
                v100.m_bGenerateIndices = false;
                memset(&v100.m_IndexBuilder.m_pIndexBuffer, 0, 12);
                v100.m_IndexBuilder.m_nCurrentIndex = 0;
                v100.m_IndexBuilder.m_nTotalIndexCount = 0;
                v100.m_IndexBuilder.m_nBufferFirstIndex = 0;
                v100.m_VertexBuilder.m_pVertexBuffer = nullptr;
                v100.m_VertexBuilder.m_nBufferFirstVertex = 0;
                memset(&v100.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
                v100.m_VertexBuilder.m_nTotalVertexCount = 0;
                v73 = GetDynamicMesh(
                        this: pRenderContext,
                        a2: false,
                        a3: g_WorldStaticMeshes.m_Memory.m_pMemory[*(_DWORD *)(v70 + 8)],
                        a4: nullptr,
                        a5: nullptr);
                CMeshBuilder::Begin(
                  this: &v100,
                  pMesh: v73,
                  type: MATERIAL_TRIANGLES,
                  nVertexCount: 0,
                  nIndexCount: *(_DWORD *)&v102.m_pMemory[v139],
                  pMeshSettings: nullptr);
                if ( (int)v129 > 0 )
                {
                  v74 = v129;
                  v75 = v131;
                  do
                  {
                    BuildIndicesForSurface(
                      meshBuilder: &v100.m_IndexBuilder,
                      surfID: *(msurface2_t **)&v95.m_pMemory[(_DWORD)v75]);
                    v75 = (S3RGBA *)((char *)v75 + 1);
                    v74 = (CBrushBatchRender::brushrendermesh_t *)((char *)v74 - 1);
                  }
                  while ( v74 != nullptr );
                  v131 = v75;
                }
                if ( v100.m_bGenerateIndices )
                {
                  switch ( v100.m_Type )
                  {
                    case MATERIAL_LINE_STRIP:
                      v76 = 2 * v100.m_VertexBuilder.m_nVertexCount - 2;
                      break;
                    case MATERIAL_LINE_LOOP:
                      v76 = 2 * v100.m_VertexBuilder.m_nVertexCount;
                      break;
                    case MATERIAL_POLYGON:
                      v76 = 3 * v100.m_VertexBuilder.m_nVertexCount - 6;
                      break;
                    case MATERIAL_QUADS:
                      v76 = 6 * v100.m_VertexBuilder.m_nVertexCount / 4;
                      break;
                    case MATERIAL_INSTANCED_QUADS:
                      v76 = 0;
                      break;
                    default:
                      v76 = v100.m_VertexBuilder.m_nVertexCount;
                      break;
                  }
                  CIndexBuilder::GenerateIndices(
                    this: &v100.m_IndexBuilder,
                    primitiveType: v100.m_Type,
                    nIndexCount: v76);
                }
                v100.m_pMesh->UnlockMesh(
                  this: v100.m_pMesh,
                  a2: v100.m_VertexBuilder.m_nVertexCount,
                  a3: v100.m_IndexBuilder.m_nIndexCount,
                  a4: &v100);
                v100.m_IndexBuilder.m_pIndexBuffer = nullptr;
                v100.m_IndexBuilder.m_nMaxIndexCount = 0;
                v100.m_VertexBuilder.m_nMaxVertexCount = 0;
                v100.m_VertexBuilder.m_pVertexBuffer = nullptr;
                v100.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                v100.m_pMesh->Draw_2(this: v100.m_pMesh, a2: -1, a3: 0);
                v100.m_pMesh = nullptr;
                if ( v100.m_VertexBuilder.m_pVertexBuffer != nullptr
                  && v100.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v100.m_VertexBuilder.m_pVertexBuffer) )
                {
                  v100.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v100.m_VertexBuilder.m_pVertexBuffer);
                }
                if ( v100.m_IndexBuilder.m_pIndexBuffer != nullptr
                  && v100.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v100.m_IndexBuilder.m_pIndexBuffer) )
                {
                  v100.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v100.m_IndexBuilder.m_pIndexBuffer);
                }
                v68 = (CBrushBatchRender::brushrendermesh_t *)v130;
              }
              v77 = v68->batchCount;
              ++v139;
              v69 = v126 + 1;
              v126 = v69;
            }
            while ( v69 < v77 );
            v67 = i;
          }
        }
        ((void (__thiscall *)(IMatRenderContext *, _DWORD))pRenderContext->__vftable[1].EndRender)(
          a1: pRenderContext,
          a2: 0);
      }
      if ( g_ShaderDebug.anydebug )
      {
        for ( j = 0; j < v132->meshCount; ++j )
        {
          v78 = 0;
          v79 = &v132->pMeshes[j];
          v80 = nullptr;
          v81 = nullptr;
          v121 = v79;
          memset(&v118, 0, sizeof(v118));
          v119 = 0;
          v120 = nullptr;
          v137 = nullptr;
          if ( v79->batchCount > 0 )
          {
            do
            {
              v82 = &v132->pBatches[(int)v81 + v79->firstBatch];
              v83 = 0;
              v124 = (int)v82;
              v140 = 0;
              if ( v82->surfaceCount > 0 )
              {
                do
                {
                  v84 = &v132->pSurfaces[v83 + v82->firstSurface];
                  if ( v94[v84->planeIndex - 1] == 0 )
                  {
                    v85 = v117 + 32 * v84->surfaceIndex;
                    v86 = v78;
                    if ( v78 + 1 > v118.m_nAllocationCount )
                    {
                      CUtlMemory<INetMessage *,int>::Grow(this: &v118, num: v78 - v118.m_nAllocationCount + 1);
                      v78 = v119;
                    }
                    v119 = ++v78;
                    v120 = v118.m_pMemory;
                    if ( v78 - v86 - 1 > 0 )
                      _V_memmove(dest: &v118.m_pMemory[v86 + 1], src: &v118.m_pMemory[v86], count: 4 * (v78 - v86 - 1));
                    v87 = &v118.m_pMemory[v86];
                    if ( v87 != nullptr )
                      *v87 = (S3RGBA)v85;
                  }
                  v82 = (CBrushBatchRender::brushrenderbatch_t *)v124;
                  v83 = v140 + 1;
                  v140 = v83;
                }
                while ( v83 < *(__int16 *)(v124 + 2) );
                v81 = v137;
                v79 = v121;
              }
              v81 = (model_t *)((char *)v81 + 1);
              v137 = v81;
            }
            while ( (int)v81 < v79->batchCount );
            v80 = (msurface2_t **)v118.m_pMemory;
          }
          DrawDebugInformation(pRenderContext, pList: v80, listCount: v78);
          if ( v118.m_nGrowSize >= 0 && v80 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v80);
        }
      }
      v88 = v102.m_pMemory;
      v105 = 0;
      if ( v102.m_nGrowSize >= 0 )
      {
        if ( v102.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v102.m_pMemory);
          v88 = nullptr;
          v102.m_pMemory = nullptr;
        }
        v102.m_nAllocationCount = 0;
      }
      v106 = v88;
      if ( v102.m_nGrowSize >= 0 )
      {
        if ( v88 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v88);
          v102.m_pMemory = nullptr;
        }
        v102.m_nAllocationCount = 0;
      }
      v89 = v111.m_pMemory;
      v114 = nullptr;
      if ( v111.m_nGrowSize >= 0 )
      {
        if ( v111.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v111.m_pMemory);
          v89 = nullptr;
          v111.m_pMemory = nullptr;
        }
        v111.m_nAllocationCount = 0;
      }
      m_pMemory = v89;
      if ( v111.m_nGrowSize >= 0 )
      {
        if ( v89 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v89);
          v111.m_pMemory = nullptr;
        }
        v111.m_nAllocationCount = 0;
      }
      v90 = v95.m_pMemory;
      v98 = nullptr;
      if ( v95.m_nGrowSize >= 0 )
      {
        if ( v95.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v95.m_pMemory);
          v90 = nullptr;
          v95.m_pMemory = nullptr;
        }
        v95.m_nAllocationCount = 0;
      }
      v99 = v90;
      if ( v95.m_nGrowSize >= 0 && v90 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v90);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100675B0
// Name: public: void CBrushBatchRender::DrawTranslucentBrushModel(class IMatRenderContext __near *,class IClientEntity __near *,struct model_t __near *,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawTranslucentBrushModel(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        IClientEntity *baseentity,
        model_t *model,
        bool bShadowDepth,
        bool bDrawOpaque,
        bool bDrawTranslucent)
{
  if ( bDrawOpaque )
    CBrushBatchRender::DrawOpaqueBrushModel(
      this,
      a2: (CMeshBuilder *)model,
      pRenderContext,
      baseentity,
      model,
      bShadowDepth);
  if ( !bShadowDepth && bDrawTranslucent )
    CBrushBatchRender::DrawTranslucentBrushModel(
      this,
      a2: (CMeshBuilder *)baseentity,
      a3: (int)model,
      pRenderContext,
      model,
      baseentity);
}

//------------------------------------------------------------------------------
// Address: 0x10067600
// Name: public: void CBrushBatchRender::DrawBrushModelShadow(class IMatRenderContext __near *,struct model_t __near *,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBrushBatchRender::DrawBrushModelShadow(
        CBrushBatchRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        IMatRenderContext *pRenderContext,
        model_t *model,
        IClientRenderable *pRenderable)
{
  model_t *v6; // ebx
  int v7; // esi
  IMesh *v8; // edi
  bool v9; // cc
  unsigned int m_nCurrentIndex; // eax
  IMatRenderContext *v11; // edi
  int v12; // edx
  int v13; // ecx
  __int16 m_nCurrentVertex; // si
  int v15; // edi
  float *m_pCurrPosition; // ecx
  float *v17; // eax
  float *v18; // eax
  int v19; // ecx
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1F4h] BYREF
  IMesh *pMesh; // [esp+1ECh] [ebp-Ch]
  int vertCount; // [esp+1F0h] [ebp-8h]
  int i; // [esp+1F4h] [ebp-4h]
  IMatRenderContext *pRenderContexta; // [esp+200h] [ebp+8h]
  IClientRenderable *pRenderablea; // [esp+208h] [ebp+10h]

  v6 = model;
  i = (int)CBrushBatchRender::FindOrCreateRenderBatch(this, pModel: model);
  if ( i != 0 )
  {
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, IClientRenderable *, int, int))pRenderContext->Bind)(
      a1: pRenderContext,
      a2: g_pMaterialShadowBuild,
      a3: pRenderable,
      a4: a2,
      a5: a3);
    v7 = *(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface;
    v8 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
    pMesh = v8;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v8,
      type: MATERIAL_TRIANGLES,
      nVertexCount: *(__int16 *)(i + 26),
      nIndexCount: *(__int16 *)(i + 24),
      pMeshSettings: nullptr);
    v9 = model->brush.nummodelsurfaces <= 0;
    i = 0;
    if ( !v9 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      v11 = (IMatRenderContext *)(v7 + 3);
      pRenderContexta = (IMatRenderContext *)(v7 + 3);
      do
      {
        if ( (BYTE1(v11[-1].__vftable) & 0x20) == 0 )
        {
          v12 = LOBYTE(v11->__vftable);
          v13 = *(int *)((char *)&v11[1].__vftable + 1);
          m_nCurrentVertex = meshBuilder.m_VertexBuilder.m_nCurrentVertex;
          vertCount = v12;
          if ( v12 != 0 )
          {
            v15 = 2 * v13;
            for ( pRenderablea = (IClientRenderable *)v12;
                  pRenderablea != nullptr;
                  pRenderablea = (IClientRenderable *)((char *)pRenderablea - 1) )
            {
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              v17 = (float *)(*(_DWORD *)(v6->sprite.numframes + 36)
                            + 12 * *(unsigned __int16 *)(*(_DWORD *)(v6->sprite.numframes + 148) + v15));
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = *v17;
              m_pCurrPosition[1] = v17[1];
              m_pCurrPosition[2] = v17[2];
              v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
              v18[1] = 0.0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v15 += 2;
            }
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            v11 = pRenderContexta;
            v12 = vertCount;
          }
          v19 = 0;
          if ( v12 - 2 > 0 )
          {
            do
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = m_nCurrentVertex
                                                                     + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
              meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
              meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = v19
                                                                                                + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                                + m_nCurrentVertex
                                                                                                + 1;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
              meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                                + v19
                                                                                                + m_nCurrentVertex
                                                                                                + 2;
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              ++v19;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
            while ( v19 < v12 - 2 );
            v6 = model;
            v11 = pRenderContexta;
          }
        }
        v11 += 8;
        ++i;
        pRenderContexta = v11;
      }
      while ( i < v6->brush.nummodelsurfaces );
      v8 = pMesh;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v8->Draw_2(this: v8, a2: -1, a3: 0);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067900
// Name: private: void CBrushBatchRender::BuildBatchListToDraw(int,struct BrushArrayInstanceData_t const __near *,class CUtlVectorFixedGrowable<struct CBrushBatchRender::BrushBatchRenderData_t,1024> __near &,struct CBrushBatchRender::brushrender_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::BuildBatchListToDraw(
        CBrushBatchRender *this,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> *batchesToRender,
        CBrushBatchRender::brushrender_t **ppBrushRender)
{
  int v5; // esi
  const BrushArrayInstanceData_t *v6; // ebx
  CBrushBatchRender::brushrender_t *RenderBatch; // ecx
  int v9; // edx
  CBrushBatchRender::brushrendermesh_t *pMeshes; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  int v13; // ebx
  CBrushBatchRender::BrushBatchRenderData_t *m_pMemory; // edx
  int v15; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v16; // eax
  IMaterial *v17; // edx
  CBrushBatchRender::brushrendermesh_t *mesh; // [esp+4h] [ebp-20h]
  unsigned __int8 *v19; // [esp+8h] [ebp-1Ch]
  int count; // [esp+Ch] [ebp-18h]
  const BrushArrayInstanceData_t *v21; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  int m; // [esp+18h] [ebp-Ch]
  int j; // [esp+1Ch] [ebp-8h]
  CBrushBatchRender::brushrender_t *pRender; // [esp+20h] [ebp-4h]
  int nBatchIndex; // [esp+30h] [ebp+Ch]
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> *batchesToRendera; // [esp+34h] [ebp+10h]

  v5 = 0;
  i = 0;
  if ( nCount > 0 )
  {
    v6 = pInstanceData;
    v21 = pInstanceData;
    do
    {
      RenderBatch = CBrushBatchRender::FindOrCreateRenderBatch(
                      this: &g_BrushBatchRenderer,
                      pModel: (model_t *)v6->m_pBrushModel);
      pRender = RenderBatch;
      ppBrushRender[v5] = RenderBatch;
      if ( RenderBatch != nullptr )
      {
        v9 = 0;
        m = 0;
        if ( RenderBatch->meshCount > 0 )
        {
          do
          {
            pMeshes = RenderBatch->pMeshes;
            nBatchIndex = pMeshes[v9].firstBatch;
            mesh = &pMeshes[v9];
            j = 0;
            if ( mesh->batchCount > 0 )
            {
              batchesToRendera = (CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> *)(16 * nBatchIndex);
              do
              {
                m_Size = batchesToRender->m_Size;
                m_nAllocationCount = batchesToRender->m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                {
                  v13 = m_Size - m_nAllocationCount + 1;
                  if ( batchesToRender->m_Memory.m_nGrowSize < 0 )
                  {
                    batchesToRender->m_Memory.m_nGrowSize = batchesToRender->m_Memory.m_nMallocGrowSize;
                    if ( m_nAllocationCount != 0 )
                    {
                      count = 16 * m_nAllocationCount;
                      v19 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nAllocationCount);
                      memcpy(dst: v19, src: (unsigned __int8 *)batchesToRender->m_Memory.m_pMemory, count);
                      batchesToRender->m_Memory.m_pMemory = (CBrushBatchRender::BrushBatchRenderData_t *)v19;
                    }
                    else
                    {
                      batchesToRender->m_Memory.m_pMemory = nullptr;
                    }
                  }
                  CUtlMemory<CPortalRect,int>::Grow(
                    this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)batchesToRender,
                    num: v13);
                  v6 = v21;
                  RenderBatch = pRender;
                }
                ++batchesToRender->m_Size;
                m_pMemory = batchesToRender->m_Memory.m_pMemory;
                v15 = batchesToRender->m_Size - m_Size - 1;
                batchesToRender->m_pElements = batchesToRender->m_Memory.m_pMemory;
                if ( v15 > 0 )
                {
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v15);
                  RenderBatch = pRender;
                }
                v16 = &batchesToRender->m_Memory.m_pMemory[m_Size];
                v17 = *(IMaterial **)((char *)&RenderBatch->pBatches->pMaterial + (unsigned int)batchesToRendera);
                batchesToRendera = (CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> *)((char *)batchesToRendera + 16);
                v16->m_pMaterial = v17;
                LOWORD(v17) = nBatchIndex ^ *((_WORD *)v16 + 6);
                LOWORD(nBatchIndex) = nBatchIndex + 1;
                *((_WORD *)v16 + 6) ^= (unsigned __int16)v17 & 0x7FFF;
                v16->m_pInstanceData = v6;
                v16->m_pBrushRender = RenderBatch;
                ++j;
              }
              while ( j < mesh->batchCount );
              v9 = m;
            }
            m = ++v9;
          }
          while ( v9 < RenderBatch->meshCount );
          v5 = i;
        }
      }
      ++v5;
      ++v6;
      i = v5;
      v21 = v6;
    }
    while ( v5 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067AA0
// Name: public: void CBrushBatchRender::DrawBrushModelArray(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawBrushModelArray(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData)
{
  void *v5; // esp
  CBrushBatchRender::BrushBatchRenderData_t *m_pMemory; // edi
  int m_Size; // ebx
  CBrushBatchRender::BrushBatchRenderData_t *v8; // ebx
  CBrushBatchRender::brushrender_t *v10[3]; // [esp+0h] [ebp-6044h] BYREF
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> batchesToRender; // [esp+Ch] [ebp-6038h] BYREF
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512> instanceGroups; // [esp+4024h] [ebp-2020h] BYREF
  CBrushBatchRender::brushrender_t **ppBrushRender; // [esp+603Ch] [ebp-8h]
  int v14; // [esp+6040h] [ebp-4h]
  IMatRenderContext *pRenderContexta; // [esp+604Ch] [ebp+8h]

  v5 = alloca(4 * nCount);
  batchesToRender.m_Memory.m_pMemory = batchesToRender.m_Memory.m_pFixedMemory;
  ppBrushRender = v10;
  batchesToRender.m_Memory.m_nMallocGrowSize = 0;
  batchesToRender.m_Size = 0;
  batchesToRender.m_Memory.m_nAllocationCount = 1024;
  batchesToRender.m_Memory.m_nGrowSize = -1;
  batchesToRender.m_pElements = batchesToRender.m_Memory.m_pFixedMemory;
  CBrushBatchRender::BuildBatchListToDraw(this, nCount, pInstanceData, &batchesToRender, ppBrushRender: v10);
  m_pMemory = batchesToRender.m_Memory.m_pMemory;
  m_Size = batchesToRender.m_Size;
  v14 = batchesToRender.m_Size;
  CBrushBatchRender::ComputeLightmapPages(
    this,
    nCount: batchesToRender.m_Size,
    pRenderData: batchesToRender.m_Memory.m_pMemory);
  v8 = &m_pMemory[m_Size];
  if ( (int)(((char *)v8 - (char *)m_pMemory) & 0xFFFFFFF0) > 16 )
    std::_Make_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
      _First: m_pMemory,
      _Last: v8,
      _Pred: CBrushBatchRender::BatchSortLessFunc,
      __formal: nullptr,
      __formal: nullptr);
  std::_Sort_heap<CBrushBatchRender::BrushBatchRenderData_t *,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
    _First: m_pMemory,
    _Last: v8,
    _Pred: CBrushBatchRender::BatchSortLessFunc);
  instanceGroups.m_Memory.m_pMemory = instanceGroups.m_Memory.m_pFixedMemory;
  instanceGroups.m_Memory.m_nMallocGrowSize = 0;
  instanceGroups.m_Size = 0;
  instanceGroups.m_pElements = instanceGroups.m_Memory.m_pFixedMemory;
  instanceGroups.m_Memory.m_nAllocationCount = 512;
  instanceGroups.m_Memory.m_nGrowSize = -1;
  pRenderContexta = (IMatRenderContext *)CBrushBatchRender::ComputeInstanceGroups(
                                           this,
                                           pRenderContext,
                                           nCount: (CBrushBatchRender::BrushBatchRenderData_t *)v14,
                                           pRenderData: m_pMemory,
                                           &instanceGroups);
  if ( CBrushBatchRender::DrawSortedBatchList(
         this,
         pRenderContext,
         nCount: instanceGroups.m_Size,
         pInstanceGroup: instanceGroups.m_Memory.m_pMemory,
         nMaxInstanceCount: (int)pRenderContexta) != 0 )
    CBrushBatchRender::DrawPaintForBatches(
      this,
      pRenderContext,
      nCount: instanceGroups.m_Size,
      pInstanceGroup: instanceGroups.m_Memory.m_pMemory,
      nMaxInstanceCount: (int)pRenderContexta);
  CBrushBatchRender::DrawDecalsForBatches(this, pRenderContext, nCount, pInstanceData, ppBrushRender);
  CBrushBatchRender::DrawArrayDebugInformation(this, pRenderContext, nCount: v14, pRenderData: m_pMemory);
  CUtlVector<CBrushBatchRender::BrushInstanceGroup_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>>::~CUtlVector<CBrushBatchRender::BrushInstanceGroup_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>>(this: &instanceGroups);
  CUtlVector<CBrushBatchRender::BrushBatchRenderData_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024,int>>::~CUtlVector<CBrushBatchRender::BrushBatchRenderData_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024,int>>(this: &batchesToRender);
}

//------------------------------------------------------------------------------
// Address: 0x10067C30
// Name: private: void CBrushBatchRender::BuildShadowBatchListToDraw(int,struct BrushArrayInstanceData_t const __near *,class CUtlVectorFixedGrowable<struct CBrushBatchRender::BrushBatchRenderData_t,1024> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::BuildShadowBatchListToDraw(
        CBrushBatchRender *this,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        CBrushBatchRender::brushrender_t *batchesToRender)
{
  CBrushBatchRender::brushrender_t *RenderBatch; // eax
  int v7; // esi
  CBrushBatchRender::brushrendermesh_t *pMeshes; // edx
  int v9; // ecx
  char *v10; // esi
  int v11; // ebx
  unsigned __int8 v12; // al
  int v13; // esi
  IMaterial *v14; // ecx
  int v15; // eax
  int v16; // ecx
  CBrushBatchRender::BrushBatchRenderData_t *pPlanes; // ecx
  int v18; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v19; // eax
  __int16 v20; // dx
  CBrushBatchRender::brushrendermesh_t *mesh; // [esp+0h] [ebp-24h]
  IMaterial *pDepthWriteMaterial; // [esp+4h] [ebp-20h]
  int v23; // [esp+8h] [ebp-1Ch]
  unsigned __int8 *v24; // [esp+Ch] [ebp-18h]
  int count; // [esp+10h] [ebp-14h]
  int v26; // [esp+14h] [ebp-10h]
  int m; // [esp+18h] [ebp-Ch]
  int nBatchIndex; // [esp+1Ch] [ebp-8h]
  int j; // [esp+20h] [ebp-4h]
  const BrushArrayInstanceData_t *pInstanceDataa; // [esp+30h] [ebp+Ch]
  CBrushBatchRender::brushrender_t *pRender; // [esp+34h] [ebp+10h]

  if ( nCount > 0 )
  {
    v26 = nCount;
    do
    {
      RenderBatch = CBrushBatchRender::FindOrCreateRenderBatch(
                      this: &g_BrushBatchRenderer,
                      pModel: (model_t *)pInstanceData->m_pBrushModel);
      pRender = RenderBatch;
      if ( RenderBatch != nullptr )
      {
        v7 = 0;
        for ( m = 0; v7 < RenderBatch->meshCount; m = ++v7 )
        {
          pMeshes = RenderBatch->pMeshes;
          mesh = &pMeshes[v7];
          nBatchIndex = mesh->firstBatch;
          j = 0;
          if ( mesh->batchCount > 0 )
          {
            v9 = 16 * pMeshes[v7].firstBatch;
            for ( pInstanceDataa = (const BrushArrayInstanceData_t *)v9; ; v9 = (int)pInstanceDataa )
            {
              v10 = (char *)RenderBatch->pBatches + v9;
              v11 = (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 1) + 72))(a1: *((_DWORD *)v10 + 1));
              v12 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 1) + 132))(a1: *((_DWORD *)v10 + 1));
              v13 = *(_DWORD *)&batchesToRender[585].batchCount;
              v14 = g_pMaterialDepthWrite[v11][v12];
              v15 = (int)batchesToRender->pMeshes;
              pDepthWriteMaterial = v14;
              if ( v13 + 1 > v15 )
              {
                v16 = v13 - v15 + 1;
                v23 = v16;
                if ( (int)batchesToRender->pBatches < 0 )
                {
                  batchesToRender->pBatches = (CBrushBatchRender::brushrenderbatch_t *)batchesToRender->pSurfaces;
                  if ( v15 != 0 )
                  {
                    count = 16 * v15;
                    v24 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * v15);
                    memcpy(dst: v24, src: (unsigned __int8 *)batchesToRender->pPlanes, count);
                    v16 = v23;
                    batchesToRender->pPlanes = (cplane_t **)v24;
                  }
                  else
                  {
                    batchesToRender->pPlanes = nullptr;
                  }
                }
                CUtlMemory<CPortalRect,int>::Grow(
                  this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)batchesToRender,
                  num: v16);
              }
              ++*(_DWORD *)&batchesToRender[585].batchCount;
              pPlanes = (CBrushBatchRender::BrushBatchRenderData_t *)batchesToRender->pPlanes;
              v18 = *(_DWORD *)&batchesToRender[585].batchCount - v13 - 1;
              *(_DWORD *)&batchesToRender[585].totalIndexCount = batchesToRender->pPlanes;
              if ( v18 > 0 )
                _V_memmove(dest: &pPlanes[v13 + 1], src: &pPlanes[v13], count: 16 * v18);
              pInstanceDataa = (const BrushArrayInstanceData_t *)((char *)pInstanceDataa + 16);
              v19 = (CBrushBatchRender::BrushBatchRenderData_t *)&batchesToRender->pPlanes[4 * v13];
              v19->m_pBrushRender = pRender;
              v20 = *((_WORD *)v19 + 6);
              v19->m_pInstanceData = pInstanceData;
              *((_WORD *)v19 + 6) ^= (nBatchIndex ^ v20) & 0x7FFF;
              *((_WORD *)v19 + 7) = ((_WORD)v11 << 15) | *((_WORD *)v19 + 7) & 0x7FFF;
              v19->m_pMaterial = pDepthWriteMaterial;
              ++nBatchIndex;
              ++j;
              RenderBatch = pRender;
              if ( j >= mesh->batchCount )
                break;
            }
            v7 = m;
          }
        }
      }
      ++pInstanceData;
      --v26;
    }
    while ( v26 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067E10
// Name: public: void CBrushBatchRender::DrawBrushModelShadowArray(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawBrushModelShadowArray(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData)
{
  CBrushBatchRender::BrushBatchRenderData_t *m_pMemory; // edi
  int m_Size; // ebx
  int v7; // eax
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> batchesToRender; // [esp+Ch] [ebp-6030h] BYREF
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512> instanceGroups; // [esp+4024h] [ebp-2018h] BYREF
  BrushArrayInstanceData_t *pInstanceDataa; // [esp+604Ch] [ebp+10h]

  batchesToRender.m_Memory.m_pMemory = batchesToRender.m_Memory.m_pFixedMemory;
  batchesToRender.m_Memory.m_nMallocGrowSize = 0;
  batchesToRender.m_Size = 0;
  batchesToRender.m_pElements = batchesToRender.m_Memory.m_pFixedMemory;
  batchesToRender.m_Memory.m_nAllocationCount = 1024;
  batchesToRender.m_Memory.m_nGrowSize = -1;
  CBrushBatchRender::BuildShadowBatchListToDraw(
    this,
    nCount,
    pInstanceData,
    (CBrushBatchRender::brushrender_t *)&batchesToRender);
  m_pMemory = batchesToRender.m_Memory.m_pMemory;
  pInstanceDataa = (BrushArrayInstanceData_t *)batchesToRender.m_Size;
  m_Size = batchesToRender.m_Size;
  if ( 16 * batchesToRender.m_Size > 16 )
    std::_Make_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
      _First: batchesToRender.m_Memory.m_pMemory,
      _Last: &batchesToRender.m_Memory.m_pMemory[batchesToRender.m_Size],
      _Pred: CBrushBatchRender::ShadowSortLessFunc,
      __formal: nullptr,
      __formal: nullptr);
  std::_Sort_heap<CBrushBatchRender::BrushBatchRenderData_t *,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
    _First: m_pMemory,
    _Last: &m_pMemory[m_Size],
    _Pred: CBrushBatchRender::ShadowSortLessFunc);
  instanceGroups.m_Memory.m_pMemory = instanceGroups.m_Memory.m_pFixedMemory;
  instanceGroups.m_Memory.m_nMallocGrowSize = 0;
  instanceGroups.m_Size = 0;
  instanceGroups.m_pElements = instanceGroups.m_Memory.m_pFixedMemory;
  instanceGroups.m_Memory.m_nAllocationCount = 512;
  instanceGroups.m_Memory.m_nGrowSize = -1;
  v7 = CBrushBatchRender::ComputeInstanceGroups(
         this,
         pRenderContext,
         nCount: (CBrushBatchRender::BrushBatchRenderData_t *)pInstanceDataa,
         pRenderData: m_pMemory,
         &instanceGroups);
  CBrushBatchRender::DrawShadowBatchList(
    this,
    pRenderContext,
    nCount: instanceGroups.m_Size,
    pInstanceGroup: instanceGroups.m_Memory.m_pMemory,
    nMaxInstanceCount: v7);
  CUtlVector<CBrushBatchRender::BrushInstanceGroup_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>>::~CUtlVector<CBrushBatchRender::BrushInstanceGroup_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>>(this: &instanceGroups);
  CUtlVector<CBrushBatchRender::BrushBatchRenderData_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024,int>>::~CUtlVector<CBrushBatchRender::BrushBatchRenderData_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024,int>>(this: &batchesToRender);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10063280
// Name: private: void CBrushBatchRender::ClearRenderHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::ClearRenderHandles(CBrushBatchRender *this)
{
  int i; // esi
  model_t *v2; // eax
  char szBrushModel[8]; // [esp+4h] [ebp-8h] BYREF

  for ( i = 1; i < host_state.worldbrush->numsubmodels; ++i )
  {
    V_snprintf(pDest: szBrushModel, maxLen: 5, pFormat: "*%i", i);
    v2 = modelloader->GetModelForName(this: modelloader, a2: szBrushModel, a3: 2);
    if ( v2 != nullptr )
      v2->brush.renderHandle = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100632E0
// Name: private: static bool CBrushBatchRender::BatchSortLessFunc(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBrushBatchRender::BatchSortLessFunc(
        const CBrushBatchRender::BrushBatchRenderData_t *left,
        const CBrushBatchRender::BrushBatchRenderData_t *right)
{
  IMaterial *m_pMaterial; // ebx
  IMaterial *v3; // edi
  bool v4; // cf
  int sortID; // eax
  int v7; // ecx
  ShaderStencilState_t *m_pStencilState; // eax
  ShaderStencilState_t *v9; // ecx
  matrix3x4a_t *m_pBrushToWorld; // edx
  matrix3x4a_t *v11; // esi

  m_pMaterial = right->m_pMaterial;
  v3 = left->m_pMaterial;
  v4 = v3 < m_pMaterial;
  if ( v3 != m_pMaterial )
    return v4;
  sortID = left->m_pBrushRender->pBatches[*((_WORD *)left + 6) & 0x7FFF].sortID;
  v7 = right->m_pBrushRender->pBatches[*((_WORD *)right + 6) & 0x7FFF].sortID;
  if ( sortID != v7 )
    return sortID < v7;
  m_pStencilState = left->m_pInstanceData->m_pStencilState;
  v9 = right->m_pInstanceData->m_pStencilState;
  v4 = m_pStencilState < v9;
  if ( m_pStencilState != v9 )
    return v4;
  m_pBrushToWorld = left->m_pInstanceData->m_pBrushToWorld;
  v11 = right->m_pInstanceData->m_pBrushToWorld;
  v4 = m_pBrushToWorld < v11;
  if ( m_pBrushToWorld != v11 )
    return v4;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10063360
// Name: private: void CBrushBatchRender::ComputeLightmapPages(int,struct CBrushBatchRender::BrushBatchRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::ComputeLightmapPages(
        CBrushBatchRender *this,
        int nCount,
        CBrushBatchRender::BrushBatchRenderData_t *pRenderData)
{
  int v3; // ecx
  _WORD *v4; // eax
  _WORD *v5; // eax

  v3 = nCount;
  if ( g_pMaterialSystemConfig->nFullbright == 1 )
  {
    if ( nCount > 0 )
    {
      v5 = (_WORD *)pRenderData + 7;
      do
      {
        *v5 = *v5 & 0x8000 | 0x7FFE;
        v5 += 8;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  else if ( nCount > 0 )
  {
    v4 = (_WORD *)pRenderData + 7;
    do
    {
      *v4 ^= (*v4
            ^ LOWORD(materialSortInfoArray[*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 - 3) + 8)
                                                     + 16 * (*(v4 - 1) & 0x7FFF)
                                                     + 8)].lightmapPageID))
           & 0x7FFF;
      v4 += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100633F0
// Name: private: static bool CBrushBatchRender::ShadowSortLessFunc(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CBrushBatchRender::ShadowSortLessFunc(
        const CBrushBatchRender::BrushBatchRenderData_t *left,
        const CBrushBatchRender::BrushBatchRenderData_t *right)
{
  IMaterial *m_pMaterial; // eax
  IMaterial *v3; // ecx
  bool v4; // cf
  bool result; // al
  matrix3x4a_t *m_pBrushToWorld; // eax
  matrix3x4a_t *v7; // ecx

  m_pMaterial = left->m_pMaterial;
  v3 = right->m_pMaterial;
  v4 = m_pMaterial < v3;
  result = (m_pMaterial != v3
         || (m_pBrushToWorld = left->m_pInstanceData->m_pBrushToWorld,
             v7 = right->m_pInstanceData->m_pBrushToWorld,
             v4 = m_pBrushToWorld < v7,
             m_pBrushToWorld != v7))
        && v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063420
// Name: void std::_Push_heap<struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)>(struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,int,struct CBrushBatchRender::BrushBatchRenderData_t __near &&,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        CBrushBatchRender::BrushBatchRenderData_t *_First,
        int _Hole,
        int _Top,
        CBrushBatchRender::BrushBatchRenderData_t *_Val,
        bool (__cdecl *_Pred)(const CBrushBatchRender::BrushBatchRenderData_t *, const CBrushBatchRender::BrushBatchRenderData_t *))
{
  int v5; // ebx
  int i; // edi
  CBrushBatchRender::BrushBatchRenderData_t *v7; // esi
  CBrushBatchRender::BrushBatchRenderData_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    v8->m_pInstanceData = v7->m_pInstanceData;
    v8->m_pMaterial = v7->m_pMaterial;
    v8->m_pBrushRender = v7->m_pBrushRender;
    *((_DWORD *)v8 + 3) = *((_DWORD *)v7 + 3);
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x100634B0
// Name: public: void Vector4D::Init(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector4D::Init(Vector4D *this, float ix, float iy, float iz, float iw)
{
  this->x = ix;
  this->y = iy;
  this->z = iz;
  this->w = iw;
}

//------------------------------------------------------------------------------
// Address: 0x100634E0
// Name: public: void CVertexBuilder::AttachBegin(class IMesh __near *,int,struct MeshDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AttachBegin(
        CVertexBuilder *this,
        IMesh *pMesh,
        int nMaxVertexCount,
        const MeshDesc_t *desc)
{
  bool v4; // zf

  this->m_pVertexBuffer = pMesh;
  this->VertexDesc_t = desc->VertexDesc_t;
  this->m_nMaxVertexCount = nMaxVertexCount;
  this->m_NumBoneWeights = this->m_NumBoneWeights != 0 ? 2 : 0;
  v4 = this->m_nBufferOffset == -1;
  this->m_nVertexCount = 0;
  this->m_bModify = false;
  if ( v4 )
  {
    this->m_nTotalVertexCount = 0;
    this->m_nBufferOffset = desc->VertexDesc_t::m_nOffset;
    this->m_nBufferFirstVertex = desc->m_nFirstVertex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063550
// Name: public: void CVertexBuilder::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::Reset(CVertexBuilder *this)
{
  float *m_pNormal; // edx
  float *v2; // edx
  float *v3; // eax
  float *v4; // edx
  float *v5; // eax
  float *v6; // edx
  float *v7; // eax
  float *v8; // edx

  m_pNormal = this->m_pNormal;
  this->m_pCurrPosition = this->m_pPosition;
  this->m_nCurrentVertex = 0;
  this->m_pCurrNormal = m_pNormal;
  v2 = this->m_pTexCoord[1];
  this->m_pCurrTexCoord[0] = this->m_pTexCoord[0];
  v3 = this->m_pTexCoord[2];
  this->m_pCurrTexCoord[1] = v2;
  v4 = this->m_pTexCoord[3];
  this->m_pCurrTexCoord[2] = v3;
  v5 = this->m_pTexCoord[4];
  this->m_pCurrTexCoord[3] = v4;
  v6 = this->m_pTexCoord[5];
  this->m_pCurrTexCoord[4] = v5;
  v7 = this->m_pTexCoord[6];
  this->m_pCurrTexCoord[5] = v6;
  v8 = this->m_pTexCoord[7];
  this->m_pCurrTexCoord[6] = v7;
  this->m_pCurrTexCoord[7] = v8;
  this->m_pCurrColor = this->m_pColor;
}

//------------------------------------------------------------------------------
// Address: 0x100635D0
// Name: public: void CIndexBuilder::FastPolygon(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::FastPolygon(CIndexBuilder *this, int startVert, int triangleCount)
{
  unsigned int v3; // edi
  unsigned __int16 *v4; // eax
  int v5; // edx
  int v6; // esi
  int m_nCurrentIndex; // eax
  int triangleCounta; // [esp+14h] [ebp+Ch]

  v3 = triangleCount * this->m_nIndexSize;
  v4 = &this->m_pIndices[this->m_nCurrentIndex];
  v5 = this->m_nIndexOffset + startVert;
  v6 = 0;
  for ( triangleCounta = v3; v6 < triangleCounta; v4 += 3 )
  {
    *v4 = v5;
    v4[1] = v6 + v5 + 1;
    v4[2] = v6 + v5 + 2;
    v3 = triangleCounta;
    ++v6;
  }
  this->m_nCurrentIndex += 3 * v3 * this->m_nIndexSize;
  m_nCurrentIndex = this->m_nCurrentIndex;
  if ( m_nCurrentIndex > this->m_nIndexCount )
    this->m_nIndexCount = m_nCurrentIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10063710
// Name: public: CMeshBuilder::~CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::~CMeshBuilder(CMeshBuilder *this)
{
  if ( this->m_VertexBuilder.m_pVertexBuffer != nullptr
    && this->m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: this->m_VertexBuilder.m_pVertexBuffer) )
  {
    this->m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: this->m_VertexBuilder.m_pVertexBuffer);
  }
  if ( this->m_IndexBuilder.m_pIndexBuffer != nullptr
    && this->m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: this->m_IndexBuilder.m_pIndexBuffer) )
  {
    this->m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: this->m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063770
// Name: public: CMeshBuilder::CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBuilder *__thiscall CMeshBuilder::CMeshBuilder(CMeshBuilder *this)
{
  this->m_pMesh = nullptr;
  this->m_bGenerateIndices = false;
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_IndexBuilder.m_nTotalIndexCount = 0;
  this->m_IndexBuilder.m_nBufferFirstIndex = 0;
  this->m_IndexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_nBufferFirstVertex = 0;
  this->m_VertexBuilder.m_nVertexCount = 0;
  this->m_VertexBuilder.m_nCurrentVertex = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_nTotalVertexCount = 0;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100637E0
// Name: private: static int CBrushBatchRender::SurfaceCmp(struct CBrushBatchRender::surfacelist_t const __near *,struct CBrushBatchRender::surfacelist_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CBrushBatchRender::SurfaceCmp(
        const CBrushBatchRender::surfacelist_t *s0,
        const CBrushBatchRender::surfacelist_t *s1)
{
  return s0->surfID->materialSortID - s1->surfID->materialSortID;
}

//------------------------------------------------------------------------------
// Address: 0x10063800
// Name: private: void CBrushBatchRender::AddSurfaceToBatch(struct CBrushBatchRender::transrender_t __near &,struct CBrushBatchRender::transnode_t __near *,struct CBrushBatchRender::transbatch_t __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::AddSurfaceToBatch(
        CBrushBatchRender *this,
        CBrushBatchRender::transrender_t *render,
        CBrushBatchRender::transnode_t *pNode,
        CBrushBatchRender::transbatch_t *pBatch,
        msurface2_t *surfID)
{
  ++pBatch->surfaceCount;
  pBatch->indexCount += 3 * HIBYTE(surfID->flags) - 6;
  render->surfaces[render->surfaceCount++] = surfID;
  if ( surfID->decals != 0xFFFF || surfID->m_ShadowDecals != 0xFFFF )
  {
    ++pNode->decalSurfaceCount;
    render->decalSurfaces[render->decalSurfaceCount++] = surfID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063870
// Name: private: void CBrushBatchRender::AddTransBatch(struct CBrushBatchRender::transrender_t __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::AddTransBatch(
        CBrushBatchRender *this,
        CBrushBatchRender::transrender_t *render,
        msurface2_t *surfID)
{
  CBrushBatchRender::transnode_t *pLastNode; // edx
  int firstBatch; // eax
  __int16 batchCount; // si
  CBrushBatchRender::transbatch_t *v6; // eax
  CBrushBatchRender::transnode_t *v7; // ebx

  pLastNode = render->pLastNode;
  firstBatch = pLastNode->firstBatch;
  batchCount = pLastNode->batchCount;
  pLastNode->batchCount = batchCount + 1;
  LOWORD(pLastNode) = render->surfaceCount;
  v6 = &render->batches[firstBatch + batchCount];
  ++render->batchCount;
  v6->firstSurface = (__int16)pLastNode;
  v6->surfaceCount = 0;
  v6->pMaterial = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
  v6->sortID = surfID->materialSortID;
  v6->indexCount = 0;
  v7 = render->pLastNode;
  render->pLastBatch = v6;
  ++v6->surfaceCount;
  v6->indexCount += 3 * HIBYTE(surfID->flags) - 6;
  render->surfaces[render->surfaceCount++] = surfID;
  if ( surfID->decals != 0xFFFF || surfID->m_ShadowDecals != 0xFFFF )
  {
    ++v7->decalSurfaceCount;
    render->decalSurfaces[render->decalSurfaceCount++] = surfID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063950
// Name: private: void CBrushBatchRender::DrawDecalsForBatches(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *,struct CBrushBatchRender::brushrender_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawDecalsForBatches(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        CBrushBatchRender::brushrender_t **ppBrushRender)
{
  int v5; // esi
  CBrushBatchRender::brushrender_t *v6; // ebx
  int v7; // edi
  int v8; // eax
  msurface2_t *v9; // esi
  int surfaceCount; // ecx
  const model_t **v11; // edi
  CBrushModelTransform pushTransform; // [esp+14h] [ebp-1Ch] BYREF
  int i; // [esp+24h] [ebp-Ch]
  int s; // [esp+28h] [ebp-8h]
  const model_t **p_m_pBrushModel; // [esp+2Ch] [ebp-4h]
  char bEncounteredDecals_3; // [esp+43h] [ebp+13h]

  v5 = 0;
  i = 0;
  if ( nCount > 0 )
  {
    p_m_pBrushModel = &pInstanceData->m_pBrushModel;
    do
    {
      DecalSurfacesInit(bBrushModel: true);
      g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
      v6 = ppBrushRender[v5];
      if ( v6 != nullptr )
      {
        v7 = *(_DWORD *)((*p_m_pBrushModel)->sprite.numframes + 124) + 32 * (*p_m_pBrushModel)->brush.firstmodelsurface;
        v8 = 0;
        bEncounteredDecals_3 = 0;
        s = 0;
        if ( v6->surfaceCount > 0 )
        {
          do
          {
            v9 = (msurface2_t *)(v7 + 32 * v6->pSurfaces[v8].surfaceIndex);
            if ( v9->decals != 0xFFFF )
            {
              bEncounteredDecals_3 = 1;
              DecalSurfaceAdd(surfID: v9, iGroup: 4);
            }
            if ( v9->m_ShadowDecals != 0xFFFF )
            {
              bEncounteredDecals_3 = 1;
              g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: v9->m_ShadowDecals);
            }
            surfaceCount = v6->surfaceCount;
            v8 = s + 1;
            s = v8;
          }
          while ( v8 < surfaceCount );
          if ( bEncounteredDecals_3 != 0 )
          {
            v11 = p_m_pBrushModel;
            CBrushModelTransform::CBrushModelTransform(
              this: &pushTransform,
              matrix: (const matrix3x4a_t *)*(p_m_pBrushModel - 1),
              pRenderContext);
            DecalSurfaceDraw(pRenderContext, renderGroup: 4, flFade: *((float *)v11 + 4));
            ((void (__thiscall *)(IShadowMgrInternal *, IMatRenderContext *, int, _DWORD, _DWORD))g_pShadowMgr->DrawFlashlightDecals)(
              a1: g_pShadowMgr,
              a2: pRenderContext,
              a3: 4,
              a4: 0,
              a5: *((float *)v11 + 4));
            R_DecalFlushDestroyList();
            g_pShadowMgr->RenderProjectedTextures(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
            CBrushModelTransform::~CBrushModelTransform(this: &pushTransform);
          }
        }
      }
      p_m_pBrushModel += 7;
      v5 = i + 1;
      i = v5;
    }
    while ( v5 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063AA0
// Name: void std::_Adjust_heap<struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)>(struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,int,struct CBrushBatchRender::BrushBatchRenderData_t __near &&,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        CBrushBatchRender::BrushBatchRenderData_t *_First,
        int _Hole,
        int _Bottom,
        CBrushBatchRender::BrushBatchRenderData_t *_Val,
        bool (__cdecl *_Pred)(const CBrushBatchRender::BrushBatchRenderData_t *, const CBrushBatchRender::BrushBatchRenderData_t *))
{
  int v5; // edx
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  CBrushBatchRender::BrushBatchRenderData_t *v9; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v10; // ecx
  CBrushBatchRender::BrushBatchRenderData_t *v11; // ecx
  int v12; // ecx
  int v13; // ebx
  CBrushBatchRender::BrushBatchRenderData_t *v14; // esi
  CBrushBatchRender::BrushBatchRenderData_t *v15; // eax
  int _Top; // [esp+Ch] [ebp-4h]
  int _Bottoma; // [esp+20h] [ebp+10h]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  _Top = _Hole;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = &_First[v7];
      v10 = &_First[v6];
      v10->m_pInstanceData = v9->m_pInstanceData;
      v10->m_pMaterial = v9->m_pMaterial;
      _Hole = v7;
      v6 = v7;
      v10->m_pBrushRender = v9->m_pBrushRender;
      v7 = 2 * v7 + 2;
      *((_DWORD *)v10 + 3) = *((_DWORD *)v9 + 3);
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    v11 = &_First[v5 - 1];
    _First[v6] = *v11;
    _Hole = v5 - 1;
    v6 = v5 - 1;
  }
  v12 = v6;
  _Bottoma = v6;
  v13 = (v6 - 1) / 2;
  if ( _Top < _Hole )
  {
    do
    {
      v14 = &_First[v13];
      if ( !_Pred(a1: v14, a2: _Val) )
        break;
      v15 = &_First[_Bottoma];
      v15->m_pInstanceData = v14->m_pInstanceData;
      v15->m_pMaterial = v14->m_pMaterial;
      v15->m_pBrushRender = v14->m_pBrushRender;
      *((_DWORD *)v15 + 3) = *((_DWORD *)v14 + 3);
      _Bottoma = v13;
      v13 = (v13 - 1) / 2;
    }
    while ( _Top < _Bottoma );
    v12 = _Bottoma;
  }
  _First[v12] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10063C30
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x10063D70
// Name: int BuildIndicesForSurface(class CIndexBuilder __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BuildIndicesForSurface(CIndexBuilder *meshBuilder, msurface2_t *surfID)
{
  int v2; // esi
  int vertBufferIndex; // edi
  int v5; // eax
  int v6; // edx
  unsigned __int16 *v7; // edi
  unsigned __int16 *v8; // eax
  int v9; // eax
  int m_nCurrentIndex; // edx
  unsigned __int16 v11; // cx
  unsigned __int16 *m_pIndices; // edi
  unsigned __int16 *v13; // edx
  int v14; // ecx

  v2 = HIBYTE(surfID->flags) - 2;
  vertBufferIndex = surfID->vertBufferIndex;
  if ( HIBYTE(surfID->flags) == 3 )
  {
    m_nCurrentIndex = meshBuilder->m_nCurrentIndex;
    v11 = vertBufferIndex + meshBuilder->m_nIndexOffset;
    m_pIndices = meshBuilder->m_pIndices;
    m_pIndices[m_nCurrentIndex] = v11;
    v13 = &m_pIndices[m_nCurrentIndex];
    v13[1] = ++v11;
    v13[2] = v11 + 1;
    meshBuilder->m_nCurrentIndex += 3 * meshBuilder->m_nIndexSize;
    v14 = meshBuilder->m_nCurrentIndex;
    if ( v14 > meshBuilder->m_nIndexCount )
      meshBuilder->m_nIndexCount = v14;
  }
  else
  {
    if ( HIBYTE(surfID->flags) != 4 )
    {
      CIndexBuilder::FastPolygon(this: meshBuilder, startVert: vertBufferIndex, triangleCount: v2);
      return v2;
    }
    v5 = meshBuilder->m_nCurrentIndex;
    v6 = vertBufferIndex + meshBuilder->m_nIndexOffset;
    v7 = meshBuilder->m_pIndices;
    v7[v5] = v6;
    v8 = &v7[v5];
    LOWORD(v6) = v6 + 1;
    v8[1] = v6;
    LOWORD(v6) = v6 + 1;
    v8[2] = v6;
    v8[3] = v6 - 2;
    v8[4] = v6;
    v8[5] = v6 + 1;
    meshBuilder->m_nCurrentIndex += 6 * meshBuilder->m_nIndexSize;
    v9 = meshBuilder->m_nCurrentIndex;
    if ( v9 > meshBuilder->m_nIndexCount )
    {
      meshBuilder->m_nIndexCount = v9;
      return 2;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10063E20
// Name: private: bool CBrushBatchRender::DrawSortedBatchList(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushInstanceGroup_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBrushBatchRender::DrawSortedBatchList(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroup,
        int nMaxInstanceCount)
{
  IMatRenderContext *v5; // ebx
  void *v6; // esp
  char result; // al
  CBrushBatchRender::BrushInstanceGroup_t *v8; // edi
  IIndexBuffer_vtbl *v9; // edx
  int m_pRenderData_high; // eax
  unsigned int m_nOffset; // eax
  __int16 v12; // ax
  float *p_z; // esi
  IMaterial *v14; // edi
  __int16 *v15; // ebx
  msurface2_t *v16; // ecx
  const char *(__thiscall *GetName)(IMaterial *); // ecx
  int v18; // edx
  int v19; // ecx
  IMesh *v20; // edx
  IIndexBuffer *v21; // ecx
  int v22; // ecx
  void (__thiscall *DrawInstances)(IMatRenderContext *, int, const MeshInstanceData_t *); // eax
  bool v24; // zf
  int v25; // [esp-8h] [ebp-68h]
  int v26; // [esp+0h] [ebp-60h] BYREF
  CIndexBuilder indexBuilder; // [esp+Ch] [ebp-54h] BYREF
  IIndexBuffer *pBuildIndexBuffer; // [esp+40h] [ebp-20h]
  msurface2_t *surfID; // [esp+44h] [ebp-1Ch]
  msurface2_t *firstSurfID; // [esp+48h] [ebp-18h]
  int v31; // [esp+4Ch] [ebp-14h]
  MeshInstanceData_t *pInstance; // [esp+50h] [ebp-10h]
  int j; // [esp+54h] [ebp-Ch]
  unsigned int v34; // [esp+58h] [ebp-8h]
  int nIndexOffset; // [esp+5Ch] [ebp-4h]
  int k; // [esp+6Ch] [ebp+Ch]
  bool k_3; // [esp+6Fh] [ebp+Fh]
  CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroupa; // [esp+70h] [ebp+10h]
  char bHasPaintedSurfaces_3; // [esp+77h] [ebp+17h]

  v5 = pRenderContext;
  pRenderContext->BindLightmapPage(this: pRenderContext, a2: 0);
  v6 = alloca(76 * nMaxInstanceCount);
  result = 0;
  pInstance = (MeshInstanceData_t *)&v26;
  bHasPaintedSurfaces_3 = 0;
  if ( nCount > 0 )
  {
    v8 = (CBrushBatchRender::BrushInstanceGroup_t *)((char *)pInstanceGroup + 12);
    pInstanceGroupa = (CBrushBatchRender::BrushInstanceGroup_t *)((char *)pInstanceGroup + 12);
    v31 = nCount;
    while ( 1 )
    {
      v5->Bind(this: v5, a2: *((IMaterial **)&v8[-1] + 3), a3: nullptr);
      indexBuilder.m_pIndexBuffer = v5->GetDynamicIndexBuffer(this: v5);
      indexBuilder.m_nBufferOffset = -1;
      indexBuilder.m_nBufferFirstIndex = 0;
      indexBuilder.m_nIndexCount = 0;
      indexBuilder.m_nCurrentIndex = 0;
      indexBuilder.m_nMaxIndexCount = 0;
      indexBuilder.m_nTotalIndexCount = 0;
      v9 = indexBuilder.m_pIndexBuffer->__vftable;
      pBuildIndexBuffer = indexBuilder.m_pIndexBuffer;
      if ( v9->IsDynamic(this: indexBuilder.m_pIndexBuffer) )
        indexBuilder.m_pIndexBuffer->BeginCastBuffer(this: indexBuilder.m_pIndexBuffer, a2: MATERIAL_INDEX_FORMAT_16BIT);
      m_pRenderData_high = HIWORD(v8->m_pRenderData);
      indexBuilder.m_bModify = false;
      indexBuilder.m_nMaxIndexCount = m_pRenderData_high;
      memset(&indexBuilder.m_nIndexCount, 0, 16);
      k_3 = indexBuilder.m_nBufferOffset == -1;
      if ( indexBuilder.m_pIndexBuffer->Lock(
             this: indexBuilder.m_pIndexBuffer,
             a2: m_pRenderData_high,
             a3: false,
             a4: &indexBuilder) )
      {
        if ( k_3 )
        {
          m_nOffset = indexBuilder.m_nOffset;
          indexBuilder.m_nBufferOffset = indexBuilder.m_nOffset;
          indexBuilder.m_nBufferFirstIndex = indexBuilder.m_nFirstIndex;
          goto LABEL_8;
        }
      }
      else
      {
        indexBuilder.m_nMaxIndexCount = 0;
      }
      m_nOffset = indexBuilder.m_nBufferOffset;
LABEL_8:
      LOWORD(v8->m_pRenderData) &= ~0x8000u;
      nIndexOffset = m_nOffset >> 1;
      v12 = (int)v8->m_pRenderData & 0x7FFF;
      j = 0;
      if ( v12 != 0 )
      {
        v34 = 0;
        p_z = &pInstance->m_DiffuseModulation.z;
        do
        {
          v14 = &v8[-1].m_pActualMaterial[v34 / 4];
          v15 = (__int16 *)((char *)v14[2].GetPreviewImageProperties + 16 * ((int)v14[3].__vftable & 0x7FFF));
          LOWORD(v14[3].__vftable) &= ~0x8000u;
          v16 = (msurface2_t *)(*(_DWORD *)(*((_DWORD *)v14->GetTextureGroupName + 78) + 124)
                              + 32 * *((_DWORD *)v14->GetTextureGroupName + 79));
          firstSurfID = v16;
          k = 0;
          if ( v15[1] > 0 )
          {
            while ( 1 )
            {
              surfID = &v16[*((__int16 *)v14[2].GetPreviewImage + 2 * k + 2 * *v15)];
              BuildIndicesForSurface(meshBuilder: &indexBuilder, surfID);
              if ( (surfID->flags & 0x200000) != 0 )
              {
                LOWORD(pInstanceGroupa->m_pRenderData) |= 0x8000u;
                LOWORD(v14[3].__vftable) |= 0x8000u;
                bHasPaintedSurfaces_3 = 1;
              }
              if ( ++k >= v15[1] )
                break;
              v16 = firstSurfID;
            }
          }
          *(p_z - 11) = 0.0;
          GetName = v14->GetName;
          v18 = nIndexOffset;
          *(p_z - 10) = 0.0;
          *(p_z - 13) = 0.0;
          *((_DWORD *)p_z - 12) = GetName;
          *((_DWORD *)p_z - 16) = v18;
          *((_DWORD *)p_z - 14) = 1;
          v19 = *((_DWORD *)v15 + 3);
          *(p_z - 5) = 0.0;
          *(p_z - 4) = 0.0;
          *((_DWORD *)p_z - 15) = v19;
          *((_DWORD *)p_z - 9) = 2;
          *(p_z - 3) = *(float *)&v14->GetNumAnimationFrames;
          v20 = g_WorldStaticMeshes.m_Memory.m_pMemory[*((_DWORD *)v15 + 2)];
          v21 = pBuildIndexBuffer;
          *(p_z - 7) = 0.0;
          v34 += 16;
          *((_DWORD *)p_z - 8) = v20;
          *((_DWORD *)p_z - 6) = v21;
          *(p_z - 2) = 1.0;
          *(p_z - 1) = 1.0;
          *p_z = 1.0;
          p_z[1] = 1.0;
          *((_DWORD *)p_z + 2) = (__int16)(2 * HIWORD(v14[3].__vftable)) >> 1;
          nIndexOffset += *((_DWORD *)v15 + 3);
          v22 = (int)pInstanceGroupa->m_pRenderData & 0x7FFF;
          p_z += 19;
          ++j;
          v8 = pInstanceGroupa;
        }
        while ( j < v22 );
        v5 = pRenderContext;
      }
      indexBuilder.m_pIndexBuffer->Unlock(
        this: indexBuilder.m_pIndexBuffer,
        a2: indexBuilder.m_nIndexCount,
        a3: &indexBuilder);
      DrawInstances = v5->DrawInstances;
      v25 = (int)v8->m_pRenderData & 0x7FFF;
      indexBuilder.m_pIndexBuffer = nullptr;
      indexBuilder.m_nMaxIndexCount = 0;
      DrawInstances(this: v5, a2: v25, a3: pInstance);
      if ( indexBuilder.m_pIndexBuffer != nullptr
        && indexBuilder.m_pIndexBuffer->IsDynamic(this: indexBuilder.m_pIndexBuffer) )
      {
        indexBuilder.m_pIndexBuffer->EndCastBuffer(this: indexBuilder.m_pIndexBuffer);
      }
      ++v8;
      v24 = v31-- == 1;
      pInstanceGroupa = v8;
      if ( v24 )
        return bHasPaintedSurfaces_3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064110
// Name: private: void CBrushBatchRender::DrawPaintForBatches(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushInstanceGroup_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawPaintForBatches(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroup,
        int nMaxInstanceCount)
{
  void *v5; // esp
  IMatRenderContext *v6; // edi
  void (__thiscall *EndRender)(IMatRenderContext *); // edx
  IMaterial **v8; // ebx
  IIndexBuffer_vtbl *v9; // edx
  int v10; // eax
  unsigned int m_nOffset; // eax
  __int16 v12; // dx
  _DWORD *v13; // esi
  IMaterial *v14; // edi
  __int16 *v15; // ebx
  int v16; // ecx
  PreviewImageRetVal_t (__thiscall *GetPreviewImage)(IMaterial *, unsigned __int8 *, int, int, ImageFormat); // edx
  int v18; // eax
  unsigned int v19; // ecx
  IMesh *v20; // edx
  int v21; // ecx
  void (__thiscall *DrawInstances)(IMatRenderContext *, int, const MeshInstanceData_t *); // eax
  bool v23; // zf
  int v24; // [esp+0h] [ebp-60h] BYREF
  CIndexBuilder meshBuilder; // [esp+Ch] [ebp-54h] BYREF
  IIndexBuffer *m_pIndexBuffer; // [esp+40h] [ebp-20h]
  int v27; // [esp+44h] [ebp-1Ch]
  int v28; // [esp+48h] [ebp-18h]
  IMaterial **v29; // [esp+4Ch] [ebp-14h]
  int *v30; // [esp+50h] [ebp-10h]
  int v31; // [esp+54h] [ebp-Ch]
  unsigned int v32; // [esp+58h] [ebp-8h]
  int v33; // [esp+5Ch] [ebp-4h]
  int i; // [esp+6Ch] [ebp+Ch]
  int v35; // [esp+70h] [ebp+10h]
  int v36; // [esp+74h] [ebp+14h]
  bool v37; // [esp+77h] [ebp+17h]

  v5 = alloca(76 * nMaxInstanceCount);
  v6 = pRenderContext;
  EndRender = pRenderContext->__vftable[1].EndRender;
  v30 = &v24;
  ((void (__thiscall *)(IMatRenderContext *, int))EndRender)(a1: pRenderContext, a2: 1);
  if ( nCount > 0 )
  {
    v8 = (IMaterial **)pInstanceGroup + 3;
    v29 = (IMaterial **)pInstanceGroup + 3;
    v28 = nCount;
    while ( *(__int16 *)v8 >= 0 )
    {
LABEL_22:
      v8 += 4;
      v23 = v28-- == 1;
      v29 = v8;
      if ( v23 )
        goto LABEL_23;
    }
    v6->Bind(this: v6, a2: *(v8 - 1), a3: nullptr);
    meshBuilder.m_pIndexBuffer = v6->GetDynamicIndexBuffer(this: v6);
    meshBuilder.m_nBufferOffset = -1;
    meshBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_nIndexCount = 0;
    meshBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_nTotalIndexCount = 0;
    v9 = meshBuilder.m_pIndexBuffer->__vftable;
    m_pIndexBuffer = meshBuilder.m_pIndexBuffer;
    if ( v9->IsDynamic(this: meshBuilder.m_pIndexBuffer) )
      meshBuilder.m_pIndexBuffer->BeginCastBuffer(this: meshBuilder.m_pIndexBuffer, a2: MATERIAL_INDEX_FORMAT_16BIT);
    v10 = *((unsigned __int16 *)v8 + 1);
    meshBuilder.m_bModify = false;
    meshBuilder.m_nMaxIndexCount = v10;
    memset(&meshBuilder.m_nIndexCount, 0, 16);
    v37 = meshBuilder.m_nBufferOffset == -1;
    if ( meshBuilder.m_pIndexBuffer->Lock(this: meshBuilder.m_pIndexBuffer, a2: v10, a3: false, a4: &meshBuilder) )
    {
      if ( v37 )
      {
        m_nOffset = meshBuilder.m_nOffset;
        meshBuilder.m_nBufferOffset = meshBuilder.m_nOffset;
        meshBuilder.m_nBufferFirstIndex = meshBuilder.m_nFirstIndex;
        goto LABEL_9;
      }
    }
    else
    {
      meshBuilder.m_nMaxIndexCount = 0;
    }
    m_nOffset = meshBuilder.m_nBufferOffset;
LABEL_9:
    v12 = *(_WORD *)v8;
    v32 = m_nOffset >> 1;
    v33 = 0;
    v31 = 0;
    if ( (v12 & 0x7FFF) != 0 )
    {
      v35 = 0;
      v13 = v30 + 16;
      do
      {
        v14 = &(*(v8 - 3))[v35];
        if ( ((int)v14[3].__vftable & 0x8000) != 0 )
        {
          v15 = (__int16 *)((char *)v14[2].GetPreviewImageProperties + 16 * ((int)v14[3].__vftable & 0x7FFF));
          v16 = *(_DWORD *)(*((_DWORD *)v14->GetTextureGroupName + 78) + 124)
              + 32 * *((_DWORD *)v14->GetTextureGroupName + 79);
          v27 = v16;
          v36 = 0;
          for ( i = 0; i < v15[1]; ++i )
          {
            GetPreviewImage = v14[2].GetPreviewImage;
            if ( (*(_DWORD *)(v16 + 32 * *((__int16 *)GetPreviewImage + 2 * i + 2 * *v15)) & 0x200000) != 0 )
            {
              v18 = BuildIndicesForSurface(
                      &meshBuilder,
                      surfID: (msurface2_t *)(v16 + 32 * *((__int16 *)GetPreviewImage + 2 * i + 2 * *v15)));
              v16 = v27;
              v36 += v18 + 2 * v18;
            }
          }
          *(v13 - 11) = 0;
          v19 = v32;
          *(v13 - 12) = v14->GetName;
          *(v13 - 15) = v36;
          *(v13 - 10) = 0;
          *(v13 - 13) = 0;
          *(v13 - 16) = v19;
          *(v13 - 5) = 0;
          *(v13 - 4) = 0;
          *(v13 - 14) = 1;
          *(v13 - 9) = 2;
          *(v13 - 3) = v14->GetNumAnimationFrames;
          v20 = g_WorldStaticMeshes.m_Memory.m_pMemory[*((_DWORD *)v15 + 2)];
          ++v33;
          v8 = v29;
          *(v13 - 8) = v20;
          *(v13 - 6) = m_pIndexBuffer;
          *(v13 - 7) = 0;
          *(v13 - 2) = 1065353216;
          *(v13 - 1) = 1065353216;
          *v13 = 1065353216;
          v13[1] = 1065353216;
          v13[2] = (__int16)(2 * HIWORD(v14[3].__vftable)) >> 1;
          v32 = v36 + v19;
          v13 += 19;
        }
        v35 += 4;
        v21 = *(_WORD *)v8 & 0x7FFF;
        ++v31;
      }
      while ( v31 < v21 );
      v6 = pRenderContext;
    }
    meshBuilder.m_pIndexBuffer->Unlock(
      this: meshBuilder.m_pIndexBuffer,
      a2: meshBuilder.m_nIndexCount,
      a3: &meshBuilder);
    DrawInstances = v6->DrawInstances;
    meshBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_nMaxIndexCount = 0;
    DrawInstances(this: v6, a2: v33, a3: (const MeshInstanceData_t *)v30);
    if ( meshBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_pIndexBuffer);
    }
    goto LABEL_22;
  }
LABEL_23:
  ((void (__thiscall *)(IMatRenderContext *, _DWORD))v6->__vftable[1].EndRender)(a1: v6, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064400
// Name: private: void CBrushBatchRender::DrawShadowBatchList(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushInstanceGroup_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawShadowBatchList(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroup,
        int nMaxInstanceCount)
{
  IMatRenderContext *v5; // ebx
  void *v6; // esp
  IMaterial **p_m_pMaterial; // edi
  IMaterialVar *v9; // esi
  IMaterialVar *v10; // eax
  int *v11; // ecx
  int v12; // edx
  msurface2_t *v13; // eax
  IMaterial *v14; // ecx
  IMaterial_vtbl *v15; // edx
  IMaterialVar *v16; // ebx
  int v17; // eax
  IMaterial *v18; // ecx
  IMaterial_vtbl *v19; // edx
  int v20; // eax
  int v21; // esi
  int v22; // eax
  IIndexBuffer_vtbl *v23; // edx
  int v24; // eax
  unsigned int m_nOffset; // eax
  __int16 v26; // dx
  float *p_z; // esi
  float **v28; // ebx
  float *v29; // edi
  msurface2_t *v30; // eax
  IMaterialVar *v31; // eax
  __int16 v32; // dx
  void (__thiscall *DrawInstances)(IMatRenderContext *, int, const MeshInstanceData_t *); // edx
  bool v34; // zf
  int v35; // [esp+38h] [ebp-60h]
  float v36; // [esp+3Ch] [ebp-5Ch]
  int v37; // [esp+40h] [ebp-58h] BYREF
  CIndexBuilder indexBuilder; // [esp+4Ch] [ebp-4Ch] BYREF
  IIndexBuffer *pBuildIndexBuffer; // [esp+80h] [ebp-18h]
  msurface2_t *firstSurfID; // [esp+84h] [ebp-14h]
  int v41; // [esp+88h] [ebp-10h]
  MeshInstanceData_t *pInstance; // [esp+8Ch] [ebp-Ch]
  int j; // [esp+90h] [ebp-8h]
  IMaterialVar *pOriginalTextureFrameVar; // [esp+94h] [ebp-4h]
  IMaterial **nCounta; // [esp+A4h] [ebp+Ch]
  CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroupb; // [esp+A8h] [ebp+10h]
  CBrushBatchRender::BrushInstanceGroup_t *pInstanceGroupa; // [esp+A8h] [ebp+10h]
  int k; // [esp+ACh] [ebp+14h]
  int ka; // [esp+ACh] [ebp+14h]
  bool k_3; // [esp+AFh] [ebp+17h]

  v5 = pRenderContext;
  pRenderContext->BindLightmapPage(this: pRenderContext, a2: -2);
  v6 = alloca(76 * nMaxInstanceCount);
  pInstance = (MeshInstanceData_t *)&v37;
  if ( nCount > 0 )
  {
    p_m_pMaterial = &pInstanceGroup->m_pMaterial;
    nCounta = &pInstanceGroup->m_pMaterial;
    v41 = nCount;
    do
    {
      if ( SHIWORD((*(p_m_pMaterial - 2))[3].__vftable) < 0 )
      {
        v9 = (*(p_m_pMaterial - 1))->FindVarFast(
               this: *(p_m_pMaterial - 1),
               a2: "$basetexture",
               a3: &originalTextureVarCache);
        v10 = (*(p_m_pMaterial - 1))->FindVarFast(
                this: *(p_m_pMaterial - 1),
                a2: "$frame",
                a3: &originalTextureFrameVarCache);
        v11 = (int *)*(p_m_pMaterial - 1);
        v12 = *v11;
        pOriginalTextureFrameVar = v10;
        v13 = (msurface2_t *)(*(int (__thiscall **)(int *, const char *, unsigned int *))(v12 + 188))(
                               a1: v11,
                               a2: "$AlphaTestReference",
                               a3: &originalAlphaRefCache);
        v14 = *p_m_pMaterial;
        v15 = (*p_m_pMaterial)->__vftable;
        firstSurfID = v13;
        v16 = v15->FindVarFast(this: v14, a2: "$basetexture", a3: &textureVarCache);
        v17 = (int)(*p_m_pMaterial)->FindVarFast(this: *p_m_pMaterial, a2: "$frame", a3: &textureFrameVarCache);
        v18 = *p_m_pMaterial;
        v19 = (*p_m_pMaterial)->__vftable;
        j = v17;
        k = (int)v19->FindVarFast(this: v18, a2: "$AlphaTestReference", a3: &alphaRefCache);
        if ( v16 != nullptr && v9 != nullptr )
        {
          pInstanceGroupb = (CBrushBatchRender::BrushInstanceGroup_t *)&v16->SetTextureValue;
          v20 = v9->GetTextureValue(this: v9);
          ((void (__thiscall *)(IMaterialVar *, int))pInstanceGroupb->m_pRenderData)(a1: v16, a2: v20);
        }
        v21 = j;
        if ( j != 0 && pOriginalTextureFrameVar != nullptr )
        {
          v22 = pOriginalTextureFrameVar->GetIntValueInternal(this: pOriginalTextureFrameVar);
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v21 + 20))(a1: v21, a2: v22);
        }
        if ( k != 0 && firstSurfID != nullptr )
        {
          v36 = ((double (__thiscall *)(msurface2_t *))*(_DWORD *)(firstSurfID->flags + 112))(a1: firstSurfID);
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)k + 16))(a1: LODWORD(v36));
        }
        v5 = pRenderContext;
      }
      v5->Bind(this: v5, a2: *p_m_pMaterial, a3: nullptr);
      indexBuilder.m_pIndexBuffer = v5->GetDynamicIndexBuffer(this: v5);
      indexBuilder.m_nBufferOffset = -1;
      indexBuilder.m_nBufferFirstIndex = 0;
      indexBuilder.m_nIndexCount = 0;
      indexBuilder.m_nCurrentIndex = 0;
      indexBuilder.m_nMaxIndexCount = 0;
      indexBuilder.m_nTotalIndexCount = 0;
      v23 = indexBuilder.m_pIndexBuffer->__vftable;
      pBuildIndexBuffer = indexBuilder.m_pIndexBuffer;
      if ( v23->IsDynamic(this: indexBuilder.m_pIndexBuffer) )
        indexBuilder.m_pIndexBuffer->BeginCastBuffer(this: indexBuilder.m_pIndexBuffer, a2: MATERIAL_INDEX_FORMAT_16BIT);
      v24 = *((unsigned __int16 *)p_m_pMaterial + 3);
      indexBuilder.m_bModify = false;
      indexBuilder.m_nMaxIndexCount = v24;
      memset(&indexBuilder.m_nIndexCount, 0, 16);
      k_3 = indexBuilder.m_nBufferOffset == -1;
      if ( indexBuilder.m_pIndexBuffer->Lock(this: indexBuilder.m_pIndexBuffer, a2: v24, a3: false, a4: &indexBuilder) )
      {
        if ( k_3 )
        {
          m_nOffset = indexBuilder.m_nOffset;
          indexBuilder.m_nBufferOffset = indexBuilder.m_nOffset;
          indexBuilder.m_nBufferFirstIndex = indexBuilder.m_nFirstIndex;
          goto LABEL_19;
        }
      }
      else
      {
        indexBuilder.m_nMaxIndexCount = 0;
      }
      m_nOffset = indexBuilder.m_nBufferOffset;
LABEL_19:
      v26 = *((_WORD *)p_m_pMaterial + 2);
      pOriginalTextureFrameVar = (IMaterialVar *)(m_nOffset >> 1);
      j = 0;
      if ( (v26 & 0x7FFF) != 0 )
      {
        pInstanceGroupa = nullptr;
        p_z = &pInstance->m_DiffuseModulation.z;
        do
        {
          v28 = (float **)((char *)*(p_m_pMaterial - 2) + (_DWORD)pInstanceGroupa);
          v29 = (float *)(*((_DWORD *)v28[2] + 2) + 16 * ((_WORD)v28[3] & 0x7FFF));
          v30 = (msurface2_t *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)*v28 + 1) + 312) + 124)
                              + 32 * *(_DWORD *)(*((_DWORD *)*v28 + 1) + 316));
          firstSurfID = v30;
          ka = 0;
          if ( *((__int16 *)v29 + 1) > 0 )
          {
            while ( 1 )
            {
              BuildIndicesForSurface(
                meshBuilder: &indexBuilder,
                surfID: &v30[*(__int16 *)(*((_DWORD *)v28[2] + 3) + 4 * (ka + *(__int16 *)v29))]);
              if ( ++ka >= *((__int16 *)v29 + 1) )
                break;
              v30 = firstSurfID;
            }
          }
          *(p_z - 11) = 0.0;
          *(p_z - 12) = **v28;
          v31 = pOriginalTextureFrameVar;
          *((_DWORD *)p_z - 16) = pOriginalTextureFrameVar;
          *(p_z - 10) = 0.0;
          *(p_z - 13) = 0.0;
          *((_DWORD *)p_z - 14) = 1;
          *(p_z - 15) = v29[3];
          *(p_z - 5) = 0.0;
          *(p_z - 4) = 0.0;
          *((_DWORD *)p_z - 9) = 2;
          ++pInstanceGroupa;
          *(p_z - 3) = (*v28)[6];
          *(p_z - 8) = *(float *)&g_WorldStaticMeshes.m_Memory.m_pMemory[*((_DWORD *)v29 + 2)];
          *((_DWORD *)p_z - 6) = pBuildIndexBuffer;
          *(p_z - 7) = 0.0;
          *(p_z - 2) = 1.0;
          *(p_z - 1) = 1.0;
          *p_z = 1.0;
          p_z[1] = 1.0;
          p_z[2] = NAN;
          v32 = *((_WORD *)nCounta + 2);
          pOriginalTextureFrameVar = (IMaterialVar *)((char *)v31 + *((_DWORD *)v29 + 3));
          p_z += 19;
          ++j;
          p_m_pMaterial = nCounta;
        }
        while ( j < (v32 & 0x7FFF) );
        v5 = pRenderContext;
      }
      indexBuilder.m_pIndexBuffer->Unlock(
        this: indexBuilder.m_pIndexBuffer,
        a2: indexBuilder.m_nIndexCount,
        a3: &indexBuilder);
      DrawInstances = v5->DrawInstances;
      v35 = (_WORD)p_m_pMaterial[1] & 0x7FFF;
      indexBuilder.m_pIndexBuffer = nullptr;
      indexBuilder.m_nMaxIndexCount = 0;
      DrawInstances(this: v5, a2: v35, a3: pInstance);
      if ( indexBuilder.m_pIndexBuffer != nullptr
        && indexBuilder.m_pIndexBuffer->IsDynamic(this: indexBuilder.m_pIndexBuffer) )
      {
        indexBuilder.m_pIndexBuffer->EndCastBuffer(this: indexBuilder.m_pIndexBuffer);
      }
      p_m_pMaterial += 4;
      v34 = v41-- == 1;
      nCounta = p_m_pMaterial;
    }
    while ( !v34 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100648A0
// Name: void std::_Make_heap<struct CBrushBatchRender::BrushBatchRenderData_t __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)>(struct CBrushBatchRender::BrushBatchRenderData_t __near *,struct CBrushBatchRender::BrushBatchRenderData_t __near *,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &),int __near *,struct CBrushBatchRender::BrushBatchRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        CBrushBatchRender::BrushBatchRenderData_t *_First,
        CBrushBatchRender::BrushBatchRenderData_t *_Last,
        bool (__cdecl *_Pred)(const CBrushBatchRender::BrushBatchRenderData_t *, const CBrushBatchRender::BrushBatchRenderData_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  CBrushBatchRender::BrushBatchRenderData_t *i; // edx
  const BrushArrayInstanceData_t *m_pInstanceData; // ebx
  CBrushBatchRender::BrushBatchRenderData_t *v9; // edx
  CBrushBatchRender::brushrender_t *m_pBrushRender; // ebx
  int v11; // eax
  int v12; // esi
  int v13; // edx
  int v14; // ebx
  bool v15; // zf
  CBrushBatchRender::BrushBatchRenderData_t *v16; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v17; // ecx
  CBrushBatchRender::BrushBatchRenderData_t *v18; // edx
  CBrushBatchRender::BrushBatchRenderData_t *v19; // ebx
  CBrushBatchRender::BrushBatchRenderData_t _Val; // [esp+4h] [ebp-18h] BYREF
  int v21; // [esp+14h] [ebp-8h]
  CBrushBatchRender::BrushBatchRenderData_t *v22; // [esp+18h] [ebp-4h]
  int _Hole; // [esp+24h] [ebp+8h]
  int _Bottom; // [esp+28h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v22 )
    {
      m_pInstanceData = i[-1].m_pInstanceData;
      v9 = i - 1;
      _Val.m_pInstanceData = m_pInstanceData;
      _Val.m_pMaterial = v9->m_pMaterial;
      m_pBrushRender = v9->m_pBrushRender;
      v11 = v5 - 1;
      v12 = v6 - 2;
      v22 = v9;
      v13 = *((_DWORD *)v9 + 3);
      _Val.m_pBrushRender = m_pBrushRender;
      _Hole = v11;
      v21 = v12;
      *((_DWORD *)&_Val + 3) = v13;
      v14 = v11;
      v15 = v12 == v4;
      if ( v12 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v12], a2: &_First[v12 - 1]) )
            --v12;
          v16 = &_First[v12];
          v17 = &_First[v14];
          v17->m_pInstanceData = v16->m_pInstanceData;
          v17->m_pMaterial = v16->m_pMaterial;
          v17->m_pBrushRender = v16->m_pBrushRender;
          v14 = v12;
          v12 = 2 * v12 + 2;
          *((_DWORD *)v17 + 3) = *((_DWORD *)v16 + 3);
        }
        while ( v12 < _Bottom );
        v4 = _Bottom;
        v11 = _Hole;
        v15 = v12 == _Bottom;
      }
      if ( v15 )
      {
        v18 = &_First[v4 - 1];
        v19 = &_First[v14];
        v19->m_pInstanceData = v18->m_pInstanceData;
        v19->m_pMaterial = v18->m_pMaterial;
        v19->m_pBrushRender = v18->m_pBrushRender;
        *((_DWORD *)v19 + 3) = *((_DWORD *)v18 + 3);
        v14 = v4 - 1;
      }
      std::_Push_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        _First,
        _Hole: v14,
        _Top: v11,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064B30
// Name: public: void CUtlMemoryFixedGrowable<struct CBrushBatchRender::BrushInstanceGroup_t,512,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>::Grow(
        CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int> *this,
        int nCount)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = this->m_nMallocGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 16 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (CBrushBatchRender::BrushInstanceGroup_t *)v5;
      CUtlMemory<CPortalRect,int>::Grow(
        (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
        num: nCount);
      return;
    }
    this->m_pMemory = nullptr;
  }
  CUtlMemory<CPortalRect,int>::Grow(
    (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
    num: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x10064BA0
// Name: public: void CBrushBatchRender::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::LevelInit(CBrushBatchRender *this)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int16 m_Head; // ax
  int v4; // edx
  UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short> *m_pMemory; // eax
  void **p_pPlanes; // esi
  unsigned __int16 m_Next; // bx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  m_Head = this->m_renderList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      v4 = m_Head;
      m_pMemory = this->m_renderList.m_Memory.m_pMemory;
      p_pPlanes = (void **)&m_pMemory[v4].m_Element->pPlanes;
      m_Next = m_pMemory[v4].m_Next;
      if ( p_pPlanes != nullptr )
      {
        free(pMem: *p_pPlanes);
        free(pMem: p_pPlanes[1]);
        free(pMem: p_pPlanes[2]);
        free(pMem: p_pPlanes[3]);
        *p_pPlanes = nullptr;
        p_pPlanes[1] = nullptr;
        p_pPlanes[2] = nullptr;
        p_pPlanes[3] = nullptr;
        free(pMem: p_pPlanes);
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_renderList);
  if ( this->m_renderList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_renderList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_renderList.m_Memory.m_pMemory);
      this->m_renderList.m_Memory.m_pMemory = nullptr;
    }
    this->m_renderList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_renderList.m_FirstFree = -1;
  this->m_renderList.m_pElements = this->m_renderList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_renderList.m_NumAlloced = -65536;
  CBrushBatchRender::ClearRenderHandles(this);
  if ( this->m_Mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)this, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10064EA0
// Name: void std::_Sort_heap<struct CBrushBatchRender::BrushBatchRenderData_t __near *,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &)>(struct CBrushBatchRender::BrushBatchRenderData_t __near *,struct CBrushBatchRender::BrushBatchRenderData_t __near *,bool (*)(struct CBrushBatchRender::BrushBatchRenderData_t const __near &,struct CBrushBatchRender::BrushBatchRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<CBrushBatchRender::BrushBatchRenderData_t *,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        CBrushBatchRender::BrushBatchRenderData_t *_First,
        CBrushBatchRender::BrushBatchRenderData_t *_Last,
        bool (__cdecl *_Pred)(const CBrushBatchRender::BrushBatchRenderData_t *, const CBrushBatchRender::BrushBatchRenderData_t *))
{
  int v3; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v4; // esi
  IMaterial *m_pMaterial; // edx
  CBrushBatchRender::brushrender_t *m_pBrushRender; // ecx
  int v7; // edx
  CBrushBatchRender::BrushBatchRenderData_t _Val; // [esp+4h] [ebp-10h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF0) > 16 )
  {
    v4 = _Last - 1;
    do
    {
      m_pMaterial = v4->m_pMaterial;
      _Val.m_pInstanceData = v4->m_pInstanceData;
      m_pBrushRender = v4->m_pBrushRender;
      _Val.m_pMaterial = m_pMaterial;
      v7 = *((_DWORD *)v4 + 3);
      _Val.m_pBrushRender = m_pBrushRender;
      v4->m_pInstanceData = _First->m_pInstanceData;
      *((_DWORD *)&_Val + 3) = v7;
      v4->m_pMaterial = _First->m_pMaterial;
      v4->m_pBrushRender = _First->m_pBrushRender;
      *((_DWORD *)v4 + 3) = *((_DWORD *)_First + 3);
      std::_Adjust_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 16) >> 4,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 16;
    }
    while ( (int)(v3 & 0xFFFFFFF0) > 16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064F30
// Name: private: void CBrushBatchRender::DrawTransLists(class IMatRenderContext __near *,struct CBrushBatchRender::transrender_t __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBrushBatchRender::DrawTransLists(
        CBrushBatchRender *this@<ecx>,
        CMeshBuilder *p_meshBuilder@<ebx>,
        int m_nIndexCount@<edi>,
        int a4@<esi>,
        IMatRenderContext *pRenderContext,
        CBrushBatchRender::transrender_t *render,
        void *pProxyData)
{
  bool v7; // zf
  __int16 *p_batchCount; // edi
  CBrushBatchRender::transbatch_t *v9; // esi
  int pMaterial; // edi
  IMesh *v11; // eax
  int m; // edi
  int m_nVertexCount; // eax
  int v14; // esi
  int v15; // edx
  __int16 v16; // ax
  int v17; // ecx
  msurface2_t *v18; // esi
  int v19; // edx
  int m_nAllocationCount; // ecx
  int m_Size; // esi
  int v22; // edx
  CBrushBatchRender::transbatch_t *v23; // ebx
  int v24; // eax
  int v25; // edi
  msurface2_t **m_pMemory; // ecx
  msurface2_t **v27; // edi
  int surfaceCount; // edx
  int v29; // eax
  int nodeCount; // edx
  CMeshBuilder meshBuilder; // [esp+74h] [ebp-224h] BYREF
  float pOldColor[4]; // [esp+25Ch] [ebp-3Ch] BYREF
  msurface2_t **v36; // [esp+26Ch] [ebp-2Ch]
  int i; // [esp+270h] [ebp-28h]
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > brushList; // [esp+274h] [ebp-24h] BYREF
  int k; // [esp+288h] [ebp-10h]
  __int16 *v40; // [esp+28Ch] [ebp-Ch]
  int j; // [esp+290h] [ebp-8h]
  bool skipLight; // [esp+297h] [ebp-1h]

  v7 = g_pMaterialSystemConfig->nFullbright == 1;
  skipLight = false;
  if ( v7 )
  {
    pRenderContext->BindLightmapPage(this: pRenderContext, a2: -2);
    skipLight = true;
  }
  i = 0;
  if ( render->nodeCount > 0 )
  {
    p_batchCount = &render->nodes[0].batchCount;
    v40 = &render->nodes[0].batchCount;
    do
    {
      j = 0;
      if ( *p_batchCount > 0 )
      {
        do
        {
          v9 = &render->batches[*(p_batchCount - 1) + j];
          meshBuilder.m_pMesh = nullptr;
          meshBuilder.m_bGenerateIndices = false;
          memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
          meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
          meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
          meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
          meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
          memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
          meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          pMaterial = (int)v9->pMaterial;
          k = pMaterial;
          if ( g_bIsBlendingOrModulating )
          {
            pOldColor[3] = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)pMaterial + 176))(a1: pMaterial);
            (*(void (__thiscall **)(int, float *, float *, float *))(*(_DWORD *)pMaterial + 180))(
              a1: pMaterial,
              a2: pOldColor,
              a3: &pOldColor[1],
              a4: &pOldColor[2]);
            (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)pMaterial + 108))(a1: pMaterial, a2: LODWORD(r_blend));
            (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)pMaterial + 112))(
              a1: pMaterial,
              a2: LODWORD(r_colormod.x),
              a3: LODWORD(r_colormod.y),
              a4: LODWORD(r_colormod.z));
          }
          if ( !skipLight )
            pRenderContext->BindLightmapPage(this: pRenderContext, a2: materialSortInfoArray[v9->sortID].lightmapPageID);
          ((void (__thiscall *)(IMatRenderContext *, int, void *, int, int, CMeshBuilder *))pRenderContext->Bind)(
            a1: pRenderContext,
            a2: pMaterial,
            a3: pProxyData,
            a4,
            a5: m_nIndexCount,
            a6: p_meshBuilder);
          v11 = pRenderContext->GetDynamicMesh(
                  this: pRenderContext,
                  a2: 0,
                  a3: g_WorldStaticMeshes.m_Memory.m_pMemory[v9->sortID],
                  a4: 0,
                  a5: 0);
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh: v11,
            type: MATERIAL_TRIANGLES,
            nVertexCount: 0,
            nIndexCount: v9->indexCount,
            pMeshSettings: nullptr);
          for ( m = 0; m < v9->surfaceCount; ++m )
            BuildIndicesForSurface(
              meshBuilder: &meshBuilder.m_IndexBuilder,
              surfID: *(&render->surfaces[m] + v9->firstSurface));
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: m_nVertexCount);
          }
          p_meshBuilder = &meshBuilder;
          m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
          a4 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          ((void (__thiscall *)(IMesh *))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          meshBuilder.m_pMesh->Draw_2(this: meshBuilder.m_pMesh, a2: -1, a3: 0);
          meshBuilder.m_pMesh = nullptr;
          if ( g_bIsBlendingOrModulating )
          {
            v14 = k;
            (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)k + 108))(a1: k, a2: LODWORD(pOldColor[3]));
            (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v14 + 112))(
              a1: v14,
              a2: LODWORD(pOldColor[0]),
              a3: LODWORD(pOldColor[1]),
              a4: LODWORD(pOldColor[2]));
          }
          if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
            && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
          {
            meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
            && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
          {
            meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
          }
          v15 = *v40;
          ++j;
          p_batchCount = v40;
        }
        while ( j < v15 );
      }
      v16 = p_batchCount[2];
      if ( v16 != 0 )
      {
        v17 = 0;
        j = 0;
        if ( v16 > 0 )
        {
          do
          {
            v18 = *(&render->decalSurfaces[v17] + p_batchCount[1]);
            if ( v18->decals != 0xFFFF )
              DecalSurfaceAdd(surfID: v18, iGroup: 4);
            if ( v18->m_ShadowDecals != 0xFFFF )
              g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: v18->m_ShadowDecals);
            v19 = p_batchCount[2];
            v17 = j + 1;
            j = v17;
          }
          while ( v17 < v19 );
        }
        DecalSurfaceDraw(pRenderContext, renderGroup: 4, flFade: 1.0);
        R_DecalFlushDestroyList();
        DecalSurfacesInit(bBrushModel: true);
        g_pShadowMgr->RenderProjectedTextures(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
      }
      if ( g_ShaderDebug.anydebug )
      {
        m_nAllocationCount = 0;
        m_Size = 0;
        v22 = 0;
        memset(&brushList, 0, sizeof(brushList));
        j = 0;
        if ( *p_batchCount > 0 )
        {
          do
          {
            v23 = &render->batches[*(p_batchCount - 1) + v22];
            v24 = 0;
            k = 0;
            if ( v23->surfaceCount > 0 )
            {
              do
              {
                v36 = &render->surfaces[v24] + v23->firstSurface;
                v25 = m_Size;
                if ( m_Size + 1 > m_nAllocationCount )
                {
                  CUtlMemory<INetMessage *,int>::Grow(
                    this: (CUtlMemory<S3RGBA,int> *)&brushList,
                    num: m_Size - m_nAllocationCount + 1);
                  m_Size = brushList.m_Size;
                }
                m_pMemory = brushList.m_Memory.m_pMemory;
                brushList.m_Size = ++m_Size;
                brushList.m_pElements = brushList.m_Memory.m_pMemory;
                if ( m_Size - v25 - 1 > 0 )
                {
                  _V_memmove(
                    dest: &brushList.m_Memory.m_pMemory[v25 + 1],
                    src: &brushList.m_Memory.m_pMemory[v25],
                    count: 4 * (m_Size - v25 - 1));
                  m_pMemory = brushList.m_Memory.m_pMemory;
                }
                v27 = &m_pMemory[v25];
                if ( v27 != nullptr )
                  *v27 = *v36;
                surfaceCount = v23->surfaceCount;
                m_nAllocationCount = brushList.m_Memory.m_nAllocationCount;
                v24 = k + 1;
                k = v24;
              }
              while ( v24 < surfaceCount );
              v22 = j;
            }
            v29 = *v40;
            p_batchCount = v40;
            j = ++v22;
          }
          while ( v22 < v29 );
        }
        DrawDebugInformation(pRenderContext, pList: brushList.m_Memory.m_pMemory, listCount: m_Size);
        if ( brushList.m_Memory.m_nGrowSize >= 0 && brushList.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: brushList.m_Memory.m_pMemory);
      }
      nodeCount = render->nodeCount;
      p_batchCount += 4;
      ++i;
      v40 = p_batchCount;
    }
    while ( i < nodeCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065460
// Name: private: void CBrushBatchRender::BuildTransLists_r(struct CBrushBatchRender::transrender_t __near &,struct model_t __near *,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::BuildTransLists_r(
        CBrushBatchRender *this,
        int render,
        model_t *model,
        mnode_t *node)
{
  mnode_t *v4; // ebx
  bool v5; // sf
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v9; // xmm0_4
  int firstsurface; // edi
  signed int m_Size; // eax
  worldbrushdata_t *pShared; // ecx
  msurface2_t *v14; // edi
  CBrushBatchRender::transbatch_t *v15; // ecx
  __int16 v16; // ax
  __int16 v17; // cx
  int v18; // ebx
  int v19; // eax
  int v20; // edi
  CBrushBatchRender::transbatch_t *v21; // ecx
  CBrushBatchRender::transnode_t *v22; // edi
  CUtlVectorFixed<CBrushBatchRender::surfacelist_t,256> sortList; // [esp+4h] [ebp-810h] BYREF
  CBrushBatchRender *v24; // [esp+80Ch] [ebp-8h]
  int side; // [esp+810h] [ebp-4h]
  int i; // [esp+81Ch] [ebp+8h]
  int ia; // [esp+81Ch] [ebp+8h]

  v4 = node;
  v5 = node->contents < 0;
  v24 = this;
  if ( v5 )
  {
    plane = node->plane;
    type = plane->type;
    if ( type > 2u )
      v9 = (float)((float)(plane->normal.y * modelorg.y) + (float)(plane->normal.x * modelorg.x))
         + (float)(plane->normal.z * modelorg.z);
    else
      v9 = *(&modelorg.x + type);
    side = (float)(v9 - plane->dist) < 0.0;
    CBrushBatchRender::BuildTransLists_r(
      this,
      (CBrushBatchRender::transrender_t *)render,
      model,
      node: node->children[side == 0]);
    firstsurface = node->firstsurface;
    m_Size = 0;
    sortList.m_pElements = (CBrushBatchRender::surfacelist_t *)&sortList;
    pShared = model->brush.pShared;
    sortList.m_Size = 0;
    v14 = &pShared->surfaces2[firstsurface];
    i = 0;
    if ( node->numsurfaces != 0 )
    {
      do
      {
        if ( (v14->flags & 0x20) != 0 && ((v14->flags & 0x200) != 0 || side == ((v14->flags & 0x40) != 0)) )
        {
          v15 = *(CBrushBatchRender::transbatch_t **)(render + 23552);
          if ( v15 != nullptr && v15->sortID == v14->materialSortID )
          {
            CBrushBatchRender::AddSurfaceToBatch(
              this: v24,
              (CBrushBatchRender::transrender_t *)render,
              pNode: *(CBrushBatchRender::transnode_t **)(render + 23556),
              pBatch: v15,
              surfID: v14);
          }
          else
          {
            sortList.m_Size = m_Size + 1;
            sortList.m_pElements = (CBrushBatchRender::surfacelist_t *)&sortList;
            *(_DWORD *)&sortList.m_Memory.m_Memory[8 * m_Size] = v14;
            v4 = node;
          }
          m_Size = sortList.m_Size;
        }
        ++v14;
        ++i;
      }
      while ( i < v4->numsurfaces );
      if ( m_Size != 0 )
      {
        if ( m_Size > 1 )
          qsort(
            base: &sortList,
            num: m_Size,
            width: 8u,
            comp: (int (__cdecl *)(const void *, const void *))CBrushBatchRender::SurfaceCmp);
        v16 = *(_WORD *)(render + 23560);
        *(_WORD *)(render + 23560) = v16 + 1;
        v17 = *(_WORD *)(render + 23562);
        *(_DWORD *)(render + 23556) = render + 8 * v16;
        *(_DWORD *)(render + 23552) = 0;
        *(_WORD *)(render + 8 * v16) = v17;
        *(_WORD *)(*(_DWORD *)(render + 23556) + 4) = *(_WORD *)(render + 23566);
        *(_WORD *)(*(_DWORD *)(render + 23556) + 2) = 0;
        *(_WORD *)(*(_DWORD *)(render + 23556) + 6) = 0;
        v18 = -1;
        for ( ia = 0; ia < sortList.m_Size; ++ia )
        {
          v19 = *(_DWORD *)&sortList.m_Memory.m_Memory[8 * ia];
          v20 = *(__int16 *)(v19 + 18);
          if ( v18 == v20 )
          {
            v21 = *(CBrushBatchRender::transbatch_t **)(render + 23552);
            v22 = *(CBrushBatchRender::transnode_t **)(render + 23556);
            ++v21->surfaceCount;
            v21->indexCount += 3 * *(unsigned __int8 *)(v19 + 3) - 6;
            *(_DWORD *)(render + 4 * (__int16)(*(_WORD *)(render + 23564))++ + 2048) = v19;
            if ( *(_WORD *)(v19 + 12) != 0xFFFF || *(_WORD *)(v19 + 14) != 0xFFFF )
            {
              ++v22->decalSurfaceCount;
              *(_DWORD *)(render + 4 * (__int16)(*(_WORD *)(render + 23566))++ + 6144) = v19;
            }
          }
          else
          {
            CBrushBatchRender::AddTransBatch(
              this: v24,
              (CBrushBatchRender::transrender_t *)render,
              surfID: *(msurface2_t **)&sortList.m_Memory.m_Memory[8 * ia]);
            v18 = v20;
          }
        }
        v4 = node;
        if ( *(_WORD *)(*(_DWORD *)(render + 23556) + 6) != 0 )
        {
          *(_DWORD *)(render + 23556) = 0;
          *(_DWORD *)(render + 23552) = 0;
        }
      }
    }
    CBrushBatchRender::BuildTransLists_r(
      this: v24,
      (CBrushBatchRender::transrender_t *)render,
      model,
      node: v4->children[side]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065730
// Name: private: int CBrushBatchRender::ComputeInstanceGroups(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t __near *,class CUtlVectorFixedGrowable<struct CBrushBatchRender::BrushInstanceGroup_t,512> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBrushBatchRender::ComputeInstanceGroups(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        CBrushBatchRender::BrushBatchRenderData_t *nCount,
        CBrushBatchRender::BrushBatchRenderData_t *pRenderData,
        CUtlVectorFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512> *instanceGroups)
{
  IMaterial *v6; // edx
  CBrushBatchRender::brushrender_t **p_m_pBrushRender; // ecx
  int v8; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBrushBatchRender::BrushInstanceGroup_t *m_pMemory; // ecx
  int v12; // eax
  int v13; // eax
  IMaterial *v14; // eax
  bool v15; // zf
  int v16; // edi
  int v17; // eax
  CBrushBatchRender::BrushInstanceGroup_t *v18; // ecx
  int v19; // eax
  int v20; // eax
  int result; // eax
  int nMaxIndices; // [esp+0h] [ebp-18h]
  CBrushBatchRender::BrushBatchRenderData_t *pFirstInstance; // [esp+4h] [ebp-14h]
  int nMaxInstanceCount; // [esp+8h] [ebp-10h]
  IMaterial *pLastMaterial; // [esp+Ch] [ebp-Ch]
  IMaterial *pLastActualMaterial; // [esp+10h] [ebp-8h]
  int nIndexCount; // [esp+14h] [ebp-4h]
  int nInstanceCount; // [esp+20h] [ebp+8h]
  CBrushBatchRender::brushrender_t **nCounta; // [esp+24h] [ebp+Ch]
  CBrushBatchRender::BrushBatchRenderData_t *pRenderDataa; // [esp+28h] [ebp+10h]

  nMaxIndices = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  v6 = nullptr;
  nMaxInstanceCount = 0;
  pLastMaterial = nullptr;
  pLastActualMaterial = nullptr;
  pFirstInstance = nullptr;
  nInstanceCount = 0;
  nIndexCount = 0;
  if ( (int)nCount <= 0 )
    return 0;
  p_m_pBrushRender = &pRenderData->m_pBrushRender;
  nCounta = &pRenderData->m_pBrushRender;
  pRenderDataa = nCount;
  while ( 1 )
  {
    v8 = (int)&(*p_m_pBrushRender)->pBatches[(_WORD)p_m_pBrushRender[1] & 0x7FFF];
    if ( v6 == *(IMaterial **)(v8 + 4) && v6 == pLastActualMaterial && nIndexCount + *(_DWORD *)(v8 + 12) <= nMaxIndices )
    {
      nIndexCount += *(_DWORD *)(v8 + 12);
    }
    else
    {
      if ( nInstanceCount > 0 )
      {
        m_Size = instanceGroups->m_Size;
        m_nAllocationCount = instanceGroups->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>::Grow(
            this: &instanceGroups->m_Memory,
            nCount: m_Size - m_nAllocationCount + 1);
        ++instanceGroups->m_Size;
        m_pMemory = instanceGroups->m_Memory.m_pMemory;
        v12 = instanceGroups->m_Size - m_Size - 1;
        instanceGroups->m_pElements = instanceGroups->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v12);
        v13 = m_Size;
        instanceGroups->m_Memory.m_pMemory[v13].m_pRenderData = pFirstInstance;
        *((_WORD *)&instanceGroups->m_Memory.m_pMemory[m_Size] + 6) ^= (nInstanceCount
                                                                      ^ *((_WORD *)&instanceGroups->m_Memory.m_pMemory[m_Size]
                                                                        + 6))
                                                                     & 0x7FFF;
        instanceGroups->m_Memory.m_pMemory[v13].m_nIndexCount = nIndexCount;
        instanceGroups->m_Memory.m_pMemory[v13].m_pMaterial = pLastMaterial;
        instanceGroups->m_Memory.m_pMemory[v13].m_pActualMaterial = pLastActualMaterial;
        p_m_pBrushRender = nCounta;
        if ( nInstanceCount > nMaxInstanceCount )
          nMaxInstanceCount = nInstanceCount;
      }
      nIndexCount = *(_DWORD *)(v8 + 12);
      pFirstInstance = (CBrushBatchRender::BrushBatchRenderData_t *)(p_m_pBrushRender - 2);
      v14 = (IMaterial *)*(p_m_pBrushRender - 1);
      nInstanceCount = 0;
      pLastMaterial = v14;
      if ( *((__int16 *)p_m_pBrushRender + 3) < 0 )
        v14 = *(IMaterial **)(v8 + 4);
      pLastActualMaterial = v14;
    }
    ++nInstanceCount;
    p_m_pBrushRender += 4;
    v15 = pRenderDataa == (CBrushBatchRender::BrushBatchRenderData_t *)1;
    pRenderDataa = (CBrushBatchRender::BrushBatchRenderData_t *)((char *)pRenderDataa - 1);
    nCounta = p_m_pBrushRender;
    if ( v15 )
      break;
    v6 = pLastMaterial;
  }
  if ( nInstanceCount <= 0 )
    return nMaxInstanceCount;
  v16 = instanceGroups->m_Size;
  v17 = instanceGroups->m_Memory.m_nAllocationCount;
  if ( v16 + 1 > v17 )
    CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>::Grow(
      this: &instanceGroups->m_Memory,
      nCount: v16 - v17 + 1);
  ++instanceGroups->m_Size;
  v18 = instanceGroups->m_Memory.m_pMemory;
  v19 = instanceGroups->m_Size - v16 - 1;
  instanceGroups->m_pElements = instanceGroups->m_Memory.m_pMemory;
  if ( v19 > 0 )
    _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 16 * v19);
  v20 = v16;
  instanceGroups->m_Memory.m_pMemory[v20].m_pRenderData = pFirstInstance;
  *((_WORD *)&instanceGroups->m_Memory.m_pMemory[v20] + 6) ^= (nInstanceCount
                                                             ^ *((_WORD *)&instanceGroups->m_Memory.m_pMemory[v16] + 6))
                                                            & 0x7FFF;
  instanceGroups->m_Memory.m_pMemory[v20].m_nIndexCount = nIndexCount;
  instanceGroups->m_Memory.m_pMemory[v20].m_pMaterial = pLastMaterial;
  instanceGroups->m_Memory.m_pMemory[v20].m_pActualMaterial = pLastActualMaterial;
  result = nMaxInstanceCount;
  if ( nInstanceCount > nMaxInstanceCount )
    return nInstanceCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065970
// Name: private: void CBrushBatchRender::DrawArrayDebugInformation(class IMatRenderContext __near *,int,struct CBrushBatchRender::BrushBatchRenderData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawArrayDebugInformation(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const CBrushBatchRender::BrushBatchRenderData_t *pRenderData)
{
  const CBrushBatchRender::BrushBatchRenderData_t *v5; // edi
  CBrushBatchRender::brushrenderbatch_t *v6; // esi
  msurface2_t *v7; // ebx
  int v8; // edx
  int m_Size; // eax
  CBrushBatchRender::brushrender_t *m_pBrushRender; // ecx
  CBrushBatchRender::brushrendersurface_t *v11; // edx
  msurface2_t *v12; // edi
  float *p_x; // ecx
  int v14; // ebx
  unsigned int v15; // ebx
  msurface2_t **m_pMemory; // edx
  msurface2_t **v17; // ecx
  msurface2_t **v18; // eax
  bool v19; // zf
  const matrix3x4_t *m_pBrushToWorld; // [esp-14h] [ebp-850h]
  CUtlVectorFixedGrowable<msurface2_t *,512> surfaceList; // [esp+0h] [ebp-83Ch] BYREF
  Vector vecModelSpaceViewOrigin; // [esp+818h] [ebp-24h] BYREF
  msurface2_t *firstSurfID; // [esp+824h] [ebp-18h]
  const Vector *vecViewOrigin; // [esp+828h] [ebp-14h]
  int num; // [esp+82Ch] [ebp-10h]
  int v26; // [esp+830h] [ebp-Ch]
  unsigned __int8 *v27; // [esp+834h] [ebp-8h]
  int v28; // [esp+838h] [ebp-4h]
  const CBrushBatchRender::BrushBatchRenderData_t *nCounta; // [esp+848h] [ebp+Ch]
  int k; // [esp+84Ch] [ebp+10h]

  if ( g_ShaderDebug.anydebug )
  {
    vecViewOrigin = g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
    if ( nCount > 0 )
    {
      v5 = pRenderData;
      nCounta = pRenderData;
      v28 = nCount;
      do
      {
        v6 = &v5->m_pBrushRender->pBatches[*((_WORD *)v5 + 6) & 0x7FFF];
        v7 = (msurface2_t *)(*(_DWORD *)(v5->m_pInstanceData->m_pBrushModel->sprite.numframes + 124)
                           + 32 * v5->m_pInstanceData->m_pBrushModel->brush.firstmodelsurface);
        m_pBrushToWorld = v5->m_pInstanceData->m_pBrushToWorld;
        firstSurfID = v7;
        VectorITransform(in1: &vecViewOrigin->x, in2: m_pBrushToWorld, out: &vecModelSpaceViewOrigin.x);
        v8 = 0;
        surfaceList.m_Memory.m_pMemory = surfaceList.m_Memory.m_pFixedMemory;
        m_Size = 0;
        surfaceList.m_pElements = surfaceList.m_Memory.m_pFixedMemory;
        surfaceList.m_Memory.m_nAllocationCount = 512;
        surfaceList.m_Memory.m_nGrowSize = -1;
        surfaceList.m_Memory.m_nMallocGrowSize = 0;
        surfaceList.m_Size = 0;
        k = 0;
        if ( v6->surfaceCount > 0 )
        {
          while ( 1 )
          {
            m_pBrushRender = v5->m_pBrushRender;
            v11 = &m_pBrushRender->pSurfaces[v8 + v6->firstSurface];
            v12 = &v7[v11->surfaceIndex];
            if ( (v12->flags & 0x20) == 0
              && ((v12->flags & 0x200) != 0
               || (float)((float)((float)((float)((p_x = &m_pBrushRender->pPlanes[v11->planeIndex]->normal.x)[1]
                                                * vecModelSpaceViewOrigin.y)
                                        + (float)(vecModelSpaceViewOrigin.x * *p_x))
                                + (float)(p_x[2] * vecModelSpaceViewOrigin.z))
                        - p_x[3]) >= -0.0099999998) )
            {
              v14 = m_Size;
              v26 = m_Size;
              if ( m_Size + 1 > surfaceList.m_Memory.m_nAllocationCount )
              {
                num = m_Size - surfaceList.m_Memory.m_nAllocationCount + 1;
                if ( surfaceList.m_Memory.m_nGrowSize < 0 )
                {
                  surfaceList.m_Memory.m_nGrowSize = surfaceList.m_Memory.m_nMallocGrowSize;
                  if ( surfaceList.m_Memory.m_nAllocationCount != 0 )
                  {
                    v15 = 4 * surfaceList.m_Memory.m_nAllocationCount;
                    v27 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                               this: _g_pMemAlloc,
                                               a2: 4 * surfaceList.m_Memory.m_nAllocationCount);
                    memcpy(dst: v27, src: (unsigned __int8 *)surfaceList.m_Memory.m_pMemory, count: v15);
                    v14 = v26;
                    surfaceList.m_Memory.m_pMemory = (msurface2_t **)v27;
                  }
                  else
                  {
                    surfaceList.m_Memory.m_pMemory = nullptr;
                  }
                }
                CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&surfaceList, num);
                m_Size = surfaceList.m_Size;
              }
              m_pMemory = surfaceList.m_Memory.m_pMemory;
              surfaceList.m_Size = ++m_Size;
              surfaceList.m_pElements = surfaceList.m_Memory.m_pMemory;
              if ( m_Size - v14 - 1 > 0 )
              {
                _V_memmove(
                  dest: &surfaceList.m_Memory.m_pMemory[v14 + 1],
                  src: &surfaceList.m_Memory.m_pMemory[v14],
                  count: 4 * (m_Size - v14 - 1));
                m_Size = surfaceList.m_Size;
                m_pMemory = surfaceList.m_Memory.m_pMemory;
              }
              v17 = &m_pMemory[v14];
              if ( v17 != nullptr )
              {
                *v17 = v12;
                m_Size = surfaceList.m_Size;
              }
            }
            v5 = nCounta;
            v8 = k + 1;
            k = v8;
            if ( v8 >= v6->surfaceCount )
              break;
            v7 = firstSurfID;
          }
        }
        DrawDebugInformation(
          pRenderContext,
          brushToWorld: v5->m_pInstanceData->m_pBrushToWorld,
          pList: surfaceList.m_Memory.m_pMemory,
          listCount: m_Size);
        v18 = surfaceList.m_Memory.m_pMemory;
        surfaceList.m_Size = 0;
        if ( surfaceList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( surfaceList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfaceList.m_Memory.m_pMemory);
            v18 = nullptr;
            surfaceList.m_Memory.m_pMemory = nullptr;
          }
          surfaceList.m_Memory.m_nAllocationCount = 0;
        }
        surfaceList.m_pElements = v18;
        if ( surfaceList.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
        ++v5;
        v19 = v28-- == 1;
        nCounta = v5;
      }
      while ( !v19 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065C10
// Name: public: void CBrushBatchRender::DrawTranslucentBrushModel(class IMatRenderContext __near *,struct model_t __near *,class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBrushBatchRender::DrawTranslucentBrushModel(
        CBrushBatchRender *this@<ecx>,
        CMeshBuilder *a2@<ebx>,
        int a3@<edi>,
        IMatRenderContext *pRenderContext,
        model_t *model,
        IClientEntity *baseentity)
{
  worldbrushdata_t *pShared; // edx
  int v8; // ecx
  IClientRenderable *v9; // eax
  CBrushBatchRender::transrender_t render; // [esp+4h] [ebp-5C10h] BYREF

  pShared = model->brush.pShared;
  v8 = model->brush.firstnode << 6;
  memset(&render.pLastBatch, 0, 16);
  CBrushBatchRender::BuildTransLists_r(this, (int)&render, model, node: (mnode_t *)((char *)pShared->nodes + v8));
  if ( baseentity != nullptr )
    v9 = baseentity->GetClientRenderable(this: baseentity);
  else
    v9 = nullptr;
  CBrushBatchRender::DrawTransLists(
    this,
    p_meshBuilder: a2,
    m_nIndexCount: a3,
    a4: (int)this,
    pRenderContext,
    &render,
    pProxyData: (void *)v9);
}

//------------------------------------------------------------------------------
// Address: 0x10065C90
// Name: public: struct CBrushBatchRender::brushrender_t __near * CBrushBatchRender::FindOrCreateRenderBatch(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBrushBatchRender::brushrender_t *__thiscall CBrushBatchRender::FindOrCreateRenderBatch(
        CBrushBatchRender *this,
        model_t *pModel)
{
  bool v2; // zf
  CBrushBatchRender::brushrender_t *result; // eax
  DWORD CurrentThreadId; // ecx
  unsigned __int16 v6; // cx
  CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short> > *p_m_renderList; // edi
  CBrushBatchRender::brushrender_t *v8; // eax
  CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short> > *v9; // ecx
  CBrushBatchRender::brushrender_t *v10; // esi
  cplane_t *v11; // eax
  __int16 v12; // ax
  cplane_t **m_pMemory; // edx
  __int16 v14; // cx
  UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short> *v15; // eax
  int m_Size; // edi
  msurface2_t *v17; // ebx
  cplane_t *v18; // ecx
  int v19; // eax
  int v20; // ecx
  cplane_t **v21; // eax
  unsigned __int8 *v22; // eax
  int v23; // edi
  int *v24; // eax
  int v25; // edx
  cplane_t *p_planeIndex; // ecx
  int materialSortID; // ecx
  CBrushBatchRender::brushrendermesh_t *v28; // edi
  int *v29; // edi
  int v30; // ecx
  IMesh *v31; // edi
  int flags_high; // ecx
  int v33; // edi
  cplane_t *v34; // ecx
  unsigned __int8 *v35; // eax
  __int16 v36; // di
  unsigned __int8 *v37; // eax
  CBrushBatchRender::surfacelist_t *v38; // eax
  int m_nGrowSize; // edi
  int v40; // edi
  cplane_t **v41; // eax
  volatile __int32 *v42; // eax
  unsigned __int8 *v43; // [esp-10h] [ebp-A70h]
  unsigned int v44; // [esp-Ch] [ebp-A6Ch]
  CBrushBatchRender::brushrenderbatch_t tmpBatch[128]; // [esp+8h] [ebp-A58h] BYREF
  CBrushBatchRender::brushrendermesh_t tmpMesh[128]; // [esp+808h] [ebp-258h] BYREF
  CBrushBatchRender *v47; // [esp+A08h] [ebp-58h]
  CBrushBatchRender::surfacelist_t tmp; // [esp+A0Ch] [ebp-54h] BYREF
  int sortID; // [esp+A14h] [ebp-4Ch]
  CBrushBatchRender::brushrendermesh_t *pMesh; // [esp+A18h] [ebp-48h]
  msurface2_t *surfID; // [esp+A1Ch] [ebp-44h]
  CBrushBatchRender::brushrendermesh_t *v52; // [esp+A20h] [ebp-40h]
  int *p_sortID; // [esp+A24h] [ebp-3Ch]
  IMesh *pLastMesh; // [esp+A28h] [ebp-38h]
  CUtlVector<CBrushBatchRender::surfacelist_t,CUtlMemory<CBrushBatchRender::surfacelist_t,int> > surfaceList; // [esp+A2Ch] [ebp-34h] BYREF
  CUtlVector<cplane_t *,CUtlMemory<cplane_t *,int> > planeList; // [esp+A40h] [ebp-20h] BYREF
  int lastSortID; // [esp+A54h] [ebp-Ch]
  cplane_t *plane; // [esp+A58h] [ebp-8h]
  int i; // [esp+A5Ch] [ebp-4h]
  int batchCount; // [esp+A68h] [ebp+8h]

  v2 = pModel->brush.nummodelsurfaces == 0;
  v47 = this;
  if ( v2 )
    return nullptr;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)this, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: this, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  v6 = pModel->brush.renderHandle - 1;
  p_m_renderList = &this->m_renderList;
  if ( v6 >= this->m_renderList.m_Memory.m_nAllocationCount
    || v6 > this->m_renderList.m_LastAlloc.index
    || p_m_renderList->m_Memory.m_pMemory[v6].m_Previous == v6 && p_m_renderList->m_Memory.m_pMemory[v6].m_Next != v6 )
  {
    v8 = (CBrushBatchRender::brushrender_t *)MemAlloc_Alloc(nSize: 0x1Cu);
    v9 = &this->m_renderList;
    v10 = v8;
    v11 = (cplane_t *)(unsigned __int16)CUtlLinkedList<CBrushBatchRender::brushrender_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBrushBatchRender::brushrender_t *,unsigned short>,unsigned short>>::AllocInternal(
                                          this: v9,
                                          multilist: false);
    plane = v11;
    if ( (_WORD)v11 == 0xFFFF )
    {
      v12 = -1;
      m_pMemory = nullptr;
    }
    else
    {
      CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)p_m_renderList,
        before: 0xFFFFu,
        elem: (unsigned __int16)v11);
      v14 = (__int16)plane;
      v15 = &p_m_renderList->m_Memory.m_pMemory[(unsigned __int16)plane];
      m_pMemory = nullptr;
      if ( v15 != nullptr )
        v15->m_Element = v10;
      v12 = v14;
    }
    pModel->brush.renderHandle = v12 + 1;
    v10->pPlanes = nullptr;
    v10->pMeshes = nullptr;
    *(_DWORD *)&v10->planeCount = 0;
    *(_DWORD *)&v10->totalIndexCount = 0;
    m_Size = 0;
    v17 = (msurface2_t *)(*(_DWORD *)(pModel->sprite.numframes + 124) + 32 * pModel->brush.firstmodelsurface);
    memset(&planeList, 0, sizeof(planeList));
    memset(&surfaceList, 0, sizeof(surfaceList));
    for ( i = 0; i < pModel->brush.nummodelsurfaces; ++i )
    {
      if ( (v17->flags & 0x20) == 0 )
      {
        v18 = v17->plane;
        v19 = 0;
        plane = v18;
        if ( m_Size <= 0 )
          goto LABEL_25;
        while ( m_pMemory[v19] != v18 )
        {
          if ( ++v19 >= m_Size )
            goto LABEL_25;
        }
        if ( v19 == -1 )
        {
LABEL_25:
          v20 = m_Size;
          lastSortID = m_Size;
          if ( m_Size + 1 > planeList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&planeList,
              num: m_Size - planeList.m_Memory.m_nAllocationCount + 1);
            m_Size = planeList.m_Size;
            m_pMemory = planeList.m_Memory.m_pMemory;
            v20 = lastSortID;
          }
          planeList.m_Size = ++m_Size;
          planeList.m_pElements = m_pMemory;
          if ( m_Size - v20 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v20 + 1], src: &m_pMemory[v20], count: 4 * (m_Size - v20 - 1));
            m_pMemory = planeList.m_Memory.m_pMemory;
            v20 = lastSortID;
          }
          v21 = &m_pMemory[v20];
          if ( v21 != nullptr )
            *v21 = plane;
          LOWORD(v19) = v20;
        }
        tmp.planeIndex = v19;
        tmp.surfaceIndex = i;
        tmp.surfID = v17;
        CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
          this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&surfaceList,
          elem: surfaceList.m_Size,
          src: (const vgui::PropertySheet::Page_t *)&tmp);
        m_pMemory = planeList.m_Memory.m_pMemory;
      }
      ++v17;
    }
    CUtlVector<CBrushBatchRender::surfacelist_t,CUtlMemory<CBrushBatchRender::surfacelist_t,int>>::Sort(
      this: &surfaceList,
      pfnCompare: (int (__cdecl *)(const void *, const void *))CBrushBatchRender::SurfaceCmp);
    v22 = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)m_Size >> 30 != 0 ? -1 : 4 * m_Size);
    v43 = (unsigned __int8 *)planeList.m_Memory.m_pMemory;
    v10->pPlanes = (cplane_t **)v22;
    v10->planeCount = m_Size;
    memcpy(dst: v22, src: v43, count: 4 * m_Size);
    v23 = surfaceList.m_Size;
    v10->pSurfaces = (CBrushBatchRender::brushrendersurface_t *)MemAlloc_Alloc(
                                                                  nSize: (unsigned __int64)(unsigned int)surfaceList.m_Size >> 30 != 0
                                                                ? -1
                                                                : 4 * surfaceList.m_Size);
    v24 = nullptr;
    v25 = 0;
    v10->surfaceCount = v23;
    i = 0;
    batchCount = 0;
    lastSortID = -1;
    pLastMesh = nullptr;
    pMesh = nullptr;
    if ( v23 > 0 )
    {
      v52 = tmpMesh;
      p_sortID = &tmpBatch[0].sortID;
      p_planeIndex = (cplane_t *)&surfaceList.m_Memory.m_pMemory->planeIndex;
      plane = (cplane_t *)&surfaceList.m_Memory.m_pMemory->planeIndex;
      do
      {
        v10->pSurfaces[v25].surfaceIndex = *(_WORD *)p_planeIndex[-1].pad;
        v10->pSurfaces[v25].planeIndex = LOWORD(p_planeIndex->normal.x);
        surfID = *(msurface2_t **)((char *)&p_planeIndex[-1].dist + 2);
        materialSortID = surfID->materialSortID;
        sortID = materialSortID;
        if ( g_WorldStaticMeshes.m_Memory.m_pMemory[materialSortID] != pLastMesh )
        {
          v28 = v52;
          ++i;
          v52->firstBatch = batchCount;
          pMesh = v28;
          v28->batchCount = 0;
          lastSortID = -1;
          v52 = v28 + 1;
        }
        if ( materialSortID != lastSortID )
        {
          v29 = p_sortID;
          *p_sortID = materialSortID;
          v30 = *((unsigned __int16 *)surfID + 11) >> 1;
          *((_WORD *)v29 - 3) = 0;
          *(v29 - 1) = (int)host_state.worldbrush->texinfo[v30].material;
          ++pMesh->batchCount;
          ++batchCount;
          materialSortID = sortID;
          v24 = v29 - 2;
          v29[1] = 0;
          *((_WORD *)v29 - 4) = v25;
          p_sortID = v29 + 4;
        }
        v31 = g_WorldStaticMeshes.m_Memory.m_pMemory[materialSortID];
        ++*((_WORD *)v24 + 1);
        lastSortID = materialSortID;
        flags_high = HIBYTE(surfID->flags);
        v10->totalVertexCount += flags_high;
        pLastMesh = v31;
        v33 = 3 * flags_high - 6;
        v34 = plane;
        v24[3] += v33;
        v10->totalIndexCount += v33;
        ++v25;
        p_planeIndex = (cplane_t *)&v34->normal.z;
        plane = p_planeIndex;
      }
      while ( v25 < surfaceList.m_Size );
    }
    v35 = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)i >> 30 != 0 ? -1 : 4 * i);
    v36 = i;
    v44 = 4 * i;
    v10->pMeshes = (CBrushBatchRender::brushrendermesh_t *)v35;
    memcpy(dst: v35, src: (unsigned __int8 *)tmpMesh, count: v44);
    v10->meshCount = v36;
    v37 = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)batchCount >> 28 != 0 ? -1 : 16 * batchCount);
    v10->pBatches = (CBrushBatchRender::brushrenderbatch_t *)v37;
    memcpy(dst: v37, src: (unsigned __int8 *)tmpBatch, count: 16 * batchCount);
    v38 = surfaceList.m_Memory.m_pMemory;
    v10->batchCount = batchCount;
    m_nGrowSize = surfaceList.m_Memory.m_nGrowSize;
    surfaceList.m_Size = 0;
    if ( surfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v38 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v38);
        surfaceList.m_Memory.m_pMemory = nullptr;
        v38 = nullptr;
      }
      surfaceList.m_Memory.m_nAllocationCount = 0;
    }
    surfaceList.m_pElements = v38;
    if ( m_nGrowSize >= 0 )
    {
      if ( v38 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v38);
        surfaceList.m_Memory.m_pMemory = nullptr;
      }
      surfaceList.m_Memory.m_nAllocationCount = 0;
    }
    v40 = planeList.m_Memory.m_nGrowSize;
    v41 = planeList.m_Memory.m_pMemory;
    planeList.m_Size = 0;
    if ( planeList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( planeList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: planeList.m_Memory.m_pMemory);
        planeList.m_Memory.m_pMemory = nullptr;
        v41 = nullptr;
      }
      planeList.m_Memory.m_nAllocationCount = 0;
    }
    planeList.m_pElements = v41;
    if ( v40 >= 0 )
    {
      if ( v41 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
        planeList.m_Memory.m_pMemory = nullptr;
      }
      planeList.m_Memory.m_nAllocationCount = 0;
    }
    v42 = (volatile __int32 *)v47;
    v2 = v47->m_Mutex.m_depth-- == 1;
    if ( v2 )
      _InterlockedExchange(v42, 0);
    return v10;
  }
  else
  {
    result = p_m_renderList->m_Memory.m_pMemory[v6].m_Element;
    v2 = this->m_Mutex.m_depth-- == 1;
    if ( v2 )
      _InterlockedExchange((volatile __int32 *)this, 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066150
// Name: public: void CBrushBatchRender::DrawOpaqueBrushModel(class IMatRenderContext __near *,class IClientEntity __near *,struct model_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBrushBatchRender::DrawOpaqueBrushModel(
        CBrushBatchRender *this@<ecx>,
        CMeshBuilder *a2@<edi>,
        IMatRenderContext *pRenderContext,
        IClientEntity *baseentity,
        model_t *model,
        bool bShadowDepth)
{
  CBrushBatchRender::brushrender_t *RenderBatch; // ebx
  int planeCount; // ecx
  int v8; // edi
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  int v12; // edx
  _DWORD *v13; // eax
  char *v14; // esi
  int v15; // eax
  int v16; // edx
  S3RGBA *v17; // edx
  int m_nAllocationCount; // ecx
  __int16 *v19; // edi
  __int16 *v20; // esi
  int v21; // edi
  unsigned int v22; // ebx
  S3RGBA *v23; // eax
  int v24; // esi
  int v25; // edi
  unsigned int v26; // ebx
  S3RGBA *v27; // eax
  CBrushBatchRender::brushrenderbatch_t *v28; // edi
  int v29; // ebx
  int surfaceCount; // eax
  __int16 *p_planeIndex; // ecx
  BOOL v32; // ebx
  IMaterial *v33; // esi
  int v34; // eax
  IMaterial *pMaterial; // ecx
  IMaterial_vtbl *v36; // edx
  int v37; // eax
  IMaterial *v38; // ecx
  IMaterial_vtbl *v39; // edx
  int v40; // eax
  IMaterial_vtbl *v41; // edx
  unsigned __int8 *v42; // ebx
  IMaterialVar *(__thiscall *FindVarFast)(IMaterial *, const char *, unsigned int *); // eax
  int v44; // eax
  IMaterial_vtbl *v45; // edx
  int v46; // ebx
  int v47; // eax
  int v48; // eax
  IMesh *v49; // eax
  CBrushBatchRender::brushrendersurface_t *pSurfaces; // edx
  int v51; // eax
  int planeIndex; // ecx
  CBrushBatchRender::brushrendersurface_t *v53; // eax
  msurface2_t *v54; // esi
  unsigned __int8 *v55; // eax
  S3RGBA *v56; // ebx
  unsigned int v57; // ebx
  S3RGBA *v58; // ecx
  int v59; // eax
  msurface2_t **v60; // ecx
  CBrushBatchRender::brushrendermesh_t *v61; // ebx
  int v62; // ecx
  int m_nVertexCount; // eax
  int batchCount; // edx
  S3RGBA *v65; // eax
  S3RGBA *v66; // edx
  int v67; // ecx
  CBrushBatchRender::brushrendermesh_t *v68; // eax
  int v69; // edx
  int v70; // esi
  IMaterial *v71; // edi
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // edx
  IMesh *v73; // eax
  CBrushBatchRender::brushrendermesh_t *v74; // ebx
  S3RGBA *v75; // esi
  int v76; // eax
  int v77; // ecx
  int v78; // esi
  CBrushBatchRender::brushrendermesh_t *v79; // edx
  msurface2_t **v80; // ebx
  model_t *v81; // edi
  CBrushBatchRender::brushrenderbatch_t *v82; // eax
  int v83; // ecx
  CBrushBatchRender::brushrendersurface_t *v84; // eax
  S3RGBA v85; // ebx
  int v86; // edi
  S3RGBA *v87; // edi
  S3RGBA *v88; // eax
  S3RGBA *v89; // eax
  S3RGBA *v90; // eax
  float v91; // [esp+60h] [ebp-1420h]
  int v93; // [esp+70h] [ebp-1410h] BYREF
  _DWORD v94[1023]; // [esp+74h] [ebp-140Ch] BYREF
  CUtlMemory<S3RGBA,int> v95; // [esp+1070h] [ebp-410h] BYREF
  int v96; // [esp+107Ch] [ebp-404h]
  _BYTE v97[256]; // [esp+1080h] [ebp-400h] BYREF
  unsigned __int8 *v98; // [esp+1180h] [ebp-300h]
  S3RGBA *v99; // [esp+1184h] [ebp-2FCh]
  CMeshBuilder v100; // [esp+1188h] [ebp-2F8h] BYREF
  int pVertexCount; // [esp+1370h] [ebp-110h] BYREF
  CUtlMemory<S3RGBA,int> v102; // [esp+1374h] [ebp-10Ch] BYREF
  int v103; // [esp+1380h] [ebp-100h]
  _BYTE v104[64]; // [esp+1384h] [ebp-FCh] BYREF
  int v105; // [esp+13C4h] [ebp-BCh]
  S3RGBA *v106; // [esp+13C8h] [ebp-B8h]
  int v107; // [esp+13CCh] [ebp-B4h] BYREF
  int v108; // [esp+13D0h] [ebp-B0h] BYREF
  int v109; // [esp+13D4h] [ebp-ACh] BYREF
  float v110; // [esp+13D8h] [ebp-A8h]
  CUtlMemory<S3RGBA,int> src; // [esp+13DCh] [ebp-A4h] BYREF
  int v112; // [esp+13E8h] [ebp-98h]
  _BYTE v113[64]; // [esp+13ECh] [ebp-94h] BYREF
  __int16 *v114; // [esp+142Ch] [ebp-54h]
  S3RGBA *m_pMemory; // [esp+1430h] [ebp-50h]
  int v116; // [esp+1434h] [ebp-4Ch]
  int v117; // [esp+1438h] [ebp-48h]
  CUtlMemory<S3RGBA,int> v118; // [esp+143Ch] [ebp-44h] BYREF
  int v119; // [esp+1448h] [ebp-38h]
  S3RGBA *v120; // [esp+144Ch] [ebp-34h]
  CBrushBatchRender::brushrendermesh_t *v121; // [esp+1450h] [ebp-30h]
  IClientRenderable *v122; // [esp+1454h] [ebp-2Ch]
  S3RGBA *v123; // [esp+1458h] [ebp-28h]
  int pIndexCount; // [esp+145Ch] [ebp-24h] BYREF
  int v125; // [esp+1460h] [ebp-20h]
  int v126; // [esp+1464h] [ebp-1Ch]
  int v127; // [esp+1468h] [ebp-18h]
  IMaterial *v128; // [esp+146Ch] [ebp-14h]
  CBrushBatchRender::brushrendermesh_t *v129; // [esp+1470h] [ebp-10h]
  int num; // [esp+1474h] [ebp-Ch]
  S3RGBA *v131; // [esp+1478h] [ebp-8h]
  CBrushBatchRender::brushrender_t *v132; // [esp+147Ch] [ebp-4h]
  char *v133; // [esp+148Ch] [ebp+Ch]
  int v134; // [esp+148Ch] [ebp+Ch]
  int i; // [esp+148Ch] [ebp+Ch]
  int j; // [esp+148Ch] [ebp+Ch]
  model_t *pModel; // [esp+1490h] [ebp+10h]
  char pModel_3; // [esp+1493h] [ebp+13h]
  int v139; // [esp+1494h] [ebp+14h]
  int v140; // [esp+1494h] [ebp+14h]

  v117 = *(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface;
  RenderBatch = CBrushBatchRender::FindOrCreateRenderBatch(this, pModel: model);
  v132 = RenderBatch;
  if ( RenderBatch != nullptr )
  {
    pModel_3 = 0;
    if ( g_pMaterialSystemConfig->nFullbright == 1 || bShadowDepth )
    {
      ((void (__stdcall *)(int))pRenderContext->BindLightmapPage)(a1: -2);
      pModel_3 = 1;
    }
    if ( baseentity != nullptr )
      v122 = baseentity->GetClientRenderable(this: baseentity);
    else
      v122 = nullptr;
    if ( bShadowDepth )
    {
      planeCount = RenderBatch->planeCount;
      if ( planeCount > 0 )
        memset(&v93, 0, 4 * planeCount);
    }
    else
    {
      v8 = RenderBatch->planeCount;
      z = modelorg.z;
      y = modelorg.y;
      x = modelorg.x;
      v12 = 0;
      if ( v8 >= 4 )
      {
        v133 = (char *)((char *)&v93 - (char *)RenderBatch->pPlanes);
        v13 = RenderBatch->pPlanes + 2;
        v129 = (CBrushBatchRender::brushrendermesh_t *)((char *)v94 - (char *)RenderBatch->pPlanes);
        do
        {
          v94[v12 - 1] = (float)((float)((float)((float)(*(float *)(*(v13 - 2) + 4) * y)
                                               + (float)(*(float *)*(v13 - 2) * x))
                                       + (float)(*(float *)(*(v13 - 2) + 8) * z))
                               - *(float *)(*(v13 - 2) + 12)) < -0.0099999998;
          v94[v12] = (float)((float)((float)((float)(*(float *)(*(v13 - 1) + 4) * y) + (float)(*(float *)*(v13 - 1) * x))
                                   + (float)(*(float *)(*(v13 - 1) + 8) * z))
                           - *(float *)(*(v13 - 1) + 12)) < -0.0099999998;
          *(_DWORD *)((char *)v13 + (_DWORD)v133) = (float)((float)((float)((float)(*(float *)(*v13 + 4) * y)
                                                                          + (float)(*(float *)*v13 * x))
                                                                  + (float)(*(float *)(*v13 + 8) * z))
                                                          - *(float *)(*v13 + 12)) < -0.0099999998;
          *(_DWORD *)((char *)v13 + (_DWORD)v129) = (float)((float)((float)((float)(*(float *)(v13[1] + 4) * y)
                                                                          + (float)(*(float *)v13[1] * x))
                                                                  + (float)(*(float *)(v13[1] + 8) * z))
                                                          - *(float *)(v13[1] + 12)) < -0.0099999998;
          v12 += 4;
          v13 += 4;
        }
        while ( v12 < v8 - 3 );
      }
      if ( v12 < v8 )
      {
        v14 = (char *)((char *)&v93 - (char *)RenderBatch->pPlanes);
        v15 = (int)&RenderBatch->pPlanes[v12];
        v16 = v8 - v12;
        do
        {
          *(_DWORD *)&v14[v15] = (float)((float)((float)((float)(*(float *)(*(_DWORD *)v15 + 4) * y)
                                                       + (float)(**(float **)v15 * x))
                                               + (float)(*(float *)(*(_DWORD *)v15 + 8) * z))
                                       - *(float *)(*(_DWORD *)v15 + 12)) < -0.0099999998;
          v15 += 4;
          --v16;
        }
        while ( v16 != 0 );
      }
    }
    v95.m_pMemory = (S3RGBA *)v97;
    v95.m_nGrowSize = -1;
    src.m_nGrowSize = -1;
    v99 = (S3RGBA *)v97;
    m_pMemory = (S3RGBA *)v113;
    v17 = (S3RGBA *)v104;
    src.m_pMemory = (S3RGBA *)v113;
    m_nAllocationCount = 16;
    v19 = nullptr;
    v95.m_nAllocationCount = 64;
    v96 = 0;
    v98 = nullptr;
    src.m_nAllocationCount = 16;
    v112 = 0;
    v114 = nullptr;
    v102.m_pMemory = (S3RGBA *)v104;
    v102.m_nAllocationCount = 16;
    v102.m_nGrowSize = -1;
    v103 = 0;
    v105 = 0;
    v106 = (S3RGBA *)v104;
    v134 = 0;
    if ( RenderBatch->meshCount > 0 )
    {
      do
      {
        v129 = &v132->pMeshes[v134];
        v125 = 0;
        if ( v129->batchCount > 0 )
        {
          do
          {
            v121 = (CBrushBatchRender::brushrendermesh_t *)v19;
            v20 = v19;
            if ( (int)v19 + 1 > m_nAllocationCount )
            {
              v21 = (int)v19 - m_nAllocationCount + 1;
              if ( src.m_nGrowSize < 0 )
              {
                src.m_nGrowSize = v112;
                if ( m_nAllocationCount != 0 )
                {
                  v22 = 4 * m_nAllocationCount;
                  v131 = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nAllocationCount);
                  memcpy(dst: (unsigned __int8 *)v131, src: (unsigned __int8 *)src.m_pMemory, count: v22);
                  src.m_pMemory = v131;
                }
                else
                {
                  src.m_pMemory = nullptr;
                }
              }
              CUtlMemory<INetMessage *,int>::Grow(this: &src, num: v21);
            }
            v114 = (__int16 *)((char *)v114 + 1);
            m_pMemory = src.m_pMemory;
            if ( (char *)v114 - (char *)v20 - 1 > 0 )
              _V_memmove(
                dest: &src.m_pMemory[(_DWORD)v20 + 1],
                src: &src.m_pMemory[(_DWORD)v20],
                count: 4 * ((char *)v114 - (char *)v20 - 1));
            v23 = &src.m_pMemory[(_DWORD)v20];
            if ( v23 != nullptr )
              *v23 = 0;
            v24 = v105;
            if ( v105 + 1 > v102.m_nAllocationCount )
            {
              v25 = v105 - v102.m_nAllocationCount + 1;
              if ( v102.m_nGrowSize < 0 )
              {
                v102.m_nGrowSize = v103;
                if ( v102.m_nAllocationCount != 0 )
                {
                  v26 = 4 * v102.m_nAllocationCount;
                  v131 = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v102.m_nAllocationCount);
                  memcpy(dst: (unsigned __int8 *)v131, src: (unsigned __int8 *)v102.m_pMemory, count: v26);
                  v102.m_pMemory = v131;
                }
                else
                {
                  v102.m_pMemory = nullptr;
                }
              }
              CUtlMemory<INetMessage *,int>::Grow(this: &v102, num: v25);
            }
            ++v105;
            v106 = v102.m_pMemory;
            if ( v105 - v24 - 1 > 0 )
              _V_memmove(dest: &v102.m_pMemory[v24 + 1], src: &v102.m_pMemory[v24], count: 4 * (v105 - v24 - 1));
            v27 = &v102.m_pMemory[v24];
            if ( v27 != nullptr )
              *v27 = 0;
            v28 = &v132->pBatches[v125 + v129->firstBatch];
            v29 = 0;
            surfaceCount = v28->surfaceCount;
            v127 = 0;
            if ( surfaceCount > 0 )
            {
              p_planeIndex = &v132->pSurfaces[v28->firstSurface].planeIndex;
              do
              {
                if ( v94[*p_planeIndex - 1] == 0 )
                  break;
                ++v29;
                p_planeIndex += 2;
              }
              while ( v29 < surfaceCount );
              v127 = v29;
            }
            if ( v29 != surfaceCount )
            {
              v100.m_pMesh = nullptr;
              v100.m_bGenerateIndices = false;
              memset(&v100.m_IndexBuilder.m_pIndexBuffer, 0, 12);
              v100.m_IndexBuilder.m_nCurrentIndex = 0;
              v100.m_IndexBuilder.m_nTotalIndexCount = 0;
              v100.m_IndexBuilder.m_nBufferOffset = -1;
              v100.m_IndexBuilder.m_nBufferFirstIndex = 0;
              v100.m_VertexBuilder.m_pVertexBuffer = nullptr;
              v100.m_VertexBuilder.m_nBufferOffset = -1;
              v100.m_VertexBuilder.m_nBufferFirstVertex = 0;
              memset(&v100.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
              v100.m_VertexBuilder.m_nTotalVertexCount = 0;
              v100.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
              if ( bShadowDepth )
              {
                v32 = v28->pMaterial->IsAlphaTested(this: v28->pMaterial);
                v33 = g_pMaterialDepthWrite[v32][(unsigned __int8)v28->pMaterial->IsTwoSided(this: v28->pMaterial)];
                if ( v32 )
                {
                  v34 = (int)v28->pMaterial->FindVarFast(
                               this: v28->pMaterial,
                               a2: "$basetexture",
                               a3: &originalTextureVarCache_0);
                  pMaterial = v28->pMaterial;
                  v36 = pMaterial->__vftable;
                  v128 = (IMaterial *)v34;
                  v37 = (int)v36->FindVarFast(this: pMaterial, a2: "$frame", a3: &originalTextureFrameVarCache_0);
                  v38 = v28->pMaterial;
                  v39 = v38->__vftable;
                  v116 = v37;
                  v40 = (int)v39->FindVarFast(this: v38, a2: "$AlphaTestReference", a3: &originalAlphaRefCache_0);
                  v41 = v33->__vftable;
                  num = v40;
                  v42 = (unsigned __int8 *)v41->FindVarFast(this: v33, a2: "$basetexture", a3: &textureVarCache_0);
                  FindVarFast = v33->FindVarFast;
                  v123 = (S3RGBA *)v42;
                  v44 = (int)FindVarFast(this: v33, a2: "$frame", a3: &textureFrameVarCache_0);
                  v45 = v33->__vftable;
                  v126 = v44;
                  v131 = (S3RGBA *)v45->FindVarFast(this: v33, a2: "$AlphaTestReference", a3: &alphaRefCache_0);
                  if ( v42 != nullptr && v128 != nullptr )
                  {
                    v46 = *(_DWORD *)v42;
                    v47 = v128->GetName(this: v128);
                    (*(void (__thiscall **)(S3RGBA *, int))(v46 + 60))(a1: v123, a2: v47);
                  }
                  if ( v126 != 0 && v116 != 0 )
                  {
                    v48 = (*(int (__thiscall **)(int))(*(_DWORD *)v116 + 108))(a1: v116);
                    (*(void (__thiscall **)(int, int))(*(_DWORD *)v126 + 20))(a1: v126, a2: v48);
                  }
                  if ( v131 != nullptr && num != 0 )
                  {
                    v91 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)num + 112))(a1: num);
                    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v131 + 16))(a1: LODWORD(v91));
                  }
                }
                v29 = v127;
                v128 = v33;
              }
              else
              {
                v33 = v28->pMaterial;
                v128 = v33;
                if ( g_bIsBlendingOrModulating )
                {
                  v110 = v33->GetAlphaModulation(this: v33);
                  v33->GetColorModulation(this: v33, a2: (float *)&v107, a3: (float *)&v108, a4: (float *)&v109);
                  ((void (__thiscall *)(IMaterial *, _DWORD))v33->AlphaModulate)(a1: v33, a2: LODWORD(r_blend));
                  ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))v33->ColorModulate)(
                    a1: v33,
                    a2: LODWORD(r_colormod.x),
                    a3: LODWORD(r_colormod.y),
                    a4: LODWORD(r_colormod.z));
                }
                if ( pModel_3 == 0 )
                  pRenderContext->BindLightmapPage(
                    this: pRenderContext,
                    a2: materialSortInfoArray[v28->sortID].lightmapPageID);
              }
              ((void (__thiscall *)(IMatRenderContext *, IMaterial *, IClientRenderable *, CMeshBuilder *))pRenderContext->Bind)(
                a1: pRenderContext,
                a2: v33,
                a3: v122,
                a4: a2);
              v49 = pRenderContext->GetDynamicMesh(
                      this: pRenderContext,
                      a2: 0,
                      a3: g_WorldStaticMeshes.m_Memory.m_pMemory[v28->sortID],
                      a4: 0,
                      a5: 0);
              CMeshBuilder::Begin(
                this: &v100,
                pMesh: v49,
                type: MATERIAL_TRIANGLES,
                nVertexCount: 0,
                nIndexCount: v28->indexCount,
                pMeshSettings: nullptr);
              if ( v29 < v28->surfaceCount )
              {
                while ( 1 )
                {
                  pSurfaces = v132->pSurfaces;
                  v51 = v29 + v28->firstSurface;
                  planeIndex = pSurfaces[v51].planeIndex;
                  v53 = &pSurfaces[v51];
                  if ( v94[planeIndex - 1] == 0 )
                  {
                    v54 = (msurface2_t *)(v117 + 32 * v53->surfaceIndex);
                    if ( !bShadowDepth && (v54->flags & 0x200000) != 0 )
                    {
                      v55 = v98;
                      v56 = (S3RGBA *)v98;
                      v131 = (S3RGBA *)v98;
                      if ( (int)(v98 + 1) > v95.m_nAllocationCount )
                      {
                        num = (int)&v98[-v95.m_nAllocationCount + 1];
                        if ( v95.m_nGrowSize < 0 )
                        {
                          v95.m_nGrowSize = v96;
                          if ( v95.m_nAllocationCount != 0 )
                          {
                            v57 = 4 * v95.m_nAllocationCount;
                            v123 = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v95.m_nAllocationCount);
                            memcpy(dst: (unsigned __int8 *)v123, src: (unsigned __int8 *)v95.m_pMemory, count: v57);
                            v56 = v131;
                            v95.m_pMemory = v123;
                          }
                          else
                          {
                            v95.m_pMemory = nullptr;
                          }
                        }
                        CUtlMemory<INetMessage *,int>::Grow(this: &v95, num);
                        v55 = v98;
                      }
                      v58 = v95.m_pMemory;
                      v98 = v55 + 1;
                      v59 = v55 - (unsigned __int8 *)v56;
                      v99 = v95.m_pMemory;
                      if ( v59 > 0 )
                      {
                        _V_memmove(
                          dest: &v95.m_pMemory[(_DWORD)v56 + 1],
                          src: &v95.m_pMemory[(_DWORD)v56],
                          count: 4 * v59);
                        v58 = v95.m_pMemory;
                      }
                      v60 = (msurface2_t **)&v58[(_DWORD)v56];
                      if ( v60 != nullptr )
                        *v60 = v54;
                      v61 = v121;
                      ++*(_DWORD *)&src.m_pMemory[(_DWORD)v121];
                      Shader_GetSurfVertexAndIndexCount(surfaceHandle: v54, &pVertexCount, &pIndexCount);
                      *(_DWORD *)&v102.m_pMemory[(_DWORD)v61] += pIndexCount;
                      v29 = v127;
                    }
                    BuildIndicesForSurface(meshBuilder: &v100.m_IndexBuilder, surfID: v54);
                    if ( v54->decals == 0xFFFF )
                    {
                      if ( !bShadowDepth )
                        goto LABEL_80;
                    }
                    else if ( !bShadowDepth )
                    {
                      DecalSurfaceAdd(surfID: v54, iGroup: 4);
LABEL_80:
                      if ( v54->m_ShadowDecals != 0xFFFF )
                        g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: v54->m_ShadowDecals);
                    }
                  }
                  v62 = v28->surfaceCount;
                  v127 = ++v29;
                  if ( v29 >= v62 )
                  {
                    v33 = v128;
                    break;
                  }
                }
              }
              if ( v100.m_bGenerateIndices )
              {
                switch ( v100.m_Type )
                {
                  case MATERIAL_LINE_STRIP:
                    m_nVertexCount = 2 * v100.m_VertexBuilder.m_nVertexCount - 2;
                    break;
                  case MATERIAL_LINE_LOOP:
                    m_nVertexCount = 2 * v100.m_VertexBuilder.m_nVertexCount;
                    break;
                  case MATERIAL_POLYGON:
                    m_nVertexCount = 3 * v100.m_VertexBuilder.m_nVertexCount - 6;
                    break;
                  case MATERIAL_QUADS:
                    m_nVertexCount = 6 * v100.m_VertexBuilder.m_nVertexCount / 4;
                    break;
                  case MATERIAL_INSTANCED_QUADS:
                    m_nVertexCount = 0;
                    break;
                  default:
                    m_nVertexCount = v100.m_VertexBuilder.m_nVertexCount;
                    break;
                }
                CIndexBuilder::GenerateIndices(
                  this: &v100.m_IndexBuilder,
                  primitiveType: v100.m_Type,
                  nIndexCount: m_nVertexCount);
              }
              a2 = &v100;
              ((void (__thiscall *)(IMesh *, int, int))v100.m_pMesh->UnlockMesh)(
                a1: v100.m_pMesh,
                a2: v100.m_VertexBuilder.m_nVertexCount,
                a3: v100.m_IndexBuilder.m_nIndexCount);
              v100.m_IndexBuilder.m_pIndexBuffer = nullptr;
              v100.m_IndexBuilder.m_nMaxIndexCount = 0;
              v100.m_VertexBuilder.m_nMaxVertexCount = 0;
              v100.m_VertexBuilder.m_pVertexBuffer = nullptr;
              v100.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
              v100.m_pMesh->Draw_2(this: v100.m_pMesh, a2: -1, a3: 0);
              v100.m_pMesh = nullptr;
              if ( !bShadowDepth && g_bIsBlendingOrModulating )
              {
                v33->AlphaModulate(this: v33, a2: COERCE_FLOAT(LODWORD(v110)));
                ((void (__thiscall *)(IMaterial *, int, int, int))v33->ColorModulate)(
                  a1: v33,
                  a2: v107,
                  a3: v108,
                  a4: v109);
              }
              if ( v100.m_VertexBuilder.m_pVertexBuffer != nullptr
                && v100.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v100.m_VertexBuilder.m_pVertexBuffer) )
              {
                v100.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v100.m_VertexBuilder.m_pVertexBuffer);
              }
              if ( v100.m_IndexBuilder.m_pIndexBuffer != nullptr
                && v100.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v100.m_IndexBuilder.m_pIndexBuffer) )
              {
                v100.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v100.m_IndexBuilder.m_pIndexBuffer);
              }
            }
            batchCount = v129->batchCount;
            v19 = v114;
            m_nAllocationCount = src.m_nAllocationCount;
            ++v125;
          }
          while ( v125 < batchCount );
          v17 = v102.m_pMemory;
        }
        ++v134;
      }
      while ( v134 < v132->meshCount );
    }
    if ( bShadowDepth )
    {
      v105 = 0;
      if ( v102.m_nGrowSize >= 0 )
      {
        if ( v17 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
          v17 = nullptr;
          v102.m_pMemory = nullptr;
        }
        v102.m_nAllocationCount = 0;
      }
      v106 = v17;
      if ( v102.m_nGrowSize >= 0 )
      {
        if ( v17 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
          v102.m_pMemory = nullptr;
        }
        v102.m_nAllocationCount = 0;
      }
      v65 = src.m_pMemory;
      v114 = nullptr;
      if ( src.m_nGrowSize >= 0 )
      {
        if ( src.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_pMemory);
          v65 = nullptr;
          src.m_pMemory = nullptr;
        }
        src.m_nAllocationCount = 0;
      }
      v66 = v95.m_pMemory;
      m_pMemory = v65;
      if ( src.m_nGrowSize >= 0 )
      {
        if ( v65 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v65);
          src.m_pMemory = nullptr;
        }
        v66 = v95.m_pMemory;
        src.m_nAllocationCount = 0;
      }
      v98 = nullptr;
      if ( v95.m_nGrowSize >= 0 )
      {
        if ( v66 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66);
          v66 = nullptr;
          v95.m_pMemory = nullptr;
        }
        v95.m_nAllocationCount = 0;
      }
      v99 = v66;
      if ( v95.m_nGrowSize >= 0 && v66 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66);
    }
    else
    {
      if ( v98 != nullptr )
      {
        ((void (__thiscall *)(IMatRenderContext *, int, CMeshBuilder *))pRenderContext->__vftable[1].EndRender)(
          a1: pRenderContext,
          a2: 1,
          a3: a2);
        v67 = 0;
        v139 = 0;
        v131 = nullptr;
        for ( i = 0; v67 < v132->meshCount; i = ++v67 )
        {
          v68 = &v132->pMeshes[v67];
          v69 = 0;
          num = (int)v68;
          v126 = 0;
          if ( v68->batchCount > 0 )
          {
            do
            {
              v129 = (CBrushBatchRender::brushrendermesh_t *)src.m_pMemory[v139];
              if ( (int)v129 > 0 )
              {
                v70 = (int)&v132->pBatches[v69 + v68->firstBatch];
                v71 = *(IMaterial **)(v70 + 4);
                if ( pModel_3 == 0 )
                  pRenderContext->BindLightmapPage(
                    this: pRenderContext,
                    a2: materialSortInfoArray[*(_DWORD *)(v70 + 8)].lightmapPageID);
                pRenderContext->Bind(this: pRenderContext, a2: v71, a3: (void *)v122);
                GetDynamicMesh = pRenderContext->GetDynamicMesh;
                v100.m_IndexBuilder.m_nBufferOffset = -1;
                v100.m_VertexBuilder.m_nBufferOffset = -1;
                v100.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                v100.m_pMesh = nullptr;
                v100.m_bGenerateIndices = false;
                memset(&v100.m_IndexBuilder.m_pIndexBuffer, 0, 12);
                v100.m_IndexBuilder.m_nCurrentIndex = 0;
                v100.m_IndexBuilder.m_nTotalIndexCount = 0;
                v100.m_IndexBuilder.m_nBufferFirstIndex = 0;
                v100.m_VertexBuilder.m_pVertexBuffer = nullptr;
                v100.m_VertexBuilder.m_nBufferFirstVertex = 0;
                memset(&v100.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
                v100.m_VertexBuilder.m_nTotalVertexCount = 0;
                v73 = GetDynamicMesh(
                        this: pRenderContext,
                        a2: false,
                        a3: g_WorldStaticMeshes.m_Memory.m_pMemory[*(_DWORD *)(v70 + 8)],
                        a4: nullptr,
                        a5: nullptr);
                CMeshBuilder::Begin(
                  this: &v100,
                  pMesh: v73,
                  type: MATERIAL_TRIANGLES,
                  nVertexCount: 0,
                  nIndexCount: *(_DWORD *)&v102.m_pMemory[v139],
                  pMeshSettings: nullptr);
                if ( (int)v129 > 0 )
                {
                  v74 = v129;
                  v75 = v131;
                  do
                  {
                    BuildIndicesForSurface(
                      meshBuilder: &v100.m_IndexBuilder,
                      surfID: *(msurface2_t **)&v95.m_pMemory[(_DWORD)v75]);
                    v75 = (S3RGBA *)((char *)v75 + 1);
                    v74 = (CBrushBatchRender::brushrendermesh_t *)((char *)v74 - 1);
                  }
                  while ( v74 != nullptr );
                  v131 = v75;
                }
                if ( v100.m_bGenerateIndices )
                {
                  switch ( v100.m_Type )
                  {
                    case MATERIAL_LINE_STRIP:
                      v76 = 2 * v100.m_VertexBuilder.m_nVertexCount - 2;
                      break;
                    case MATERIAL_LINE_LOOP:
                      v76 = 2 * v100.m_VertexBuilder.m_nVertexCount;
                      break;
                    case MATERIAL_POLYGON:
                      v76 = 3 * v100.m_VertexBuilder.m_nVertexCount - 6;
                      break;
                    case MATERIAL_QUADS:
                      v76 = 6 * v100.m_VertexBuilder.m_nVertexCount / 4;
                      break;
                    case MATERIAL_INSTANCED_QUADS:
                      v76 = 0;
                      break;
                    default:
                      v76 = v100.m_VertexBuilder.m_nVertexCount;
                      break;
                  }
                  CIndexBuilder::GenerateIndices(
                    this: &v100.m_IndexBuilder,
                    primitiveType: v100.m_Type,
                    nIndexCount: v76);
                }
                v100.m_pMesh->UnlockMesh(
                  this: v100.m_pMesh,
                  a2: v100.m_VertexBuilder.m_nVertexCount,
                  a3: v100.m_IndexBuilder.m_nIndexCount,
                  a4: &v100);
                v100.m_IndexBuilder.m_pIndexBuffer = nullptr;
                v100.m_IndexBuilder.m_nMaxIndexCount = 0;
                v100.m_VertexBuilder.m_nMaxVertexCount = 0;
                v100.m_VertexBuilder.m_pVertexBuffer = nullptr;
                v100.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                v100.m_pMesh->Draw_2(this: v100.m_pMesh, a2: -1, a3: 0);
                v100.m_pMesh = nullptr;
                if ( v100.m_VertexBuilder.m_pVertexBuffer != nullptr
                  && v100.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v100.m_VertexBuilder.m_pVertexBuffer) )
                {
                  v100.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v100.m_VertexBuilder.m_pVertexBuffer);
                }
                if ( v100.m_IndexBuilder.m_pIndexBuffer != nullptr
                  && v100.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v100.m_IndexBuilder.m_pIndexBuffer) )
                {
                  v100.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v100.m_IndexBuilder.m_pIndexBuffer);
                }
                v68 = (CBrushBatchRender::brushrendermesh_t *)num;
              }
              v77 = v68->batchCount;
              ++v139;
              v69 = v126 + 1;
              v126 = v69;
            }
            while ( v69 < v77 );
            v67 = i;
          }
        }
        ((void (__thiscall *)(IMatRenderContext *, _DWORD))pRenderContext->__vftable[1].EndRender)(
          a1: pRenderContext,
          a2: 0);
      }
      if ( g_ShaderDebug.anydebug )
      {
        for ( j = 0; j < v132->meshCount; ++j )
        {
          v78 = 0;
          v79 = &v132->pMeshes[j];
          v80 = nullptr;
          v81 = nullptr;
          v121 = v79;
          memset(&v118, 0, sizeof(v118));
          v119 = 0;
          v120 = nullptr;
          pModel = nullptr;
          if ( v79->batchCount > 0 )
          {
            do
            {
              v82 = &v132->pBatches[(int)v81 + v79->firstBatch];
              v83 = 0;
              pIndexCount = (int)v82;
              v140 = 0;
              if ( v82->surfaceCount > 0 )
              {
                do
                {
                  v84 = &v132->pSurfaces[v83 + v82->firstSurface];
                  if ( v94[v84->planeIndex - 1] == 0 )
                  {
                    v85 = (S3RGBA)(v117 + 32 * v84->surfaceIndex);
                    v86 = v78;
                    if ( v78 + 1 > v118.m_nAllocationCount )
                    {
                      CUtlMemory<INetMessage *,int>::Grow(this: &v118, num: v78 - v118.m_nAllocationCount + 1);
                      v78 = v119;
                    }
                    v119 = ++v78;
                    v120 = v118.m_pMemory;
                    if ( v78 - v86 - 1 > 0 )
                      _V_memmove(dest: &v118.m_pMemory[v86 + 1], src: &v118.m_pMemory[v86], count: 4 * (v78 - v86 - 1));
                    v87 = &v118.m_pMemory[v86];
                    if ( v87 != nullptr )
                      *v87 = v85;
                  }
                  v82 = (CBrushBatchRender::brushrenderbatch_t *)pIndexCount;
                  v83 = v140 + 1;
                  v140 = v83;
                }
                while ( v83 < *(__int16 *)(pIndexCount + 2) );
                v81 = pModel;
                v79 = v121;
              }
              v81 = (model_t *)((char *)v81 + 1);
              pModel = v81;
            }
            while ( (int)v81 < v79->batchCount );
            v80 = (msurface2_t **)v118.m_pMemory;
          }
          DrawDebugInformation(pRenderContext, pList: v80, listCount: v78);
          if ( v118.m_nGrowSize >= 0 && v80 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v80);
        }
      }
      v88 = v102.m_pMemory;
      v105 = 0;
      if ( v102.m_nGrowSize >= 0 )
      {
        if ( v102.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v102.m_pMemory);
          v88 = nullptr;
          v102.m_pMemory = nullptr;
        }
        v102.m_nAllocationCount = 0;
      }
      v106 = v88;
      if ( v102.m_nGrowSize >= 0 )
      {
        if ( v88 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v88);
          v102.m_pMemory = nullptr;
        }
        v102.m_nAllocationCount = 0;
      }
      v89 = src.m_pMemory;
      v114 = nullptr;
      if ( src.m_nGrowSize >= 0 )
      {
        if ( src.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_pMemory);
          v89 = nullptr;
          src.m_pMemory = nullptr;
        }
        src.m_nAllocationCount = 0;
      }
      m_pMemory = v89;
      if ( src.m_nGrowSize >= 0 )
      {
        if ( v89 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v89);
          src.m_pMemory = nullptr;
        }
        src.m_nAllocationCount = 0;
      }
      v90 = v95.m_pMemory;
      v98 = nullptr;
      if ( v95.m_nGrowSize >= 0 )
      {
        if ( v95.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v95.m_pMemory);
          v90 = nullptr;
          v95.m_pMemory = nullptr;
        }
        v95.m_nAllocationCount = 0;
      }
      v99 = v90;
      if ( v95.m_nGrowSize >= 0 && v90 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v90);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100672D0
// Name: public: void CBrushBatchRender::DrawTranslucentBrushModel(class IMatRenderContext __near *,class IClientEntity __near *,struct model_t __near *,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawTranslucentBrushModel(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        IClientEntity *baseentity,
        model_t *model,
        bool bShadowDepth,
        bool bDrawOpaque,
        bool bDrawTranslucent)
{
  if ( bDrawOpaque )
    CBrushBatchRender::DrawOpaqueBrushModel(
      this,
      a2: (CMeshBuilder *)model,
      pRenderContext,
      baseentity,
      model,
      bShadowDepth);
  if ( !bShadowDepth && bDrawTranslucent )
    CBrushBatchRender::DrawTranslucentBrushModel(
      this,
      a2: (CMeshBuilder *)baseentity,
      a3: (int)model,
      pRenderContext,
      model,
      baseentity);
}

//------------------------------------------------------------------------------
// Address: 0x10067320
// Name: public: void CBrushBatchRender::DrawBrushModelShadow(class IMatRenderContext __near *,struct model_t __near *,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBrushBatchRender::DrawBrushModelShadow(
        CBrushBatchRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        IMatRenderContext *pRenderContext,
        model_t *model,
        IClientRenderable *pRenderable)
{
  model_t *v6; // ebx
  int v7; // esi
  IMesh *v8; // edi
  bool v9; // cc
  unsigned int m_nCurrentIndex; // eax
  IMatRenderContext *v11; // edi
  int v12; // edx
  int v13; // ecx
  __int16 m_nCurrentVertex; // si
  int v15; // edi
  float *m_pCurrPosition; // ecx
  float *v17; // eax
  float *v18; // eax
  int v19; // ecx
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1F4h] BYREF
  IMesh *pMesh; // [esp+1ECh] [ebp-Ch]
  int vertCount; // [esp+1F0h] [ebp-8h]
  int i; // [esp+1F4h] [ebp-4h]
  IMatRenderContext *pRenderContexta; // [esp+200h] [ebp+8h]
  IClientRenderable *pRenderablea; // [esp+208h] [ebp+10h]

  v6 = model;
  i = (int)CBrushBatchRender::FindOrCreateRenderBatch(this, pModel: model);
  if ( i != 0 )
  {
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, IClientRenderable *, int, int))pRenderContext->Bind)(
      a1: pRenderContext,
      a2: g_pMaterialShadowBuild,
      a3: pRenderable,
      a4: a2,
      a5: a3);
    v7 = *(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface;
    v8 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
    pMesh = v8;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v8,
      type: MATERIAL_TRIANGLES,
      nVertexCount: *(__int16 *)(i + 26),
      nIndexCount: *(__int16 *)(i + 24),
      pMeshSettings: nullptr);
    v9 = model->brush.nummodelsurfaces <= 0;
    i = 0;
    if ( !v9 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      v11 = (IMatRenderContext *)(v7 + 3);
      pRenderContexta = (IMatRenderContext *)(v7 + 3);
      do
      {
        if ( (BYTE1(v11[-1].__vftable) & 0x20) == 0 )
        {
          v12 = LOBYTE(v11->__vftable);
          v13 = *(int *)((char *)&v11[1].__vftable + 1);
          m_nCurrentVertex = meshBuilder.m_VertexBuilder.m_nCurrentVertex;
          vertCount = v12;
          if ( v12 != 0 )
          {
            v15 = 2 * v13;
            for ( pRenderablea = (IClientRenderable *)v12;
                  pRenderablea != nullptr;
                  pRenderablea = (IClientRenderable *)((char *)pRenderablea - 1) )
            {
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              v17 = (float *)(*(_DWORD *)(v6->sprite.numframes + 36)
                            + 12 * *(unsigned __int16 *)(*(_DWORD *)(v6->sprite.numframes + 148) + v15));
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = *v17;
              m_pCurrPosition[1] = v17[1];
              m_pCurrPosition[2] = v17[2];
              v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
              v18[1] = 0.0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v15 += 2;
            }
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            v11 = pRenderContexta;
            v12 = vertCount;
          }
          v19 = 0;
          if ( v12 - 2 > 0 )
          {
            do
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = m_nCurrentVertex
                                                                     + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
              meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
              meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = v19
                                                                                                + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                                + m_nCurrentVertex
                                                                                                + 1;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
              meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                                + v19
                                                                                                + m_nCurrentVertex
                                                                                                + 2;
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              ++v19;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
            while ( v19 < v12 - 2 );
            v6 = model;
            v11 = pRenderContexta;
          }
        }
        v11 += 8;
        ++i;
        pRenderContexta = v11;
      }
      while ( i < v6->brush.nummodelsurfaces );
      v8 = pMesh;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v8->Draw_2(this: v8, a2: -1, a3: 0);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067620
// Name: private: void CBrushBatchRender::BuildBatchListToDraw(int,struct BrushArrayInstanceData_t const __near *,class CUtlVectorFixedGrowable<struct CBrushBatchRender::BrushBatchRenderData_t,1024> __near &,struct CBrushBatchRender::brushrender_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::BuildBatchListToDraw(
        CBrushBatchRender *this,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> *batchesToRender,
        CBrushBatchRender::brushrender_t **ppBrushRender)
{
  int v5; // esi
  const BrushArrayInstanceData_t *v6; // ebx
  CBrushBatchRender::brushrender_t *RenderBatch; // ecx
  int v9; // edx
  CBrushBatchRender::brushrendermesh_t *pMeshes; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  int v13; // ebx
  CBrushBatchRender::BrushBatchRenderData_t *m_pMemory; // edx
  int v15; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v16; // eax
  IMaterial *v17; // edx
  CBrushBatchRender::brushrendermesh_t *mesh; // [esp+4h] [ebp-20h]
  unsigned __int8 *v19; // [esp+8h] [ebp-1Ch]
  int count; // [esp+Ch] [ebp-18h]
  const BrushArrayInstanceData_t *v21; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  int m; // [esp+18h] [ebp-Ch]
  int j; // [esp+1Ch] [ebp-8h]
  CBrushBatchRender::brushrender_t *pRender; // [esp+20h] [ebp-4h]
  int nBatchIndex; // [esp+30h] [ebp+Ch]
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> *batchesToRendera; // [esp+34h] [ebp+10h]

  v5 = 0;
  i = 0;
  if ( nCount > 0 )
  {
    v6 = pInstanceData;
    v21 = pInstanceData;
    do
    {
      RenderBatch = CBrushBatchRender::FindOrCreateRenderBatch(
                      this: &g_BrushBatchRenderer,
                      pModel: (model_t *)v6->m_pBrushModel);
      pRender = RenderBatch;
      ppBrushRender[v5] = RenderBatch;
      if ( RenderBatch != nullptr )
      {
        v9 = 0;
        m = 0;
        if ( RenderBatch->meshCount > 0 )
        {
          do
          {
            pMeshes = RenderBatch->pMeshes;
            nBatchIndex = pMeshes[v9].firstBatch;
            mesh = &pMeshes[v9];
            j = 0;
            if ( mesh->batchCount > 0 )
            {
              batchesToRendera = (CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> *)(16 * nBatchIndex);
              do
              {
                m_Size = batchesToRender->m_Size;
                m_nAllocationCount = batchesToRender->m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                {
                  v13 = m_Size - m_nAllocationCount + 1;
                  if ( batchesToRender->m_Memory.m_nGrowSize < 0 )
                  {
                    batchesToRender->m_Memory.m_nGrowSize = batchesToRender->m_Memory.m_nMallocGrowSize;
                    if ( m_nAllocationCount != 0 )
                    {
                      count = 16 * m_nAllocationCount;
                      v19 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nAllocationCount);
                      memcpy(dst: v19, src: (unsigned __int8 *)batchesToRender->m_Memory.m_pMemory, count);
                      batchesToRender->m_Memory.m_pMemory = (CBrushBatchRender::BrushBatchRenderData_t *)v19;
                    }
                    else
                    {
                      batchesToRender->m_Memory.m_pMemory = nullptr;
                    }
                  }
                  CUtlMemory<CPortalRect,int>::Grow(
                    this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)batchesToRender,
                    num: v13);
                  v6 = v21;
                  RenderBatch = pRender;
                }
                ++batchesToRender->m_Size;
                m_pMemory = batchesToRender->m_Memory.m_pMemory;
                v15 = batchesToRender->m_Size - m_Size - 1;
                batchesToRender->m_pElements = batchesToRender->m_Memory.m_pMemory;
                if ( v15 > 0 )
                {
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v15);
                  RenderBatch = pRender;
                }
                v16 = &batchesToRender->m_Memory.m_pMemory[m_Size];
                v17 = *(IMaterial **)((char *)&RenderBatch->pBatches->pMaterial + (unsigned int)batchesToRendera);
                batchesToRendera = (CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> *)((char *)batchesToRendera + 16);
                v16->m_pMaterial = v17;
                LOWORD(v17) = nBatchIndex ^ *((_WORD *)v16 + 6);
                LOWORD(nBatchIndex) = nBatchIndex + 1;
                *((_WORD *)v16 + 6) ^= (unsigned __int16)v17 & 0x7FFF;
                v16->m_pInstanceData = v6;
                v16->m_pBrushRender = RenderBatch;
                ++j;
              }
              while ( j < mesh->batchCount );
              v9 = m;
            }
            m = ++v9;
          }
          while ( v9 < RenderBatch->meshCount );
          v5 = i;
        }
      }
      ++v5;
      ++v6;
      i = v5;
      v21 = v6;
    }
    while ( v5 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100677C0
// Name: public: void CBrushBatchRender::DrawBrushModelArray(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawBrushModelArray(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData)
{
  void *v5; // esp
  CBrushBatchRender::BrushBatchRenderData_t *m_pMemory; // edi
  int m_Size; // ebx
  CBrushBatchRender::BrushBatchRenderData_t *v8; // ebx
  CBrushBatchRender::brushrender_t *v10[3]; // [esp+0h] [ebp-6044h] BYREF
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> batchesToRender; // [esp+Ch] [ebp-6038h] BYREF
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512> instanceGroups; // [esp+4024h] [ebp-2020h] BYREF
  CBrushBatchRender::brushrender_t **ppBrushRender; // [esp+603Ch] [ebp-8h]
  int v14; // [esp+6040h] [ebp-4h]
  IMatRenderContext *pRenderContexta; // [esp+604Ch] [ebp+8h]

  v5 = alloca(4 * nCount);
  batchesToRender.m_Memory.m_pMemory = batchesToRender.m_Memory.m_pFixedMemory;
  ppBrushRender = v10;
  batchesToRender.m_Memory.m_nMallocGrowSize = 0;
  batchesToRender.m_Size = 0;
  batchesToRender.m_Memory.m_nAllocationCount = 1024;
  batchesToRender.m_Memory.m_nGrowSize = -1;
  batchesToRender.m_pElements = batchesToRender.m_Memory.m_pFixedMemory;
  CBrushBatchRender::BuildBatchListToDraw(this, nCount, pInstanceData, &batchesToRender, ppBrushRender: v10);
  m_pMemory = batchesToRender.m_Memory.m_pMemory;
  m_Size = batchesToRender.m_Size;
  v14 = batchesToRender.m_Size;
  CBrushBatchRender::ComputeLightmapPages(
    this,
    nCount: batchesToRender.m_Size,
    pRenderData: batchesToRender.m_Memory.m_pMemory);
  v8 = &m_pMemory[m_Size];
  if ( (int)(((char *)v8 - (char *)m_pMemory) & 0xFFFFFFF0) > 16 )
    std::_Make_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
      _First: m_pMemory,
      _Last: v8,
      _Pred: CBrushBatchRender::BatchSortLessFunc);
  std::_Sort_heap<CBrushBatchRender::BrushBatchRenderData_t *,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
    _First: m_pMemory,
    _Last: v8,
    _Pred: CBrushBatchRender::BatchSortLessFunc);
  instanceGroups.m_Memory.m_pMemory = instanceGroups.m_Memory.m_pFixedMemory;
  instanceGroups.m_Memory.m_nMallocGrowSize = 0;
  instanceGroups.m_Size = 0;
  instanceGroups.m_pElements = instanceGroups.m_Memory.m_pFixedMemory;
  instanceGroups.m_Memory.m_nAllocationCount = 512;
  instanceGroups.m_Memory.m_nGrowSize = -1;
  pRenderContexta = (IMatRenderContext *)CBrushBatchRender::ComputeInstanceGroups(
                                           this,
                                           pRenderContext,
                                           nCount: (CBrushBatchRender::BrushBatchRenderData_t *)v14,
                                           pRenderData: m_pMemory,
                                           &instanceGroups);
  if ( CBrushBatchRender::DrawSortedBatchList(
         this,
         pRenderContext,
         nCount: instanceGroups.m_Size,
         pInstanceGroup: instanceGroups.m_Memory.m_pMemory,
         nMaxInstanceCount: (int)pRenderContexta) != 0 )
    CBrushBatchRender::DrawPaintForBatches(
      this,
      pRenderContext,
      nCount: instanceGroups.m_Size,
      pInstanceGroup: instanceGroups.m_Memory.m_pMemory,
      nMaxInstanceCount: (int)pRenderContexta);
  CBrushBatchRender::DrawDecalsForBatches(this, pRenderContext, nCount, pInstanceData, ppBrushRender);
  CBrushBatchRender::DrawArrayDebugInformation(this, pRenderContext, nCount: v14, pRenderData: m_pMemory);
  CUtlVector<CBrushBatchRender::BrushInstanceGroup_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>>::~CUtlVector<CBrushBatchRender::BrushInstanceGroup_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>>(this: &instanceGroups);
  CUtlVector<CBrushBatchRender::BrushBatchRenderData_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024,int>>::~CUtlVector<CBrushBatchRender::BrushBatchRenderData_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024,int>>(this: &batchesToRender);
}

//------------------------------------------------------------------------------
// Address: 0x10067950
// Name: private: void CBrushBatchRender::BuildShadowBatchListToDraw(int,struct BrushArrayInstanceData_t const __near *,class CUtlVectorFixedGrowable<struct CBrushBatchRender::BrushBatchRenderData_t,1024> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::BuildShadowBatchListToDraw(
        CBrushBatchRender *this,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        CBrushBatchRender::brushrender_t *batchesToRender)
{
  CBrushBatchRender::brushrender_t *RenderBatch; // eax
  int v7; // esi
  CBrushBatchRender::brushrendermesh_t *pMeshes; // edx
  int v9; // ecx
  char *v10; // esi
  int v11; // ebx
  unsigned __int8 v12; // al
  int v13; // esi
  IMaterial *v14; // ecx
  int v15; // eax
  int v16; // ecx
  CBrushBatchRender::BrushBatchRenderData_t *pPlanes; // ecx
  int v18; // eax
  CBrushBatchRender::BrushBatchRenderData_t *v19; // eax
  __int16 v20; // dx
  CBrushBatchRender::brushrendermesh_t *mesh; // [esp+0h] [ebp-24h]
  IMaterial *pDepthWriteMaterial; // [esp+4h] [ebp-20h]
  int v23; // [esp+8h] [ebp-1Ch]
  unsigned __int8 *v24; // [esp+Ch] [ebp-18h]
  int count; // [esp+10h] [ebp-14h]
  int v26; // [esp+14h] [ebp-10h]
  int m; // [esp+18h] [ebp-Ch]
  int nBatchIndex; // [esp+1Ch] [ebp-8h]
  int j; // [esp+20h] [ebp-4h]
  const BrushArrayInstanceData_t *pInstanceDataa; // [esp+30h] [ebp+Ch]
  CBrushBatchRender::brushrender_t *pRender; // [esp+34h] [ebp+10h]

  if ( nCount > 0 )
  {
    v26 = nCount;
    do
    {
      RenderBatch = CBrushBatchRender::FindOrCreateRenderBatch(
                      this: &g_BrushBatchRenderer,
                      pModel: (model_t *)pInstanceData->m_pBrushModel);
      pRender = RenderBatch;
      if ( RenderBatch != nullptr )
      {
        v7 = 0;
        for ( m = 0; v7 < RenderBatch->meshCount; m = ++v7 )
        {
          pMeshes = RenderBatch->pMeshes;
          mesh = &pMeshes[v7];
          nBatchIndex = mesh->firstBatch;
          j = 0;
          if ( mesh->batchCount > 0 )
          {
            v9 = 16 * pMeshes[v7].firstBatch;
            for ( pInstanceDataa = (const BrushArrayInstanceData_t *)v9; ; v9 = (int)pInstanceDataa )
            {
              v10 = (char *)RenderBatch->pBatches + v9;
              v11 = (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 1) + 72))(a1: *((_DWORD *)v10 + 1));
              v12 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 1) + 132))(a1: *((_DWORD *)v10 + 1));
              v13 = *(_DWORD *)&batchesToRender[585].batchCount;
              v14 = g_pMaterialDepthWrite[v11][v12];
              v15 = (int)batchesToRender->pMeshes;
              pDepthWriteMaterial = v14;
              if ( v13 + 1 > v15 )
              {
                v16 = v13 - v15 + 1;
                v23 = v16;
                if ( (int)batchesToRender->pBatches < 0 )
                {
                  batchesToRender->pBatches = (CBrushBatchRender::brushrenderbatch_t *)batchesToRender->pSurfaces;
                  if ( v15 != 0 )
                  {
                    count = 16 * v15;
                    v24 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * v15);
                    memcpy(dst: v24, src: (unsigned __int8 *)batchesToRender->pPlanes, count);
                    v16 = v23;
                    batchesToRender->pPlanes = (cplane_t **)v24;
                  }
                  else
                  {
                    batchesToRender->pPlanes = nullptr;
                  }
                }
                CUtlMemory<CPortalRect,int>::Grow(
                  this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)batchesToRender,
                  num: v16);
              }
              ++*(_DWORD *)&batchesToRender[585].batchCount;
              pPlanes = (CBrushBatchRender::BrushBatchRenderData_t *)batchesToRender->pPlanes;
              v18 = *(_DWORD *)&batchesToRender[585].batchCount - v13 - 1;
              *(_DWORD *)&batchesToRender[585].totalIndexCount = batchesToRender->pPlanes;
              if ( v18 > 0 )
                _V_memmove(dest: &pPlanes[v13 + 1], src: &pPlanes[v13], count: 16 * v18);
              pInstanceDataa = (const BrushArrayInstanceData_t *)((char *)pInstanceDataa + 16);
              v19 = (CBrushBatchRender::BrushBatchRenderData_t *)&batchesToRender->pPlanes[4 * v13];
              v19->m_pBrushRender = pRender;
              v20 = *((_WORD *)v19 + 6);
              v19->m_pInstanceData = pInstanceData;
              *((_WORD *)v19 + 6) ^= (nBatchIndex ^ v20) & 0x7FFF;
              *((_WORD *)v19 + 7) = ((_WORD)v11 << 15) | *((_WORD *)v19 + 7) & 0x7FFF;
              v19->m_pMaterial = pDepthWriteMaterial;
              ++nBatchIndex;
              ++j;
              RenderBatch = pRender;
              if ( j >= mesh->batchCount )
                break;
            }
            v7 = m;
          }
        }
      }
      ++pInstanceData;
      --v26;
    }
    while ( v26 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067B30
// Name: public: void CBrushBatchRender::DrawBrushModelShadowArray(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBatchRender::DrawBrushModelShadowArray(
        CBrushBatchRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData)
{
  CBrushBatchRender::BrushBatchRenderData_t *m_pMemory; // edi
  int m_Size; // ebx
  int v7; // eax
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024> batchesToRender; // [esp+Ch] [ebp-6030h] BYREF
  CUtlVectorFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512> instanceGroups; // [esp+4024h] [ebp-2018h] BYREF
  BrushArrayInstanceData_t *pInstanceDataa; // [esp+604Ch] [ebp+10h]

  batchesToRender.m_Memory.m_pMemory = batchesToRender.m_Memory.m_pFixedMemory;
  batchesToRender.m_Memory.m_nMallocGrowSize = 0;
  batchesToRender.m_Size = 0;
  batchesToRender.m_pElements = batchesToRender.m_Memory.m_pFixedMemory;
  batchesToRender.m_Memory.m_nAllocationCount = 1024;
  batchesToRender.m_Memory.m_nGrowSize = -1;
  CBrushBatchRender::BuildShadowBatchListToDraw(
    this,
    nCount,
    pInstanceData,
    (CBrushBatchRender::brushrender_t *)&batchesToRender);
  m_pMemory = batchesToRender.m_Memory.m_pMemory;
  pInstanceDataa = (BrushArrayInstanceData_t *)batchesToRender.m_Size;
  m_Size = batchesToRender.m_Size;
  if ( 16 * batchesToRender.m_Size > 16 )
    std::_Make_heap<CBrushBatchRender::BrushBatchRenderData_t *,int,CBrushBatchRender::BrushBatchRenderData_t,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
      _First: batchesToRender.m_Memory.m_pMemory,
      _Last: &batchesToRender.m_Memory.m_pMemory[batchesToRender.m_Size],
      _Pred: CBrushBatchRender::ShadowSortLessFunc);
  std::_Sort_heap<CBrushBatchRender::BrushBatchRenderData_t *,bool (__cdecl *)(CBrushBatchRender::BrushBatchRenderData_t const &,CBrushBatchRender::BrushBatchRenderData_t const &)>(
    _First: m_pMemory,
    _Last: &m_pMemory[m_Size],
    _Pred: CBrushBatchRender::ShadowSortLessFunc);
  instanceGroups.m_Memory.m_pMemory = instanceGroups.m_Memory.m_pFixedMemory;
  instanceGroups.m_Memory.m_nMallocGrowSize = 0;
  instanceGroups.m_Size = 0;
  instanceGroups.m_pElements = instanceGroups.m_Memory.m_pFixedMemory;
  instanceGroups.m_Memory.m_nAllocationCount = 512;
  instanceGroups.m_Memory.m_nGrowSize = -1;
  v7 = CBrushBatchRender::ComputeInstanceGroups(
         this,
         pRenderContext,
         nCount: (CBrushBatchRender::BrushBatchRenderData_t *)pInstanceDataa,
         pRenderData: m_pMemory,
         &instanceGroups);
  CBrushBatchRender::DrawShadowBatchList(
    this,
    pRenderContext,
    nCount: instanceGroups.m_Size,
    pInstanceGroup: instanceGroups.m_Memory.m_pMemory,
    nMaxInstanceCount: v7);
  CUtlVector<CBrushBatchRender::BrushInstanceGroup_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>>::~CUtlVector<CBrushBatchRender::BrushInstanceGroup_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushInstanceGroup_t,512,int>>(this: &instanceGroups);
  CUtlVector<CBrushBatchRender::BrushBatchRenderData_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024,int>>::~CUtlVector<CBrushBatchRender::BrushBatchRenderData_t,CUtlMemoryFixedGrowable<CBrushBatchRender::BrushBatchRenderData_t,1024,int>>(this: &batchesToRender);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1031E170
// Name: _dynamic_initializer_for__render_blanks_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__render_blanks_command__()
{
  ConCommand::ConCommand(
    this: &render_blanks_command,
    pName: "render_blanks",
    callback: render_blanks,
    pHelpString: "render N blank frames",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__render_blanks_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326C50
// Name: _dynamic_atexit_destructor_for__render_blanks_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__render_blanks_command__()
{
  ConCommand::~ConCommand(this: &render_blanks_command);
}

} // namespace engine_xlsp
