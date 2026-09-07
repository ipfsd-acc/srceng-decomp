// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/beamdraw.cpp
// Functions: 25
// ============================================================

#include "game\client\beamdraw.h"

//------------------------------------------------------------------------------
// Address: 0x1001EB40
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
// Address: 0x1001EBB0
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
// Address: 0x1001EC30
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
// Address: 0x1001ED00
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
// Address: 0x1001ED60
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
// Address: 0x1001EDD0
// Name: private: void CMeshBuilder::ComputeNumVertsAndIndices(int __near *,int __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::ComputeNumVertsAndIndices(
        CMeshBuilder *this,
        int *pMaxVertices,
        int *pMaxIndices,
        MaterialPrimitiveType_t type,
        int nPrimitiveCount)
{
  switch ( type )
  {
    case MATERIAL_POINTS:
      *pMaxIndices = nPrimitiveCount;
      *pMaxVertices = nPrimitiveCount;
      break;
    case MATERIAL_LINES:
      *pMaxIndices = 2 * nPrimitiveCount;
      *pMaxVertices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLES:
      *pMaxIndices = 3 * nPrimitiveCount;
      *pMaxVertices = 3 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLE_STRIP:
      *pMaxIndices = nPrimitiveCount + 2;
      *pMaxVertices = nPrimitiveCount + 2;
      break;
    case MATERIAL_LINE_STRIP:
      *pMaxVertices = nPrimitiveCount + 1;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_LINE_LOOP:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_POLYGON:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 3 * nPrimitiveCount - 6;
      break;
    case MATERIAL_QUADS:
      *pMaxVertices = 4 * nPrimitiveCount;
      *pMaxIndices = 6 * nPrimitiveCount;
      break;
    case MATERIAL_INSTANCED_QUADS:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 0;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EED0
// Name: private: int CMeshBuilder::IndicesFromVertices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshBuilder::IndicesFromVertices(CMeshBuilder *this, MaterialPrimitiveType_t type, int nVertexCount)
{
  int result; // eax

  switch ( type )
  {
    case MATERIAL_LINE_STRIP:
      result = 2 * nVertexCount - 2;
      break;
    case MATERIAL_LINE_LOOP:
      result = 2 * nVertexCount;
      break;
    case MATERIAL_POLYGON:
      result = 3 * nVertexCount - 6;
      break;
    case MATERIAL_QUADS:
      result = 6 * nVertexCount / 4;
      break;
    case MATERIAL_INSTANCED_QUADS:
      result = 0;
      break;
    default:
      result = nVertexCount;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001EF50
// Name: public: void CMeshBuilder::End(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::End(CMeshBuilder *this, bool bSpewData, bool bDraw)
{
  MaterialPrimitiveType_t m_Type; // edi
  int v5; // eax

  if ( this->m_bGenerateIndices )
  {
    m_Type = this->m_Type;
    v5 = CMeshBuilder::IndicesFromVertices(this, type: m_Type, nVertexCount: this->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &this->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v5);
  }
  if ( bSpewData )
    this->m_pMesh->Spew_2(
      this: this->m_pMesh,
      a2: this->m_VertexBuilder.m_nVertexCount,
      a3: this->m_IndexBuilder.m_nIndexCount,
      a4: this);
  this->m_pMesh->UnlockMesh(
    this: this->m_pMesh,
    a2: this->m_VertexBuilder.m_nVertexCount,
    a3: this->m_IndexBuilder.m_nIndexCount,
    a4: this);
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  if ( bDraw )
    this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
  this->m_pMesh = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001F010
// Name: public: CBeamSegDraw::~CBeamSegDraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSegDraw::~CBeamSegDraw(CBeamSegDraw *this)
{
  if ( this->m_Mesh.m_VertexBuilder.m_pVertexBuffer != nullptr
    && this->m_Mesh.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: this->m_Mesh.m_VertexBuilder.m_pVertexBuffer) )
  {
    this->m_Mesh.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: this->m_Mesh.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( this->m_Mesh.m_IndexBuilder.m_pIndexBuffer != nullptr
    && this->m_Mesh.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: this->m_Mesh.m_IndexBuilder.m_pIndexBuffer) )
  {
    this->m_Mesh.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: this->m_Mesh.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F070
// Name: void CalcSegOrigin(class Vector __near *,int,int,float __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcSegOrigin(
        Vector *vecOut,
        int iPoint,
        int noise_divisions,
        float *prgNoise,
        const Vector *source,
        const Vector *delta,
        const Vector *perp,
        int segments,
        float freq,
        float scale,
        float fraction,
        char flags)
{
  float v12; // xmm2_4
  float v13; // xmm0_4
  int v14; // ecx
  float v15; // xmm1_4
  const Vector *v16; // eax
  const Vector *v17; // eax
  float v18; // [esp-18h] [ebp-24h]
  float v19; // [esp-8h] [ebp-14h]
  float v20; // [esp-4h] [ebp-10h]

  v12 = fsqrt((float)((float)(delta->x * delta->x) + (float)(delta->y * delta->y)) + (float)(delta->z * delta->z))
      * 0.01;
  v13 = 1.0 / (double)(segments - 1);
  v14 = iPoint * (int)(float)((float)(v13 * (float)(noise_divisions - 1)) * 65536.0);
  if ( (flags & 0x10) != 0 )
  {
    v12 = (double)segments * 0.1;
    v14 = 0;
  }
  vecOut->x = (float)(delta->x * fraction) + source->x;
  vecOut->y = (float)(fraction * delta->y) + source->y;
  vecOut->z = (float)(fraction * delta->z) + source->z;
  if ( scale != 0.0 )
  {
    v15 = prgNoise[v14 >> 16] * scale;
    if ( (flags & 0x10) != 0 )
    {
      v18 = fraction * 3.141592653589793 * v12 + freq;
      v19 = cos(v18);
      v20 = sin(v18);
      v16 = CurrentViewUp();
      vecOut->x = (float)(v16->x * (float)(v20 * v15)) + vecOut->x;
      vecOut->y = (float)(v16->y * (float)(v20 * v15)) + vecOut->y;
      vecOut->z = (float)(v16->z * (float)(v20 * v15)) + vecOut->z;
      v17 = CurrentViewRight();
      vecOut->x = (float)((float)(v19 * v15) * v17->x) + vecOut->x;
      vecOut->y = (float)(v17->y * (float)(v19 * v15)) + vecOut->y;
      vecOut->z = (float)(v17->z * (float)(v19 * v15)) + vecOut->z;
    }
    else
    {
      vecOut->x = (float)(perp->x * v15) + vecOut->x;
      vecOut->y = (float)(perp->y * v15) + vecOut->y;
      vecOut->z = (float)(perp->z * v15) + vecOut->z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F2C0
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F2E0
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
// Address: 0x1001F470
// Name: public: CMatRenderContextPtr::CMatRenderContextPtr(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContextPtr *__thiscall CMatRenderContextPtr::CMatRenderContextPtr(
        CMatRenderContextPtr *this,
        IMaterialSystem *pFrom)
{
  IMatRenderContext *v3; // eax

  v3 = pFrom->GetRenderContext(this: pFrom);
  this->m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001F4A0
// Name: class CEngineSprite __near * Draw_SetSpriteTexture(struct model_t const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__usercall Draw_SetSpriteTexture@<eax>(
        int a1@<esi>,
        const struct model_t *pSpriteModel,
        int frame,
        RenderMode_t rendermode)
{
  CEngineSprite *v4; // edi
  IMaterial *result; // eax
  CEngineSprite *v6; // ebx
  int v7; // esi
  IMaterial *v8; // eax

  v4 = (CEngineSprite *)modelinfo->GetModelExtraData(this: modelinfo, a2: pSpriteModel);
  result = CEngineSprite::GetMaterial(this: v4, nRenderMode: rendermode, nFrame: frame);
  v6 = (CEngineSprite *)result;
  if ( result != nullptr )
  {
    v7 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: a1);
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    if ( ShouldDrawInWireFrameMode() || r_DrawBeams.m_pParent != nullptr && r_DrawBeams.m_pParent->m_Value.m_nValue == 2 )
    {
      v8 = g_pBeamWireframeMaterial;
      if ( g_pBeamWireframeMaterial == nullptr )
      {
        v8 = materials->FindMaterial(
               this: materials,
               a2: "debug/debugwireframevertexcolor",
               a3: "Other textures",
               a4: 1,
               a5: 0);
        g_pBeamWireframeMaterial = v8;
      }
      (*(void (__thiscall **)(int, IMaterial *))(*(_DWORD *)v7 + 36))(a1: v7, a2: v8);
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
      return (IMaterial *)v4;
    }
    else
    {
      (*(void (__thiscall **)(int, CEngineSprite *))(*(_DWORD *)v7 + 36))(a1: v7, a2: v6);
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
      return (IMaterial *)v4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001F580
// Name: void DrawHalo(class IMaterial __near *,class Vector const __near &,float,float const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawHalo(
        int a1@<ebx>,
        IMaterial *pMaterial,
        const Vector *source,
        float scale,
        const float *color,
        float flHDRColorScale)
{
  IMaterialVar *v6; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  IMesh *v9; // ebx
  float *v12; // eax
  const Vector *v13; // eax
  const Vector *v14; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v17; // xmm0_4
  float *m_pCurrPosition; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float *v22; // eax
  const Vector *v23; // eax
  const Vector *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float *v28; // eax
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float *v32; // eax
  const Vector *v33; // eax
  const Vector *v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  float *v37; // eax
  const Vector *v38; // eax
  const Vector *v39; // eax
  float x; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm2_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  Vector screen; // [esp+14h] [ebp-208h] BYREF
  CMeshBuilder meshBuilder; // [esp+20h] [ebp-1FCh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+208h] [ebp-14h]
  float v51; // [esp+20Ch] [ebp-10h]
  Vector point; // [esp+210h] [ebp-Ch]
  float pMateriala; // [esp+224h] [ebp+8h]
  float sourcea; // [esp+228h] [ebp+Ch]
  float sourceb; // [esp+228h] [ebp+Ch]
  float sourcec; // [esp+228h] [ebp+Ch]
  float sourced; // [esp+228h] [ebp+Ch]
  float colora; // [esp+230h] [ebp+14h]
  float colorb; // [esp+230h] [ebp+14h]
  float colorc; // [esp+230h] [ebp+14h]
  float colord; // [esp+230h] [ebp+14h]

  if ( pMaterial != nullptr )
  {
    v6 = pMaterial->FindVarFast(this: pMaterial, a2: "$hdrcolorscale", a3: &nHDRColorScaleCache);
    if ( v6 != nullptr )
      ((void (__thiscall *)(IMaterialVar *, _DWORD))v6->SetFloatValue)(a1: v6, a2: LODWORD(flHDRColorScale));
  }
  v7 = materials->GetRenderContext(this: materials);
  v8 = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v9 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v8->GetDynamicMesh)(
                  a1: v8,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: a1);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v9;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v9->SetPrimitiveType(this: v9, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v9, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  ScreenTransform(point: source, &screen);
  colora = (float)(color[2] * 255.0) + 8388608.0;
  sourcea = (float)(color[1] * 255.0) + 8388608.0;
  pMateriala = (float)(*color * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(colora)
                                                      | ((LOBYTE(sourcea) | ((LOBYTE(pMateriala) | 0xFFFFFF00) << 8)) << 8);
  v12 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v12[1] = 1.0;
  v13 = CurrentViewUp();
  point.x = (float)(COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_) * v13->x) + source->x;
  point.y = (float)(v13->y * COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_)) + source->y;
  point.z = (float)(v13->z * COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_)) + source->z;
  v14 = CurrentViewRight();
  y = v14->y;
  z = v14->z;
  v17 = COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_) * v14->x;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v19 = v17 + point.x;
  v20 = (float)(y * COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_)) + point.y;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v19;
  v21 = (float)(z * COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_)) + point.z;
  m_pCurrPosition[1] = v20;
  point.x = v19;
  point.y = v20;
  point.z = v21;
  m_pCurrPosition[2] = v21;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v51 = (float)(color[2] * 255.0) + 8388608.0;
  colorb = (float)(color[1] * 255.0) + 8388608.0;
  sourceb = (float)(*color * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v51)
                                                      | ((LOBYTE(colorb) | ((LOBYTE(sourceb) | 0xFFFFFF00) << 8)) << 8);
  v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v22[1] = 0.0;
  v23 = CurrentViewUp();
  point.x = (float)(v23->x * scale) + source->x;
  point.y = (float)(v23->y * scale) + source->y;
  point.z = (float)(v23->z * scale) + source->z;
  v24 = CurrentViewRight();
  v25 = v24->y;
  v26 = v24->z;
  v27 = COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_) * v24->x;
  v28 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v29 = v27 + point.x;
  v30 = (float)(v25 * COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_)) + point.y;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  v31 = (float)(v26 * COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_)) + point.z;
  v28[1] = v30;
  point.x = v29;
  point.y = v30;
  point.z = v31;
  v28[2] = v31;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v51 = (float)(color[2] * 255.0) + 8388608.0;
  colorc = (float)(color[1] * 255.0) + 8388608.0;
  sourcec = (float)(*color * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v51)
                                                      | ((LOBYTE(colorc) | ((LOBYTE(sourcec) | 0xFFFFFF00) << 8)) << 8);
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v32[1] = 0.0;
  v33 = CurrentViewUp();
  point.x = (float)(v33->x * scale) + source->x;
  point.y = (float)(v33->y * scale) + source->y;
  point.z = (float)(v33->z * scale) + source->z;
  v34 = CurrentViewRight();
  v35 = (float)(v34->y * scale) + point.y;
  v36 = (float)(v34->z * scale) + point.z;
  point.x = (float)(v34->x * scale) + point.x;
  point.y = v35;
  point.z = v36;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = point;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v51 = (float)(color[2] * 255.0) + 8388608.0;
  colord = (float)(color[1] * 255.0) + 8388608.0;
  sourced = (float)(*color * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v51)
                                                      | ((LOBYTE(colord) | ((LOBYTE(sourced) | 0xFFFFFF00) << 8)) << 8);
  v37 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v37[1] = 1.0;
  v38 = CurrentViewUp();
  point.x = (float)(COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_) * v38->x) + source->x;
  point.y = (float)(v38->y * COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_)) + source->y;
  point.z = (float)(v38->z * COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_)) + source->z;
  v39 = CurrentViewRight();
  x = v39->x;
  v41 = v39->y;
  v42 = v39->z;
  v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v44 = (float)(v41 * scale) + point.y;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(x * scale) + point.x;
  v45 = (float)(v42 * scale) + point.z;
  v43[1] = v44;
  v43[2] = v45;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v9->Draw_2(this: v9, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1001FC50
// Name: void DrawSprite(class Vector const __near &,float,float,struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawSprite(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *vecOrigin,
        float flWidth,
        float flHeight,
        color32_s color)
{
  const Vector *v7; // eax
  const Vector *v8; // eax
  const Vector *v9; // eax
  IMatRenderContext *v10; // ebx
  IMesh *v11; // ebx
  int v12; // edi
  float *v13; // eax
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float *m_pCurrPosition; // eax
  float v19; // xmm2_4
  float v20; // xmm1_4
  float *v21; // eax
  float *v22; // eax
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float *v27; // eax
  float *v28; // eax
  float v29; // xmm2_4
  float v30; // xmm0_4
  float z; // xmm1_4
  float *v32; // eax
  float *v33; // eax
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-214h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1E8h] [ebp-2Ch]
  Vector fwd; // [esp+1ECh] [ebp-28h] BYREF
  Vector right; // [esp+1F8h] [ebp-1Ch] BYREF
  Vector up; // [esp+204h] [ebp-10h] BYREF
  unsigned __int8 pColor[4]; // [esp+210h] [ebp-4h]
  float flWidtha; // [esp+220h] [ebp+Ch]
  float flHeighta; // [esp+224h] [ebp+10h]

  flWidtha = flWidth * 0.5;
  *(color32_s *)pColor = color;
  flHeighta = flHeight * 0.5;
  right.x = 1.0;
  right.y = 0.0;
  right.z = 0.0;
  up.x = 0.0;
  up.y = 1.0;
  up.z = 0.0;
  v7 = CurrentViewOrigin();
  fwd.x = v7->x - vecOrigin->x;
  fwd.y = v7->y - vecOrigin->y;
  fwd.z = v7->z - vecOrigin->z;
  if ( VectorNormalize(vec: &fwd) >= 0.001 )
  {
    v8 = CurrentViewUp();
    right.x = (float)(v8->y * fwd.z) - (float)(v8->z * fwd.y);
    right.y = (float)(v8->z * fwd.x) - (float)(fwd.z * v8->x);
    right.z = (float)(fwd.y * v8->x) - (float)(v8->y * fwd.x);
    if ( VectorNormalize(vec: &right) < 0.001 )
    {
      v9 = CurrentViewRight();
      up.x = (float)(fwd.y * v9->z) - (float)(fwd.z * v9->y);
      up.y = (float)(v9->x * fwd.z) - (float)(fwd.x * v9->z);
      up.z = (float)(fwd.x * v9->y) - (float)(v9->x * fwd.y);
      VectorNormalize(vec: &up);
      right.x = (float)(fwd.z * up.y) - (float)(fwd.y * up.z);
      right.y = (float)(up.z * fwd.x) - (float)(fwd.z * up.x);
      right.z = (float)(fwd.y * up.x) - (float)(up.y * fwd.x);
    }
    else
    {
      up.x = (float)(fwd.y * right.z) - (float)(fwd.z * right.y);
      up.y = (float)(fwd.z * right.x) - (float)(right.z * fwd.x);
      up.z = (float)(right.y * fwd.x) - (float)(fwd.y * right.x);
    }
  }
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v10 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
                               a1: materials,
                               a2,
                               a3,
                               a4: a1);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = v10->GetDynamicMesh(this: v10, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v12 = pColor[2] | ((pColor[1] | ((pColor[0] | (pColor[3] << 8)) << 8)) << 8);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v13[1] = 1.0;
  v14 = (float)(COERCE_FLOAT(LODWORD(flHeighta) ^ _mask__NegFloat_) * up.x) + vecOrigin->x;
  v15 = (float)(COERCE_FLOAT(LODWORD(flHeighta) ^ _mask__NegFloat_) * up.y) + vecOrigin->y;
  *(_DWORD *)pColor = LODWORD(flHeighta) ^ _mask__NegFloat_;
  v16 = (float)(COERCE_FLOAT(LODWORD(flHeighta) ^ _mask__NegFloat_) * up.z) + vecOrigin->z;
  v17 = (float)(COERCE_FLOAT(LODWORD(flWidtha) ^ _mask__NegFloat_) * right.x) + v14;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v19 = COERCE_FLOAT(LODWORD(flWidtha) ^ _mask__NegFloat_) * right.y;
  v20 = COERCE_FLOAT(LODWORD(flWidtha) ^ _mask__NegFloat_) * right.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  m_pCurrPosition[1] = v19 + v15;
  m_pCurrPosition[2] = v20 + v16;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v23 = (float)(up.y * flHeighta) + vecOrigin->y;
  v24 = (float)(up.z * flHeighta) + vecOrigin->z;
  v25 = COERCE_FLOAT(LODWORD(flWidtha) ^ _mask__NegFloat_) * right.y;
  v26 = COERCE_FLOAT(LODWORD(flWidtha) ^ _mask__NegFloat_) * right.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(COERCE_FLOAT(LODWORD(flWidtha) ^ _mask__NegFloat_) * right.x)
                                               + (float)((float)(up.x * flHeighta) + vecOrigin->x);
  v22[1] = v25 + v23;
  v22[2] = v26 + v24;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v29 = (float)(up.z * flHeighta) + vecOrigin->z;
  v30 = (float)(right.y * flWidtha) + (float)((float)(up.y * flHeighta) + vecOrigin->y);
  z = right.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(right.x * flWidtha)
                                               + (float)((float)(up.x * flHeighta) + vecOrigin->x);
  v28[1] = v30;
  v28[2] = (float)(z * flWidtha) + v29;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v12;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v32[1] = 1.0;
  v33 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v34 = (float)(*(float *)pColor * up.z) + vecOrigin->z;
  v35 = (float)(right.y * flWidtha) + (float)((float)(*(float *)pColor * up.y) + vecOrigin->y);
  v36 = right.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(right.x * flWidtha)
                                               + (float)((float)(*(float *)pColor * up.x) + vecOrigin->x);
  v33[1] = v35;
  v33[2] = (float)(v36 * flWidtha) + v34;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v11->Draw_2(this: v11, a2: -1, a3: 0);
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
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

//------------------------------------------------------------------------------
// Address: 0x10020310
// Name: void DrawSegs(int,float __near *,struct model_t const __near *,float,int,class Vector const __near &,class Vector const __near &,float,float,float,float,float,int,int,float __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DrawSegs(
        int a1@<ebp>,
        int noise_divisions,
        float *prgNoise,
        const struct model_t *spritemodel,
        float frame,
        RenderMode_t rendermode,
        const Vector *source,
        const Vector *delta,
        float startWidth,
        float endWidth,
        float scale,
        float freq,
        float speed,
        int segments,
        __int16 flags,
        float *color,
        float fadeLength,
        float flHDRColorScale)
{
  IMaterial *v18; // eax
  int v19; // edi
  IMaterial_vtbl *v20; // ecx
  int v21; // eax
  float z; // xmm1_4
  float y; // xmm2_4
  __int128 v24; // xmm0
  float v25; // xmm0_4
  float v26; // xmm2_4
  double v27; // xmm0_8
  float v28; // xmm0_4
  float v29; // xmm1_4
  __int128 v30; // xmm0
  float v31; // xmm0_4
  float v32; // edx
  const Vector *v33; // eax
  IMatRenderContext *v34; // eax
  IMatRenderContext *v35; // esi
  int v36; // esi
  CMatRenderContextPtr v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  const Vector *v47; // eax
  const Vector *v48; // eax
  IMatRenderContext *v49; // esi
  _DWORD v50[3]; // [esp+1Ch] [ebp-2FCh] BYREF
  CBeamSegDraw segDraw; // [esp+28h] [ebp-2F0h] BYREF
  int v52; // [esp+278h] [ebp-A0h]
  int v53; // [esp+27Ch] [ebp-9Ch]
  float v54; // [esp+280h] [ebp-98h]
  float *p_s; // [esp+284h] [ebp-94h]
  IMatRenderContext *v56; // [esp+288h] [ebp-90h]
  int v57; // [esp+28Ch] [ebp-8Ch]
  int v58; // [esp+290h] [ebp-88h]
  CMatRenderContextPtr pRenderContext; // [esp+294h] [ebp-84h]
  float v60; // [esp+298h] [ebp-80h]
  __int128 noiseStep; // [esp+29Ch] [ebp-7Ch] OVERLAPPED BYREF
  Vector v62; // [esp+2ACh] [ebp-6Ch] BYREF
  Vector perp1; // [esp+2B8h] [ebp-60h] BYREF
  float vStep; // [esp+2C4h] [ebp-54h]
  BeamSeg_t curSeg; // [esp+2C8h] [ebp-50h]
  float v66; // [esp+2E8h] [ebp-30h]
  float v67; // [esp+2ECh] [ebp-2Ch] BYREF
  float v68; // [esp+2F0h] [ebp-28h]
  float length; // [esp+2F4h] [ebp-24h]
  float s; // [esp+2F8h] [ebp-20h] BYREF
  float vLast; // [esp+2FCh] [ebp-1Ch]
  int div; // [esp+300h] [ebp-18h]
  float c; // [esp+304h] [ebp-14h]
  float factor; // [esp+308h] [ebp-10h]
  int noiseIndex; // [esp+30Ch] [ebp-Ch]
  void *v76; // [esp+310h] [ebp-8h]
  void *retaddr; // [esp+318h] [ebp+0h]
  float scalea; // [esp+340h] [ebp+28h]

  noiseIndex = a1;
  v76 = retaddr;
  v18 = Draw_SetSpriteTexture(a1: rendermode, pSpriteModel: spritemodel, (int)frame, rendermode);
  if ( v18 == nullptr )
    return;
  v19 = segments;
  if ( segments < 2 )
    return;
  v20 = v18[rendermode + 4].__vftable;
  if ( v20 != nullptr )
  {
    v21 = (*((int (__thiscall **)(IMaterial_vtbl *, const char *, unsigned int *))v20->GetName + 47))(
            a1: v20,
            a2: "$hdrcolorscale",
            a3: &nHDRColorScaleCache_0);
    if ( v21 != 0 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v21 + 16))(a1: v21, a2: LODWORD(flHDRColorScale));
  }
  z = delta->z;
  y = delta->y;
  vLast = delta->x * delta->x;
  v24 = 0;
  *(float *)&v24 = fsqrt((float)((float)(y * y) + (float)(z * z)) + vLast);
  noiseStep = v24;
  v25 = startWidth;
  if ( startWidth <= endWidth )
    v25 = endWidth;
  v26 = 1.0 / (double)(segments - 1);
  v27 = (float)(v25 * 0.5) * 1.414;
  if ( v27 > (float)(v26 * *(float *)&noiseStep) )
  {
    v19 = (int)(*(float *)&noiseStep / v27) + 1;
    if ( v19 < 2 )
      v19 = 2;
  }
  if ( v19 > noise_divisions )
    v19 = noise_divisions;
  v28 = 1.0 / (double)(v19 - 1);
  v29 = *(float *)&noiseStep * 0.01;
  length = v28;
  v66 = v29;
  if ( (flags & 0x200) == 0 )
    v28 = v28 * v29;
  perp1.x = v28;
  v68 = fmod(freq * speed, 1.0);
  v57 = flags & 0x10;
  if ( (flags & 0x10) != 0 )
  {
    if ( v19 < 16 )
    {
      v19 = 16;
      length = 0.06666667;
    }
    scalea = scale * 100.0;
    v66 = (double)v19 * 0.1;
  }
  else
  {
    scalea = v66 * scale;
  }
  v58 = (int)(float)((float)((float)(noise_divisions - 1) * length) * 65536.0);
  div = 0;
  if ( (flags & 0x10) != 0 )
    div = 0;
  factor = 1.0;
  v52 = flags & 0x40;
  if ( (flags & 0x40) != 0 )
    factor = 0.0;
  v30 = 0;
  *(float *)&v30 = fsqrt((float)((float)(delta->y * delta->y) + (float)(delta->z * delta->z)) + vLast);
  noiseStep = v30;
  v31 = fadeLength / *(float *)&v30;
  if ( v31 >= 0.000001 )
  {
    if ( v31 > 1.0 )
    {
      c = 1.0;
      goto LABEL_27;
    }
  }
  else
  {
    v31 = 0.000001;
  }
  c = v31;
