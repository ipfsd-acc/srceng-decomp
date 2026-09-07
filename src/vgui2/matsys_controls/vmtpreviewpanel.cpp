// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/vmtpreviewpanel.cpp
// Functions: 24
// ============================================================

#include "vgui2\matsys_controls\vmtpreviewpanel.h"

//------------------------------------------------------------------------------
// Address: 0x004CA5A0
// Name: public: static char const __near * CVMTPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPreviewPanel::GetPanelClassName()
{
  return "CVMTPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004CA5B0
// Name: public: void CVMTPreviewPanel::SetSheetPreviewSpeed(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSheetPreviewSpeed(CVMTPreviewPanel *this, float flPreviewSpeed)
{
  this->m_flSheetPreviewSpeed = flPreviewSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x004CA5E0
// Name: public: void CVMTPreviewPanel::DrawIn3DMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawIn3DMode(CVMTPreviewPanel *this, bool b3DMode)
{
  this->m_bDrawIn3DMode = b3DMode;
}

//------------------------------------------------------------------------------
// Address: 0x004CA5F0
// Name: public: int CVMTPreviewPanel::GetSheetSequenceCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMTPreviewPanel::GetSheetSequenceCount(CVMTPreviewPanel *this)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    return CSheetExtended::GetSheetSequenceCount(this: m_pMaterialSheet);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CA610
// Name: public: int CVMTPreviewPanel::GetRealSequenceNumber(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMTPreviewPanel::GetRealSequenceNumber(CVMTPreviewPanel *this)
{
  return this->m_nCurrentSheetSequence;
}

//------------------------------------------------------------------------------
// Address: 0x004CA620
// Name: public: int CVMTPreviewPanel::GetCurrentSecondarySequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMTPreviewPanel::GetCurrentSecondarySequence(CVMTPreviewPanel *this)
{
  return this->m_nCurrentSecondarySheetSequence;
}

//------------------------------------------------------------------------------
// Address: 0x004CA630
// Name: public: void CVMTPreviewPanel::SetSheetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSheetSequence(CVMTPreviewPanel *this, int nSequence)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    this->m_nCurrentSheetSequence = CSheetExtended::GetNthSequenceIndex(
                                      this: m_pMaterialSheet,
                                      nSequenceNumber: nSequence);
}

//------------------------------------------------------------------------------
// Address: 0x004CA660
// Name: public: void CVMTPreviewPanel::SetSecondarySheetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSecondarySheetSequence(CVMTPreviewPanel *this, int nSequence)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    this->m_nCurrentSecondarySheetSequence = CSheetExtended::GetNthSequenceIndex(
                                               this: m_pMaterialSheet,
                                               nSequenceNumber: nSequence);
}

//------------------------------------------------------------------------------
// Address: 0x004CA690
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int,int,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(
        CMeshBuilder *this,
        IMesh *pMesh,
        MaterialPrimitiveType_t type,
        int nVertexCount,
        int nIndexCount,
        MeshBuffersAllocationSettings_t *pMeshSettings)
{
  this->m_Type = type;
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->SetPrimitiveType(this: pMesh, a2: type);
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: nVertexCount, a3: nIndexCount, a4: this, a5: pMeshSettings);
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: nVertexCount, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x004CA750
// Name: public: void CVMTPreviewPanel::SetVMT(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetVMT(CVMTPreviewPanel *this, const char *pMaterialName)
{
  CSheetExtended *m_pMaterialSheet; // edi
  CSheetExtended *v4; // eax
  CSheetExtended *v5; // eax

  CMaterialReference::Init(
    this: &this->m_Material,
    pMaterialName,
    pTextureGroupName: "editor material",
    bComplain: true);
  CUtlString::operator=(this: &this->m_VMTName, src: pMaterialName);
  this->m_flLastSwitchTime = _Plat_FloatTime();
  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
  {
    CSheetExtended::~CSheetExtended(this: this->m_pMaterialSheet);
    free(pMem: m_pMaterialSheet);
  }
  if ( this->m_bDrawIn3DMode )
  {
    v4 = (CSheetExtended *)MemAlloc_Alloc(nSize: 8u);
    if ( v4 != nullptr )
    {
      v5 = CSheetExtended::CSheetExtended(this: v4, pMaterial: this->m_Material.m_pMaterial);
      this->m_nCurrentSheetSequence = 0;
      this->m_nCurrentSecondarySheetSequence = 0;
      this->m_pMaterialSheet = v5;
    }
    else
    {
      this->m_nCurrentSheetSequence = 0;
      this->m_nCurrentSecondarySheetSequence = 0;
      this->m_pMaterialSheet = nullptr;
    }
  }
  else
  {
    this->m_nCurrentSheetSequence = 0;
    this->m_nCurrentSecondarySheetSequence = 0;
    this->m_pMaterialSheet = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CA820
// Name: private: void CVMTPreviewPanel::SetupLightingState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetupLightingState(CVMTPreviewPanel *this)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float z; // xmm0_4
  IMaterialSystem *v7; // eax
  int v8; // eax
  int v9; // esi
  MaterialLightingState_t state; // [esp+4h] [ebp-1B8h] BYREF

  memset(dst: (unsigned __int8 *)&state, value: 0, count: sizeof(state));
  v2 = this->m_flLightIntensity * 0.0039215689;
  v3 = (float)this->m_LightColor._color[0] * v2;
  v4 = (float)this->m_LightColor._color[1] * v2;
  v5 = (float)this->m_LightColor._color[2] * v2;
  state.m_pLocalLightDesc[0].m_Attenuation0 = 1.0;
  state.m_pLocalLightDesc[0].m_Attenuation1 = 0.0;
  state.m_pLocalLightDesc[0].m_Attenuation2 = 0.0;
  state.m_pLocalLightDesc[0].m_Direction.x = this->m_LightDirection.x;
  state.m_pLocalLightDesc[0].m_Direction.y = this->m_LightDirection.y;
  z = this->m_LightDirection.z;
  state.m_nLocalLightCount = 1;
  state.m_pLocalLightDesc[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  state.m_pLocalLightDesc[0].m_Color.x = v3;
  state.m_pLocalLightDesc[0].m_Color.y = v4;
  state.m_pLocalLightDesc[0].m_Color.z = v5;
  state.m_pLocalLightDesc[0].m_Direction.z = z;
  VectorNormalize(vec: &state.m_pLocalLightDesc[0].m_Direction);
  state.m_pLocalLightDesc[0].m_Theta = 0.0;
  state.m_pLocalLightDesc[0].m_Phi = 0.0;
  state.m_pLocalLightDesc[0].m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: state.m_pLocalLightDesc);
  v7 = vgui::MaterialSystem();
  v8 = (int)v7->GetRenderContext(this: v7);
  v9 = v8;
  if ( v8 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
  (*(void (__thiscall **)(int, MaterialLightingState_t *))(*(_DWORD *)v9 + 56))(a1: v9, a2: &state);
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
}

//------------------------------------------------------------------------------
// Address: 0x004CA990
// Name: private: void CVMTPreviewPanel::RenderSphere(class Vector const __near &,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::RenderSphere(
        CVMTPreviewPanel *this,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi)
{
  IMaterialSystem *v6; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *m_pObject; // ecx
  bool v9; // al
  IMaterial *m_pMaterial; // ecx
  bool v11; // al
  ITexture *m_pTexture; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  int v17; // ecx
  int v18; // esi
  float v19; // xmm1_4
  double v20; // xmm0_8
  unsigned int v21; // xmm0_4
  double v22; // xmm0_8
  double v23; // xmm0_8
  double v24; // xmm0_8
  double v25; // xmm0_8
  float x; // xmm6_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  int v35; // edx
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  int v40; // xmm7_4
  float *m_pCurrPosition; // eax
  int v42; // xmm1_4
  float *v43; // eax
  float *v44; // eax
  float v45; // xmm3_4
  float *v46; // eax
  float *v47; // eax
  float *v48; // eax
  float *v49; // eax
  float *v50; // eax
  float v51; // xmm0_4
  int v52; // ecx
  __int16 v53; // dx
  unsigned int m_nCurrentIndex; // eax
  int v55; // esi
  int v56; // ecx
  bool v57; // zf
  int m_nVertexCount; // eax
  IMatRenderContext *v59; // esi
  long double v60; // [esp+0h] [ebp-258h]
  long double v61; // [esp+0h] [ebp-258h]
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-250h] BYREF
  Vector vecTangentT; // [esp+1F0h] [ebp-68h]
  int u; // [esp+1FCh] [ebp-5Ch]
  unsigned int phi; // [esp+200h] [ebp-58h]
  float v66; // [esp+204h] [ebp-54h]
  Vector vecNormal; // [esp+208h] [ebp-50h] BYREF
  float u1; // [esp+214h] [ebp-44h]
  float v69; // [esp+218h] [ebp-40h]
  unsigned int theta; // [esp+21Ch] [ebp-3Ch]
  IMesh *pMesh; // [esp+220h] [ebp-38h]
  CMatRenderContextPtr pRenderContext; // [esp+224h] [ebp-34h]
  Vector vecPos; // [esp+228h] [ebp-30h]
  int v2; // [esp+234h] [ebp-24h]
  int flHalfLuxel; // [esp+238h] [ebp-20h]
  Vector4D vecTangentS; // [esp+23Ch] [ebp-1Ch] BYREF
  int u2; // [esp+24Ch] [ebp-Ch]
  int i; // [esp+250h] [ebp-8h]
  bool bIsUsingLightmap; // [esp+256h] [ebp-2h]
  bool bIsUsingBumpedLightmap; // [esp+257h] [ebp-1h]
  float v; // [esp+260h] [ebp+8h]
  __int16 va; // [esp+260h] [ebp+8h]
  int flRadiusa; // [esp+264h] [ebp+Ch]
  int nPhia; // [esp+26Ch] [ebp+14h]

  u2 = (nTheta + 1) * (2 * nPhi - 2);
  v6 = vgui::MaterialSystem();
  v7 = v6->GetRenderContext(this: v6);
  m_pObject = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
  {
    v7->BeginRender(this: v7);
    m_pObject = pRenderContext.m_pObject;
  }
  pMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLE_STRIP,
    nVertexCount: nPhi * nTheta,
    nIndexCount: u2,
    pMeshSettings: nullptr);
  v9 = this->m_Material.m_pMaterial->GetPropertyFlag(
         this: this->m_Material.m_pMaterial,
         a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP);
  m_pMaterial = this->m_Material.m_pMaterial;
  bIsUsingLightmap = v9;
  v11 = m_pMaterial->GetPropertyFlag(this: m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
  m_pTexture = this->m_pLightmapTexture.m_pTexture;
  bIsUsingBumpedLightmap = v11;
  v13 = m_pTexture->GetActualWidth(this: m_pTexture);
  v14 = nPhi;
  v15 = 0;
  *(float *)&flHalfLuxel = 0.5 / (float)v13;
  i = 0;
  if ( nPhi > 0 )
  {
    do
    {
      v17 = nTheta;
      v18 = 0;
      if ( nTheta > 0 )
      {
        v66 = (float)(nTheta - 1);
        v19 = (float)v15 / (float)(nPhi - 1);
        v = v19;
        while ( 1 )
        {
          *(float *)&u = (float)v18 / v66;
          if ( v18 == v17 - 1 )
            v20 = 0.0;
          else
            v20 = (float)((float)v18 / v66) * 6.283185307179586;
          *(float *)&v21 = v20;
          theta = v21;
          *(float *)&phi = v19 * 3.141592653589793;
          v22 = *(float *)&phi;
          __libm_sse2_sin(x: v60);
          *(float *)&v22 = v22;
          v69 = *(float *)&v22 * flRadius;
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)theta));
          *(float *)&v23 = v23;
          vecPos.x = *(float *)&v23 * v69;
          v24 = *(float *)&theta;
          __libm_sse2_sin(x: v61);
          *(float *)&v24 = v24;
          vecPos.y = *(float *)&v24 * v69;
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)phi));
          *(float *)&v25 = v25;
          vecPos.z = *(float *)&v25 * flRadius;
          *(_QWORD *)&vecNormal.x = *(_QWORD *)&vecPos.x;
          vecNormal.z = *(float *)&v25 * flRadius;
          VectorNormalize(vec: &vecNormal);
          vecTangentS.x = vecPos.z;
          vecTangentS.y = -vecPos.x;
          vecTangentS.z = 0.0;
          vecTangentS.w = 1.0;
          if ( VectorNormalize(vec: (Vector *)&vecTangentS) == 0.0 )
          {
            x = 1.0;
            y = 0.0;
            z = 0.0;
            vecTangentS.x = 1.0;
            vecTangentS.y = 0.0;
            vecTangentS.z = 0.0;
            vecTangentS.w = 1.0;
          }
          else
          {
            z = vecTangentS.z;
            y = vecTangentS.y;
            x = vecTangentS.x;
          }
          v29 = vecNormal.y * z;
          v30 = (float)(vecNormal.z * x) - (float)(z * vecNormal.x);
          v31 = *(float *)&u;
          v32 = vecNormal.z * y;
          v33 = vecNormal.y * x;
          v34 = vCenter->y + vecPos.y;
          vecTangentT.y = v30;
          v35 = (int)(float)(*(float *)&u * 255.0);
          v36 = v;
          vecTangentT.z = (float)(y * vecNormal.x) - v33;
          v37 = vCenter->z + vecPos.z;
          v38 = vCenter->x + vecPos.x;
          v39 = v29 - v32;
          v40 = LODWORD(v);
          u2 = u;
          u1 = *(float *)&u;
          v2 = LODWORD(v);
          if ( bIsUsingLightmap )
          {
            u1 = (float)((float)((float)(0.25 - *(float *)&flHalfLuxel) - *(float *)&flHalfLuxel) * *(float *)&u)
               + *(float *)&flHalfLuxel;
            if ( bIsUsingBumpedLightmap )
            {
              u2 = 1048576000;
              v40 = 0;
            }
            else
            {
              v40 = v2;
            }
            v36 = v;
          }
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v38;
          m_pCurrPosition[1] = v34;
          m_pCurrPosition[2] = v37;
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
          v42 = u2;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)(int)(float)(v * 255.0)
                                                              | (((unsigned __int8)(int)(float)(v * 255.0)
                                                                | (((unsigned __int8)v35
                                                                  | ((unsigned __int8)(int)(float)(v * 255.0) << 8)) << 8)) << 8);
          v43 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v31 * 2.0;
          v43[1] = v36;
          v43[2] = 0.0;
          v43[3] = 0.0;
          v44 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          v45 = u1;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1;
          v44[1] = v36;
          v44[2] = 0.0;
          v44[3] = 0.0;
          v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v42;
          *((_DWORD *)v46 + 1) = v40;
          v46[2] = 0.0;
          v46[3] = 0.0;
          v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v45;
          v47[1] = v36;
          v47[2] = 0.0;
          v47[3] = 0.0;
          v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v42;
          *((_DWORD *)v48 + 1) = v40;
          v48[2] = 0.0;
          v48[3] = 0.0;
          v49 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
          *v49 = vecTangentS.x;
          v49[1] = vecTangentS.y;
          v49[2] = vecTangentS.z;
          v50 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
          v51 = vecTangentT.y;
          *v50 = v39;
          v50[1] = v51;
          v50[2] = vecTangentT.z;
          if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
            *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                     * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
          meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
          *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_UserData) = vecTangentS;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++v18 >= nTheta )
            break;
          v19 = v;
          v17 = nTheta;
        }
        v15 = i;
      }
      i = ++v15;
    }
    while ( v15 < nPhi );
    v14 = nPhi;
  }
  v52 = 0;
  v53 = 0;
  i = 0;
  flHalfLuxel = v14 - 1;
  if ( v14 - 1 > 0 )
  {
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    v2 = v14 - 2;
    v55 = 0;
    flRadiusa = 0;
    do
    {
      if ( nTheta > 0 )
      {
        v56 = v55;
        nPhia = nTheta;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v56
                                                                 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                            + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                            + v56;
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          va = v56++;
          v57 = nPhia-- == 1;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( !v57 );
        v52 = i;
        v53 = va;
      }
      if ( v52 < v2 )
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                               + v53
                                                               + 1;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                          + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                          + v53
                                                                                          + 1;
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      v55 = nTheta + flRadiusa;
      i = ++v52;
      flRadiusa += nTheta;
    }
    while ( v52 < flHalfLuxel );
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
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
  v59 = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  v59->Release(this: v59);
}

