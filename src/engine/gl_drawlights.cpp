// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_drawlights.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100C3370
// Name: bool ActivateLightSprites(bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ActivateLightSprites(bool bActive)
{
  bool result; // al

  result = s_bActivateLightSprites;
  s_bActivateLightSprites = bActive;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C3390
// Name: float ComputeLightRadius(struct dworldlight_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ComputeLightRadius(dworldlight_t *pLight, bool bIsHDR)
{
  float v3; // xmm3_4
  float quadratic_attn; // xmm1_4
  float linear_attn; // xmm0_4
  long double result; // st7
  float discrim; // [esp+8h] [ebp-4h]
  float discrima; // [esp+8h] [ebp-4h]
  float flLightRadius; // [esp+14h] [ebp+8h]

  flLightRadius = pLight->radius;
  if ( flLightRadius != 0.0 )
    return flLightRadius;
  if ( bIsHDR )
    v3 = 0.015;
  else
    v3 = 0.029999999;
  quadratic_attn = pLight->quadratic_attn;
  linear_attn = pLight->linear_attn;
  discrim = sqrt(
              pLight->intensity.x * pLight->intensity.x
            + pLight->intensity.y * pLight->intensity.y
            + pLight->intensity.z * pLight->intensity.z);
  if ( quadratic_attn != 0.0 )
  {
    discrima = (float)(linear_attn * linear_attn)
             - (float)((float)(pLight->constant_attn - (float)(discrim / v3)) * (float)(quadratic_attn * 4.0));
    if ( discrima < 0.0 )
      return 2000.0;
    result = (sqrt(discrima) - linear_attn) / (quadratic_attn + quadratic_attn);
    if ( result >= 0.0 )
      return result;
    return 0.0;
  }
  if ( linear_attn == 0.0 )
    return 2000.0;
  return (float)((float)((float)(discrim / v3) - pLight->constant_attn) / linear_attn);
}

//------------------------------------------------------------------------------
// Address: 0x100C3490
// Name: DrawLightSprite
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawLightSprite(dworldlight_t *pLight@<eax>, int a2@<edi>, float angleAttenFactor)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float y; // ecx
  float z; // edx
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // ebx
  IMesh *v10; // edi
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float x; // xmm2_4
  float v15; // xmm4_4
  float *v16; // eax
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float *m_pCurrPosition; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float *v31; // eax
  float *v32; // eax
  float *v33; // eax
  float v34; // xmm5_4
  float v35; // xmm4_4
  float v36; // xmm6_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float *v42; // eax
  float *v43; // eax
  float v44; // xmm5_4
  float v45; // xmm4_4
  float v46; // xmm6_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float *v52; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-22Ch] BYREF
  Vector lightToEye; // [esp+1E8h] [ebp-44h] BYREF
  Vector p; // [esp+1F4h] [ebp-38h]
  Vector right; // [esp+200h] [ebp-2Ch] BYREF
  Vector up; // [esp+20Ch] [ebp-20h] BYREF
  float v59; // [esp+218h] [ebp-14h]
  float v60; // [esp+21Ch] [ebp-10h]
  Vector color; // [esp+220h] [ebp-Ch] BYREF
  float angleAttenFactora; // [esp+234h] [ebp+8h]
  float angleAttenFactorb; // [esp+234h] [ebp+8h]
  float angleAttenFactorc; // [esp+234h] [ebp+8h]
  float angleAttenFactord; // [esp+234h] [ebp+8h]

  v4 = g_CurrentViewOrigin.y - pLight->origin.y;
  v5 = g_CurrentViewOrigin.z - pLight->origin.z;
  lightToEye.x = g_CurrentViewOrigin.x - pLight->origin.x;
  lightToEye.y = v4;
  lightToEye.z = v5;
  VectorNormalize(vec: &lightToEye);
  up.z = 1.0;
  right.x = (float)(lightToEye.z * 0.0) - lightToEye.y;
  up.x = 0.0;
  up.y = 0.0;
  right.y = lightToEye.x - (float)(lightToEye.z * 0.0);
  right.z = (float)(lightToEye.y * 0.0) - (float)(lightToEye.x * 0.0);
  VectorNormalize(vec: &right);
  up.x = (float)(right.z * lightToEye.y) - (float)(right.y * lightToEye.z);
  up.y = (float)(lightToEye.z * right.x) - (float)(right.z * lightToEye.x);
  up.z = (float)(right.y * lightToEye.x) - (float)(lightToEye.y * right.x);
  VectorNormalize(vec: &up);
  y = pLight->intensity.y;
  z = pLight->intensity.z;
  color.x = pLight->intensity.x;
  color.y = y;
  color.z = z;
  VectorNormalize(vec: &color);
  color.y = color.y * angleAttenFactor;
  color.z = angleAttenFactor * color.z;
  color.x = pow(color.x * angleAttenFactor, 0.4545454382896423);
  color.y = pow(color.y, 0.4545454382896423);
  color.z = pow(color.z, 0.4545454382896423);
  v8 = materials->GetRenderContext(this: materials);
  v9 = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))v9->Bind)(
    a1: v9,
    a2: g_pMaterialLightSprite,
    a3: 0,
    a4: a2);
  v10 = v9->GetDynamicMesh(this: v9, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v10;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v10->SetPrimitiveType(this: v10, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v10->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v10, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v11 = color.y;
  v12 = color.z;
  if ( color.y <= color.z )
    v13 = color.z;
  else
    v13 = color.y;
  x = color.x;
  if ( color.x <= v13 )
  {
    if ( color.y <= color.z )
      v15 = color.z;
    else
      v15 = color.y;
  }
  else
  {
    v15 = color.x;
  }
  if ( v15 > 1.0 )
  {
    x = color.x * (float)(1.0 / v15);
    v11 = color.y * (float)(1.0 / v15);
    v12 = color.z * (float)(1.0 / v15);
    color.x = x;
    color.y = v11;
    color.z = v12;
  }
  if ( x < 0.0 )
    color.x = 0.0;
  if ( v11 < 0.0 )
    color.y = 0.0;
  if ( v12 < 0.0 )
    color.z = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v17 = up.z * 16.0;
  v18 = up.y * 16.0;
  v19 = up.x * 16.0;
  v20 = right.z * 16.0;
  v21 = pLight->origin.x + (float)(right.x * 16.0);
  v22 = pLight->origin.y + (float)(right.y * 16.0);
  v23 = pLight->origin.z;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v16[1] = 1.0;
  v24 = v21 + v19;
  v25 = (float)(v23 + v20) + v17;
  v26 = v22 + v18;
  p.x = v24;
  p.y = v26;
  p.z = v25;
  v60 = (float)(color.z * 255.0) + 8388608.0;
  v59 = (float)(color.y * 255.0) + 8388608.0;
  angleAttenFactora = (float)(color.x * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v60)
                                                      | ((LOBYTE(v59) | ((LOBYTE(angleAttenFactora) | 0xFFFFFF00) << 8)) << 8);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
  m_pCurrPosition[1] = v26;
  m_pCurrPosition[2] = v25;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v29 = (float)(pLight->origin.y + (float)(right.y * -16.0)) + (float)(up.y * 16.0);
  v30 = (float)(pLight->origin.z + (float)(right.z * -16.0)) + (float)(up.z * 16.0);
  p.x = (float)((float)(right.x * -16.0) + pLight->origin.x) + (float)(up.x * 16.0);
  v28 = p.x;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v31[1] = 1.0;
  p.y = v29;
  p.z = v30;
  v59 = (float)(color.z * 255.0) + 8388608.0;
  v60 = (float)(color.y * 255.0) + 8388608.0;
  angleAttenFactorb = (float)(color.x * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v59)
                                                      | ((LOBYTE(v60) | ((LOBYTE(angleAttenFactorb) | 0xFFFFFF00) << 8)) << 8);
  v32 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v28;
  v32[1] = v29;
  v32[2] = v30;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v33 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v34 = up.z * -16.0;
  v35 = up.y * -16.0;
  v36 = right.z * -16.0;
  v37 = pLight->origin.y + (float)(right.y * -16.0);
  v38 = pLight->origin.z;
  v39 = (float)((float)(right.x * -16.0) + pLight->origin.x) + (float)(up.x * -16.0);
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v33[1] = 0.0;
  v40 = (float)(v38 + v36) + v34;
  v41 = v37 + v35;
  p.x = v39;
  p.y = v41;
  p.z = v40;
  v59 = (float)(color.z * 255.0) + 8388608.0;
  v60 = (float)(color.y * 255.0) + 8388608.0;
  angleAttenFactorc = (float)(color.x * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v59)
                                                      | ((LOBYTE(v60) | ((LOBYTE(angleAttenFactorc) | 0xFFFFFF00) << 8)) << 8);
  v42 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39;
  v42[1] = v41;
  v42[2] = v40;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v43 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v44 = up.z * -16.0;
  v45 = up.y * -16.0;
  v46 = right.z * 16.0;
  v47 = (float)((float)(right.x * 16.0) + pLight->origin.x) + (float)(up.x * -16.0);
  v48 = pLight->origin.y + (float)(right.y * 16.0);
  v49 = pLight->origin.z;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v43[1] = 0.0;
  v50 = (float)(v49 + v46) + v44;
  v51 = v48 + v45;
  p.x = v47;
  p.y = v51;
  p.z = v50;
  v59 = (float)(color.z * 255.0) + 8388608.0;
  v60 = (float)(color.y * 255.0) + 8388608.0;
  angleAttenFactord = (float)(color.x * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v59)
                                                      | ((LOBYTE(v60) | ((LOBYTE(angleAttenFactord) | 0xFFFFFF00) << 8)) << 8);
  v52 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v47;
  v52[1] = v51;
  v52[2] = v50;
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
  v9->EndRender(this: v9);
  v9->Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x100C3CF0
// Name: void DrawSpotLight(struct dworldlight_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSpotLight(dworldlight_t *pLight)
{
  int v2; // edi
  int v3; // ecx
  float z; // xmm1_4
  float y; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  int (*GetRenderContext)(void); // eax
  float v9; // xmm2_4
  float v10; // xmm1_4
  int v11; // eax
  int v12; // ebx
  long double v13; // st7
  float v14; // xmm0_4
  float v15; // xmm1_4
  float x; // xmm2_4
  float v17; // xmm4_4
  int v18; // ebx
  float *m_pCurrPosition; // eax
  long double v20; // st6
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  bool v28; // zf
  int v29; // eax
  signed int m_nCurrentIndex; // ecx
  int v31; // edx
  __int16 v32; // ax
  __int16 v33; // si
  signed int v34; // ecx
  signed int v35; // ecx
  signed int v36; // ecx
  signed int v37; // ecx
  signed int v38; // ecx
  signed int v39; // ecx
  signed int v40; // ecx
  int m_nVertexCount; // eax
  CMeshBuilder v42; // [esp+20h] [ebp-230h] BYREF
  float v43; // [esp+208h] [ebp-48h]
  float v44; // [esp+20Ch] [ebp-44h]
  float v45; // [esp+210h] [ebp-40h]
  float v46; // [esp+214h] [ebp-3Ch]
  int v47; // [esp+218h] [ebp-38h]
  int flTanAngle; // [esp+21Ch] [ebp-34h]
  Vector yaxis; // [esp+220h] [ebp-30h]
  CMatRenderContextPtr pRenderContext; // [esp+22Ch] [ebp-24h]
  int nGridLines; // [esp+230h] [ebp-20h] BYREF
  float flGridLineDist; // [esp+234h] [ebp-1Ch]
  float v53; // [esp+238h] [ebp-18h]
  float flDist; // [esp+23Ch] [ebp-14h]
  float flRadius; // [esp+240h] [ebp-10h]
  Vector xaxis; // [esp+244h] [ebp-Ch]
  float vecCenter_4; // [esp+258h] [ebp+8h]
  int vecCenter_4a; // [esp+258h] [ebp+8h]

  xaxis.z = ComputeLightRadius(pLight, bIsHDR: false);
  RenderWireframeSphere(
    vCenter: &pLight->origin,
    flRadius: xaxis.z,
    nTheta: 20,
    nPhi: 20,
    c: (Color)-16776961,
    bZBuffer: true);
  yaxis.x = 50.0;
  v2 = 1 - (int)(float)(xaxis.z * -0.02);
  flTanAngle = v2;
  if ( v2 > 256 )
  {
    v2 = 256;
    flTanAngle = 256;
    yaxis.x = xaxis.z * 0.0039215689;
  }
  v3 = fabs(pLight->normal.y) <= fabs(pLight->normal.x);
  if ( fabs(pLight->normal.z) <= fabs(*(&pLight->normal.x + v3)) )
    v3 = 2;
  z = pLight->normal.z;
  flRadius = vec3_origin.x;
  xaxis.x = vec3_origin.y;
  xaxis.y = vec3_origin.z;
  *(&flRadius + v3) = 1.0;
  y = pLight->normal.y;
  *(float *)&nGridLines = (float)(z * xaxis.x) - (float)(y * xaxis.y);
  v6 = (float)(y * flRadius) - (float)(pLight->normal.x * xaxis.x);
  flGridLineDist = (float)(pLight->normal.x * xaxis.y) - (float)(z * flRadius);
  v53 = v6;
  VectorNormalize(vec: (Vector *)&nGridLines);
  v7 = pLight->normal.z;
  GetRenderContext = (int (*)(void))materials->GetRenderContext;
  v9 = pLight->normal.y * *(float *)&nGridLines;
  v44 = (float)(pLight->normal.y * v53) - (float)(v7 * flGridLineDist);
  v10 = (float)(pLight->normal.x * flGridLineDist) - v9;
  v45 = (float)(v7 * *(float *)&nGridLines) - (float)(pLight->normal.x * v53);
  v46 = v10;
  v11 = GetRenderContext();
  v12 = v11;
  v47 = v11;
  if ( v11 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 8))(a1: v11);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v12 + 36))(
    a1: v12,
    a2: g_materialWorldWireframeZBuffer,
    a3: 0);
  LODWORD(xaxis.z) = (*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12 + 228))(
                       a1: v12,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
  CMeshBuilder::CMeshBuilder(this: &v42);
  CMeshBuilder::Begin(
    this: &v42,
    pMesh: (IMesh *)LODWORD(xaxis.z),
    type: MATERIAL_LINES,
    nVertexCount: 8 * v2 + 8,
    nIndexCount: v2 << 6,
    pMeshSettings: nullptr);
  v13 = tan(acos(pLight->stopdot2));
  v14 = 0.0;
  yaxis.z = 0.0;
  v43 = v13;
  if ( v2 >= 0 )
  {
    LODWORD(yaxis.y) = v2 + 1;
    do
    {
      v15 = (float)(v14 * pLight->normal.x) + pLight->origin.x;
      x = (float)(pLight->normal.y * v14) + pLight->origin.y;
      v17 = (float)(v14 * pLight->normal.z) + pLight->origin.z;
      *(float *)&pRenderContext.m_pObject = v14 * v43;
      flRadius = v15;
      xaxis.x = x;
      xaxis.y = v17;
      vecCenter_4 = 0.0;
      v18 = 8;
      while ( 1 )
      {
        m_pCurrPosition = v42.m_VertexBuilder.m_pCurrPosition;
        v20 = vecCenter_4 * 0.017453292;
        flDist = cos(v20) * *(float *)&pRenderContext.m_pObject;
        v21 = (float)(flDist * *(float *)&nGridLines) + v15;
        v22 = (float)(flGridLineDist * flDist) + x;
        v23 = (float)(v53 * flDist) + v17;
        flDist = *(float *)&pRenderContext.m_pObject * sin(v20);
        v24 = flDist;
        v25 = (float)(flDist * v44) + v21;
        v26 = (float)(v45 * flDist) + v22;
        v27 = v46;
        *v42.m_VertexBuilder.m_pCurrPosition = v25;
        m_pCurrPosition[1] = v26;
        m_pCurrPosition[2] = (float)(v27 * v24) + v23;
        CVertexBuilder::AdvanceVertex(this: &v42.m_VertexBuilder);
        --v18;
        vecCenter_4 = vecCenter_4 + 45.0;
        if ( v18 == 0 )
          break;
        v17 = xaxis.y;
        x = xaxis.x;
        v15 = flRadius;
      }
      v28 = LODWORD(yaxis.y)-- == 1;
      v14 = yaxis.z + yaxis.x;
      yaxis.z = yaxis.z + yaxis.x;
    }
    while ( !v28 );
    v12 = v47;
  }
  LOWORD(v29) = 0;
  vecCenter_4a = 0;
  if ( v2 > 0 )
  {
    m_nCurrentIndex = v42.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      v31 = 0;
      v32 = 8 * v29;
      do
      {
        if ( v31 == 7 )
          v33 = 0;
        else
          v33 = v31 + 1;
        v42.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v32 + v31 + LOWORD(v42.m_IndexBuilder.m_nIndexOffset);
        v34 = v42.m_IndexBuilder.m_nIndexSize + v42.m_IndexBuilder.m_nCurrentIndex;
        v42.m_IndexBuilder.m_nCurrentIndex = v34;
        if ( v34 > v42.m_IndexBuilder.m_nIndexCount )
          v42.m_IndexBuilder.m_nIndexCount = v34;
        v42.m_IndexBuilder.m_pIndices[v34] = v31 + LOWORD(v42.m_IndexBuilder.m_nIndexOffset) + v32 + 8;
        v35 = v42.m_IndexBuilder.m_nIndexSize + v42.m_IndexBuilder.m_nCurrentIndex;
        v42.m_IndexBuilder.m_nCurrentIndex = v35;
        if ( v35 > v42.m_IndexBuilder.m_nIndexCount )
          v42.m_IndexBuilder.m_nIndexCount = v35;
        v42.m_IndexBuilder.m_pIndices[v35] = v31 + LOWORD(v42.m_IndexBuilder.m_nIndexOffset) + v32 + 8;
        v36 = v42.m_IndexBuilder.m_nIndexSize + v42.m_IndexBuilder.m_nCurrentIndex;
        v42.m_IndexBuilder.m_nCurrentIndex = v36;
        if ( v36 > v42.m_IndexBuilder.m_nIndexCount )
          v42.m_IndexBuilder.m_nIndexCount = v36;
        v42.m_IndexBuilder.m_pIndices[v36] = v33 + LOWORD(v42.m_IndexBuilder.m_nIndexOffset) + v32 + 8;
        v37 = v42.m_IndexBuilder.m_nIndexSize + v42.m_IndexBuilder.m_nCurrentIndex;
        v42.m_IndexBuilder.m_nCurrentIndex = v37;
        if ( v37 > v42.m_IndexBuilder.m_nIndexCount )
          v42.m_IndexBuilder.m_nIndexCount = v37;
        v42.m_IndexBuilder.m_pIndices[v37] = v33 + LOWORD(v42.m_IndexBuilder.m_nIndexOffset) + v32 + 8;
        v38 = v42.m_IndexBuilder.m_nIndexSize + v42.m_IndexBuilder.m_nCurrentIndex;
        v42.m_IndexBuilder.m_nCurrentIndex = v38;
        if ( v38 > v42.m_IndexBuilder.m_nIndexCount )
          v42.m_IndexBuilder.m_nIndexCount = v38;
        v42.m_IndexBuilder.m_pIndices[v38] = v32 + v33 + LOWORD(v42.m_IndexBuilder.m_nIndexOffset);
        v39 = v42.m_IndexBuilder.m_nIndexSize + v42.m_IndexBuilder.m_nCurrentIndex;
        v42.m_IndexBuilder.m_nCurrentIndex = v39;
        if ( v39 > v42.m_IndexBuilder.m_nIndexCount )
          v42.m_IndexBuilder.m_nIndexCount = v39;
        v42.m_IndexBuilder.m_pIndices[v39] = v32 + v33 + LOWORD(v42.m_IndexBuilder.m_nIndexOffset);
        v40 = v42.m_IndexBuilder.m_nIndexSize + v42.m_IndexBuilder.m_nCurrentIndex;
        v42.m_IndexBuilder.m_nCurrentIndex = v40;
        if ( v40 > v42.m_IndexBuilder.m_nIndexCount )
          v42.m_IndexBuilder.m_nIndexCount = v40;
        v42.m_IndexBuilder.m_pIndices[v40] = v32 + v31 + LOWORD(v42.m_IndexBuilder.m_nIndexOffset);
        m_nCurrentIndex = v42.m_IndexBuilder.m_nIndexSize + v42.m_IndexBuilder.m_nCurrentIndex;
        v42.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        if ( m_nCurrentIndex > v42.m_IndexBuilder.m_nIndexCount )
          v42.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        ++v31;
      }
      while ( v31 < 8 );
      v29 = vecCenter_4a + 1;
      vecCenter_4a = v29;
    }
    while ( v29 < flTanAngle );
    v12 = v47;
  }
  if ( v42.m_bGenerateIndices )
  {
    switch ( v42.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * v42.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * v42.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * v42.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * v42.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = v42.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(this: &v42.m_IndexBuilder, primitiveType: v42.m_Type, nIndexCount: m_nVertexCount);
  }
  v42.m_pMesh->UnlockMesh(
    this: v42.m_pMesh,
    a2: v42.m_VertexBuilder.m_nVertexCount,
    a3: v42.m_IndexBuilder.m_nIndexCount,
    a4: &v42);
  v42.m_IndexBuilder.m_pIndexBuffer = nullptr;
  v42.m_IndexBuilder.m_nMaxIndexCount = 0;
  v42.m_VertexBuilder.m_nMaxVertexCount = 0;
  v42.m_VertexBuilder.m_pVertexBuffer = nullptr;
  v42.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  v42.m_pMesh = nullptr;
  (*(void (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)LODWORD(xaxis.z) + 48))(a1: LODWORD(xaxis.z), a2: -1, a3: 0);
  if ( v42.m_VertexBuilder.m_pVertexBuffer != nullptr
    && v42.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v42.m_VertexBuilder.m_pVertexBuffer) )
  {
    v42.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v42.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( v42.m_IndexBuilder.m_pIndexBuffer != nullptr
    && v42.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v42.m_IndexBuilder.m_pIndexBuffer) )
  {
    v42.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v42.m_IndexBuilder.m_pIndexBuffer);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 12))(a1: v12);
  (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 4))(a1: v12);
}