LABEL_27:
  v32 = delta->z;
  *(_QWORD *)((char *)&noiseStep + 4) = *(_QWORD *)&delta->x;
  *((float *)&noiseStep + 3) = v32;
  VectorNormalize(vec: (Vector *)((char *)&noiseStep + 4));
  v33 = CurrentViewForward();
  v62.x = (float)(v33->y * *((float *)&noiseStep + 3)) - (float)(v33->z * *((float *)&noiseStep + 2));
  v62.y = (float)(v33->z * *((float *)&noiseStep + 1)) - (float)(*((float *)&noiseStep + 3) * v33->x);
  v62.z = (float)(*((float *)&noiseStep + 2) * v33->x) - (float)(v33->y * *((float *)&noiseStep + 1));
  VectorNormalize(vec: &v62);
  v34 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v35 = v34;
  v56 = v34;
  if ( v34 != nullptr )
    v34->BeginRender(this: v34);
  v50[0] = &CBeamSegDraw::`vftable';
  CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&(&segDraw.__vftable)[3]);
  segDraw.m_vNormalLast.x = 0.0;
  CBeamSegDraw::Start(
    this: (CBeamSegDraw *)v50,
    pRenderContext: v35,
    nSegs: v19,
    pMaterial: nullptr,
    pMeshBuilder: nullptr,
    nMeshVertCount: 0);
  v36 = 0;
  if ( v19 > 0 )
  {
    while ( 1 )
    {
      *(float *)&v37.m_pObject = (float)v36 * length;
      pRenderContext.m_pObject = v37.m_pObject;
      if ( v52 != 0 )
      {
        if ( (flags & 0x80u) == 0 )
        {
          v38 = *(float *)&v37.m_pObject / c;
          factor = *(float *)&v37.m_pObject / c;
        }
        else
        {
          v38 = *(float *)&v37.m_pObject >= 0.5
              ? (float)(1.0 - (float)(*(float *)&v37.m_pObject / c)) * 2.0
              : (float)(*(float *)&v37.m_pObject / c) * 2.0;
          factor = v38;
        }
      }
      else if ( (flags & 0x80u) == 0 )
      {
        v38 = factor;
      }
      else
      {
        v38 = 1.0 - (float)(*(float *)&v37.m_pObject / c);
        factor = v38;
      }
      if ( v38 < 0.0 )
        break;
      if ( v38 > 1.0 )
      {
        v38 = 1.0;
        goto LABEL_46;
      }
LABEL_47:
      v39 = *color * v38;
      v40 = v38;
      v41 = v38 * color[2];
      v42 = v40 * color[1];
      v54 = (float)(v39 * 255.0) + 8388608.0;
      LOBYTE(curSeg.m_vPos.y) = LOBYTE(v54);
      v60 = (float)(v42 * 255.0) + 8388608.0;
      BYTE1(curSeg.m_vPos.y) = LOBYTE(v60);
      *((float *)&segDraw.m_vecCameraPos + 4) = (float)(v41 * 255.0) + 8388608.0;
      BYTE2(curSeg.m_vPos.y) = *((_BYTE *)&segDraw.m_vecCameraPos + 16);
      v53 = 1258291455;
      HIBYTE(curSeg.m_vPos.y) = -1;
      v43 = (float)(*(float *)&v37.m_pObject * delta->y) + source->y;
      v44 = (float)(*(float *)&v37.m_pObject * delta->z) + source->z;
      v45 = (float)(delta->x * *(float *)&v37.m_pObject) + source->x;
      perp1.y = v45;
      perp1.z = v43;
      vStep = v44;
      if ( scalea != 0.0 )
      {
        v46 = prgNoise[div >> 16] * scalea;
        vLast = v46;
        if ( v57 != 0 )
        {
          p_s = &s;
          *((_DWORD *)&segDraw.m_vecCameraPos + 3) = &v67;
          *((float *)&segDraw.m_vecCameraPos + 5) = *(float *)&v37.m_pObject * 3.141592653589793 * v66 + freq;
          s = cos(*((float *)&segDraw.m_vecCameraPos + 5));
          v67 = sin(*((float *)&segDraw.m_vecCameraPos + 5));
          v47 = CurrentViewUp();
          perp1.y = (float)(v47->x * (float)(v67 * vLast)) + perp1.y;
          perp1.z = (float)(v47->y * (float)(v67 * vLast)) + perp1.z;
          vStep = (float)(v47->z * (float)(v67 * vLast)) + vStep;
          v48 = CurrentViewRight();
          v37.m_pObject = pRenderContext.m_pObject;
          perp1.y = (float)(v48->x * (float)(s * vLast)) + perp1.y;
          perp1.z = (float)(v48->y * (float)(s * vLast)) + perp1.z;
          vStep = (float)(v48->z * (float)(s * vLast)) + vStep;
        }
        else
        {
          perp1.y = (float)(v62.x * v46) + v45;
          perp1.z = (float)(v62.y * v46) + v43;
          vStep = (float)(v62.z * v46) + v44;
        }
      }
      if ( endWidth == startWidth )
        curSeg.m_vPos.w = startWidth * 2.0;
      else
        curSeg.m_vPos.w = (float)((float)((float)(endWidth - startWidth) * *(float *)&v37.m_pObject) + startWidth) * 2.0;
      curSeg.m_vPos.z = v68;
      CBeamSegDraw::NextSeg(this: (CBeamSegDraw *)v50, pSeg: (BeamSeg_t *)&perp1.y);
      div += v58;
      ++v36;
      v68 = v68 + perp1.x;
      if ( v36 >= v19 )
        goto LABEL_55;
    }
    v38 = 0.0;
LABEL_46:
    factor = v38;
    goto LABEL_47;
  }
LABEL_55:
  CBeamSegDraw::End(this: (CBeamSegDraw *)v50);
  if ( segDraw.m_Mesh.m_VertexBuilder.m_pUserData != nullptr
    && (*(unsigned __int8 (__thiscall **)(float *))(*(_DWORD *)segDraw.m_Mesh.m_VertexBuilder.m_pUserData + 8))(a1: segDraw.m_Mesh.m_VertexBuilder.m_pUserData) != 0 )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)segDraw.m_Mesh.m_VertexBuilder.m_pUserData + 16))(a1: segDraw.m_Mesh.m_VertexBuilder.m_pUserData);
  }
  if ( segDraw.m_Mesh.m_IndexBuilder.m_nOffset != 0
    && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)segDraw.m_Mesh.m_IndexBuilder.m_nOffset + 8))(a1: segDraw.m_Mesh.m_IndexBuilder.m_nOffset) != 0 )
  {
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)segDraw.m_Mesh.m_IndexBuilder.m_nOffset + 16))(a1: segDraw.m_Mesh.m_IndexBuilder.m_nOffset);
  }
  v49 = v56;
  if ( v56 != nullptr )
  {
    v56->EndRender(this: v56);
    v49->Release(this: v49);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020A60
// Name: void DrawTeslaSegs(int,float __near *,struct model_t const __near *,float,int,class Vector const __near &,class Vector const __near &,float,float,float,float,float,int,int,float __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DrawTeslaSegs(
        int a1@<ebp>,
        int noise_divisions,
        float *prgNoise,
        const struct model_t *spritemodel,
        __int64 frame,
        const Vector *source,
        const Vector *delta,
        float startWidth,
        float endWidth,
        float scale,
        float freq,
        float speed,
        int segments,
        int flags,
        float *color,
        float fadeLength,
        float flHDRColorScale)
{
  IMaterial *v17; // eax
  int v18; // edi
  IMaterial_vtbl *v19; // ecx
  int v20; // eax
  float z; // xmm1_4
  float y; // xmm2_4
  __int128 v23; // xmm0
  __int128 v24; // xmm0
  float v25; // xmm0_4
  float v26; // ecx
  const Vector *v27; // eax
  IMatRenderContext *v28; // eax
  IMatRenderContext *v29; // edi
  int v30; // edi
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  const Vector *v37; // eax
  const Vector *v38; // eax
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float x; // esi
  _DWORD v43[3]; // [esp+54h] [ebp-30Ch] BYREF
  CBeamSegDraw segDraw; // [esp+60h] [ebp-300h] BYREF
  float v45; // [esp+2B0h] [ebp-B0h]
  Vector vecEnd; // [esp+2B4h] [ebp-ACh] BYREF
  BeamSeg_t curSeg; // [esp+2C0h] [ebp-A0h] BYREF
  float v48; // [esp+2E0h] [ebp-80h]
  float v49; // [esp+2E4h] [ebp-7Ch]
  Vector perp; // [esp+2E8h] [ebp-78h]
  CMatRenderContextPtr pRenderContext; // [esp+2F4h] [ebp-6Ch]
  float div; // [esp+2F8h] [ebp-68h]
  float fraction; // [esp+2FCh] [ebp-64h]
  __int64 vStep; // [esp+300h] [ebp-60h] OVERLAPPED BYREF
  float v55; // [esp+308h] [ebp-58h]
  float v56; // [esp+30Ch] [ebp-54h]
  int v57; // [esp+310h] [ebp-50h]
  float v58; // [esp+314h] [ebp-4Ch]
  Vector v59; // [esp+318h] [ebp-48h] BYREF
  __int128 vecStart; // [esp+324h] [ebp-3Ch] OVERLAPPED
  float v61; // [esp+33Ch] [ebp-24h]
  float v62; // [esp+340h] [ebp-20h]
  __int64 v63; // [esp+344h] [ebp-1Ch] OVERLAPPED
  float vLast; // [esp+34Ch] [ebp-14h]
  float flWidth; // [esp+350h] [ebp-10h]
  int iBranches; // [esp+354h] [ebp-Ch]
  void *v67; // [esp+358h] [ebp-8h]
  void *retaddr; // [esp+360h] [ebp+0h]

  iBranches = a1;
  v67 = retaddr;
  v17 = Draw_SetSpriteTexture(
          a1: SHIDWORD(frame),
          pSpriteModel: spritemodel,
          frame: (int)*(float *)&frame,
          rendermode: SHIDWORD(frame));
  if ( v17 == nullptr )
    return;
  v18 = segments;
  if ( segments < 2 )
    return;
  v19 = v17[HIDWORD(frame) + 4].__vftable;
  if ( v19 != nullptr )
  {
    v20 = (*((int (__thiscall **)(IMaterial_vtbl *, const char *, unsigned int *))v19->GetName + 47))(
            a1: v19,
            a2: "$hdrcolorscale",
            a3: &nHDRColorScaleCache_1);
    if ( v20 != 0 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v20 + 16))(a1: v20, a2: LODWORD(flHDRColorScale));
  }
  if ( segments > noise_divisions )
  {
    segments = noise_divisions;
    v18 = noise_divisions;
  }
  z = delta->z;
  y = delta->y;
  *(float *)&v63 = delta->x * delta->x;
  v23 = 0;
  *(float *)&v23 = fsqrt((float)((float)(y * y) + (float)(z * z)) + *(float *)&v63);
  vecStart = v23;
  perp.y = 1.0 / (double)(v18 - 1);
  *(float *)&pRenderContext.m_pObject = (float)(*(float *)&v23 * 0.01) * perp.y;
  v62 = fmod(freq * speed, 1.0);
  flWidth = 1.0;
  v57 = flags & 0x40;
  if ( (flags & 0x40) != 0 )
    flWidth = 0.0;
  v24 = 0;
  *(float *)&v24 = fsqrt((float)((float)(delta->y * delta->y) + (float)(delta->z * delta->z)) + *(float *)&v63);
  vecStart = v24;
  v25 = fadeLength / *(float *)&v24;
  if ( v25 >= 0.000001 )
  {
    if ( v25 > 1.0 )
    {
      vLast = 1.0;
      goto LABEL_13;
    }
  }
  else
  {
    v25 = 0.000001;
  }
  vLast = v25;
LABEL_13:
  v26 = delta->z;
  vStep = *(_QWORD *)&delta->x;
  v55 = v26;
  VectorNormalize(vec: (Vector *)&vStep);
  v27 = CurrentViewForward();
  *(&curSeg.m_flWidth + 1) = (float)(v27->y * v55) - (float)(v27->z * *((float *)&vStep + 1));
  v48 = (float)(v27->z * *(float *)&vStep) - (float)(v27->x * v55);
  v49 = (float)(v27->x * *((float *)&vStep + 1)) - (float)(v27->y * *(float *)&vStep);
  VectorNormalize(vec: (Vector *)(&curSeg.m_flWidth + 1));
  v28 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v29 = v28;
  LODWORD(perp.x) = v28;
  if ( v28 != nullptr )
    v28->BeginRender(this: v28);
  v43[0] = &CBeamSegDraw::`vftable';
  CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&(&segDraw.__vftable)[3]);
  segDraw.m_vNormalLast.x = 0.0;
  CBeamSegDraw::Start(
    this: (CBeamSegDraw *)v43,
    pRenderContext: v29,
    nSegs: segments,
    pMaterial: nullptr,
    pMeshBuilder: nullptr,
    nMeshVertCount: 0);
  v30 = 0;
  v63 = 0;
  v61 = 0.0;
  if ( segments > 0 )
  {
    while ( 1 )
    {
      v31 = (float)v30 * perp.y;
      perp.z = v31;
      if ( v57 != 0 )
      {
        if ( (flags & 0x80u) == 0 )
        {
          v32 = v31 / vLast;
          flWidth = v31 / vLast;
        }
        else
        {
          v32 = v31 >= 0.5 ? (float)(1.0 - (float)(v31 / vLast)) * 2.0 : (float)(v31 / vLast) * 2.0;
          flWidth = v32;
        }
      }
      else if ( (flags & 0x80u) == 0 )
      {
        v32 = flWidth;
      }
      else
      {
        v32 = 1.0 - (float)(v31 / vLast);
        flWidth = v32;
      }
      if ( v32 < 0.0 )
        break;
      if ( v32 > 1.0 )
      {
        v32 = 1.0;
        goto LABEL_32;
      }
LABEL_33:
      v33 = color[1];
      v34 = color[2];
      div = (float)((float)(*color * v32) * 255.0) + 8388608.0;
      LOBYTE(curSeg.m_vPos.y) = LOBYTE(div);
      v56 = (float)((float)(v33 * v32) * 255.0) + 8388608.0;
      BYTE1(curSeg.m_vPos.y) = LOBYTE(v56);
      v58 = (float)((float)(v34 * v32) * 255.0) + 8388608.0;
      BYTE2(curSeg.m_vPos.y) = LOBYTE(v58);
      fraction = 8388863.0;
      HIBYTE(curSeg.m_vPos.y) = -1;
      CalcSegOrigin(
        vecOut: &vecEnd,
        iPoint: v30,
        noise_divisions,
        prgNoise,
        source,
        delta,
        perp: (const Vector *)(&curSeg.m_flWidth + 1),
        segments,
        freq,
        scale,
        fraction: v31,
        flags);
      if ( endWidth == startWidth )
        v35 = startWidth;
      else
        v35 = (float)((float)(endWidth - startWidth) * perp.z) + startWidth;
      v36 = v35 * 2.0;
      curSeg.m_vPos.w = v36;
      if ( v30 < SHIDWORD(v63) )
      {
        while ( 1 )
          v36 = v36 * 0.5;
      }
      curSeg.m_vPos.z = v62;
      CBeamSegDraw::NextSeg(this: (CBeamSegDraw *)v43, pSeg: (BeamSeg_t *)&vecEnd);
      v62 = v62 + *(float *)&pRenderContext.m_pObject;
      if ( (double)v30 == (double)segments * 0.5 )
      {
        *(float *)&v63 = curSeg.m_vPos.w * 0.25;
        if ( (float)(curSeg.m_vPos.w * 0.25) > 1.0 )
        {
          ++HIDWORD(v63);
          v59 = vecEnd;
          v37 = CurrentViewRight();
          *((float *)&vecStart + 1) = v37->x * 32.0;
          *((float *)&vecStart + 2) = v37->y * 32.0;
          *((float *)&vecStart + 3) = v37->z * 32.0;
          v38 = CurrentViewUp();
          v39 = (float)((float)((float)(source->y + delta->y) + (float)(v38->y * 32.0)) + *((float *)&vecStart + 2))
              - v59.y;
          v40 = (float)((float)((float)(source->z + delta->z) + (float)(v38->z * 32.0)) + *((float *)&vecStart + 3))
              - v59.z;
          *((float *)&segDraw.m_vecCameraPos + 4) = (float)((float)((float)(source->x + delta->x)
                                                                  + (float)(v38->x * 32.0))
                                                          + *((float *)&vecStart + 1))
                                                  - v59.x;
          v41 = endWidth;
          *((float *)&segDraw.m_vecCameraPos + 5) = v39;
          v45 = v40;
          v61 = endWidth;
          if ( v30 < SHIDWORD(v63) )
          {
            while ( 1 )
              v41 = v41 * 0.5;
          }
        }
      }
      if ( ++v30 >= segments )
        goto LABEL_44;
    }
    v32 = 0.0;
LABEL_32:
    flWidth = v32;
    goto LABEL_33;
  }
