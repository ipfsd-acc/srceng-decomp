// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/vtfpreviewpanel.cpp
// Functions: 13
// ============================================================

#include "vgui2\matsys_controls\vtfpreviewpanel.h"

//------------------------------------------------------------------------------
// Address: 0x004CD8E0
// Name: public: static char const __near * CVTFPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPreviewPanel::GetPanelClassName()
{
  return "CVTFPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004CD8F0
// Name: public: void CVTFPreviewPanel::SetVTF(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::SetVTF(CVTFPreviewPanel *this, const char *pFullPath, bool bLoadImmediately)
{
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  IMaterialSystem *v6; // eax
  IMaterial *v7; // eax
  IMatSystemSurface *v8; // eax

  CTextureReference::Init(
    this: &this->m_PreviewTexture,
    pTextureName: pFullPath,
    pTextureGroupName: "editor texture",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  CUtlString::operator=(this: &this->m_VTFName, src: pFullPath);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "UnlitGeneric");
  else
    v5 = nullptr;
  if ( this->m_PreviewTexture.m_pTexture->IsCubeMap(this: this->m_PreviewTexture.m_pTexture) )
  {
    KeyValues::SetString(this: v5, keyName: "$envmap", value: pFullPath);
  }
  else if ( this->m_PreviewTexture.m_pTexture->IsNormalMap(this: this->m_PreviewTexture.m_pTexture) )
  {
    KeyValues::SetString(this: v5, keyName: "$bumpmap", value: pFullPath);
  }
  else
  {
    KeyValues::SetString(this: v5, keyName: "$basetexture", value: pFullPath);
  }
  KeyValues::SetInt(this: v5, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v5, keyName: "$nodebug", value: 1);
  v6 = vgui::MaterialSystem();
  v7 = v6->CreateMaterial(this: v6, a2: pFullPath, a3: v5);
  CMaterialReference::Init(this: &this->m_PreviewMaterial, pMaterial: v7);
  v8 = vgui::MatSystemSurface();
  v8->DrawSetTextureMaterial(this: v8, a2: this->m_nTextureID, a3: this->m_PreviewMaterial.m_pMaterial);
  this->m_vecCameraDirection.x = 1.0;
  this->m_vecCameraDirection.y = 0.0;
  this->m_vecCameraDirection.z = 0.0;
  this->m_flLastRotationTime = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x004CDA20
// Name: private: void CVTFPreviewPanel::PaintStandardTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::PaintStandardTexture(CVTFPreviewPanel *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // esi
  float v6; // xmm0_4
  float v7; // xmm2_4
  int tw; // [esp+Ch] [ebp-Ch]
  int w; // [esp+10h] [ebp-8h] BYREF
  int h; // [esp+14h] [ebp-4h] BYREF

  v2 = 0;
  v3 = 0;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nTextureID);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  tw = this->m_PreviewTexture.m_pTexture->GetActualWidth(this: this->m_PreviewTexture.m_pTexture);
  v4 = this->m_PreviewTexture.m_pTexture->GetActualHeight(this: this->m_PreviewTexture.m_pTexture);
  v5 = h;
  if ( v4 > 0 && h > 0 )
  {
    v6 = (float)tw / (float)v4;
    if ( (float)(v6 / (float)((float)w / (float)h)) <= 1.0 )
    {
      v7 = (float)h * v6;
      v3 = (w - (int)v7) / 2;
      w = (int)v7;
    }
    else
    {
      v5 = (int)(float)((float)w / v6);
      v2 = (h - v5) / 2;
      h = v5;
    }
  }
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: v3, a3: v2, a4: v3 + w, a5: v2 + v5);
}