//------------------------------------------------------------------------------
// Address: 0x004CB110
// Name: private: void CVMTPreviewPanel::RenderSheet(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::RenderSheet(CVMTPreviewPanel *this, const Vector *vCenter, float flRadius)
{
  IMaterialSystem *v4; // eax
  int v5; // eax
  int v6; // esi
  IMesh *v7; // ebx
  float flAge; // [esp+18h] [ebp-24h]
  float v9; // [esp+38h] [ebp-4h]

  v4 = vgui::MaterialSystem();
  v5 = (int)v4->GetRenderContext(this: v4);
  v6 = v5;
  if ( v5 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
  v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                  a1: v6,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0);
  if ( CSheetExtended::ValidSheetData(this: this->m_pMaterialSheet) )
  {
    v9 = _Plat_FloatTime() - this->m_flLastSwitchTime;
    flAge = fmod(
              v9,
              CSheetExtended::GetSequenceTimeSpan(
                this: this->m_pMaterialSheet,
                nSequenceIndex: this->m_nCurrentSheetSequence));
    CSheetExtended::DrawSheet(
      this: this->m_pMaterialSheet,
      pMesh: v7,
      vCenter,
      flRadius,
      nSheetSequence: this->m_nCurrentSheetSequence,
      flAge,
      flSheetPreviewSpeed: this->m_flSheetPreviewSpeed,
      bLoopSheetPreview: true,
      nSecondarySequence: this->m_nCurrentSecondarySheetSequence,
      bOverrideSpriteCard: false);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004CB1F0
// Name: private: void CVMTPreviewPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVMTPreviewPanel::LookAt(
        CVMTPreviewPanel *this@<ecx>,
        long double a2@<esi:edi>,
        const Vector *vecLookAt,
        float flRadius)
{
  int v5; // edi
  double v6; // xmm0_8
  double v7; // xmm0_8
  float v8; // xmm0_4
  float z; // edx
  Vector *p_m_vecCameraDirection; // edi
  float v11; // xmm0_4
  IMaterialSystem *v12; // eax
  int v13; // eax
  int v14; // esi
  void (__thiscall *v15)(int, int, int); // eax
  int v17; // [esp+60h] [ebp-38h]
  int v18; // [esp+64h] [ebp-34h]
  QAngle angles; // [esp+68h] [ebp-30h] BYREF
  Vector vecMDLOrigin; // [esp+74h] [ebp-24h]
  Vector vecCameraOrigin; // [esp+80h] [ebp-18h]
  float flFOVx; // [esp+8Ch] [ebp-Ch]
  int h; // [esp+90h] [ebp-8h] BYREF
  int w; // [esp+94h] [ebp-4h] BYREF

  flFOVx = 0.78539819;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v5 = h;
  if ( h >= w )
  {
    v8 = flFOVx;
  }
  else
  {
    __libm_sse2_tan(X: (__m128i)0x3FE921FB54442D18uLL);
    *(float *)&v6 = v6;
    v7 = (float)((float)(*(float *)&v6 * (float)v5) / (float)w);
    __libm_sse2_atan();
    v8 = v7;
  }
  z = vecLookAt->z;
  *(_QWORD *)&vecMDLOrigin.x = *(_QWORD *)&vecLookAt->x;
  vecMDLOrigin.z = z;
  p_m_vecCameraDirection = &this->m_vecCameraDirection;
  __libm_sse2_sin(x: a2);
  LODWORD(v11) = COERCE_UNSIGNED_INT(flRadius / v8) ^ _mask__NegFloat_;
  vecCameraOrigin.x = (float)(this->m_vecCameraDirection.x * v11) + vecMDLOrigin.x;
  vecCameraOrigin.y = (float)(this->m_vecCameraDirection.y * v11) + vecMDLOrigin.y;
  vecCameraOrigin.z = (float)(this->m_vecCameraDirection.z * v11) + vecMDLOrigin.z;
  v12 = vgui::MaterialSystem();
  v13 = ((int (__thiscall *)(IMaterialSystem *, int, int))v12->GetRenderContext)(a1: v12, a2: v17, a3: v18);
  v14 = v13;
  if ( v13 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 8))(a1: v13);
  VectorAngles(forward: p_m_vecCameraDirection, &angles);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v14 + 80))(
    a1: v14,
    a2: 0,
    a3: LODWORD(angles.x),
    a4: LODWORD(angles.y));
  (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 124))(a1: v14);
  v15 = *(void (__thiscall **)(int, int, int))(*(_DWORD *)v14 + 140);
  angles.y = 0.0;
  angles.x = 0.0;
  v15(a1: v14, a2: -1028390912, a3: 1065353216);
  (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)v14 + 140))(
    a1: v14,
    a2: 1119092736,
    a3: 0,
    a4: 0,
    a5: 1065353216);
  (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v14 + 140))(
    a1: v14,
    a2: LODWORD(angles.z) ^ _mask__NegFloat_,
    a3: 1065353216,
    a4: 0,
    a5: 0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v14 + 140))(
    a1: v14,
    a2: LODWORD(angles.x) ^ _mask__NegFloat_,
    a3: 0,
    a4: 1065353216,
    a5: 0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v14 + 140))(
    a1: v14,
    a2: LODWORD(angles.y) ^ _mask__NegFloat_,
    a3: 0,
    a4: 0,
    a5: 1065353216);
  (*(void (__thiscall **)(int, _DWORD, unsigned int, _DWORD))(*(_DWORD *)v14 + 144))(
    a1: v14,
    a2: -vecCameraOrigin.x,
    a3: LODWORD(vecCameraOrigin.y) ^ 0x80000000,
    a4: -vecCameraOrigin.z);
  (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 12))(a1: v14);
  (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 4))(a1: v14);
}

//------------------------------------------------------------------------------
// Address: 0x004CB490
// Name: private: void CVMTPreviewPanel::SetupProjectionMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CVMTPreviewPanel::SetupProjectionMatrix(
        CVMTPreviewPanel *this@<ecx>,
        int a2@<esi>,
        int nWidth,
        int nHeight)
{
  float v4; // xmm0_4
  double v5; // xmm0_8
  IMaterialSystem *v6; // eax
  int v7; // eax
  int v8; // esi
  VMatrix proj; // [esp+0h] [ebp-40h] BYREF
  float flApsectRatio; // [esp+4Ch] [ebp+Ch]

  if ( (float)nHeight == 0.0 )
    v4 = 100.0;
  else
    v4 = (float)nWidth / (float)nHeight;
  flApsectRatio = v4;
  __libm_sse2_tan(X: (__m128i)0x3FE921FB54442D18uLL);
  *(float *)&v5 = v5;
  memset(dst: (unsigned __int8 *)&proj, value: 0, count: sizeof(proj));
  proj.m[1][1] = 1.0 / (float)(*(float *)&v5 / flApsectRatio);
  *(_QWORD *)&proj.m[2][2] = 0xBDCCCF6CBF8001A3uLL;
  proj.m[3][2] = -1.0;
  proj.m[0][0] = 1.0 / *(float *)&v5;
  v6 = vgui::MaterialSystem();
  v7 = ((int (__thiscall *)(IMaterialSystem *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v6->GetRenderContext)(
         a1: v6,
         a2,
         a3: LODWORD(proj.m[0][0]),
         a4: LODWORD(proj.m[0][1]),
         a5: LODWORD(proj.m[0][2]),
         a6: LODWORD(proj.m[0][3]),
         a7: LODWORD(proj.m[1][0]),
         a8: LODWORD(proj.m[1][1]),
         a9: LODWORD(proj.m[1][2]),
         a10: LODWORD(proj.m[1][3]),
         a11: LODWORD(proj.m[2][0]),
         a12: LODWORD(proj.m[2][1]),
         a13: LODWORD(proj.m[2][2]),
         a14: LODWORD(proj.m[2][3]),
         a15: LODWORD(proj.m[3][0]),
         a16: LODWORD(proj.m[3][1]),
         a17: LODWORD(proj.m[3][2]),
         a18: LODWORD(proj.m[3][3]));
  v8 = v7;
  if ( v7 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 1);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v8 + 96))(a1: v8, a2: &proj);
  (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8);
  (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
}

//------------------------------------------------------------------------------
// Address: 0x004CB590
// Name: private: void CVMTPreviewPanel::SetupOrthoMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetupOrthoMatrix(CVMTPreviewPanel *this, int nWidth, int nHeight)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = vgui::MaterialSystem();
  v4 = (int)v3->GetRenderContext(this: v3);
  v5 = v4;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 124))(a1: v5);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v5 + 128))(
    a1: v5,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0,
    a6: COERCE_UNSIGNED_INT64((double)nWidth),
    a7: HIDWORD(COERCE_UNSIGNED_INT64((double)nWidth)),
    a8: COERCE_UNSIGNED_INT64((double)nHeight),
    a9: HIDWORD(COERCE_UNSIGNED_INT64((double)nHeight)),
    a10: 0,
    a11: -1074790400,
    a12: 0,
    a13: 1072693248);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004CB640
