// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_quad.cpp
// Functions: 6
// ============================================================

#include "game\client\fx_quad.h"

//------------------------------------------------------------------------------
// Address: 0x100DD920
// Name: public: virtual bool CFXQuad::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFXQuad::IsActive(CFXQuad *this)
{
  return this->m_FXData.m_flDieTime > this->m_FXData.m_flLifeTime;
}

//------------------------------------------------------------------------------
// Address: 0x100DD940
// Name: public: virtual void CFXQuad::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFXQuad::Destroy(CFXQuad *this)
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
// Address: 0x100DD960
// Name: public: virtual void CFXQuad::Update(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFXQuad::Update(CFXQuad *this, long double frametime)
{
  this->m_FXData.m_flLifeTime = this->m_FXData.m_flLifeTime + frametime;
}

//------------------------------------------------------------------------------
// Address: 0x100DD980
// Name: public: struct FXQuadData_t __near & FXQuadData_t::operator=(struct FXQuadData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
FXQuadData_t *__thiscall FXQuadData_t::operator=(FXQuadData_t *this, const FXQuadData_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DDA10
// Name: public: CFXQuad::CFXQuad(struct FXQuadData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CFXQuad *__thiscall CFXQuad::CFXQuad(CFXQuad *this, const FXQuadData_t *data)
{
  CClientSideEffect::CClientSideEffect(this, name: "Quad");
  this->__vftable = (CFXQuad_vtbl *)&CFXQuad::`vftable';
  *(_QWORD *)&this->m_FXData.m_flDieTime = 0;
  this->m_FXData.m_uiFlags = 0;
  FXQuadData_t::operator=(this: &this->m_FXData, __that: data);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DDA90
// Name: public: virtual void CFXQuad::Draw(double)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFXQuad::Draw(CFXQuad *this@<ecx>, int a2@<ebx>, long double frametime)
{
  float m_flDieTime; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  IMatRenderContext *v9; // ebx
  IMesh *v10; // ebx
  float v11; // xmm0_4
  bool v12; // zf
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  __m128 m_flYaw_low; // xmm0
  double v17; // xmm0_8
  double v18; // xmm0_8
  float v19; // xmm3_4
  __m128 v20; // xmm0
  double v21; // xmm0_8
  double v22; // xmm0_8
  float v23; // xmm1_4
  float v24; // xmm7_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float *m_pCurrPosition; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float *m_pCurrNormal; // eax
  float *v35; // eax
  float v36; // xmm1_4
  float v37; // xmm2_4
  float *v38; // eax
  float *v39; // eax
  double v40; // st7
  float *v41; // eax
  float *v42; // eax
  float v43; // xmm1_4
  float v44; // xmm2_4
  float *v45; // eax
  double v46; // st7
  float *v47; // eax
  float *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm2_4
  float *v51; // eax
  double v52; // st7
  float *v53; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+2Ch] [ebp-248h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+214h] [ebp-60h]
  float v58; // [esp+218h] [ebp-5Ch]
  float v59; // [esp+21Ch] [ebp-58h]
  float v60; // [esp+220h] [ebp-54h]
  float color[4]; // [esp+224h] [ebp-50h]
  float v62; // [esp+234h] [ebp-40h]
  float scale; // [esp+238h] [ebp-3Ch]
  Vector vUp; // [esp+23Ch] [ebp-38h] BYREF
  Vector vRight; // [esp+248h] [ebp-2Ch] BYREF
  float v66; // [esp+254h] [ebp-20h]
  Vector pos; // [esp+258h] [ebp-1Ch]
  float v68; // [esp+264h] [ebp-10h]
  float v69; // [esp+268h] [ebp-Ch]
  float v70; // [esp+26Ch] [ebp-8h]
  unsigned int alphaTimePerc; // [esp+270h] [ebp-4h]
  int frametime_4; // [esp+280h] [ebp+Ch]
  unsigned int frametime_4a; // [esp+280h] [ebp+Ch]
  float frametime_4b; // [esp+280h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_Quad::Draw",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  ((void (__thiscall *)(CFXQuad *, _DWORD, _DWORD))this->Update)(
    a1: this,
    a2: LODWORD(frametime),
    a3: HIDWORD(frametime));
  m_flDieTime = this->m_FXData.m_flDieTime;
  if ( m_flDieTime == 0.0 )
  {
    v5 = 1.0;
  }
  else if ( (this->m_FXData.m_uiFlags & 1) != 0 )
  {
    *(float *)&alphaTimePerc = Bias(
                                 x: this->m_FXData.m_flLifeTime / m_flDieTime,
                                 biasAmt: LODWORD(this->m_FXData.m_flScaleBias));
    v5 = *(float *)&alphaTimePerc;
  }
  else
  {
    v5 = this->m_FXData.m_flLifeTime / m_flDieTime;
  }
  scale = (float)((float)(this->m_FXData.m_flEndScale - this->m_FXData.m_flStartScale) * v5)
        + this->m_FXData.m_flStartScale;
  v6 = this->m_FXData.m_flDieTime;
  if ( v6 == 0.0 )
  {
    v7 = 1.0;
  }
  else if ( (this->m_FXData.m_uiFlags & 2) != 0 )
  {
    *(float *)&alphaTimePerc = Bias(x: this->m_FXData.m_flLifeTime / v6, biasAmt: LODWORD(this->m_FXData.m_flAlphaBias));
    v7 = *(float *)&alphaTimePerc;
  }
  else
  {
    v7 = this->m_FXData.m_flLifeTime / v6;
  }
  v8 = (float)((float)(this->m_FXData.m_flEndAlpha - this->m_FXData.m_flStartAlpha) * v7)
     + this->m_FXData.m_flStartAlpha;
  if ( v8 >= 0.0 )
  {
    if ( v8 <= 1.0 )
      v70 = (float)((float)(this->m_FXData.m_flEndAlpha - this->m_FXData.m_flStartAlpha) * v7)
          + this->m_FXData.m_flStartAlpha;
    else
      v70 = 1.0;
  }
  else
  {
    v70 = 0.0;
  }
  v9 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
  pRenderContext.m_pObject = v9;
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  v10 = v9->GetDynamicMesh(this: v9, a2: true, a3: nullptr, a4: nullptr, a5: this->m_FXData.m_pMaterial);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v10;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v10->SetPrimitiveType(this: v10, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v10->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v10, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v11 = this->m_FXData.m_flDeltaYaw * frametime + this->m_FXData.m_flYaw;
  v12 = (this->m_FXData.m_uiFlags & 4) == 0;
  this->m_FXData.m_flYaw = (float)(unsigned __int16)(int)(float)(v11 * 182.04445) * 0.0054931641;
  x = this->m_FXData.m_Color.x;
  y = this->m_FXData.m_Color.y;
  z = this->m_FXData.m_Color.z;
  color[0] = x;
  color[1] = y;
  color[2] = z;
  if ( !v12 )
  {
    color[0] = v70 * x;
    color[1] = v70 * y;
    color[2] = v70 * z;
  }
  VectorVectors(forward: &this->m_FXData.m_vecNormal, right: &vRight, up: &vUp);
  m_flYaw_low = (__m128)LODWORD(this->m_FXData.m_flYaw);
  alphaTimePerc = m_flYaw_low.m128_u32[0];
  m_flYaw_low.m128_f32[0] = m_flYaw_low.m128_f32[0] * 0.017453292;
  frametime_4 = m_flYaw_low.m128_i32[0];
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(m_flYaw_low));
  *(float *)&v17 = v17;
  pos.x = vUp.x * *(float *)&v17;
  pos.y = vUp.y * *(float *)&v17;
  pos.z = vUp.z * *(float *)&v17;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)frametime_4));
  v19 = v18;
  v58 = (float)(vRight.x * v19) - pos.x;
  v20 = (__m128)alphaTimePerc;
  v20.m128_f32[0] = (float)(*(float *)&alphaTimePerc + 90.0) * 0.017453292;
  frametime_4a = v20.m128_u32[0];
  v59 = (float)(vRight.y * v19) - pos.y;
  v60 = (float)(vRight.z * v19) - pos.z;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v20));
  *(float *)&v21 = v21;
  pos.x = vUp.x * *(float *)&v21;
  pos.y = vUp.y * *(float *)&v21;
  pos.z = vUp.z * *(float *)&v21;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)frametime_4a));
  v23 = v22;
  v24 = (float)(v23 * vRight.x) - pos.x;
  v25 = (float)(vRight.y * v23) - pos.y;
  v26 = (float)(v23 * vRight.z) - pos.z;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  vRight.x = (float)(scale * 0.5) * v58;
  *(float *)&v22 = vRight.x + this->m_FXData.m_vecOrigin.x;
  vRight.y = v59 * (float)(scale * 0.5);
  v28 = vRight.y + this->m_FXData.m_vecOrigin.y;
  vRight.z = v60 * (float)(scale * 0.5);
  v29 = vRight.z + this->m_FXData.m_vecOrigin.z;
  vUp.x = (float)(scale * 0.5) * v24;
  pos.x = *(float *)&v22 - vUp.x;
  v30 = v25 * (float)(scale * 0.5);
  vUp.y = v30;
  v31 = v26 * (float)(scale * 0.5);
  vUp.z = v31;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)&v22 - vUp.x;
  v32 = v28 - v30;
  m_pCurrPosition[1] = v32;
  v33 = v29 - v31;
  m_pCurrPosition[2] = v33;
  m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
  *meshBuilder.m_VertexBuilder.m_pCurrNormal = this->m_FXData.m_vecNormal.x;
  pos.y = v32;
  m_pCurrNormal[1] = this->m_FXData.m_vecNormal.y;
  pos.z = v33;
  m_pCurrNormal[2] = this->m_FXData.m_vecNormal.z;
  v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v35[1] = 1.0;
  v69 = (float)(color[2] * 255.0) + 8388608.0;
  frametime_4b = v69;
  v66 = (float)(color[1] * 255.0) + 8388608.0;
  scale = v66;
  v68 = (float)(color[0] * 255.0) + 8388608.0;
  *(float *)&alphaTimePerc = v68;
  v70 = (float)(v70 * 255.0) + 8388608.0;
  v62 = v70;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v69)
                                                      | ((LOBYTE(v66) | ((LOBYTE(v68) | (LOBYTE(v62) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v36 = (float)(this->m_FXData.m_vecOrigin.y - vRight.y) - vUp.y;
  v37 = (float)(this->m_FXData.m_vecOrigin.z - vRight.z) - vUp.z;
  pos.x = (float)(this->m_FXData.m_vecOrigin.x - vRight.x) - vUp.x;
  pos.y = v36;
  v38 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = pos.x;
  v38[1] = v36;
  v38[2] = v37;
  v39 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
  *meshBuilder.m_VertexBuilder.m_pCurrNormal = this->m_FXData.m_vecNormal.x;
  v40 = this->m_FXData.m_vecNormal.y;
  pos.z = v37;
  v39[1] = v40;
  v39[2] = this->m_FXData.m_vecNormal.z;
  v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v41[1] = 1.0;
  v62 = frametime_4b;
  v68 = scale;
  v66 = *(float *)&alphaTimePerc;
  v69 = v70;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(frametime_4b)
                                                      | ((LOBYTE(scale)
                                                        | (((unsigned __int8)alphaTimePerc | (LOBYTE(v70) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(float *)&v22 = (float)(this->m_FXData.m_vecOrigin.x - vRight.x) + vUp.x;
  v42 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v43 = (float)(this->m_FXData.m_vecOrigin.y - vRight.y) + vUp.y;
  v44 = (float)(this->m_FXData.m_vecOrigin.z - vRight.z) + vUp.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)&v22;
  v42[1] = v43;
  v42[2] = v44;
  v45 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
  *meshBuilder.m_VertexBuilder.m_pCurrNormal = this->m_FXData.m_vecNormal.x;
  pos.x = *(float *)&v22;
  v45[1] = this->m_FXData.m_vecNormal.y;
  pos.y = v43;
  v46 = this->m_FXData.m_vecNormal.z;
  pos.z = v44;
  v45[2] = v46;
  v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v47[1] = 0.0;
  v62 = frametime_4b;
  v68 = scale;
  v66 = *(float *)&alphaTimePerc;
  v69 = v70;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(frametime_4b)
                                                      | ((LOBYTE(scale)
                                                        | (((unsigned __int8)alphaTimePerc | (LOBYTE(v70) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(float *)&v22 = (float)(vRight.x + this->m_FXData.m_vecOrigin.x) + vUp.x;
  v48 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v49 = (float)(vRight.y + this->m_FXData.m_vecOrigin.y) + vUp.y;
  v50 = (float)(vRight.z + this->m_FXData.m_vecOrigin.z) + vUp.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)&v22;
  v48[1] = v49;
  v48[2] = v50;
  v51 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
  *meshBuilder.m_VertexBuilder.m_pCurrNormal = this->m_FXData.m_vecNormal.x;
  pos.x = *(float *)&v22;
  v51[1] = this->m_FXData.m_vecNormal.y;
  pos.y = v49;
  v52 = this->m_FXData.m_vecNormal.z;
  pos.z = v50;
  v51[2] = v52;
  v53 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v53[1] = 0.0;
  v68 = frametime_4b;
  v66 = scale;
  v69 = *(float *)&alphaTimePerc;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(frametime_4b)
                                                      | ((LOBYTE(scale)
                                                        | (((unsigned __int8)alphaTimePerc | (LOBYTE(v70) << 8)) << 8)) << 8);
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
  v10->Draw_2(this: v10, a2: -1, a3: 0);
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
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}
