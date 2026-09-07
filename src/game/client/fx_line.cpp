// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_line.cpp
// Functions: 6
// ============================================================

#include "game\client\fx_line.h"

//------------------------------------------------------------------------------
// Address: 0x1026B0F0
// Name: public: virtual bool CFXLine::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFXLine::IsActive(CFXLine *this)
{
  return this->m_FXData.m_flDieTime > this->m_FXData.m_flLifeTime;
}

//------------------------------------------------------------------------------
// Address: 0x1026B110
// Name: public: virtual void CFXLine::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFXLine::Destroy(CFXLine *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_FXData.m_pMaterial;
  if ( m_pMaterial != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_FXData.m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026B130
// Name: public: struct FXLineData_t __near & FXLineData_t::operator=(struct FXLineData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
FXLineData_t *__thiscall FXLineData_t::operator=(FXLineData_t *this, const FXLineData_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1026B1B0
// Name: public: virtual void CFXLine::Update(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFXLine::Update(CFXLine *this, long double frametime)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  v2 = this->m_FXData.m_flLifeTime + frametime;
  this->m_FXData.m_flLifeTime = v2;
  v3 = frametime;
  this->m_FXData.m_vecStart.x = (float)(this->m_FXData.m_vecStartVelocity.x * v3) + this->m_FXData.m_vecStart.x;
  this->m_FXData.m_vecStart.y = (float)(this->m_FXData.m_vecStartVelocity.y * v3) + this->m_FXData.m_vecStart.y;
  this->m_FXData.m_vecStart.z = (float)(this->m_FXData.m_vecStartVelocity.z * v3) + this->m_FXData.m_vecStart.z;
  this->m_FXData.m_vecEnd.x = (float)(v3 * this->m_FXData.m_vecEndVelocity.x) + this->m_FXData.m_vecEnd.x;
  this->m_FXData.m_vecEnd.y = (float)(this->m_FXData.m_vecEndVelocity.y * v3) + this->m_FXData.m_vecEnd.y;
  this->m_FXData.m_vecEnd.z = (float)(this->m_FXData.m_vecEndVelocity.z * v3) + this->m_FXData.m_vecEnd.z;
}

//------------------------------------------------------------------------------
// Address: 0x1026B250
// Name: public: CFXLine::CFXLine(char const __near *,struct FXLineData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFXLine *__thiscall CFXLine::CFXLine(CFXLine *this, const char *name, const FXLineData_t *data)
{
  CClientSideEffect::CClientSideEffect(this, name);
  this->__vftable = (CFXLine_vtbl *)&CFXLine::`vftable';
  FXLineData_t::operator=(this: &this->m_FXData, __that: data);
  this->m_FXData.m_flLifeTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1026B2C0
// Name: public: virtual void CFXLine::Draw(double)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CFXLine::Draw(CFXLine *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>, long double frametime)
{
  const Vector *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // ebx
  IMesh *v12; // ebx
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float *m_pCurrPosition; // eax
  int v17; // ecx
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float *v21; // eax
  int v22; // edi
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // eax
  float *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float *v30; // eax
  float *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm2_4
  float *v34; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+14h] [ebp-208h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1FCh] [ebp-20h]
  Vector lineDir; // [esp+200h] [ebp-1Ch]
  float v41; // [esp+20Ch] [ebp-10h]
  Vector cross; // [esp+210h] [ebp-Ch] BYREF
  float scale_4; // [esp+228h] [ebp+Ch]

  ((void (__thiscall *)(CFXLine *, _DWORD, _DWORD, int, int, int))this->Update)(
    a1: this,
    a2: LODWORD(frametime),
    a3: HIDWORD(frametime),
    a4: a3,
    a5: a4,
    a6: a2);
  lineDir.x = this->m_FXData.m_vecStart.x - this->m_FXData.m_vecEnd.x;
  lineDir.y = this->m_FXData.m_vecStart.y - this->m_FXData.m_vecEnd.y;
  lineDir.z = this->m_FXData.m_vecStart.z - this->m_FXData.m_vecEnd.z;
  v6 = CurrentViewOrigin();
  v7 = this->m_FXData.m_vecEnd.y - v6->y;
  v8 = this->m_FXData.m_vecEnd.z - v6->z;
  v9 = this->m_FXData.m_vecEnd.x - v6->x;
  cross.x = (float)(v8 * lineDir.y) - (float)(v7 * lineDir.z);
  cross.y = (float)(lineDir.z * v9) - (float)(v8 * lineDir.x);
  cross.z = (float)(v7 * lineDir.x) - (float)(lineDir.y * v9);
  VectorNormalize(vec: &cross);
  v10 = materials->GetRenderContext(this: materials);
  v11 = v10;
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v12 = v11->GetDynamicMesh(this: v11, a2: true, a3: nullptr, a4: nullptr, a5: this->m_FXData.m_pMaterial);
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
  v13 = this->m_FXData.m_flLifeTime / this->m_FXData.m_flDieTime;
  v14 = (float)((float)(this->m_FXData.m_flEndAlpha - this->m_FXData.m_flStartAlpha) * v13)
      + this->m_FXData.m_flStartAlpha;
  scale_4 = (float)((float)(this->m_FXData.m_flEndScale - this->m_FXData.m_flStartScale) * v13)
          + this->m_FXData.m_flStartScale;
  if ( v14 >= 0.0 )
  {
    if ( v14 > 1.0 )
      v14 = 1.0;
  }
  else
  {
    v14 = 0.0;
  }
  LODWORD(v15) = COERCE_UNSIGNED_INT(
                   (float)((float)(this->m_FXData.m_flEndScale - this->m_FXData.m_flStartScale) * v13)
                 + this->m_FXData.m_flStartScale)
               ^ _mask__NegFloat_;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v17 = (int)(float)(v14 * 255.0);
  v18 = (float)(v15 * cross.x) + this->m_FXData.m_vecStart.x;
  v19 = (float)(v15 * cross.y) + this->m_FXData.m_vecStart.y;
  v41 = v15;
  v20 = (float)(v15 * cross.z) + this->m_FXData.m_vecStart.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
  m_pCurrPosition[1] = v19;
  m_pCurrPosition[2] = v20;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v21[1] = 1.0;
  v22 = ((unsigned __int8)v17 << 24) | 0xFFFFFF;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v24 = (float)(cross.y * scale_4) + this->m_FXData.m_vecStart.y;
  v25 = (float)(cross.z * scale_4) + this->m_FXData.m_vecStart.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(cross.x * scale_4) + this->m_FXData.m_vecStart.x;
  v23[1] = v24;
  v23[2] = v25;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v26[1] = 1.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v27 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v28 = (float)(cross.y * scale_4) + this->m_FXData.m_vecEnd.y;
  v29 = (float)(cross.z * scale_4) + this->m_FXData.m_vecEnd.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(cross.x * scale_4) + this->m_FXData.m_vecEnd.x;
  v27[1] = v28;
  v27[2] = v29;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v30[1] = 0.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v31 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v32 = (float)(v41 * cross.z) + this->m_FXData.m_vecEnd.z;
  v33 = (float)(v41 * cross.y) + this->m_FXData.m_vecEnd.y;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v41 * cross.x) + this->m_FXData.m_vecEnd.x;
  v31[1] = v33;
  v31[2] = v32;
  v34 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v34[1] = 0.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
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