// Name: private: void CVMTPreviewPanel::DrawRectangle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawRectangle(CVMTPreviewPanel *this)
{
  int v2; // eax
  IMaterial *m_pMaterial; // ecx
  int v4; // esi
  int (__thiscall *GetMappingHeight)(IMaterial *); // edx
  int v6; // eax
  IMaterialSystem *v7; // eax
  int v8; // eax
  int v9; // esi
  IMesh *v10; // ebx
  bool v11; // al
  IMaterial *v12; // ecx
  IMaterial_vtbl *v13; // edx
  bool v14; // al
  ITexture *m_pTexture; // ecx
  ITexture_vtbl *v16; // edx
  int v17; // eax
  int v18; // edx
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  int v22; // edi
  int v23; // ecx
  float v24; // xmm4_4
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  float v28; // xmm4_4
  __int64 v29; // rax
  int v30; // ecx
  int v31; // edi
  int v32; // ebx
  int v33; // xmm6_4
  float v34; // xmm4_4
  float v35; // xmm3_4
  int v36; // edx
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // eax
  float *v39; // eax
  float *v40; // eax
  float *v41; // eax
  int v42; // xmm2_4
  float *v43; // eax
  float *v44; // eax
  float *v45; // eax
  float *v46; // eax
  float *v47; // eax
  _DWORD *v48; // eax
  _DWORD *v49; // eax
  __int64 v50; // xmm0_8
  _QWORD *v51; // eax
  float *v52; // eax
  float x; // xmm1_4
  float v54; // xmm2_4
  int v55; // xmm4_4
  float v56; // xmm5_4
  float *v57; // eax
  float *v58; // eax
  float *v59; // eax
  float v60; // xmm1_4
  float *v61; // eax
  float *v62; // eax
  float *v63; // eax
  float *v64; // eax
  float *v65; // eax
  float *v66; // eax
  _DWORD *v67; // eax
  _DWORD *v68; // eax
  __int64 v69; // xmm0_8
  _QWORD *v70; // eax
  float *v71; // eax
  int v72; // xmm1_4
  float v73; // xmm2_4
  float v74; // xmm4_4
  int v75; // xmm5_4
  float *v76; // eax
  float *v77; // eax
  float *v78; // eax
  float v79; // xmm1_4
  float *v80; // eax
  float *v81; // eax
  float *v82; // eax
  float *v83; // eax
  float *v84; // eax
  float *v85; // eax
  _DWORD *v86; // eax
  _DWORD *v87; // eax
  __int64 v88; // xmm0_8
  _QWORD *v89; // eax
  float *v90; // eax
  float *v91; // eax
  float *v92; // eax
  float *v93; // eax
  float v94; // xmm2_4
  float v95; // xmm1_4
  float *v96; // eax
  float v97; // xmm4_4
  float v98; // xmm5_4
  float *v99; // eax
  float *v100; // eax
  float *v101; // eax
  float *v102; // eax
  float *v103; // eax
  _DWORD *v104; // eax
  _DWORD *v105; // eax
  __int64 v106; // xmm0_8
  _QWORD *v107; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-244h] BYREF
  float v109; // [esp+1F0h] [ebp-5Ch]
  float v110; // [esp+1F4h] [ebp-58h]
  Vector2D halfTexel; // [esp+1F8h] [ebp-54h]
  IMesh *pMesh; // [esp+200h] [ebp-4Ch]
  float v1_t; // [esp+204h] [ebp-48h]
  Vector4D vecTangentS; // [esp+208h] [ebp-44h]
  float u1_l; // [esp+218h] [ebp-34h]
  float v2_b; // [esp+21Ch] [ebp-30h]
  float v1_b; // [esp+220h] [ebp-2Ch]
  float u2_r; // [esp+224h] [ebp-28h]
  float u1_r; // [esp+228h] [ebp-24h]
  int th; // [esp+22Ch] [ebp-20h]
  int w; // [esp+230h] [ebp-1Ch] BYREF
  float flHalfLuxel; // [esp+234h] [ebp-18h]
  bool bIsUsingBumpedLightmap; // [esp+23Ah] [ebp-12h]
  bool bIsUsingLightmap; // [esp+23Bh] [ebp-11h]
  int h; // [esp+23Ch] [ebp-10h] BYREF
  int nYBorder; // [esp+240h] [ebp-Ch]
  int v2_t; // [esp+244h] [ebp-8h]
  int usewide; // [esp+248h] [ebp-4h]

  *(float *)&v2 = COERCE_FLOAT(this->m_Material.m_pMaterial->GetMappingWidth(this: this->m_Material.m_pMaterial));
  m_pMaterial = this->m_Material.m_pMaterial;
  v4 = v2;
  GetMappingHeight = m_pMaterial->GetMappingHeight;
  usewide = v2;
  *(float *)&v6 = COERCE_FLOAT(GetMappingHeight(this: m_pMaterial));
  th = v6;
  if ( v4 > 0 && v6 > 0 )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    if ( w != 0 && h != 0 )
    {
      CVMTPreviewPanel::SetupOrthoMatrix(this, nWidth: w, nHeight: h);
      CVMTPreviewPanel::SetupLightingState(this);
      v7 = vgui::MaterialSystem();
      v8 = (int)v7->GetRenderContext(this: v7);
      v9 = v8;
      if ( v8 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 80))(a1: v9, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 80))(a1: v9, a2: 10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9);
      v10 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 228))(
                       a1: v9,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
      pMesh = v10;
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh: v10,
        type: MATERIAL_TRIANGLE_STRIP,
        nVertexCount: 4,
        nIndexCount: 4,
        pMeshSettings: nullptr);
      v11 = this->m_Material.m_pMaterial->GetPropertyFlag(
              this: this->m_Material.m_pMaterial,
              a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP);
      v12 = this->m_Material.m_pMaterial;
      v13 = v12->__vftable;
      bIsUsingLightmap = v11;
      v14 = v13->GetPropertyFlag(this: v12, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
      m_pTexture = this->m_pLightmapTexture.m_pTexture;
      v16 = m_pTexture->__vftable;
      bIsUsingBumpedLightmap = v14;
      v17 = v16->GetActualWidth(this: m_pTexture);
      v18 = h;
      v19 = 0.5 / (float)th;
      flHalfLuxel = 0.5 / (float)v17;
      v20 = 0.5 / (float)usewide;
      halfTexel.x = v20;
      halfTexel.y = v19;
      vecTangentS.x = 1.0;
      vecTangentS.y = 0.0;
      vecTangentS.z = 0.0;
      vecTangentS.w = 1.0;
      v21 = (float)usewide / (float)th;
      v22 = 0;
      v23 = 0;
      v24 = v21 / (float)((float)w / (float)h);
      if ( w <= 15 )
      {
        v18 = h;
        v2_t = w / 3;
      }
      else
      {
        v2_t = 5;
      }
      if ( v18 <= 15 )
      {
        v25 = v18 / 3;
        v18 = h;
        nYBorder = v25;
      }
      else
      {
        nYBorder = 5;
      }
      v26 = w - 2 * v2_t;
      v27 = v18 - 2 * nYBorder;
      w = v26;
      h = v27;
      if ( v24 <= 1.0 )
      {
        v28 = (float)v27 * v21;
        v29 = v26 - (int)v28;
        usewide = (int)v28;
        v26 = (int)v28;
        v23 = ((int)v29 - HIDWORD(v29)) >> 1;
        w = (int)v28;
      }
      else
      {
        usewide = (int)(float)((float)v26 / v21);
        v22 = (v27 - usewide) / 2;
        h = usewide;
      }
      v30 = v2_t + v23;
      v31 = nYBorder + v22;
      v32 = v30 + v26;
      *(float *)&th = 1.0 - v20;
      u2_r = 1.0 - v20;
      u1_r = 1.0 - v20;
      v33 = LODWORD(v20);
      v34 = v20;
      v35 = v19;
      v36 = v31 + h;
      nYBorder = LODWORD(v20);
      u1_l = v20;
      v2_t = LODWORD(v19);
      v1_t = v19;
      *(float *)&usewide = 1.0 - v19;
      v2_b = 1.0 - v19;
      v1_b = 1.0 - v19;
      if ( bIsUsingLightmap )
      {
        v35 = flHalfLuxel;
        v34 = flHalfLuxel;
        v1_t = flHalfLuxel;
        u1_l = flHalfLuxel;
        v1_b = 0.25 - flHalfLuxel;
        u1_r = 0.25 - flHalfLuxel;
        if ( bIsUsingBumpedLightmap )
        {
          v33 = 1048576000;
          u2_r = 0.25;
          nYBorder = 1048576000;
          v2_b = 0.0;
          v2_t = 0;
        }
        else
        {
          v33 = nYBorder;
        }
      }
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v30;
      flHalfLuxel = (float)v30;
      m_pCurrPosition[1] = (float)v36;
      m_pCurrPosition[2] = 0.0;
      m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      m_pCurrNormal[1] = 0.0;
      m_pCurrNormal[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v20;
      v39[1] = v19;
      v39[2] = 0.0;
      v39[3] = 0.0;
      v40 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v34;
      v40[1] = v35;
      v40[2] = 0.0;
      v40[3] = 0.0;
      v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v33;
      v42 = v2_t;
      *((_DWORD *)v41 + 1) = v2_t;
      v41[2] = 0.0;
      v41[3] = 0.0;
      v43 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v34;
      v43[1] = v35;
      v43[2] = 0.0;
      v43[3] = 0.0;
      v44 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v33;
      *((_DWORD *)v44 + 1) = v42;
      v44[2] = 0.0;
      v44[3] = 0.0;
      v45 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v34;
      v45[1] = v35;
      v45[2] = 0.0;
      v45[3] = 0.0;
      v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v33;
      *((_DWORD *)v46 + 1) = v42;
      v46[2] = 0.0;
      v46[3] = 0.0;
      v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v34;
      v47[1] = v35;
      v47[2] = 0.0;
      v47[3] = 0.0;
      v48 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      v109 = (float)v36;
      *v48 = 1065353216;
      v48[1] = 0;
      v48[2] = 0;
      v49 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v49 = 0;
      v49[1] = 1065353216;
      v49[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v50 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v51 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v51 = v50;
      v51[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v52 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = flHalfLuxel;
      x = halfTexel.x;
      v54 = v1_b;
      v55 = nYBorder;
      v56 = v2_b;
      v52[1] = (float)v31;
      v110 = (float)v31;
      v52[2] = 0.0;
      v57 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v57[1] = 0.0;
      v57[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v58 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = x;
      v58[1] = *(float *)&usewide;
      v58[2] = 0.0;
      v58[3] = 0.0;
      v59 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v60 = u1_l;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1_l;
      v59[1] = v54;
      v59[2] = 0.0;
      v59[3] = 0.0;
      v61 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v55;
      v61[1] = v56;
      v61[2] = 0.0;
      v61[3] = 0.0;
      v62 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v60;
      v62[1] = v54;
      v62[2] = 0.0;
      v62[3] = 0.0;
      v63 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v55;
      v63[1] = v56;
      v63[2] = 0.0;
      v63[3] = 0.0;
      v64 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v60;
      v64[1] = v54;
      v64[2] = 0.0;
      v64[3] = 0.0;
      v65 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v55;
      v65[1] = v56;
      v65[2] = 0.0;
      v65[3] = 0.0;
      v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v60;
      v66[1] = v54;
      v66[2] = 0.0;
      v66[3] = 0.0;
      v67 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v67 = 1065353216;
      v67[1] = 0;
      v67[2] = 0;
      v68 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v68 = 0;
      v68[1] = 1065353216;
      v68[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v69 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v70 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v70 = v69;
      v70[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v71 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v72 = th;
      v73 = u1_r;
      v74 = u2_r;
      v75 = v2_t;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v32;
      flHalfLuxel = (float)v32;
      v71[1] = v109;
      v71[2] = 0.0;
      v76 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v76[1] = 0.0;
      v76[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v77 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v72;
      v77[1] = halfTexel.y;
      v77[2] = 0.0;
      v77[3] = 0.0;
      v78 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v73;
      v79 = v1_t;
      v78[1] = v1_t;
      v78[2] = 0.0;
      v78[3] = 0.0;
      v80 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v74;
      *((_DWORD *)v80 + 1) = v75;
      v80[2] = 0.0;
      v80[3] = 0.0;
      v81 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v73;
      v81[1] = v79;
      v81[2] = 0.0;
      v81[3] = 0.0;
      v82 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v74;
      *((_DWORD *)v82 + 1) = v75;
      v82[2] = 0.0;
      v82[3] = 0.0;
      v83 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v73;
      v83[1] = v79;
      v83[2] = 0.0;
      v83[3] = 0.0;
      v84 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v74;
      *((_DWORD *)v84 + 1) = v75;
      v84[2] = 0.0;
      v84[3] = 0.0;
      v85 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v73;
      v85[1] = v79;
      v85[2] = 0.0;
      v85[3] = 0.0;
      v86 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v86 = 1065353216;
      v86[1] = 0;
      v86[2] = 0;
      v87 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v87 = 0;
      v87[1] = 1065353216;
      v87[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v88 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v89 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v89 = v88;
      v89[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v90 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = flHalfLuxel;
      v90[1] = v110;
      v90[2] = 0.0;
      v91 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v91[1] = 0.0;
      v91[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v92 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(float *)&th;
      v92[1] = *(float *)&usewide;
      v92[2] = 0.0;
      v92[3] = 0.0;
      v93 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v94 = u1_r;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1_r;
      v95 = v1_b;
      v93[1] = v1_b;
      v93[2] = 0.0;
      v93[3] = 0.0;
      v96 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      v97 = u2_r;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = u2_r;
      v98 = v2_b;
      v96[1] = v2_b;
      v96[2] = 0.0;
      v96[3] = 0.0;
      v99 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v94;
      v99[1] = v95;
      v99[2] = 0.0;
      v99[3] = 0.0;
      v100 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v97;
      v100[1] = v98;
      v100[2] = 0.0;
      v100[3] = 0.0;
      v101 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v94;
      v101[1] = v95;
      v101[2] = 0.0;
      v101[3] = 0.0;
      v102 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v97;
      v102[1] = v98;
      v102[2] = 0.0;
      v102[3] = 0.0;
      v103 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v94;
      v103[1] = v95;
      v103[2] = 0.0;
      v103[3] = 0.0;
      v104 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v104 = 1065353216;
      v104[1] = 0;
      v104[2] = 0;
      v105 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v105 = 0;
      v105[1] = 1065353216;
      v105[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v106 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v107 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v107 = v106;
      v107[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 1;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 2;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 3;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      CMeshBuilder::End(this: &meshBuilder, bSpewData: false, bDraw: false);
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC150
// Name: private: void CVMTPreviewPanel::DrawSphere(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawSphere(CVMTPreviewPanel *this)
{
  double v1; // st7
  long double v2; // rdi
  double v3; // st7
  CSheetExtended *v4; // ecx
  float angleDegrees; // [esp+8h] [ebp-64h]
  VMatrix rot; // [esp+14h] [ebp-58h] BYREF
  Vector vecTemp; // [esp+54h] [ebp-18h] BYREF
  int w; // [esp+60h] [ebp-Ch] BYREF
  int h; // [esp+64h] [ebp-8h] BYREF
  float flNewTime; // [esp+68h] [ebp-4h]

  HIDWORD(v2) = this;
  v1 = _Plat_FloatTime();
  flNewTime = v1;
  angleDegrees = (v1 - *(float *)(HIDWORD(v2) + 400)) * 40.0;
  MatrixBuildRotateZ(dst: &rot, angleDegrees);
  LODWORD(v2) = HIDWORD(v2) + 388;
  Vector3DMultiply(src1: &rot, src2: (Vector *)(HIDWORD(v2) + 388), dst: &vecTemp);
  v3 = flNewTime;
  *(Vector *)(HIDWORD(v2) + 388) = vecTemp;
  *(float *)(HIDWORD(v2) + 400) = v3;
  vgui::Panel::GetSize(this: (vgui::Panel *)HIDWORD(v2), wide: &w, tall: &h);
  CVMTPreviewPanel::SetupProjectionMatrix(
    this: (CVMTPreviewPanel *)HIDWORD(v2),
    a2: SHIDWORD(v2),
    nWidth: w,
    nHeight: h);
  CVMTPreviewPanel::SetupLightingState(this: (CVMTPreviewPanel *)HIDWORD(v2));
  CVMTPreviewPanel::LookAt(this: (CVMTPreviewPanel *)HIDWORD(v2), a2: v2, vecLookAt: &vec3_origin, flRadius: 12.0);
  v4 = *(CSheetExtended **)(HIDWORD(v2) + 356);
  if ( v4 != nullptr && CSheetExtended::ValidSheetData(this: v4) )
    CVMTPreviewPanel::RenderSheet(this: (CVMTPreviewPanel *)HIDWORD(v2), vCenter: &vec3_origin, flRadius: 10.0);
  else
    CVMTPreviewPanel::RenderSphere(
      this: (CVMTPreviewPanel *)HIDWORD(v2),
      vCenter: &vec3_origin,
      flRadius: 10.0,
      nTheta: 20,
      nPhi: 20);
}

//------------------------------------------------------------------------------
// Address: 0x004CC250
// Name: public: virtual void CVMTPreviewPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::Paint(CVMTPreviewPanel *this)
{
  IMaterialSystem *v2; // eax
  int v3; // eax
  int v4; // esi
  IMatSystemSurface *v5; // eax
  ITexture *m_pTexture; // ecx
  IMaterialSystem *v7; // eax
  ITexture *v8; // eax
  ITexture *v9; // ebx
  IMatSystemSurface *v10; // eax
  int w; // [esp+8h] [ebp-8h] BYREF
  int h; // [esp+Ch] [ebp-4h] BYREF

  v2 = vgui::MaterialSystem();
  v3 = (int)v2->GetRenderContext(this: v2);
  v4 = v3;
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v5 = vgui::MatSystemSurface();
  v5->Begin3DPaint(this: v5, a2: 0, a3: 0, a4: w, a5: h);
  if ( this->m_Material.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(this: this->m_Material.m_pMaterial, a2: true) )
  {
    m_pTexture = s_pPowerOfTwoFrameBufferTexture.m_pTexture;
    if ( s_pPowerOfTwoFrameBufferTexture.m_pTexture == nullptr )
    {
      v7 = vgui::MaterialSystem();
      v8 = v7->FindTexture(this: v7, a2: "_rt_PowerOfTwoFB", a3: "RenderTargets", a4: true, a5: 0);
      CTextureReference::Init(this: &s_pPowerOfTwoFrameBufferTexture, pTexture: v8);
      m_pTexture = s_pPowerOfTwoFrameBufferTexture.m_pTexture;
    }
    v9 = m_pTexture;
    if ( m_pTexture != nullptr && !m_pTexture->IsError(this: m_pTexture) )
    {
      (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 68))(a1: v4, a2: v9);
      (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v4 + 72))(a1: v4, a2: v9, a3: 0);
    }
  }
  (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v4 + 296))(a1: v4, a2: 76, a3: 88, a4: 68, a5: 255);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v4 + 48))(a1: v4, a2: 1, a3: 1, a4: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 176))(a1: v4, a2: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 216))(a1: v4, a2: 0);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
    a1: v4,
    a2: this->m_Material.m_pMaterial,
    a3: 0);
  (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 448))(a1: v4, a2: this->m_pLightmapTexture.m_pTexture);
  (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 20))(a1: v4, a2: this->m_DefaultEnvCubemap.m_pTexture);
  if ( this->m_bDrawIn3DMode )
    CVMTPreviewPanel::DrawSphere(this);
  else
    CVMTPreviewPanel::DrawRectangle(this);
  v10 = vgui::MatSystemSurface();
  v10->End3DPaint(this: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004CC3E0
// Name: public: CVMTPreviewPanel::CVMTPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMTPreviewPanel *__thiscall CVMTPreviewPanel::CVMTPreviewPanel(
        CVMTPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CVMTPreviewPanel_vtbl *)&CVMTPreviewPanel::`vftable';
  if ( `CVMTPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewPanel");
    v4->pfnClassName = CVMTPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CVMTPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVMTPreviewPanel");
    v5->pfnClassName = CVMTPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CVMTPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewPanel");
    v6->pfnClassName = CVMTPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CUtlString::CUtlString(this: &this->m_VMTName);
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_pLightmapTexture);
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  this->m_LightColor = 0;
  this->m_pMaterialSheet = nullptr;
  CVMTPreviewPanel::SetVMT(this, pMaterialName: "//platform/materials/vgui/vtfnotloaded");
  CTextureReference::Init(
    this: &this->m_pLightmapTexture,
    pTextureName: "//platform/materials/debug/defaultlightmap",
    pTextureGroupName: "editor",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  CTextureReference::Init(
    this: &this->m_DefaultEnvCubemap,
    pTextureName: "editor/cubemap",
    pTextureGroupName: "editor",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  this->m_LightDirection.z = -1.0;
  this->m_LightDirection.x = 0.0;
  this->m_LightDirection.y = 1.0;
  this->m_LightColor = (Color)-1;
  this->m_flLightIntensity = 2.0;
  this->m_bDrawIn3DMode = false;
  this->m_flSheetPreviewSpeed = 750.0;
  this->m_nCurrentSheetSequence = 0;
  this->m_nCurrentSecondarySheetSequence = 0;
  this->m_vecCameraDirection.x = 1.0;
  this->m_vecCameraDirection.y = 0.0;
  this->m_vecCameraDirection.z = 0.0;
  this->m_flLastRotationTime = _Plat_FloatTime();
  this->m_flLastSwitchTime = _Plat_FloatTime();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CC5B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPreviewPanel::GetMessageMap(CVMTPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CVMTPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewPanel");
  `CVMTPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CC5E0
// Name: public: virtual struct PanelAnimationMap __near * CVMTPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPreviewPanel::GetAnimMap(CVMTPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004CC5F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPreviewPanel::GetKBMap(CVMTPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CVMTPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewPanel");
  `CVMTPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CC620
// Name: public: virtual CVMTPreviewPanel::~CVMTPreviewPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::~CVMTPreviewPanel(CVMTPreviewPanel *this)
{
  bool v2; // sf

  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_pLightmapTexture);
  CMaterialReference::~CMaterialReference(this: &this->m_Material);
  v2 = this->m_VMTName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_VMTName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_VMTName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VMTName.m_Storage.m_Memory.m_pMemory);
      this->m_VMTName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_VMTName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D01C0
// Name: public: static char const __near * CVMTPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPreviewPanel::GetPanelClassName()
{
  return "CVMTPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104D01D0
// Name: public: void CVMTPreviewPanel::SetSheetPreviewSpeed(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSheetPreviewSpeed(CVMTPreviewPanel *this, float flPreviewSpeed)
{
  this->m_flSheetPreviewSpeed = flPreviewSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x104D0200
// Name: public: void CVMTPreviewPanel::DrawIn3DMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawIn3DMode(CVMTPreviewPanel *this, bool b3DMode)
{
  this->m_bDrawIn3DMode = b3DMode;
}

//------------------------------------------------------------------------------
// Address: 0x104D0210
// Name: public: int CVMTPreviewPanel::GetSheetSequenceCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMTPreviewPanel::GetSheetSequenceCount(CVMTPreviewPanel *this)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    return CSheetExtended::GetSheetSequenceCount(this: m_pMaterialSheet);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104D0230
// Name: public: int CVMTPreviewPanel::GetRealSequenceNumber(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMTPreviewPanel::GetRealSequenceNumber(CVMTPreviewPanel *this)
{
  return this->m_nCurrentSheetSequence;
}

//------------------------------------------------------------------------------
// Address: 0x104D0240
// Name: public: void CVMTPreviewPanel::SetSheetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSheetSequence(CVMTPreviewPanel *this, int nSequence)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    this->m_nCurrentSheetSequence = CSheetExtended::GetNthSequenceIndex(
                                      this: m_pMaterialSheet,
                                      nSequenceNumber: nSequence);
}

//------------------------------------------------------------------------------
// Address: 0x104D0270
// Name: public: void CVMTPreviewPanel::SetSecondarySheetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSecondarySheetSequence(CVMTPreviewPanel *this, int nSequence)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    this->m_nCurrentSecondarySheetSequence = CSheetExtended::GetNthSequenceIndex(
                                               this: m_pMaterialSheet,
                                               nSequenceNumber: nSequence);
}

//------------------------------------------------------------------------------
// Address: 0x104D02A0
// Name: public: void CVMTPreviewPanel::SetVMT(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x104D0370
// Name: private: void CVMTPreviewPanel::SetupLightingState(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVMTPreviewPanel::SetupLightingState(CVMTPreviewPanel *this@<ecx>, int a2@<edi>)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float z; // xmm0_4
  IMaterialSystem *v8; // eax
  int v9; // eax
  int v10; // esi
  MaterialLightingState_t state; // [esp+4h] [ebp-1B8h] BYREF

  memset(dst: (unsigned __int8 *)&state, value: 0, count: sizeof(state));
  v3 = this->m_flLightIntensity * 0.0039215689;
  v4 = (float)this->m_LightColor._color[0] * v3;
  v5 = (float)this->m_LightColor._color[1] * v3;
  v6 = (float)this->m_LightColor._color[2] * v3;
  state.m_pLocalLightDesc[0].m_Attenuation0 = 1.0;
  state.m_pLocalLightDesc[0].m_Attenuation1 = 0.0;
  state.m_pLocalLightDesc[0].m_Attenuation2 = 0.0;
  state.m_pLocalLightDesc[0].m_Direction.x = this->m_LightDirection.x;
  state.m_pLocalLightDesc[0].m_Direction.y = this->m_LightDirection.y;
  z = this->m_LightDirection.z;
  state.m_nLocalLightCount = 1;
  state.m_pLocalLightDesc[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  state.m_pLocalLightDesc[0].m_Color.x = v4;
  state.m_pLocalLightDesc[0].m_Color.y = v5;
  state.m_pLocalLightDesc[0].m_Color.z = v6;
  state.m_pLocalLightDesc[0].m_Direction.z = z;
  VectorNormalize(vec: &state.m_pLocalLightDesc[0].m_Direction);
  state.m_pLocalLightDesc[0].m_Theta = 0.0;
  state.m_pLocalLightDesc[0].m_Phi = 0.0;
  state.m_pLocalLightDesc[0].m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: state.m_pLocalLightDesc, a2, a3: (int)this);
  v8 = vgui::MaterialSystem();
  v9 = (int)v8->GetRenderContext(this: v8);
  v10 = v9;
  if ( v9 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
  (*(void (__thiscall **)(int, MaterialLightingState_t *))(*(_DWORD *)v10 + 56))(a1: v10, a2: &state);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 12))(a1: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
}

//------------------------------------------------------------------------------
// Address: 0x104D04E0
// Name: private: void CVMTPreviewPanel::RenderSphere(class Vector const __near &,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::RenderSphere(
        CVMTPreviewPanel *this,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi)
{
  IMaterialSystem *v6; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *m_pObject; // ecx
  bool v9; // al
  IMaterial *m_pMaterial; // ecx
  bool v11; // al
  ITexture *m_pTexture; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  int v17; // ecx
  int v18; // esi
  float v19; // xmm1_4
  double v20; // xmm0_8
  float v21; // xmm0_4
  double v22; // xmm0_8
  double v23; // xmm0_8
  double v24; // xmm0_8
  double v25; // xmm0_8
  float x; // xmm6_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  int v35; // edx
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  int v40; // xmm7_4
  float *m_pCurrPosition; // eax
  int v42; // xmm1_4
  float *v43; // eax
  float *v44; // eax
  float v45; // xmm3_4
  float *v46; // eax
  float *v47; // eax
  float *v48; // eax
  float *v49; // eax
  float *v50; // eax
  float v51; // xmm0_4
  int v52; // ecx
  __int16 v53; // dx
  unsigned int m_nCurrentIndex; // eax
  int v55; // esi
  int v56; // ecx
  bool v57; // zf
  int m_nVertexCount; // eax
  IMatRenderContext *v59; // esi
  long double v60; // [esp+0h] [ebp-258h]
  long double v61; // [esp+0h] [ebp-258h]
  long double v62; // [esp+0h] [ebp-258h]
  long double v63; // [esp+0h] [ebp-258h]
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-250h] BYREF
  Vector vecTangentT; // [esp+1F0h] [ebp-68h]
  int u; // [esp+1FCh] [ebp-5Ch]
  float phi; // [esp+200h] [ebp-58h]
  float v68; // [esp+204h] [ebp-54h]
  Vector vecNormal; // [esp+208h] [ebp-50h] BYREF
  float u1; // [esp+214h] [ebp-44h]
  float v71; // [esp+218h] [ebp-40h]
  float theta; // [esp+21Ch] [ebp-3Ch]
  IMesh *pMesh; // [esp+220h] [ebp-38h]
  CMatRenderContextPtr pRenderContext; // [esp+224h] [ebp-34h]
  Vector vecPos; // [esp+228h] [ebp-30h]
  int v2; // [esp+234h] [ebp-24h]
  int flHalfLuxel; // [esp+238h] [ebp-20h]
  Vector4D vecTangentS; // [esp+23Ch] [ebp-1Ch] BYREF
  int u2; // [esp+24Ch] [ebp-Ch]
  int i; // [esp+250h] [ebp-8h]
  bool bIsUsingLightmap; // [esp+256h] [ebp-2h]
  bool bIsUsingBumpedLightmap; // [esp+257h] [ebp-1h]
  float v; // [esp+260h] [ebp+8h]
  __int16 va; // [esp+260h] [ebp+8h]
  int flRadiusa; // [esp+264h] [ebp+Ch]
  int nPhia; // [esp+26Ch] [ebp+14h]

  u2 = (nTheta + 1) * (2 * nPhi - 2);
  v6 = vgui::MaterialSystem();
  v7 = v6->GetRenderContext(this: v6);
  m_pObject = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
  {
    v7->BeginRender(this: v7);
    m_pObject = pRenderContext.m_pObject;
  }
  pMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLE_STRIP,
    nVertexCount: nPhi * nTheta,
    nIndexCount: u2,
    pMeshSettings: nullptr);
  v9 = this->m_Material.m_pMaterial->GetPropertyFlag(
         this: this->m_Material.m_pMaterial,
         a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP);
  m_pMaterial = this->m_Material.m_pMaterial;
  bIsUsingLightmap = v9;
  v11 = m_pMaterial->GetPropertyFlag(this: m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
  m_pTexture = this->m_pLightmapTexture.m_pTexture;
  bIsUsingBumpedLightmap = v11;
  v13 = m_pTexture->GetActualWidth(this: m_pTexture);
  v14 = nPhi;
  v15 = 0;
  *(float *)&flHalfLuxel = 0.5 / (float)v13;
  i = 0;
  if ( nPhi > 0 )
  {
    do
    {
      v17 = nTheta;
      v18 = 0;
      if ( nTheta > 0 )
      {
        v68 = (float)(nTheta - 1);
        v19 = (float)v15 / (float)(nPhi - 1);
        v = v19;
        while ( 1 )
        {
          *(float *)&u = (float)v18 / v68;
          if ( v18 == v17 - 1 )
            v20 = 0.0;
          else
            v20 = (float)((float)v18 / v68) * 6.283185307179586;
          v21 = v20;
          theta = v21;
          phi = v19 * 3.141592653589793;
          v22 = phi;
          __libm_sse2_sin(x: v60);
          *(float *)&v22 = v22;
          v71 = *(float *)&v22 * flRadius;
          v23 = theta;
          __libm_sse2_cos(x: v61);
          *(float *)&v23 = v23;
          vecPos.x = *(float *)&v23 * v71;
          v24 = theta;
          __libm_sse2_sin(x: v62);
          *(float *)&v24 = v24;
          vecPos.y = *(float *)&v24 * v71;
          v25 = phi;
          __libm_sse2_cos(x: v63);
          *(float *)&v25 = v25;
          vecPos.z = *(float *)&v25 * flRadius;
          *(_QWORD *)&vecNormal.x = *(_QWORD *)&vecPos.x;
          vecNormal.z = *(float *)&v25 * flRadius;
          VectorNormalize(vec: &vecNormal);
          vecTangentS.x = vecPos.z;
          vecTangentS.y = -vecPos.x;
          vecTangentS.z = 0.0;
          vecTangentS.w = 1.0;
          if ( VectorNormalize(vec: (Vector *)&vecTangentS) == 0.0 )
          {
            x = 1.0;
            y = 0.0;
            z = 0.0;
            vecTangentS.x = 1.0;
            vecTangentS.y = 0.0;
            vecTangentS.z = 0.0;
            vecTangentS.w = 1.0;
          }
          else
          {
            z = vecTangentS.z;
            y = vecTangentS.y;
            x = vecTangentS.x;
          }
          v29 = vecNormal.y * z;
          v30 = (float)(vecNormal.z * x) - (float)(z * vecNormal.x);
          v31 = *(float *)&u;
          v32 = vecNormal.z * y;
          v33 = vecNormal.y * x;
          v34 = vCenter->y + vecPos.y;
          vecTangentT.y = v30;
          v35 = (int)(float)(*(float *)&u * 255.0);
          v36 = v;
          vecTangentT.z = (float)(y * vecNormal.x) - v33;
          v37 = vCenter->z + vecPos.z;
          v38 = vCenter->x + vecPos.x;
          v39 = v29 - v32;
          v40 = LODWORD(v);
          u2 = u;
          u1 = *(float *)&u;
          v2 = LODWORD(v);
          if ( bIsUsingLightmap )
          {
            u1 = (float)((float)((float)(0.25 - *(float *)&flHalfLuxel) - *(float *)&flHalfLuxel) * *(float *)&u)
               + *(float *)&flHalfLuxel;
            if ( bIsUsingBumpedLightmap )
            {
              u2 = 1048576000;
              v40 = 0;
            }
            else
            {
              v40 = v2;
            }
            v36 = v;
          }
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v38;
          m_pCurrPosition[1] = v34;
          m_pCurrPosition[2] = v37;
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
          v42 = u2;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)(int)(float)(v * 255.0)
                                                              | (((unsigned __int8)(int)(float)(v * 255.0)
                                                                | (((unsigned __int8)v35
                                                                  | ((unsigned __int8)(int)(float)(v * 255.0) << 8)) << 8)) << 8);
          v43 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v31 * 2.0;
          v43[1] = v36;
          v43[2] = 0.0;
          v43[3] = 0.0;
          v44 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          v45 = u1;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1;
          v44[1] = v36;
          v44[2] = 0.0;
          v44[3] = 0.0;
          v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v42;
          *((_DWORD *)v46 + 1) = v40;
          v46[2] = 0.0;
          v46[3] = 0.0;
          v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v45;
          v47[1] = v36;
          v47[2] = 0.0;
          v47[3] = 0.0;
          v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v42;
          *((_DWORD *)v48 + 1) = v40;
          v48[2] = 0.0;
          v48[3] = 0.0;
          v49 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
          *v49 = vecTangentS.x;
          v49[1] = vecTangentS.y;
          v49[2] = vecTangentS.z;
          v50 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
          v51 = vecTangentT.y;
          *v50 = v39;
          v50[1] = v51;
          v50[2] = vecTangentT.z;
          if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
            *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                     * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
          meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
          *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_UserData) = vecTangentS;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++v18 >= nTheta )
            break;
          v19 = v;
          v17 = nTheta;
        }
        v15 = i;
      }
      i = ++v15;
    }
    while ( v15 < nPhi );
    v14 = nPhi;
  }
  v52 = 0;
  v53 = 0;
  i = 0;
  flHalfLuxel = v14 - 1;
  if ( v14 - 1 > 0 )
  {
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    v2 = v14 - 2;
    v55 = 0;
    flRadiusa = 0;
    do
    {
      if ( nTheta > 0 )
      {
        v56 = v55;
        nPhia = nTheta;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v56
                                                                 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                            + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                            + v56;
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          va = v56++;
          v57 = nPhia-- == 1;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( !v57 );
        v52 = i;
        v53 = va;
      }
      if ( v52 < v2 )
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                               + v53
                                                               + 1;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                          + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                          + v53
                                                                                          + 1;
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      v55 = nTheta + flRadiusa;
      i = ++v52;
      flRadiusa += nTheta;
    }
    while ( v52 < flHalfLuxel );
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
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
  v59 = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  v59->Release(this: v59);
}