//------------------------------------------------------------------------------
// Address: 0x100C4370
// Name: void DrawLightSprites(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DrawLightSprites(int a1@<ebp>)
{
  worldbrushdata_t *worldbrush; // eax
  int v2; // edi
  dworldlight_t *v3; // esi
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6[13]; // [esp+Ch] [ebp-D4h] BYREF
  CGameTrace tr; // [esp+40h] [ebp-A0h] BYREF
  int v8; // [esp+94h] [ebp-4Ch]
  _BYTE ray[68]; // [esp+98h] [ebp-48h] OVERLAPPED BYREF
  int ray_72; // [esp+E0h] [ebp+0h]

  *(_DWORD *)&ray[60] = a1;
  *(_DWORD *)&ray[64] = ray_72;
  if ( s_bActivateLightSprites )
  {
    worldbrush = host_state.worldbrush;
    *(_DWORD *)&ray[56] = 0;
    if ( host_state.worldbrush->numworldlights > 0 )
    {
      v2 = 0;
      do
      {
        v3 = &worldbrush->worldlights[v2];
        *(_DWORD *)&ray[52] = &CTraceFilterWorldAndPropsOnly::`vftable';
        *(_DWORD *)&ray[12] = 0;
        *(float *)&tr.dispFlags = v3->origin.x - g_CurrentViewOrigin.x;
        tr.fractionleftsolid = v3->origin.y - g_CurrentViewOrigin.y;
        *(float *)&tr.surface.name = v3->origin.z - g_CurrentViewOrigin.z;
        ray[17] = (float)((float)((float)(tr.fractionleftsolid * tr.fractionleftsolid)
                                + (float)(*(float *)&tr.dispFlags * *(float *)&tr.dispFlags))
                        + (float)(*(float *)&tr.surface.name * *(float *)&tr.surface.name)) != 0.0;
        *(_DWORD *)&ray[12] = 0;
        *(_DWORD *)&ray[4] = 0;
        *(_DWORD *)ray = 0;
        v8 = 0;
        ray[16] = 1;
        memset(&tr.hitgroup, 0, 12);
        *(Vector *)&tr.plane.dist = g_CurrentViewOrigin;
        g_pEngineTraceClient->TraceRay(
          this: g_pEngineTraceClient,
          a2: (const Ray_t *)&tr.plane.dist,
          a3: 16513u,
          a4: (ITraceFilter *)&ray[52],
          a5: (CGameTrace *)v6);
        if ( v6[11] >= 1.0 )
        {
          v4 = g_CurrentViewOrigin.y - v3->origin.y;
          v5 = g_CurrentViewOrigin.z - v3->origin.z;
          *(float *)&ray[40] = g_CurrentViewOrigin.x - v3->origin.x;
          *(float *)&ray[44] = v4;
          *(float *)&ray[48] = v5;
          VectorNormalize(vec: (Vector *)&ray[40]);
          if ( v3->type == emit_point )
            DrawLightSprite(pLight: v3, a2: v2 * 100, angleAttenFactor: 1.0);
        }
        worldbrush = host_state.worldbrush;
        ++v2;
        ++*(_DWORD *)&ray[56];
      }
      while ( *(int *)&ray[56] < host_state.worldbrush->numworldlights );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4520
// Name: void DrawLightDebuggingInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawLightDebuggingInfo()
{
  int v0; // ebx
  worldbrushdata_t *worldbrush; // eax
  int i; // edi
  dworldlight_t *v3; // esi
  int v4; // ebx
  int v5; // edi
  dworldlight_t *worldlights; // esi
  emittype_t type; // ecx
  dworldlight_t *v8; // esi
  __int32 v9; // ecx
  float quadratic_attn; // xmm1_4
  float linear_attn; // xmm0_4
  float constant_attn; // xmm3_4
  long double v13; // st7
  int v14; // edi
  Vector *p_origin; // esi
  double x; // st7
  float v17; // [esp-14h] [ebp-138h]
  float duration; // [esp+Ch] [ebp-118h] BYREF
  char buf[256]; // [esp+20h] [ebp-104h]
  Color c; // [esp+120h] [ebp-4h]

  v0 = 0;
  if ( r_drawlights.m_pParent != nullptr )
    c = (Color)r_drawlights.m_pParent->m_Value.m_nValue;
  else
    c = 0;
  if ( r_drawlightinfo.m_pParent != nullptr && r_drawlightinfo.m_pParent->m_Value.m_nValue != 0 )
  {
    worldbrush = host_state.worldbrush;
    for ( i = 0; i < host_state.worldbrush->numworldlights; ++v0 )
    {
      ++i;
      v3 = &worldbrush->worldlights[v0];
      V_snprintf(pDest: (char *)&duration, maxLen: 256, pFormat: "light:  %d\n", i);
      CDebugOverlay::AddTextOverlay(textPos: &v3->origin, line_offset: 0, duration: 0.0, text: (const char *)&duration);
      V_snprintf(
        pDest: (char *)&duration,
        maxLen: 256,
        pFormat: "origin: <%d, %d, %d>\n",
        (int)v3->origin.x,
        (int)v3->origin.y,
        (int)v3->origin.z);
      CDebugOverlay::AddTextOverlay(textPos: &v3->origin, line_offset: 1, duration: 0.0, text: (const char *)&duration);
      if ( c == 0 )
        DrawLightSprite(pLight: v3, a2: i, angleAttenFactor: 1.0);
      worldbrush = host_state.worldbrush;
    }
  }
  else
  {
    worldbrush = host_state.worldbrush;
  }
  if ( c != 0 )
  {
    v4 = 0;
    if ( worldbrush->numworldlights > 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        worldlights = worldbrush->worldlights;
        type = worldlights[v5].type;
        v8 = &worldlights[v5];
        v9 = type - 1;
        if ( v9 == 0 )
          break;
        if ( v9 == 1 )
        {
          DrawSpotLight(pLight: v8);
LABEL_28:
          DrawLightSprite(pLight: v8, a2: v5 * 100, angleAttenFactor: 1.0);
          worldbrush = host_state.worldbrush;
        }
        ++v4;
        ++v5;
        if ( v4 >= worldbrush->numworldlights )
          goto LABEL_30;
      }
      *(float *)&buf[252] = v8->radius;
      if ( *(float *)&buf[252] == 0.0 )
      {
        quadratic_attn = v8->quadratic_attn;
        linear_attn = v8->linear_attn;
        *(float *)&buf[248] = sqrt(
                                v8->intensity.x * v8->intensity.x
                              + v8->intensity.y * v8->intensity.y
                              + v8->intensity.z * v8->intensity.z);
        if ( quadratic_attn == 0.0 )
        {
          if ( linear_attn == 0.0 )
            *(_DWORD *)&buf[252] = 1157234688;
          else
            *(float *)&buf[252] = (float)((float)(*(float *)&buf[248] * 33.333336) - v8->constant_attn) / linear_attn;
        }
        else
        {
          constant_attn = v8->constant_attn;
          *(float *)&buf[240] = quadratic_attn;
          *(float *)&buf[236] = linear_attn;
          *(float *)&buf[244] = (float)(linear_attn * linear_attn)
                              - (float)((float)(constant_attn - (float)(*(float *)&buf[248] * 33.333336))
                                      * (float)(quadratic_attn * 4.0));
          if ( *(float *)&buf[244] >= 0.0 )
          {
            v13 = (sqrt(*(float *)&buf[244]) - *(float *)&buf[236]) / (*(float *)&buf[240] + *(float *)&buf[240]);
            *(float *)&buf[252] = v13;
            if ( v13 < 0.0 )
              *(_DWORD *)&buf[252] = 0;
          }
          else
          {
            *(_DWORD *)&buf[252] = 1157234688;
          }
        }
      }
      c = (Color)-256;
      RenderWireframeSphere(
        vCenter: &v8->origin,
        flRadius: *(float *)&buf[252],
        nTheta: 8,
        nPhi: 8,
        c: (Color)-256,
        bZBuffer: true);
      goto LABEL_28;
    }
LABEL_30:
    v14 = 1;
    p_origin = &cl_dlights[0].origin;
    do
    {
      if ( (v14 & r_dlightactive) != 0 )
      {
        x = p_origin[1].x;
        c = (Color)-256;
        v17 = x;
        RenderWireframeSphere(vCenter: p_origin, flRadius: v17, nTheta: 8, nPhi: 8, c: (Color)-256, bZBuffer: true);
      }
      p_origin = (Vector *)((char *)p_origin + 68);
      v14 = __ROL4__(v14, 1);
    }
    while ( (int)p_origin < (int)&cl_elights[0].origin );
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100C2FA0
// Name: bool ActivateLightSprites(bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ActivateLightSprites(bool bActive)
{
  bool result; // al

  result = s_bActivateLightSprites;
  s_bActivateLightSprites = bActive;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C2FC0
// Name: float ComputeLightRadius(struct dworldlight_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ComputeLightRadius(dworldlight_t *pLight, bool bIsHDR)
{
  float v3; // xmm3_4
  float quadratic_attn; // xmm1_4
  float linear_attn; // xmm0_4
  long double result; // st7
  float discrim; // [esp+8h] [ebp-4h]
  float discrima; // [esp+8h] [ebp-4h]
  float flLightRadius; // [esp+14h] [ebp+8h]

  flLightRadius = pLight->radius;
  if ( flLightRadius != 0.0 )
    return flLightRadius;
  if ( bIsHDR )
    v3 = 0.015;
  else
    v3 = 0.029999999;
  quadratic_attn = pLight->quadratic_attn;
  linear_attn = pLight->linear_attn;
  discrim = sqrt(
              pLight->intensity.x * pLight->intensity.x
            + pLight->intensity.y * pLight->intensity.y
            + pLight->intensity.z * pLight->intensity.z);
  if ( quadratic_attn != 0.0 )
  {
    discrima = (float)(linear_attn * linear_attn)
             - (float)((float)(pLight->constant_attn - (float)(discrim / v3)) * (float)(quadratic_attn * 4.0));
    if ( discrima < 0.0 )
      return 2000.0;
    result = (sqrt(discrima) - linear_attn) / (quadratic_attn + quadratic_attn);
    if ( result >= 0.0 )
      return result;
    return 0.0;
  }
  if ( linear_attn == 0.0 )
    return 2000.0;
  return (float)((float)((float)(discrim / v3) - pLight->constant_attn) / linear_attn);
}

//------------------------------------------------------------------------------
// Address: 0x100C30C0
// Name: DrawLightSprite
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawLightSprite(dworldlight_t *pLight@<eax>, int a2@<edi>, float angleAttenFactor)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float y; // ecx
  float z; // edx
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // ebx
  IMesh *v10; // edi
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float x; // xmm2_4
  float v15; // xmm4_4
  float *v16; // eax
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float *m_pCurrPosition; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float *v31; // eax
  float *v32; // eax
  float *v33; // eax
  float v34; // xmm5_4
  float v35; // xmm4_4
  float v36; // xmm6_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float *v42; // eax
  float *v43; // eax
  float v44; // xmm5_4
  float v45; // xmm4_4
  float v46; // xmm6_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float *v52; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-22Ch] BYREF
  Vector lightToEye; // [esp+1E8h] [ebp-44h] BYREF
  Vector p; // [esp+1F4h] [ebp-38h]
  Vector right; // [esp+200h] [ebp-2Ch] BYREF
  Vector up; // [esp+20Ch] [ebp-20h] BYREF
  float v59; // [esp+218h] [ebp-14h]
  float v60; // [esp+21Ch] [ebp-10h]
  Vector color; // [esp+220h] [ebp-Ch] BYREF
  float angleAttenFactora; // [esp+234h] [ebp+8h]
  float angleAttenFactorb; // [esp+234h] [ebp+8h]
  float angleAttenFactorc; // [esp+234h] [ebp+8h]
  float angleAttenFactord; // [esp+234h] [ebp+8h]

  v4 = g_CurrentViewOrigin.y - pLight->origin.y;
  v5 = g_CurrentViewOrigin.z - pLight->origin.z;
  lightToEye.x = g_CurrentViewOrigin.x - pLight->origin.x;
  lightToEye.y = v4;
  lightToEye.z = v5;
  VectorNormalize(vec: &lightToEye);
  up.z = 1.0;
  right.x = (float)(lightToEye.z * 0.0) - lightToEye.y;
  up.x = 0.0;
  up.y = 0.0;
  right.y = lightToEye.x - (float)(lightToEye.z * 0.0);
  right.z = (float)(lightToEye.y * 0.0) - (float)(lightToEye.x * 0.0);
  VectorNormalize(vec: &right);
  up.x = (float)(right.z * lightToEye.y) - (float)(right.y * lightToEye.z);
  up.y = (float)(lightToEye.z * right.x) - (float)(right.z * lightToEye.x);
  up.z = (float)(right.y * lightToEye.x) - (float)(lightToEye.y * right.x);
  VectorNormalize(vec: &up);
  y = pLight->intensity.y;
  z = pLight->intensity.z;
  color.x = pLight->intensity.x;
  color.y = y;
  color.z = z;
  VectorNormalize(vec: &color);
  color.y = color.y * angleAttenFactor;
  color.z = angleAttenFactor * color.z;
  color.x = pow(color.x * angleAttenFactor, 0.4545454382896423);
  color.y = pow(color.y, 0.4545454382896423);
  color.z = pow(color.z, 0.4545454382896423);
  v8 = materials->GetRenderContext(this: materials);
  v9 = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))v9->Bind)(
    a1: v9,
    a2: g_pMaterialLightSprite,
    a3: 0,
    a4: a2);
  v10 = v9->GetDynamicMesh(this: v9, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v10;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v10->SetPrimitiveType(this: v10, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v10->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v10, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v11 = color.y;
  v12 = color.z;
  if ( color.y <= color.z )
    v13 = color.z;
  else
    v13 = color.y;
  x = color.x;
  if ( color.x <= v13 )
  {
    if ( color.y <= color.z )
      v15 = color.z;
    else
      v15 = color.y;
  }
  else
  {
    v15 = color.x;
  }
  if ( v15 > 1.0 )
  {
    x = color.x * (float)(1.0 / v15);
    v11 = color.y * (float)(1.0 / v15);
    v12 = color.z * (float)(1.0 / v15);
    color.x = x;
    color.y = v11;
    color.z = v12;
  }
  if ( x < 0.0 )
    color.x = 0.0;
  if ( v11 < 0.0 )
    color.y = 0.0;
  if ( v12 < 0.0 )
    color.z = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v17 = up.z * 16.0;
  v18 = up.y * 16.0;
  v19 = up.x * 16.0;
  v20 = right.z * 16.0;
  v21 = pLight->origin.x + (float)(right.x * 16.0);
  v22 = pLight->origin.y + (float)(right.y * 16.0);
  v23 = pLight->origin.z;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v16[1] = 1.0;
  v24 = v21 + v19;
  v25 = (float)(v23 + v20) + v17;
  v26 = v22 + v18;
  p.x = v24;
  p.y = v26;
  p.z = v25;
  v60 = (float)(color.z * 255.0) + 8388608.0;
  v59 = (float)(color.y * 255.0) + 8388608.0;
  angleAttenFactora = (float)(color.x * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v60)
                                                      | ((LOBYTE(v59) | ((LOBYTE(angleAttenFactora) | 0xFFFFFF00) << 8)) << 8);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
  m_pCurrPosition[1] = v26;
  m_pCurrPosition[2] = v25;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v29 = (float)(pLight->origin.y + (float)(right.y * -16.0)) + (float)(up.y * 16.0);
  v30 = (float)(pLight->origin.z + (float)(right.z * -16.0)) + (float)(up.z * 16.0);
  p.x = (float)((float)(right.x * -16.0) + pLight->origin.x) + (float)(up.x * 16.0);
  v28 = p.x;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v31[1] = 1.0;
  p.y = v29;
  p.z = v30;
  v59 = (float)(color.z * 255.0) + 8388608.0;
  v60 = (float)(color.y * 255.0) + 8388608.0;
  angleAttenFactorb = (float)(color.x * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v59)
                                                      | ((LOBYTE(v60) | ((LOBYTE(angleAttenFactorb) | 0xFFFFFF00) << 8)) << 8);
  v32 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v28;
  v32[1] = v29;
  v32[2] = v30;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v33 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v34 = up.z * -16.0;
  v35 = up.y * -16.0;
  v36 = right.z * -16.0;
  v37 = pLight->origin.y + (float)(right.y * -16.0);
  v38 = pLight->origin.z;
  v39 = (float)((float)(right.x * -16.0) + pLight->origin.x) + (float)(up.x * -16.0);
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v33[1] = 0.0;
  v40 = (float)(v38 + v36) + v34;
  v41 = v37 + v35;
  p.x = v39;
  p.y = v41;
  p.z = v40;
  v59 = (float)(color.z * 255.0) + 8388608.0;
  v60 = (float)(color.y * 255.0) + 8388608.0;
  angleAttenFactorc = (float)(color.x * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v59)
                                                      | ((LOBYTE(v60) | ((LOBYTE(angleAttenFactorc) | 0xFFFFFF00) << 8)) << 8);
  v42 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39;
  v42[1] = v41;
  v42[2] = v40;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v43 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v44 = up.z * -16.0;
  v45 = up.y * -16.0;
  v46 = right.z * 16.0;
  v47 = (float)((float)(right.x * 16.0) + pLight->origin.x) + (float)(up.x * -16.0);
  v48 = pLight->origin.y + (float)(right.y * 16.0);
  v49 = pLight->origin.z;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v43[1] = 0.0;
  v50 = (float)(v49 + v46) + v44;
  v51 = v48 + v45;
  p.x = v47;
  p.y = v51;
  p.z = v50;
  v59 = (float)(color.z * 255.0) + 8388608.0;
  v60 = (float)(color.y * 255.0) + 8388608.0;
  angleAttenFactord = (float)(color.x * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v59)
                                                      | ((LOBYTE(v60) | ((LOBYTE(angleAttenFactord) | 0xFFFFFF00) << 8)) << 8);
  v52 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v47;
  v52[1] = v51;
  v52[2] = v50;
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
  v9->EndRender(this: v9);
  v9->Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x100C3920
// Name: void DrawSpotLight(struct dworldlight_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSpotLight(dworldlight_t *pLight)
{
  int v2; // edi
  int v3; // ecx
  float z; // xmm1_4
  float y; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  int (*GetRenderContext)(void); // eax
  float v9; // xmm2_4
  float v10; // xmm1_4
  IMatRenderContext *v11; // eax
  IMatRenderContext *m_pObject; // ebx
  long double v13; // st7
  float v14; // xmm0_4
  float x; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  int v18; // ebx
  float *m_pCurrPosition; // eax
  long double v20; // st6
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  bool v28; // zf
  int v29; // eax
  signed int m_nCurrentIndex; // ecx
  int v31; // edx
  __int16 v32; // ax
  __int16 v33; // si
  signed int v34; // ecx
  signed int v35; // ecx
  signed int v36; // ecx
  signed int v37; // ecx
  signed int v38; // ecx
  signed int v39; // ecx
  signed int v40; // ecx
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+20h] [ebp-230h] BYREF
  float flTanAngle; // [esp+208h] [ebp-48h]
  Vector yaxis; // [esp+20Ch] [ebp-44h]
  CMatRenderContextPtr pRenderContext; // [esp+218h] [ebp-38h]
  int nGridLines; // [esp+21Ch] [ebp-34h]
  float flGridLineDist; // [esp+220h] [ebp-30h]
  int v48; // [esp+224h] [ebp-2Ch]
  float flDist; // [esp+228h] [ebp-28h]
  float flRadius; // [esp+22Ch] [ebp-24h]
  Vector xaxis; // [esp+230h] [ebp-20h] BYREF
  float v52; // [esp+23Ch] [ebp-14h]
  Vector vecCenter; // [esp+240h] [ebp-10h]
  IMesh *pMesh; // [esp+24Ch] [ebp-4h]
  float flAngle; // [esp+258h] [ebp+8h]
  int flAnglea; // [esp+258h] [ebp+8h]

  *(float *)&pMesh = ComputeLightRadius(pLight, bIsHDR: false);
  RenderWireframeSphere(
    vCenter: &pLight->origin,
    flRadius: *(float *)&pMesh,
    nTheta: 20,
    nPhi: 20,
    c: (Color)-16776961,
    bZBuffer: true);
  flGridLineDist = 50.0;
  v2 = 1 - (int)(float)(*(float *)&pMesh * -0.02);
  nGridLines = v2;
  if ( v2 > 256 )
  {
    v2 = 256;
    nGridLines = 256;
    flGridLineDist = *(float *)&pMesh * 0.0039215689;
  }
  v3 = fabs(pLight->normal.y) <= fabs(pLight->normal.x);
  if ( fabs(pLight->normal.z) <= fabs(*(&pLight->normal.x + v3)) )
    v3 = 2;
  z = pLight->normal.z;
  vecCenter = vec3_origin;
  *((_DWORD *)&vecCenter.x + v3) = 1065353216;
  y = pLight->normal.y;
  xaxis.x = (float)(z * vecCenter.y) - (float)(y * vecCenter.z);
  v6 = (float)(y * vecCenter.x) - (float)(pLight->normal.x * vecCenter.y);
  xaxis.y = (float)(pLight->normal.x * vecCenter.z) - (float)(z * vecCenter.x);
  xaxis.z = v6;
  VectorNormalize(vec: &xaxis);
  v7 = pLight->normal.z;
  GetRenderContext = (int (*)(void))materials->GetRenderContext;
  v9 = pLight->normal.y * xaxis.x;
  yaxis.x = (float)(pLight->normal.y * xaxis.z) - (float)(v7 * xaxis.y);
  v10 = (float)(pLight->normal.x * xaxis.y) - v9;
  yaxis.y = (float)(v7 * xaxis.x) - (float)(pLight->normal.x * xaxis.z);
  yaxis.z = v10;
  v11 = (IMatRenderContext *)GetRenderContext();
  m_pObject = v11;
  pRenderContext.m_pObject = v11;
  if ( v11 != nullptr )
    v11->BeginRender(this: v11);
  m_pObject->Bind(this: m_pObject, a2: g_materialWorldWireframeZBuffer, a3: nullptr);
  *(float *)&pMesh = COERCE_FLOAT((int)m_pObject->GetDynamicMesh(
                                         this: m_pObject,
                                         a2: true,
                                         a3: nullptr,
                                         a4: nullptr,
                                         a5: nullptr));
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_LINES,
    nVertexCount: 8 * v2 + 8,
    nIndexCount: v2 << 6,
    pMeshSettings: nullptr);
  v13 = tan(acos(pLight->stopdot2));
  v14 = 0.0;
  flDist = 0.0;
  flTanAngle = v13;
  if ( v2 >= 0 )
  {
    v48 = v2 + 1;
    do
    {
      x = (float)(v14 * pLight->normal.x) + pLight->origin.x;
      v16 = (float)(pLight->normal.y * v14) + pLight->origin.y;
      v17 = (float)(v14 * pLight->normal.z) + pLight->origin.z;
      flRadius = v14 * flTanAngle;
      vecCenter.x = x;
      vecCenter.y = v16;
      vecCenter.z = v17;
      flAngle = 0.0;
      v18 = 8;
      while ( 1 )
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v20 = flAngle * 0.017453292;
        v52 = cos(v20) * flRadius;
        v21 = (float)(v52 * xaxis.x) + x;
        v22 = (float)(xaxis.y * v52) + v16;
        v23 = (float)(xaxis.z * v52) + v17;
        v52 = flRadius * sin(v20);
        v24 = v52;
        v25 = (float)(v52 * yaxis.x) + v21;
        v26 = (float)(yaxis.y * v52) + v22;
        v27 = yaxis.z;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v25;
        m_pCurrPosition[1] = v26;
        m_pCurrPosition[2] = (float)(v27 * v24) + v23;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        --v18;
        flAngle = flAngle + 45.0;
        if ( v18 == 0 )
          break;
        v17 = vecCenter.z;
        v16 = vecCenter.y;
        x = vecCenter.x;
      }
      v28 = v48-- == 1;
      v14 = flDist + flGridLineDist;
      flDist = flDist + flGridLineDist;
    }
    while ( !v28 );
    m_pObject = pRenderContext.m_pObject;
  }
  LOWORD(v29) = 0;
  flAnglea = 0;
  if ( v2 > 0 )
  {
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      v31 = 0;
      v32 = 8 * v29;
      do
      {
        if ( v31 == 7 )
          v33 = 0;
        else
          v33 = v31 + 1;
        meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v32
                                                               + v31
                                                               + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
        v34 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v34;
        if ( v34 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v34;
        meshBuilder.m_IndexBuilder.m_pIndices[v34] = v31 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v32 + 8;
        v35 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v35;
        if ( v35 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v35;
        meshBuilder.m_IndexBuilder.m_pIndices[v35] = v31 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v32 + 8;
        v36 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v36;
        if ( v36 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v36;
        meshBuilder.m_IndexBuilder.m_pIndices[v36] = v33 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v32 + 8;
        v37 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v37;
        if ( v37 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v37;
        meshBuilder.m_IndexBuilder.m_pIndices[v37] = v33 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v32 + 8;
        v38 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v38;
        if ( v38 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v38;
        meshBuilder.m_IndexBuilder.m_pIndices[v38] = v32 + v33 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
        v39 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v39;
        if ( v39 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v39;
        meshBuilder.m_IndexBuilder.m_pIndices[v39] = v32 + v33 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
        v40 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v40;
        if ( v40 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v40;
        meshBuilder.m_IndexBuilder.m_pIndices[v40] = v32 + v31 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
        if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        ++v31;
      }
      while ( v31 < 8 );
      v29 = flAnglea + 1;
      flAnglea = v29;
    }
    while ( v29 < nGridLines );
    m_pObject = pRenderContext.m_pObject;
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
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
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
// Address: 0x100C3FA0
// Name: void DrawLightSprites(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DrawLightSprites(float a1@<ebp>)
{
  worldbrushdata_t *worldbrush; // eax
  int v2; // edi
  dworldlight_t *v3; // esi
  float v4; // xmm1_4
  float v5; // xmm2_4
  int v6; // [esp+1Ch] [ebp-D4h] BYREF
  _BYTE tr_32[56]; // [esp+48h] [ebp-A8h] OVERLAPPED BYREF
  Ray_t ray; // [esp+80h] [ebp-70h] BYREF
  Vector v9; // [esp+D0h] [ebp-20h] BYREF
  Vector lightToEye; // [esp+DCh] [ebp-14h] BYREF
  CTraceFilterWorldAndPropsOnly traceFilter; // [esp+E8h] [ebp-8h]
  CTraceFilterWorldAndPropsOnly_vtbl *retaddr; // [esp+F0h] [ebp+0h]

  lightToEye.z = a1;
  traceFilter.__vftable = retaddr;
  if ( s_bActivateLightSprites )
  {
    worldbrush = host_state.worldbrush;
    lightToEye.y = 0.0;
    if ( host_state.worldbrush->numworldlights > 0 )
    {
      v2 = 0;
      do
      {
        v3 = &worldbrush->worldlights[v2];
        LODWORD(lightToEye.x) = &CTraceFilterWorldAndPropsOnly::`vftable';
        ray.m_Extents.y = 0.0;
        ray.m_Start.y = v3->origin.x - g_CurrentViewOrigin.x;
        ray.m_Start.z = v3->origin.y - g_CurrentViewOrigin.y;
        ray.m_Start.w = v3->origin.z - g_CurrentViewOrigin.z;
        BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                               + (float)(ray.m_Start.y * ray.m_Start.y))
                                       + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
        ray.m_Extents.y = 0.0;
        memset(&ray.m_StartOffset.y, 0, 12);
        LOBYTE(ray.m_Extents.z) = 1;
        memset(&ray.m_Delta.y, 0, 12);
        *(Vector *)&tr_32[44] = g_CurrentViewOrigin;
        g_pEngineTraceClient->TraceRay(
          this: g_pEngineTraceClient,
          a2: (const Ray_t *)&tr_32[44],
          a3: 16513u,
          a4: (ITraceFilter *)&lightToEye,
          a5: (CGameTrace *)&v6);
        if ( *(float *)tr_32 >= 1.0 )
        {
          v4 = g_CurrentViewOrigin.y - v3->origin.y;
          v5 = g_CurrentViewOrigin.z - v3->origin.z;
          v9.x = g_CurrentViewOrigin.x - v3->origin.x;
          v9.y = v4;
          v9.z = v5;
          VectorNormalize(vec: &v9);
          if ( v3->type == emit_point )
            DrawLightSprite(pLight: v3, a2: v2 * 100, angleAttenFactor: 1.0);
        }
        worldbrush = host_state.worldbrush;
        ++v2;
        ++LODWORD(lightToEye.y);
      }
      while ( SLODWORD(lightToEye.y) < host_state.worldbrush->numworldlights );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4150
// Name: void DrawLightDebuggingInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawLightDebuggingInfo()
{
  int v0; // ebx
  worldbrushdata_t *worldbrush; // eax
  int i; // edi
  dworldlight_t *v3; // esi
  int v4; // ebx
  int v5; // edi
  dworldlight_t *worldlights; // esi
  emittype_t type; // ecx
  dworldlight_t *v8; // esi
  __int32 v9; // ecx
  float quadratic_attn; // xmm1_4
  float linear_attn; // xmm0_4
  float constant_attn; // xmm3_4
  long double v13; // st7
  int v14; // edi
  Vector *p_origin; // esi
  double x; // st7
  float flRadius; // [esp+0h] [ebp-138h]
  char buf[256]; // [esp+20h] [ebp-118h] BYREF
  float v19; // [esp+120h] [ebp-18h]
  float v20; // [esp+124h] [ebp-14h]
  float v21; // [esp+128h] [ebp-10h]
  float v22; // [esp+12Ch] [ebp-Ch]
  float radius; // [esp+130h] [ebp-8h]
  int nLight; // [esp+134h] [ebp-4h]

  v0 = 0;
  if ( r_drawlights.m_pParent != nullptr )
    nLight = r_drawlights.m_pParent->m_Value.m_nValue;
  else
    nLight = 0;
  if ( r_drawlightinfo.m_pParent != nullptr && r_drawlightinfo.m_pParent->m_Value.m_nValue != 0 )
  {
    worldbrush = host_state.worldbrush;
    for ( i = 0; i < host_state.worldbrush->numworldlights; ++v0 )
    {
      ++i;
      v3 = &worldbrush->worldlights[v0];
      V_snprintf(pDest: buf, maxLen: 256, pFormat: "light:  %d\n", i);
      CDebugOverlay::AddTextOverlay(textPos: &v3->origin, line_offset: 0, duration: 0.0, text: buf);
      V_snprintf(
        pDest: buf,
        maxLen: 256,
        pFormat: "origin: <%d, %d, %d>\n",
        (int)v3->origin.x,
        (int)v3->origin.y,
        (int)v3->origin.z);
      CDebugOverlay::AddTextOverlay(textPos: &v3->origin, line_offset: 1, duration: 0.0, text: buf);
      if ( nLight == 0 )
        DrawLightSprite(pLight: v3, a2: i, angleAttenFactor: 1.0);
      worldbrush = host_state.worldbrush;
    }
  }
  else
  {
    worldbrush = host_state.worldbrush;
  }
  if ( nLight != 0 )
  {
    v4 = 0;
    if ( worldbrush->numworldlights > 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        worldlights = worldbrush->worldlights;
        type = worldlights[v5].type;
        v8 = &worldlights[v5];
        v9 = type - 1;
        if ( v9 == 0 )
          break;
        if ( v9 == 1 )
        {
          DrawSpotLight(pLight: v8);
LABEL_28:
          DrawLightSprite(pLight: v8, a2: v5 * 100, angleAttenFactor: 1.0);
          worldbrush = host_state.worldbrush;
        }
        ++v4;
        ++v5;
        if ( v4 >= worldbrush->numworldlights )
          goto LABEL_30;
      }
      radius = v8->radius;
      if ( radius == 0.0 )
      {
        quadratic_attn = v8->quadratic_attn;
        linear_attn = v8->linear_attn;
        v22 = sqrt(
                v8->intensity.x * v8->intensity.x
              + v8->intensity.y * v8->intensity.y
              + v8->intensity.z * v8->intensity.z);
        if ( quadratic_attn == 0.0 )
        {
          if ( linear_attn == 0.0 )
            radius = 2000.0;
          else
            radius = (float)((float)(v22 * 33.333336) - v8->constant_attn) / linear_attn;
        }
        else
        {
          constant_attn = v8->constant_attn;
          v20 = quadratic_attn;
          v19 = linear_attn;
          v21 = (float)(linear_attn * linear_attn)
              - (float)((float)(constant_attn - (float)(v22 * 33.333336)) * (float)(quadratic_attn * 4.0));
          if ( v21 >= 0.0 )
          {
            v13 = (sqrt(v21) - v19) / (v20 + v20);
            radius = v13;
            if ( v13 < 0.0 )
              radius = 0.0;
          }
          else
          {
            radius = 2000.0;
          }
        }
      }
      nLight = -256;
      RenderWireframeSphere(vCenter: &v8->origin, flRadius: radius, nTheta: 8, nPhi: 8, c: (Color)-256, bZBuffer: true);
      goto LABEL_28;
    }
LABEL_30:
    v14 = 1;
    p_origin = &cl_dlights[0].origin;
    do
    {
      if ( (v14 & r_dlightactive) != 0 )
      {
        x = p_origin[1].x;
        nLight = -256;
        flRadius = x;
        RenderWireframeSphere(vCenter: p_origin, flRadius, nTheta: 8, nPhi: 8, c: (Color)-256, bZBuffer: true);
      }
      p_origin = (Vector *)((char *)p_origin + 68);
      v14 = __ROL4__(v14, 1);
    }
    while ( (int)p_origin < (int)&cl_elights[0].origin );
  }
}

} // namespace engine_xlsp
