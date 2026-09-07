// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_pixel_visibility.cpp
// Functions: 37
// ============================================================

#include "game\client\c_pixel_visibility.h"

//------------------------------------------------------------------------------
// Address: 0x1007A350
// Name: public: virtual void PrecacheOcclusionProxyPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheOcclusionProxyPrecache::CResourcePrecacher::Cache(
        PrecacheOcclusionProxyPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "engine/occlusionproxy",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "engine/occlusionproxy_countdraw",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1007A390
// Name: public: virtual bool CTraceFilterGlow::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterGlow::ShouldHitEntity(
        CTraceFilterGlow *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  int v4; // esi

  v4 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].dtr_IHandleEntity)(a1: pHandleEntity);
  return ((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 44))(a1: v4) == 6
       || (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 44))(a1: v4) == 1)
      && CTraceFilterSimple::ShouldHitEntity(this, a2: v4, pHandleEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x1007A3E0
// Name: float PixelVisibility_DrawProxy(class IMatRenderContext __near *,struct OcclusionQueryObjectHandle_t__ __near *,class Vector,float,float,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
double __usercall PixelVisibility_DrawProxy@<st0>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IMatRenderContext *pRenderContext,
        OcclusionQueryObjectHandle_t__ *queryHandle,
        Vector origin,
        IMesh *scale,
        float proxyAspect,
        IMaterial *pMaterial,
        float screenspace)
{
  float (__thiscall *ComputePixelDiameterOfSphere)(IMatRenderContext *, const Vector *, float); // edx
  double v11; // st7
  float v12; // xmm1_4
  const Vector *v13; // eax
  float (__thiscall *v14)(IMatRenderContext *, const Vector *, float); // edx
  double v15; // st7
  const Vector *v16; // eax
  const Vector *v17; // eax
  float v18; // xmm0_4
  float v19; // xmm1_4
  const Vector *v20; // eax
  const Vector *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  const Vector *v24; // eax
  const Vector *v25; // eax
  float v26; // xmm1_4
  float v27; // xmm2_4
  const Vector *v28; // eax
  const Vector *v29; // eax
  float v30; // xmm1_4
  float v31; // xmm2_4
  const Vector *v32; // eax
  const Vector *v33; // eax
  float v34; // xmm1_4
  float v35; // xmm2_4
  int i; // edi
  float x; // xmm2_4
  float y; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  float v41; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // edx
  IMesh *v46; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  Vector *m_pPosition; // eax
  int v49; // edi
  float *p_y; // esi
  float *m_pCurrPosition; // eax
  float *v52; // ecx
  Vector *v53; // eax
  int m_nVertexCount; // eax
  Vector screen[4]; // [esp+18h] [ebp-280h] BYREF
  CMeshBuilder meshBuilder; // [esp+48h] [ebp-250h] BYREF
  float v57[3]; // [esp+230h] [ebp-68h] BYREF
  Vector verts[5]; // [esp+23Ch] [ebp-5Ch] BYREF
  IMesh *forwardScale; // [esp+278h] [ebp-20h]
  Vector dir; // [esp+27Ch] [ebp-1Ch] BYREF
  float pixelsPerUnit; // [esp+288h] [ebp-10h]
  Vector v62; // [esp+28Ch] [ebp-Ch]

  ComputePixelDiameterOfSphere = pRenderContext->ComputePixelDiameterOfSphere;
  forwardScale = scale;
  v11 = ((double (__thiscall *)(IMatRenderContext *, Vector *, int, int, int, int))ComputePixelDiameterOfSphere)(
          a1: pRenderContext,
          a2: &origin,
          a3: 1065353216,
          a4: a2,
          a5: a3,
          a6: a1);
  pixelsPerUnit = v11;
  if ( v11 > 0.000099999997 )
  {
    v12 = pixelsPerUnit;
  }
  else
  {
    v12 = 0.000099999997;
    pixelsPerUnit = 0.000099999997;
  }
  if ( LOBYTE(screenspace) != 0 )
  {
    v62 = *CurrentViewForward();
    v13 = CurrentViewOrigin();
    v57[0] = v13->x + v62.x;
    v57[1] = v13->y + v62.y;
    v14 = pRenderContext->ComputePixelDiameterOfSphere;
    v57[2] = v13->z + v62.z;
    v15 = ((double (__thiscall *)(IMatRenderContext *, float *, _DWORD))v14)(
            a1: pRenderContext,
            a2: v57,
            a3: *(float *)&scale * 0.5);
    *(float *)&scale = v15 / pixelsPerUnit;
  }
  else if ( (float)(v12 * *(float *)&scale) < 5.0 )
  {
    *(float *)&scale = 5.0 / v12;
  }
  v16 = CurrentViewOrigin();
  dir.x = origin.x - v16->x;
  dir.y = origin.y - v16->y;
  dir.z = origin.z - v16->z;
  VectorNormalize(vec: &dir);
  origin.y = origin.y - (float)(dir.y * *(float *)&forwardScale);
  origin.z = origin.z - (float)(dir.z * *(float *)&forwardScale);
  *(float *)&scale = *(float *)&scale * 0.70710677;
  origin.x = origin.x - (float)(dir.x * *(float *)&forwardScale);
  screenspace = *(float *)&scale / proxyAspect;
  v17 = CurrentViewForward();
  v18 = origin.y - (float)(v17->y * 0.0);
  v19 = origin.z - (float)(v17->z * 0.0);
  verts[0].x = origin.x - (float)(v17->x * 0.0);
  verts[0].y = v18;
  verts[0].z = v19;
  v20 = CurrentViewRight();
  v62.x = v20->x * *(float *)&scale;
  v62.y = v20->y * *(float *)&scale;
  v62.z = v20->z * *(float *)&scale;
  v21 = CurrentViewUp();
  v22 = (float)((float)(v21->y * screenspace) + origin.y) - v62.y;
  v23 = (float)((float)(v21->z * screenspace) + origin.z) - v62.z;
  verts[1].x = (float)((float)(v21->x * screenspace) + origin.x) - v62.x;
  verts[1].y = v22;
  verts[1].z = v23;
  v24 = CurrentViewRight();
  v62.x = v24->x * *(float *)&scale;
  v62.y = v24->y * *(float *)&scale;
  v62.z = v24->z * *(float *)&scale;
  v25 = CurrentViewUp();
  v26 = (float)((float)(v25->y * screenspace) + origin.y) + v62.y;
  v27 = (float)((float)(v25->z * screenspace) + origin.z) + v62.z;
  verts[2].x = (float)((float)(v25->x * screenspace) + origin.x) + v62.x;
  verts[2].y = v26;
  verts[2].z = v27;
  v28 = CurrentViewRight();
  v62.x = v28->x * *(float *)&scale;
  v62.y = v28->y * *(float *)&scale;
  v62.z = v28->z * *(float *)&scale;
  v29 = CurrentViewUp();
  v30 = (float)(origin.y - (float)(v29->y * screenspace)) + v62.y;
  v31 = (float)(origin.z - (float)(v29->z * screenspace)) + v62.z;
  verts[3].x = (float)(origin.x - (float)(v29->x * screenspace)) + v62.x;
  verts[3].y = v30;
  verts[3].z = v31;
  v32 = CurrentViewRight();
  v62.x = v32->x * *(float *)&scale;
  v62.y = v32->y * *(float *)&scale;
  v62.z = v32->z * *(float *)&scale;
  v33 = CurrentViewUp();
  v34 = (float)(origin.y - (float)(v33->y * screenspace)) - v62.y;
  v35 = (float)(origin.z - (float)(v33->z * screenspace)) - v62.z;
  verts[4].x = (float)(origin.x - (float)(v33->x * screenspace)) - v62.x;
  verts[4].y = v34;
  verts[4].z = v35;
  for ( i = 0; i < 4; ++i )
  {
    if ( ScreenTransform(point: &verts[i + 1], screen: &screen[i]) != 0 )
      return -1.0;
  }
  x = screen[1].x;
  y = screen[0].y;
  v39 = screen[0].x;
  if ( screen[1].x > 1.0 )
    x = 1.0;
  if ( screen[0].x < -1.0 )
    v39 = -1.0;
  v40 = x - v39;
  if ( screen[0].y > 1.0 )
    y = 1.0;
  if ( screen[3].y >= -1.0 )
    v41 = screen[3].y;
  else
    v41 = -1.0;
  v43 = (float)(screen[0].y - screen[3].y) * (float)(screen[1].x - screen[0].x);
  screenspace = 0.0;
  if ( v43 != 0.0 )
  {
    v44 = (float)((float)(y - v41) * v40) / v43;
    if ( v44 >= 0.0 )
    {
      if ( v44 > 1.0 )
        v44 = 1.0;
    }
    else
    {
      v44 = 0.0;
    }
    screenspace = v44;
  }
  pRenderContext->BeginOcclusionQueryDrawing(this: pRenderContext, a2: queryHandle);
  meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
  meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  GetDynamicMesh = pRenderContext->GetDynamicMesh;
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_bGenerateIndices = false;
  memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
  memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
  meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
  v46 = GetDynamicMesh(this: pRenderContext, a2: false, a3: nullptr, a4: nullptr, a5: pMaterial);
  meshBuilder.m_pMesh = v46;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLES;
  SetPrimitiveType = v46->SetPrimitiveType;
  scale = v46;
  SetPrimitiveType(this: v46, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 12, a3: 12, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v46->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = v46;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 12;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 12;
  meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_bModify = false;
  if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
  {
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
  }
  m_pPosition = (Vector *)meshBuilder.m_VertexBuilder.m_pPosition;
  meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
  qmemcpy(
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
    meshBuilder.m_VertexBuilder.m_pTexCoord,
    sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
  meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
  meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
  v49 = 0;
  p_y = &verts[1].y;
  while ( 1 )
  {
    *m_pPosition = verts[0];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
    m_pCurrPosition[1] = *p_y;
    m_pCurrPosition[2] = p_y[1];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v49;
    v52 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v53 = &verts[v49 % 4 + 1];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v53->x;
    v52[1] = v53->y;
    v52[2] = v53->z;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    p_y += 3;
    if ( v49 >= 4 )
      break;
    m_pPosition = (Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition;
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
  scale->Draw_2(this: scale, a2: -1, a3: 0);
  pRenderContext->EndOcclusionQueryDrawing(this: pRenderContext, a2: queryHandle);
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
  return screenspace;
}

//------------------------------------------------------------------------------
// Address: 0x1007ACA0
// Name: public: void CPixelVisibilityQuery::IssueQuery(class IMatRenderContext __near *,float,float,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPixelVisibilityQuery::IssueQuery(
        CPixelVisibilityQuery *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IMatRenderContext *pRenderContext,
        IMesh *proxySize,
        float proxyAspect,
        IMaterial *pMaterial,
        float sizeIsScreenSpace)
{
  double v9; // st7
  int v10; // ecx

  if ( (*((_BYTE *)this + 32) & 2) != 0 )
    goto LABEL_8;
  if ( r_pixelvisibility_spew.m_pParent != nullptr
    && r_pixelvisibility_spew.m_pParent->m_Value.m_nValue != 0
    && CurrentViewID() == VIEW_MAIN )
  {
    _DevMsg(a1: 1, a2: "Draw Proxy: qh:%d org:<%d,%d,%d> (frame:%d)\n");
  }
  v9 = PixelVisibility_DrawProxy(
         a1: a2,
         a2: a3,
         a3: (int)this,
         pRenderContext,
         queryHandle: this->m_queryHandle,
         origin: this->m_origin,
         scale: proxySize,
         proxyAspect,
         pMaterial,
         screenspace: sizeIsScreenSpace);
  this->m_clipFraction = v9;
  if ( v9 >= 0.0 )
  {
LABEL_8:
    v10 = *(_DWORD *)(gpGlobals.m_Index + 4);
    *((_WORD *)this + 16) &= 0xFFFCu;
    this->m_frameIssued = v10;
  }
  else
  {
    *((_WORD *)this + 16) &= 0xFFFCu;
    this->m_clipFraction = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AD80
// Name: PixelvisDrawChanged
// Source: json
//------------------------------------------------------------------------------
void __cdecl PixelvisDrawChanged(IConVar *pPixelvisVar)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar: pPixelvisVar);
  g_PixelVisibilitySystem.m_drawQueries = var.m_pConVarState->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007ADB0
// Name: float GlowSightDistance(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __usercall GlowSightDistance@<st0>(int a1@<ebp>, const Vector *glowOrigin, bool bShouldTrace)
{
  const Vector *v3; // eax
  CTraceFilterGlow v4; // xmm0
  C_BasePlayer *LocalPlayer; // eax
  float z; // eax
  const Vector *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm3_4
  const Vector *v10; // eax
  int v12; // [esp-Ch] [ebp-94h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-88h] BYREF
  CTraceFilterGlow filter_4; // [esp+5Ch] [ebp-2Ch] OVERLAPPED BYREF
  CTraceFilterGlow_vtbl *v15; // [esp+78h] [ebp-10h]
  int v16; // [esp+7Ch] [ebp-Ch]
  void *v17; // [esp+80h] [ebp-8h]
  void *retaddr; // [esp+88h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v3 = CurrentViewOrigin();
  v4 = 0;
  *(float *)&v4.__vftable = fsqrt(
                              (float)((float)((float)(glowOrigin->y - v3->y) * (float)(glowOrigin->y - v3->y))
                                    + (float)((float)(glowOrigin->z - v3->z) * (float)(glowOrigin->z - v3->z)))
                            + (float)((float)(glowOrigin->x - v3->x) * (float)(glowOrigin->x - v3->x)));
  filter_4 = v4;
  v15 = v4.__vftable;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    *(float *)&v15 = C_BasePlayer::GetFOVDistanceAdjustFactor(this: LocalPlayer) * *(float *)&filter_4.__vftable;
  if ( !bShouldTrace )
    return *(float *)&v15;
  z = glowOrigin->z;
  *(_QWORD *)&filter_4.m_pPassEnt = *(_QWORD *)&glowOrigin->x;
  *(float *)&filter_4.m_pExtraShouldHitCheckFunction = z;
  if ( *(float *)&v15 > 4.0 )
  {
    v7 = CurrentViewForward();
    v8 = v7->z * 4.0;
    v9 = *(float *)&filter_4.m_pPassEnt - (float)(v7->x * 4.0);
    *(float *)&filter_4.m_collisionGroup = *(float *)&filter_4.m_collisionGroup - (float)(v7->y * 4.0);
    *(float *)&filter_4.m_pPassEnt = v9;
    *(float *)&filter_4.m_pExtraShouldHitCheckFunction = *(float *)&filter_4.m_pExtraShouldHitCheckFunction - v8;
  }
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&tr.m_pEnt,
    passedict: nullptr,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  tr.m_pEnt = (struct CBaseEntity *)&CTraceFilterGlow::`vftable';
  v10 = CurrentViewOrigin();
  UTIL_TraceLine(
    vecAbsStart: v10,
    vecAbsEnd: (const Vector *)&filter_4.m_pPassEnt,
    mask: 0x6004081u,
    pFilter: (ITraceFilter *)&tr.m_pEnt,
    ptr: (CGameTrace *)&v12);
  if ( tr.plane.normal.z == 1.0 )
    return *(float *)&v15;
  else
    return -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1007AF20
// Name: bool PixelVisibility_IsAvailable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PixelVisibility_IsAvailable()
{
  return r_dopixelvisibility.m_pParent != nullptr
      && r_dopixelvisibility.m_pParent->m_Value.m_nValue != 0
      && g_PixelVisibilitySystem.m_hwCanTestGlows;
}

//------------------------------------------------------------------------------
// Address: 0x1007AF50
// Name: public: void COcclusionQuerySet::EndQueryDrawing(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQuerySet::EndQueryDrawing(COcclusionQuerySet *this, int iViewID, int iSplitScreenSlot)
{
  char *v3; // edi
  int v4; // eax
  int v5; // esi
  _DWORD *i; // ecx
  IMatRenderContext *v7; // eax

  v3 = (char *)this->m_pManagedData + 20 * iSplitScreenSlot;
  v4 = *((_DWORD *)v3 + 4);
  v5 = 0;
  if ( v4 != 0 )
  {
    for ( i = (_DWORD *)(*((_DWORD *)v3 + 1) + 4); *i != iViewID; i += 3 )
    {
      if ( ++v5 == v4 )
        return;
    }
    if ( v5 != -1 )
    {
      v7 = materials->GetRenderContext(this: materials);
      v7->EndOcclusionQueryDrawing(this: v7, a2: *(OcclusionQueryObjectHandle_t__ **)(*((_DWORD *)v3 + 1) + 12 * v5));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AFC0
// Name: public: void COcclusionQuerySet::EndQueryDrawing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQuerySet::EndQueryDrawing(COcclusionQuerySet *this)
{
  view_id_t v2; // eax

  v2 = CurrentViewID();
  COcclusionQuerySet::EndQueryDrawing(this, iViewID: v2, iSplitScreenSlot: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007B470
// Name: public: CPixelVisibilityQuery::CPixelVisibilityQuery(void)
// Source: json
//------------------------------------------------------------------------------
CPixelVisibilityQuery *__thiscall CPixelVisibilityQuery::CPixelVisibilityQuery(CPixelVisibilityQuery *this)
{
  IMatRenderContext *v2; // esi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  this->m_brightnessTarget = 0.0;
  *((_WORD *)this + 16) &= 0xFFE0u;
  this->m_viewID = -1;
  this->m_clipFraction = 1.0;
  this->m_frameIssued = -1;
  this->m_queryHandle = v2->CreateOcclusionQueryObject(this: v2);
  this->m_queryHandleCount = v2->CreateOcclusionQueryObject(this: v2);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007B500
// Name: public: void CPixelVisibilityQuery::ResetOcclusionQueries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPixelVisibilityQuery::ResetOcclusionQueries(CPixelVisibilityQuery *this)
{
  IMatRenderContext *v2; // esi
  OcclusionQueryObjectHandle_t__ *m_queryHandleCount; // edi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  if ( this->m_queryHandle != nullptr )
    v2->ResetOcclusionQueryObject(this: v2, a2: this->m_queryHandle);
  m_queryHandleCount = this->m_queryHandleCount;
  if ( m_queryHandleCount != nullptr )
    v2->ResetOcclusionQueryObject(this: v2, a2: m_queryHandleCount);
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B570
// Name: public: float CPixelVisibilityQuery::GetFractionVisible(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPixelVisibilityQuery::GetFractionVisible(CPixelVisibilityQuery *this, float fadeTimeInv)
{
  IMatRenderContext *v4; // edi
  int v5; // ebx
  float target; // xmm0_4
  float v7; // xmm0_4
  float speed; // xmm0_4
  float v9; // xmm1_4
  int pixelsPossible; // [esp+20h] [ebp-4h]

  if ( this->m_queryHandle == nullptr )
    return 0.0;
  if ( (*((_BYTE *)this + 32) & 1) != 0 )
    return this->m_clipFraction * this->m_brightnessTarget;
  v4 = materials->GetRenderContext(this: materials);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  *((_WORD *)this + 16) |= 1u;
  v5 = -1;
  pixelsPossible = -1;
  if ( r_pixelvisibility_partial.m_pParent != nullptr && r_pixelvisibility_partial.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_frameIssued != -1 )
    {
      pixelsPossible = v4->OcclusionQuery_GetNumPixelsRendered(this: v4, a2: this->m_queryHandleCount);
      v5 = v4->OcclusionQuery_GetNumPixelsRendered(this: v4, a2: this->m_queryHandle);
    }
    if ( r_pixelvisibility_spew.m_pParent != nullptr
      && r_pixelvisibility_spew.m_pParent->m_Value.m_nValue != 0
      && CurrentViewID() == VIEW_MAIN )
    {
      _DevMsg(a1: 1, a2: "Pixels visible: %d (qh:%d) Pixels possible: %d (qh:%d) (frame:%d)\n");
    }
    if ( v5 >= 0 && pixelsPossible >= 0 )
    {
      *((_WORD *)this + 16) |= 4u;
      if ( pixelsPossible > 0 )
      {
        target = (float)v5 / (float)pixelsPossible;
        if ( target < 0.94999999 )
        {
          if ( target < 0.0 )
            target = 0.0;
        }
        else
        {
          target = 1.0;
        }
        this->m_brightnessTarget = Approach(
                                     target,
                                     value: this->m_brightnessTarget,
                                     speed: *(float *)(gpGlobals.m_Index + 16) * fadeTimeInv);
        goto LABEL_37;
      }
LABEL_36:
      this->m_brightnessTarget = 0.0;
LABEL_37:
      if ( v4 != nullptr )
      {
        v4->EndRender(this: v4);
        v4->Release(this: v4);
      }
      return this->m_clipFraction * this->m_brightnessTarget;
    }
  }
  else
  {
    if ( this->m_frameIssued != -1 )
      v5 = v4->OcclusionQuery_GetNumPixelsRendered(this: v4, a2: this->m_queryHandle);
    if ( r_pixelvisibility_spew.m_pParent != nullptr
      && r_pixelvisibility_spew.m_pParent->m_Value.m_nValue != 0
      && CurrentViewID() == VIEW_MAIN )
    {
      _DevMsg(a1: 1, a2: "Pixels visible: %d (qh:%d) (frame:%d)\n");
    }
    if ( v5 >= 0 )
    {
      *((_WORD *)this + 16) |= 4u;
      if ( this->m_frameIssued == *(_DWORD *)(gpGlobals.m_Index + 4) - 1 )
      {
        speed = *(float *)(gpGlobals.m_Index + 16) * fadeTimeInv;
        v9 = 0.0;
        if ( v5 > 0 )
        {
          speed = speed * 0.5;
          v9 = 1.0;
        }
        this->m_brightnessTarget = Approach(target: v9, value: this->m_brightnessTarget, speed);
        goto LABEL_37;
      }
      goto LABEL_36;
    }
  }
  v7 = this->m_clipFraction * this->m_brightnessTarget;
  *((_WORD *)this + 16) = *((_WORD *)this + 16) & 0xFFFD | (2 * (this->m_frameIssued >= 0));
  if ( v4 != nullptr )
  {
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1007B7F0
// Name: public: unsigned short CPixelVisibilitySystem::FindQueryForView(class CPixelVisSet __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPixelVisibilitySystem::FindQueryForView(
        CPixelVisibilitySystem *this,
        CPixelVisSet *pSet,
        int nPlayerSlot,
        int viewID)
{
  int result; // eax
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 *v6; // ecx

  result = this->m_queryList.m_List.m_Memory.m_pMemory[pSet->queryList].m_Element.m_Head;
  if ( (_WORD)result == 0xFFFF )
    return 0xFFFF;
  m_pMemory = this->m_queryList.m_Memory.m_pMemory;
  while ( 1 )
  {
    v6 = (unsigned __int16 *)&m_pMemory[(unsigned __int16)result];
    if ( v6[17] == viewID && nPlayerSlot == ((v6[16] >> 3) & 3) )
      break;
    result = v6[19];
    if ( (_WORD)result == 0xFFFF )
      return 0xFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B860
// Name: public: int COcclusionQuerySet::QueryNumPixelsRenderedForAllViewsLastFrame(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COcclusionQuerySet::QueryNumPixelsRenderedForAllViewsLastFrame(
        COcclusionQuerySet *this,
        int iSplitScreenSlot)
{
  _DWORD *m_pManagedData; // edi
  int v3; // ebx
  IMatRenderContext *v4; // eax
  IMatRenderContext *v5; // esi
  bool v6; // zf
  char *v7; // edi
  OcclusionQueryObjectHandle_t__ **v8; // eax
  int i; // [esp+Ch] [ebp-8h]
  int iResult; // [esp+10h] [ebp-4h]
  int iSplitScreenSlota; // [esp+1Ch] [ebp+8h]

  m_pManagedData = this->m_pManagedData;
  v3 = *(_DWORD *)(gpGlobals.m_Index + 4) - 1;
  iResult = 0;
  v4 = materials->GetRenderContext(this: materials);
  v5 = v4;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v6 = m_pManagedData[5 * iSplitScreenSlot + 4] == 0;
  v7 = (char *)&m_pManagedData[5 * iSplitScreenSlot];
  i = 0;
  if ( !v6 )
  {
    iSplitScreenSlota = 0;
    do
    {
      v8 = (OcclusionQueryObjectHandle_t__ **)(*((_DWORD *)v7 + 1) + iSplitScreenSlota);
      if ( v8[2] == (OcclusionQueryObjectHandle_t__ *)v3 )
        iResult += v5->OcclusionQuery_GetNumPixelsRendered(this: v5, a2: *v8);
      iSplitScreenSlota += 12;
      ++i;
    }
    while ( i != *((_DWORD *)v7 + 4) );
  }
  if ( v5 != nullptr )
  {
    v5->EndRender(this: v5);
    v5->Release(this: v5);
  }
  return iResult;
}

//------------------------------------------------------------------------------
// Address: 0x1007B910
// Name: public: int COcclusionQuerySet::QueryNumPixelsRenderedForAllViewsLastFrame(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COcclusionQuerySet::QueryNumPixelsRenderedForAllViewsLastFrame(COcclusionQuerySet *this)
{
  return COcclusionQuerySet::QueryNumPixelsRenderedForAllViewsLastFrame(this, iSplitScreenSlot: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007B920
// Name: pixelvis_debug
// Source: json
//------------------------------------------------------------------------------
void __cdecl pixelvis_debug()
{
  _Msg(
    a1: "Pixel vis system using %d sets total (%d in free list), %d queries total (%d in free list)\n",
    g_PixelVisibilitySystem.m_setList.m_TotalElements,
    g_PixelVisibilitySystem.m_setList.m_List.m_Memory.m_pMemory[g_PixelVisibilitySystem.m_freeSetsList].m_Element.m_Count,
    g_PixelVisibilitySystem.m_queryList.m_TotalElements,
    g_PixelVisibilitySystem.m_queryList.m_List.m_Memory.m_pMemory[g_PixelVisibilitySystem.m_freeQueriesList].m_Element.m_Count);
}

//------------------------------------------------------------------------------
// Address: 0x1007BC90
// Name: public: void CPixelVisibilitySystem::EndView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPixelVisibilitySystem::EndView(CPixelVisibilitySystem *this)
{
  IMatRenderContext *v2; // edi
  unsigned __int16 m_Head; // ax
  int v4; // ebx
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v5; // edi
  view_id_t v6; // eax
  unsigned __int16 QueryForView; // ax
  int v8; // edx
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *m_pMemory; // eax
  bool v10; // zf
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *v11; // eax
  unsigned __int16 m_Next; // ax
  int v13; // ebx
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v14; // edi
  view_id_t v15; // eax
  unsigned __int16 v16; // ax
  IMatRenderContext *pRenderContext; // [esp+34h] [ebp-8h]
  IMaterial *pProxy; // [esp+38h] [ebp-4h]

  if ( (r_dopixelvisibility.m_pParent != nullptr
     && r_dopixelvisibility.m_pParent->m_Value.m_nValue != 0
     && g_PixelVisibilitySystem.m_hwCanTestGlows
     || CurrentViewID() < VIEW_MAIN)
    && this->m_setList.m_List.m_Memory.m_pMemory[this->m_activeSetsList].m_Element.m_Head != 0xFFFF )
  {
    v2 = materials->GetRenderContext(this: materials);
    pRenderContext = v2;
    if ( v2 != nullptr )
      v2->BeginRender(this: v2);
    if ( this->m_drawQueries )
      pProxy = this->m_pDrawMaterial;
    else
      pProxy = this->m_pProxyMaterial;
    v2->Bind(this: v2, a2: pProxy, a3: nullptr);
    if ( r_pixelvisibility_partial.m_pParent != nullptr
      && r_pixelvisibility_partial.m_pParent->m_Value.m_nValue != 0
      && !this->m_drawQueries )
    {
      ((void (__thiscall *)(IMatRenderContext *, _DWORD, int))v2->DepthRange)(a1: v2, a2: 0, a3: 1008981770);
      m_Head = this->m_setList.m_List.m_Memory.m_pMemory[this->m_activeSetsList].m_Element.m_Head;
      if ( m_Head != 0xFFFF )
      {
        do
        {
          v4 = m_Head;
          v5 = &this->m_setList.m_Memory.m_pMemory[v4];
          v6 = CurrentViewID();
          QueryForView = CPixelVisibilitySystem::FindQueryForView(
                           this,
                           pSet: &v5->m_Element,
                           nPlayerSlot: 0,
                           viewID: v6);
          if ( QueryForView != 0xFFFF )
          {
            v8 = QueryForView;
            m_pMemory = this->m_queryList.m_Memory.m_pMemory;
            v10 = (*((_BYTE *)&m_pMemory[v8].m_Element + 32) & 2) == 0;
            v11 = &m_pMemory[v8];
            if ( v10 )
              PixelVisibility_DrawProxy(
                a1: v4 * 28,
                a2: (int)v5,
                a3: (int)this,
                pRenderContext,
                queryHandle: v11->m_Element.m_queryHandleCount,
                origin: v11->m_Element.m_origin,
                scale: (IMesh *)LODWORD(v5->m_Element.proxySize),
                proxyAspect: v5->m_Element.proxyAspect,
                pMaterial: pProxy,
                screenspace: COERCE_FLOAT(v5->m_Element.sizeIsScreenSpace));
          }
          m_Head = this->m_setList.m_Memory.m_pMemory[v4].m_Next;
        }
        while ( m_Head != 0xFFFF );
        v2 = pRenderContext;
      }
      ((void (__thiscall *)(IMatRenderContext *, _DWORD, int))v2->DepthRange)(a1: v2, a2: 0, a3: 1065353216);
    }
    m_Next = this->m_setList.m_List.m_Memory.m_pMemory[this->m_activeSetsList].m_Element.m_Head;
    if ( m_Next != 0xFFFF )
    {
      do
      {
        v13 = m_Next;
        v14 = &this->m_setList.m_Memory.m_pMemory[v13];
        v15 = CurrentViewID();
        v16 = CPixelVisibilitySystem::FindQueryForView(this, pSet: &v14->m_Element, nPlayerSlot: 0, viewID: v15);
        if ( v16 != 0xFFFF )
          CPixelVisibilityQuery::IssueQuery(
            this: &this->m_queryList.m_Memory.m_pMemory[v16].m_Element,
            a2: v13 * 28,
            a3: (int)v14,
            pRenderContext,
            proxySize: (IMesh *)LODWORD(v14->m_Element.proxySize),
            proxyAspect: v14->m_Element.proxyAspect,
            pMaterial: pProxy,
            sizeIsScreenSpace: COERCE_FLOAT(v14->m_Element.sizeIsScreenSpace));
        m_Next = this->m_setList.m_Memory.m_pMemory[v13].m_Next;
      }
      while ( m_Next != 0xFFFF );
      v2 = pRenderContext;
    }
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007BF10
// Name: void PixelVisibility_EndCurrentView(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PixelVisibility_EndCurrentView()
{
  CPixelVisibilitySystem::EndView(this: &g_PixelVisibilitySystem);
}

//------------------------------------------------------------------------------
// Address: 0x1007C180
// Name: public: void CPixelVisibilitySystem::DeleteUnusedQueries(class CPixelVisSet __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPixelVisibilitySystem::DeleteUnusedQueries(
        CPixelVisibilitySystem *this,
        CPixelVisSet *pSet,
        bool bDeleteAll)
{
  unsigned __int16 m_Head; // si
  CUtlMultiList<CPixelVisibilityQuery,unsigned short> *p_m_queryList; // edi
  unsigned __int16 m_Next; // bx

  m_Head = this->m_queryList.m_List.m_Memory.m_pMemory[pSet->queryList].m_Element.m_Head;
  if ( m_Head != 0xFFFF )
  {
    p_m_queryList = &this->m_queryList;
    do
    {
      m_Next = p_m_queryList->m_Memory.m_pMemory[m_Head].m_Next;
      if ( bDeleteAll
        || *(_DWORD *)(gpGlobals.m_Index + 4) - p_m_queryList->m_Memory.m_pMemory[m_Head].m_Element.m_frameIssued > 1 )
      {
        CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Unlink(
          this: p_m_queryList,
          list: pSet->queryList,
          elem: m_Head);
        CUtlMultiList<CPixelVisibilityQuery,unsigned short>::LinkAfter(
          this: p_m_queryList,
          list: this->m_freeQueriesList,
          after: 0xFFFFu,
          elem: m_Head);
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C220
// Name: public: void COcclusionQuerySet::BeginQueryDrawing(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQuerySet::BeginQueryDrawing(COcclusionQuerySet *this, int iViewID, int iSplitScreenSlot)
{
  char *v3; // eax
  int v4; // ecx
  CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int> > *v5; // edi
  int v6; // eax
  int v7; // esi
  _DWORD *v8; // eax
  OcclusionHandleViewIDPair_t *v9; // ebx
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // eax
  IMatRenderContext *v12; // eax
  int v13; // esi

  v3 = (char *)this->m_pManagedData + 20 * iSplitScreenSlot;
  v4 = *((_DWORD *)v3 + 4);
  v5 = (CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int> > *)(v3 + 4);
  v6 = *((_DWORD *)v3 + 1);
  v7 = 0;
  if ( v4 == 0 )
    goto LABEL_7;
  v8 = (_DWORD *)(v6 + 4);
  while ( *v8 != iViewID )
  {
    ++v7;
    v8 += 3;
    if ( v7 == v4 )
      goto LABEL_7;
  }
  if ( v7 == -1 )
  {
LABEL_7:
    v7 = CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int>>::AddToTail(this: v5);
    v9 = &v5->m_Memory.m_pMemory[v7];
    v9->iViewID = iViewID;
    v10 = materials->GetRenderContext(this: materials);
    v9->hOcclusionHandle = v10->CreateOcclusionQueryObject(this: v10);
    v11 = materials->GetRenderContext(this: materials);
    v11->ResetOcclusionQueryObject(this: v11, a2: v9->hOcclusionHandle);
  }
  v12 = materials->GetRenderContext(this: materials);
  v13 = v7;
  v12->BeginOcclusionQueryDrawing(this: v12, a2: v5->m_Memory.m_pMemory[v13].hOcclusionHandle);
  v5->m_Memory.m_pMemory[v13].iLastFrameRendered = *(_DWORD *)(gpGlobals.m_Index + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1007C2F0
// Name: public: void COcclusionQuerySet::BeginQueryDrawing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQuerySet::BeginQueryDrawing(COcclusionQuerySet *this)
{
  view_id_t v2; // eax

  v2 = CurrentViewID();
  COcclusionQuerySet::BeginQueryDrawing(this, iViewID: v2, iSplitScreenSlot: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007C450
// Name: public: unsigned short CPixelVisibilitySystem::FindOrCreateQueryForView(class CPixelVisSet __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CPixelVisibilitySystem::FindOrCreateQueryForView(
        CPixelVisibilitySystem *this,
        CPixelVisSet *pSet,
        int nPlayerSlot,
        int viewID)
{
  unsigned __int16 result; // ax
  unsigned __int16 m_freeQueriesList; // ax
  int m_Head; // esi
  CUtlMultiList<CPixelVisibilityQuery,unsigned short> *p_m_queryList; // edi
  int v9; // eax
  __int16 v10; // cx

  result = CPixelVisibilitySystem::FindQueryForView(this, pSet, nPlayerSlot, viewID);
  if ( result == 0xFFFF )
  {
    m_freeQueriesList = this->m_freeQueriesList;
    m_Head = this->m_queryList.m_List.m_Memory.m_pMemory[m_freeQueriesList].m_Element.m_Head;
    p_m_queryList = &this->m_queryList;
    if ( (_WORD)m_Head == 0xFFFF )
    {
      LOWORD(m_Head) = CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Alloc(this: p_m_queryList);
    }
    else
    {
      CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Unlink(
        this: p_m_queryList,
        list: m_freeQueriesList,
        elem: m_Head);
      CPixelVisibilityQuery::ResetOcclusionQueries(this: &p_m_queryList->m_Memory.m_pMemory[m_Head].m_Element);
    }
    CUtlMultiList<CPixelVisibilityQuery,unsigned short>::LinkAfter(
      this: p_m_queryList,
      list: pSet->queryList,
      after: 0xFFFFu,
      elem: m_Head);
    v9 = (int)&p_m_queryList->m_Memory.m_pMemory[(unsigned __int16)m_Head];
    v10 = *(_WORD *)(v9 + 32) & 0xFFE0;
    *(_DWORD *)(v9 + 16) = 0;
    *(_WORD *)(v9 + 34) = viewID;
    *(_DWORD *)(v9 + 20) = 1065353216;
    *(_DWORD *)(v9 + 12) = -1;
    *(_WORD *)(v9 + 32) = v10 | (8 * (nPlayerSlot & 3));
    return m_Head;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007C530
// Name: public: void CPixelVisibilitySystem::DeleteUnusedSets(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPixelVisibilitySystem::DeleteUnusedSets(CPixelVisibilitySystem *this, bool bDeleteAll)
{
  unsigned __int16 m_Head; // ax
  CUtlMultiList<CPixelVisSet,unsigned short> *p_m_setList; // edi
  int v4; // esi
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v5; // ebx
  unsigned __int16 next; // [esp+0h] [ebp-Ch]
  CPixelVisibilitySystem *v7; // [esp+4h] [ebp-8h]
  unsigned __int16 node; // [esp+8h] [ebp-4h]

  m_Head = this->m_setList.m_List.m_Memory.m_pMemory[this->m_activeSetsList].m_Element.m_Head;
  v7 = this;
  node = m_Head;
  if ( m_Head != 0xFFFF )
  {
    p_m_setList = &this->m_setList;
    while ( 1 )
    {
      v4 = m_Head;
      v5 = &p_m_setList->m_Memory.m_pMemory[v4];
      next = v5->m_Next;
      if ( bDeleteAll
        || *(_DWORD *)(gpGlobals.m_Index + 4) - p_m_setList->m_Memory.m_pMemory[v4].m_Element.frameIssued > 1 )
      {
        CPixelVisibilitySystem::DeleteUnusedQueries(this, pSet: &v5->m_Element, bDeleteAll: true);
      }
      else
      {
        CPixelVisibilitySystem::DeleteUnusedQueries(this, pSet: &v5->m_Element, bDeleteAll: false);
      }
      if ( v7->m_queryList.m_List.m_Memory.m_pMemory[v5->m_Element.queryList].m_Element.m_Head == 0xFFFF )
      {
        CUtlMultiList<CPixelVisSet,unsigned short>::Unlink(this: p_m_setList, list: v7->m_activeSetsList, elem: node);
        CUtlMultiList<CPixelVisSet,unsigned short>::LinkAfter(
          this: p_m_setList,
          list: v7->m_freeSetsList,
          after: 0xFFFFu,
          elem: node);
        ++p_m_setList->m_Memory.m_pMemory[v4].m_Element.serial;
      }
      node = next;
      if ( next == 0xFFFF )
        break;
      m_Head = next;
      this = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C850
// Name: public: CPixelVisibilitySystem::CPixelVisibilitySystem(void)
// Source: json
//------------------------------------------------------------------------------
CPixelVisibilitySystem *__thiscall CPixelVisibilitySystem::CPixelVisibilitySystem(CPixelVisibilitySystem *this)
{
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short> *v3; // ecx
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *v4; // edx

  CAutoGameSystem::CAutoGameSystem(this, name: "CPixelVisibilitySystem");
  this->__vftable = (CPixelVisibilitySystem_vtbl *)&CPixelVisibilitySystem::`vftable';
  this->m_setList.m_Memory.m_pMemory = nullptr;
  this->m_setList.m_Memory.m_nAllocationCount = 0;
  this->m_setList.m_Memory.m_nGrowSize = 0;
  this->m_setList.m_List.m_Memory.m_pMemory = nullptr;
  this->m_setList.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_setList.m_List.m_Memory.m_nGrowSize = 0;
  this->m_setList.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_setList.m_List.m_FirstFree = 0xFFFF;
  this->m_setList.m_List.m_pElements = this->m_setList.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_setList.m_List.m_Head = -1;
  this->m_setList.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_setList.m_Memory.m_pMemory;
  this->m_setList.m_pElementList = nullptr;
  this->m_setList.m_MaxElementIndex = 0;
  this->m_setList.m_pElements = m_pMemory;
  *(_DWORD *)&this->m_setList.m_FirstFree = 0xFFFF;
  this->m_queryList.m_Memory.m_pMemory = nullptr;
  this->m_queryList.m_Memory.m_nAllocationCount = 0;
  this->m_queryList.m_Memory.m_nGrowSize = 0;
  this->m_queryList.m_List.m_Memory.m_pMemory = nullptr;
  this->m_queryList.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_queryList.m_List.m_Memory.m_nGrowSize = 0;
  this->m_queryList.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_queryList.m_List.m_FirstFree = 0xFFFF;
  v3 = this->m_queryList.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_queryList.m_List.m_Head = -1;
  this->m_queryList.m_List.m_pElements = v3;
  this->m_queryList.m_List.m_NumAlloced = 0;
  v4 = this->m_queryList.m_Memory.m_pMemory;
  this->m_queryList.m_pElementList = nullptr;
  this->m_queryList.m_MaxElementIndex = 0;
  *(_DWORD *)&this->m_queryList.m_FirstFree = 0xFFFF;
  this->m_queryList.m_pElements = v4;
  *(_WORD *)&this->m_hwCanTestGlows = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007C940
// Name: public: virtual void CPixelVisibilitySystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPixelVisibilitySystem::LevelInitPreEntity(CPixelVisibilitySystem *this)
{
  int m_nValue; // eax
  bool v3; // al
  IMatRenderContext *v4; // esi
  int v5; // eax
  IMaterial *v6; // eax
  IMaterial *v7; // eax
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // bx
  unsigned __int16 v10; // cx
  int v11; // eax
  unsigned __int16 v12; // bx
  unsigned __int16 v13; // cx
  int v14; // eax
  unsigned __int16 v15; // bx
  unsigned __int16 v16; // cx
  int v17; // eax

  if ( r_dopixelvisibility.m_pParent != nullptr )
    m_nValue = r_dopixelvisibility.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = m_nValue != 0;
  this->m_hwCanTestGlows = v3;
  if ( v3 )
  {
    v4 = materials->GetRenderContext(this: materials);
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    v5 = (int)v4->CreateOcclusionQueryObject(this: v4);
    if ( v5 != 0 )
      v4->DestroyOcclusionQueryObject(this: v4, a2: (OcclusionQueryObjectHandle_t__ *)v5);
    else
      this->m_hwCanTestGlows = false;
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
  v6 = materials->FindMaterial(this: materials, a2: "engine/occlusionproxy", a3: "ClientEffect textures", a4: 1, a5: 0);
  this->m_pProxyMaterial = v6;
  v6->IncrementReferenceCount(this: v6);
  v7 = materials->FindMaterial(
         this: materials,
         a2: "engine/occlusionproxy_countdraw",
         a3: "ClientEffect textures",
         a4: 1,
         a5: 0);
  this->m_pDrawMaterial = v7;
  v7->IncrementReferenceCount(this: v7);
  v8 = CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_queryList.m_List,
         multilist: false);
  v9 = v8;
  v10 = -1;
  if ( v8 != 0xFFFF )
  {
    CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_queryList.m_List,
      before: 0xFFFFu,
      elem: v8);
    v10 = v9;
  }
  v11 = v10;
  this->m_queryList.m_List.m_Memory.m_pMemory[v11].m_Element.m_Tail = -1;
  this->m_queryList.m_List.m_Memory.m_pMemory[v11].m_Element.m_Head = -1;
  this->m_queryList.m_List.m_Memory.m_pMemory[v11].m_Element.m_Count = 0;
  this->m_freeQueriesList = v10;
  v12 = CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_setList.m_List,
          multilist: false);
  if ( v12 == 0xFFFF )
  {
    v13 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_setList.m_List,
      before: 0xFFFFu,
      elem: v12);
    v13 = v12;
  }
  v14 = v13;
  this->m_setList.m_List.m_Memory.m_pMemory[v14].m_Element.m_Tail = -1;
  this->m_setList.m_List.m_Memory.m_pMemory[v14].m_Element.m_Head = -1;
  this->m_setList.m_List.m_Memory.m_pMemory[v14].m_Element.m_Count = 0;
  this->m_activeSetsList = v13;
  v15 = CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_setList.m_List,
          multilist: false);
  if ( v15 == 0xFFFF )
  {
    v16 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_setList.m_List,
      before: 0xFFFFu,
      elem: v15);
    v16 = v15;
  }
  v17 = v16;
  this->m_setList.m_List.m_Memory.m_pMemory[v17].m_Element.m_Tail = -1;
  this->m_setList.m_List.m_Memory.m_pMemory[v17].m_Element.m_Head = -1;
  this->m_setList.m_List.m_Memory.m_pMemory[v17].m_Element.m_Count = 0;
  this->m_freeSetsList = v16;
}