//------------------------------------------------------------------------------
// Address: 0x104D0C60
// Name: private: void CVMTPreviewPanel::RenderSheet(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::RenderSheet(CVMTPreviewPanel *this, const Vector *vCenter, float flRadius)
{
  IMaterialSystem *v4; // eax
  int v5; // eax
  int v6; // esi
  IMesh *v7; // ebx
  double SequenceTimeSpan; // st6
  __int64 v9; // [esp+8h] [ebp-24h]
  int v10; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+20h] [ebp-Ch]
  int v12; // [esp+24h] [ebp-8h]
  int v13; // [esp+28h] [ebp-4h]
  float v14; // [esp+28h] [ebp-4h]
  int _2C; // [esp+2Ch] [ebp+0h]

  v4 = vgui::MaterialSystem();
  v5 = (int)v4->GetRenderContext(this: v4);
  v6 = v5;
  if ( v5 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
  v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                  a1: v6,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0);
  if ( CSheetExtended::ValidSheetData(this: this->m_pMaterialSheet) )
  {
    v14 = _Plat_FloatTime(a1: v10, a2: v11, a3: v12, a4: v13, a5: _2C) - this->m_flLastSwitchTime;
    SequenceTimeSpan = CSheetExtended::GetSequenceTimeSpan(
                         this: this->m_pMaterialSheet,
                         nSequenceIndex: this->m_nCurrentSheetSequence);
    HIDWORD(v9) = LODWORD(this->m_flSheetPreviewSpeed);
    *(float *)&v9 = fmod(v14, SequenceTimeSpan);
    CSheetExtended::DrawSheet(
      this: this->m_pMaterialSheet,
      pMesh: v7,
      vCenter,
      flRadius,
      nSheetSequence: this->m_nCurrentSheetSequence,
      flAge: v9,
      bLoopSheetPreview: true,
      nSecondarySequence: this->m_nCurrentSecondarySheetSequence,
      bOverrideSpriteCard: false);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x104D0D40
// Name: private: void CVMTPreviewPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVMTPreviewPanel::LookAt(
        CVMTPreviewPanel *this@<ecx>,
        double a2@<esi:edi>,
        const Vector *vecLookAt,
        float flRadius)
{
  int v5; // edi
  double v6; // xmm0_8
  float v7; // xmm0_4
  float z; // edx
  Vector *p_m_vecCameraDirection; // edi
  float v10; // xmm0_4
  IMaterialSystem *v11; // eax
  int v12; // eax
  int v13; // esi
  void (__thiscall *v14)(int, int, int); // eax
  long double v15; // [esp+10h] [ebp-38h]
  int v16; // [esp+10h] [ebp-38h]
  int v17; // [esp+14h] [ebp-34h]
  QAngle v18; // [esp+18h] [ebp-30h] BYREF
  __int64 v19; // [esp+24h] [ebp-24h]
  float v20; // [esp+2Ch] [ebp-1Ch]
  float v21; // [esp+30h] [ebp-18h]
  float v22; // [esp+34h] [ebp-14h]
  float v23; // [esp+38h] [ebp-10h]
  int v24; // [esp+3Ch] [ebp-Ch]
  int tall; // [esp+40h] [ebp-8h] BYREF
  int wide; // [esp+44h] [ebp-4h] BYREF

  v15 = a2;
  *(float *)&v24 = 0.78539819;
  vgui::Panel::GetSize(this, &wide, &tall);
  v5 = tall;
  if ( tall >= wide )
  {
    v7 = *(float *)&v24;
  }
  else
  {
    __libm_sse2_tan(x: v15);
    v6 = (float)((float)((float)0.7853981633974483 * (float)v5) / (float)wide);
    __libm_sse2_atan();
    v7 = v6;
  }
  z = vecLookAt->z;
  v19 = *(_QWORD *)&vecLookAt->x;
  v20 = z;
  p_m_vecCameraDirection = &this->m_vecCameraDirection;
  __libm_sse2_sin(x: v15);
  LODWORD(v10) = COERCE_UNSIGNED_INT(flRadius / v7) ^ _mask__NegFloat_;
  v21 = (float)(this->m_vecCameraDirection.x * v10) + *(float *)&v19;
  v22 = (float)(this->m_vecCameraDirection.y * v10) + *((float *)&v19 + 1);
  v23 = (float)(this->m_vecCameraDirection.z * v10) + v20;
  v11 = vgui::MaterialSystem();
  v12 = ((int (__thiscall *)(IMaterialSystem *, int, int))v11->GetRenderContext)(a1: v11, a2: v16, a3: v17);
  v13 = v12;
  if ( v12 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 8))(a1: v12);
  VectorAngles(a1: v13, forward: p_m_vecCameraDirection, angles: &v18);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v13 + 80))(
    a1: v13,
    a2: 0,
    a3: LODWORD(v18.x),
    a4: LODWORD(v18.y));
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 124))(a1: v13);
  v14 = *(void (__thiscall **)(int, int, int))(*(_DWORD *)v13 + 140);
  v18.y = 0.0;
  v18.x = 0.0;
  v14(a1: v13, a2: -1028390912, a3: 1065353216);
  (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)v13 + 140))(
    a1: v13,
    a2: 1119092736,
    a3: 0,
    a4: 0,
    a5: 1065353216);
  (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v13 + 140))(
    a1: v13,
    a2: LODWORD(v18.z) ^ _mask__NegFloat_,
    a3: 1065353216,
    a4: 0,
    a5: 0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v13 + 140))(
    a1: v13,
    a2: LODWORD(v18.x) ^ _mask__NegFloat_,
    a3: 0,
    a4: 1065353216,
    a5: 0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v13 + 140))(
    a1: v13,
    a2: LODWORD(v18.y) ^ _mask__NegFloat_,
    a3: 0,
    a4: 0,
    a5: 1065353216);
  (*(void (__thiscall **)(int, _DWORD, unsigned int, _DWORD))(*(_DWORD *)v13 + 144))(
    a1: v13,
    a2: -v21,
    a3: LODWORD(v22) ^ 0x80000000,
    a4: -v23);
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 12))(a1: v13);
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 4))(a1: v13);
}

//------------------------------------------------------------------------------
// Address: 0x104D0FE0
// Name: private: void CVMTPreviewPanel::SetupProjectionMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CVMTPreviewPanel::SetupProjectionMatrix(
        CVMTPreviewPanel *this@<ecx>,
        int a2@<esi>,
        int nWidth,
        int nHeight)
{
  float v4; // xmm0_4
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // esi
  _BYTE v8[68]; // [esp-4h] [ebp-44h] OVERLAPPED BYREF

  if ( (float)nHeight == 0.0 )
    v4 = 100.0;
  else
    v4 = (float)nWidth / (float)nHeight;
  *(_DWORD *)v8 = a2;
  __libm_sse2_tan(x: *(long double *)v8);
  memset(dst: &v8[4], value: 0, count: 0x40u);
  *(float *)&v8[24] = 1.0 / (float)((float)0.7853981633974483 / v4);
  *(_QWORD *)&v8[44] = 0xBDCCCF6CBF8001A3uLL;
  *(_DWORD *)&v8[60] = -1082130432;
  *(float *)&v8[4] = 1.0 / (float)0.7853981633974483;
  v5 = vgui::MaterialSystem();
  v6 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v5->GetRenderContext)(
         a1: v5,
         a2: *(_DWORD *)v8,
         a3: *(_DWORD *)&v8[4],
         a4: *(_DWORD *)&v8[8],
         a5: *(_DWORD *)&v8[12],
         a6: *(_DWORD *)&v8[16],
         a7: *(_DWORD *)&v8[20],
         a8: *(_DWORD *)&v8[24],
         a9: *(_DWORD *)&v8[28],
         a10: *(_DWORD *)&v8[32],
         a11: *(_DWORD *)&v8[36],
         a12: *(_DWORD *)&v8[40],
         a13: *(_DWORD *)&v8[44],
         a14: *(_DWORD *)&v8[48],
         a15: *(_DWORD *)&v8[52],
         a16: *(_DWORD *)&v8[56],
         a17: *(_DWORD *)&v8[60],
         a18: *(_DWORD *)&v8[64]);
  v7 = v6;
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 80))(a1: v7, a2: 1);
  (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v7 + 96))(a1: v7, a2: &v8[4]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x104D10E0
// Name: private: void CVMTPreviewPanel::SetupOrthoMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetupOrthoMatrix(CVMTPreviewPanel *this, int nWidth, int nHeight)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = vgui::MaterialSystem();
  v4 = (int)v3->GetRenderContext(this: v3);
  v5 = v4;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 124))(a1: v5);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v5 + 128))(
    a1: v5,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0,
    a6: COERCE_UNSIGNED_INT64((double)nWidth),
    a7: HIDWORD(COERCE_UNSIGNED_INT64((double)nWidth)),
    a8: COERCE_UNSIGNED_INT64((double)nHeight),
    a9: HIDWORD(COERCE_UNSIGNED_INT64((double)nHeight)),
    a10: 0,
    a11: -1074790400,
    a12: 0,
    a13: 1072693248);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x104D1190