//------------------------------------------------------------------------------
// Address: 0x004CDB30
// Name: private: void CVTFPreviewPanel::RenderSphere(class Vector const __near &,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::RenderSphere(
        CVTFPreviewPanel *this,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi)
{
  IMaterialSystem *v6; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *m_pObject; // esi
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v13; // eax
  float v14; // xmm1_4
  double v15; // xmm0_8
  unsigned int v16; // xmm0_4
  double v17; // xmm0_8
  double v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  float y; // xmm0_4
  float x; // xmm5_4
  float z; // xmm3_4
  float *m_pCurrPosition; // eax
  float v25; // xmm2_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float *m_pCurrNormal; // eax
  float v34; // xmm4_4
  int v35; // xmm3_4
  float *v36; // eax
  float *v37; // eax
  float *v38; // eax
  float *v39; // eax
  float *v40; // eax
  unsigned int m_nCurrentIndex; // eax
  int v42; // ecx
  bool v43; // zf
  int m_nVertexCount; // eax
  long double v45; // [esp+0h] [ebp-23Ch]
  long double v46; // [esp+0h] [ebp-23Ch]
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-234h] BYREF
  float v48; // [esp+1F0h] [ebp-4Ch]
  Vector vecNormal; // [esp+1F4h] [ebp-48h] BYREF
  float v; // [esp+200h] [ebp-3Ch]
  unsigned int theta; // [esp+204h] [ebp-38h]
  float v52; // [esp+208h] [ebp-34h]
  CMatRenderContextPtr pRenderContext; // [esp+20Ch] [ebp-30h]
  IMesh *pMesh; // [esp+210h] [ebp-2Ch]
  Vector vecPos; // [esp+214h] [ebp-28h]
  unsigned int phi; // [esp+220h] [ebp-1Ch]
  int u; // [esp+224h] [ebp-18h]
  Vector4D vecTangentS; // [esp+228h] [ebp-14h] BYREF
  int i; // [esp+238h] [ebp-4h]
  int j; // [esp+244h] [ebp+8h]
  int ja; // [esp+244h] [ebp+8h]
  int flRadiusa; // [esp+248h] [ebp+Ch]
  __int16 idx; // [esp+250h] [ebp+14h]

  v6 = vgui::MaterialSystem();
  v7 = v6->GetRenderContext(this: v6);
  m_pObject = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  m_pObject->FogMode(this: m_pObject, a2: MATERIAL_FOG_NONE);
  m_pObject->SetNumBoneWeights(this: m_pObject, a2: 0);
  m_pObject->Bind(this: m_pObject, a2: this->m_PreviewMaterial.m_pMaterial, a3: nullptr);
  pMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v9 = nTheta;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLE_STRIP,
    nVertexCount: nPhi * nTheta,
    nIndexCount: (nTheta + 1) * (2 * nPhi - 2),
    pMeshSettings: nullptr);
  v10 = nPhi;
  v11 = 0;
  i = 0;
  if ( nPhi > 0 )
  {
    do
    {
      v13 = 0;
      j = 0;
      if ( nTheta > 0 )
      {
        v48 = (float)(nTheta - 1);
        v14 = (float)v11 / (float)(nPhi - 1);
        v = v14;
        while ( 1 )
        {
          *(float *)&u = (float)v13 / v48;
          if ( v13 == nTheta - 1 )
            v15 = 0.0;
          else
            v15 = (float)((float)v13 / v48) * 6.283185307179586;
          *(float *)&v16 = v15;
          theta = v16;
          *(float *)&phi = v14 * 3.141592653589793;
          v17 = *(float *)&phi;
          __libm_sse2_sin(x: v45);
          *(float *)&v17 = v17;
          v52 = *(float *)&v17 * flRadius;
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)theta));
          *(float *)&v18 = v18;
          vecPos.x = *(float *)&v18 * v52;
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)phi));
          *(float *)&v19 = v19;
          vecPos.y = *(float *)&v19 * flRadius;
          v20 = *(float *)&theta;
          __libm_sse2_sin(x: v46);
          *(float *)&v20 = v20;
          LODWORD(vecPos.z) = COERCE_UNSIGNED_INT(*(float *)&v20 * v52) ^ _mask__NegFloat_;
          vecNormal = vecPos;
          VectorNormalize(vec: &vecNormal);
          vecTangentS.x = vecPos.z;
          vecTangentS.y = -vecPos.x;
          vecTangentS.z = 0.0;
          vecTangentS.w = 1.0;
          if ( VectorNormalize(vec: (Vector *)&vecTangentS) == 0.0 )
          {
            y = 0.0;
            x = 1.0;
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
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v25 = vecNormal.y * z;
          v26 = vecNormal.y * x;
          v27 = vecNormal.z * y;
          v28 = vecNormal.z * x;
          v29 = vCenter->z + vecPos.z;
          v30 = v28 - (float)(z * vecNormal.x);
          v31 = (float)(y * vecNormal.x) - v26;
          v32 = vCenter->y;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + vecPos.x;
          m_pCurrPosition[1] = v32 + vecPos.y;
          m_pCurrPosition[2] = v29;
          m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
          *meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal.x;
          m_pCurrNormal[1] = vecNormal.y;
          v34 = v;
          m_pCurrNormal[2] = vecNormal.z;
          v35 = u;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)(int)(float)(v34 * 255.0)
                                                              | (((unsigned __int8)(int)(float)(v34 * 255.0)
                                                                | ((((unsigned __int8)(int)(float)(v34 * 255.0) << 8)
                                                                  | (unsigned __int8)(int)(float)(*(float *)&u * 255.0)) << 8)) << 8);
          v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v35;
          v36[1] = v34;
          v37 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v35;
          v37[1] = v34;
          v38 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v35;
          v38[1] = v34;
          v39 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
          *v39 = vecTangentS.x;
          v39[1] = vecTangentS.y;
          v39[2] = vecTangentS.z;
          v40 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
          *v40 = v25 - v27;
          v40[1] = v30;
          v40[2] = v31;
          if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
            *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                     * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
          meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
          *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_UserData) = vecTangentS;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++j >= nTheta )
            break;
          v14 = v;
          v13 = j;
        }
        v11 = i;
      }
      i = ++v11;
    }
    while ( v11 < nPhi );
    m_pObject = pRenderContext.m_pObject;
    v10 = nPhi;
  }
  idx = 0;
  i = 0;
  phi = v10 - 1;
  if ( v10 - 1 > 0 )
  {
    u = v10 - 2;
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    flRadiusa = 0;
    do
    {
      if ( v9 > 0 )
      {
        v42 = flRadiusa;
        ja = v9;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v42
                                                                 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          v9 = nTheta;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                            + v42
                                                                                            + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          idx = v42++;
          v43 = ja-- == 1;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( !v43 );
        m_pObject = pRenderContext.m_pObject;
      }
      if ( i < u )
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                               + idx
                                                               + 1;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                          + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                          + idx
                                                                                          + 1;
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      flRadiusa += v9;
      ++i;
    }
    while ( i < (int)phi );
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x004CE1B0
// Name: private: void CVTFPreviewPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVTFPreviewPanel::LookAt(
        CVTFPreviewPanel *this@<ecx>,
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
// Address: 0x004CE450
// Name: private: void CVTFPreviewPanel::SetupProjectionMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::SetupProjectionMatrix(CVTFPreviewPanel *this, int nWidth, int nHeight)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi
  float v6; // xmm0_4
  double v7; // xmm0_8
  VMatrix proj; // [esp+4h] [ebp-40h] BYREF
  float flApsectRatio; // [esp+50h] [ebp+Ch]

  v3 = vgui::MaterialSystem();
  v4 = (int)v3->GetRenderContext(this: v3);
  v5 = v4;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  if ( (float)nHeight == 0.0 )
    v6 = 100.0;
  else
    v6 = (float)nWidth / (float)nHeight;
  flApsectRatio = v6;
  __libm_sse2_tan(X: (__m128i)0x3FE921FB54442D18uLL);
  *(float *)&v7 = v7;
  memset(dst: (unsigned __int8 *)&proj, value: 0, count: sizeof(proj));
  proj.m[1][1] = 1.0 / (float)(*(float *)&v7 / flApsectRatio);
  *(_QWORD *)&proj.m[2][2] = 0xBDCCCF6CBF8001A3uLL;
  proj.m[3][2] = -1.0;
  proj.m[0][0] = 1.0 / *(float *)&v7;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
  (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v5 + 96))(a1: v5, a2: &proj);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004CE550