//------------------------------------------------------------------------------
// Address: 0x1007CB20
// Name: public: virtual void CPixelVisibilitySystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPixelVisibilitySystem::LevelShutdownPostEntity(CPixelVisibilitySystem *this)
{
  IMaterial *m_pDrawMaterial; // ecx

  this->m_pProxyMaterial->DecrementReferenceCount(this: this->m_pProxyMaterial);
  m_pDrawMaterial = this->m_pDrawMaterial;
  this->m_pProxyMaterial = nullptr;
  m_pDrawMaterial->DecrementReferenceCount(this: m_pDrawMaterial);
  this->m_pDrawMaterial = nullptr;
  CPixelVisibilitySystem::DeleteUnusedSets(this, bDeleteAll: true);
  CUtlMultiList<CPixelVisSet,unsigned short>::Purge(this: &this->m_setList);
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Purge(this: &this->m_queryList);
  *(_DWORD *)&this->m_freeQueriesList = -1;
  this->m_freeSetsList = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1007CB80
// Name: public: unsigned short CPixelVisibilitySystem::AllocSet(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CPixelVisibilitySystem::AllocSet(CPixelVisibilitySystem *this)
{
  int m_freeSetsList; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  unsigned __int16 m_Head; // di
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v6; // [esp+Ch] [ebp-4h]

  m_freeSetsList = this->m_freeSetsList;
  m_pMemory = this->m_setList.m_List.m_Memory.m_pMemory;
  m_Head = m_pMemory[m_freeSetsList].m_Element.m_Head;
  if ( m_Head == 0xFFFF )
  {
    m_Head = CUtlMultiList<CPixelVisSet,unsigned short>::Alloc(this: &this->m_setList);
    v6 = &this->m_setList.m_Memory.m_pMemory[m_Head];
    v6->m_Element.queryList = CUtlMultiList<CPixelVisibilityQuery,unsigned short>::CreateList(this: &this->m_queryList);
  }
  else
  {
    CUtlMultiList<CPixelVisSet,unsigned short>::Unlink(
      this: &this->m_setList,
      list: m_freeSetsList,
      elem: m_pMemory[m_freeSetsList].m_Element.m_Head);
  }
  CUtlMultiList<CPixelVisSet,unsigned short>::LinkAfter(
    this: &this->m_setList,
    list: this->m_activeSetsList,
    after: 0xFFFFu,
    elem: m_Head);
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x1007CC00
// Name: public: class CPixelVisSet __near * CPixelVisibilitySystem::FindOrCreatePixelVisSet(struct pixelvis_queryparams_t const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *__thiscall CPixelVisibilitySystem::FindOrCreatePixelVisSet(
        CPixelVisibilitySystem *this,
        const pixelvis_queryparams_t *params,
        int *queryHandle)
{
  int v4; // edx
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *m_pMemory; // ecx
  int v6; // eax
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *result; // eax
  unsigned __int16 v8; // dx
  int v9; // ecx
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v10; // eax
  float fadeTime; // xmm0_4

  if ( *queryHandle == 0
    || (v4 = (unsigned __int16)(*queryHandle - 1)) >= this->m_setList.m_MaxElementIndex
    || (m_pMemory = this->m_setList.m_Memory.m_pMemory, v6 = v4, m_pMemory[v4].m_Previous == (_WORD)v4)
    && m_pMemory[v6].m_Next != (_WORD)v4
    || (result = &m_pMemory[v6])->m_Element.serial != HIWORD(*queryHandle) )
  {
    v8 = CPixelVisibilitySystem::AllocSet(this);
    v9 = v8;
    v10 = &this->m_setList.m_Memory.m_pMemory[v9];
    v10->m_Element.proxySize = params->proxySize;
    v10->m_Element.proxyAspect = params->proxyAspect;
    fadeTime = params->fadeTime;
    if ( fadeTime <= 0.0 )
      v10->m_Element.fadeTimeInv = 8.0;
    else
      v10->m_Element.fadeTimeInv = 1.0 / fadeTime;
    v10->m_Element.frameIssued = 0;
    v10->m_Element.sizeIsScreenSpace = params->bSizeInScreenspace;
    *queryHandle = (unsigned __int16)(v8 + 1) | (this->m_setList.m_Memory.m_pMemory[v9].m_Element.serial << 16);
    return &this->m_setList.m_Memory.m_pMemory[v9];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007CCE0
// Name: void PixelVisibility_EndScene(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PixelVisibility_EndScene()
{
  CPixelVisibilitySystem::DeleteUnusedSets(this: &g_PixelVisibilitySystem, bDeleteAll: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007CD70
// Name: public: float CPixelVisibilitySystem::GetFractionVisible(struct pixelvis_queryparams_t const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPixelVisibilitySystem::GetFractionVisible(
        CPixelVisibilitySystem *this,
        const pixelvis_queryparams_t *params,
        int *queryHandle)
{
  double result; // st7
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *PixelVisSet; // ebx
  view_id_t v6; // eax
  int QueryForView; // edx
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( !this->m_hwCanTestGlows
    || building_cubemaps.m_pParent != nullptr && building_cubemaps.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( GlowSightDistance(a1: (int)&savedregs, glowOrigin: &params->position, bShouldTrace: true) <= 0.0 )
      return 0.0;
    else
      return 1.0;
  }
  else if ( CurrentViewID() >= VIEW_MAIN )
  {
    PixelVisSet = CPixelVisibilitySystem::FindOrCreatePixelVisSet(this, params, queryHandle);
    v6 = CurrentViewID();
    QueryForView = CPixelVisibilitySystem::FindOrCreateQueryForView(
                     this,
                     pSet: &PixelVisSet->m_Element,
                     nPlayerSlot: 0,
                     viewID: v6);
    this->m_queryList.m_Memory.m_pMemory[QueryForView].m_Element.m_origin = params->position;
    result = CPixelVisibilityQuery::GetFractionVisible(
               this: &this->m_queryList.m_Memory.m_pMemory[QueryForView].m_Element,
               fadeTimeInv: PixelVisSet->m_Element.fadeTimeInv);
    PixelVisSet->m_Element.frameIssued = *(_DWORD *)(gpGlobals.m_Index + 4);
  }
  else
  {
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007CE50
// Name: float PixelVisibility_FractionVisible(struct pixelvis_queryparams_t const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl PixelVisibility_FractionVisible(const pixelvis_queryparams_t *params, int *queryHandle)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( queryHandle != nullptr )
    return CPixelVisibilitySystem::GetFractionVisible(this: &g_PixelVisibilitySystem, params, queryHandle);
  if ( GlowSightDistance(a1: (int)&savedregs, glowOrigin: &params->position, bShouldTrace: true) <= 0.0 )
    return 0.0;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1007CEB0
// Name: public: COcclusionQuerySet::~COcclusionQuerySet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionQuerySet::~COcclusionQuerySet(COcclusionQuerySet *this)
{
  int v1; // ebx
  int v2; // edi
  OcclusionQueryHiddenData_t *m_pManagedData; // ecx
  OcclusionQueryHiddenData_t *i; // eax
  IMatRenderContext *v5; // esi
  int v6; // eax
  int v7; // edi
  char *v8; // esi
  void *v9; // edx
  int m_Size; // ecx
  bool v11; // zf
  OcclusionQueryHiddenData_t *m_pMemory; // edx
  OcclusionQueryHiddenData_t *v13; // ecx
  int v14; // ecx
  int v15; // edx
  int *p_m_Size; // [esp+8h] [ebp-10h]
  _DWORD *v17; // [esp+Ch] [ebp-Ch]
  int iIndex; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v1 = 0;
  v2 = 0;
  if ( s_OcclusionQueries.m_Size != 0 )
  {
    m_pManagedData = (OcclusionQueryHiddenData_t *)this->m_pManagedData;
    for ( i = s_OcclusionQueries.m_Memory.m_pMemory; i != m_pManagedData; ++i )
    {
      if ( ++v2 == s_OcclusionQueries.m_Size )
        return;
    }
    iIndex = v2;
    if ( v2 != s_OcclusionQueries.m_Size )
    {
      v5 = materials->GetRenderContext(this: materials);
      if ( v5 != nullptr )
        v5->BeginRender(this: v5);
      v6 = 24 * v2;
      v19 = 24 * v2;
      p_m_Size = &s_OcclusionQueries.m_Memory.m_pMemory[v2].occlusionHandles[0].m_Size;
      if ( *p_m_Size != 0 )
      {
        v17 = (OcclusionHandleViewIDPair_t **)((char *)&s_OcclusionQueries.m_Memory.m_pMemory->occlusionHandles[0].m_Memory.m_pMemory
                                             + v6);
        v7 = 0;
        do
        {
          v5->DestroyOcclusionQueryObject(this: v5, a2: *(OcclusionQueryObjectHandle_t__ **)(v7 + *v17));
          ++v1;
          v7 += 12;
        }
        while ( v1 != *p_m_Size );
        v6 = v19;
        v2 = iIndex;
      }
      if ( v5 != nullptr )
      {
        v5->EndRender(this: v5);
        v5->Release(this: v5);
        v6 = v19;
      }
      v8 = (char *)&s_OcclusionQueries.m_Memory.m_pMemory[1] + v6;
      *((_DWORD *)v8 - 2) = 0;
      if ( *((int *)v8 - 3) >= 0 )
      {
        if ( *((_DWORD *)v8 - 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v8 - 5));
          v6 = v19;
          *((_DWORD *)v8 - 5) = 0;
        }
        *((_DWORD *)v8 - 4) = 0;
      }
      v9 = *((void **)v8 - 5);
      *((_DWORD *)v8 - 1) = v9;
      if ( *((int *)v8 - 3) >= 0 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v6 = v19;
          *((_DWORD *)v8 - 5) = 0;
        }
        *((_DWORD *)v8 - 4) = 0;
      }
      m_Size = s_OcclusionQueries.m_Size;
      v11 = s_OcclusionQueries.m_Size == 0;
      if ( s_OcclusionQueries.m_Size > 0 )
      {
        if ( v2 != s_OcclusionQueries.m_Size - 1 )
        {
          m_pMemory = s_OcclusionQueries.m_Memory.m_pMemory;
          v13 = &s_OcclusionQueries.m_Memory.m_pMemory[s_OcclusionQueries.m_Size - 1];
          *(_QWORD *)((char *)&s_OcclusionQueries.m_Memory.m_pMemory->pOwner + v6) = *(_QWORD *)&v13->pOwner;
          *(_QWORD *)((char *)&m_pMemory->occlusionHandles[0].m_Memory.m_nAllocationCount + v6) = *(_QWORD *)&v13->occlusionHandles[0].m_Memory.m_nAllocationCount;
          *(_QWORD *)((char *)&m_pMemory->occlusionHandles[0].m_Size + v6) = *(_QWORD *)&v13->occlusionHandles[0].m_Size;
          m_Size = s_OcclusionQueries.m_Size;
        }
        s_OcclusionQueries.m_Size = m_Size - 1;
        v11 = m_Size == 1;
      }
      if ( !v11 )
      {
        **(_DWORD **)((char *)&s_OcclusionQueries.m_Memory.m_pMemory->pOwner + v6) = (char *)s_OcclusionQueries.m_Memory.m_pMemory
                                                                                   + v6;
        if ( s_OcclusionQueries.m_Size > 1
          && s_OcclusionQueries.m_Memory.m_pMemory[v2 == 0].pOwner->m_pManagedData != &s_OcclusionQueries.m_Memory.m_pMemory[v2 == 0] )
        {
          v14 = 0;
          if ( s_OcclusionQueries.m_Size != 0 )
          {
            v15 = 0;
            do
            {
              ++v14;
              s_OcclusionQueries.m_Memory.m_pMemory[v15].pOwner->m_pManagedData = &s_OcclusionQueries.m_Memory.m_pMemory[v15];
              ++v15;
            }
            while ( v14 != s_OcclusionQueries.m_Size );
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D0E0
// Name: public: COcclusionQuerySet::COcclusionQuerySet(void)
// Source: json
//------------------------------------------------------------------------------
COcclusionQuerySet *__thiscall COcclusionQuerySet::COcclusionQuerySet(COcclusionQuerySet *this)
{
  OcclusionQueryHiddenData_t *v2; // eax
  OcclusionQueryHiddenData_t *m_pMemory; // eax
  int v4; // ecx
  int v5; // edx

  v2 = &s_OcclusionQueries.m_Memory.m_pMemory[CUtlVector<CPropData::propdata_breakablechunk_t,CUtlMemory<CPropData::propdata_breakablechunk_t,int>>::InsertBefore(
                                                this: (CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *)&s_OcclusionQueries,
                                                elem: s_OcclusionQueries.m_Size)];
  v2->pOwner = this;
  this->m_pManagedData = v2;
  if ( s_OcclusionQueries.m_Size > 1 )
  {
    m_pMemory = s_OcclusionQueries.m_Memory.m_pMemory;
    if ( s_OcclusionQueries.m_Memory.m_pMemory->pOwner->m_pManagedData != s_OcclusionQueries.m_Memory.m_pMemory )
    {
      v4 = 0;
      if ( s_OcclusionQueries.m_Size != 0 )
      {
        v5 = 0;
        while ( 1 )
        {
          ++v4;
          m_pMemory[v5].pOwner->m_pManagedData = &m_pMemory[v5];
          ++v5;
          if ( v4 == s_OcclusionQueries.m_Size )
            break;
          m_pMemory = s_OcclusionQueries.m_Memory.m_pMemory;
        }
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10412CD0
// Name: PrecacheOcclusionProxyPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheOcclusionProxyPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheOcclusionProxyPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheOcclusionProxyPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412CF0
// Name: _dynamic_initializer_for__g_PixelVisibilitySystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PixelVisibilitySystem__()
{
  CPixelVisibilitySystem::CPixelVisibilitySystem(this: &g_PixelVisibilitySystem);
  return atexit(func: dynamic_atexit_destructor_for__g_PixelVisibilitySystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10412D10
// Name: _dynamic_initializer_for__pixelvis_debug_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__pixelvis_debug_command__()
{
  ConCommand::ConCommand(
    this: &pixelvis_debug_command,
    pName: "pixelvis_debug",
    callback: pixelvis_debug,
    pHelpString: "Dump debug info",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__pixelvis_debug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10412D40
// Name: _dynamic_initializer_for____g_C_PlasmaClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PlasmaClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PlasmaClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PlasmaClientClass;
  return result;
}