// Name: private: void CVMTPreviewPanel::DrawRectangle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawRectangle(CVMTPreviewPanel *this)
{
  int v2; // eax
  IMaterial *m_pMaterial; // ecx
  int v4; // esi
  int (__thiscall *GetMappingHeight)(IMaterial *); // edx
  int v6; // eax
  IMaterialSystem *v7; // eax
  int v8; // eax
  int v9; // esi
  IMesh *v10; // ebx
  bool v11; // al
  IMaterial *v12; // ecx
  IMaterial_vtbl *v13; // edx
  bool v14; // al
  ITexture *m_pTexture; // ecx
  ITexture_vtbl *v16; // edx
  int v17; // eax
  int v18; // edx
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  int v22; // edi
  int v23; // ecx
  float v24; // xmm4_4
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  float v28; // xmm4_4
  __int64 v29; // rax
  int v30; // ecx
  int v31; // edi
  int v32; // ebx
  int v33; // xmm6_4
  float v34; // xmm4_4
  float v35; // xmm3_4
  int v36; // edx
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // eax
  float *v39; // eax
  float *v40; // eax
  float *v41; // eax
  int v42; // xmm2_4
  float *v43; // eax
  float *v44; // eax
  float *v45; // eax
  float *v46; // eax
  float *v47; // eax
  _DWORD *v48; // eax
  _DWORD *v49; // eax
  __int64 v50; // xmm0_8
  _QWORD *v51; // eax
  float *v52; // eax
  float x; // xmm1_4
  float v54; // xmm2_4
  int v55; // xmm4_4
  float v56; // xmm5_4
  float *v57; // eax
  float *v58; // eax
  float *v59; // eax
  float v60; // xmm1_4
  float *v61; // eax
  float *v62; // eax
  float *v63; // eax
  float *v64; // eax
  float *v65; // eax
  float *v66; // eax
  _DWORD *v67; // eax
  _DWORD *v68; // eax
  __int64 v69; // xmm0_8
  _QWORD *v70; // eax
  float *v71; // eax
  int v72; // xmm1_4
  float v73; // xmm2_4
  float v74; // xmm4_4
  int v75; // xmm5_4
  float *v76; // eax
  float *v77; // eax
  float *v78; // eax
  float v79; // xmm1_4
  float *v80; // eax
  float *v81; // eax
  float *v82; // eax
  float *v83; // eax
  float *v84; // eax
  float *v85; // eax
  _DWORD *v86; // eax
  _DWORD *v87; // eax
  __int64 v88; // xmm0_8
  _QWORD *v89; // eax
  float *v90; // eax
  float *v91; // eax
  float *v92; // eax
  float *v93; // eax
  float v94; // xmm2_4
  float v95; // xmm1_4
  float *v96; // eax
  float v97; // xmm4_4
  float v98; // xmm5_4
  float *v99; // eax
  float *v100; // eax
  float *v101; // eax
  float *v102; // eax
  float *v103; // eax
  _DWORD *v104; // eax
  _DWORD *v105; // eax
  __int64 v106; // xmm0_8
  _QWORD *v107; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-244h] BYREF
  float v109; // [esp+1F0h] [ebp-5Ch]
  float v110; // [esp+1F4h] [ebp-58h]
  Vector2D halfTexel; // [esp+1F8h] [ebp-54h]
  IMesh *pMesh; // [esp+200h] [ebp-4Ch]
  float v1_t; // [esp+204h] [ebp-48h]
  Vector4D vecTangentS; // [esp+208h] [ebp-44h]
  float u1_l; // [esp+218h] [ebp-34h]
  float v2_b; // [esp+21Ch] [ebp-30h]
  float v1_b; // [esp+220h] [ebp-2Ch]
  float u2_r; // [esp+224h] [ebp-28h]
  float u1_r; // [esp+228h] [ebp-24h]
  int th; // [esp+22Ch] [ebp-20h]
  int w; // [esp+230h] [ebp-1Ch] BYREF
  float flHalfLuxel; // [esp+234h] [ebp-18h]
  bool bIsUsingBumpedLightmap; // [esp+23Ah] [ebp-12h]
  bool bIsUsingLightmap; // [esp+23Bh] [ebp-11h]
  int h; // [esp+23Ch] [ebp-10h] BYREF
  int nYBorder; // [esp+240h] [ebp-Ch]
  int v2_t; // [esp+244h] [ebp-8h]
  int usewide; // [esp+248h] [ebp-4h]

  *(float *)&v2 = COERCE_FLOAT(this->m_Material.m_pMaterial->GetMappingWidth(this: this->m_Material.m_pMaterial));
  m_pMaterial = this->m_Material.m_pMaterial;
  v4 = v2;
  GetMappingHeight = m_pMaterial->GetMappingHeight;
  usewide = v2;
  *(float *)&v6 = COERCE_FLOAT(GetMappingHeight(this: m_pMaterial));
  th = v6;
  if ( v4 > 0 && v6 > 0 )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    if ( w != 0 && h != 0 )
    {
      CVMTPreviewPanel::SetupOrthoMatrix(this, nWidth: w, nHeight: h);
      CVMTPreviewPanel::SetupLightingState(this, a2: (int)this);
      v7 = vgui::MaterialSystem();
      v8 = (int)v7->GetRenderContext(this: v7);
      v9 = v8;
      if ( v8 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 80))(a1: v9, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 80))(a1: v9, a2: 10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9);
      v10 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 228))(
                       a1: v9,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
      pMesh = v10;
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh: v10,
        type: MATERIAL_TRIANGLE_STRIP,
        nVertexCount: 4,
        nIndexCount: 4,
        pMeshSettings: nullptr);
      v11 = this->m_Material.m_pMaterial->GetPropertyFlag(
              this: this->m_Material.m_pMaterial,
              a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP);
      v12 = this->m_Material.m_pMaterial;
      v13 = v12->__vftable;
      bIsUsingLightmap = v11;
      v14 = v13->GetPropertyFlag(this: v12, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
      m_pTexture = this->m_pLightmapTexture.m_pTexture;
      v16 = m_pTexture->__vftable;
      bIsUsingBumpedLightmap = v14;
      v17 = v16->GetActualWidth(this: m_pTexture);
      v18 = h;
      v19 = 0.5 / (float)th;
      flHalfLuxel = 0.5 / (float)v17;
      v20 = 0.5 / (float)usewide;
      halfTexel.x = v20;
      halfTexel.y = v19;
      vecTangentS.x = 1.0;
      vecTangentS.y = 0.0;
      vecTangentS.z = 0.0;
      vecTangentS.w = 1.0;
      v21 = (float)usewide / (float)th;
      v22 = 0;
      v23 = 0;
      v24 = v21 / (float)((float)w / (float)h);
      if ( w <= 15 )
      {
        v18 = h;
        v2_t = w / 3;
      }
      else
      {
        v2_t = 5;
      }
      if ( v18 <= 15 )
      {
        v25 = v18 / 3;
        v18 = h;
        nYBorder = v25;
      }
      else
      {
        nYBorder = 5;
      }
      v26 = w - 2 * v2_t;
      v27 = v18 - 2 * nYBorder;
      w = v26;
      h = v27;
      if ( v24 <= 1.0 )
      {
        v28 = (float)v27 * v21;
        v29 = v26 - (int)v28;
        usewide = (int)v28;
        v26 = (int)v28;
        v23 = ((int)v29 - HIDWORD(v29)) >> 1;
        w = (int)v28;
      }
      else
      {
        usewide = (int)(float)((float)v26 / v21);
        v22 = (v27 - usewide) / 2;
        h = usewide;
      }
      v30 = v2_t + v23;
      v31 = nYBorder + v22;
      v32 = v30 + v26;
      *(float *)&th = 1.0 - v20;
      u2_r = 1.0 - v20;
      u1_r = 1.0 - v20;
      v33 = LODWORD(v20);
      v34 = v20;
      v35 = v19;
      v36 = v31 + h;
      nYBorder = LODWORD(v20);
      u1_l = v20;
      v2_t = LODWORD(v19);
      v1_t = v19;
      *(float *)&usewide = 1.0 - v19;
      v2_b = 1.0 - v19;
      v1_b = 1.0 - v19;
      if ( bIsUsingLightmap )
      {
        v35 = flHalfLuxel;
        v34 = flHalfLuxel;
        v1_t = flHalfLuxel;
        u1_l = flHalfLuxel;
        v1_b = 0.25 - flHalfLuxel;
        u1_r = 0.25 - flHalfLuxel;
        if ( bIsUsingBumpedLightmap )
        {
          v33 = 1048576000;
          u2_r = 0.25;
          nYBorder = 1048576000;
          v2_b = 0.0;
          v2_t = 0;
        }
        else
        {
          v33 = nYBorder;
        }
      }
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v30;
      flHalfLuxel = (float)v30;
      m_pCurrPosition[1] = (float)v36;
      m_pCurrPosition[2] = 0.0;
      m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      m_pCurrNormal[1] = 0.0;
      m_pCurrNormal[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v20;
      v39[1] = v19;
      v39[2] = 0.0;
      v39[3] = 0.0;
      v40 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v34;
      v40[1] = v35;
      v40[2] = 0.0;
      v40[3] = 0.0;
      v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v33;
      v42 = v2_t;
      *((_DWORD *)v41 + 1) = v2_t;
      v41[2] = 0.0;
      v41[3] = 0.0;
      v43 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v34;
      v43[1] = v35;
      v43[2] = 0.0;
      v43[3] = 0.0;
      v44 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v33;
      *((_DWORD *)v44 + 1) = v42;
      v44[2] = 0.0;
      v44[3] = 0.0;
      v45 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v34;
      v45[1] = v35;
      v45[2] = 0.0;
      v45[3] = 0.0;
      v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v33;
      *((_DWORD *)v46 + 1) = v42;
      v46[2] = 0.0;
      v46[3] = 0.0;
      v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v34;
      v47[1] = v35;
      v47[2] = 0.0;
      v47[3] = 0.0;
      v48 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      v109 = (float)v36;
      *v48 = 1065353216;
      v48[1] = 0;
      v48[2] = 0;
      v49 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v49 = 0;
      v49[1] = 1065353216;
      v49[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v50 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v51 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v51 = v50;
      v51[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v52 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = flHalfLuxel;
      x = halfTexel.x;
      v54 = v1_b;
      v55 = nYBorder;
      v56 = v2_b;
      v52[1] = (float)v31;
      v110 = (float)v31;
      v52[2] = 0.0;
      v57 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v57[1] = 0.0;
      v57[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v58 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = x;
      v58[1] = *(float *)&usewide;
      v58[2] = 0.0;
      v58[3] = 0.0;
      v59 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v60 = u1_l;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1_l;
      v59[1] = v54;
      v59[2] = 0.0;
      v59[3] = 0.0;
      v61 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v55;
      v61[1] = v56;
      v61[2] = 0.0;
      v61[3] = 0.0;
      v62 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v60;
      v62[1] = v54;
      v62[2] = 0.0;
      v62[3] = 0.0;
      v63 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v55;
      v63[1] = v56;
      v63[2] = 0.0;
      v63[3] = 0.0;
      v64 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v60;
      v64[1] = v54;
      v64[2] = 0.0;
      v64[3] = 0.0;
      v65 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v55;
      v65[1] = v56;
      v65[2] = 0.0;
      v65[3] = 0.0;
      v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v60;
      v66[1] = v54;
      v66[2] = 0.0;
      v66[3] = 0.0;
      v67 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v67 = 1065353216;
      v67[1] = 0;
      v67[2] = 0;
      v68 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v68 = 0;
      v68[1] = 1065353216;
      v68[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v69 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v70 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v70 = v69;
      v70[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v71 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v72 = th;
      v73 = u1_r;
      v74 = u2_r;
      v75 = v2_t;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v32;
      flHalfLuxel = (float)v32;
      v71[1] = v109;
      v71[2] = 0.0;
      v76 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v76[1] = 0.0;
      v76[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v77 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v72;
      v77[1] = halfTexel.y;
      v77[2] = 0.0;
      v77[3] = 0.0;
      v78 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v73;
      v79 = v1_t;
      v78[1] = v1_t;
      v78[2] = 0.0;
      v78[3] = 0.0;
      v80 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v74;
      *((_DWORD *)v80 + 1) = v75;
      v80[2] = 0.0;
      v80[3] = 0.0;
      v81 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v73;
      v81[1] = v79;
      v81[2] = 0.0;
      v81[3] = 0.0;
      v82 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v74;
      *((_DWORD *)v82 + 1) = v75;
      v82[2] = 0.0;
      v82[3] = 0.0;
      v83 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v73;
      v83[1] = v79;
      v83[2] = 0.0;
      v83[3] = 0.0;
      v84 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v74;
      *((_DWORD *)v84 + 1) = v75;
      v84[2] = 0.0;
      v84[3] = 0.0;
      v85 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v73;
      v85[1] = v79;
      v85[2] = 0.0;
      v85[3] = 0.0;
      v86 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v86 = 1065353216;
      v86[1] = 0;
      v86[2] = 0;
      v87 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v87 = 0;
      v87[1] = 1065353216;
      v87[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v88 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v89 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v89 = v88;
      v89[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v90 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = flHalfLuxel;
      v90[1] = v110;
      v90[2] = 0.0;
      v91 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v91[1] = 0.0;
      v91[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v92 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(float *)&th;
      v92[1] = *(float *)&usewide;
      v92[2] = 0.0;
      v92[3] = 0.0;
      v93 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v94 = u1_r;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1_r;
      v95 = v1_b;
      v93[1] = v1_b;
      v93[2] = 0.0;
      v93[3] = 0.0;
      v96 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      v97 = u2_r;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = u2_r;
      v98 = v2_b;
      v96[1] = v2_b;
      v96[2] = 0.0;
      v96[3] = 0.0;
      v99 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v94;
      v99[1] = v95;
      v99[2] = 0.0;
      v99[3] = 0.0;
      v100 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v97;
      v100[1] = v98;
      v100[2] = 0.0;
      v100[3] = 0.0;
      v101 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v94;
      v101[1] = v95;
      v101[2] = 0.0;
      v101[3] = 0.0;
      v102 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v97;
      v102[1] = v98;
      v102[2] = 0.0;
      v102[3] = 0.0;
      v103 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v94;
      v103[1] = v95;
      v103[2] = 0.0;
      v103[3] = 0.0;
      v104 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v104 = 1065353216;
      v104[1] = 0;
      v104[2] = 0;
      v105 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v105 = 0;
      v105[1] = 1065353216;
      v105[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v106 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v107 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v107 = v106;
      v107[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 1;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 2;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 3;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      CMeshBuilder::End(this: &meshBuilder, bSpewData: false, bDraw: false);
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D1CA0
// Name: private: void CVMTPreviewPanel::DrawSphere(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawSphere(CVMTPreviewPanel *this)
{
  double v1; // st7
  double v2; // rdi
  double z; // st7
  CSheetExtended *v4; // ecx
  float v5; // [esp+8h] [ebp-64h]
  int flRadius; // [esp+Ch] [ebp-60h]
  int v7; // [esp+10h] [ebp-5Ch]
  _DWORD angleDegrees[3]; // [esp+14h] [ebp-58h] BYREF
  VMatrix rot; // [esp+20h] [ebp-4Ch] BYREF
  Vector vecTemp; // [esp+60h] [ebp-Ch] BYREF

  HIDWORD(v2) = this;
  v1 = _Plat_FloatTime(a1: flRadius, a2: v7, a3: angleDegrees[0], a4: angleDegrees[1], a5: angleDegrees[2]);
  vecTemp.z = v1;
  v5 = (v1 - *(float *)(HIDWORD(v2) + 400)) * 40.0;
  MatrixBuildRotateZ(dst: (VMatrix *)angleDegrees, angleDegrees: v5);
  LODWORD(v2) = HIDWORD(v2) + 388;
  Vector3DMultiply(
    src1: (const VMatrix *)angleDegrees,
    src2: (Vector *)(HIDWORD(v2) + 388),
    dst: (Vector *)&rot.m[3][1]);
  z = vecTemp.z;
  *(Vector *)(HIDWORD(v2) + 388) = *(Vector *)&rot.m[3][1];
  *(float *)(HIDWORD(v2) + 400) = z;
  vgui::Panel::GetSize(this: (vgui::Panel *)HIDWORD(v2), wide: (int *)&vecTemp, tall: (int *)&vecTemp.y);
  CVMTPreviewPanel::SetupProjectionMatrix(
    this: (CVMTPreviewPanel *)HIDWORD(v2),
    a2: SHIDWORD(v2),
    nWidth: SLODWORD(vecTemp.x),
    nHeight: SLODWORD(vecTemp.y));
  CVMTPreviewPanel::SetupLightingState(this: (CVMTPreviewPanel *)HIDWORD(v2), a2: HIDWORD(v2) + 388);
  CVMTPreviewPanel::LookAt(this: (CVMTPreviewPanel *)HIDWORD(v2), a2: v2, vecLookAt: &vec3_origin, flRadius: 12.0);
  v4 = *(CSheetExtended **)(HIDWORD(v2) + 356);
  if ( v4 != nullptr && CSheetExtended::ValidSheetData(this: v4) )
    CVMTPreviewPanel::RenderSheet(this: (CVMTPreviewPanel *)HIDWORD(v2), vCenter: &vec3_origin, flRadius: 10.0);
  else
    CVMTPreviewPanel::RenderSphere(
      this: (CVMTPreviewPanel *)HIDWORD(v2),
      vCenter: &vec3_origin,
      flRadius: 10.0,
      nTheta: 20,
      nPhi: 20);
}

//------------------------------------------------------------------------------
// Address: 0x104D1DA0
// Name: public: virtual void CVMTPreviewPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::Paint(CVMTPreviewPanel *this)
{
  IMaterialSystem *v2; // eax
  int v3; // eax
  int v4; // esi
  IMatSystemSurface *v5; // eax
  ITexture *m_pTexture; // ecx
  IMaterialSystem *v7; // eax
  ITexture *v8; // eax
  ITexture *v9; // ebx
  IMatSystemSurface *v10; // eax
  int w; // [esp+8h] [ebp-8h] BYREF
  int h; // [esp+Ch] [ebp-4h] BYREF

  v2 = vgui::MaterialSystem();
  v3 = (int)v2->GetRenderContext(this: v2);
  v4 = v3;
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v5 = vgui::MatSystemSurface();
  v5->Begin3DPaint(this: v5, a2: 0, a3: 0, a4: w, a5: h);
  if ( this->m_Material.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(this: this->m_Material.m_pMaterial, a2: true) )
  {
    m_pTexture = s_pPowerOfTwoFrameBufferTexture.m_pTexture;
    if ( s_pPowerOfTwoFrameBufferTexture.m_pTexture == nullptr )
    {
      v7 = vgui::MaterialSystem();
      v8 = v7->FindTexture(this: v7, a2: "_rt_PowerOfTwoFB", a3: "RenderTargets", a4: true, a5: 0);
      CTextureReference::Init(this: &s_pPowerOfTwoFrameBufferTexture, pTexture: v8);
      m_pTexture = s_pPowerOfTwoFrameBufferTexture.m_pTexture;
    }
    v9 = m_pTexture;
    if ( m_pTexture != nullptr && !m_pTexture->IsError(this: m_pTexture) )
    {
      (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 68))(a1: v4, a2: v9);
      (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v4 + 72))(a1: v4, a2: v9, a3: 0);
    }
  }
  (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v4 + 296))(a1: v4, a2: 76, a3: 88, a4: 68, a5: 255);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v4 + 48))(a1: v4, a2: 1, a3: 1, a4: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 176))(a1: v4, a2: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 216))(a1: v4, a2: 0);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
    a1: v4,
    a2: this->m_Material.m_pMaterial,
    a3: 0);
  (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 448))(a1: v4, a2: this->m_pLightmapTexture.m_pTexture);
  (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 20))(a1: v4, a2: this->m_DefaultEnvCubemap.m_pTexture);
  if ( this->m_bDrawIn3DMode )
    CVMTPreviewPanel::DrawSphere(this);
  else
    CVMTPreviewPanel::DrawRectangle(this);
  v10 = vgui::MatSystemSurface();
  v10->End3DPaint(this: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104D1F30
// Name: public: CVMTPreviewPanel::CVMTPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x104D2100
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPreviewPanel::GetMessageMap(CVMTPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CVMTPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewPanel");
  `CVMTPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D2130
// Name: public: virtual struct PanelAnimationMap __near * CVMTPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPreviewPanel::GetAnimMap(CVMTPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104D2140
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPreviewPanel::GetKBMap(CVMTPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CVMTPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewPanel");
  `CVMTPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D2170
// Name: public: virtual CVMTPreviewPanel::~CVMTPreviewPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::~CVMTPreviewPanel(CVMTPreviewPanel *this)
{
  bool v2; // sf

  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_pLightmapTexture);
  CMaterialReference::~CMaterialReference(this: &this->m_Material);
  v2 = this->m_VMTName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_VMTName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_VMTName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VMTName.m_Storage.m_Memory.m_pMemory);
      this->m_VMTName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_VMTName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004E58D0
// Name: public: static char const __near * CVMTPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPreviewPanel::GetPanelClassName()
{
  return "CVMTPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004E58E0
// Name: public: void CVMTPreviewPanel::SetSheetPreviewSpeed(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSheetPreviewSpeed(CVMTPreviewPanel *this, float flPreviewSpeed)
{
  this->m_flSheetPreviewSpeed = flPreviewSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x004E5900
// Name: public: void CVMTPreviewPanel::DrawIn3DMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawIn3DMode(CVMTPreviewPanel *this, bool b3DMode)
{
  this->m_bDrawIn3DMode = b3DMode;
}

//------------------------------------------------------------------------------
// Address: 0x004E5910
// Name: public: int CVMTPreviewPanel::GetSheetSequenceCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMTPreviewPanel::GetSheetSequenceCount(CVMTPreviewPanel *this)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    return CSheetExtended::GetSheetSequenceCount(this: m_pMaterialSheet);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E5930
// Name: public: int CVMTPreviewPanel::GetRealSequenceNumber(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMTPreviewPanel::GetRealSequenceNumber(CVMTPreviewPanel *this)
{
  return this->m_nCurrentSheetSequence;
}

//------------------------------------------------------------------------------
// Address: 0x004E5940
// Name: public: int CVMTPreviewPanel::GetCurrentSecondarySequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMTPreviewPanel::GetCurrentSecondarySequence(CVMTPreviewPanel *this)
{
  return this->m_nCurrentSecondarySheetSequence;
}

//------------------------------------------------------------------------------
// Address: 0x004E5950
// Name: public: void CVMTPreviewPanel::SetSheetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSheetSequence(CVMTPreviewPanel *this, int nSequence)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    this->m_nCurrentSheetSequence = CSheetExtended::GetNthSequenceIndex(
                                      this: m_pMaterialSheet,
                                      nSequenceNumber: nSequence);
}

//------------------------------------------------------------------------------
// Address: 0x004E5980
// Name: public: void CVMTPreviewPanel::SetSecondarySheetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetSecondarySheetSequence(CVMTPreviewPanel *this, int nSequence)
{
  CSheetExtended *m_pMaterialSheet; // ecx

  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
    this->m_nCurrentSecondarySheetSequence = CSheetExtended::GetNthSequenceIndex(
                                               this: m_pMaterialSheet,
                                               nSequenceNumber: nSequence);
}

//------------------------------------------------------------------------------
// Address: 0x004E59B0
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int,int,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(
        CMeshBuilder *this,
        IMesh *pMesh,
        MaterialPrimitiveType_t type,
        int nVertexCount,
        int nIndexCount,
        MeshBuffersAllocationSettings_t *pMeshSettings)
{
  this->m_Type = type;
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->SetPrimitiveType(this: pMesh, a2: type);
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: nVertexCount, a3: nIndexCount, a4: this, a5: pMeshSettings);
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: nVertexCount, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x004E5A70
// Name: public: void CVMTPreviewPanel::SetVMT(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetVMT(CVMTPreviewPanel *this, const char *pMaterialName)
{
  CSheetExtended *m_pMaterialSheet; // edi
  CSheetExtended *v4; // eax
  CSheetExtended *v5; // eax

  CMaterialReference::Init(
    this: &this->m_Material,
    pMaterialName,
    pTextureGroupName: "editor material",
    bComplain: true);
  CUtlString::operator=(this: &this->m_VMTName, src: pMaterialName);
  this->m_flLastSwitchTime = _Plat_FloatTime();
  m_pMaterialSheet = this->m_pMaterialSheet;
  if ( m_pMaterialSheet != nullptr )
  {
    CSheetExtended::~CSheetExtended(this: this->m_pMaterialSheet);
    free(pMem: m_pMaterialSheet);
  }
  if ( this->m_bDrawIn3DMode )
  {
    v4 = (CSheetExtended *)MemAlloc_Alloc(nSize: 8u);
    if ( v4 != nullptr )
    {
      v5 = CSheetExtended::CSheetExtended(this: v4, pMaterial: this->m_Material.m_pMaterial);
      this->m_nCurrentSheetSequence = 0;
      this->m_nCurrentSecondarySheetSequence = 0;
      this->m_pMaterialSheet = v5;
    }
    else
    {
      this->m_nCurrentSheetSequence = 0;
      this->m_nCurrentSecondarySheetSequence = 0;
      this->m_pMaterialSheet = nullptr;
    }
  }
  else
  {
    this->m_nCurrentSheetSequence = 0;
    this->m_nCurrentSecondarySheetSequence = 0;
    this->m_pMaterialSheet = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E5B40
// Name: private: void CVMTPreviewPanel::SetupLightingState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetupLightingState(CVMTPreviewPanel *this)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float z; // xmm0_4
  IMaterialSystem *v7; // eax
  int v8; // eax
  int v9; // esi
  MaterialLightingState_t state; // [esp+4h] [ebp-1B8h] BYREF

  memset(dst: (unsigned __int8 *)&state, value: 0, count: sizeof(state));
  v2 = this->m_flLightIntensity * 0.0039215689;
  v3 = (float)this->m_LightColor._color[0] * v2;
  v4 = (float)this->m_LightColor._color[1] * v2;
  v5 = (float)this->m_LightColor._color[2] * v2;
  state.m_pLocalLightDesc[0].m_Attenuation0 = 1.0;
  state.m_pLocalLightDesc[0].m_Attenuation1 = 0.0;
  state.m_pLocalLightDesc[0].m_Attenuation2 = 0.0;
  state.m_pLocalLightDesc[0].m_Direction.x = this->m_LightDirection.x;
  state.m_pLocalLightDesc[0].m_Direction.y = this->m_LightDirection.y;
  z = this->m_LightDirection.z;
  state.m_nLocalLightCount = 1;
  state.m_pLocalLightDesc[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  state.m_pLocalLightDesc[0].m_Color.x = v3;
  state.m_pLocalLightDesc[0].m_Color.y = v4;
  state.m_pLocalLightDesc[0].m_Color.z = v5;
  state.m_pLocalLightDesc[0].m_Direction.z = z;
  VectorNormalize(vec: &state.m_pLocalLightDesc[0].m_Direction);
  state.m_pLocalLightDesc[0].m_Theta = 0.0;
  state.m_pLocalLightDesc[0].m_Phi = 0.0;
  state.m_pLocalLightDesc[0].m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: state.m_pLocalLightDesc);
  v7 = vgui::MaterialSystem();
  v8 = (int)v7->GetRenderContext(this: v7);
  v9 = v8;
  if ( v8 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
  (*(void (__thiscall **)(int, MaterialLightingState_t *))(*(_DWORD *)v9 + 56))(a1: v9, a2: &state);
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
}

//------------------------------------------------------------------------------
// Address: 0x004E5CB0
// Name: private: void CVMTPreviewPanel::RenderSphere(class Vector const __near &,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::RenderSphere(
        CVMTPreviewPanel *this,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi)
{
  IMaterialSystem *v6; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *m_pObject; // ecx
  bool v9; // al
  IMaterial *m_pMaterial; // ecx
  bool v11; // al
  ITexture *m_pTexture; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  int v17; // ecx
  int v18; // esi
  float v19; // xmm1_4
  double v20; // xmm0_8
  float v21; // xmm0_4
  double v22; // xmm0_8
  double v23; // xmm0_8
  double v24; // xmm0_8
  double v25; // xmm0_8
  float x; // xmm6_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm7_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  int v35; // edx
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  int v40; // xmm7_4
  float *m_pCurrPosition; // eax
  int v42; // xmm1_4
  float *v43; // eax
  float *v44; // eax
  float v45; // xmm3_4
  float *v46; // eax
  float *v47; // eax
  float *v48; // eax
  float *v49; // eax
  float *v50; // eax
  float v51; // xmm0_4
  int v52; // ecx
  __int16 v53; // dx
  unsigned int m_nCurrentIndex; // eax
  int v55; // esi
  int v56; // ecx
  bool v57; // zf
  int m_nVertexCount; // eax
  IMatRenderContext *v59; // esi
  long double v60; // [esp+0h] [ebp-258h]
  long double v61; // [esp+0h] [ebp-258h]
  long double v62; // [esp+0h] [ebp-258h]
  long double v63; // [esp+0h] [ebp-258h]
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-250h] BYREF
  Vector vecTangentT; // [esp+1F0h] [ebp-68h]
  int u; // [esp+1FCh] [ebp-5Ch]
  float phi; // [esp+200h] [ebp-58h]
  float v68; // [esp+204h] [ebp-54h]
  Vector vecNormal; // [esp+208h] [ebp-50h] BYREF
  float u1; // [esp+214h] [ebp-44h]
  float v71; // [esp+218h] [ebp-40h]
  float theta; // [esp+21Ch] [ebp-3Ch]
  IMesh *pMesh; // [esp+220h] [ebp-38h]
  CMatRenderContextPtr pRenderContext; // [esp+224h] [ebp-34h]
  Vector vecPos; // [esp+228h] [ebp-30h]
  int v2; // [esp+234h] [ebp-24h]
  int flHalfLuxel; // [esp+238h] [ebp-20h]
  Vector4D vecTangentS; // [esp+23Ch] [ebp-1Ch] BYREF
  int u2; // [esp+24Ch] [ebp-Ch]
  int i; // [esp+250h] [ebp-8h]
  bool bIsUsingLightmap; // [esp+256h] [ebp-2h]
  bool bIsUsingBumpedLightmap; // [esp+257h] [ebp-1h]
  float v; // [esp+260h] [ebp+8h]
  __int16 va; // [esp+260h] [ebp+8h]
  int flRadiusa; // [esp+264h] [ebp+Ch]
  int nPhia; // [esp+26Ch] [ebp+14h]

  u2 = (nTheta + 1) * (2 * nPhi - 2);
  v6 = vgui::MaterialSystem();
  v7 = v6->GetRenderContext(this: v6);
  m_pObject = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
  {
    v7->BeginRender(this: v7);
    m_pObject = pRenderContext.m_pObject;
  }
  pMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLE_STRIP,
    nVertexCount: nPhi * nTheta,
    nIndexCount: u2,
    pMeshSettings: nullptr);
  v9 = this->m_Material.m_pMaterial->GetPropertyFlag(
         this: this->m_Material.m_pMaterial,
         a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP);
  m_pMaterial = this->m_Material.m_pMaterial;
  bIsUsingLightmap = v9;
  v11 = m_pMaterial->GetPropertyFlag(this: m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
  m_pTexture = this->m_pLightmapTexture.m_pTexture;
  bIsUsingBumpedLightmap = v11;
  v13 = m_pTexture->GetActualWidth(this: m_pTexture);
  v14 = nPhi;
  v15 = 0;
  *(float *)&flHalfLuxel = 0.5 / (float)v13;
  i = 0;
  if ( nPhi > 0 )
  {
    do
    {
      v17 = nTheta;
      v18 = 0;
      if ( nTheta > 0 )
      {
        v68 = (float)(nTheta - 1);
        v19 = (float)v15 / (float)(nPhi - 1);
        v = v19;
        while ( 1 )
        {
          *(float *)&u = (float)v18 / v68;
          if ( v18 == v17 - 1 )
            v20 = 0.0;
          else
            v20 = (float)((float)v18 / v68) * 6.283185307179586;
          v21 = v20;
          theta = v21;
          phi = v19 * 3.141592653589793;
          v22 = phi;
          __libm_sse2_sin(x: v60);
          *(float *)&v22 = v22;
          v71 = *(float *)&v22 * flRadius;
          v23 = theta;
          __libm_sse2_cos(x: v61);
          *(float *)&v23 = v23;
          vecPos.x = *(float *)&v23 * v71;
          v24 = theta;
          __libm_sse2_sin(x: v62);
          *(float *)&v24 = v24;
          vecPos.y = *(float *)&v24 * v71;
          v25 = phi;
          __libm_sse2_cos(x: v63);
          *(float *)&v25 = v25;
          vecPos.z = *(float *)&v25 * flRadius;
          *(_QWORD *)&vecNormal.x = *(_QWORD *)&vecPos.x;
          vecNormal.z = *(float *)&v25 * flRadius;
          VectorNormalize(vec: &vecNormal);
          vecTangentS.x = vecPos.z;
          vecTangentS.y = -vecPos.x;
          vecTangentS.z = 0.0;
          vecTangentS.w = 1.0;
          if ( VectorNormalize(vec: (Vector *)&vecTangentS) == 0.0 )
          {
            x = 1.0;
            y = 0.0;
            z = 0.0;
            vecTangentS.x = 1.0;
            vecTangentS.y = 0.0;
            vecTangentS.z = 0.0;
            vecTangentS.w = 1.0;
          }
          else
          {
            z = vecTangentS.z;
            y = vecTangentS.y;
            x = vecTangentS.x;
          }
          v29 = vecNormal.y * z;
          v30 = (float)(vecNormal.z * x) - (float)(z * vecNormal.x);
          v31 = *(float *)&u;
          v32 = vecNormal.z * y;
          v33 = vecNormal.y * x;
          v34 = vCenter->y + vecPos.y;
          vecTangentT.y = v30;
          v35 = (int)(float)(*(float *)&u * 255.0);
          v36 = v;
          vecTangentT.z = (float)(y * vecNormal.x) - v33;
          v37 = vCenter->z + vecPos.z;
          v38 = vCenter->x + vecPos.x;
          v39 = v29 - v32;
          v40 = LODWORD(v);
          u2 = u;
          u1 = *(float *)&u;
          v2 = LODWORD(v);
          if ( bIsUsingLightmap )
          {
            u1 = (float)((float)((float)(0.25 - *(float *)&flHalfLuxel) - *(float *)&flHalfLuxel) * *(float *)&u)
               + *(float *)&flHalfLuxel;
            if ( bIsUsingBumpedLightmap )
            {
              u2 = 1048576000;
              v40 = 0;
            }
            else
            {
              v40 = v2;
            }
            v36 = v;
          }
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v38;
          m_pCurrPosition[1] = v34;
          m_pCurrPosition[2] = v37;
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
          v42 = u2;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)(int)(float)(v * 255.0)
                                                              | (((unsigned __int8)(int)(float)(v * 255.0)
                                                                | (((unsigned __int8)v35
                                                                  | ((unsigned __int8)(int)(float)(v * 255.0) << 8)) << 8)) << 8);
          v43 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v31 * 2.0;
          v43[1] = v36;
          v43[2] = 0.0;
          v43[3] = 0.0;
          v44 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          v45 = u1;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1;
          v44[1] = v36;
          v44[2] = 0.0;
          v44[3] = 0.0;
          v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v42;
          *((_DWORD *)v46 + 1) = v40;
          v46[2] = 0.0;
          v46[3] = 0.0;
          v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v45;
          v47[1] = v36;
          v47[2] = 0.0;
          v47[3] = 0.0;
          v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v42;
          *((_DWORD *)v48 + 1) = v40;
          v48[2] = 0.0;
          v48[3] = 0.0;
          v49 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
          *v49 = vecTangentS.x;
          v49[1] = vecTangentS.y;
          v49[2] = vecTangentS.z;
          v50 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
          v51 = vecTangentT.y;
          *v50 = v39;
          v50[1] = v51;
          v50[2] = vecTangentT.z;
          if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
            *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                     * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
          meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
          *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_UserData) = vecTangentS;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++v18 >= nTheta )
            break;
          v19 = v;
          v17 = nTheta;
        }
        v15 = i;
      }
      i = ++v15;
    }
    while ( v15 < nPhi );
    v14 = nPhi;
  }
  v52 = 0;
  v53 = 0;
  i = 0;
  flHalfLuxel = v14 - 1;
  if ( v14 - 1 > 0 )
  {
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    v2 = v14 - 2;
    v55 = 0;
    flRadiusa = 0;
    do
    {
      if ( nTheta > 0 )
      {
        v56 = v55;
        nPhia = nTheta;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v56
                                                                 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                            + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                            + v56;
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          va = v56++;
          v57 = nPhia-- == 1;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( !v57 );
        v52 = i;
        v53 = va;
      }
      if ( v52 < v2 )
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                               + v53
                                                               + 1;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                          + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                          + v53
                                                                                          + 1;
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      v55 = nTheta + flRadiusa;
      i = ++v52;
      flRadiusa += nTheta;
    }
    while ( v52 < flHalfLuxel );
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
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
  v59 = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  v59->Release(this: v59);
}

//------------------------------------------------------------------------------
// Address: 0x004E6430
// Name: private: void CVMTPreviewPanel::RenderSheet(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::RenderSheet(CVMTPreviewPanel *this, const Vector *vCenter, float flRadius)
{
  IMaterialSystem *v4; // eax
  int v5; // eax
  int v6; // esi
  IMesh *v7; // ebx
  float flAge; // [esp+18h] [ebp-24h]
  float v9; // [esp+38h] [ebp-4h]

  v4 = vgui::MaterialSystem();
  v5 = (int)v4->GetRenderContext(this: v4);
  v6 = v5;
  if ( v5 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
  v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                  a1: v6,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0);
  if ( CSheetExtended::ValidSheetData(this: this->m_pMaterialSheet) )
  {
    v9 = _Plat_FloatTime() - this->m_flLastSwitchTime;
    flAge = fmod(
              v9,
              CSheetExtended::GetSequenceTimeSpan(
                this: this->m_pMaterialSheet,
                nSequenceIndex: this->m_nCurrentSheetSequence));
    CSheetExtended::DrawSheet(
      this: this->m_pMaterialSheet,
      pMesh: v7,
      vCenter,
      flRadius,
      nSheetSequence: this->m_nCurrentSheetSequence,
      flAge,
      flSheetPreviewSpeed: this->m_flSheetPreviewSpeed,
      bLoopSheetPreview: true,
      nSecondarySequence: this->m_nCurrentSecondarySheetSequence,
      bOverrideSpriteCard: false);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004E6510
// Name: private: void CVMTPreviewPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVMTPreviewPanel::LookAt(
        CVMTPreviewPanel *this@<ecx>,
        double a2@<esi:edi>,
        const Vector *vecLookAt,
        float flRadius)
{
  int v5; // edi
  double v6; // xmm0_8
  float v7; // xmm0_4
  float z; // edx
  Vector *p_m_vecCameraDirection; // edi
  float v10; // xmm0_4
  IMaterialSystem *v11; // eax
  int v12; // eax
  int v13; // esi
  void (__thiscall *v14)(int, int, int); // eax
  long double v15; // [esp+60h] [ebp-38h]
  long double v16; // [esp+60h] [ebp-38h]
  int v17; // [esp+60h] [ebp-38h]
  int v18; // [esp+64h] [ebp-34h]
  QAngle angles; // [esp+68h] [ebp-30h] BYREF
  Vector vecMDLOrigin; // [esp+74h] [ebp-24h]
  Vector vecCameraOrigin; // [esp+80h] [ebp-18h]
  float flFOVx; // [esp+8Ch] [ebp-Ch]
  int h; // [esp+90h] [ebp-8h] BYREF
  int w; // [esp+94h] [ebp-4h] BYREF

  v15 = a2;
  flFOVx = 0.78539819;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v5 = h;
  if ( h >= w )
  {
    v7 = flFOVx;
  }
  else
  {
    __libm_sse2_tan(x: v15);
    v6 = (float)((float)((float)0.7853981633974483 * (float)v5) / (float)w);
    __libm_sse2_atan(x: v16);
    v7 = v6;
  }
  z = vecLookAt->z;
  *(_QWORD *)&vecMDLOrigin.x = *(_QWORD *)&vecLookAt->x;
  vecMDLOrigin.z = z;
  p_m_vecCameraDirection = &this->m_vecCameraDirection;
  __libm_sse2_sin(x: v15);
  LODWORD(v10) = COERCE_UNSIGNED_INT(flRadius / v7) ^ _mask__NegFloat_;
  vecCameraOrigin.x = (float)(this->m_vecCameraDirection.x * v10) + vecMDLOrigin.x;
  vecCameraOrigin.y = (float)(this->m_vecCameraDirection.y * v10) + vecMDLOrigin.y;
  vecCameraOrigin.z = (float)(this->m_vecCameraDirection.z * v10) + vecMDLOrigin.z;
  v11 = vgui::MaterialSystem();
  v12 = ((int (__thiscall *)(IMaterialSystem *, int, int))v11->GetRenderContext)(a1: v11, a2: v17, a3: v18);
  v13 = v12;
  if ( v12 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 8))(a1: v12);
  VectorAngles(a1: v13, forward: p_m_vecCameraDirection, &angles);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v13 + 80))(
    a1: v13,
    a2: 0,
    a3: LODWORD(angles.x),
    a4: LODWORD(angles.y));
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 124))(a1: v13);
  v14 = *(void (__thiscall **)(int, int, int))(*(_DWORD *)v13 + 140);
  angles.y = 0.0;
  angles.x = 0.0;
  v14(a1: v13, a2: -1028390912, a3: 1065353216);
  (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)v13 + 140))(
    a1: v13,
    a2: 1119092736,
    a3: 0,
    a4: 0,
    a5: 1065353216);
  (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v13 + 140))(
    a1: v13,
    a2: LODWORD(angles.z) ^ _mask__NegFloat_,
    a3: 1065353216,
    a4: 0,
    a5: 0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v13 + 140))(
    a1: v13,
    a2: LODWORD(angles.x) ^ _mask__NegFloat_,
    a3: 0,
    a4: 1065353216,
    a5: 0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v13 + 140))(
    a1: v13,
    a2: LODWORD(angles.y) ^ _mask__NegFloat_,
    a3: 0,
    a4: 0,
    a5: 1065353216);
  (*(void (__thiscall **)(int, _DWORD, unsigned int, _DWORD))(*(_DWORD *)v13 + 144))(
    a1: v13,
    a2: -vecCameraOrigin.x,
    a3: LODWORD(vecCameraOrigin.y) ^ 0x80000000,
    a4: -vecCameraOrigin.z);
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 12))(a1: v13);
  (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 4))(a1: v13);
}