// Name: private: void CVTFPreviewPanel::PaintCubeTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::PaintCubeTexture(CVTFPreviewPanel *this)
{
  long double v1; // rdi
  double v2; // st7
  double v3; // st7
  float angleDegrees; // [esp+8h] [ebp-5Ch]
  VMatrix rot; // [esp+14h] [ebp-50h] BYREF
  Vector vecTemp; // [esp+54h] [ebp-10h] BYREF
  float flNewTime; // [esp+60h] [ebp-4h]

  HIDWORD(v1) = this;
  v2 = _Plat_FloatTime();
  flNewTime = v2;
  angleDegrees = (v2 - *(float *)(HIDWORD(v1) + 376)) * 120.0;
  MatrixBuildRotateZ(dst: &rot, angleDegrees);
  LODWORD(v1) = HIDWORD(v1) + 364;
  Vector3DMultiply(src1: &rot, src2: (Vector *)(HIDWORD(v1) + 364), dst: &vecTemp);
  v3 = flNewTime;
  *(Vector *)(HIDWORD(v1) + 364) = vecTemp;
  *(float *)(HIDWORD(v1) + 376) = v3;
  CVTFPreviewPanel::LookAt(this: (CVTFPreviewPanel *)HIDWORD(v1), a2: v1, vecLookAt: &vec3_origin, flRadius: 12.0);
  CVTFPreviewPanel::RenderSphere(
    this: (CVTFPreviewPanel *)HIDWORD(v1),
    vCenter: &vec3_origin,
    flRadius: 10.0,
    nTheta: 20,
    nPhi: 20);
}

