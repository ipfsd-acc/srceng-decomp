// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_staticline.cpp
// Functions: 5
// ============================================================

#include "game\client\fx_staticline.h"

//------------------------------------------------------------------------------
// Address: 0x100DE430
// Name: public: virtual bool CFXStaticLine::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFXStaticLine::IsActive(CFXStaticLine *this)
{
  return this->m_fLife > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100DE450
// Name: public: virtual void CFXStaticLine::Update(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFXStaticLine::Update(CFXStaticLine *this, long double frametime)
{
  this->m_fLife = this->m_fLife - frametime;
}

//------------------------------------------------------------------------------
// Address: 0x100DE470
// Name: public: CFXStaticLine::CFXStaticLine(char const __near *,class Vector const __near &,class Vector const __near &,float,float,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CFXStaticLine *__thiscall CFXStaticLine::CFXStaticLine(
        CFXStaticLine *this,
        const char *name,
        const Vector *start,
        const Vector *end,
        float scale,
        float life,
        const char *shader,
        unsigned int flags)
{
  IMaterial *v9; // eax

  CClientSideEffect::CClientSideEffect(this, name);
  this->__vftable = (CFXStaticLine_vtbl *)&CFXStaticLine::`vftable';
  if ( materials != nullptr )
  {
    v9 = materials->FindMaterial(this: materials, a2: shader, a3: "ClientEffect textures", a4: 1, a5: 0);
    this->m_pMaterial = v9;
    v9->IncrementReferenceCount(this: v9);
    this->m_vecStart = *start;
    this->m_vecEnd = *end;
    this->m_fLife = life;
    this->m_uiFlags = flags;
    this->m_fScale = scale * 0.5;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DE550
// Name: public: virtual void CFXStaticLine::Draw(double)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CFXStaticLine::Draw(
        CFXStaticLine *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        long double frametime)
{
  const Vector *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // edi
  IMesh *v12; // edi
  float v13; // xmm0_4
  float *m_pCurrPosition; // eax
  unsigned int m_uiFlags; // ecx
  char v16; // bl
  float v17; // xmm2_4
  float v18; // xmm3_4
  bool v19; // cl
  float *v20; // eax
  char v21; // bl
  float m_fScale; // xmm3_4
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // eax
  int v27; // xmm0_4
  float v28; // xmm3_4
  float *v29; // eax
  float v30; // xmm1_4
  float v31; // xmm2_4
  float *v32; // eax
  int v33; // xmm0_4
  float *v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float *v38; // eax
  int v39; // xmm0_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+14h] [ebp-204h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1FCh] [ebp-1Ch]
  Vector lineDir; // [esp+200h] [ebp-18h]
  Vector cross; // [esp+20Ch] [ebp-Ch] BYREF
  bool flipVertical_7; // [esp+227h] [ebp+Fh]

  ((void (__thiscall *)(CFXStaticLine *, _DWORD, _DWORD, int, int, int))this->Update)(
    a1: this,
    a2: LODWORD(frametime),
    a3: HIDWORD(frametime),
    a4: a3,
    a5: a4,
    a6: a2);
  lineDir.x = this->m_vecEnd.x - this->m_vecStart.x;
  lineDir.y = this->m_vecEnd.y - this->m_vecStart.y;
  lineDir.z = this->m_vecEnd.z - this->m_vecStart.z;
  v6 = CurrentViewOrigin();
  v7 = this->m_vecEnd.y - v6->y;
  v8 = this->m_vecEnd.z - v6->z;
  v9 = this->m_vecEnd.x - v6->x;
  cross.x = (float)(v8 * lineDir.y) - (float)(v7 * lineDir.z);
  cross.y = (float)(lineDir.z * v9) - (float)(v8 * lineDir.x);
  cross.z = (float)(v7 * lineDir.x) - (float)(lineDir.y * v9);
  VectorNormalize(vec: &cross);
  v10 = materials->GetRenderContext(this: materials);
  v11 = v10;
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v12 = v11->GetDynamicMesh(this: v11, a2: true, a3: nullptr, a4: nullptr, a5: this->m_pMaterial);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v12;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v12->SetPrimitiveType(this: v12, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v12->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v12, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  LODWORD(v13) = LODWORD(this->m_fScale) ^ _mask__NegFloat_;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  m_uiFlags = this->m_uiFlags;
  v16 = this->m_uiFlags;
  v17 = (float)(cross.y * v13) + this->m_vecStart.y;
  v18 = (float)(cross.z * v13) + this->m_vecStart.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v13 * cross.x) + this->m_vecStart.x;
  m_pCurrPosition[1] = v17;
  m_pCurrPosition[2] = v18;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
  v19 = (m_uiFlags & 2) != 0;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  flipVertical_7 = v19;
  v21 = v16 & 1;
  if ( v21 != 0 )
  {
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  }
  else
  {
    if ( v19 )
    {
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v20[1] = 0.0;
      goto LABEL_9;
    }
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  }
  v20[1] = 1.0;
LABEL_9:
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  m_fScale = this->m_fScale;
  v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v24 = (float)(cross.y * m_fScale) + this->m_vecStart.y;
  v25 = (float)(cross.z * m_fScale) + this->m_vecStart.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(m_fScale * cross.x) + this->m_vecStart.x;
  v23[1] = v24;
  v23[2] = v25;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  if ( v21 != 0 )
  {
    v27 = 1065353216;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  }
  else if ( flipVertical_7 )
  {
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v27 = 0;
  }
  else
  {
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v27 = 1065353216;
  }
  *((_DWORD *)v26 + 1) = v27;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v28 = this->m_fScale;
  v29 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v30 = (float)(cross.y * v28) + this->m_vecEnd.y;
  v31 = (float)(cross.z * v28) + this->m_vecEnd.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v28 * cross.x) + this->m_vecEnd.x;
  v29[1] = v30;
  v29[2] = v31;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  if ( v21 != 0 )
  {
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v33 = 0;
  }
  else
  {
    if ( flipVertical_7 )
      v33 = 1065353216;
    else
      v33 = 0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v33;
  }
  *((_DWORD *)v32 + 1) = v33;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v34 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  LODWORD(v35) = LODWORD(this->m_fScale) ^ _mask__NegFloat_;
  v36 = (float)(cross.y * v35) + this->m_vecEnd.y;
  v37 = (float)(cross.z * v35) + this->m_vecEnd.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v35 * cross.x) + this->m_vecEnd.x;
  v34[1] = v36;
  v34[2] = v37;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
  v38 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  if ( v21 != 0 )
  {
    v39 = 0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  }
  else if ( flipVertical_7 )
  {
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v39 = 1065353216;
  }
  else
  {
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v39 = 0;
  }
  *((_DWORD *)v38 + 1) = v39;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
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
  v12->Draw_2(this: v12, a2: -1, a3: 0);
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
// Address: 0x1026A360
// Name: public: virtual void CFXStaticLine::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFXStaticLine::Destroy(CFXStaticLine *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}