//------------------------------------------------------------------------------
// Address: 0x004E67B0
// Name: private: void CVMTPreviewPanel::SetupProjectionMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CVMTPreviewPanel::SetupProjectionMatrix(
        CVMTPreviewPanel *this@<ecx>,
        int a2@<esi>,
        int nWidth,
        int nHeight)
{
  float v4; // xmm0_4
  IMaterialSystem *v5; // eax
  int v6; // eax
  int v7; // esi
  _BYTE v8[68]; // [esp-4h] [ebp-44h] OVERLAPPED BYREF

  if ( (float)nHeight == 0.0 )
    v4 = 100.0;
  else
    v4 = (float)nWidth / (float)nHeight;
  *(_DWORD *)v8 = a2;
  __libm_sse2_tan(x: *(long double *)v8);
  memset(dst: &v8[4], value: 0, count: 0x40u);
  *(float *)&v8[24] = 1.0 / (float)((float)0.7853981633974483 / v4);
  *(_QWORD *)&v8[44] = 0xBDCCCF6CBF8001A3uLL;
  *(_DWORD *)&v8[60] = -1082130432;
  *(float *)&v8[4] = 1.0 / (float)0.7853981633974483;
  v5 = vgui::MaterialSystem();
  v6 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v5->GetRenderContext)(
         a1: v5,
         a2: *(_DWORD *)v8,
         a3: *(_DWORD *)&v8[4],
         a4: *(_DWORD *)&v8[8],
         a5: *(_DWORD *)&v8[12],
         a6: *(_DWORD *)&v8[16],
         a7: *(_DWORD *)&v8[20],
         a8: *(_DWORD *)&v8[24],
         a9: *(_DWORD *)&v8[28],
         a10: *(_DWORD *)&v8[32],
         a11: *(_DWORD *)&v8[36],
         a12: *(_DWORD *)&v8[40],
         a13: *(_DWORD *)&v8[44],
         a14: *(_DWORD *)&v8[48],
         a15: *(_DWORD *)&v8[52],
         a16: *(_DWORD *)&v8[56],
         a17: *(_DWORD *)&v8[60],
         a18: *(_DWORD *)&v8[64]);
  v7 = v6;
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 80))(a1: v7, a2: 1);
  (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v7 + 96))(a1: v7, a2: &v8[4]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x004E68B0
// Name: private: void CVMTPreviewPanel::SetupOrthoMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::SetupOrthoMatrix(CVMTPreviewPanel *this, int nWidth, int nHeight)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = vgui::MaterialSystem();
  v4 = (int)v3->GetRenderContext(this: v3);
  v5 = v4;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 124))(a1: v5);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v5 + 128))(
    a1: v5,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0,
    a6: COERCE_UNSIGNED_INT64((double)nWidth),
    a7: HIDWORD(COERCE_UNSIGNED_INT64((double)nWidth)),
    a8: COERCE_UNSIGNED_INT64((double)nHeight),
    a9: HIDWORD(COERCE_UNSIGNED_INT64((double)nHeight)),
    a10: 0,
    a11: -1074790400,
    a12: 0,
    a13: 1072693248);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004E6960