//------------------------------------------------------------------------------
// Address: 0x004CE600
// Name: public: virtual void CVTFPreviewPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVTFPreviewPanel::Paint(CVTFPreviewPanel *this@<ecx>, int a2@<esi>)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi
  IMatSystemSurface *v6; // eax
  IMatSystemSurface *v7; // eax
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_PreviewTexture.m_pTexture->IsCubeMap(this: this->m_PreviewTexture.m_pTexture)
    || this->m_PreviewTexture.m_pTexture->IsVolumeTexture(this: this->m_PreviewTexture.m_pTexture) )
  {
    v3 = vgui::MaterialSystem();
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))v3->GetRenderContext)(a1: v3, a2);
    v5 = v4;
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    v6 = vgui::MatSystemSurface();
    ((void (__thiscall *)(IMatSystemSurface *, _DWORD, _DWORD, int))v6->Begin3DPaint)(a1: v6, a2: 0, a3: 0, a4: w);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v5 + 296))(a1: v5, a2: 76, a3: 88, a4: 68, a5: 255);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v5 + 48))(a1: v5, a2: 1, a3: 1, a4: 0);
    CVTFPreviewPanel::SetupProjectionMatrix(this, nWidth: w, nHeight: h);
    if ( this->m_PreviewTexture.m_pTexture->IsCubeMap(this: this->m_PreviewTexture.m_pTexture) )
    {
      CVTFPreviewPanel::PaintCubeTexture(this);
    }
    else if ( !this->m_PreviewTexture.m_pTexture->IsNormalMap(this: this->m_PreviewTexture.m_pTexture) )
    {
      this->m_PreviewTexture.m_pTexture->IsVolumeTexture(this: this->m_PreviewTexture.m_pTexture);
    }
    v7 = vgui::MatSystemSurface();
    v7->End3DPaint(this: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  }
  else
  {
    CVTFPreviewPanel::PaintStandardTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE720
// Name: public: CVTFPreviewPanel::CVTFPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPreviewPanel *__thiscall CVTFPreviewPanel::CVTFPreviewPanel(
        CVTFPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IMatSystemSurface *v7; // eax

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CVTFPreviewPanel_vtbl *)&CVTFPreviewPanel::`vftable';
  if ( `CVTFPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVTFPreviewPanel");
    v4->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CVTFPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVTFPreviewPanel");
    v5->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CVTFPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPreviewPanel");
    v6->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CUtlString::CUtlString(this: &this->m_VTFName);
  CTextureReference::CTextureReference(this: &this->m_PreviewTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_PreviewMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CVTFPreviewPanel::SetVTF(this, pFullPath: "//platform/materials/vgui/vtfnotloaded", bLoadImmediately: true);
  v7 = vgui::MatSystemSurface();
  this->m_nTextureID = v7->CreateNewTextureID(this: v7, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004CE830
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPreviewPanel::GetMessageMap(CVTFPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CVTFPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPreviewPanel");
  `CVTFPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CE860
// Name: public: virtual struct PanelAnimationMap __near * CVTFPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPreviewPanel::GetAnimMap(CVTFPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004CE870
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPreviewPanel::GetKBMap(CVTFPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CVTFPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPreviewPanel");
  `CVTFPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CE8A0
// Name: public: virtual CVTFPreviewPanel::~CVTFPreviewPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::~CVTFPreviewPanel(CVTFPreviewPanel *this)
{
  bool v2; // sf

  CMaterialReference::~CMaterialReference(this: &this->m_PreviewMaterial);
  CTextureReference::~CTextureReference(this: &this->m_PreviewTexture);
  v2 = this->m_VTFName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_VTFName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_VTFName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VTFName.m_Storage.m_Memory.m_pMemory);
      this->m_VTFName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_VTFName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D2210
// Name: public: static char const __near * CVTFPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPreviewPanel::GetPanelClassName()
{
  return "CVTFPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104D2220
// Name: public: void CVTFPreviewPanel::SetVTF(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x104D2350
// Name: private: void CVTFPreviewPanel::PaintStandardTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::PaintStandardTexture(CVTFPreviewPanel *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // esi
  float v6; // xmm0_4
  float v7; // xmm2_4
  int tw; // [esp+Ch] [ebp-Ch]
  int w; // [esp+10h] [ebp-8h] BYREF
  int h; // [esp+14h] [ebp-4h] BYREF

  v2 = 0;
  v3 = 0;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nTextureID);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  tw = this->m_PreviewTexture.m_pTexture->GetActualWidth(this: this->m_PreviewTexture.m_pTexture);
  v4 = this->m_PreviewTexture.m_pTexture->GetActualHeight(this: this->m_PreviewTexture.m_pTexture);
  v5 = h;
  if ( v4 > 0 && h > 0 )
  {
    v6 = (float)tw / (float)v4;
    if ( (float)(v6 / (float)((float)w / (float)h)) <= 1.0 )
    {
      v7 = (float)h * v6;
      v3 = (w - (int)v7) / 2;
      w = (int)v7;
    }
    else
    {
      v5 = (int)(float)((float)w / v6);
      v2 = (h - v5) / 2;
      h = v5;
    }
  }
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: v3, a3: v2, a4: v3 + w, a5: v2 + v5);
}

//------------------------------------------------------------------------------
// Address: 0x104D2460
// Name: private: void CVTFPreviewPanel::RenderSphere(class Vector const __near &,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::RenderSphere(
        CVTFPreviewPanel *this,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi)
{
  IMaterialSystem *v6; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *m_pObject; // esi
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v13; // eax
  float v14; // xmm1_4
  double v15; // xmm0_8
  float v16; // xmm0_4
  double v17; // xmm0_8
  double v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  float y; // xmm0_4
  float x; // xmm5_4
  float z; // xmm3_4
  float *m_pCurrPosition; // eax
  float v25; // xmm2_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float *m_pCurrNormal; // eax
  float v34; // xmm4_4
  int v35; // xmm3_4
  float *v36; // eax
  float *v37; // eax
  float *v38; // eax
  float *v39; // eax
  float *v40; // eax
  unsigned int m_nCurrentIndex; // eax
  int v42; // ecx
  bool v43; // zf
  int m_nVertexCount; // eax
  long double v45; // [esp+0h] [ebp-23Ch]
  long double v46; // [esp+0h] [ebp-23Ch]
  long double v47; // [esp+0h] [ebp-23Ch]
  long double v48; // [esp+0h] [ebp-23Ch]
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-234h] BYREF
  float v50; // [esp+1F0h] [ebp-4Ch]
  Vector vecNormal; // [esp+1F4h] [ebp-48h] BYREF
  float v; // [esp+200h] [ebp-3Ch]
  float theta; // [esp+204h] [ebp-38h]
  float v54; // [esp+208h] [ebp-34h]
  CMatRenderContextPtr pRenderContext; // [esp+20Ch] [ebp-30h]
  IMesh *pMesh; // [esp+210h] [ebp-2Ch]
  Vector vecPos; // [esp+214h] [ebp-28h]
  int phi; // [esp+220h] [ebp-1Ch]
  int u; // [esp+224h] [ebp-18h]
  Vector4D vecTangentS; // [esp+228h] [ebp-14h] BYREF
  int i; // [esp+238h] [ebp-4h]
  int j; // [esp+244h] [ebp+8h]
  int ja; // [esp+244h] [ebp+8h]
  int flRadiusa; // [esp+248h] [ebp+Ch]
  __int16 idx; // [esp+250h] [ebp+14h]

  v6 = vgui::MaterialSystem();
  v7 = v6->GetRenderContext(this: v6);
  m_pObject = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  m_pObject->FogMode(this: m_pObject, a2: MATERIAL_FOG_NONE);
  m_pObject->SetNumBoneWeights(this: m_pObject, a2: 0);
  m_pObject->Bind(this: m_pObject, a2: this->m_PreviewMaterial.m_pMaterial, a3: nullptr);
  pMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v9 = nTheta;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLE_STRIP,
    nVertexCount: nPhi * nTheta,
    nIndexCount: (nTheta + 1) * (2 * nPhi - 2),
    pMeshSettings: nullptr);
  v10 = nPhi;
  v11 = 0;
  i = 0;
  if ( nPhi > 0 )
  {
    do
    {
      v13 = 0;
      j = 0;
      if ( nTheta > 0 )
      {
        v50 = (float)(nTheta - 1);
        v14 = (float)v11 / (float)(nPhi - 1);
        v = v14;
        while ( 1 )
        {
          *(float *)&u = (float)v13 / v50;
          if ( v13 == nTheta - 1 )
            v15 = 0.0;
          else
            v15 = (float)((float)v13 / v50) * 6.283185307179586;
          v16 = v15;
          theta = v16;
          *(float *)&phi = v14 * 3.141592653589793;
          v17 = *(float *)&phi;
          __libm_sse2_sin(x: v45);
          *(float *)&v17 = v17;
          v54 = *(float *)&v17 * flRadius;
          v18 = theta;
          __libm_sse2_cos(x: v46);
          *(float *)&v18 = v18;
          vecPos.x = *(float *)&v18 * v54;
          v19 = *(float *)&phi;
          __libm_sse2_cos(x: v47);
          *(float *)&v19 = v19;
          vecPos.y = *(float *)&v19 * flRadius;
          v20 = theta;
          __libm_sse2_sin(x: v48);
          *(float *)&v20 = v20;
          LODWORD(vecPos.z) = COERCE_UNSIGNED_INT(*(float *)&v20 * v54) ^ _mask__NegFloat_;
          vecNormal = vecPos;
          VectorNormalize(vec: &vecNormal);
          vecTangentS.x = vecPos.z;
          vecTangentS.y = -vecPos.x;
          vecTangentS.z = 0.0;
          vecTangentS.w = 1.0;
          if ( VectorNormalize(vec: (Vector *)&vecTangentS) == 0.0 )
          {
            y = 0.0;
            x = 1.0;
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
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v25 = vecNormal.y * z;
          v26 = vecNormal.y * x;
          v27 = vecNormal.z * y;
          v28 = vecNormal.z * x;
          v29 = vCenter->z + vecPos.z;
          v30 = v28 - (float)(z * vecNormal.x);
          v31 = (float)(y * vecNormal.x) - v26;
          v32 = vCenter->y;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + vecPos.x;
          m_pCurrPosition[1] = v32 + vecPos.y;
          m_pCurrPosition[2] = v29;
          m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
          *meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal.x;
          m_pCurrNormal[1] = vecNormal.y;
          v34 = v;
          m_pCurrNormal[2] = vecNormal.z;
          v35 = u;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)(int)(float)(v34 * 255.0)
                                                              | (((unsigned __int8)(int)(float)(v34 * 255.0)
                                                                | ((((unsigned __int8)(int)(float)(v34 * 255.0) << 8)
                                                                  | (unsigned __int8)(int)(float)(*(float *)&u * 255.0)) << 8)) << 8);
          v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v35;
          v36[1] = v34;
          v37 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v35;
          v37[1] = v34;
          v38 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v35;
          v38[1] = v34;
          v39 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
          *v39 = vecTangentS.x;
          v39[1] = vecTangentS.y;
          v39[2] = vecTangentS.z;
          v40 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
          *v40 = v25 - v27;
          v40[1] = v30;
          v40[2] = v31;
          if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
            *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                     * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
          meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
          *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_UserData) = vecTangentS;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++j >= nTheta )
            break;
          v14 = v;
          v13 = j;
        }
        v11 = i;
      }
      i = ++v11;
    }
    while ( v11 < nPhi );
    m_pObject = pRenderContext.m_pObject;
    v10 = nPhi;
  }
  idx = 0;
  i = 0;
  phi = v10 - 1;
  if ( v10 - 1 > 0 )
  {
    u = v10 - 2;
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    flRadiusa = 0;
    do
    {
      if ( v9 > 0 )
      {
        v42 = flRadiusa;
        ja = v9;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v42
                                                                 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          v9 = nTheta;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                            + v42
                                                                                            + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          idx = v42++;
          v43 = ja-- == 1;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( !v43 );
        m_pObject = pRenderContext.m_pObject;
      }
      if ( i < u )
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                               + idx
                                                               + 1;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                          + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                          + idx
                                                                                          + 1;
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      flRadiusa += v9;
      ++i;
    }
    while ( i < phi );
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x104D2AE0
// Name: private: void CVTFPreviewPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVTFPreviewPanel::LookAt(
        CVTFPreviewPanel *this@<ecx>,
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
// Address: 0x104D2D80
// Name: private: void CVTFPreviewPanel::SetupProjectionMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CVTFPreviewPanel::SetupProjectionMatrix(CVTFPreviewPanel *this, int nWidth, int nHeight)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi
  float v6; // xmm0_4
  _BYTE v7[68]; // [esp+0h] [ebp-44h] OVERLAPPED BYREF

  v3 = vgui::MaterialSystem();
  v4 = (int)v3->GetRenderContext(this: v3);
  v5 = v4;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  if ( (float)nHeight == 0.0 )
    v6 = 100.0;
  else
    v6 = (float)nWidth / (float)nHeight;
  __libm_sse2_tan(x: *(long double *)v7);
  memset(dst: &v7[4], value: 0, count: 0x40u);
  *(float *)&v7[24] = 1.0 / (float)((float)0.7853981633974483 / v6);
  *(_QWORD *)&v7[44] = 0xBDCCCF6CBF8001A3uLL;
  *(_DWORD *)&v7[60] = -1082130432;
  *(float *)&v7[4] = 1.0 / (float)0.7853981633974483;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
  (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v5 + 96))(a1: v5, a2: &v7[4]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x104D2E80
// Name: private: void CVTFPreviewPanel::PaintCubeTexture(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CVTFPreviewPanel::PaintCubeTexture(CVTFPreviewPanel *this)
{
  double v1; // rdi
  double v2; // st7
  double v3; // st7
  float v4; // [esp-4h] [ebp-5Ch]
  int flRadius; // [esp+0h] [ebp-58h]
  int v6; // [esp+4h] [ebp-54h]
  _DWORD angleDegrees[3]; // [esp+8h] [ebp-50h] BYREF
  VMatrix rot; // [esp+14h] [ebp-44h] BYREF
  float vecTemp; // [esp+54h] [ebp-4h] OVERLAPPED

  HIDWORD(v1) = this;
  v2 = _Plat_FloatTime(a1: flRadius, a2: v6, a3: angleDegrees[0], a4: angleDegrees[1], a5: angleDegrees[2]);
  vecTemp = v2;
  v4 = (v2 - *(float *)(HIDWORD(v1) + 376)) * 120.0;
  MatrixBuildRotateZ(dst: (VMatrix *)angleDegrees, angleDegrees: v4);
  LODWORD(v1) = HIDWORD(v1) + 364;
  Vector3DMultiply(
    src1: (const VMatrix *)angleDegrees,
    src2: (Vector *)(HIDWORD(v1) + 364),
    dst: (Vector *)&rot.m[3][1]);
  v3 = vecTemp;
  *(Vector *)(HIDWORD(v1) + 364) = *(Vector *)&rot.m[3][1];
  *(float *)(HIDWORD(v1) + 376) = v3;
  CVTFPreviewPanel::LookAt(this: (CVTFPreviewPanel *)HIDWORD(v1), a2: v1, vecLookAt: &vec3_origin, flRadius: 12.0);
  CVTFPreviewPanel::RenderSphere(
    this: (CVTFPreviewPanel *)HIDWORD(v1),
    vCenter: &vec3_origin,
    flRadius: 10.0,
    nTheta: 20,
    nPhi: 20);
}

//------------------------------------------------------------------------------
// Address: 0x104D2F30
// Name: public: virtual void CVTFPreviewPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVTFPreviewPanel::Paint(CVTFPreviewPanel *this@<ecx>, int a2@<esi>)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi
  IMatSystemSurface *v6; // eax
  IMatSystemSurface *v7; // eax
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_PreviewTexture.m_pTexture->IsCubeMap(this: this->m_PreviewTexture.m_pTexture)
    || this->m_PreviewTexture.m_pTexture->IsVolumeTexture(this: this->m_PreviewTexture.m_pTexture) )
  {
    v3 = vgui::MaterialSystem();
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))v3->GetRenderContext)(a1: v3, a2);
    v5 = v4;
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    v6 = vgui::MatSystemSurface();
    ((void (__thiscall *)(IMatSystemSurface *, _DWORD, _DWORD, int))v6->Begin3DPaint)(a1: v6, a2: 0, a3: 0, a4: w);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v5 + 296))(a1: v5, a2: 76, a3: 88, a4: 68, a5: 255);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v5 + 48))(a1: v5, a2: 1, a3: 1, a4: 0);
    CVTFPreviewPanel::SetupProjectionMatrix(this, nWidth: w, nHeight: h);
    if ( this->m_PreviewTexture.m_pTexture->IsCubeMap(this: this->m_PreviewTexture.m_pTexture) )
    {
      CVTFPreviewPanel::PaintCubeTexture(this);
    }
    else if ( !this->m_PreviewTexture.m_pTexture->IsNormalMap(this: this->m_PreviewTexture.m_pTexture) )
    {
      this->m_PreviewTexture.m_pTexture->IsVolumeTexture(this: this->m_PreviewTexture.m_pTexture);
    }
    v7 = vgui::MatSystemSurface();
    v7->End3DPaint(this: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  }
  else
  {
    CVTFPreviewPanel::PaintStandardTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D3050
// Name: public: CVTFPreviewPanel::CVTFPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPreviewPanel *__thiscall CVTFPreviewPanel::CVTFPreviewPanel(
        CVTFPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IMatSystemSurface *v7; // eax

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CVTFPreviewPanel_vtbl *)&CVTFPreviewPanel::`vftable';
  if ( `CVTFPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVTFPreviewPanel");
    v4->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CVTFPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVTFPreviewPanel");
    v5->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CVTFPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPreviewPanel");
    v6->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CUtlString::CUtlString(this: &this->m_VTFName);
  CTextureReference::CTextureReference(this: &this->m_PreviewTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_PreviewMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CVTFPreviewPanel::SetVTF(this, pFullPath: "//platform/materials/vgui/vtfnotloaded", bLoadImmediately: true);
  v7 = vgui::MatSystemSurface();
  this->m_nTextureID = v7->CreateNewTextureID(this: v7, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104D3160
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPreviewPanel::GetMessageMap(CVTFPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CVTFPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPreviewPanel");
  `CVTFPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D3190
// Name: public: virtual struct PanelAnimationMap __near * CVTFPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPreviewPanel::GetAnimMap(CVTFPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104D31A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPreviewPanel::GetKBMap(CVTFPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CVTFPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPreviewPanel");
  `CVTFPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104D31D0
// Name: public: virtual CVTFPreviewPanel::~CVTFPreviewPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::~CVTFPreviewPanel(CVTFPreviewPanel *this)
{
  bool v2; // sf

  CMaterialReference::~CMaterialReference(this: &this->m_PreviewMaterial);
  CTextureReference::~CTextureReference(this: &this->m_PreviewTexture);
  v2 = this->m_VTFName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_VTFName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_VTFName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VTFName.m_Storage.m_Memory.m_pMemory);
      this->m_VTFName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_VTFName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004E8C00
// Name: public: static char const __near * CVTFPreviewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVTFPreviewPanel::GetPanelClassName()
{
  return "CVTFPreviewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004E8C10
// Name: public: void CVTFPreviewPanel::SetVTF(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::SetVTF(CVTFPreviewPanel *this, const char *pFullPath, bool bLoadImmediately)
{
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  IMaterialSystem *v6; // eax
  IMaterial *v7; // eax
  IMatSystemSurface *v8; // eax

  CTextureReference::Init(
    this: &this->m_PreviewTexture,
    pTextureName: pFullPath,
    pTextureGroupName: "editor texture",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  CUtlString::operator=(this: &this->m_VTFName, src: pFullPath);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "UnlitGeneric");
  else
    v5 = nullptr;
  if ( this->m_PreviewTexture.m_pTexture->IsCubeMap(this: this->m_PreviewTexture.m_pTexture) )
  {
    KeyValues::SetString(this: v5, keyName: "$envmap", value: pFullPath);
  }
  else if ( this->m_PreviewTexture.m_pTexture->IsNormalMap(this: this->m_PreviewTexture.m_pTexture) )
  {
    KeyValues::SetString(this: v5, keyName: "$bumpmap", value: pFullPath);
  }
  else
  {
    KeyValues::SetString(this: v5, keyName: "$basetexture", value: pFullPath);
  }
  KeyValues::SetInt(this: v5, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v5, keyName: "$nodebug", value: 1);
  v6 = vgui::MaterialSystem();
  v7 = v6->CreateMaterial(this: v6, a2: pFullPath, a3: v5);
  CMaterialReference::Init(this: &this->m_PreviewMaterial, pMaterial: v7);
  v8 = vgui::MatSystemSurface();
  v8->DrawSetTextureMaterial(this: v8, a2: this->m_nTextureID, a3: this->m_PreviewMaterial.m_pMaterial);
  this->m_vecCameraDirection.x = 1.0;
  this->m_vecCameraDirection.y = 0.0;
  this->m_vecCameraDirection.z = 0.0;
  this->m_flLastRotationTime = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x004E8D40
// Name: private: void CVTFPreviewPanel::PaintStandardTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::PaintStandardTexture(CVTFPreviewPanel *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // esi
  float v6; // xmm0_4
  float v7; // xmm2_4
  int tw; // [esp+Ch] [ebp-Ch]
  int w; // [esp+10h] [ebp-8h] BYREF
  int h; // [esp+14h] [ebp-4h] BYREF

  v2 = 0;
  v3 = 0;
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nTextureID);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  tw = this->m_PreviewTexture.m_pTexture->GetActualWidth(this: this->m_PreviewTexture.m_pTexture);
  v4 = this->m_PreviewTexture.m_pTexture->GetActualHeight(this: this->m_PreviewTexture.m_pTexture);
  v5 = h;
  if ( v4 > 0 && h > 0 )
  {
    v6 = (float)tw / (float)v4;
    if ( (float)(v6 / (float)((float)w / (float)h)) <= 1.0 )
    {
      v7 = (float)h * v6;
      v3 = (w - (int)v7) / 2;
      w = (int)v7;
    }
    else
    {
      v5 = (int)(float)((float)w / v6);
      v2 = (h - v5) / 2;
      h = v5;
    }
  }
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: v3, a3: v2, a4: v3 + w, a5: v2 + v5);
}

//------------------------------------------------------------------------------
// Address: 0x004E8E50
// Name: private: void CVTFPreviewPanel::RenderSphere(class Vector const __near &,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::RenderSphere(
        CVTFPreviewPanel *this,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi)
{
  IMaterialSystem *v6; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *m_pObject; // esi
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v13; // eax
  float v14; // xmm1_4
  double v15; // xmm0_8
  float v16; // xmm0_4
  double v17; // xmm0_8
  double v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  float y; // xmm0_4
  float x; // xmm5_4
  float z; // xmm3_4
  float *m_pCurrPosition; // eax
  float v25; // xmm2_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float *m_pCurrNormal; // eax
  float v34; // xmm4_4
  int v35; // xmm3_4
  float *v36; // eax
  float *v37; // eax
  float *v38; // eax
  float *v39; // eax
  float *v40; // eax
  unsigned int m_nCurrentIndex; // eax
  int v42; // ecx
  bool v43; // zf
  int m_nVertexCount; // eax
  long double v45; // [esp+0h] [ebp-23Ch]
  long double v46; // [esp+0h] [ebp-23Ch]
  long double v47; // [esp+0h] [ebp-23Ch]
  long double v48; // [esp+0h] [ebp-23Ch]
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-234h] BYREF
  float v50; // [esp+1F0h] [ebp-4Ch]
  Vector vecNormal; // [esp+1F4h] [ebp-48h] BYREF
  float v; // [esp+200h] [ebp-3Ch]
  float theta; // [esp+204h] [ebp-38h]
  float v54; // [esp+208h] [ebp-34h]
  CMatRenderContextPtr pRenderContext; // [esp+20Ch] [ebp-30h]
  IMesh *pMesh; // [esp+210h] [ebp-2Ch]
  Vector vecPos; // [esp+214h] [ebp-28h]
  int phi; // [esp+220h] [ebp-1Ch]
  int u; // [esp+224h] [ebp-18h]
  Vector4D vecTangentS; // [esp+228h] [ebp-14h] BYREF
  int i; // [esp+238h] [ebp-4h]
  int j; // [esp+244h] [ebp+8h]
  int ja; // [esp+244h] [ebp+8h]
  int flRadiusa; // [esp+248h] [ebp+Ch]
  __int16 idx; // [esp+250h] [ebp+14h]

  v6 = vgui::MaterialSystem();
  v7 = v6->GetRenderContext(this: v6);
  m_pObject = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  m_pObject->FogMode(this: m_pObject, a2: MATERIAL_FOG_NONE);
  m_pObject->SetNumBoneWeights(this: m_pObject, a2: 0);
  m_pObject->Bind(this: m_pObject, a2: this->m_PreviewMaterial.m_pMaterial, a3: nullptr);
  pMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v9 = nTheta;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLE_STRIP,
    nVertexCount: nPhi * nTheta,
    nIndexCount: (nTheta + 1) * (2 * nPhi - 2),
    pMeshSettings: nullptr);
  v10 = nPhi;
  v11 = 0;
  i = 0;
  if ( nPhi > 0 )
  {
    do
    {
      v13 = 0;
      j = 0;
      if ( nTheta > 0 )
      {
        v50 = (float)(nTheta - 1);
        v14 = (float)v11 / (float)(nPhi - 1);
        v = v14;
        while ( 1 )
        {
          *(float *)&u = (float)v13 / v50;
          if ( v13 == nTheta - 1 )
            v15 = 0.0;
          else
            v15 = (float)((float)v13 / v50) * 6.283185307179586;
          v16 = v15;
          theta = v16;
          *(float *)&phi = v14 * 3.141592653589793;
          v17 = *(float *)&phi;
          __libm_sse2_sin(x: v45);
          *(float *)&v17 = v17;
          v54 = *(float *)&v17 * flRadius;
          v18 = theta;
          __libm_sse2_cos(x: v46);
          *(float *)&v18 = v18;
          vecPos.x = *(float *)&v18 * v54;
          v19 = *(float *)&phi;
          __libm_sse2_cos(x: v47);
          *(float *)&v19 = v19;
          vecPos.y = *(float *)&v19 * flRadius;
          v20 = theta;
          __libm_sse2_sin(x: v48);
          *(float *)&v20 = v20;
          LODWORD(vecPos.z) = COERCE_UNSIGNED_INT(*(float *)&v20 * v54) ^ _mask__NegFloat_;
          vecNormal = vecPos;
          VectorNormalize(vec: &vecNormal);
          vecTangentS.x = vecPos.z;
          vecTangentS.y = -vecPos.x;
          vecTangentS.z = 0.0;
          vecTangentS.w = 1.0;
          if ( VectorNormalize(vec: (Vector *)&vecTangentS) == 0.0 )
          {
            y = 0.0;
            x = 1.0;
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
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v25 = vecNormal.y * z;
          v26 = vecNormal.y * x;
          v27 = vecNormal.z * y;
          v28 = vecNormal.z * x;
          v29 = vCenter->z + vecPos.z;
          v30 = v28 - (float)(z * vecNormal.x);
          v31 = (float)(y * vecNormal.x) - v26;
          v32 = vCenter->y;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + vecPos.x;
          m_pCurrPosition[1] = v32 + vecPos.y;
          m_pCurrPosition[2] = v29;
          m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
          *meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal.x;
          m_pCurrNormal[1] = vecNormal.y;
          v34 = v;
          m_pCurrNormal[2] = vecNormal.z;
          v35 = u;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (unsigned __int8)(int)(float)(v34 * 255.0)
                                                              | (((unsigned __int8)(int)(float)(v34 * 255.0)
                                                                | ((((unsigned __int8)(int)(float)(v34 * 255.0) << 8)
                                                                  | (unsigned __int8)(int)(float)(*(float *)&u * 255.0)) << 8)) << 8);
          v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v35;
          v36[1] = v34;
          v37 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v35;
          v37[1] = v34;
          v38 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v35;
          v38[1] = v34;
          v39 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
          *v39 = vecTangentS.x;
          v39[1] = vecTangentS.y;
          v39[2] = vecTangentS.z;
          v40 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
          *v40 = v25 - v27;
          v40[1] = v30;
          v40[2] = v31;
          if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
            *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                     * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
          meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
          *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                      + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_UserData) = vecTangentS;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++j >= nTheta )
            break;
          v14 = v;
          v13 = j;
        }
        v11 = i;
      }
      i = ++v11;
    }
    while ( v11 < nPhi );
    m_pObject = pRenderContext.m_pObject;
    v10 = nPhi;
  }
  idx = 0;
  i = 0;
  phi = v10 - 1;
  if ( v10 - 1 > 0 )
  {
    u = v10 - 2;
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    flRadiusa = 0;
    do
    {
      if ( v9 > 0 )
      {
        v42 = flRadiusa;
        ja = v9;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v42
                                                                 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          v9 = nTheta;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nTheta
                                                                                            + v42
                                                                                            + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          idx = v42++;
          v43 = ja-- == 1;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( !v43 );
        m_pObject = pRenderContext.m_pObject;
      }
      if ( i < u )
      {
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                               + idx
                                                               + 1;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = v9
                                                                                          + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                          + idx
                                                                                          + 1;
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      }
      flRadiusa += v9;
      ++i;
    }
    while ( i < phi );
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x004E94D0
// Name: private: void CVTFPreviewPanel::LookAt(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVTFPreviewPanel::LookAt(
        CVTFPreviewPanel *this@<ecx>,
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
// Address: 0x004E9770
// Name: private: void CVTFPreviewPanel::SetupProjectionMatrix(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CVTFPreviewPanel::SetupProjectionMatrix(CVTFPreviewPanel *this, int nWidth, int nHeight)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi
  float v6; // xmm0_4
  _BYTE v7[68]; // [esp+0h] [ebp-44h] OVERLAPPED BYREF

  v3 = vgui::MaterialSystem();
  v4 = (int)v3->GetRenderContext(this: v3);
  v5 = v4;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  if ( (float)nHeight == 0.0 )
    v6 = 100.0;
  else
    v6 = (float)nWidth / (float)nHeight;
  __libm_sse2_tan(x: *(long double *)v7);
  memset(dst: &v7[4], value: 0, count: 0x40u);
  *(float *)&v7[24] = 1.0 / (float)((float)0.7853981633974483 / v6);
  *(_QWORD *)&v7[44] = 0xBDCCCF6CBF8001A3uLL;
  *(_DWORD *)&v7[60] = -1082130432;
  *(float *)&v7[4] = 1.0 / (float)0.7853981633974483;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
  (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v5 + 96))(a1: v5, a2: &v7[4]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004E9870
// Name: private: void CVTFPreviewPanel::PaintCubeTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::PaintCubeTexture(CVTFPreviewPanel *this)
{
  double v1; // rdi
  double v2; // st7
  double v3; // st7
  float angleDegrees; // [esp+8h] [ebp-5Ch]
  VMatrix rot; // [esp+14h] [ebp-50h] BYREF
  Vector vecTemp; // [esp+54h] [ebp-10h] BYREF
  float flNewTime; // [esp+60h] [ebp-4h]

  HIDWORD(v1) = this;
  v2 = _Plat_FloatTime();
  flNewTime = v2;
  angleDegrees = (v2 - *(float *)(HIDWORD(v1) + 376)) * 120.0;
  MatrixBuildRotateZ(dst: &rot, angleDegrees);
  LODWORD(v1) = HIDWORD(v1) + 364;
  Vector3DMultiply(src1: &rot, src2: (Vector *)(HIDWORD(v1) + 364), dst: &vecTemp);
  v3 = flNewTime;
  *(Vector *)(HIDWORD(v1) + 364) = vecTemp;
  *(float *)(HIDWORD(v1) + 376) = v3;
  CVTFPreviewPanel::LookAt(this: (CVTFPreviewPanel *)HIDWORD(v1), a2: v1, vecLookAt: &vec3_origin, flRadius: 12.0);
  CVTFPreviewPanel::RenderSphere(
    this: (CVTFPreviewPanel *)HIDWORD(v1),
    vCenter: &vec3_origin,
    flRadius: 10.0,
    nTheta: 20,
    nPhi: 20);
}

//------------------------------------------------------------------------------
// Address: 0x004E9920
// Name: public: virtual void CVTFPreviewPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVTFPreviewPanel::Paint(CVTFPreviewPanel *this@<ecx>, int a2@<esi>)
{
  IMaterialSystem *v3; // eax
  int v4; // eax
  int v5; // esi
  IMatSystemSurface *v6; // eax
  IMatSystemSurface *v7; // eax
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_PreviewTexture.m_pTexture->IsCubeMap(this: this->m_PreviewTexture.m_pTexture)
    || this->m_PreviewTexture.m_pTexture->IsVolumeTexture(this: this->m_PreviewTexture.m_pTexture) )
  {
    v3 = vgui::MaterialSystem();
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))v3->GetRenderContext)(a1: v3, a2);
    v5 = v4;
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    v6 = vgui::MatSystemSurface();
    ((void (__thiscall *)(IMatSystemSurface *, _DWORD, _DWORD, int))v6->Begin3DPaint)(a1: v6, a2: 0, a3: 0, a4: w);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v5 + 296))(a1: v5, a2: 76, a3: 88, a4: 68, a5: 255);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v5 + 48))(a1: v5, a2: 1, a3: 1, a4: 0);
    CVTFPreviewPanel::SetupProjectionMatrix(this, nWidth: w, nHeight: h);
    if ( this->m_PreviewTexture.m_pTexture->IsCubeMap(this: this->m_PreviewTexture.m_pTexture) )
    {
      CVTFPreviewPanel::PaintCubeTexture(this);
    }
    else if ( !this->m_PreviewTexture.m_pTexture->IsNormalMap(this: this->m_PreviewTexture.m_pTexture) )
    {
      this->m_PreviewTexture.m_pTexture->IsVolumeTexture(this: this->m_PreviewTexture.m_pTexture);
    }
    v7 = vgui::MatSystemSurface();
    v7->End3DPaint(this: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  }
  else
  {
    CVTFPreviewPanel::PaintStandardTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9A40
// Name: public: CVTFPreviewPanel::CVTFPreviewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFPreviewPanel *__thiscall CVTFPreviewPanel::CVTFPreviewPanel(
        CVTFPreviewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  IMatSystemSurface *v7; // eax

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CVTFPreviewPanel_vtbl *)&CVTFPreviewPanel::`vftable';
  if ( `CVTFPreviewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVTFPreviewPanel");
    v4->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CVTFPreviewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVTFPreviewPanel");
    v5->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CVTFPreviewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVTFPreviewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPreviewPanel");
    v6->pfnClassName = CVTFPreviewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CUtlString::CUtlString(this: &this->m_VTFName);
  CTextureReference::CTextureReference(this: &this->m_PreviewTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_PreviewMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CVTFPreviewPanel::SetVTF(this, pFullPath: "//platform/materials/vgui/vtfnotloaded", bLoadImmediately: true);
  v7 = vgui::MatSystemSurface();
  this->m_nTextureID = v7->CreateNewTextureID(this: v7, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E9B50
// Name: public: virtual struct vgui::PanelMessageMap __near * CVTFPreviewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVTFPreviewPanel::GetMessageMap(CVTFPreviewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVTFPreviewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPreviewPanel::GetMessageMap'::`2'::s_pMap;
  `CVTFPreviewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVTFPreviewPanel");
  `CVTFPreviewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E9B80
// Name: public: virtual struct PanelAnimationMap __near * CVTFPreviewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVTFPreviewPanel::GetAnimMap(CVTFPreviewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CVTFPreviewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004E9B90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVTFPreviewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVTFPreviewPanel::GetKBMap(CVTFPreviewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVTFPreviewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVTFPreviewPanel::GetKBMap'::`2'::s_pMap;
  `CVTFPreviewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVTFPreviewPanel");
  `CVTFPreviewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E9BC0
// Name: public: virtual CVTFPreviewPanel::~CVTFPreviewPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTFPreviewPanel::~CVTFPreviewPanel(CVTFPreviewPanel *this)
{
  bool v2; // sf

  CMaterialReference::~CMaterialReference(this: &this->m_PreviewMaterial);
  CTextureReference::~CTextureReference(this: &this->m_PreviewTexture);
  v2 = this->m_VTFName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_VTFName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_VTFName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VTFName.m_Storage.m_Memory.m_pMemory);
      this->m_VTFName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_VTFName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

} // namespace sceneviewer