LABEL_44:
  CBeamSegDraw::End(this: (CBeamSegDraw *)v43);
  if ( HIDWORD(v63) != 0 )
    DrawTeslaSegs(
      noise_divisions,
      prgNoise,
      spritemodel,
      frame: *(float *)&frame,
      rendermode: SHIDWORD(frame),
      source: &v59,
      delta: (const Vector *)((char *)&segDraw.m_vecCameraPos + 16),
      startWidth: *(float *)&v63,
      endWidth: v61,
      scale,
      freq,
      speed,
      segments,
      flags,
      color,
      fadeLength,
      flHDRColorScale);
  if ( segDraw.m_Mesh.m_VertexBuilder.m_pUserData != nullptr
    && (*(unsigned __int8 (__thiscall **)(float *))(*(_DWORD *)segDraw.m_Mesh.m_VertexBuilder.m_pUserData + 8))(a1: segDraw.m_Mesh.m_VertexBuilder.m_pUserData) != 0 )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)segDraw.m_Mesh.m_VertexBuilder.m_pUserData + 16))(a1: segDraw.m_Mesh.m_VertexBuilder.m_pUserData);
  }
  if ( segDraw.m_Mesh.m_IndexBuilder.m_nOffset != 0
    && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)segDraw.m_Mesh.m_IndexBuilder.m_nOffset + 8))(a1: segDraw.m_Mesh.m_IndexBuilder.m_nOffset) != 0 )
  {
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)segDraw.m_Mesh.m_IndexBuilder.m_nOffset + 16))(a1: segDraw.m_Mesh.m_IndexBuilder.m_nOffset);
  }
  x = perp.x;
  if ( LODWORD(perp.x) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(perp.x) + 12))(a1: LODWORD(perp.x));
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(x) + 4))(a1: COERCE_FLOAT(LODWORD(x)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021160
// Name: void DrawSplineSegs(int,float __near *,struct model_t const __near *,struct model_t const __near *,float,float,int,int,class Vector __near *,float,float,float,float,float,int,int,float __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DrawSplineSegs(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        int noise_divisions,
        float *prgNoise,
        const struct model_t *beammodel,
        const struct model_t *halomodel,
        float flHaloScale,
        float frame,
        RenderMode_t rendermode,
        int numAttachments,
        Vector *attachment,
        float startWidth,
        float endWidth,
        float scale,
        float freq,
        float speed,
        int segments,
        char flags,
        float *color,
        float fadeLength,
        float flHDRColorScale)
{
  IMaterial *v22; // eax
  IMaterial *v23; // esi
  IMaterial_vtbl *v24; // ecx
  int v25; // eax
  IMaterial *v26; // esi
  float v27; // eax
  float v28; // edi
  float *v29; // eax
  int v30; // esi
  float v31; // xmm0_4
  float v32; // edx
  float y; // xmm1_4
  float v34; // xmm2_4
  Vector *v35; // eax
  float x; // xmm3_4
  float v37; // xmm5_4
  int z_low; // xmm6_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  Vector *v42; // eax
  float v43; // xmm1_4
  __int128 v44; // xmm0
  float v45; // xmm0_4
  float v46; // xmm5_4
  float v47; // xmm0_4
  float v48; // xmm3_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  int v51; // edi
  const Vector *v52; // eax
  float v53; // xmm0_4
  float *v54; // esi
  float v55; // xmm0_4
  const Vector *v56; // eax
  const Vector *v57; // eax
  float v58; // xmm0_4
  const Vector *v59; // eax
  __m128i v60; // xmm0
  double v61; // xmm0_8
  float v62; // esi
  _DWORD v63[3]; // [esp+34h] [ebp-37Ch] BYREF
  _BYTE segDraw_12[584]; // [esp+4Ch] [ebp-364h] OVERLAPPED BYREF
  float v65[3]; // [esp+298h] [ebp-118h] BYREF
  float scaledColor[3]; // [esp+2A4h] [ebp-10Ch]
  float v67; // [esp+2B0h] [ebp-100h]
  int v68; // [esp+2B4h] [ebp-FCh]
  float v69; // [esp+2B8h] [ebp-F8h] BYREF
  float startSegWidth; // [esp+2BCh] [ebp-F4h]
  int noiseStep; // [esp+2C0h] [ebp-F0h]
  Vector pStart; // [esp+2C4h] [ebp-ECh]
  float *p_y; // [esp+2D0h] [ebp-E0h]
  int v74; // [esp+2D4h] [ebp-DCh]
  CMatRenderContextPtr pRenderContext; // [esp+2D8h] [ebp-D8h]
  float v76; // [esp+2DCh] [ebp-D4h]
  float v77; // [esp+2E0h] [ebp-D0h]
  float v78; // [esp+2E4h] [ebp-CCh]
  float vStep; // [esp+2E8h] [ebp-C8h]
  float *p_length; // [esp+2ECh] [ebp-C4h]
  float endSegWidth; // [esp+2F0h] [ebp-C0h] BYREF
  float v82; // [esp+2F4h] [ebp-BCh]
  float v83; // [esp+2F8h] [ebp-B8h]
  Vector pEnd; // [esp+2FCh] [ebp-B4h] BYREF
  Vector vBeamDir1; // [esp+308h] [ebp-A8h] BYREF
  Vector vLookDir; // [esp+314h] [ebp-9Ch] BYREF
  Vector vTarget; // [esp+320h] [ebp-90h] BYREF
  float widthStep; // [esp+32Ch] [ebp-84h]
  float bestDot; // [esp+330h] [ebp-80h]
  Vector pNext; // [esp+334h] [ebp-7Ch] BYREF
  float z; // [esp+340h] [ebp-70h]
  Vector pPre; // [esp+344h] [ebp-6Ch] BYREF
  float div; // [esp+350h] [ebp-60h]
  int s; // [esp+354h] [ebp-5Ch]
  Vector vLastPoint; // [esp+358h] [ebp-58h]
  float length; // [esp+364h] [ebp-4Ch] BYREF
  int vLast; // [esp+368h] [ebp-48h]
  IMaterial *pHaloMaterial; // [esp+36Ch] [ebp-44h]
  int c; // [esp+370h] [ebp-40h]
  float v100; // [esp+374h] [ebp-3Ch] BYREF
  float fraction; // [esp+378h] [ebp-38h]
  int noiseIndex; // [esp+37Ch] [ebp-34h]
  BeamSeg_t seg; // [esp+380h] [ebp-30h]
  float v104; // [esp+3A0h] [ebp-10h]
  int v105; // [esp+3A4h] [ebp-Ch]
  void *v106; // [esp+3A8h] [ebp-8h]
  float factor; // [esp+3ACh] [ebp-4h] BYREF
  void *retaddr; // [esp+3B0h] [ebp+0h]

  v105 = a1;
  v106 = retaddr;
  v22 = Draw_SetSpriteTexture(a1: a3, pSpriteModel: beammodel, (int)frame, rendermode);
  v23 = v22;
  if ( v22 != nullptr && segments >= 2 )
  {
    v24 = v22[rendermode + 4].__vftable;
    if ( v24 != nullptr )
    {
      v25 = (*((int (__thiscall **)(IMaterial_vtbl *, const char *, unsigned int *))v24->GetName + 47))(
              a1: v24,
              a2: "$hdrcolorscale",
              a3: &nHDRColorScaleCache_2);
      if ( v25 != 0 )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v25 + 16))(a1: v25, a2: LODWORD(flHDRColorScale));
    }
    if ( segments > noise_divisions )
      segments = noise_divisions;
    LODWORD(pNext.x) = flags & 0x10;
    if ( (flags & 0x10) != 0 && segments < 16 )
      segments = 16;
    v26 = (IMaterial *)v23[rendermode + 4].__vftable;
    v27 = COERCE_FLOAT(((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2));
    v28 = v27;
    pStart.z = v27;
    if ( v27 != 0.0 )
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v27) + 8))(a1: COERCE_FLOAT(LODWORD(v27)));
    v63[0] = &CBeamSegDraw::`vftable';
    CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)segDraw_12);
    *(_DWORD *)&segDraw_12[540] = 0;
    vLast = numAttachments - 1;
    CBeamSegDraw::Start(
      this: (CBeamSegDraw *)v63,
      pRenderContext: (IMatRenderContext *)LODWORD(v28),
      nSegs: (numAttachments - 1) * (segments - 1),
      pMaterial: v26,
      pMeshBuilder: nullptr,
      nMeshVertCount: 0);
    v29 = (float *)modelinfo->GetModelExtraData(this: modelinfo, a2: halomodel);
    v30 = 0;
    vLastPoint.z = 0.0;
    if ( v29 != nullptr )
      vLastPoint.z = v29[7];
    if ( startWidth == endWidth )
      vTarget.x = 0.0;
    else
      vTarget.x = (float)(endWidth - startWidth) / (float)numAttachments;
    pPre.z = 0.0;
    div = 0.0;
    *(float *)&s = 0.0;
    if ( vLast > 0 )
    {
      v31 = 1.0 / (double)(segments - 1);
      pPre.x = v31;
      pStart.y = fmod(freq * speed, 1.0);
      LODWORD(v32) = flags & 0x40;
      scaledColor[0] = (float)(noise_divisions - 1);
      scaledColor[2] = v32;
      do
      {
        if ( v30 != 0 )
        {
          v35 = &attachment[v30];
          pNext.y = v35[-1].x;
          pNext.z = v35[-1].y;
          z = v35[-1].z;
        }
        else
        {
          y = attachment->y;
          v34 = attachment->z;
          pNext.y = attachment->x;
          pNext.z = y;
          z = v34;
          pPre.z = pNext.y;
          div = y;
          *(float *)&s = v34;
        }
        x = attachment[v30].x;
        v37 = attachment[v30].y;
        z_low = SLODWORD(attachment[v30].z);
        v39 = attachment[v30 + 1].x;
        v40 = attachment[v30 + 1].y;
        v41 = attachment[v30 + 1].z;
        v69 = x;
        startSegWidth = v37;
        noiseStep = z_low;
        endSegWidth = v39;
        v82 = v40;
        v83 = v41;
        if ( v30 + 2 < vLast )
        {
          v42 = &attachment[v30 + 2];
          vTarget.z = v42->x;
          widthStep = v42->y;
          bestDot = v42->z;
        }
        else
        {
          vTarget.z = v39;
          widthStep = v40;
          bestDot = v41;
        }
        v43 = (float)((float)((float)(v40 - v37) * (float)(v40 - v37))
                    + (float)((float)(v41 - *(float *)&z_low) * (float)(v41 - *(float *)&z_low)))
            + (float)((float)(v39 - x) * (float)(v39 - x));
        v44 = 0;
        *(float *)&v44 = fsqrt(v43);
        *(_OWORD *)&segDraw_12[568] = v44;
        v45 = *(float *)&v44 * 0.01;
        vLastPoint.x = v45;
        if ( v45 < 0.5 )
        {
          v45 = 0.5;
          vLastPoint.x = 0.5;
        }
        v46 = pPre.x;
        v76 = pPre.x * v45;
        vLastPoint.y = pStart.y;
        if ( LODWORD(pNext.x) != 0 )
        {
          scale = scale * 100.0;
          v47 = (double)segments * 0.1;
          vLastPoint.x = v47;
        }
        else
        {
          scale = v45 * scale;
        }
        v68 = (int)(float)((float)(scaledColor[0] * pPre.x) * 65536.0);
        c = v68;
        if ( LODWORD(pNext.x) != 0 )
          c = 0;
        v48 = 1.0;
        if ( v32 != 0.0 )
          v48 = 0.0;
        v49 = color[1];
        v50 = color[2];
        v65[0] = *color * v48;
        v65[1] = v49 * v48;
        v65[2] = v50 * v48;
        pStart.x = (float)(v65[0] * 255.0) + 8388608.0;
        LOBYTE(seg.m_vPos.y) = LOBYTE(pStart.x);
        vStep = (float)((float)(v49 * v48) * 255.0) + 8388608.0;
        BYTE1(seg.m_vPos.y) = LOBYTE(vStep);
        v77 = (float)((float)(v50 * v48) * 255.0) + 8388608.0;
        BYTE2(seg.m_vPos.y) = LOBYTE(v77);
        pRenderContext.m_pObject = (IMatRenderContext *)1258291455;
        v67 = (float)((float)v30++ * vTarget.x) + startWidth;
        v51 = 1;
        HIBYTE(seg.m_vPos.y) = -1;
        v74 = v30;
        v78 = (float)((float)v30 * vTarget.x) + startWidth;
        vTarget.y = 0.0;
        if ( segments > 1 )
        {
          while ( 1 )
          {
            *(float *)&pHaloMaterial = (float)v51 * v46;
            memset((void *)&vLookDir, 0, sizeof(vLookDir));
            Catmull_Rom_Spline(
              p1: (Vector *)&pNext.y,
              p2: (const Vector *)&v69,
              p3: (const Vector *)&endSegWidth,
              p4: (Vector *)&vTarget.z,
              t: *(float *)&pHaloMaterial,
              output: &vLookDir);
            v100 = vLookDir.x;
            fraction = vLookDir.y;
            noiseIndex = SLODWORD(vLookDir.z);
            if ( LODWORD(vLastPoint.z) != 0 )
            {
              pEnd.x = vLookDir.x - pPre.z;
              pEnd.y = vLookDir.y - div;
              pEnd.z = vLookDir.z - *(float *)&s;
              VectorNormalize(vec: &pEnd);
              v52 = CurrentViewOrigin();
              vBeamDir1.x = v52->x - v100;
              vBeamDir1.y = v52->y - fraction;
              vBeamDir1.z = v52->z - *(float *)&noiseIndex;
              VectorNormalize(vec: &vBeamDir1);
              v53 = fabs(
                      (float)((float)(vBeamDir1.y * pEnd.y) + (float)(vBeamDir1.x * pEnd.x))
                    + (float)(vBeamDir1.z * pEnd.z));
              if ( v53 > thresh && v53 > vTarget.y )
                vTarget.y = v53;
              pPre.z = v100;
              div = fraction;
              s = noiseIndex;
            }
            if ( scale != 0.0 )
            {
              v54 = &prgNoise[c >> 16];
              v104 = *v54 * scale;
              if ( LODWORD(pNext.x) != 0 )
              {
                v55 = *(float *)&pHaloMaterial * 3.141592653589793 * vLastPoint.x + freq;
                p_length = &length;
                p_y = &pPre.y;
                scaledColor[1] = v55;
                length = cos(v55);
                pPre.y = sin(v55);
                v56 = CurrentViewUp();
                v100 = (float)(v56->x * (float)(pPre.y * v104)) + v100;
                fraction = (float)(v56->y * (float)(pPre.y * v104)) + fraction;
                *(float *)&noiseIndex = (float)(v56->z * (float)(pPre.y * v104)) + *(float *)&noiseIndex;
                v57 = CurrentViewRight();
                v58 = length * v104;
              }
              else
              {
                v59 = CurrentViewUp();
                v100 = (float)(v104 * v59->x) + v100;
                fraction = (float)(v59->y * v104) + fraction;
                v60 = (__m128i)_mm_cvtps_pd((__m128)(unsigned int)pHaloMaterial);
                *(float *)&noiseIndex = (float)(v59->z * v104) + *(float *)&noiseIndex;
                *(double *)v60.m128i_i64 = *(double *)v60.m128i_i64 * 3.141592653589793 * 3.0 + freq;
                __libm_sse2_cos(X: v60);
                *(float *)&v61 = v61 * (float)(*v54 * scale);
                v104 = *(float *)&v61;
                v57 = CurrentViewRight();
                v58 = v104;
              }
              v100 = (float)(v57->x * v58) + v100;
              fraction = (float)(v57->y * v58) + fraction;
              *(float *)&noiseIndex = (float)(v57->z * v58) + *(float *)&noiseIndex;
            }
            seg.m_vPos.w = startWidth == endWidth
                         ? startWidth * 2.0
                         : (float)((float)((float)(v78 - v67) * *(float *)&pHaloMaterial) + v67) * 2.0;
            seg.m_vPos.z = vLastPoint.y;
            CBeamSegDraw::NextSeg(this: (CBeamSegDraw *)v63, pSeg: (BeamSeg_t *)&v100);
            c += v68;
            ++v51;
            vLastPoint.y = vLastPoint.y + v76;
            if ( v51 >= segments )
              break;
            v46 = pPre.x;
          }
          v30 = v74;
          v32 = scaledColor[2];
        }
      }
      while ( v30 < vLast );
      v28 = pStart.z;
    }
    CBeamSegDraw::End(this: (CBeamSegDraw *)v63);
    v62 = vLastPoint.z;
    if ( LODWORD(vLastPoint.z) != 0 )
    {
      (*(void (__thiscall **)(float, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v28) + 36))(
        a1: COERCE_FLOAT(LODWORD(v28)),
        a2: LODWORD(vLastPoint.z),
        a3: 0);
      DrawHalo(
        a1: (int)&factor,
        pMaterial: (IMaterial *)LODWORD(v62),
        source: (const Vector *)&endSegWidth,
        scale: flHaloScale,
        color: v65,
        flHDRColorScale);
    }
    if ( *(_DWORD *)&segDraw_12[408] != 0
      && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&segDraw_12[408] + 8))(a1: *(_DWORD *)&segDraw_12[408]) != 0 )
    {
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&segDraw_12[408] + 16))(a1: *(_DWORD *)&segDraw_12[408]);
    }
    if ( *(_DWORD *)&segDraw_12[208] != 0
      && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&segDraw_12[208] + 8))(a1: *(_DWORD *)&segDraw_12[208]) != 0 )
    {
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&segDraw_12[208] + 16))(a1: *(_DWORD *)&segDraw_12[208]);
    }
    if ( v28 != 0.0 )
    {
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v28) + 12))(a1: COERCE_FLOAT(LODWORD(v28)));
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v28) + 4))(a1: COERCE_FLOAT(LODWORD(v28)));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021AC0
// Name: void BeamDrawHalo(struct model_t const __near *,float,int,class Vector const __near &,float,float __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall BeamDrawHalo(
        int a1@<ebx>,
        const struct model_t *spritemodel,
        float frame,
        RenderMode_t rendermode,
        const Vector *source,
        float scale,
        float *color,
        float flHDRColorScale)
{
  IMaterial *v8; // eax

  v8 = Draw_SetSpriteTexture(a1: rendermode, pSpriteModel: spritemodel, (int)frame, rendermode);
  if ( v8 != nullptr )
    DrawHalo(a1, pMaterial: (IMaterial *)v8[rendermode + 4].__vftable, source, scale, color, flHDRColorScale);
}

//------------------------------------------------------------------------------
// Address: 0x10021B10
// Name: void DrawDisk(int,float __near *,struct model_t const __near *,float,int,class Vector const __near &,class Vector const __near &,float,float,float,float,int,float __near *,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawDisk(
        float a1@<ebp>,
        int noise_divisions,
        float *prgNoise,
        const struct model_t *spritemodel,
        float frame,
        RenderMode_t rendermode,
        const Vector *source,
        const Vector *delta,
        float width,
        float scale,
        float freq,
        float speed,
        int segments,
        float *color,
        float flHDRColorScale)
{
  IMaterial *v15; // eax
  int v16; // edi
  IMaterial_vtbl *v17; // ecx
  int v18; // eax
  __int128 v19; // xmm0
  float v20; // xmm0_4
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // eax
  int v22; // eax
  int v23; // esi
  IMesh *v24; // esi
  int v25; // edi
  float v26; // xmm5_4
  int v27; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  float v30; // xmm6_4
  int v31; // eax
  int v32; // eax
  float v33; // xmm0_4
  float *v34; // eax
  float v35; // xmm4_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm5_4
  int v39; // eax
  int v40; // eax
  int v41; // eax
  void (__thiscall *v42)(_DWORD, _DWORD, _DWORD); // eax
  int v43; // esi
  _DWORD v44[3]; // [esp+1Ch] [ebp-25Ch] BYREF
  _BYTE meshBuilder_144[356]; // [esp+B8h] [ebp-1C0h] OVERLAPPED BYREF
  float v46; // [esp+228h] [ebp-50h]
  int v47; // [esp+22Ch] [ebp-4Ch]
  float *v48; // [esp+230h] [ebp-48h]
  IMesh *v49; // [esp+234h] [ebp-44h]
  CMatRenderContextPtr pRenderContext; // [esp+238h] [ebp-40h]
  float v51; // [esp+23Ch] [ebp-3Ch]
  IMesh *pMesh; // [esp+240h] [ebp-38h]
  float w; // [esp+244h] [ebp-34h]
  float vStep; // [esp+248h] [ebp-30h]
  float v55; // [esp+24Ch] [ebp-2Ch]
  float v56; // [esp+250h] [ebp-28h]
  float div; // [esp+254h] [ebp-24h]
  float *v58; // [esp+258h] [ebp-20h]
  int v59; // [esp+25Ch] [ebp-1Ch]
  float v60; // [esp+260h] [ebp-18h] BYREF
  float v61; // [esp+264h] [ebp-14h] BYREF
  int i; // [esp+268h] [ebp-10h]
  float c; // [esp+26Ch] [ebp-Ch]
  float s; // [esp+270h] [ebp-8h]
  float retaddr; // [esp+278h] [ebp+0h]

  c = a1;
  s = retaddr;
  v15 = Draw_SetSpriteTexture(a1: rendermode, pSpriteModel: spritemodel, (int)frame, rendermode);
  if ( v15 != nullptr )
  {
    v16 = segments;
    if ( segments >= 2 )
    {
      v17 = v15[rendermode + 4].__vftable;
      if ( v17 != nullptr )
      {
        v18 = (*((int (__thiscall **)(IMaterial_vtbl *, const char *, unsigned int *))v17->GetName + 47))(
                a1: v17,
                a2: "$hdrcolorscale",
                a3: &nHDRColorScaleCache_3);
        if ( v18 != 0 )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v18 + 16))(a1: v18, a2: LODWORD(flHDRColorScale));
      }
      if ( segments > noise_divisions )
      {
        segments = noise_divisions;
        v16 = noise_divisions;
      }
      v19 = 0;
      *(float *)&v19 = fsqrt(
                         (float)((float)(delta->x * delta->x) + (float)(delta->y * delta->y))
                       + (float)(delta->z * delta->z));
      *(_OWORD *)&meshBuilder_144[340] = v19;
      v20 = *(float *)&v19 * 0.01;
      if ( v20 < 0.5 )
        v20 = 0.5;
      vStep = 1.0 / (double)(v16 - 1);
      v51 = vStep * v20;
      *(float *)&i = fmod(freq * speed, 1.0);
      GetRenderContext = materials->GetRenderContext;
      *(float *)&pRenderContext.m_pObject = delta->z * freq;
      v22 = (int)GetRenderContext(this: materials);
      v23 = v22;
      v47 = v22;
      if ( v22 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v22 + 8))(a1: v22);
      v24 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v23 + 228))(
                       a1: v23,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
      v49 = v24;
      CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)v44);
      *(_DWORD *)&meshBuilder_144[24] = v24;
      meshBuilder_144[32] = 1;
      *(_DWORD *)&meshBuilder_144[28] = 3;
      v25 = 2 * v16;
      v24->SetPrimitiveType(this: v24, a2: MATERIAL_TRIANGLE_STRIP);
      (*(void (__thiscall **)(_DWORD, int, int, _DWORD *, _DWORD))(**(_DWORD **)&meshBuilder_144[24] + 68))(
        a1: *(_DWORD *)&meshBuilder_144[24],
        a2: v25,
        a3: v25,
        a4: v44,
        a5: 0);
      *(_DWORD *)&meshBuilder_144[36] = *(_DWORD *)&meshBuilder_144[8];
      *(_DWORD *)&meshBuilder_144[64] = *(_DWORD *)meshBuilder_144;
      *(_DWORD *)&meshBuilder_144[52] = &v24->IIndexBuffer;
      *(_DWORD *)&meshBuilder_144[48] = *(_DWORD *)&meshBuilder_144[20];
      *(_DWORD *)&meshBuilder_144[60] = 0;
      *(_DWORD *)&meshBuilder_144[56] = v25;
      meshBuilder_144[84] = 0;
      *(_DWORD *)&meshBuilder_144[68] = 0;
      CVertexBuilder::AttachBegin(
        this: (CVertexBuilder *)&meshBuilder_144[88],
        pMesh: v24,
        nMaxVertexCount: v25,
        desc: (const MeshDesc_t *)v44);
      *(_DWORD *)&meshBuilder_144[68] = 0;
      CVertexBuilder::Reset(this: (CVertexBuilder *)&meshBuilder_144[88]);
      v59 = 0;
      if ( segments > 0 )
      {
        v26 = *(float *)&i;
        v58 = &v60;
        v48 = &v61;
        do
        {
          y = source->y;
          z = source->z;
          v30 = (float)(color[2] * 255.0) + 8388608.0;
          *(float *)&meshBuilder_144[344] = source->x;
          v27 = *(_DWORD *)&meshBuilder_144[344];
          *(float *)&meshBuilder_144[348] = y;
          *(float *)&meshBuilder_144[352] = z;
          v46 = v30;
          v56 = (float)(color[1] * 255.0) + 8388608.0;
          *(float *)&pMesh = (float)(*color * 255.0) + 8388608.0;
          **(_DWORD **)&meshBuilder_144[280] = LOBYTE(v30)
                                             | ((LOBYTE(v56) | (((unsigned __int8)pMesh | 0xFFFFFF00) << 8)) << 8);
          v31 = *(_DWORD *)&meshBuilder_144[284];
          **(_DWORD **)&meshBuilder_144[284] = 1065353216;
          *(float *)(v31 + 4) = v26;
          v32 = *(_DWORD *)&meshBuilder_144[272];
          **(_DWORD **)&meshBuilder_144[272] = v27;
          *(float *)(v32 + 4) = y;
          *(float *)(v32 + 8) = z;
          CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder_144[88]);
          v33 = (float)((float)((float)v59 * vStep) * 2.0) * 3.141592653589793;
          *(float *)&meshBuilder_144[336] = v33;
          v34 = v48;
          *v58 = cos(v33);
          *v34 = sin(v33);
          v35 = source->z;
          v37 = (float)(v60 * *(float *)&pRenderContext.m_pObject) + source->y;
          v38 = (float)(color[2] * 255.0) + 8388608.0;
          *(float *)&meshBuilder_144[344] = (float)(v61 * *(float *)&pRenderContext.m_pObject) + source->x;
          v36 = *(float *)&meshBuilder_144[344];
          *(float *)&meshBuilder_144[348] = v37;
          *(float *)&meshBuilder_144[352] = v35;
          w = v38;
          v55 = (float)(color[1] * 255.0) + 8388608.0;
          div = (float)(*color * 255.0) + 8388608.0;
          **(_DWORD **)&meshBuilder_144[280] = LOBYTE(v38) | ((LOBYTE(v55) | ((LOBYTE(div) | 0xFFFFFF00) << 8)) << 8);
          v39 = *(_DWORD *)&meshBuilder_144[284];
          **(_DWORD **)&meshBuilder_144[284] = 0;
          *(float *)(v39 + 4) = *(float *)&i;
          v40 = *(_DWORD *)&meshBuilder_144[272];
          **(float **)&meshBuilder_144[272] = v36;
          *(float *)(v40 + 4) = v37;
          *(float *)(v40 + 8) = v35;
          CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder_144[88]);
          v26 = *(float *)&i + v51;
          *(float *)&i = *(float *)&i + v51;
          ++v59;
        }
        while ( v59 < segments );
        v24 = v49;
      }
      if ( meshBuilder_144[32] != 0 )
      {
        switch ( *(_DWORD *)&meshBuilder_144[28] )
        {
          case 4:
            v41 = 2 * *(_DWORD *)&meshBuilder_144[264] - 2;
            break;
          case 5:
            v41 = 2 * *(_DWORD *)&meshBuilder_144[264];
            break;
          case 6:
            v41 = 3 * *(_DWORD *)&meshBuilder_144[264] - 6;
            break;
          case 7:
            v41 = 6 * *(_DWORD *)&meshBuilder_144[264] / 4;
            break;
          case 0xA:
            v41 = 0;
            break;
          default:
            v41 = *(_DWORD *)&meshBuilder_144[264];
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: (CIndexBuilder *)&meshBuilder_144[36],
          primitiveType: *(MaterialPrimitiveType_t *)&meshBuilder_144[28],
          nIndexCount: v41);
      }
      v42 = *(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)&meshBuilder_144[24] + 80);
      v44[0] = v44;
      v42(
        a1: *(_DWORD *)&meshBuilder_144[24],
        a2: *(_DWORD *)&meshBuilder_144[264],
        a3: *(_DWORD *)&meshBuilder_144[60]);
      *(_DWORD *)&meshBuilder_144[52] = 0;
      *(_DWORD *)&meshBuilder_144[56] = 0;
      *(_DWORD *)&meshBuilder_144[260] = 0;
      *(_DWORD *)&meshBuilder_144[252] = 0;
      *(_DWORD *)&meshBuilder_144[24] = 0;
      *(_DWORD *)&meshBuilder_144[164] = -1;
      v24->Draw_2(this: v24, a2: -1, a3: 0);
      if ( *(_DWORD *)&meshBuilder_144[252] != 0
        && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[252] + 8))(a1: *(_DWORD *)&meshBuilder_144[252]) != 0 )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[252] + 16))(a1: *(_DWORD *)&meshBuilder_144[252]);
      }
      if ( *(_DWORD *)&meshBuilder_144[52] != 0
        && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[52] + 8))(a1: *(_DWORD *)&meshBuilder_144[52]) != 0 )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[52] + 16))(a1: *(_DWORD *)&meshBuilder_144[52]);
      }
      v43 = v47;
      (*(void (__thiscall **)(int))(*(_DWORD *)v47 + 12))(a1: v47);
      (*(void (__thiscall **)(int))(*(_DWORD *)v43 + 4))(a1: v43);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022090
// Name: void DrawCylinder(int,float __near *,struct model_t const __near *,float,int,class Vector const __near &,class Vector const __near &,float,float,float,float,int,float __near *,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawCylinder(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        int noise_divisions,
        float *prgNoise,
        const struct model_t *spritemodel,
        float frame,
        RenderMode_t rendermode,
        const Vector *source,
        const Vector *delta,
        float width,
        float scale,
        float freq,
        float speed,
        int segments,
        float *color,
        float flHDRColorScale)
{
  IMaterial *v17; // eax
  int v18; // edi
  IMaterial_vtbl *v19; // ecx
  int v20; // eax
  __int128 v21; // xmm0
  float v22; // xmm0_4
  int v23; // eax
  int v24; // esi
  IMesh *v25; // esi
  int v26; // edi
  IMesh *z_low; // xmm2_4
  int v28; // edi
  float v29; // xmm5_4
  float v30; // xmm0_4
  float *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  int v35; // eax
  int v36; // eax
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm5_4
  int v41; // eax
  int v42; // eax
  int v43; // eax
  void (__thiscall *v44)(_DWORD, _DWORD, _DWORD); // edx
  int v45; // esi
  _DWORD v47[3]; // [esp+1Ch] [ebp-25Ch] BYREF
  _BYTE meshBuilder_144[356]; // [esp+B8h] [ebp-1C0h] OVERLAPPED BYREF
  float *v49; // [esp+228h] [ebp-50h]
  int v50; // [esp+22Ch] [ebp-4Ch]
  int v51; // [esp+230h] [ebp-48h]
  IMesh *v52; // [esp+234h] [ebp-44h]
  CMatRenderContextPtr pRenderContext; // [esp+238h] [ebp-40h]
  float v54; // [esp+23Ch] [ebp-3Ch]
  IMesh *pMesh; // [esp+240h] [ebp-38h]
  float div; // [esp+244h] [ebp-34h]
  float vStep; // [esp+248h] [ebp-30h]
  float radius; // [esp+24Ch] [ebp-2Ch]
  float *v59; // [esp+250h] [ebp-28h]
  float v60; // [esp+254h] [ebp-24h]
  float v61; // [esp+258h] [ebp-20h]
  int v62; // [esp+25Ch] [ebp-1Ch]
  float v63; // [esp+260h] [ebp-18h]
  float v64; // [esp+264h] [ebp-14h] BYREF
  float v65; // [esp+268h] [ebp-10h] BYREF
  float vLast; // [esp+26Ch] [ebp-Ch]
  float s; // [esp+270h] [ebp-8h]
  float retaddr; // [esp+278h] [ebp+0h]

  vLast = a1;
  s = retaddr;
  v17 = Draw_SetSpriteTexture(a1: rendermode, pSpriteModel: spritemodel, (int)frame, rendermode);
  if ( v17 != nullptr )
  {
    v18 = segments;
    if ( segments >= 2 )
    {
      v19 = v17[rendermode + 4].__vftable;
      if ( v19 != nullptr )
      {
        v20 = (*((int (__thiscall **)(IMaterial_vtbl *, const char *, unsigned int *))v19->GetName + 47))(
                a1: v19,
                a2: "$hdrcolorscale",
                a3: &nHDRColorScaleCache_4);
        if ( v20 != 0 )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v20 + 16))(a1: v20, a2: LODWORD(flHDRColorScale));
      }
      if ( segments > noise_divisions )
      {
        segments = noise_divisions;
        v18 = noise_divisions;
      }
      v21 = 0;
      *(float *)&v21 = fsqrt(
                         (float)((float)(delta->x * delta->x) + (float)(delta->y * delta->y))
                       + (float)(delta->z * delta->z));
      *(_OWORD *)&meshBuilder_144[340] = v21;
      v22 = *(float *)&v21 * 0.01;
      if ( v22 < 0.5 )
        v22 = 0.5;
      *(float *)&pRenderContext.m_pObject = 1.0 / (double)(v18 - 1);
      v54 = *(float *)&pRenderContext.m_pObject * v22;
      v63 = fmod(freq * speed, 1.0);
      v23 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2, a3);
      v24 = v23;
      v50 = v23;
      if ( v23 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v23 + 8))(a1: v23);
      v25 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v24 + 228))(
                       a1: v24,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
      v52 = v25;
      CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)v47);
      *(_DWORD *)&meshBuilder_144[24] = v25;
      meshBuilder_144[32] = 1;
      *(_DWORD *)&meshBuilder_144[28] = 3;
      v26 = 2 * v18;
      v25->SetPrimitiveType(this: v25, a2: MATERIAL_TRIANGLE_STRIP);
      (*(void (__thiscall **)(_DWORD, int, int, _DWORD *, _DWORD))(**(_DWORD **)&meshBuilder_144[24] + 68))(
        a1: *(_DWORD *)&meshBuilder_144[24],
        a2: v26,
        a3: v26,
        a4: v47,
        a5: 0);
      *(_DWORD *)&meshBuilder_144[36] = *(_DWORD *)&meshBuilder_144[8];
      *(_DWORD *)&meshBuilder_144[64] = *(_DWORD *)meshBuilder_144;
      *(_DWORD *)&meshBuilder_144[52] = &v25->IIndexBuffer;
      *(_DWORD *)&meshBuilder_144[48] = *(_DWORD *)&meshBuilder_144[20];
      *(_DWORD *)&meshBuilder_144[60] = 0;
      *(_DWORD *)&meshBuilder_144[56] = v26;
      meshBuilder_144[84] = 0;
      *(_DWORD *)&meshBuilder_144[68] = 0;
      CVertexBuilder::AttachBegin(
        this: (CVertexBuilder *)&meshBuilder_144[88],
        pMesh: v25,
        nMaxVertexCount: v26,
        desc: (const MeshDesc_t *)v47);
      *(_DWORD *)&meshBuilder_144[68] = 0;
      CVertexBuilder::Reset(this: (CVertexBuilder *)&meshBuilder_144[88]);
      z_low = (IMesh *)LODWORD(delta->z);
      v28 = 0;
      pMesh = z_low;
      if ( segments > 0 )
      {
        v29 = v63;
        v49 = &v65;
        v59 = &v64;
        v61 = *(float *)&z_low + width;
        while ( 1 )
        {
          v30 = (float)((float)((float)v28 * *(float *)&pRenderContext.m_pObject) * 2.0) * 3.141592653589793;
          vStep = v30;
          v31 = v59;
          *v49 = cos(v30);
          *v31 = sin(v30);
          v32 = (float)((float)(v64 * freq) * *(float *)&z_low) + source->x;
          v33 = (float)((float)(v65 * freq) * *(float *)&z_low) + source->y;
          v34 = width + source->z;
          *(float *)&meshBuilder_144[344] = v32;
          *(float *)&meshBuilder_144[348] = v33;
          *(float *)&meshBuilder_144[352] = v34;
          *(_DWORD *)&meshBuilder_144[336] = 1258291200;
          v62 = 1258291200;
          v51 = 1258291200;
          **(_DWORD **)&meshBuilder_144[280] = -16777216;
          v35 = *(_DWORD *)&meshBuilder_144[284];
          **(_DWORD **)&meshBuilder_144[284] = 1065353216;
          *(float *)(v35 + 4) = v29;
          v36 = *(_DWORD *)&meshBuilder_144[272];
          **(float **)&meshBuilder_144[272] = v32;
          *(float *)(v36 + 4) = v33;
          *(float *)(v36 + 8) = v34;
          CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder_144[88]);
          v38 = (float)((float)(v65 * freq) * v61) + source->y;
          v39 = source->z - width;
          v40 = (float)(color[2] * 255.0) + 8388608.0;
          *(float *)&meshBuilder_144[344] = (float)((float)(v64 * freq) * v61) + source->x;
          v37 = *(float *)&meshBuilder_144[344];
          *(float *)&meshBuilder_144[348] = v38;
          *(float *)&meshBuilder_144[352] = v39;
          div = v40;
          radius = (float)(color[1] * 255.0) + 8388608.0;
          v60 = (float)(*color * 255.0) + 8388608.0;
          **(_DWORD **)&meshBuilder_144[280] = LOBYTE(v40) | ((LOBYTE(radius) | ((LOBYTE(v60) | 0xFFFFFF00) << 8)) << 8);
          v41 = *(_DWORD *)&meshBuilder_144[284];
          **(_DWORD **)&meshBuilder_144[284] = 0;
          *(float *)(v41 + 4) = v63;
          v42 = *(_DWORD *)&meshBuilder_144[272];
          **(float **)&meshBuilder_144[272] = v37;
          *(float *)(v42 + 4) = v38;
          *(float *)(v42 + 8) = v39;
          CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder_144[88]);
          v29 = v63 + v54;
          ++v28;
          v63 = v63 + v54;
          if ( v28 >= segments )
            break;
          z_low = pMesh;
        }
        v25 = v52;
      }
      if ( meshBuilder_144[32] != 0 )
      {
        switch ( *(_DWORD *)&meshBuilder_144[28] )
        {
          case 4:
            v43 = 2 * *(_DWORD *)&meshBuilder_144[264] - 2;
            break;
          case 5:
            v43 = 2 * *(_DWORD *)&meshBuilder_144[264];
            break;
          case 6:
            v43 = 3 * *(_DWORD *)&meshBuilder_144[264] - 6;
            break;
          case 7:
            v43 = 6 * *(_DWORD *)&meshBuilder_144[264] / 4;
            break;
          case 0xA:
            v43 = 0;
            break;
          default:
            v43 = *(_DWORD *)&meshBuilder_144[264];
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: (CIndexBuilder *)&meshBuilder_144[36],
          primitiveType: *(MaterialPrimitiveType_t *)&meshBuilder_144[28],
          nIndexCount: v43);
      }
      v44 = *(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)&meshBuilder_144[24] + 80);
      v47[0] = v47;
      v44(
        a1: *(_DWORD *)&meshBuilder_144[24],
        a2: *(_DWORD *)&meshBuilder_144[264],
        a3: *(_DWORD *)&meshBuilder_144[60]);
      *(_DWORD *)&meshBuilder_144[52] = 0;
      *(_DWORD *)&meshBuilder_144[56] = 0;
      *(_DWORD *)&meshBuilder_144[260] = 0;
      *(_DWORD *)&meshBuilder_144[252] = 0;
      *(_DWORD *)&meshBuilder_144[24] = 0;
      *(_DWORD *)&meshBuilder_144[164] = -1;
      v25->Draw_2(this: v25, a2: -1, a3: 0);
      if ( *(_DWORD *)&meshBuilder_144[252] != 0
        && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[252] + 8))(a1: *(_DWORD *)&meshBuilder_144[252]) != 0 )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[252] + 16))(a1: *(_DWORD *)&meshBuilder_144[252]);
      }
      if ( *(_DWORD *)&meshBuilder_144[52] != 0
        && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[52] + 8))(a1: *(_DWORD *)&meshBuilder_144[52]) != 0 )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_144[52] + 16))(a1: *(_DWORD *)&meshBuilder_144[52]);
      }
      v45 = v50;
      (*(void (__thiscall **)(int))(*(_DWORD *)v50 + 12))(a1: v50);
      (*(void (__thiscall **)(int))(*(_DWORD *)v45 + 4))(a1: v45);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022610
// Name: void DrawRing(int,float __near *,void (*)(float __near *,int,float),struct model_t const __near *,float,int,class Vector const __near &,class Vector const __near &,float,float,float,float,int,float __near *,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawRing(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        int noise_divisions,
        float *prgNoise,
        void (__cdecl *pfnNoise)(float *, int, int),
        const struct model_t *spritemodel,
        float frame,
        RenderMode_t rendermode,
        const Vector *source,
        const Vector *delta,
        float width,
        float amplitude,
        float freq,
        float speed,
        int segments,
        float *color,
        float flHDRColorScale)
{
  IMaterial *v18; // eax
  IMaterial_vtbl *v19; // ecx
  int v20; // eax
  float v21; // xmm0_4
  float v22; // xmm1_4
  float z; // xmm2_4
  float v24; // xmm0_4
  __int128 v25; // xmm1
  int v26; // edi
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  __int128 v33; // xmm5
  IMaterialSystem_vtbl *v34; // edx
  float v35; // eax
  float v36; // esi
  float v37; // esi
  int v38; // edi
  float v39; // xmm0_4
  float v40; // eax
  float *v41; // edi
  const Vector *v42; // eax
  __m128i v43; // xmm0
  double v44; // xmm0_8
  const Vector *v45; // eax
  const Vector *v46; // eax
  const Vector *v47; // eax
  float v48; // xmm6_4
  float v49; // xmm2_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm5_4
  float v53; // xmm4_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float *m_pCurrPosition; // eax
  int m_nMaxVertexCount; // eax
  float *v58; // eax
  int v59; // eax
  bool v60; // zf
  int m_pVertexBuffer; // eax
  void (__thiscall *v62)(unsigned int, IVertexBuffer *, unsigned int); // edx
  float v63; // esi
  int v65; // [esp+4Ch] [ebp-2F4h] BYREF
  int v66; // [esp+50h] [ebp-2F0h]
  int *v67; // [esp+54h] [ebp-2ECh]
  CMeshBuilder meshBuilder; // [esp+58h] [ebp-2E8h] BYREF
  Vector xaxis; // [esp+240h] [ebp-100h]
  Vector zaxis; // [esp+24Ch] [ebp-F4h]
  float v71; // [esp+258h] [ebp-E8h]
  int v72; // [esp+25Ch] [ebp-E4h]
  CMatRenderContextPtr pRenderContext; // [esp+260h] [ebp-E0h]
  float v74; // [esp+264h] [ebp-DCh]
  Vector screenLast; // [esp+26Ch] [ebp-D4h]
  float v76; // [esp+278h] [ebp-C8h]
  Vector normal; // [esp+27Ch] [ebp-C4h]
  float v78; // [esp+288h] [ebp-B8h]
  Vector center; // [esp+28Ch] [ebp-B4h]
  float v80; // [esp+298h] [ebp-A8h]
  float vStep; // [esp+29Ch] [ebp-A4h]
  int v82; // [esp+2A0h] [ebp-A0h]
  float v83; // [esp+2A4h] [ebp-9Ch]
  unsigned int v84; // [esp+2A8h] [ebp-98h]
  float v85; // [esp+2ACh] [ebp-94h]
  float v86; // [esp+2B0h] [ebp-90h]
  float fraction; // [esp+2B4h] [ebp-8Ch]
  float v88; // [esp+2B8h] [ebp-88h]
  _BYTE last1[24]; // [esp+2BCh] [ebp-84h] OVERLAPPED
  Vector last2; // [esp+2D4h] [ebp-6Ch] BYREF
  float v91; // [esp+2E0h] [ebp-60h]
  Vector screen; // [esp+2E4h] [ebp-5Ch] BYREF
  int noiseIndex; // [esp+2F0h] [ebp-50h] BYREF
  float x; // [esp+2F4h] [ebp-4Ch]
  float vLast; // [esp+2F8h] [ebp-48h]
  float y; // [esp+2FCh] [ebp-44h] BYREF
  float factor; // [esp+300h] [ebp-40h]
  int j; // [esp+304h] [ebp-3Ch]
  Vector tmp; // [esp+308h] [ebp-38h]
  Vector d; // [esp+314h] [ebp-2Ch] BYREF
  Vector yaxis; // [esp+320h] [ebp-20h] BYREF
  int i; // [esp+32Ch] [ebp-14h]
  float length; // [esp+330h] [ebp-10h]
  Vector point; // [esp+334h] [ebp-Ch]
  float retaddr; // [esp+340h] [ebp+0h]

  point.x = a1;
  point.y = retaddr;
  *(float *)&pRenderContext.m_pObject = 0.0;
  v74 = 0.0;
  v18 = Draw_SetSpriteTexture(a1: rendermode, pSpriteModel: spritemodel, (int)frame, rendermode);
  if ( v18 != nullptr )
  {
    v19 = v18[rendermode + 4].__vftable;
    if ( v19 != nullptr )
    {
      v20 = (*((int (__thiscall **)(IMaterial_vtbl *, const char *, unsigned int *))v19->GetName + 47))(
              a1: v19,
              a2: "$hdrcolorscale",
              a3: &nHDRColorScaleCache_5);
      if ( v20 != 0 )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v20 + 16))(a1: v20, a2: LODWORD(flHDRColorScale));
    }
    v21 = delta->x;
    v22 = delta->y;
    z = delta->z;
    tmp.x = delta->x;
    tmp.y = v22;
    tmp.z = z;
    if ( segments >= 2 )
    {
      v24 = (float)(v21 * v21) + (float)(v22 * v22);
      v25 = 0;
      *(float *)&v25 = fsqrt(v24 + (float)(z * z));
      *(_OWORD *)&last1[8] = v25;
      v26 = (int)((double)segments * 3.141592653589793);
      v27 = *(float *)&v25 * 0.01 * 3.141592653589793;
      if ( v26 > 8 * noise_divisions )
        v26 = 8 * noise_divisions;
      yaxis.y = v27;
      if ( v27 < 0.5 )
      {
        v27 = 0.5;
        yaxis.y = 0.5;
      }
      v28 = 1.0 / (double)(v26 - 1);
      *(float *)&last1[4] = v28;
      center.y = (float)(v28 * v27) * 0.125;
      screen.z = fmod(freq * speed, 1.0);
      tmp.x = tmp.x * 0.5;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = LODWORD(tmp.x);
      v72 = 8 * (int)(float)((float)((float)(noise_divisions - 1) * v28) * 65536.0);
      v29 = source->z;
      v30 = source->x + tmp.x;
      v31 = source->y + (float)(tmp.y * 0.5);
      tmp.y = tmp.y * 0.5;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = LODWORD(tmp.y);
      v32 = v29 + (float)(tmp.z * 0.5);
      tmp.z = tmp.z * 0.5;
      *((_DWORD *)&meshBuilder.m_VertexBuilder + 60) = LODWORD(tmp.z);
      v33 = 0;
      *(float *)&v33 = fsqrt((float)((float)(tmp.x * tmp.x) + (float)(tmp.y * tmp.y)) + (float)(tmp.z * tmp.z));
      *(_OWORD *)&last1[8] = v33;
      v86 = *(float *)&v33;
      fraction = *(float *)&v33;
      y = *(float *)&v33 + v30;
      factor = v31 + *(float *)&v33;
      xaxis.x = 0.0;
      xaxis.y = 0.0;
      normal.y = v30;
      *(float *)last1 = (float)(yaxis.y * amplitude) * 0.125;
      screen.x = 0.0;
      normal.z = v31;
      v78 = v32;
      xaxis.z = 1.0;
      v88 = *(float *)last1;
      *(float *)&j = v32 + *(float *)last1;
      last2.y = v30 - *(float *)&v33;
      last2.z = v31 - *(float *)&v33;
      v91 = v32 - *(float *)last1;
      if ( engine->IsBoxVisible(this: engine, a2: (Vector *)&last2.y, a3: (const Vector *)&y) != 0
        && !engine->CullBox(this: engine, a2: (Vector *)&last2.y, a3: (const Vector *)&y) )
      {
        d.x = tmp.y;
        LODWORD(d.y) = LODWORD(tmp.x) ^ _mask__NegFloat_;
        d.z = 0.0;
        VectorNormalize(vec: &d);
        d.x = d.x * *(float *)&last1[8];
        d.y = d.y * *(float *)&last1[8];
        d.z = d.z * *(float *)&last1[8];
        v34 = materials->__vftable;
        LODWORD(center.x) = v26 / 8;
        LODWORD(vLast) = v26 / 8;
        v35 = COERCE_FLOAT(
                ((int (__thiscall *)(IMaterialSystem *, int, int, int, int, int *, int, int, int, int, int, int, int, int, int))v34->GetRenderContext)(
                  a1: materials,
                  a2,
                  a3,
                  a4: v65,
                  a5: v66,
                  a6: v67,
                  a7: meshBuilder.m_VertexSize_Position,
                  a8: meshBuilder.m_VertexSize_BoneWeight,
                  a9: meshBuilder.m_VertexSize_BoneMatrixIndex,
                  a10: meshBuilder.m_VertexSize_Normal,
                  a11: meshBuilder.m_VertexSize_Color,
                  a12: meshBuilder.m_VertexSize_Specular,
                  a13: meshBuilder.m_VertexSize_TexCoord[0],
                  a14: meshBuilder.m_VertexSize_TexCoord[1],
                  a15: meshBuilder.m_VertexSize_TexCoord[2]));
        v36 = v35;
        zaxis.z = v35;
        if ( v35 != 0.0 )
          (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v35) + 8))(a1: COERCE_FLOAT(LODWORD(v35)));
        v37 = COERCE_FLOAT(
                (*(int (__thiscall **)(float, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v36) + 228))(
                  a1: COERCE_FLOAT(LODWORD(v36)),
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0));
        yaxis.y = v37;
        CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&v65);
        *(float *)&meshBuilder.MeshDesc_t::IndexDesc_t::m_nOffset = v37;
        LOBYTE(meshBuilder.m_nIndexSize) = 1;
        meshBuilder.m_nFirstIndex = 3;
        (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)LODWORD(yaxis.y) + 40))(a1: LODWORD(yaxis.y), a2: 3);
        (*(void (__thiscall **)(unsigned int, int, int, int *, _DWORD))(*(_DWORD *)meshBuilder.MeshDesc_t::IndexDesc_t::m_nOffset
                                                                      + 68))(
          a1: meshBuilder.MeshDesc_t::IndexDesc_t::m_nOffset,
          a2: 2 * v26 + 2,
          a3: 2 * v26 + 2,
          a4: &v65,
          a5: 0);
        meshBuilder.m_IndexBuilder.m_nOffset = LODWORD(yaxis.y) + 4;
        meshBuilder.m_IndexBuilder.m_nIndexSize = 0;
        LOBYTE(meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = 0;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = (IIndexBuffer *)meshBuilder.m_pTangentT;
        meshBuilder.m_pMesh = (IMesh *)meshBuilder.m_pUserData;
        v66 = 2 * v26 + 2;
        meshBuilder.m_IndexBuilder.m_nFirstIndex = v66;
        meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
        CVertexBuilder::AttachBegin(
          this: (CVertexBuilder *)&meshBuilder.m_IndexBuilder.m_nBufferOffset,
          pMesh: (IMesh *)LODWORD(yaxis.y),
          nMaxVertexCount: v66,
          desc: (const MeshDesc_t *)&v65);
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        CVertexBuilder::Reset(this: (CVertexBuilder *)&meshBuilder.m_IndexBuilder.m_nBufferOffset);
        v38 = v26 + 1;
        yaxis.x = 0.0;
        v82 = v38;
        if ( v38 > 0 )
        {
          LODWORD(normal.x) = &noiseIndex;
          LODWORD(screenLast.x) = &screen.y;
          do
          {
            *(float *)&v84 = (float)SLODWORD(yaxis.x) * *(float *)&last1[4];
            v39 = (float)(*(float *)&v84 * 2.0) * 3.141592653589793;
            zaxis.x = v39;
            v40 = screenLast.x;
            *(float *)LODWORD(normal.x) = cos(v39);
            *(float *)LODWORD(v40) = sin(v39);
            yaxis.z = (float)((float)(d.x * *(float *)&noiseIndex) + (float)(tmp.x * screen.y)) + normal.y;
            *(float *)&i = (float)((float)(d.y * *(float *)&noiseIndex) + (float)(tmp.y * screen.y)) + normal.z;
            length = (float)((float)(d.z * *(float *)&noiseIndex) + (float)(tmp.z * screen.y)) + v78;
            if ( *(float *)last1 != 0.0 )
            {
              v41 = &prgNoise[(SLODWORD(screen.x) >> 16) & 0x7F];
              x = *(float *)last1 * *v41;
              v42 = CurrentViewUp();
              yaxis.z = (float)(v42->x * x) + yaxis.z;
              *(float *)&i = (float)(v42->y * x) + *(float *)&i;
              v43 = (__m128i)_mm_cvtps_pd((__m128)v84);
              length = (float)(v42->z * x) + length;
              *(double *)v43.m128i_i64 = *(double *)v43.m128i_i64 * 3.141592653589793 * 3.0 * 8.0 + freq;
              __libm_sse2_cos(X: v43);
              *(float *)&v44 = v44 * (float)(*(float *)last1 * *v41);
              x = *(float *)&v44;
              v45 = CurrentViewRight();
              v38 = v82;
              yaxis.z = (float)(v45->x * x) + yaxis.z;
              *(float *)&i = (float)(v45->y * x) + *(float *)&i;
              length = (float)(v45->z * x) + length;
            }
            ScreenTransform(point: (Vector *)&yaxis.z, screen: (Vector *)&last2.y);
            if ( LODWORD(yaxis.x) != 0 )
            {
              y = last2.y - *(float *)&pRenderContext.m_pObject;
              factor = last2.z - v74;
              *(float *)&j = 0.0;
              VectorNormalize(vec: (Vector *)&y);
              v80 = y;
              v46 = CurrentViewUp();
              screenLast.y = v46->x * v80;
              screenLast.z = v46->y * v80;
              v76 = v46->z * v80;
              v47 = CurrentViewRight();
              v48 = color[2];
              v49 = (float)(COERCE_FLOAT(LODWORD(factor) ^ _mask__NegFloat_) * v47->x) + screenLast.y;
              v50 = (float)(v47->y * COERCE_FLOAT(LODWORD(factor) ^ _mask__NegFloat_)) + screenLast.z;
              v51 = (float)(v47->z * COERCE_FLOAT(LODWORD(factor) ^ _mask__NegFloat_)) + v76;
              v86 = (float)(v49 * width) + yaxis.z;
              fraction = (float)(v50 * width) + *(float *)&i;
              v88 = (float)(v51 * width) + length;
              v53 = (float)(COERCE_FLOAT(LODWORD(width) ^ _mask__NegFloat_) * v49) + yaxis.z;
              v54 = (float)(v50 * COERCE_FLOAT(LODWORD(width) ^ _mask__NegFloat_)) + *(float *)&i;
              v55 = (float)(v51 * COERCE_FLOAT(LODWORD(width) ^ _mask__NegFloat_)) + length;
              *(float *)&last1[12] = v53;
              *(float *)&last1[16] = v54;
              *(float *)&last1[20] = v55;
              v85 = (float)(v48 * 255.0) + 8388608.0;
              v83 = (float)(color[1] * 255.0) + 8388608.0;
              zaxis.y = (float)(*color * 255.0) + 8388608.0;
              screen.z = screen.z + center.y;
              v52 = screen.z;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_nCurrentVertex = LOBYTE(v85)
                                                                      | ((LOBYTE(v83)
                                                                        | ((LOBYTE(zaxis.y) | 0xFFFFFF00) << 8)) << 8);
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = 1.0;
              m_pCurrPosition[1] = v52;
              m_nMaxVertexCount = meshBuilder.m_VertexBuilder.m_nMaxVertexCount;
              *(float *)meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v53;
              *(float *)(m_nMaxVertexCount + 4) = v54;
              *(float *)(m_nMaxVertexCount + 8) = v55;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_IndexBuilder.m_nBufferOffset);
              center.z = (float)(color[2] * 255.0) + 8388608.0;
              v71 = (float)(color[1] * 255.0) + 8388608.0;
              vStep = (float)(*color * 255.0) + 8388608.0;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_nCurrentVertex = LOBYTE(center.z)
                                                                      | ((LOBYTE(v71)
                                                                        | ((LOBYTE(vStep) | 0xFFFFFF00) << 8)) << 8);
              v58 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
              v58[1] = screen.z;
              v59 = meshBuilder.m_VertexBuilder.m_nMaxVertexCount;
              *(float *)meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v86;
              *(float *)(v59 + 4) = fraction;
              *(float *)(v59 + 8) = v88;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_IndexBuilder.m_nBufferOffset);
            }
            LODWORD(screen.x) += v72;
            v60 = LODWORD(vLast)-- == 1;
            pRenderContext.m_pObject = (IMatRenderContext *)LODWORD(last2.y);
            v74 = last2.z;
            if ( v60 && amplitude != 0.0 )
            {
              vLast = center.x;
              pfnNoise(a1: prgNoise, a2: noise_divisions, a3: 1065353216);
            }
            ++LODWORD(yaxis.x);
          }
          while ( SLODWORD(yaxis.x) < v38 );
        }
        if ( LOBYTE(meshBuilder.m_nIndexSize) != 0 )
        {
          switch ( meshBuilder.m_nFirstIndex )
          {
            case 4u:
              m_pVertexBuffer = 2 * (int)meshBuilder.m_VertexBuilder.m_pVertexBuffer - 2;
              break;
            case 5u:
              m_pVertexBuffer = 2 * (int)meshBuilder.m_VertexBuilder.m_pVertexBuffer;
              break;
            case 6u:
              m_pVertexBuffer = 3 * (int)meshBuilder.m_VertexBuilder.m_pVertexBuffer - 6;
              break;
            case 7u:
              m_pVertexBuffer = 6 * (int)meshBuilder.m_VertexBuilder.m_pVertexBuffer / 4;
              break;
            case 0xAu:
              m_pVertexBuffer = 0;
              break;
            default:
              m_pVertexBuffer = (int)meshBuilder.m_VertexBuilder.m_pVertexBuffer;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: (CIndexBuilder *)&meshBuilder.m_pMesh,
            primitiveType: (MaterialPrimitiveType_t)meshBuilder.m_nFirstIndex,
            nIndexCount: m_pVertexBuffer);
        }
        v62 = *(void (__thiscall **)(unsigned int, IVertexBuffer *, unsigned int))(*(_DWORD *)meshBuilder.MeshDesc_t::IndexDesc_t::m_nOffset
                                                                                 + 80);
        v67 = &v65;
        v62(
          a1: meshBuilder.MeshDesc_t::IndexDesc_t::m_nOffset,
          a2: meshBuilder.m_VertexBuilder.m_pVertexBuffer,
          a3: meshBuilder.m_IndexBuilder.m_nIndexSize);
        meshBuilder.m_IndexBuilder.m_nOffset = 0;
        meshBuilder.m_IndexBuilder.m_nFirstIndex = 0;
        meshBuilder.m_VertexBuilder.m_nOffset = 0;
        meshBuilder.m_VertexBuilder.m_pUserData = nullptr;
        meshBuilder.MeshDesc_t::IndexDesc_t::m_nOffset = 0;
        meshBuilder.m_VertexBuilder.m_VertexSize_Wrinkle = -1;
        (*(void (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)LODWORD(yaxis.y) + 48))(
          a1: LODWORD(yaxis.y),
          a2: -1,
          a3: 0);
        CMeshBuilder::~CMeshBuilder(this: (CMeshBuilder *)&v65);
        v63 = zaxis.z;
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(zaxis.z) + 12))(a1: LODWORD(zaxis.z));
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v63) + 4))(a1: COERCE_FLOAT(LODWORD(v63)));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100230E0
// Name: void DrawBeamFollow(struct model_t const __near *,struct BeamTrail_t __near *,int,int,class Vector __near &,class Vector __near &,class Vector __near &,float,class Vector const __near &,int,float,float,float,float __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawBeamFollow(
        int a1@<ebx>,
        int a2@<edi>,
        const struct model_t *spritemodel,
        BeamTrail_t *pHead,
        int frame,
        RenderMode_t rendermode,
        Vector *delta,
        Vector *screen,
        Vector *screenLast,
        float die,
        const Vector *source,
        int flags,
        float width,
        float amplitude,
        float freq,
        float *color,
        float flHDRColorScale)
{
  IMaterial *v17; // eax
  IMaterial_vtbl *v18; // ecx
  int v19; // eax
  const Vector *v20; // eax
  const Vector *v21; // eax
  float x; // xmm5_4
  float z; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  int v34; // eax
  int v35; // eax
  int v36; // eax
  BeamTrail_t *v37; // eax
  int v38; // ecx
  IMatRenderContext *v39; // esi
  IMesh *v40; // esi
  IMesh_vtbl *v41; // edx
  unsigned __int8 v42; // si
  int v43; // edx
  unsigned int v44; // esi
  float *v45; // eax
  float *v46; // eax
  const Vector *v47; // eax
  const Vector *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  bool v52; // zf
  float v53; // xmm5_4
  float v54; // xmm4_4
  float v55; // xmm0_4
  float v56; // xmm7_4
  float v57; // xmm4_4
  float v58; // xmm5_4
  float v59; // xmm0_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  int v62; // eax
  int v63; // eax
  int v64; // eax
  float *m_pCurrPosition; // eax
  unsigned __int8 v66; // si
  int v67; // edx
  unsigned int v68; // esi
  float *v69; // eax
  float *v70; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+10h] [ebp-234h] BYREF
  float v74; // [esp+1F8h] [ebp-4Ch]
  float div; // [esp+1FCh] [ebp-48h]
  CMatRenderContextPtr pRenderContext; // [esp+200h] [ebp-44h]
  IMesh *pMesh; // [esp+204h] [ebp-40h]
  Vector last2; // [esp+208h] [ebp-3Ch]
  Vector normal; // [esp+214h] [ebp-30h]
  Vector last1; // [esp+220h] [ebp-24h]
  Vector tmp; // [esp+22Ch] [ebp-18h] BYREF
  int count; // [esp+238h] [ebp-Ch]
  int nMaxVertexCount; // [esp+23Ch] [ebp-8h]
  unsigned __int8 nColor[4]; // [esp+240h] [ebp-4h] BYREF

  v17 = Draw_SetSpriteTexture(a1: rendermode, pSpriteModel: spritemodel, frame, rendermode);
  if ( v17 != nullptr )
  {
    v18 = v17[rendermode + 4].__vftable;
    if ( v18 != nullptr )
    {
      v19 = (*((int (__thiscall **)(IMaterial_vtbl *, const char *, unsigned int *))v18->GetName + 47))(
              a1: v18,
              a2: "$hdrcolorscale",
              a3: &nHDRColorScaleCache_6);
      if ( v19 != 0 )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v19 + 16))(a1: v19, a2: LODWORD(flHDRColorScale));
    }
    tmp.x = screen->x - screenLast->x;
    tmp.y = screen->y - screenLast->y;
    tmp.z = 0.0;
    VectorNormalize(vec: &tmp);
    nMaxVertexCount = SLODWORD(tmp.x);
    v20 = CurrentViewUp();
    normal.x = v20->x * *(float *)&nMaxVertexCount;
    normal.y = v20->y * *(float *)&nMaxVertexCount;
    normal.z = v20->z * *(float *)&nMaxVertexCount;
    v21 = CurrentViewRight();
    x = delta->x;
    z = delta->z;
    v24 = (float)(v21->x * COERCE_FLOAT(LODWORD(tmp.y) ^ _mask__NegFloat_)) + normal.x;
    v25 = (float)(v21->y * COERCE_FLOAT(LODWORD(tmp.y) ^ _mask__NegFloat_)) + normal.y;
    v26 = (float)(v21->z * COERCE_FLOAT(LODWORD(tmp.y) ^ _mask__NegFloat_)) + normal.z;
    last1.x = (float)(v24 * width) + delta->x;
    last1.y = (float)(v25 * width) + delta->y;
    LODWORD(v74) = LODWORD(width) ^ _mask__NegFloat_;
    last1.z = (float)(v26 * width) + z;
    v27 = COERCE_FLOAT(LODWORD(width) ^ _mask__NegFloat_) * v24;
    v28 = (float)(COERCE_FLOAT(LODWORD(width) ^ _mask__NegFloat_) * v25) + delta->y;
    last2.z = (float)(COERCE_FLOAT(LODWORD(width) ^ _mask__NegFloat_) * v26) + z;
    last2.y = v28;
    v29 = die - *(float *)(gpGlobals.m_Index + 12);
    v30 = 1.0 / amplitude;
    last2.x = v27 + x;
    div = v30;
    v31 = v29 * v30;
    v32 = color[1] * v31;
    v33 = color[2] * v31;
    v34 = (int)(float)((float)(*color * v31) * 255.0);
    if ( v34 >= 0 )
    {
      if ( v34 > 255 )
        LOBYTE(v34) = -1;
    }
    else
    {
      LOBYTE(v34) = 0;
    }
    nColor[0] = v34;
    v35 = (int)(float)(v32 * 255.0);
    if ( v35 >= 0 )
    {
      if ( v35 > 255 )
        LOBYTE(v35) = -1;
    }
    else
    {
      LOBYTE(v35) = 0;
    }
    nColor[1] = v35;
    v36 = (int)(float)(v33 * 255.0);
    if ( v36 >= 0 )
    {
      if ( v36 > 255 )
        LOBYTE(v36) = -1;
    }
    else
    {
      LOBYTE(v36) = 0;
    }
    nColor[2] = v36;
    v37 = pHead;
    v38 = 0;
    count = 0;
    if ( pHead != nullptr )
    {
      do
      {
        v37 = v37->next;
        ++v38;
      }
      while ( v37 != nullptr );
      count = v38;
    }
    v39 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                                 a1: materials,
                                 a2,
                                 a3: a1);
    pRenderContext.m_pObject = v39;
    if ( v39 != nullptr )
      v39->BeginRender(this: v39);
    v40 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD))v39->GetDynamicMesh)(a1: v39, a2: 1, a3: 0);
    pMesh = v40;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v40;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v41 = v40->IVertexBuffer::__vftable;
    nMaxVertexCount = 4 * count;
    count *= 6;
    v41->SetPrimitiveType(this: v40, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(
      this: meshBuilder.m_pMesh,
      a2: nMaxVertexCount,
      a3: count,
      a4: &meshBuilder,
      a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v40->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = count;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v40, nMaxVertexCount, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    if ( pHead != nullptr )
    {
      do
      {
        v42 = nColor[0];
        v43 = nColor[1];
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = last1;
        v44 = nColor[2] | ((v43 | ((*(_DWORD *)&v42 | 0xFFFFFF00) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v44;
        v45 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v45[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = last2;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v44;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        v46[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ScreenTransform(point: &pHead->org, screen);
        tmp.x = screen->x - screenLast->x;
        tmp.y = screen->y - screenLast->y;
        tmp.z = 0.0;
        VectorNormalize(vec: &tmp);
        nMaxVertexCount = SLODWORD(tmp.x);
        v47 = CurrentViewUp();
        normal.x = *(float *)&nMaxVertexCount * v47->x;
        normal.y = v47->y * *(float *)&nMaxVertexCount;
        normal.z = v47->z * *(float *)&nMaxVertexCount;
        v48 = CurrentViewRight();
        v49 = (float)(v48->x * COERCE_FLOAT(LODWORD(tmp.y) ^ _mask__NegFloat_)) + normal.x;
        v50 = (float)(v48->y * COERCE_FLOAT(LODWORD(tmp.y) ^ _mask__NegFloat_)) + normal.y;
        v51 = (float)(v48->z * COERCE_FLOAT(LODWORD(tmp.y) ^ _mask__NegFloat_)) + normal.z;
        v52 = pHead->next == nullptr;
        last1.y = (float)(v50 * width) + pHead->org.y;
        v53 = pHead->org.z;
        v54 = (float)(v49 * width) + pHead->org.x;
        last1.z = (float)(v51 * width) + v53;
        v55 = (float)(v74 * v50) + pHead->org.y;
        last1.x = v54;
        v56 = (float)(v74 * v49) + pHead->org.x;
        v57 = v55;
        v58 = v53 + (float)(v74 * v51);
        last2.x = v56;
        last2.y = v55;
        last2.z = v58;
        if ( v52 )
        {
          memset(nColor, 0, 3);
        }
        else
        {
          v59 = (float)(pHead->die - *(float *)(gpGlobals.m_Index + 12)) * div;
          v60 = color[1] * v59;
          v61 = color[2] * v59;
          v62 = (int)(float)((float)(*color * v59) * 255.0);
          if ( v62 >= 0 )
          {
            if ( v62 > 255 )
              LOBYTE(v62) = -1;
          }
          else
          {
            LOBYTE(v62) = 0;
          }
          nColor[0] = v62;
          v63 = (int)(float)(v60 * 255.0);
          if ( v63 >= 0 )
          {
            if ( v63 > 255 )
              LOBYTE(v63) = -1;
          }
          else
          {
            LOBYTE(v63) = 0;
          }
          nColor[1] = v63;
          v64 = (int)(float)(v61 * 255.0);
          if ( v64 >= 0 )
          {
            if ( v64 > 255 )
              LOBYTE(v64) = -1;
            nColor[2] = v64;
          }
          else
          {
            nColor[2] = 0;
          }
        }
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v66 = nColor[0];
        v67 = nColor[1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v56;
        m_pCurrPosition[1] = v57;
        m_pCurrPosition[2] = v58;
        v68 = nColor[2] | ((v67 | ((*(_DWORD *)&v66 | 0xFFFFFF00) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v68;
        v69 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        v69[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = last1;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v68;
        v70 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v70[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        *screenLast = *screen;
        pHead = pHead->next;
      }
      while ( pHead != nullptr );
      v40 = pMesh;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v40->Draw_2(this: v40, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100238A0
// Name: void DrawBeamQuadratic(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawBeamQuadratic(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *start,
        const Vector *control,
        const Vector *end,
        float width,
        const Vector *color,
        float scrollOffset)
{
  IMatRenderContext *v9; // esi
  float v10; // xmm4_4
  int i; // esi
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float z; // xmm3_4
  float v18; // xmm1_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  IMatRenderContext *v23; // esi
  _DWORD v24[3]; // [esp-Ch] [ebp-2ACh] BYREF
  CBeamSegDraw beamDraw; // [esp+0h] [ebp-2A0h] BYREF
  BeamSeg_t seg; // [esp+250h] [ebp-50h]
  float v27; // [esp+270h] [ebp-30h]
  float v28; // [esp+274h] [ebp-2Ch]
  float u; // [esp+278h] [ebp-28h]
  float v30; // [esp+27Ch] [ebp-24h]
  float v31; // [esp+280h] [ebp-20h]
  IMatRenderContext *v32; // [esp+284h] [ebp-1Ch]
  int v33; // [esp+288h] [ebp-18h]
  float v34; // [esp+28Ch] [ebp-14h]
  CMatRenderContextPtr pRenderContext; // [esp+290h] [ebp-10h]
  int v36; // [esp+294h] [ebp-Ch]
  void *v37; // [esp+298h] [ebp-8h]
  void *retaddr; // [esp+2A0h] [ebp+0h]

  v36 = a1;
  v37 = retaddr;
  v9 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
                              a1: g_pMaterialSystem,
                              a2,
                              a3);
  v32 = v9;
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  v24[0] = &CBeamSegDraw::`vftable';
  CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&(&beamDraw.__vftable)[3]);
  beamDraw.m_vNormalLast.x = 0.0;
  CBeamSegDraw::Start(
    this: (CBeamSegDraw *)v24,
    pRenderContext: v9,
    nSegs: 17,
    pMaterial: nullptr,
    pMeshBuilder: nullptr,
    nMeshVertCount: 0);
  seg.m_vPos.w = width;
  *(float *)&pRenderContext.m_pObject = 0.0;
  *(&seg.m_flWidth + 1) = fmod(scrollOffset, 1.0);
  v10 = 0.0;
  for ( i = 0; i <= 16; ++i )
  {
    v12 = (float)(1.0 - v10) * (float)(1.0 - v10);
    v13 = (float)(v10 * 2.0) * (float)(1.0 - v10);
    v14 = end->x * (float)(v10 * v10);
    v15 = end->z * (float)(v10 * v10);
    v16 = end->y * (float)(v10 * v10);
    v28 = control->x * v13;
    u = control->y * v13;
    z = start->z;
    v18 = control->z * v13;
    x = start->x;
    v30 = v18;
    y = start->y;
    *((float *)&beamDraw.m_vecCameraPos + 3) = (float)((float)(x * v12) + v28) + v14;
    *((float *)&beamDraw.m_vecCameraPos + 4) = (float)((float)(y * v12) + u) + v16;
    *((float *)&beamDraw.m_vecCameraPos + 5) = (float)((float)(z * v12) + v30) + v15;
    seg.m_vPos.z = *(&seg.m_flWidth + 1) - v10;
    if ( i == 0 || i == 16 )
    {
      seg.m_vPos.y = -1.7014118e38;
    }
    else
    {
      v21 = color->y;
      v22 = color->z;
      v27 = (float)(color->x * 255.0) + 8388608.0;
      LOBYTE(seg.m_vPos.y) = LOBYTE(v27);
      v31 = (float)(v21 * 255.0) + 8388608.0;
      BYTE1(seg.m_vPos.y) = LOBYTE(v31);
      v34 = (float)(v22 * 255.0) + 8388608.0;
      BYTE2(seg.m_vPos.y) = LOBYTE(v34);
      v33 = 1258291455;
      HIBYTE(seg.m_vPos.y) = -1;
    }
    CBeamSegDraw::NextSeg(this: (CBeamSegDraw *)v24, pSeg: (BeamSeg_t *)(&beamDraw.m_vecCameraPos + 1));
    v10 = *(float *)&pRenderContext.m_pObject + 0.0625;
    *(float *)&pRenderContext.m_pObject = *(float *)&pRenderContext.m_pObject + 0.0625;
  }
  CBeamSegDraw::End(this: (CBeamSegDraw *)v24);
  if ( beamDraw.m_Mesh.m_VertexBuilder.m_pUserData != nullptr
    && (*(unsigned __int8 (__thiscall **)(float *))(*(_DWORD *)beamDraw.m_Mesh.m_VertexBuilder.m_pUserData + 8))(a1: beamDraw.m_Mesh.m_VertexBuilder.m_pUserData) != 0 )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)beamDraw.m_Mesh.m_VertexBuilder.m_pUserData + 16))(a1: beamDraw.m_Mesh.m_VertexBuilder.m_pUserData);
  }
  if ( beamDraw.m_Mesh.m_IndexBuilder.m_nOffset != 0
    && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)beamDraw.m_Mesh.m_IndexBuilder.m_nOffset + 8))(a1: beamDraw.m_Mesh.m_IndexBuilder.m_nOffset) != 0 )
  {
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)beamDraw.m_Mesh.m_IndexBuilder.m_nOffset + 16))(a1: beamDraw.m_Mesh.m_IndexBuilder.m_nOffset);
  }
  v23 = v32;
  if ( v32 != nullptr )
  {
    v32->EndRender(this: v32);
    v23->Release(this: v23);
  }
}