// Name: private: void CVMTPreviewPanel::DrawRectangle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawRectangle(CVMTPreviewPanel *this)
{
  int v2; // eax
  IMaterial *m_pMaterial; // ecx
  int v4; // esi
  int (__thiscall *GetMappingHeight)(IMaterial *); // edx
  int v6; // eax
  IMaterialSystem *v7; // eax
  int v8; // eax
  int v9; // esi
  IMesh *v10; // ebx
  bool v11; // al
  IMaterial *v12; // ecx
  IMaterial_vtbl *v13; // edx
  bool v14; // al
  ITexture *m_pTexture; // ecx
  ITexture_vtbl *v16; // edx
  int v17; // eax
  int v18; // edx
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  int v22; // edi
  int v23; // ecx
  float v24; // xmm4_4
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  float v28; // xmm4_4
  __int64 v29; // rax
  int v30; // ecx
  int v31; // edi
  int v32; // ebx
  int v33; // xmm6_4
  float v34; // xmm4_4
  float v35; // xmm3_4
  int v36; // edx
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // eax
  float *v39; // eax
  float *v40; // eax
  float *v41; // eax
  int v42; // xmm2_4
  float *v43; // eax
  float *v44; // eax
  float *v45; // eax
  float *v46; // eax
  float *v47; // eax
  _DWORD *v48; // eax
  _DWORD *v49; // eax
  __int64 v50; // xmm0_8
  _QWORD *v51; // eax
  float *v52; // eax
  float x; // xmm1_4
  float v54; // xmm2_4
  int v55; // xmm4_4
  float v56; // xmm5_4
  float *v57; // eax
  float *v58; // eax
  float *v59; // eax
  float v60; // xmm1_4
  float *v61; // eax
  float *v62; // eax
  float *v63; // eax
  float *v64; // eax
  float *v65; // eax
  float *v66; // eax
  _DWORD *v67; // eax
  _DWORD *v68; // eax
  __int64 v69; // xmm0_8
  _QWORD *v70; // eax
  float *v71; // eax
  int v72; // xmm1_4
  float v73; // xmm2_4
  float v74; // xmm4_4
  int v75; // xmm5_4
  float *v76; // eax
  float *v77; // eax
  float *v78; // eax
  float v79; // xmm1_4
  float *v80; // eax
  float *v81; // eax
  float *v82; // eax
  float *v83; // eax
  float *v84; // eax
  float *v85; // eax
  _DWORD *v86; // eax
  _DWORD *v87; // eax
  __int64 v88; // xmm0_8
  _QWORD *v89; // eax
  float *v90; // eax
  float *v91; // eax
  float *v92; // eax
  float *v93; // eax
  float v94; // xmm2_4
  float v95; // xmm1_4
  float *v96; // eax
  float v97; // xmm4_4
  float v98; // xmm5_4
  float *v99; // eax
  float *v100; // eax
  float *v101; // eax
  float *v102; // eax
  float *v103; // eax
  _DWORD *v104; // eax
  _DWORD *v105; // eax
  __int64 v106; // xmm0_8
  _QWORD *v107; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-244h] BYREF
  float v109; // [esp+1F0h] [ebp-5Ch]
  float v110; // [esp+1F4h] [ebp-58h]
  Vector2D halfTexel; // [esp+1F8h] [ebp-54h]
  IMesh *pMesh; // [esp+200h] [ebp-4Ch]
  float v1_t; // [esp+204h] [ebp-48h]
  Vector4D vecTangentS; // [esp+208h] [ebp-44h]
  float u1_l; // [esp+218h] [ebp-34h]
  float v2_b; // [esp+21Ch] [ebp-30h]
  float v1_b; // [esp+220h] [ebp-2Ch]
  float u2_r; // [esp+224h] [ebp-28h]
  float u1_r; // [esp+228h] [ebp-24h]
  int th; // [esp+22Ch] [ebp-20h]
  int w; // [esp+230h] [ebp-1Ch] BYREF
  float flHalfLuxel; // [esp+234h] [ebp-18h]
  bool bIsUsingBumpedLightmap; // [esp+23Ah] [ebp-12h]
  bool bIsUsingLightmap; // [esp+23Bh] [ebp-11h]
  int h; // [esp+23Ch] [ebp-10h] BYREF
  int nYBorder; // [esp+240h] [ebp-Ch]
  int v2_t; // [esp+244h] [ebp-8h]
  int usewide; // [esp+248h] [ebp-4h]

  *(float *)&v2 = COERCE_FLOAT(this->m_Material.m_pMaterial->GetMappingWidth(this: this->m_Material.m_pMaterial));
  m_pMaterial = this->m_Material.m_pMaterial;
  v4 = v2;
  GetMappingHeight = m_pMaterial->GetMappingHeight;
  usewide = v2;
  *(float *)&v6 = COERCE_FLOAT(GetMappingHeight(this: m_pMaterial));
  th = v6;
  if ( v4 > 0 && v6 > 0 )
  {
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    if ( w != 0 && h != 0 )
    {
      CVMTPreviewPanel::SetupOrthoMatrix(this, nWidth: w, nHeight: h);
      CVMTPreviewPanel::SetupLightingState(this);
      v7 = vgui::MaterialSystem();
      v8 = (int)v7->GetRenderContext(this: v7);
      v9 = v8;
      if ( v8 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 80))(a1: v9, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 80))(a1: v9, a2: 10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9);
      v10 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 228))(
                       a1: v9,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
      pMesh = v10;
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh: v10,
        type: MATERIAL_TRIANGLE_STRIP,
        nVertexCount: 4,
        nIndexCount: 4,
        pMeshSettings: nullptr);
      v11 = this->m_Material.m_pMaterial->GetPropertyFlag(
              this: this->m_Material.m_pMaterial,
              a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP);
      v12 = this->m_Material.m_pMaterial;
      v13 = v12->__vftable;
      bIsUsingLightmap = v11;
      v14 = v13->GetPropertyFlag(this: v12, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
      m_pTexture = this->m_pLightmapTexture.m_pTexture;
      v16 = m_pTexture->__vftable;
      bIsUsingBumpedLightmap = v14;
      v17 = v16->GetActualWidth(this: m_pTexture);
      v18 = h;
      v19 = 0.5 / (float)th;
      flHalfLuxel = 0.5 / (float)v17;
      v20 = 0.5 / (float)usewide;
      halfTexel.x = v20;
      halfTexel.y = v19;
      vecTangentS.x = 1.0;
      vecTangentS.y = 0.0;
      vecTangentS.z = 0.0;
      vecTangentS.w = 1.0;
      v21 = (float)usewide / (float)th;
      v22 = 0;
      v23 = 0;
      v24 = v21 / (float)((float)w / (float)h);
      if ( w <= 15 )
      {
        v18 = h;
        v2_t = w / 3;
      }
      else
      {
        v2_t = 5;
      }
      if ( v18 <= 15 )
      {
        v25 = v18 / 3;
        v18 = h;
        nYBorder = v25;
      }
      else
      {
        nYBorder = 5;
      }
      v26 = w - 2 * v2_t;
      v27 = v18 - 2 * nYBorder;
      w = v26;
      h = v27;
      if ( v24 <= 1.0 )
      {
        v28 = (float)v27 * v21;
        v29 = v26 - (int)v28;
        usewide = (int)v28;
        v26 = (int)v28;
        v23 = ((int)v29 - HIDWORD(v29)) >> 1;
        w = (int)v28;
      }
      else
      {
        usewide = (int)(float)((float)v26 / v21);
        v22 = (v27 - usewide) / 2;
        h = usewide;
      }
      v30 = v2_t + v23;
      v31 = nYBorder + v22;
      v32 = v30 + v26;
      *(float *)&th = 1.0 - v20;
      u2_r = 1.0 - v20;
      u1_r = 1.0 - v20;
      v33 = LODWORD(v20);
      v34 = v20;
      v35 = v19;
      v36 = v31 + h;
      nYBorder = LODWORD(v20);
      u1_l = v20;
      v2_t = LODWORD(v19);
      v1_t = v19;
      *(float *)&usewide = 1.0 - v19;
      v2_b = 1.0 - v19;
      v1_b = 1.0 - v19;
      if ( bIsUsingLightmap )
      {
        v35 = flHalfLuxel;
        v34 = flHalfLuxel;
        v1_t = flHalfLuxel;
        u1_l = flHalfLuxel;
        v1_b = 0.25 - flHalfLuxel;
        u1_r = 0.25 - flHalfLuxel;
        if ( bIsUsingBumpedLightmap )
        {
          v33 = 1048576000;
          u2_r = 0.25;
          nYBorder = 1048576000;
          v2_b = 0.0;
          v2_t = 0;
        }
        else
        {
          v33 = nYBorder;
        }
      }
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v30;
      flHalfLuxel = (float)v30;
      m_pCurrPosition[1] = (float)v36;
      m_pCurrPosition[2] = 0.0;
      m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      m_pCurrNormal[1] = 0.0;
      m_pCurrNormal[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v20;
      v39[1] = v19;
      v39[2] = 0.0;
      v39[3] = 0.0;
      v40 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v34;
      v40[1] = v35;
      v40[2] = 0.0;
      v40[3] = 0.0;
      v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v33;
      v42 = v2_t;
      *((_DWORD *)v41 + 1) = v2_t;
      v41[2] = 0.0;
      v41[3] = 0.0;
      v43 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v34;
      v43[1] = v35;
      v43[2] = 0.0;
      v43[3] = 0.0;
      v44 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v33;
      *((_DWORD *)v44 + 1) = v42;
      v44[2] = 0.0;
      v44[3] = 0.0;
      v45 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v34;
      v45[1] = v35;
      v45[2] = 0.0;
      v45[3] = 0.0;
      v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v33;
      *((_DWORD *)v46 + 1) = v42;
      v46[2] = 0.0;
      v46[3] = 0.0;
      v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v34;
      v47[1] = v35;
      v47[2] = 0.0;
      v47[3] = 0.0;
      v48 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      v109 = (float)v36;
      *v48 = 1065353216;
      v48[1] = 0;
      v48[2] = 0;
      v49 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v49 = 0;
      v49[1] = 1065353216;
      v49[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v50 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v51 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v51 = v50;
      v51[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v52 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = flHalfLuxel;
      x = halfTexel.x;
      v54 = v1_b;
      v55 = nYBorder;
      v56 = v2_b;
      v52[1] = (float)v31;
      v110 = (float)v31;
      v52[2] = 0.0;
      v57 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v57[1] = 0.0;
      v57[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v58 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = x;
      v58[1] = *(float *)&usewide;
      v58[2] = 0.0;
      v58[3] = 0.0;
      v59 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v60 = u1_l;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1_l;
      v59[1] = v54;
      v59[2] = 0.0;
      v59[3] = 0.0;
      v61 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v55;
      v61[1] = v56;
      v61[2] = 0.0;
      v61[3] = 0.0;
      v62 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v60;
      v62[1] = v54;
      v62[2] = 0.0;
      v62[3] = 0.0;
      v63 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v55;
      v63[1] = v56;
      v63[2] = 0.0;
      v63[3] = 0.0;
      v64 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v60;
      v64[1] = v54;
      v64[2] = 0.0;
      v64[3] = 0.0;
      v65 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v55;
      v65[1] = v56;
      v65[2] = 0.0;
      v65[3] = 0.0;
      v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v60;
      v66[1] = v54;
      v66[2] = 0.0;
      v66[3] = 0.0;
      v67 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v67 = 1065353216;
      v67[1] = 0;
      v67[2] = 0;
      v68 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v68 = 0;
      v68[1] = 1065353216;
      v68[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v69 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v70 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v70 = v69;
      v70[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v71 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v72 = th;
      v73 = u1_r;
      v74 = u2_r;
      v75 = v2_t;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v32;
      flHalfLuxel = (float)v32;
      v71[1] = v109;
      v71[2] = 0.0;
      v76 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v76[1] = 0.0;
      v76[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v77 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v72;
      v77[1] = halfTexel.y;
      v77[2] = 0.0;
      v77[3] = 0.0;
      v78 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v73;
      v79 = v1_t;
      v78[1] = v1_t;
      v78[2] = 0.0;
      v78[3] = 0.0;
      v80 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v74;
      *((_DWORD *)v80 + 1) = v75;
      v80[2] = 0.0;
      v80[3] = 0.0;
      v81 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v73;
      v81[1] = v79;
      v81[2] = 0.0;
      v81[3] = 0.0;
      v82 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v74;
      *((_DWORD *)v82 + 1) = v75;
      v82[2] = 0.0;
      v82[3] = 0.0;
      v83 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v73;
      v83[1] = v79;
      v83[2] = 0.0;
      v83[3] = 0.0;
      v84 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v74;
      *((_DWORD *)v84 + 1) = v75;
      v84[2] = 0.0;
      v84[3] = 0.0;
      v85 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v73;
      v85[1] = v79;
      v85[2] = 0.0;
      v85[3] = 0.0;
      v86 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v86 = 1065353216;
      v86[1] = 0;
      v86[2] = 0;
      v87 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v87 = 0;
      v87[1] = 1065353216;
      v87[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v88 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v89 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v89 = v88;
      v89[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v90 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = flHalfLuxel;
      v90[1] = v110;
      v90[2] = 0.0;
      v91 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
      v91[1] = 0.0;
      v91[2] = 1.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      v92 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(float *)&th;
      v92[1] = *(float *)&usewide;
      v92[2] = 0.0;
      v92[3] = 0.0;
      v93 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v94 = u1_r;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = u1_r;
      v95 = v1_b;
      v93[1] = v1_b;
      v93[2] = 0.0;
      v93[3] = 0.0;
      v96 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
      v97 = u2_r;
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = u2_r;
      v98 = v2_b;
      v96[1] = v2_b;
      v96[2] = 0.0;
      v96[3] = 0.0;
      v99 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = v94;
      v99[1] = v95;
      v99[2] = 0.0;
      v99[3] = 0.0;
      v100 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = v97;
      v100[1] = v98;
      v100[2] = 0.0;
      v100[3] = 0.0;
      v101 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = v94;
      v101[1] = v95;
      v101[2] = 0.0;
      v101[3] = 0.0;
      v102 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = v97;
      v102[1] = v98;
      v102[2] = 0.0;
      v102[3] = 0.0;
      v103 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = v94;
      v103[1] = v95;
      v103[2] = 0.0;
      v103[3] = 0.0;
      v104 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
      *v104 = 1065353216;
      v104[1] = 0;
      v104[2] = 0;
      v105 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
      *v105 = 0;
      v105[1] = 1065353216;
      v105[2] = 0;
      if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
      v106 = *(_QWORD *)&vecTangentS.x;
      meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                   * meshBuilder.m_VertexBuilder.m_nCurrentVertex] = 0;
      v107 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_VertexSize_UserData * meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      *v107 = v106;
      v107[1] = *(_QWORD *)&vecTangentS.z;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 1;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 2;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                        + 3;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      CMeshBuilder::End(this: &meshBuilder, bSpewData: false, bDraw: false);
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E7470
// Name: private: void CVMTPreviewPanel::DrawSphere(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::DrawSphere(CVMTPreviewPanel *this)
{
  double v1; // st7
  double v2; // rdi
  double v3; // st7
  CSheetExtended *v4; // ecx
  float angleDegrees; // [esp+8h] [ebp-64h]
  VMatrix rot; // [esp+14h] [ebp-58h] BYREF
  Vector vecTemp; // [esp+54h] [ebp-18h] BYREF
  int w; // [esp+60h] [ebp-Ch] BYREF
  int h; // [esp+64h] [ebp-8h] BYREF
  float flNewTime; // [esp+68h] [ebp-4h]

  HIDWORD(v2) = this;
  v1 = _Plat_FloatTime();
  flNewTime = v1;
  angleDegrees = (v1 - *(float *)(HIDWORD(v2) + 400)) * 40.0;
  MatrixBuildRotateZ(dst: &rot, angleDegrees);
  LODWORD(v2) = HIDWORD(v2) + 388;
  Vector3DMultiply(src1: &rot, src2: (Vector *)(HIDWORD(v2) + 388), dst: &vecTemp);
  v3 = flNewTime;
  *(Vector *)(HIDWORD(v2) + 388) = vecTemp;
  *(float *)(HIDWORD(v2) + 400) = v3;
  vgui::Panel::GetSize(this: (vgui::Panel *)HIDWORD(v2), wide: &w, tall: &h);
  CVMTPreviewPanel::SetupProjectionMatrix(
    this: (CVMTPreviewPanel *)HIDWORD(v2),
    a2: SHIDWORD(v2),
    nWidth: w,
    nHeight: h);
  CVMTPreviewPanel::SetupLightingState(this: (CVMTPreviewPanel *)HIDWORD(v2));
  CVMTPreviewPanel::LookAt(this: (CVMTPreviewPanel *)HIDWORD(v2), a2: v2, vecLookAt: &vec3_origin, flRadius: 12.0);
  v4 = *(CSheetExtended **)(HIDWORD(v2) + 356);
  if ( v4 != nullptr && CSheetExtended::ValidSheetData(this: v4) )
    CVMTPreviewPanel::RenderSheet(this: (CVMTPreviewPanel *)HIDWORD(v2), vCenter: &vec3_origin, flRadius: 10.0);
  else
    CVMTPreviewPanel::RenderSphere(
      this: (CVMTPreviewPanel *)HIDWORD(v2),
      vCenter: &vec3_origin,
      flRadius: 10.0,
      nTheta: 20,
      nPhi: 20);
}

//------------------------------------------------------------------------------
// Address: 0x004E7570
// Name: public: virtual void CVMTPreviewPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::Paint(CVMTPreviewPanel *this)
{
  IMaterialSystem *v2; // eax
  int v3; // eax
  int v4; // esi
  IMatSystemSurface *v5; // eax
  ITexture *m_pTexture; // ecx
  IMaterialSystem *v7; // eax
  ITexture *v8; // eax
  ITexture *v9; // ebx
  IMatSystemSurface *v10; // eax
  int w; // [esp+8h] [ebp-8h] BYREF
  int h; // [esp+Ch] [ebp-4h] BYREF

  v2 = vgui::MaterialSystem();
  v3 = (int)v2->GetRenderContext(this: v2);
  v4 = v3;
  if ( v3 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v5 = vgui::MatSystemSurface();
  v5->Begin3DPaint(this: v5, a2: 0, a3: 0, a4: w, a5: h);
  if ( this->m_Material.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(this: this->m_Material.m_pMaterial, a2: true) )
  {
    m_pTexture = s_pPowerOfTwoFrameBufferTexture.m_pTexture;
    if ( s_pPowerOfTwoFrameBufferTexture.m_pTexture == nullptr )
    {
      v7 = vgui::MaterialSystem();
      v8 = v7->FindTexture(this: v7, a2: "_rt_PowerOfTwoFB", a3: "RenderTargets", a4: true, a5: 0);
      CTextureReference::Init(this: &s_pPowerOfTwoFrameBufferTexture, pTexture: v8);
      m_pTexture = s_pPowerOfTwoFrameBufferTexture.m_pTexture;
    }
    v9 = m_pTexture;
    if ( m_pTexture != nullptr && !m_pTexture->IsError(this: m_pTexture) )
    {
      (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 68))(a1: v4, a2: v9);
      (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v4 + 72))(a1: v4, a2: v9, a3: 0);
    }
  }
  (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v4 + 296))(a1: v4, a2: 76, a3: 88, a4: 68, a5: 255);
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v4 + 48))(a1: v4, a2: 1, a3: 1, a4: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 176))(a1: v4, a2: 0);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 216))(a1: v4, a2: 0);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v4 + 36))(
    a1: v4,
    a2: this->m_Material.m_pMaterial,
    a3: 0);
  (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 448))(a1: v4, a2: this->m_pLightmapTexture.m_pTexture);
  (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v4 + 20))(a1: v4, a2: this->m_DefaultEnvCubemap.m_pTexture);
  if ( this->m_bDrawIn3DMode )
    CVMTPreviewPanel::DrawSphere(this);
  else
    CVMTPreviewPanel::DrawRectangle(this);
  v10 = vgui::MatSystemSurface();
  v10->End3DPaint(this: v10);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004E7700
// Name: public: CVMTPreviewPanel::CVMTPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMTPreviewPanel *__thiscall CVMTPreviewPanel::CVMTPreviewPanel(
        CVMTPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CVMTPreviewPanel_vtbl *)&CVMTPreviewPanel::`vftable';
  if ( `CVMTPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewPanel");
    v4->pfnClassName = CVMTPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CVMTPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVMTPreviewPanel");
    v5->pfnClassName = CVMTPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CVMTPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewPanel");
    v6->pfnClassName = CVMTPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CUtlString::CUtlString(this: &this->m_VMTName);
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_pLightmapTexture);
  CTextureReference::CTextureReference(this: &this->m_DefaultEnvCubemap);
  this->m_LightColor = 0;
  this->m_pMaterialSheet = nullptr;
  CVMTPreviewPanel::SetVMT(this, pMaterialName: "//platform/materials/vgui/vtfnotloaded");
  CTextureReference::Init(
    this: &this->m_pLightmapTexture,
    pTextureName: "//platform/materials/debug/defaultlightmap",
    pTextureGroupName: "editor",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  CTextureReference::Init(
    this: &this->m_DefaultEnvCubemap,
    pTextureName: "editor/cubemap",
    pTextureGroupName: "editor",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  this->m_LightDirection.z = -1.0;
  this->m_LightDirection.x = 0.0;
  this->m_LightDirection.y = 1.0;
  this->m_LightColor = (Color)-1;
  this->m_flLightIntensity = 2.0;
  this->m_bDrawIn3DMode = false;
  this->m_flSheetPreviewSpeed = 750.0;
  this->m_nCurrentSheetSequence = 0;
  this->m_nCurrentSecondarySheetSequence = 0;
  this->m_vecCameraDirection.x = 1.0;
  this->m_vecCameraDirection.y = 0.0;
  this->m_vecCameraDirection.z = 0.0;
  this->m_flLastRotationTime = _Plat_FloatTime();
  this->m_flLastSwitchTime = _Plat_FloatTime();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E78D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPreviewPanel::GetMessageMap(CVMTPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CVMTPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewPanel");
  `CVMTPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E7900
// Name: public: virtual struct PanelAnimationMap __near * CVMTPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPreviewPanel::GetAnimMap(CVMTPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004E7910
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPreviewPanel::GetKBMap(CVMTPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CVMTPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewPanel");
  `CVMTPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E7940
// Name: public: virtual CVMTPreviewPanel::~CVMTPreviewPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewPanel::~CVMTPreviewPanel(CVMTPreviewPanel *this)
{
  bool v2; // sf

  CTextureReference::~CTextureReference(this: &this->m_DefaultEnvCubemap);
  CTextureReference::~CTextureReference(this: &this->m_pLightmapTexture);
  CMaterialReference::~CMaterialReference(this: &this->m_Material);
  v2 = this->m_VMTName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_VMTName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_VMTName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VMTName.m_Storage.m_Memory.m_pMemory);
      this->m_VMTName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_VMTName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

} // namespace sceneviewer
